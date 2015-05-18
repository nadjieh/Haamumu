{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Nov 26 11:17:42 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",839,114,700,500);
   Canvas_1->Range(-125,-4557.394,1125,41016.54);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *aptMu__63 = new TH1D("aptMu__63","",50,0,1000);
   aptMu__63->SetBinContent(1,21630);
   aptMu__63->SetBinContent(2,34723);
   aptMu__63->SetBinContent(3,20320);
   aptMu__63->SetBinContent(4,8354);
   aptMu__63->SetBinContent(5,3896);
   aptMu__63->SetBinContent(6,1879);
   aptMu__63->SetBinContent(7,937);
   aptMu__63->SetBinContent(8,482);
   aptMu__63->SetBinContent(9,249);
   aptMu__63->SetBinContent(10,172);
   aptMu__63->SetBinContent(11,112);
   aptMu__63->SetBinContent(12,45);
   aptMu__63->SetBinContent(13,33);
   aptMu__63->SetBinContent(14,19);
   aptMu__63->SetBinContent(15,21);
   aptMu__63->SetBinContent(16,7);
   aptMu__63->SetBinContent(17,10);
   aptMu__63->SetBinContent(18,4);
   aptMu__63->SetBinContent(19,3);
   aptMu__63->SetBinContent(20,3);
   aptMu__63->SetBinContent(21,2);
   aptMu__63->SetBinContent(22,2);
   aptMu__63->SetBinContent(23,1);
   aptMu__63->SetBinContent(25,1);
   aptMu__63->SetBinContent(29,1);
   aptMu__63->SetEntries(92906);
   aptMu__63->SetStats(0);   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("aptMu__63");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 92906  ");
   text = ptstats->AddText("Mean  =  40.33");
   text = ptstats->AddText("RMS   =  29.78");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   aptMu__63->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(aptMu__63);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   aptMu__63->SetLineColor(ci);
   aptMu__63->GetXaxis()->SetLabelFont(42);
   aptMu__63->GetXaxis()->SetLabelSize(0.035);
   aptMu__63->GetXaxis()->SetTitleSize(0.035);
   aptMu__63->GetXaxis()->SetTitleFont(42);
   aptMu__63->GetYaxis()->SetLabelFont(42);
   aptMu__63->GetYaxis()->SetLabelSize(0.035);
   aptMu__63->GetYaxis()->SetTitleSize(0.035);
   aptMu__63->GetYaxis()->SetTitleFont(42);
   aptMu__63->GetZaxis()->SetLabelFont(42);
   aptMu__63->GetZaxis()->SetLabelSize(0.035);
   aptMu__63->GetZaxis()->SetTitleSize(0.035);
   aptMu__63->GetZaxis()->SetTitleFont(42);
   aptMu__63->Draw("");
   
   TPaveText *pt = new TPaveText(0.4397126,0.9342405,0.5602874,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("aptMu__63");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
