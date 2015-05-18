/* 
 * File:   DYinvestigators.h
 * Author: nadjieh
 *
 * Created on September 11, 2014, 3:52 PM
 */

#ifndef DYINVESTIGATORS_H
#define	DYINVESTIGATORS_H

#include "TString.h"
#include "RDSRegion.h"
#include "RDS.h"
#include "RDSData.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooPlot.h"
#include "RooExponential.h"
#include "RooPolynomial.h"
#include "RooRealVar.h"
#include "RooKeysPdf.h"
#include "RooHistPdf.h"
#include "RooFFTConvPdf.h"
#include "TH1.h"
#include "RooDataSet.h"
#include "RooFitResult.h"
#include "RooRandom.h"
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "RooVoigtian.h"
#include <vector>
#include <sstream>
using namespace RooFit;
using namespace std;

struct PE {
    double value[5];
    double error[5];
};

class DYinvestigators {
public:

    DYinvestigators(TString name_, TString var_, Region * reg, std::vector<std::pair<double, bool> > ranges, std::vector<TString> toExclude,
            RooDataSet * myMCDataSet = 0, double meanbw = 0, double meanb = 0, double meantt = 0) :
    name(name_), var(var_), myReg(reg), myMCData(myMCDataSet) {
        inclusive = (toExclude.size() == 0);
        if (myMCDataSet == 0) {
            std::vector<std::pair<RooDataSet*, RooRealVar*> > myMCDatasets = myReg->datasets;
            myMCData = (RooDataSet*) (myMCDatasets[0].first)->Clone(name_ + "_myMCDataset");
            for (unsigned int i = 1; i < myMCDatasets.size(); i++) {
                bool ex = false;
                for (unsigned int j = 0; j < toExclude.size(); j++) {
                    if (TString(myMCDatasets[i].first->GetName()).Contains(toExclude[j])) {
                        ex = true;
                        break;
                    }
                }
                if (ex)
                    continue;
                myMCData->append(*myMCDatasets[i].first);
            }
        }
        mean_bw = new RooRealVar(name + "_mean_bw", "Mean", 90.8, 60, 120);
        mean_cb = new RooRealVar(name + "_mean_cb", "Mean", 1.0, 0., 50.);
        sigma_bw = new RooRealVar(name + "_sigma_bw", "Width", 6.5, 1.0, 260.0);
        sigma_cb = new RooRealVar(name + "_sigma_cb", "Width", 2.3, 0., 260.0);
        n = new RooRealVar(name + "_n", "", 0.0, 5.0);
        alpha = new RooRealVar(name + "_alpha", "", 0.0, 5.0);
        lambda = new RooRealVar(name + "_lambda", "slope", -0.1, -5., 0.);
        //        s_bw = new RooRealVar(name + "_signal_bw", "signal", 800000, 0, 2000000);
        s_bw = new RooRealVar(name + "_signal_bw", "signal", meanbw, 0, 4 * meanbw);
        s_cb = new RooRealVar(name + "_signal_cb", "signal", 100, 0, 10000);
        //        b = new RooRealVar(name + "_background", "background yield", 5000, 0, 1000000);
        b = new RooRealVar(name + "_background", "background yield", meanb, 0, 4 * meanb);
        gauss_bw = new RooBreitWigner(name + "_gauss_bw", "gauss_bw", *myReg->VariablesMap[var], *mean_bw, *sigma_bw);
        cball = new RooCBShape(name + "_cball", "crystal ball", *myReg->VariablesMap[var], *mean_cb, *sigma_cb, *alpha, *n);
        expo = new RooExponential(name + "_expo", "exponential PDF", *myReg->VariablesMap[var], *lambda);
        bwxCryBall = new RooFFTConvPdf(name + "_bwxCryBall", "FFT Conv CryBall and BW", *myReg->VariablesMap[var],
                *gauss_bw, *cball);
        voig = new RooVoigtian(name + "_Voig", "BW conv. Gauss", *myReg->VariablesMap[var], *mean_bw, *sigma_cb, *sigma_bw);
        ttCont = new RooRealVar(name + "_ttCont", "ttCont", meantt, 0., 4 * meantt);
        topPdf = 0;
        stringstream s;
        for (unsigned int i = 0; (i + 1) < ranges.size(); i++) {
            s.str("");
            s << name << "_" << i;
            myReg->VariablesMap[var]->setRange(s.str().c_str(), ranges[i].first, ranges[i + 1].first);
            doFit.push_back(ranges[i].second);
        }
        if (inclusive) {
            int itop = -1;
            for (unsigned int j = 0; j < myReg->datasets.size(); j++) {
                if (TString(myReg->datasets[j].first->GetName()).Contains("TTFull")) {
                    itop = j;
                }
            }
            topPdf = new RooKeysPdf(name + "_toppdf", "toppdf", *myReg->VariablesMap[var], *myReg->datasets[itop].first);
            // ********* Version for low pt and 1 bjet in the window
            //            sum = new RooAddPdf(name + "_sum", "Voig and exponential PDF",
            //                    RooArgList(*voig, *expo), RooArgList(*s_bw, *b));
            sum = new RooAddPdf(name + "_sum", "Gaussian crystal ball and exponential PDF",
                    RooArgList(*bwxCryBall, *expo), RooArgList(*s_bw, *b));
            //            sum = new RooAddPdf(name + "_sum", "Gaussian crystal ball and exponential PDF",
            //                    RooArgList(*bwxCryBall, *expo, *topPdf), RooArgList(*s_bw, *b, *ttCont));

            // ********* Version for low pt and 1 bjet out of window
            //            sum = new RooAddPdf(name + "_sum", "Gaussian crystal ball and exponential PDF",
            //                    RooArgList(*bwxCryBall, *expo), RooArgList(*s_bw, *b));
            // ********* Version for high pt and 2 bjets
            //            sum = new RooAddPdf(name + "_sum", "Gaussian crystal ball and exponential PDF",
            //                    RooArgList(*bwxCryBall, *expo, *topPdf), RooArgList(*s_bw, *b, *ttCont));
        } else {
            sum = new RooAddPdf(name + "_sum", "Gaussian crystal ball and exponential PDF",
                    RooArgList(*bwxCryBall, *expo), RooArgList(*s_bw, *b));
        }
        results = 0;
    }

