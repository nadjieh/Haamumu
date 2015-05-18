/* 
 * File:   InfoAnalyzer.C
 * Author: nadjieh
 *
 * Created on May 11, 2015, 3:37 PM
 */

#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "../interface/MassPoint.h"
#include "../interface/MassErrInfo.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

/*
 * 
 */
std::pair<double, double> GetEnvelope(ValueUncert input) {
    std::vector<double> systsUp;
    std::vector<double> systsDown;
    systsDown.push_back(input.JERD);
    systsDown.push_back(input.JESD);
    systsDown.push_back(input.mud);
    systsDown.push_back(input.bDown);
    systsDown.push_back(input.pud);
    cout << "------------------" << endl;
    cout << "------------------" << endl;
    for (unsigned int i = 0; i < systsDown.size(); i++) {
        cout << systsDown[i] << endl;
    }
    systsUp.push_back(input.JERU);
    systsUp.push_back(input.JESU);
    systsUp.push_back(input.muu);
    systsUp.push_back(input.bUp);
    systsUp.push_back(input.puu);
    cout << "------------------" << endl;
    for (unsigned int i = 0; i < systsUp.size(); i++) {
        cout << systsUp[i] << endl;
    }
    std::sort(systsUp.begin(), systsUp.end());
    std::sort(systsDown.begin(), systsDown.end());
    return make_pair(systsDown[systsDown.size() - 1], systsUp[systsUp.size() - 1]);
}

