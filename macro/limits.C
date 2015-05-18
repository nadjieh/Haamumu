/* 
 * File:   DelphesHistCreator.C
 * Author: nadjieh
 *
 * Created on June 14, 2014, 8:18 AM
 */
#include <string>
#include <iostream>
#include <vector>
#include "../interface/myLimits.h"
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
    std::string method;
    std::string inputfilename;
    std::string outfilename;
    std::string run = "";
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "method") {
            f++;
            std::string in(*(argv + f));
            method = in;
        } else if (arg_fth == "input") {
            f++;
            std::string in(*(argv + f));
            inputfilename = "higgsCombine" + in + "." + method+".mH120.root";
                    outfilename = method + "_" + in + ".root";
        } 
    }

    TFile * f = TFile::Open(inputfilename.c_str());
    myLimits * dtree = 0;
    TTree * eventTree = 0;
    dtree = new PythiaStuff(myLimits, f);
    /*
     * Loop over events
     */


    for (int eventNumber = 0; eventNumber < dtree->fChain->GetEntriesFast(); eventNumber++) {
        int nb = 0;
        int nm = 0;
        dtree->GetEntry(eventNumber);
        if(dtree->quantileExpected == -1){
            std::cout<<"Observed limit is "<<dtree->limit<<endl;
        } else if (dtree->quantileExpected == 0){
            std::cout<<"Median expected limit is "<<dtree->limit<<endl;            
        } //else if(dtree->quantileExpected == 0.16)        
    }
    //    TFile * outfile = new TFile(outfilename.c_str(), "recreate");
    //    outfile->cd();
    //
    //    outfile->Close();
    return 1;
}

