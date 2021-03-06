{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Mar 29 12:08:01 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TH1D *frame_f96e110__1 = new TH1D("frame_f96e110__1","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_f96e110__1->SetBinContent(1,2466.034);
   frame_f96e110__1->SetMaximum(2466.034);
   frame_f96e110__1->SetEntries(2);
   frame_f96e110__1->SetDirectory(0);
   frame_f96e110__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_f96e110__1->SetLineColor(ci);
   frame_f96e110__1->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_f96e110__1->GetXaxis()->SetLabelFont(42);
   frame_f96e110__1->GetXaxis()->SetLabelSize(0.035);
   frame_f96e110__1->GetXaxis()->SetTitleSize(0.035);
   frame_f96e110__1->GetXaxis()->SetTitleFont(42);
   frame_f96e110__1->GetYaxis()->SetTitle("Events / ( 0.5 )");
   frame_f96e110__1->GetYaxis()->SetLabelFont(42);
   frame_f96e110__1->GetYaxis()->SetLabelSize(0.035);
   frame_f96e110__1->GetYaxis()->SetTitleSize(0.035);
   frame_f96e110__1->GetYaxis()->SetTitleFont(42);
   frame_f96e110__1->GetZaxis()->SetLabelFont(42);
   frame_f96e110__1->GetZaxis()->SetLabelSize(0.035);
   frame_f96e110__1->GetZaxis()->SetTitleSize(0.035);
   frame_f96e110__1->GetZaxis()->SetTitleFont(42);
   frame_f96e110__1->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100);
   grae->SetName("h_sigData_dimu");
   grae->SetTitle("Histogram of sigData_dimu_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,20.25,0);
   grae->SetPointError(0,0.25,0.25,0,1.147874);
   grae->SetPoint(1,20.75,0);
   grae->SetPointError(1,0.25,0.25,0,1.147874);
   grae->SetPoint(2,21.25,0);
   grae->SetPointError(2,0.25,0.25,0,1.147874);
   grae->SetPoint(3,21.75,0);
   grae->SetPointError(3,0.25,0.25,0,1.147874);
   grae->SetPoint(4,22.25,1);
   grae->SetPointError(4,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(5,22.75,0);
   grae->SetPointError(5,0.25,0.25,0,1.147874);
   grae->SetPoint(6,23.25,0);
   grae->SetPointError(6,0.25,0.25,0,1.147874);
   grae->SetPoint(7,23.75,0);
   grae->SetPointError(7,0.25,0.25,0,1.147874);
   grae->SetPoint(8,24.25,0);
   grae->SetPointError(8,0.25,0.25,0,1.147874);
   grae->SetPoint(9,24.75,1);
   grae->SetPointError(9,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(10,25.25,2);
   grae->SetPointError(10,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(11,25.75,2);
   grae->SetPointError(11,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(12,26.25,0);
   grae->SetPointError(12,0.25,0.25,0,1.147874);
   grae->SetPoint(13,26.75,0);
   grae->SetPointError(13,0.25,0.25,0,1.147874);
   grae->SetPoint(14,27.25,0);
   grae->SetPointError(14,0.25,0.25,0,1.147874);
   grae->SetPoint(15,27.75,3);
   grae->SetPointError(15,0.25,0.25,1.632705,2.918186);
   grae->SetPoint(16,28.25,2);
   grae->SetPointError(16,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(17,28.75,0);
   grae->SetPointError(17,0.25,0.25,0,1.147874);
   grae->SetPoint(18,29.25,2);
   grae->SetPointError(18,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(19,29.75,1);
   grae->SetPointError(19,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(20,30.25,4);
   grae->SetPointError(20,0.25,0.25,1.914339,3.162753);
   grae->SetPoint(21,30.75,2);
   grae->SetPointError(21,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(22,31.25,3);
   grae->SetPointError(22,0.25,0.25,1.632705,2.918186);
   grae->SetPoint(23,31.75,2);
   grae->SetPointError(23,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(24,32.25,6);
   grae->SetPointError(24,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(25,32.75,2);
   grae->SetPointError(25,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(26,33.25,6);
   grae->SetPointError(26,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(27,33.75,3);
   grae->SetPointError(27,0.25,0.25,1.632705,2.918186);
   grae->SetPoint(28,34.25,8);
   grae->SetPointError(28,0.25,0.25,2.768386,3.945142);
   grae->SetPoint(29,34.75,11);
   grae->SetPointError(29,0.25,0.25,3.265579,4.416521);
   grae->SetPoint(30,35.25,16);
   grae->SetPointError(30,0.25,0.25,3.957801,5.083066);
   grae->SetPoint(31,35.75,16);
   grae->SetPointError(31,0.25,0.25,3.957801,5.083066);
   grae->SetPoint(32,36.25,14);
   grae->SetPointError(32,0.25,0.25,3.6965,4.830381);
   grae->SetPoint(33,36.75,29);
   grae->SetPointError(33,0.25,0.25,5.353932,6.44702);
   grae->SetPoint(34,37.25,33);
   grae->SetPointError(34,0.25,0.25,5.715302,6.802567);
   grae->SetPoint(35,37.75,53);
   grae->SetPointError(35,0.25,0.25,7.257065,8.325916);
   grae->SetPoint(36,38.25,96);
   grae->SetPointError(36,0.25,0.25,9.780867,10.83201);
   grae->SetPoint(37,38.75,228);
   grae->SetPointError(37,0.25,0.25,14.60794,15.60794);
   grae->SetPoint(38,39.25,774);
   grae->SetPointError(38,0.25,0.25,27.32535,28.32535);
   grae->SetPoint(39,39.75,2103);
   grae->SetPointError(39,0.25,0.25,45.3612,46.3612);
   grae->SetPoint(40,40.25,1848);
   grae->SetPointError(40,0.25,0.25,42.49128,43.49128);
   grae->SetPoint(41,40.75,531);
   grae->SetPointError(41,0.25,0.25,22.54886,23.54886);
   grae->SetPoint(42,41.25,96);
   grae->SetPointError(42,0.25,0.25,9.780867,10.83201);
   grae->SetPoint(43,41.75,25);
   grae->SetPointError(43,0.25,0.25,4.966335,6.066589);
   grae->SetPoint(44,42.25,6);
   grae->SetPointError(44,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(45,42.75,0);
   grae->SetPointError(45,0.25,0.25,0,1.147874);
   grae->SetPoint(46,43.25,0);
   grae->SetPointError(46,0.25,0.25,0,1.147874);
   grae->SetPoint(47,43.75,0);
   grae->SetPointError(47,0.25,0.25,0,1.147874);
   grae->SetPoint(48,44.25,0);
   grae->SetPointError(48,0.25,0.25,0,1.147874);
   grae->SetPoint(49,44.75,0);
   grae->SetPointError(49,0.25,0.25,0,1.147874);
   grae->SetPoint(50,45.25,0);
   grae->SetPointError(50,0.25,0.25,0,1.147874);
   grae->SetPoint(51,45.75,0);
   grae->SetPointError(51,0.25,0.25,0,1.147874);
   grae->SetPoint(52,46.25,0);
   grae->SetPointError(52,0.25,0.25,0,1.147874);
   grae->SetPoint(53,46.75,0);
   grae->SetPointError(53,0.25,0.25,0,1.147874);
   grae->SetPoint(54,47.25,0);
   grae->SetPointError(54,0.25,0.25,0,1.147874);
   grae->SetPoint(55,47.75,0);
   grae->SetPointError(55,0.25,0.25,0,1.147874);
   grae->SetPoint(56,48.25,0);
   grae->SetPointError(56,0.25,0.25,0,1.147874);
   grae->SetPoint(57,48.75,0);
   grae->SetPointError(57,0.25,0.25,0,1.147874);
   grae->SetPoint(58,49.25,0);
   grae->SetPointError(58,0.25,0.25,0,1.147874);
   grae->SetPoint(59,49.75,0);
   grae->SetPointError(59,0.25,0.25,0,1.147874);
   grae->SetPoint(60,50.25,0);
   grae->SetPointError(60,0.25,0.25,0,1.147874);
   grae->SetPoint(61,50.75,0);
   grae->SetPointError(61,0.25,0.25,0,1.147874);
   grae->SetPoint(62,51.25,0);
   grae->SetPointError(62,0.25,0.25,0,1.147874);
   grae->SetPoint(63,51.75,1);
   grae->SetPointError(63,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(64,52.25,0);
   grae->SetPointError(64,0.25,0.25,0,1.147874);
   grae->SetPoint(65,52.75,0);
   grae->SetPointError(65,0.25,0.25,0,1.147874);
   grae->SetPoint(66,53.25,0);
   grae->SetPointError(66,0.25,0.25,0,1.147874);
   grae->SetPoint(67,53.75,0);
   grae->SetPointError(67,0.25,0.25,0,1.147874);
   grae->SetPoint(68,54.25,0);
   grae->SetPointError(68,0.25,0.25,0,1.147874);
   grae->SetPoint(69,54.75,0);
   grae->SetPointError(69,0.25,0.25,0,1.147874);
   grae->SetPoint(70,55.25,0);
   grae->SetPointError(70,0.25,0.25,0,1.147874);
   grae->SetPoint(71,55.75,0);
   grae->SetPointError(71,0.25,0.25,0,1.147874);
   grae->SetPoint(72,56.25,0);
   grae->SetPointError(72,0.25,0.25,0,1.147874);
   grae->SetPoint(73,56.75,0);
   grae->SetPointError(73,0.25,0.25,0,1.147874);
   grae->SetPoint(74,57.25,0);
   grae->SetPointError(74,0.25,0.25,0,1.147874);
   grae->SetPoint(75,57.75,0);
   grae->SetPointError(75,0.25,0.25,0,1.147874);
   grae->SetPoint(76,58.25,0);
   grae->SetPointError(76,0.25,0.25,0,1.147874);
   grae->SetPoint(77,58.75,0);
   grae->SetPointError(77,0.25,0.25,0,1.147874);
   grae->SetPoint(78,59.25,0);
   grae->SetPointError(78,0.25,0.25,0,1.147874);
   grae->SetPoint(79,59.75,0);
   grae->SetPointError(79,0.25,0.25,0,1.147874);
   grae->SetPoint(80,60.25,0);
   grae->SetPointError(80,0.25,0.25,0,1.147874);
   grae->SetPoint(81,60.75,1);
   grae->SetPointError(81,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(82,61.25,0);
   grae->SetPointError(82,0.25,0.25,0,1.147874);
   grae->SetPoint(83,61.75,0);
   grae->SetPointError(83,0.25,0.25,0,1.147874);
   grae->SetPoint(84,62.25,0);
   grae->SetPointError(84,0.25,0.25,0,1.147874);
   grae->SetPoint(85,62.75,0);
   grae->SetPointError(85,0.25,0.25,0,1.147874);
   grae->SetPoint(86,63.25,0);
   grae->SetPointError(86,0.25,0.25,0,1.147874);
   grae->SetPoint(87,63.75,0);
   grae->SetPointError(87,0.25,0.25,0,1.147874);
   grae->SetPoint(88,64.25,0);
   grae->SetPointError(88,0.25,0.25,0,1.147874);
   grae->SetPoint(89,64.75,0);
   grae->SetPointError(89,0.25,0.25,0,1.147874);
   grae->SetPoint(90,65.25,0);
   grae->SetPointError(90,0.25,0.25,0,1.147874);
   grae->SetPoint(91,65.75,0);
   grae->SetPointError(91,0.25,0.25,0,1.147874);
   grae->SetPoint(92,66.25,0);
   grae->SetPointError(92,0.25,0.25,0,1.147874);
   grae->SetPoint(93,66.75,0);
   grae->SetPointError(93,0.25,0.25,0,1.147874);
   grae->SetPoint(94,67.25,0);
   grae->SetPointError(94,0.25,0.25,0,1.147874);
   grae->SetPoint(95,67.75,0);
   grae->SetPointError(95,0.25,0.25,0,1.147874);
   grae->SetPoint(96,68.25,0);
   grae->SetPointError(96,0.25,0.25,0,1.147874);
   grae->SetPoint(97,68.75,0);
   grae->SetPointError(97,0.25,0.25,0,1.147874);
   grae->SetPoint(98,69.25,0);
   grae->SetPointError(98,0.25,0.25,0,1.147874);
   grae->SetPoint(99,69.75,0);
   grae->SetPointError(99,0.25,0.25,0,1.147874);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(141);
   graph->SetName("tmp_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of FFT Conv CryBall and BW");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,19.5,0);
   graph->SetPoint(1,19.5,0.7540935107);
   graph->SetPoint(2,20,0.7540935107);
   graph->SetPoint(3,20.5,0.7741434061);
   graph->SetPoint(4,21,0.8204794728);
   graph->SetPoint(5,21.5,0.8656109672);
   graph->SetPoint(6,22,0.9145714917);
   graph->SetPoint(7,22.5,0.9678068045);
   graph->SetPoint(8,23,1.025829477);
   graph->SetPoint(9,23.5,1.089231282);
   graph->SetPoint(10,24,1.158698351);
   graph->SetPoint(11,24.5,1.235029823);
   graph->SetPoint(12,25,1.319160939);
   graph->SetPoint(13,25.5,1.41219185);
   graph->SetPoint(14,26,1.515423782);
   graph->SetPoint(15,26.5,1.630404816);
   graph->SetPoint(16,27,1.758988313);
   graph->SetPoint(17,27.5,1.903408128);
   graph->SetPoint(18,28,2.066376379);
   graph->SetPoint(19,28.5,2.251211842);
   graph->SetPoint(20,29,2.462010451);
   graph->SetPoint(21,29.5,2.70387447);
   graph->SetPoint(22,30,2.983224601);
   graph->SetPoint(23,30.5,3.308231228);
   graph->SetPoint(24,31,3.689419767);
   graph->SetPoint(25,31.5,4.140535427);
   graph->SetPoint(26,32,4.679802767);
   graph->SetPoint(27,32.5,5.331800519);
   graph->SetPoint(28,33,6.130321132);
   graph->SetPoint(29,33.5,7.122854436);
   graph->SetPoint(30,34,8.377843461);
   graph->SetPoint(31,34.5,9.996862192);
   graph->SetPoint(32,35,12.13594252);
   graph->SetPoint(33,35.5,15.04485294);
   graph->SetPoint(34,36,19.14395398);
   graph->SetPoint(35,36.5,25.18615792);
   graph->SetPoint(36,37,34.63150096);
   graph->SetPoint(37,37.5,50.62383787);
   graph->SetPoint(38,37.75,62.35351366);
   graph->SetPoint(39,38,80.97932909);
   graph->SetPoint(40,38.25,104.9679441);
   graph->SetPoint(41,38.5,149.5920447);
   graph->SetPoint(42,38.75,209.7607354);
   graph->SetPoint(43,38.875,274.8787208);
   graph->SetPoint(44,39,355.5646213);
   graph->SetPoint(45,39.125,451.8184368);
   graph->SetPoint(46,39.25,563.6401674);
   graph->SetPoint(47,39.3125,704.9694006);
   graph->SetPoint(48,39.375,867.8751459);
   graph->SetPoint(49,39.4375,1052.357403);
   graph->SetPoint(50,39.5,1258.416173);
   graph->SetPoint(51,39.5625,1486.051454);
   graph->SetPoint(52,39.625,1735.263247);
   graph->SetPoint(53,39.6875,2006.051553);
   graph->SetPoint(54,39.75,2298.41637);
   graph->SetPoint(55,39.8125,2342.685389);
   graph->SetPoint(56,39.875,2348.60374);
   graph->SetPoint(57,39.9375,2316.171423);
   graph->SetPoint(58,40,2245.388437);
   graph->SetPoint(59,40.0625,2136.254784);
   graph->SetPoint(60,40.125,1988.770462);
   graph->SetPoint(61,40.1875,1802.935472);
   graph->SetPoint(62,40.25,1578.749814);
   graph->SetPoint(63,40.3125,1455.900512);
   graph->SetPoint(64,40.375,1325.742102);
   graph->SetPoint(65,40.4375,1188.274586);
   graph->SetPoint(66,40.5,1043.497962);
   graph->SetPoint(67,40.5625,891.412231);
   graph->SetPoint(68,40.625,732.0173927);
   graph->SetPoint(69,40.6875,565.3134472);
   graph->SetPoint(70,40.75,391.3003944);
   graph->SetPoint(71,40.8125,310.2055447);
   graph->SetPoint(72,40.875,244.0743233);
   graph->SetPoint(73,40.9375,192.9067302);
   graph->SetPoint(74,41,156.7027656);
   graph->SetPoint(75,41.0625,135.4624293);
   graph->SetPoint(76,41.125,129.1857214);
   graph->SetPoint(77,41.1875,137.8726419);
   graph->SetPoint(78,41.25,161.5231907);
   graph->SetPoint(79,41.375,128.2912893);
   graph->SetPoint(80,41.5,104.7443477);
   graph->SetPoint(81,42,65.02184287);
   graph->SetPoint(82,42.5,43.24985665);
   graph->SetPoint(83,43,30.64096163);
   graph->SetPoint(84,43.5,22.787093);
   graph->SetPoint(85,44,17.58959878);
   graph->SetPoint(86,44.5,13.9799748);
   graph->SetPoint(87,45,11.37422463);
   graph->SetPoint(88,45.5,9.43296622);
   graph->SetPoint(89,46,7.948564759);
   graph->SetPoint(90,46.5,6.788393897);
   graph->SetPoint(91,47,5.864596618);
   graph->SetPoint(92,47.5,5.117135414);
   graph->SetPoint(93,48,4.503869179);
   graph->SetPoint(94,48.5,3.994520806);
   graph->SetPoint(95,49,3.566887513);
   graph->SetPoint(96,49.5,3.204390385);
   graph->SetPoint(97,50,2.89444889);
   graph->SetPoint(98,50.5,2.627377847);
   graph->SetPoint(99,51,2.39562353);
   graph->SetPoint(100,51.5,2.193224839);
   graph->SetPoint(101,52,2.015426869);
   graph->SetPoint(102,52.5,1.858399564);
   graph->SetPoint(103,53,1.719030027);
   graph->SetPoint(104,53.5,1.594767255);
   graph->SetPoint(105,54,1.483504718);
   graph->SetPoint(106,54.5,1.383490584);
   graph->SetPoint(107,55,1.293258406);
   graph->SetPoint(108,55.5,1.211573111);
   graph->SetPoint(109,56,1.13738854);
   graph->SetPoint(110,56.5,1.069813814);
   graph->SetPoint(111,57,1.008086479);
   graph->SetPoint(112,57.5,0.9515509152);
   graph->SetPoint(113,58,0.8996408691);
   graph->SetPoint(114,58.5,0.8518652252);
   graph->SetPoint(115,59,0.8077963536);
   graph->SetPoint(116,59.5,0.7670605112);
   graph->SetPoint(117,60,0.7293298952);
   graph->SetPoint(118,60.5,0.6943160304);
   graph->SetPoint(119,61,0.6617642407);
   graph->SetPoint(120,61.5,0.631449007);
   graph->SetPoint(121,62,0.6031700515);
   graph->SetPoint(122,62.5,0.5767490231);
   graph->SetPoint(123,63,0.5520266793);
   graph->SetPoint(124,63.5,0.5288604826);
   graph->SetPoint(125,64,0.5071225429);
   graph->SetPoint(126,64.5,0.4866978516);
   graph->SetPoint(127,65,0.4674827635);
   graph->SetPoint(128,65.5,0.4493836978);
   graph->SetPoint(129,66,0.4323160786);
   graph->SetPoint(130,66.5,0.4162039304);
   graph->SetPoint(131,67,0.4009777591);
   graph->SetPoint(132,67.5,0.3865716918);
   graph->SetPoint(133,68,0.3729282235);
   graph->SetPoint(134,68.5,0.3599956791);
   graph->SetPoint(135,69,0.3477263308);
   graph->SetPoint(136,69.5,0.336077195);
   graph->SetPoint(137,70,0.3290560545);
   graph->SetPoint(138,70,0.3290560545);
   graph->SetPoint(139,70.5,0.3290560545);
   graph->SetPoint(140,70.5,0);
   graph->Draw("l");
   
   TH1D *frame_f96e110__2 = new TH1D("frame_f96e110__2","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_f96e110__2->SetBinContent(1,2466.034);
   frame_f96e110__2->SetMaximum(2466.034);
   frame_f96e110__2->SetEntries(2);
   frame_f96e110__2->SetDirectory(0);
   frame_f96e110__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_f96e110__2->SetLineColor(ci);
   frame_f96e110__2->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_f96e110__2->GetXaxis()->SetLabelFont(42);
   frame_f96e110__2->GetXaxis()->SetLabelSize(0.035);
   frame_f96e110__2->GetXaxis()->SetTitleSize(0.035);
   frame_f96e110__2->GetXaxis()->SetTitleFont(42);
   frame_f96e110__2->GetYaxis()->SetTitle("Events / ( 0.5 )");
   frame_f96e110__2->GetYaxis()->SetLabelFont(42);
   frame_f96e110__2->GetYaxis()->SetLabelSize(0.035);
   frame_f96e110__2->GetYaxis()->SetTitleSize(0.035);
   frame_f96e110__2->GetYaxis()->SetTitleFont(42);
   frame_f96e110__2->GetZaxis()->SetLabelFont(42);
   frame_f96e110__2->GetZaxis()->SetLabelSize(0.035);
   frame_f96e110__2->GetZaxis()->SetTitleSize(0.035);
   frame_f96e110__2->GetZaxis()->SetTitleFont(42);
   frame_f96e110__2->Draw("AXISSAME");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