    ~DYinvestigators() {
        delete mean_bw;
        delete mean_cb;
        delete sigma_bw;
        delete sigma_cb;
        delete n;
        delete alpha;
        delete lambda;
        delete s_bw;
        delete s_cb;
        delete b;
        delete gauss_bw;
        delete cball;
        delete expo;
        delete bwxCryBall;
        delete ttCont;
        delete myMCData;
        delete sum;
        delete results;
    }

    RooPlot * Fit(bool doMC = true, bool doPrint = true, bool doPlot = false) {
        stringstream s;
        for (unsigned int i = 0; i < doFit.size(); i++) {
            if (doFit[i])
                s << name << "_" << i << ",";
        }
        if (doMC)
            results = sum->fitTo(*myMCData, RooFit::Range(s.str().c_str()), RooFit::Save(kTRUE), RooFit::Extended(), RooFit::Save(), SumW2Error(kTRUE));
        else
            results = sum->fitTo(*myReg->GetData(var), RooFit::Save(kTRUE), RooFit::Range(s.str().c_str()), RooFit::Extended(), RooFit::Save());
        double err = 0;
        if (inclusive)
            //            err = sqrt(pow(b->getError(), 2) + pow(ttCont->getError(), 2) + pow(s_bw->getError(), 2));
            err = sqrt(pow(b->getError(), 2) + pow(s_bw->getError(), 2));
        else
            err = sqrt(pow(b->getError(), 2) + pow(s_bw->getError(), 2));
        RooAbsReal* fracInt = 0;
        for (unsigned int i = 0; i < doFit.size(); i++) {
            s.str("");
            s << name << "_" << i;
            fracInt = sum->createIntegral(*myReg->VariablesMap[var], *myReg->VariablesMap[var], s.str().c_str());
            if (inclusive)
                //                sumEntries.push_back(fracInt->getVal()*(b->getVal() + s_bw->getVal() + ttCont->getVal()));
                sumEntries.push_back(fracInt->getVal()*(b->getVal() + s_bw->getVal()));
            else
                sumEntries.push_back(fracInt->getVal()*(b->getVal() + s_bw->getVal()));
            sumErrEntries.push_back(fracInt->getVal() * err);
        }
        delete fracInt;

        if (doPrint) {
            this->Print(doMC);
        }
        if (doPlot)
            return this->plot();
        return 0;
    }

