{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Mon May 18 14:36:29 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",13,34,700,502);
   Canvas_1->Range(22.5,0.5416081,67.5,0.6952385);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("fracStat");
   gre->SetTitle("frac");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.612212);
   gre->SetPointError(0,0,0.03903587);
   gre->SetPoint(1,40,0.6035794);
   gre->SetPointError(1,0,0.03636626);
   gre->SetPoint(2,50,0.6322553);
   gre->SetPointError(2,0,0.03737816);
   gre->SetPoint(3,60,0.6045979);
   gre->SetPointError(3,0,0.02945816);
   
   TH1F *Graph_fracStat1 = new TH1F("Graph_fracStat1","frac",100,27,63);
   Graph_fracStat1->SetMinimum(0.5569711);
   Graph_fracStat1->SetMaximum(0.6798755);
   Graph_fracStat1->SetDirectory(0);
   Graph_fracStat1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_fracStat1->SetLineColor(ci);
   Graph_fracStat1->GetXaxis()->SetLabelFont(42);
   Graph_fracStat1->GetXaxis()->SetLabelSize(0.035);
   Graph_fracStat1->GetXaxis()->SetTitleSize(0.035);
   Graph_fracStat1->GetXaxis()->SetTitleFont(42);
   Graph_fracStat1->GetYaxis()->SetLabelFont(42);
   Graph_fracStat1->GetYaxis()->SetLabelSize(0.035);
   Graph_fracStat1->GetYaxis()->SetTitleSize(0.035);
   Graph_fracStat1->GetYaxis()->SetTitleFont(42);
   Graph_fracStat1->GetZaxis()->SetLabelFont(42);
   Graph_fracStat1->GetZaxis()->SetLabelSize(0.035);
   Graph_fracStat1->GetZaxis()->SetTitleSize(0.035);
   Graph_fracStat1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_fracStat1);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol0",27,63);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(0.4104194);
   PrevFitTMP->SetNDF(3);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,0.6119207);
   PrevFitTMP->SetParError(0,0.0174594);
   PrevFitTMP->SetParLimits(0,0,0);
   gre->GetListOfFunctions()->Add(PrevFitTMP);
   gre->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4583908,0.94,0.5416092,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("frac");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
