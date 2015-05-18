{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Jan  7 17:25:51 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,4.109375);
   grae->SetPointError(0,0,0,2.159027,6.191311);
   grae->SetPoint(1,40,5.609375);
   grae->SetPointError(1,0,0,2.925201,8.14277);
   grae->SetPoint(2,50,5.203125);
   grae->SetPointError(2,0,0,2.693024,7.56957);
   grae->SetPoint(3,60,4.976562);
   grae->SetPointError(3,0,0,2.57576,7.109165);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.109375);
   grae->SetPointError(0,0,0,1.391561,2.407881);
   grae->SetPoint(1,40,5.609375);
   grae->SetPointError(1,0,0,1.862531,3.152649);
   grae->SetPoint(2,50,5.203125);
   grae->SetPointError(2,0,0,1.714699,2.965803);
   grae->SetPoint(3,60,4.976562);
   grae->SetPointError(3,0,0,1.640035,2.796988);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,4.109375);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,5.609375);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,5.203125);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,4.976562);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
