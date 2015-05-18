/* 
 * File:   ReadDYPETree.C
 * Author: nadjieh
 *
 * Created on September 15, 2014, 5:24 PM
 */
#include <vector>
#include <sstream>
#include <iostream>
#include "TH1.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TCanvas.h"
#include "../interface/AuxClassDyPe.h"
using namespace std;

int main(int argc, char** argv) {
    TString treename = "PETree";
    TString outname = "";
    AuxClassDyPe * myTree = 0;

    std::vector<int> steps;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "input") {
            f++;
            std::string out(*(argv + f));
            TFile * fMC = TFile::Open(out.c_str());
            TTree * t = (TTree*) fMC->Get(treename);
            myTree = new AuxClassDyPe(t, treename);

        } else if (arg_fth == "out") {
            f++;
            std::string out(*(argv + f));
            outname = string("dype_" + out + ".root").c_str();
        }
    }

    float mean[10] = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};
    TH1D * myMean = new TH1D("myMean", "mean", 7000, 1000, 8000);


    for (int i = 0; i < myTree->fChain->GetEntriesFast(); i++) {
        if (i == 0 || i == 36 || i == 58 || i == 72)
            continue;
        myTree->GetEntry(i);
        //        cout << myTree->rsize << endl;
        for (int j = 0; j < myTree->rsize; j++) {
            mean[j] += myTree->means[j];
        }
        myMean->Fill(myTree->means[1]);
        mean[3] += myTree->Alpha[0];
        mean[4] += myTree->Lambda[0];
        mean[5] += myTree->Mean_bw[0];
        mean[6] += myTree->Mean_cb[0];
        mean[7] += myTree->Sigma_bw[0];
        mean[8] += myTree->Sigma_cb[0];
        mean[9] += myTree->N[0];
        cout << "---- " << i << "\n\t" << myTree->means[0] << "\t" << myTree->means[1] << "\t" << myTree->means[2] << endl;
    }
    for (int i = 0; i < 10; i++) {
        mean[i] = mean[i] / (myTree->fChain->GetEntriesFast() - 4);
    }
    cout << mean[0] << "\t" << mean[1] << "\t" << mean[2] << endl;
    int mySize = myTree->rsize;
    std::vector<TH1D *> pulls;
    std::vector<TH1D *> residuals;
    stringstream s;
    for (int j = 0; j < mySize + 7; j++) {
        s.str("");
        s << "pull_" << j;
        pulls.push_back(new TH1D(s.str().c_str(), s.str().c_str(), 20000, -1000., 1000.));
        s.str("");
        s << "residual_" << j;
        residuals.push_back(new TH1D(s.str().c_str(), s.str().c_str(), 20000, -1000., 1000.));
    }

    for (int i = 0; i < myTree->fChain->GetEntriesFast(); i++) {
        myTree->GetEntry(i);
        if (i == 0 || i == 36 || i == 58 || i == 72)
            continue;
        for (int j = 0; j < mySize; j++) {
            pulls[j]->Fill((myTree->means[j] - mean[j]) / myTree->errs[j]);
            if (j == 1)
                cout << "--- Diff " << i << ": " << myTree->means[j] << " - " << mean[j] << " = " << myTree->means[j] - mean[j] << endl;
            residuals[j]->Fill(myTree->means[j] - mean[j]);
        }
        pulls[3]->Fill((myTree->Alpha[0] - mean[3]) / myTree->Alpha[1]);
        pulls[4]->Fill((myTree->Lambda[0] - mean[4]) / myTree->Lambda[1]);
        pulls[5]->Fill((myTree->Mean_bw[0] - mean[5]) / myTree->Mean_bw[1]);
        pulls[6]->Fill((myTree->Mean_cb[0] - mean[6]) / myTree->Mean_cb[1]);
        pulls[7]->Fill((myTree->Sigma_bw[0] - mean[7]) / myTree->Sigma_bw[1]);
        pulls[8]->Fill((myTree->Sigma_cb[0] - mean[8]) / myTree->Sigma_cb[1]);
        pulls[9]->Fill((myTree->N[0] - mean[9]) / myTree->N[1]);
        residuals[3]->Fill((myTree->Alpha[0] - mean[3]));
        residuals[4]->Fill((myTree->Lambda[0] - mean[4]));
        residuals[5]->Fill((myTree->Mean_bw[0] - mean[5]));
        residuals[6]->Fill((myTree->Mean_cb[0] - mean[6]));
        residuals[7]->Fill((myTree->Sigma_bw[0] - mean[7]));
        residuals[8]->Fill((myTree->Sigma_cb[0] - mean[8]));
        residuals[9]->Fill((myTree->N[0] - mean[9]));
    }

    TFile * f = new TFile(outname, "recreate");
    for (int j = 0; j < mySize + 7; j++) {
        s.str("");
        s << "range_" << j;
        f->mkdir(s.str().c_str())->cd();
        pulls[j]->Write();
        residuals[j]->Write();
        f->cd();
    }
    myMean->Write();
    f->Write();
    f->Close();
    return 0;
}

