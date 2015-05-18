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
#include "../../../../../interface/HambFitter.h"
#include "../../../../../interface/RDS.h"
#include "../../../../../interface/RDSData.h"
#include "../../../../../interface/RDSRegion.h"
#include "../../../../../interface/CutApplierRDS.h"
#include "TString.h"
#include "TCanvas.h"
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

int main(int argc, char** argv) {
    int step = 1000;
    std::vector<RDSData*> rds;
    std::vector<TString> names;
    TString treename = "rds_zbb";
    std::vector<double> cutVals;
    double mass = 999.;
    TString what = "";
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "treeName") {
            f++;
            std::string out(*(argv + f));
            treename = out.c_str();
        } else if (arg_fth == "step") {
            f++;
            std::string out(*(argv + f));
            step = (int) atof(out.c_str());
        } else if (arg_fth == "data") {
            f++;
            std::string out(*(argv + f));
            TFile * fdata = TFile::Open(out.c_str());
            rds.push_back(new RDSData((TTree*) fdata->Get(treename)));
            int pos = out.find(".root");
            names.push_back(out.substr(0, pos).c_str());
        } else if (arg_fth == "mc") {
            f++;
            std::string out(*(argv + f));
            TFile * fdata = TFile::Open(out.c_str());
            rds.push_back(new RDS((TTree*) fdata->Get(treename)));
            int pos = out.find(".root");
            names.push_back(out.substr(0, pos).c_str());
        } else if (arg_fth == "AddCut") {
            f++;
            std::string out(*(argv + f));
            cutVals.push_back(std::atof(out.c_str()));
        } else if (arg_fth == "mass") {
            f++;
            std::string out(*(argv + f));
            mass = std::atof(out.c_str());
        } else if (arg_fth == "inout") {
            f++;
            std::string out(*(argv + f));
            what = out;
        }
    }
    stringstream n;
    n << what;
    TFile * fout = new TFile(names[0] + "_" + n.str().c_str() + ".root", "recreate");
    fout->cd();
    cout << "before event loop " << rds[0]->fChain << endl;
    TTree * newTree = rds[0]->fChain->CloneTree(0);
    cout << rds[0]->fChain->GetEntriesFast() << endl;
    for (int eventNumber = 0; eventNumber < rds[0]->fChain->GetEntriesFast(); eventNumber++) {
       rds[0]->GetEntry(eventNumber);
       if(what == "in"){
       	if (!(fabs(rds[0]->eventSelectionamassMu - mass) < 10.))
            	continue;
       } else if(what == "out"){
       	if (!(fabs(rds[0]->eventSelectionamassMu - mass) > 10.))
            	continue;
       }
			cout<<   eventNumber  <<"- Tree 1 is good! "<<     rds[0]->eventSelectionamassMu <<endl;
       if (rds[0]->isInRegion(step)) newTree->Fill();
    }
    
    newTree->Write();
    fout->Save();
    fout->Close();
    
    return 1;
}

