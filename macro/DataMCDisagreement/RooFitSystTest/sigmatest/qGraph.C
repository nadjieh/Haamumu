{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Feb  8 17:29:52 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(25);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   //gre->SetPoint(0,20,0.31);
   //gre->SetPointError(0,0,0.04624932);
   gre->SetPoint(1,22,0.69);
   gre->SetPointError(1,0,0.04624932);
   gre->SetPoint(2,24,0.65);
   gre->SetPointError(2,0,0.04769696);
   gre->SetPoint(3,26,0.67);
   gre->SetPointError(3,0,0.04702127);
   gre->SetPoint(4,28,0.7);
   gre->SetPointError(4,0,0.04582576);
   gre->SetPoint(5,30,0.68);
   gre->SetPointError(5,0,0.04664762);
   gre->SetPoint(6,32,0.71);
   gre->SetPointError(6,0,0.04537621);
   gre->SetPoint(7,34,0.8);
   gre->SetPointError(7,0,0.04);
   gre->SetPoint(8,36,0.72);
   gre->SetPointError(8,0,0.04489989);
   gre->SetPoint(9,38,0.73);
   gre->SetPointError(9,0,0.04439595);
   gre->SetPoint(10,40,0.67);
   gre->SetPointError(10,0,0.04702127);
   gre->SetPoint(11,42,0.72);
   gre->SetPointError(11,0,0.04489989);
   gre->SetPoint(12,44,0.73);
   gre->SetPointError(12,0,0.04439595);
   gre->SetPoint(13,46,0.76);
   gre->SetPointError(13,0,0.04270831);
   gre->SetPoint(14,48,0.73);
   gre->SetPointError(14,0,0.04439595);
   gre->SetPoint(15,50,0.69);
   gre->SetPointError(15,0,0.04624932);
   gre->SetPoint(16,52,0.75);
   gre->SetPointError(16,0,0.04330127);
   gre->SetPoint(17,54,0.66);
   gre->SetPointError(17,0,0.04737088);
   gre->SetPoint(18,56,0.66);
   gre->SetPointError(18,0,0.04737088);
   gre->SetPoint(19,58,0.68);
   gre->SetPointError(19,0,0.04664762);
   gre->SetPoint(20,60,0.75);
   gre->SetPointError(20,0,0.04330127);
   gre->SetPoint(21,62,0.76);
   gre->SetPointError(21,0,0.04270831);
   gre->SetPoint(22,64,0.75);
   gre->SetPointError(22,0,0.04330127);
   gre->SetPoint(23,66,0.71);
   gre->SetPointError(23,0,0.04537621);
   gre->SetPoint(24,68,0.67);
   gre->SetPointError(24,0,0.04702127);
   gre->Draw("ap");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
