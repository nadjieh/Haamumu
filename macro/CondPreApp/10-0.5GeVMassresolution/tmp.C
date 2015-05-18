{
//=========Macro generated from canvas: C/C
//=========  (Sun May 17 19:56:25 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",246,60,728,660);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.51,0.49,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(22.5,22.47493,67.5,67.3817);
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
   
   TH1F *Graph_mean1 = new TH1F("Graph_mean1","mean",100,27,63);
   Graph_mean1->SetMinimum(26.9656);
   Graph_mean1->SetMaximum(62.89102);
   Graph_mean1->SetDirectory(0);
   Graph_mean1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_mean1->SetLineColor(ci);
   Graph_mean1->GetXaxis()->SetLabelFont(42);
   Graph_mean1->GetXaxis()->SetLabelSize(0.035);
   Graph_mean1->GetXaxis()->SetTitleSize(0.035);
   Graph_mean1->GetXaxis()->SetTitleFont(42);
   Graph_mean1->GetYaxis()->SetLabelFont(42);
   Graph_mean1->GetYaxis()->SetLabelSize(0.035);
   Graph_mean1->GetYaxis()->SetTitleSize(0.035);
   Graph_mean1->GetYaxis()->SetTitleFont(42);
   Graph_mean1->GetZaxis()->SetLabelFont(42);
   Graph_mean1->GetZaxis()->SetLabelSize(0.035);
   Graph_mean1->GetZaxis()->SetTitleSize(0.035);
   Graph_mean1->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_mean1);
   
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
   
   TH1F *Graph_meanStat1 = new TH1F("Graph_meanStat1","mean",100,27,63);
   Graph_meanStat1->SetMinimum(26.95936);
   Graph_meanStat1->SetMaximum(62.90205);
   Graph_meanStat1->SetDirectory(0);
   Graph_meanStat1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_meanStat1->SetLineColor(ci);
   Graph_meanStat1->GetXaxis()->SetLabelFont(42);
   Graph_meanStat1->GetXaxis()->SetLabelSize(0.035);
   Graph_meanStat1->GetXaxis()->SetTitleSize(0.035);
   Graph_meanStat1->GetXaxis()->SetTitleFont(42);
   Graph_meanStat1->GetYaxis()->SetLabelFont(42);
   Graph_meanStat1->GetYaxis()->SetLabelSize(0.035);
   Graph_meanStat1->GetYaxis()->SetTitleSize(0.035);
   Graph_meanStat1->GetYaxis()->SetTitleFont(42);
   Graph_meanStat1->GetZaxis()->SetLabelFont(42);
   Graph_meanStat1->GetZaxis()->SetLabelSize(0.035);
   Graph_meanStat1->GetZaxis()->SetTitleSize(0.035);
   Graph_meanStat1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_meanStat1);
   
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
   
   TH1F *Graph_mean2 = new TH1F("Graph_mean2","mean",100,27,63);
   Graph_mean2->SetMinimum(26.9656);
   Graph_mean2->SetMaximum(62.89102);
   Graph_mean2->SetDirectory(0);
   Graph_mean2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_mean2->SetLineColor(ci);
   Graph_mean2->GetXaxis()->SetLabelFont(42);
   Graph_mean2->GetXaxis()->SetLabelSize(0.035);
   Graph_mean2->GetXaxis()->SetTitleSize(0.035);
   Graph_mean2->GetXaxis()->SetTitleFont(42);
   Graph_mean2->GetYaxis()->SetLabelFont(42);
   Graph_mean2->GetYaxis()->SetLabelSize(0.035);
   Graph_mean2->GetYaxis()->SetTitleSize(0.035);
   Graph_mean2->GetYaxis()->SetTitleFont(42);
   Graph_mean2->GetZaxis()->SetLabelFont(42);
   Graph_mean2->GetZaxis()->SetLabelSize(0.035);
   Graph_mean2->GetZaxis()->SetTitleSize(0.035);
   Graph_mean2->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_mean2);
   
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
   
   TH1F *Graph_sigma3 = new TH1F("Graph_sigma3","sigma",100,27,63);
   Graph_sigma3->SetMinimum(0.2519099);
   Graph_sigma3->SetMaximum(0.6243578);
   Graph_sigma3->SetDirectory(0);
   Graph_sigma3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma3->SetLineColor(ci);
   Graph_sigma3->GetXaxis()->SetLabelFont(42);
   Graph_sigma3->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma3->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma3->GetXaxis()->SetTitleFont(42);
   Graph_sigma3->GetYaxis()->SetLabelFont(42);
   Graph_sigma3->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma3->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma3->GetYaxis()->SetTitleFont(42);
   Graph_sigma3->GetZaxis()->SetLabelFont(42);
   Graph_sigma3->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma3->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma3->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma3);
   
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
   
   TH1F *Graph_sigmaStat2 = new TH1F("Graph_sigmaStat2","sigma",100,27,63);
   Graph_sigmaStat2->SetMinimum(0.2427935);
   Graph_sigmaStat2->SetMaximum(0.6369017);
   Graph_sigmaStat2->SetDirectory(0);
   Graph_sigmaStat2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigmaStat2->SetLineColor(ci);
   Graph_sigmaStat2->GetXaxis()->SetLabelFont(42);
   Graph_sigmaStat2->GetXaxis()->SetLabelSize(0.035);
   Graph_sigmaStat2->GetXaxis()->SetTitleSize(0.035);
   Graph_sigmaStat2->GetXaxis()->SetTitleFont(42);
   Graph_sigmaStat2->GetYaxis()->SetLabelFont(42);
   Graph_sigmaStat2->GetYaxis()->SetLabelSize(0.035);
   Graph_sigmaStat2->GetYaxis()->SetTitleSize(0.035);
   Graph_sigmaStat2->GetYaxis()->SetTitleFont(42);
   Graph_sigmaStat2->GetZaxis()->SetLabelFont(42);
   Graph_sigmaStat2->GetZaxis()->SetLabelSize(0.035);
   Graph_sigmaStat2->GetZaxis()->SetTitleSize(0.035);
   Graph_sigmaStat2->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_sigmaStat2);
   
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
   
   TH1F *Graph_sigma4 = new TH1F("Graph_sigma4","sigma",100,27,63);
   Graph_sigma4->SetMinimum(0.2519099);
   Graph_sigma4->SetMaximum(0.6243578);
   Graph_sigma4->SetDirectory(0);
   Graph_sigma4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma4->SetLineColor(ci);
   Graph_sigma4->GetXaxis()->SetLabelFont(42);
   Graph_sigma4->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma4->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma4->GetXaxis()->SetTitleFont(42);
   Graph_sigma4->GetYaxis()->SetLabelFont(42);
   Graph_sigma4->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma4->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma4->GetYaxis()->SetTitleFont(42);
   Graph_sigma4->GetZaxis()->SetLabelFont(42);
   Graph_sigma4->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma4->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma4->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma4);
   
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
   C_3->Range(22.5,0.3439803,67.5,1.239202);
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
   
   TH1F *Graph_sigma_cb5 = new TH1F("Graph_sigma_cb5","sigma_cb",100,27,63);
   Graph_sigma_cb5->SetMinimum(0.4335024);
   Graph_sigma_cb5->SetMaximum(1.14968);
   Graph_sigma_cb5->SetDirectory(0);
   Graph_sigma_cb5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cb5->SetLineColor(ci);
   Graph_sigma_cb5->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cb5->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cb5->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cb5->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cb5->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cb5->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cb5->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cb5->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cb5->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cb5->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cb5->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cb5->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma_cb5);
   
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
   
   TH1F *Graph_sigma_cbStat3 = new TH1F("Graph_sigma_cbStat3","sigma_cb",100,27,63);
   Graph_sigma_cbStat3->SetMinimum(0.4191278);
   Graph_sigma_cbStat3->SetMaximum(1.162271);
   Graph_sigma_cbStat3->SetDirectory(0);
   Graph_sigma_cbStat3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cbStat3->SetLineColor(ci);
   Graph_sigma_cbStat3->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cbStat3->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat3->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat3->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cbStat3->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cbStat3->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat3->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat3->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cbStat3->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cbStat3->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat3->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_sigma_cbStat3);
   
   gre->Draw("p");
   
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
   
   TH1F *Graph_sigma_cb6 = new TH1F("Graph_sigma_cb6","sigma_cb",100,27,63);
   Graph_sigma_cb6->SetMinimum(0.4335024);
   Graph_sigma_cb6->SetMaximum(1.14968);
   Graph_sigma_cb6->SetDirectory(0);
   Graph_sigma_cb6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cb6->SetLineColor(ci);
   Graph_sigma_cb6->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cb6->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cb6->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cb6->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cb6->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cb6->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cb6->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cb6->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cb6->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cb6->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cb6->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cb6->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma_cb6);
   
   
   TF1 *Linear = new TF1("Linear","pol1",27,63);
   Linear->SetFillColor(19);
   Linear->SetFillStyle(0);
   Linear->SetLineColor(6);
   Linear->SetLineWidth(2);
   Linear->SetLineStyle(2);
   Linear->SetChisquare(15.84473);
   Linear->SetNDF(2);
   Linear->GetXaxis()->SetLabelFont(42);
   Linear->GetXaxis()->SetLabelSize(0.035);
   Linear->GetXaxis()->SetTitleSize(0.035);
   Linear->GetXaxis()->SetTitleFont(42);
   Linear->GetYaxis()->SetLabelFont(42);
   Linear->GetYaxis()->SetLabelSize(0.035);
   Linear->GetYaxis()->SetTitleSize(0.035);
   Linear->GetYaxis()->SetTitleFont(42);
   Linear->SetParameter(0,-0.06401716);
   Linear->SetParError(0,0.01724726);
   Linear->SetParLimits(0,0,0);
   Linear->SetParameter(1,0.01895345);
   Linear->SetParError(1,0.0004489028);
   Linear->SetParLimits(1,0,0);
   grae->GetListOfFunctions()->Add(Linear);
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
   cout<<PrevFitTMP->Eval(30)<<endl;
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
   C_4->Range(22.5,22.47493,67.5,67.3817);
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
   
   TH1F *Graph_width7 = new TH1F("Graph_width7","width",100,27,63);
   Graph_width7->SetMinimum(26.9656);
   Graph_width7->SetMaximum(62.89102);
   Graph_width7->SetDirectory(0);
   Graph_width7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_width7->SetLineColor(ci);
   Graph_width7->GetXaxis()->SetLabelFont(42);
   Graph_width7->GetXaxis()->SetLabelSize(0.035);
   Graph_width7->GetXaxis()->SetTitleSize(0.035);
   Graph_width7->GetXaxis()->SetTitleFont(42);
   Graph_width7->GetYaxis()->SetLabelFont(42);
   Graph_width7->GetYaxis()->SetLabelSize(0.035);
   Graph_width7->GetYaxis()->SetTitleSize(0.035);
   Graph_width7->GetYaxis()->SetTitleFont(42);
   Graph_width7->GetZaxis()->SetLabelFont(42);
   Graph_width7->GetZaxis()->SetLabelSize(0.035);
   Graph_width7->GetZaxis()->SetTitleSize(0.035);
   Graph_width7->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_width7);
   
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
   
   TH1F *Graph_widthStat4 = new TH1F("Graph_widthStat4","width",100,27,63);
   Graph_widthStat4->SetMinimum(26.95936);
   Graph_widthStat4->SetMaximum(62.90205);
   Graph_widthStat4->SetDirectory(0);
   Graph_widthStat4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_widthStat4->SetLineColor(ci);
   Graph_widthStat4->GetXaxis()->SetLabelFont(42);
   Graph_widthStat4->GetXaxis()->SetLabelSize(0.035);
   Graph_widthStat4->GetXaxis()->SetTitleSize(0.035);
   Graph_widthStat4->GetXaxis()->SetTitleFont(42);
   Graph_widthStat4->GetYaxis()->SetLabelFont(42);
   Graph_widthStat4->GetYaxis()->SetLabelSize(0.035);
   Graph_widthStat4->GetYaxis()->SetTitleSize(0.035);
   Graph_widthStat4->GetYaxis()->SetTitleFont(42);
   Graph_widthStat4->GetZaxis()->SetLabelFont(42);
   Graph_widthStat4->GetZaxis()->SetLabelSize(0.035);
   Graph_widthStat4->GetZaxis()->SetTitleSize(0.035);
   Graph_widthStat4->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_widthStat4);
   
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
   
   TH1F *Graph_width8 = new TH1F("Graph_width8","width",100,27,63);
   Graph_width8->SetMinimum(26.9656);
   Graph_width8->SetMaximum(62.89102);
   Graph_width8->SetDirectory(0);
   Graph_width8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_width8->SetLineColor(ci);
   Graph_width8->GetXaxis()->SetLabelFont(42);
   Graph_width8->GetXaxis()->SetLabelSize(0.035);
   Graph_width8->GetXaxis()->SetTitleSize(0.035);
   Graph_width8->GetXaxis()->SetTitleFont(42);
   Graph_width8->GetYaxis()->SetLabelFont(42);
   Graph_width8->GetYaxis()->SetLabelSize(0.035);
   Graph_width8->GetYaxis()->SetTitleSize(0.035);
   Graph_width8->GetYaxis()->SetTitleFont(42);
   Graph_width8->GetZaxis()->SetLabelFont(42);
   Graph_width8->GetZaxis()->SetLabelSize(0.035);
   Graph_width8->GetZaxis()->SetTitleSize(0.035);
   Graph_width8->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_width8);
   
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
