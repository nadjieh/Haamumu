//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jul 26 17:38:03 2014 by ROOT version 5.34/03
// from TTree limit/limit
// found on file: higgsCombine4observed.Asymptotic.mH120.root
//////////////////////////////////////////////////////////

#ifndef myLimits_h
#define myLimits_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class myLimits {
public:
    TTree *fChain; //!pointer to the analyzed TTree or TChain
    Int_t fCurrent; //!current Tree number in a TChain

    // Declaration of leaf types
    Double_t limit;
    Double_t limitErr;
    Double_t mh;
    Int_t syst;
    Int_t iToy;
    Int_t iSeed;
    Int_t iChannel;
    Float_t t_cpu;
    Float_t t_real;
    Float_t quantileExpected;

    // List of branches
    TBranch *b_limit; //!
    TBranch *b_limitErr; //!
    TBranch *b_mh; //!
    TBranch *b_syst; //!
    TBranch *b_iToy; //!
    TBranch *b_iSeed; //!
    TBranch *b_iChannel; //!
    TBranch *b_t_cpu; //!
    TBranch *b_t_real; //!
    TBranch *b_quantileExpected; //!

    myLimits(TTree *tree = 0, TFile * f = 0, TString treeName = "limit") {
        // if parameter tree is not specified (or zero), connect the file
        // used to generate this class and read the Tree.
        if (tree == 0) {
            if (f != NULL)
                f->GetObject(treeName, tree);

        }
        Init(tree);
    }

    virtual ~myLimits() {
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

    virtual void Init(TTree * tree) {
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

        fChain->SetBranchAddress("limit", &limit, &b_limit);
        fChain->SetBranchAddress("limitErr", &limitErr, &b_limitErr);
        fChain->SetBranchAddress("mh", &mh, &b_mh);
        fChain->SetBranchAddress("syst", &syst, &b_syst);
        fChain->SetBranchAddress("iToy", &iToy, &b_iToy);
        fChain->SetBranchAddress("iSeed", &iSeed, &b_iSeed);
        fChain->SetBranchAddress("iChannel", &iChannel, &b_iChannel);
        fChain->SetBranchAddress("t_cpu", &t_cpu, &b_t_cpu);
        fChain->SetBranchAddress("t_real", &t_real, &b_t_real);
        fChain->SetBranchAddress("quantileExpected", &quantileExpected, &b_quantileExpected);
        Notify();
    }

    virtual void Loop() {
        //   In a ROOT session, you can do:
        //      Root > .L myLimits.C
        //      Root > myLimits t
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