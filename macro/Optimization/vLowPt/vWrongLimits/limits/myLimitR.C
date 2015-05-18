{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Nov 19 11:37:36 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,6.40625);
   grae->SetPointError(0,0,0,2.990417,5.834383);
   grae->SetPoint(1,50,4.421875);
   grae->SetPointError(1,0,0,1.649567,2.687037);
   grae->SetPoint(2,60,5.421875);
   grae->SetPointError(2,0,0,2.520325,6.254513);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,6.40625);
   grae->SetPointError(0,0,0,1.880692,2.83445);
   grae->SetPoint(1,50,4.421875);
   grae->SetPointError(1,0,0,1.043866,1.110425);
   grae->SetPoint(2,60,5.421875);
   grae->SetPointError(2,0,0,1.565358,2.571807);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,40,6.40625);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,4.421875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,5.421875);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
