{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Mon May 18 20:07:12 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",13,34,700,530);
   Canvas_1->Range(22.5,-0.009395554,67.5,0.08455998);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("widthStat");
   gre->SetTitle("width");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.04523542);
   gre->SetPointError(0,0,0.01339278);
   gre->SetPoint(1,40,0.01769103);
   gre->SetPointError(1,0,0.01212437);
   gre->SetPoint(2,50,0.04927796);
   gre->SetPointError(2,0,0.0195594);
   gre->SetPoint(3,60,0.03189469);
   gre->SetPointError(3,0,0.01725244);
   
   TH1F *Graph_widthStat1 = new TH1F("Graph_widthStat1","width",100,27,63);
   Graph_widthStat1->SetMinimum(0);
   Graph_widthStat1->SetMaximum(0.07516443);
   Graph_widthStat1->SetDirectory(0);
   Graph_widthStat1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_widthStat1->SetLineColor(ci);
   Graph_widthStat1->GetXaxis()->SetLabelFont(42);
   Graph_widthStat1->GetXaxis()->SetLabelSize(0.035);
   Graph_widthStat1->GetXaxis()->SetTitleSize(0.035);
   Graph_widthStat1->GetXaxis()->SetTitleFont(42);
   Graph_widthStat1->GetYaxis()->SetLabelFont(42);
   Graph_widthStat1->GetYaxis()->SetLabelSize(0.035);
   Graph_widthStat1->GetYaxis()->SetTitleSize(0.035);
   Graph_widthStat1->GetYaxis()->SetTitleFont(42);
   Graph_widthStat1->GetZaxis()->SetLabelFont(42);
   Graph_widthStat1->GetZaxis()->SetLabelSize(0.035);
   Graph_widthStat1->GetZaxis()->SetTitleSize(0.035);
   Graph_widthStat1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_widthStat1);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol0",27,63);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(3.125199);
   PrevFitTMP->SetNDF(3);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,0.03315845);
   PrevFitTMP->SetParError(0,0.007381841);
   PrevFitTMP->SetParLimits(0,0,0);
   gre->GetListOfFunctions()->Add(PrevFitTMP);
   gre->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4454598,0.94,0.5545402,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("width");
   pt->Draw();
      tex = new TLatex(31.09914,0.07048647,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(30.64655,0.06731498,"p0 = 0.033 #pm 0.007");
   tex->SetLineWidth(2);
   tex->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
   Canvas_1->ToggleToolBar();
}
