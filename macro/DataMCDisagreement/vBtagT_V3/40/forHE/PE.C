
using namespace RooFit;
using namespace RooStats;
void
PE()
{
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
  
  double mcSU =  1351.9;
  double mcSL = 490.001;
  double dataSU = 1197;
  double dataSL = 554;
  double scaleSU = dataSU/mcSU;
  double scaleSL = dataSL/mcSL;  
  cout<<"scaleSU: "<<scaleSU<<endl;
  cout<<"scaleSL: "<<scaleSL<<endl;  
  for(int i = 0; i < bin20; i++)
  	hh->SetBinContent(i+1, hh->GetBinContent(i+1)*scaleSL);
  	
  for(int i = bin20+1; i < bin50; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSL);  
  for(int i = bin50; i < bin70; i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSL);   	
  	 	
  for(int i = bin70; i < hh->GetXaxis()->GetNbins(); i++)
  	hh->SetBinContent(i, hh->GetBinContent(i)*scaleSU); 
  	
  hh->SetBinContent(21, 90);
hh->SetBinError(21, 25);
hh->SetBinContent(22, 87);
hh->SetBinError(22, 23);

  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataHist data("data","data",RooArgList(eventSelectionamassMu),hh);
  TString title = "MC-fit";


  /////////////////////
  // FIT IN SIDEBAND //
  /////////////////////
  
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
  
  bool sbpe = false;
  if(sbpe){
  
  /////// Pseudo experiments before fitting to MC in SB /////
  
  TH1D * hb2 = new TH1D("residualNsmb2","N_{est}-N_{exp}", 2000, -10,10);
  TH1D * hbu2 = new TH1D("residualNsmbu2","N_{est}-N_{exp}", 2000, -10,10);
  RooAbsReal* fracInt = 0;
  RooHistPdf model("MCmodel","MCmodel",eventSelectionamassMu,data);
  for(int i = 0; i < 100; i++){
  	RooDataSet * PD = model.generate(eventSelectionamassMu, 2000);
  	sum.fitTo(*PD, RooFit::Save(kTRUE),RooFit::Range("SL,SU"), RooFit::Extended());
  	fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SL");
  	double est_low = fracInt->getVal() * (s_bw.getVal()+b.getVal());
    fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SU");
    double est_up = fracInt->getVal() * (s_bw.getVal()+b.getVal());
  	double exp_low = PD.sumEntries(0, "SL");
  	double exp_up = PD.sumEntries(0, "SU");  	
  	
  	hb2->Fill(est_low-exp_low);
  	hbu2->Fill(est_up-exp_up);
  } 
  
  hb2->SaveAs("myResSBL_MC.C");
  hbu2->SaveAs("myResSBU_MC.C");
  
  }
  else
  {
  sum.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SL,SU"), RooFit::Extended());  

  
 ///////////// SECOND PART OF FITTING //////////
 //////////// FIT IN SIGNAL REGION, SM /////////
 
 
  TFile* ftop = new TFile("TTFullLept_Summer12_final_5.root", "READ");
  TTree* htop = (TTree*)ftop->Get("rds_zbb");
  RooDataSet topData("topData","topData",htop,eventSelectionamassMu,"");
  RooKeysPdf topPdf(name + "_toppdf", "toppdf", eventSelectionamassMu, topData);
  RooRealVar frac(name + "frac" ,"tt fraction" , 0.051,0.,0.102) ;
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
  RooRealVar frac_pf(name + "_frac_pf", "frac_pf", 0.8); 
  RooRealVar tot(name + "_tot_pf", "tot_pf", (meanb+meanbw), 0, 4 * (meanbw+meanb));
  RooBreitWigner gauss_bw_pf(name + "_gauss_bw_pf", "gauss_bw_pf", eventSelectionamassMu, mean_bw_pf, sigma_bw_pf);
  RooCBShape cball_pf(name + "_cball_pf", "crystal ball_pf", eventSelectionamassMu, mean_cb_pf, sigma_cb_pf, alpha_pf, n_pf);
  RooExponential expo_pf(name + "_expo_pf", "exponential PDF_pf", eventSelectionamassMu, lambda_pf);
  RooAddPdf bkg(name+"_bkg", "all bkgs",topPdf, expo_pf, frac);  
  bkg.fixCoefRange("SM") ;
  RooFFTConvPdf bwxCryBall_pf(name + "_bwxCryBall_pf", "FFT Conv CryBall and BW_pf", eventSelectionamassMu, gauss_bw_pf, cball_pf);
  //RooAddPdf sum_pf_norm(name + "_sum_norm_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(bwxCryBall_pf, bkg), RooArgList(frac_pf));
  //sum_pf_norm.fixCoefRange("SM") ;   
  //RooExtendPdf sum_pf(name + "_sum_pf", "Gaussian crystal ball and exponential PDF_pf",sum_pf_norm ,tot );
  
  RooRealVar mean_dytt(name + "_mean_dytt", "mean_dytt", 42.48403);
  RooRealVar sigma_dytt(name + "_sigma_dytt", "sigma_dytt", 9.348124);
  RooGaussian dytt("dytt","dytt",eventSelectionamassMu,mean_dytt,sigma_dytt); 
  RooRealVar frac_dy(name + "frac_dy" ,"dytt fraction" ,0.428571);// 0.428571 -0.147871,0.428571 +0.147871);
  RooAddPdf fulldy(name+"_fulldy","full dy", RooArgList(dytt, bwxCryBall_pf) , RooArgList(frac_dy));
  fulldy.fixCoefRange("SM");
  RooAddPdf sum_pf(name + "_sum_norm_pf", "Gaussian crystal ball and exponential PDF_pf", RooArgList(fulldy, expo_pf), RooArgList(frac_pf));
  
  
  sum_pf.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SM"), RooFit::Extended());
  RooPlot* frame1 = eventSelectionamassMu.frame(Title("Data")) ;
  data.plotOn(frame1,DataError(RooAbsData::SumW2)) ;
  sum_pf.plotOn(frame1) ;
  RooHist* hresid = frame1->residHist() ;
  RooHist* hpull = frame1->pullHist() ;
  RooPlot* frame2 = eventSelectionamassMu.frame(Title("Residual Distribution")) ;
  frame2->addPlotable(hresid,"P") ;
  RooPlot* frame3 = eventSelectionamassMu.frame(Title("Pull Distribution")) ;
  frame3->addPlotable(hpull,"P") ;
  TCanvas* c = new TCanvas("rf109_chi2residpull","rf109_chi2residpull",900,300) ;
  c->Divide(2) ;
  c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitleOffset(1.6) ; frame2->Draw() ;
  c->cd(2) ; gPad->SetLeftMargin(0.15) ; frame3->GetYaxis()->SetTitleOffset(1.6) ; frame3->Draw() ;
  c->SaveAs("prdy.C");
  
    TCanvas c2; 
  c2.SetTitle("");
  RooPlot * xFrame_pf = eventSelectionamassMu.frame(Title("SM")) ;

  
  
  data.plotOn(xFrame_pf) ;
  sum_pf.plotOn(xFrame_pf) ;
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(expo_pf), 
        RooFit::LineStyle(kDashed)) ;  
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(topPdf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;         
  sum_pf.plotOn(xFrame_pf, 
        RooFit::Components(bwxCryBall_pf), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ;         

 
  xFrame_pf->Draw();


  c2.SaveAs("PE_dy.C");

  /////// Pseudo experiments before fitting to MC in SR /////
  /*TH1D * h = new TH1D("residualNsm","N_{est}-N_{exp}", 2000, -10,10);
  TH1D * p = new TH1D("pullNsm","N_{est}-N_{exp}/#delta N", 1000, -0.5,0.5);
  for(int i = 0; i < 100; i++){
  	RooDataSet * PD = sum_pf_norm.generate(eventSelectionamassMu, 2000);
  	sum_pf.fitTo(*PD, RooFit::Save(kTRUE),RooFit::Range("SM"), RooFit::Extended());
  	double est = tot.getVal();
  	double exp = PD.sumEntries(0, "SM");
  	h->Fill(est-exp);
  	p->Fill((est-exp)/tot.getError());
  } 
  
  h->SaveAs("myRes_pdf.C");
  p->SaveAs("myPull_pdf.C");
  */
  /*double nTruth = data.sumEntries(0, "SM");

  TH1D * h2 = new TH1D("residualNsm2","N_{est}-N_{exp}", 20000, -100,100);
  TH1D * p2 = new TH1D("pullNsm2","N_{est}-N_{exp}/#delta N", 20000, -100,100);
  TH1D * p3 = new TH1D("pullNsm3","N_{est}-N_{truth}/#delta N", 20000, -100,100); 
  TH1D * h3 = new TH1D("residualNsm3","N_{est}-N_{truth}", 20000, -100,100);   
  TH1D * pd = new TH1D("pd","N_{PD}", 20000, 0,2000);   
  TH1D * Est = new TH1D("Est","N_{est}", 20000, 0,2000);     
  TH1D * Err = new TH1D("Err","#delta N_{est}", 20000, 0,200);           
  RooHistPdf model("MCmodel","MCmodel",eventSelectionamassMu,data);
  std::vector<double> ests;
  std::vector<double> errs;  
  for(int i = 0; i < 100; i++){
    cout<<"----------------------------------------- "<<i<<endl;
  	RooDataSet * PD = model.generate(eventSelectionamassMu, 3210);
  	sum_pf.fitTo(*PD, RooFit::Save(kTRUE),RooFit::Range("SM"), RooFit::Extended());
  	double est = tot.getVal();
  	double exp = PD.sumEntries(0, "SM");
  	//h2->Fill(est-exp);
  	//p2->Fill((est-exp)/tot.getError());
  	ests.push_back(est);
  	errs.push_back(tot.getError());
  	cout<<est<<endl;
  	pd->Fill(exp);
  	Est->Fill(est);
  	Err->Fill(tot.getError()); 	
  } 
  
  //h2->SaveAs("myRes_MC.C");
  //p2->SaveAs("myPull_MC.C");
  double mean = 0;
  for(int i = 0; i<100; i++)
  	mean+=ests[i];
  mean=mean/100;
  cout<<mean<<endl;
  for(int i = 0; i<100; i++){
  	h2->Fill(ests[i]-mean);
  	p2->Fill((ests[i]-mean)/errs[i]);
  	p3->Fill((ests[i]-nTruth)/errs[i]);
  	h3->Fill((ests[i]-nTruth));  	
  }
  h2->SaveAs("myRes_MC.C");
  p2->SaveAs("myPull_MC.C");
  p3->SaveAs("myPullG_MC.C");
  h3->SaveAs("myResG_MC.C");
  pd->SaveAs("myPDValsSM_MC.C");
  Est->SaveAs("myEstValsSM_MC.C");
  Err->SaveAs("Err.C");
    cout<<nTruth<<endl;*/
  }
}


