{
//=========Macro generated from canvas: rf109_chi2residpull/rf109_chi2residpull
//=========  (Thu Jan 22 18:36:42 2015) by ROOT version5.34/19
   TCanvas *rf109_chi2residpull = new TCanvas("rf109_chi2residpull", "rf109_chi2residpull",6,48,900,300);
   rf109_chi2residpull->Range(0,0,1,1);
   rf109_chi2residpull->SetFillColor(0);
   rf109_chi2residpull->SetBorderMode(0);
   rf109_chi2residpull->SetBorderSize(2);
   rf109_chi2residpull->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: rf109_chi2residpull_1
   TPad *rf109_chi2residpull_1 = new TPad("rf109_chi2residpull_1", "rf109_chi2residpull_1",0.01,0.01,0.49,0.99);
   rf109_chi2residpull_1->Draw();
   rf109_chi2residpull_1->cd();
   rf109_chi2residpull_1->Range(0,0,1,1);
   rf109_chi2residpull_1->SetFillColor(0);
   rf109_chi2residpull_1->SetBorderMode(0);
   rf109_chi2residpull_1->SetBorderSize(2);
   rf109_chi2residpull_1->SetLeftMargin(0.15);
   rf109_chi2residpull_1->SetFrameBorderMode(0);
   
   TH1D *frame_1c58080__1 = new TH1D("frame_1c58080__1","Residual Distribution",100,10,120);
   frame_1c58080__1->SetBinContent(1,54.19689);
   frame_1c58080__1->SetMinimum(-42.09381);
   frame_1c58080__1->SetMaximum(54.19689);
   frame_1c58080__1->SetEntries(1);
   frame_1c58080__1->SetDirectory(0);
   frame_1c58080__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_1c58080__1->SetLineColor(ci);
   frame_1c58080__1->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_1c58080__1->GetXaxis()->SetLabelFont(42);
   frame_1c58080__1->GetXaxis()->SetLabelSize(0.035);
   frame_1c58080__1->GetXaxis()->SetTitleSize(0.035);
   frame_1c58080__1->GetXaxis()->SetTitleFont(42);
   frame_1c58080__1->GetYaxis()->SetLabelFont(42);
   frame_1c58080__1->GetYaxis()->SetLabelSize(0.035);
   frame_1c58080__1->GetYaxis()->SetTitleSize(0.035);
   frame_1c58080__1->GetYaxis()->SetTitleOffset(1.6);
   frame_1c58080__1->GetYaxis()->SetTitleFont(42);
   frame_1c58080__1->GetZaxis()->SetLabelFont(42);
   frame_1c58080__1->GetZaxis()->SetLabelSize(0.035);
   frame_1c58080__1->GetZaxis()->SetTitleSize(0.035);
   frame_1c58080__1->GetZaxis()->SetTitleFont(42);
   frame_1c58080__1->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10);
   grae->SetName("resid_h_data_test_sum_norm_pf_Norm[eventSelectionamassMu]_Range[fit_nll_test_sum_norm_pf_data]_NormRange[fit_nll_test_sum_norm_pf_data]");
   grae->SetTitle("Residual of Histogram of data_plot__eventSelectionamassMu and Projection of Gaussian crystal ball and exponential PDF_pf");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,31,-15.4221);
   grae->SetPointError(0,0,0,17.8771,17.8771);
   grae->SetPoint(1,33,-1.876976);
   grae->SetPointError(1,0,0,21.0918,21.0918);
   grae->SetPoint(2,35,-7.22207);
   grae->SetPointError(2,0,0,21.1618,21.1618);
   grae->SetPoint(3,37,1.632995);
   grae->SetPointError(3,0,0,23.4451,23.4451);
   grae->SetPoint(4,39,23.2345);
   grae->SetPointError(4,0,0,26.58554,26.58554);
   grae->SetPoint(5,41,10.17604);
   grae->SetPointError(5,0,0,25,25);
   grae->SetPoint(6,43,5.940024);
   grae->SetPointError(6,0,0,23,23);
   grae->SetPoint(7,45,3.040375);
   grae->SetPointError(7,0,0,24.06009,24.06009);
   grae->SetPoint(8,47,-0.2893067);
   grae->SetPointError(8,0,0,24.24754,24.24754);
   grae->SetPoint(9,49,-20.86708);
   grae->SetPointError(9,0,0,16.84988,16.84988);
   grae->Draw("p");
   
   TH1D *frame_1c58080__2 = new TH1D("frame_1c58080__2","Residual Distribution",100,10,120);
   frame_1c58080__2->SetBinContent(1,54.19689);
   frame_1c58080__2->SetMinimum(-42.09381);
   frame_1c58080__2->SetMaximum(54.19689);
   frame_1c58080__2->SetEntries(1);
   frame_1c58080__2->SetDirectory(0);
   frame_1c58080__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_1c58080__2->SetLineColor(ci);
   frame_1c58080__2->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_1c58080__2->GetXaxis()->SetLabelFont(42);
   frame_1c58080__2->GetXaxis()->SetLabelSize(0.035);
   frame_1c58080__2->GetXaxis()->SetTitleSize(0.035);
   frame_1c58080__2->GetXaxis()->SetTitleFont(42);
   frame_1c58080__2->GetYaxis()->SetLabelFont(42);
   frame_1c58080__2->GetYaxis()->SetLabelSize(0.035);
   frame_1c58080__2->GetYaxis()->SetTitleSize(0.035);
   frame_1c58080__2->GetYaxis()->SetTitleOffset(1.6);
   frame_1c58080__2->GetYaxis()->SetTitleFont(42);
   frame_1c58080__2->GetZaxis()->SetLabelFont(42);
   frame_1c58080__2->GetZaxis()->SetLabelSize(0.035);
   frame_1c58080__2->GetZaxis()->SetTitleSize(0.035);
   frame_1c58080__2->GetZaxis()->SetTitleFont(42);
   frame_1c58080__2->Draw("AXISSAME");
   rf109_chi2residpull_1->Modified();
   rf109_chi2residpull->cd();
  
