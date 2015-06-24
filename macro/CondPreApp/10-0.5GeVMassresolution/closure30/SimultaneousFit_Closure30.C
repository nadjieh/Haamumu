

/*
 * File:   SimultaneousFit.C
 * Author: nadjieh
 *
 * Created on May 20, 2015, 2:47 PM
 */

/*
 * *OPTIONS*
 * scratch: all peremters are free and mean is not shifting.
 * meanshift: only mean is shifting but the rest are free.
 * sgimaline: mean is shifting, sigma is linear
 * sigmaCBline: as sigmaline + linear sigma_cb
 * a1b1: as sigmaCBline with sigma's modeled w/o intercept
 */

/* m1a1b1
 * 2  alpha        1.08603e+00   7.93007e-02   
 * 4  frac         6.04536e-01   4.05085e-02   
 * 6  n            3.15299e+00   2.65356e-01   
 * 7  width        4.10999e-02   9.51977e-03   
 */
//#define INTERMEDIATE
const double ALPHA = 1.09;
const double ALPHAERROR = 0.0777;
const double FRAC = 0.601;
const double FRACERROR = 0.0396;
const double WIDTH = 0.066;
const double WIDTHERROR = 0.00955;
const double N = 3.12;
const double NERROR = 0.2595;

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "RooHist.h"
#include <ios>
#include <fstream>
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "TH2.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooDataHist.h"
#include "RooAbsReal.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooSimultaneous.h"
#include "RooFitResult.h"
#include "RooPolyVar.h"
#include "RooCategory.h"
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"
#include "TString.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TColorWheel.h"
#include "TColorGradient.h"
#include "RooVoigtian.h"
#include "RooCBShape.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooRandom.h"
#include <algorithm>
#include <map>

using namespace std;
using namespace RooFit;

typedef std::pair<double, std::vector<int> > PerMassParameRange;

class RangesPerSyst {
public:

    RangesPerSyst(TString name, std::vector<PerMassParameRange> input) : Name(name) {
        for (unsigned int i = 0; i < input.size(); i++) {
            info.push_back(input[i]);
        }
        paramIndex["alpha"] = 0;
        paramIndex["frac"] = 1;
        paramIndex["width"] = 2;
        paramIndex["n"] = 3;
    }

    RangesPerSyst() {
        paramIndex["alpha"] = 0;
        paramIndex["frac"] = 1;
        paramIndex["width"] = 2;
        paramIndex["n"] = 3;
    }

    ~RangesPerSyst() {
    }

    int GetMassIndex(double mass) {
        int ret = -1;
        for (unsigned int i = 0; i < info.size(); i++) {
            if (info[i].first == mass) {
                ret = i;
                break;
            }
        }
        return ret;
    }

    PerMassParameRange GetPerMassRaramRange(double mass) {
        int massIndex = this->GetMassIndex(mass);
        if (massIndex == -1) {
            cout << "ERROR: BAD MASS VALUE FOR RANGE" << endl;
            std::vector<int> c;
            c.clear();
            return make_pair(mass, c);
        }
        return info[massIndex];
    }

    int GetParamSystRange(double mass, int iPar) {
        int massIndex = this->GetMassIndex(mass);
        if (massIndex == -1)
            return 10;
        return info[massIndex].second[iPar];
    }

    int GetParamSystRange(double mass, TString iParChr) {
        int iPar = paramIndex[iParChr];
        return this->GetParamSystRange(mass, iPar);
    }

    void SetParamSystRange(double mass, int iPar, int range) {
        int massIndex = this->GetMassIndex(mass);
        if (massIndex == -1) {
            cout << "ERROR: BAD MASS VALUE FOR RANGE, SET TO 10" << endl;
            info[massIndex].second[iPar] = 10;
            return;
        }
        //        cout << "Index: " << iPar << ", range: " << range << endl;
        info[massIndex].second[iPar] = range;
    }

    void SetParamSystRange(double mass, TString iParChr, int range) {
        int iPar = paramIndex[iParChr];
        this->SetParamSystRange(mass, iPar, range);
    }

    TString GetSystName() {
        return Name;
    }
private:
    TString Name;
    std::vector<PerMassParameRange> info;
    std::map<TString, int> paramIndex;
};

typedef std::map< TString, RangesPerSyst> SystRanges;

std::pair<double, double> GraphRangeSetter(TGraphErrors * g) {
    int n = g->GetN();
    //    cout << "NNNNNNNNNNNNNNNNNNNNNNNN: " << n << endl;
    std::vector<double> valsup;
    std::vector<double> valsdown;
    double x, y, e;
    for (int i = 0; i < n; i++) {
        g->GetPoint(i, x, y);
        e = g->GetErrorY(i);
        valsup.push_back(y + e);
        valsdown.push_back(y - e);
    }
    sort(valsup.begin(), valsup.end());
    sort(valsdown.begin(), valsdown.end());
    return make_pair((1 - (valsdown[0]*0.2 / fabs(valsdown[0]))) * valsdown[0],
            (1 + (valsup[valsup.size() - 1]*0.2 / fabs(valsup[valsup.size() - 1]))) * valsup[valsup.size() - 1]);
}

TGraph * GoodRangeGraph(TGraphErrors * g) {
    std::pair<double, double> points = GraphRangeSetter(g);
    double x[3] = {40, 50, 60};
    double y[3] = {points.first, points.first, points.second};
    TGraph * good = new TGraph(3, x, y);
    good->SetLineColor(kWhite);
    good->SetMarkerColor(kWhite);
    good->SetNameTitle(g->GetName(), g->GetTitle());
    return good;
}

TGraph * GoodRangeGraph(TGraphErrors * g, TGraphErrors * g2) {
    std::pair<double, double> points = GraphRangeSetter(g);
    std::pair<double, double> points2 = GraphRangeSetter(g2);
    if (points.first < points2.first)
        points2.first = points.first;
    if (points.second < points2.second)
        points2.second = points.second;
    double x[3] = {40, 50, 60};
    double y[3] = {points2.first, points2.first, points2.second};
    TGraph * good = new TGraph(3, x, y);
    good->SetLineColor(kWhite);
    good->SetMarkerColor(kWhite);
    good->SetNameTitle(g2->GetName(), g2->GetTitle());
    cout << good << endl;
    return good;
}

