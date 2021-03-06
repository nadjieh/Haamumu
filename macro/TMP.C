{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Sep 12 14:37:26 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   THStack *amassMu = new THStack();
   amassMu->SetName("amassMu");
   amassMu->SetTitle("MC stack");
   
   TH1D *DY = new TH1D("DY","Z+jets (>50 GeV)",10000,0,10000);
   DY->SetBinContent(38,3.625696);
   DY->SetBinContent(42,3.625696);
   DY->SetBinContent(49,3.625696);
   DY->SetBinContent(53,3.625696);
   DY->SetBinContent(54,3.625696);
   DY->SetBinContent(58,7.251392);
   DY->SetBinContent(62,3.625696);
   DY->SetBinContent(67,7.251392);
   DY->SetBinContent(68,3.625696);
   DY->SetBinContent(75,3.625696);
   DY->SetBinContent(78,3.625696);
   DY->SetBinContent(79,3.625696);
   DY->SetBinContent(83,3.625696);
   DY->SetBinContent(84,3.625696);
   DY->SetBinContent(85,3.625696);
   DY->SetBinContent(86,7.251392);
   DY->SetBinContent(88,14.50278);
   DY->SetBinContent(89,29.00557);
   DY->SetBinContent(90,25.37987);
   DY->SetBinContent(91,29.00557);
   DY->SetBinContent(92,25.37987);
   DY->SetBinContent(93,21.75418);
   DY->SetBinContent(94,21.75418);
   DY->SetBinContent(95,14.50278);
   DY->SetBinContent(97,7.251392);
   DY->SetBinContent(98,3.625696);
   DY->SetBinContent(101,3.625696);
   DY->SetBinContent(107,3.625696);
   DY->SetEntries(74);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff6666");
   DY->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   DY->SetLineColor(ci);
   DY->GetXaxis()->SetTitle("m_{#mu#mu}");
   DY->GetXaxis()->SetLabelFont(42);
   DY->GetXaxis()->SetLabelSize(0.035);
   DY->GetXaxis()->SetTitleSize(0.035);
   DY->GetXaxis()->SetTitleFont(42);
   DY->GetYaxis()->SetLabelFont(42);
   DY->GetYaxis()->SetLabelSize(0.035);
   DY->GetYaxis()->SetTitleSize(0.035);
   DY->GetYaxis()->SetTitleFont(42);
   DY->GetZaxis()->SetLabelFont(42);
   DY->GetZaxis()->SetLabelSize(0.035);
   DY->GetZaxis()->SetTitleSize(0.035);
   DY->GetZaxis()->SetTitleFont(42);
   amassMu->Add(DY,"");
   
   TH1D *DYLow = new TH1D("DYLow","Z+jets (10-50 GeV)",10000,0,10000);
   DYLow->SetBinContent(22,11.02147);
   DYLow->SetBinContent(24,22.04294);
   DYLow->SetBinContent(25,11.02147);
   DYLow->SetBinContent(26,11.02147);
   DYLow->SetBinContent(32,22.04294);
   DYLow->SetBinContent(34,11.02147);
   DYLow->SetBinContent(35,11.02147);
   DYLow->SetBinContent(36,11.02147);
   DYLow->SetBinContent(37,11.02147);
   DYLow->SetBinContent(49,11.02147);
   DYLow->SetEntries(12);

   ci = TColor::GetColor("#ff9999");
   DYLow->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   DYLow->SetLineColor(ci);
   DYLow->GetXaxis()->SetTitle("m_{#mu#mu}");
   DYLow->GetXaxis()->SetLabelFont(42);
   DYLow->GetXaxis()->SetLabelSize(0.035);
   DYLow->GetXaxis()->SetTitleSize(0.035);
   DYLow->GetXaxis()->SetTitleFont(42);
   DYLow->GetYaxis()->SetLabelFont(42);
   DYLow->GetYaxis()->SetLabelSize(0.035);
   DYLow->GetYaxis()->SetTitleSize(0.035);
   DYLow->GetYaxis()->SetTitleFont(42);
   DYLow->GetZaxis()->SetLabelFont(42);
   DYLow->GetZaxis()->SetLabelSize(0.035);
   DYLow->GetZaxis()->SetTitleSize(0.035);
   DYLow->GetZaxis()->SetTitleFont(42);
   amassMu->Add(DYLow,"");
   
   TH1D *TTFull = new TH1D("TTFull","t#bar{t} dilep",10000,0,10000);
   TTFull->SetBinContent(27,0.07100384);
   TTFull->SetBinContent(34,0.07100384);
   TTFull->SetBinContent(36,0.07100384);
   TTFull->SetBinContent(78,0.07100384);
   TTFull->SetEntries(4);

   ci = TColor::GetColor("#ffff66");
   TTFull->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   TTFull->SetLineColor(ci);
   TTFull->GetXaxis()->SetTitle("m_{#mu#mu}");
   TTFull->GetXaxis()->SetLabelFont(42);
   TTFull->GetXaxis()->SetLabelSize(0.035);
   TTFull->GetXaxis()->SetTitleSize(0.035);
   TTFull->GetXaxis()->SetTitleFont(42);
   TTFull->GetYaxis()->SetLabelFont(42);
   TTFull->GetYaxis()->SetLabelSize(0.035);
   TTFull->GetYaxis()->SetTitleSize(0.035);
   TTFull->GetYaxis()->SetTitleFont(42);
   TTFull->GetZaxis()->SetLabelFont(42);
   TTFull->GetZaxis()->SetLabelSize(0.035);
   TTFull->GetZaxis()->SetTitleSize(0.035);
   TTFull->GetZaxis()->SetTitleFont(42);
   amassMu->Add(TTFull,"");
   
   TH1D *Wt = new TH1D("Wt","Wt",10000,0,10000);
   Wt->SetBinContent(25,0.7030368);
   Wt->SetBinContent(28,0.7030368);
   Wt->SetBinContent(29,0.7030368);
   Wt->SetBinContent(30,1.406074);
   Wt->SetBinContent(31,0.7030368);
   Wt->SetBinContent(34,0.7030368);
   Wt->SetBinContent(38,0.7030368);
   Wt->SetBinContent(39,1.406074);
   Wt->SetBinContent(41,0.7030368);
   Wt->SetBinContent(42,0.7030368);
   Wt->SetBinContent(44,1.406074);
   Wt->SetBinContent(45,0.7030368);
   Wt->SetBinContent(48,0.7030368);
   Wt->SetBinContent(49,0.7030368);
   Wt->SetBinContent(50,1.406074);
   Wt->SetBinContent(55,0.7030368);
   Wt->SetEntries(20);

   ci = TColor::GetColor("#336600");
   Wt->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   Wt->SetLineColor(ci);
   Wt->GetXaxis()->SetTitle("m_{#mu#mu}");
   Wt->GetXaxis()->SetLabelFont(42);
   Wt->GetXaxis()->SetLabelSize(0.035);
   Wt->GetXaxis()->SetTitleSize(0.035);
   Wt->GetXaxis()->SetTitleFont(42);
   Wt->GetYaxis()->SetLabelFont(42);
   Wt->GetYaxis()->SetLabelSize(0.035);
   Wt->GetYaxis()->SetTitleSize(0.035);
   Wt->GetYaxis()->SetTitleFont(42);
   Wt->GetZaxis()->SetLabelFont(42);
   Wt->GetZaxis()->SetLabelSize(0.035);
   Wt->GetZaxis()->SetTitleSize(0.035);
   Wt->GetZaxis()->SetTitleFont(42);
   amassMu->Add(Wt,"");
   
   TH1D *Wtbar = new TH1D("Wtbar","W#bar{t}",10000,0,10000);
   Wtbar->SetBinContent(24,0.7090176);
   Wtbar->SetBinContent(29,1.418035);
   Wtbar->SetBinContent(30,2.127053);
   Wtbar->SetBinContent(33,1.418035);
   Wtbar->SetBinContent(34,1.418035);
   Wtbar->SetBinContent(38,1.418035);
   Wtbar->SetBinContent(39,0.7090176);
   Wtbar->SetBinContent(40,0.7090176);
   Wtbar->SetBinContent(42,1.418035);
   Wtbar->SetBinContent(44,1.418035);
   Wtbar->SetBinContent(45,0.7090176);
   Wtbar->SetBinContent(50,0.7090176);
   Wtbar->SetBinContent(51,1.418035);
   Wtbar->SetEntries(22);

   ci = TColor::GetColor("#336600");
   Wtbar->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   Wtbar->SetLineColor(ci);
   Wtbar->GetXaxis()->SetTitle("m_{#mu#mu}");
   Wtbar->GetXaxis()->SetLabelFont(42);
   Wtbar->GetXaxis()->SetLabelSize(0.035);
   Wtbar->GetXaxis()->SetTitleSize(0.035);
   Wtbar->GetXaxis()->SetTitleFont(42);
   Wtbar->GetYaxis()->SetLabelFont(42);
   Wtbar->GetYaxis()->SetLabelSize(0.035);
   Wtbar->GetYaxis()->SetTitleSize(0.035);
   Wtbar->GetYaxis()->SetTitleFont(42);
   Wtbar->GetZaxis()->SetLabelFont(42);
   Wtbar->GetZaxis()->SetLabelSize(0.035);
   Wtbar->GetZaxis()->SetTitleSize(0.035);
   Wtbar->GetZaxis()->SetTitleFont(42);
   amassMu->Add(Wtbar,"");
   
   TH1D *WW = new TH1D("WW","WW",10000,0,10000);
   WW->SetBinContent(40,0.176504);
   WW->SetEntries(1);

   ci = TColor::GetColor("#996633");
   WW->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   WW->SetLineColor(ci);
   WW->GetXaxis()->SetTitle("m_{#mu#mu}");
   WW->GetXaxis()->SetLabelFont(42);
   WW->GetXaxis()->SetLabelSize(0.035);
   WW->GetXaxis()->SetTitleSize(0.035);
   WW->GetXaxis()->SetTitleFont(42);
   WW->GetYaxis()->SetLabelFont(42);
   WW->GetYaxis()->SetLabelSize(0.035);
   WW->GetYaxis()->SetTitleSize(0.035);
   WW->GetYaxis()->SetTitleFont(42);
   WW->GetZaxis()->SetLabelFont(42);
   WW->GetZaxis()->SetLabelSize(0.035);
   WW->GetZaxis()->SetTitleSize(0.035);
   WW->GetZaxis()->SetTitleFont(42);
   amassMu->Add(WW,"");
   
   TH1D *WZ = new TH1D("WZ","WZ)",10000,0,10000);
   WZ->SetBinContent(28,0.1059042);
   WZ->SetBinContent(65,0.1059042);
   WZ->SetBinContent(71,0.1059042);
   WZ->SetBinContent(79,0.1059042);
   WZ->SetBinContent(83,0.1059042);
   WZ->SetBinContent(88,0.1059042);
   WZ->SetBinContent(89,0.1059042);
   WZ->SetBinContent(90,0.3177125);
   WZ->SetBinContent(91,0.635425);
   WZ->SetBinContent(92,0.5295208);
   WZ->SetBinContent(93,0.4236166);
   WZ->SetBinContent(94,0.2118083);
   WZ->SetBinContent(95,0.2118083);
   WZ->SetBinContent(96,0.1059042);
   WZ->SetEntries(30);

   ci = TColor::GetColor("#ff6666");
   WZ->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   WZ->SetLineColor(ci);
   WZ->GetXaxis()->SetTitle("m_{#mu#mu}");
   WZ->GetXaxis()->SetLabelFont(42);
   WZ->GetXaxis()->SetLabelSize(0.035);
   WZ->GetXaxis()->SetTitleSize(0.035);
   WZ->GetXaxis()->SetTitleFont(42);
   WZ->GetYaxis()->SetLabelFont(42);
   WZ->GetYaxis()->SetLabelSize(0.035);
   WZ->GetYaxis()->SetTitleSize(0.035);
   WZ->GetYaxis()->SetTitleFont(42);
   WZ->GetZaxis()->SetLabelFont(42);
   WZ->GetZaxis()->SetLabelSize(0.035);
   WZ->GetZaxis()->SetTitleSize(0.035);
   WZ->GetZaxis()->SetTitleFont(42);
   amassMu->Add(WZ,"");
   
   TH1D *ZH = new TH1D("ZH","ZH_125",10000,0,10000);
   ZH->SetBinContent(37,0.0007852704);
   ZH->SetBinContent(38,0.0007852704);
   ZH->SetBinContent(39,0.0007852704);
   ZH->SetBinContent(43,0.0007852704);
   ZH->SetBinContent(51,0.0007852704);
   ZH->SetBinContent(53,0.0007852704);
   ZH->SetBinContent(55,0.0007852704);
   ZH->SetBinContent(56,0.0007852704);
   ZH->SetBinContent(58,0.0007852704);
   ZH->SetBinContent(65,0.001570541);
   ZH->SetBinContent(66,0.001570541);
   ZH->SetBinContent(67,0.003141082);
   ZH->SetBinContent(69,0.001570541);
   ZH->SetBinContent(70,0.003141082);
   ZH->SetBinContent(71,0.002355811);
   ZH->SetBinContent(72,0.006282163);
   ZH->SetBinContent(73,0.003141082);
   ZH->SetBinContent(74,0.006282163);
   ZH->SetBinContent(75,0.004711622);
   ZH->SetBinContent(76,0.007067434);
   ZH->SetBinContent(77,0.005496893);
   ZH->SetBinContent(78,0.005496893);
   ZH->SetBinContent(79,0.004711622);
   ZH->SetBinContent(80,0.007852704);
   ZH->SetBinContent(81,0.005496893);
   ZH->SetBinContent(82,0.01020852);
   ZH->SetBinContent(83,0.008637974);
   ZH->SetBinContent(84,0.01177906);
   ZH->SetBinContent(85,0.01884649);
   ZH->SetBinContent(86,0.02198757);
   ZH->SetBinContent(87,0.029055);
   ZH->SetBinContent(88,0.04318987);
   ZH->SetBinContent(89,0.0636069);
   ZH->SetBinContent(90,0.09344718);
   ZH->SetBinContent(91,0.1099379);
   ZH->SetBinContent(92,0.08166812);
   ZH->SetBinContent(93,0.07617123);
   ZH->SetBinContent(94,0.04318987);
   ZH->SetBinContent(95,0.03219609);
   ZH->SetBinContent(96,0.01806122);
   ZH->SetBinContent(97,0.008637974);
   ZH->SetBinContent(98,0.006282163);
   ZH->SetBinContent(99,0.003926352);
   ZH->SetBinContent(100,0.004711622);
   ZH->SetBinContent(101,0.003141082);
   ZH->SetBinContent(102,0.0007852704);
   ZH->SetBinContent(103,0.001570541);
   ZH->SetBinContent(104,0.002355811);
   ZH->SetBinContent(106,0.0007852704);
   ZH->SetBinContent(107,0.002355811);
   ZH->SetBinContent(108,0.001570541);
   ZH->SetBinContent(109,0.0007852704);
   ZH->SetBinContent(112,0.0007852704);
   ZH->SetBinContent(117,0.0007852704);
   ZH->SetEntries(990);

   ci = TColor::GetColor("#000099");
   ZH->SetLineColor(ci);
   ZH->GetXaxis()->SetTitle("m_{#mu#mu}");
   ZH->GetXaxis()->SetLabelFont(42);
   ZH->GetXaxis()->SetLabelSize(0.035);
   ZH->GetXaxis()->SetTitleSize(0.035);
   ZH->GetXaxis()->SetTitleFont(42);
   ZH->GetYaxis()->SetLabelFont(42);
   ZH->GetYaxis()->SetLabelSize(0.035);
   ZH->GetYaxis()->SetTitleSize(0.035);
   ZH->GetYaxis()->SetTitleFont(42);
   ZH->GetZaxis()->SetLabelFont(42);
   ZH->GetZaxis()->SetLabelSize(0.035);
   ZH->GetZaxis()->SetTitleSize(0.035);
   ZH->GetZaxis()->SetTitleFont(42);
   amassMu->Add(ZH,"");
   
   TH1D *ZZ = new TH1D("ZZ","ZZ",10000,0,10000);
   ZZ->SetBinContent(24,0.02656064);
   ZZ->SetBinContent(25,0.02656064);
   ZZ->SetBinContent(26,0.02656064);
   ZZ->SetBinContent(27,0.02656064);
   ZZ->SetBinContent(28,0.05312128);
   ZZ->SetBinContent(29,0.07968192);
   ZZ->SetBinContent(30,0.02656064);
   ZZ->SetBinContent(31,0.05312128);
   ZZ->SetBinContent(32,0.05312128);
   ZZ->SetBinContent(33,0.02656064);
   ZZ->SetBinContent(34,0.02656064);
   ZZ->SetBinContent(35,0.02656064);
   ZZ->SetBinContent(40,0.02656064);
   ZZ->SetBinContent(42,0.05312128);
   ZZ->SetBinContent(48,0.02656064);
   ZZ->SetBinContent(49,0.02656064);
   ZZ->SetBinContent(51,0.02656064);
   ZZ->SetBinContent(53,0.02656064);
   ZZ->SetBinContent(55,0.02656064);
   ZZ->SetBinContent(57,0.02656064);
   ZZ->SetBinContent(58,0.05312128);
   ZZ->SetBinContent(59,0.02656064);
   ZZ->SetBinContent(63,0.02656064);
   ZZ->SetBinContent(65,0.02656064);
   ZZ->SetBinContent(66,0.02656064);
   ZZ->SetBinContent(67,0.05312128);
   ZZ->SetBinContent(69,0.02656064);
   ZZ->SetBinContent(73,0.05312128);
   ZZ->SetBinContent(74,0.02656064);
   ZZ->SetBinContent(75,0.02656064);
   ZZ->SetBinContent(78,0.02656064);
   ZZ->SetBinContent(79,0.02656064);
   ZZ->SetBinContent(80,0.02656064);
   ZZ->SetBinContent(83,0.02656064);
   ZZ->SetBinContent(84,0.05312128);
   ZZ->SetBinContent(85,0.07968192);
   ZZ->SetBinContent(86,0.07968192);
   ZZ->SetBinContent(87,0.1062426);
   ZZ->SetBinContent(88,0.1593638);
   ZZ->SetBinContent(89,0.1593638);
   ZZ->SetBinContent(90,0.2390458);
   ZZ->SetBinContent(91,0.2124851);
   ZZ->SetBinContent(92,0.3187277);
   ZZ->SetBinContent(93,0.371849);
   ZZ->SetBinContent(94,0.2390458);
   ZZ->SetBinContent(95,0.2124851);
   ZZ->SetBinContent(96,0.1328032);
   ZZ->SetBinContent(97,0.02656064);
   ZZ->SetBinContent(100,0.02656064);
   ZZ->SetBinContent(103,0.02656064);
   ZZ->SetEntries(135);

   ci = TColor::GetColor("#ff66ff");
   ZZ->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   ZZ->SetLineColor(ci);
   ZZ->GetXaxis()->SetTitle("m_{#mu#mu}");
   ZZ->GetXaxis()->SetLabelFont(42);
   ZZ->GetXaxis()->SetLabelSize(0.035);
   ZZ->GetXaxis()->SetTitleSize(0.035);
   ZZ->GetXaxis()->SetTitleFont(42);
   ZZ->GetYaxis()->SetLabelFont(42);
   ZZ->GetYaxis()->SetLabelSize(0.035);
   ZZ->GetYaxis()->SetTitleSize(0.035);
   ZZ->GetYaxis()->SetTitleFont(42);
   ZZ->GetZaxis()->SetLabelFont(42);
   ZZ->GetZaxis()->SetLabelSize(0.035);
   ZZ->GetZaxis()->SetTitleSize(0.035);
   ZZ->GetZaxis()->SetTitleFont(42);
   amassMu->Add(ZZ,"");
   amassMu->Draw("");
   
   TH1D *data = new TH1D("data","step_7_Mll_DRMuMu",10000,0,10000);
   data->SetBinContent(22,2);
   data->SetBinContent(23,2);
   data->SetBinContent(24,2);
   data->SetBinContent(25,3);
   data->SetBinContent(26,5);
   data->SetBinContent(27,5);
   data->SetBinContent(28,11);
   data->SetBinContent(29,14);
   data->SetBinContent(30,17);
   data->SetBinContent(31,14);
   data->SetBinContent(32,6);
   data->SetBinContent(33,6);
   data->SetBinContent(34,9);
   data->SetBinContent(35,10);
   data->SetBinContent(36,8);
   data->SetBinContent(37,11);
   data->SetBinContent(38,11);
   data->SetBinContent(39,11);
   data->SetBinContent(40,6);
   data->SetBinContent(41,9);
   data->SetBinContent(42,8);
   data->SetBinContent(43,5);
   data->SetBinContent(44,3);
   data->SetBinContent(45,8);
   data->SetBinContent(46,6);
   data->SetBinContent(47,8);
   data->SetBinContent(48,7);
   data->SetBinContent(49,4);
   data->SetBinContent(50,5);
   data->SetBinContent(51,7);
   data->SetBinContent(52,1);
   data->SetBinContent(53,2);
   data->SetBinContent(54,2);
   data->SetBinContent(55,5);
   data->SetBinContent(57,3);
   data->SetBinContent(58,2);
   data->SetBinContent(59,2);
   data->SetBinContent(60,1);
   data->SetBinContent(61,3);
   data->SetBinContent(62,1);
   data->SetBinContent(65,4);
   data->SetBinContent(67,1);
   data->SetBinContent(68,1);
   data->SetBinContent(69,1);
   data->SetBinContent(74,2);
   data->SetBinContent(75,1);
   data->SetBinContent(76,2);
   data->SetBinContent(78,1);
   data->SetBinContent(79,1);
   data->SetBinContent(80,2);
   data->SetBinContent(81,3);
   data->SetBinContent(82,3);
   data->SetBinContent(83,2);
   data->SetBinContent(84,2);
   data->SetBinContent(85,6);
   data->SetBinContent(86,5);
   data->SetBinContent(87,7);
   data->SetBinContent(88,7);
   data->SetBinContent(89,17);
   data->SetBinContent(90,22);
   data->SetBinContent(91,23);
   data->SetBinContent(92,18);
   data->SetBinContent(93,23);
   data->SetBinContent(94,14);
   data->SetBinContent(95,5);
   data->SetBinContent(96,5);
   data->SetBinContent(97,5);
   data->SetBinContent(98,3);
   data->SetBinContent(99,2);
   data->SetBinContent(100,3);
   data->SetBinContent(105,1);
   data->SetBinContent(110,1);
   data->SetEntries(438);

   ci = TColor::GetColor("#000099");
   data->SetLineColor(ci);
   data->GetXaxis()->SetTitle("m_{#mu#mu}");
   data->GetXaxis()->SetLabelFont(42);
   data->GetXaxis()->SetLabelSize(0.035);
   data->GetXaxis()->SetTitleSize(0.035);
   data->GetXaxis()->SetTitleFont(42);
   data->GetYaxis()->SetLabelFont(42);
   data->GetYaxis()->SetLabelSize(0.035);
   data->GetYaxis()->SetTitleSize(0.035);
   data->GetYaxis()->SetTitleFont(42);
   data->GetZaxis()->SetLabelFont(42);
   data->GetZaxis()->SetLabelSize(0.035);
   data->GetZaxis()->SetTitleSize(0.035);
   data->GetZaxis()->SetTitleFont(42);
   data->Draw("EHISTSAMES");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
