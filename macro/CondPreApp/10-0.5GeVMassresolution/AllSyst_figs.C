{
//=========Macro generated from canvas: C/C
//=========  (Sun May 17 19:54:27 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",6,82,1185,658);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.51,0.49,0.99);
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
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
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
   gre->SetPoint(0,30,29.96002);
   gre->SetPointError(0,0,0.00543284);
   gre->SetPoint(1,40,39.94894);
   gre->SetPointError(1,0,0.00720373);
   gre->SetPoint(2,50,49.90149);
   gre->SetPointError(2,0,0.008582456);
   gre->SetPoint(3,60,59.89711);
   gre->SetPointError(3,0,0.009716029);
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
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
   grae->Draw("p|>");
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.51,0.51,0.99,0.99);
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
   grae->SetPoint(0,30,0.2829472);
   grae->SetPointError(0,0,0,3.822831e-12,0.0003518551);
   grae->SetPoint(1,40,0.38439);
   grae->SetPointError(1,0,0,7.608081e-12,8.78418e-05);
   grae->SetPoint(2,50,0.4846037);
   grae->SetPointError(2,0,0,0.004872312,0.005046477);
   grae->SetPoint(3,60,0.5922342);
   grae->SetPointError(3,0,0,0.00389924,0.001086245);
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
   gre->SetPoint(0,30,0.2829472);
   gre->SetPointError(0,0,0.007311351);
   gre->SetPoint(1,40,0.38439);
   gre->SetPointError(1,0,0.008711803);
   gre->SetPoint(2,50,0.4846037);
   gre->SetPointError(2,0,0.01145726);
   gre->SetPoint(3,60,0.5922342);
   gre->SetPointError(3,0,0.01182519);
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
   grae->SetPoint(0,30,0.2829472);
   grae->SetPointError(0,0,0,3.822831e-12,0.0003518551);
   grae->SetPoint(1,40,0.38439);
   grae->SetPointError(1,0,0,7.608081e-12,8.78418e-05);
   grae->SetPoint(2,50,0.4846037);
   grae->SetPointError(2,0,0,0.004872312,0.005046477);
   grae->SetPoint(3,60,0.5922342);
   grae->SetPointError(3,0,0,0.00389924,0.001086245);
   grae->Draw("p|>");
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.01,0.01,0.49,0.49);
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
   grae->SetPoint(0,30,0.4990149);
   grae->SetPointError(0,0,0,0.005831031,0.005107821);
   grae->SetPoint(1,40,0.6987899);
   grae->SetPointError(1,0,0,0.003311269,7.93584e-05);
   grae->SetPoint(2,50,0.8236251);
   grae->SetPointError(2,0,0,0.02030932,0.01686733);
   grae->SetPoint(3,60,1.072813);
   grae->SetPointError(3,0,0,0.01711699,0.01718518);
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
   gre->SetPoint(0,30,0.4990149);
   gre->SetPointError(0,0,0.01795853);
   gre->SetPoint(1,40,0.6987899);
   gre->SetPointError(1,0,0.02211676);
   gre->SetPoint(2,50,0.8236251);
   gre->SetPointError(2,0,0.02945104);
   gre->SetPoint(3,60,1.072813);
   gre->SetPointError(3,0,0.02752898);
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
   grae->SetPoint(0,30,0.4990149);
   grae->SetPointError(0,0,0,0.005831031,0.005107821);
   grae->SetPoint(1,40,0.6987899);
   grae->SetPointError(1,0,0,0.003311269,7.93584e-05);
   grae->SetPoint(2,50,0.8236251);
   grae->SetPointError(2,0,0,0.02030932,0.01686733);
   grae->SetPoint(3,60,1.072813);
   grae->SetPointError(3,0,0,0.01711699,0.01718518);
   grae->Draw("p|>");
   C_3->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_4
   C_4 = new TPad("C_4", "C_4",0.51,0.01,0.99,0.49);
   C_4->Draw();
   C_4->cd();
   C_4->Range(0,0,1,1);
   C_4->SetFillColor(0);
   C_4->SetBorderMode(0);
   C_4->SetBorderSize(2);
   C_4->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("widthStat");
   gre->SetTitle("width");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,29.96002);
   gre->SetPointError(0,0,0.00543284);
   gre->SetPoint(1,40,39.94894);
   gre->SetPointError(1,0,0.00720373);
   gre->SetPoint(2,50,49.90149);
   gre->SetPointError(2,0,0.008582456);
   gre->SetPoint(3,60,59.89711);
   gre->SetPointError(3,0,0.009716029);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
   grae->Draw("p|>");
   C_4->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