void PrintFr(RooFitResult * fr, TString common = "", TString option = "") {
    std::vector<TString> syst;
    //    syst.push_back("_M30");
    syst.push_back("_M40");
    syst.push_back("_M50");
    syst.push_back("_M60");

    cout << "============= " << common << "\t" << common.Contains("alpha") << common.Contains("width") << common.Contains("frac") << common.Contains("n") << endl;
    std::vector<TString> Vars;
    if (!common.Contains("alpha"))
        Vars.push_back("alpha");
    if (!common.Contains("frac"))
        Vars.push_back("frac");
    if (!common.Contains("width"))
        Vars.push_back("width");
    if (!common.Contains("n"))
        Vars.push_back("n");
    if (option == "scratch" || option == "meanshift") {
        Vars.push_back("sigma");
    }
    if (option == "scratch" || option == "meanshift" || option == "sigmaline") {
        Vars.push_back("sigma_cb");
    }
    if (option == "scratch") {
        Vars.push_back("mean");
    }

    std::vector<TString> All;

    for (unsigned int i = 0; i < syst.size(); i++) {
        for (unsigned int j = 0; j < Vars.size(); j++) {
            All.push_back(Vars[j] + syst[i]);
            cout << All[All.size() - 1] << endl;
        }
    }
    if (option == "sigmaCBline") {
        All.push_back("a0");
        All.push_back("a1");
        All.push_back("b0");
        All.push_back("b1");
        //        All.push_back("m0");
        All.push_back("m1");
    }
    if (option == "sigmaline") {
        All.push_back("a0");
        All.push_back("a1");
    }

    if (option == "m1a1b1") {
        All.push_back("a1");
        All.push_back("b1");
        All.push_back("m1");
    }

    if (common.Contains("width") && !common.Contains("widthFixed"))
        All.push_back("width");
    if (common.Contains("alpha") && !common.Contains("alphaFixed"))
        All.push_back("alpha");
    if (common.Contains("frac") && !common.Contains("fracFixed"))
        All.push_back("frac");
    if (common.Contains("n") && !common.Contains("nFixed"))
        All.push_back("n");

    cout << "All size: " << All.size() << endl;
    int n = 0;

    TH2D * h = new TH2D("correlations", "correlations", All.size(), 0., (double) (All.size()),
            All.size(), 0., (double) (All.size()));
    TH2D * h2 = new TH2D("abscorrelations", "abscorrelations", All.size(), 0., (double) (All.size()),
            All.size(), 0., (double) (All.size()));


    for (unsigned int i = 0; i < All.size(); i++) {
        h->GetXaxis()->SetBinLabel(i + 1, All[i]);
        h->GetYaxis()->SetBinLabel(i + 1, All[i]);
        h2->GetXaxis()->SetBinLabel(i + 1, All[i]);
        h2->GetYaxis()->SetBinLabel(i + 1, All[i]);
        cout << "Bin " << i + 1 << "- " << All[i] << endl;
    }


    for (unsigned int i = 0; i < All.size(); i++) {
        //        h->SetBinContent(i + 1, i + 1, fr->correlation(All[i], All[i]));
        //        h2->SetBinContent(i + 1, i + 1, fr->correlation(All[i], All[i]));

        for (unsigned int j = 0; j < All.size(); j++) {
            n++;
            cout << i + 1 << "- " << j + 1 << ": " << h->GetXaxis()->GetBinLabel(j + 1) << "\tvs\t" << h->GetYaxis()->GetBinLabel(i + 1) << endl;
            h->SetBinContent(j + 1, i + 1, fr->correlation(h->GetXaxis()->GetBinLabel(j + 1), h->GetYaxis()->GetBinLabel(i + 1)));
            h2->SetBinContent(j + 1, i + 1, fabs(fr->correlation(h->GetXaxis()->GetBinLabel(j + 1), h->GetYaxis()->GetBinLabel(i + 1))));
        }
    }


    TFile * f = new TFile("correlations_" + option + ".root", "recreate");
    f->cd();
    h->Write();
    h2->Write();
    f->Close();

}

RooCBShape * CBMaker(double Mass, RooRealVar * mass, RooAbsReal * mean,
        SystRanges systband,
        RooAbsReal * sigma_cb = 0, RooRealVar * n = 0, RooRealVar * alpha = 0, RooRealVar * b0 = 0, RooRealVar * b1 = 0, TString sys = "",
        RooRealVar * MH = 0) {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    if (n == 0) {
        if (sys == "")
            n = new RooRealVar("n" + Name, "" + Name, 0, 10);
        else
            n = new RooRealVar("n" + Name, "" + Name, N,
                N - systband[sys].GetParamSystRange(Mass, 3) * NERROR,
                N + systband[sys].GetParamSystRange(Mass, 3) * NERROR);
    }
    if (alpha == 0) {
        if (sys == "")
            alpha = new RooRealVar("alpha" + Name, "" + Name, 0, 5);
        else
            alpha = new RooRealVar("alpha" + Name, "" + Name, ALPHA,
                ALPHA - systband[sys].GetParamSystRange(Mass, 0) * ALPHAERROR,
                ALPHA + systband[sys].GetParamSystRange(Mass, 0) * ALPHAERROR);
    }
    if (sigma_cb == 0) {
        if (b0 != 0 && b1 != 0) {
            if (MH == 0)
                sigma_cb = new RooPolyVar("sigma_cb" + Name, "sigma_cb" + Name, *mean, RooArgSet(*b0, *b1));
            else
                sigma_cb = new RooPolyVar("sigma_cb" + Name, "sigma_cb" + Name, *MH, RooArgSet(*b0, *b1));
        } else {
            sigma_cb = new RooRealVar("sigma_cb" + Name, "sigma_cb" + Name, 2.3, 0, 260.);
        }
    }
    RooCBShape * CB = new RooCBShape("cball" + Name, "crystal ball" + Name, *mass, *mean, *sigma_cb, *alpha, *n);

    return CB;
}

RooVoigtian * VoigMaker(double Mass, RooRealVar * mass, RooAbsReal * mean,
        SystRanges systband,
        RooAbsReal * sigma = 0, RooRealVar * width = 0, RooRealVar * a0 = 0, RooRealVar * a1 = 0, TString sys = "",
        RooRealVar * MH = 0) {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    if (sigma == 0) {
        if (a1 != 0 && a0 != 0) {
            if (MH == 0)
                sigma = new RooPolyVar("sigma" + Name, "mean" + Name, *mean, RooArgSet(*a0, *a1));
            else
                sigma = new RooPolyVar("sigma" + Name, "mean" + Name, *MH, RooArgSet(*a0, *a1));
        } else {
            sigma = new RooRealVar("sigma" + Name, "sigma" + Name, 0, 2.5);
        }
    }
    if (width == 0) {
        cout << "WIDTH: " << sys << endl;
        if (sys == "")
            width = new RooRealVar("width" + Name, "width" + Name, 1, 0., 5);
        else
            width = new RooRealVar("width" + Name, "width" + Name, WIDTH,
                WIDTH - systband[sys].GetParamSystRange(Mass, 2) * WIDTHERROR,
                WIDTH + systband[sys].GetParamSystRange(Mass, 2) * WIDTHERROR);
    }
    RooVoigtian * Voig = new RooVoigtian("tmp" + Name, "" + Name, *mass, *mean, *width, *sigma);

    return Voig;
}

