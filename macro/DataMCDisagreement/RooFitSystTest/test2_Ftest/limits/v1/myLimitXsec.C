{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Mon Mar  2 14:37:44 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,7.954193,22.47053);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,8.482269,24.06207);
   grae->SetPoint(2,50,15.79688);
   grae->SetPointError(2,0,0,8.29953,23.44095);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,7.923065,22.0498);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,5.126726,8.833694);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,5.467087,9.336308);
   grae->SetPoint(2,50,15.79688);
   grae->SetPointError(2,0,0,5.349306,9.256153);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,5.044765,8.706825);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,15.79688);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
