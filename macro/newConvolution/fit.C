
using namespace RooFit;
using namespace RooStats;
void
fit()
{
  
  TFile* f = new TFile("DoubleMu2012_Summer12_final_1_1.root", "READ");
  TCanvas c; 
  c.SetTitle("");
  
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  eventSelectionamassMu.setRange("SL", 10, 20);
  eventSelectionamassMu.setRange("SU", 70, 120);


  
  //Reg. 1
  /*RooRealVar mean_bw("mean_bw", "Mean" ,90.8,60,120) ;
  RooRealVar mean_cb("mean_cb", "Mean" ,1,0,50) ;
  RooRealVar sigma_bw("sigma_bw", "Width" , 6.5, 1.0,260.0) ;
  RooRealVar sigma_cb("sigma_cb", "Width" , 2.3, 0.,260.0) ;
  RooRealVar n("n","", 0.0, 5.0);
  RooRealVar alpha("alpha","", 0.0, 5.0);
  RooRealVar lambda("lambda", "slope", -0.1, -5., 0.);*/
  RooRealVar mean_bw("mean_bw", "Mean" ,90.9) ;
  RooRealVar mean_cb("mean_cb", "Mean" ,0.47) ;
  RooRealVar sigma_bw("sigma_bw", "Width" , 4.5) ;
  RooRealVar sigma_cb("sigma_cb", "Width" , 0.33) ;
  RooRealVar n("n","", 3.6);
  RooRealVar alpha("alpha","", 3.0);
  RooRealVar lambda("lambda", "slope", -9e-9);
  RooRealVar s_bw("signal_bw", "signal", 100, 0, 10000);
  RooRealVar s_cb("signal_cb", "signal", 100, 0, 10000);
  RooRealVar b("background", "background yield", 100, 0, 10000);
  RooRealVar width("width", "width", 5,0.,10.);
  
  //RooVoigtian gauss_bw("gauss_bw","gauss_bw",eventSelectionamassMu,mean_bw,width,sigma_bw);
  RooBreitWigner gauss_bw("gauss_bw","gauss_bw",eventSelectionamassMu,mean_bw,sigma_bw);
  RooCBShape cball("cball", "crystal ball", eventSelectionamassMu, mean_cb, sigma_cb, alpha, n);
  RooExponential expo("expo", "exponential PDF", eventSelectionamassMu, lambda);
  RooFFTConvPdf bwxCryBall1("bwxCryBall1", "FFT Conv CryBall and BW", eventSelectionamassMu, gauss_bw, cball); 
  RooAddPdf sum("sum", "gaussian crystal ball and exponential PDF", 
                RooArgList(bwxCryBall1, expo), RooArgList(s_bw, b));

                
                

  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  

  sum.fitTo(data, RooFit::Save(kTRUE),RooFit::Range("SL,SU"), RooFit::Extended());  
  
  data.plotOn(xFrame) ;
  sum.plotOn(xFrame) ;
  sum.plotOn(xFrame, 
             RooFit::Components(expo), 
             RooFit::LineStyle(kDashed)) ;  
  /*sum.plotOn(xFrame, 
             RooFit::Components(cball), 
             RooFit::LineStyle(kDashed),RooFit::LineColor(kRed)) ;              */
  
    sum.plotOn(xFrame, 
             RooFit::Components(gauss_bw), 
             RooFit::LineStyle(kDashed),RooFit::LineColor(kGreen)) ;   
    sum.plotOn(xFrame, 
             RooFit::Components(bwxCryBall1), 
             RooFit::LineStyle(kDashed),RooFit::LineColor(kYellow)) ;             
   
  sum.paramOn(xFrame,Layout(0.65), 
              Format("NEU", AutoPrecision(1)), 
              Parameters( RooArgList(s_bw, s_cb, b, mean_bw, mean_cb, sigma_bw/*,width*/, sigma_cb )));


  xFrame->Draw();
  mean_bw.Print() ;
  mean_cb.Print() ;
  sigma_bw.Print();
  sigma_cb.Print();
  n.Print();
  alpha.Print();
  lambda.Print();
  s_bw.Print();
  //s_cb.Print();
  b.Print();

  c.SaveAs("fitplot21.C");
 
   
}
