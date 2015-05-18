
using namespace RooFit;
using namespace RooStats;
void
fit()
{
  TString name = "test";
  TFile* f = new TFile("mcMass.root", "READ");
  TH1D* hh = (TH1D*)f->Get("mcMass") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  TString title = "MC-fit";
  
  
  /*TFile* f = new TFile("DoubleMu2012_Summer12_final_8_8.root", "READ");
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  TString title = "Data-fit";  */
  /////////////////////
  // FIT IN SIDEBAND //
  /////////////////////
  
  TCanvas c; 
  c.SetTitle("");
  

  eventSelectionamassMu.setRange("SL", 10, 20);
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

  c.SaveAs("fitplot2.C");
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
 
 
  TFile* ftop = new TFile("TTFullLept_Summer12_final_8_8.root", "READ");
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

  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, expo_pf, frac);  
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);
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
  
  cout<<"|MC Data | " << data.sumEntries(0, "SM")<< " | " <<endl;  
  
  

  //// SIGNAL ////
   RooRealVar mean_sig("mean_sig","mean_sig",60.);
   RooRealVar sigma_sig("mean_sig","sigma_sig",2.);
   RooGaussian signal(name + "_signal", "signal", eventSelectionamassMu, mean_sig, sigma_sig);
   
  //////// CREATING WORKSPACE ///////   
   RooWorkspace *ws = new RooWorkspace("ws","workspace") ;
   ws->import(sum_pf) ;
   ws->import(data) ;
   ws->Print() ;
   ws->writeToFile("workspace_bkgdata.root") ;
   RooWorkspace *ws_ = new RooWorkspace("ws2","workspace") ;
   ws_->import(signal);
   ws_->writeToFile("workspace_signal.root") ;
   
   //////// GENERATING HISTOGRAM //////
   eventSelectionamassMu.setBins(110);
   RooDataSet* data2 = sum_pf.generate(eventSelectionamassMu,100000) ;
   RooDataHist* hist2 = data2->binnedClone() ;
   RooHistPdf histpdf2("histpdf2","histpdf2",eventSelectionamassMu,*hist2,2) ;
   RooPlot* frame2 = eventSelectionamassMu.frame(Title("High stats histogram pdf with interpolation"),Bins(110)) ;
   hist2.plotOn(frame2) ; 
   TCanvas c3;
   c3.cd();
   frame2->Draw();
   c3.SaveAs("tmp.C");
   
   RooDataSet* bkg_data = bkg.generate(eventSelectionamassMu,100000) ;
   RooDataHist* bkg_hist = bkg_data->binnedClone() ; 
   RooPlot* frame3 = eventSelectionamassMu.frame(Title("High stats histogram pdf with interpolation"),Bins(110)) ;
   bkg_hist.plotOn(frame3) ; 
   TCanvas c4;
   c4.cd();
   frame3->Draw();
   c4.SaveAs("bkg_hist.C");
     
   RooDataSet* bw_data = bwxCryBall_pf.generate(eventSelectionamassMu,100000) ;
   RooDataHist* bw_hist = bw_data->binnedClone() ; 
   RooPlot* frame4 = eventSelectionamassMu.frame(Title("High stats histogram pdf with interpolation"),Bins(110)) ;
   bw_hist.plotOn(frame4) ; 
   TCanvas c5;
   c5.cd();
   frame4->Draw();
   c5.SaveAs("bw_hist.C");  
}


/*
| | SL | SM | SU |
|expo | 316.293 \pm 21.0867|4.61128 \pm 0.307426|0.674427 \pm 0.0449629|
|B.W | 232.406 \pm 4.98576|2252.96 \pm 48.3323|
|Sum fit | 548.699 \pm 21.6681|316.73 \pm 6.70287|2253.64 \pm 48.3323|
|MC Data | 547.086 | 383.416 | 2255.25 |


| | SL | SM | SU |
|expo | 329.878 \pm 22.0828|6.61455 \pm 0.442793|1.1748 \pm 0.0786437|
|B.W | 587.205 \pm 12.7403|1000.4 \pm 21.7051|1193.07 \pm 25.8853|
|Sum fit | 943.238 \pm 25.4944|1035.73 \pm 21.7096|1228.3 \pm 25.8854|
|MC Data | 547.086 | 383.416 | 2255.25 |



*/
/*
| | SL | SM | SU |
|expo | 338.558 \pm 25.6444|6.16222 \pm 0.466763|1.0311 \pm 0.0781017|
|B.W | 212.732 \pm 5.44251|284.346 \pm 7.27466|1801.72 \pm 46.0949|
|Sum fit | 551.29 \pm 26.2156|290.508 \pm 7.28962|1802.75 \pm 46.0949|
|MC Data | 566 | 295 | 1788 |
*/
