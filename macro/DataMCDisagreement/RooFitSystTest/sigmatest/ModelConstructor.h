#include <algorithm> 
#include<iostream>
#include<sstream>
#include "TF1.h"
#include "TRandom3.h"
#include "TGraphErrors.h"
#include "TString.h"
#include "RooRealVar.h"
#include "RooKeysPdf.h"
#include "RooGaussian.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooExponential.h"
#include "RooFFTConvPdf.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooWorkspace.h"
TF1 *f1, *f2;

double finter(double *x, double *par) {
    return (f1->EvalPar(x, par) - f2->EvalPar(x, par));
}
//using namespace RooFit;
using namespace std;

class ModelConstructor {
public:

    ModelConstructor(TString name_, int nPD_ = 100, double xl = 20., double xh = 70.) : name(name_), nPD(nPD_) {
        double dy_range = 8.10450000000000017e+01;
        double dytt_range = 4.95274000000000001e+02;
        double expo_range = 3.28866300000000024e+02;
        double sum_val = dy_range + dytt_range + expo_range;
        double frac_dy_val = dytt_range / sum_val;
        double frac_pf_val = dy_range / sum_val;
        w = 0;
        eventSelectionamassMu = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", xl, xh);
        mean_bw = new RooRealVar(name + "_mean_bw", "Mean", 90.8, 60, 120);
        mean_cb = new RooRealVar(name + "_mean_cb", "Mean", 1.0, 0., 50.);
        sigma_bw = new RooRealVar(name + "_sigma_bw", "Width", 4., 0.5, 10.);
        sigma_cb = new RooRealVar(name + "_sigma_cb", "Width", 2.3, 0., 260.0);
        n = new RooRealVar(name + "_n", "", 0.0, 5.0);
        alpha = new RooRealVar(name + "_alpha", "", 0.0, 5.0);
        lambda = new RooRealVar(name + "_lambda", "slope", -0.1, -5., 0.);
        mean_dytt = new RooRealVar(name + "_mean_dytt", "mean_dytt", 42.48403);
        sigma_dytt = new RooRealVar(name + "_sigma_dytt", "sigma_dytt", 9.348124);
        frac_dy = new RooRealVar(name + "frac_dy", "dytt fraction", frac_dy_val);
        frac_pf = new RooRealVar(name + "_frac_pf", "frac_pf", frac_pf_val);
        gauss_bw = new RooBreitWigner(name + "_gauss_bw", "gauss_bw", *eventSelectionamassMu, *mean_bw, *sigma_bw);
        cball = new RooCBShape(name + "_cball", "crystal ball", *eventSelectionamassMu, *mean_cb, *sigma_cb, *alpha, *n);
        expo = new RooExponential(name + "_expo", "exponential PDF", *eventSelectionamassMu, *lambda);
        bwxCryBall = new RooFFTConvPdf(name + "_bwxCryBall", "FFT Conv CryBall and BW", *eventSelectionamassMu, *gauss_bw, *cball);
        dytt = new RooGaussian("dytt", "dytt", *eventSelectionamassMu, *mean_dytt, *sigma_dytt);
        sum = new RooAddPdf(name + "_norm", "all", RooArgList(*bwxCryBall, *dytt, *expo), RooArgList(*frac_pf, *frac_dy));
    }

    ~ModelConstructor() {
    }

    RooDataSet * getOriginalData(int iData, double nEvent = 1500., int seed = 37) {
        TRandom3 r(seed);
        int nData = (int) r.Poisson(nEvent);
        RooDataSet * data_orig = sum->generate(*eventSelectionamassMu, nData);
        stringstream s;
        s << "AtoyPD_" << iData;
        data_orig->SetName(s.str().c_str());
        s.str("");
        s << "The original toy data number " << iData;
        data_orig->SetTitle(s.str().c_str());
        return data_orig;
    }

    RooKeysPdf * getOriginalKeysPdf(int iData, RooDataSet * data_orig, double rho = 1.) {
        stringstream s;
        s << "pdf_orig_" << iData;
        stringstream s2;
        s2 << "Original keyspdf number " << iData;
        return (new RooKeysPdf(s.str().c_str(), s2.str().c_str(), *eventSelectionamassMu, *data_orig, RooKeysPdf::MirrorBoth, rho));
    }

