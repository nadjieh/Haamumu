{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Sat Nov 29 23:21:31 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",261,95,538,327);
   Canvas_1->Range(-125,-31.5,1125,283.5);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *amassMu__12 = new TH1D("amassMu__12","amassMu__12",500,0,1000);
   amassMu__12->SetBinContent(6,176);
   amassMu__12->SetBinContent(7,86);
   amassMu__12->SetBinContent(8,84);
   amassMu__12->SetBinContent(9,74);
   amassMu__12->SetBinContent(10,59);
   /*amassMu__12->SetBinContent(11,43);
   amassMu__12->SetBinContent(12,36);
   amassMu__12->SetBinContent(13,61);
   amassMu__12->SetBinContent(14,51);
   amassMu__12->SetBinContent(15,52);
   amassMu__12->SetBinContent(16,40);
   amassMu__12->SetBinContent(17,47);
   amassMu__12->SetBinContent(18,55);
   amassMu__12->SetBinContent(19,70);
   amassMu__12->SetBinContent(20,56);
   amassMu__12->SetBinContent(21,46);
   amassMu__12->SetBinContent(22,54);
   amassMu__12->SetBinContent(23,49);
   amassMu__12->SetBinContent(24,40);
   amassMu__12->SetBinContent(25,47);
   amassMu__12->SetBinContent(26,34);
   amassMu__12->SetBinContent(27,42);
   amassMu__12->SetBinContent(28,34);
   amassMu__12->SetBinContent(29,36);
   amassMu__12->SetBinContent(30,35);
   amassMu__12->SetBinContent(31,30);
   amassMu__12->SetBinContent(32,23);
   amassMu__12->SetBinContent(33,23);
   amassMu__12->SetBinContent(34,19);
   amassMu__12->SetBinContent(35,23);
   amassMu__12->SetBinContent(36,32);*/
   amassMu__12->SetBinContent(37,24);
   amassMu__12->SetBinContent(38,28);
   amassMu__12->SetBinContent(39,32);
   amassMu__12->SetBinContent(40,36);
   amassMu__12->SetBinContent(41,35);
   amassMu__12->SetBinContent(42,55);
   amassMu__12->SetBinContent(43,65);
   amassMu__12->SetBinContent(44,85);
   amassMu__12->SetBinContent(45,190);
   amassMu__12->SetBinContent(46,240);
   amassMu__12->SetBinContent(47,106);
   amassMu__12->SetBinContent(48,24);
   amassMu__12->SetBinContent(49,5);
   amassMu__12->SetBinContent(50,2);
   amassMu__12->SetBinContent(51,1);
   amassMu__12->SetBinContent(52,2);
   amassMu__12->SetEntries(2487);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu__12");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 2487   ");
   text = ptstats->AddText("Mean  =  53.89");
   text = ptstats->AddText("RMS   =  29.69");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu__12->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu__12);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu__12->SetLineColor(ci);
   amassMu__12->GetXaxis()->SetLabelFont(42);
   amassMu__12->GetXaxis()->SetLabelSize(0.035);
   amassMu__12->GetXaxis()->SetTitleSize(0.035);
   amassMu__12->GetXaxis()->SetTitleFont(42);
   amassMu__12->GetYaxis()->SetLabelFont(42);
   amassMu__12->GetYaxis()->SetLabelSize(0.035);
   amassMu__12->GetYaxis()->SetTitleSize(0.035);
   amassMu__12->GetYaxis()->SetTitleFont(42);
   amassMu__12->GetZaxis()->SetLabelFont(42);
   amassMu__12->GetZaxis()->SetLabelSize(0.035);
   amassMu__12->GetZaxis()->SetTitleSize(0.035);
   amassMu__12->GetZaxis()->SetTitleFont(42);
   amassMu__12->Draw("");
   
   TPaveText *pt = new TPaveText(0.4179026,0.94,0.5820974,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu__12");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
