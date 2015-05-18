
using namespace RooFit;
using namespace RooStats;
void
fit()
{
  TString name = "test";
  
  TFile* f = new TFile("mcMass.root", "READ");
  TString data_ = "MC";
  TH1D* hh = (TH1D*)f->Get("mcMass") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  
  /*TFile* f = new TFile("DoubleMu2012_Summer12_final_8_8.root", "READ");
  TString data_ = "Data";
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");*/
  
  /////////////////////
  // FIT IN SIDEBAND //
  /////////////////////
  
  TCanvas c; 
  c.SetTitle("");
  

  eventSelectionamassMu.setRange("SL", 10, 20);
  eventSelectionamassMu.setRange("SM", 30, 50);
  eventSelectionamassMu.setRange("SU", 70, 120);


  double meanbw = 1726;
  double meanb = 1094.91;
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
  mean_bw.Print() ;
  mean_cb.Print() ;
  sigma_bw.Print();
  sigma_cb.Print();
  s_bw.Print();
  s_cb.Print();
  b.Print();

  c.SaveAs("fitplot2.C");
  
    cout<<"////////////////////////////////"<<endl;
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
    
  cout<<"|"<<data_<<" Data | "<<data.sumEntries(0, "SL")<< " | " << data.sumEntries(0, "SM")<< " | " <<data.sumEntries(0, "SU")<<" |" <<endl;  
 
 ///////////// SECOND PART OF FITTING //////////
 //////////// FIT IN SIGNAL REGION, SM /////////
 
 
  TFile* ftop = new TFile("TTFullLept_Summer12_final_8_8.root", "READ");
  TTree* htop = (TTree*)ftop->Get("rds_zbb");
  RooDataSet topData("topData","topData",htop,eventSelectionamassMu,"");
  RooKeysPdf topPdf(name + "_toppdf", "toppdf", eventSelectionamassMu, topData);
  //double meantt = 55.8325;
  //RooRealVar ttCont(name + "_ttCont", "ttCont", meantt, 0., 4 * meantt);
  RooRealVar frac(name + "frac" ,"tt fraction" , 0.5,0.0, 1.0) ;
  
  RooRealVar mean_bw_pf(name + "_mean_bw_pf", "Mean_pf", mean_bw.getVal());
  mean_bw_pf.setConstant(kTRUE);
  RooRealVar mean_cb_pf(name + "_mean_cb_pf", "Mean_pf", mean_cb.getVal());
  mean_cb_pf.setConstant(kTRUE);  
  RooRealVar sigma_bw_pf(name + "_sigma_bw_pf", "Width_pf",sigma_bw.getVal() );
  sigma_bw_pf.setConstant(kTRUE);    
  RooRealVar sigma_cb_pf(name + "_sigma_cb_pf", "Width_pf", sigma_cb.getVal());
  sigma_cb_pf.setConstant(kTRUE);      
  RooRealVar n_pf(name + "_n_pf", "_pf", n.getVal());
  n_pf.setConstant(kTRUE);        
  RooRealVar alpha_pf(name + "_alpha_pf", "_pf", alpha.getVal());
  alpha_pf.setConstant(kTRUE);        
  RooRealVar lambda_pf(name + "_lambda_pf", "slope_pf", lambda.getVal());
  lambda_pf.setConstant(kTRUE);        
  RooRealVar s_bw_pf(name + "_signal_bw_pf", "signal_pf", meanbw, 0, 4 * meanbw);
  RooRealVar b_pf(name + "_background_pf", "background yield_pf", meanb, 0, 4 * meanb);

  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, expo_pf, frac);  
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw, cball_pf);
  //RooAddPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, expo_pf, topPdf), RooArgList(s_bw_pf, b_pf,ttCont));
  
  RooAddPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, bkg), RooArgList(s_bw_pf, b_pf));
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


  c2.SaveAs("fitplot2_pf.C");
  
  
  
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
  
  cout<<"|"<<data_<<" Data | " << data.sumEntries(0, "SM")<< " | " <<endl;  
  
  
}



/*
| | SL | SM | SU |
|expo | 673.719 \pm 37.6106|223.192 \pm 12.4598|108.255 \pm 6.0434|
|B.W | 7.78118 \pm 0.265296|191.75 \pm 6.53762|1556.29 \pm 53.061|
|Sum fit | 681.5 \pm 37.6116|414.941 \pm 14.0708|1664.55 \pm 53.404|
|MC Data | 678.662 | 474.938 | 1667.31 |

| | SL | SM | SU |
|expo | 713.851 \pm 39.3435|157.466 \pm 8.67865|44.3408 \pm 2.44382|
|B.W | 8.70417 \pm 0.337764|218.665 \pm 8.48528|1216.25 \pm 47.1966|
|Sum fit | 722.555 \pm 39.345|376.131 \pm 12.1375|1260.59 \pm 47.2598|
|MC Data | 722 | 504 | 1261 |


| | SM |
|expo_pf | 78.4714 \pm 34.0568|
|B.W_pf | 300.209 \pm 32.1098|
|ttCont_pf | 95.2435 \pm 67.4454|
|Sum fit_pf | 473.924 \pm 82.0962|
|MC Data | 474.938 | 


*/

/*| | SL | SM | SU |
|expo | 356.044 \pm 24.2872|13.2932 \pm 0.906785|0.0137874 \pm 0.000940494|
|B.W | 0.906965 \pm 0.036616|135.811 \pm 5.48297|1276.04 \pm 51.5163|
|Sum fit |356.951 \pm 24.2873|149.105 \pm 5.55745|1276.06 \pm 51.5163|
|MC Data | 356.889 | 474.938 | 1276.08 |



*/


