{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Jan  6 15:05:33 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,3.984375);
   grae->SetPointError(0,0,0,2.108917,6.002982);
   grae->SetPoint(1,40,5.328125);
   grae->SetPointError(1,0,0,2.757721,7.768346);
   grae->SetPoint(2,50,5.734375);
   grae->SetPointError(2,0,0,2.967987,8.210651);
   grae->SetPoint(3,60,4.828125);
   grae->SetPointError(3,0,0,2.498932,6.897118);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,3.984375);
   grae->SetPointError(0,0,0,1.351025,2.334638);
   grae->SetPoint(1,40,5.328125);
   grae->SetPointError(1,0,0,1.755893,3.07953);
   grae->SetPoint(2,50,5.734375);
   grae->SetPointError(2,0,0,1.889773,3.268618);
   grae->SetPoint(3,60,4.828125);
   grae->SetPointError(3,0,0,1.61064,2.713561);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,30,3.984375);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,5.328125);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,5.734375);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,4.828125);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
