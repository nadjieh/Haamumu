/* 
 * File:   DelphesHistCreator.C
 * Author: nadjieh
 *
 * Created on June 14, 2014, 8:18 AM
 */
#include <string>
#include <iostream>
#include <vector>
#include "../interface/PythiaStuff.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TLorentzVector.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double m_a = 0.;
    std::string inputfilename;
    std::string outfilename;
    std::string run = "";
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "m_a") {
            f++;
            std::string in(*(argv + f));
            m_a = (int) atof(in.c_str());
            inputfilename = "~/work/MG5_aMC_v2_1_0/signalA" + in + "/Events/run_01/tag_1_pythia_lhe_events.root";
            outfilename = "pythiaHists_ma" + in + ".root";
        } else if (arg_fth == "run") {
            f++;
            std::string in(*(argv + f));
            run = in;
        } else if (arg_fth == "input") {
            f++;
            std::string in(*(argv + f));
            inputfilename = "~/work/MG5_aMC_v2_1_0/" + in + "/Events/run_0" + run + "/tag_1_pythia_lhe_events.root";
            outfilename = "pythiaHists_" + in + "_run0" + run + ".root";
        }
    }

    TFile * f = TFile::Open(inputfilename.c_str());
    PythiaStuff * dtree = 0;
    TTree * eventTree = 0;
    dtree = new PythiaStuff(eventTree, f);

    /*
     * Histogram definitions
     */

    /*
     * Basic variable
     */
    TH1D * nMuons = new TH1D("nMuons", "N_{#mu}", 10, -0.5, 9.5);
    nMuons->GetXaxis()->SetTitle("N_{#mu}");
    TH1D * nBquarks = (TH1D*) nMuons->Clone("nBquarks");
    nBquarks->SetTitle("N_{b}");

    
    /*
     * Loop over events
     */


    for (int eventNumber = 0; eventNumber < dtree->fChain->GetEntriesFast(); eventNumber++) {
    		int nb = 0;
				int nm = 0;
        dtree->GetEntry(eventNumber);
        //cout<<"---- "<<dtree->Event_Nparticles<<" ---- "<<dtree->Particle_size<<endl;
        //cout<<" ============================================================= "<<dtree->Particle_size<<endl;
        for(int iP = 0; iP < dtree->Particle_size; iP++){
					if(dtree->Particle_Status[iP] != 2)
						continue;
					/*cout<<"New particle -------------------"<<endl;
					cout<<"Particle Id: "<<dtree->Particle_PID[iP]<<endl;
					cout<<"Mother1 Id: "<<dtree->Particle_Mother1[iP]<<endl;
					cout<<"Mother2 Id: "<<dtree->Particle_Mother2[iP]<<endl;
					cout<<"Status: "<<dtree->Particle_Status[iP]<<endl;*/					
					if(fabs(dtree->Particle_PID[iP]) == 5)
						nb++;
					if(fabs(dtree->Particle_PID[iP]) == 13 /*&& fabs(dtree->Particle_Mother1[iP]) == 23*/)
						nm++;						
				}	
				cout<<"nMu: "<<nm<<", nB: "<<nb<<endl;
				if(nm != 2 || nb != 2){
					cout<<"Event Number: "<<eventNumber<<endl;
					break;
				}	
				nMuons->Fill(nm);	
				nBquarks->Fill(nb);					
    }
    TFile * outfile = new TFile(outfilename.c_str(), "recreate");
    outfile->cd();

    nMuons->Write();
    nBquarks->Write();
    
    outfile->Close();
    return 1;
}

