/* 
 * File:   RDSRegion.h
 * Author: nadjieh
 *
 * Created on August 18, 2014, 10:12 PM
 */

#ifndef RDSREGION_H
#define	RDSREGION_H
#include "/opt/root/math/mathcore/inc/Math/Functor.h"
#include<iostream>
#include "TFile.h"
#include "TTree.h"
#include "RDS.h"
#include "RDSData.h"
#include "TString.h"
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooCategory.h"
#include "RooPlot.h"
#include "RooHistPdf.h"
#include "RooDataHist.h"
#include "RooAddPdf.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "RooKeysPdf.h"
#include "TH1.h"
#include "TH2.h"
#include "TDirectory.h"
#include "TString.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using namespace RooFit;
typedef std::pair<double, double> interval;
typedef std::map<TString, interval> varInfo;

string nameExtractor(string name) {
    int pos = name.find("_Summer12_final_");
    return name.substr(0, pos);
}

class Region {
public:

    Region(TTree* data_, varInfo myInfo) : data(data_) {
        TString prefix = "eventSelection";
        varInfo::const_iterator it = myInfo.begin();
        for (; it != myInfo.end(); it++) {
            VariablesMap[it->first] = new RooRealVar(prefix + it->first, prefix + it->first, it->second.first, it->second.second);
            VariablesMaxMap[it->first] = it->second.second;
        }
        dataHist = 0;
    }

    virtual ~Region() {
        delete data;
        for (unsigned int s = 0; s < MCs.size(); s++) {
            delete MCs[s];
        }
        for (std::map<TString, RooRealVar*>::iterator itr = VariablesMap.begin(); itr != VariablesMap.end(); itr++) {
            delete itr->second;
        }
    }

    void addMC(TTree * mc, double lumiW, double err, bool fix, TString name_) {
        MCs.push_back(mc);
        MCLumiWeights.push_back(lumiW /* mc->GetEntries()*/);
        errorOnWeights.push_back(err);
        isMCFixed.push_back(fix);
        MCName.push_back(name_);
    }

    void FillHist(TTree* t, TH1D * h, TString var, double weight = 1) {
        RDS rds(t);
        Long64_t nentries = rds.fChain->GetEntries();
        for (Long64_t i = 0; i < nentries; i++) {
            rds.GetEntry(i);
            if (var == "amassMu") {
                h->Fill(rds.eventSelectionamassMu, weight);
                continue;
            } else if (var == "diffMassaa") {
                h->Fill(rds.eventSelectiondiffMassaa, weight);
                continue;
            } else if (var == "METsignificance_hamb") {
                h->Fill(rds.eventSelectionMETsignificance_hamb, weight);
                continue;
            }
        }
    }

    void FillHists(TString var, int nBins, bool doWeight = true) {
        stringstream s;
        for (unsigned int i = 0; i < MCs.size(); i++) {
            s.str("");
            s << "Hist_" << var << "_" << i;
            TH1D * h = new TH1D(s.str().c_str(), s.str().c_str(), nBins, 0., this->VariablesMaxMap[var]);
            h->Sumw2();
            if (doWeight)
                FillHist(MCs[i], h, var, MCLumiWeights[i]);
            else
                FillHist(MCs[i], h, var);
            hists.push_back(h);
        }
    }

    void FillDataHist(TString var, int nBins) {
        stringstream s;
        s.str("");
        s << "dataHist_" << var;
        dataHist = new TH1D(s.str().c_str(), s.str().c_str(), nBins, 0., this->VariablesMaxMap[var]);
        dataHist->Sumw2();
        RDSData rds(data);
        Long64_t nentries = rds.fChain->GetEntries();
        for (Long64_t i = 0; i < nentries; i++) {
            rds.GetEntry(i);
            if (var == "amassMu") {
                dataHist->Fill(rds.eventSelectionamassMu);
                continue;
            } else if (var == "diffMassaa") {
                dataHist->Fill(rds.eventSelectiondiffMassaa);
                continue;
            } else if (var == "METsignificance_hamb") {
                dataHist->Fill(rds.eventSelectionMETsignificance_hamb);
                continue;
            }
        }
    }

