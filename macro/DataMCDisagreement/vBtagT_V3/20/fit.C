
using namespace RooFit;
using namespace RooStats;
void
fit()
{
TString name = "test";
  double mcSU =  1;
  double mcSL = 1;
  double dataSU = 1;
  double dataSL = 1;
  double scaleSU = dataSU/mcSU;
  double scaleSL = dataSL/mcSL;  
  cout<<"scaleSU: "<<scaleSU<<endl;
  cout<<"scaleSL: "<<scaleSL<<endl;  
  
  TFile* f = new TFile("mcMass20.root", "READ");
  TH1D* hh = (TH1D*)f->Get("mcMass") ;
  int bin70 = hh->FindBin(70);
  int bin60 = hh->FindBin(60);  
  int bin50 = hh->FindBin(50);  
  int bin40 = hh->FindBin(40);
  int bin30 = hh->FindBin(30);  
  int bin20 = hh->FindBin(20);

  for(int i = 0; i < bin20; i++)
  	hh->SetBinContent(i+1, hh->GetBinContent(i+1)*scaleSL);
  	
  for(int i = bin30; i < bin50; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSL);  
  	 	
  for(int i = bin70; i < hh->GetXaxis()->GetNbins(); i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSU);  	
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  TString title = "MC-fit";
  
  /*
  TFile* f = new TFile("DoubleMu2012_Summer12_final_8.root", "READ");
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  TString title = "Data-fit";  */
  
  /////////////////////
  // FIT IN SIDEBAND //
  /////////////////////
  
  TCanvas c; 
  c.SetTitle("");
  

  eventSelectionamassMu.setRange("SL", 10, 30);
  eventSelectionamassMu.setRange("SM", 30, 70);
  eventSelectionamassMu.setRange("SU", 70, 120);

  TFile* ftop = new TFile("TTFullLept_Summer12_final_8.root", "READ");
  TTree* htop = (TTree*)ftop->Get("rds_zbb");
  RooDataSet topData("topData","topData",htop,eventSelectionamassMu,"");
  RooKeysPdf topPdf(name + "_toppdf", "toppdf", eventSelectionamassMu, topData);

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

  RooFFTConvPdf bwxCryBall(name + "_bwxCryBall", "FFT Conv CryBall and BW", eventSelectionamassMu, gauss_bw, cball);

  RooAddPdf sum(name + "_sum", "Gaussian crystal ball and exponential PDF", RooArgList(bwxCryBall, topPdf), RooArgList(s_bw, b));



      
      

  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  

  sum.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SM,SU"), RooFit::Extended());  
  
  data.plotOn(xFrame) ;
  sum.plotOn(xFrame) ;
  sum.plotOn(xFrame, 
        RooFit::Components(topPdf), 
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
  cout<<"|top | ";  
  fracInt = topPdf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * b.getVal() <<" \\pm " << fracInt->getVal() * b.getError() << "|";
  double e1 = fracInt->getVal() * b.getError() ;
  fracInt = topPdf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * b.getVal() <<" \\pm " << fracInt->getVal() * b.getError() << "|"; 
  double e2 = fracInt->getVal() * b.getError() ;
  fracInt = topPdf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
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
       
  RooRealVar s_bw_pf(name + "_signal_bw_pf", "signal_pf", meanbw, 0, 4 * meanbw);
  RooRealVar b_pf(name + "_background_pf", "background yield_pf", meanb, 0, 4 * meanb);

  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda);
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);  
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, bwxCryBall_pf, frac);  

  //RooAddPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, expo_pf, topPdf), RooArgList(s_bw_pf, b_pf,ttCont));
  
  RooAddPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(expo_pf, bkg), RooArgList(s_bw_pf, b_pf));
  TCanvas c2; 
  c2.SetTitle("");
  RooPlot * xFrame_pf = eventSelectionamassMu.frame(Title("SL")) ;

  sum_pf.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SL"), RooFit::Extended());
  
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
  cout<<"//// stringstream lambda; lambda << "<<lambda.getVal()<<";"<<endl;
  cout<<"| | SM |"<<endl;
  cout<<"|bkg | ";  
  fracInt = bkg.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * b_pf.getVal() <<" \\pm " << fracInt->getVal() * b_pf.getError() << "|"<<endl; 
  double E1 = fracInt->getVal() * b_pf.getError() ;
  
  cout<<"|expo_pf | ";  
  fracInt = expo_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * s_bw_pf.getVal() <<" \\pm " << fracInt->getVal() * s_bw_pf.getError() << "|"<<endl; 
  double E2 = fracInt->getVal() * s_bw_pf.getError() ; 
  
  /*cout<<"|ttCont_pf | ";  
  fracInt = topPdf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * ttCont.getVal() <<" \\pm " << fracInt->getVal() * ttCont.getError() << "|"<<endl; 
  double E3 = fracInt->getVal() * ttCont.getError() ;   */
      
  cout<<"|Sum fit_pf | ";  
  fracInt = sum_pf.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  cout<<fracInt->getVal() * (s_bw_pf.getVal()+b_pf.getVal()/*+ttCont.getVal()*/) <<" \\pm " << sqrt(pow(E1,2)+pow(E2,2)/*+pow(E3,2)*/)  << "|"<<endl; 
  
  cout<<"|MC Data | " << data.sumEntries(0, "SL")<< " | " <<endl;  
  
  
}


