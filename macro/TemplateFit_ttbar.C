/* 
 * File:   TemplateFit.C
 * Author: nadjieh
 *
 * Created on June 9, 2012, 3:57 PM
 */
#include "/opt/root/math/mathcore/inc/Math/Functor.h"
#include<iostream>
#include "TFile.h"
#include "TTree.h"
#include "../interface/HambFitter.h"
#include "../interface/RDS.h"
#include "../interface/RDSData.h"
#include "../interface/RDSRegion.h"
#include "TString.h"
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooMinuit.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooCategory.h"
#include "RooPlot.h"
#include "RooHistPdf.h"
#include "RooExponential.h"
#include "RooDataHist.h"
#include "RooPolynomial.h"
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

/*
 * 
 */

int main(int argc, char** argv) {
    double lumi = 19700.;
    TString treename = "rds_zbb";
    TString var = "";
    int step = 1000;
    Region * myReg;
    interval range;
    varInfo myInfo;
    TFile * ftmp = new TFile("atmp.root", "recreate");
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "treeName") {
            f++;
            std::string out(*(argv + f));
            treename = out.c_str();
        } else if (arg_fth == "variable") {
            f++;
            var = string(*(argv + f));
            f++;
            range.first = atof(string(*(argv + f)).c_str());
            f++;
            range.second = atof(string(*(argv + f)).c_str());
            myInfo[var] = range;
            cout << "var: " << var << endl;
            cout << "low: " << range.first << endl;
            cout << "high: " << range.second << endl;
        } else if (arg_fth == "step") {
            f++;
            std::string out(*(argv + f));
            step = (int) atof(out.c_str());
        } else if (arg_fth == "data") {
            if (var == "" || step == 1000) {
                cout << "first set var and step!" << endl;
                return 1;
            }
            f++;
            std::string out(*(argv + f));
            int pos = out.find(".root");
            std::string mydir = out.substr(0, pos);
            TFile * fdata = TFile::Open(out.c_str());
            ftmp->mkdir(mydir.c_str())->cd();
            //            TTree * myTree = myReg->GetDataInRegion((TTree*) fdata->Get(treename), step, true);
            TTree * myTree = (TTree*) fdata->Get(treename);
            myReg = new Region(myTree, myInfo);
            //            delete fdata;
        } else if (arg_fth == "mc") {
            if (var == "" || step == 1000) {
                cout << "first set var and step!" << endl;
                return 1;
            }
            f++;
            std::string out(*(argv + f));
            int pos = out.find(".root");
            std::string mydir = out.substr(0, pos);
            TFile * fMC = TFile::Open(out.c_str());
            ftmp->mkdir(mydir.c_str())->cd();
            //            TTree * myTree = myReg->GetDataInRegion((TTree*) fMC->Get(treename), step);
            TTree * myTree = (TTree*) fMC->Get(treename);
            //error
            f++;
            out = string(*(argv + f));
            double err = (double) atof(out.c_str());
            //Weight: number of processed events, cross section
            f++;
            out = string(*(argv + f));
            double nevt = (double) atof(out.c_str());
            f++;
            out = string(*(argv + f));
            double xsec = (double) atof(out.c_str());
            double weight = (xsec * lumi) / nevt;
            //is fixed?
            f++;
            out = string(*(argv + f));
            bool isFixed = (atof(out.c_str()) == 1.);
            string name_ = nameExtractor(string(fMC->GetName()));
            myReg->addMC(myTree, weight, err, isFixed, name_);
            //            delete fMC;
        }
    }

    //ttbar with diffMassaa
    //the ttbar id in the script
    std::vector<int> ids;
    ids.push_back(2);
    //the rest of MC
    std::vector<int> ids2;
    for (int i = 0; i < 10; i++) {
        if (i == 2)
            continue;
        ids2.push_back(i);
    }
    cout << "---------" << endl;

    //One could take PDF from binned dataset or from histograms
    //Make binned and unbinned RooDataSets from MC trees
    myReg->PrepareMCDataSets(var);
    std::vector<std::pair<RooDataSet*, RooRealVar*> > myMCDatasets = myReg->datasets;
    RooDataSet * myMCData = (RooDataSet*) (myMCDatasets[0].first)->Clone("myMCDataSet");
    for (unsigned int i = 1; i < myMCDatasets.size(); i++) {
        //        if (TString(myMCDatasets[i].first->GetName()).Contains("TTFullLep"))
        //            continue;
        myMCData->append(*myMCDatasets[i].first);
    }
    //Get unbinned data
    RooDataSet * myData = myReg->GetData(var);
    
    cout<<"Data: "<<myData->sumEntries(0)<<endl;
    cout<<"MCData: "<<myMCData->sumEntries(0)<<endl;
    //Fill Histograms from trees with appropriate luminosity weight
    // bins  =100 is very good for dimu mass
    // bins  =10 is very good for diff mass
    ////    myReg->FillHists(var, 100);
    //One could get rid of binning estimating the shape of ttbar in diMu mass with a line
    RooRealVar a0("a0", "a0", 64.3, 0., 100.);
    RooRealVar a1("a1", "a1", 9.0, 0., 20.);
    RooPolynomial ttDimu("ttDimu", "ttDimu", *myReg->VariablesMap[var], RooArgList(a0, a1), 0);
    RooRealVar b0("b0", "b0", 64.3, 0., 100.);
    RooRealVar b1("b1", "b1", 9.0, 0., 20.);
    RooPolynomial bkgDimu("bkgDimu", "bkgDimu", *myReg->VariablesMap[var], RooArgList(b0, b1), 0);
    RooRealVar lambda("lambda", "lambda", 0.1, 0., 10.);
    RooExponential expo("expo", "exponential PDF", *myReg->VariablesMap[var], lambda);

    RooPolynomial bkg("bkg", "bkg", *myReg->VariablesMap[var]);
    RooRealVar N_sig111("N_sig111", "N_sig111", 0.9, 0., 1.);
    RooRealVar N_bkg111("N_bkg111", "N_bkg111", 100., 0., 200.);

    // Binned dataset does not make any difference
    //    RooDataHist * myData_binned = new RooDataHist("binnedData", "binnedData", RooArgSet(*myReg->GetVar(var)), *myData);

    //Get PDF from histograms
    //    RooHistPdf p1sig = myReg->GetCombinedPdfFromHistogram(var, ids2, "sig");
    //    RooHistPdf p1bkg = myReg->GetCombinedPdfFromHistogram(var, ids, "bkg");
    RooRealVar N_sig1("N_sig1", "N_sig1", 1000., 0., 5000.);
    RooRealVar N_bkg1("N_bkg1", "N_bkg1", 5., 0., 1500.);
    RooRealVar N_sig11("N_sig11", "N_sig11", 1000., 0., 5000.);
    RooRealVar N_bkg11("N_bkg11", "N_bkg11", 5., 0., 1500.);
    //    RooAddPdf model1("model1", "model1", RooArgList(p1sig, p1bkg), RooArgList(N_sig1, N_bkg1));
    //    RooAddPdf model1("model1", "model1", RooArgList(p1sig), RooArgList(N_sig1));
    //    RooAddPdf model11("model11", "model11", RooArgList(p1sig, p1bkg), RooArgList(N_sig11, N_bkg11));
    RooAddPdf model111("model111", "model111", RooArgList(ttDimu, bkg), RooArgList(N_sig111));
    //    RooAddPdf model111("model111", "model111", RooArgList(expo, ttDimu), RooArgList(N_sig111));

    /*SCAN*/
    //    //    RooAbsReal* nll = model1.createNLL(*myData_binned, NumCPU(2));
    //    RooAbsReal* nll = model1.createNLL(*myData, NumCPU(2));
    //    // Minimize likelihood w.r.t all parameters before making plots
    //    RooMinuit(*nll).migrad();
    //    // Plot likelihood scan frac 
    //    RooPlot* frame1 = N_sig1.frame(Bins(10), Range(0., 5000.), Title("LL and profileLL in frac"));
    //    nll->plotOn(frame1, ShiftToZero());
    //    TFile * hplot = new TFile("scantt.root", "recreate");
    //    TCanvas * c2 = new TCanvas("N_sig1", "N_sig1");
    //    c2->cd();
    //    frame1->Draw();
    //    c2->Write();
    //    hplot->Write();
    //    hplot->Close();
    //    cout << "--- from Nll: " << N_sig1.getVal() << " +/- " << N_sig1.getError() << "\t" << N_bkg1.getVal() << " +/- " << N_bkg1.getError() << endl;
    //    /*End scan*/
    //    //    model11.fitTo(*myData_binned);
    //    model11.fitTo(*myData);
    //    cout << "--- from fit: " << N_sig11.getVal() << " +/- " << N_sig11.getError() << "\t" << N_bkg11.getVal() << " +/- " << N_bkg11.getError() << endl;
    //Do the fit and compare the results
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    model111.fitTo(*myData);
    cout << "--- from fit: " << N_sig111.getVal() << " +/- " << N_sig111.getError() << endl;
    cout << "--- from fit: " << N_bkg111.getVal() << " +/- " << N_bkg111.getError() << endl;
    cout << "--- from fit: " << a0.getVal() << " +/- " << a0.getError() << endl;
    cout << "--- from fit: " << a1.getVal() << " +/- " << a1.getError() << endl;
    cout << "--- from fit: " << lambda.getVal() << " +/- " << lambda.getError() << endl;
    double fracData3 = myData->sumEntries(0);
    cout << "Number of tt:" << fracData3 * (N_sig111.getVal())
            << "\\pm" << fracData3 * (N_sig111.getError()) << endl;
    cout << "Number of rest:" << fracData3 * (1. - N_sig111.getVal()) << endl;

    //    Plotting both PDFs for comparison
    RooPlot * varFram = ((RooRealVar*) myReg->GetVar(var))->frame();
    //    p1bkg.plotOn(varFram, LineColor(kBlue));
    //    p1sig.plotOn(varFram, LineColor(kRed));
    ttDimu.plotOn(varFram, LineColor(kBlue));
    bkg.plotOn(varFram, LineColor(kGreen));
    myData->plotOn(varFram);
    model111.plotOn(varFram, LineColor(kRed));
    //    RooPlot * varFramSig = ((RooRealVar*) myReg->GetVar(var))->frame();
    //    myData->plotOn(varFramSig);
    //    model1.plotOn(varFramSig, LineColor(kRed));
    TFile * hplot2 = new TFile("hplot_tt.root", "recreate");
    TCanvas * c = new TCanvas("tmp", "tmp");
    c->cd();
    varFram->Draw();
    c->Write();
    //    c = new TCanvas("tmp2", "tmp2");
    //    c->cd();
    //    varFramSig->Draw();
    //    c->Write();
    hplot2->Write();
    hplot2->Close();
    return 1;

    //Conclusion: Histograms are gitty!
}

