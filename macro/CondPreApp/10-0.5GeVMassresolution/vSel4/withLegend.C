{
//=========Macro generated from canvas: C/C
//=========  (Wed May 13 19:03:18 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",11,38,1185,660);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.51,0.24,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(22.5,22.49482,67.5,67.41332);
   C_1->SetFillColor(0);
   C_1->SetBorderMode(0);
   C_1->SetBorderSize(2);
   C_1->SetFrameBorderMode(0);
   C_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.98182);
   grae->SetPointError(0,0,0,0.0005795806,5.449465e-06);
   grae->SetPoint(1,40,39.95788);
   grae->SetPointError(1,0,0,0.0001422755,0.0001395867);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.001933375,0.001459286);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.001284517,0.0003720207);
   
   TH1F *Graph_mean1 = new TH1F("Graph_mean1","mean",100,27,63);
   Graph_mean1->SetMinimum(26.98667);
   Graph_mean1->SetMaximum(62.92147);
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
   gre->SetPoint(0,30,29.98182);
   gre->SetPointError(0,0,0.006705251);
   gre->SetPoint(1,40,39.95788);
   gre->SetPointError(1,0,0.006455383);
   gre->SetPoint(2,50,49.92739);
   gre->SetPointError(2,0,0.00901934);
   gre->SetPoint(3,60,59.92653);
   gre->SetPointError(3,0,0.01173615);
   
   TH1F *Graph_meanStat1 = new TH1F("Graph_meanStat1","mean",100,27,63);
   Graph_meanStat1->SetMinimum(26.9788);
   Graph_meanStat1->SetMaximum(62.93458);
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
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.98182);
   grae->SetPointError(0,0,0,0.0005795806,5.449465e-06);
   grae->SetPoint(1,39.92646,40.06776);
   grae->SetPointError(1,0,0,0.0001422755,0.0001395867);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.001933375,0.001459286);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.001284517,0.0003720207);
   
   TH1F *Graph_mean2 = new TH1F("Graph_mean2","mean",100,27,63);
   Graph_mean2->SetMinimum(26.98667);
   Graph_mean2->SetMaximum(62.92147);
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
   
   TPaveText *pt = new TPaveText(0.4237334,0.94,0.5762666,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("mean");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.1626845,0.6483386,0.5418768,0.8593091,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Stat. Unc.","lf");
   entry->SetFillColor(0);
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Syst. Unc.","lpf");
   entry->SetFillStyle(1001);
   entry->SetFillColor(0);
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(4);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.26,0.51,0.49,0.99);
   C_2->Draw();
   C_2->cd();
   C_2->Range(22.5,0.1701577,67.5,0.6882678);
   C_2->SetFillColor(0);
   C_2->SetBorderMode(0);
   C_2->SetBorderSize(2);
   C_2->SetFrameBorderMode(0);
   C_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.2626502);
   grae->SetPointError(0,0,0,0.006140816,0.006452005);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0001546841);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001975279,0.004211177);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0008342907,4.249021e-06);
   
   TH1F *Graph_sigma3 = new TH1F("Graph_sigma3","sigma",100,27,63);
   Graph_sigma3->SetMinimum(0.2219687);
   Graph_sigma3->SetMaximum(0.6364568);
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
   gre->SetPoint(0,30,0.2626502);
   gre->SetPointError(0,0,0.01366939);
   gre->SetPoint(1,40,0.4121476);
   gre->SetPointError(1,0,0.01159685);
   gre->SetPoint(2,50,0.522387);
   gre->SetPointError(2,0,0.01915432);
   gre->SetPoint(3,60,0.6019119);
   gre->SetPointError(3,0,0.02203727);
   
   TH1F *Graph_sigmaStat2 = new TH1F("Graph_sigmaStat2","sigma",100,27,63);
   Graph_sigmaStat2->SetMinimum(0.211484);
   Graph_sigmaStat2->SetMaximum(0.661446);
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
   grae->SetPoint(0,30,0.2626502);
   grae->SetPointError(0,0,0,0.006140816,0.006452005);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0001546841);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001975279,0.004211177);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0008342907,4.249021e-06);
   
   TH1F *Graph_sigma4 = new TH1F("Graph_sigma4","sigma",100,27,63);
   Graph_sigma4->SetMinimum(0.2219687);
   Graph_sigma4->SetMaximum(0.6364568);
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
   
   pt = new TPaveText(0.4145297,0.9356646,0.5854703,0.995,"blNDC");
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
   C_3 = new TPad("C_3", "C_3",0.51,0.51,0.74,0.99);
   C_3->Draw();
   C_3->cd();
   C_3->Range(22.5,22.42103,67.5,67.17073);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
   C_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean_cb");
   grae->SetTitle("mean_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   
   TH1F *Graph_mean_cb5 = new TH1F("Graph_mean_cb5","mean_cb",100,27,63);
   Graph_mean_cb5->SetMinimum(26.896);
   Graph_mean_cb5->SetMaximum(62.69576);
   Graph_mean_cb5->SetDirectory(0);
   Graph_mean_cb5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_mean_cb5->SetLineColor(ci);
   Graph_mean_cb5->GetXaxis()->SetLabelFont(42);
   Graph_mean_cb5->GetXaxis()->SetLabelSize(0.035);
   Graph_mean_cb5->GetXaxis()->SetTitleSize(0.035);
   Graph_mean_cb5->GetXaxis()->SetTitleFont(42);
   Graph_mean_cb5->GetYaxis()->SetLabelFont(42);
   Graph_mean_cb5->GetYaxis()->SetLabelSize(0.035);
   Graph_mean_cb5->GetYaxis()->SetTitleSize(0.035);
   Graph_mean_cb5->GetYaxis()->SetTitleFont(42);
   Graph_mean_cb5->GetZaxis()->SetLabelFont(42);
   Graph_mean_cb5->GetZaxis()->SetLabelSize(0.035);
   Graph_mean_cb5->GetZaxis()->SetTitleSize(0.035);
   Graph_mean_cb5->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_mean_cb5);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("mean_cbStat");
   gre->SetTitle("mean_cb");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,29.87947);
   gre->SetPointError(0,0,0.01985296);
   gre->SetPoint(1,40,39.737);
   gre->SetPointError(1,0,0.06351425);
   gre->SetPoint(2,50,49.64195);
   gre->SetPointError(2,0,0.07862462);
   gre->SetPoint(3,60,59.68974);
   gre->SetPointError(3,0,0.06440656);
   
   TH1F *Graph_mean_cbStat3 = new TH1F("Graph_mean_cbStat3","mean_cb",100,27,63);
   Graph_mean_cbStat3->SetMinimum(26.87016);
   Graph_mean_cbStat3->SetMaximum(62.7436);
   Graph_mean_cbStat3->SetDirectory(0);
   Graph_mean_cbStat3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_mean_cbStat3->SetLineColor(ci);
   Graph_mean_cbStat3->GetXaxis()->SetLabelFont(42);
   Graph_mean_cbStat3->GetXaxis()->SetLabelSize(0.035);
   Graph_mean_cbStat3->GetXaxis()->SetTitleSize(0.035);
   Graph_mean_cbStat3->GetXaxis()->SetTitleFont(42);
   Graph_mean_cbStat3->GetYaxis()->SetLabelFont(42);
   Graph_mean_cbStat3->GetYaxis()->SetLabelSize(0.035);
   Graph_mean_cbStat3->GetYaxis()->SetTitleSize(0.035);
   Graph_mean_cbStat3->GetYaxis()->SetTitleFont(42);
   Graph_mean_cbStat3->GetZaxis()->SetLabelFont(42);
   Graph_mean_cbStat3->GetZaxis()->SetLabelSize(0.035);
   Graph_mean_cbStat3->GetZaxis()->SetTitleSize(0.035);
   Graph_mean_cbStat3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_mean_cbStat3);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean_cb");
   grae->SetTitle("mean_cb");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   
   TH1F *Graph_mean_cb6 = new TH1F("Graph_mean_cb6","mean_cb",100,27,63);
   Graph_mean_cb6->SetMinimum(26.896);
   Graph_mean_cb6->SetMaximum(62.69576);
   Graph_mean_cb6->SetDirectory(0);
   Graph_mean_cb6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_mean_cb6->SetLineColor(ci);
   Graph_mean_cb6->GetXaxis()->SetLabelFont(42);
   Graph_mean_cb6->GetXaxis()->SetLabelSize(0.035);
   Graph_mean_cb6->GetXaxis()->SetTitleSize(0.035);
   Graph_mean_cb6->GetXaxis()->SetTitleFont(42);
   Graph_mean_cb6->GetYaxis()->SetLabelFont(42);
   Graph_mean_cb6->GetYaxis()->SetLabelSize(0.035);
   Graph_mean_cb6->GetYaxis()->SetTitleSize(0.035);
   Graph_mean_cb6->GetYaxis()->SetTitleFont(42);
   Graph_mean_cb6->GetZaxis()->SetLabelFont(42);
   Graph_mean_cb6->GetZaxis()->SetLabelSize(0.035);
   Graph_mean_cb6->GetZaxis()->SetTitleSize(0.035);
   Graph_mean_cb6->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_mean_cb6);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.3777149,0.9396203,0.6222851,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("mean_cb");
   pt->Draw();
   C_3->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_4
   C_4 = new TPad("C_4", "C_4",0.76,0.51,0.99,0.99);
   C_4->Draw();
   C_4->cd();
   C_4->Range(22.5,0.3130447,67.5,1.422495);
   C_4->SetFillColor(0);
   C_4->SetBorderMode(0);
   C_4->SetBorderSize(2);
   C_4->SetFrameBorderMode(0);
   C_4->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.5346017);
   grae->SetPointError(0,0,0,0.01061698,0.01120148);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.01190164);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.0154785,0.02302831);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.005549079,0.006334122);
   
   TH1F *Graph_sigma_cb7 = new TH1F("Graph_sigma_cb7","sigma_cb",100,27,63);
   Graph_sigma_cb7->SetMinimum(0.4239897);
   Graph_sigma_cb7->SetMaximum(1.31155);
   Graph_sigma_cb7->SetDirectory(0);
   Graph_sigma_cb7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cb7->SetLineColor(ci);
   Graph_sigma_cb7->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cb7->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cb7->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cb7->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cb7->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cb7->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cb7->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cb7->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cb7->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cb7->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cb7->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cb7->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma_cb7);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigma_cbStat");
   gre->SetTitle("sigma_cb");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.5346017);
   gre->SetPointError(0,0,0.0273445);
   gre->SetPoint(1,40,0.8982298);
   gre->SetPointError(1,0,0.06397683);
   gre->SetPoint(2,50,1.106017);
   gre->SetPointError(2,0,0.09537667);
   gre->SetPoint(3,60,1.193986);
   gre->SetPointError(3,0,0.07823012);
   
   TH1F *Graph_sigma_cbStat4 = new TH1F("Graph_sigma_cbStat4","sigma_cb",100,27,63);
   Graph_sigma_cbStat4->SetMinimum(0.4307613);
   Graph_sigma_cbStat4->SetMaximum(1.348712);
   Graph_sigma_cbStat4->SetDirectory(0);
   Graph_sigma_cbStat4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cbStat4->SetLineColor(ci);
   Graph_sigma_cbStat4->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cbStat4->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat4->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat4->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cbStat4->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cbStat4->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat4->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat4->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cbStat4->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cbStat4->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cbStat4->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cbStat4->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_sigma_cbStat4);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.5346017);
   grae->SetPointError(0,0,0,0.01061698,0.01120148);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.01190164);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.0154785,0.02302831);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.005549079,0.006334122);
   
   TH1F *Graph_sigma_cb8 = new TH1F("Graph_sigma_cb8","sigma_cb",100,27,63);
   Graph_sigma_cb8->SetMinimum(0.4563512);
   Graph_sigma_cb8->SetMaximum(1.267954);
   Graph_sigma_cb8->SetDirectory(0);
   Graph_sigma_cb8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_sigma_cb8->SetLineColor(ci);
   Graph_sigma_cb8->GetXaxis()->SetLabelFont(42);
   Graph_sigma_cb8->GetXaxis()->SetLabelSize(0.035);
   Graph_sigma_cb8->GetXaxis()->SetTitleSize(0.035);
   Graph_sigma_cb8->GetXaxis()->SetTitleFont(42);
   Graph_sigma_cb8->GetYaxis()->SetLabelFont(42);
   Graph_sigma_cb8->GetYaxis()->SetLabelSize(0.035);
   Graph_sigma_cb8->GetYaxis()->SetTitleSize(0.035);
   Graph_sigma_cb8->GetYaxis()->SetTitleFont(42);
   Graph_sigma_cb8->GetZaxis()->SetLabelFont(42);
   Graph_sigma_cb8->GetZaxis()->SetLabelSize(0.035);
   Graph_sigma_cb8->GetZaxis()->SetTitleSize(0.035);
   Graph_sigma_cb8->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_sigma_cb8);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.3703519,0.9356646,0.6296481,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma_cb");
   pt->Draw();
   C_4->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_5
   C_5 = new TPad("C_5", "C_5",0.01,0.01,0.24,0.49);
   C_5->Draw();
   C_5->cd();
   C_5->Range(22.5,22.42103,67.5,67.17073);
   C_5->SetFillColor(0);
   C_5->SetBorderMode(0);
   C_5->SetBorderSize(2);
   C_5->SetFrameBorderMode(0);
   C_5->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   
   TH1F *Graph_width9 = new TH1F("Graph_width9","width",100,27,63);
   Graph_width9->SetMinimum(26.896);
   Graph_width9->SetMaximum(62.69576);
   Graph_width9->SetDirectory(0);
   Graph_width9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_width9->SetLineColor(ci);
   Graph_width9->GetXaxis()->SetLabelFont(42);
   Graph_width9->GetXaxis()->SetLabelSize(0.035);
   Graph_width9->GetXaxis()->SetTitleSize(0.035);
   Graph_width9->GetXaxis()->SetTitleFont(42);
   Graph_width9->GetYaxis()->SetLabelFont(42);
   Graph_width9->GetYaxis()->SetLabelSize(0.035);
   Graph_width9->GetYaxis()->SetTitleSize(0.035);
   Graph_width9->GetYaxis()->SetTitleFont(42);
   Graph_width9->GetZaxis()->SetLabelFont(42);
   Graph_width9->GetZaxis()->SetLabelSize(0.035);
   Graph_width9->GetZaxis()->SetTitleSize(0.035);
   Graph_width9->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_width9);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("widthStat");
   gre->SetTitle("width");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,29.87947);
   gre->SetPointError(0,0,0.01985296);
   gre->SetPoint(1,40,39.737);
   gre->SetPointError(1,0,0.06351425);
   gre->SetPoint(2,50,49.64195);
   gre->SetPointError(2,0,0.07862462);
   gre->SetPoint(3,60,59.68974);
   gre->SetPointError(3,0,0.06440656);
   
   TH1F *Graph_widthStat5 = new TH1F("Graph_widthStat5","width",100,27,63);
   Graph_widthStat5->SetMinimum(26.87016);
   Graph_widthStat5->SetMaximum(62.7436);
   Graph_widthStat5->SetDirectory(0);
   Graph_widthStat5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_widthStat5->SetLineColor(ci);
   Graph_widthStat5->GetXaxis()->SetLabelFont(42);
   Graph_widthStat5->GetXaxis()->SetLabelSize(0.035);
   Graph_widthStat5->GetXaxis()->SetTitleSize(0.035);
   Graph_widthStat5->GetXaxis()->SetTitleFont(42);
   Graph_widthStat5->GetYaxis()->SetLabelFont(42);
   Graph_widthStat5->GetYaxis()->SetLabelSize(0.035);
   Graph_widthStat5->GetYaxis()->SetTitleSize(0.035);
   Graph_widthStat5->GetYaxis()->SetTitleFont(42);
   Graph_widthStat5->GetZaxis()->SetLabelFont(42);
   Graph_widthStat5->GetZaxis()->SetLabelSize(0.035);
   Graph_widthStat5->GetZaxis()->SetTitleSize(0.035);
   Graph_widthStat5->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_widthStat5);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   
   TH1F *Graph_width10 = new TH1F("Graph_width10","width",100,27,63);
   Graph_width10->SetMinimum(26.896);
   Graph_width10->SetMaximum(62.69576);
   Graph_width10->SetDirectory(0);
   Graph_width10->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_width10->SetLineColor(ci);
   Graph_width10->GetXaxis()->SetLabelFont(42);
   Graph_width10->GetXaxis()->SetLabelSize(0.035);
   Graph_width10->GetXaxis()->SetTitleSize(0.035);
   Graph_width10->GetXaxis()->SetTitleFont(42);
   Graph_width10->GetYaxis()->SetLabelFont(42);
   Graph_width10->GetYaxis()->SetLabelSize(0.035);
   Graph_width10->GetYaxis()->SetTitleSize(0.035);
   Graph_width10->GetYaxis()->SetTitleFont(42);
   Graph_width10->GetZaxis()->SetLabelFont(42);
   Graph_width10->GetZaxis()->SetLabelSize(0.035);
   Graph_width10->GetZaxis()->SetTitleSize(0.035);
   Graph_width10->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_width10);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4237334,0.94,0.5762666,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("width");
   pt->Draw();
   C_5->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_6
   C_6 = new TPad("C_6", "C_6",0.26,0.01,0.49,0.49);
   C_6->Draw();
   C_6->cd();
   C_6->Range(22.5,1.466347,67.5,2.947744);
   C_6->SetFillColor(0);
   C_6->SetBorderMode(0);
   C_6->SetBorderSize(2);
   C_6->SetFrameBorderMode(0);
   C_6->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("n");
   grae->SetTitle("n");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.969983);
   grae->SetPointError(0,0,0,0.07830033,0.08884695);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0014026);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.06993785,0.07117535);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.0493131,0.04885718);
   
   TH1F *Graph_n11 = new TH1F("Graph_n11","n",100,27,63);
   Graph_n11->SetMinimum(1.614487);
   Graph_n11->SetMaximum(2.799604);
   Graph_n11->SetDirectory(0);
   Graph_n11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_n11->SetLineColor(ci);
   Graph_n11->GetXaxis()->SetLabelFont(42);
   Graph_n11->GetXaxis()->SetLabelSize(0.035);
   Graph_n11->GetXaxis()->SetTitleSize(0.035);
   Graph_n11->GetXaxis()->SetTitleFont(42);
   Graph_n11->GetYaxis()->SetLabelFont(42);
   Graph_n11->GetYaxis()->SetLabelSize(0.035);
   Graph_n11->GetYaxis()->SetTitleSize(0.035);
   Graph_n11->GetYaxis()->SetTitleFont(42);
   Graph_n11->GetZaxis()->SetLabelFont(42);
   Graph_n11->GetZaxis()->SetLabelSize(0.035);
   Graph_n11->GetZaxis()->SetTitleSize(0.035);
   Graph_n11->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_n11);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("nStat");
   gre->SetTitle("n");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,1.969983);
   gre->SetPointError(0,0,0.1556854);
   gre->SetPoint(1,40,2.399169);
   gre->SetPointError(1,0,0.2131461);
   gre->SetPoint(2,50,1.983956);
   gre->SetPointError(2,0,0.1546523);
   gre->SetPoint(3,60,1.922008);
   gre->SetPointError(3,0,0.1165036);
   
   TH1F *Graph_nStat6 = new TH1F("Graph_nStat6","n",100,27,63);
   Graph_nStat6->SetMinimum(1.724823);
   Graph_nStat6->SetMaximum(2.692996);
   Graph_nStat6->SetDirectory(0);
   Graph_nStat6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_nStat6->SetLineColor(ci);
   Graph_nStat6->GetXaxis()->SetLabelFont(42);
   Graph_nStat6->GetXaxis()->SetLabelSize(0.035);
   Graph_nStat6->GetXaxis()->SetTitleSize(0.035);
   Graph_nStat6->GetXaxis()->SetTitleFont(42);
   Graph_nStat6->GetYaxis()->SetLabelFont(42);
   Graph_nStat6->GetYaxis()->SetLabelSize(0.035);
   Graph_nStat6->GetYaxis()->SetTitleSize(0.035);
   Graph_nStat6->GetYaxis()->SetTitleFont(42);
   Graph_nStat6->GetZaxis()->SetLabelFont(42);
   Graph_nStat6->GetZaxis()->SetLabelSize(0.035);
   Graph_nStat6->GetZaxis()->SetTitleSize(0.035);
   Graph_nStat6->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_nStat6);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("n");
   grae->SetTitle("n");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,1.969983);
   grae->SetPointError(0,0,0,0.07830033,0.08884695);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0014026);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.06993785,0.07117535);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.0493131,0.04885718);
   
   TH1F *Graph_n12 = new TH1F("Graph_n12","n",100,27,63);
   Graph_n12->SetMinimum(1.819907);
   Graph_n12->SetMaximum(2.453359);
   Graph_n12->SetDirectory(0);
   Graph_n12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_n12->SetLineColor(ci);
   Graph_n12->GetXaxis()->SetLabelFont(42);
   Graph_n12->GetXaxis()->SetLabelSize(0.035);
   Graph_n12->GetXaxis()->SetTitleSize(0.035);
   Graph_n12->GetXaxis()->SetTitleFont(42);
   Graph_n12->GetYaxis()->SetLabelFont(42);
   Graph_n12->GetYaxis()->SetLabelSize(0.035);
   Graph_n12->GetYaxis()->SetTitleSize(0.035);
   Graph_n12->GetYaxis()->SetTitleFont(42);
   Graph_n12->GetZaxis()->SetLabelFont(42);
   Graph_n12->GetZaxis()->SetLabelSize(0.035);
   Graph_n12->GetZaxis()->SetTitleSize(0.035);
   Graph_n12->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_n12);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4752741,0.94,0.5247259,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("n");
   pt->Draw();
   C_6->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_7
   C_7 = new TPad("C_7", "C_7",0.51,0.01,0.74,0.49);
   C_7->Draw();
   C_7->cd();
   C_7->Range(22.5,1.043442,67.5,1.658512);
   C_7->SetFillColor(0);
   C_7->SetBorderMode(0);
   C_7->SetBorderSize(2);
   C_7->SetFrameBorderMode(0);
   C_7->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("alpha");
   grae->SetTitle("alpha");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.474416);
   grae->SetPointError(0,0,0,0.000371194,0.008386376);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,0.001989542,0.005409373);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002682861);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.01022805,0.00281023);
   
   TH1F *Graph_alpha13 = new TH1F("Graph_alpha13","alpha",100,27,63);
   Graph_alpha13->SetMinimum(1.104949);
   Graph_alpha13->SetMaximum(1.597005);
   Graph_alpha13->SetDirectory(0);
   Graph_alpha13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_alpha13->SetLineColor(ci);
   Graph_alpha13->GetXaxis()->SetLabelFont(42);
   Graph_alpha13->GetXaxis()->SetLabelSize(0.035);
   Graph_alpha13->GetXaxis()->SetTitleSize(0.035);
   Graph_alpha13->GetXaxis()->SetTitleFont(42);
   Graph_alpha13->GetYaxis()->SetLabelFont(42);
   Graph_alpha13->GetYaxis()->SetLabelSize(0.035);
   Graph_alpha13->GetYaxis()->SetTitleSize(0.035);
   Graph_alpha13->GetYaxis()->SetTitleFont(42);
   Graph_alpha13->GetZaxis()->SetLabelFont(42);
   Graph_alpha13->GetZaxis()->SetLabelSize(0.035);
   Graph_alpha13->GetZaxis()->SetTitleSize(0.035);
   Graph_alpha13->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_alpha13);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("alphaStat");
   gre->SetTitle("alpha");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,1.474416);
   gre->SetPointError(0,0,0.07578345);
   gre->SetPoint(1,40,1.216039);
   gre->SetPointError(1,0,0.07230666);
   gre->SetPoint(2,50,1.287164);
   gre->SetPointError(2,0,0.08697325);
   gre->SetPoint(3,60,1.322775);
   gre->SetPointError(3,0,0.07369161);
   
   TH1F *Graph_alphaStat7 = new TH1F("Graph_alphaStat7","alpha",100,27,63);
   Graph_alphaStat7->SetMinimum(1.103086);
   Graph_alphaStat7->SetMaximum(1.590846);
   Graph_alphaStat7->SetDirectory(0);
   Graph_alphaStat7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_alphaStat7->SetLineColor(ci);
   Graph_alphaStat7->GetXaxis()->SetLabelFont(42);
   Graph_alphaStat7->GetXaxis()->SetLabelSize(0.035);
   Graph_alphaStat7->GetXaxis()->SetTitleSize(0.035);
   Graph_alphaStat7->GetXaxis()->SetTitleFont(42);
   Graph_alphaStat7->GetYaxis()->SetLabelFont(42);
   Graph_alphaStat7->GetYaxis()->SetLabelSize(0.035);
   Graph_alphaStat7->GetYaxis()->SetTitleSize(0.035);
   Graph_alphaStat7->GetYaxis()->SetTitleFont(42);
   Graph_alphaStat7->GetZaxis()->SetLabelFont(42);
   Graph_alphaStat7->GetZaxis()->SetLabelSize(0.035);
   Graph_alphaStat7->GetZaxis()->SetTitleSize(0.035);
   Graph_alphaStat7->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_alphaStat7);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("alpha");
   grae->SetTitle("alpha");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,1.474416);
   grae->SetPointError(0,0,0,0.000371194,0.008386376);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,0.001989542,0.005409373);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002682861);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.01022805,0.00281023);
   
   TH1F *Graph_alpha14 = new TH1F("Graph_alpha14","alpha",100,27,63);
   Graph_alpha14->SetMinimum(1.187174);
   Graph_alpha14->SetMaximum(1.509678);
   Graph_alpha14->SetDirectory(0);
   Graph_alpha14->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_alpha14->SetLineColor(ci);
   Graph_alpha14->GetXaxis()->SetLabelFont(42);
   Graph_alpha14->GetXaxis()->SetLabelSize(0.035);
   Graph_alpha14->GetXaxis()->SetTitleSize(0.035);
   Graph_alpha14->GetXaxis()->SetTitleFont(42);
   Graph_alpha14->GetYaxis()->SetLabelFont(42);
   Graph_alpha14->GetYaxis()->SetLabelSize(0.035);
   Graph_alpha14->GetYaxis()->SetTitleSize(0.035);
   Graph_alpha14->GetYaxis()->SetTitleFont(42);
   Graph_alpha14->GetZaxis()->SetLabelFont(42);
   Graph_alpha14->GetZaxis()->SetLabelSize(0.035);
   Graph_alpha14->GetZaxis()->SetTitleSize(0.035);
   Graph_alpha14->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_alpha14);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4218926,0.9356646,0.5781074,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("alpha");
   pt->Draw();
   C_7->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_8
   C_8 = new TPad("C_8", "C_8",0.76,0.01,0.99,0.49);
   C_8->Draw();
   C_8->cd();
   C_8->Range(22.5,0.4383757,67.5,0.8101341);
   C_8->SetFillColor(0);
   C_8->SetBorderMode(0);
   C_8->SetBorderSize(2);
   C_8->SetFrameBorderMode(0);
   C_8->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("frac");
   grae->SetTitle("frac");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.549942);
   grae->SetPointError(0,0,0,0.02769746,0.02885475);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.005052632);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.007027193,0.01084936);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.001799883,0.001800258);
   
   TH1F *Graph_frac15 = new TH1F("Graph_frac15","frac",100,27,63);
   Graph_frac15->SetMinimum(0.4755516);
   Graph_frac15->SetMaximum(0.7729583);
   Graph_frac15->SetDirectory(0);
   Graph_frac15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_frac15->SetLineColor(ci);
   Graph_frac15->GetXaxis()->SetLabelFont(42);
   Graph_frac15->GetXaxis()->SetLabelSize(0.035);
   Graph_frac15->GetXaxis()->SetTitleSize(0.035);
   Graph_frac15->GetXaxis()->SetTitleFont(42);
   Graph_frac15->GetYaxis()->SetLabelFont(42);
   Graph_frac15->GetYaxis()->SetLabelSize(0.035);
   Graph_frac15->GetYaxis()->SetTitleSize(0.035);
   Graph_frac15->GetYaxis()->SetTitleFont(42);
   Graph_frac15->GetZaxis()->SetLabelFont(42);
   Graph_frac15->GetZaxis()->SetLabelSize(0.035);
   Graph_frac15->GetZaxis()->SetTitleSize(0.035);
   Graph_frac15->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_frac15);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("fracStat");
   gre->SetTitle("frac");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.549942);
   gre->SetPointError(0,0,0.053217);
   gre->SetPoint(1,40,0.6968665);
   gre->SetPointError(1,0,0.03641596);
   gre->SetPoint(2,50,0.7026572);
   gre->SetPointError(2,0,0.04639769);
   gre->SetPoint(3,60,0.6172068);
   gre->SetPointError(3,0,0.04857021);
   
   TH1F *Graph_fracStat8 = new TH1F("Graph_fracStat8","frac",100,27,63);
   Graph_fracStat8->SetMinimum(0.471492);
   Graph_fracStat8->SetMaximum(0.7742879);
   Graph_fracStat8->SetDirectory(0);
   Graph_fracStat8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_fracStat8->SetLineColor(ci);
   Graph_fracStat8->GetXaxis()->SetLabelFont(42);
   Graph_fracStat8->GetXaxis()->SetLabelSize(0.035);
   Graph_fracStat8->GetXaxis()->SetTitleSize(0.035);
   Graph_fracStat8->GetXaxis()->SetTitleFont(42);
   Graph_fracStat8->GetYaxis()->SetLabelFont(42);
   Graph_fracStat8->GetYaxis()->SetLabelSize(0.035);
   Graph_fracStat8->GetYaxis()->SetTitleSize(0.035);
   Graph_fracStat8->GetYaxis()->SetTitleFont(42);
   Graph_fracStat8->GetZaxis()->SetLabelFont(42);
   Graph_fracStat8->GetZaxis()->SetLabelSize(0.035);
   Graph_fracStat8->GetZaxis()->SetTitleSize(0.035);
   Graph_fracStat8->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_fracStat8);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("frac");
   grae->SetTitle("frac");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.549942);
   grae->SetPointError(0,0,0,0.02769746,0.02885475);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.005052632);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.007027193,0.01084936);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.001799883,0.001800258);
   
   TH1F *Graph_frac16 = new TH1F("Graph_frac16","frac",100,27,63);
   Graph_frac16->SetMinimum(0.5031183);
   Graph_frac16->SetMaximum(0.7326328);
   Graph_frac16->SetDirectory(0);
   Graph_frac16->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_frac16->SetLineColor(ci);
   Graph_frac16->GetXaxis()->SetLabelFont(42);
   Graph_frac16->GetXaxis()->SetLabelSize(0.035);
   Graph_frac16->GetXaxis()->SetTitleSize(0.035);
   Graph_frac16->GetXaxis()->SetTitleFont(42);
   Graph_frac16->GetYaxis()->SetLabelFont(42);
   Graph_frac16->GetYaxis()->SetLabelSize(0.035);
   Graph_frac16->GetYaxis()->SetTitleSize(0.035);
   Graph_frac16->GetYaxis()->SetTitleFont(42);
   Graph_frac16->GetZaxis()->SetLabelFont(42);
   Graph_frac16->GetZaxis()->SetLabelSize(0.035);
   Graph_frac16->GetZaxis()->SetTitleSize(0.035);
   Graph_frac16->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_frac16);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4421408,0.94,0.5578592,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("frac");
   pt->Draw();
   C_8->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
