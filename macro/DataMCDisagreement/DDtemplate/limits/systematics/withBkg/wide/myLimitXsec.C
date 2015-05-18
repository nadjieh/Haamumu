{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Jan 25 02:50:36 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",13,34,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 95%");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,6.623383,18.76972);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,8.083557,22.5663);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,8.00766,22.54148);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,6.525238,18.25606);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,4.217232,7.427118);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,5.146952,8.878349);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,5.098628,8.908244);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,4.205719,7.125363);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
