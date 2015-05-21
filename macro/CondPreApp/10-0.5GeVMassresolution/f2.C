{
//=========Macro generated from canvas: C/C
//=========  (Tue May 19 20:07:52 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",6,130,1179,587);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.01,0.3233333,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(22.5,22.47473,67.5,67.38183);
   C_1->SetFillColor(0);
   C_1->SetBorderMode(0);
   C_1->SetBorderSize(2);
   C_1->SetFrameBorderMode(0);
   C_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,0.000469783,9.521273e-13);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.002615954,0.0002950292);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,0.006248464,0.006230438);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.0002689503,0.0001844169);
   
   TH1F *Graph_Graph_Graph_Graph_mean1117 = new TH1F("Graph_Graph_Graph_Graph_mean1117","mean",100,27,63);
   Graph_Graph_Graph_Graph_mean1117->SetMinimum(26.96544);
   Graph_Graph_Graph_Graph_mean1117->SetMaximum(62.89112);
   Graph_Graph_Graph_Graph_mean1117->SetDirectory(0);
   Graph_Graph_Graph_Graph_mean1117->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_mean1117->SetLineColor(ci);
   Graph_Graph_Graph_Graph_mean1117->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean1117->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_mean1117->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean1117->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_mean1117->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean1117->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean1117->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_mean1117);
   
   grae->Draw("alp");
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("meanStat");
   gre->SetTitle("mean");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,29.95972);
   gre->SetPointError(0,0,0.005422914);
   gre->SetPoint(1,40,39.94931);
   gre->SetPointError(1,0,0.007195136);
   gre->SetPoint(2,50,49.90091);
   gre->SetPointError(2,0,0.008555621);
   gre->SetPoint(3,60,59.89713);
   gre->SetPointError(3,0,0.009706139);
   
   TH1F *Graph_Graph_Graph_Graph_meanStat1114 = new TH1F("Graph_Graph_Graph_Graph_meanStat1114","mean",100,27,63);
   Graph_Graph_Graph_Graph_meanStat1114->SetMinimum(26.95904);
   Graph_Graph_Graph_Graph_meanStat1114->SetMaximum(62.90209);
   Graph_Graph_Graph_Graph_meanStat1114->SetDirectory(0);
   Graph_Graph_Graph_Graph_meanStat1114->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_meanStat1114->SetLineColor(ci);
   Graph_Graph_Graph_Graph_meanStat1114->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_meanStat1114->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_meanStat1114->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_meanStat1114->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_meanStat1114->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_meanStat1114->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_meanStat1114->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph_meanStat1114);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,0.000469783,9.521273e-13);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.002615954,0.0002950292);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,0.006248464,0.006230438);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.0002689503,0.0001844169);
   
   TH1F *Graph_Graph_Graph_Graph_mean2228 = new TH1F("Graph_Graph_Graph_Graph_mean2228","mean",100,27,63);
   Graph_Graph_Graph_Graph_mean2228->SetMinimum(26.96544);
   Graph_Graph_Graph_Graph_mean2228->SetMaximum(62.89112);
   Graph_Graph_Graph_Graph_mean2228->SetDirectory(0);
   Graph_Graph_Graph_Graph_mean2228->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_mean2228->SetLineColor(ci);
   Graph_Graph_Graph_Graph_mean2228->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean2228->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_mean2228->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean2228->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_mean2228->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_mean2228->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_mean2228->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_mean2228);
   
   grae->Draw("p|>");
   
   TPaveText *pt = new TPaveText(0.4237921,0.94,0.5762079,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("mean");
   pt->Draw();
   TLine *line = new TLine(59.80987,59.69975,29.61974,29.51656);

   ci = TColor::GetColor("#cc66cc");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.3433333,0.01,0.6566667,0.99);
   C_2->Draw();
   C_2->cd();
   C_2->Range(22.5,0.2092722,67.5,0.6686725);
   C_2->SetFillColor(0);
   C_2->SetBorderMode(0);
   C_2->SetBorderSize(2);
   C_2->SetFrameBorderMode(0);
   C_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,3.28626e-13,3.28626e-13);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,2.256917e-12,8.571902e-05);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.002874717,0.003161333);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.003686261,0.0002548107);
   
   TH1F *Graph_Graph_Graph_Graph_sigma3339 = new TH1F("Graph_Graph_Graph_Graph_sigma3339","sigma",100,27,63);
   Graph_Graph_Graph_Graph_sigma3339->SetMinimum(0.2552122);
   Graph_Graph_Graph_Graph_sigma3339->SetMaximum(0.6227325);
   Graph_Graph_Graph_Graph_sigma3339->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigma3339->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigma3339->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigma3339->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma3339->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma3339->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma3339->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma3339->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma3339->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma3339->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_sigma3339);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigmaStat");
   gre->SetTitle("sigma");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.2858389);
   gre->SetPointError(0,0,0.006380716);
   gre->SetPoint(1,40,0.3810689);
   gre->SetPointError(1,0,0.008510948);
   gre->SetPoint(2,50,0.487961);
   gre->SetPointError(2,0,0.01039632);
   gre->SetPoint(3,60,0.591851);
   gre->SetPointError(3,0,0.0110008);
   
   TH1F *Graph_Graph_Graph_Graph_sigmaStat2225 = new TH1F("Graph_Graph_Graph_Graph_sigmaStat2225","sigma",100,27,63);
   Graph_Graph_Graph_Graph_sigmaStat2225->SetMinimum(0.2471188);
   Graph_Graph_Graph_Graph_sigmaStat2225->SetMaximum(0.6351912);
   Graph_Graph_Graph_Graph_sigmaStat2225->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigmaStat2225->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigmaStat2225->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigmaStat2225->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph_sigmaStat2225);
   
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetLineColor(3);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,3.28626e-13,3.28626e-13);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,2.256917e-12,8.571902e-05);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.002874717,0.003161333);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.003686261,0.0002548107);
   
   TH1F *Graph_Graph_Graph_Graph_sigma44410 = new TH1F("Graph_Graph_Graph_Graph_sigma44410","sigma",100,27,63);
   Graph_Graph_Graph_Graph_sigma44410->SetMinimum(0.2552122);
   Graph_Graph_Graph_Graph_sigma44410->SetMaximum(0.6227325);
   Graph_Graph_Graph_Graph_sigma44410->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigma44410->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigma44410->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigma44410->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma44410->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma44410->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma44410->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma44410->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma44410->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma44410->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_sigma44410);
   
   grae->Draw("p|>");
   
   pt = new TPaveText(0.4156851,0.94,0.5843149,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma");
   pt->Draw();
   
   TF1 *tmp = new TF1("tmp","(0.010226*x)-0.0215593",30,60);
   tmp->SetFillColor(19);
   tmp->SetFillStyle(0);

   ci = TColor::GetColor("#cc33cc");
   tmp->SetLineColor(ci);
   tmp->SetLineWidth(2);
   tmp->SetLineStyle(2);
   tmp->GetXaxis()->SetLabelFont(42);
   tmp->GetXaxis()->SetLabelSize(0.035);
   tmp->GetXaxis()->SetTitleSize(0.035);
   tmp->GetXaxis()->SetTitleFont(42);
   tmp->GetYaxis()->SetLabelFont(42);
   tmp->GetYaxis()->SetLabelSize(0.035);
   tmp->GetYaxis()->SetTitleSize(0.035);
   tmp->GetYaxis()->SetTitleFont(42);
   tmp->Draw("sames");
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.6766667,0.01,0.99,0.99);
   C_3->Draw();
   C_3->cd();
   C_3->Range(22.5,0.3627572,67.5,1.229716);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
   C_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,0.002392026,0.00224625);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,0.002884949,9.314515e-05);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.009655952,0.007137143);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.01349143,0.0135774);
   
   TH1F *Graph_Graph_Graph_Graph_sigma_cb55511 = new TH1F("Graph_Graph_Graph_Graph_sigma_cb55511","sigma_cb",100,27,63);
   Graph_Graph_Graph_Graph_sigma_cb55511->SetMinimum(0.4494531);
   Graph_Graph_Graph_Graph_sigma_cb55511->SetMaximum(1.14302);
   Graph_Graph_Graph_Graph_sigma_cb55511->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigma_cb55511->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigma_cb55511->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb55511->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_sigma_cb55511);
   
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigma_cbStat");
   gre->SetTitle("sigma_cb");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetPoint(0,30,0.5096423);
   gre->SetPointError(0,0,0.01356009);
   gre->SetPoint(1,40,0.6835205);
   gre->SetPointError(1,0,0.01814551);
   gre->SetPoint(2,50,0.841637);
   gre->SetPointError(2,0,0.02155012);
   gre->SetPoint(3,60,1.071645);
   gre->SetPointError(3,0,0.02345126);
   
   TH1F *Graph_Graph_Graph_Graph_sigma_cbStat3336 = new TH1F("Graph_Graph_Graph_Graph_sigma_cbStat3336","sigma_cb",100,27,63);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->SetMinimum(0.4361808);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->SetMaximum(1.154998);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigma_cbStat3336->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cbStat3336->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph_sigma_cbStat3336);
   
   gre->Draw("p");
   
   pt = new TPaveText(0.4403546,0.94,0.6991253,0.995,"blNDC");
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
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,0.002392026,0.00224625);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,0.002884949,9.314515e-05);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.009655952,0.007137143);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.01349143,0.0135774);
   
   TH1F *Graph_Graph_Graph_Graph_sigma_cb66612 = new TH1F("Graph_Graph_Graph_Graph_sigma_cb66612","sigma_cb",100,27,63);
   Graph_Graph_Graph_Graph_sigma_cb66612->SetMinimum(0.4494531);
   Graph_Graph_Graph_Graph_sigma_cb66612->SetMaximum(1.14302);
   Graph_Graph_Graph_Graph_sigma_cb66612->SetDirectory(0);
   Graph_Graph_Graph_Graph_sigma_cb66612->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph_sigma_cb66612->SetLineColor(ci);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_Graph_sigma_cb66612->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph_Graph_sigma_cb66612);
   
   
   TF1 *Pol3 = new TF1("Pol3","pol3",27,63);
   Pol3->SetFillColor(19);
   Pol3->SetFillStyle(0);
   Pol3->SetLineColor(2);
   Pol3->SetLineWidth(2);
   Pol3->SetChisquare(11.01075);
   Pol3->SetNDF(0);
   Pol3->GetXaxis()->SetLabelFont(42);
   Pol3->GetXaxis()->SetLabelSize(0.035);
   Pol3->GetXaxis()->SetTitleSize(0.035);
   Pol3->GetXaxis()->SetTitleFont(42);
   Pol3->GetYaxis()->SetLabelFont(42);
   Pol3->GetYaxis()->SetLabelSize(0.035);
   Pol3->GetYaxis()->SetTitleSize(0.035);
   Pol3->GetYaxis()->SetTitleFont(42);
   Pol3->SetParameter(0,0.07494366);
   Pol3->SetParError(0,0.01371696);
   Pol3->SetParLimits(0,0,0);
   Pol3->SetParameter(1,0.01235939);
   Pol3->SetParError(1,0.0006028197);
   Pol3->SetParLimits(1,0,0);
   Pol3->SetParameter(2,7.876638e-05);
   Pol3->SetParError(2,1.534026e-05);
   Pol3->SetParLimits(2,0,0);
   Pol3->SetParameter(3,-2.340986e-07);
   Pol3->SetParError(3,2.170711e-07);
   Pol3->SetParLimits(3,0,0);
   grae->GetListOfFunctions()->Add(Pol3);
   grae->Draw("p|>");
   
   pt = new TPaveText(0.3724472,0.94,0.6275528,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("sigma_cb");
   pt->Draw();
   C_3->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
   C->ToggleToolBar();
}
