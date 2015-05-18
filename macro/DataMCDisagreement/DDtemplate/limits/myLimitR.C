{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 23 15:14:35 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,4.171875);
   grae->SetPointError(0,0,0,2.224457,6.303794);
   grae->SetPoint(1,40,5.265625);
   grae->SetPointError(1,0,0,2.694519,7.522099);
   grae->SetPoint(2,50,5.421875);
   grae->SetPointError(2,0,0,2.710938,7.582881);
   grae->SetPoint(3,60,3.953125);
   grae->SetPointError(3,0,0,2.107819,5.9559);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.171875);
   grae->SetPointError(0,0,0,1.416353,2.494391);
   grae->SetPoint(1,40,5.265625);
   grae->SetPointError(1,0,0,1.715651,2.95945);
   grae->SetPoint(2,50,5.421875);
   grae->SetPointError(2,0,0,1.736694,2.96082);
   grae->SetPoint(3,60,3.953125);
   grae->SetPointError(3,0,0,1.342088,2.316327);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,4.171875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,5.265625);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,5.421875);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,3.953125);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
