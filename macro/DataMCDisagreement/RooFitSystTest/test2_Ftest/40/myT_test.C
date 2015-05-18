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
#include "RooExtendPdf.h"
#include "RooWorkspace.h"
#include "RooChebychev.h"
#include "RooExponential.h"
#include <stdio.h>
#include <math.h>
#include "ForFtest.h"

int main(int argc, char** argv) {
    using namespace RooFit;
    using namespace std;
    RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
    int nbins = 50;
    int dop = 1;
    double minpar = -10.;
    double maxpar = 10.;
    double mL = 20.;
    double mH = 70.;
    vector<double> degrees;
    bool inv = false;
    for (int f = 1; f < argc; f++) {
        string arg_fth(*(argv + f));
        if (arg_fth == "nBins") {
            f++;
            string in(*(argv + f));
            nbins = atof(in.c_str());
        } else if (arg_fth == "degree") {
            f++;
            string in(*(argv + f));
            dop = atof(in.c_str());
        } else if (arg_fth == "minpar") {
            f++;
            string in(*(argv + f));
            minpar = atof(in.c_str());
        } else if (arg_fth == "maxpar") {
            f++;
            string in(*(argv + f));
            maxpar = atof(in.c_str());
        } else if (arg_fth == "lowmass") {
            f++;
            string in(*(argv + f));
            mL = atof(in.c_str());
        } else if (arg_fth == "highmass") {
            f++;
            string in(*(argv + f));
            mH = atof(in.c_str());
        } else if (arg_fth == "vdop") {
            f++;
            string in(*(argv + f));
            degrees.push_back(atof(in.c_str()));
        } else if (arg_fth == "inversePdf") {
            f++;
            string in(*(argv + f));
            if (in == "yes" || "Y" || "true")
                inv = true;
        }
    }
    stringstream s;
    TString name = "";
    TCanvas * c = 0;
    gErrorIgnoreLevel = kError;
    RooRealVar * eventSelectionamassMu = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", mL, mH);
    TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
    TTree * tree = (TTree*) input->Get("rds_zbb");
    RooDataSet * data = new RooDataSet("ControlData", "The original control data", tree, *eventSelectionamassMu, "");
    RooDataHist * dataHist = 0;
    RooWorkspace * w = 0;
    if (!inv)
        w = new RooWorkspace("WS", "WS");
    else
        w = new RooWorkspace("InvWS", "InvWS");
    w->import(*data);
    w->import(*eventSelectionamassMu);
    for (unsigned int i = 0; i < degrees.size(); i++) {
        dop = degrees[i];
        cout << "================ Degree: " << dop << endl;
        Ttest mytest("test", nbins, dop, eventSelectionamassMu, data, minpar, maxpar);
        mytest.getTtest(inv);
        mytest.Print(inv);
        if (i == 0) {
            dataHist = new RooDataHist("hist", "hist", *eventSelectionamassMu, (TH1D*) mytest.getDataHist());
            w->import(*dataHist);
        }
        bool keep = mytest.keepPdf(inv);
        if (keep) {
            RooAbsPdf * genPdf;
            if (!inv)
                genPdf = mytest.getFinalPolynomial();
            else
                genPdf = mytest.getFinalInvPolynomial();
            s.str("");
            s << "n_" << dop;
            name = s.str().c_str();
            RooRealVar * n = new RooRealVar(name, name, tree->GetEntries(), 0, 2 * tree->GetEntries());
            s.str("");
            s << "pdfext_" << dop;
            name = s.str().c_str();
            RooExtendPdf * pdfext = new RooExtendPdf(name, name, *genPdf, *n);
            pdfext->fitTo(*data, Save());
            w->import(*n);
            w->import(*genPdf);
            w->import(*pdfext);
            if (!inv)
                w->writeToFile("ws.root");
            else
                w->writeToFile("wsInv.root");
            RooPlot * P = eventSelectionamassMu->frame();
            data->plotOn(P, Binning(nbins));
            pdfext->plotOn(P);
            s.str("");
            if (!inv)
                s << "gen_" << dop;
            else
                s << "invx_" << dop;
            name = s.str().c_str();
            c = new TCanvas(name, name, 600, 800);
            c->cd();
            P->Draw();
            name = name + ".C";
            c->SaveAs(name);
        }
    }
    dop = 3;

    //    RooRealVar lambda("lambda", "lambda", -10., 10.);
    //    RooExponential expo("expo", "expo", *eventSelectionamassMu, lambda);
    //    expo.fitTo(*dataHist);
    //    RooPlot * Pexp = eventSelectionamassMu->frame();
    //    dataHist->plotOn(Pexp);
    //    expo.plotOn(Pexp);
    //    s.str("");
    //    s << "expo_" << dop;
    //    name = s.str().c_str();
    //    c = new TCanvas(name, name, 600, 800);
    //    c->cd();
    //    Pexp->Draw();
    //    name = name + ".C";
    //    c->SaveAs(name);
    RooRealVar a0("a0", "a0", -10., 10.);
    RooRealVar a1("a1", "a1", -10., 10.);
    RooRealVar a2("a2", "a2", -10., 10.);
    RooRealVar a3("a3", "a3", -10., 10.);
    RooRealVar a4("a4", "a4", -10., 10.);
    RooChebychev ch("ch", "ch", *eventSelectionamassMu, RooArgSet(a0, a1, a2, a3, a4));
    ch.fitTo(*dataHist);
    RooPlot * Pexp = eventSelectionamassMu->frame();
    dataHist->plotOn(Pexp);
    ch.plotOn(Pexp);
    s.str("");
    s << "chepychev_" << dop;
    name = s.str().c_str();
    c = new TCanvas(name, name, 600, 800);
    c->cd();
    Pexp->Draw();
    name = name + ".C";
    c->SaveAs(name);
    return 1;
}
