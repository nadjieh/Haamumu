{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Nov 26 11:17:07 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",839,114,700,500);
   Canvas_1->Range(-125,-5191.069,1125,46719.62);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *hPt__127 = new TH1D("hPt__127","",50,0,1000);
   hPt__127->SetBinContent(1,39551);
   hPt__127->SetBinContent(2,34118);
   hPt__127->SetBinContent(3,11334);
   hPt__127->SetBinContent(4,4069);
   hPt__127->SetBinContent(5,1740);
   hPt__127->SetBinContent(6,875);
   hPt__127->SetBinContent(7,452);
   hPt__127->SetBinContent(8,291);
   hPt__127->SetBinContent(9,173);
   hPt__127->SetBinContent(10,110);
   hPt__127->SetBinContent(11,69);
   hPt__127->SetBinContent(12,40);
   hPt__127->SetBinContent(13,25);
   hPt__127->SetBinContent(14,19);
   hPt__127->SetBinContent(15,9);
   hPt__127->SetBinContent(16,4);
   hPt__127->SetBinContent(17,5);
   hPt__127->SetBinContent(18,9);
   hPt__127->SetBinContent(19,4);
   hPt__127->SetBinContent(20,1);
   hPt__127->SetBinContent(21,1);
   hPt__127->SetBinContent(22,3);
   hPt__127->SetBinContent(25,3);
   hPt__127->SetBinContent(35,1);
   hPt__127->SetEntries(92906);
      hPt__127->SetStats(0);
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hPt__127");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 92906  ");
   text = ptstats->AddText("Mean  =  29.33");
   text = ptstats->AddText("RMS   =  25.81");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hPt__127->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hPt__127);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hPt__127->SetLineColor(ci);
   hPt__127->GetXaxis()->SetLabelFont(42);
   hPt__127->GetXaxis()->SetLabelSize(0.035);
   hPt__127->GetXaxis()->SetTitleSize(0.035);
   hPt__127->GetXaxis()->SetTitleFont(42);
   hPt__127->GetYaxis()->SetLabelFont(42);
   hPt__127->GetYaxis()->SetLabelSize(0.035);
   hPt__127->GetYaxis()->SetTitleSize(0.035);
   hPt__127->GetYaxis()->SetTitleFont(42);
   hPt__127->GetZaxis()->SetLabelFont(42);
   hPt__127->GetZaxis()->SetLabelSize(0.035);
   hPt__127->GetZaxis()->SetTitleSize(0.035);
   hPt__127->GetZaxis()->SetTitleFont(42);
   hPt__127->Draw("");
   
   TPaveText *pt = new TPaveText(0.4619828,0.94,0.5380172,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("hPt__127");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
