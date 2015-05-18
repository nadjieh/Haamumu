/* 
 * File:   MassPoint.h
 * Author: nadjieh
 *
 * Created on May 5, 2015, 6:39 PM
 */

#ifndef MASSPOINT_H
#define	MASSPOINT_H
#include <vector>
#include <sstream>
#include <iostream>
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
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
const long SEED = 124578963;
//const int NSYST = 2;
//const TString systprefix[NSYST] = {"pud", "puu"};
const int NSYST = 10;
const TString systprefix[NSYST] = {"bDown", "bUp", "JESD", "JESU", "JERD", "JERU", "mud", "muu", "pud", "puu"};

enum Colors {
    bDownC = 618, bUpC = 616, JESDC = 434, JESUC = 432, JERDC = 632, JERUC = 623, mudC = 801, muuC = 796, pudC = 602, puuC = 596
};

struct ValueUncert {
    double value;
    double statUnc;
    double bDown;
    double bUp;
    double JESD;
    double JESU;
    double JERD;
    double JERU;
    double mud;
    double muu;
    double pud;
    double puu;
};

struct Initials {
    double low;
    double high;
    double mean;
};

class MassPoint {
public:

    MassPoint(double mass, TString pref1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-",
            TString pref2 = "_LowJetPt10_Summer12_final_4.root",
            TString prefsys1 = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1_",
            TString prefsys2 = "_Summer12_final_4.root") :
    mass_(mass) {
        stringstream Mass;
        Mass << mass;
        TString MassStr = Mass.str().c_str();
        var = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
        TFile * fnominal = TFile::Open(pref1 + MassStr + pref2);
        TTree * tnominal = (TTree*) fnominal->Get("rds_zbb");
        nominal = new RooDataSet("data_dimu" + MassStr, "data", tnominal, *var, "");
        TFile * f = 0;
        TTree * t = 0;
        for (int i = 0; i < NSYST; i++) {
            f = TFile::Open(systprefix[i] + TString("_") + prefsys1 + MassStr + prefsys2);
            t = (TTree*) f->Get("rds_zbb");
            if (i % 2 != 0) {
                systUp.push_back(new RooDataSet("data_dimu" + MassStr + systprefix[i], "data", t, *var, ""));
            } else {
                systDown.push_back(new RooDataSet("data_dimu" + MassStr + systprefix[i], "data", t, *var, ""));
            }
        }
        MeanInit.low = 0.85;
        MeanInit.mean = 1;
        MeanInit.high = 1.15;
        MeanCBInit.low = 0.8 * mass_;
        MeanCBInit.mean = mass_;
        MeanCBInit.high = 1.2 * mass_;
        WidthInit.low = 0.8;
        WidthInit.mean = 1;
        WidthInit.high = 1.2;
        SigmaInit.low = 0;
        SigmaInit.high = 10;
        SigmaInit.mean = 1;
        SigmaCBInit.low = 0;
        SigmaCBInit.high = 260.0;
        SigmaCBInit.mean = 2.3;
        NInit.low = 0;
        NInit.high = 10.;
        NInit.mean = 5;
        AlphaInit.low = 0;
        AlphaInit.high = 10.;
        AlphaInit.mean = 5;
    }

    ~MassPoint() {
    }

    void SetMeanCBInit(double mean, double low, double high) {
        MeanCBInit.mean = mean;
        MeanCBInit.low = low;
        MeanCBInit.high = high;
    }

    void SetSigmaInit(double mean, double low, double high) {
        SigmaInit.mean = mean;
        SigmaInit.low = low;
        SigmaInit.high = high;
    }

    void SetSigmaCBInit(double mean, double low, double high) {
        SigmaCBInit.mean = mean;
        SigmaCBInit.low = low;
        SigmaCBInit.high = high;
    }

    void SetAlphaInit(double mean, double low, double high) {
        AlphaInit.mean = mean;
        AlphaInit.low = low;
        AlphaInit.high = high;
    }

    void SetNInit(double mean, double low, double high) {
        NInit.mean = mean;
        NInit.low = low;
        NInit.high = high;
    }

