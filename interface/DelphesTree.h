//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 13 12:05:34 2014 by ROOT version 5.32/00
// from TTree Delphes/Analysis tree
// found on file: ../../MG5_aMC_v2_1_0/signalA45/Events/run_01/tag_1_delphes_events.root
//////////////////////////////////////////////////////////

#ifndef DelphesTree_h
#define DelphesTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <iostream>
#include <string>
// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TRef.h>
#include <TRefArray.h>
using namespace std;

struct ArraySorter {

    bool operator() (std::pair<double, int> comb1, std::pair<double, int> comb2) {
        return (comb1.first > comb2.first);
    }
};
// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxEvent = 1;
const Int_t kMaxParticle = 693;
const Int_t kMaxTrack = 64;
const Int_t kMaxTower = 302;
const Int_t kMaxEFlowTrack = 64;
const Int_t kMaxEFlowTower = 269;
const Int_t kMaxEFlowMuon = 5;
const Int_t kMaxJet = 10;
const Int_t kMaxElectron = 1;
const Int_t kMaxPhoton = 2;
const Int_t kMaxMuon = 3;
const Int_t kMaxMissingET = 1;
const Int_t kMaxScalarHT = 1;

class DelphesTree {
public:
    TTree *fChain; //!pointer to the analyzed TTree or TChain
    Int_t fCurrent; //!current Tree number in a TChain

