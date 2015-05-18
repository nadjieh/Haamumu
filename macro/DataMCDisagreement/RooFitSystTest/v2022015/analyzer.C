#include <iostream>
#include <sstream>
#include <vector>
void analyzer(int seed = 37){

  //**** General Settings
  using namespace RooFit;
  using namespace std;
  TString name = "test";
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRandom::randomGenerator()->SetSeed(seed);

  //**** Reading file
  TFile * f = TFile::Open("a.root");
  RooWorkspace *w = (RooWorkspace*)f->Get("w");
  RooRealVar *var = w->var("eventSelectionamassMu");
  stringstream s;
  vector<RooKeysPdf*> pdfs;
  for(int i = 0; i<100; i++){
  	s.str("");
  	s << "mypdf_" << i+1 ;
  	TString Name = s.str().c_str();
  	pdfs.push_back((RooKeysPdf*)w->pdf(Name));  
  }
  
  RooPlot * p = var->frame(Title("All KeysPdf's"));
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p, LineColor(kYellow));
  }
  
  TCanvas c;
  c.cd();
  p->Draw();
  c.SaveAs("band.C");
}
