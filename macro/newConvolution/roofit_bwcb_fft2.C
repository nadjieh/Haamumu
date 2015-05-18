void roofit_bwcb_fft2(){

  gSystem->Load("libRooFit") ;
  using namespace RooFit ;
  
  RooRealVar x1("x1","x symmetric ",70000,110000);
  RooRealVar x2("x2","x symmetric ",60000,120000);
  RooRealVar x3("x3","x asymmetric",60000,150000);
  RooRealVar x4("x4","x asymmetric",70000,120000);
  
  RooRealVar sigma("sigma", "BW sigma (GeV)"  	   ,2490);  
  RooRealVar avg("avg",	    "BW avg (GeV)"	   ,91153.);
  
  RooRealVar CBmean("CBmean",  	"CBmean"       	,0.);
  RooRealVar CBsigma("CBsigma",	"CBsigma"	,2000);   
  RooRealVar CBalpha("CBalpha",	"CBalpha"	,1.);	
  RooRealVar CBn("CBn",		"CBn"		,5.);        
  
  RooBreitWigner BW1("BW1","Breit Wigner theory",x1,avg,sigma);
  RooCBShape cryBall1("cryBall1","Crystal Ball resolution model", x1, CBmean, CBsigma, CBalpha, CBn) ;
  RooFFTConvPdf bwxCryBall1("bwxCryBall1", "FFT Conv CryBall and BW", x1, BW1, cryBall1); 
  
  RooBreitWigner BW2("BW2","Breit Wigner theory",x2,avg,sigma);
  RooCBShape cryBall2("cryBall2","Crystal Ball resolution model", x2, CBmean, CBsigma, CBalpha, CBn) ;
  RooFFTConvPdf bwxCryBall2("bwxCryBall2", "FFT Conv CryBall and BW", x2, BW2, cryBall2); 
  
  RooBreitWigner BW3("BW3","Breit Wigner theory",x3,avg,sigma);
  RooCBShape cryBall3("cryBall3","Crystal Ball resolution model", x3, CBmean, CBsigma, CBalpha, CBn) ;
  RooFFTConvPdf bwxCryBall3("bwxCryBall3", "FFT Conv CryBall and BW", x3, BW3, cryBall3); 
  
  RooBreitWigner BW4("BW4","Breit Wigner theory",x4,avg,sigma);
  RooCBShape cryBall4("cryBall4","Crystal Ball resolution model", x4, CBmean, CBsigma, CBalpha, CBn) ;
  RooFFTConvPdf bwxCryBall4("bwxCryBall4", "FFT Conv CryBall and BW", x4, BW4, cryBall4); 
  
  RooPlot* plot_sym1  = x1.frame(Range(70000,110000));
  RooPlot* plot_sym2  = x2.frame(Range(70000,110000));
  RooPlot* plot_asym1 = x3.frame(Range(70000,110000));  
  RooPlot* plot_asym2 = x4.frame(Range(70000,110000));
  
  bwxCryBall1.plotOn(plot_sym1,LineColor(kRed));
  bwxCryBall2.plotOn(plot_sym2,LineColor(kGreen));
  bwxCryBall3.plotOn(plot_asym1,LineColor(kBlack));
  bwxCryBall4.plotOn(plot_asym2);
  
  TCanvas *c1 = new TCanvas("c1","c1",800, 800);
  
  plot_sym1->Draw();  
  plot_sym2->Draw("SAME");
  plot_asym1->Draw("SAME");
  plot_asym2->Draw("SAME");
  
}

