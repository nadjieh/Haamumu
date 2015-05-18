{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Nov 16 22:23:02 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",0,0,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,15.84375);
   grae->SetPointError(0,0,0,6.281799,9.627757);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,2.703049,5.684751);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,2.669769,5.737521);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,15.84375);
   grae->SetPointError(0,0,0,3.778895,3.978693);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,1.678847,2.519895);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,1.658177,2.544185);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,15.84375);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
