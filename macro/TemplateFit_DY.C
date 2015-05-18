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
#include "RooFitResult.h"
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
    bool inclusive = true;
    double meanb = 0;
    double meanbw = 0;
    double meantt = 0;
    TString name = "myDYtool";
    std::vector<double> inRange;
    TFile * ftmp = new TFile("atmp.root", "recreate");
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "treeName") {
            f++;
            std::string out(*(argv + f));
            treename = out.c_str();
        } else if (arg_fth == "meanb") {
            f++;
            std::string out(*(argv + f));
            meanb = atof(out.c_str());
        } else if (arg_fth == "meanbw") {
            f++;
            std::string out(*(argv + f));
            meanbw = atof(out.c_str());
        } else if (arg_fth == "meantt") {
            f++;
            std::string out(*(argv + f));
            meantt = atof(out.c_str());
        } else if (arg_fth == "name") {
            f++;
            std::string out(*(argv + f));
            name = name + "_" + out.c_str();
        } else if (arg_fth == "range") {
            f++;
            std::string out(*(argv + f));
            inRange.push_back(atof(out.c_str()));
            f++;
            out = std::string(*(argv + f));
            inRange.push_back(atof(out.c_str()));
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
            ftmp->mkdir(mydir.c_str())->cd();
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
    cout << inRange[0] << "\t" << inRange[1] << endl;
    std::vector < std::pair<double, bool> > ranges;
    ranges.push_back(make_pair(10., true));
    ranges.push_back(make_pair(inRange[0], false));
    ranges.push_back(make_pair(inRange[1], true));
    ranges.push_back(make_pair(120., false));

    std::vector<TString> toExclude;
    if (!inclusive)
        toExclude.push_back("TTFullLep");
    myReg->PrepareMCDataSets(var);

    DYinvestigators * myDYtool = new DYinvestigators(name, var, myReg, ranges, toExclude, myReg->GetData(var), meanbw, meanb, meantt);
    //    DYinvestigators * myDYtool = new DYinvestigators(name, var, myReg, ranges, toExclude, 0, meanbw, meanb, meantt);
    TCanvas c;
    c.cd();
    //    myDYtool->Fit(true, true, true)->Draw();
    myDYtool->Fit(false, true, true)->Draw();
    c.SaveAs(name + ".C");
    RooFitResult * results = myDYtool->GetFitResults();
    results->Print();
    return 1;

    //Conclusion: Histograms are gitty!
}

