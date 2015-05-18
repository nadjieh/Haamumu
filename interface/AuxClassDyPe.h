//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 15 17:47:28 2014 by ROOT version 5.34/19
// from TTree PETree/PE results
// found on file: DYPE_out.root
//////////////////////////////////////////////////////////

#ifndef AuxClassDyPe_h
#define AuxClassDyPe_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class AuxClassDyPe {
public:
    TTree *fChain; //!pointer to the analyzed TTree or TChain
    Int_t fCurrent; //!current Tree number in a TChain

    // Declaration of leaf types
    Int_t rsize;
    Float_t means[3]; //[rsize]
    Float_t errs[3]; //[rsize]
    Float_t Mean_bw[2];
    Float_t Sigma_bw[2];
    Float_t Mean_cb[2];
    Float_t Sigma_cb[2];
    Float_t N[2];
    Float_t Alpha[2];
    Float_t Lambda[2];

    // List of branches
    TBranch *b_rsize; //!
    TBranch *b_means; //!
    TBranch *b_errs; //!
    TBranch *b_Mean_bw; //!
    TBranch *b_Sigma_bw; //!
    TBranch *b_Mean_cb; //!
    TBranch *b_Sigma_cb; //!
    TBranch *b_N; //!
    TBranch *b_Alpha; //!
    TBranch *b_Lambda; //!

    AuxClassDyPe(TTree *tree, TString treeName = "PETree") : fChain(0) {
        // if parameter tree is not specified (or zero), connect the file
        // used to generate this class and read the Tree.
        Init(tree);
    }

    virtual ~AuxClassDyPe() {
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

        fChain->SetBranchAddress("rsize", &rsize, &b_rsize);
        fChain->SetBranchAddress("means", means, &b_means);
        fChain->SetBranchAddress("errs", errs, &b_errs);
        fChain->SetBranchAddress("Mean_bw", Mean_bw, &b_Mean_bw);
        fChain->SetBranchAddress("Sigma_bw", Sigma_bw, &b_Sigma_bw);
        fChain->SetBranchAddress("Mean_cb", Mean_cb, &b_Mean_cb);
        fChain->SetBranchAddress("Sigma_cb", Sigma_cb, &b_Sigma_cb);
        fChain->SetBranchAddress("N", N, &b_N);
        fChain->SetBranchAddress("Alpha", Alpha, &b_Alpha);
        fChain->SetBranchAddress("Lambda", Lambda, &b_Lambda);
        Notify();
    }

    virtual void Loop() {
        //   In a ROOT session, you can do:
        //      Root > .L AuxClassDyPe.C
        //      Root > AuxClassDyPe t
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

    virtual void Show(Long64_t entry = -1) {
        // Print contents of entry.
        // If entry is not specified, print current entry
        if (!fChain) return;
        fChain->Show(entry);
    }
};

#endif