int main(int argc, char** argv) {
    TFile * file = TFile::Open("Info.root");
    TTree *tree = (TTree*) file->Get("MassTree");
    MassErrInfo * myME = new MassErrInfo(tree);
    Long64_t numEntries = myME->fChain->GetEntriesFast();
    cout << "numEntries " << numEntries << endl;
    ValueUncert mean2, mean_cb2, width2, sigma2, sigma_cb2, frac2, alpha2, n2;
    double mass[4];
    double mass_eL[4] = {0., 0., 0., 0.};
    double mass_eH[4] = {0., 0., 0., 0.};
    double mean[4];
    double mean_eL[4];
    double mean_eH[4];
    double mean_e[4];
    double mean_cb[4];
    double mean_cb_eL[4];
    double mean_cb_eH[4];
    double mean_cb_e[4];
    double width[4];
    double width_eL[4];
    double width_eH[4];
    double width_e[4];
    double sigma[4];
    double sigma_eL[4];
    double sigma_eH[4];
    double sigma_e[4];
    double sigma_cb[4];
    double sigma_cb_eL[4];
    double sigma_cb_eH[4];
    double sigma_cb_e[4];
    double frac[4];
    double frac_eL[4];
    double frac_eH[4];
    double frac_e[4];
    double alpha[4];
    double alpha_eL[4];
    double alpha_eH[4];
    double alpha_e[4];
    double n[4];
    double n_eL[4];
    double n_eH[4];
    double n_e[4];

    for (int i = 0; i < myME->fChain->GetEntriesFast(); i++) {
        myME->GetEntry(i);
        mass[i] = myME->mass;
        cout << ">>>>>>>>>>>>>>> Mass " << mass[i] << endl;

        mean2 = myME->MakeStruct("mean");
        mean[i] = mean2.value;
        std::pair<double, double> meanSyst = GetEnvelope(mean2);
        mean_eL[i] = fabs(meanSyst.first);
        mean_eH[i] = fabs(meanSyst.second);
        mean_e[i] = mean2.statUnc;

        //        mean_cb2 = myME->MakeStruct("mean_cb");
        //        mean_cb[i] = mean_cb2.value;
        //        std::pair<double, double> mean_cbSyst = GetEnvelope(mean_cb2);
        //        mean_cb_eL[i] = fabs(mean_cbSyst.first);
        //        mean_cb_eH[i] = fabs(mean_cbSyst.second);
        //        mean_cb_e[i] = mean_cb2.statUnc;

        cout << "width" << endl;
        width2 = myME->MakeStruct("width");
        width[i] = width2.value;
        std::pair<double, double> widthSyst = GetEnvelope(width2);
        width_eL[i] = fabs(widthSyst.first);
        width_eH[i] = fabs(widthSyst.second);
        width_e[i] = width2.statUnc;

        cout << "sigma" << endl;
        sigma2 = myME->MakeStruct("sigma");
        sigma[i] = sigma2.value;
        cout << "Sigma Value: " << sigma[i] << endl;
        std::pair<double, double> sigmaSyst = GetEnvelope(sigma2);
        sigma_eL[i] = fabs(sigmaSyst.first);
        sigma_eH[i] = fabs(sigmaSyst.second);
        sigma_e[i] = sigma2.statUnc;

        cout << "sigma_cb" << endl;
        sigma_cb2 = myME->MakeStruct("sigma_cb");
        sigma_cb[i] = sigma_cb2.value;
        std::pair<double, double> sigma_cbSyst = GetEnvelope(sigma_cb2);
        sigma_cb_eL[i] = fabs(sigma_cbSyst.first);
        sigma_cb_eH[i] = fabs(sigma_cbSyst.second);
        sigma_cb_e[i] = sigma_cb2.statUnc;

        cout << "frac ----" << endl;
        frac2 = myME->MakeStruct("frac");
        frac[i] = frac2.value;
        std::pair<double, double> fracSyst = GetEnvelope(frac2);
        frac_eL[i] = fabs(fracSyst.first);
        frac_eH[i] = fabs(fracSyst.second);
        frac_e[i] = frac2.statUnc;

        //        cout << "alpha" << endl;
        //        alpha2 = myME->MakeStruct("alpha");
        //        alpha[i] = alpha2.value;
        //        std::pair<double, double> alphaSyst = GetEnvelope(alpha2);
        //        alpha_eL[i] = fabs(alphaSyst.first);
        //        alpha_eH[i] = fabs(alphaSyst.second);
        //        alpha_e[i] = alpha2.statUnc;

        cout << "n" << endl;
        n2 = myME->MakeStruct("n");
        n[i] = n2.value;
        std::pair<double, double> nSyst = GetEnvelope(n2);
        n_eL[i] = fabs(nSyst.first);
        n_eH[i] = fabs(nSyst.second);
        n_e[i] = n2.statUnc;
    }
    TGraphAsymmErrors Mean(4, mass, mean, mass_eL, mass_eH, mean_eL, mean_eH);
    Mean.SetNameTitle("mean", "mean");
    TGraphAsymmErrors Sigma(4, mass, sigma, mass_eL, mass_eH, sigma_eL, sigma_eH);
    Sigma.SetNameTitle("sigma", "sigma");
    //    TGraphAsymmErrors MeanCB(4, mass, mean_cb, mass_eL, mass_eH, mean_cb_eL, mean_cb_eH);
    //    MeanCB.SetNameTitle("mean_cb", "mean_cb");
    TGraphAsymmErrors SigmaCB(4, mass, sigma_cb, mass_eL, mass_eH, sigma_cb_eL, sigma_cb_eH);
    SigmaCB.SetNameTitle("sigma_cb", "sigma_cb");
    TGraphAsymmErrors Width(4, mass, width, mass_eL, mass_eH, width_eL, width_eH);
    Width.SetNameTitle("width", "width");
    TGraphAsymmErrors N(4, mass, n, mass_eL, mass_eH, n_eL, n_eH);
    N.SetNameTitle("n", "n");
    //    TGraphAsymmErrors Alpha(4, mass, alpha, mass_eL, mass_eH, alpha_eL, alpha_eH);
    //    Alpha.SetNameTitle("alpha", "alpha");
    TGraphAsymmErrors Frac(4, mass, frac, mass_eL, mass_eH, frac_eL, frac_eH);
    Frac.SetNameTitle("frac", "frac");

    TGraphErrors MeanStat(4, mass, mean, mass_eL, mean_e);
    MeanStat.SetNameTitle("meanStat", "mean");
    TGraphErrors SigmaStat(4, mass, sigma, mass_eL, sigma_e);
    SigmaStat.SetNameTitle("sigmaStat", "sigma");
    //    TGraphErrors MeanCBStat(4, mass, mean_cb, mass_eL, mean_cb_e);
    //    MeanCBStat.SetNameTitle("mean_cbStat", "mean_cb");
    TGraphErrors SigmaCBStat(4, mass, sigma_cb, mass_eL, sigma_cb_e);
    SigmaCBStat.SetNameTitle("sigma_cbStat", "sigma_cb");
    TGraphErrors WidthStat(4, mass, width, mass_eL, width_e);
    WidthStat.SetNameTitle("widthStat", "width");
    TGraphErrors NStat(4, mass, n, mass_eL, n_e);
    NStat.SetNameTitle("nStat", "n");
    //    TGraphErrors AlphaStat(4, mass, alpha, mass_eL, alpha_e);
    //    AlphaStat.SetNameTitle("alphaStat", "alpha");
    TGraphErrors FracStat(4, mass, frac, mass_eL, frac_e);
    FracStat.SetNameTitle("fracStat", "frac");

    TFile fout("graphs.root", "recreate");
    Mean.Write();
    Sigma.Write();
    //    MeanCB.Write();
    SigmaCB.Write();
    Width.Write();
    N.Write();
    //    Alpha.Write();
    Frac.Write();
    MeanStat.Write();
    SigmaStat.Write();
    //    MeanCBStat.Write();
    SigmaCBStat.Write();
    WidthStat.Write();
    NStat.Write();
    //    AlphaStat.Write();
    FracStat.Write();
    fout.Close();
    return 0;
}