    void Print(bool doMC = true) {
        cout << "Table for MC in " << name << endl;
        cout << "||";
        for (unsigned int i = 0; i < doFit.size(); i++) {
            cout << name << "_" << i << "|";
        }
        cout << endl;
        stringstream s;
        std::vector<std::pair<RooDataSet*, RooRealVar*> > myMCDatasets = myReg->datasets;
        double mcSum[3] = {0, 0, 0};
        for (unsigned int i = 0; i < myMCDatasets.size(); i++) {
            cout << "|" << string(myMCDatasets[i].first->GetName()).substr(3) << "|";
            for (unsigned int j = 0; j < doFit.size(); j++) {
                s.str("");
                s << name << "_" << j;
                cout << myMCDatasets[i].first->sumEntries(0, s.str().c_str()) << "|";
                mcSum[j] += myMCDatasets[i].first->sumEntries(0, s.str().c_str());
            }
            cout << endl;
        }
        cout << "|MCDataSet|";
        for (unsigned int j = 0; j < doFit.size(); j++) {
            s.str("");
            s << name << "_" << j;
            if (!doMC)
                cout << mcSum[j] << "|";
            else
                cout << myMCData->sumEntries(0, s.str().c_str()) << "|";
        }
        cout << endl;

        cout << "|BW.CB|";
        RooAbsReal* fracInt = 0;
        for (unsigned int j = 0; j < doFit.size(); j++) {
            s.str("");
            s << name << "_" << j;
            fracInt = bwxCryBall->createIntegral(*myReg->VariablesMap[var], *myReg->VariablesMap[var], s.str().c_str());
            double myErr = fracInt->getVal() * s_bw->getError();
            cout << fracInt->getVal() * s_bw->getVal() << " \\pm " << myErr << "|";
            //            fracInt = voig->createIntegral(*myReg->VariablesMap[var], *myReg->VariablesMap[var], s.str().c_str());
            //            cout << fracInt->getVal() * s_bw->getVal() << "|";
        }
        cout << endl;
        cout << "|expo|";
        for (unsigned int j = 0; j < doFit.size(); j++) {
            s.str("");
            s << name << "_" << j;
            fracInt = expo->createIntegral(*myReg->VariablesMap[var], *myReg->VariablesMap[var], s.str().c_str());
            double myErr = fracInt->getVal() * b->getError();
            cout << fracInt->getVal() * b->getVal() << " \\pm " << myErr << "|";
        }
        cout << endl;
        if (inclusive) {
            //            cout << "|ttCont|";
            //            for (unsigned int j = 0; j < doFit.size(); j++) {
            //                s.str("");
            //                s << name << "_" << j;
            //                fracInt = topPdf->createIntegral(*myReg->VariablesMap[var], *myReg->VariablesMap[var], s.str().c_str());
            //                double myErr = fracInt->getVal() * ttCont->getError();
            //                cout << fracInt->getVal() * ttCont->getVal() << " \\pm "<<myErr<<"|";
            //            }
            //            cout << endl;
        }
        if (fracInt != NULL)
            delete fracInt;

        if (!doMC) {
            cout << "|DataSet|";
            for (unsigned int j = 0; j < doFit.size(); j++) {
                s.str("");
                s << name << "_" << j;
                cout << myReg->GetData(var)->sumEntries(0, s.str().c_str()) << "|";
            }
        }
        cout << endl;
        cout << "|Sum fit|";
        for (unsigned int j = 0; j < doFit.size(); j++) {
            //            s.str("");
            //            s << name << "_" << j;
            cout << sumEntries[j] << "|";
        }
        cout << endl;
    }

    std::vector<double> getSumEntries() {
        return sumEntries;
    };

    std::vector<double> getSumErrEntries() {
        return sumErrEntries;
    };

