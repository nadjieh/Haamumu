{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Nov 30 17:02:38 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",0,0,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(kBlue);
   grae->SetFillStyle(3005);   
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,124.4216,346.6709);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,107.8572,300.5181);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,85.08105,237.0579);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(kRed);
   grae->SetFillStyle(3004);      
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,79.22159,135.3615);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,68.67469,117.3406);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,54.1727,92.5619);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,247.875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,214.875);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,169.5);
   grae->SetPointError(2,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
