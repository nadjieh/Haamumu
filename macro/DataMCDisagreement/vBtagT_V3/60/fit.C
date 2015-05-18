
using namespace RooFit;
using namespace RooStats;
void
fit()
{
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  TString name = "test";
  double mcSU =  2315.49;
  double mcSL = 294.562;
  double dataSU = 2118;
  double dataSL = 249;
  double scaleSU = dataSU/mcSU;
  double scaleSL = dataSL/mcSL;  
  cout<<"scaleSU: "<<scaleSU<<endl;
  cout<<"scaleSL: "<<scaleSL<<endl;  
  
  TFile* f = new TFile("mcMass60.root", "READ");
  TH1D* hh = (TH1D*)f->Get("mcMass") ;
  int bin70 = hh->FindBin(70);
  int bin60 = hh->FindBin(60);  
  int bin50 = hh->FindBin(50);  
  int bin40 = hh->FindBin(40);
  int bin30 = hh->FindBin(30);  
  int bin20 = hh->FindBin(20);
  
  for(int i = 0; i < bin20; i++)
  	hh->SetBinContent(i+1, hh->GetBinContent(i+1)*scaleSL);
  	
  for(int i = bin50; i < bin70; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSU);  	
  	
  for(int i = bin70; i < hh->GetXaxis()->GetNbins(); i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSU);  	
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  TString title = "MC-fit";
  
 /* TFile* f = new TFile("DoubleMu2012_Summer12_final_7.root", "READ");
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
  eventSelectionamassMu.setRange("SLP", 10, 50);  
  eventSelectionamassMu.setRange("SM", 50, 70);
  eventSelectionamassMu.setRange("SU", 70, 120);


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
        RooFit::Components(cball), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;         
  
    sum.plotOn(xFrame, 
        RooFit::Components(gauss_bw), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ;         
   
  sum.paramOn(xFrame,Layout(0.65), 
         Format("NEU", AutoPrecision(1)), 
         Parameters( RooArgList(s_bw, s_cb, b, mean_bw, mean_cb, sigma_bw/*,width*/, sigma_cb )));


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

  c.SaveAs(title+"plot2.C");
  cout<<"/////////// "<<title<<" ////////////////"<<endl;
  cout<<"//// Tstring fname = \"hamb-shapes-UnbinnedParam-m60-"<<title<<".root\";"<<endl;  
  cout<<"//// stringstream lambda; lambda << "<<lambda.getVal()<<";"<<endl;
  cout<<"//// stringstream alpha; alpha << "<<alpha.getVal()<<";"<<endl;  
  cout<<"//// stringstream n; n <<  "<<n.getVal()<<";"<<endl;  
  cout<<"//// stringstream meanbw; meanbw <<  "<<mean_bw.getVal()<<";"<<endl;  
  cout<<"//// stringstream sigmabw; sigmabw <<  "<<sigma_bw.getVal()<<";"<<endl;    
  cout<<"//// stringstream meancb; meancb <<  "<<mean_cb.getVal()<<";"<<endl;  
  cout<<"//// stringstream sigmacb; sigmacb <<  "<<sigma_cb.getVal()<<";"<<endl;      
  cout<<"///////////////////////////////////"<<endl;
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
 
 
  TFile* ftop = new TFile("TTFullLept_Summer12_final_7.root", "READ");
  TTree* htop = (TTree*)ftop->Get("rds_zbb");
  RooDataSet topData("topData","topData",htop,eventSelectionamassMu,"");
  RooKeysPdf topPdf(name + "_toppdf", "toppdf", eventSelectionamassMu, topData);
  //double meantt = 55.8325;
  //RooRealVar ttCont(name + "_ttCont", "ttCont", meantt, 0., 4 * meantt);
  RooRealVar frac(name + "frac" ,"tt fraction" , 0.5,0.0, 1.0) ;
  double mean_bw_ = mean_bw.getVal();
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
  lambda_pf.setConstant(kTRUE);        
  RooRealVar s_bw_pf(name + "_signal_bw_pf", "signal_pf", meanbw, 0, 4 * meanbw);
  RooRealVar b_pf(name + "_background_pf", "background yield_pf", meanb, 0, 4 * meanb);

  RooRealVar frac_pf(name + "_frac_pf", "frac_pf", 0.5,0.,1.0);
  RooRealVar tot(name + "_tot_pf", "tot_pf", (meanb+meanbw), 0, 4 * (meanbw+meanb));
  
  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, expo_pf, frac);  
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);

  RooAddPdf sum_pf_norm(name + "_sum_norm_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, bkg), RooArgList(frac_pf));
  RooExtendPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf",sum_pf_norm ,tot );
  TCanvas c2; 
  c2.SetTitle("");
  RooPlot * xFrame_pf = eventSelectionamassMu.frame(Title("SM")) ;

  sum_pf.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SM"), RooFit::Extended());
  
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

  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(topPdf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ; 
  sum_pf.paramOn(xFrame_pf,Layout(0.65), 
         Format("NEU", AutoPrecision(1)), 
         Parameters( RooArgList(s_bw_pf, /*ttCont,*/ b_pf, mean_bw_pf, mean_cb_pf, sigma_bw_pf/*,width*/, sigma_cb_pf )));
  xFrame_pf->Draw();


  c2.SaveAs(title+"plot2_pf.C");
  
  
  
 ///////////////
 
 

  
  cout<<"////////////////////////////////"<<endl;
  cout<<"| | SM |"<<endl;
  cout<<"|bkg | ";  
  fracInt = bkg.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * b_pf.getVal() <<" \\pm " << fracInt->getVal() * b_pf.getError() << "|"<<endl; 
  double E1 = fracInt->getVal() * b_pf.getError() ;
  
  cout<<"|B.W_pf | ";  
  fracInt = bwxCryBall_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * s_bw_pf.getVal() <<" \\pm " << fracInt->getVal() * s_bw_pf.getError() << "|"<<endl; 
  double E2 = fracInt->getVal() * s_bw_pf.getError() ; 
  
  /*cout<<"|ttCont_pf | ";  
  fracInt = topPdf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * ttCont.getVal() <<" \\pm " << fracInt->getVal() * ttCont.getError() << "|"<<endl; 
  double E3 = fracInt->getVal() * ttCont.getError() ;   */
      
  cout<<"|Sum fit_pf | ";  
  fracInt = sum_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * (s_bw_pf.getVal()+b_pf.getVal()/*+ttCont.getVal()*/) <<" \\pm " << sqrt(pow(E1,2)+pow(E2,2)/*+pow(E3,2)*/)  << "|"<<endl; 
  cout<<tot.getVal()<<" \\pm " << tot.getError()  << "|"<<endl; 
  cout<<"|MC Data | " << data.sumEntries(0, "SM")<< " | " <<endl;  
  
     /////////////////////  DETERMINE THE NORMALIZATION FROM DATA //////////////
  RooRealVar s_bw_norm(name + "_signal_bw_norm", "signal_pf", meanbw, 0, 4 * meanbw);
  RooRealVar b_norm(name + "_background_norm", "background yield_pf", meanb, 0, 4 * meanb);  
  RooBreitWigner gauss_bw_norm(name + "_gauss_bw_norm", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_norm(name + "_cball_norm", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_norm(name + "_expo_norm", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg_norm(name+"_bkg_norm", "all bkgs",topPdf, expo_norm, frac);  
  RooFFTConvPdf bwxCryBall_norm(name + "_bwxCryBall_norm", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);
  RooAddPdf sum_norm(name + "_sum_norm", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_norm, bkg_norm), RooArgList(s_bw_norm, b_norm));
  sum_norm.fitTo(data, RooFit::Save(kTRUE), RooFit::Range("SLP,SU"),RooFit::Extended());
  cout<<"////////////// NORMALIZATION /////////////"<<endl;
  cout<<"| | SLP | SM | SU |"<<endl;
  cout<<"|bkg | ";  
  fracInt = bkg_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SLP");
  cout<<fracInt->getVal() * b_norm.getVal() <<" \\pm " << fracInt->getVal() * b_norm.getError() << "|"; 
  double L1 = fracInt->getVal() * b_norm.getError() ;
  fracInt = bkg_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * b_norm.getVal() <<" \\pm " << fracInt->getVal() * b_norm.getError() << "|"; 
  double M1 = fracInt->getVal() * b_norm.getError() ;
  fracInt = bkg_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * b_norm.getVal() <<" \\pm " << fracInt->getVal() * b_norm.getError() << "|"<<endl; 
  double U1 = fracInt->getVal() * b_norm.getError() ;  
  
  cout<<"|B.W_pf | ";  
  fracInt = bwxCryBall_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SLP");
  cout<<fracInt->getVal() * s_bw_norm.getVal() <<" \\pm " << fracInt->getVal() * s_bw_norm.getError() << "|"; 
  double L2 = fracInt->getVal() * s_bw_norm.getError() ; 
  
  fracInt = bwxCryBall_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * s_bw_norm.getVal() <<" \\pm " << fracInt->getVal() * s_bw_norm.getError() << "|"; 
  double M2 = fracInt->getVal() * s_bw_norm.getError() ; 
  
  fracInt = bwxCryBall_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * s_bw_norm.getVal() <<" \\pm " << fracInt->getVal() * s_bw_norm.getError() << "|"<<endl; 
  double U2 = fracInt->getVal() * s_bw_norm.getError() ; 
      
  cout<<"|Sum fit_pf | ";  
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SLP");
  cout<<fracInt->getVal() * (s_bw_norm.getVal()+b_norm.getVal()/*+ttCont.getVal()*/) <<" \\pm " << sqrt(pow(L1,2)+pow(L2,2)/*+pow(E3,2)*/)  << "|"; 
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * (s_bw_norm.getVal()+b_norm.getVal()/*+ttCont.getVal()*/) <<" \\pm " << sqrt(pow(M1,2)+pow(M2,2)/*+pow(E3,2)*/)  << "|"; 
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
  cout<<fracInt->getVal() * (s_bw_norm.getVal()+b_norm.getVal()/*+ttCont.getVal()*/) <<" \\pm " << sqrt(pow(U1,2)+pow(U2,2)/*+pow(E3,2)*/)  << "|"<<endl;
  
  cout<<"|MC Data | " <<data.sumEntries(0, "SLP")<< " | "<< data.sumEntries(0, "SM")<< " | "<<data.sumEntries(0, "SU")<< " | " <<endl;      
  TCanvas c3; 
    c3.SetTitle("");
  RooPlot * xFrame_norm = eventSelectionamassMu.frame(Title("noSM")) ;  
    data.plotOn(xFrame_norm) ;
  sum_norm.plotOn(xFrame_norm) ;
  sum_norm.plotOn(xFrame_norm, 
        RooFit::Components(bwxCryBall_norm), 
        RooFit::LineStyle(kDashed)) ;  
  sum_norm.plotOn(xFrame_norm, 
        RooFit::Components(bkg_norm), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;         
      

  sum_pf.plotOn(xFrame_norm,RooFit::LineColor(kOrange+2) ) ;
  sum_pf.plotOn(xFrame_norm, 
        RooFit::Components(bwxCryBall_pf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen+7)) ;  
  sum_pf.plotOn(xFrame_norm, 
        RooFit::Components(bkg), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed+10)) ;     
  xFrame_norm->Draw();


  c3.SaveAs(title+"plot2_norm.C");
  
}