RooAddPdf * VoigCBMaker(double Mass, RooRealVar * mass, std::map< TString, RooRealVar*> inputs,
        SystRanges systband,
        RooRealVar * frac = 0, TString option = "", TString sys = "") {
    stringstream s;
    s << "_M" << Mass;
    TString Name = s.str().c_str();
    RooAbsReal * mean = 0;
    RooRealVar * MH = new RooRealVar("MH" + Name, "MH" + Name, Mass);
    if (inputs["m0"] == 0 && inputs["m1"] == 0) {
        mean = new RooRealVar("mean" + Name, "mean" + Name, 0.8 * Mass, 1.2 * Mass);
    } else {
        mean = new RooPolyVar("mean" + Name, "mean" + Name, *MH, RooArgSet(*inputs["m0"], *inputs["m1"]));
    }
    RooVoigtian * Voig = VoigMaker(Mass, mass, mean, systband, inputs["sigma"], inputs["width"], inputs["a0"], inputs["a1"], sys, MH);
    RooCBShape * CB = CBMaker(Mass, mass, mean, systband, inputs["sigma_cb"], inputs["n"],
            inputs["alpha"], inputs["b0"], inputs["b1"], sys, MH);
    if (frac == 0) {
        if (sys == "")
            frac = new RooRealVar("frac" + Name, "frac" + Name, 0.5, 0, 1);
        else {
            frac = new RooRealVar("frac" + Name, "frac" + Name, FRAC,
                    FRAC - systband[sys].GetParamSystRange(Mass, 1) * FRACERROR,
                    FRAC + systband[sys].GetParamSystRange(Mass, 1) * FRACERROR);
        }
    }
    RooAddPdf * Voig2 = new RooAddPdf("sum" + Name, "Gaussian crystal ball and Voig PDF" + Name, RooArgList(*Voig, *CB), RooArgList(*frac));

    return Voig2;
}

/*
 * 
 *//*SimultaneousFit*/

