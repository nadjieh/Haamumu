{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Mar  8 15:21:25 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,13.35938);
   grae->SetPointError(0,0,0,7.044983,16.77928);
   grae->SetPoint(1,40,14.76562);
   grae->SetPointError(1,0,0,7.353973,17.3454);
   grae->SetPoint(2,50,14.67188);
   grae->SetPointError(2,0,0,7.364594,17.12379);
   grae->SetPoint(3,60,13.73438);
   grae->SetPointError(3,0,0,6.947662,16.19514);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,13.35938);
   grae->SetPointError(0,0,0,4.430634,7.082388);
   grae->SetPoint(1,40,14.76562);
   grae->SetPointError(1,0,0,4.624959,7.239339);
   grae->SetPoint(2,50,14.67188);
   grae->SetPointError(2,0,0,4.689175,7.31034);
   grae->SetPoint(3,60,13.73438);
   grae->SetPointError(3,0,0,4.315149,6.843226);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,13.35938);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,14.76562);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,14.67188);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,13.73438);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
