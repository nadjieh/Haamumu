{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Mar  8 15:21:25 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,4.453125);
   grae->SetPointError(0,0,0,2.348328,5.593093);
   grae->SetPoint(1,40,4.921875);
   grae->SetPointError(1,0,0,2.451324,5.781799);
   grae->SetPoint(2,50,4.890625);
   grae->SetPointError(2,0,0,2.454865,5.707929);
   grae->SetPoint(3,60,4.578125);
   grae->SetPointError(3,0,0,2.315887,5.398378);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,4.453125);
   grae->SetPointError(0,0,0,1.476878,2.360796);
   grae->SetPoint(1,40,4.921875);
   grae->SetPointError(1,0,0,1.541653,2.413113);
   grae->SetPoint(2,50,4.890625);
   grae->SetPointError(2,0,0,1.563058,2.43678);
   grae->SetPoint(3,60,4.578125);
   grae->SetPointError(3,0,0,1.438383,2.281075);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,4.453125);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,4.921875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,4.890625);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,4.578125);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
