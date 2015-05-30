/* 
 * File:   SimultaneousFit.C
 * Author: nadjieh
 *
 * Created on May 20, 2015, 2:47 PM
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
#include <map>
using namespace std;
using namespace RooFit;

void PrintFr(RooFitResult * fr) {
    cout << "\n\n\nCorrelations: " << endl;
    TString syst = "_M30";
    cout << "\t" << syst << " ===================== " << endl;
    cout << "\talpha,n: " << fr->correlation("alpha" + syst, "n" + syst) << endl;
    cout << "\talpha,width: " << fr->correlation("width" + syst, "alpha" + syst) << endl;
    cout << "\talpha,frac: " << fr->correlation("frac" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma_cb: " << fr->correlation("sigma_cb" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma: " << fr->correlation("sigma" + syst, "alpha" + syst) << endl;
    cout << "\talpha,mean: " << fr->correlation("mean" + syst, "alpha" + syst) << endl;
    //    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    //    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    //    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma_cb: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,mean: " << fr->correlation("mean" + syst, "width" + syst) << endl;
    cout << "\tsigma_cb,sigma: " << fr->correlation("sigma_cb" + syst, "sigma" + syst) << endl;
    cout << "\tsigma_cb,mean: " << fr->correlation("mean" + syst, "sigma_cb" + syst) << endl;
    cout << "\tsigma,mean: " << fr->correlation("mean" + syst, "sigma" + syst) << endl;
    syst = "_M40";
    cout << "\t" << syst << " ===================== " << endl;
    cout << "\talpha,n: " << fr->correlation("alpha" + syst, "n" + syst) << endl;
    cout << "\talpha,width: " << fr->correlation("width" + syst, "alpha" + syst) << endl;
    cout << "\talpha,frac: " << fr->correlation("frac" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma_cb: " << fr->correlation("sigma_cb" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma: " << fr->correlation("sigma" + syst, "alpha" + syst) << endl;
    cout << "\talpha,mean: " << fr->correlation("mean" + syst, "alpha" + syst) << endl;
    //    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    //    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    //    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma_cb: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,mean: " << fr->correlation("mean" + syst, "width" + syst) << endl;
    cout << "\tsigma_cb,sigma: " << fr->correlation("sigma_cb" + syst, "sigma" + syst) << endl;
    cout << "\tsigma_cb,mean: " << fr->correlation("mean" + syst, "sigma_cb" + syst) << endl;
    cout << "\tsigma,mean: " << fr->correlation("mean" + syst, "sigma" + syst) << endl;
    syst = "_M50";
    cout << "\t" << syst << " ===================== " << endl;
    cout << "\talpha,n: " << fr->correlation("alpha" + syst, "n" + syst) << endl;
    cout << "\talpha,width: " << fr->correlation("width" + syst, "alpha" + syst) << endl;
    cout << "\talpha,frac: " << fr->correlation("frac" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma_cb: " << fr->correlation("sigma_cb" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma: " << fr->correlation("sigma" + syst, "alpha" + syst) << endl;
    cout << "\talpha,mean: " << fr->correlation("mean" + syst, "alpha" + syst) << endl;
    //    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    //    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    //    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma_cb: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,mean: " << fr->correlation("mean" + syst, "width" + syst) << endl;
    cout << "\tsigma_cb,sigma: " << fr->correlation("sigma_cb" + syst, "sigma" + syst) << endl;
    cout << "\tsigma_cb,mean: " << fr->correlation("mean" + syst, "sigma_cb" + syst) << endl;
    cout << "\tsigma,mean: " << fr->correlation("mean" + syst, "sigma" + syst) << endl;
    syst = "_M60";
    cout << "\t" << syst << " ===================== " << endl;
    cout << "\talpha,n: " << fr->correlation("alpha" + syst, "n" + syst) << endl;
    cout << "\talpha,width: " << fr->correlation("width" + syst, "alpha" + syst) << endl;
    cout << "\talpha,frac: " << fr->correlation("frac" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma_cb: " << fr->correlation("sigma_cb" + syst, "alpha" + syst) << endl;
    cout << "\talpha,sigma: " << fr->correlation("sigma" + syst, "alpha" + syst) << endl;
    cout << "\talpha,mean: " << fr->correlation("mean" + syst, "alpha" + syst) << endl;
    //    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    //    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    //    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    //    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    //    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma_cb: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,sigma: " << fr->correlation("sigma_cb" + syst, "width" + syst) << endl;
    cout << "\twidth,mean: " << fr->correlation("mean" + syst, "width" + syst) << endl;
    cout << "\tsigma_cb,sigma: " << fr->correlation("sigma_cb" + syst, "sigma" + syst) << endl;
    cout << "\tsigma_cb,mean: " << fr->correlation("mean" + syst, "sigma_cb" + syst) << endl;
    cout << "\tsigma,mean: " << fr->correlation("mean" + syst, "sigma" + syst) << endl;
}

RooCBShape * CBMaker(double Mass, RooRealVar * mass, RooRealVar * mean,
        RooRealVar * sigma_cb = 0, RooRealVar * n = 0, RooRealVar * alpha = 0) {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    if (n == 0)
        n = new RooRealVar("n" + Name, "" + Name, 0, 10);
    if (alpha == 0)
        alpha = new RooRealVar("alpha" + Name, "" + Name, 0, 5);
    if (sigma_cb == 0)
        sigma_cb = new RooRealVar("sigma_cb" + Name, "Width" + Name, 2.3, 0, 260.);
    //        sigma_cb = new RooRealVar("sigma_cb" + Name, "Width" + Name, widthSigmaCB, 0., 2 * widthSigmaCB);
    RooCBShape * CB = new RooCBShape("cball" + Name, "crystal ball" + Name, *mass, *mean, *sigma_cb, *alpha, *n);
    return CB;
}

RooVoigtian * VoigMaker(double Mass, RooRealVar * mass, RooRealVar * mean,
        RooRealVar * sigma = 0, RooRealVar * width = 0) {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    if (sigma == 0)
        sigma = new RooRealVar("sigma" + Name, "sigma" + Name, 0, 2.5);
    //        sigma = new RooRealVar("sigma" + Name, "sigma" + Name, sigmaMean, 0., 2 * sigmaMean);
    if (width == 0)
        width = new RooRealVar("width" + Name, "width" + Name, 1, 0., 5);
    RooVoigtian * Voig = new RooVoigtian("tmp" + Name, "" + Name, *mass, *mean, *width, *sigma);
    return Voig;
}

RooAddPdf * VoigCBMaker(double Mass, RooRealVar * mass, std::map< TString, RooRealVar*> inputs, RooRealVar * frac = 0) {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    RooRealVar * mean = new RooRealVar("mean" + Name, "mean" + Name, Mass, 0.8 * Mass, 1.2 * Mass);
    RooVoigtian * Voig = VoigMaker(Mass, mass, mean, inputs["sigma"], inputs["width"]);
    RooCBShape * CB = CBMaker(Mass, mass, mean, inputs["sigma_cb"], inputs["n"], inputs["alpha"]);
    if (frac == 0)
        frac = new RooRealVar("frac" + Name, "frac" + Name, 0.5, 0, 1);
    RooAddPdf * Voig2 = new RooAddPdf("sum" + Name, "Gaussian crystal ball and Voig PDF" + Name, RooArgList(*Voig, *CB), RooArgList(*frac));
    return Voig2;
}

/*
 * 
 *//*SimultaneousFit*/

