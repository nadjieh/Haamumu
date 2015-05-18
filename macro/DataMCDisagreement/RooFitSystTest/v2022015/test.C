#include <iostream>
#include <sstream>
#include <vector>
#define RANGE
void test(int seed = 37){

  //**** General Settings
  using namespace RooFit;
  using namespace std;
  TString name = "test";
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRandom::randomGenerator()->SetSeed(seed);
  double meanbw = 2661.71;
  double meanb = 524.043;
  int nbin = 50;
  
  //**** PDF definition in full range
  #ifdef FULL
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  double frac_dy_val = 0.1;
  double frac_pf_val = 0.72;
  #endif /*FULL*/
  
  #ifdef RANGE
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
  double dy_range = 8.10450000000000017e+01; 
  double dytt_range = 4.95274000000000001e+02;
  double expo_range = 3.28866300000000024e+02;
  double sum_val = dy_range + dytt_range + expo_range;

  double frac_dy_val = dytt_range/sum_val;
  double frac_pf_val = dy_range/sum_val;  
  #endif /*RANGE*/  
  
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
  /*
  RooRealVar mean_bw(name + "_mean_bw", "Mean", 90.858);
  RooRealVar mean_cb(name + "_mean_cb", "Mean", 0.638953);
  RooRealVar sigma_bw(name + "_sigma_bw", "Width", 0.5);
  RooRealVar sigma_cb(name + "_sigma_cb", "Width", 0.206847);
  RooRealVar n(name + "_n", "", 0.766);
  RooRealVar alpha(name + "_alpha", "", 0.341);
  RooRealVar lambda(name + "_lambda", "slope", -0.069);*/
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
  
  /*
   * Contributions to total
   * dytt = frac_dy = 0.1
   * expo = 0.9*0.2 = 0.18
   * bwxCB = 0.9*0.8 = 0.72
   */
  
  RooAddPdf sum(name + "_norm", "all", RooArgList(bwxCryBall, dytt, expo), RooArgList(frac_pf, frac_dy));
 
  #ifdef FULL
  RooAbsReal * integExpo = expo.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "INT");
  RooAbsReal * integDytt = dytt.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "INT");  
  RooAbsReal * integBwxCryBall = bwxCryBall.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "INT");  
  RooAbsReal * integSum = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "INT");    
    
  cout<<integExpo->getVal()<<"\t"<<integDytt->getVal()<<"\t"<<integBwxCryBall->getVal()<<"\t"<<integSum->getVal()<<endl;
  
  RooPlot * p = eventSelectionamassMu.frame(Title("Original pdf"), Bins(nbin));  
  sum.plotOn(p);
  TCanvas c;
  c.cd();
  p->Draw();
  c.SaveAs("OriginalPDF.C");
  
  #endif
  
  //*** Toy MC generation

  RooWorkspace *w = new RooWorkspace("w", "w");
  stringstream s;
  std::vector<TH1D*> histograms;
  for(int i = 0; i < 100; i++){
    s.str("");
    s <<"_"<<i+1;
    TString Name = s.str().c_str();
    TString dataName = "data" + Name;    
  	RooDataSet * PD = sum.generate(eventSelectionamassMu, 1500);
  	PD->SetName(dataName);
  	w->import(*PD);
    w->factory("KeysPdf::mypdf" + Name + "(eventSelectionamassMu,"+dataName+",RooKeysPdf::MirrorBoth,1)");  	
    
  	TString hName = "hist_"+dataName;
  	histograms.push_back((TH1D*)PD->createHistogram(hName,eventSelectionamassMu,Binning(50)));
  	    
  }
  
  w->writeToFile("a.root");
  
  TFile * h = new TFile("b.root","recreate");
  h->cd();
  for(unsigned int j = 0; j < histograms.size(); j++){
  	histograms[j]->SetStats(kFALSE);
  	histograms[j]->SetTitle("");
  	histograms[j]->SetLineColor(kYellow);
  	histograms[j]->SetMarkerColor(kYellow);  	
 	histograms[j]->Write(); 
  }
  h->Close();
  cout<<histograms[0]<<endl;
  
  #ifdef FULL
  cout<<PD->sumEntries(0,"INT")<<endl;
  #endif
  
  //*** Reading the results
  TFile * f = TFile::Open("a.root");
  RooWorkspace *w2 = (RooWorkspace*)f->Get("w");
  RooRealVar *var = w2->var("eventSelectionamassMu");
  stringstream s2;
  vector<RooKeysPdf*> pdfs;
  for(int i = 0; i<100; i++){
  	s2.str("");
  	s2 << "mypdf_" << i+1 ;
  	TString Name2 = s2.str().c_str();
  	pdfs.push_back((RooKeysPdf*)w2->pdf(Name2));  
  }
  
  
  //*** Generating a nominal data set and different kespdfs
  RooDataSet * myPD = sum.generate(eventSelectionamassMu, 1500);
  myPD->SetName("AtoyPD");
  myPD->SetTitle("A toy PD");  
  RooKeysPdf pdf1("pdf1","nominal (1)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,1);
  
  RooKeysPdf pdf2("pdf2","up (2)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,2);
  RooKeysPdf pdf3("pdf3","up (2)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,3);
  RooKeysPdf pdf4("pdf4","up (4)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,4);
  
  RooKeysPdf pdf05("pdf05","down (0.5)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,0.5);  
  RooKeysPdf pdf03("pdf03","down (0.33)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,0.33);  
  RooKeysPdf pdf02("pdf02","down (0.25)", eventSelectionamassMu, *myPD, RooKeysPdf::MirrorBoth,0.25);    

  
  RooPlot * p = var->frame(Title("All KeysPdf's"), Bins(nbin));
  myPD->plotOn(p, MarkerStyle(24));  
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p, LineColor(kYellow));
  }
  myPD->plotOn(p, MarkerStyle(24));  
  pdf1.plotOn(p, LineColor(kRed));
  pdf2.plotOn(p, LineColor(kGreen));
  pdf05.plotOn(p, LineColor(kBlue));  
    
  RooPlot * p2 = var->frame(Title("All KeysPdf's"), Bins(nbin));
  myPD->plotOn(p2, MarkerStyle(24));  
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p2, LineColor(kYellow));
  }
  myPD->plotOn(p2, MarkerStyle(24));  
  pdf1.plotOn(p2, LineColor(kRed));
  pdf3.plotOn(p2, LineColor(kGreen));
  pdf03.plotOn(p2, LineColor(kBlue));    
      
  RooPlot * p3 = var->frame(Title("All KeysPdf's"), Bins(nbin));
  myPD->plotOn(p3, MarkerStyle(24));  
  for(int i = 0; i<pdfs.size(); i++){
  	pdfs[i]->plotOn(p3, LineColor(kYellow));
  }
  myPD->plotOn(p3, MarkerStyle(24));  
  pdf1.plotOn(p3, LineColor(kRed));
  pdf4.plotOn(p3, LineColor(kGreen));
  pdf02.plotOn(p3, LineColor(kBlue));    
  TCanvas c;
  c.Divide(3,1);
  c.cd(1);
  p->Draw();
  c.cd(2);
  p2->Draw();
  c.cd(3);
  p3->Draw();
  c.SaveAs("band.C");
  
  //**** Compared with binned version
  
  //** Nominal histogram
  TH1D* hdata = myPD->createHistogram("hdata", *var,Binning(50)); 
  hdata->SetLineColor(kRed);
  hdata->SetFillStyle(0);  
  
  //** Systematics 
  vector<double> min;
  vector<double> max;
  
  for(int iBin = 0; iBin < hdata->GetXaxis()->GetNbins(); iBin++){
  	double mymin = 10000;
  	double mymax = -10;
  	for(int i = 0; i<histograms.size(); i++){
  		if(histograms[i]->GetBinContent(iBin+1) > mymax)
  			mymax = histograms[i]->GetBinContent(iBin+1);
		if(histograms[i]->GetBinContent(iBin+1) < mymin)
			mymin = histograms[i]->GetBinContent(iBin+1);
	}
	min.push_back(mymin);
	max.push_back(mymax);	
  }
  
  //* Band
  TH1D * hband = new TH1D("hband","Expected 68%", histograms[0]->GetXaxis()->GetNbins(), histograms[0]->GetXaxis()->GetXmin() ,histograms[0]->GetXaxis()->GetXmax());
  hband->SetLineColor(kYellow);
  hband->SetLineWidth(2);  
  hband->SetFillColor(kYellow);  
 
  for(int iBin = 0; iBin < hdata->GetXaxis()->GetNbins(); iBin++){
  	hband->SetBinContent(iBin+1,(min[iBin]+max[iBin])/2);
  	hband->SetBinError(iBin+1,(max[iBin] - ((min[iBin]+max[iBin])/2)));
  }

  TCanvas c2;
  c2.cd();

  for(int i = 0; i<histograms.size(); i++){
  	if(i == 0)
  		histograms[i]->Draw("E2");
  	else
  		histograms[i]->Draw("E2SAMES");
  }
  hband->Draw("E2SAME");
  
  //* Minimum
  TH1D * hmin = new TH1D("hmin","down (-1 #sigma)", histograms[0]->GetXaxis()->GetNbins(), histograms[0]->GetXaxis()->GetXmin() ,histograms[0]->GetXaxis()->GetXmax());
  hmin->SetLineColor(kBlue);
  hmin->SetLineWidth(2);  
  for(int iBin = 0; iBin < hdata->GetXaxis()->GetNbins(); iBin++){
  	hmin->SetBinContent(iBin+1, hdata->GetBinContent(iBin+1) - hdata->GetBinError(iBin+1));
  }  
    
  //* Maximum
  TH1D * hmax = new TH1D("hmax","up (+1 #sigma)", histograms[0]->GetXaxis()->GetNbins(), histograms[0]->GetXaxis()->GetXmin() ,histograms[0]->GetXaxis()->GetXmax());
  hmax->SetLineColor(kGreen);
  hmax->SetLineWidth(2);    
  for(int iBin = 0; iBin < hdata->GetXaxis()->GetNbins(); iBin++){
  	hmax->SetBinContent(iBin+1, hdata->GetBinContent(iBin+1) + hdata->GetBinError(iBin+1));
  }  
  
  hmax->Draw("SAME");
  hmin->Draw("SAME");
  c2.SaveAs("hist2.C");
  hdata->Draw("E2SAME");

  c2.SaveAs("hist.C");
  
}
