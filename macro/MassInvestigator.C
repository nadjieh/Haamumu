/* 
 * File:   MassInvestigator.C
 * Author: nadjieh
 *
 * Created on May 6, 2015, 5:50 PM
 */

#include "../interface/MassPoint.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::vector<MassPoint*> myMasses;
    myMasses.push_back(new MassPoint(30, "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-", "_LowJetPt10_Summer12_final_4_4.root", "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_", "_Summer12_final_4_4.root"));
    myMasses[0]->SetNInit(3., 0., 6.);
    myMasses[0]->SetAlphaInit(1.09, 0.0, 5.0);
    myMasses[0]->SetWidthInit(1., 0.0, 1.8);
    myMasses[0]->SetSigmaInit(0.2, 0.0, 1.);

    myMasses.push_back(new MassPoint(40, "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-", "_LowJetPt10_Summer12_final_4_4.root", "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_", "_Summer12_final_4_4.root"));
    myMasses[1]->SetNInit(3., 0., 6.);
    myMasses[1]->SetAlphaInit(1.09, 0.0, 5.0);
    myMasses[1]->SetWidthInit(1., 0.0, 1.8);
    myMasses[1]->SetSigmaInit(0.2, 0.0, 1.);
    //
    myMasses.push_back(new MassPoint(50, "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-", "_LowJetPt10_Summer12_final_4_4.root", "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_", "_Summer12_final_4_4.root"));
    myMasses[2]->SetNInit(3., 0., 6.);
    myMasses[2]->SetAlphaInit(1.09, 0.0, 5.0);
    myMasses[2]->SetWidthInit(1., 0.0, 1.8);
    myMasses[2]->SetSigmaInit(0.2, 0.0, 1.);

    myMasses.push_back(new MassPoint(60, "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-", "_LowJetPt10_Summer12_final_4_4.root", "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_", "_Summer12_final_4_4.root"));
    myMasses[3]->SetNInit(3., 0., 6.);
    myMasses[3]->SetAlphaInit(1.09, 0.0, 5.0);
    myMasses[3]->SetWidthInit(1., 0.0, 3.);
    myMasses[3]->SetSigmaInit(0.2, 0.0, 1.);
    myMasses[3]->SetMeanCBInit(60., 50., 70.);

    for (unsigned int i = 0; i < myMasses.size(); i++) {
        myMasses[i]->fillValues(true);
    }
    const int nMax = 20;
    TFile f("Info.root", "recreate");
    TTree MassTree("MassTree", "MassTree");
    /*
     * parameters
     */
    ValueUncert mean, mean_cb, width, sigma, sigma_cb, frac, alpha, n;
    float mass;
    MassTree.Branch("mass", &mass, "mass/F");
    MassTree.Branch("mean", &mean, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    //    MassTree.Branch("mean_cb", &mean_cb, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("width", &width, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("sigma", &sigma, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("sigma_cb", &sigma_cb, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("frac", &frac, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("alpha", &alpha, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");
    MassTree.Branch("n", &n, "value/D:statUnc/D:bDown/D:bup/D:JESD/D:JESU/D:JERD/D:JERU/D:mud/D:muu/D:pud/D:puu/D");

    /*
     * Fill Tree
     */
    for (unsigned int i = 0; i < myMasses.size(); i++) {
        mass = myMasses[i]->GetMass();

        std::map<TString, double> paramNominal = myMasses[i]->GetParamNominal();
        mean.value = paramNominal["mean"];
        cout << paramNominal["mean"] << endl;
        //        mean_cb.value = paramNominal["mean_cb"];
        sigma_cb.value = paramNominal["sigma_cb"];
        sigma.value = paramNominal["sigma"];
        width.value = paramNominal["width"];
        //        frac.value = paramNominal["frac"];
        //        n.value = paramNominal["n"];
        //        alpha.value = paramNominal["alpha"];

        std::map<TString, double> paramNominalErr = myMasses[i]->GetParamNominalErr();
        mean.statUnc = paramNominalErr["mean"];
        //        mean_cb.statUnc = paramNominalErr["mean_cb"];
        sigma_cb.statUnc = paramNominalErr["sigma_cb"];
        sigma.statUnc = paramNominalErr["sigma"];
        width.statUnc = paramNominalErr["width"];
        //        frac.statUnc = paramNominalErr["frac"];
        //        n.statUnc = paramNominalErr["n"];
        //        alpha.statUnc = paramNominalErr["alpha"];

        std::map <TString, std::pair<double, double> > paramSystb = myMasses[i]->GetParamErrorsInd("b");
        mean.bDown = paramSystb["mean"].first;
        mean.bUp = paramSystb["mean"].second;
        //        mean_cb.bDown = paramSystb["mean_cb"].first;
        //        mean_cb.bUp = paramSystb["mean_cb"].second;
        sigma.bDown = paramSystb["sigma"].first;
        sigma.bUp = paramSystb["sigma"].second;
        sigma_cb.bDown = paramSystb["sigma_cb"].first;
        sigma_cb.bUp = paramSystb["sigma_cb"].second;
        //        alpha.bDown = paramSystb["alpha"].first;
        //        alpha.bUp = paramSystb["alpha"].second;
        width.bDown = paramSystb["width"].first;
        width.bUp = paramSystb["width"].second;
        //        frac.bDown = paramSystb["frac"].first;
        //        frac.bUp = paramSystb["frac"].second;
        //        n.bDown = paramSystb["n"].first;
        //        n.bUp = paramSystb["n"].second;

        std::map <TString, std::pair<double, double> > paramSystJES = myMasses[i]->GetParamErrorsInd("JES");
        mean.JESD = paramSystJES["mean"].first;
        mean.JESU = paramSystJES["mean"].second;
        //        mean_cb.JESD = paramSystJES["mean_cb"].first;
        //        mean_cb.JESU = paramSystJES["mean_cb"].second;
        sigma.JESD = paramSystJES["sigma"].first;
        sigma.JESU = paramSystJES["sigma"].second;
        sigma_cb.JESD = paramSystJES["sigma_cb"].first;
        sigma_cb.JESU = paramSystJES["sigma_cb"].second;
        //        alpha.JESD = paramSystJES["alpha"].first;
        //        alpha.JESU = paramSystJES["alpha"].second;
        width.JESD = paramSystb["width"].first;
        width.JESU = paramSystb["width"].second;
        //        frac.JESD = paramSystJES["frac"].first;
        //        frac.JESU = paramSystJES["frac"].second;
        //        n.JESD = paramSystJES["n"].first;
        //        n.JESU = paramSystJES["n"].second;

        std::map <TString, std::pair<double, double> > paramSystJER = myMasses[i]->GetParamErrorsInd("JER");
        mean.JERD = paramSystJER["mean"].first;
        mean.JERU = paramSystJER["mean"].second;
        //        mean_cb.JERD = paramSystJER["mean_cb"].first;
        //        mean_cb.JERU = paramSystJER["mean_cb"].second;
        sigma.JERD = paramSystJER["sigma"].first;
        sigma.JERU = paramSystJER["sigma"].second;
        sigma_cb.JERD = paramSystJER["sigma_cb"].first;
        sigma_cb.JERU = paramSystJER["sigma_cb"].second;
        //        alpha.JERD = paramSystJER["alpha"].first;
        //        alpha.JERU = paramSystJER["alpha"].second;
        width.JERD = paramSystb["width"].first;
        width.JERU = paramSystb["width"].second;
        //        frac.JERD = paramSystJER["frac"].first;
        //        frac.JERU = paramSystJER["frac"].second;
        //        n.JERD = paramSystJER["n"].first;
        //        n.JERU = paramSystJER["n"].second;

        std::map <TString, std::pair<double, double> > paramSystmu = myMasses[i]->GetParamErrorsInd("mu");
        mean.mud = paramSystmu["mean"].first;
        mean.muu = paramSystmu["mean"].second;
        //        mean_cb.mud = paramSystmu["mean_cb"].first;
        //        mean_cb.muu = paramSystmu["mean_cb"].second;
        sigma.mud = paramSystmu["sigma"].first;
        sigma.muu = paramSystmu["sigma"].second;
        sigma_cb.mud = paramSystmu["sigma_cb"].first;
        sigma_cb.muu = paramSystmu["sigma_cb"].second;
        //        alpha.mud = paramSystmu["alpha"].first;
        //        alpha.muu = paramSystmu["alpha"].second;
        width.mud = paramSystb["width"].first;
        width.muu = paramSystb["width"].second;
        //        frac.mud = paramSystmu["frac"].first;
        //        frac.muu = paramSystmu["frac"].second;
        //        n.mud = paramSystmu["n"].first;
        //        n.muu = paramSystmu["n"].second;

        std::map <TString, std::pair<double, double> > paramSystpu = myMasses[i]->GetParamErrorsInd("pu");
        mean.pud = paramSystpu["mean"].first;
        mean.puu = paramSystpu["mean"].second;
        //        mean_cb.pud = paramSystpu["mean_cb"].first;
        //        mean_cb.puu = paramSystpu["mean_cb"].second;
        sigma.pud = paramSystpu["sigma"].first;
        sigma.puu = paramSystpu["sigma"].second;
        sigma_cb.pud = paramSystpu["sigma_cb"].first;
        sigma_cb.puu = paramSystpu["sigma_cb"].second;
        //        alpha.pud = paramSystpu["alpha"].first;
        //        alpha.puu = paramSystpu["alpha"].second;
        width.pud = paramSystb["width"].first;
        width.puu = paramSystb["width"].second;
        //        frac.pud = paramSystpu["frac"].first;
        //        frac.puu = paramSystpu["frac"].second;
        //        n.pud = paramSystpu["n"].first;
        //        n.puu = paramSystpu["n"].second;
        MassTree.Fill();
    }
    MassTree.Write();
    f.Write();
    f.Close();

    /*
     * Test the tree
     */
    TFile file("Info.root", "read");
    TTree *tree = (TTree*) file.Get("MassTree");
    tree->ls();
    Long64_t numEntries = tree->GetEntries();
    cout << "numEntries " << numEntries << endl;
    ValueUncert mean2, mean_cb2, width2, sigma2, sigma_cb2, frac2, alpha2, n2;
    float mass2;
    tree->SetBranchAddress("mass", &mass2);
    tree->SetBranchAddress("mean", &mean2);
    //    tree->SetBranchAddress("mean_cb", &mean_cb2);
    tree->SetBranchAddress("width", &width2);
    tree->SetBranchAddress("sigma", &sigma2);
    tree->SetBranchAddress("sigma_cb", &sigma_cb2);
    tree->SetBranchAddress("frac", &frac2);
    tree->SetBranchAddress("alpha", &alpha2);
    tree->SetBranchAddress("n", &n2);
    for (int i = 0; i < numEntries; i++) {
        tree->GetEntry(i);
        cout << mass2 << "\n"
                << "mean: " << mean2.value << "\t" << mean2.statUnc << "\n"
                //                << "mean_cb: " << mean_cb2.value << "\t" << mean_cb2.statUnc << "\n"
                << "width: " << width2.value << "\t" << width2.statUnc << "\n"
                << "sigma: " << sigma2.value << "\t" << sigma2.statUnc << "\n"
                << "sigma_cb: " << sigma_cb2.value << "\t" << sigma_cb2.statUnc << "\n"
                << "frac: " << frac2.value << "\t" << frac2.statUnc << "\n"
                << "alpha: " << alpha2.value << "\t" << alpha2.statUnc << "\n"
                << "n: " << n2.value << "\t" << n2.statUnc << endl;
    }

    return 0;
}

