#include <iostream>
#include <sstream>

#include "TFile.h"
#include "TArrow.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TStyle.h"
#include "TChain.h"
#include "TH2.h"
#include "TH1.h"
#include "TF1.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TVirtualFitter.h"

#include <stdio.h>
#include <math.h>

void F_test (int Nbins=50, int Ndata=5000, double alpha=0.1, int option=1) {
  using namespace RooFit;
  using namespace std;
  // Pass parameters:
  // Nbins = bins of tested histogram
  // Ndata = number of events filling histogram
  // alpha = size of test
  // ------------------------------------------

  cout << endl;
  cout << " F - test " << endl;
  cout << " -------- " << endl;
  cout << endl;
  cout << " Will test pseudo-data with a size alpha = " << alpha << endl;
  cout << endl;
  if (Nbins>1000) {
    cout << "Too many bins, max 1000. Stopping. Edit code and increase arrays size." << endl;
    return;
  }

  gStyle->SetOptFit(111111);
  gStyle->SetOptStat(0);

  // Change preset generator
  // NB other versions of TRandom are flawed
  // ---------------------------------------
  delete gRandom;
  TRandom3 * myRNG = new TRandom3();
  gRandom = myRNG;

  // To read and write random data:
  // ------------------------------
  // gRandom->ReadRandom("random.dat");
  // gRandom->WriteRandom("random.dat");
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
  TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
  TTree * tree = (TTree*) input->Get("rds_zbb");
  Ndata = tree->GetEntriesFast();
  RooDataSet data("ControlData", "The original control data", tree, eventSelectionamassMu, "");
  double xmin = 20.;
  double xmax = 70.;
  TH1D * Data0 = data.createHistogram("Data0",eventSelectionamassMu,Binning(Nbins));
  TH1D * Data1 = data.createHistogram("Data1",eventSelectionamassMu,Binning(Nbins));
  TH1D * Data2 = data.createHistogram("Data2",eventSelectionamassMu,Binning(Nbins));
  TH1D * Data3 = data.createHistogram("Data3",eventSelectionamassMu,Binning(Nbins));
  TH1D * Data4 = data.createHistogram("Data4",eventSelectionamassMu,Binning(Nbins));  
  TH1D * Data5 = data.createHistogram("Data5",eventSelectionamassMu,Binning(Nbins));  

  // F distributions
  // ---------------
  double xmaxF = 20.;
  int NbinsF = 100;
  TH1D * Fdistr10 = new TH1D ("Fdistr10", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr21 = new TH1D ("Fdistr21", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr32 = new TH1D ("Fdistr32", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr43 = new TH1D ("Fdistr43", "", NbinsF, 0., xmaxF);  
  TH1D * Fdistr54 = new TH1D ("Fdistr54", "", NbinsF, 0., xmaxF);   
  TH1D * Fdistr10extr = new TH1D ("Fdistr10extr", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr21extr = new TH1D ("Fdistr21extr", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr32extr = new TH1D ("Fdistr32extr", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr43extr = new TH1D ("Fdistr43extr", "", NbinsF, 0., xmaxF);
  TH1D * Fdistr54extr = new TH1D ("Fdistr54extr", "", NbinsF, 0., xmaxF);  
  TH1D * Finteg10 = new TH1D ("Finteg10", "", NbinsF, 0., xmaxF);
  TH1D * Finteg21 = new TH1D ("Finteg21", "", NbinsF, 0., xmaxF);
  TH1D * Finteg32 = new TH1D ("Finteg32", "", NbinsF, 0., xmaxF);
  TH1D * Finteg43 = new TH1D ("Finteg43", "", NbinsF, 0., xmaxF);  
  TH1D * Finteg54 = new TH1D ("Finteg54", "", NbinsF, 0., xmaxF); 
     
  double y0[1000];
  double y1[1000];
  double y2[1000];
  double y3[1000];
  double y4[1000];  
  double y5[1000];   
  
  for (int i=0; i<Nbins; i++) {
    y0[i] = Data0->GetBinContent(i+1);
    y1[i] = Data1->GetBinContent(i+1);
    y2[i] = Data2->GetBinContent(i+1);
    y3[i] = Data3->GetBinContent(i+1);
    y4[i] = Data4->GetBinContent(i+1);    
    y5[i] = Data5->GetBinContent(i+1);        
  }

  TF1 * Pol0 = new TF1 ("Pol0","[0]", xmin, xmax);
  TF1 * Pol1 = new TF1 ("Pol1","[0]+[1]*x", xmin, xmax);
  TF1 * Pol2 = new TF1 ("Pol2","[0]+[1]*x+[2]*x*x", xmin, xmax);
  TF1 * Pol3 = new TF1 ("Pol3","[0]+[1]*x+[2]*x*x+[3]*x*x*x", xmin, xmax);
  TF1 * Pol4 = new TF1 ("Pol4","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x", xmin, xmax);  
  TF1 * Pol5 = new TF1 ("Pol5","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x+[5]*x*x*x*x*x", xmin, xmax);    
  
  Pol0->SetParameter(0,1.);
  Pol1->SetParameter(0,1.);
  Pol1->SetParameter(1,0.);
  Pol2->SetParameter(0,1.);
  Pol2->SetParameter(1,0.);
  Pol2->SetParameter(2,0.);
  Pol3->SetParameter(0,1.);
  Pol3->SetParameter(1,0.);
  Pol3->SetParameter(2,0.);
  Pol3->SetParameter(3,0.);
  Pol4->SetParameter(0,1.);
  Pol4->SetParameter(1,0.);
  Pol4->SetParameter(2,0.);
  Pol4->SetParameter(3,0.);  
  Pol4->SetParameter(4,0.);  
  Pol5->SetParameter(0,1.);
  Pol5->SetParameter(1,0.);
  Pol5->SetParameter(2,0.);
  Pol5->SetParameter(3,0.);  
  Pol5->SetParameter(4,0.);  
  Pol5->SetParameter(5,0.);    
  
  double Npar0=1.;
  double Npar1=2.;
  double Npar2=3.;
  double Npar3=4.;
  double Npar4=5.;
  double Npar5=6.;  
  Data0->Fit("Pol0","QNL");
  double p00 = Pol0->GetParameter(0);
  Data1->Fit("Pol1","QNL");
  double p10 = Pol1->GetParameter(0);
  double p11 = Pol1->GetParameter(1);
  Data2->Fit("Pol2","QNL");
  double p20 = Pol2->GetParameter(0);
  double p21 = Pol2->GetParameter(1);
  double p22 = Pol2->GetParameter(2);
  Data3->Fit("Pol3","QNL");
  Data3->Fit("Pol3","QNL");
  double p30 = Pol3->GetParameter(0);
  double p31 = Pol3->GetParameter(1);
  double p32 = Pol3->GetParameter(2);
  double p33 = Pol3->GetParameter(3);
  Data4->Fit("Pol4","QNL");
  Data4->Fit("Pol4","QNL");
  Data4->Fit("Pol4","QNL"); 
  double p40 = Pol4->GetParameter(0);
  double p41 = Pol4->GetParameter(1);
  double p42 = Pol4->GetParameter(2);
  double p43 = Pol4->GetParameter(3);     
  double p44 = Pol4->GetParameter(4);   
  Data5->Fit("Pol5","QNL");
  Data5->Fit("Pol5","QNL");
  Data5->Fit("Pol5","QNL"); 
  double p50 = Pol5->GetParameter(0);
  double p51 = Pol5->GetParameter(1);
  double p52 = Pol5->GetParameter(2);
  double p53 = Pol5->GetParameter(3);     
  double p54 = Pol5->GetParameter(4);     
  double p55 = Pol5->GetParameter(5);       


  // Calculate residual sums of squares for the three hypotheses
  // -----------------------------------------------------------
  double rss0=0;
  double rss1=0;
  double rss2=0;
  double rss3=0;
  double rss4=0;
  double rss5=0;  
  
  for (int i=0; i<Nbins; i++) {
    double x = (i+0.5)*xmax/(double)Nbins;
    rss0+= pow(y0[i]-Pol0->Eval(x),2);
    rss1+= pow(y1[i]-Pol1->Eval(x),2);
    rss2+= pow(y2[i]-Pol2->Eval(x),2);
    rss3+= pow(y3[i]-Pol3->Eval(x),2);
    rss4+= pow(y4[i]-Pol4->Eval(x),2);   
    rss5+= pow(y5[i]-Pol5->Eval(x),2);         
  }

  // F-values
  // --------
  double p1_10 = Npar1-Npar0;
  double p1_21 = Npar2-Npar1;  
  double p1_32 = Npar3-Npar2;
  double p1_43 = Npar4-Npar3;
  double p1_54 = Npar5-Npar4;
        
  double p2_10 = Nbins-Npar1;
  double p2_21 = Nbins-Npar2;
  double p2_32 = Nbins-Npar3;
  double p2_43 = Nbins-Npar4;
  double p2_54 = Nbins-Npar5;  
    
  double Ftest_10 = (rss0-rss1)/p1_10 / (rss1/p2_10);
  double Ftest_21 = (rss1-rss2)/p1_21 / (rss2/p2_21);
  double Ftest_32 = (rss2-rss3)/p1_32 / (rss3/p2_32);
  double Ftest_43 = (rss3-rss4)/p1_43 / (rss4/p2_43);  
  double Ftest_54 = (rss4-rss5)/p1_54 / (rss5/p2_54);   
  cout <<  Ftest_43 <<"\t"<<Ftest_54 <<endl;
  cout <<  rss4 <<"\t"<<rss5 <<"\t"<< rss3 <<endl;  

  double good_CL10 =  1.-TMath::FDistI(Ftest_10,p1_10,p2_10);
  double good_CL21 =  1.-TMath::FDistI(Ftest_21,p1_21,p2_21);
  double good_CL32 =  1.-TMath::FDistI(Ftest_32,p1_32,p2_32);
  double good_CL43 =  1.-TMath::FDistI(Ftest_43,p1_43,p2_43);
  double good_CL54 =  1.-TMath::FDistI(Ftest_54,p1_54,p2_54);
      
    
  cout << " Ftest10 = " << good_CL10 << endl;
  cout << " Ftest21 = " << good_CL21 << endl;
  cout << " Ftest32 = " << good_CL32 << endl; 
  cout << " Ftest43 = " << good_CL43 << endl;   
  cout << " Ftest54 = " << good_CL43 << endl;     
  cout << endl;
  cout << " F - test results: " << endl;
  cout << " ----------------- " << endl;
  cout << endl;
  if (good_CL10>alpha) {
    cout << " No need for anything more than a constant fit." << endl;
  } else if (good_CL21>alpha) {
    cout << " A linear fit is sufficient to describe these data." << endl;
  } else if (good_CL32>alpha) {
    cout << " A quadratic fit appears adequate to describe these data." << endl;
  } else if (good_CL43>alpha) {
    cout << " A cubic fit appears adequate to describe these data." << endl;
  } else {
    cout << " A higher-order fit is needed for these data. " << endl;
    cout << " You should check for higher-order polynomials" << endl;
    cout << " or change the family of test functions." << endl;
  }
  cout << endl;

  // Create the histograms of F distributions and cumulatives
  // --------------------------------------------------------
  for (int i=0; i<NbinsF; i++) {
    double x = (i+0.5)*xmaxF/(double)NbinsF;
    double Fvalue10 = TMath::FDist(x,p1_10,p2_10);
    double Fvalue21 = TMath::FDist(x,p1_21,p2_21);
    double Fvalue32 = TMath::FDist(x,p1_32,p2_32);
    double Fvalue43 = TMath::FDist(x,p1_43,p2_43);    
    double Fvalue54 = TMath::FDist(x,p1_54,p2_54);        
    double Fsum10 = TMath::FDistI(x,p1_10,p2_10);
    double Fsum21 = TMath::FDistI(x,p1_21,p2_21);
    double Fsum32 = TMath::FDistI(x,p1_32,p2_32);
    double Fsum43 = TMath::FDistI(x,p1_43,p2_43);    
    double Fsum54 = TMath::FDistI(x,p1_54,p2_54);        
    
    Fdistr10->SetBinContent(i+1,Fvalue10);
    Fdistr21->SetBinContent(i+1,Fvalue21);
    Fdistr32->SetBinContent(i+1,Fvalue32);
    Fdistr43->SetBinContent(i+1,Fvalue43);   
    Fdistr54->SetBinContent(i+1,Fvalue54);         
    if (x>Ftest_10) Fdistr10extr->SetBinContent(i+1,Fvalue10);
    if (x>Ftest_21) Fdistr21extr->SetBinContent(i+1,Fvalue21);
    if (x>Ftest_32) Fdistr32extr->SetBinContent(i+1,Fvalue32);
    if (x>Ftest_43) Fdistr43extr->SetBinContent(i+1,Fvalue43);    
    if (x>Ftest_54) Fdistr54extr->SetBinContent(i+1,Fvalue54);        
    Finteg10->SetBinContent(i+1,Fsum10);
    Finteg21->SetBinContent(i+1,Fsum21);
    Finteg32->SetBinContent(i+1,Fsum32);
    Finteg43->SetBinContent(i+1,Fsum43);    
    Finteg54->SetBinContent(i+1,Fsum54);        
  }

  Fdistr10extr->SetFillColor(kBlue);
  Fdistr21extr->SetFillColor(kBlue);
  Fdistr32extr->SetFillColor(kBlue);
  Fdistr43extr->SetFillColor(kBlue);  
  Fdistr54extr->SetFillColor(kBlue);    
  TArrow * Arrow1 = new TArrow (Ftest_10,0.8,Ftest_10,0.1);
  TArrow * Arrow2 = new TArrow (Ftest_21,0.8,Ftest_21,0.1);
  TArrow * Arrow3 = new TArrow (Ftest_32,0.8,Ftest_32,0.1);
  TArrow * Arrow4 = new TArrow (Ftest_43,0.8,Ftest_43,0.1);  
  TArrow * Arrow5 = new TArrow (Ftest_54,0.8,Ftest_54,0.1);    
  TArrow * Arrow1i = new TArrow (Ftest_10,0.1,Ftest_10,0.8);
  TArrow * Arrow2i = new TArrow (Ftest_21,0.1,Ftest_21,0.8);
  TArrow * Arrow3i = new TArrow (Ftest_32,0.1,Ftest_32,0.8);
  TArrow * Arrow4i = new TArrow (Ftest_43,0.1,Ftest_43,0.8);  
  TArrow * Arrow5i = new TArrow (Ftest_54,0.1,Ftest_54,0.8);   
  
  
  Arrow1->SetLineWidth(2);
  Arrow1i->SetLineWidth(2);
  Arrow2->SetLineWidth(2);
  Arrow2i->SetLineWidth(2);
  Arrow3->SetLineWidth(2);
  Arrow3i->SetLineWidth(2);
  Arrow4->SetLineWidth(2);
  Arrow4i->SetLineWidth(2);  
  Arrow5->SetLineWidth(2);
  Arrow5i->SetLineWidth(2);   
  Arrow1->SetLineColor(kBlue);
  Arrow1i->SetLineColor(kBlue);
  Arrow2->SetLineColor(kBlue);
  Arrow2i->SetLineColor(kBlue);
  Arrow3->SetLineColor(kBlue);
  Arrow3i->SetLineColor(kBlue);
  Arrow4->SetLineColor(kBlue);
  Arrow4i->SetLineColor(kBlue);  
  Arrow5->SetLineColor(kBlue);
  Arrow5i->SetLineColor(kBlue);   

  TCanvas * Ftest10 = new TCanvas ("Ftest10", "F test 10", 500, 500);
  Ftest10->Divide(2,2);
  Ftest10->cd(1);
  Data0->SetMinimum(0);
  Data0->SetMarkerStyle(20);
  Data0->SetMarkerSize(0.7);
  Data0->Draw("PE");
  Pol0->SetLineColor(kRed);
  Pol0->SetLineWidth(1);
  Pol0->Draw("SAME");
  Ftest10->cd(2);
  Data1->SetMinimum(0);
  Data1->SetMarkerStyle(20);
  Data1->SetMarkerSize(0.7);
  Data1->Draw("PE");
  Pol1->SetLineColor(kRed);
  Pol1->SetLineWidth(1);
  Pol1->Draw("SAME");
  Ftest10->cd(3);
  Ftest10->GetPad(3)->SetLogy();
  Fdistr10->Draw();
  Fdistr10extr->Draw("SAME");
  //Arrow1->Draw();
  Ftest10->cd(4);
  Finteg10->SetMinimum(0);
  Finteg10->Draw();
  Arrow1i->Draw();
  //Ftest10->Print("F_test_1.jpg");

  TCanvas * Ftest21 = new TCanvas ("Ftest21", "F test 21", 500, 500);
  Ftest21->Divide(2,2);
  Ftest21->cd(1);
  Data1->SetMinimum(0);
  Data1->SetMarkerStyle(20);
  Data1->SetMarkerSize(0.7);
  Data1->Draw("PE");
  Pol1->SetLineColor(kRed);
  Pol1->SetLineWidth(1);
  Pol1->Draw("SAME");
  Ftest21->cd(2);
  Data2->SetMinimum(0);
  Data2->SetMarkerStyle(20);
  Data2->SetMarkerSize(0.7);
  Data2->Draw("PE");
  Pol2->SetLineColor(kRed);
  Pol2->SetLineWidth(1);
  Pol2->Draw("SAME");
  Ftest21->cd(3);
  Ftest21->GetPad(3)->SetLogy();
  Fdistr21->Draw();
  Fdistr21extr->Draw("SAME");
  //Arrow2->Draw();
  Ftest21->cd(4);
  Finteg21->SetMinimum(0);
  Finteg21->Draw();		
  Arrow2i->Draw();
  //Ftest21->Print("F_test_2.jpg");

  TCanvas * Ftest32 = new TCanvas ("Ftest32", "F test 32", 500, 500);
  Ftest32->Divide(2,2);
  Ftest32->cd(1);
  Data2->SetMinimum(0);
  Data2->SetMarkerStyle(20);
  Data2->SetMarkerSize(0.7);
  Data2->Draw("PE");
  Pol2->SetLineColor(kRed);
  Pol2->SetLineWidth(1);
  Pol2->Draw("SAME");
  Ftest32->cd(2);
  Data3->SetMinimum(0);
  Data3->SetMarkerStyle(20);
  Data3->SetMarkerSize(0.7);
  Data3->Draw("PE");
  Pol3->SetLineColor(kRed);
  Pol3->SetLineWidth(1);
  Pol3->Draw("SAME");
  Ftest32->cd(3);
  Ftest32->GetPad(3)->SetLogy();
  Fdistr32->Draw();
  Fdistr32extr->Draw("SAME");
  //Arrow2->Draw();
  Ftest32->cd(4);
  Finteg32->SetMinimum(0);
  Finteg32->Draw();
  Arrow3i->Draw();
  //Ftest32->Print("F_test_3.jpg");

  TCanvas * Ftest43 = new TCanvas ("Ftest43", "F test 43", 500, 500);
  Ftest43->Divide(2,2);
  Ftest43->cd(1);
  Data3->SetMinimum(0);
  Data3->SetMarkerStyle(20);
  Data3->SetMarkerSize(0.7);
  Data3->Draw("PE");
  Pol3->SetLineColor(kRed);
  Pol3->SetLineWidth(1);
  Pol3->Draw("SAME");
  Ftest43->cd(2);
  Data4->SetMinimum(0);
  Data4->SetMarkerStyle(20);
  Data4->SetMarkerSize(0.7);
  Data4->Draw("PE");
  Pol4->SetLineColor(kRed);
  Pol4->SetLineWidth(1);
  Pol4->Draw("SAME");
  Ftest43->cd(3);
  Ftest43->GetPad(3)->SetLogy();
  Fdistr43->Draw();
  Fdistr43extr->Draw("SAME");
  //Arrow2->Draw();
  Ftest43->cd(4);
  Finteg43->SetMinimum(0);
  Finteg43->Draw();
  Arrow4i->Draw();

  TCanvas * Ftest54 = new TCanvas ("Ftest54", "F test 54", 500, 500);
  Ftest54->Divide(2,2);
  Ftest54->cd(1);
  Data4->SetMinimum(0);
  Data4->SetMarkerStyle(20);
  Data4->SetMarkerSize(0.7);
  Data4->Draw("PE");
  Pol4->SetLineColor(kRed);
  Pol4->SetLineWidth(1);
  Pol4->Draw("SAME");
  Ftest54->cd(2);
  Data5->SetMinimum(0);
  Data5->SetMarkerStyle(20);
  Data5->SetMarkerSize(0.7);
  Data5->Draw("PE");
  Pol5->SetLineColor(kRed);
  Pol5->SetLineWidth(1);
  Pol5->Draw("SAME");
  Ftest54->cd(3);
  Ftest54->GetPad(3)->SetLogy();
  Fdistr54->Draw();
  Fdistr54extr->Draw("SAME");
  //Arrow2->Draw();
  Ftest54->cd(4);
  Finteg54->SetMinimum(0);
  Finteg54->Draw();
  Arrow5i->Draw();
  
  TCanvas * P2 = new TCanvas ("P2","",300,600);
  P2->Divide(3,2);
  P2->cd(1);
  Data0->Fit("Pol0", "Q");
  Data0->Draw("PE");
  P2->cd(2);
  Data1->Fit("Pol1", "Q");
  Data1->Draw("PE");
  P2->cd(3);
  Data2->Fit("Pol2", "Q");
  Data2->Draw("PE");
  P2->cd(4);
  Data3->Fit("Pol3", "Q");
  Data3->Draw("PE");
  P2->cd(5);
  Data4->Fit("Pol4", "Q");
  Data4->Draw("PE"); 
  P2->cd(6);
  Data5->Fit("Pol5", "Q");
  Data5->Draw("PE");   
  //P2->Print("F_test_0.jpg");
  
}
