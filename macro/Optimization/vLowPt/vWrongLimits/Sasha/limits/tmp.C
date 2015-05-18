{
//=========Macro generated from canvas: c1_n2/#Delta m(a,a)
//=========  (Sun Nov 30 17:27:56 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "#Delta m(a,a)",509,130,500,500);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(33.31707,-142.6829,62.58537,954.8781);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetTickx(1);
   c1_n2->SetTicky(1);
   c1_n2->SetLeftMargin(0.16);
   c1_n2->SetRightMargin(0.02);
   c1_n2->SetTopMargin(0.05);
   c1_n2->SetBottomMargin(0.13);
   c1_n2->SetFrameFillStyle(0);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameFillStyle(0);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");
   grae->SetFillColor(3);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,46.11694,128.4938);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,50.12439,136.9824);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,49.08472,132.092);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","",100,38,62);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(900);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.035);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleSize(0.035);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("");
   grae->SetFillColor(5);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,29.36353,50.17183);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,31.71934,53.77645);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,31.25316,51.48422);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","",100,38,62);
   Graph_g12->SetMinimum(53.24122);
   Graph_g12->SetMaximum(164.4842);
   Graph_g12->SetDirectory(0);
   Graph_g12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g12->SetLineColor(ci);
   Graph_g12->GetXaxis()->SetLabelFont(42);
   Graph_g12->GetXaxis()->SetLabelSize(0.035);
   Graph_g12->GetXaxis()->SetTitleSize(0.035);
   Graph_g12->GetXaxis()->SetTitleFont(42);
   Graph_g12->GetYaxis()->SetLabelFont(42);
   Graph_g12->GetYaxis()->SetLabelSize(0.035);
   Graph_g12->GetYaxis()->SetTitleSize(0.035);
   Graph_g12->GetYaxis()->SetTitleFont(42);
   Graph_g12->GetZaxis()->SetLabelFont(42);
   Graph_g12->GetZaxis()->SetLabelSize(0.035);
   Graph_g12->GetZaxis()->SetTitleSize(0.035);
   Graph_g12->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g12);
   
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,38,62);
   Graph_g003->SetMinimum(90.91875);
   Graph_g003->SetMaximum(102.3937);
   Graph_g003->SetDirectory(0);
   Graph_g003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g003->SetLineColor(ci);
   Graph_g003->GetXaxis()->SetLabelFont(42);
   Graph_g003->GetXaxis()->SetLabelSize(0.035);
   Graph_g003->GetXaxis()->SetTitleSize(0.035);
   Graph_g003->GetXaxis()->SetTitleFont(42);
   Graph_g003->GetYaxis()->SetLabelFont(42);
   Graph_g003->GetYaxis()->SetLabelSize(0.035);
   Graph_g003->GetYaxis()->SetTitleSize(0.035);
   Graph_g003->GetYaxis()->SetTitleFont(42);
   Graph_g003->GetZaxis()->SetLabelFont(42);
   Graph_g003->GetZaxis()->SetLabelSize(0.035);
   Graph_g003->GetZaxis()->SetTitleSize(0.035);
   Graph_g003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g003);
   
   grae->Draw("p");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");

   ci = TColor::GetColor("#0000ff");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3005);
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,124.4216,346.6709);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,107.8572,300.5181);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,85.08105,237.0579);
   
   TH1F *Graph_g24 = new TH1F("Graph_g24","",100,38,62);
   Graph_g24->SetMinimum(33.40625);
   Graph_g24->SetMaximum(645.5586);
   Graph_g24->SetDirectory(0);
   Graph_g24->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g24->SetLineColor(ci);
   Graph_g24->GetXaxis()->SetLabelFont(42);
   Graph_g24->GetXaxis()->SetLabelSize(0.035);
   Graph_g24->GetXaxis()->SetTitleSize(0.035);
   Graph_g24->GetXaxis()->SetTitleFont(42);
   Graph_g24->GetYaxis()->SetLabelFont(42);
   Graph_g24->GetYaxis()->SetLabelSize(0.035);
   Graph_g24->GetYaxis()->SetTitleSize(0.035);
   Graph_g24->GetYaxis()->SetTitleFont(42);
   Graph_g24->GetZaxis()->SetLabelFont(42);
   Graph_g24->GetZaxis()->SetLabelSize(0.035);
   Graph_g24->GetZaxis()->SetTitleSize(0.035);
   Graph_g24->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g24);
   
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ff0000");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3004);
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,79.22159,135.3615);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,68.67469,117.3406);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,54.1727,92.5619);
   
   TH1F *Graph_g15 = new TH1F("Graph_g15","Expected 1 #sigma",100,38,62);
   Graph_g15->SetMinimum(88.53638);
   Graph_g15->SetMaximum(410.0274);
   Graph_g15->SetDirectory(0);
   Graph_g15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g15->SetLineColor(ci);
   Graph_g15->GetXaxis()->SetLabelFont(42);
   Graph_g15->GetXaxis()->SetLabelSize(0.035);
   Graph_g15->GetXaxis()->SetTitleSize(0.035);
   Graph_g15->GetXaxis()->SetTitleFont(42);
   Graph_g15->GetYaxis()->SetLabelFont(42);
   Graph_g15->GetYaxis()->SetLabelSize(0.035);
   Graph_g15->GetYaxis()->SetTitleSize(0.035);
   Graph_g15->GetYaxis()->SetTitleFont(42);
   Graph_g15->GetZaxis()->SetLabelFont(42);
   Graph_g15->GetZaxis()->SetLabelSize(0.035);
   Graph_g15->GetZaxis()->SetTitleSize(0.035);
   Graph_g15->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g15);
   
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,0,0);
   
   TH1F *Graph_g006 = new TH1F("Graph_g006","Graph",100,38,62);
   Graph_g006->SetMinimum(161.6625);
   Graph_g006->SetMaximum(255.7125);
   Graph_g006->SetDirectory(0);
   Graph_g006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g006->SetLineColor(ci);
   Graph_g006->GetXaxis()->SetLabelFont(42);
   Graph_g006->GetXaxis()->SetLabelSize(0.035);
   Graph_g006->GetXaxis()->SetTitleSize(0.035);
   Graph_g006->GetXaxis()->SetTitleFont(42);
   Graph_g006->GetYaxis()->SetLabelFont(42);
   Graph_g006->GetYaxis()->SetLabelSize(0.035);
   Graph_g006->GetYaxis()->SetTitleSize(0.035);
   Graph_g006->GetYaxis()->SetTitleFont(42);
   Graph_g006->GetZaxis()->SetLabelFont(42);
   Graph_g006->GetZaxis()->SetLabelSize(0.035);
   Graph_g006->GetZaxis()->SetTitleSize(0.035);
   Graph_g006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g006);
   
   grae->Draw("p");
   
   TLegend *leg = new TLegend(0.578629,0.6181435,0.9193548,0.943038,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","","lpf");

   ci = TColor::GetColor("#0000ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3005);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.577621,0.6656118,0.9183468,0.8871308,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("NULL","Expected 95%","lpf");

   ci = TColor::GetColor("#ff0000");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3004);
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","","l");
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","Expected 68%","lpf");
   entry->SetFillColor(5);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
