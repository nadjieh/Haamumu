{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Tue Jan  6 15:05:33 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",0,0,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,11.95312);
   grae->SetPointError(0,0,0,6.326752,18.00895);
   grae->SetPoint(1,40,15.98438);
   grae->SetPointError(1,0,0,8.273163,23.30504);
   grae->SetPoint(2,50,17.20312);
   grae->SetPointError(2,0,0,8.903961,24.63195);
   grae->SetPoint(3,60,14.48438);
   grae->SetPointError(3,0,0,7.496796,20.69135);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,11.95312);
   grae->SetPointError(0,0,0,4.053075,7.003913);
   grae->SetPoint(1,40,15.98438);
   grae->SetPointError(1,0,0,5.267678,9.238589);
   grae->SetPoint(2,50,17.20312);
   grae->SetPointError(2,0,0,5.669319,9.805853);
   grae->SetPoint(3,60,14.48438);
   grae->SetPointError(3,0,0,4.831919,8.140683);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,11.95312);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,15.98438);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,17.20312);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,14.48438);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
