/* 
 * File:   TemplateFit.C
 * Author: nadjieh
 *
 * Created on June 9, 2012, 3:57 PM
 */
#include "/opt/root/math/mathcore/inc/Math/Functor.h"
#include "../interface/AccommulativeSelection.h"
#include<iostream>
#include "TFile.h"
#include "TTree.h"
#include "../interface/RDS.h"
#include "../interface/DYinvestigators.h"
#include "../interface/RDSData.h"
#include "../interface/RDSRegion.h"
#include "TString.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"
#include "TH2.h"
#include "TDirectory.h"
#include "TString.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    double lumi = 1.;
    TString treename = "rds_zbb";
    TString var = "";
    int step = 1;
    double xLow;
    double xHigh;
    int region = -1;
    TTree * sigTree;
    std::vector<TTree*> bkgTrees;
    std::vector<double> weights;
    bool greater = true;
    string signalname = "";
    string bkgname = "";

    //TFile * ftmp = new TFile("atmp.root", "recreate");
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
            xLow = atof(string(*(argv + f)).c_str());
            f++;
            xHigh = atof(string(*(argv + f)).c_str());
            f++;
            step = atof(string(*(argv + f)).c_str());
        } else if (arg_fth == "signal") {
            f++;
            std::string out(*(argv + f));
            signalname = out;
            TFile * fdata = TFile::Open(out.c_str());
            sigTree = (TTree*) fdata->Get(treename);
            //Weight: number of processed events, cross section
            f++;
            out = string(*(argv + f));
            double nevt = (double) atof(out.c_str());
            f++;
            out = string(*(argv + f));
            double xsec = (double) atof(out.c_str());
            weights.push_back((xsec * lumi) / nevt);
        } else if (arg_fth == "bkg") {
            f++;
            std::string out(*(argv + f));
            bkgname = out;
            TFile * fMC = TFile::Open(out.c_str());
            bkgTrees.push_back((TTree*) fMC->Get(treename));
            //Weight: number of processed events, cross section
            f++;
            out = string(*(argv + f));
            double nevt = (double) atof(out.c_str());
            f++;
            out = string(*(argv + f));
            double xsec = (double) atof(out.c_str());
            weights.push_back((xsec * lumi) / nevt);
        } else if (arg_fth == "region") {
            f++;
            string out = string(*(argv + f));
            region = (int) atof(out.c_str());
        } else if (arg_fth == "greater") {
            f++;
            string out = string(*(argv + f));
            greater = (out == "g");
        }
    }

    cout << "signal mass " << signalname << endl;
    int pos = signalname.find("mH1-");
    signalname = signalname.substr(pos + 4);
    signalname = signalname.substr(0, 2);
    cout << "signal mass " << signalname << endl;
    pos = bkgname.find("_Summer12");
    bkgname = bkgname.substr(0, pos);
    cout << "background " << bkgname << endl;
    cout << bkgTrees.size()<< endl;
    cout << weights.size()<< endl;
    if (weights.size() != 0)
        bkgname = "allBkg";
    Optimizer optim("optim", var, sigTree, bkgTrees, xLow, xHigh, step, region, std::atof(signalname.c_str()));
    optim.Fill(weights, greater);
    stringstream s;
    s.str("");
    if (greater)
        s << "m_" << signalname << "_" << bkgname << "_" << var << "_" << fabs(region) << "_greater.root";
    else
        s << "m_" << signalname << "_" << bkgname << "_" << var << "_" << fabs(region) << "_less.root";
    TFile * oufile = new TFile(s.str().c_str(), "recreate");
    optim.Write(oufile);
    oufile->Close();
    return 1;
}

