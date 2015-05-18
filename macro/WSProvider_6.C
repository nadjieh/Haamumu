#include <fstream>
#include "RooCategory.h"
#include "RooWorkspace.h"
#include "RooRandom.h"
#include "../interface/RooMultiPdf.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "TFile.h"
#include "TArrow.h"
#include "TPaveText.h"
#include "TLatex.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TStyle.h"
#include "TChain.h"
#include "TH2.h"
#include "TH1.h"
#include "TF1.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TVirtualFitter.h"
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooPolynomial.h"
#include "RooExponential.h"
#include "RooArgList.h"
#include "RooGenericPdf.h"
#include "RooExtendPdf.h"
#include "RooFitResult.h"
#include "RooChebychev.h"
#include "RooDataHist.h"
#include "RooVoigtian.h"
#include "RooPlot.h"
#include <stdio.h>
#include <math.h>

using namespace RooFit;
using namespace std;
TString yieldSystProvider(double ySyst, double tmpYieldSyst){
	cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout <<"num 1:" << ySyst<<endl;
	cout <<"num 2:" << tmpYieldSyst<<endl;
	TString YieldSyst;
        if(ySyst == 1. && tmpYieldSyst == 1.){
		cout << "num1 = num2 = 1.0"<<endl;
                YieldSyst = "1.0";
        } else if((tmpYieldSyst == 1. || ySyst == 1.) || (tmpYieldSyst > 1. && ySyst > 1.) ||  (tmpYieldSyst < 1. && ySyst < 1.)){
		cout << "non-symmetric"<<endl;
                double avg = (tmpYieldSyst+ySyst)/2.;
                if(avg < 1.)
                        avg = 1. + (1.-avg);
                stringstream myTmp;
                myTmp << avg;
                YieldSyst = myTmp.str().c_str();
		if(fabs(avg -1) < 0.0001)
			YieldSyst = "1.0";
        } else {
		cout << "symmetric"<<endl;
                stringstream myTmp;
                if(tmpYieldSyst > ySyst)
                        myTmp << ySyst <<"/"<<tmpYieldSyst;
                else
                        myTmp << tmpYieldSyst <<"/"<< ySyst;
                YieldSyst = myTmp.str().c_str();
        } 
	cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	return YieldSyst;
}
std::pair<double,double> systSignalParam(std::map<TString,double> input, bool envelope = true){
	std::vector<double >systs;
	std::vector<double> systsEnvelope;
	for(auto& x: input){
		if(x.first.Contains("DOWN"))
			continue;
		int pos = string(x.first).find(" ");
		TString systName = string(x.first).substr(0,pos);
		for(auto& y: input){
			if(y.first.Contains("UP"))
                        	continue;
			if(string(y.first).substr(0,pos) == systName){
				if(!envelope)
					systs.push_back((fabs(x.second)+fabs(y.second))/2);
				else {
					systsEnvelope.push_back(x.second);
					systsEnvelope.push_back(y.second);
				}
			}
		}
	}
	double unc = 0;
	for(unsigned int i = 0; i< systs.size(); i++){
		unc+=pow(systs[i],2);
	}
	unc = sqrt(unc);
	sort(systsEnvelope.begin(),systsEnvelope.end());
	if(envelope)
		return make_pair(systsEnvelope[0],systsEnvelope[systsEnvelope.size() -1]);
	return make_pair(unc,unc);
}


std::vector<std::pair<double,double> > fitToSignal(RooDataSet data, RooRealVar eventSelectionamassMu, TString & meanret, TString & widthret, TString & sigmaret, int nbin = 50){
    	TH1D * hist = (TH1D*)data.createHistogram("hist",eventSelectionamassMu,RooFit::Binning(nbin));
    	RooRealVar mean("mean", "mean", hist->GetMean(), 0.8*hist->GetMean(),1.2* hist->GetMean());
    	RooRealVar sigma("sigma", "sigma",  0.5,0.,2.);  
    	RooRealVar width("width", "width", hist->GetRMS(), 0.5*hist->GetRMS(), 1.5*hist->GetRMS());    	
    	RooVoigtian Voig("tmp","",eventSelectionamassMu,mean, width,sigma);    	
    	Voig.fitTo(data);
	std::vector<std::pair<double,double> > ret;
	ret.push_back(make_pair(mean.getVal(),mean.getError()));
        ret.push_back(make_pair(width.getVal(),width.getError()));
        ret.push_back(make_pair(sigma.getVal(),sigma.getError()));

    	stringstream val;
    	val << mean.getVal();
	meanret = val.str().c_str();
	val.str("");
    	val << sigma.getVal();		
	sigmaret = val.str().c_str();
	val.str("");
    	val << width.getVal();		
	widthret = val.str().c_str();
	delete 	hist;	
	return ret;
}