    // Declaration of leaf types
    Int_t Event_;
    UInt_t Event_fUniqueID[kMaxEvent]; //[Event_]
    UInt_t Event_fBits[kMaxEvent]; //[Event_]
    Long64_t Event_Number[kMaxEvent]; //[Event_]
    Float_t Event_ReadTime[kMaxEvent]; //[Event_]
    Float_t Event_ProcTime[kMaxEvent]; //[Event_]
    Int_t Event_ProcessID[kMaxEvent]; //[Event_]
    Float_t Event_Weight[kMaxEvent]; //[Event_]
    Float_t Event_ScalePDF[kMaxEvent]; //[Event_]
    Float_t Event_AlphaQED[kMaxEvent]; //[Event_]
    Float_t Event_AlphaQCD[kMaxEvent]; //[Event_]
    Int_t Event_size;
    Int_t Particle_;
    UInt_t Particle_fUniqueID[kMaxParticle]; //[Particle_]
    UInt_t Particle_fBits[kMaxParticle]; //[Particle_]
    Int_t Particle_PID[kMaxParticle]; //[Particle_]
    Int_t Particle_Status[kMaxParticle]; //[Particle_]
    Int_t Particle_IsPU[kMaxParticle]; //[Particle_]
    Int_t Particle_M1[kMaxParticle]; //[Particle_]
    Int_t Particle_M2[kMaxParticle]; //[Particle_]
    Int_t Particle_D1[kMaxParticle]; //[Particle_]
    Int_t Particle_D2[kMaxParticle]; //[Particle_]
    Int_t Particle_Charge[kMaxParticle]; //[Particle_]
    Float_t Particle_Mass[kMaxParticle]; //[Particle_]
    Float_t Particle_E[kMaxParticle]; //[Particle_]
    Float_t Particle_Px[kMaxParticle]; //[Particle_]
    Float_t Particle_Py[kMaxParticle]; //[Particle_]
    Float_t Particle_Pz[kMaxParticle]; //[Particle_]
    Float_t Particle_PT[kMaxParticle]; //[Particle_]
    Float_t Particle_Eta[kMaxParticle]; //[Particle_]
    Float_t Particle_Phi[kMaxParticle]; //[Particle_]
    Float_t Particle_Rapidity[kMaxParticle]; //[Particle_]
    Float_t Particle_T[kMaxParticle]; //[Particle_]
    Float_t Particle_X[kMaxParticle]; //[Particle_]
    Float_t Particle_Y[kMaxParticle]; //[Particle_]
    Float_t Particle_Z[kMaxParticle]; //[Particle_]
    Int_t Particle_size;
    Int_t Track_;
    UInt_t Track_fUniqueID[kMaxTrack]; //[Track_]
    UInt_t Track_fBits[kMaxTrack]; //[Track_]
    Int_t Track_PID[kMaxTrack]; //[Track_]
    Int_t Track_Charge[kMaxTrack]; //[Track_]
    Float_t Track_PT[kMaxTrack]; //[Track_]
    Float_t Track_Eta[kMaxTrack]; //[Track_]
    Float_t Track_Phi[kMaxTrack]; //[Track_]
    Float_t Track_EtaOuter[kMaxTrack]; //[Track_]
    Float_t Track_PhiOuter[kMaxTrack]; //[Track_]
    Float_t Track_X[kMaxTrack]; //[Track_]
    Float_t Track_Y[kMaxTrack]; //[Track_]
    Float_t Track_Z[kMaxTrack]; //[Track_]
    Float_t Track_T[kMaxTrack]; //[Track_]
    Float_t Track_XOuter[kMaxTrack]; //[Track_]
    Float_t Track_YOuter[kMaxTrack]; //[Track_]
    Float_t Track_ZOuter[kMaxTrack]; //[Track_]
    Float_t Track_TOuter[kMaxTrack]; //[Track_]
    TRef Track_Particle[kMaxTrack];
    Int_t Track_size;
    Int_t Tower_;
    UInt_t Tower_fUniqueID[kMaxTower]; //[Tower_]
    UInt_t Tower_fBits[kMaxTower]; //[Tower_]
    Float_t Tower_ET[kMaxTower]; //[Tower_]
    Float_t Tower_Eta[kMaxTower]; //[Tower_]
    Float_t Tower_Phi[kMaxTower]; //[Tower_]
    Float_t Tower_E[kMaxTower]; //[Tower_]
    Float_t Tower_T[kMaxTower]; //[Tower_]
    Float_t Tower_Eem[kMaxTower]; //[Tower_]
    Float_t Tower_Ehad[kMaxTower]; //[Tower_]
    Float_t Tower_Edges[kMaxTower][4]; //[Tower_]
    TRefArray Tower_Particles[kMaxTower];
    Int_t Tower_size;
    Int_t EFlowTrack_;
    UInt_t EFlowTrack_fUniqueID[kMaxEFlowTrack]; //[EFlowTrack_]
    UInt_t EFlowTrack_fBits[kMaxEFlowTrack]; //[EFlowTrack_]
    Int_t EFlowTrack_PID[kMaxEFlowTrack]; //[EFlowTrack_]
    Int_t EFlowTrack_Charge[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_PT[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_Eta[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_Phi[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_EtaOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_PhiOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_X[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_Y[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_Z[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_T[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_XOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_YOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_ZOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    Float_t EFlowTrack_TOuter[kMaxEFlowTrack]; //[EFlowTrack_]
    TRef EFlowTrack_Particle[kMaxEFlowTrack];
    Int_t EFlowTrack_size;
    Int_t EFlowTower_;
    UInt_t EFlowTower_fUniqueID[kMaxEFlowTower]; //[EFlowTower_]
    UInt_t EFlowTower_fBits[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_ET[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_Eta[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_Phi[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_E[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_T[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_Eem[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_Ehad[kMaxEFlowTower]; //[EFlowTower_]
    Float_t EFlowTower_Edges[kMaxEFlowTower][4]; //[EFlowTower_]
    TRefArray EFlowTower_Particles[kMaxEFlowTower];
    Int_t EFlowTower_size;
    Int_t EFlowMuon_;
    UInt_t EFlowMuon_fUniqueID[kMaxEFlowMuon]; //[EFlowMuon_]
    UInt_t EFlowMuon_fBits[kMaxEFlowMuon]; //[EFlowMuon_]
    Float_t EFlowMuon_PT[kMaxEFlowMuon]; //[EFlowMuon_]
    Float_t EFlowMuon_Eta[kMaxEFlowMuon]; //[EFlowMuon_]
    Float_t EFlowMuon_Phi[kMaxEFlowMuon]; //[EFlowMuon_]
    Float_t EFlowMuon_T[kMaxEFlowMuon]; //[EFlowMuon_]
    Int_t EFlowMuon_Charge[kMaxEFlowMuon]; //[EFlowMuon_]
    TRef EFlowMuon_Particle[kMaxEFlowMuon];
    Int_t EFlowMuon_size;
    Int_t Jet_;
    UInt_t Jet_fUniqueID[kMaxJet]; //[Jet_]
    UInt_t Jet_fBits[kMaxJet]; //[Jet_]
    Float_t Jet_PT[kMaxJet]; //[Jet_]
    Float_t Jet_Eta[kMaxJet]; //[Jet_]
    Float_t Jet_Phi[kMaxJet]; //[Jet_]
    Float_t Jet_T[kMaxJet]; //[Jet_]
    Float_t Jet_Mass[kMaxJet]; //[Jet_]
    Float_t Jet_DeltaEta[kMaxJet]; //[Jet_]
    Float_t Jet_DeltaPhi[kMaxJet]; //[Jet_]
    UInt_t Jet_BTag[kMaxJet]; //[Jet_]
    UInt_t Jet_TauTag[kMaxJet]; //[Jet_]
    Int_t Jet_Charge[kMaxJet]; //[Jet_]
    Float_t Jet_EhadOverEem[kMaxJet]; //[Jet_]
    TRefArray Jet_Constituents[kMaxJet];
    TRefArray Jet_Particles[kMaxJet];
    Int_t Jet_NCharged[kMaxJet]; //[Jet_]
    Int_t Jet_NNeutrals[kMaxJet]; //[Jet_]
    Float_t Jet_Beta[kMaxJet]; //[Jet_]
    Float_t Jet_BetaStar[kMaxJet]; //[Jet_]
    Float_t Jet_MeanSqDeltaR[kMaxJet]; //[Jet_]
    Float_t Jet_PTD[kMaxJet]; //[Jet_]
    Float_t Jet_FracPt[kMaxJet][5]; //[Jet_]
    Int_t Jet_size;
    Int_t Electron_;
    UInt_t Electron_fUniqueID[kMaxElectron]; //[Electron_]
    UInt_t Electron_fBits[kMaxElectron]; //[Electron_]
    Float_t Electron_PT[kMaxElectron]; //[Electron_]
    Float_t Electron_Eta[kMaxElectron]; //[Electron_]
    Float_t Electron_Phi[kMaxElectron]; //[Electron_]
    Float_t Electron_T[kMaxElectron]; //[Electron_]
    Int_t Electron_Charge[kMaxElectron]; //[Electron_]
    Float_t Electron_EhadOverEem[kMaxElectron]; //[Electron_]
    TRef Electron_Particle[kMaxElectron];
    Int_t Electron_size;
    Int_t Photon_;
    UInt_t Photon_fUniqueID[kMaxPhoton]; //[Photon_]
    UInt_t Photon_fBits[kMaxPhoton]; //[Photon_]
    Float_t Photon_PT[kMaxPhoton]; //[Photon_]
    Float_t Photon_Eta[kMaxPhoton]; //[Photon_]
    Float_t Photon_Phi[kMaxPhoton]; //[Photon_]
    Float_t Photon_E[kMaxPhoton]; //[Photon_]
    Float_t Photon_T[kMaxPhoton]; //[Photon_]
    Float_t Photon_EhadOverEem[kMaxPhoton]; //[Photon_]
    TRefArray Photon_Particles[kMaxPhoton];
    Int_t Photon_size;
    Int_t Muon_;
    UInt_t Muon_fUniqueID[kMaxMuon]; //[Muon_]
    UInt_t Muon_fBits[kMaxMuon]; //[Muon_]
    Float_t Muon_PT[kMaxMuon]; //[Muon_]
    Float_t Muon_Eta[kMaxMuon]; //[Muon_]
    Float_t Muon_Phi[kMaxMuon]; //[Muon_]
    Float_t Muon_T[kMaxMuon]; //[Muon_]
    Int_t Muon_Charge[kMaxMuon]; //[Muon_]
    TRef Muon_Particle[kMaxMuon];
    Int_t Muon_size;
    Int_t MissingET_;
    UInt_t MissingET_fUniqueID[kMaxMissingET]; //[MissingET_]
    UInt_t MissingET_fBits[kMaxMissingET]; //[MissingET_]
    Float_t MissingET_MET[kMaxMissingET]; //[MissingET_]
    Float_t MissingET_Eta[kMaxMissingET]; //[MissingET_]
    Float_t MissingET_Phi[kMaxMissingET]; //[MissingET_]
    Int_t MissingET_size;
    Int_t ScalarHT_;
    UInt_t ScalarHT_fUniqueID[kMaxScalarHT]; //[ScalarHT_]
    UInt_t ScalarHT_fBits[kMaxScalarHT]; //[ScalarHT_]
    Float_t ScalarHT_HT[kMaxScalarHT]; //[ScalarHT_]
    Int_t ScalarHT_size;

    // List of branches
    TBranch *b_Event_; //!
    TBranch *b_Event_fUniqueID; //!
    TBranch *b_Event_fBits; //!
    TBranch *b_Event_Number; //!
    TBranch *b_Event_ReadTime; //!
    TBranch *b_Event_ProcTime; //!
    TBranch *b_Event_ProcessID; //!
    TBranch *b_Event_Weight; //!
    TBranch *b_Event_ScalePDF; //!
    TBranch *b_Event_AlphaQED; //!
    TBranch *b_Event_AlphaQCD; //!
    TBranch *b_Event_size; //!
    TBranch *b_Particle_; //!
    TBranch *b_Particle_fUniqueID; //!
    TBranch *b_Particle_fBits; //!
    TBranch *b_Particle_PID; //!
    TBranch *b_Particle_Status; //!
    TBranch *b_Particle_IsPU; //!
    TBranch *b_Particle_M1; //!
    TBranch *b_Particle_M2; //!
    TBranch *b_Particle_D1; //!
    TBranch *b_Particle_D2; //!
    TBranch *b_Particle_Charge; //!
    TBranch *b_Particle_Mass; //!
    TBranch *b_Particle_E; //!
    TBranch *b_Particle_Px; //!
    TBranch *b_Particle_Py; //!
    TBranch *b_Particle_Pz; //!
    TBranch *b_Particle_PT; //!
    TBranch *b_Particle_Eta; //!
    TBranch *b_Particle_Phi; //!
    TBranch *b_Particle_Rapidity; //!
    TBranch *b_Particle_T; //!
    TBranch *b_Particle_X; //!
    TBranch *b_Particle_Y; //!
    TBranch *b_Particle_Z; //!
    TBranch *b_Particle_size; //!
    TBranch *b_Track_; //!
    TBranch *b_Track_fUniqueID; //!
    TBranch *b_Track_fBits; //!
    TBranch *b_Track_PID; //!
    TBranch *b_Track_Charge; //!
    TBranch *b_Track_PT; //!
    TBranch *b_Track_Eta; //!
    TBranch *b_Track_Phi; //!
    TBranch *b_Track_EtaOuter; //!
    TBranch *b_Track_PhiOuter; //!
    TBranch *b_Track_X; //!
    TBranch *b_Track_Y; //!
    TBranch *b_Track_Z; //!
    TBranch *b_Track_T; //!
    TBranch *b_Track_XOuter; //!
    TBranch *b_Track_YOuter; //!
    TBranch *b_Track_ZOuter; //!
    TBranch *b_Track_TOuter; //!
    TBranch *b_Track_Particle; //!
    TBranch *b_Track_size; //!
    TBranch *b_Tower_; //!
    TBranch *b_Tower_fUniqueID; //!
    TBranch *b_Tower_fBits; //!
    TBranch *b_Tower_ET; //!
    TBranch *b_Tower_Eta; //!
    TBranch *b_Tower_Phi; //!
    TBranch *b_Tower_E; //!
    TBranch *b_Tower_T; //!
    TBranch *b_Tower_Eem; //!
    TBranch *b_Tower_Ehad; //!
    TBranch *b_Tower_Edges; //!
    TBranch *b_Tower_Particles; //!
    TBranch *b_Tower_size; //!
    TBranch *b_EFlowTrack_; //!
    TBranch *b_EFlowTrack_fUniqueID; //!
    TBranch *b_EFlowTrack_fBits; //!
    TBranch *b_EFlowTrack_PID; //!
    TBranch *b_EFlowTrack_Charge; //!
    TBranch *b_EFlowTrack_PT; //!
    TBranch *b_EFlowTrack_Eta; //!
    TBranch *b_EFlowTrack_Phi; //!
    TBranch *b_EFlowTrack_EtaOuter; //!
    TBranch *b_EFlowTrack_PhiOuter; //!
    TBranch *b_EFlowTrack_X; //!
    TBranch *b_EFlowTrack_Y; //!
    TBranch *b_EFlowTrack_Z; //!
    TBranch *b_EFlowTrack_T; //!
    TBranch *b_EFlowTrack_XOuter; //!
    TBranch *b_EFlowTrack_YOuter; //!
    TBranch *b_EFlowTrack_ZOuter; //!
    TBranch *b_EFlowTrack_TOuter; //!
    TBranch *b_EFlowTrack_Particle; //!
    TBranch *b_EFlowTrack_size; //!
    TBranch *b_EFlowTower_; //!
    TBranch *b_EFlowTower_fUniqueID; //!
    TBranch *b_EFlowTower_fBits; //!
    TBranch *b_EFlowTower_ET; //!
    TBranch *b_EFlowTower_Eta; //!
    TBranch *b_EFlowTower_Phi; //!
    TBranch *b_EFlowTower_E; //!
    TBranch *b_EFlowTower_T; //!
    TBranch *b_EFlowTower_Eem; //!
    TBranch *b_EFlowTower_Ehad; //!
    TBranch *b_EFlowTower_Edges; //!
    TBranch *b_EFlowTower_Particles; //!
    TBranch *b_EFlowTower_size; //!
    TBranch *b_EFlowMuon_; //!
    TBranch *b_EFlowMuon_fUniqueID; //!
    TBranch *b_EFlowMuon_fBits; //!
    TBranch *b_EFlowMuon_PT; //!
    TBranch *b_EFlowMuon_Eta; //!
    TBranch *b_EFlowMuon_Phi; //!
    TBranch *b_EFlowMuon_T; //!
    TBranch *b_EFlowMuon_Charge; //!
    TBranch *b_EFlowMuon_Particle; //!
    TBranch *b_EFlowMuon_size; //!
    TBranch *b_Jet_; //!
    TBranch *b_Jet_fUniqueID; //!
    TBranch *b_Jet_fBits; //!
    TBranch *b_Jet_PT; //!
    TBranch *b_Jet_Eta; //!
    TBranch *b_Jet_Phi; //!
    TBranch *b_Jet_T; //!
    TBranch *b_Jet_Mass; //!
    TBranch *b_Jet_DeltaEta; //!
    TBranch *b_Jet_DeltaPhi; //!
    TBranch *b_Jet_BTag; //!
    TBranch *b_Jet_TauTag; //!
    TBranch *b_Jet_Charge; //!
    TBranch *b_Jet_EhadOverEem; //!
    TBranch *b_Jet_Constituents; //!
    TBranch *b_Jet_Particles; //!
    TBranch *b_Jet_NCharged; //!
    TBranch *b_Jet_NNeutrals; //!
    TBranch *b_Jet_Beta; //!
    TBranch *b_Jet_BetaStar; //!
    TBranch *b_Jet_MeanSqDeltaR; //!
    TBranch *b_Jet_PTD; //!
    TBranch *b_Jet_FracPt; //!
    TBranch *b_Jet_size; //!
    TBranch *b_Electron_; //!
    TBranch *b_Electron_fUniqueID; //!
    TBranch *b_Electron_fBits; //!
    TBranch *b_Electron_PT; //!
    TBranch *b_Electron_Eta; //!
    TBranch *b_Electron_Phi; //!
    TBranch *b_Electron_T; //!
    TBranch *b_Electron_Charge; //!
    TBranch *b_Electron_EhadOverEem; //!
    TBranch *b_Electron_Particle; //!
    TBranch *b_Electron_size; //!
    TBranch *b_Photon_; //!
    TBranch *b_Photon_fUniqueID; //!
    TBranch *b_Photon_fBits; //!
    TBranch *b_Photon_PT; //!
    TBranch *b_Photon_Eta; //!
    TBranch *b_Photon_Phi; //!
    TBranch *b_Photon_E; //!
    TBranch *b_Photon_T; //!
    TBranch *b_Photon_EhadOverEem; //!
    TBranch *b_Photon_Particles; //!
    TBranch *b_Photon_size; //!
    TBranch *b_Muon_; //!
    TBranch *b_Muon_fUniqueID; //!
    TBranch *b_Muon_fBits; //!
    TBranch *b_Muon_PT; //!
    TBranch *b_Muon_Eta; //!
    TBranch *b_Muon_Phi; //!
    TBranch *b_Muon_T; //!
    TBranch *b_Muon_Charge; //!
    TBranch *b_Muon_Particle; //!
    TBranch *b_Muon_size; //!
    TBranch *b_MissingET_; //!
    TBranch *b_MissingET_fUniqueID; //!
    TBranch *b_MissingET_fBits; //!
    TBranch *b_MissingET_MET; //!
    TBranch *b_MissingET_Eta; //!
    TBranch *b_MissingET_Phi; //!
    TBranch *b_MissingET_size; //!
    TBranch *b_ScalarHT_; //!
    TBranch *b_ScalarHT_fUniqueID; //!
    TBranch *b_ScalarHT_fBits; //!
    TBranch *b_ScalarHT_HT; //!
    TBranch *b_ScalarHT_size; //!

    DelphesTree(TTree *tree = 0, TFile * f = 0, TString treeName = "Delphes") {
        // if parameter tree is not specified (or zero), connect the file
        // used to generate this class and read the Tree.
        if (tree == 0) {
            if (f != NULL)
                f->GetObject(treeName, tree);

        }
        Init(tree);
    };

    virtual ~DelphesTree() {
        if (!fChain) return;
        delete fChain->GetCurrentFile();
    };

    virtual Int_t Cut(Long64_t entry) {
        // This function may be called from Loop.
        // returns  1 if entry is accepted.
        // returns -1 otherwise.
        return 1;
    };

    virtual Int_t GetEntry(Long64_t entry) {
        // Read contents of entry.
        if (!fChain) return 0;
        return fChain->GetEntry(entry);
    };

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
    };

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

        fChain->SetBranchAddress("Event", &Event_, &b_Event_);
        fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
        fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
        fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
        fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
        fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
        fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
        fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
        fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
        fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
        fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
        fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
        fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
        fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
        fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
        fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
        fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
        fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
        fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
        fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
        fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
        fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
        fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
        fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
        fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
        fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
        fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
        fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
        fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
        fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
        fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
        fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
        fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
        fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
        fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
        fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
        fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
        fChain->SetBranchAddress("Track", &Track_, &b_Track_);
        fChain->SetBranchAddress("Track.fUniqueID", Track_fUniqueID, &b_Track_fUniqueID);
        fChain->SetBranchAddress("Track.fBits", Track_fBits, &b_Track_fBits);
        fChain->SetBranchAddress("Track.PID", Track_PID, &b_Track_PID);
        fChain->SetBranchAddress("Track.Charge", Track_Charge, &b_Track_Charge);
        fChain->SetBranchAddress("Track.PT", Track_PT, &b_Track_PT);
        fChain->SetBranchAddress("Track.Eta", Track_Eta, &b_Track_Eta);
        fChain->SetBranchAddress("Track.Phi", Track_Phi, &b_Track_Phi);
        fChain->SetBranchAddress("Track.EtaOuter", Track_EtaOuter, &b_Track_EtaOuter);
        fChain->SetBranchAddress("Track.PhiOuter", Track_PhiOuter, &b_Track_PhiOuter);
        fChain->SetBranchAddress("Track.X", Track_X, &b_Track_X);
        fChain->SetBranchAddress("Track.Y", Track_Y, &b_Track_Y);
        fChain->SetBranchAddress("Track.Z", Track_Z, &b_Track_Z);
        fChain->SetBranchAddress("Track.T", Track_T, &b_Track_T);
        fChain->SetBranchAddress("Track.XOuter", Track_XOuter, &b_Track_XOuter);
        fChain->SetBranchAddress("Track.YOuter", Track_YOuter, &b_Track_YOuter);
        fChain->SetBranchAddress("Track.ZOuter", Track_ZOuter, &b_Track_ZOuter);
        fChain->SetBranchAddress("Track.TOuter", Track_TOuter, &b_Track_TOuter);
        fChain->SetBranchAddress("Track.Particle", Track_Particle, &b_Track_Particle);
        fChain->SetBranchAddress("Track_size", &Track_size, &b_Track_size);
        fChain->SetBranchAddress("Tower", &Tower_, &b_Tower_);
        fChain->SetBranchAddress("Tower.fUniqueID", Tower_fUniqueID, &b_Tower_fUniqueID);
        fChain->SetBranchAddress("Tower.fBits", Tower_fBits, &b_Tower_fBits);
        fChain->SetBranchAddress("Tower.ET", Tower_ET, &b_Tower_ET);
        fChain->SetBranchAddress("Tower.Eta", Tower_Eta, &b_Tower_Eta);
        fChain->SetBranchAddress("Tower.Phi", Tower_Phi, &b_Tower_Phi);
        fChain->SetBranchAddress("Tower.E", Tower_E, &b_Tower_E);
        fChain->SetBranchAddress("Tower.T", Tower_T, &b_Tower_T);
        fChain->SetBranchAddress("Tower.Eem", Tower_Eem, &b_Tower_Eem);
        fChain->SetBranchAddress("Tower.Ehad", Tower_Ehad, &b_Tower_Ehad);
        fChain->SetBranchAddress("Tower.Edges[4]", Tower_Edges, &b_Tower_Edges);
        fChain->SetBranchAddress("Tower.Particles", Tower_Particles, &b_Tower_Particles);
        fChain->SetBranchAddress("Tower_size", &Tower_size, &b_Tower_size);
        fChain->SetBranchAddress("EFlowTrack", &EFlowTrack_, &b_EFlowTrack_);
        fChain->SetBranchAddress("EFlowTrack.fUniqueID", EFlowTrack_fUniqueID, &b_EFlowTrack_fUniqueID);
        fChain->SetBranchAddress("EFlowTrack.fBits", EFlowTrack_fBits, &b_EFlowTrack_fBits);
        fChain->SetBranchAddress("EFlowTrack.PID", EFlowTrack_PID, &b_EFlowTrack_PID);
        fChain->SetBranchAddress("EFlowTrack.Charge", EFlowTrack_Charge, &b_EFlowTrack_Charge);
        fChain->SetBranchAddress("EFlowTrack.PT", EFlowTrack_PT, &b_EFlowTrack_PT);
        fChain->SetBranchAddress("EFlowTrack.Eta", EFlowTrack_Eta, &b_EFlowTrack_Eta);
        fChain->SetBranchAddress("EFlowTrack.Phi", EFlowTrack_Phi, &b_EFlowTrack_Phi);
        fChain->SetBranchAddress("EFlowTrack.EtaOuter", EFlowTrack_EtaOuter, &b_EFlowTrack_EtaOuter);
        fChain->SetBranchAddress("EFlowTrack.PhiOuter", EFlowTrack_PhiOuter, &b_EFlowTrack_PhiOuter);
        fChain->SetBranchAddress("EFlowTrack.X", EFlowTrack_X, &b_EFlowTrack_X);
        fChain->SetBranchAddress("EFlowTrack.Y", EFlowTrack_Y, &b_EFlowTrack_Y);
        fChain->SetBranchAddress("EFlowTrack.Z", EFlowTrack_Z, &b_EFlowTrack_Z);
        fChain->SetBranchAddress("EFlowTrack.T", EFlowTrack_T, &b_EFlowTrack_T);
        fChain->SetBranchAddress("EFlowTrack.XOuter", EFlowTrack_XOuter, &b_EFlowTrack_XOuter);
        fChain->SetBranchAddress("EFlowTrack.YOuter", EFlowTrack_YOuter, &b_EFlowTrack_YOuter);
        fChain->SetBranchAddress("EFlowTrack.ZOuter", EFlowTrack_ZOuter, &b_EFlowTrack_ZOuter);
        fChain->SetBranchAddress("EFlowTrack.TOuter", EFlowTrack_TOuter, &b_EFlowTrack_TOuter);
        fChain->SetBranchAddress("EFlowTrack.Particle", EFlowTrack_Particle, &b_EFlowTrack_Particle);
        fChain->SetBranchAddress("EFlowTrack_size", &EFlowTrack_size, &b_EFlowTrack_size);
        fChain->SetBranchAddress("EFlowTower", &EFlowTower_, &b_EFlowTower_);
        fChain->SetBranchAddress("EFlowTower.fUniqueID", EFlowTower_fUniqueID, &b_EFlowTower_fUniqueID);
        fChain->SetBranchAddress("EFlowTower.fBits", EFlowTower_fBits, &b_EFlowTower_fBits);
        fChain->SetBranchAddress("EFlowTower.ET", EFlowTower_ET, &b_EFlowTower_ET);
        fChain->SetBranchAddress("EFlowTower.Eta", EFlowTower_Eta, &b_EFlowTower_Eta);
        fChain->SetBranchAddress("EFlowTower.Phi", EFlowTower_Phi, &b_EFlowTower_Phi);
        fChain->SetBranchAddress("EFlowTower.E", EFlowTower_E, &b_EFlowTower_E);
        fChain->SetBranchAddress("EFlowTower.T", EFlowTower_T, &b_EFlowTower_T);
        fChain->SetBranchAddress("EFlowTower.Eem", EFlowTower_Eem, &b_EFlowTower_Eem);
        fChain->SetBranchAddress("EFlowTower.Ehad", EFlowTower_Ehad, &b_EFlowTower_Ehad);
        fChain->SetBranchAddress("EFlowTower.Edges[4]", EFlowTower_Edges, &b_EFlowTower_Edges);
        fChain->SetBranchAddress("EFlowTower.Particles", EFlowTower_Particles, &b_EFlowTower_Particles);
        fChain->SetBranchAddress("EFlowTower_size", &EFlowTower_size, &b_EFlowTower_size);
        fChain->SetBranchAddress("EFlowMuon", &EFlowMuon_, &b_EFlowMuon_);
        fChain->SetBranchAddress("EFlowMuon.fUniqueID", EFlowMuon_fUniqueID, &b_EFlowMuon_fUniqueID);
        fChain->SetBranchAddress("EFlowMuon.fBits", EFlowMuon_fBits, &b_EFlowMuon_fBits);
        fChain->SetBranchAddress("EFlowMuon.PT", EFlowMuon_PT, &b_EFlowMuon_PT);
        fChain->SetBranchAddress("EFlowMuon.Eta", EFlowMuon_Eta, &b_EFlowMuon_Eta);
        fChain->SetBranchAddress("EFlowMuon.Phi", EFlowMuon_Phi, &b_EFlowMuon_Phi);
        fChain->SetBranchAddress("EFlowMuon.T", EFlowMuon_T, &b_EFlowMuon_T);
        fChain->SetBranchAddress("EFlowMuon.Charge", EFlowMuon_Charge, &b_EFlowMuon_Charge);
        fChain->SetBranchAddress("EFlowMuon.Particle", EFlowMuon_Particle, &b_EFlowMuon_Particle);
        fChain->SetBranchAddress("EFlowMuon_size", &EFlowMuon_size, &b_EFlowMuon_size);
        fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
        fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
        fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
        fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
        fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
        fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
        fChain->SetBranchAddress("Jet.T", Jet_T, &b_Jet_T);
        fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
        fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
        fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
        fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
        fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
        fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
        fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
        fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
        fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
        fChain->SetBranchAddress("Jet.NCharged", Jet_NCharged, &b_Jet_NCharged);
        fChain->SetBranchAddress("Jet.NNeutrals", Jet_NNeutrals, &b_Jet_NNeutrals);
        fChain->SetBranchAddress("Jet.Beta", Jet_Beta, &b_Jet_Beta);
        fChain->SetBranchAddress("Jet.BetaStar", Jet_BetaStar, &b_Jet_BetaStar);
        fChain->SetBranchAddress("Jet.MeanSqDeltaR", Jet_MeanSqDeltaR, &b_Jet_MeanSqDeltaR);
        fChain->SetBranchAddress("Jet.PTD", Jet_PTD, &b_Jet_PTD);
        fChain->SetBranchAddress("Jet.FracPt[5]", Jet_FracPt, &b_Jet_FracPt);
        fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
        fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
        fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
        fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
        fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
        fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
        fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
        fChain->SetBranchAddress("Electron.T", Electron_T, &b_Electron_T);
        fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
        fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
        fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
        fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
        fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
        fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
        fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
        fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
        fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
        fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
        fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
        fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
        fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
        fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
        fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
        fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
        fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
        fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
        fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
        fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
        fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
        fChain->SetBranchAddress("Muon.T", Muon_T, &b_Muon_T);
        fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
        fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
        fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
        fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
        fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
        fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
        fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
        fChain->SetBranchAddress("MissingET.Eta", MissingET_Eta, &b_MissingET_Eta);
        fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
        fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
        fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
        fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
        fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
        fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
        fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
        Notify();
    };

    virtual void Loop() {
        //   In a ROOT session, you can do:
        //      Root > .L DelphesTree.C
        //      Root > DelphesTree t
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
    };

    virtual Bool_t Notify() { // The Notify() function is called when a new file is opened. This
        // can be either for a new TTree in a TChain or when when a new TTree
        // is started when using PROOF. It is normally not necessary to make changes
        // to the generated code, but the routine can be extended by the
        // user if needed. The return value is currently not used.

        return kTRUE;
    };

    virtual void Show(Long64_t entry = -1) {
        // Print contents of entry.
        // If entry is not specified, print current entry
        if (!fChain) return;
        fChain->Show(entry);
    };

    //Helper methods

    double GetJetEnergy(int i, bool massive = true) {
        TLorentzVector ret(-1, -1, -1, -1);
        ret.SetXYZT(this->Jet_PT[i] * TMath::Cos(this->Jet_Phi[i]),
                this->Jet_PT[i] * TMath::Sin(this->Jet_Phi[i]),
                this->Jet_PT[i] * sinh(this->Jet_Eta[i]), 0);
        double P2 = pow(ret.X(), 2) + pow(ret.Y(), 2) + pow(ret.Z(), 2);
        if (!massive)
            return sqrt(P2);
        double E2 = fabs(P2 - pow(Jet_Mass[i], 2));
        return sqrt(E2);
    }

    TLorentzVector GetJet(int i, bool massive = true) {
        TLorentzVector ret(-1, -1, -1, -1);
        double ejet = this->GetJetEnergy(i, massive);
        ret.SetPtEtaPhiE(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], ejet);
        return ret;
    }

    TLorentzVector GetMassiveJet(int i) {
        return this->GetJet(i, true);
    }

    TLorentzVector GetMasslesJet(int i) {
        return this->GetJet(i, false);
    }

    std::vector<TLorentzVector> GetBjets(bool massive = true) {
        std::vector<TLorentzVector> ret;
        for (int i = 0; i < Jet_size; i++) {
            if (Jet_BTag[i]) {
                if (massive)
                    ret.push_back(this->GetMassiveJet(i));
                else
                    ret.push_back(this->GetMasslesJet(i));
            }
        }
        return ret;
    }

    TLorentzVector GetMuon(int i) {
        TLorentzVector ret(-1, -1, -1, -1);
        if (i > Muon_size) {
            std::cout << "Out of the jet range, will return a meaningless value" << std::endl;
            return ret;
        }
        ret.SetXYZT(this->Muon_PT[i] * TMath::Cos(this->Muon_Phi[i]),
                this->Muon_PT[i] * TMath::Sin(this->Muon_Phi[i]),
                this->Muon_PT[i] * sinh(this->Muon_Eta[i]),
                this->Muon_PT[i] * cosh(this->Muon_Eta[i]));
        return ret;
    }

    std::vector<TLorentzVector> GetSelectedJets(double ptcut, double etacut, bool massive = true) {
        std::vector<TLorentzVector> ret;
        for (int i = 0; i < Jet_size; i++) {
            if (Jet_PT[i] > ptcut && fabs(Jet_Eta[i]) < etacut) {
                if (massive)
                    ret.push_back(this->GetMassiveJet(i));
                else
                    ret.push_back(this->GetMasslesJet(i));
            }
        }
        return ret;
    }

    std::vector<TLorentzVector> GetSelectedBJets(double ptcut, double etacut, bool massive = true) {
        std::vector<TLorentzVector> ret;
        for (int i = 0; i < Jet_size; i++) {
            if (!Jet_BTag[i])
                continue;
            if (Jet_PT[i] > ptcut && fabs(Jet_Eta[i]) < etacut) {
                if (massive)
                    ret.push_back(this->GetMassiveJet(i));
                else
                    ret.push_back(this->GetMasslesJet(i));
            }
        }
        return ret;
    }

    std::vector<TLorentzVector> GetSelectedMuons(double ptcut, double etacut) {
        std::vector<TLorentzVector> ret;
        //        cout<<"Muon Size: "<<Muon_size<<endl;
        for (int i = 0; i < Muon_size; i++) {
            //            cout<<"\tpt: "<<Muon_PT[i]<<", decision: "<< (Muon_PT[i] > ptcut)<<endl;
            //            cout<<"\teta: "<<Muon_PT[i]<<", decision: "<< (fabs(Muon_Eta[i]) < etacut)<<endl;
            if (Muon_PT[i] > ptcut && fabs(Muon_Eta[i]) < etacut) {
                ret.push_back(this->GetMuon(i));
            }
            //            cout<<"\teta: "<<Muon_PT[i]<<", decision: "<< (fabs(Muon_Eta[i]) < etacut)<<endl;
        }
        return ret;
    }

    std::vector<TLorentzVector> GetSelectedMuPair(double ptcut, double etacut) {
        std::vector<TLorentzVector> ret;
        int charge = 0;
        for (int i = 0; i < Muon_size; i++) {
            if (Muon_PT[i] > ptcut && fabs(Muon_Eta[i]) < etacut) {
                if (ret.size() == 0) {
                    ret.push_back(this->GetMuon(i));
                    charge = Muon_Charge[i];
                } else {
                    if ((charge * Muon_Charge[i]) < 0)
                        ret.push_back(this->GetMuon(i));
                }
            }
        }
        return ret;
    }

    double GetInvMass(std::vector<TLorentzVector> input) {
        TLorentzVector ret(0., 0., 0., 0.);
        for (unsigned int i = 0; i < input.size(); i++)
            ret += input[i];
        return ret.M();
    }

};

#endif

