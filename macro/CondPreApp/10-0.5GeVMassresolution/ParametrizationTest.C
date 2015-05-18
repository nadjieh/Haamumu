/* 
 * File:   ParametrizationTest.C
 * Author: nadjieh
 *
 * Created on May 18, 2015, 4:52 PM
 */

/*
 * 
 */
//int ParametrizationTest() {
//    TFile* f = new TFile("Info_AllFree.root", "READ");
//    TTree* hh = (TTree*) f->Get("MassTree");
//    RooRealVar mass("mass", "mass", 20, 70);
//    RooDataSet data("data", "data", hh, mass, "");
//
//    TH1D * h = new TH1D("sigma_cb", "#sigma_{CB}", 50, 20, 70);
//    h->Fill(30, 0.4990149);
//    h->Fill(40, 0.6987899);
//    h->Fill(50, 0.8236251);
//    h->Fill(60, 1.072813);
//
//    RooDataHist dataH("dataH", "dataH", RooArgList(mass), h);
//
//    RooRealVar a0("a0", "a0", -1.188572);
//    RooRealVar a1("a1", "a1", 0.08596956);
//    RooRealVar a2("a2", "a2", -0.0009840915);
//    RooRealVar a3("a3", "a3", -3.773191e-07);
//    RooRealVar a4("a4", "a4", -1.077683e-08);
//    RooRealVar a5("a5", "a5", -3.696408e-11);
//    RooRealVar a6("a6", "a6", 1.920123e-11);
//    RooPolynomial p2("p2", "p2", mass, RooArgList(a0, a1, a2, a3, a4, a5, a6));
//    RooDataSet * D = p2.generate(mass, 40);
//    RooRealVar norm("norm", "norm", 40.1094);
//    RooExtendPdf extP2("extp2", "extp2", p2, norm);
//    p2.fitTo(*D, RooFit::Save());
//    RooPlot * p = mass.frame();
//    D->plotOn(p);
//    p2.plotOn(p);
//
//    TCanvas c;
//    c.cd();
//    p->Draw();
//    c.SaveAs("Params.C");
//    
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////
//
// 'BASIC FUNCTIONALITY' RooFit tutorial macro #105
// 
//  Demonstration of binding ROOT Math functions as RooFit functions
//  and pdfs
//
// 07/2008 - Wouter Verkerke 
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#else
// Refer to a class implemented in libRooFit to force its loading
// via the autoloader.
class Roo2DKeysPdf;
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TMath.h"
#include "TF1.h"
#include "Math/DistFunc.h"
#ifndef __CINT__
#include "RooCFunction1Binding.h" 
#include "RooCFunction3Binding.h"
#endif
#include "RooTFnBinding.h" 

using namespace RooFit;

void ParametrizationTest() {

    RooRealVar mass("mass", "mass", 20, 70);
    TF1 *fa1 = new TF1("fa1", "-1.188572+0.08596956*x -0.0009840915*(x^2) -3.773191e-07*(x^3) -1.077683e-08*(x^4) -3.696408e-11*(x^5)+ 1.920123e-11*(x^6)", 20, 70);
    cout << fa1->Eval(30) << endl;
    RooAbsReal* rfa1 = bindFunction(fa1, mass);
    rfa1->Print();
    RooPlot* frame3 = mass.frame(Title("TF1 bound as RooFit function"));
    rfa1->plotOn(frame3);
    TCanvas* c = new TCanvas("Params", "params", 300, 100);
    c->SetLeftMargin(0.15);
    frame3->GetYaxis()->SetTitleOffset(1.6);
    frame3->Draw();
    
    
}