    TH1 * GetDataHist() {
        return dataHist;
    }

    RooDataHist * GetBinnedDataSet(TString var) {
        stringstream s;
        s.str("");
        s << var << "_BinnedData";
        return (new RooDataHist(s.str().c_str(), s.str().c_str(), RooArgSet(*this->VariablesMap[var]), dataHist));
    }

    TH1* GetBkgSubtracted(TString var, std::vector<int> exIds, TString name = "") {
        stringstream s;
        TH1D * myH = new TH1D("forSub" + name, "forSub" + name, hists[0]->GetXaxis()->GetNbins(), hists[0]->GetXaxis()->GetXmin(),
                hists[0]->GetXaxis()->GetXmax());
        myH->Sumw2();
        for (unsigned int i = 0; i < hists.size(); i++) {
            bool add = true;
            for (unsigned int j = 0; j < exIds.size(); j++)
                if ((int)i == exIds[j]) {
                    add = false;
                    break;
                }
            if (!add)
                continue;
            myH->Add(hists[i]);
        }
        cout << "BkgIntegral: " << myH->Integral() << endl;
        cout << "DataIntegral: " << dataHist->Integral() << endl;
        myH->Scale(-1);
        TH1D * newData = (TH1D*) dataHist->Clone("bkgSubtracted" + name);
        newData->Add(myH);
        cout << "newData: " << newData->Integral() << endl;

        delete myH;
        return newData;
    }

    RooDataSet * GetData(TString var) {
        stringstream s;
        s << "dataset with " << var;
        TString title = s.str().c_str();
        return new RooDataSet("data", title, this->data, *this->VariablesMap[var], "");
    }

    std::pair<RooDataSet*, RooRealVar*> GetMCData(TString var, int i = -1) {
        stringstream s;
        s << "dataset number " << i + 1 << " with " << var;
        TString title = s.str().c_str();
        s.str("");
        s << "MC_" << MCName[i];
        TString name = s.str().c_str();
        stringstream tmpS;
        tmpS << MCLumiWeights[i];
        RooDataSet ret(name, title, this->MCs[i], *this->VariablesMap[var]);
        s << "_W";
        RooFormulaVar wFunc(s.str().c_str(), "event weight", tmpS.str().c_str(), *this->VariablesMap[var]);
        RooRealVar* w = (RooRealVar*) ret.addColumn(wFunc);
        RooDataSet * wdata = new RooDataSet(ret.GetName(), ret.GetTitle(), &ret, *ret.get(), 0, w->GetName());
        cout << w->getVal() << "\t" << w->getVal() * MCs[i]->GetEntriesFast() << "\t" << MCName[i] << endl;
        return make_pair(wdata, w);
    }

    void PrepareMCDataSets(TString var, int nBins = 10000) {
        //unbinned
        for (unsigned int i = 0; i < MCs.size(); i++) {
            cout << "Number of entries: " << MCs[i]->GetEntriesFast() << endl;
            stringstream s;
            s.str("");
            s << "dataset" << i;
            datasets.push_back(this->GetMCData(var, i));
        }

        //binned
        this->VariablesMap[var]->SetBit(nBins);
        for (unsigned int i = 0; i < datasets.size(); i++) {
            stringstream s;
            s.str("");
            s << "dataset_binned" << i;
            datasets_binned.push_back(make_pair(new RooDataHist(s.str().c_str(), s.str().c_str(), RooArgSet(*this->VariablesMap[var]), *(datasets[i].first))
                    , datasets[i].second));
            cout << "Binned dataset integral: " << datasets_binned[datasets_binned.size() - 1].first->sum(kFALSE) << endl;
        }
    }

