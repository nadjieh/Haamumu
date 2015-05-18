
using namespace RooFit;
using namespace RooStats;
void
fitbkp2()
{
  
  TFile* f = new TFile("DoubleMu2012_Summer12_final_1.root", "READ");
  TCanvas c; 
  c.SetTitle("");
  
  TTree* hh = (TTree*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  RooRealVar mean_bw("mean_bw", "Mean" ,90.8,60,120) ;
  RooRealVar mean_cb("mean_cb", "Mean" ,90.8,60,120) ;
  RooRealVar sigma_bw("sigma_bw", "Width" , 6.5, 1.0,260.0) ;
  RooRealVar sigma_cb("sigma_cb", "Width" , 2.3, 1.0,260.0) ;
  RooRealVar n("n","", 0.0, 5.0);
  RooRealVar alpha("alpha","", 0.0, 5.0);
  RooRealVar lambda("lambda", "slope", -0.1, -5., 0.);
  RooRealVar s_bw("signal_bw", "signal", 100, 0, 10000);
  RooRealVar s_cb("signal_cb", "signal", 100, 0, 10000);
  RooRealVar b("background", "background yield", 100, 0, 10000);
  RooRealVar width0("width0", "width0", 5,0.,10.);

  //RooGaussian gauss("gauss","gauss",x,mean,sigma);
  //RooVoigtian gauss("gauss","gauss", x, mean, width, sigma);
  RooVoigtian gauss_bw("gauss_bw","gauss_bw",eventSelectionamassMu,mean_bw,width0,sigma_bw);
  RooCBShape cball("cball", "crystal ball", eventSelectionamassMu, mean_cb, sigma_cb, alpha, n);
  RooExponential expo("expo", "exponential PDF", eventSelectionamassMu, lambda);
  RooAddPdf sum("sum", "gaussian crystal ball and exponential PDF", 
                RooArgList(gauss_bw, cball, expo), RooArgList(s_bw, s_cb, b));
  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  

  RooFitResult* fitresult = sum.fitTo(data, RooFit::Extended(), RooFit::Save());  
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
              Parameters( RooArgList(s_bw, s_cb, b, mean_bw, mean_cb, sigma_bw, sigma_cb )));


  xFrame->Draw();
  mean_bw.Print() ;
  mean_cb.Print() ;
  sigma_bw.Print();
  sigma_cb.Print();
  s_bw.Print();
  s_cb.Print();
  b.Print();
  cout<<"-------------"<<endl;
  fitresult->Print();
  RooRealVar* cb_mean = (RooRealVar*) fitresult->floatParsFinal()->find("mean_cb");
  cout<<"-------------"<<endl;
  cout<<cb_mean->getVal()<<endl;
//  cb_mean->GetAsymErrorHi() ; // etc... 

  c.SaveAs("fitplot.C");
 
   
}
