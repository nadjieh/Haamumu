{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Wed Jan  7 17:25:51 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",0,0,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,6.477081,18.57393);
   grae->SetPoint(1,40,16.82812);
   grae->SetPointError(1,0,0,8.775604,24.42831);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,8.079071,22.70871);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,7.72728,21.3275);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,4.174682,7.223644);
   grae->SetPoint(1,40,16.82812);
   grae->SetPointError(1,0,0,5.587592,9.457947);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,5.144096,8.897409);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,4.920104,8.390963);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,16.82812);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
