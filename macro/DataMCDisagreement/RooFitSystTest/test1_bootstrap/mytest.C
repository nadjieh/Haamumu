#include <iostream>
#include <sstream>
#include <vector>
void mytest(int seed = 37){
  int npd = 101;
  //**** General Settings
  using namespace RooFit;
  using namespace std;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);  
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRandom::randomGenerator()->SetSeed(seed);
  vector<RooKeysPdf*> pdfs;
  int nbin = 50;
  TString s1 = "hamb-shapes-UnbinnedParam-m40-Data-fit-";
  TString s2 = ".root";
  RooRealVar *var = 0;//w->var("eventSelectionamassMu");
  for(int i = 1; i < npd; i++){
	stringstream S;
	S << s1 << i << s2;
	cout<<S.str()<<endl;
	TFile * f = TFile::Open(S.str().c_str());
	cout<<f->GetName()<<endl;
	f->ls();
	RooWorkspace *w = (RooWorkspace*)f->Get("w");
	//var = w->var("eventSelectionamassMu");
    pdfs.push_back((RooKeysPdf*)w->pdf("test_bkg_dimu"));  
  }

  //**** Read data
  TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
  TTree * tree = (TTree*) input->Get("rds_zbb");
  RooDataSet data("ControlData", "The original control data", tree, eventSelectionamassMu, "");
  RooKeysPdf pdf_orig("ControlPdf","Original keyspdf",eventSelectionamassMu, data, RooKeysPdf::MirrorBoth,1);  
  //**** Plotting
  
  RooPlot * p3 = eventSelectionamassMu.frame(Title("All KeysPdf's"), Bins(nbin));
  data.plotOn(p3, MarkerStyle(24));  
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p3, LineColor(kYellow));
  }
  pdf_orig.plotOn(p3, LineColor(kRed));
  data.plotOn(p3, MarkerStyle(24));    
  TCanvas chn;
  chn.cd();
  p3->Draw();
  chn.SaveAs("post-forhn.C");
  
    
}
