/* 
 * File:   ParametrizationTest.C
 * Author: nadjieh
 *
 * Created on May 18, 2015, 4:52 PM
 */
#ifndef __CINT__
#include "RooGlobalFunc.h"
#else
// Refer to a class implemented in libRooFit to force its loading
// via the autoloader.
class Roo2DKeysPdf;
#endif
#include "RooRealVar.h"
#include "RooGenericPdf.h"
#include "RooChebychev.h"
#include "RooRealSumPdf.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooVoigtian.h"
#include "RooCBShape.h"
#include "RooFitResult.h"
#include "RooAddPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TMath.h"
#include "TF1.h"
#include <iostream>
#include <sstream>
#include "Math/DistFunc.h"
#ifndef __CINT__
#include "RooCFunction1Binding.h" 
#include "RooCFunction3Binding.h"
#endif
#include "RooTFnBinding.h" 

using namespace RooFit;
using namespace std;

Double_t Sigma(Double_t *x, Double_t *par = 0) {
    Double_t ret = 0;
    if (x[0] < 40.) {
        double p30[2] = {30, 0.285839};
        double p40[2] = {40, 0.381069};
        double slope = (p40[1] - p30[1]) / (p40[0] - p30[0]);
        double intercept = ((p40[0] * p30[1]) - (p40[1] * p30[0])) / (p40[0] - p30[0]);
        ret = (x[0] * slope) + intercept;
    } else if (40 <= x[0] < 50.) {
        double p40[2] = {40, 0.381069};
        double p50[2] = {50, 0.487961};
        double slope = (p50[1] - p40[1]) / (p50[0] - p40[0]);
        double intercept = ((p50[0] * p40[1]) - (p50[1] * p40[0])) / (p50[0] - p40[0]);
        ret = (x[0] * slope) + intercept;
    } else if (50 <= x[0] <= 60.) {
        double p50[2] = {50, 0.487961};
        double p60[2] = {60, 0.591851};
        double slope = (p60[1] - p50[1]) / (p60[0] - p50[0]);
        double intercept = ((p60[0] * p50[1]) - (p60[1] * p50[0])) / (p60[0] - p50[0]);
        ret = (x[0] * slope) + intercept;
    }
    return ret;
}

RooPlot * fitSignal(double Mass) {
    RooRealVar mass("mass", "mass", 20, 70);
    RooFormulaVar sigma_cb("sigma_cb", "-0.4756193+0.04638364*mass -0.0004420156*(mass^2) -7.566989e-07*(mass^3) -1.041907e-08*(mass^4) +8.410242e-10*(mass^5)"
            , RooArgList(mass));
    RooRealVar mean("mean", "mean", Mass);
    RooFormulaVar sigma("sigma", "(0.010226*mass)-0.0215593", RooArgList(mass));
    //    RooRealVar sigma("sigma", "sigma", 0.285);
    RooRealVar width("width", "width", 0.033);
    RooVoigtian Voig("tmp", "", mass, mean, width, sigma);
    RooRealVar n("n", "", 3.12);
    RooRealVar alpha("alpha", "", 1.09);
    RooCBShape CB("cball", "crystal ball", mass, mean, sigma_cb, alpha, n);
    RooRealVar frac("frac", "frac", 0.612);
    RooAddPdf Voig2("sum", "Gaussian crystal ball and Voig PDF", RooArgList(Voig, CB), RooArgList(frac));

    RooDataSet * D = Voig2.generate(mass, 6000);
    cout << D->GetName() << endl;
    Voig2.fitTo(*D, RooFit::Save());
    stringstream S;
    S << "m_{a} = " << Mass << " GeV";
    RooPlot * p = mass.frame(RooFit::Title(S.str().c_str()));
    D->plotOn(p);
    Voig2.plotOn(p, RooFit::LineColor(kBlack));
    Voig2.plotOn(p, RooFit::Components(Voig), RooFit::LineColor(kBlue));
    Voig2.plotOn(p, RooFit::Components(CB), RooFit::LineColor(kRed));

    return p;
}

