/* 
 * File:   Coverage.C
 * Author: nadjieh
 *
 * Created on February 7, 2015, 5:32 PM
 */

using namespace std;
//using namespace RooFit;
#include<sstream>
#include<iostream>
#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
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
#include "RooRandom.h"
#include "RooWorkspace.h"
#include "ModelConstructor.h"

/*
 * 
 */
int main(int argc, char** argv) {
    RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
    RooRandom::randomGenerator()->SetSeed(37);

    int nPD = 100;
    int nSample = 100;
    int nPoint = 25;
    double width = (70. - 20.) / (double) nPoint;
    vector<double> xs;
    for (int i = 0; i < nPoint; i++)
        xs.push_back(20 + (i * width));

    ModelConstructor mymodel("mymodel", nPD);
    mymodel.makeNOrigDataPdf();
    RooWorkspace * w = mymodel.getWS();
    vector<vector<double> > allDiffs;
    for (int iData = 0; iData < nPD; iData++)
        allDiffs.push_back(mymodel.getLocalOrigKeysDiffsScaled(xs, iData));
    //    cout << allDiffs.size() << "\t" << allDiffs[0][10] << endl;

    SigmaEvaluator mysigma("mysigma", nSample, mymodel.getWS(), mymodel.getnPD());
    vector<vector<pair<double, double> > > forNPDsigandps;
    for (int iData = 0; iData < nPD; iData++) {
        mysigma.resampler(iData);
        vector<pair<double, double> > sigandps = mysigma.getSigmaAndPoints(xs, iData);
        TGraphErrors * tmp = mysigma.getSigmaAndPointsGraph(xs, iData);
        stringstream s;
        s << "band_" << iData << ".C";
        tmp->SaveAs(s.str().c_str());
        forNPDsigandps.push_back(sigandps);
    }
    cout << forNPDsigandps.size() << endl;
    cout << forNPDsigandps[0].size() << endl;

    vector< vector<double> > forNPDz_x;
    for (int iData = 0; iData < nPD; iData++) {
        vector<double> diff_iData = allDiffs[iData];
        vector<pair<double, double> > sigandps_iData = forNPDsigandps[iData];
        vector<double> z_x;
        for (unsigned int ix = 0; ix < sigandps_iData.size(); ix++) {
            z_x.push_back(diff_iData[ix] / sigandps_iData[ix].second);
            //            cout << "Z " << ix << ": " << z_x.at(z_x.size() - 1) << endl;
        }
        forNPDz_x.push_back(z_x);
    }

    vector<double> q_x;
    for (unsigned int iX = 0; iX < xs.size(); iX++) {
        int nInInteval_X = 0;
        for (int iData = 0; iData < nPD; iData++) {
            vector<double> z_x = forNPDz_x[iData];
            //            cout << "Z " << iX << ": " << z_x.at(iX) << endl;
            if (z_x[iX] <= 1. && z_x[iX] >= -1.)
                nInInteval_X++;
            //            cout<<"nInInteval_X: "<<nInInteval_X<<endl;
        }
        q_x.push_back((double) nInInteval_X / (double) nPD);
    }
    TGraphErrors * qGraph = new TGraphErrors((int) xs.size());
    for (unsigned int iX = 0; iX < xs.size(); iX++) {
        qGraph->SetPoint(iX, xs[iX], q_x[iX]);
        qGraph->SetPointError(iX, 0, sqrt(q_x[iX] * (1 - q_x[iX]) / (double) nPD));
    }
    qGraph->SetMarkerStyle(20);
    qGraph->SetMarkerColor(kRed);
    TCanvas c;
    c.cd();
    qGraph->Draw("ap");
    c.SaveAs("qGraph.C");

    return 0;
}

