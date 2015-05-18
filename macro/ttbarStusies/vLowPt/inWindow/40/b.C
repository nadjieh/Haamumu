{
//=========Macro generated from canvas: Canvas_1_n2/Canvas_1
//=========  (Fri Nov 28 23:56:25 2014) by ROOT version5.34/19
   TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1",204,225,538,343);
   Canvas_1_n2->Range(13.75,34.74718,76.25,322.7753);
   Canvas_1_n2->SetFillColor(0);
   Canvas_1_n2->SetBorderMode(0);
   Canvas_1_n2->SetBorderSize(2);
   Canvas_1_n2->SetFrameBorderMode(0);
   Canvas_1_n2->SetFrameBorderMode(0);
   
   TH1D *amassMu__1 = new TH1D("amassMu__1","amassMu",500,0,1000);
   amassMu__1->SetBinContent(11,186);
   amassMu__1->SetBinContent(12,210);
   amassMu__1->SetBinContent(13,208);
   amassMu__1->SetBinContent(14,216);
   amassMu__1->SetBinContent(15,229);
   amassMu__1->SetBinContent(16,280);
   amassMu__1->SetBinContent(17,274);
   amassMu__1->SetBinContent(18,273);
   amassMu__1->SetBinContent(19,283);
   amassMu__1->SetBinContent(20,263);
   amassMu__1->SetBinContent(21,249);
   amassMu__1->SetBinContent(22,246);
   amassMu__1->SetBinContent(23,273);
   amassMu__1->SetBinContent(24,248);
   amassMu__1->SetBinContent(25,248);
   amassMu__1->SetBinContent(26,221);
   amassMu__1->SetBinContent(27,224);
   amassMu__1->SetBinContent(28,189);
   amassMu__1->SetBinContent(29,188);
   amassMu__1->SetBinContent(30,164);
   amassMu__1->SetBinContent(31,138);
   amassMu__1->SetBinContent(32,106);
   amassMu__1->SetBinContent(33,94);
   amassMu__1->SetBinContent(34,96);
   amassMu__1->SetBinContent(35,74);
   amassMu__1->SetEntries(5180);
   amassMu__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 5180   ");
   text = ptstats->AddText("Mean  =  42.08");
   text = ptstats->AddText("RMS   =  12.68");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu__1->SetLineColor(ci);
   amassMu__1->GetXaxis()->SetRange(11,35);
   amassMu__1->GetXaxis()->SetLabelFont(42);
   amassMu__1->GetXaxis()->SetLabelSize(0.035);
   amassMu__1->GetXaxis()->SetTitleSize(0.035);
   amassMu__1->GetXaxis()->SetTitleFont(42);
   amassMu__1->GetYaxis()->SetLabelFont(42);
   amassMu__1->GetYaxis()->SetLabelSize(0.035);
   amassMu__1->GetYaxis()->SetTitleSize(0.035);
   amassMu__1->GetYaxis()->SetTitleFont(42);
   amassMu__1->GetZaxis()->SetLabelFont(42);
   amassMu__1->GetZaxis()->SetLabelSize(0.035);
   amassMu__1->GetZaxis()->SetTitleSize(0.035);
   amassMu__1->GetZaxis()->SetTitleFont(42);
   amassMu__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.4179026,0.94,0.5820974,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu");
   pt->Draw();
   Canvas_1_n2->Modified();
   Canvas_1_n2->cd();
   Canvas_1_n2->SetSelected(Canvas_1_n2);
}
