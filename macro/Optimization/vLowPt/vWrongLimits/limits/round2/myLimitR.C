{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 27 20:53:20 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",10,10,700,500);
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
   grae->SetPoint(0,40,2.351562);
   grae->SetPointError(0,0,0,1.281418,2.52288);
   grae->SetPoint(1,50,2.132812);
   grae->SetPointError(1,0,0,1.287186,2.386426);
   grae->SetPoint(2,60,1.617188);
   grae->SetPointError(2,0,0,0.7675323,1.605778);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,2.351562);
   grae->SetPointError(0,0,0,0.7758584,1.134185);
   grae->SetPoint(1,50,2.132812);
   grae->SetPointError(1,0,0,0.7592385,1.062685);
   grae->SetPoint(2,60,1.617188);
   grae->SetPointError(2,0,0,0.4767096,0.7026334);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,40,2.351562);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,2.132812);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,1.617188);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
