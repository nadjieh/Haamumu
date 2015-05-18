{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Thu Nov 27 20:53:20 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,10,700,500);
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
   grae->SetPoint(0,40,7.054688);
   grae->SetPointError(0,0,0,3.844254,7.56864);
   grae->SetPoint(1,50,6.398438);
   grae->SetPointError(1,0,0,3.861557,7.159278);
   grae->SetPoint(2,60,4.851562);
   grae->SetPointError(2,0,0,2.302597,4.817335);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,40,7.054688);
   grae->SetPointError(0,0,0,2.327575,3.402555);
   grae->SetPoint(1,50,6.398438);
   grae->SetPointError(1,0,0,2.277715,3.188056);
   grae->SetPoint(2,60,4.851562);
   grae->SetPointError(2,0,0,1.430129,2.1079);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,7.054688);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,6.398438);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,4.851562);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
