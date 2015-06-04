/* 
 * File:   SignalFitHelper.h
 * Author: nadjieh
 *
 * Created on June 4, 2015, 10:52 AM
 */

#ifndef SIGNALFITHELPER_H
#define	SIGNALFITHELPER_H

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
    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
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
    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
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
    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
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
    cout << "\tn,width: " << fr->correlation("width" + syst, "n" + syst) << endl;
    cout << "\tn,frac: " << fr->correlation("frac" + syst, "n" + syst) << endl;
    cout << "\tn,sigma_cb: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,sigma: " << fr->correlation("sigma_cb" + syst, "n" + syst) << endl;
    cout << "\tn,mean: " << fr->correlation("mean" + syst, "n" + syst) << endl;
    cout << "\tfrac,sigma_cb: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,sigma: " << fr->correlation("sigma_cb" + syst, "frac" + syst) << endl;
    cout << "\tfrac,mean: " << fr->correlation("mean" + syst, "frac" + syst) << endl;
    cout << "\tfrac,width: " << fr->correlation("frac" + syst, "width" + syst) << endl;
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


#endif	/* SIGNALFITHELPER_H */

