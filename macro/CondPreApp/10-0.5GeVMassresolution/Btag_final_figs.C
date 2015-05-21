{
//=========Macro generated from canvas: C/C
//=========  (Tue May 19 18:22:35 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",6,82,1185,658);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.01,0.3233333,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(0,0,1,1);
   C_1->SetFillColor(0);
   C_1->SetBorderMode(0);
   C_1->SetBorderSize(2);
   C_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,9.521273e-13,9.521273e-13);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.0001003497,0.0001234047);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,1.253383e-05,0.0001765191);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.0002689503,0.0001844169);
   grae->Draw("alp");
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("meanStat");
   gre->SetTitle("mean");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,29.95972);
   gre->SetPointError(0,0,0.005422914);
   gre->SetPoint(1,40,39.94931);
   gre->SetPointError(1,0,0.007195136);
   gre->SetPoint(2,50,49.90091);
   gre->SetPointError(2,0,0.008555621);
   gre->SetPoint(3,60,59.89713);
   gre->SetPointError(3,0,0.009706139);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,9.521273e-13,9.521273e-13);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.0001003497,0.0001234047);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,1.253383e-05,0.0001765191);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.0002689503,0.0001844169);
   grae->Draw("p|>");
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.3433333,0.01,0.6566667,0.99);
   C_2->Draw();
   C_2->cd();
   C_2->Range(0,0,1,1);
   C_2->SetFillColor(0);
   C_2->SetBorderMode(0);
   C_2->SetBorderSize(2);
   C_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,3.28626e-13,3.28626e-13);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,0.0001946976,8.571902e-05);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.0007657354,0.0002323988);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.0001749127,0.0002548107);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigmaStat");
   gre->SetTitle("sigma");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,0.2858389);
   gre->SetPointError(0,0,0.006380716);
   gre->SetPoint(1,40,0.3810689);
   gre->SetPointError(1,0,0.008510948);
   gre->SetPoint(2,50,0.487961);
   gre->SetPointError(2,0,0.01039632);
   gre->SetPoint(3,60,0.591851);
   gre->SetPointError(3,0,0.0110008);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,3.28626e-13,3.28626e-13);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,0.0001946976,8.571902e-05);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.0007657354,0.0002323988);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.0001749127,0.0002548107);
   grae->Draw("p|>");
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.6766667,0.01,0.99,0.99);
   C_3->Draw();
   C_3->cd();
   C_3->Range(0,0,1,1);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,2.453593e-13,2.453593e-13);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,8.554968e-05,9.314515e-05);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.002805451,0.0002399093);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.0002242547,0.0001468295);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigma_cbStat");
   gre->SetTitle("sigma_cb");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,0.5096423);
   gre->SetPointError(0,0,0.01356009);
   gre->SetPoint(1,40,0.6835205);
   gre->SetPointError(1,0,0.01814551);
   gre->SetPoint(2,50,0.841637);
   gre->SetPointError(2,0,0.02155012);
   gre->SetPoint(3,60,1.071645);
   gre->SetPointError(3,0,0.02345126);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,2.453593e-13,2.453593e-13);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,8.554968e-05,9.314515e-05);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.002805451,0.0002399093);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.0002242547,0.0001468295);
   grae->Draw("p|>");
   C_3->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
