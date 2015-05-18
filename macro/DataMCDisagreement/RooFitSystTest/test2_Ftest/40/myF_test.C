#include <iostream>
#include <sstream>
#include <string>

#include "TFile.h"
#include "TArrow.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TStyle.h"
#include "TChain.h"
#include "TH2.h"
#include "TH1.h"
#include "TF1.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TVirtualFitter.h"
#include "RooMsgService.h"
#include <stdio.h>
#include <math.h>
#include "ForFtest.h"

std::vector<double> myF_test(int Nbins = 50, int Ndata = 5000, double alpha = 0.1, int option = 1, int polynomDeg = 1) {
    using namespace RooFit;
    using namespace std;
    // Pass parameters:
    // Nbins = bins of tested histogram
    // Ndata = number of events filling histogram
    // alpha = size of test
    // ------------------------------------------
    std::vector<double> ret;
    cout << endl;
    cout << " F - test " << endl;
    cout << " -------- " << endl;
    cout << endl;
    cout << " Will test pseudo-data with a size alpha = " << alpha << endl;
    cout << endl;
    if (Nbins > 1000) {
        cout << "Too many bins, max 1000. Stopping. Edit code and increase arrays size." << endl;
        return ret;
    }

    gStyle->SetOptFit(111111);
    gStyle->SetOptStat(0);

    // Change preset generator
    // NB other versions of TRandom are flawed
    // ---------------------------------------
    delete gRandom;
    TRandom3 * myRNG = new TRandom3();
    gRandom = myRNG;

    // To read and write random data:
    // ------------------------------
    // gRandom->ReadRandom("random.dat");
    // gRandom->WriteRandom("random.dat");
    RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
    TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
    TTree * tree = (TTree*) input->Get("rds_zbb");
    Ndata = tree->GetEntriesFast();
    RooDataSet data("ControlData", "The original control data", tree, eventSelectionamassMu, "");
    double xmin = 20.;
    double xmax = 70.;
    double xmaxF = 1000.;
    int NbinsF = 5000;
    FtestTwoBody mytest("ftest", Nbins, NbinsF, xmaxF, polynomDeg, xmin, xmax, eventSelectionamassMu, data);

    mytest. getGood_CL();
    mytest.Print();
    TCanvas * c = mytest.getConv();
    c->Draw();
    TString name = TString(c->GetName()) + ".C";
    c->SaveAs(name);
    ret.push_back(mytest.getFtest());
    ret.push_back(mytest.getRss0());
    ret.push_back(mytest.getRss1());
    ret.push_back(mytest.getGoodCL());
    cout <<">>>> p-value "<<polynomDeg+1<< " vs "<<polynomDeg<<": "<<mytest.calcPvalue()<<endl;
//    cout <<">>>> F-test alt. 0 for "<<polynomDeg+1<< " vs "<<polynomDeg<<": "<<mytest.getAlternativeFtest()<<endl;    
//    cout <<">>>> F-test alt. 1 for "<<polynomDeg+1<< " vs "<<polynomDeg<<": "<<mytest.getAlternativeFtest(1)<<endl;        
    return ret;
}

int main() {
    double ftest[7];
    double rss0[7];
    double rss1[7];
    double goodCL[7];
    std::vector<double> ret = myF_test(50, 5000, 0.1, 1, 0);
    ftest[0] = ret[0];
    rss0[0] = ret[1];
    rss1[0] = ret[2];
    goodCL[0] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 1);
    ftest[1] = ret[0];
    rss0[1] = ret[1];
    rss1[1] = ret[2];
    goodCL[1] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 2);
    ftest[2] = ret[0];
    rss0[2] = ret[1];
    rss1[2] = ret[2];
    goodCL[2] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 3);
    ftest[3] = ret[0];
    rss0[3] = ret[1];
    rss1[3] = ret[2];
    goodCL[3] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 4);
    ftest[4] = ret[0];
    rss0[4] = ret[1];
    rss1[4] = ret[2];
    goodCL[4] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 5);
    ftest[5] = ret[0];
    rss0[5] = ret[1];
    rss1[5] = ret[2];
    goodCL[5] = ret[3];
    ret.clear();
    cout << ret.size() << endl;
    ret = myF_test(50, 5000, 0.1, 1, 6);
    ftest[6] = ret[0];
    rss0[6] = ret[1];
    rss1[6] = ret[2];
    goodCL[6] = ret[3];
    
			
    double x[7];
    for (double i = 0.5; i < 8.5; i++) {
        x[(int) (i - 0.5)] = i;
    }

    TGraph * g1 = new TGraph(7, x, ftest);
    TCanvas c;
    g1->Draw("ap");    
    c.SaveAs("ftest.C");
    
    g1 = new TGraph(7, x, goodCL);
    TCanvas c2;
    g1->Draw("ap");
    c2.SaveAs("goodCL.C");
    
    g1 = new TGraph(7, rss0, rss1);
    TCanvas c3;
    g1->Draw("ap");
    c3.SaveAs("rss.C");



    return 1;
}
