{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Fri Feb 13 15:53:41 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,34,700,500);
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
   grae->SetPoint(0,30,24.09375);
   grae->SetPointError(0,0,0,12.28217,32.25213);
   grae->SetPoint(1,40,25.96875);
   grae->SetPointError(1,0,0,13.23798,34.81014);
   grae->SetPoint(2,50,26.0625);
   grae->SetPointError(2,0,0,13.18396,35.13709);
   grae->SetPoint(3,60,17.39062);
   grae->SetPointError(3,0,0,8.933075,23.44579);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,24.09375);
   grae->SetPointError(0,0,0,7.72433,12.77315);
   grae->SetPoint(1,40,25.96875);
   grae->SetPointError(1,0,0,8.325445,13.87068);
   grae->SetPoint(2,50,26.0625);
   grae->SetPointError(2,0,0,8.394475,14.02464);
   grae->SetPoint(3,60,17.39062);
   grae->SetPointError(3,0,0,5.687857,9.358169);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,24.09375);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,25.96875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,26.0625);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,17.39062);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
