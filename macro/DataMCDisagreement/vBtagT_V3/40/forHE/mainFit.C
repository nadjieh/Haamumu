
using namespace RooFit;
using namespace RooStats;
void
mainFit()
{
  double mcSU =  1351.9;
  double mcSL = 490.001;
  double dataSU = 1197;
  double dataSL = 554;
  double scaleSU = dataSU/mcSU;
  double scaleSL = dataSL/mcSL;  


  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  TString name = "test";

  TFile* f = new TFile("mcMass40.root", "READ");
  TH1D* hh = (TH1D*)f->Get("mcMass") ;
  
  int bin70 = hh->FindBin(70);
  int bin60 = hh->FindBin(60);  
  int bin50 = hh->FindBin(50);  
  int bin40 = hh->FindBin(40);
  int bin30 = hh->FindBin(30);  
  int bin20 = hh->FindBin(20);

  for(int i = 0; i < bin20; i++)
  	hh->SetBinContent(i+1, hh->GetBinContent(i+1)*scaleSL);
  	
  for(int i = bin20+1; i < bin50; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSL);  
  for(int i = bin50; i < bin70; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSL);   	
  	 	
  for(int i = bin70; i < hh->GetXaxis()->GetNbins(); i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSU); 

  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  TString title = "MC-fit";
  /*

  TFile* f = new TFile("DoubleMu2012_Summer12_final_5.root", "READ");
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  TString title = "Data-fit";  
*/


  /////////////////////
  // FIT IN SIDEBAND //
  /////////////////////
  
  TCanvas c; 
  c.SetTitle("");
  

  eventSelectionamassMu.setRange("SL", 10, 20);
  eventSelectionamassMu.setRange("SM", 30, 50);
  eventSelectionamassMu.setRange("SU", 70, 120);
  eventSelectionamassMu.setRange("SUP", 50, 120);  
  eventSelectionamassMu.setRange("SLP", 10, 30);
  eventSelectionamassMu.setRange("INT", 20, 70); 
  eventSelectionamassMu.setRange("FULL", 10, 120);  	
  
  double meanbw = 2661.71;
  double meanb = 524.043;

  //Reg. 1
  RooRealVar mean_bw(name + "_mean_bw", "Mean", 90.8, 60, 120);
  RooRealVar mean_cb(name + "_mean_cb", "Mean", 1.0, 0., 50.);
  RooRealVar sigma_bw(name + "_sigma_bw", "Width", 6.5, 1.0, 260.0);
  RooRealVar sigma_cb(name + "_sigma_cb", "Width", 2.3, 0., 260.0);
  RooRealVar n(name + "_n", "", 0.0, 5.0);
  RooRealVar alpha(name + "_alpha", "", 0.0, 5.0);
  RooRealVar lambda(name + "_lambda", "slope", -0.1, -5., 0.);
  RooRealVar s_bw(name + "_signal_bw", "signal", meanbw, 0, 4 * meanbw);
  RooRealVar s_cb(name + "_signal_cb", "signal", 100, 0, 10000);
  RooRealVar b(name + "_background", "background yield", meanb, 0, 4 * meanb);
 
  RooBreitWigner gauss_bw(name + "_gauss_bw", "gauss_bw", eventSelectionamassMu, mean_bw, sigma_bw);
  RooCBShape cball(name + "_cball", "crystal ball", eventSelectionamassMu, mean_cb, sigma_cb, alpha, n);
  RooExponential expo(name + "_expo", "exponential PDF", eventSelectionamassMu, lambda);
  RooFFTConvPdf bwxCryBall(name + "_bwxCryBall", "FFT Conv CryBall and BW", eventSelectionamassMu, gauss_bw, cball);
  RooAddPdf sum(name + "_sum", "Gaussian crystal ball and exponential PDF", RooArgList(bwxCryBall, expo), RooArgList(s_bw, b));
  
  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  sum.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SL,SU"), RooFit::Extended());  
 
  data.plotOn(xFrame) ;
  sum.plotOn(xFrame) ;
  sum.plotOn(xFrame, 
        RooFit::Components(expo), 
        RooFit::LineStyle(kDashed)) ;  
       
  
    sum.plotOn(xFrame, 
        RooFit::Components(bwxCryBall), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ;         



  xFrame->Draw();
  lambda.Print() ;
  alpha.Print() ;
  n.Print() ;
  mean_bw.Print() ;
  mean_cb.Print() ;
  sigma_bw.Print();
  sigma_cb.Print();
  s_bw.Print();
  s_cb.Print();
  b.Print();

  c.SaveAs(title+"_sideband.C");

  /// PRINT OUT OF NORMALIZATIONS
  cout<<"| | SL | SM | SU |"<<endl;
  RooAbsReal* fracInt = 0;
  cout<<"|expo | ";  
  fracInt = expo.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * b.getVal() <<" \\pm " << fracInt->getVal() * b.getError() << "|";
  double e1 = fracInt->getVal() * b.getError() ;
  fracInt = expo.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * b.getVal() <<" \\pm " << fracInt->getVal() * b.getError() << "|"; 
  double e2 = fracInt->getVal() * b.getError() ;
  fracInt = expo.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * b.getVal() <<" \\pm " << fracInt->getVal() * b.getError() << "|"<<endl; 
  double e3 = fracInt->getVal() * b.getError() ;  
  
  cout<<"|B.W | ";  
  fracInt = bwxCryBall.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * s_bw.getVal() <<" \\pm " << fracInt->getVal() * s_bw.getError() << "|";
  double e4 = fracInt->getVal() * s_bw.getError() ;
  fracInt = bwxCryBall.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * s_bw.getVal() <<" \\pm " << fracInt->getVal() * s_bw.getError() << "|"; 
  double e5 = fracInt->getVal() * s_bw.getError() ;  
  fracInt = bwxCryBall.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * s_bw.getVal() <<" \\pm " << fracInt->getVal() * s_bw.getError() << "|"<<endl; 
  double e6 = fracInt->getVal() * s_bw.getError() ;  
    
  cout<<"|Sum fit | ";  
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * (s_bw.getVal()+b.getVal()) <<" \\pm " << sqrt(pow(e1,2)+pow(e4,2)) << "|";
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * (s_bw.getVal()+b.getVal()) <<" \\pm " << sqrt(pow(e2,2)+pow(e5,2))  << "|"; 
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * (s_bw.getVal()+b.getVal()) <<" \\pm " << sqrt(pow(e3,2)+pow(e6,2))  << "|"<<endl; 
    
  cout<<"|MC Data | "<<data.sumEntries(0, "SL")<< " | " << data.sumEntries(0, "SM")<< " | " <<data.sumEntries(0, "SU")<<" |" <<endl;  
 
 ///////////// SECOND PART OF FITTING //////////
 //////////// FIT IN SIGNAL REGION, SM /////////
 
 
  TFile* ftop = new TFile("TTFullLept_Summer12_final_5.root", "READ");
  TTree* htop = (TTree*)ftop->Get("rds_zbb");
  RooDataSet topData("topData","topData",htop,eventSelectionamassMu,"");
  RooKeysPdf topPdf(name + "_toppdf", "toppdf", eventSelectionamassMu, topData);

  // SHAPE PARAMETERS FROM SIDBAND
  RooRealVar frac(name + "frac" ,"tt fraction" , 0.051,0.,1) ;
  /*double mean_bw_ = mean_bw.getVal();
  RooRealVar mean_bw_pf(name + "_mean_bw_pf", "Mean_pf", mean_bw_);
  mean_bw_pf.setConstant(kTRUE);
  double mean_cb_= mean_cb.getVal();
  RooRealVar mean_cb_pf(name + "_mean_cb_pf", "Mean_pf", mean_cb_);
  mean_cb_pf.setConstant(kTRUE);  
  double sigma_bw_ = sigma_bw.getVal();
  RooRealVar sigma_bw_pf(name + "_sigma_bw_pf", "Width_pf",sigma_bw_ );
  sigma_bw_pf.setConstant(kTRUE);    
  double sigma_cb_ = sigma_cb.getVal();
  RooRealVar sigma_cb_pf(name + "_sigma_cb_pf", "Width_pf", sigma_cb_);
  sigma_cb_pf.setConstant(kTRUE);     
  double n_ =  n.getVal();
  RooRealVar n_pf(name + "_n_pf", "_pf", n_);
  n_pf.setConstant(kTRUE);     
  double  alpha_ = alpha.getVal();
  RooRealVar alpha_pf(name + "_alpha_pf", "_pf", alpha_);
  alpha_pf.setConstant(kTRUE);    
  double   lambda_  = lambda.getVal();
  RooRealVar lambda_pf(name + "_lambda_pf", "slope_pf", lambda_);
  lambda_pf.setConstant(kTRUE);        */
  
  RooRealVar mean_bw_pf(name + "_mean_bw_pf", "Mean", 90.8, 60, 120);
  RooRealVar mean_cb_pf(name + "_mean_cb_pf", "Mean", 1.0, 0., 50.);
  RooRealVar sigma_bw_pf(name + "_sigma_bw_pf", "Width", 6.5, 1.0, 260.0);
  RooRealVar sigma_cb_pf(name + "_sigma_cb_pf", "Width", 2.3, 0., 260.0);
  RooRealVar n_pf(name + "_n_pf", "", 0.0, 5.0);
  RooRealVar alpha_pf(name + "_alpha_pf", "", 0.0, 5.0);
  RooRealVar lambda_pf(name + "_lambda_pf", "slope", -0.1, -5., 0.);
  //RooRealVar s_bw_pf(name + "_signal_bw_pf", "signal", meanbw, 0, 4 * meanbw);
  RooRealVar s_cb_pf(name + "_signal_cb_pf", "signal", 100, 0, 10000);
 // RooRealVar b_pf(name + "_background_pf", "background yield", meanb, 0, 4 * meanb);
  
  //
  
  
  RooRealVar s_bw_pf(name + "_signal_bw_pf", "signal_pf", meanbw, 0, 4 * meanbw);
  RooRealVar b_pf(name + "_background_pf", "background yield_pf", meanb, 0, 4 * meanb);
  RooRealVar frac_pf(name + "_frac_pf", "frac_pf", 0.6, 0,1); 
  RooRealVar tot(name + "_tot_pf", "tot_pf", (meanb+meanbw), 0, 4 * (meanbw+meanb));
  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, expo_pf, frac);  
  bkg.fixCoefRange("FULL") ;
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);
  RooAddPdf sum_pf(name + "_sum_norm_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, bkg), RooArgList(s_bw_pf,b_pf));
  //sum_pf_norm.fixCoefRange("FULL") ;   
  //RooExtendPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf",sum_pf_norm ,tot );

  
  
  TCanvas c2; 
  c2.SetTitle("");
  RooPlot * xFrame_pf = eventSelectionamassMu.frame(Title("SM")) ;

  sum_pf.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("FULL"), RooFit::Extended());
  
  data.plotOn(xFrame_pf) ;
  sum_pf.plotOn(xFrame_pf) ;
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(expo_pf), 
        RooFit::LineStyle(kDashed)) ;  
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(topPdf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;         
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(gauss_bw_pf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ;         

 
  xFrame_pf->Draw();


  c2.SaveAs(title+"_signal.C");
  
  
  
 /////////////// PRINT OUT
 
 

  
  cout<<"////////////////////////////////"<<endl;
  cout<<"| | SM |"<<endl;
  cout<<"|ttbar | ";  
  
  cout<<frac.getVal() * (1-frac_pf.getVal()) * tot.getVal() <<" \\pm " <<sqrt(pow(frac.getError()/frac.getVal(),2)+pow(frac_pf.getError()/(1-frac_pf.getVal()) ,2)+pow(tot.getError()/tot.getVal() ,2))* frac.getVal() * (1-frac_pf.getVal()) * tot.getVal()<< "|"<<endl; 
  cout<<"|expo | ";  
  cout<<(1 - frac.getVal()) * (1-frac_pf.getVal()) * tot.getVal() <<" \\pm " <<sqrt(pow(frac.getError()/(1 - frac.getVal()),2)+pow(frac_pf.getError()/(1-frac_pf.getVal()) ,2)+pow(tot.getError()/tot.getVal() ,2))* (1 - frac.getVal()) * (1-frac_pf.getVal()) * tot.getVal()<< "|"<<endl;     

  cout<<"|B.W_pf | ";  
  cout<<frac_pf.getVal() * tot.getVal() <<" \\pm " << sqrt(pow(frac_pf.getError()/frac_pf.getVal(),2)+pow(tot.getError()/tot.getVal() ,2))* (frac_pf.getVal()) * tot.getVal()<< "|"<<endl; 
  
  cout<<"|Sum fit_pf | ";  
  cout<<tot.getVal() <<" \\pm " << tot.getError() << "|"<<endl; 
  cout<<"|MC Data | " << data.sumEntries(0, "FULL")<< " | " <<endl;  
  
  
  
  
  
  cout<<"| | SL | SM | SU |"<<endl;
  RooAbsReal* fracInt = 0;
  cout<<"|expo | ";  
  fracInt = expo_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * b_pf.getVal() <<" \\pm " << fracInt->getVal() * b_pf.getError() << "|";
  double e1 = fracInt->getVal() * b_pf.getError() ;
  fracInt = expo_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * b_pf.getVal() <<" \\pm " << fracInt->getVal() * b_pf.getError() << "|"; 
  double e2 = fracInt->getVal() * b_pf.getError() ;
  fracInt = expo_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * b_pf.getVal() <<" \\pm " << fracInt->getVal() * b_pf.getError() << "|"<<endl; 
  double e3 = fracInt->getVal() * b_pf.getError() ;  
  
  cout<<"|B.W | ";  
  fracInt = bwxCryBall_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * s_bw_pf.getVal() <<" \\pm " << fracInt->getVal() * s_bw_pf.getError() << "|";
  double e4 = fracInt->getVal() * s_bw_pf.getError() ;
  fracInt = bwxCryBall_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * s_bw_pf.getVal() <<" \\pm " << fracInt->getVal() * s_bw_pf.getError() << "|"; 
  double e5 = fracInt->getVal() * s_bw_pf.getError() ;  
  fracInt = bwxCryBall_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * s_bw_pf.getVal() <<" \\pm " << fracInt->getVal() * s_bw_pf.getError() << "|"<<endl; 
  double e6 = fracInt->getVal() * s_bw_pf.getError() ;  
    
  cout<<"|Sum fit | ";  
  fracInt = sum_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * (s_bw_pf.getVal()+b_pf.getVal()) <<" \\pm " << sqrt(pow(e1,2)+pow(e4,2)) << "|";
  fracInt = sum_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * (s_bw_pf.getVal()+b_pf.getVal()) <<" \\pm " << sqrt(pow(e2,2)+pow(e5,2))  << "|"; 
  fracInt = sum_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * (s_bw_pf.getVal()+b_pf.getVal()) <<" \\pm " << sqrt(pow(e3,2)+pow(e6,2))  << "|"<<endl; 
    
  cout<<"|MC Data | "<<data.sumEntries(0, "SL")<< " | " << data.sumEntries(0, "SM")<< " | " <<data.sumEntries(0, "SU")<<" |" <<endl;  
  
}


