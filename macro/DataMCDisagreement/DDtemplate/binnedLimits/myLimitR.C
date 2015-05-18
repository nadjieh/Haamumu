{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Feb 13 15:53:41 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,8.03125);
   grae->SetPointError(0,0,0,4.094055,10.75071);
   grae->SetPoint(1,40,8.65625);
   grae->SetPointError(1,0,0,4.412659,11.60338);
   grae->SetPoint(2,50,8.6875);
   grae->SetPointError(2,0,0,4.394653,11.71236);
   grae->SetPoint(3,60,5.796875);
   grae->SetPointError(3,0,0,2.977692,7.815263);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,8.03125);
   grae->SetPointError(0,0,0,2.574777,4.257716);
   grae->SetPoint(1,40,8.65625);
   grae->SetPointError(1,0,0,2.775148,4.623561);
   grae->SetPoint(2,50,8.6875);
   grae->SetPointError(2,0,0,2.798158,4.674881);
   grae->SetPoint(3,60,5.796875);
   grae->SetPointError(3,0,0,1.895952,3.11939);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,8.03125);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,8.65625);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,8.6875);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,5.796875);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
