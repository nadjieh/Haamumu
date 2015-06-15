/* 
 * File:   ComposedFit.C
 * Author: nadjieh
 *
 * Created on June 4, 2015, 10:48 AM
 * Based on rf301_composition.C
 */


#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <ios>
#include <fstream>
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooDataHist.h"
#include "RooConstVar.h"
#include "RooPolyVar.h"
#include "RooPolynomial.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooSimultaneous.h"
#include "RooFitResult.h"
#include "RooCategory.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"
#include "TString.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TColorWheel.h"
#include "TColorGradient.h"
#include "RooVoigtian.h"
#include "RooCBShape.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooRandom.h"
#include <algorithm>
#include "SignalFitHelper.h"

using namespace std;
using namespace RooFit;

/*
 * 
 */

int main(int argc, char** argv) {
    TFile * f30 = 0;
    TFile * f40 = 0;
    TFile * f50 = 0;
    TFile * f60 = 0;
    RooDataSet * d30;
    RooDataSet * d40;
    RooDataSet * d50;
    RooDataSet * d60;
    RooDataSet * wd30;
    RooDataSet * wd40;
    RooDataSet * wd50;
    RooDataSet * wd60;
    RooRealVar* w30 = 0;
    RooRealVar* w40 = 0;
    RooRealVar* w50 = 0;
    RooRealVar* w60 = 0;
    RooRealVar* w = 0;
    TString sys = "";
    TString pref1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-";
    TString pref2 = "_LowJetPt10_Summer12_final_4_4.root";
    TString prefsys1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_";
    TString prefsys2 = "_Summer12_final_4_4.root";
    double fracMean = -1000.;
    double alphaMean = -1000.;
    double widthMean = -1000.;
    double nMean = -1000.;
    std::map< TString, RooAbsReal *> inputVars;
    inputVars["alpha"] = 0;
    inputVars["sigma"] = 0;
    inputVars["sigma_cb"] = 0;
    inputVars["width"] = 0;
    inputVars["n"] = 0;
    bool repeat = false;
    RooRealVar* frac = new RooRealVar("frac", "frac", 0.5, 0, 1);
    bool weighted = false;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "syst") {
            f++;
            std::string out(*(argv + f));
            sys = out;
            cout << "begin!" << endl;
        } else if (arg_fth == "correlation") {
            frac = new RooRealVar("frac", "frac", 0.609842, 0, 1);
            inputVars["alpha"] = new RooRealVar("alpha", "", 1.00325, 0, 2);
            inputVars["width"] = new RooRealVar("width", "", 0.0641421, 0, 1);
            inputVars["n"] = new RooRealVar("n", "", 3.49775, 0, 7);
        } else if (arg_fth == "frac") {
            f++;
            std::string out(*(argv + f));
            fracMean = std::atof(out.c_str());
            frac = new RooRealVar("frac", "frac", fracMean);
            inputVars["alpha"] = new RooRealVar("alpha", "", 0, 5);
        } else if (arg_fth == "alpha") {
            if (fracMean == -1000.) {
                cout << "First fix frac value!!" << endl;
                return -1;
            }
            f++;
            std::string out(*(argv + f));
            alphaMean = std::atof(out.c_str());
            inputVars["alpha"] = new RooRealVar("alpha", "", alphaMean);
            inputVars["width"] = new RooRealVar("width", "", 1, 0, 5);
        } else if (arg_fth == "width") {
            if (alphaMean == -1000.) {
                cout << "First fix alpha (after frac) value!!" << endl;
                return -1;
            }
            f++;
            std::string out(*(argv + f));
            widthMean = std::atof(out.c_str());
            inputVars["width"] = new RooRealVar("width", "", widthMean);
            inputVars["n"] = new RooRealVar("n", "", 0, 10);
        } else if (arg_fth == "n") {
            if (widthMean == -1000.) {
                cout << "First fix width (after frac and alpha) value!!" << endl;
                return -1;
            }
            f++;
            std::string out(*(argv + f));
            nMean = std::atof(out.c_str());
            inputVars["n"] = new RooRealVar("n", "", nMean);
            repeat = false;
        } else if (arg_fth == "weighted") {
            std::string out(*(argv + f));
            weighted = true;
        }
    }
    RooRealVar * mass = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
    RooRealVar * masssigma = new RooRealVar("eventSelectionamassMu", "masssigma", 20, 70);
    RooRealVar * masssigmacb = new RooRealVar("eventSelectionamassMu", "masssigmacb", 20, 70);
    RooRealVar * massmean = new RooRealVar("eventSelectionamassMu", "massmean", 20, 70);
    RooRealVar * sigma0 = new RooRealVar("sigma0", "sigma0", -0.02, -1, 1);
    RooRealVar * sigma1 = new RooRealVar("sigma1", "sigma1", 0.01, -1, 1);
    inputVars["sigma"] = new RooPolyVar("sigma", "sigma", *masssigma, RooArgSet(*sigma0, *sigma1));

    RooRealVar * sigma_cb0 = new RooRealVar("sigma_cb0", "sigma_cb0", -0.05, -1, 1);
    RooRealVar * sigma_cb1 = new RooRealVar("sigma_cb1", "sigma_cb1", 0.02, -1, 1);
    inputVars["sigma_cb"] = new RooPolyVar("sigma_cb", "sigma_cb", *masssigmacb, RooArgSet(*sigma_cb0, *sigma_cb1));

    RooRealVar * leptonWeight = new RooRealVar("LeptonsReweightingweight", "LeptonsReweightingweight", 0, 2.);
    RooRealVar * btagWeightT = new RooRealVar("BtaggingReweightingT", "BtaggingReweightingT", -2., 2.);
    RooRealVar * btagWeightL = new RooRealVar("BtaggingReweightingL", "BtaggingReweightingL", -2., 2.);
    RooRealVar * puWeight = new RooRealVar("lumiReweightingLumiWeight", "lumiReweightingLumiWeight", 0, 2.);
    RooFormulaVar * Weight30 = new RooFormulaVar("Weight30", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight40 = new RooFormulaVar("Weight40", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight50 = new RooFormulaVar("Weight50", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight60 = new RooFormulaVar("Weight60", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight = new RooFormulaVar("Weight", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    if (sys == "") {

        f30 = TFile::Open(pref1 + "30" + pref2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        d30->Print();
        //        RooPolynomial sigma30("sigma30", "sigma30", *masssigma, RooArgList());
        //        RooDataSet * forsigma30 = sigma30.generate(*masssigma, t30->GetEntries());
        //        d30->merge(forsigma30);
        //        RooPolynomial sigmacb30("sigmacb30", "sigmacb30", *masssigmacb, RooArgList());
        //        RooDataSet * forsigmacb30 = sigmacb30.generate(*masssigmacb, t30->GetEntries());
        //        d30->merge(forsigmacb30);
        //        RooPolynomial mean30("mean30", "mean30", *massmean, RooArgList());
        //        RooDataSet * formean30 = mean30.generate(*massmean, t30->GetEntries());
        //        d30->merge(formean30);
        //        d30->Print();
        w30 = (RooRealVar*) d30->addColumn(*Weight30);
        wd30 = new RooDataSet(d30->GetName(), d30->GetTitle(), d30, *d30->get(), 0, w30->GetName());
        wd30->Print();

        f40 = TFile::Open(pref1 + "40" + pref2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        d40->Print();
        //        RooPolynomial sigma40("sigma40", "sigma40", *masssigma, RooArgList());
        //        RooDataSet * forsigma40 = sigma40.generate(*masssigma, t40->GetEntries());
        //        d40->merge(forsigma40);
        //        RooPolynomial sigmacb40("sigmacb40", "sigmacb40", *masssigmacb, RooArgList());
        //        RooDataSet * forsigmacb40 = sigmacb40.generate(*masssigmacb, t40->GetEntries());
        //        d40->merge(forsigmacb40);
        //        RooPolynomial mean40("mean40", "mean40", *massmean, RooArgList());
        //        RooDataSet * formean40 = mean40.generate(*massmean, t40->GetEntries());
        //        d40->merge(formean40);
        //        d40->Print();
        w40 = (RooRealVar*) d40->addColumn(*Weight40);
        wd40 = new RooDataSet(d40->GetName(), d40->GetTitle(), d40, *d40->get(), 0, w40->GetName());
        wd40->Print();

        f50 = TFile::Open(pref1 + "50" + pref2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        d50->Print();
        //        RooPolynomial sigma50("sigma50", "sigma50", *masssigma, RooArgList());
        //        RooDataSet * forsigma50 = sigma50.generate(*masssigma, t50->GetEntries());
        //        d50->merge(forsigma50);
        //        RooPolynomial sigmacb50("sigmacb50", "sigmacb50", *masssigmacb, RooArgList());
        //        RooDataSet * forsigmacb50 = sigmacb50.generate(*masssigmacb, t50->GetEntries());
        //        d50->merge(forsigmacb50);
        //        RooPolynomial mean50("mean50", "mean50", *massmean, RooArgList());
        //        RooDataSet * formean50 = mean50.generate(*massmean, t50->GetEntries());
        //        d50->merge(formean50);
        //        d50->Print();
        w50 = (RooRealVar*) d50->addColumn(*Weight50);
        wd50 = new RooDataSet(d50->GetName(), d50->GetTitle(), d50, *d50->get(), 0, w50->GetName());
        wd50->Print();

        f60 = TFile::Open(pref1 + "60" + pref2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        d60->Print();
        //        RooPolynomial sigma60("sigma60", "sigma60", *masssigma, RooArgList());
        //        RooDataSet * forsigma60 = sigma60.generate(*masssigma, t60->GetEntries() - 1);
        //        d60->merge(forsigma60);
        //        RooPolynomial sigmacb60("sigmacb60", "sigmacb60", *masssigmacb, RooArgList());
        //        RooDataSet * forsigmacb60 = sigmacb60.generate(*masssigmacb, t60->GetEntries() - 1);
        //        d60->merge(forsigmacb60);
        //        RooPolynomial mean60("mean60", "mean60", *massmean, RooArgList());
        //        RooDataSet * formean60 = mean60.generate(*massmean, t60->GetEntries() - 1);
        //        d60->merge(formean60);
        //        d60->Print();
        w60 = (RooRealVar*) d60->addColumn(*Weight60);
        wd60 = new RooDataSet(d60->GetName(), d60->GetTitle(), d60, *d60->get(), 0, w60->GetName());
        wd60->Print();


    } else {
        f30 = TFile::Open(sys + TString("_") + prefsys1 + "30" + prefsys2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w30 = (RooRealVar*) d30->addColumn(*Weight30);
        wd30 = new RooDataSet(d30->GetName(), d30->GetTitle(), d30, *d30->get(), 0, w30->GetName());

        f40 = TFile::Open(sys + TString("_") + prefsys1 + "40" + prefsys2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w40 = (RooRealVar*) d40->addColumn(*Weight40);
        wd40 = new RooDataSet(d40->GetName(), d40->GetTitle(), d40, *d40->get(), 0, w40->GetName());

        f50 = TFile::Open(sys + TString("_") + prefsys1 + "50" + prefsys2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w50 = (RooRealVar*) d50->addColumn(*Weight50);
        wd50 = new RooDataSet(d50->GetName(), d50->GetTitle(), d50, *d50->get(), 0, w50->GetName());

        f60 = TFile::Open(sys + TString("_") + prefsys1 + "60" + prefsys2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w60 = (RooRealVar*) d60->addColumn(*Weight60);
        wd60 = new RooDataSet(d60->GetName(), d60->GetTitle(), d60, *d60->get(), 0, w60->GetName());

    }
    cout << "begin ..." << endl;
    RooCategory sampleWeighted("sampleWeighted", "sampleWeighted");
    sampleWeighted.defineType("p30");
    sampleWeighted.defineType("p40");
    sampleWeighted.defineType("p50");
    sampleWeighted.defineType("p60");




    RooDataSet * combDataWeighted = new RooDataSet("combDataWeighted", "combined data", RooArgSet(*mass, *leptonWeight, *btagWeightL,
            *btagWeightT, *puWeight, *massmean, *masssigma, *masssigmacb),
            Index(sampleWeighted),
            Import("p30", *wd30),
            Import("p40", *wd40),
            Import("p50", *wd50),
            Import("p60", *wd60)
            );
    combDataWeighted->Print();
    w = (RooRealVar*) combDataWeighted->addColumn(*Weight);
    RooDataSet * wcombDataWeighted = new RooDataSet(combDataWeighted->GetName(), combDataWeighted->GetTitle(), combDataWeighted,
            *combDataWeighted->get(), 0, w->GetName());
    wcombDataWeighted->Print();
    RooAddPdf * m30 = VoigCBMaker(30, mass, massmean, inputVars, frac);
    RooAddPdf * m40 = VoigCBMaker(40, mass, massmean, inputVars, frac);
    RooAddPdf * m50 = VoigCBMaker(50, mass, massmean, inputVars, frac);
    RooAddPdf * m60 = VoigCBMaker(60, mass, massmean, inputVars, frac);

    RooSimultaneous simPdfWeighted("simPdfWeighted", "simultaneous pdf", sampleWeighted);
    simPdfWeighted.addPdf(*m30, "p30");
    simPdfWeighted.addPdf(*m40, "p40");
    simPdfWeighted.addPdf(*m50, "p50");
    simPdfWeighted.addPdf(*m60, "p60");

    RooFitResult * fr = 0;


    fr = simPdfWeighted.fitTo(*combDataWeighted, RooFit::Save(), RooFit::SumW2Error(kTRUE));
    return 10;
    PrintFr(fr);
    stringstream myVal;
    if (repeat) {
        if (sys != "")
            myVal << "./SimFit syst " << sys;
        else
            myVal << "./SimFit ";
        if (((RooRealVar*) fr->floatParsFinal().find("frac")) != 0) {
            cout << "HERE frac >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << ((RooRealVar*) fr->floatParsFinal().find("frac"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("alpha")) != 0) {
            cout << "HERE alpha >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << ((RooRealVar*) fr->floatParsFinal().find("alpha"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("width")) != 0) {
            cout << "HERE width >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << ((RooRealVar*) fr->floatParsFinal().find("width"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("n")) != 0) {
            cout << "HERE n >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << widthMean << " n " << ((RooRealVar*) fr->floatParsFinal().find("n"))->getVal();
        }
        if (weighted)
            myVal << " weighted";
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << myVal.str() << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

        system(myVal.str().c_str());
    } else {
        myVal.str("");
        if (sys != "")
            myVal << "./SimFit syst " << sys;
        else
            myVal << "./SimFit ";
        myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << widthMean << " n " << nMean;
        if (weighted)
            myVal << " weighted\n";

        std::ofstream log("fullSyst.sh", std::ios_base::app | std::ios_base::out);
        log << myVal.str();

    }





    RooPlot* frame1 = mass->frame(Title("30 GeV sample"));
    RooPlot* frame2 = mass->frame(Title("40 GeV sample"), RooFit::Binning(100));
    RooPlot* frame3 = mass->frame(Title("50 GeV sample"), RooFit::Binning(100));
    RooPlot* frame4 = mass->frame(Title("60 GeV sample"));

    cout << "Weighted data" << endl;
    combDataWeighted->plotOn(frame1, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p30"), RooFit::Binning(100));
    simPdfWeighted.plotOn(frame1, Slice(sampleWeighted, "p30"), ProjWData(sampleWeighted, *combDataWeighted));
    simPdfWeighted.plotOn(frame1, Slice(sampleWeighted, "p30"), Components("tmp_M30"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed));
    simPdfWeighted.plotOn(frame1, Slice(sampleWeighted, "p30"), Components("cball_M30"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    combDataWeighted->plotOn(frame2, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p40"));
    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), ProjWData(sampleWeighted, *combDataWeighted));
    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), Components("tmp_M40"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed));
    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), Components("cball_M40"), ProjWData(sampleWeighted, * combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    combDataWeighted->plotOn(frame3, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p50"));
    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), ProjWData(sampleWeighted, *combDataWeighted));
    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), Components("tmp_M50"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed));
    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), Components("cball_M50"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    combDataWeighted->plotOn(frame4, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p60"));
    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), ProjWData(sampleWeighted, *combDataWeighted), RooFit::Binning(100));
    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), Components("tmp_M60"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed));
    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), Components("cball_M60"), ProjWData(sampleWeighted, *combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    TCanvas* c = new TCanvas("SimultaneousFit", "SimultaneousFit", 1600, 800);
    c->Divide(2, 2);
    c->cd(1);
    gPad->SetLeftMargin(0.05);
    frame1->GetYaxis()->SetTitleOffset(0.9);
    frame1->Draw();
    c->cd(2);
    gPad->SetLeftMargin(0.05);
    frame2->GetYaxis()->SetTitleOffset(0.9);
    frame2->Draw();
    c->cd(3);
    gPad->SetLeftMargin(0.05);
    frame3->GetYaxis()->SetTitleOffset(0.9);
    frame3->Draw();
    c->cd(4);
    gPad->SetLeftMargin(0.05);
    frame4->GetYaxis()->SetTitleOffset(0.9);
    frame4->Draw();

    c->SaveAs(sys + "compweighted_graph_SimFit.C");



#ifdef INTERMEDIATE

    /*
     * Pseudo data for intermediate points
     */
    TF1 * fsig = new TF1("fsig", "-0.0256989 +(x*0.0102457)", 20., 70.);
    TF1 * fsigcb = new TF1("fsigcb", "-0.0498343 +(x*0.0183338)", 20., 70.);
    frac = new RooRealVar("frac", "frac", 0.609842);
    inputVars["alpha"] = new RooRealVar("alpha", "", 1.00325);
    inputVars["width"] = new RooRealVar("width", "", 0.0641421);
    inputVars["n"] = new RooRealVar("n", "", 3.49775);
    inputVars["sigma"] = new RooRealVar("sigma", "", fsig->Eval(35));
    inputVars["sigma_cb"] = new RooRealVar("sigma_cb", "", fsigcb->Eval(35));
    RooAddPdf * m35 = VoigCBMaker(35, mass, inputVars, frac);
    RooDataSet * d35 = m35->generate(*mass, 6000);
    inputVars["sigma"] = new RooRealVar("sigma", "", fsig->Eval(45));
    inputVars["sigma_cb"] = new RooRealVar("sigma_cb", "", fsigcb->Eval(45));
    RooAddPdf * m45 = VoigCBMaker(45, mass, inputVars, frac);
    RooDataSet * d45 = m45->generate(*mass, 6000);
    inputVars["sigma"] = new RooRealVar("sigma", "", fsig->Eval(55));
    inputVars["sigma_cb"] = new RooRealVar("sigma_cb", "", fsigcb->Eval(55));
    RooAddPdf * m55 = VoigCBMaker(55, mass, inputVars, frac);
    RooDataSet * d55 = m55->generate(*mass, 6000);
    inputVars["sigma"] = new RooRealVar("sigma", "", fsig->Eval(65));
    inputVars["sigma_cb"] = new RooRealVar("sigma_cb", "", fsigcb->Eval(65));
    RooAddPdf * m65 = VoigCBMaker(65, mass, inputVars, frac);
    RooDataSet * d65 = m65->generate(*mass, 6000);

    frac = new RooRealVar("frac", "frac", 0.5, 0, 1);
    inputVars["alpha"] = new RooRealVar("alpha", "", 0, 5);
    inputVars["width"] = new RooRealVar("width", "", 1, 0., 5);
    inputVars["n"] = new RooRealVar("n", "", 0, 10);
    inputVars["sigma"] = new RooRealVar("sigma", "", 0, 2.5);
    inputVars["sigma_cb"] = new RooRealVar("sigma_cb", "", 2.3, 0, 260.);
    RooCategory sampleIn("sampleIn", "sampleIn");
    sampleIn.defineType("p35");
    sampleIn.defineType("p45");
    sampleIn.defineType("p55");
    sampleIn.defineType("p65");

    RooDataSet combDataIn("combDataIn", "combined data", *mass, Index(sampleIn),
            Import("p35", *d35),
            Import("p45", *d45),
            Import("p55", *d55),
            Import("p65", *d65)
            );

    RooSimultaneous simPdfInt("simPdfInt", "simultaneous pdf", sampleIn);
    simPdfInt.addPdf(*m35, "p35");
    simPdfInt.addPdf(*m45, "p45");
    simPdfInt.addPdf(*m55, "p55");
    simPdfInt.addPdf(*m65, "p65");
    RooFitResult * frIn = simPdfInt.fitTo(combDataIn, RooFit::Save());

    RooPlot* framIn1 = mass->frame(Title("35 GeV sampleIn"));
    combDataIn.plotOn(framIn1, Cut("sampleIn==sampleIn::p35"), RooFit::Binning(100));
    simPdfInt.plotOn(framIn1, Slice(sampleIn, "p35"), ProjWData(sampleIn, combDataIn));
    simPdfInt.plotOn(framIn1, Slice(sampleIn, "p35"), Components("tmp_M35"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed));
    simPdfInt.plotOn(framIn1, Slice(sampleIn, "p35"), Components("cball_M35"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed), LineColor(kRed));

    RooPlot* framIn2 = mass->frame(Title("45 GeV sampleIn"), RooFit::Binning(100));
    combDataIn.plotOn(framIn2, Cut("sampleIn==sampleIn::p45"));
    simPdfInt.plotOn(framIn2, Slice(sampleIn, "p45"), ProjWData(sampleIn, combDataIn));
    simPdfInt.plotOn(framIn2, Slice(sampleIn, "p45"), Components("tmp_M45"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed));
    simPdfInt.plotOn(framIn2, Slice(sampleIn, "p45"), Components("cball_M45"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed), LineColor(kRed));

    RooPlot* framIn3 = mass->frame(Title("55 GeV sampleIn"), RooFit::Binning(100));
    combDataIn.plotOn(framIn3, Cut("sampleIn==sampleIn::p55"));
    simPdfInt.plotOn(framIn3, Slice(sampleIn, "p55"), ProjWData(sampleIn, combDataIn));
    simPdfInt.plotOn(framIn3, Slice(sampleIn, "p55"), Components("tmp_M55"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed));
    simPdfInt.plotOn(framIn3, Slice(sampleIn, "p55"), Components("cball_M55"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed), LineColor(kRed));

    RooPlot* framIn4 = mass->frame(Title("65 GeV sampleIn"));
    combDataIn.plotOn(framIn4, Cut("sampleIn==sampleIn::p65"));
    simPdfInt.plotOn(framIn4, Slice(sampleIn, "p65"), ProjWData(sampleIn, combDataIn), RooFit::Binning(100));
    simPdfInt.plotOn(framIn4, Slice(sampleIn, "p65"), Components("tmp_M65"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed));
    simPdfInt.plotOn(framIn4, Slice(sampleIn, "p65"), Components("cball_M65"), ProjWData(sampleIn, combDataIn), LineStyle(kDashed), LineColor(kRed));

    TCanvas* c3 = new TCanvas("SimultaneousFitIn", "SimultaneousFitIn", 1600, 800);
    c3->Divide(2, 2);
    c3->cd(1);
    gPad->SetLeftMargin(0.05);
    framIn1->GetYaxis()->SetTitleOffset(0.9);
    framIn1->Draw();
    c3->cd(2);
    gPad->SetLeftMargin(0.05);
    framIn2->GetYaxis()->SetTitleOffset(0.9);
    framIn2->Draw();
    c3->cd(3);
    gPad->SetLeftMargin(0.05);
    framIn3->GetYaxis()->SetTitleOffset(0.9);
    framIn3->Draw();
    c3->cd(4);
    gPad->SetLeftMargin(0.05);
    framIn4->GetYaxis()->SetTitleOffset(0.9);
    framIn4->Draw();

    c3->SaveAs(sys + "Graph_SimFitIn.C");
#endif
#ifdef TESTONPD
    /*
     * Test on a pseudo data with background using functional form for parameters
     * Mass = 47 GeV
     */

    //Data production

    double Mass = 47;
    RooFormulaVar sigma_cb_model("sigma_cb_model", "-0.4756193+0.04638364*@0 -0.0004420156*(@0^2) -7.566989e-07*(@0^3) -1.041907e-08*(@0^4) +8.410242e-10*(@0^5)"
            , RooArgList(*mass));
    RooRealVar mean_model("mean_model", "mean", Mass);
    RooFormulaVar sigma_model("sigma_model", "(0.010226*@0)-0.0215593", RooArgList(*mass));
    RooRealVar width_model("width_model", "width", inputVars["width"]->getVal());
    RooVoigtian Voig_model("tmp", "", *mass, mean_model, width_model, sigma_model);
    RooRealVar n_model("n_model", "", inputVars["n"]->getVal());
    RooRealVar alpha_model("alpha_model", "", inputVars["alpha"]->getVal());
    RooCBShape CB_model("cball_model", "crystal ball", *mass, mean_model, sigma_cb_model, alpha_model, n_model);
    RooRealVar frac_model("frac_model", "frac", frac->getVal());
    RooAddPdf Voig2_model("sum_model", "Gaussian crystal ball and Voig PDF", RooArgList(Voig_model, CB_model), RooArgList(frac_model));

    RooRealVar beta_model("beta_model", "", -0.05);
    RooExponential bkg_model("bkg_model", "", *mass, beta_model);
    RooRealVar frac_SB("frac_SB", "frac_SB", 0.2);

    RooAddPdf model_SB("model_SB", "", RooArgList(Voig2_model, bkg_model), RooArgList(frac_SB));

    RooDataSet * dModel = model_SB.generate(*mass, 5000);

    //Modeling the data for fitting
    RooFormulaVar sigma_cb_fit("sigma_cb_fit", "-0.4756193+0.04638364*@0 -0.0004420156*(@0^2) -7.566989e-07*(@0^3) -1.041907e-08*(@0^4) +8.410242e-10*(@0^5)"
            , RooArgList(*mass));
    RooRealVar mean_fit("mean_fit", "mean", 20., 70.);
    RooFormulaVar sigma_fit("sigma_fit", "(0.010226*@0)-0.0215593", RooArgList(*mass));
    RooRealVar width_fit("width_fit", "width", 1, 0., 5);
    RooVoigtian Voig_fit("tmp_fit", "", *mass, mean_fit, width_fit, sigma_fit);
    RooRealVar n_fit("n_fit", "", 0, 10);
    RooRealVar alpha_fit("alpha_fit", "", 0, 5);
    RooCBShape CB_fit("cball_fit", "crystal ball", *mass, mean_fit, sigma_cb_fit, alpha_fit, n_fit);
    RooRealVar frac_fit("frac_fit", "frac", 0.5, 0., 1);
    RooAddPdf Voig2_fit("sum_fit", "Gaussian crystal ball and Voig PDF", RooArgList(Voig_fit, CB_fit), RooArgList(frac_fit));

    RooRealVar beta_fit("beta_fit", "", -0.5, 0.5);
    RooExponential bkg_fit("bkg_fit", "", *mass, beta_fit);
    RooRealVar fit_frac_SB("fit_frac_SB", "fit_frac_SB", 0., 1.);

    RooAddPdf fit_SB("fit_SB", "", RooArgList(Voig2_fit, bkg_fit), RooArgList(fit_frac_SB));

    fit_SB.fitTo(*dModel, RooFit::Save());
    RooPlot * frame5 = mass->frame();
    dModel->plotOn(frame5);
    fit_SB.plotOn(frame5, RooFit::Components(Voig2_fit), RooFit::LineColor(kBlue));
    fit_SB.plotOn(frame5, RooFit::Components(Voig_fit), RooFit::LineColor(kGreen + 2), RooFit::LineStyle(kDashed));
    fit_SB.plotOn(frame5, RooFit::Components(CB_fit), RooFit::LineColor(kOrange - 2), RooFit::LineStyle(kDashed));
    fit_SB.plotOn(frame5, RooFit::Components(bkg_fit), RooFit::LineColor(kRed));
    fit_SB.plotOn(frame5, RooFit::LineColor(kBlack));
    TCanvas* c4 = new TCanvas("TestParam", "TestParam", 1600, 800);
    c4->cd();
    c4->SetLeftMargin(0.05);
    frame5->GetYaxis()->SetTitleOffset(0.9);
    frame5->Draw();

    c4->SaveAs(sys + "Graph_TestParam.C");
#endif

    return 0;
}