void cardMaker(TString mass, double bkgUnc, std::vector<std::pair<double,double> > signalPars, std::vector<std::pair<double,double> > signalSysts, std::map<TString,TString> systYield, bool binned = false, float nSig = 0, float nBkg = 0, int ndata = 0) {
        TString outname = "hamb_shape_" + mass + "_ws.txt";
        if(binned)
                outname = "hamb_shapeBinned_" + mass + "_ws.txt";
    ofstream myfile;
    myfile.open(outname);
    myfile << "imax 1" << endl;
    myfile << "jmax 1  number of backgrounds" << endl;
    myfile << "kmax 8  number of nuisance parameters (sources of systematical uncertainties)" << endl;
    if(!binned){
        myfile << "\n------------" << endl;
        myfile << "shapes\tsigPdf\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:sigPdf_dimu_"<<mass <<endl;//$PROCESS_$CHANNEL w:$PROCESS_$CHANNEL_$SYSTEMATIC" << endl;
        myfile << "shapes\tbkg\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_dimu_bkgshape" << endl;
        myfile << "shapes\tdata_obs\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:data_dimu" << endl;
        myfile << "------------" << endl;
        myfile << "bin\tdimu" << endl;
        myfile << "observation\t-1.0" << endl;
        myfile << "------------" << endl;
        myfile << "bin\tdimu\tdimu" << endl;
        myfile << "process\tsigPdf\tbkg" << endl;
        myfile << "process\t0\t1" << endl;
        myfile << "rate\t1.0\t1.0" << endl;
        myfile << "------------" << endl;
        myfile << "lumi_8TeV\tlnN\t1.026\t-" << endl;
        myfile << "sigPdf_dimu_"<<mass<<"_norm\tlnN\t1.15\t-" << endl;
	if(signalSysts[0].first == signalSysts[0].second){
		myfile << "mean\tparam\t"<<signalPars[0].first<<"\t"<<signalSysts[0].second<< endl;
		myfile << "width\tparam\t"<<signalPars[1].first<<"\t"<<signalSysts[1].second<< endl;
		myfile << "sigma\tparam\t"<<signalPars[2].first<<"\t"<<signalSysts[2].second<< endl;
	} else {
		double eL = -sqrt(pow(signalPars[0].second,2)+pow(signalSysts[0].first,2));
		double eH = sqrt(pow(signalPars[0].second,2)+pow(signalSysts[0].second,2));
		myfile << "mean\tparam\t"<<signalPars[0].first<<"\t"<<eL<<"/+"<<eH<< endl;
		eL = -sqrt(pow(signalPars[1].second,2)+pow(signalSysts[1].first,2));
		eH = sqrt(pow(signalPars[1].second,2)+pow(signalSysts[1].second,2));
		myfile << "width\tparam\t"<<signalPars[1].first<<"\t"<<eL<<"/+"<<eH<< endl;
		eL = -sqrt(pow(signalPars[2].second,2)+pow(signalSysts[2].first,2));
		eH = sqrt(pow(signalPars[2].second,2)+pow(signalSysts[2].second,2));
		myfile << "sigma\tparam\t"<<signalPars[2].first<<"\t"<<eL<<"/+"<<eH<< endl;
	}
	for (auto& x: systYield) {
		if(x.second == "1.0")
			continue;
                myfile << x.first << "\tlnN\t" << x.second << "\t-" <<endl;
        }
        myfile << "pdfindex\tdiscrete" << endl;
    } else {
        myfile << "\n------------" << endl;
        myfile << "shapes * *  hamb-shapes-BinnedParam-m"<< mass <<"-Data-fit.root $CHANNEL/$PROCESS"<<endl;
        myfile << "------------" << endl;
        myfile << "bin\tdimu" << endl;
        myfile << "observation\t"<<ndata << endl;
        myfile << "------------" << endl;
        myfile << "bin\tdimu\tdimu" << endl;
        myfile << "process\tsignal\tbkg" << endl;
        myfile << "process\t0\t1" << endl;
        myfile << "rate\t"<<nSig<<"\t"<<nBkg << endl;
        myfile << "------------" << endl;
        myfile << "lumi_8TeV\tlnN\t1.026\t-" << endl;
        myfile << "signal_norm\tlnN\t1.3\t-" << endl;
        myfile << "bkg_norm\tlnU\t-\t" << 1 + bkgUnc << endl;

    }
    myfile.close();
}
int main(int argc, char** argv) {
    int seed = 37;
    int nbin = 50;
    bool binned = false;
    stringstream nSig;
    stringstream nBkg;
    stringstream mass;
    mass << "40";
    double bL = 20.; //std::atof(mass.str().c_str()) - 10;
    double bH = 70.; //std::atof(mass.str().c_str()) + 10;
    TString pf = "4_4";
    nSig << 3.45;
    nBkg << 552;
    double bkgUnc = 1; //(510-424.)/424.; //50%
    bool parametric = true;
    for (int f = 1; f < argc; f++) {
        string arg_fth(*(argv + f));
        if (arg_fth == "nBins") {
            f++;
            string in(*(argv + f));
            nbin = atof(in.c_str());
        } else if (arg_fth == "nSig") {
            f++;
            string in(*(argv + f));
            nSig.str("");
	    nSig << in;
	    cout<<"========= "<<nSig.str()<<endl;
        } else if (arg_fth == "mass") {
            f++;
            string in(*(argv + f));
	    mass.str("");
            mass << in;
        } else if (arg_fth == "parametric") {
            f++;
            string in(*(argv + f));
	    if(in == "yes")
            	parametric = true;
 	    if(in == "no")
                parametric = false;	
        } 
    }

    stringstream range;
    range << bL << "," << bH;
    cout << "Mass: " << mass.str() << endl;
    cout << "Range: " << range.str() << endl;
    TString Range = range.str().c_str();
    TString Mass = mass.str().c_str();
    ///	Data-fit ////////////////
    TString fname = "";
    if (!binned)
        fname = "hamb-shapes-UnbinnedParam-m" + Mass + "-Data-fit.root";
    else
        fname = "hamb-shapes-BinnedParam-m" + Mass + "-Data-fit.root";

    if (!binned) {
        TString name = "test";
        RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", bL, bH);
        RooRandom::randomGenerator()->SetSeed(seed);

        RooWorkspace *w = new RooWorkspace("w", "w");
        w->factory("eventSelectionamassMu[" + Range + "]"/*,Range(SM, 50,70)"*/);

        //Data observed:
        TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
        TTree* hh = (TTree*) f->Get("rds_zbb");
        RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
        w->import(data);
        TH1D * hData = (TH1D*)data.createHistogram("data_obs", eventSelectionamassMu, Binning(nbin));
        double frac = (double) hData->Integral() / (double) nbin;
        nBkg.str("");
        nBkg << hData->Integral() - (2 * frac);

        //Signal and systematics
        TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hsig = (TTree*) fsig->Get("rds_zbb");
	int nTreeSig = hsig->GetEntries();
        RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
	std::vector<std::pair<double,double> > sigPars;
	if(!parametric){
		cout<< "Importing ..."<<endl;
       		w->import(sigData);
        	w->factory("KeysPdf::sigPdf_dimu_"+Mass+"(eventSelectionamassMu,sigData_dimu)");
	}else {
		TString meanval,sigval,widthval;
	    	sigPars = fitToSignal(sigData, eventSelectionamassMu,meanval,widthval, sigval);
		cout<<">>>>>>>>>>>>>>>>>>>>>>"<<endl;
		cout<<"mean: "<<sigPars[0].first<<" +/- "<<sigPars[0].second<<endl;
		cout<<"width: "<<sigPars[1].first<<" +/- "<<sigPars[1].second<<endl;
		cout<<"sigma: "<<sigPars[2].first<<" +/- "<<sigPars[2].second<<endl;
		cout<<">>>>>>>>>>>>>>>>>>>>>>"<<endl;
    		w->factory("mean["+meanval+"]");	
	    	w->factory("sigma["+sigval+"]");	
    		w->factory("width["+widthval+"]");	
	    	w->factory("Voigtian::sigPdf_dimu_"+Mass+"(eventSelectionamassMu,mean, width,sigma)");
	}
	TString sigVal = nSig.str().c_str();
        w->factory("sigPdf_dimu_"+Mass+"_norm[" + sigVal + "]");

	std::vector<std::pair<double,double> > tmp;
	std::map<TString,double> diffMean;
	std::map<TString,double> diffSigma;
	std::map<TString,double> diffWidth;
	std::map<TString,TString> systYield;
        ////JES UP
        TString jes = "JES";
        TFile * fjesup = new TFile(jes + "U_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjesup = (TTree*) fjesup->Get("rds_zbb");

        int nSyst = hjesup->GetEntriesFast();
        double ySyst = (double) nSyst / (double) nTreeSig;
	double tmpYieldSyst = ySyst;
        ySyst = ySyst * atof(nSig.str().c_str());
        stringstream ySystStr;
        ySystStr << ySyst;

        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;

        RooDataSet jesupData("jesupData_dimu", "jesupData", hjesup, eventSelectionamassMu, "");
        jes = "sigPdf_dimu_"+Mass +"_"+ jes + "Up";
        if(!parametric){
        	w->import(jesupData);
	        w->factory("KeysPdf::" + jes + "(eventSelectionamassMu,jesupData_dimu)");
	} else {
		TString meanjesu,sigjesu,widthjesu;
		tmp.clear();
                tmp = fitToSignal(jesupData, eventSelectionamassMu,meanjesu,widthjesu,sigjesu);
		diffMean["JES UP"] = tmp[0].first - sigPars[0].first;
		diffWidth["JES UP"] = tmp[1].first - sigPars[1].first;
		diffSigma["JES UP"] = tmp[2].first - sigPars[2].first;
                w->factory("meanjesup["+meanjesu+"]");
                w->factory("sigmajesup["+sigjesu+"]");
                w->factory("widthjesup["+widthjesu+"]");
                w->factory("Voigtian::"+ jes +"(eventSelectionamassMu,meanjesup, widthjesup,sigmajesup)");
	}
        w->factory(jes + "_norm[" + ySystStr.str().c_str() + "]");

        ////JES DOWN
        jes = "JES";
        TFile * fjesdown = new TFile(jes + "D_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjesdown = (TTree*) fjesdown->Get("rds_zbb");

        nSyst = hjesdown->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;

	//Nuisance for JES
        cout <<jes <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	systYield[jes]= yieldSystProvider(tmpYieldSyst,ySyst);
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;

        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;


        RooDataSet jesdownData("jesdownData_dimu", "jesdownData", hjesdown, eventSelectionamassMu, "");
        jes = "sigPdf_dimu_"+Mass +"_"+ jes + "Down";
        if(!parametric){
        	w->import(jesdownData);
	        w->factory("KeysPdf::" + jes + "(eventSelectionamassMu,jesdownData_dimu)");
	} else{
		TString meanjesd,sigjesd,widthjesd;
		tmp.clear();
                tmp = fitToSignal(jesdownData, eventSelectionamassMu,meanjesd,widthjesd,sigjesd);
		diffMean["JES DOWN"] = tmp[0].first - sigPars[0].first;
		diffWidth["JES DOWN"] = tmp[1].first - sigPars[1].first;
		diffSigma["JES DOWN"] = tmp[2].first - sigPars[2].first;
                w->factory("meanjesdown["+meanjesd+"]");
                w->factory("sigmajesdown["+sigjesd+"]");
                w->factory("widthjesdown["+widthjesd+"]");
                w->factory("Voigtian::"+ jes +"(eventSelectionamassMu,meanjesdown, widthjesdown,sigmajesdown)");
	}
        w->factory(jes + "_norm[" + ySystStr.str().c_str() + "]");

        ////JER UP
        TString jer = "JER";
        TFile * fjerup = new TFile(jer + "U_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjerup = (TTree*) fjerup->Get("rds_zbb");

        nSyst = hjerup->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
	tmpYieldSyst = ySyst;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;

        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;
        RooDataSet jerupData("jerupData_dimu", "jerupData", hjerup, eventSelectionamassMu, "");
        jer = "sigPdf_dimu_"+Mass +"_"+ jer + "Up";
        if(!parametric){
        	w->import(jerupData);
	        w->factory("KeysPdf::" + jer + "(eventSelectionamassMu,jerupData_dimu)");
	} else{
		TString meanjeru,sigjeru,widthjeru;
		tmp.clear();
                tmp = fitToSignal(jerupData, eventSelectionamassMu,meanjeru,widthjeru,sigjeru);
		diffMean["JER UP"] = tmp[0].first - sigPars[0].first;
		diffWidth["JER UP"] = tmp[1].first - sigPars[1].first;
		diffSigma["JER UP"] = tmp[2].first - sigPars[2].first;
                w->factory("meanjerup["+meanjeru+"]");
                w->factory("sigmajerup["+sigjeru+"]");
                w->factory("widthjerup["+widthjeru+"]");
                w->factory("Voigtian::"+ jer +"(eventSelectionamassMu,meanjerup, widthjerup,sigmajerup)");
	}
        w->factory(jer + "_norm[" + ySystStr.str().c_str() + "]");

        ////JER DOWN
        jer = "JER";
        TFile * fjerdown = new TFile(jer + "D_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjerdown = (TTree*) fjerdown->Get("rds_zbb");

        nSyst = hjerdown->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
        //Nuisance for JER
        cout <<jer <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        systYield[jer] = yieldSystProvider(tmpYieldSyst,ySyst);

        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;

        
        RooDataSet jerdownData("jerdownData_dimu", "jerdownData", hjerdown, eventSelectionamassMu, "");
        jer = "sigPdf_dimu_"+Mass +"_"+ jer + "Down";
        if(!parametric){
        	w->import(jerdownData);
	        w->factory("KeysPdf::" + jer + "(eventSelectionamassMu,jerdownData_dimu)");
	} else{
		TString meanjerd,sigjerd,widthjerd;
		tmp.clear();
                tmp = fitToSignal(jerdownData, eventSelectionamassMu,meanjerd,widthjerd,sigjerd);
		diffMean["JER DOWN"] = tmp[0].first - sigPars[0].first;
		diffWidth["JER DOWN"] = tmp[1].first - sigPars[1].first;
		diffSigma["JER DOWN"] = tmp[2].first - sigPars[2].first;
                w->factory("meanjerdown["+meanjerd+"]");
                w->factory("sigmajerdown["+sigjerd+"]");
                w->factory("widthjerdown["+widthjerd+"]");
                w->factory("Voigtian::"+ jer +"(eventSelectionamassMu,meanjerdown, widthjerdown,sigmajerdown)");
	}
        w->factory(jer + "_norm[" + ySystStr.str().c_str() + "]");


        ////Btag UP
        TString btag = "b";
        TFile * fbtagup = new TFile(btag + "Up_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hbtagup = (TTree*) fbtagup->Get("rds_zbb");

        btag = "Btag";
        nSyst = hbtagup->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
	tmpYieldSyst = ySyst;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;
        RooDataSet btagupData("btagupData_dimu", "btagupData", hbtagup, eventSelectionamassMu, "");
        btag = "sigPdf_dimu_"+Mass +"_"+ btag + "Up";
        if(!parametric){
        	w->import(btagupData);
	        w->factory("KeysPdf::" + btag + "(eventSelectionamassMu,btagupData_dimu)");
	} else{
		TString meanbu,sigbu,widthbu;
                tmp = fitToSignal(btagupData, eventSelectionamassMu,meanbu,widthbu,sigbu);
		diffMean["Btag UP"] = tmp[0].first - sigPars[0].first;
		diffWidth["Btag UP"] = tmp[1].first - sigPars[1].first;
		diffSigma["Btag UP"] = tmp[2].first - sigPars[2].first;
                w->factory("meanbtagup["+meanbu+"]");
                w->factory("sigmabtagup["+sigbu+"]");
                w->factory("widthbtagup["+widthbu+"]");
                w->factory("Voigtian::"+ btag +"(eventSelectionamassMu,meanbtagup, widthbtagup,sigmabtagup)");
	}
        w->factory(btag + "_norm[" + ySystStr.str().c_str() + "]");

        ////Btag DOWN
        btag = "b";
        TFile * fbtagdown = new TFile(btag + "Down_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hbtagdown = (TTree*) fbtagdown->Get("rds_zbb");

        btag = "Btag";
        nSyst = hbtagdown->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
        //Nuisance for JES
        cout <<btag <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        systYield[btag] = yieldSystProvider(tmpYieldSyst,ySyst);
	cout<<btag<<": "<<nSyst<<"\t"<<nTreeSig <<endl;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;


        RooDataSet btagdownData("btagdownData_dimu", "btagdownData", hbtagdown, eventSelectionamassMu, "");
        btag = "sigPdf_dimu_"+Mass +"_"+ btag + "Down";
        if(!parametric){
        	w->import(btagdownData);
	        w->factory("KeysPdf::" + btag + "(eventSelectionamassMu,btagdownData_dimu)");
	} else{
		TString meanbd,sigbd,widthbd;
		tmp.clear();
                tmp = fitToSignal(btagdownData, eventSelectionamassMu,meanbd,widthbd,sigbd);
		diffMean["Btag DOWN"] = tmp[0].first - sigPars[0].first;
		diffWidth["Btag DOWN"] = tmp[1].first - sigPars[1].first;
		diffSigma["Btag DOWN"] = tmp[2].first - sigPars[2].first;
                w->factory("meanbtagdown["+meanbd+"]");
                w->factory("sigmabtagdown["+sigbd+"]");
                w->factory("widthbtagdown["+widthbd+"]");
                w->factory("Voigtian::"+ btag +"(eventSelectionamassMu,meanbtagdown, widthbtagdown,sigmabtagdown)");
	}
        w->factory(btag + "_norm[" + ySystStr.str().c_str() + "]");

	////Muon Up
        TString mu = "mu";
        TFile * fmuup = new TFile(mu + "u_H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hmuup = (TTree*) fmuup->Get("rds_zbb");

        mu = "Muon";
        nSyst = hmuup->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
        tmpYieldSyst = ySyst;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;
        RooDataSet muupData("muupData_dimu", "muupData", hmuup, eventSelectionamassMu, "");
        mu = "sigPdf_dimu_"+Mass +"_"+ mu + "Up";
        if(!parametric){
                w->import(muupData);
                w->factory("KeysPdf::" + mu + "(eventSelectionamassMu,muupData_dimu)");
        } else{
                TString meanmuu,sigmuu,widthmuu;
                tmp = fitToSignal(muupData, eventSelectionamassMu,meanmuu,widthmuu,sigmuu);
                diffMean["Muon UP"] = tmp[0].first - sigPars[0].first;
                diffWidth["Muon UP"] = tmp[1].first - sigPars[1].first;
                diffSigma["Muon UP"] = tmp[2].first - sigPars[2].first;
                w->factory("meanmuup["+meanmuu+"]");
                w->factory("sigmamuup["+sigmuu+"]");
                w->factory("widthmuup["+widthmuu+"]");
                w->factory("Voigtian::"+ mu +"(eventSelectionamassMu,meanmuup, widthmuup,sigmamuup)");
        }
        w->factory(mu + "_norm[" + ySystStr.str().c_str() + "]");

	////Muon DOWN
        mu= "mu";
        TFile * fmudown = new TFile(mu + "d_H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hmudown = (TTree*) fmudown->Get("rds_zbb");

        mu = "Muon";
        nSyst = hmudown->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;

        cout <<mu <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        systYield[mu] = yieldSystProvider(tmpYieldSyst,ySyst);
        cout<<mu<<": "<<nSyst<<"\t"<<nTreeSig <<endl;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;


        RooDataSet mudownData("mudownData_dimu", "mudownData", hmudown, eventSelectionamassMu, "");
        
                mu = "sigPdf_dimu_"+Mass +"_"+ mu + "Down";
        if(!parametric){
                w->import(mudownData);
                w->factory("KeysPdf::" + mu + "(eventSelectionamassMu,mudownData_dimu)");
        } else{
                TString meanmud,sigmud,widthmud;
                tmp.clear();
                tmp = fitToSignal(mudownData, eventSelectionamassMu,meanmud,widthmud,sigmud);
                diffMean["Muon DOWN"] = tmp[0].first - sigPars[0].first;
                diffWidth["Muon DOWN"] = tmp[1].first - sigPars[1].first;
                diffSigma["Muon DOWN"] = tmp[2].first - sigPars[2].first;
                w->factory("meanmudown["+meanmud+"]");
                w->factory("sigmamudown["+sigmud+"]");
                w->factory("widthmudown["+widthmud+"]");
                w->factory("Voigtian::"+ mu +"(eventSelectionamassMu,meanmudown, widthmudown,sigmamudown)");
        }
        w->factory(mu + "_norm[" + ySystStr.str().c_str() + "]");

	////PU UP
	TString pu = "pu";
        TFile * fpuup = new TFile(pu + "u_H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hpuup = (TTree*) fpuup->Get("rds_zbb");

        pu = "pu";
        nSyst = hpuup->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;
        tmpYieldSyst = ySyst;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;
        RooDataSet puupData("puupData_dimu", "puupData", hpuup, eventSelectionamassMu, "");
        pu = "sigPdf_dimu_"+Mass +"_"+ pu + "Up";
        if(!parametric){
                w->import(puupData);
                w->factory("KeysPdf::" + pu + "(eventSelectionamassMu,puupData_dimu)");
        } else{
                TString meanpuu,sigpuu,widthpuu;
                tmp = fitToSignal(puupData, eventSelectionamassMu,meanpuu,widthpuu,sigpuu);
                diffMean["Pileup UP"] = tmp[0].first - sigPars[0].first;
                diffWidth["Pileup UP"] = tmp[1].first - sigPars[1].first;
                diffSigma["Pileup UP"] = tmp[2].first - sigPars[2].first;
                w->factory("meanpuup["+meanpuu+"]");
                w->factory("sigmapuup["+sigpuu+"]");
                w->factory("widthpuup["+widthpuu+"]");
                w->factory("Voigtian::"+ pu +"(eventSelectionamassMu,meanpuup, widthpuup,sigmapuup)");
        }
        w->factory(pu + "_norm[" + ySystStr.str().c_str() + "]");

	////PU DOWN
        pu = "pu";
        TFile * fpudown = new TFile(pu + "d_H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hpudown = (TTree*) fpudown->Get("rds_zbb");

        pu = "pu";
        nSyst = hpudown->GetEntriesFast();
        ySyst = (double) nSyst / (double) nTreeSig;

        cout <<pu <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        systYield[pu] = yieldSystProvider(tmpYieldSyst,ySyst);
        cout<<pu<<": "<<nSyst<<"\t"<<nTreeSig <<endl;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout << nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst << "  " << ySystStr.str() << endl;


        RooDataSet pudownData("pudownData_dimu", "pudownData", hpudown, eventSelectionamassMu, "");
        
        pu = "sigPdf_dimu_"+Mass +"_"+ pu + "Down";
        if(!parametric){
                w->import(pudownData);
                w->factory("KeysPdf::" + pu + "(eventSelectionamassMu,pudownData_dimu)");
        } else{
                TString meanpud,sigpud,widthpud;
                tmp.clear();
                tmp = fitToSignal(pudownData, eventSelectionamassMu,meanpud,widthpud,sigpud);
                diffMean["Pileup DOWN"] = tmp[0].first - sigPars[0].first;
                diffWidth["Pileup DOWN"] = tmp[1].first - sigPars[1].first;
                diffSigma["Pileup DOWN"] = tmp[2].first - sigPars[2].first;
                w->factory("meanpudown["+meanpud+"]");
                w->factory("sigmapudown["+sigpud+"]");
                w->factory("widthpudown["+widthpud+"]");
                w->factory("Voigtian::"+ pu +"(eventSelectionamassMu,meanpudown, widthpudown,sigmapudown)");
        }
        w->factory(pu + "_norm[" + ySystStr.str().c_str() + "]");	


        //MultiPdf for background
        TFile* fbkg = new TFile("DoubleMu2012_Summer12_final_CR_" + pf + ".root", "READ");
        TTree* hbkg = (TTree*) fbkg->Get("rds_zbb");
        RooDataSet bkgData("bkgData", "bkgData", hbkg, eventSelectionamassMu, "");
        w->import(bkgData);

        RooCategory pdfindex("pdfindex","c");
        // Make a list of pdfs
        RooArgList storedPdfs("store");

        RooDataHist * dataHist = 0;
        stringstream poly;
        //PolyNomial
        TFile * fpoly = TFile::Open("ws.root");
	if(fpoly != NULL){
		cout<<"Polynomial is included"<<endl;
        	RooWorkspace * WS = (RooWorkspace*) fpoly->Get("WS");
	        dataHist = (RooDataHist*)WS->data("hist");
        	w->import(*dataHist);
        	for (int x = 0; x < 30; x++) {
	            poly.str("");
        	    poly << "PolyPdf_" << x;
	            TString PolyName = poly.str().c_str();
        	    RooPolynomial * pdf = (RooPolynomial*)WS->pdf(PolyName);
	            if (pdf == NULL)
        	        continue;
		    cout<<"************************************" <<PolyName <<" *******************"<<endl;
	            pdf->fitTo(*dataHist);
        	    storedPdfs.add(*pdf);
        	}
	}
        //Inverted PolyNomial
        TFile * finvpoly = TFile::Open("wsInv.root");
        RooWorkspace * InvWS = (RooWorkspace*) finvpoly->Get("InvWS");
        for (int x = 0; x < 30; x++) {
            poly.str("");
	    //if(x == 3)
	    //	continue;
            poly << "InvPolyPdf_" << x;
            TString PolyName = poly.str().c_str();
            RooGenericPdf * pdf = (RooGenericPdf*)InvWS->pdf(PolyName);
            if (pdf == NULL)
                continue;
	    cout<<"************************************" <<PolyName <<" *******************"<<endl;
	    if(dataHist == 0){
		dataHist = (RooDataHist*)InvWS->data("hist");
	    }
            pdf->fitTo(*dataHist);
            storedPdfs.add(*pdf);
        }

	//Chebychev in case one of the two above fail
	TFile * fcheb = TFile::Open("wsChb.root");
	if(fcheb != NULL){
		RooWorkspace * ChebWS = (RooWorkspace*) fcheb->Get("ChebWS");
	        for (int x = 0; x < 30; x++) {
	            poly.str("");
		    poly << "Chebychev_" << x;
            	    TString PolyName = poly.str().c_str();
	            RooChebychev * pdf = (RooChebychev*)ChebWS->pdf(PolyName);
        	    if (pdf == NULL)
                	continue;
		    cout<<"************************************" <<PolyName <<" *******************"<<endl;
	    	    if(dataHist == 0){
			dataHist = (RooDataHist*)ChebWS->data("hist");
	   	    }
	            pdf->fitTo(*dataHist);
        	    storedPdfs.add(*pdf);
        	}

	}
        
        RooRealVar lambda("lambda", "lambda", -10., 10.);
        RooExponential expo("expo", "expo", eventSelectionamassMu, lambda);
        expo.fitTo(*dataHist);
        storedPdfs.add(expo);
        RooMultiPdf multipdfsbkg(name+"_dimu_bkgshape","", pdfindex,storedPdfs);
        w->import(multipdfsbkg);
        TString bkgName_ = nBkg.str().c_str();
        w->factory(name+"_dimu_bkgshape_norm[" + bkgName_ + "]");

        w->writeToFile(fname);
	std::vector<std::pair<double,double> > systs;
	std::pair<double,double> ret1 = systSignalParam(diffMean);
	cout<<ret1.first<<"\t"<<ret1.second<<endl;
	systs.push_back(ret1);
	std::pair<double,double> ret11 = systSignalParam(diffWidth);
	cout<<ret11.first<<"\t"<<ret11.second<<endl;
	systs.push_back(ret11);
	std::pair<double,double> ret111 = systSignalParam(diffSigma);
	cout<<ret111.first<<"\t"<<ret111.second<<endl;
	systs.push_back(ret111);
        cardMaker(Mass, bkgUnc, sigPars, systs, systYield, binned);

	cout<<"Mean: --------------------------"<<endl;
	for (auto& x: diffMean) {
   		std::cout << x.first << ": " << x.second << '\n';
  	}
	cout<<"Width: --------------------------"<<endl;
	for (auto& x: diffWidth) {
   		std::cout << x.first << ": " << x.second << '\n';
  	}
	cout<<"Sigma: --------------------------"<<endl;
	for (auto& x: diffSigma) {
   		std::cout << x.first << ": " << x.second << '\n';
  	}
	std::pair<double,double> ret2 = systSignalParam(diffMean, false);
	cout<<ret2.first<<"\t"<<ret2.second<<endl;
    }
    return 1;
}
