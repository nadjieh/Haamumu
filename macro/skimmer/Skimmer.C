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
#include "../../interface/HambFitter.h"
#include "../../interface/RDS.h"
#include "../../interface/RDSData.h"
#include "../../interface/RDSRegion.h"
#include "../../interface/CutApplierRDS.h"
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
    bool blind = false;
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
        } else if (arg_fth == "blind") {
            f++;
            blind = true;
        }
    }
    stringstream n;
    n << step;
    for (unsigned int i = 0; i < rds.size(); i++) {
        TFile * fout = new TFile(names[i] + "_" + n.str().c_str() + ".root", "recreate");
        fout->cd();
        cout << "before event loop " << rds[i]->fChain << endl;
        TTree * newTree = rds[i]->fChain->CloneTree(0);
        cout << rds[i]->fChain->GetEntriesFast() << endl;
        for (int eventNumber = 0; eventNumber < rds[i]->fChain->GetEntriesFast(); eventNumber++) {
            rds[i]->GetEntry(eventNumber);
            //            if(rds[i]->jetmetbjet1CSVdisc < 0.898)
            //                continue;
            //            if (!(rds[i]->eventSelectionamassMu > 20. && rds[i]->eventSelectionamassMu < 70.))
            //                continue;
            if (!isSelected(rds[i], cutVals, blind))
                continue;
            if (rds[i]->isInRegion(step)) newTree->Fill();
        }
        newTree->Write();
        fout->Save();
        fout->Close();
    }
    return 1;
}