int main(int argc, char** argv) {
    TFile * f30 = 0;
    TFile * f40 = 0;
    TFile * f50 = 0;
    TFile * f60 = 0;
    TFile * fh30 = 0;
    TFile * fh40 = 0;
    TFile * fh50 = 0;
    TFile * fh60 = 0;
    RooDataSet * d30;
    RooDataSet * d40;
    RooDataSet * d50;
    RooDataSet * d60;
    RooDataHist * dh30;
    RooDataHist * dh40;
    RooDataHist * dh50;
    RooDataHist * dh60;
    TString sys = "";
    TString pref1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-";
    TString pref2 = "_LowJetPt10_Summer12_final_4_4.root";
    TString prefsys1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_";
    TString prefsys2 = "_Summer12_final_4_4.root";
    TString prefsys3 = "_Summer12.root";
    double fracMean = -1000.;
    double alphaMean = -1000.;
    double widthMean = -1000.;
    double nMean = -1000.;
    std::map< TString, RooRealVar *> inputVars;
    inputVars["alpha"] = 0;
    inputVars["sigma"] = 0;
    inputVars["sigma_cb"] = 0;
    inputVars["width"] = 0;
    inputVars["n"] = 0;
    bool repeat = true;
    RooRealVar* frac = new RooRealVar("frac", "frac", 0.5, 0, 1);
    bool binned = false;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "syst") {
            f++;
            std::string out(*(argv + f));
            sys = out;
            cout << "begin!" << endl;
        } else if (arg_fth == "Frac") {
            f++;
            std::string out(*(argv + f));
            double fracTmp = std::atof(out.c_str());
            frac = new RooRealVar("frac", "frac", fracTmp, 0, 1);
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
        } else if (arg_fth == "binned") {
            std::string out(*(argv + f));
            binned = true;
        }
    }
    if (binned)
        cout << "I am using histograms" << endl;
    RooRealVar * mass = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
    if (sys == "") {
        f30 = TFile::Open(pref1 + "30" + pref2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, *mass, "");
        f40 = TFile::Open(pref1 + "40" + pref2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, *mass, "");
        f50 = TFile::Open(pref1 + "50" + pref2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, *mass, "");
        f60 = TFile::Open(pref1 + "60" + pref2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, *mass, "");

        fh30 = TFile::Open(pref1 + "30_LowJetPt10" + prefsys3);
        TH1D * h30 = (TH1D*) fh30->Get("eventSelectionamassMu");
        dh30 = new RooDataHist("dh30", "dh30", *mass, h30);
        fh40 = TFile::Open(pref1 + "40_LowJetPt10" + prefsys3);
        TH1D * h40 = (TH1D*) fh40->Get("eventSelectionamassMu");
        dh40 = new RooDataHist("dh40", "dh40", *mass, h40);
        fh50 = TFile::Open(pref1 + "50_LowJetPt10" + prefsys3);
        TH1D * h50 = (TH1D*) fh50->Get("eventSelectionamassMu");
        dh50 = new RooDataHist("dh50", "dh50", *mass, h50);
        fh60 = TFile::Open(pref1 + "60_LowJetPt10" + prefsys3);
        TH1D * h60 = (TH1D*) fh60->Get("eventSelectionamassMu");
        dh60 = new RooDataHist("dh60", "dh60", *mass, h60);
    } else {
        f30 = TFile::Open(sys + TString("_") + prefsys1 + "30" + prefsys2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, *mass, "");
        f40 = TFile::Open(sys + TString("_") + prefsys1 + "40" + prefsys2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, *mass, "");
        f50 = TFile::Open(sys + TString("_") + prefsys1 + "50" + prefsys2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, *mass, "");
        f60 = TFile::Open(sys + TString("_") + prefsys1 + "60" + prefsys2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, *mass, "");

        fh30 = TFile::Open(sys + TString("_") + prefsys1 + "30" + prefsys3);
        TH1D * h30 = (TH1D*) fh30->Get("eventSelectionamassMu");
        dh30 = new RooDataHist("dh30", "dh30", *mass, h30);
        fh40 = TFile::Open(sys + TString("_") + prefsys1 + "40" + prefsys3);
        TH1D * h40 = (TH1D*) fh40->Get("eventSelectionamassMu");
        dh40 = new RooDataHist("dh40", "dh40", *mass, h40);
        fh50 = TFile::Open(sys + TString("_") + prefsys1 + "50" + prefsys3);
        TH1D * h50 = (TH1D*) fh50->Get("eventSelectionamassMu");
        dh50 = new RooDataHist("dh50", "dh50", *mass, h50);
        fh60 = TFile::Open(sys + TString("_") + prefsys1 + "60" + prefsys3);
        TH1D * h60 = (TH1D*) fh60->Get("eventSelectionamassMu");
        dh60 = new RooDataHist("dh60", "dh60", *mass, h60);
    }
    cout << "begin ..." << endl;
    RooCategory sample("sample", "sample");
    sample.defineType("p30");
    sample.defineType("p40");
    sample.defineType("p50");
    sample.defineType("p60");

    RooCategory sampleHist("sampleHist", "sampleHist");
    sampleHist.defineType("p30");
    sampleHist.defineType("p40");
    sampleHist.defineType("p50");
    sampleHist.defineType("p60");

    RooDataSet combData("combData", "combined data", *mass, Index(sample),
            Import("p30", *d30),
            Import("p40", *d40),
            Import("p50", *d50),
            Import("p60", *d60)
            );
    RooDataHist combDataHist("combDataHist", "combined data", *mass, Index(sampleHist),
            Import("p30", *dh30),
            Import("p40", *dh40),
            Import("p50", *dh50),
            Import("p60", *dh60)
            );


    RooAddPdf * m30 = VoigCBMaker(30, mass, inputVars, frac);
    RooAddPdf * m40 = VoigCBMaker(40, mass, inputVars, frac);
    RooAddPdf * m50 = VoigCBMaker(50, mass, inputVars, frac);
    RooAddPdf * m60 = VoigCBMaker(60, mass, inputVars, frac);

    RooSimultaneous simPdf("simPdf", "simultaneous pdf", sample);
    simPdf.addPdf(*m30, "p30");
    simPdf.addPdf(*m40, "p40");
    simPdf.addPdf(*m50, "p50");
    simPdf.addPdf(*m60, "p60");

    RooSimultaneous simHistPdf("simHistPdf", "simultaneous pdf", sampleHist);
    simHistPdf.addPdf(*m30, "p30");
    simHistPdf.addPdf(*m40, "p40");
    simHistPdf.addPdf(*m50, "p50");
    simHistPdf.addPdf(*m60, "p60");

    RooFitResult * fr = 0;
    if (!binned) {
        fr = simPdf.fitTo(combData, RooFit::Save());
    } else {
        cout << "START ====================================================================" << endl;
        fr = simHistPdf.fitTo(combDataHist, RooFit::Save());
        cout << "END ====================================================================" << endl;

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
            if (binned)
                myVal << " binned";
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
            myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << widthMean << " n " << nMean << " binned\n";

            std::ofstream log("fullSyst.sh", std::ios_base::app | std::ios_base::out);
            log << myVal.str();

        }
    }


    //    PrintFr(fr);

    RooPlot* frame1 = mass->frame(Title("30 GeV sample"));
    RooPlot* frame2 = mass->frame(Title("40 GeV sample"), RooFit::Binning(100));
    RooPlot* frame3 = mass->frame(Title("50 GeV sample"), RooFit::Binning(100));
    RooPlot* frame4 = mass->frame(Title("60 GeV sample"));
    if (!binned) {
        combData.plotOn(frame1, Cut("sample==sample::p30"), RooFit::Binning(100));
        simPdf.plotOn(frame1, Slice(sample, "p30"), ProjWData(sample, combData));
        simPdf.plotOn(frame1, Slice(sample, "p30"), Components("tmp_M30"), ProjWData(sample, combData), LineStyle(kDashed));
        simPdf.plotOn(frame1, Slice(sample, "p30"), Components("cball_M30"), ProjWData(sample, combData), LineStyle(kDashed), LineColor(kRed));

        combData.plotOn(frame2, Cut("sample==sample::p40"));
        simPdf.plotOn(frame2, Slice(sample, "p40"), ProjWData(sample, combData));
        simPdf.plotOn(frame2, Slice(sample, "p40"), Components("tmp_M40"), ProjWData(sample, combData), LineStyle(kDashed));
        simPdf.plotOn(frame2, Slice(sample, "p40"), Components("cball_M40"), ProjWData(sample, combData), LineStyle(kDashed), LineColor(kRed));

        combData.plotOn(frame3, Cut("sample==sample::p50"));
        simPdf.plotOn(frame3, Slice(sample, "p50"), ProjWData(sample, combData));
        simPdf.plotOn(frame3, Slice(sample, "p50"), Components("tmp_M50"), ProjWData(sample, combData), LineStyle(kDashed));
        simPdf.plotOn(frame3, Slice(sample, "p50"), Components("cball_M50"), ProjWData(sample, combData), LineStyle(kDashed), LineColor(kRed));

        combData.plotOn(frame4, Cut("sample==sample::p60"));
        simPdf.plotOn(frame4, Slice(sample, "p60"), ProjWData(sample, combData), RooFit::Binning(100));
        simPdf.plotOn(frame4, Slice(sample, "p60"), Components("tmp_M60"), ProjWData(sample, combData), LineStyle(kDashed));
        simPdf.plotOn(frame4, Slice(sample, "p60"), Components("cball_M60"), ProjWData(sample, combData), LineStyle(kDashed), LineColor(kRed));
    } else {
        cout << "Using hists!" << endl;
        combDataHist.plotOn(frame1, Cut("sampleHist==sampleHist::p30"), RooFit::Binning(100));
        simHistPdf.plotOn(frame1, Slice(sampleHist, "p30"), ProjWData(sampleHist, combDataHist));
        simHistPdf.plotOn(frame1, Slice(sampleHist, "p30"), Components("tmp_M30"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed));
        simHistPdf.plotOn(frame1, Slice(sampleHist, "p30"), Components("cball_M30"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed), LineColor(kRed));

        combDataHist.plotOn(frame2, Cut("sampleHist==sampleHist::p40"));
        simHistPdf.plotOn(frame2, Slice(sampleHist, "p40"), ProjWData(sampleHist, combDataHist));
        simHistPdf.plotOn(frame2, Slice(sampleHist, "p40"), Components("tmp_M40"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed));
        simHistPdf.plotOn(frame2, Slice(sampleHist, "p40"), Components("cball_M40"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed), LineColor(kRed));

        combDataHist.plotOn(frame3, Cut("sampleHist==sampleHist::p50"));
        simHistPdf.plotOn(frame3, Slice(sampleHist, "p50"), ProjWData(sampleHist, combDataHist));
        simHistPdf.plotOn(frame3, Slice(sampleHist, "p50"), Components("tmp_M50"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed));
        simHistPdf.plotOn(frame3, Slice(sampleHist, "p50"), Components("cball_M50"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed), LineColor(kRed));

        combDataHist.plotOn(frame4, Cut("sampleHist==sampleHist::p60"));
        simHistPdf.plotOn(frame4, Slice(sampleHist, "p60"), ProjWData(sampleHist, combDataHist), RooFit::Binning(100));
        simHistPdf.plotOn(frame4, Slice(sampleHist, "p60"), Components("tmp_M60"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed));
        simHistPdf.plotOn(frame4, Slice(sampleHist, "p60"), Components("cball_M60"), ProjWData(sampleHist, combDataHist), LineStyle(kDashed), LineColor(kRed));
    }
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

    c->SaveAs(sys + "graph_SimFit.C");

    /*
     * Plotting parameters
     */
    double x[4] = {30, 40, 50, 60};
    double x_e[4] = {0., 0., 0., 0.};
    double Mean[4];
    double MeanE[4];
    double fixMass = 30;
    stringstream S;
    for (int i = 0; i < 4; i++) {
        S.str("");
        S << "mean_M" << fixMass;
        cout << S.str().c_str() << endl;
        Mean[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
        MeanE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
        fixMass += 10;
    }
    TGraphErrors * gMean = new TGraphErrors(4, x, Mean, x_e, MeanE);
    gMean->SetNameTitle("Mean", "Mean");

    double Sigma[4];
    double SigmaE[4];
    fixMass = 30;
    for (int i = 0; i < 4; i++) {
        S.str("");
        S << "sigma_M" << fixMass;
        Sigma[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
        SigmaE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
        fixMass += 10;
    }
    TGraphErrors * gSigma = new TGraphErrors(4, x, Sigma, x_e, SigmaE);
    gSigma->SetNameTitle("Sigma", "Sigma");

    double Sigma_cb[4];
    double Sigma_cbE[4];
    fixMass = 30;
    for (int i = 0; i < 4; i++) {
        S.str("");
        S << "sigma_cb_M" << fixMass;
        Sigma_cb[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
        Sigma_cbE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
        fixMass += 10;
    }
    TGraphErrors * gSigma_cb = new TGraphErrors(4, x, Sigma_cb, x_e, Sigma_cbE);
    gSigma_cb->SetNameTitle("Sigma_cb", "Sigma_cb");

    //    double Width[4];
    //    double WidthE[4];
    //    fixMass = 30;
    //    for (int i = 0; i < 4; i++) {
    //        S.str("");
    //        S << "width_M" << fixMass;
    //        Width[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
    //        WidthE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
    //        fixMass += 10;
    //    }
    //    TGraphErrors * gWidth = new TGraphErrors(4, x, Width, x_e, WidthE);
    //    gWidth->SetNameTitle("Width", "Width");

    //    double N[4];
    //    double NE[4];
    //    fixMass = 30;
    //    for (int i = 0; i < 4; i++) {
    //        S.str("");
    //        S << "n_M" << fixMass;
    //        N[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
    //        NE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
    //        fixMass += 10;
    //    }
    //    TGraphErrors * gN = new TGraphErrors(4, x, N, x_e, NE);
    //    gN->SetNameTitle("N", "N");

    TCanvas* c2 = new TCanvas("Graphs", "Graphs", 1600, 800);
    c2->Divide(3);
    c2->cd(1);
    gPad->SetLeftMargin(0.05);
    gMean->Draw("alp");
    c2->cd(2);
    gPad->SetLeftMargin(0.05);
    gSigma->Draw("alp");
    c2->cd(3);
    gPad->SetLeftMargin(0.05);
    gSigma_cb->Draw("alp");
    //    c2->cd(4);
    //    gPad->SetLeftMargin(0.05);
    //    gWidth->Draw("alp");
    //    c2->cd(5);
    //    gPad->SetLeftMargin(0.05);
    //    gN->Draw("alp");

    c2->SaveAs(sys + "Graphs_SimFit.C");

#ifdef INTERMEDIATE

    /*
     * Pseudo data for intermediate points
     */

    RooAddPdf * m35 = VoigCBMaker(35, mass, inputVars, frac);
    RooDataSet * d35 = m35->generate(*mass, 6000);
    RooAddPdf * m45 = VoigCBMaker(45, mass, inputVars, frac);
    RooDataSet * d45 = m45->generate(*mass, 6000);
    RooAddPdf * m55 = VoigCBMaker(55, mass, inputVars, frac);
    RooDataSet * d55 = m55->generate(*mass, 6000);
    RooAddPdf * m65 = VoigCBMaker(65, mass, inputVars, frac);
    RooDataSet * d65 = m65->generate(*mass, 6000);

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

