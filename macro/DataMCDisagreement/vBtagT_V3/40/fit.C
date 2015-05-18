
using namespace RooFit;
using namespace RooStats;
void
fit()
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
  

  eventSelectionamassMu.setRange("SL", 10, 28);
  eventSelectionamassMu.setRange("SM", 30, 50);
  eventSelectionamassMu.setRange("SU", 50, 120);
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
 
 
}