    void PrepareParams(int allFree = 1000) {
        stringstream s;
        for (unsigned int i = 0; i < MCs.size(); i++) {
            s.str("");
            s << "mu_" << i;
            //            RooRealVar * myVar = new RooRealVar(s.str().c_str(), s.str().c_str(), 1, 1 - errorOnWeights[i], 1 + errorOnWeights[i]);
            RooRealVar * myVar = new RooRealVar(s.str().c_str(), s.str().c_str(), MCLumiWeights[i], MCLumiWeights[i]*(1 - errorOnWeights[i])
                    , MCLumiWeights[i]*(1 + errorOnWeights[i]));
            if (isMCFixed[i])
                myVar->setConstant(kTRUE);
            if ((int)i < allFree)
                parameters.push_back(myVar);
        }
    }

    void PreparePDFs(TString var) {
        stringstream s;
        for (unsigned int i = 0; i < MCs.size(); i++) {
            s.str("");
            s << "pdf_" << i;
            pdfs.push_back(new RooKeysPdf(s.str().c_str(), s.str().c_str(), *this->VariablesMap[var], *datasets[i].first));
            cout << "   " << pdfs[pdfs.size() - 1]->createIntegral(*this->VariablesMap[var])->getVal() << endl;
        }
    }

    RooAddPdf GetModel(TString var) {
        RooArgList myList;
        RooArgList myNumbers;
        for (unsigned int i = 0; i < MCs.size(); i++) {
            myList.add(*pdfs[i]);
            myNumbers.add(*parameters[i]);
        }
        stringstream s;
        s.str("");
        s << var << "_model";
        RooAddPdf ret(s.str().c_str(), s.str().c_str(), myList, myNumbers);
        return ret;

    }

    RooAddPdf GetCombinedPdfFromBinnedDataSet(TString var, std::vector<int> exIds, TString name = "") {
        //Smooth: better results
        RooRealVar* unit = new RooRealVar("unit", "unit", 1., 0.9, 1.1);
        unit->setConstant(kTRUE);
        RooArgList myList;
        RooArgList myNumbers;
        stringstream s;
        double net = 0;
        for (unsigned int i = 0; i < datasets_binned.size(); i++) {
            bool add = true;
            cout << "In GetCombinedPdfFromBinnedDataSet: " << i << endl;
            for (unsigned int j = 0; j < exIds.size(); j++)
                if ((int)i == exIds[j]) {
                    add = false;
                    break;
                }
            //            cout << "In GetCombinedPdfFromBinnedDataSet: " << add << endl;
            //            if (!add)
            //                cout << "I don't add " << i << endl;
            //            else
            //                cout << "I add " << i << endl;
            if (!add)
                continue;
            //            cout << "In GetCombinedPdfFromBinnedDataSet: I reached" << endl;
            s.str();
            s << var << "_BinnedDataSetPdf" << i;
            RooHistPdf * tmp = new RooHistPdf(s.str().c_str(), s.str().c_str(), *this->VariablesMap[var], *datasets_binned[i].first);
            //            myList.add(*(new RooHistPdf(s.str().c_str(), s.str().c_str(), *this->VariablesMap[var], *datasets_binned[i].first)));
            //            cout<<tmp->createIntegral(*this->VariablesMap[var])->getVal()<<endl;
            net += tmp->createIntegral(*this->VariablesMap[var])->getVal();
            myList.add(*tmp);
            myNumbers.add(*unit);
        }
        cout << "--- " << name << " " << net << endl;
        s.str("");
        s << var << "_" << name << "_BinnedDataSetPdf";
        RooAddPdf ret(s.str().c_str(), s.str().c_str(), myList, myNumbers);

        return ret;
    }

