{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Mar  2 14:37:44 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
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
   grae->SetPoint(0,30,4.796875);
   grae->SetPointError(0,0,0,2.651398,7.490176);
   grae->SetPoint(1,40,5.421875);
   grae->SetPointError(1,0,0,2.827423,8.020689);
   grae->SetPoint(2,50,5.265625);
   grae->SetPointError(2,0,0,2.76651,7.81365);
   grae->SetPoint(3,60,4.953125);
   grae->SetPointError(3,0,0,2.641022,7.349932);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.796875);
   grae->SetPointError(0,0,0,1.708909,2.944565);
   grae->SetPoint(1,40,5.421875);
   grae->SetPointError(1,0,0,1.822362,3.112103);
   grae->SetPoint(2,50,5.265625);
   grae->SetPointError(2,0,0,1.783102,3.085384);
   grae->SetPoint(3,60,4.953125);
   grae->SetPointError(3,0,0,1.681588,2.902275);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,4.796875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,5.421875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,5.265625);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,4.953125);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
