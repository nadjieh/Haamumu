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
#include "../interface/RDS.h"
#include "../interface/DYinvestigators.h"
#include "../interface/RDSData.h"
#include "../interface/RDSRegion.h"
#include "TString.h"
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooVoigtian.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooCategory.h"
#include "RooPlot.h"
#include "RooHistPdf.h"
#include "RooDataHist.h"
#include "RooAddPdf.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooPolynomial.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooSimultaneous.h"
#include "RooExtendPdf.h"
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


double getMultipliedErr(RooRealVar a, RooRealVar b) {
    double a_ = a.getError() / a.getVal();
    double b_ = b.getError() / b.getVal();
    return a.getVal() * b.getVal() * sqrt(pow(a_, 2) + pow(b_, 2));
}

int main(int argc, char** argv) {
    double lumi = 19700.;
    TString treename = "rds_zbb";
    TString var = "";
    int step = 1000;
    Region * myReg;
    interval range;
    varInfo myInfo;
    int nPE = 1;
    bool inclusive = true;
    //TFile * ftmp = new TFile("atmp.root", "recreate");
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "treeName") {
            f++;
            std::string out(*(argv + f));
            treename = out.c_str();
        } else if (arg_fth == "inclusive") {
            f++;
            std::string out(*(argv + f));
            if (out == string("false"))
                inclusive = false;
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
            cout << "step: " << step << endl;
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
            //            ftmp->mkdir(mydir.c_str())->cd();
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
            //            ftmp->mkdir(mydir.c_str())->cd();
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
        } else if (arg_fth == "nPE") {
            f++;
            string out(*(argv + f));
            nPE = (int) atof(out.c_str());
        }
    }

    std::vector < std::pair<double, bool> > ranges;
    ranges.push_back(make_pair(10., true));
    ranges.push_back(make_pair(20., false));
    ranges.push_back(make_pair(70., true));
    ranges.push_back(make_pair(120., false));

    std::vector<TString> toExclude;
    TString name = "DYPE";
    if (!inclusive) {
        toExclude.push_back("TTFullLep");
        name = name + "_exclusive";
    }
    myReg->PrepareMCDataSets(var);
    BiasChecker mybiaschecker(name, var, nPE, myReg, ranges, toExclude);
    mybiaschecker.doPE();
    //    DYinvestigators * myDYtool = new DYinvestigators("myDYtool", var, myReg, ranges, toExclude);
    //    myDYtool->Fit();

    return 1;

    //Conclusion: Histograms are gitty!
}