    void SetWidthInit(double mean, double low, double high) {
        WidthInit.mean = mean;
        WidthInit.low = low;
        WidthInit.high = high;
    }

    void SetMeanInit(double mean, double low, double high) {
        MeanInit.mean = mean;
        MeanInit.low = low;
        MeanInit.high = high;
    }

    RooFitResult* fitToSignal(RooDataSet * data, TString syst = "", int nbin = 50) {
        RooRandom::randomGenerator()->SetSeed(SEED);
        if (syst == "") {
            TH1D * hist = (TH1D*) data->createHistogram("hist" + syst, *var, RooFit::Binning(nbin));
            RooRealVar mean("mean" + syst, "mean" + syst, hist->GetMean(), MeanInit.low * hist->GetMean(), MeanInit.high * hist->GetMean());
            RooRealVar sigma("sigma" + syst, "sigma" + syst, SigmaInit.mean, SigmaInit.low, SigmaInit.high);
            RooRealVar width("width" + syst, "width" + syst, hist->GetRMS(), WidthInit.low * hist->GetRMS(), WidthInit.high * hist->GetRMS());
            RooVoigtian Voig("tmp" + syst, "" + syst, *var, mean, width, sigma);

            //RooRealVar mean_cb("mean_cb" + syst, "Mean" + syst, MeanCBInit.mean, MeanCBInit.low, MeanCBInit.high);
            RooRealVar sigma_cb("sigma_cb" + syst, "Width" + syst, SigmaCBInit.mean, SigmaCBInit.low, SigmaCBInit.high);
            //            RooRealVar n("n" + syst, "" + syst, 3.12);
            RooRealVar n("n" + syst, "" + syst, NInit.mean, NInit.low, NInit.high);
            //            RooRealVar alpha("alpha" + syst, "" + syst, AlphaInit.mean, AlphaInit.low, AlphaInit.high);
            RooRealVar alpha("alpha" + syst, "" + syst, AlphaInit.mean);
            //            RooCBShape CB("cball" + syst, "crystal ball" + syst, *var, mean_cb, sigma_cb, alpha, n);
            RooCBShape CB("cball" + syst, "crystal ball" + syst, *var, mean, sigma_cb, alpha, n);

            //            RooRealVar frac("frac" + syst, "frac" + syst, 0.612, 0., 1.);
            RooRealVar frac("frac" + syst, "frac" + syst, 0.612);
            RooAddPdf Voig2("sum" + syst, "Gaussian crystal ball and Voig PDF" + syst, RooArgList(Voig, CB), RooArgList(frac));
            RooFitResult * ret = Voig2.fitTo(*data, RooFit::Save());

            delete hist;
            return ret;
        } else {
            cout << ">>>>>>>>>>>>>>>>>>>>> " << syst << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            TH1D * hist = (TH1D*) data->createHistogram("hist" + syst, *var, RooFit::Binning(nbin));
            RooRealVar mean("mean" + syst, "mean" + syst, hist->GetMean(), MeanInit.low * hist->GetMean(), MeanInit.high * hist->GetMean());
            RooRealVar sigma("sigma" + syst, "sigma" + syst, SigmaInit.mean, SigmaInit.low, SigmaInit.high);
            RooRealVar width("width" + syst, "width" + syst, hist->GetRMS(), WidthInit.low * hist->GetRMS(), WidthInit.high * hist->GetRMS());
            RooVoigtian Voig("tmp" + syst, "" + syst, *var, mean, width, sigma);

            //            RooRealVar mean_cb("mean_cb" + syst, "Mean" + syst, MeanCBInit.mean, MeanCBInit.low, MeanCBInit.high);
            RooRealVar sigma_cb("sigma_cb" + syst, "Width" + syst, SigmaCBInit.mean, SigmaCBInit.low, SigmaCBInit.high);
            //            RooRealVar n("n" + syst, "" + syst, 3.12);
            RooRealVar n("n" + syst, "" + syst, NInit.mean, NInit.low, NInit.high);
            //            RooRealVar n("n" + syst, "" + syst, paramNominal["n"],
            //                    paramNominal["n"] - paramNominalErr["n"],
            //                    paramNominal["n"] + paramNominalErr["n"]
            //                    );
            //            cout << "RooRealVar n(\"n\"+" << syst << ", \"\" + " << syst << ", " << paramNominal["n"]
            //                    << ", " << paramNominal["n"] - paramNominalErr["n"]
            //                    << ", " << paramNominal["n"] + paramNominalErr["n"] << " );" << endl;
            //            RooRealVar alpha("alpha" + syst, "" + syst, AlphaInit.mean, AlphaInit.low, AlphaInit.high
            RooRealVar alpha("alpha" + syst, "" + syst, AlphaInit.mean
                    );
            //            RooCBShape CB("cball" + syst, "crystal ball" + syst, *var, mean_cb, sigma_cb, alpha, n);
            RooCBShape CB("cball" + syst, "crystal ball" + syst, *var, mean, sigma_cb, alpha, n);

            RooRealVar frac("frac" + syst, "frac" + syst, 0.612);
            //            RooRealVar frac("frac" + syst, "frac" + syst, paramNominal["frac"],
            //                    paramNominal["frac"] - paramNominalErr["frac"],
            //                    paramNominal["frac"] + paramNominalErr["frac"]
            //                    );
            //            cout << "RooRealVar frac(\"frac\"+" << syst << ", \"\" + " << syst << ", " << paramNominal["frac"]
            //                    << ", " << paramNominal["frac"] - paramNominalErr["frac"]
            //                    << ", " << paramNominal["frac"] + paramNominalErr["frac"] << " );" << endl;
            RooAddPdf Voig2("sum" + syst, "Gaussian crystal ball and Voig PDF" + syst, RooArgList(Voig, CB), RooArgList(frac));
            RooFitResult * ret = Voig2.fitTo(*data, RooFit::Save());

            delete hist;
            return ret;
        }
        return 0;
    }