/*
 * 
 */
int ParametrizationTest() {
    /*
     * How to parameterize a parameter versus a variable
     */

    RooRealVar mass("mass", "mass", 20, 70);
    RooPlot * m25 = fitSignal(25.);
    RooPlot * m35 = fitSignal(35.);
    RooPlot * m45 = fitSignal(45.);
    RooPlot * m55 = fitSignal(55.);
    TCanvas c;
    c.SetLeftMargin(0.01);
    c.SetRightMargin(0.01);
    c.SetTopMargin(0.01);
    c.SetBottomMargin(0.01);
    c.Divide(2,2);
    c.cd(1);
    m25->Draw();
    c.cd(2);
    m35->Draw();
    c.cd(3);
    m45->Draw();
    c.cd(4);
    m55->Draw();
    c.SaveAs("Params.C");


    /////////////////////////////////////////////////////

    // 'BASIC FUNCTIONALITY' RooFit tutorial macro #105
    // 
    //  Demonstration of binding ROOT Math functions as RooFit functions
    //  and pdfs

    TF1 *fa1 = new TF1("fa1", "-1.188572+0.08596956*x -0.0009840915*(x^2) -3.773191e-07*(x^3) -1.077683e-08*(x^4) -3.696408e-11*(x^5)+ 1.920123e-11*(x^6)", 20, 70);
    cout << fa1->Eval(30) << endl;
    RooAbsReal* rfa1 = bindFunction(fa1, mass);
    rfa1->Print();
    RooPlot* frame3 = mass.frame(Title("TF1 bound as RooFit function"));
    rfa1->plotOn(frame3);
    TCanvas* c2 = new TCanvas("Params2", "params", 300, 100);
    c2->SetLeftMargin(0.15);
    frame3->GetYaxis()->SetTitleOffset(1.6);
    frame3->Draw();
    c2->SaveAs("Params2.C");


    /*
     * Create a good fit for sigma: Linear does not work!!
     */

    TF1 *func = new TF1("MyLine", Sigma, 25, 65, 0);
    cout << func->Eval(40) << endl;
    cout << func->Eval(39.9) << endl;
    cout << func->Eval(40.1) << endl;
    RooAbsReal* rfunc = bindFunction(func, mass);
    RooRealVar a0("a0", "a0", 0);
    RooRealVar c1("c1", "c1", 1);
    a0.setConstant(kTRUE);
    RooChebychev bkg("bkg", "bkg", mass, RooArgList(a0));
    RooAbsPdf *mypdf = new RooRealSumPdf("mypdf", "mypdf", *rfunc, bkg, c1);


    RooDataSet * D2 = mypdf->generate(mass, 1000);
    RooPlot* frame4 = mass.frame();
    D2->plotOn(frame4);
    //    for (int i = 1; i < 100; i++) {
    //        RooDataSet * D3 = mypdf->generate(mass, 1000);
    //        RooRealVar a1("a1", "a1", -1., 1.);
    //        RooRealVar a2("a2", "a2", 0, 10);
    //        RooRealVar a3("a3", "a3", 0, 10);
    //        RooRealVar a4("a4", "a4", 0, 10);
    //        RooRealVar a5("a5", "a5", 0, 10);
    //        RooPolynomial pol1("pol1", "pol1", mass, RooArgList(a1));
    //        pol1->fitTo(*D3, RooFit::Save());
    //        pol1.plotOn(frame4, RooFit::LineColor(kYellow));
    //
    //    }
    mypdf->plotOn(frame4);
    TCanvas* c3 = new TCanvas("Params3", "params");
    c3->SetLeftMargin(0.15);
    frame4->GetYaxis()->SetTitleOffset(1.6);
    frame4->Draw();
    c3->SaveAs("Params3.C");

    return 0;
}
