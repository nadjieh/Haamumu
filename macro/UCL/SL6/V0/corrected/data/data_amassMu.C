{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Nov 26 11:16:51 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",839,114,700,500);
   Canvas_1->Range(-125,-555.0563,1125,4995.506);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *amassMu__15 = new TH1D("amassMu__15","",500,0,1000);
   amassMu__15->SetBinContent(11,3979);
   amassMu__15->SetBinContent(12,3744);
   amassMu__15->SetBinContent(13,3626);
   amassMu__15->SetBinContent(14,3514);
   amassMu__15->SetBinContent(15,3602);
   amassMu__15->SetBinContent(16,3697);
   amassMu__15->SetBinContent(17,3806);
   amassMu__15->SetBinContent(18,3820);
   amassMu__15->SetBinContent(19,3845);
   amassMu__15->SetBinContent(20,3631);
   amassMu__15->SetBinContent(21,3805);
   amassMu__15->SetBinContent(22,3838);
   amassMu__15->SetBinContent(23,3708);
   amassMu__15->SetBinContent(24,3880);
   amassMu__15->SetBinContent(25,3805);
   amassMu__15->SetBinContent(26,3709);
   amassMu__15->SetBinContent(27,3551);
   amassMu__15->SetBinContent(28,3602);
   amassMu__15->SetBinContent(29,3424);
   amassMu__15->SetBinContent(30,3379);
   amassMu__15->SetBinContent(31,3552);
   amassMu__15->SetBinContent(32,3512);
   amassMu__15->SetBinContent(33,3680);
   amassMu__15->SetBinContent(34,3968);
   amassMu__15->SetBinContent(35,4229);
   amassMu__15->SetEntries(92906);
   amassMu__15->SetStats(0); 
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu__15");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 92906  ");
   text = ptstats->AddText("Mean  =  44.98");
   text = ptstats->AddText("RMS   =  14.52");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu__15->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu__15);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu__15->SetLineColor(ci);
   amassMu__15->GetXaxis()->SetLabelFont(42);
   amassMu__15->GetXaxis()->SetLabelSize(0.035);
   amassMu__15->GetXaxis()->SetTitleSize(0.035);
   amassMu__15->GetXaxis()->SetTitleFont(42);
   amassMu__15->GetYaxis()->SetLabelFont(42);
   amassMu__15->GetYaxis()->SetLabelSize(0.035);
   amassMu__15->GetYaxis()->SetTitleSize(0.035);
   amassMu__15->GetYaxis()->SetTitleFont(42);
   amassMu__15->GetZaxis()->SetLabelFont(42);
   amassMu__15->GetZaxis()->SetLabelSize(0.035);
   amassMu__15->GetZaxis()->SetTitleSize(0.035);
   amassMu__15->GetZaxis()->SetTitleFont(42);
   amassMu__15->Draw("");
   
   TPaveText *pt = new TPaveText(0.4124138,0.94,0.5875862,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu__15");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
