{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Jan 25 01:37:13 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.140625);
   grae->SetPointError(0,0,0,2.207794,6.256574);
   grae->SetPoint(1,40,5.234375);
   grae->SetPointError(1,0,0,2.688751,7.477458);
   grae->SetPoint(2,50,5.359375);
   grae->SetPointError(2,0,0,2.66922,7.513828);
   grae->SetPoint(3,60,3.96875);
   grae->SetPointError(3,0,0,2.108398,5.979441);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.140625);
   grae->SetPointError(0,0,0,1.405744,2.475706);
   grae->SetPoint(1,40,5.234375);
   grae->SetPointError(1,0,0,1.711978,2.941887);
   grae->SetPoint(2,50,5.359375);
   grae->SetPointError(2,0,0,1.699543,2.969415);
   grae->SetPoint(3,60,3.96875);
   grae->SetPointError(3,0,0,1.350693,2.325482);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,4.140625);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,5.234375);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,5.359375);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,3.96875);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