    RooAddPdf * getModel() {
        return sum;
    }

    RooPlot * plot() {
        RooPlot * xFrame = myReg->VariablesMap[var]->frame(Title("Z-peak"));
        myMCData->plotOn(xFrame, DataError(RooAbsData::SumW2), RooFit::MarkerColor(kRed));
        sum->plotOn(xFrame);
        sum->plotOn(xFrame, RooFit::Components(*expo), RooFit::LineStyle(kDashed), RooFit::LineColor(kBlack));
        sum->plotOn(xFrame, RooFit::Components(*bwxCryBall), RooFit::LineStyle(kDashed), RooFit::LineColor(kGreen));
        //        sum->plotOn(xFrame, RooFit::Components(*voig), RooFit::LineStyle(kDashed), RooFit::LineColor(kGreen));
        //        sum->paramOn(xFrame, Layout(0.65), Format("NEU", AutoPrecision(1)), Parameters(RooArgList(*s_bw, *ttCont, *b, *mean_bw, *mean_cb,
        //                *sigma_bw, *sigma_cb)));
        sum->paramOn(xFrame, Layout(0.65), Format("NEU", AutoPrecision(1)), Parameters(RooArgList(*s_bw, *b, *mean_bw, *mean_cb,
                *sigma_bw, *sigma_cb)));
        return xFrame;
    }

    RooFitResult * GetFitResults()const {
        return results;
    }

    TString GetName()const {
        return name;
    }

private:
    TString name;
    TString var;
    std::vector<bool> doFit;
    RooRealVar * mean_bw;
    RooRealVar * mean_cb;
    RooRealVar * sigma_bw;
    RooRealVar * sigma_cb;
    RooRealVar * n;
    RooRealVar * alpha;
    RooRealVar * lambda;
    RooRealVar * s_bw;
    RooRealVar * s_cb;
    RooRealVar * b;
    RooBreitWigner * gauss_bw;
    RooCBShape * cball;
    RooExponential * expo;
    RooVoigtian * voig;
    Region * myReg;
    RooDataSet * myMCData;
    RooAddPdf * sum;
    RooFitResult * results;
    std::vector<double> sumEntries;
    std::vector<double> sumErrEntries;
    RooRealVar * ttCont;
    RooFFTConvPdf * bwxCryBall; //correct convolution
    bool inclusive;
    RooKeysPdf * topPdf;
};

// For pseudo-experiments

class BiasChecker {
public:

    BiasChecker(TString name_, TString var_, int N, Region * reg, std::vector<std::pair<double, bool> > ranges_,
            std::vector<TString> toExclude_, bool doPlot_ = false) : name(name_), var(var_), nPE(N), myReg(reg), doPlot(doPlot_) {
        for (unsigned int s = 0; s < ranges_.size(); s++)
            ranges.push_back(ranges_[s]);
        for (unsigned int s = 0; s < toExclude_.size(); s++)
            toExclude.push_back(toExclude_[s]);

        std::vector<std::pair<RooDataSet*, RooRealVar*> > myMCDatasets = myReg->datasets;
        baseMCData = (RooDataSet*) (myMCDatasets[0].first)->Clone(name_ + "_myMCDataset");
        for (unsigned int i = 1; i < myMCDatasets.size(); i++) {
            bool ex = false;
            for (unsigned int j = 0; j < toExclude.size(); j++) {
                if (TString(myMCDatasets[i].first->GetName()).Contains(toExclude[j])) {
                    ex = true;
                    break;
                }
            }
            if (ex)
                continue;
            baseMCData->append(*myMCDatasets[i].first);
        }
    }

    ~BiasChecker() {
        delete baseMCData;
        delete myReg;
    }

    RooKeysPdf * GetBasePdf() {
        return new RooKeysPdf(name + "_keysPdf", "main data shape", *myReg->VariablesMap[var], *baseMCData, RooKeysPdf::MirrorBoth);
    }

