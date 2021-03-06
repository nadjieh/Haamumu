{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Jan 20 15:57:42 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",484,108,700,502);
   Canvas_1->Range(-3.750001,-12.8625,83.75,115.7625);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","eventSelectionamassMu",100,5,75);
   htemp__2->SetBinContent(8,98);
   htemp__2->SetBinContent(9,28);
   htemp__2->SetBinContent(10,32);
   htemp__2->SetBinContent(11,29);
   htemp__2->SetBinContent(12,25);
   htemp__2->SetBinContent(13,27);
   htemp__2->SetBinContent(14,41);
   htemp__2->SetBinContent(15,22);
   htemp__2->SetBinContent(16,35);
   htemp__2->SetBinContent(17,32);
   htemp__2->SetBinContent(18,21);
   htemp__2->SetBinContent(19,21);
   htemp__2->SetBinContent(20,11);
   htemp__2->SetBinContent(21,22);
   htemp__2->SetBinContent(22,21);//
   htemp__2->SetBinContent(23,20);
   htemp__2->SetBinContent(24,11);
   htemp__2->SetBinContent(25,14);
   htemp__2->SetBinContent(26,14);
   htemp__2->SetBinContent(27,13);
   htemp__2->SetBinContent(28,21);
   htemp__2->SetBinContent(29,25);
   htemp__2->SetBinContent(30,17);
   htemp__2->SetBinContent(31,17);
   htemp__2->SetBinContent(32,22);
   htemp__2->SetBinContent(33,15);
   htemp__2->SetBinContent(34,17);
   htemp__2->SetBinContent(35,13);
   htemp__2->SetBinContent(36,20);
   htemp__2->SetBinContent(37,9);
   htemp__2->SetBinContent(38,13);
   htemp__2->SetBinContent(39,12);
   htemp__2->SetBinContent(40,15);
   htemp__2->SetBinContent(41,17);
   htemp__2->SetBinContent(42,22);
   htemp__2->SetBinContent(43,19);
   htemp__2->SetBinContent(44,18);
   htemp__2->SetBinContent(45,22);
   htemp__2->SetBinContent(46,23);
   htemp__2->SetBinContent(47,27);
   htemp__2->SetBinContent(48,14);
   htemp__2->SetBinContent(49,15);
   htemp__2->SetBinContent(50,27);//
   htemp__2->SetBinContent(51,22);
   htemp__2->SetBinContent(52,13);
   htemp__2->SetBinContent(53,22);
   htemp__2->SetBinContent(54,26);
   htemp__2->SetBinContent(55,16);
   htemp__2->SetBinContent(56,16);
   htemp__2->SetBinContent(57,24);
   htemp__2->SetBinContent(58,18);
   htemp__2->SetBinContent(59,25);
   htemp__2->SetBinContent(60,22);
   htemp__2->SetBinContent(61,16);
   htemp__2->SetBinContent(62,19);
   htemp__2->SetBinContent(63,16);
   htemp__2->SetBinContent(64,27);
   htemp__2->SetBinContent(65,18);
   htemp__2->SetBinContent(66,18);
   htemp__2->SetBinContent(67,13);
   htemp__2->SetBinContent(68,21);
   htemp__2->SetBinContent(69,23);
   htemp__2->SetBinContent(70,18);
   htemp__2->SetBinContent(71,20);
   htemp__2->SetBinContent(72,20);
   htemp__2->SetBinContent(73,16);
   htemp__2->SetBinContent(74,27);
   htemp__2->SetBinContent(75,15);
   htemp__2->SetBinContent(76,19);
   htemp__2->SetBinContent(77,18);
   htemp__2->SetBinContent(78,17);
   htemp__2->SetBinContent(79,18);
   htemp__2->SetBinContent(80,16);
   htemp__2->SetBinContent(81,14);
   htemp__2->SetBinContent(82,11);
   htemp__2->SetBinContent(83,15);
   htemp__2->SetBinContent(84,10);
   htemp__2->SetBinContent(85,17);
   htemp__2->SetBinContent(86,13);
   htemp__2->SetBinContent(87,13);
   htemp__2->SetBinContent(88,18);
   htemp__2->SetBinContent(89,10);
   htemp__2->SetBinContent(90,12);
   htemp__2->SetBinContent(91,17);
   htemp__2->SetBinContent(92,10);
   htemp__2->SetBinContent(93,11);
   htemp__2->SetEntries(1707);
   htemp__2->SetDirectory(0);
   cout<<htemp__2->Integral(22,50)<<endl;
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1707   ");
   text = ptstats->AddText("Mean  =  36.29");
   text = ptstats->AddText("RMS   =   17.9");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__2->SetLineColor(ci);
   htemp__2->GetXaxis()->SetTitle("eventSelectionamassMu");
   htemp__2->GetXaxis()->SetRange(1,100);
   htemp__2->GetXaxis()->SetLabelFont(42);
   htemp__2->GetXaxis()->SetLabelSize(0.035);
   htemp__2->GetXaxis()->SetTitleSize(0.035);
   htemp__2->GetXaxis()->SetTitleFont(42);
   htemp__2->GetYaxis()->SetLabelFont(42);
   htemp__2->GetYaxis()->SetLabelSize(0.035);
   htemp__2->GetYaxis()->SetTitleSize(0.035);
   htemp__2->GetYaxis()->SetTitleFont(42);
   htemp__2->GetZaxis()->SetLabelFont(42);
   htemp__2->GetZaxis()->SetLabelSize(0.035);
   htemp__2->GetZaxis()->SetTitleSize(0.035);
   htemp__2->GetZaxis()->SetTitleFont(42);
   htemp__2->Draw("");
   
   TPaveText *pt = new TPaveText(0.2902874,0.94,0.7097126,0.995,"blNDC");
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
