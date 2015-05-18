/* 
 * File:   RDSPlot.C
 * Author: nadjieh
 *
 * Created on August 18, 2014, 7:48 AM
 */

#include "../interface/RDS.h"
#include "../interface/RDSData.h"
#include "../interface/HambHists.h"
#include "../interface/HambObjectProperty.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <TApplication.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TBranch.h>
#include <TTree.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TSystem.h>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TString treename = "rds_zbb";
    TString outname = "";
    bool isData = false;
    RDSData * rds = 0;
    std::vector<ObjectProperty<Hamb>*> hop;
    hop.push_back(new Mll());
    hop.push_back(new DiffM());
    hop.push_back(new MetSig());
    hop.push_back(new HiggsMass());
    hop.push_back(new DRMuMu());

    std::vector<int> steps;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "mc") {
            f++;
            std::string out(*(argv + f));
            TFile * fMC = TFile::Open(out.c_str());
            rds = new RDS((TTree*) fMC->Get(treename));
        } else if (arg_fth == "data") {
            f++;
            std::string out(*(argv + f));
            TFile * fMC = TFile::Open(out.c_str());
            rds = new RDSData((TTree*) fMC->Get(treename));
            isData = true;
        } else if (arg_fth == "out") {
            f++;
            std::string out(*(argv + f));
            outname = string("rds" + out + ".root").c_str();
        } else if (arg_fth == "step") {
            f++;
            std::string out(*(argv + f));
            int p = atof(out.c_str());
            steps.push_back(p);
        }
    }

    std::vector<HambHist*> myHists;
    stringstream s;
    for (unsigned int i = 0; i < steps.size(); i++) {
        s.str("");
        s << "step_" << steps[i];
        myHists.push_back(new HambHist(s.str().c_str(), hop));
        //        cout << "size: " << myHists.size() << endl;
    }
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n7 = 0;
    int n8 = 0;
    int n10 = 0;
    int n = 0;
    for (int eventNumber = 0; eventNumber < rds->fChain->GetEntriesFast(); eventNumber++) {
        rds->GetEntry(eventNumber);
        //        if (rds->eventSelectionamassMu < 10.)
        //            continue;
        //        if(rds->eventSelectiondiMudR > 1.)
        //            continue;
        //        if(rds->eventSelectiondiMudR < 0.8)
        //            continue;            
        for (unsigned int i = 0; i < steps.size(); i++) {
            //            cout << "step: " << steps[i] << endl;
            if (rds->isInRegion(steps[i])) {
                //                cout << "in category " << steps[i] << endl;
                Hamb * hamb = new Hamb(rds->eventSelectiondiffMassaa, rds->eventSelectionamassMu,
                        rds->eventSelectionMETsignificance_hamb, rds->eventSelectionhMass, rds->eventSelectiondiMudR);
                //                if (isData)
                //                    myHists[i]->Fill(hamb, 1);
                //                else
                cout << rds->getWeight() << endl;
                myHists[i]->Fill(hamb, rds->getWeight());
                delete hamb;
            }
        }
        //        if (rds->eventSelectionamassMu > 20. && rds->eventSelectionamassMu < 70.) {
        //            if (fabs(rds->eventSelectiondphidiBjet) < 1.5)
        //                continue;
        //            //            if (fabs(rds->eventSelectionhMass - 125.) > 20.)
        //            //                continue;
        //            n++;
        //            if (rds->eventSelectionMETsignificance_hamb < 2.)
        //                n2++;
        //            if (rds->eventSelectionMETsignificance_hamb < 3.)
        //                n3++;
        //            if (rds->eventSelectionMETsignificance_hamb < 4.)
        //                n4++;
        //            if (rds->eventSelectionMETsignificance_hamb < 5.)
        //                n5++;
        //            if (rds->eventSelectionMETsignificance_hamb < 7.)
        //                n7++;
        //            if (rds->eventSelectionMETsignificance_hamb < 8.)
        //                n8++;
        //            if (rds->eventSelectionMETsignificance_hamb < 10.)
        //                n10++;
        //        }
    }
    //    TH1D * h = new TH1D("METSIGN", "METSIGN", 11, -0.5, 10.5);
    //    h->SetBinContent(h->GetXaxis()->FindBin(0.), n);
    //    h->SetBinContent(h->GetXaxis()->FindBin(2), n2);
    //    h->SetBinContent(h->GetXaxis()->FindBin(3), n3);
    //    h->SetBinContent(h->GetXaxis()->FindBin(4), n4);
    //    h->SetBinContent(h->GetXaxis()->FindBin(5), n5);
    //    h->SetBinContent(h->GetXaxis()->FindBin(7), n7);
    //    h->SetBinContent(h->GetXaxis()->FindBin(8), n8);
    //    h->SetBinContent(h->GetXaxis()->FindBin(10), n10);
    TFile * out = new TFile(outname, "recreate");
    cout << "after file!" << endl;
    for (unsigned int i = 0; i < steps.size(); i++) {
        //        cout<<"Trying to write "<<i<<", "<<myHists[i]<<endl;
        myHists[i]->WriteAll(out);
    }
    out->cd();
    //    h->Write();
    out->Close();
    return 0;
}

