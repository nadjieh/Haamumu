{
//=========Macro generated from canvas: C/C
//=========  (Tue May 19 18:22:35 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",6,82,1185,658);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
     Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha

  /* TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
      grae = new TGraphAsymmErrors(4);
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.002392026);
   grae->SetPoint(1,40,6.660049e-05);
   grae->SetPoint(2,50,0.009655952);
   grae->SetPoint(3,60,0.0135774);
   grae->Draw("alp");
   */
      gre = new TGraphErrors(4);
   gre->SetName("sigmaStat");
   gre->SetTitle("sigma");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,sqrt(pow(0.01356009,2)+pow(0.002392026,2)));
   gre->SetPoint(1,40,sqrt(pow(0.01814551,2)+pow(6.660049e-05,2)));
   gre->SetPoint(2,50,sqrt(pow(0.02155012,2)+pow(0.009655952,2)));
   gre->SetPoint(3,60,sqrt(pow(0.02345126,2)+pow(0.0135774,2)));
   gre->Draw("alp");
  
  
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
