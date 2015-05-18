{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Nov 30 13:37:08 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "#Delta m(a,a)",506,106,500,500);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(0,0,1,1);
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
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,46.11694,128.4938);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,50.12439,136.9824);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,49.08472,132.092);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,29.36353,50.17183);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,31.71934,53.77645);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,31.25316,51.48422);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,91.875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,101.4375);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,100.125);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(kBlue);
   grae->SetFillStyle(3005);   
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,124.4216,346.6709);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,107.8572,300.5181);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,85.08105,237.0579);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(kRed);
   grae->SetFillStyle(3004);      
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,79.22159,135.3615);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,68.67469,117.3406);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,54.1727,92.5619);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   
   TLegend *leg = new TLegend(0.578629,0.6181435,0.9193548,0.943038,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","","pf");

   ci = TColor::GetColor("#0000ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3005);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","","pf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(kGreen);
   entry->SetLineStyle(1);
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
      entry->SetLineColor(kWhite);
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
