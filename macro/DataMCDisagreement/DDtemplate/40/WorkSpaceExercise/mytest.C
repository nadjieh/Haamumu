#include <sstream>
#include <fstream>
#include <iostream>

void fitToSignal(RooDataSet data, RooRealVar eventSelectionamassMu, TString & meanret, TString & widthret, TString & sigmaret, int nbin = 50){
    	TH1D * hist = (TH1D*)data.createHistogram("hist",eventSelectionamassMu,Binning(nbin));
    	RooRealVar mean("mean", "mean", hist->GetMean(), 0.8*hist->GetMean(),1.2* hist->GetMean());
    	RooRealVar sigma("sigma", "sigma",  1.,0.,2.);  
    	RooRealVar width("width", "width", hist->GetRMS(), 0.5*hist->GetRMS(), 1.5*hist->GetRMS());    	
    	RooVoigtian Voig("tmp","",eventSelectionamassMu,mean, width,sigma);    	
    	Voig.fitTo(data);
    	stringstream val;
    	val << mean.getVal();
		meanret = val.str().c_str();
		val.str("");
    	val << sigma.getVal();		
		sigmaret = val.str().c_str();
		val.str("");
    	val << width.getVal();		
		widthret = val.str().c_str();
		
    	RooRealVar mean2("mean2", "mean2", mean.getVal());
    	RooRealVar sigma2("sigma2", "sigma2", sigma.getVal());  
    	RooRealVar width2("width2", "width2", 0.3*width.getVal());  
    	RooVoigtian Voig2("tmp2","",eventSelectionamassMu,mean2, width2,sigma2);   
    	Voig2.fitTo(data);
		RooPlot * p = eventSelectionamassMu.frame();
		data.plotOn(p);
		Voig.plotOn(p, RooFit::LineColor(kRed));
		Voig2.plotOn(p);
		
		TCanvas C;
		p->Draw();
		C.SaveAs("testVoig.C");
		delete 	hist;	
}

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
    	myfile << "test_bkg_dimu_norm\tlnN\t-\t" << 1 + bkgUnc << endl;
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

void mytest(int seed = 37) {
    using namespace RooFit;
    using namespace std;
    int nbin = 50;
    bool binned = false;
    stringstream nSig;
    stringstream nBkg;
    stringstream bwRatio;
    stringstream bRatio;
    stringstream mass = "40";
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
    	TFile* fbkg = new TFile("DoubleMu2012_Summer12_final_CR_" + pf + ".root", "READ");
    	TTree* hbkg = (TTree*) fbkg->Get("rds_zbb");
	    RooDataSet bkgData("bkgData", "bkgData", hbkg, eventSelectionamassMu, "");
    	RooRandom::randomGenerator()->SetSeed(seed);
    	RooWorkspace *w = new RooWorkspace("w", "w");
    	w->factory("eventSelectionamassMu[" + Range + "]"/*,Range(SM, 50,70)"*/);
    	w->import(bkgData);
    	w->factory("KeysPdf::"+name+"_bkg_dimu(eventSelectionamassMu,bkgData)");

    	TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
    	TTree* hh = (TTree*) f->Get("rds_zbb");
    	RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
    	w->import(data);
    	TH1D * hData = data.createHistogram("data_obs",eventSelectionamassMu,Binning(nbin));
    	double frac = (double)hData->Integral()/(double)nbin;
    	nBkg.str("");
    	nBkg << hData->Integral() - (5 * frac);

    	TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
    	TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    	RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
    	TString meanval,sigval,widthval;
    	fitToSignal(sigData, eventSelectionamassMu,meanval,widthval, sigval);
    	w->factory("mean["+meanval+"]");	
    	w->factory("sigma["+sigval+"]");	
    	w->factory("width["+widthval+"]");	
    	w->factory("Voigtian::"+name + "_sigPdf_dimu(eventSelectionamassMu,mean, width,sigma)");    	    	
    	cout<<meanval <<"\t"<<widthval<<"\t"<<sigval<<endl;
    	w->factory(name + "_bkg_dimu_norm[" + nBkg.str().c_str() + "]");
    	w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
   	
    	w->writeToFile(fname);
    	//w->var("eventSelectionamassMu")->setBins(55);
    	cardMaker(Mass, bkgUnc, binned);
		
	} else {
        RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", bL, bH);
    	TFile* fbkg = new TFile("DoubleMu2012_Summer12_final_CR_" + pf + ".root", "READ");
    	TTree* hbkg = (TTree*) fbkg->Get("rds_zbb");
    	RooDataSet bkgData("bkgData", "bkgData", hbkg, eventSelectionamassMu, "");
    	TH1D * hbkgData = bkgData.createHistogram("bkg",eventSelectionamassMu,Binning(nbin));
    	hbkgData->SetName("bkg");
	    TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
    	TTree* hh = (TTree*) f->Get("rds_zbb");
    	RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
    	TH1D * hData = data.createHistogram("data_obs",eventSelectionamassMu,Binning(nbin));
    	int nData = hData->Integral();
    	double frac = (double)hData->Integral()/(double)nbin;
    	nBkg.str("");
    	nBkg << hData->Integral() - (5 * frac);
    	hData->SetName("data_obs");
   		TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
    	TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    	RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
	    TH1D * hsigData = sigData.createHistogram("signal",eventSelectionamassMu,Binning(nbin));
	    hsigData->SetName("signal");
	    
	    hbkgData->Scale(std::atof(nBkg.str().c_str())/hbkgData->Integral());
	    hsigData->Scale(std::atof(nSig.str().c_str())/hsigData->Integral());
	    	    
		TFile * fOut = new TFile(fname,"recreate");
		fOut->mkdir("dimu")->cd();
		hData->Write();
		hbkgData->Write();
		hsigData->Write();
		fOut->cd();
		fOut->Close();
	    cardMaker(Mass, bkgUnc, binned, std::atof(nSig.str().c_str()), std::atof(nBkg.str().c_str()), nData);
	}
}
