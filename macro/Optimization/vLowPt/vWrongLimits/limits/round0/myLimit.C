{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Nov 16 21:42:10 2014) by ROOT version5.34/19
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
   grae->SetPoint(0,40,5.28125);
   grae->SetPointError(0,0,0,2.093933,3.209252);
   grae->SetPoint(1,50,1.898438);
   grae->SetPointError(1,0,0,0.9010162,1.894917);
   grae->SetPoint(2,60,1.882812);
   grae->SetPointError(2,0,0,0.8899231,1.912507);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,5.28125);
   grae->SetPointError(0,0,0,1.259632,1.326231);
   grae->SetPoint(1,50,1.898438);
   grae->SetPointError(1,0,0,0.5596156,0.8399651);
   grae->SetPoint(2,60,1.882812);
   grae->SetPointError(2,0,0,0.5527257,0.8480618);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,40,5.28125);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,1.898438);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,1.882812);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
