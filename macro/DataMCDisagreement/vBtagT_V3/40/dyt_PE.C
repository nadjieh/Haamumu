
using namespace RooFit;
using namespace RooStats;
void
dyt_PE()
{
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
TString name = "test";
  double mcSU =  1351.9;
  double mcSL = 490.001;
  double dataSU = 1197;
  double dataSL = 554;
  double scaleSU = dataSU/mcSU;
  double scaleSL = dataSL/mcSL;  
  cout<<"scaleSU: "<<scaleSU<<endl;
  cout<<"scaleSL: "<<scaleSL<<endl;  
  
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
  eventSelectionamassMu.setRange("SDYT", 30, 50);
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
  RooRealVar b(name + "_background", "background yield", meanb, 0, 4 * meanb);
  RooRealVar bdy(name + "_bdy", "bdy yield", meanb, 0, 4 * meanb);  
  RooRealVar mean_dytt(name + "_mean_dytt", "mean_dytt", 42.48403);
  RooRealVar sigma_dytt(name + "_sigma_dytt", "sigma_dytt", 9.348124);
  RooRealVar frac_dy(name + "frac_dy" ,"dytt fraction" , 0.6,0.,1.);
  RooRealVar frac_pf(name + "_frac_pf", "frac_pf", 0.2,0.,1.);
  
  RooBreitWigner gauss_bw(name + "_gauss_bw", "gauss_bw", eventSelectionamassMu, mean_bw, sigma_bw);
  RooCBShape cball(name + "_cball", "crystal ball", eventSelectionamassMu, mean_cb, sigma_cb, alpha, n);
  RooExponential expo(name + "_expo", "exponential PDF", eventSelectionamassMu, lambda);
  RooFFTConvPdf bwxCryBall(name + "_bwxCryBall", "FFT Conv CryBall and BW", eventSelectionamassMu, gauss_bw, cball);
  RooGaussian dytt("dytt","dytt",eventSelectionamassMu,mean_dytt,sigma_dytt); 
  RooRealVar tot(name + "_tot_pf", "tot_pf", (meanb+meanbw), 0, 4 * (meanbw+meanb));
  
  RooExtendPdf bwxCryBall_ext(name+"_bwxCryBallExt","FFT Conv CryBall and BW",bwxCryBall, s_bw);//,"SUP");
  RooExtendPdf expo_ext(name+"_expoExt","FFT Conv CryBall and BW",expo, b);//,"SLP");  
  RooExtendPdf dytt_ext(name+"_dyttExt","FFT Conv CryBall and BW",dytt, bdy);//,"SDYT");    
  
  RooAddPdf sum(name + "_norm", "Gaussian crystal ball and exponential PDF", RooArgList(bwxCryBall_ext, expo_ext, dytt_ext), RooArgList(s_bw, b, bdy));
//  RooExtendPdf sum(name + "_sum", "Gaussian crystal ball and exponential PDF_pf",sum_norm ,tot );


  int nPE = 100;

 double nTruth = data.sumEntries(0, "SM");
  TH1D * h2 = new TH1D("residualNsm2","N_{est}-N_{exp}", 20000, -100,100);
  TH1D * p2 = new TH1D("pullNsm2","N_{est}-N_{exp}/#delta N", 20000, -100,100);
  TH1D * p3 = new TH1D("pullNsm3","N_{est}-N_{truth}/#delta N", 20000, -100,100); 
  TH1D * h3 = new TH1D("residualNsm3","N_{est}-N_{truth}", 20000, -1000,1000);   
  RooHistPdf model("MCmodel","MCmodel",eventSelectionamassMu,data);
  std::vector<double> ests;
  std::vector<double> errs;  
  RooAbsReal* fracIntpe = 0;
  for(int i = 0; i < nPE; i++){
    cout<<"----------------------------------------- "<<i<<endl;
  	RooDataSet * PD = model.generate(eventSelectionamassMu, 3210);
  	sum.fitTo(*PD, RooFit::Save(kTRUE),RooFit::Range("FULL"), RooFit::Extended());
  	double est = (b.getVal()+bdy.getVal()+s_bw.getVal());
  	fracIntpe = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  	est= est * fracIntpe->getVal();
  	double exp = PD.sumEntries(0, "SM");
  	cout<<exp<<" "<<nTruth <<"  "<<est<<endl;
  	ests.push_back(est);
  	errs.push_back(tot.getError());
  	cout<<est<<endl;
  } 
  
  //h2->SaveAs("myRes_MC.C");
  //p2->SaveAs("myPull_MC.C");

  double mean = 0;
  for(int i = 0; i<nPE; i++)
  	mean+=ests[i];
  mean=mean/nPE;
  cout<<mean<<endl;
  for(int i = 0; i<nPE; i++){
  	h2->Fill(ests[i]-mean);
  	p2->Fill((ests[i]-mean)/errs[i]);
  	p3->Fill((ests[i]-nTruth)/errs[i]);
  	h3->Fill((ests[i]-nTruth));  	
  }
  h2->SaveAs("myRes_MC.C");
  p2->SaveAs("myPull_MC.C");
  p3->SaveAs("myPullG_MC.C");
  h3->SaveAs("myResG_MC.C");
      }
    /*  

  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  

  sum.fitTo(data, RooFit::Save(kTRUE), RooFit::Extended(), RooFit::Range("FULL"));  
  
  data.plotOn(xFrame) ;
  sum.plotOn(xFrame) ;
  sum.plotOn(xFrame, 
        RooFit::Components(expo), 
        RooFit::LineStyle(kDashed)) ;  
  sum.plotOn(xFrame, 
        RooFit::Components(bwxCryBall), 
        RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;         
  
    sum.plotOn(xFrame, 
        RooFit::Components(dytt), 
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
  b.Print();
  bdy.Print();
  tot.Print();
  frac_dy.Print();
  frac_pf.Print();
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
  
  RooAbsReal* fracInt = 0;
  double sumErr = pow((pow(b.getError(),2)+pow(bdy.getError(),2)+pow(s_bw.getError(),2)),0.5);
  
 /* RooAbsReal* fracInt = 0;
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SLP");
  double fracL = fracInt->getVal();
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SUP");
  double fracU = fracInt->getVal();
  fracInt = sum_norm.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  double fracM = fracInt->getVal();
  double realTot = tot.getVal()*(fracM/(fracU+fracL));
  cout<<fracL<<"   "<<fracM<<"    "<<fracU<<endl;
  cout<<"Real tot: " << tot.getVal()<<endl;
  
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
    
  */
    
  /*cout<<"|Sum fit | ";  
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SLP");
  cout<<fracInt->getVal() * (b.getVal()+bdy.getVal()+s_bw.getVal()) <<" \\pm " << fracInt->getVal() * sumErr << "|";
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SM");
  cout<<fracInt->getVal() * (b.getVal()+bdy.getVal()+s_bw.getVal()) <<" \\pm " << fracInt->getVal() * sumErr  << "|"; 
  fracInt = sum.createIntegral(eventSelectionamassMu, eventSelectionamassMu, "SUP");
  cout<<fracInt->getVal() * (b.getVal()+bdy.getVal()+s_bw.getVal()) <<" \\pm " << fracInt->getVal() * sumErr  << "|"<<endl; 
    
  cout<<"|MC Data | "<<data.sumEntries(0, "SLP")<< " | " << data.sumEntries(0, "SM")<< " | " <<data.sumEntries(0, "SUP")<<" |" <<endl;
  
}*/