    void doPE() {
        RooRandom::randomGenerator()->SetSeed(1213563596);
        RooKeysPdf * forPData = this->GetBasePdf();
        stringstream s;
        Int_t rsize = ranges.size() - 1;
        Float_t means[rsize];
        Float_t errs[rsize];
        Float_t Mean_bw[2];
        Float_t Sigma_bw[2];
        Float_t Mean_cb[2];
        Float_t Sigma_cb[2];
        Float_t N[2];
        Float_t Alpha[2];
        Float_t Lambda[2];
        //        Float_t TtCont[2];
        out = new TFile(name + "_out.root", "recreate");
        res = new TTree("PETree", "PE results");
        res->Branch("rsize", &rsize, "rsize/I");
        res->Branch("means", means, "means[rsize]/F");
        res->Branch("errs", errs, "errs[rsize]/F");
        res->Branch("Mean_bw", Mean_bw, "Mean_bw[2]/F");
        res->Branch("Sigma_bw", Sigma_bw, "Sigma_bw[2]/F");
        res->Branch("Mean_cb", Mean_cb, "Mean_cb[2]/F");
        res->Branch("Sigma_cb", Sigma_cb, "Sigma_cb[2]/F");
        res->Branch("N", N, "N[2]/F");
        res->Branch("Alpha", Alpha, "Alpha[2]/F");
        res->Branch("Lambda", Lambda, "Lambda[2]/F");
        //        res->Branch("TtCont", TtCont, "TtCont[2]/F");

        for (int i = 0; i < nPE; i++) {
            cout << "---------------- " << i << endl;
            RooDataSet * pData = forPData->generate(*myReg->VariablesMap[var], 100000);
            s.str("");
            s << name << "_pData_" << i;
            pData->SetName(s.str().c_str());
            s.str("");
            s << name << "_" << var << "_" << i;
            DYinvestigators * myDY = new DYinvestigators(s.str().c_str(), var, myReg, ranges, toExclude, pData);
            RooPlot * pl = myDY->Fit(true, false, doPlot);
            RooFitResult * results = myDY->GetFitResults();

            Mean_bw[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_mean_bw"))->getVal();
            Sigma_bw[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_sigma_bw"))->getVal();
            Mean_cb[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_mean_cb"))->getVal();
            Sigma_cb[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_sigma_cb"))->getVal();
            N[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_n"))->getVal();
            Alpha[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_alpha"))->getVal();
            Lambda[0] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_lambda"))->getVal();
            //            RooRealVar* tmp = (RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_ttCont");
            //            if (tmp != NULL)
            //                TtCont[0] = tmp->getVal();
            //            else
            //                TtCont[0] = -1.;

            Mean_bw[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_mean_bw"))->getError();
            Sigma_bw[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_sigma_bw"))->getError();
            Mean_cb[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_mean_cb"))->getError();
            Sigma_cb[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_sigma_cb"))->getError();
            N[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_n"))->getError();
            Alpha[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_alpha"))->getError();
            Lambda[1] = ((RooRealVar*) results->floatParsFinal().find(myDY->GetName() + "_lambda"))->getError();
            //            if (tmp != NULL)
            //                TtCont[1] = tmp->getError();
            //            else
            //                TtCont[1] = -1.;
            //            if(results != NULL){
            //                cout<<"FitRes: "<<endl;
            //                results->Print();
            //            }
            std::vector<double> entries = myDY->getSumEntries();
            std::vector<double> entriesErr = myDY->getSumErrEntries();
            for (unsigned int iEnt = 0; iEnt < entries.size(); iEnt++) {
                means[iEnt] = entries[iEnt];
                errs[iEnt] = entriesErr[iEnt];
            }
            res->Fill();
            if (doPlot) {
                TCanvas c(s.str().c_str(), s.str().c_str());
                c.cd();
                pl->Draw();
                out->cd();
                c.Write();
            }
            delete myDY;
            delete pl;
            //            delete pData;
        }
        res->Write();
        out->Write();
        out->Close();
    }

private:
    TString name;
    TString var;
    int nPE;
    Region * myReg;
    bool doPlot;
    std::vector < std::pair<double, bool> > ranges;
    std::vector<TString> toExclude;
    RooDataSet * baseMCData;
    TFile * out;
    TTree * res;
};




#endif	/* DYINVESTIGATORS_H */

