/* 
 * File:   DelphesHistCreator.C
 * Author: nadjieh
 *
 * Created on June 14, 2014, 8:18 AM
 */
#include <string>
#include <iostream>
#include <vector>
#include "../interface/DelphesTree.h"
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
            inputfilename = "~/work/MG5_aMC_v2_1_0/signalA" + in + "/Events/run_01/tag_1_delphes_events.root";
            outfilename = "delphesHists_ma" + in + ".root";
        } else if (arg_fth == "run") {
            f++;
            std::string in(*(argv + f));
            run = in;
        } else if (arg_fth == "input") {
            f++;
            std::string in(*(argv + f));
            inputfilename = "~/work/MG5_aMC_v2_1_0/" + in + "/Events/run_0" + run + "/tag_1_delphes_events.root";
            outfilename = "delphesHists_" + in + "_run0" + run + ".root";
        }
    }

    int cuts[10];

    TFile * f = TFile::Open(inputfilename.c_str());
    DelphesTree * dtree = 0;
    TTree * eventTree = 0;
    dtree = new DelphesTree(eventTree, f);

    /*
     * Histogram definitions
     */

    /*
     * Basic variable
     */
    TH1D * jetpt = new TH1D("jetpt", "jet p_{T}", 100, 0., 500.);
    jetpt->GetXaxis()->SetTitle("Jet p_{T} (GeV)");
    TH1D * seljetpt = (TH1D*) jetpt->Clone("seljetpt");
    seljetpt->SetTitle("selected jet p_{t}");

    TH1D * jeteta = new TH1D("jeteta", "jet #eta", 100, -5., 5.);
    jeteta->GetXaxis()->SetTitle("Jet #eta");
    TH1D * seljeteta = (TH1D*) jeteta->Clone("seljeteta");
    seljeteta->SetTitle("selected jet #eta");

    TH1D * bjetpt = new TH1D("bjetpt", "bjet p_{T}", 100, 0., 500.);
    bjetpt->GetXaxis()->SetTitle("b-Jet p_{T} (GeV)");
    TH1D * selbjetpt = (TH1D*) bjetpt->Clone("selbjetpt");
    selbjetpt->SetTitle("selected bjet p_{t}");

    TH1D * bjeteta = new TH1D("bjeteta", "bjet #eta", 100, -5., 5.);
    bjeteta->GetXaxis()->SetTitle("b-Jet #eta");
    TH1D * selbjeteta = (TH1D*) bjeteta->Clone("selbjeteta");
    selbjeteta->SetTitle("selected bjet #eta");

    TH1D * mupt = new TH1D("mupt", "mu p_{T}", 100, 0., 500.);
    mupt->GetXaxis()->SetTitle("Muon p_{T} (GeV)");
    TH1D * selmupt = (TH1D*) mupt->Clone("selmupt");
    selmupt->SetTitle("selected mu p_{t}");

    TH1D * mueta = new TH1D("mueta", "mu #eta", 100, -5., 5.);
    mueta->GetXaxis()->SetTitle("Muont #eta");
    TH1D * selmueta = (TH1D*) mueta->Clone("selmueta");
    selmueta->SetTitle("selected mu #eta");

    TH1D * mupt1 = new TH1D("mupt1", "first mu p_{T}", 100, 0., 500.);
    mupt1->GetXaxis()->SetTitle("Leading muon p_{T} (GeV)");
    TH1D * mupt2 = new TH1D("mupt2", "second mu p_{T}", 100, 0., 500.);
    mupt2->GetXaxis()->SetTitle("Sub-leading muon p_{T} (GeV)");

    TH1D * met = new TH1D("met", "MET", 100, 0, 100);
    met->GetXaxis()->SetTitle("MET (GeV)");
    TH1D * selmet = new TH1D("selmet", "MET", 100, 0, 100);
    selmet->GetXaxis()->SetTitle("MET (GeV)");

    TH1D * ht = new TH1D("ht", "HT", 100, 0, 500);
    ht->GetXaxis()->SetTitle("H_{T} (GeV)");
    TH1D * selht = new TH1D("selht", "HT", 100, 0, 500);
    selht->GetXaxis()->SetTitle("H_{T} (GeV)");

    /*
     * invariant masses, pts, etas
     */

    TH1D * invMass_mu = new TH1D("mumumass", "m_{#mu#mu}", 100, 0., 200.);
    invMass_mu->GetXaxis()->SetTitle("m_{#mu#mu} (GeV)");
    TH1D * invMass_b = new TH1D("bbmass", "m_{bb}", 100, 0., 200.);
    invMass_b->GetXaxis()->SetTitle("m_{bb} (GeV)");
    TH1D * invMass_bmu = new TH1D("hmass", "m_{bb#mu#mu}", 250, 0., 500.);
    invMass_bmu->GetXaxis()->SetTitle("m_{Higgs} (GeV)");

    TH1D * mmpt = new TH1D("mmpt", "p_{T}^{#mu#mu}", 100, 0., 500.);
    mmpt->GetXaxis()->SetTitle("p_{T}^{#mu#mu} (GeV)");
    TH1D * bbpt = new TH1D("bbpt", "p_{T}^{bb}", 100, 0., 500.);
    bbpt->GetXaxis()->SetTitle("p_{T}^{bb} (GeV)");
    TH1D * mbpt = new TH1D("hpt", "p_{T}^{h}", 100, 0., 500.);
    mbpt->GetXaxis()->SetTitle("p_{T}^{h} (GeV)");

    TH1D * mmeta = new TH1D("mmeta", "#eta_{#mu#mu}", 100, -5., 5.);
    mmeta->GetXaxis()->SetTitle("#eta_{#mu#mu} ");
    TH1D * bbeta = new TH1D("bbeta", "#eta_{bb}", 100, -5., 5.);
    bbeta->GetXaxis()->SetTitle("#eta_{bb} ");
    TH1D * mbeta = new TH1D("heta", "#eta_{bb#mu#mu}", 100, -5., 5.);
    mbeta->GetXaxis()->SetTitle("#eta_{h} ");

    TH3D * invMass = new TH3D("invMass", "invMass", 100, 0., 200, 100, 0., 200, 100, 0., 200);
    invMass->GetXaxis()->SetTitle("m_{#mu#mu} (GeV)");
    invMass->GetYaxis()->SetTitle("m_{bb} (GeV)");
    invMass->GetZaxis()->SetTitle("m_{Higgs} (GeV)");

    TH1D * dMass = new TH1D("dMass", "#Delta m_{a,a}", 100, 0., 100.);
    dMass->GetXaxis()->SetTitle("#Delta m_{a,a} (GeV)");

    /*
     * multiplicity
     */
    TH1D * muMult = new TH1D("muMult", "muMult", 10, -0.5, 9.5);
    muMult->GetXaxis()->SetTitle("N_{#mu}");
    TH1D * jetMult = new TH1D("jetMult", "jetMult", 10, -0.5, 9.5);
    jetMult->GetXaxis()->SetTitle("N_{jet}");
    TH1D * bjetMult = new TH1D("bjetMult", "bjetMult", 10, -0.5, 9.5);
    bjetMult->GetXaxis()->SetTitle("N_{b-jet}");
    TH1D * rawmuMult = new TH1D("rawmuMult", "rawmuMult", 10, -0.5, 9.5);
    rawmuMult->GetXaxis()->SetTitle("N_{#mu}");
    TH1D * rawjetMult = new TH1D("rawjetMult", "rawjetMult", 10, -0.5, 9.5);
    rawjetMult->GetXaxis()->SetTitle("N_{jet}");
    TH1D * rawbjetMult = new TH1D("rawbjetMult", "rawbjetMult", 10, -0.5, 9.5);
    rawbjetMult->GetXaxis()->SetTitle("N_{b-jet}");

    /*
     * separations
     */
    //DRs
    TH1D * DRmm = new TH1D("DRmm", "#Delta R (#mu,#mu)", 100, 0., 10.);
    DRmm->GetXaxis()->SetTitle("#Delta R (#mu,#mu)");
    TH1D * DRbb = new TH1D("DRbb", "#Delta R (b,b)", 100, 0., 10.);
    DRbb->GetXaxis()->SetTitle("#Delta R (b,b)");
    TH1D * DRaa = new TH1D("DRaa", "#Delta R (a,a)", 100, 0., 10.);
    DRaa->GetXaxis()->SetTitle("#Delta R (a,a)");

    //DPhis
    TH1D * DPhimm = new TH1D("DPhimm", "#Delta#phi (#mu,#mu)", 80, -4.0, 4.0);
    DPhimm->GetXaxis()->SetTitle("#Delta#phi (#mu,#mu)");
    TH1D * DPhibb = new TH1D("DPhibb", "#Delta#phi (b,b)", 80, -4.0, 4.0);
    DPhibb->GetXaxis()->SetTitle("#Delta#phi (b,b)");
    TH1D * DPhiaa = new TH1D("DPhiaa", "#Delta#phi (a,a)", 80, -4.0, 4.0);
    DPhiaa->GetXaxis()->SetTitle("#Delta#phi (a,a)");

    TH1D * cutFlow = new TH1D("CutFlow", "cut flow", 10, -0.5, 9.5);

    TH2D * jet_bjet = new TH2D("jettag", "jet tag multiplicity", 10, -0.5, 9.5, 10, -0.5, 9.5);
    jet_bjet->GetXaxis()->SetTitle("N_{jets}");
    jet_bjet->GetYaxis()->SetTitle("N_{b-jets}");

    TH2D * jet_bjet_sel = new TH2D("jettag_dimu", "jet tag multiplicity", 10, -0.5, 9.5, 10, -0.5, 9.5);
    jet_bjet_sel->GetXaxis()->SetTitle("N_{jets}");
    jet_bjet_sel->GetYaxis()->SetTitle("N_{b-jets}");


    /*
     * Loop over events
     */

    for (int eventNumber = 0; eventNumber < dtree->fChain->GetEntriesFast(); eventNumber++) {
        dtree->GetEntry(eventNumber);

        rawmuMult->Fill(dtree->Muon_size);
        std::vector<TLorentzVector> muons = dtree->GetSelectedMuons(0., 12.);
        for (unsigned int s = 0; s < muons.size(); s++) {
            mupt->Fill(muons[s].Pt());
            mueta->Fill(muons[s].Eta());
        }
        if (muons.size() >= 2) {
            mupt1->Fill(muons[0].Pt());
            mupt2->Fill(muons[1].Pt());
        }

        std::vector<TLorentzVector> selmuons = dtree->GetSelectedMuons(20., 2.1);
        muMult->Fill(selmuons.size());
        for (unsigned int s = 0; s < selmuons.size(); s++) {
            selmupt->Fill(selmuons[s].Pt());
            selmueta->Fill(selmuons[s].Eta());
        }

        rawjetMult->Fill(dtree->Jet_size);
        std::vector<TLorentzVector> jets = dtree->GetSelectedJets(0., 12.);
        for (unsigned int s = 0; s < jets.size(); s++) {
            jetpt->Fill(jets[s].Pt());
            jeteta->Fill(jets[s].Eta());
        }

        std::vector<TLorentzVector> seljets = dtree->GetSelectedJets(25., 2.5);
        jetMult->Fill(seljets.size());
        for (unsigned int s = 0; s < seljets.size(); s++) {
            seljetpt->Fill(seljets[s].Pt());
            seljeteta->Fill(seljets[s].Eta());
        }

        std::vector<TLorentzVector> bjets = dtree->GetSelectedBJets(0., 12.);
        rawbjetMult->Fill(bjets.size());
        for (unsigned int s = 0; s < bjets.size(); s++) {
            bjetpt->Fill(bjets[s].Pt());
            bjeteta->Fill(bjets[s].Eta());
        }

        std::vector<TLorentzVector> selbjets = dtree->GetSelectedBJets(25., 2.5);
        bjetMult->Fill(selbjets.size());
        for (unsigned int s = 0; s < selbjets.size(); s++) {
            selbjetpt->Fill(selbjets[s].Pt());
            selbjeteta->Fill(selbjets[s].Eta());
        }


        jet_bjet->Fill(seljets.size(), selbjets.size());
        met->Fill(dtree->MissingET_MET[0]);
        ht->Fill(dtree->ScalarHT_HT[0]);

        /*
         * Event selection
         */
        cuts[0]++;
        std::vector<TLorentzVector> mupair = dtree->GetSelectedMuPair(20., 2.1);
        if (mupair.size() < 2)
            continue;
        cuts[1]++;
        jet_bjet_sel->Fill(seljets.size(), selbjets.size());

        if (selbjets.size() < 2)
            continue;
        cuts[2]++;

        selmet->Fill(dtree->MissingET_MET[0]);
        selht->Fill(dtree->ScalarHT_HT[0]);


        invMass_mu->Fill(dtree->GetInvMass(mupair));
        DRmm->Fill(mupair[0].DeltaR(mupair[1]));
        DPhimm->Fill(mupair[0].DeltaPhi(mupair[1]));

        std::vector<TLorentzVector> bjets_a;
        bjets_a.push_back(selbjets[0]);
        bjets_a.push_back(selbjets[1]);
        double mbb = dtree->GetInvMass(bjets_a);
        invMass_b->Fill(mbb);
        dMass->Fill(fabs(mbb - dtree->GetInvMass(mupair)));
        
        DRbb->Fill(selbjets[0].DeltaR(selbjets[1]));
        DPhibb->Fill(selbjets[0].DeltaPhi(selbjets[1]));
        bjets_a.push_back(mupair[0]);
        bjets_a.push_back(mupair[1]);
        invMass_bmu->Fill(dtree->GetInvMass(bjets_a));
        invMass->Fill(dtree->GetInvMass(mupair), mbb, dtree->GetInvMass(bjets_a));

        TLorentzVector amuCand = mupair[0] + mupair[1];
        mmpt->Fill(amuCand.Pt());
        mmeta->Fill(amuCand.Eta());

        TLorentzVector abCand = selbjets[0] + selbjets[1];
        bbpt->Fill(abCand.Pt());
        bbeta->Fill(abCand.Eta());

        TLorentzVector hcand(0, 0, 0, 0);
        for (unsigned int s = 0; s < bjets_a.size(); s++)
            hcand += bjets_a[s];
        mbpt->Fill(hcand.Pt());
        mbeta->Fill(hcand.Eta());

        DRaa->Fill(abCand.DeltaR(amuCand));
        DPhiaa->Fill(abCand.DeltaPhi(amuCand));
    }

    cutFlow->SetBinContent(1, cuts[0]);
    cutFlow->SetBinContent(2, cuts[1]);
    cutFlow->SetBinContent(3, cuts[2]);

    TFile * outfile = new TFile(outfilename.c_str(), "recreate");
    outfile->cd();

    jetpt->Write();
    jeteta->Write();
    seljetpt->Write();
    seljeteta->Write();

    bjetpt->Write();
    bjeteta->Write();
    selbjetpt->Write();
    selbjeteta->Write();

    mupt->Write();
    mueta->Write();
    mupt1->Write();
    mupt2->Write();
    selmupt->Write();
    selmueta->Write();

    jetMult->Write();
    bjetMult->Write();
    muMult->Write();

    DRbb->Write();
    DPhibb->Write();
    invMass_b->Write();
    bbpt->Write();
    bbeta->Write();

    DRmm->Write();
    DPhimm->Write();
    invMass_mu->Write();
    mmpt->Write();
    mmeta->Write();

    DRaa->Write();
    DPhiaa->Write();

    invMass_bmu->Write();
    mbpt->Write();
    mbeta->Write();

    jet_bjet->Write();
    jet_bjet_sel->Write();

    rawbjetMult->Write();
    rawjetMult->Write();
    rawmuMult->Write();

    met->Write();
    ht->Write();
    selmet->Write();
    selht->Write();

    invMass->Write();
    dMass->Write();
    cutFlow->Write();
    outfile->Close();
    return 1;
}

