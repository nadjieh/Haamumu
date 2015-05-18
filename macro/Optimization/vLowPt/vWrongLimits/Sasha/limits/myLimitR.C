{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Nov 30 17:02:38 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,350,496);
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
   grae->SetPoint(0,40,82.625);
   grae->SetPointError(0,0,0,41.47388,115.557);
   grae->SetPoint(1,50,71.625);
   grae->SetPointError(1,0,0,35.95239,100.1727);
   grae->SetPoint(2,60,56.5);
   grae->SetPointError(2,0,0,28.36035,79.0193);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,82.625);
   grae->SetPointError(0,0,0,26.4072,45.12051);
   grae->SetPoint(1,50,71.625);
   grae->SetPointError(1,0,0,22.89156,39.11354);
   grae->SetPoint(2,60,56.5);
   grae->SetPointError(2,0,0,18.05757,30.85397);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,40,82.625);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,71.625);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,56.5);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