    void fillValues(bool draw = false) {
        RooFitResult * iFRN = fitToSignal(nominal);
        paramNominal["mean" ] = ((RooRealVar*) iFRN->floatParsFinal().find("mean"))->getVal();
        paramNominal["sigma" ] = ((RooRealVar*) iFRN->floatParsFinal().find("sigma"))->getVal();
        paramNominal["width" ] = ((RooRealVar*) iFRN->floatParsFinal().find("width"))->getVal();
        //        paramNominal["mean_cb" ] = ((RooRealVar*) iFRN->floatParsFinal().find("mean_cb"))->getVal();
        paramNominal["sigma_cb" ] = ((RooRealVar*) iFRN->floatParsFinal().find("sigma_cb"))->getVal();
        //        paramNominal["alpha" ] = ((RooRealVar*) iFRN->floatParsFinal().find("alpha"))->getVal();
        paramNominal["n" ] = ((RooRealVar*) iFRN->floatParsFinal().find("n"))->getVal();
        //        paramNominal["frac" ] = ((RooRealVar*) iFRN->floatParsFinal().find("frac"))->getVal();
        paramNominalErr["mean" ] = ((RooRealVar*) iFRN->floatParsFinal().find("mean"))->getError();
        paramNominalErr["sigma" ] = ((RooRealVar*) iFRN->floatParsFinal().find("sigma"))->getError();
        paramNominalErr["width" ] = ((RooRealVar*) iFRN->floatParsFinal().find("width"))->getError();
        //        paramNominalErr["mean_cb" ] = ((RooRealVar*) iFRN->floatParsFinal().find("mean_cb"))->getError();
        paramNominalErr["sigma_cb" ] = ((RooRealVar*) iFRN->floatParsFinal().find("sigma_cb"))->getError();
        //        paramNominalErr["alpha" ] = ((RooRealVar*) iFRN->floatParsFinal().find("alpha"))->getError();
        paramNominalErr["n" ] = ((RooRealVar*) iFRN->floatParsFinal().find("n"))->getError();
        //        paramNominalErr["frac" ] = ((RooRealVar*) iFRN->floatParsFinal().find("frac"))->getError();
        if (draw) {
            stringstream S;
            S << "plots_" << mass_ << ".C";
            RooPlot * pl = var->frame();
            nominal->plotOn(pl);
            RooVoigtian * Voig = new RooVoigtian("tmpDraw", "", *var, *((RooRealVar*) iFRN->floatParsFinal().find("mean")),
                    *((RooRealVar*) iFRN->floatParsFinal().find("width")),
                    *((RooRealVar*) iFRN->floatParsFinal().find("sigma")));
            //            RooCBShape * CB = new RooCBShape("cballDraw", "crystal ball", *var, *((RooRealVar*) iFRN->floatParsFinal().find("mean_cb")),
            RooCBShape * CB = new RooCBShape("cballDraw", "crystal ball", *var, *((RooRealVar*) iFRN->floatParsFinal().find("mean")),
                    *((RooRealVar*) iFRN->floatParsFinal().find("sigma_cb")),
                    //                    *((RooRealVar*) iFRN->floatParsFinal().find("alpha")),
                    *(new RooRealVar("TMP", "TMP", AlphaInit.mean)),
                    //                    *(new RooRealVar("TMPN", "TMPN", 3.12)));
                    *((RooRealVar*) iFRN->floatParsFinal().find("n")));
            RooAddPdf * Voig2 = new RooAddPdf("sumDraw", "Gaussian crystal ball and Voig PDF", RooArgList(*Voig, *CB),
                    RooArgList(*(new RooRealVar("NAME", "", 0.612))));
            //                    RooArgList(*((RooRealVar*) iFRN->floatParsFinal().find("frac"))));
            Voig2->plotOn(pl, RooFit::LineColor(kBlack));
            Voig2->plotOn(pl, RooFit::Components(*CB), RooFit::LineColor(kBlue));
            Voig2->plotOn(pl, RooFit::Components(*Voig), RooFit::LineColor(kRed));

            TCanvas C;
            C.cd();
            pl->Draw();
            C.SaveAs(S.str().c_str());
        }
        delete iFRN;
        for (unsigned int iu = 0; iu < systUp.size(); iu++) {
            RooFitResult * iFRU = fitToSignal(systUp[iu], systprefix[(2 * iu) + 1]);
            paramUp["mean" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("mean" + systprefix[(2 * iu) + 1]))->getVal();
            paramUp["sigma" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("sigma" + systprefix[(2 * iu) + 1]))->getVal();
            paramUp["width" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("width" + systprefix[(2 * iu) + 1]))->getVal();
            //            paramUp["mean_cb" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("mean_cb" + systprefix[(2 * iu) + 1]))->getVal();
            paramUp["mean" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("mean" + systprefix[(2 * iu) + 1]))->getVal();
            paramUp["sigma_cb" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("sigma_cb" + systprefix[(2 * iu) + 1]))->getVal();
            //            paramUp["alpha" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("alpha" + systprefix[(2 * iu) + 1]))->getVal();
            paramUp["n" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("n" + systprefix[(2 * iu) + 1]))->getVal();
            //            paramUp["frac" + systprefix[(2 * iu) + 1]] = ((RooRealVar*) iFRU->floatParsFinal().find("frac" + systprefix[(2 * iu) + 1]))->getVal();
            delete iFRU;
        }
        for (unsigned int iu = 0; iu < systDown.size(); iu++) {

            RooFitResult * iFRD = fitToSignal(systDown[iu], systprefix[(2 * iu)]);
            paramDown["mean" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("mean" + systprefix[(2 * iu)]))->getVal();
            paramDown["sigma" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("sigma" + systprefix[(2 * iu)]))->getVal();
            paramDown["width" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("width" + systprefix[(2 * iu)]))->getVal();
            //            paramDown["mean_cb" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("mean_cb" + systprefix[(2 * iu)]))->getVal();
            paramDown["mean" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("mean" + systprefix[(2 * iu)]))->getVal();
            paramDown["sigma_cb" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("sigma_cb" + systprefix[(2 * iu)]))->getVal();
            //            paramDown["alpha" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("alpha" + systprefix[(2 * iu)]))->getVal();
            paramDown["n" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("n" + systprefix[(2 * iu)]))->getVal();
            //            paramDown["frac" + systprefix[(2 * iu)]] = ((RooRealVar*) iFRD->floatParsFinal().find("frac" + systprefix[(2 * iu)]))->getVal();
            delete iFRD;
        }


    }

