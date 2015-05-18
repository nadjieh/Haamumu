{
//=========Macro generated from canvas: C/C
//=========  (Sun May 17 19:58:47 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",249,78,728,662);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.51,0.49,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(22.5,22.47492,67.5,67.3817);
   C_1->SetFillColor(0);
   C_1->SetBorderMode(0);
   C_1->SetBorderSize(2);
   C_1->SetFrameBorderMode(0);
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
   
   TH1F *Graph_Graph_mean11 = new TH1F("Graph_Graph_mean11","mean",100,27,63);
   Graph_Graph_mean11->SetMinimum(26.9656);
   Graph_Graph_mean11->SetMaximum(62.89102);
   Graph_Graph_mean11->SetDirectory(0);
   Graph_Graph_mean11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_mean11->SetLineColor(ci);
   Graph_Graph_mean11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_mean11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_mean11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_mean11->GetXaxis()->SetTitleFont(42);
   Graph_Graph_mean11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_mean11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_mean11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_mean11->GetYaxis()->SetTitleFont(42);
   Graph_Graph_mean11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_mean11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_mean11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_mean11->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_mean11);
   
   grae->Draw("alp");
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("meanStat");
   gre->SetTitle("mean");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,29.96002);
   gre->SetPointError(0,0,0.00543284);
   gre->SetPoint(1,40,39.94894);
   gre->SetPointError(1,0,0.00720373);
   gre->SetPoint(2,50,49.90149);
   gre->SetPointError(2,0,0.008582456);
   gre->SetPoint(3,60,59.89711);
   gre->SetPointError(3,0,0.009716029);
   
   TH1F *Graph_Graph_meanStat11 = new TH1F("Graph_Graph_meanStat11","mean",100,27,63);
   Graph_Graph_meanStat11->SetMinimum(26.95936);
   Graph_Graph_meanStat11->SetMaximum(62.90205);
   Graph_Graph_meanStat11->SetDirectory(0);
   Graph_Graph_meanStat11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_meanStat11->SetLineColor(ci);
   Graph_Graph_meanStat11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_meanStat11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_meanStat11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_meanStat11->GetXaxis()->SetTitleFont(42);
   Graph_Graph_meanStat11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_meanStat11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_meanStat11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_meanStat11->GetYaxis()->SetTitleFont(42);
   Graph_Graph_meanStat11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_meanStat11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_meanStat11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_meanStat11->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_meanStat11);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
   
   TH1F *Graph_Graph_mean22 = new TH1F("Graph_Graph_mean22","mean",100,27,63);
   Graph_Graph_mean22->SetMinimum(26.9656);
   Graph_Graph_mean22->SetMaximum(62.89102);
   Graph_Graph_mean22->SetDirectory(0);
   Graph_Graph_mean22->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_mean22->SetLineColor(ci);
   Graph_Graph_mean22->GetXaxis()->SetLabelFont(42);
   Graph_Graph_mean22->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_mean22->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_mean22->GetXaxis()->SetTitleFont(42);
   Graph_Graph_mean22->GetYaxis()->SetLabelFont(42);
   Graph_Graph_mean22->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_mean22->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_mean22->GetYaxis()->SetTitleFont(42);
   Graph_Graph_mean22->GetZaxis()->SetLabelFont(42);
   Graph_Graph_mean22->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_mean22->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_mean22->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_mean22);
   
   grae->Draw("p|>");
   
   TPaveText *pt = new TPaveText(0.4538371,0.94,0.5461629,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("mean");
   pt->Draw();
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.51,0.51,0.99,0.99);
   C_2->Draw();
   C_2->cd();
   C_2->Range(22.5,0.2053539,67.5,0.6709138);
   C_2->SetFillColor(0);
   C_2->SetBorderMode(0);
   C_2->SetBorderSize(2);
   C_2->SetFrameBorderMode(0);
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
   
   TH1F *Graph_Graph_sigma33 = new TH1F("Graph_Graph_sigma33","sigma",100,27,63);
   Graph_Graph_sigma33->SetMinimum(0.2519099);
   Graph_Graph_sigma33->SetMaximum(0.6243578);
   Graph_Graph_sigma33->SetDirectory(0);
   Graph_Graph_sigma33->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigma33->SetLineColor(ci);
   Graph_Graph_sigma33->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigma33->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma33->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma33->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigma33->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigma33->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma33->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma33->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigma33->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigma33->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma33->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma33->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_sigma33);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigmaStat");
   gre->SetTitle("sigma");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.2829472);
   gre->SetPointError(0,0,0.007311351);
   gre->SetPoint(1,40,0.38439);
   gre->SetPointError(1,0,0.008711803);
   gre->SetPoint(2,50,0.4846037);
   gre->SetPointError(2,0,0.01145726);
   gre->SetPoint(3,60,0.5922342);
   gre->SetPointError(3,0,0.01182519);
   
   TH1F *Graph_Graph_sigmaStat22 = new TH1F("Graph_Graph_sigmaStat22","sigma",100,27,63);
   Graph_Graph_sigmaStat22->SetMinimum(0.2427935);
   Graph_Graph_sigmaStat22->SetMaximum(0.6369017);
   Graph_Graph_sigmaStat22->SetDirectory(0);
   Graph_Graph_sigmaStat22->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigmaStat22->SetLineColor(ci);
   Graph_Graph_sigmaStat22->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigmaStat22->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigmaStat22->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigmaStat22->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigmaStat22->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigmaStat22->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigmaStat22->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigmaStat22->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigmaStat22->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigmaStat22->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigmaStat22->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigmaStat22->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_sigmaStat22);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.2829472);
   grae->SetPointError(0,0,0,3.822831e-12,0.0003518551);
   grae->SetPoint(1,40,0.38439);
   grae->SetPointError(1,0,0,7.608081e-12,8.78418e-05);
   grae->SetPoint(2,50,0.4846037);
   grae->SetPointError(2,0,0,0.004872312,0.005046477);
   grae->SetPoint(3,60,0.5922342);
   grae->SetPointError(3,0,0,0.00389924,0.001086245);
   
   TH1F *Graph_Graph_sigma44 = new TH1F("Graph_Graph_sigma44","sigma",100,27,63);
   Graph_Graph_sigma44->SetMinimum(0.2519099);
   Graph_Graph_sigma44->SetMaximum(0.6243578);
   Graph_Graph_sigma44->SetDirectory(0);
   Graph_Graph_sigma44->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigma44->SetLineColor(ci);
   Graph_Graph_sigma44->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigma44->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma44->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma44->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigma44->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigma44->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma44->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma44->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigma44->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigma44->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma44->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma44->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_sigma44);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.449427,0.9317089,0.550573,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma");
   pt->Draw();
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.01,0.01,0.49,0.49);
   C_3->Draw();
   C_3->cd();
   C_3->Range(22.5,0.3439802,67.5,1.239202);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
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
   
   TH1F *Graph_Graph_sigma_cb55 = new TH1F("Graph_Graph_sigma_cb55","sigma_cb",100,27,63);
   Graph_Graph_sigma_cb55->SetMinimum(0.4335024);
   Graph_Graph_sigma_cb55->SetMaximum(1.14968);
   Graph_Graph_sigma_cb55->SetDirectory(0);
   Graph_Graph_sigma_cb55->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigma_cb55->SetLineColor(ci);
   Graph_Graph_sigma_cb55->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb55->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb55->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb55->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cb55->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb55->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb55->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb55->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cb55->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb55->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb55->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb55->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_sigma_cb55);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigma_cbStat");
   gre->SetTitle("sigma_cb");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.4990149);
   gre->SetPointError(0,0,0.01795853);
   gre->SetPoint(1,40,0.6987899);
   gre->SetPointError(1,0,0.02211676);
   gre->SetPoint(2,50,0.8236251);
   gre->SetPointError(2,0,0.02945104);
   gre->SetPoint(3,60,1.072813);
   gre->SetPointError(3,0,0.02752898);
   
   TH1F *Graph_Graph_sigma_cbStat33 = new TH1F("Graph_Graph_sigma_cbStat33","sigma_cb",100,27,63);
   Graph_Graph_sigma_cbStat33->SetMinimum(0.4191278);
   Graph_Graph_sigma_cbStat33->SetMaximum(1.162271);
   Graph_Graph_sigma_cbStat33->SetDirectory(0);
   Graph_Graph_sigma_cbStat33->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigma_cbStat33->SetLineColor(ci);
   Graph_Graph_sigma_cbStat33->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cbStat33->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cbStat33->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cbStat33->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cbStat33->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cbStat33->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cbStat33->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cbStat33->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cbStat33->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cbStat33->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cbStat33->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cbStat33->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_sigma_cbStat33);
   
   gre->Draw("p");
   
   pt = new TPaveText(0.4453983,0.9319085,0.6783356,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma_cb");
   pt->Draw();
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.4990149);
   grae->SetPointError(0,0,0,0.005831031,0.005107821);
   grae->SetPoint(1,40,0.6987899);
   grae->SetPointError(1,0,0,0.003311269,7.93584e-05);
   grae->SetPoint(2,50,0.8236251);
   grae->SetPointError(2,0,0,0.02030932,0.01686733);
   grae->SetPoint(3,60,1.072813);
   grae->SetPointError(3,0,0,0.01711699,0.01718518);
   
   TH1F *Graph_Graph_sigma_cb66 = new TH1F("Graph_Graph_sigma_cb66","sigma_cb",100,27,63);
   Graph_Graph_sigma_cb66->SetMinimum(0.4335024);
   Graph_Graph_sigma_cb66->SetMaximum(1.14968);
   Graph_Graph_sigma_cb66->SetDirectory(0);
   Graph_Graph_sigma_cb66->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_sigma_cb66->SetLineColor(ci);
   Graph_Graph_sigma_cb66->GetXaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb66->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb66->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb66->GetXaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cb66->GetYaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb66->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb66->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb66->GetYaxis()->SetTitleFont(42);
   Graph_Graph_sigma_cb66->GetZaxis()->SetLabelFont(42);
   Graph_Graph_sigma_cb66->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_sigma_cb66->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_sigma_cb66->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_sigma_cb66);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol6",27,63);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(2.016261e-09);
   PrevFitTMP->SetNDF(0);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,-1.188572);
   PrevFitTMP->SetParError(0,0.1110229);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,0.08596956);
   PrevFitTMP->SetParError(1,0.006682632);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,-0.0009840915);
   PrevFitTMP->SetParError(2,0.000101848);
   PrevFitTMP->SetParLimits(2,0,0);
   PrevFitTMP->SetParameter(3,-3.773191e-07);
   PrevFitTMP->SetParError(3,2.094496e-08);
   PrevFitTMP->SetParLimits(3,0,0);
   PrevFitTMP->SetParameter(4,-1.077683e-08);
   PrevFitTMP->SetParError(4,6.564843e-10);
   PrevFitTMP->SetParLimits(4,0,0);
   PrevFitTMP->SetParameter(5,-3.696408e-11);
   PrevFitTMP->SetParError(5,1.114231e-11);
   PrevFitTMP->SetParLimits(5,0,0);
   PrevFitTMP->SetParameter(6,1.920123e-11);
   PrevFitTMP->SetParError(6,1.911263e-12);
   PrevFitTMP->SetParLimits(6,0,0);
   grae->GetListOfFunctions()->Add(PrevFitTMP);
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4247305,0.9317089,0.5752695,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma_cb");
   pt->Draw();
   C_3->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_4
   C_4 = new TPad("C_4", "C_4",0.51,0.01,0.99,0.49);
   C_4->Draw();
   C_4->cd();
   C_4->Range(22.5,22.47492,67.5,67.3817);
   C_4->SetFillColor(0);
   C_4->SetBorderMode(0);
   C_4->SetBorderSize(2);
   C_4->SetFrameBorderMode(0);
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
   
   TH1F *Graph_Graph_width77 = new TH1F("Graph_Graph_width77","width",100,27,63);
   Graph_Graph_width77->SetMinimum(26.9656);
   Graph_Graph_width77->SetMaximum(62.89102);
   Graph_Graph_width77->SetDirectory(0);
   Graph_Graph_width77->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_width77->SetLineColor(ci);
   Graph_Graph_width77->GetXaxis()->SetLabelFont(42);
   Graph_Graph_width77->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_width77->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_width77->GetXaxis()->SetTitleFont(42);
   Graph_Graph_width77->GetYaxis()->SetLabelFont(42);
   Graph_Graph_width77->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_width77->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_width77->GetYaxis()->SetTitleFont(42);
   Graph_Graph_width77->GetZaxis()->SetLabelFont(42);
   Graph_Graph_width77->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_width77->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_width77->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_width77);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("widthStat");
   gre->SetTitle("width");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,29.96002);
   gre->SetPointError(0,0,0.00543284);
   gre->SetPoint(1,40,39.94894);
   gre->SetPointError(1,0,0.00720373);
   gre->SetPoint(2,50,49.90149);
   gre->SetPointError(2,0,0.008582456);
   gre->SetPoint(3,60,59.89711);
   gre->SetPointError(3,0,0.009716029);
   
   TH1F *Graph_Graph_widthStat44 = new TH1F("Graph_Graph_widthStat44","width",100,27,63);
   Graph_Graph_widthStat44->SetMinimum(26.95936);
   Graph_Graph_widthStat44->SetMaximum(62.90205);
   Graph_Graph_widthStat44->SetDirectory(0);
   Graph_Graph_widthStat44->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_widthStat44->SetLineColor(ci);
   Graph_Graph_widthStat44->GetXaxis()->SetLabelFont(42);
   Graph_Graph_widthStat44->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_widthStat44->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_widthStat44->GetXaxis()->SetTitleFont(42);
   Graph_Graph_widthStat44->GetYaxis()->SetLabelFont(42);
   Graph_Graph_widthStat44->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_widthStat44->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_widthStat44->GetYaxis()->SetTitleFont(42);
   Graph_Graph_widthStat44->GetZaxis()->SetLabelFont(42);
   Graph_Graph_widthStat44->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_widthStat44->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_widthStat44->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_widthStat44);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.96002);
   grae->SetPointError(0,0,0,0.0006302875,2.145839e-12);
   grae->SetPoint(1,40,39.94894);
   grae->SetPointError(1,0,0,0.002585356,0.0007776076);
   grae->SetPoint(2,50,49.90149);
   grae->SetPointError(2,0,0,0.005890568,0.005899973);
   grae->SetPoint(3,60,59.89711);
   grae->SetPointError(3,0,0,0.0002718613,0.0001269699);
   
   TH1F *Graph_Graph_width88 = new TH1F("Graph_Graph_width88","width",100,27,63);
   Graph_Graph_width88->SetMinimum(26.9656);
   Graph_Graph_width88->SetMaximum(62.89102);
   Graph_Graph_width88->SetDirectory(0);
   Graph_Graph_width88->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_width88->SetLineColor(ci);
   Graph_Graph_width88->GetXaxis()->SetLabelFont(42);
   Graph_Graph_width88->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_width88->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_width88->GetXaxis()->SetTitleFont(42);
   Graph_Graph_width88->GetYaxis()->SetLabelFont(42);
   Graph_Graph_width88->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_width88->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_width88->GetYaxis()->SetTitleFont(42);
   Graph_Graph_width88->GetZaxis()->SetLabelFont(42);
   Graph_Graph_width88->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_width88->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_width88->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_width88);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4538371,0.94,0.5461629,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("width");
   pt->Draw();
   C_4->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