    void makeNOrigDataPdf(double nEvent = 1500., int seed = 37) {
        w = new RooWorkspace(name, name);
        w->import(*eventSelectionamassMu);
        for (int i = 0; i < nPD; i++) {
            RooDataSet * PD = this->getOriginalData(i, nEvent, seed);
            w->import(*PD);
            RooKeysPdf * mypdf = this->getOriginalKeysPdf(i, PD);
            eventSelectionamassMu->setRange("INT", 20., 70.);
            RooAbsReal * value = mypdf->createIntegral(*eventSelectionamassMu, *eventSelectionamassMu, "INT");
            //            cout << "-------- In make" << value->getVal() << endl;
            w->import(*mypdf);
            stringstream s;
            s << "%f * " << mypdf->GetName();
            TString formula = TString::Format(s.str().c_str(), PD->sumEntries(0));
            //            cout << formula << endl;
            s.str("");
            s << "scaled_OrigPdf_" << i;
            RooFormulaVar scaled_pdf(s.str().c_str(), formula, RooArgList(*mypdf));
            TF1 * func = scaled_pdf.asTF(*eventSelectionamassMu, RooArgList(), *eventSelectionamassMu);
            //            cout << "-------- In make" << func->Integral(20., 70.) << endl;
            w->import(*func);
        }

        w->writeToFile(name + "_Originals.root");
    }

    RooWorkspace * getWS()const {
        return w;
    }

    double getLocalOrigKeysDiffScaled(double x, int iData) {
        stringstream s;
        s << "AtoyPD_" << iData;
        TString dataName = s.str().c_str();
        RooDataSet * data = (RooDataSet*) w->data(dataName);
        s.str("");
        s << "OrigModel_" << iData;
        TString modelName = s.str().c_str();
        RooAbsPdf * pdf = (RooAbsPdf*) sum->Clone(modelName);
        modelName = "%f * " + modelName;
        TString formula = TString::Format(modelName, data->sumEntries(0));
        RooFormulaVar scaled_pdf("scaled_pdf", formula, RooArgList(*pdf));
        TF1 * model = scaled_pdf.asTF(*eventSelectionamassMu, RooArgList(), *eventSelectionamassMu);
        s.str("");
        s << pdf->GetName() << "_scaledfunc";
        model->SetName(s.str().c_str());
        //        TF1 * model = getScaledModelFunction(iData);
        //        cout << "model: " << model->GetName() << " iData " << iData << ":\n\tX = " << x << "\n\tf(x) = " << model->Eval(x) << endl;

        s.str("");
        s << "scaled_OrigPdf_" << iData;
        TF1 * keys = (TF1*) w->obj(s.str().c_str());
        //        cout << "keys: " << keys->GetName() << " iData " << iData << ":\n\tX = " << x << "\n\tf(x) = " << keys->Eval(x) << endl;
        //        cout << model->Integral(20., 70.) << endl;
        //        cout << keys->Integral(20., 70.) << endl;
        eventSelectionamassMu->setRange("INT", 20, 70);
        //        cout << keys->Integral(20., 70.) << endl;
        return keys->Eval(x) - model->Eval(x);
    }

    vector<double> getLocalOrigKeysDiffsScaled(vector<double> x, int iData) {
        vector<double> ret;
        for (unsigned int i = 0; i < x.size(); i++) {
            ret.push_back(this->getLocalOrigKeysDiffScaled(x[i], iData));
        }
        return ret;
    }

    int getnPD()const {
        return nPD;
    }
private:
    TString name;
    int nPD;
    RooRealVar * eventSelectionamassMu;
    RooRealVar * mean_bw;
    RooRealVar * mean_cb;
    RooRealVar * sigma_bw;
    RooRealVar * sigma_cb;
    RooRealVar * n;
    RooRealVar * alpha;
    RooRealVar * lambda;
    RooRealVar * mean_dytt;
    RooRealVar * sigma_dytt;
    RooRealVar * frac_dy;
    RooRealVar * frac_pf;
    RooBreitWigner * gauss_bw;
    RooCBShape * cball;
    RooExponential * expo;
    RooFFTConvPdf * bwxCryBall;
    RooGaussian * dytt;
    RooAddPdf * sum;
    RooWorkspace * w;
};

class SigmaEvaluator {
public:

    SigmaEvaluator(TString name_, int nP, RooWorkspace * origWS, int nData, double xl = 20, double xh = 70) : name(name_),
    nSample(nP), rangeL(xl), rangeU(xh) {
        wsOrig = origWS;
        for (int i = 0; i < nData; i++)
            wsKeys.push_back(0);
    }

    ~SigmaEvaluator() {
    }

