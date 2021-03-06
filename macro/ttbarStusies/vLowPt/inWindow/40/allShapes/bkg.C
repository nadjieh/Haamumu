{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Nov 27 14:20:18 2014) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",338,95,461,327);
   Canvas_1->Range(8.749999,-27.5625,81.25,248.0625);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","eventSelectionamassMu",100,16,74);
   htemp__1->SetBinContent(7,11);
   htemp__1->SetBinContent(8,111);
   htemp__1->SetBinContent(9,127);
   htemp__1->SetBinContent(10,108);
   htemp__1->SetBinContent(11,133);
   htemp__1->SetBinContent(12,143);
   htemp__1->SetBinContent(13,142);
   htemp__1->SetBinContent(14,143);
   htemp__1->SetBinContent(15,128);
   htemp__1->SetBinContent(16,137);
   htemp__1->SetBinContent(17,136);
   htemp__1->SetBinContent(18,157);
   htemp__1->SetBinContent(19,142);
   htemp__1->SetBinContent(20,128);
   htemp__1->SetBinContent(21,148);
   htemp__1->SetBinContent(22,139);
   htemp__1->SetBinContent(23,152);
   htemp__1->SetBinContent(24,151);
   htemp__1->SetBinContent(25,185);
   htemp__1->SetBinContent(26,163);
   htemp__1->SetBinContent(27,198);
   htemp__1->SetBinContent(28,172);
   htemp__1->SetBinContent(29,166);
   htemp__1->SetBinContent(30,151);
   htemp__1->SetBinContent(31,210);
   htemp__1->SetBinContent(32,170);
   htemp__1->SetBinContent(33,179);
   htemp__1->SetBinContent(34,209);
   htemp__1->SetBinContent(35,173);
   htemp__1->SetBinContent(36,192);
   htemp__1->SetBinContent(37,178);
   htemp__1->SetBinContent(38,192);
   htemp__1->SetBinContent(39,196);
   htemp__1->SetBinContent(40,182);
   htemp__1->SetBinContent(41,169);
   htemp__1->SetBinContent(42,179);
   htemp__1->SetBinContent(43,174);
   htemp__1->SetBinContent(44,173);
   htemp__1->SetBinContent(45,196);
   htemp__1->SetBinContent(46,167);
   htemp__1->SetBinContent(47,168);
   htemp__1->SetBinContent(48,193);
   htemp__1->SetBinContent(49,188);
   htemp__1->SetBinContent(50,185);
   htemp__1->SetBinContent(51,198);
   htemp__1->SetBinContent(52,151);
   htemp__1->SetBinContent(53,187);
   htemp__1->SetBinContent(54,170);
   htemp__1->SetBinContent(55,170);
   htemp__1->SetBinContent(56,190);
   htemp__1->SetBinContent(57,171);
   htemp__1->SetBinContent(58,167);
   htemp__1->SetBinContent(59,174);
   htemp__1->SetBinContent(60,186);
   htemp__1->SetBinContent(61,146);
   htemp__1->SetBinContent(62,150);
   htemp__1->SetBinContent(63,167);
   htemp__1->SetBinContent(64,160);
   htemp__1->SetBinContent(65,146);
   htemp__1->SetBinContent(66,143);
   htemp__1->SetBinContent(67,138);
   htemp__1->SetBinContent(68,155);
   htemp__1->SetBinContent(69,147);
   htemp__1->SetBinContent(70,125);
   htemp__1->SetBinContent(71,144);
   htemp__1->SetBinContent(72,141);
   htemp__1->SetBinContent(73,103);
   htemp__1->SetBinContent(74,119);
   htemp__1->SetBinContent(75,127);
   htemp__1->SetBinContent(76,115);
   htemp__1->SetBinContent(77,117);
   htemp__1->SetBinContent(78,113);
   htemp__1->SetBinContent(79,97);
   htemp__1->SetBinContent(80,108);
   htemp__1->SetBinContent(81,76);
   htemp__1->SetBinContent(82,86);
   htemp__1->SetBinContent(83,89);
   htemp__1->SetBinContent(84,93);
   htemp__1->SetBinContent(85,91);
   htemp__1->SetBinContent(86,68);
   htemp__1->SetBinContent(87,90);
   htemp__1->SetBinContent(88,88);
   htemp__1->SetBinContent(89,62);
   htemp__1->SetBinContent(90,71);
   htemp__1->SetBinContent(91,68);
   htemp__1->SetBinContent(92,73);
   htemp__1->SetBinContent(93,70);
   htemp__1->SetEntries(12494);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 12494  ");
   text = ptstats->AddText("Mean  =  42.97");
   text = ptstats->AddText("RMS   =   12.9");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("eventSelectionamassMu");
   htemp__1->GetXaxis()->SetRange(1,100);
   htemp__1->GetXaxis()->SetLabelFont(42);
   htemp__1->GetXaxis()->SetLabelSize(0.035);
   htemp__1->GetXaxis()->SetTitleSize(0.035);
   htemp__1->GetXaxis()->SetTitleFont(42);
   htemp__1->GetYaxis()->SetLabelFont(42);
   htemp__1->GetYaxis()->SetLabelSize(0.035);
   htemp__1->GetYaxis()->SetTitleSize(0.035);
   htemp__1->GetYaxis()->SetTitleFont(42);
   htemp__1->GetZaxis()->SetLabelFont(42);
   htemp__1->GetZaxis()->SetLabelSize(0.035);
   htemp__1->GetZaxis()->SetTitleSize(0.035);
   htemp__1->GetZaxis()->SetTitleFont(42);
   htemp__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.2744639,0.94,0.7255361,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("eventSelectionamassMu");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
