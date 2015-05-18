/* 
 * File:   HambLikelihood.h
 * Author: nadjieh
 *
 * Created on May 1, 2012, 7:06 PM
 */
#ifndef HambLikelihood_H
#define	HambLikelihood_H
#include "TF1.h"
#include "TF2.h"
#include "TF3.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TRandom1.h"
#include "TVirtualFitter.h"
#include "TMinuit.h"
#include "TFitter.h"
#include "TROOT.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class HambLikelihood {
public:

    HambLikelihood(string name, TH1* hData, std::vector<TH1*> WtbSum) : Name(name), data(hData) {
        data->Sumw2(); //cout<<"---"<<endl;
        //        bkg->Sumw2(); //cout<<"----"<<endl;
        for (unsigned int p = 0; p < WtbSum.size(); p++) {
            //            cout<<"==== "<<WtbSum.at(p)->GetEntries()<<endl;

            WtbSum.at(p)->Sumw2();
            signals.push_back(WtbSum.at(p));
        }
    }

    ~HambLikelihood() {
    }

    virtual Double_t operator()(double * x, double * par = 0) {
        //        cout<<"operator is called"<<endl;
        /*
         * x[0]: ttN
         * x[1]: dyN
         * x[2]: otherN
         */
        double LL = 0.0;
        int nbins = data->GetXaxis()->GetNbins();
        for (int i = 0; i < nbins; i++) {
            std::pair<double, double> numbers = this->getNdataNmc(i + 1, x);
            //            cout<<"++++++++++ log LL calculator "<<i+1<<endl;
            LL += this->logLikelihood(numbers.first, numbers.second);
        }
        return LL;
    }

    static std::pair<TF3, HambLikelihood*> getHambLLGeneralized(string name, TH1* hData,
            std::vector<TH1*> WtbSum) {
        HambLikelihood * functor = 0;
        functor = new HambLikelihood(name, hData, WtbSum);
        TF3 ret(name.c_str(), functor, 1000, 2000, 0.0, 20, 0.0, 80., 0, "HambLikelihoodGeneralized");
        //        ret.SetRange(0.0, 0.0, 0.000001, 1.0, 1.0, 2.0);

        return make_pair(ret, functor);
    }

    int getNbinData() {
        return this->data->GetXaxis()->GetNbins();
    }

    int findNbinData(double input) {
        return this->data->GetXaxis()->FindBin(input);
    }

protected:
    string Name;
    //    TH1* bkg;
    TH1* data;
    std::vector<TH1*> signals;

    double nSignalRW(int bin, double * n) {
        double nSignal = -100.;
        if (signals.size() != 0) {
            //            cout<<"In general: "<<endl;
            nSignal = 0;
            gROOT->cd();
            stringstream s;
            for (unsigned int p = 0; p < signals.size(); p++) {
                nSignal += (n[p] * signals[p]->GetBinContent(bin));
            }
        }
        if (nSignal == -100.) {

            cout << "************** FATAL ERROR: nSignal is not set ...." << endl;
        }
        return nSignal;
    }
public:

    std::pair<double, double> getNdataNmc(int bin, double * n) {
        int nbins = data->GetXaxis()->GetNbins();
        if (bin > nbins || nbins < 0) {
            cout << "No value for this cos(theta) bin" << endl;
            return make_pair(-100, -100);
        }
        double nData = data->GetBinContent(bin);
        double nSignal = nSignalRW(bin, n);
        //        double nMC = bkg->GetBinContent(bin) + nSignal;
        double nMC = nSignal;
        //        cout<<"****** "<<nData<<"\t"<<nMC<<endl;

        return make_pair(nData, nMC);
    }
protected:

    double logLikelihood(double nData, double nMC) {
        double x_mean = nMC;
        double x = nData;
        if (x_mean <= 0.0)
            return 0.0;
        if (x <= 0.0)
            return 0.0;
        double log_pow_1 = x * log(x_mean);
        double log_exp_1 = -x_mean;
        double log_factoral = x * log(x) - x + (log(x * (1 + 4 * x * (1 + 2 * x))) / 6) + log(M_PI) / 2;

        return log_factoral - log_exp_1 - log_pow_1;
    }

};

void GetMinimumHamb(TF3 F, double * x, double * xerr, double & corr12, bool CalcError = true) {
    //    based on the documentation of TF3::GetMinimumXYZ from
    //    http://root.cern.ch/root/html532/src/TF3.cxx.html#QUjxjE
    //    F.Print("all");
    cout << x[0] << "\t" << x[1] << "\t" << x[2] << endl;
    //    double x0 = x[0];
    //    double x1 = x[1];
    //    double x2 = x[2];
    F.SetNpx(5);
    F.SetNpy(5);
    F.SetNpz(5);
    F.GetMinimumXYZ(x[0], x[1], x[2]);
    if (!CalcError)
        return;
    //    go to minuit for the final minimization

    TVirtualFitter * minuit = TVirtualFitter::Fitter(&F, 3);
    minuit->Clear();
    minuit->SetFitMethod("F3Minimizer");
    double arg_list[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int nNargs = 1;
    minuit->ExecuteCommand("SET PRINT", arg_list, nNargs);
    double xl = 0.0;
    double xu = 0.0;
    double yl = 0.0;
    double yu = 0.0;
    double zl = 0.0;
    double zu = 0.0;
    //    x[0] = 0.593245;
    minuit->SetParameter(0, "x", x[0], 1., x[0] + 500, x[0] - 500);
    //    minuit->FixParameter(0      );
    //    x[1] = FL;
    minuit->SetParameter(1, "y", x[1], 1., x[1] + 10, x[1] - 10);
    //    minuit->FixParameter(1      );
    //    x[2] = 0.925322;
    minuit->SetParameter(2, "z", x[2], 1., x[2] + 10, x[2] - 10);
    //    minuit->SetParameter(2, "z", 1, 0.1, zl , zu );
    minuit->FixParameter(2);
    //    x[0] = 0.7;
    //    x[1] = 0.3;
    //    x[2] = 1.;
    for (int i = 0; i < 10; i++)
        arg_list[i] = 1.;
    Int_t fitResult = minuit->ExecuteCommand("MIGRAD", arg_list, 0);
    if (fitResult != 0) {
        cout << "Abnormal termination of minimization" << endl;
        x[0] = -1.0;
        x[1] = -1.0;
        x[2] = -1.0;
        delete minuit;
        return;
    }

    x[0] = minuit->GetParameter(0);
    x[1] = minuit->GetParameter(1);
    x[2] = minuit->GetParameter(2);

    double globcc = 0.0;
    minuit->GetErrors(0, xu, xl, xerr[0], globcc);
    minuit->GetErrors(1, yu, yl, xerr[1], globcc);
    minuit->GetErrors(2, zu, zl, xerr[2], globcc);
    corr12 = minuit->GetCovarianceMatrixElement(0, 1);
    cout << x[0] << " \\pm " << xerr[0] << endl;
    cout << x[1] << " \\pm " << xerr[1] << endl;
    cout << x[2] << " \\pm " << xerr[2] << endl;
    delete minuit;
}





#endif	/* HambLikelihood_H */

