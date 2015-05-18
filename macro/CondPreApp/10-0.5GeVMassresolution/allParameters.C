{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Apr 23 19:08:13 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c1_1
   TPad *c1_1 = new TPad("c1_1", "c1_1",0.01,0.51,0.24,0.99);
   c1_1->Draw();
   c1_1->cd();
   c1_1->Range(0,0,1,1);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("MeanV");
   grae->SetTitle("Mean Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,30.7858);
   grae->SetPointError(0,0,0,0.0504107,0.0504107);
   grae->SetPoint(1,40,39.9898);
   grae->SetPointError(1,0,0,0.0729742,0.0729742);
   grae->SetPoint(2,50,49.9067);
   grae->SetPointError(2,0,0,0.0543431,0.0543431);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   c1_2 = new TPad("c1_2", "c1_2",0.26,0.51,0.49,0.99);
   c1_2->Draw();
   c1_2->cd();
   c1_2->Range(0,0,1,1);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("SigmaV");
   grae->SetTitle("Sigma Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.000487618);
   grae->SetPointError(0,0,0,1.02105,1.02105);
   grae->SetPoint(1,40,0.000614142);
   grae->SetPointError(1,0,0,6.13889,6.13889);
   grae->SetPoint(2,50,2.91873e-07);
   grae->SetPointError(2,0,0,0.0275776,0.0275776);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_3
   c1_3 = new TPad("c1_3", "c1_3",0.51,0.51,0.74,0.99);
   c1_3->Draw();
   c1_3->cd();
   c1_3->Range(0,0,1,1);
   c1_3->SetFillColor(0);
   c1_3->SetBorderMode(0);
   c1_3->SetBorderSize(2);
   c1_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("WidthV");
   grae->SetTitle("Width Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.551957);
   grae->SetPointError(0,0,0,0.0264548,0.0264548);
   grae->SetPoint(1,40,0.59528);
   grae->SetPointError(1,0,0,0.0286809,0.0286809);
   grae->SetPoint(2,50,0.74515);
   grae->SetPointError(2,0,0,0.0158905,0.0158905);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_4
   c1_4 = new TPad("c1_4", "c1_4",0.76,0.51,0.99,0.99);
   c1_4->Draw();
   c1_4->cd();
   c1_4->Range(0,0,1,1);
   c1_4->SetFillColor(0);
   c1_4->SetBorderMode(0);
   c1_4->SetBorderSize(2);
   c1_4->SetFrameBorderMode(0);
   c1_4->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_5
   c1_5 = new TPad("c1_5", "c1_5",0.01,0.01,0.24,0.49);
   c1_5->Draw();
   c1_5->cd();
   c1_5->Range(0,0,1,1);
   c1_5->SetFillColor(0);
   c1_5->SetBorderMode(0);
   c1_5->SetBorderSize(2);
   c1_5->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Mean_cbs");
   grae->SetTitle("Mean CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.9628);
   grae->SetPointError(0,0,0,0.00623764,0.00623764);
   grae->SetPoint(1,40,39.9528);
   grae->SetPointError(1,0,0,0.0107845,0.0107845);
   grae->SetPoint(2,50,49.913);
   grae->SetPointError(2,0,0,0.0135731,0.0135731);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_5->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_6
   c1_6 = new TPad("c1_6", "c1_6",0.26,0.01,0.49,0.49);
   c1_6->Draw();
   c1_6->cd();
   c1_6->Range(0,0,1,1);
   c1_6->SetFillColor(0);
   c1_6->SetBorderMode(0);
   c1_6->SetBorderSize(2);
   c1_6->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Sigma_cbs");
   grae->SetTitle("Sigma CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.323546);
   grae->SetPointError(0,0,0,0.00679792,0.00679792);
   grae->SetPoint(1,40,0.465931);
   grae->SetPointError(1,0,0,0.00717722,0.00717722);
   grae->SetPoint(2,50,0.608408);
   grae->SetPointError(2,0,0,0.010637,0.010637);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_6->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_7
   c1_7 = new TPad("c1_7", "c1_7",0.51,0.01,0.74,0.49);
   c1_7->Draw();
   c1_7->cd();
   c1_7->Range(0,0,1,1);
   c1_7->SetFillColor(0);
   c1_7->SetBorderMode(0);
   c1_7->SetBorderSize(2);
   c1_7->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Ns");
   grae->SetTitle("N CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,2.40107);
   grae->SetPointError(0,0,0,0.170946,0.170946);
   grae->SetPoint(1,40,2.25472);
   grae->SetPointError(1,0,0,0.14342,0.14342);
   grae->SetPoint(2,50,2.28523);
   grae->SetPointError(2,0,0,0.154835,0.154835);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_7->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_8
   c1_8 = new TPad("c1_8", "c1_8",0.76,0.01,0.99,0.49);
   c1_8->Draw();
   c1_8->cd();
   c1_8->Range(0,0,1,1);
   c1_8->SetFillColor(0);
   c1_8->SetBorderMode(0);
   c1_8->SetBorderSize(2);
   c1_8->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Alphas");
   grae->SetTitle("Alpha CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.40974);
   grae->SetPointError(0,0,0,0.0614695,0.0614695);
   grae->SetPoint(1,40,1.50852);
   grae->SetPointError(1,0,0,0.0544729,0.0544729);
   grae->SetPoint(2,50,1.53224);
   grae->SetPointError(2,0,0,0.0620815,0.0620815);
   grae->SetPoint(3,60,0);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("ap");
   c1_8->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
