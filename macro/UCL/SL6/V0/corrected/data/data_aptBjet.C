{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Nov 26 11:18:00 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",839,114,700,500);
   Canvas_1->Range(-125,-4305.788,1125,38752.09);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *aptBjet__95 = new TH1D("aptBjet__95","",50,0,1000);
   aptBjet__95->SetBinContent(1,18246);
   aptBjet__95->SetBinContent(2,32806);
   aptBjet__95->SetBinContent(3,22820);
   aptBjet__95->SetBinContent(4,9491);
   aptBjet__95->SetBinContent(5,4484);
   aptBjet__95->SetBinContent(6,2240);
   aptBjet__95->SetBinContent(7,1181);
   aptBjet__95->SetBinContent(8,621);
   aptBjet__95->SetBinContent(9,369);
   aptBjet__95->SetBinContent(10,223);
   aptBjet__95->SetBinContent(11,136);
   aptBjet__95->SetBinContent(12,88);
   aptBjet__95->SetBinContent(13,54);
   aptBjet__95->SetBinContent(14,39);
   aptBjet__95->SetBinContent(15,33);
   aptBjet__95->SetBinContent(16,20);
   aptBjet__95->SetBinContent(17,15);
   aptBjet__95->SetBinContent(18,12);
   aptBjet__95->SetBinContent(19,3);
   aptBjet__95->SetBinContent(20,8);
   aptBjet__95->SetBinContent(21,3);
   aptBjet__95->SetBinContent(22,6);
   aptBjet__95->SetBinContent(23,3);
   aptBjet__95->SetBinContent(25,1);
   aptBjet__95->SetBinContent(26,2);
   aptBjet__95->SetBinContent(31,1);
   aptBjet__95->SetBinContent(33,1);
   aptBjet__95->SetEntries(92906);
      aptBjet__95->SetStats(0);
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("aptBjet__95");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 92906  ");
   text = ptstats->AddText("Mean  =  44.01");
   text = ptstats->AddText("RMS   =  32.66");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   aptBjet__95->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(aptBjet__95);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   aptBjet__95->SetLineColor(ci);
   aptBjet__95->GetXaxis()->SetLabelFont(42);
   aptBjet__95->GetXaxis()->SetLabelSize(0.035);
   aptBjet__95->GetXaxis()->SetTitleSize(0.035);
   aptBjet__95->GetXaxis()->SetTitleFont(42);
   aptBjet__95->GetYaxis()->SetLabelFont(42);
   aptBjet__95->GetYaxis()->SetLabelSize(0.035);
   aptBjet__95->GetYaxis()->SetTitleSize(0.035);
   aptBjet__95->GetYaxis()->SetTitleFont(42);
   aptBjet__95->GetZaxis()->SetLabelFont(42);
   aptBjet__95->GetZaxis()->SetLabelSize(0.035);
   aptBjet__95->GetZaxis()->SetTitleSize(0.035);
   aptBjet__95->GetZaxis()->SetTitleFont(42);
   aptBjet__95->Draw("");
   
   TPaveText *pt = new TPaveText(0.4318103,0.9342405,0.5681897,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("aptBjet__95");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