    void resampler(int iData, TString varname = "eventSelectionamassMu", double nEvent = 1500.,
            int rho = 1, int seed = 37) {
        RooRealVar * var = wsOrig->var(varname);
        stringstream s;
        s << "pdf_orig_" << iData;
        TString origPdfName = s.str().c_str();
        RooKeysPdf * mypdf = (RooKeysPdf*) wsOrig->pdf(origPdfName);
        s.str("");
        s << name << "_" << iData;
        TRandom3 r(seed);
        wsKeys[iData] = new RooWorkspace(s.str().c_str(), s.str().c_str());
        wsKeys[iData]->import(*var);
        for (int i = 0; i < nSample; i++) {
            s.str("");
            s << "_" << i + 1;
            TString Name = s.str().c_str();
            TString dataName = "data" + Name;
            int nData = (int) r.Poisson(nEvent);
            RooDataSet * PD = mypdf->generate(*var, nData);
            PD->SetName(dataName);
            wsKeys[iData]->import(*PD);
            s.str("");
            s << rho;
            wsKeys[iData]->factory("KeysPdf::mypdf" + Name + "(" + varname + "," + dataName +
                    ",RooKeysPdf::MirrorBoth," + s.str().c_str() + ")");
        }
        s.str("");
        s << name << "_" << iData << "_KeysSample.root";
        wsKeys[iData]->writeToFile(s.str().c_str());
    }

    TF1 * getScaledPdfFunction(RooKeysPdf pdf, RooDataSet data, int iData, TString varname = "eventSelectionamassMu", double binWidth = 1.) {
        RooRealVar * var = wsKeys[iData]->var(varname);
        TString pdfName = pdf.GetName();
        pdfName = "%f * " + pdfName;
        TString formula = TString::Format(pdfName, data.sumEntries(0));
        RooFormulaVar scaled_pdf("scaled_pdf", formula, RooArgList(pdf));
        TF1 * func = scaled_pdf.asTF(*var, RooArgList(), *var);
        stringstream s;
        s << pdf.GetName() << "_scaledfunc";
        func->SetName(s.str().c_str());
        //        cout << func->GetName() << " ------------ " << func->Eval(68) << endl;
        return func;
    }

    pair<double, double> getSigmaPoint(double x, int iData, TString varname = "eventSelectionamassMu") {
        stringstream s;
        std::vector<double> xs;
        for (int i = 0; i < nSample; i++) {
            s.str("");
            s << "_" << i + 1;
            TString Name = s.str().c_str();
            TString dataName = "data" + Name;
            TString pdfName = "mypdf" + Name;
            RooDataSet * data = (RooDataSet*) wsKeys[iData]->data(dataName);
            RooKeysPdf * pdf = (RooKeysPdf*) wsKeys[iData]->pdf(pdfName);

            //----------- Not possible to take external function :(
            RooRealVar * var = wsKeys[iData]->var(varname);
            pdfName = "%f * " + pdfName;
            TString formula = TString::Format(pdfName, data->sumEntries(0));
            RooFormulaVar scaled_pdf("scaled_pdf", formula, RooArgList(*pdf));
            TF1 * func = scaled_pdf.asTF(*var, RooArgList(), *var);
            stringstream s;
            s << pdf->GetName() << "_scaledfunc";
            func->SetName(s.str().c_str());
            //-----------

            //TF1 * func = this->getScaledPdfFunction(*pdf, *data, iData, varname);

            xs.push_back(func->Eval(x));
            //cout << func->GetName() << " iData " << iData << ", iSample: " << i << "\n\tX = " << x << "\n\tf(x) = " << xs[xs.size() - 1] << endl;
        }
        std::sort(xs.begin(), xs.end());
        int n16 = (int) (0.1587 * nSample);
        double sigL = (xs[n16 + 1] - xs[n16])*((0.1587 * nSample) - n16) + xs[n16];
        int n84 = (int) (0.8413 * nSample);
        double sigH = (xs[n84 + 1] - xs[n84])*((0.8413 * nSample) - n84) + xs[n84];
        double mean = 0;
        for (unsigned int i = 0; i < xs.size(); i++) {
            mean += xs[i];
        }
        mean /= xs.size();
        return make_pair(mean, 0.5 * (sigH - sigL));
    }

    vector<pair<double, double> > getSigmaAndPoints(vector<double> x, int iData) {
        vector<pair<double, double> > ret;
        for (unsigned int i = 0; i < x.size(); i++) {
            ret.push_back(this->getSigmaPoint(x[i], iData));
        }
        return ret;
    }

    TGraphErrors * getSigmaAndPointsGraph(vector<double> x, int iData) {
        vector<pair<double, double> > vect = this->getSigmaAndPoints(x, iData);
        TGraphErrors * ret = new TGraphErrors((int) x.size());
        ret->SetName("pointErrs");
        for (unsigned int i = 0; i < x.size(); i++) {
            pair<double, double> valErr = vect[i];
            ret->SetPoint(i, x[i], valErr.first);
            ret->SetPointError(i, 0, valErr.second);
        }
        return ret;
    }

private:
    TString name;
    int nSample;
    RooWorkspace * wsOrig;
    vector<RooWorkspace*> wsKeys;
    double rangeL;
    double rangeU;
};