// ------------>Primitives in pad: rf109_chi2residpull_2
   rf109_chi2residpull_2 = new TPad("rf109_chi2residpull_2", "rf109_chi2residpull_2",0.51,0.01,0.99,0.99);
   rf109_chi2residpull_2->Draw();
   rf109_chi2residpull_2->cd();
   rf109_chi2residpull_2->Range(0,0,1,1);
   rf109_chi2residpull_2->SetFillColor(0);
   rf109_chi2residpull_2->SetBorderMode(0);
   rf109_chi2residpull_2->SetBorderSize(2);
   rf109_chi2residpull_2->SetLeftMargin(0.15);
   rf109_chi2residpull_2->SetFrameBorderMode(0);
   
   TH1D *frame_1c4a8f0__3 = new TH1D("frame_1c4a8f0__3","Pull Distribution",100,10,120);
   frame_1c4a8f0__3->SetBinContent(1,2.079571);
   frame_1c4a8f0__3->SetMinimum(-2.44403);
   frame_1c4a8f0__3->SetMaximum(2.079571);
   frame_1c4a8f0__3->SetEntries(1);
   frame_1c4a8f0__3->SetDirectory(0);
   frame_1c4a8f0__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_1c4a8f0__3->SetLineColor(ci);
   frame_1c4a8f0__3->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_1c4a8f0__3->GetXaxis()->SetLabelFont(42);
   frame_1c4a8f0__3->GetXaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__3->GetXaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__3->GetXaxis()->SetTitleFont(42);
   frame_1c4a8f0__3->GetYaxis()->SetLabelFont(42);
   frame_1c4a8f0__3->GetYaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__3->GetYaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__3->GetYaxis()->SetTitleOffset(1.6);
   frame_1c4a8f0__3->GetYaxis()->SetTitleFont(42);
   frame_1c4a8f0__3->GetZaxis()->SetLabelFont(42);
   frame_1c4a8f0__3->GetZaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__3->GetZaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__3->GetZaxis()->SetTitleFont(42);
   frame_1c4a8f0__3->Draw("FUNC");
   
   grae = new TGraphAsymmErrors(10);
   grae->SetName("pull_h_data_test_sum_norm_pf_Norm[eventSelectionamassMu]_Range[fit_nll_test_sum_norm_pf_data]_NormRange[fit_nll_test_sum_norm_pf_data]");
   grae->SetTitle("Pull of Histogram of data_plot__eventSelectionamassMu and Projection of Gaussian crystal ball and exponential PDF_pf");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,31,-0.8626734);
   grae->SetPointError(0,0,0,1,1);
   grae->SetPoint(1,33,-0.08899082);
   grae->SetPointError(1,0,0,1,1);
   grae->SetPoint(2,35,-0.3412786);
   grae->SetPointError(2,0,0,1,1);
   grae->SetPoint(3,37,0.06965187);
   grae->SetPointError(3,0,0,1,1);
   grae->SetPoint(4,39,0.8739527);
   grae->SetPointError(4,0,0,1,1);
   grae->SetPoint(5,41,0.4070418);
   grae->SetPointError(5,0,0,1,1);
   grae->SetPoint(6,43,0.2582619);
   grae->SetPointError(6,0,0,1,1);
   grae->SetPoint(7,45,0.1263659);
   grae->SetPointError(7,0,0,1,1);
   grae->SetPoint(8,47,-0.01193139);
   grae->SetPointError(8,0,0,1,1);
   grae->SetPoint(9,49,-1.238411);
   grae->SetPointError(9,0,0,1,1);
   grae->Draw("p");
   
   TH1D *frame_1c4a8f0__4 = new TH1D("frame_1c4a8f0__4","Pull Distribution",100,10,120);
   frame_1c4a8f0__4->SetBinContent(1,2.079571);
   frame_1c4a8f0__4->SetMinimum(-2.44403);
   frame_1c4a8f0__4->SetMaximum(2.079571);
   frame_1c4a8f0__4->SetEntries(1);
   frame_1c4a8f0__4->SetDirectory(0);
   frame_1c4a8f0__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_1c4a8f0__4->SetLineColor(ci);
   frame_1c4a8f0__4->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_1c4a8f0__4->GetXaxis()->SetLabelFont(42);
   frame_1c4a8f0__4->GetXaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__4->GetXaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__4->GetXaxis()->SetTitleFont(42);
   frame_1c4a8f0__4->GetYaxis()->SetLabelFont(42);
   frame_1c4a8f0__4->GetYaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__4->GetYaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__4->GetYaxis()->SetTitleOffset(1.6);
   frame_1c4a8f0__4->GetYaxis()->SetTitleFont(42);
   frame_1c4a8f0__4->GetZaxis()->SetLabelFont(42);
   frame_1c4a8f0__4->GetZaxis()->SetLabelSize(0.035);
   frame_1c4a8f0__4->GetZaxis()->SetTitleSize(0.035);
   frame_1c4a8f0__4->GetZaxis()->SetTitleFont(42);
   frame_1c4a8f0__4->Draw("AXISSAME");
   rf109_chi2residpull_2->Modified();
   rf109_chi2residpull->cd();
   rf109_chi2residpull->Modified();
   rf109_chi2residpull->cd();
   rf109_chi2residpull->SetSelected(rf109_chi2residpull);
}
