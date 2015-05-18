#include <sstream>
#include <fstream>
#include <iostream>
#include "RooCategory.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooPolynomial.h"
#include "RooRandom.h"
#include "TString.h"
#include "../interface/RooMultiPdf.h"
void cardMaker(TString mass, double bkgUnc, bool binned = false, float nSig = 0, float nBkg = 0, int ndata = 0) {
	TString outname = "hamb_shape_" + mass + "_ws.txt";
	if(binned)
		outname = "hamb_shapeBinned_" + mass + "_ws.txt";
    ofstream myfile;
    myfile.open(outname);
    myfile << "imax 1" << endl;
    myfile << "jmax 1  number of backgrounds" << endl;
    myfile << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl;
    if(!binned){
    	myfile << "\n------------" << endl;
	    myfile << "shapes\tsigPdf\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_sigPdf_dimu" << endl;
    	myfile << "shapes\tbkg\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_bkg_dimu" << endl;
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
    	myfile << "test_sigPdf_dimu_norm\tlnN\t1.3\t-" << endl;
    	//myfile << "test_bkg_dimu_norm\tlnN\t-\t" << 1 + bkgUnc << endl;
    	myfile << "test_bkg_dimu\tdiscrete" << endl;
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

int main() {
    int seed = 37;
    using namespace RooFit;
    using namespace std;
    //gSystem->Load("libHiggsAnalysisCombinedLimit.so");
    int nbin = 50;
    bool binned = false;
    stringstream nSig;
    stringstream nBkg;
    stringstream bwRatio;
    stringstream bRatio;
    stringstream mass; mass << "40";
    double bL = 20.;//std::atof(mass.str().c_str()) - 10;
    double bH = 70.;//std::atof(mass.str().c_str()) + 10;
    TString pf = "4_4";
    nSig <<3.45;
    nBkg << 552;
    double bkgUnc = 1;//(510-424.)/424.; //50%
    bwRatio << 0.2;
    bRatio << 0.8;
    stringstream range;
    range << bL << "," << bH;
    cout << "Mass: " << mass.str() << endl;
    cout << "Range: " << range.str() << endl;
    TString Range = range.str().c_str();
    TString Mass = mass.str().c_str();
    ///	Data-fit ////////////////
    TString fname = ""; 
    if(!binned)
	    fname = "hamb-shapes-UnbinnedParam-m" + Mass + "-Data-fit.root";
	else
	    fname = "hamb-shapes-BinnedParam-m" + Mass + "-Data-fit.root";		
	
	if(!binned){
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
    	TH1D * hData = data.createHistogram("data_obs",eventSelectionamassMu,Binning(nbin));
    	double frac = (double)hData->Integral()/(double)nbin;
    	nBkg.str("");
    	nBkg << hData->Integral() - (2 * frac);
    	
    	//Signal and systematics
    	TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
    	TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    	RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
    	w->import(sigData);
    	w->factory("KeysPdf::" + name + "_sigPdf_dimu(eventSelectionamassMu,sigData_dimu)");
    	w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
    	
    	////JES UP
        TString jes = "JES";
        TFile * fjesup = new TFile(jes + "U_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjesup = (TTree*) fjesup->Get("rds_zbb");

        int nSyst = hjesup->GetEntriesFast();
        double ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        stringstream ySystStr;
        ySystStr << ySyst;

        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;

        RooDataSet jesupData("jesupData_dimu", "jesupData", hjesup, eventSelectionamassMu, "");
        w->import(jesupData);
        jes = "sigPdf_dimu_" + jes + "Up";
        w->factory("KeysPdf::" + jes + "(eventSelectionamassMu,jesupData_dimu)");
        w->factory(jes+"_norm[" + ySystStr.str().c_str() + "]");

        ////JES DOWN
        jes = "JES";
        TFile * fjesdown = new TFile(jes + "D_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjesdown = (TTree*) fjesdown->Get("rds_zbb");

        nSyst = hjesdown->GetEntriesFast();
        ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;

        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;

        RooDataSet jesdownData("jesdownData_dimu", "jesdownData", hjesdown, eventSelectionamassMu, "");
        w->import(jesdownData);
        jes = "sigPdf_dimu_" + jes + "Down";
        w->factory("KeysPdf::" + jes + "(eventSelectionamassMu,jesdownData_dimu)");
        w->factory(jes+"_norm[" + ySystStr.str().c_str() + "]");

        ////JER UP
        TString jer = "JER";
        TFile * fjerup = new TFile(jer + "U_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjerup = (TTree*) fjerup->Get("rds_zbb");

        nSyst = hjerup->GetEntriesFast();
        ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;

        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;
        RooDataSet jerupData("jerupData_dimu", "jerupData", hjerup, eventSelectionamassMu, "");
        w->import(jerupData);
        jer = "sigPdf_dimu_" + jer + "Up";
        w->factory("KeysPdf::" + jer + "(eventSelectionamassMu,jerupData_dimu)");
        w->factory(jer+"_norm[" + ySystStr.str().c_str() + "]");

        ////JER DOWN
        jer = "JER";
        TFile * fjerdown = new TFile(jer + "D_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hjerdown = (TTree*) fjerdown->Get("rds_zbb");

        nSyst = hjerdown->GetEntriesFast();
        ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;

        RooDataSet jerdownData("jerdownData_dimu", "jerdownData", hjerdown, eventSelectionamassMu, "");
        w->import(jerdownData);
        jer = "sigPdf_dimu_" + jer + "Down";
        w->factory("KeysPdf::" + jer + "(eventSelectionamassMu,jerdownData_dimu)");
        w->factory(jer+"_norm[" + ySystStr.str().c_str() + "]");


        ////Btag UP
        TString btag = "b";
        TFile * fbtagup = new TFile(btag + "Up_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hbtagup = (TTree*) fbtagup->Get("rds_zbb");

        btag = "Btag";
        nSyst = hbtagup->GetEntriesFast();
        ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;
        RooDataSet btagupData("btagupData_dimu", "btagupData", hbtagup, eventSelectionamassMu, "");
        w->import(btagupData);
        btag = "sigPdf_dimu_" + btag + "Up";
        w->factory("KeysPdf::" + btag + "(eventSelectionamassMu,btagupData_dimu)");
        w->factory(btag+"_norm[" + ySystStr.str().c_str() + "]");

		////Btag DOWN
        btag = "b";
        TFile * fbtagdown = new TFile(btag + "Down_H2ToH1H1_H1To2Mu2B_mH2-125_mH1_" + Mass + "_Summer12_final_" + pf + ".root", "read");
        TTree* hbtagdown = (TTree*) fbtagdown->Get("rds_zbb");

        btag = "Btag";
        nSyst = hbtagdown->GetEntriesFast();
        ySyst = (double)nSyst/(double)nTreeSig;
        ySyst = ySyst * atof(nSig.str().c_str());
        ySystStr.str("");
        ySystStr << ySyst;
        cout<<nSig.str() << "  " << nSyst << "  " << nTreeSig << "  " << ySyst <<"  " <<ySystStr.str()<<endl;
        RooDataSet btagdownData("btagdownData_dimu", "btagdownData", hbtagdown, eventSelectionamassMu, "");
        w->import(btagdownData);
        btag = "sigPdf_dimu_" + btag + "Down";
        w->factory("KeysPdf::" + btag + "(eventSelectionamassMu,btagdownData_dimu)");
        w->factory(btag+"_norm[" + ySystStr.str().c_str() + "]");   	


		//MultiPdf for background
		TFile* fbkg = new TFile("DoubleMu2012_Summer12_final_CR_" + pf + ".root", "READ");
    	TTree* hbkg = (TTree*) fbkg->Get("rds_zbb");
	    RooDataSet bkgData("bkgData", "bkgData", hbkg, eventSelectionamassMu, "");
	    w->import(bkgData);
	    
	    RooCategory catIndex("pdfindex","c");
		// Make a list of pdfs
		RooArgList storedPdfs("store");
	    
	    //Model building and fitting
		//Pol 3
	    RooRealVar p31("p31","coeff #1", -1000, 1000.);    	
    	RooRealVar p32("p32","coeff #2", -1000, 1000.);
    	RooRealVar p33("p33","coeff #3", -1000, 1000.);
		RooPolynomial pol3("pol3","bkgd pdf", eventSelectionamassMu, RooArgList(p31, p32, p33));
		pol3->fitTo(bkgData);
		storedPdfs.add(pol3);
		
   		//Pol 4
		RooRealVar p41("p41","coeff #1", -1000, 1000.);
    	RooRealVar p42("p42","coeff #2", -1000, 1000.);
    	RooRealVar p43("p43","coeff #3", -1000, 1000.);
    	RooRealVar p44("p44","coeff #4", -1000, 1000.);
	    RooPolynomial pol4("pol4","bkgd pdf", eventSelectionamassMu, RooArgList(p41, p42, p43, p44));
	    pol4->fitTo(bkgData);
		storedPdfs.add(pol4);	
		    
	    //Pol 5
		RooRealVar p51("p51","coeff #1", -1000, 1000.);
    	RooRealVar p52("p52","coeff #2", -1000, 1000.);
    	RooRealVar p53("p53","coeff #3", -1000, 1000.);
    	RooRealVar p54("p54","coeff #4", -1000, 1000.);
    	RooRealVar p55("p55","coeff #4", -1000, 1000.);    	
	    RooPolynomial pol5("pol5","bkgd pdf", eventSelectionamassMu, RooArgList(p51, p52, p53, p54, p55));
	    pol5->fitTo(bkgData);
		storedPdfs.add(pol5);			
	    
	    //Pol 6
		RooRealVar p61("p61","coeff #1", -1000, 1000.);
    	RooRealVar p62("p62","coeff #2", -1000, 1000.);
    	RooRealVar p63("p63","coeff #3", -1000, 1000.);
    	RooRealVar p64("p64","coeff #4", -1000, 1000.);
    	RooRealVar p65("p65","coeff #4", -1000, 1000.);    	
    	RooRealVar p66("p66","coeff #4", -1000, 1000.);    	
	    RooPolynomial pol6("pol6","bkgd pdf", eventSelectionamassMu, RooArgList(p61, p62, p63, p64, p65, p66));
	    pol6->fitTo(bkgData);
		storedPdfs.add(pol6);				    
			    
	    //Pol 7
		RooRealVar p71("p71","coeff #1", -1000, 1000.);
    	RooRealVar p72("p72","coeff #2", -1000, 1000.);
    	RooRealVar p73("p73","coeff #3", -1000, 1000.);
    	RooRealVar p74("p74","coeff #4", -1000, 1000.);
    	RooRealVar p75("p75","coeff #4", -1000, 1000.);    	
    	RooRealVar p76("p76","coeff #4", -1000, 1000.);    	
    	RooRealVar p77("p77","coeff #4", -1000, 1000.);    	    	
	    RooPolynomial pol7("pol7","bkgd pdf", eventSelectionamassMu, RooArgList(p71, p72, p73, p74, p75, p76, p77));
	    pol7->fitTo(bkgData);	    
   		storedPdfs.add(pol7);				    		
   		
		RooMultiPdf multipdfsbkg("bkgshape","", catIndex,storedPdfs);
		w->factory("MultiPdf::bkgshape(catIndex,storedPdfs)");
		//w->factory("MultiPdf::multipdfsbkg(cat, {pol3,pol4})");
    	w->factory("bkgshape_norm[" + nBkg.str().c_str() + "]");

    	w->writeToFile(fname);
    	//w->var("eventSelectionamassMu")->setBins(55);
    	cardMaker(Mass, bkgUnc, binned);
	}
	return 1;
}
