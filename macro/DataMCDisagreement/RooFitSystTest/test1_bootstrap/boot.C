#include <iostream>
#include <sstream>
#include <vector>
void boot(int seed = 37){

  //**** General Settings
  using namespace RooFit;
  using namespace std;
  TString name = "test";
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRandom::randomGenerator()->SetSeed(seed);
/*  double meanbw = 2661.71;
  double meanb = 524.043;
  int nbin = 50;
  
  //**** Model construction
  //*** In real analysis eventSelectionamassMu is the dimuon inveriant mass. We hunt a bump in [20,70] GeV.
  
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
  double dy_range = 8.10450000000000017e+01; 
  double dytt_range = 4.95274000000000001e+02;
  double expo_range = 3.28866300000000024e+02;
  double sum_val = dy_range + dytt_range + expo_range;

  double frac_dy_val = dytt_range/sum_val;
  double frac_pf_val = dy_range/sum_val;  
  
  eventSelectionamassMu.setRange("INT", 20, 70);  
  
  RooRealVar mean_bw(name + "_mean_bw", "Mean", 90.8, 60, 120);
  RooRealVar mean_cb(name + "_mean_cb", "Mean", 1.0, 0., 50.);
  RooRealVar sigma_bw(name + "_sigma_bw", "Width", 4., 0.5, 10.);
  RooRealVar sigma_bwR(name + "_sigma_bwR", "Width", 2., 0.5, 10.);
  RooRealVar sigma_cb(name + "_sigma_cb", "Width", 2.3, 0., 260.0);
  RooRealVar n(name + "_n", "", 0.0, 5.0);
  RooRealVar alpha(name + "_alpha", "", 0.0, 5.0);
  RooRealVar lambda(name + "_lambda", "slope", -0.1, -5., 0.);
  RooRealVar mean_dytt(name + "_mean_dytt", "mean_dytt", 42.48403);
  RooRealVar sigma_dytt(name + "_sigma_dytt", "sigma_dytt", 9.348124);
  RooRealVar frac_dy(name + "frac_dy" ,"dytt fraction" , frac_dy_val);
  RooRealVar frac_pf(name + "_frac_pf", "frac_pf", frac_pf_val);
  
  RooBreitWigner gauss_bw(name + "_gauss_bw", "gauss_bw", eventSelectionamassMu, mean_bw, sigma_bw);
  RooCBShape cball(name + "_cball", "crystal ball", eventSelectionamassMu, mean_cb, sigma_cb, alpha, n);
  RooExponential expo(name + "_expo", "exponential PDF", eventSelectionamassMu, lambda);
  RooFFTConvPdf bwxCryBall(name + "_bwxCryBall", "FFT Conv CryBall and BW", eventSelectionamassMu, gauss_bw, cball);
  RooGaussian dytt("dytt","dytt",eventSelectionamassMu,mean_dytt,sigma_dytt); 
  RooAddPdf wobump(name + "_wobump", "wobump", RooArgList(bwxCryBall, expo), RooArgList(frac_pf));
  
  RooAddPdf sum(name + "_norm", "all", RooArgList(bwxCryBall, dytt, expo), RooArgList(frac_pf, frac_dy));
*/
  //**** Number of data events
  TRandom3 r(37);
  int nData = (int)r.Poisson(1500.);
  int nbin = 50;
 
  //**** Data generation and a nominal KeysPdf
  /*RooDataSet * data_orig = sum.generate(eventSelectionamassMu, nData);  
  data_orig->SetName("AtoyPD");
  data_orig->SetTitle("The original toy data"); 
  RooKeysPdf pdf_orig("pdf_orig","Original keyspdf",eventSelectionamassMu, *data_orig, RooKeysPdf::MirrorBoth,1);*/
  
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
  TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
  TTree * tree = (TTree*) input->Get("rds_zbb");
  int n = tree->GetEntriesFast();
  RooDataSet data("ControlData", "The original control data", tree, eventSelectionamassMu, "");
  RooKeysPdf pdf_orig("ControlPdf","Original keyspdf",eventSelectionamassMu, data, RooKeysPdf::MirrorBoth,1);
  
    
  //**** Toy MC generation based on original keyspdf

  int NPD = 100;
  RooWorkspace *w = new RooWorkspace("keyspdfs", "keyspdfs");
  stringstream s;
  for(int i = 0; i < NPD; i++){
    s.str("");
    s <<"_"<<i+1;
    TString Name = s.str().c_str();
    TString dataName = "data" + Name;    
    //*** pseudo data
    nData = (int)r.Poisson(n);
  	RooDataSet * PD = pdf_orig.generate(eventSelectionamassMu, nData);
  	PD->SetName(dataName);
  	w->import(*PD);
  	//cout<<dataName<<endl;
  	//*** unbinned shape: keyspdf
    w->factory("KeysPdf::mypdf" + Name + "(eventSelectionamassMu,"+dataName+",RooKeysPdf::MirrorBoth,1)");  	
  	    
  }
  
  w->writeToFile("keyspdfs.root");
  
 
  //**** Reading the results
  TFile * f = TFile::Open("keyspdfs.root");
  RooWorkspace *w2 = (RooWorkspace*)f->Get("keyspdfs");
  RooRealVar *var = w2->var("eventSelectionamassMu");
  stringstream s2;
  vector<RooKeysPdf*> pdfs;
  for(int i = 0; i<NPD; i++){
  	s2.str("");
  	s2 << "mypdf_" << i+1 ;
  	TString Name2 = s2.str().c_str();
  	pdfs.push_back((RooKeysPdf*)w2->pdf(Name2));  
  }
  
  
  //**** Plotting
  
  RooPlot * p3 = var->frame(Title("All KeysPdf's"), Bins(nbin));
  data->plotOn(p3, MarkerStyle(24));  
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p3, LineColor(kYellow));
  }
  data->plotOn(p3, MarkerStyle(24));  
  pdf_orig.plotOn(p3, LineColor(kRed));
  
  TCanvas chn;
  chn.cd();
  p3->Draw();
  chn.SaveAs("forhn.C");
  
    
}