    RooHistPdf GetCombinedPdfFromHistogram(TString var, std::vector<int> exIds, TString name = "") {
        //Gitty!
        stringstream s;
        TH1D * myH = new TH1D("forPdf" + name, "forPdf" + name, hists[0]->GetXaxis()->GetNbins(), hists[0]->GetXaxis()->GetXmin(),
                hists[0]->GetXaxis()->GetXmax());
        for (unsigned int i = 0; i < hists.size(); i++) {
            bool add = true;
            for (unsigned int j = 0; j < exIds.size(); j++)
                if ((int)i == exIds[j]) {
                    add = false;
                    break;
                }
            if (!add)
                continue;
            myH->Add(hists[i]);
        }
        //        for (unsigned int i = 0; i < datasets_binned.size(); i++) {
        //            bool add = true;
        //            for (unsigned int j = 0; j < exIds.size(); j++)
        //                if (i == exIds[j]) {
        //                    add = false;
        //                    break;
        //                }
        //            if (!add)
        //                continue;
        //            s.str();
        //            s << var << "_DataHist" << i;
        //            RooDataHist* tmp = new RooDataHist(s.str().c_str(), s.str().c_str(), RooArgList(*this->VariablesMap[var]), hists[i]);
        //            myList.add(*(new RooHistPdf(s.str().c_str(), s.str().c_str(), *this->VariablesMap[var], *tmp)));
        //            myNumbers.add(*unit);
        //        }
        s << var << "_" << name << "_HistData";
        RooDataHist* tmp = new RooDataHist(s.str().c_str(), s.str().c_str(),
                RooArgList(*this->VariablesMap[var]), myH);
        cout << "DataHist is made" << endl;
        s << var << "_" << name << "_HistPdf";
        return RooHistPdf(s.str().c_str(), s.str().c_str(), *this->VariablesMap[var], *tmp);
    }

    TTree* GetDataInRegion(TTree* input, int regIndex, bool isData = false) {
        TTree * newtree = 0;
        if (isData) {
            RDSData * rds = new RDSData(input);
            Long64_t nentries = rds->fChain->GetEntries();
            //            Long64_t nentries = 10000;
            newtree = rds->fChain->CloneTree(0);
            for (Long64_t i = 0; i < nentries; i++) {
                rds->GetEntry(i);
                if (rds->isInRegion(regIndex)) newtree->Fill();
            }
            newtree->AutoSave();
            delete rds;
            std::cout << newtree << std::endl;
        } else {
            RDS * rds = new RDS(input);
            Long64_t nentries = rds->fChain->GetEntries();
            //            Long64_t nentries = 10000;
            newtree = rds->fChain->CloneTree(0);
            for (Long64_t i = 0; i < nentries; i++) {
                rds->GetEntry(i);
                if (rds->isInRegion(regIndex)) newtree->Fill();
            }
            newtree->AutoSave();
            delete rds;
            std::cout << newtree << std::endl;
        }
        return newtree;
    }

    void setVarRange(TString s, double l, double h) {
        VariablesMap[s]->setRange(l, h);
    }

    RooRealVar * GetVar(TString s) {
        return VariablesMap[s];
    }

    std::vector<RooKeysPdf*> GetPdfs() {
        return pdfs;
    }

    std::vector<TH1*> GetHists() {
        return hists;
    }

    map<TString, RooRealVar*> VariablesMap;
    std::vector<std::pair<RooDataSet*, RooRealVar*> >datasets;
private:
    TTree* data;
    //Those I don't want to merge are at the beginning
    std::vector<TTree*> MCs;
    std::vector<double> MCLumiWeights;
    std::vector<double> errorOnWeights;
    std::vector<TString> MCName;
    std::vector<bool> isMCFixed;
    map<TString, double> VariablesMaxMap;
    std::vector<std::pair<RooDataHist*, RooRealVar*> >datasets_binned;
    std::vector<RooKeysPdf*> pdfs;
    std::vector<RooRealVar*> parameters;
    std::vector<TH1*> hists;
    TH1* dataHist;





};

#endif	/* RDSREGION_H */

