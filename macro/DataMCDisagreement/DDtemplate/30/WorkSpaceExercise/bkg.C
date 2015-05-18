#include <sstream>
#include <fstream>
#include <iostream>


void bkg(int seed = 37) {
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
    	
    	RooKeysPdf bkg1("bkg1","nominal (1)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 1);
    	RooKeysPdf bkg05("bkg05","doen (0.5)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 0.5);
    	RooKeysPdf bkg2("bkg2","up (2)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 2);
    	RooKeysPdf bkg03("bkg03","down (0.3)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 0.3);
    	RooKeysPdf bkg3("bkg3","up (3)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 3);   
    	RooKeysPdf bkg02("bkg04","down (0.2)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 0.2);
    	RooKeysPdf bkg4("bkg4","up (4)",eventSelectionamassMu, bkgData,RooKeysPdf::MirrorBoth, 4);        	 	
    	
    	RooPlot * p =    eventSelectionamassMu.frame(RooFit::Title("#rho =  0.5, 1, 2"),RooFit::Bins(nbin));	
    	bkgData.plotOn(p,RooFit::MarkerStyle(24));
    	bkg1.plotOn(p, RooFit::LineColor(kRed));
    	bkg05.plotOn(p, RooFit::LineColor(kGreen));    	
    	bkg2.plotOn(p, RooFit::LineColor(kBlue)); 
    	
        RooPlot * p2 =    eventSelectionamassMu.frame(RooFit::Title("#rho =  0.3, 1, 3"),RooFit::Bins(nbin));	
    	bkgData.plotOn(p2,RooFit::MarkerStyle(24));
    	bkg1.plotOn(p2, RooFit::LineColor(kRed));
    	bkg03.plotOn(p2, RooFit::LineColor(kGreen));    	
    	bkg3.plotOn(p2, RooFit::LineColor(kBlue));      	
    	  
    	
        RooPlot * p3 =    eventSelectionamassMu.frame(RooFit::Title("#rho =  0.2, 1, 4"),RooFit::Bins(nbin));	
    	bkgData.plotOn(p3,RooFit::MarkerStyle(24));
    	bkg1.plotOn(p3,RooFit::FillColor(kWhite), RooFit::LineColor(kRed));
    	bkg02.plotOn(p3,RooFit::FillColor(kWhite), RooFit::LineColor(kGreen)/*, RooFit::LineStyle(kDashed)*/);    	
    	bkg4.plotOn(p3,RooFit::FillColor(kWhite), RooFit::LineColor(kBlue) /*, RooFit::LineStyle(kDashed)*/);  
    	
    	   	
    	TCanvas Can;
    	Can.Divide(3,1);
    	Can.cd(1);
    	p->Draw();  	
    	Can.cd(2);
    	p2->Draw();
    	Can.cd(3);
    	p3->Draw();
    	Can.SaveAs("bkgtemp.C");
    	
    	TFile* fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-30_Summer12_final_3_4.root", "READ");
     	TTree* hsig = (TTree*) fsig->Get("rds_zbb");  
	    RooDataSet sigData("sigData", "sigData", hsig, eventSelectionamassMu, "");   
	    RooKeysPdf sig1("sig1","Signal CR",eventSelectionamassMu, sigData,RooKeysPdf::MirrorBoth, 1);  
	    double nbkg = hbkg->GetEntriesFast();
	    double nsig = 0.2183*3.35;
	    RooRealVar frac("frac","frac", (nsig/nbkg));	 	
	    RooAddPdf sum("sum","sum nominal",RooArgList(sig1,bkg1), RooArgList(frac));
	    RooPlot * p4 =    eventSelectionamassMu.frame(RooFit::Title("Signal + Background"),RooFit::Bins(nbin));	
   	    bkgData.plotOn(p4,RooFit::MarkerStyle(24));
	    sum.plotOn(p4,RooFit::FillColor(kWhite), RooFit::LineColor(kRed));
	    bkg05.plotOn(p4, RooFit::LineColor(kGreen));    	
    	bkg2.plotOn(p4, RooFit::LineColor(kBlue)); 
    	
    	RooPlot * p5 =    eventSelectionamassMu.frame(RooFit::Title("Signal + Background"),RooFit::Bins(nbin));	
    	bkgData.plotOn(p5,RooFit::MarkerStyle(24));
    	sum.plotOn(p5, RooFit::LineColor(kRed));
    	bkg03.plotOn(p5, RooFit::LineColor(kGreen));    	
    	bkg3.plotOn(p5, RooFit::LineColor(kBlue));      	
    	  
    	
        RooPlot * p6 =    eventSelectionamassMu.frame(RooFit::Title("Signal + Background"),RooFit::Bins(nbin));	
    	bkgData.plotOn(p6,RooFit::MarkerStyle(24));
    	sum.plotOn(p6,RooFit::FillColor(kWhite), RooFit::LineColor(kRed));
    	bkg02.plotOn(p6,RooFit::FillColor(kWhite), RooFit::LineColor(kGreen)/*, RooFit::LineStyle(kDashed)*/);    	
    	bkg4.plotOn(p6,RooFit::FillColor(kWhite), RooFit::LineColor(kBlue) /*, RooFit::LineStyle(kDashed)*/);  
    	
	    TCanvas Can2;
		Can2.Divide(3,1);
    	Can2.cd(1);
	    p4->Draw();
	    Can2.cd(2);
    	p5->Draw();
    	Can2.cd(3);
    	p6->Draw();
	    Can2.SaveAs("sumtemp.C");

	} 
}
