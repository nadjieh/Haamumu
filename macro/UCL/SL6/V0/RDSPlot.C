/* 
 * File:   RDSPlot.C
 * Author: nadjieh
 *
 * Created on August 18, 2014, 7:48 AM
 */

#include "../../../../interface/RDS.h"
#include "../../../../interface/RDSData.h"
#include "../../../../interface/HambHists.h"
#include "../../../../interface/HambObjectProperty.h"
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
#include "RooMCStudy.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TString treename = "rds_zbb";
    TString outname = "";
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
    TH1D * mu1pt = new TH1D("mu1pt", "mu1pt", 500, 0, 500);
    TH1D * mu2pt = new TH1D("mu2pt", "mu2pt", 500, 0, 500);
    TH1D * amassMu = new TH1D("amassMu", "amassMu", 1000, 0, 1000);
    TH1D * met = new TH1D("met", "met", 100, 0, 200);
    TH1D * jet2pt = new TH1D("jet2pt", "jet2pt", 1000, 0, 1000);
    TH1D * jet1pt = new TH1D("jet1pt", "jet1pt", 1000, 0, 1000);
    TH1D * hPt = new TH1D("hPt", "hPt", 50, 0, 1000);
    TH1D * hMass = new TH1D("hMass", "hMass", 50, 0, 1000);
    TH1D * aptMu = new TH1D("aptMu", "aptMu", 50, 0, 1000);
    TH1D * aptBjet = new TH1D("aptBjet", "aptBjet", 50, 0, 1000);
    TH1D *amassBjet = new TH1D("amassBjet", "amassBjet", 100, 0, 1000);
    TH2D *amassMuhMass = new TH2D("amassMuhMass", "amassMuhMass", 500, 0, 1000,50, 0, 1000);    
    TH2D *amassMuhMass125 = new TH2D("amassMuhMass125", "amassMuhMass", 500, 0, 1000,1000, 0, 1000); 
    TH2D *amassMuMETSig = new TH2D("amassMETSig", "amassMETSig", 500, 0, 1000,1000, 0, 1000);                   
    int n40 = 0;
    int n40t = 0;
    int n50 = 0;
    int n50t = 0;
    int n60 = 0;
    int n60t = 0;

    for (int eventNumber = 0; eventNumber < rds->fChain->GetEntriesFast(); eventNumber++) {
        rds->GetEntry(eventNumber);
        //if(!(rds->eventSelectionmu1pt > 26. && rds->eventSelectionmu2pt > 10.))
        //        continue;
        //Make it blind
//        if (fabs(rds->eventSelectionhMass-125) < 20) {
//        	if(fabs(rds->eventSelectionamassMu-30)< 1 || fabs(rds->eventSelectionamassMu-40)< 1 || fabs(rds->eventSelectionamassMu-50)< 1 || fabs(rds->eventSelectionamassMu-60)< 1 )
//	            continue;
//        } 
        if (rds->eventSelectionamassMu > 30 && rds->eventSelectionamassMu < 50) {
            n40++;
        } else if (rds->eventSelectionamassMu > 40 && rds->eventSelectionamassMu < 60) {
            n50++;
        } else if (rds->eventSelectionamassMu > 50 && rds->eventSelectionamassMu < 70) {
            n60++;
        }
       // if (fabs(((RDS*) rds)->mcSelectionFlavLepNeg) == 15 || fabs(((RDS*) rds)->mcSelectionFlavLepPos) == 15) {
            if (rds->eventSelectionamassMu > 30 && rds->eventSelectionamassMu < 50) {
                n40t++;
            } else if (rds->eventSelectionamassMu > 40 && rds->eventSelectionamassMu < 60) {
                n50t++;
            } else if (rds->eventSelectionamassMu > 50 && rds->eventSelectionamassMu < 70) {
                n60t++;
            }

            double weight = rds->getWeight();
            //        cout<< weight << endl;
            if (weight < 0)
                weight = 1.;
            mu1pt->Fill(rds->eventSelectionmu1pt, weight);
            mu2pt->Fill(rds->eventSelectionmu2pt, weight);
            amassMu->Fill(rds->eventSelectionamassMu, weight);
            hPt->Fill(rds->eventSelectionhPt, weight);
            hMass->Fill(rds->eventSelectionhMass, weight);
            aptMu->Fill(rds->eventSelectionaptMu, weight);
            aptBjet->Fill(rds->eventSelectionaptBjet, weight);
            jet1pt->Fill(rds->jetmetjet1pt, weight);
            jet2pt->Fill(rds->jetmetjet2pt, weight);
            met->Fill(rds->eventSelectionMET_hamb, weight);
            amassBjet->Fill(rds->eventSelectionamassBjet, weight);
            amassMuhMass->Fill(rds->eventSelectionamassMu,rds->eventSelectionhMass, weight);
            amassMuhMass125->Fill(rds->eventSelectionamassMu,fabs(rds->eventSelectionhMass-125), weight);
       // }
    }
    double err = ((double)n40t/(double)n40)*sqrt(1./(double)n40t+1./(double)n40);
    cout<<"40: "<<(double)n40t/(double)n40<<" +- "<<err<<endl;
    err = ((double)n50t/(double)n50)*sqrt(1./(double)n50t+1./(double)n50);
    cout<<"50: "<<(double)n50t/(double)n50<<" +- "<<err<<endl;
    err = ((double)n60t/(double)n60)*sqrt(1./(double)n60t+1./(double)n60);    
    cout<<"60: "<<(double)n60t/(double)n60<<" +- "<<err<<endl;

    TFile * out = new TFile(outname, "recreate");

    out->cd();
    mu1pt->Write();
    mu2pt->Write();
    amassMu->Write();
    hPt->Write();
    hMass->Write();
    aptMu->Write();
    aptBjet->Write();
    jet1pt->Write();
    jet2pt->Write();
    met->Write();
    amassBjet->Write();
    amassMuhMass->Write();
    amassMuhMass125->Write();
    out->Close();
    return 0;
}

