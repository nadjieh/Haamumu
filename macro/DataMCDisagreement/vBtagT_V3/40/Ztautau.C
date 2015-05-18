{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Jan 13 11:13:07 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",530,169,700,502);
   Canvas_1->Range(-12,-0.8450219,108,7.605196);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *amassMu = new TH1D("amassMu","amassMu",125,0,1000);
   amassMu->SetBinContent(3,1.082212);
   amassMu->SetBinContent(4,0.9087198);
   amassMu->SetBinContent(5,6.438261);
   amassMu->SetBinContent(6,3.818378);
   amassMu->SetBinContent(7,3.799358);
   amassMu->SetBinContent(8,0.6068995);
   amassMu->SetBinContent(9,1.076352);
   amassMu->SetEntries(20);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu");
   text->SetTextSize(0.02944);
   text = ptstats->AddText("Entries = 20     ");
   text = ptstats->AddText("Mean  =  42.53");
   text = ptstats->AddText("RMS   =  11.26");
   text = ptstats->AddText("#chi^{2} / ndf = 3.422 / 4");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(100);
   ptstats->Draw();
   amassMu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu);
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","gaus",8,72);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(3.422341);
   PrevFitTMP->SetNDF(4);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,4.895977);
   PrevFitTMP->SetParError(0,1.756431);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,42.48403);
   PrevFitTMP->SetParError(1,2.506875);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,9.348124);
   PrevFitTMP->SetParError(2,2.318706);
   PrevFitTMP->SetParLimits(2,0,120.132);
   amassMu->GetListOfFunctions()->Add(PrevFitTMP);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu->SetLineColor(ci);
   amassMu->GetXaxis()->SetRange(1,12);
   amassMu->GetXaxis()->SetLabelFont(42);
   amassMu->GetXaxis()->SetLabelSize(0.035);
   amassMu->GetXaxis()->SetTitleSize(0.035);
   amassMu->GetXaxis()->SetTitleFont(42);
   amassMu->GetYaxis()->SetLabelFont(42);
   amassMu->GetYaxis()->SetLabelSize(0.035);
   amassMu->GetYaxis()->SetTitleSize(0.035);
   amassMu->GetYaxis()->SetTitleFont(42);
   amassMu->GetZaxis()->SetLabelFont(42);
   amassMu->GetZaxis()->SetLabelSize(0.035);
   amassMu->GetZaxis()->SetTitleSize(0.035);
   amassMu->GetZaxis()->SetTitleFont(42);
   amassMu->Draw("");
   
   TPaveText *pt = new TPaveText(0.4124138,0.94,0.5875862,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
