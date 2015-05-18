
using namespace RooFit;
using namespace RooStats;
void
fitbkp()
{
  
  TFile* f = new TFile("DoubleMu2012_Summer12_final_1.root", "READ");
  TCanvas c; 
  c.SetTitle("");
  
  TTree* hh = (TChain*)f->Get("rds_zbb") ;
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 10, 120);
  RooRealVar eventSelectionamassMuL("eventSelectionamassMu", "eventSelectionamassMuL", 10, 20); 
  RooRealVar eventSelectionamassMuH("eventSelectionamassMu", "eventSelectionamassMuH", 70, 120);  
  eventSelectionamassMu.setRange("LR",10.,20.);
  eventSelectionamassMu.setRange("HR",70.,120.);
  RooDataSet data("data","data",hh,eventSelectionamassMu,"");
  RooDataSet dataL("dataL","dataL",hh,eventSelectionamassMuL,"");
  RooDataSet dataH("dataH","dataH",hh,eventSelectionamassMuH,"");  
 
  //RooGaussian gauss("gauss","gauss",x,mean,sigma);
  //RooVoigtian gauss("gauss","gauss", x, mean, width, sigma);

  RooPlot * xFrame = eventSelectionamassMu.frame(Title("Z-peak")) ;
  


  //data.plotOn(xFrame);
  cout<<"------------"<<endl;
  dataL.plotOn(xFrame/*, RooFit::MarkerColor(kRed)*/) ;
  dataH.plotOn(xFrame/*, RooFit::MarkerColor(kBlue)*/) ;
  /*sum.plotOn(xFrame) ;
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

*/
  xFrame->Draw();
  /*mean_bw.Print() ;
  mean_cb.Print() ;
  sigma_bw.Print();
  sigma_cb.Print();
  s_bw.Print();
  s_cb.Print();
  b.Print();
*/
  c.SaveAs("fitplot.C");
 
   
}
