//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 11 16:31:31 2015 by ROOT version 5.34/19
// from TTree MassTree/MassTree
// found on file: Info.root
//////////////////////////////////////////////////////////

#ifndef MassErrInfo_h
#define MassErrInfo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "MassPoint.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class MassErrInfo {
public:
    TTree *fChain; //!pointer to the analyzed TTree or TChain
    Int_t fCurrent; //!current Tree number in a TChain

    // Declaration of leaf types
    Float_t mass;
    Double_t mean_value;
    Double_t mean_statUnc;
    Double_t mean_bDown;
    Double_t mean_bup;
    Double_t mean_JESD;
    Double_t mean_JESU;
    Double_t mean_JERD;
    Double_t mean_JERU;
    Double_t mean_mud;
    Double_t mean_muu;
    Double_t mean_pud;
    Double_t mean_puu;
    Double_t mean_cb_value;
    Double_t mean_cb_statUnc;
    Double_t mean_cb_bDown;
    Double_t mean_cb_bup;
    Double_t mean_cb_JESD;
    Double_t mean_cb_JESU;
    Double_t mean_cb_JERD;
    Double_t mean_cb_JERU;
    Double_t mean_cb_mud;
    Double_t mean_cb_muu;
    Double_t mean_cb_pud;
    Double_t mean_cb_puu;
    Double_t width_value;
    Double_t width_statUnc;
    Double_t width_bDown;
    Double_t width_bup;
    Double_t width_JESD;
    Double_t width_JESU;
    Double_t width_JERD;
    Double_t width_JERU;
    Double_t width_mud;
    Double_t width_muu;
    Double_t width_pud;
    Double_t width_puu;
    Double_t sigma_value;
    Double_t sigma_statUnc;
    Double_t sigma_bDown;
    Double_t sigma_bup;
    Double_t sigma_JESD;
    Double_t sigma_JESU;
    Double_t sigma_JERD;
    Double_t sigma_JERU;
    Double_t sigma_mud;
    Double_t sigma_muu;
    Double_t sigma_pud;
    Double_t sigma_puu;
    Double_t sigma_cb_value;
    Double_t sigma_cb_statUnc;
    Double_t sigma_cb_bDown;
    Double_t sigma_cb_bup;
    Double_t sigma_cb_JESD;
    Double_t sigma_cb_JESU;
    Double_t sigma_cb_JERD;
    Double_t sigma_cb_JERU;
    Double_t sigma_cb_mud;
    Double_t sigma_cb_muu;
    Double_t sigma_cb_pud;
    Double_t sigma_cb_puu;
    Double_t frac_value;
    Double_t frac_statUnc;
    Double_t frac_bDown;
    Double_t frac_bup;
    Double_t frac_JESD;
    Double_t frac_JESU;
    Double_t frac_JERD;
    Double_t frac_JERU;
    Double_t frac_mud;
    Double_t frac_muu;
    Double_t frac_pud;
    Double_t frac_puu;
    Double_t alpha_value;
    Double_t alpha_statUnc;
    Double_t alpha_bDown;
    Double_t alpha_bup;
    Double_t alpha_JESD;
    Double_t alpha_JESU;
    Double_t alpha_JERD;
    Double_t alpha_JERU;
    Double_t alpha_mud;
    Double_t alpha_muu;
    Double_t alpha_pud;
    Double_t alpha_puu;
    Double_t n_value;
    Double_t n_statUnc;
    Double_t n_bDown;
    Double_t n_bup;
    Double_t n_JESD;
    Double_t n_JESU;
    Double_t n_JERD;
    Double_t n_JERU;
    Double_t n_mud;
    Double_t n_muu;
    Double_t n_pud;
    Double_t n_puu;

    // List of branches
    TBranch *b_mass; //!
    TBranch *b_mean; //!
    TBranch *b_mean_cb; //!
    TBranch *b_width; //!
    TBranch *b_sigma; //!
    TBranch *b_sigma_cb; //!
    TBranch *b_frac; //!
    TBranch *b_alpha; //!
    TBranch *b_n; //!

    MassErrInfo(TTree *tree, TString treeName = "MassTree") : fChain(0) {
        Init(tree);
    }

    virtual ~MassErrInfo() {
        if (!fChain) return;
        delete fChain->GetCurrentFile();
    }

    virtual Int_t Cut(Long64_t entry) {
        // This function may be called from Loop.
        // returns  1 if entry is accepted.
        // returns -1 otherwise.
        return 1;
    }

    virtual Int_t GetEntry(Long64_t entry) {
        // Read contents of entry.
        if (!fChain) return 0;
        return fChain->GetEntry(entry);
    }

    virtual Long64_t LoadTree(Long64_t entry) {
        // Set the environment to read one entry
        if (!fChain) return -5;
        Long64_t centry = fChain->LoadTree(entry);
        if (centry < 0) return centry;
        if (fChain->GetTreeNumber() != fCurrent) {
            fCurrent = fChain->GetTreeNumber();
            Notify();
        }
        return centry;
    }

    virtual void Init(TTree *tree) {
        // The Init() function is called when the selector needs to initialize
        // a new tree or chain. Typically here the branch addresses and branch
        // pointers of the tree will be set.
        // It is normally not necessary to make changes to the generated
        // code, but the routine can be extended by the user if needed.
        // Init() will be called many times when running on PROOF
        // (once per file to be processed).

        // Set branch addresses and branch pointers
        if (!tree) return;
        fChain = tree;
        fCurrent = -1;
        fChain->SetMakeClass(1);

        fChain->SetBranchAddress("mass", &mass, &b_mass);
        fChain->SetBranchAddress("mean", &mean_value, &b_mean);
        fChain->SetBranchAddress("mean_cb", &mean_cb_value, &b_mean_cb);
        fChain->SetBranchAddress("width", &width_value, &b_width);
        fChain->SetBranchAddress("sigma", &sigma_value, &b_sigma);
        fChain->SetBranchAddress("sigma_cb", &sigma_cb_value, &b_sigma_cb);
        fChain->SetBranchAddress("frac", &frac_value, &b_frac);
        fChain->SetBranchAddress("alpha", &alpha_value, &b_alpha);
        fChain->SetBranchAddress("n", &n_value, &b_n);
        Notify();
    }

    virtual void Loop() {
        //   In a ROOT session, you can do:
        //      Root > .L MassErrInfo.C
        //      Root > MassErrInfo t
        //      Root > t.GetEntry(12); // Fill t data members with entry number 12
        //      Root > t.Show();       // Show values of entry 12
        //      Root > t.Show(16);     // Read and show values of entry 16
        //      Root > t.Loop();       // Loop on all entries
        //

        //     This is the loop skeleton where:
        //    jentry is the global entry number in the chain
        //    ientry is the entry number in the current Tree
        //  Note that the argument to GetEntry must be:
        //    jentry for TChain::GetEntry
        //    ientry for TTree::GetEntry and TBranch::GetEntry
        //
        //       To read only selected branches, Insert statements like:
        // METHOD1:
        //    fChain->SetBranchStatus("*",0);  // disable all branches
        //    fChain->SetBranchStatus("branchname",1);  // activate branchname
        // METHOD2: replace line
        //    fChain->GetEntry(jentry);       //read all branches
        //by  b_branchname->GetEntry(ientry); //read only this branch
        if (fChain == 0) return;

        Long64_t nentries = fChain->GetEntriesFast();

        Long64_t nbytes = 0, nb = 0;
        for (Long64_t jentry = 0; jentry < nentries; jentry++) {
            Long64_t ientry = LoadTree(jentry);
            if (ientry < 0) break;
            nb = fChain->GetEntry(jentry);
            nbytes += nb;
            // if (Cut(ientry) < 0) continue;
        }
    }

    virtual Bool_t Notify() {
        // The Notify() function is called when a new file is opened. This
        // can be either for a new TTree in a TChain or when when a new TTree
        // is started when using PROOF. It is normally not necessary to make changes
        // to the generated code, but the routine can be extended by the
        // user if needed. The return value is currently not used.

        return kTRUE;
    }

    virtual void Show(Long64_t entry) {
        // Print contents of entry.
        // If entry is not specified, print current entry
        if (!fChain) return;
        fChain->Show(entry);
    };

    ValueUncert MakeStruct(TString input) {
        ValueUncert ret;
        if (input == "mean") {
            ret.value = this->mean_value;
            ret.statUnc = this->mean_statUnc;
            ret.JESD = this->mean_JESD;
            ret.JESU = this->mean_JESU;
            ret.JERD = this->mean_JERD;
            ret.JERU = this->mean_JERU;
            ret.bUp = this->mean_bup;
            ret.bDown = this->mean_bDown;
            ret.puu = this->mean_bup;
            ret.pud = this->mean_pud;
            ret.muu = this->mean_bup;
            ret.mud = this->mean_mud;
        } else if (input == "mean_cb") {
            ret.value = this->mean_cb_value;
            ret.statUnc = this->mean_cb_statUnc;
            ret.JESD = this->mean_cb_JESD;
            ret.JESU = this->mean_cb_JESU;
            ret.JERD = this->mean_cb_JERD;
            ret.JERU = this->mean_cb_JERU;
            ret.bUp = this->mean_cb_bup;
            ret.bDown = this->mean_cb_bDown;
            ret.puu = this->mean_cb_bup;
            ret.pud = this->mean_cb_pud;
            ret.muu = this->mean_cb_bup;
            ret.mud = this->mean_cb_mud;
        } else if (input == "sigma_cb") {
            ret.value = this->sigma_cb_value;
            ret.statUnc = this->sigma_cb_statUnc;
            ret.JESD = this->sigma_cb_JESD;
            ret.JESU = this->sigma_cb_JESU;
            ret.JERD = this->sigma_cb_JERD;
            ret.JERU = this->sigma_cb_JERU;
            ret.bUp = this->sigma_cb_bup;
            ret.bDown = this->sigma_cb_bDown;
            ret.puu = this->sigma_cb_bup;
            ret.pud = this->sigma_cb_pud;
            ret.muu = this->sigma_cb_bup;
            ret.mud = this->sigma_cb_mud;
        } else if (input == "sigma") {
            ret.value = this->sigma_value;
            ret.statUnc = this->sigma_statUnc;
            ret.JESD = this->sigma_JESD;
            ret.JESU = this->sigma_JESU;
            ret.JERD = this->sigma_JERD;
            ret.JERU = this->sigma_JERU;
            ret.bUp = this->sigma_bup;
            ret.bDown = this->sigma_bDown;
            ret.puu = this->sigma_bup;
            ret.pud = this->sigma_pud;
            ret.muu = this->sigma_bup;
            ret.mud = this->sigma_mud;
        } else if (input == "alpha") {
            ret.value = this->alpha_value;
            ret.statUnc = this->alpha_statUnc;
            ret.JESD = this->alpha_JESD;
            ret.JESU = this->alpha_JESU;
            ret.JERD = this->alpha_JERD;
            ret.JERU = this->alpha_JERU;
            ret.bUp = this->alpha_bup;
            ret.bDown = this->alpha_bDown;
            ret.puu = this->alpha_bup;
            ret.pud = this->alpha_pud;
            ret.muu = this->alpha_bup;
            ret.mud = this->alpha_mud;
        } else if (input == "frac") {
            ret.value = this->frac_value;
            ret.statUnc = this->frac_statUnc;
            ret.JESD = this->frac_JESD;
            ret.JESU = this->frac_JESU;
            ret.JERD = this->frac_JERD;
            ret.JERU = this->frac_JERU;
            ret.bUp = this->frac_bup;
            ret.bDown = this->frac_bDown;
            ret.puu = this->frac_bup;
            ret.pud = this->frac_pud;
            ret.muu = this->frac_bup;
            ret.mud = this->frac_mud;
        } else if (input == TString("n")) {
            ret.value = this->n_value;
            ret.statUnc = this->n_statUnc;
            ret.JESD = this->n_JESD;
            ret.JESU = this->n_JESU;
            ret.JERD = this->n_JERD;
            ret.JERU = this->n_JERU;
            ret.bUp = this->n_bup;
            ret.bDown = this->n_bDown;
            ret.puu = this->n_bup;
            ret.pud = this->n_pud;
            ret.muu = this->n_bup;
            ret.mud = this->n_mud;
        }
        return ret;
    }
};

#endif


