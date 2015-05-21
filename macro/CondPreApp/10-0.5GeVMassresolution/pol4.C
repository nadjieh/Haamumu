{
//=========Macro generated from canvas: C/C
//=========  (Tue May 19 14:26:29 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",104,109,1179,529);
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
   
   TH1F *Graph_Graph_mean11 = new TH1F("Graph_Graph_mean11","mean",100,27,63);
   Graph_Graph_mean11->SetMinimum(26.96544);
   Graph_Graph_mean11->SetMaximum(62.89112);
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
   gre->SetPoint(0,30,29.95972);
   gre->SetPointError(0,0,0.005422914);
   gre->SetPoint(1,40,39.94931);
   gre->SetPointError(1,0,0.007195136);
   gre->SetPoint(2,50,49.90091);
   gre->SetPointError(2,0,0.008555621);
   gre->SetPoint(3,60,59.89713);
   gre->SetPointError(3,0,0.009706139);
   
   TH1F *Graph_Graph_meanStat11 = new TH1F("Graph_Graph_meanStat11","mean",100,27,63);
   Graph_Graph_meanStat11->SetMinimum(26.95904);
   Graph_Graph_meanStat11->SetMaximum(62.90209);
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
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,0.000469783,9.521273e-13);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.002615954,0.0002950292);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,0.006248464,0.006230438);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.0002689503,0.0001844169);
   
   TH1F *Graph_Graph_mean22 = new TH1F("Graph_Graph_mean22","mean",100,27,63);
   Graph_Graph_mean22->SetMinimum(26.96544);
   Graph_Graph_mean22->SetMaximum(62.89112);
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
   
   TPaveText *pt = new TPaveText(0.4237921,0.94,0.5762079,0.995,"blNDC");
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
   
   TH1F *Graph_Graph_sigma33 = new TH1F("Graph_Graph_sigma33","sigma",100,27,63);
   Graph_Graph_sigma33->SetMinimum(0.2552122);
   Graph_Graph_sigma33->SetMaximum(0.6227325);
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
   gre->SetPoint(0,30,0.2858389);
   gre->SetPointError(0,0,0.006380716);
   gre->SetPoint(1,40,0.3810689);
   gre->SetPointError(1,0,0.008510948);
   gre->SetPoint(2,50,0.487961);
   gre->SetPointError(2,0,0.01039632);
   gre->SetPoint(3,60,0.591851);
   gre->SetPointError(3,0,0.0110008);
   
   TH1F *Graph_Graph_sigmaStat22 = new TH1F("Graph_Graph_sigmaStat22","sigma",100,27,63);
   Graph_Graph_sigmaStat22->SetMinimum(0.2471188);
   Graph_Graph_sigmaStat22->SetMaximum(0.6351912);
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
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,3.28626e-13,3.28626e-13);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,2.256917e-12,8.571902e-05);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.002874717,0.003161333);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.003686261,0.0002548107);
   
   TH1F *Graph_Graph_sigma44 = new TH1F("Graph_Graph_sigma44","sigma",100,27,63);
   Graph_Graph_sigma44->SetMinimum(0.2552122);
   Graph_Graph_sigma44->SetMaximum(0.6227325);
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
   
   pt = new TPaveText(0.4156851,0.94,0.5843149,0.995,"blNDC");
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
   
   TH1F *Graph_Graph_sigma_cb55 = new TH1F("Graph_Graph_sigma_cb55","sigma_cb",100,27,63);
   Graph_Graph_sigma_cb55->SetMinimum(0.4494531);
   Graph_Graph_sigma_cb55->SetMaximum(1.14302);
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
   gre->SetPoint(0,30,0.5096423);
   gre->SetPointError(0,0,0.01356009);
   gre->SetPoint(1,40,0.6835205);
   gre->SetPointError(1,0,0.01814551);
   gre->SetPoint(2,50,0.841637);
   gre->SetPointError(2,0,0.02155012);
   gre->SetPoint(3,60,1.071645);
   gre->SetPointError(3,0,0.02345126);
   
   TH1F *Graph_Graph_sigma_cbStat33 = new TH1F("Graph_Graph_sigma_cbStat33","sigma_cb",100,27,63);
   Graph_Graph_sigma_cbStat33->SetMinimum(0.4361808);
   Graph_Graph_sigma_cbStat33->SetMaximum(1.154998);
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
   
   TH1F *Graph_Graph_sigma_cb66 = new TH1F("Graph_Graph_sigma_cb66","sigma_cb",100,27,63);
   Graph_Graph_sigma_cb66->SetMinimum(0.4494531);
   Graph_Graph_sigma_cb66->SetMaximum(1.14302);
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
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol4",29.52,60.12);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(11.12064);
   PrevFitTMP->SetNDF(0);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,0.08335659);
   PrevFitTMP->SetParError(0,0.01280835);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,0.01193581);
   PrevFitTMP->SetParError(1,0.000566144);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,8.243647e-05);
   PrevFitTMP->SetParError(2,1.407999e-05);
   PrevFitTMP->SetParLimits(2,0,0);
   PrevFitTMP->SetParameter(3,-1.753602e-07);
   PrevFitTMP->SetParError(3,3.400169e-07);
   PrevFitTMP->SetParLimits(3,0,0);
   PrevFitTMP->SetParameter(4,-5.618808e-10);
   PrevFitTMP->SetParError(4,4.470739e-09);
   PrevFitTMP->SetParLimits(4,0,0);
   grae->GetListOfFunctions()->Add(PrevFitTMP);
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
}