int main(int argc, char** argv) {
    TFile * f30 = 0;
    TFile * f40 = 0;
    TFile * f50 = 0;
    TFile * f60 = 0;

    RooDataSet * d30;
    RooDataSet * d40;
    RooDataSet * d50;
    RooDataSet * d60;
    RooDataSet * wd30;
    RooDataSet * wd40;
    RooDataSet * wd50;
    RooDataSet * wd60;

    RooRealVar* w30 = 0;
    RooRealVar* w40 = 0;
    RooRealVar* w50 = 0;
    RooRealVar* w60 = 0;
    TString sys = "";
    TString pref1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-";
    TString pref2 = "_LowJetPt10_Summer12_final_4_4.root";
    TString prefsys1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_";
    TString prefsys2 = "_Summer12_final_4_4.root";

    std::vector<int> forSyst(4);
    forSyst[0] = 10;
    forSyst[1] = 10;
    forSyst[2] = 10;
    forSyst[3] = 10;
    std::vector<PerMassParameRange> AllMassSystRanges;
    AllMassSystRanges.push_back(make_pair(30, forSyst));
    AllMassSystRanges.push_back(make_pair(40, forSyst));
    AllMassSystRanges.push_back(make_pair(50, forSyst));
    AllMassSystRanges.push_back(make_pair(60, forSyst));
    RangesPerSyst puu("puu", AllMassSystRanges);
    RangesPerSyst pud("pud", AllMassSystRanges);
    RangesPerSyst muu("muu", AllMassSystRanges);
    muu.SetParamSystRange(50, "width", 1);
    muu.SetParamSystRange(50, "alpha", 1);
    RangesPerSyst mud("mud", AllMassSystRanges);
    RangesPerSyst bDown("bDown", AllMassSystRanges);
    RangesPerSyst bUp("bUp", AllMassSystRanges);
    RangesPerSyst JERD("JERD", AllMassSystRanges);
    RangesPerSyst JERU("JERU", AllMassSystRanges);
    JERU.SetParamSystRange(40, "alpha", 5);
    JERU.SetParamSystRange(40, "frac", 1);
    JERU.SetParamSystRange(40, "width", 1);
    JERU.SetParamSystRange(40, "n", 5);
    RangesPerSyst JESU("JESU", AllMassSystRanges);
    JESU.SetParamSystRange(40, "frac", 1);
    RangesPerSyst JESD("JESD", AllMassSystRanges);
    SystRanges SystBand;
    SystBand[muu.GetSystName()] = muu;
    SystBand[mud.GetSystName()] = mud;
    SystBand[puu.GetSystName()] = puu;
    SystBand[pud.GetSystName()] = pud;
    SystBand[bDown.GetSystName()] = bDown;
    SystBand[bUp.GetSystName()] = bUp;
    SystBand[JERD.GetSystName()] = JERD;
    SystBand[JERU.GetSystName()] = JERU;
    SystBand[JESD.GetSystName()] = JESD;
    SystBand[JESU.GetSystName()] = JESU;


    TString option = ""; //scratch

    double fracMean = -1000.;
    double alphaMean = -1000.;
    double widthMean = -1000.;
    double nMean = -1000.;
    std::map< TString, RooRealVar *> inputVars;
    inputVars["alpha"] = 0;
    inputVars["sigma"] = 0;
    inputVars["sigma_cb"] = 0;
    inputVars["width"] = 0;
    inputVars["n"] = 0;
    inputVars["a0"] = 0;
    inputVars["b0"] = 0;
    inputVars["m0"] = 0;
    inputVars["a1"] = 0;
    inputVars["b1"] = 0;
    inputVars["m1"] = 0;
    bool repeat = false;
    RooRealVar* frac = 0; //new RooRealVar("frac", "frac", 0.5, 0, 1);
    bool binned = false;
    bool weighted = false;
    bool fracFixed = false;
    bool alphaFixed = false;
    bool nFixed = false;
    bool widthFixed = false;
    bool compare = false;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "syst") {
            f++;
            std::string out(*(argv + f));
            sys = out;
            cout << "begin!" << endl;
        } else if (arg_fth == "option") {
            f++;
            std::string out(*(argv + f));
            option = out.c_str();
        } else if (arg_fth == "correlation") {
            frac = new RooRealVar("frac", "frac", 0.609842, 0, 1);
            inputVars["alpha"] = new RooRealVar("alpha", "", 1.00325, 0, 2);
            inputVars["width"] = new RooRealVar("width", "", 0.0641421, 0, 1);
            inputVars["n"] = new RooRealVar("n", "", 3.49775, 0, 7);
        } else if (arg_fth == "frac") {
            f++;
            std::string out(*(argv + f));
            fracMean = std::atof(out.c_str());
            f++;
            std::string out2(*(argv + f));
            fracFixed = (out2 == "fixed");
            if (!fracFixed)
                frac = new RooRealVar("frac", "frac", fracMean, fracMean - 0.1, fracMean + 0.1);
            else
                frac = new RooRealVar("frac", "frac", fracMean);
        } else if (arg_fth == "alpha") {
            f++;
            std::string out(*(argv + f));
            alphaMean = std::atof(out.c_str());
            f++;
            std::string out2(*(argv + f));
            alphaFixed = (out2 == "fixed");
            if (!alphaFixed)
                inputVars["alpha"] = new RooRealVar("alpha", "", alphaMean, 0.5 * alphaMean, 1.5 * alphaMean);
            else
                inputVars["alpha"] = new RooRealVar("alpha", "", alphaMean);
        } else if (arg_fth == "width") {
            f++;
            std::string out(*(argv + f));
            widthMean = std::atof(out.c_str());
            f++;
            std::string out2(*(argv + f));
            widthFixed = (out2 == "fixed");
            if (!widthFixed)
                inputVars["width"] = new RooRealVar("width", "", widthMean, 0, 3 * widthMean);
            else
                inputVars["width"] = new RooRealVar("width", "", widthMean);
        } else if (arg_fth == "n") {
            f++;
            std::string out(*(argv + f));
            nMean = std::atof(out.c_str());
            f++;
            std::string out2(*(argv + f));
            nFixed = (out2 == "fixed");
            if (!nFixed)
                inputVars["n"] = new RooRealVar("n", "", nMean, nMean - 1.5, nMean + 1.5);
            else
                inputVars["n"] = new RooRealVar("n", "", nMean);
            repeat = false;
        } else if (arg_fth == "binned") {
            std::string out(*(argv + f));
            binned = true;
        } else if (arg_fth == "weighted") {
            std::string out(*(argv + f));
            weighted = true;
        } else if (arg_fth == "compare") {
            compare = true;
        }
    }
    if (option != "scratch") {
        inputVars["m0"] = new RooRealVar("m0", "m0", 0, -0.5, 0.5);
        inputVars["m1"] = new RooRealVar("m1", "m1", 1, 0.8, 1.2);
    }
    if (option.Contains("sigma")) {
        inputVars["a0"] = new RooRealVar("a0", "a0", -0.038, -1, 0.1);
        inputVars["a1"] = new RooRealVar("a1", "a1", 0.01, 0, 0.5);
    }
    if (option == "sigmaCBline") {
        inputVars["b0"] = new RooRealVar("b0", "b0", -0.0618, -1, 0.1);
        inputVars["b1"] = new RooRealVar("b1", "b1", 0.01729, 0, 0.1);
    }
    if (option == "m1a1b1") {
        inputVars["a0"] = new RooRealVar("a0", "a0", -2.54762e-02);
        inputVars["a1"] = new RooRealVar("a1", "a1", 1.01730e-02, 0, 0.5);
        inputVars["b0"] = new RooRealVar("b0", "b0", -5.29410e-02);
        inputVars["b1"] = new RooRealVar("b1", "b1", 1.82017e-02, 0, 0.1);
    }

    RooRealVar * mass = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
    RooRealVar * leptonWeight = new RooRealVar("LeptonsReweightingweight", "LeptonsReweightingweight", 0, 2.);
    RooRealVar * btagWeightT = new RooRealVar("BtaggingReweightingT", "BtaggingReweightingT", -2., 2.);
    RooRealVar * btagWeightL = new RooRealVar("BtaggingReweightingL", "BtaggingReweightingL", -2., 2.);
    RooRealVar * puWeight = new RooRealVar("lumiReweightingLumiWeight", "lumiReweightingLumiWeight", 0, 2.);
    RooFormulaVar * Weight30 = new RooFormulaVar("Weight30", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight40 = new RooFormulaVar("Weight40", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight50 = new RooFormulaVar("Weight50", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * Weight60 = new RooFormulaVar("Weight60", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    RooFormulaVar * WeightGlobal = new RooFormulaVar("WeightGlobal", "@0*@1*@2*@3", RooArgSet(*leptonWeight, *btagWeightL, *btagWeightT, *puWeight));
    if (sys == "") {
        f30 = TFile::Open(pref1 + "30" + pref2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        d30->Print();
        w30 = (RooRealVar*) d30->addColumn(*Weight30);
        wd30 = new RooDataSet(d30->GetName(), d30->GetTitle(), d30, *d30->get(), 0, w30->GetName());
        wd30->Print();

        f40 = TFile::Open(pref1 + "40" + pref2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w40 = (RooRealVar*) d40->addColumn(*Weight40);
        wd40 = new RooDataSet(d40->GetName(), d40->GetTitle(), d40, *d40->get(), 0, w40->GetName());

        f50 = TFile::Open(pref1 + "50" + pref2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w50 = (RooRealVar*) d50->addColumn(*Weight50);
        wd50 = new RooDataSet(d50->GetName(), d50->GetTitle(), d50, *d50->get(), 0, w50->GetName());

        f60 = TFile::Open(pref1 + "60" + pref2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w60 = (RooRealVar*) d60->addColumn(*Weight60);
        wd60 = new RooDataSet(d60->GetName(), d60->GetTitle(), d60, *d60->get(), 0, w60->GetName());

    } else {
        f30 = TFile::Open(sys + TString("_") + prefsys1 + "30" + prefsys2);
        TTree * t30 = (TTree*) f30->Get("rds_zbb");
        d30 = new RooDataSet("d30", "d30", t30, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w30 = (RooRealVar*) d30->addColumn(*Weight30);
        wd30 = new RooDataSet(d30->GetName(), d30->GetTitle(), d30, *d30->get(), 0, w30->GetName());

        f40 = TFile::Open(sys + TString("_") + prefsys1 + "40" + prefsys2);
        TTree * t40 = (TTree*) f40->Get("rds_zbb");
        d40 = new RooDataSet("d40", "d40", t40, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w40 = (RooRealVar*) d40->addColumn(*Weight40);
        wd40 = new RooDataSet(d40->GetName(), d40->GetTitle(), d40, *d40->get(), 0, w40->GetName());

        f50 = TFile::Open(sys + TString("_") + prefsys1 + "50" + prefsys2);
        TTree * t50 = (TTree*) f50->Get("rds_zbb");
        d50 = new RooDataSet("d50", "d50", t50, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w50 = (RooRealVar*) d50->addColumn(*Weight50);
        wd50 = new RooDataSet(d50->GetName(), d50->GetTitle(), d50, *d50->get(), 0, w50->GetName());

        f60 = TFile::Open(sys + TString("_") + prefsys1 + "60" + prefsys2);
        TTree * t60 = (TTree*) f60->Get("rds_zbb");
        d60 = new RooDataSet("d60", "d60", t60, RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), "");
        w60 = (RooRealVar*) d60->addColumn(*Weight60);
        wd60 = new RooDataSet(d60->GetName(), d60->GetTitle(), d60, *d60->get(), 0, w60->GetName());

    }
    cout << "begin ..." << endl;
    RooCategory sampleWeighted("sampleWeighted", "sampleWeighted");
    //    sampleWeighted.defineType("p30");
    sampleWeighted.defineType("p40");
    sampleWeighted.defineType("p50");
    sampleWeighted.defineType("p60");

    RooDataSet combData("combDataWeighted", "combined data", RooArgSet(*mass, *leptonWeight, *btagWeightL, *btagWeightT, *puWeight), Index(sampleWeighted),
            //            Import("p30", *wd30),
            Import("p40", *wd40),
            Import("p50", *wd50),
            Import("p60", *wd60)
            );
    RooRealVar * weightGlobal = (RooRealVar*) combData.addColumn(*WeightGlobal);
    RooDataSet combDataWeighted(combData.GetName(), combData.GetTitle(), &combData, *combData.get(), 0, weightGlobal->GetName());

    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    combDataWeighted.Print();
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    //    RooAddPdf * m30 = VoigCBMaker(30, mass, inputVars, SystBand, frac, option, sys);
    RooAddPdf * m40 = VoigCBMaker(40, mass, inputVars, SystBand, frac, option, sys);
    RooAddPdf * m50 = VoigCBMaker(50, mass, inputVars, SystBand, frac, option, sys);
    RooAddPdf * m60 = VoigCBMaker(60, mass, inputVars, SystBand, frac, option, sys);


    RooPlot * M = mass->frame();
    //    m30->plotOn(M);
    m40->plotOn(M);
    m50->plotOn(M);
    m60->plotOn(M);
    //    m30->plotOn(M, Components("tmp_M30"), LineColor(kRed));
    m40->plotOn(M, Components("tmp_M40"), LineColor(kRed));
    m50->plotOn(M, Components("tmp_M50"), LineColor(kRed));
    m60->plotOn(M, Components("tmp_M60"), LineColor(kRed));
    //    m30->plotOn(M, Components("cball_M30"), LineColor(kGreen + 2));
    m40->plotOn(M, Components("cball_M40"), LineColor(kGreen + 2));
    m50->plotOn(M, Components("cball_M50"), LineColor(kGreen + 2));
    m60->plotOn(M, Components("cball_M60"), LineColor(kGreen + 2));

    TCanvas Can;
    Can.cd();
    M->Draw();
    Can.SaveAs("Can_" + option + ".C");
    //    return 2;
    RooSimultaneous simPdfWeighted("simPdfWeighted", "simultaneous pdf", sampleWeighted);
    //    simPdfWeighted.addPdf(*m30, "p30");
    simPdfWeighted.addPdf(*m40, "p40");
    simPdfWeighted.addPdf(*m50, "p50");
    simPdfWeighted.addPdf(*m60, "p60");


    RooFitResult * fr = 0;

    fr = simPdfWeighted.fitTo(combDataWeighted, RooFit::Save(), RooFit::SumW2Error(kTRUE));
    {
        RooAddPdf * m30 = VoigCBMaker(30, mass, inputVars, SystBand, frac, option, sys);

        RooPlot* frame2 = mass->frame(Title("30 GeV sample"));
        wd30->plotOn(frame2, RooFit::Binning(200));
        m30->plotOn(frame2, RooFit::Binning(200));
        //        m30->plotOn(frame2, Components("tmp_M30"), LineStyle(kDashed));
        //        m30->plotOn(frame2, Components("cball_M30"), LineColor(kRed), LineStyle(kDashed));
        RooHist* hresid30 = frame2->pullHist();
        RooPlot* frame2res = mass->frame(Title("Residual m_{a} = 30 GeV"));
        frame2res->addPlotable(hresid30, "P");
        TCanvas closure;
        closure.Divide(2, 2);
        closure.cd(1);
        gPad->SetLeftMargin(0.05);
        frame2->GetYaxis()->SetTitleOffset(0.9);
        frame2->Draw();
        closure.cd(2);
        gPad->SetLeftMargin(0.05);
        frame2res->GetYaxis()->SetTitleOffset(0.9);
        frame2res->Draw();


        m30->fitTo(*wd30, RooFit::SumW2Error(kTRUE));
        RooPlot* frame22 = mass->frame(Title("30 GeV sample, individual fit"));
        wd30->plotOn(frame22, RooFit::Binning(200));
        m30->plotOn(frame22, RooFit::Binning(200));
        RooHist* hresid302 = frame22->pullHist();
        RooPlot* frame22res = mass->frame(Title("Residual m_{a} = 30 GeV, individual fit"));
        frame22res->addPlotable(hresid302, "P");
        closure.cd(3);
        gPad->SetLeftMargin(0.05);
        frame22->GetYaxis()->SetTitleOffset(0.9);
        frame22->Draw();
        closure.cd(4);
        gPad->SetLeftMargin(0.05);
        frame22res->GetYaxis()->SetTitleOffset(0.9);
        frame22res->Draw();
        closure.SaveAs("closure30_residulaFit.C");
    }
    cout << "width: " << inputVars["width"] << "\t" << frac << endl;
    TString prinput = "";
    if (inputVars["alpha"] != 0) {
        prinput += "alpha";
        if (alphaFixed)
            prinput += "Fixed";
    }
    if (inputVars["width"] != 0) {
        prinput += "width";
        if (widthFixed)
            prinput += "Fixed";
    }
    if (inputVars["n"] != 0) {
        prinput += TString("n");
        if (nFixed)
            prinput += "Fixed";
    }
    if (frac != 0) {
        prinput += "frac";
        if (fracFixed)
            prinput += "Fixed";
    }

    PrintFr(fr, prinput, option);

    stringstream myVal;
    if (repeat) {
        if (sys != "")
            myVal << "./SimFit syst " << sys;
        else
            myVal << "./SimFit ";
        if (((RooRealVar*) fr->floatParsFinal().find("frac")) != 0) {
            cout << "HERE frac >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << ((RooRealVar*) fr->floatParsFinal().find("frac"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("alpha")) != 0) {
            cout << "HERE alpha >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << ((RooRealVar*) fr->floatParsFinal().find("alpha"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("width")) != 0) {
            cout << "HERE width >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << ((RooRealVar*) fr->floatParsFinal().find("width"))->getVal();
        } else if (((RooRealVar*) fr->floatParsFinal().find("n")) != 0) {
            cout << "HERE n >>>>>>>>>>>>>>>>>>>>>>" << endl;
            myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << widthMean << " n " << ((RooRealVar*) fr->floatParsFinal().find("n"))->getVal();
        }
        //            if (weighted)
        myVal << " weighted";
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << myVal.str() << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

        system(myVal.str().c_str());
    } else {
        myVal.str("");
        if (sys != "")
            myVal << "./SimFit syst " << sys;
        else
            myVal << "./SimFit ";
        myVal << " frac " << fracMean << " alpha " << alphaMean << " width " << widthMean << " n " << nMean;
        //            if (weighted)
        myVal << " weighted\n";

        std::ofstream log("fullSyst.sh", std::ios_base::app | std::ios_base::out);
        log << myVal.str();

    }




    //    RooPlot* frame1 = mass->frame(Title("30 GeV sample"));
    RooPlot* frame2 = mass->frame(Title("40 GeV sample"));
    RooPlot* frame3 = mass->frame(Title("50 GeV sample"));
    RooPlot* frame4 = mass->frame(Title("60 GeV sample"));

    cout << "Weighted data" << endl;
    combDataWeighted.plotOn(frame2, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p40"), RooFit::Binning(200));
    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), ProjWData(sampleWeighted, combDataWeighted), RooFit::Binning(200));
    //    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), Components("tmp_M40"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed));
    //    simPdfWeighted.plotOn(frame2, Slice(sampleWeighted, "p40"), Components("cball_M40"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    combDataWeighted.plotOn(frame3, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p50"), RooFit::Binning(200));
    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), ProjWData(sampleWeighted, combDataWeighted), RooFit::Binning(200));
    //    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), Components("tmp_M50"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed));
    //    simPdfWeighted.plotOn(frame3, Slice(sampleWeighted, "p50"), Components("cball_M50"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    combDataWeighted.plotOn(frame4, DataError(RooAbsData::SumW2), Cut("sampleWeighted==sampleWeighted::p60"), RooFit::Binning(200));
    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), ProjWData(sampleWeighted, combDataWeighted), RooFit::Binning(200));
    //    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), Components("tmp_M60"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed));
    //    simPdfWeighted.plotOn(frame4, Slice(sampleWeighted, "p60"), Components("cball_M60"), ProjWData(sampleWeighted, combDataWeighted), LineStyle(kDashed), LineColor(kRed));

    /*
     * ==============
     * Residuals
     * ==============
     */
    RooHist* hresid40 = frame2->pullHist();
    RooPlot* frame1res = mass->frame(Title("Residual m_{a} = 40 GeV"));
    frame1res->addPlotable(hresid40, "P");
    RooHist* hresid50 = frame3->pullHist();
    RooPlot* frame3res = mass->frame(Title("Residual m_{a} = 50 GeV"));
    frame3res->addPlotable(hresid50, "P");
    RooHist* hresid60 = frame4->pullHist();
    RooPlot* frame4res = mass->frame(Title("Residual m_{a} = 60 GeV"));
    frame4res->addPlotable(hresid60, "P");

    TCanvas* c = new TCanvas("SimultaneousFit", "SimultaneousFit", 1600, 800);
    c->Divide(2, 3);
    c->cd(1);
    gPad->SetLeftMargin(0.05);
    frame2->GetYaxis()->SetTitleOffset(0.9);
    frame2->Draw();
    c->cd(2);
    gPad->SetLeftMargin(0.05);
    frame1res->GetYaxis()->SetTitleOffset(0.9);
    frame1res->Draw();

    c->cd(3);
    gPad->SetLeftMargin(0.05);
    frame3->GetYaxis()->SetTitleOffset(0.9);
    frame3->Draw();
    c->cd(4);
    gPad->SetLeftMargin(0.05);
    frame3res->GetYaxis()->SetTitleOffset(0.9);
    frame3res->Draw();

    c->cd(5);
    gPad->SetLeftMargin(0.05);
    frame4->GetYaxis()->SetTitleOffset(0.9);
    frame4->Draw();
    c->cd(6);
    gPad->SetLeftMargin(0.05);
    frame4res->GetYaxis()->SetTitleOffset(0.9);
    frame4res->Draw();
    c->SaveAs(sys + "weighted_graph_SimFit_" + option + ".C");

    /*
     * ==============
     * Comparison of residuals between the simultaneous and individual fit
     * ==============
     */


    c = new TCanvas("Residuals", "Residuals", 1600, 800);
    c->Divide(2, 3);
    c->cd(1);
    gPad->SetLeftMargin(0.05);
    frame1res->GetYaxis()->SetTitleOffset(0.9);
    frame1res->Draw();

    m40->fitTo(*wd40, RooFit::SumW2Error(kTRUE));
    RooPlot* frame12 = mass->frame(Title("40 GeV sample, individual fit"));
    wd40->plotOn(frame12, RooFit::Binning(200));
    m40->plotOn(frame12, RooFit::Binning(200));
    RooHist* hresid402 = frame12->pullHist();
    RooPlot* frame12res = mass->frame(Title("Residual m_{a} = 40 GeV, individual fit"));
    frame12res->addPlotable(hresid402, "P");
    c->cd(2);
    gPad->SetLeftMargin(0.05);
    frame12res->GetYaxis()->SetTitleOffset(0.9);
    frame12res->Draw();

    c->cd(3);
    gPad->SetLeftMargin(0.05);
    frame3res->GetYaxis()->SetTitleOffset(0.9);
    frame3res->Draw();

    m50->fitTo(*wd50, RooFit::SumW2Error(kTRUE));
    RooPlot* frame32 = mass->frame(Title("50 GeV sample, individual fit"));
    wd50->plotOn(frame32, RooFit::Binning(200));
    m50->plotOn(frame32, RooFit::Binning(200));
    RooHist* hresid502 = frame32->pullHist();
    RooPlot* frame32res = mass->frame(Title("Residual m_{a} = 50 GeV, individual fit"));
    frame32res->addPlotable(hresid502, "P");
    c->cd(4);
    gPad->SetLeftMargin(0.05);
    frame32res->GetYaxis()->SetTitleOffset(0.9);
    frame32res->Draw();

    c->cd(5);
    gPad->SetLeftMargin(0.05);
    frame4res->GetYaxis()->SetTitleOffset(0.9);
    frame4res->Draw();

    m60->fitTo(*wd60, RooFit::SumW2Error(kTRUE));
    RooPlot* frame42 = mass->frame(Title("60 GeV sample, individual fit"));
    wd60->plotOn(frame42, RooFit::Binning(200));
    m60->plotOn(frame42, RooFit::Binning(200));
    RooHist* hresid602 = frame42->pullHist();
    RooPlot* frame42res = mass->frame(Title("Residual m_{a} = 60 GeV, individual fit"));
    frame42res->addPlotable(hresid602, "P");
    c->cd(6);
    gPad->SetLeftMargin(0.05);
    frame42res->GetYaxis()->SetTitleOffset(0.9);
    frame42res->Draw();
    c->SaveAs("residulaFits.C");

    if (option == "sigmaCBline") {
        stringstream ab;
        ab << "\ta0[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("a0"))->getVal() << ";\n";
        ab << "\ta0er[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("a0"))->getError() << ";\n";
        ab << "\ta1[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("a1"))->getVal() << ";\n";
        ab << "\ta1er[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("a1"))->getError() << ";\n";
        ab << "\tb0[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("b0"))->getVal() << ";\n";
        ab << "\tb0er[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("b0"))->getError() << ";\n";
        ab << "\tb1[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("b1"))->getVal() << ";\n";
        ab << "\tb1er[\"" << sys << "\"] = " << ((RooRealVar*) fr->floatParsFinal().find("b1"))->getError() << ";\n";

        std::ofstream log("ab.C", std::ios_base::app | std::ios_base::out);
        log << ab.str();
        return 1;
    }


    /*
     * Plotting parameters
     */

    std::map<TString, int> myColors;
    myColors["bDown"] = 618;
    myColors["bUp"] = 616;
    myColors["JESD"] = 434;
    myColors["JESU"] = 432;
    myColors["JERD"] = 632;
    myColors["JERU"] = 623;
    myColors["mud"] = 801;
    myColors["muu"] = 796;
    myColors["pud"] = 602;
    myColors["puu"] = 596;
    myColors[""] = 1;


    double x[3] = {40, 50, 60};
    double x_e[3] = {0., 0., 0.};
    double Mean[3];
    double MeanE[3];
    double fixMass = 30;
    stringstream S;
    TGraphErrors * gMean = 0;
    if (option == "scratch") {
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "mean_M" << fixMass;
            cout << S.str().c_str() << endl;
            Mean[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            MeanE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
        gMean = new TGraphErrors(3, x, Mean, x_e, MeanE);
        gMean->SetNameTitle("Mean" + sys, "Mean" + sys);
    }

    TGraphErrors * gSigma = 0;
    if (option == "scratch" || option == "meanshift") {
        double Sigma[3];
        double SigmaE[3];
        fixMass = 30;
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "sigma_M" << fixMass;
            Sigma[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            SigmaE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
        gSigma = new TGraphErrors(3, x, Sigma, x_e, SigmaE);
        gSigma->SetNameTitle("Sigma" + sys, "Sigma" + sys);
    }

    double Alpha[3];
    double AlphaE[3];
    fixMass = 30;
    TGraphErrors * gAlpha = 0;
    if (alphaMean == -1000) {
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "alpha_M" << fixMass;
            Alpha[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            AlphaE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
    } else if (!alphaFixed) {
        for (int i = 0; i < 3; i++) {
            Alpha[i] = ((RooRealVar*) fr->floatParsFinal().find("alpha"))->getVal();
            AlphaE[i] = ((RooRealVar*) fr->floatParsFinal().find("alpha"))->getError();
        }
    }
    gAlpha = new TGraphErrors(3, x, Alpha, x_e, AlphaE);
    gAlpha->SetNameTitle("Alpha" + sys, "Alpha" + sys);

    double Frac[3];
    double FracE[3];
    fixMass = 30;
    TGraphErrors * gFrac = 0;
    if (fracMean == -1000) {
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "frac_M" << fixMass;
            Frac[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            FracE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
    } else if (!fracFixed) {
        for (int i = 0; i < 3; i++) {
            Frac[i] = ((RooRealVar*) fr->floatParsFinal().find("frac"))->getVal();
            FracE[i] = ((RooRealVar*) fr->floatParsFinal().find("frac"))->getError();
        }
    }
    gFrac = new TGraphErrors(3, x, Frac, x_e, FracE);
    gFrac->SetNameTitle("Frac" + sys, "Frac" + sys);

    TGraphErrors * gSigma_cb = 0;
    if (option == "scratch" || option == "meanshift" || option == "sigmaline") {
        cout << "option is " << option << endl;
        double Sigma_cb[3];
        double Sigma_cbE[3];
        fixMass = 30;
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "sigma_cb_M" << fixMass;
            Sigma_cb[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            Sigma_cbE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
        gSigma_cb = new TGraphErrors(3, x, Sigma_cb, x_e, Sigma_cbE);
        gSigma_cb->SetNameTitle("Sigma_cb" + sys, "Sigma_cb" + sys);
    }

    double Width[3];
    double WidthE[3];
    fixMass = 30;
    TGraphErrors * gWidth = 0;
    if (widthMean == -1000) {
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "width_M" << fixMass;
            Width[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            WidthE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
    } else if (!widthFixed) {
        for (int i = 0; i < 3; i++) {
            Width[i] = ((RooRealVar*) fr->floatParsFinal().find("width"))->getVal();
            WidthE[i] = ((RooRealVar*) fr->floatParsFinal().find("width"))->getError();
        }
    }
    gWidth = new TGraphErrors(3, x, Width, x_e, WidthE);
    gWidth->SetNameTitle("Width" + sys, "Width" + sys);

    double N[3];
    double NE[3];
    fixMass = 30;
    TGraphErrors * gN = 0;
    if (nMean == -1000) {
        for (int i = 0; i < 3; i++) {
            if (fixMass == 30)
                fixMass += 10;
            S.str("");
            S << "n_M" << fixMass;
            N[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getVal();
            NE[i] = ((RooRealVar*) fr->floatParsFinal().find(S.str().c_str()))->getError();
            fixMass += 10;
        }
    } else if (!nFixed) {
        for (int i = 0; i < 3; i++) {
            N[i] = ((RooRealVar*) fr->floatParsFinal().find("n"))->getVal();
            NE[i] = ((RooRealVar*) fr->floatParsFinal().find("n"))->getError();
        }
    }
    gN = new TGraphErrors(3, x, N, x_e, NE);
    gN->SetNameTitle("N", "N");
    TGraphErrors *gre = 0;
    TGraph *good = 0;
    TCanvas* c2 = new TCanvas("Graphs", "Graphs", 1600, 800);
    c2->Divide(4, 2);
    if (option == "scratch") {
        c2->cd(1);
        gPad->SetLeftMargin(0.05);
        gMean->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Mean");
            gre->SetTitle("Mean");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 29.95858);
            gre->SetPointError(0, 0, 0.006181047);
            gre->SetPoint(1, 40, 39.94656);
            gre->SetPointError(1, 0, 0.008243594);
            gre->SetPoint(2, 50, 49.90414);
            gre->SetPointError(2, 0, 0.009817385);
            gre->SetPoint(3, 60, 59.89826);
            gre->SetPointError(3, 0, 0.01098931);
            //            good = GoodRangeGraph(gMean, gre);
            //            good->Draw("alp");
            gre->Draw("alp");
            gMean->Draw("lp");
        } else {
            //            good = GoodRangeGraph(gMean);
            //            good->Draw("alp");
            gMean->Draw("alp");
        }
    }
    if (option == "scratch" || option == "meanshift") {
        c2->cd(2);
        gPad->SetLeftMargin(0.05);
        gSigma->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Sigma");
            gre->SetTitle("Sigma");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 0.290046);
            gre->SetPointError(0, 0, 0.01907824);
            gre->SetPoint(1, 40, 0.3750509);
            gre->SetPointError(1, 0, 0.02926995);
            gre->SetPoint(2, 50, 0.4744997);
            gre->SetPointError(2, 0, 0.04251392);
            gre->SetPoint(3, 60, 0.5847943);
            gre->SetPointError(3, 0, 0.03252513);
            //            good = GoodRangeGraph(gSigma, gre);
            //            good->Draw("alp");
            gre->Draw("alp");
            gSigma->Draw("lp");
        } else {
            //            good = GoodRangeGraph(gSigma);
            //            good->Draw("alp");
            gSigma->Draw("alp");
        }
    }
    if (option == "scratch" || option == "meanshift" || option == "sigmaline") {
        c2->cd(3);
        gPad->SetLeftMargin(0.05);
        gSigma_cb->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Sigma_cb");
            gre->SetTitle("Sigma_cb");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 0.5100873);
            gre->SetPointError(0, 0, 0.03934521);
            gre->SetPoint(1, 40, 0.6763777);
            gre->SetPointError(1, 0, 0.06013699);
            gre->SetPoint(2, 50, 0.8196444);
            gre->SetPointError(2, 0, 0.06586182);
            gre->SetPoint(3, 60, 1.05092);
            gre->SetPointError(3, 0, 0.0598879);
            //            good = GoodRangeGraph(gSigma_cb, gre);
            //            good->Draw("alp");
            gre->Draw("alp");
            gSigma_cb->Draw("lp");
        } else {
            //            good = GoodRangeGraph(gSigma_cb);
            //            good->Draw("alp");
            gSigma_cb->Draw("alp");
        }
    }
    if (!widthFixed) {
        c2->cd(4);
        gPad->SetLeftMargin(0.05);
        gWidth->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Width");
            gre->SetTitle("Width");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 0.04295271);
            gre->SetPointError(0, 0, 0.01434878);
            gre->SetPoint(1, 40, 0.02764905);
            gre->SetPointError(1, 0, 0.02182932);
            gre->SetPoint(2, 50, 0.05756835);
            gre->SetPointError(2, 0, 0.02777882);
            gre->SetPoint(3, 60, 0.02853778);
            gre->SetPointError(3, 0, 0.0187434);
            good = GoodRangeGraph(gWidth, gre);
            good->Draw("alp");
            gre->Draw("lp");
            gWidth->Draw("lp");
        } else {
            good = GoodRangeGraph(gWidth);
            good->Draw("alp");
            gWidth->Draw("lp");
        }
    }
    if (!nFixed) {
        c2->cd(5);
        gPad->SetLeftMargin(0.05);
        gN->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("N");
            gre->SetTitle("N");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 3.244394);
            gre->SetPointError(0, 0, 0.7997434);
            gre->SetPoint(1, 40, 3.262713);
            gre->SetPointError(1, 0, 0.6028268);
            gre->SetPoint(2, 50, 3.220279);
            gre->SetPointError(2, 0, 0.7100905);
            gre->SetPoint(3, 60, 2.975253);
            gre->SetPointError(3, 0, 0.4191292);
            good = GoodRangeGraph(gN, gre);
            good->Draw("alp");
            gre->Draw("lp");
            gN->Draw("lp");
        } else {
            good = GoodRangeGraph(gN);
            good->Draw("alp");
            gN->Draw("lp");
        }
    }
    if (!alphaFixed) {
        c2->cd(6);
        gPad->SetLeftMargin(0.05);
        gAlpha->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Alpha");
            gre->SetTitle("Alpha");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 1.019416);
            gre->SetPointError(0, 0, 0.2074091);
            gre->SetPoint(1, 40, 1.085271);
            gre->SetPointError(1, 0, 0.1661705);
            gre->SetPoint(2, 50, 1.08708);
            gre->SetPointError(2, 0, 0.2218907);
            gre->SetPoint(3, 60, 1.133119);
            gre->SetPointError(3, 0, 0.1411355);
            good = GoodRangeGraph(gAlpha, gre);
            good->Draw("alp");
            gre->Draw("lp");
            gAlpha->Draw("lp");
        } else {
            good = GoodRangeGraph(gAlpha);
            good->Draw("alp");
            gAlpha->Draw("lp");
        }
    }
    if (!fracFixed) {
        c2->cd(7);
        gPad->SetLeftMargin(0.05);
        gFrac->SetLineColor(myColors[sys]);
        if (compare) {
            gre = new TGraphErrors(4);
            gre->SetName("Frac");
            gre->SetTitle("Frac");
            gre->SetFillColor(1);
            gre->SetPoint(0, 30, 0.6523356);
            gre->SetPointError(0, 0, 0.09041394);
            gre->SetPoint(1, 40, 0.5863207);
            gre->SetPointError(1, 0, 0.09521651);
            gre->SetPoint(2, 50, 0.6076257);
            gre->SetPointError(2, 0, 0.1126714);
            gre->SetPoint(3, 60, 0.5767429);
            gre->SetPointError(3, 0, 0.07355287);
            good = GoodRangeGraph(gFrac, gre);
            good->Draw("alp");
            gre->Draw("lp");
            gFrac->Draw("lp");
        } else {
            good = GoodRangeGraph(gFrac);
            good->Draw("alp");
            gFrac->Draw("lp");
        }
    }

    c2->SaveAs(sys + "weighted_Graphs_SimFit_" + option + ".C");
    //    c2->SaveAs(sys + "weighted_Graphs_SimFit_" + option + ".png");


    return 0;
}