/*
 
 //Get PDF from binned dataset
RooAddPdf p2sig = myReg->GetCombinedPdfFromBinnedDataSet(var, ids2, "sig");
RooAddPdf p2bkg = myReg->GetCombinedPdfFromBinnedDataSet(var, ids, "bkg");
RooRealVar N_sig2("N_sig2", "N_sig2", 1722., 1500., 1800.);
RooRealVar N_bkg2("N_bkg2", "N_bkg2", 57.749, 0., 150.);
RooRealVar N_sig22("N_sig22", "N_sig22", 1722., 1500., 1800.);
RooRealVar N_bkg22("N_bkg22", "N_bkg22", 57.749, 0., 150.);
RooAddPdf model2("model2", "model2", RooArgList(p2sig, p2bkg), RooArgList(N_sig2, N_bkg2));
RooAddPdf model22("model22", "model22", RooArgList(p2sig, p2bkg), RooArgList(N_sig22, N_bkg22));
RooAbsReal* nll2 = model2.createNLL(*myData, NumCPU(2));
// Minimize likelihood w.r.t all parameters before making plots
RooMinuit(*nll2).migrad();
// Plot likelihood scan frac 
RooPlot* frame2 = N_sig2.frame(Bins(10), Range(0., 5000.), Title("LL and profileLL in frac"));
nll2->plotOn(frame2, ShiftToZero());
TFile * hplot2 = new TFile("scantt2.root", "recreate");
c2 = new TCanvas("N_sig2", "N_sig2");
c2->cd();
frame2->Draw();
c2->Write();
hplot2->Write();
hplot2->Close();
cout << "--- from Nll (model2): " << N_sig2.getVal() << " +/- " << N_sig2.getError() << "\t" << N_bkg2.getVal() << " +/- " << N_bkg2.getError() << endl;
model22.fitTo(*myData);
cout << "--- from fit (model2): " << N_sig22.getVal() << " +/- " << N_sig22.getError() << "\t" << N_bkg22.getVal() << " +/- " << N_bkg22.getError() << endl;

 */
/*
 //One could take PDF from binned dataset or from histograms
    //Make binned and unbinned RooDataSets from MC trees
    myReg->PrepareMCDataSets(var);
    //Fill Histograms from trees with appropriate luminosity weight
    // bins  =100 is very good for dimu mass
    // bins  =10 is very good for diff mass
    myReg->FillHists(var, 100);

    //Get unbinned data
    RooDataSet * myData = myReg->GetData(var);
    // Binned dataset does not make any difference
    //    RooDataHist * myData_binned = new RooDataHist("binnedData", "binnedData", RooArgSet(*myReg->GetVar(var)), *myData);
 
 */