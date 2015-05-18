{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Wed Nov 19 11:37:36 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",0,0,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,19.21875);
   grae->SetPointError(0,0,0,8.971252,17.50315);
   grae->SetPoint(1,50,13.26562);
   grae->SetPointError(1,0,0,4.9487,8.061111);
   grae->SetPoint(2,60,16.26562);
   grae->SetPointError(2,0,0,7.560974,18.76354);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,19.21875);
   grae->SetPointError(0,0,0,5.642077,8.503349);
   grae->SetPoint(1,50,13.26562);
   grae->SetPointError(1,0,0,3.131599,3.331274);
   grae->SetPoint(2,60,16.26562);
   grae->SetPointError(2,0,0,4.696074,7.715422);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,19.21875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,13.26562);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,16.26562);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