    std::map<TString, std::pair<double, double> > GetParamErrors(double envelope = true) {
        std::map<TString, std::pair<double, double> > allSysts;
        std::map<TString, double>::iterator iNominal = paramNominal.begin();
        std::map<TString, double>::iterator iDown = paramDown.begin();
        for (; iNominal != paramNominal.end(); iNominal++) {
            std::vector<double> Systs;
            double cent = iNominal->second;
            int iu = 0;
            for (; iDown != paramDown.end(); iDown++) {

                double eL = paramDown[iNominal->first + systprefix[(2 * iu)]];
                double eH = paramUp[iNominal->first + systprefix[(2 * iu) + 1]];
                Systs.push_back(-cent + eL);
                Systs.push_back(-cent + eH);
                iu++;
            }
            std::sort(Systs.begin(), Systs.end());
            double eL = -sqrt(pow(paramNominalErr[iNominal->first], 2) + pow(Systs[0], 2));
            double eH = sqrt(pow(paramNominalErr[iNominal->first], 2) + pow(Systs[Systs.size() - 1], 2));
            allSysts[iNominal->first] = make_pair(eL, eH);
        }
        return allSysts;
    }

    std::map <TString, std::pair<double, double> >GetParamErrorsInd(TString src) {
        std::map <TString, std::pair<double, double> > ret;
        std::map<TString, double>::iterator iNominal = paramNominal.begin();

        cout << "------- Systematic for " << src << endl;
        for (; iNominal != paramNominal.end(); iNominal++) {
            double cent = iNominal->second;
            cout << "---- Central value of * " << iNominal->first << " *: " << cent << endl;
            double eL = 1000;
            double eH = 1000;
            if (src == "b") {
                eL = paramDown[iNominal->first + systprefix[0]];
                cout << "Down b value: " << eL << endl;
                eH = paramUp[iNominal->first + systprefix[1]];
                cout << "Up b value: " << eH << endl;
            } else if (src == "JES") {
                eL = paramDown[iNominal->first + systprefix[2]];
                cout << "Down JES value: " << eL << endl;
                eH = paramUp[iNominal->first + systprefix[3]];
                cout << "Up JES value: " << eL << endl;
            } else if (src == "JER") {
                eL = paramDown[iNominal->first + systprefix[4]];
                cout << "Down JER value: " << eL << endl;
                eH = paramUp[iNominal->first + systprefix[5]];
                cout << "Up JER value: " << eL << endl;
            } else if (src == "mu") {
                eL = paramDown[iNominal->first + systprefix[6]];
                cout << "Down mu value: " << eL << endl;
                eH = paramUp[iNominal->first + systprefix[7]];
                cout << "Up mu value: " << eL << endl;
            } else if (src == "pu") {

                eL = paramDown[iNominal->first + systprefix[8]];
                cout << "Down pu value: " << eL << endl;
                eH = paramUp[iNominal->first + systprefix[9]];
                cout << "Up pu value: " << eL << endl;
            }
            ret[iNominal->first] = make_pair(eL - cent, eH - cent);
        }
        return ret;
    }

    std::map<TString, double> GetParamUp()const {

        return paramUp;
    }

    std::map<TString, double> GetParamDown()const {

        return paramDown;
    }

    std::map<TString, double> GetParamNominal()const {

        return paramNominal;
    }

    std::map<TString, double> GetParamNominalErr()const {

        return paramNominalErr;
    }

    double GetMass()const {
        return mass_;
    }
private:
    double mass_;
    std::vector<RooDataSet*> systUp;
    std::vector<RooDataSet*> systDown;
    RooDataSet * nominal;
    RooRealVar * var;
    std::map<TString, double> paramUp;
    std::map<TString, double> paramDown;
    std::map<TString, double> paramNominal;
    std::map<TString, double> paramNominalErr;
    Initials MeanCBInit;
    Initials MeanInit;
    Initials WidthInit;
    Initials SigmaInit;
    Initials SigmaCBInit;
    Initials NInit;
    Initials AlphaInit;
    Initials FracInit;
};


#endif	/* MASSPOINT_H */

