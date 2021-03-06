{
//=========Macro generated from canvas: c1_n2/
//=========  (Sun Jan  4 18:39:08 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "",13,34,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TH1D *frame_2dd1230__3 = new TH1D("frame_2dd1230__3","SM",100,10,120);
   frame_2dd1230__3->SetBinContent(1,40.65154);
   frame_2dd1230__3->SetMaximum(40.65154);
   frame_2dd1230__3->SetEntries(1);
   frame_2dd1230__3->SetDirectory(0);
   frame_2dd1230__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_2dd1230__3->SetLineColor(ci);
   frame_2dd1230__3->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_2dd1230__3->GetXaxis()->SetLabelFont(42);
   frame_2dd1230__3->GetXaxis()->SetLabelSize(0.035);
   frame_2dd1230__3->GetXaxis()->SetTitleSize(0.035);
   frame_2dd1230__3->GetXaxis()->SetTitleFont(42);
   frame_2dd1230__3->GetYaxis()->SetTitle("Events / ( 1.1 )");
   frame_2dd1230__3->GetYaxis()->SetLabelFont(42);
   frame_2dd1230__3->GetYaxis()->SetLabelSize(0.035);
   frame_2dd1230__3->GetYaxis()->SetTitleSize(0.035);
   frame_2dd1230__3->GetYaxis()->SetTitleFont(42);
   frame_2dd1230__3->GetZaxis()->SetLabelFont(42);
   frame_2dd1230__3->GetZaxis()->SetLabelSize(0.035);
   frame_2dd1230__3->GetZaxis()->SetTitleSize(0.035);
   frame_2dd1230__3->GetZaxis()->SetTitleFont(42);
   frame_2dd1230__3->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100);
   grae->SetName("h_data");
   grae->SetTitle("Histogram of data_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,10.55,15);
   grae->SetPointError(0,0.55,0.55,3.82938,4.958738);
   grae->SetPoint(1,11.65,4);
   grae->SetPointError(1,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(2,12.75,4);
   grae->SetPointError(2,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(3,13.85,10);
   grae->SetPointError(3,0.55,0.55,3.108694,4.26695);
   grae->SetPoint(4,14.95,5);
   grae->SetPointError(4,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(5,16.05,4);
   grae->SetPointError(5,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(6,17.15,7);
   grae->SetPointError(6,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(7,18.25,6);
   grae->SetPointError(7,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(8,19.35,5);
   grae->SetPointError(8,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(9,20.45,7);
   grae->SetPointError(9,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(10,21.55,5);
   grae->SetPointError(10,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(11,22.65,3);
   grae->SetPointError(11,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(12,23.75,3);
   grae->SetPointError(12,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(13,24.85,3);
   grae->SetPointError(13,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(14,25.95,3);
   grae->SetPointError(14,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(15,27.05,7);
   grae->SetPointError(15,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(16,28.15,3);
   grae->SetPointError(16,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(17,29.25,5);
   grae->SetPointError(17,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(18,30.35,5);
   grae->SetPointError(18,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(19,31.45,3);
   grae->SetPointError(19,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(20,32.55,6);
   grae->SetPointError(20,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(21,33.65,6);
   grae->SetPointError(21,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(22,34.75,1);
   grae->SetPointError(22,0.55,0.55,0.8272462,2.299527);
   grae->SetPoint(23,35.85,2);
   grae->SetPointError(23,0.55,0.55,1.291815,2.63786);
   grae->SetPoint(24,36.95,5);
   grae->SetPointError(24,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(25,38.05,3);
   grae->SetPointError(25,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(26,39.15,3);
   grae->SetPointError(26,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(27,40.25,4);
   grae->SetPointError(27,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(28,41.35,4);
   grae->SetPointError(28,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(29,42.45,2);
   grae->SetPointError(29,0.55,0.55,1.291815,2.63786);
   grae->SetPoint(30,43.55,2);
   grae->SetPointError(30,0.55,0.55,1.291815,2.63786);
   grae->SetPoint(31,44.65,6);
   grae->SetPointError(31,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(32,45.75,5);
   grae->SetPointError(32,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(33,46.85,2);
   grae->SetPointError(33,0.55,0.55,1.291815,2.63786);
   grae->SetPoint(34,47.95,2);
   grae->SetPointError(34,0.55,0.55,1.291815,2.63786);
   grae->SetPoint(35,49.05,5);
   grae->SetPointError(35,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(36,50.15,6);
   grae->SetPointError(36,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(37,51.25,3);
   grae->SetPointError(37,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(38,52.35,9);
   grae->SetPointError(38,0.55,0.55,2.943461,4.110204);
   grae->SetPoint(39,53.45,4);
   grae->SetPointError(39,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(40,54.55,8);
   grae->SetPointError(40,0.55,0.55,2.768386,3.945142);
   grae->SetPoint(41,55.65,9);
   grae->SetPointError(41,0.55,0.55,2.943461,4.110204);
   grae->SetPoint(42,56.75,6);
   grae->SetPointError(42,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(43,57.85,10);
   grae->SetPointError(43,0.55,0.55,3.108694,4.26695);
   grae->SetPoint(44,58.95,6);
   grae->SetPointError(44,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(45,60.05,10);
   grae->SetPointError(45,0.55,0.55,3.108694,4.26695);
   grae->SetPoint(46,61.15,10);
   grae->SetPointError(46,0.55,0.55,3.108694,4.26695);
   grae->SetPoint(47,62.25,4);
   grae->SetPointError(47,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(48,63.35,4);
   grae->SetPointError(48,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(49,64.45,4);
   grae->SetPointError(49,0.55,0.55,1.914339,3.162753);
   grae->SetPoint(50,65.55,3);
   grae->SetPointError(50,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(51,66.65,5);
   grae->SetPointError(51,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(52,67.75,7);
   grae->SetPointError(52,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(53,68.85,3);
   grae->SetPointError(53,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(54,69.95,1);
   grae->SetPointError(54,0.55,0.55,0.8272462,2.299527);
   grae->SetPoint(55,71.05,7);
   grae->SetPointError(55,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(56,72.15,7);
   grae->SetPointError(56,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(57,73.25,5);
   grae->SetPointError(57,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(58,74.35,5);
   grae->SetPointError(58,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(59,75.45,3);
   grae->SetPointError(59,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(60,76.55,9);
   grae->SetPointError(60,0.55,0.55,2.943461,4.110204);
   grae->SetPoint(61,77.65,3);
   grae->SetPointError(61,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(62,78.75,7);
   grae->SetPointError(62,0.55,0.55,2.58147,3.770281);
   grae->SetPoint(63,79.85,8);
   grae->SetPointError(63,0.55,0.55,2.768386,3.945142);
   grae->SetPoint(64,80.95,6);
   grae->SetPointError(64,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(65,82.05,5);
   grae->SetPointError(65,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(66,83.15,6);
   grae->SetPointError(66,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(67,84.25,6);
   grae->SetPointError(67,0.55,0.55,2.379931,3.583642);
   grae->SetPoint(68,85.35,3);
   grae->SetPointError(68,0.55,0.55,1.632705,2.918186);
   grae->SetPoint(69,86.45,9);
   grae->SetPointError(69,0.55,0.55,2.943461,4.110204);
   grae->SetPoint(70,87.55,9);
   grae->SetPointError(70,0.55,0.55,2.943461,4.110204);
   grae->SetPoint(71,88.65,16);
   grae->SetPointError(71,0.55,0.55,3.957801,5.083066);
   grae->SetPoint(72,89.75,32);
   grae->SetPointError(72,0.55,0.55,5.627135,6.715753);
   grae->SetPoint(73,90.85,25);
   grae->SetPointError(73,0.55,0.55,4.966335,6.066589);
   grae->SetPoint(74,91.95,23);
   grae->SetPointError(74,0.55,0.55,4.760717,5.865235);
   grae->SetPoint(75,93.05,8);
   grae->SetPointError(75,0.55,0.55,2.768386,3.945142);
   grae->SetPoint(76,94.15,5);
   grae->SetPointError(76,0.55,0.55,2.159691,3.382473);
   grae->SetPoint(77,95.25,1);
   grae->SetPointError(77,0.55,0.55,0.8272462,2.299527);
   grae->SetPoint(78,96.35,1);
   grae->SetPointError(78,0.55,0.55,0.8272462,2.299527);
   grae->SetPoint(79,97.45,0);
   grae->SetPointError(79,0.55,0.55,0,1.147874);
   grae->SetPoint(80,98.55,0);
   grae->SetPointError(80,0.55,0.55,0,1.147874);
   grae->SetPoint(81,99.65,0);
   grae->SetPointError(81,0.55,0.55,0,1.147874);
   grae->SetPoint(82,100.75,0);
   grae->SetPointError(82,0.55,0.55,0,1.147874);
   grae->SetPoint(83,101.85,0);
   grae->SetPointError(83,0.55,0.55,0,1.147874);
   grae->SetPoint(84,102.95,0);
   grae->SetPointError(84,0.55,0.55,0,1.147874);
   grae->SetPoint(85,104.05,0);
   grae->SetPointError(85,0.55,0.55,0,1.147874);
   grae->SetPoint(86,105.15,0);
   grae->SetPointError(86,0.55,0.55,0,1.147874);
   grae->SetPoint(87,106.25,0);
   grae->SetPointError(87,0.55,0.55,0,1.147874);
   grae->SetPoint(88,107.35,0);
   grae->SetPointError(88,0.55,0.55,0,1.147874);
   grae->SetPoint(89,108.45,0);
   grae->SetPointError(89,0.55,0.55,0,1.147874);
   grae->SetPoint(90,109.55,0);
   grae->SetPointError(90,0.55,0.55,0,1.147874);
   grae->SetPoint(91,110.65,0);
   grae->SetPointError(91,0.55,0.55,0,1.147874);
   grae->SetPoint(92,111.75,0);
   grae->SetPointError(92,0.55,0.55,0,1.147874);
   grae->SetPoint(93,112.85,0);
   grae->SetPointError(93,0.55,0.55,0,1.147874);
   grae->SetPoint(94,113.95,0);
   grae->SetPointError(94,0.55,0.55,0,1.147874);
   grae->SetPoint(95,115.05,0);
   grae->SetPointError(95,0.55,0.55,0,1.147874);
   grae->SetPoint(96,116.15,0);
   grae->SetPointError(96,0.55,0.55,0,1.147874);
   grae->SetPoint(97,117.25,0);
   grae->SetPointError(97,0.55,0.55,0,1.147874);
   grae->SetPoint(98,118.35,0);
   grae->SetPointError(98,0.55,0.55,0,1.147874);
   grae->SetPoint(99,119.45,0);
   grae->SetPointError(99,0.55,0.55,0,1.147874);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(106);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,20,4.90250749);
   graph->SetPoint(1,20.2,4.863303257);
   graph->SetPoint(2,20.4,4.824445652);
   graph->SetPoint(3,20.6,4.785952683);
   graph->SetPoint(4,20.8,4.747842526);
   graph->SetPoint(5,21,4.710126844);
   graph->SetPoint(6,21.2,4.672844246);
   graph->SetPoint(7,21.4,4.636044372);
   graph->SetPoint(8,21.6,4.59977171);
   graph->SetPoint(9,21.8,4.564078706);
   graph->SetPoint(10,22,4.529007869);
   graph->SetPoint(11,22.2,4.494609057);
   graph->SetPoint(12,22.4,4.460942602);
   graph->SetPoint(13,22.6,4.428058321);
   graph->SetPoint(14,22.8,4.396015926);
   graph->SetPoint(15,23,4.364855369);
   graph->SetPoint(16,23.2,4.334620177);
   graph->SetPoint(17,23.4,4.305341762);
   graph->SetPoint(18,23.6,4.277038664);
   graph->SetPoint(19,23.8,4.249730693);
   graph->SetPoint(20,24,4.223440377);
   graph->SetPoint(21,24.2,4.198146403);
   graph->SetPoint(22,24.4,4.173837836);
   graph->SetPoint(23,24.6,4.150467839);
   graph->SetPoint(24,24.8,4.127992125);
   graph->SetPoint(25,25,4.106400552);
   graph->SetPoint(26,25.2,4.085614949);
   graph->SetPoint(27,25.4,4.065548699);
   graph->SetPoint(28,25.6,4.04611159);
   graph->SetPoint(29,25.8,4.027214273);
   graph->SetPoint(30,26,4.008797254);
   graph->SetPoint(31,26.2,3.990859969);
   graph->SetPoint(32,26.4,3.973222073);
   graph->SetPoint(33,26.6,3.955778712);
   graph->SetPoint(34,26.8,3.938458849);
   graph->SetPoint(35,27,3.92118651);
   graph->SetPoint(36,27.2,3.904211232);
   graph->SetPoint(37,27.4,3.887385001);
   graph->SetPoint(38,27.6,3.870541236);
   graph->SetPoint(39,27.8,3.853680904);
   graph->SetPoint(40,28,3.836797917);
   graph->SetPoint(41,28.2,3.820347242);
   graph->SetPoint(42,28.4,3.805642208);
   graph->SetPoint(43,28.6,3.79158452);
   graph->SetPoint(44,28.8,3.778223221);
   graph->SetPoint(45,29,3.765642022);
   graph->SetPoint(46,29.2,3.753914951);
   graph->SetPoint(47,29.25,3.751129351);
   graph->SetPoint(48,29.3,3.752865125);
   graph->SetPoint(49,29.4,3.757693904);
   graph->SetPoint(50,29.6,3.7727968);
   graph->SetPoint(51,29.8,3.795241314);
   graph->SetPoint(52,30,3.825142532);
   graph->SetPoint(53,30.2,3.862603203);
   graph->SetPoint(54,30.3,3.884200237);
   graph->SetPoint(55,30.35,3.895717543);
   graph->SetPoint(56,30.4,3.899014721);
   graph->SetPoint(57,30.6,3.909481085);
   graph->SetPoint(58,30.8,3.915699323);
   graph->SetPoint(59,31,3.917764233);
   graph->SetPoint(60,31.2,3.915743897);
   graph->SetPoint(61,31.4,3.90970782);
   graph->SetPoint(62,31.6,3.905978244);
   graph->SetPoint(63,31.8,3.90276971);
   graph->SetPoint(64,32,3.898404411);
   graph->SetPoint(65,32.2,3.892860934);
   graph->SetPoint(66,32.4,3.886144992);
   graph->SetPoint(67,32.6,3.879665201);
   graph->SetPoint(68,32.8,3.877464891);
   graph->SetPoint(69,33,3.876023474);
   graph->SetPoint(70,33.2,3.875270027);
   graph->SetPoint(71,33.4,3.87511856);
   graph->SetPoint(72,33.6,3.875485267);
   graph->SetPoint(73,33.8,3.876928791);
   graph->SetPoint(74,34,3.879148182);
   graph->SetPoint(75,34.2,3.881834628);
   graph->SetPoint(76,34.4,3.884828619);
   graph->SetPoint(77,34.6,3.887979139);
   graph->SetPoint(78,34.8,3.891179942);
   graph->SetPoint(79,35,3.894418582);
   graph->SetPoint(80,35.2,3.897354534);
   graph->SetPoint(81,35.4,3.899806623);
   graph->SetPoint(82,35.6,3.901598581);
   graph->SetPoint(83,35.8,3.902548314);
   graph->SetPoint(84,36,3.902545089);
   graph->SetPoint(85,36.2,3.901370506);
   graph->SetPoint(86,36.4,3.898798069);
   graph->SetPoint(87,36.6,3.894735546);
   graph->SetPoint(88,36.8,3.889054036);
   graph->SetPoint(89,37,3.881654202);
   graph->SetPoint(90,37.2,3.872477492);
   graph->SetPoint(91,37.4,3.861337205);
   graph->SetPoint(92,37.6,3.848286146);
   graph->SetPoint(93,37.8,3.833343137);
   graph->SetPoint(94,38,3.816541987);
   graph->SetPoint(95,38.2,3.797965421);
   graph->SetPoint(96,38.4,3.777665634);
   graph->SetPoint(97,38.6,3.755766149);
   graph->SetPoint(98,38.8,3.732495336);
   graph->SetPoint(99,39,3.708048145);
   graph->SetPoint(100,39.2,3.68264895);
   graph->SetPoint(101,39.4,3.656551541);
   graph->SetPoint(102,39.6,3.629997564);
   graph->SetPoint(103,39.8,3.603320962);
   graph->SetPoint(104,40,3.576818461);
   graph->SetPoint(105,40,3.576818461);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_expo_pf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,20,3.184036507);
   graph->SetPoint(1,20.2,3.130183445);
   graph->SetPoint(2,20.4,3.077241224);
   graph->SetPoint(3,20.6,3.025194439);
   graph->SetPoint(4,20.8,2.974027945);
   graph->SetPoint(5,21,2.923726853);
   graph->SetPoint(6,21.2,2.874276527);
   graph->SetPoint(7,21.4,2.825662576);
   graph->SetPoint(8,21.6,2.777870856);
   graph->SetPoint(9,21.8,2.730887459);
   graph->SetPoint(10,22,2.684698713);
   graph->SetPoint(11,22.2,2.639291179);
   graph->SetPoint(12,22.4,2.594651643);
   graph->SetPoint(13,22.6,2.550767115);
   graph->SetPoint(14,22.8,2.507624827);
   graph->SetPoint(15,23,2.465212224);
   graph->SetPoint(16,23.2,2.423516965);
   graph->SetPoint(17,23.4,2.382526917);
   graph->SetPoint(18,23.6,2.342230152);
   graph->SetPoint(19,23.8,2.302614945);
   graph->SetPoint(20,24,2.263669768);
   graph->SetPoint(21,24.2,2.225383288);
   graph->SetPoint(22,24.4,2.187744365);
   graph->SetPoint(23,24.6,2.150742046);
   graph->SetPoint(24,24.8,2.114365565);
   graph->SetPoint(25,25,2.078604335);
   graph->SetPoint(26,25.2,2.043447951);
   graph->SetPoint(27,25.4,2.008886184);
   graph->SetPoint(28,25.6,1.974908975);
   graph->SetPoint(29,25.8,1.941506438);
   graph->SetPoint(30,26,1.908668854);
   graph->SetPoint(31,26.2,1.876386667);
   graph->SetPoint(32,26.4,1.844650483);
   graph->SetPoint(33,26.6,1.813451068);
   graph->SetPoint(34,26.8,1.782779342);
   graph->SetPoint(35,27,1.752626382);
   graph->SetPoint(36,27.2,1.722983412);
   graph->SetPoint(37,27.4,1.693841807);
   graph->SetPoint(38,27.6,1.665193088);
   graph->SetPoint(39,27.8,1.637028918);
   graph->SetPoint(40,28,1.609341101);
   graph->SetPoint(41,28.2,1.58212158);
   graph->SetPoint(42,28.4,1.555362436);
   graph->SetPoint(43,28.6,1.529055881);
   graph->SetPoint(44,28.8,1.503194262);
   graph->SetPoint(45,29,1.477770051);
   graph->SetPoint(46,29.2,1.452775852);
   graph->SetPoint(47,29.4,1.428204391);
   graph->SetPoint(48,29.6,1.404048518);
   graph->SetPoint(49,29.8,1.380301205);
   graph->SetPoint(50,30,1.356955541);
   graph->SetPoint(51,30.2,1.334004733);
   graph->SetPoint(52,30.4,1.311442102);
   graph->SetPoint(53,30.6,1.289261083);
   graph->SetPoint(54,30.8,1.267455222);
   graph->SetPoint(55,31,1.246018174);
   graph->SetPoint(56,31.2,1.2249437);
   graph->SetPoint(57,31.4,1.204225668);
   graph->SetPoint(58,31.6,1.18385805);
   graph->SetPoint(59,31.8,1.163834919);
   graph->SetPoint(60,32,1.144150448);
   graph->SetPoint(61,32.2,1.124798909);
   graph->SetPoint(62,32.4,1.105774672);
   graph->SetPoint(63,32.6,1.0870722);
   graph->SetPoint(64,32.8,1.068686052);
   graph->SetPoint(65,33,1.050610877);
   graph->SetPoint(66,33.2,1.032841416);
   graph->SetPoint(67,33.4,1.015372498);
   graph->SetPoint(68,33.6,0.9981990396);
   graph->SetPoint(69,33.8,0.9813160438);
   graph->SetPoint(70,34,0.9647185978);
   graph->SetPoint(71,34.2,0.9484018719);
   graph->SetPoint(72,34.4,0.9323611183);
   graph->SetPoint(73,34.6,0.9165916693);
   graph->SetPoint(74,34.8,0.9010889362);
   graph->SetPoint(75,35,0.8858484078);
   graph->SetPoint(76,35.2,0.8708656495);
   graph->SetPoint(77,35.4,0.8561363014);
   graph->SetPoint(78,35.6,0.8416560775);
   graph->SetPoint(79,35.8,0.8274207642);
   graph->SetPoint(80,36,0.8134262192);
   graph->SetPoint(81,36.2,0.7996683704);
   graph->SetPoint(82,36.4,0.7861432144);
   graph->SetPoint(83,36.6,0.7728468155);
   graph->SetPoint(84,36.8,0.7597753047);
   graph->SetPoint(85,37,0.7469248783);
   graph->SetPoint(86,37.2,0.734291797);
   graph->SetPoint(87,37.4,0.7218723848);
   graph->SetPoint(88,37.6,0.7096630277);
   graph->SetPoint(89,37.8,0.6976601731);
   graph->SetPoint(90,38,0.6858603283);
   graph->SetPoint(91,38.2,0.6742600596);
   graph->SetPoint(92,38.4,0.6628559915);
   graph->SetPoint(93,38.6,0.6516448057);
   graph->SetPoint(94,38.8,0.6406232398);
   graph->SetPoint(95,39,0.6297880866);
   graph->SetPoint(96,39.2,0.6191361933);
   graph->SetPoint(97,39.4,0.6086644604);
   graph->SetPoint(98,39.6,0.5983698406);
   graph->SetPoint(99,39.8,0.5882493385);
   graph->SetPoint(100,40,0.578300009);
   graph->SetPoint(101,40,0.578300009);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_toppdf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,20,1.708662569);
   graph->SetPoint(1,20.2,1.723131837);
   graph->SetPoint(2,20.4,1.737031449);
   graph->SetPoint(3,20.6,1.750390123);
   graph->SetPoint(4,20.8,1.763242559);
   graph->SetPoint(5,21,1.775616621);
   graph->SetPoint(6,21.2,1.787565555);
   graph->SetPoint(7,21.4,1.799153393);
   graph->SetPoint(8,21.6,1.810436502);
   graph->SetPoint(9,21.8,1.821474738);
   graph->SetPoint(10,22,1.832329894);
   graph->SetPoint(11,22.2,1.843065268);
   graph->SetPoint(12,22.4,1.853754404);
   graph->SetPoint(13,22.6,1.864460108);
   graph->SetPoint(14,22.8,1.875242527);
   graph->SetPoint(15,23,1.886157784);
   graph->SetPoint(16,23.2,1.897265203);
   graph->SetPoint(17,23.4,1.908608327);
   graph->SetPoint(18,23.6,1.920217626);
   graph->SetPoint(19,23.8,1.932117794);
   graph->SetPoint(20,24,1.944323257);
   graph->SetPoint(21,24.2,1.956840988);
   graph->SetPoint(22,24.4,1.969671194);
   graph->SetPoint(23,24.6,1.982777986);
   graph->SetPoint(24,24.8,1.996127849);
   graph->SetPoint(25,25,2.009676335);
   graph->SetPoint(26,25.2,2.023368846);
   graph->SetPoint(27,25.4,2.037141566);
   graph->SetPoint(28,25.6,2.050914337);
   graph->SetPoint(29,25.8,2.0646077);
   graph->SetPoint(30,26,2.078139541);
   graph->SetPoint(31,26.2,2.091426064);
   graph->SetPoint(32,26.4,2.10437645);
   graph->SetPoint(33,26.6,2.116895085);
   graph->SetPoint(34,26.8,2.128920009);
   graph->SetPoint(35,27,2.140384172);
   graph->SetPoint(36,27.2,2.151229868);
   graph->SetPoint(37,27.4,2.161410408);
   graph->SetPoint(38,27.6,2.170856175);
   graph->SetPoint(39,27.8,2.179576471);
   graph->SetPoint(40,28,2.187573406);
   graph->SetPoint(41,28.2,2.194858911);
   graph->SetPoint(42,28.4,2.201459797);
   graph->SetPoint(43,28.6,2.20740348);
   graph->SetPoint(44,28.8,2.212746656);
   graph->SetPoint(45,29,2.217580564);
   graph->SetPoint(46,29.2,2.221986629);
   graph->SetPoint(47,29.4,2.226055675);
   graph->SetPoint(48,29.6,2.229886152);
   graph->SetPoint(49,29.8,2.233581903);
   graph->SetPoint(50,30,2.237264921);
   graph->SetPoint(51,30.2,2.241044749);
   graph->SetPoint(52,30.4,2.245029894);
   graph->SetPoint(53,30.6,2.249326077);
   graph->SetPoint(54,30.8,2.254050053);
   graph->SetPoint(55,31,2.259302966);
   graph->SetPoint(56,31.2,2.265159136);
   graph->SetPoint(57,31.4,2.271694201);
   graph->SetPoint(58,31.6,2.278973194);
   graph->SetPoint(59,31.8,2.287053799);
   graph->SetPoint(60,32,2.296017744);
   graph->SetPoint(61,32.2,2.30584934);
   graph->SetPoint(62,32.4,2.316559934);
   graph->SetPoint(63,32.6,2.328146761);
   graph->SetPoint(64,32.8,2.340592666);
   graph->SetPoint(65,33,2.353893893);
   graph->SetPoint(66,33.2,2.367984781);
   graph->SetPoint(67,33.4,2.382784509);
   graph->SetPoint(68,33.6,2.398214355);
   graph->SetPoint(69,33.8,2.414181369);
   graph->SetPoint(70,34,2.430582111);
   graph->SetPoint(71,34.2,2.447296448);
   graph->SetPoint(72,34.4,2.464169615);
   graph->SetPoint(73,34.6,2.481055264);
   graph->SetPoint(74,34.8,2.497797064);
   graph->SetPoint(75,35,2.514230179);
   graph->SetPoint(76,35.2,2.530154024);
   graph->SetPoint(77,35.4,2.545391782);
   graph->SetPoint(78,35.6,2.559771472);
   graph->SetPoint(79,35.8,2.573115213);
   graph->SetPoint(80,36,2.585248753);
   graph->SetPoint(81,36.2,2.595977611);
   graph->SetPoint(82,36.4,2.605098241);
   graph->SetPoint(83,36.6,2.612522345);
   graph->SetPoint(84,36.8,2.618124892);
   graph->SetPoint(85,37,2.621800669);
   graph->SetPoint(86,37.2,2.623467091);
   graph->SetPoint(87,37.4,2.622965117);
   graph->SetPoint(88,37.6,2.620351168);
   graph->SetPoint(89,37.8,2.615647617);
   graph->SetPoint(90,38,2.608891768);
   graph->SetPoint(91,38.2,2.600152718);
   graph->SetPoint(92,38.4,2.58949104);
   graph->SetPoint(93,38.6,2.577038354);
   graph->SetPoint(94,38.8,2.563026293);
   graph->SetPoint(95,39,2.547653014);
   graph->SetPoint(96,39.2,2.531142859);
   graph->SetPoint(97,39.4,2.513743586);
   graph->SetPoint(98,39.6,2.495707776);
   graph->SetPoint(99,39.8,2.477372367);
   graph->SetPoint(100,40,2.45903703);
   graph->SetPoint(101,40,2.45903703);
   graph->Draw("l");
   
   graph = new TGraph(117);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_gauss_bw_pf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,20,0.009808414176);
   graph->SetPoint(1,20.2,0.009987975208);
   graph->SetPoint(2,20.4,0.01017297967);
   graph->SetPoint(3,20.6,0.01036812104);
   graph->SetPoint(4,20.8,0.01057202257);
   graph->SetPoint(5,21,0.01078337008);
   graph->SetPoint(6,21.2,0.01100216358);
   graph->SetPoint(7,21.4,0.01122840305);
   graph->SetPoint(8,21.6,0.01146435264);
   graph->SetPoint(9,21.8,0.01171650941);
   graph->SetPoint(10,22,0.01197926225);
   graph->SetPoint(11,22.2,0.01225261117);
   graph->SetPoint(12,22.4,0.01253655616);
   graph->SetPoint(13,22.6,0.01283109724);
   graph->SetPoint(14,22.8,0.01314857155);
   graph->SetPoint(15,23,0.01348536021);
   graph->SetPoint(16,23.2,0.01383800881);
   graph->SetPoint(17,23.4,0.01420651734);
   graph->SetPoint(18,23.6,0.01459088581);
   graph->SetPoint(19,23.8,0.01499795451);
   graph->SetPoint(20,24,0.01544735211);
   graph->SetPoint(21,24.2,0.01592212657);
   graph->SetPoint(22,24.4,0.01642227791);
   graph->SetPoint(23,24.6,0.01694780611);
   graph->SetPoint(24,24.8,0.01749871118);
   graph->SetPoint(25,25,0.01811988195);
   graph->SetPoint(26,25.2,0.01879815103);
   graph->SetPoint(27,25.4,0.01952094954);
   graph->SetPoint(28,25.6,0.02028827749);
   graph->SetPoint(29,25.8,0.02110013488);
   graph->SetPoint(30,26,0.02198885817);
   graph->SetPoint(31,26.2,0.02304723902);
   graph->SetPoint(32,26.4,0.02419513919);
   graph->SetPoint(33,26.6,0.02543255868);
   graph->SetPoint(34,26.8,0.02675949748);
   graph->SetPoint(35,27,0.02817595561);
   graph->SetPoint(36,27.2,0.02999795106);
   graph->SetPoint(37,27.4,0.03213278522);
   graph->SetPoint(38,27.6,0.03449197305);
   graph->SetPoint(39,27.8,0.03707551456);
   graph->SetPoint(40,28,0.03988340973);
   graph->SetPoint(41,28.2,0.04336675053);
   graph->SetPoint(42,28.4,0.04881997475);
   graph->SetPoint(43,28.6,0.05512515885);
   graph->SetPoint(44,28.8,0.06228230282);
   graph->SetPoint(45,29,0.07029140667);
   graph->SetPoint(46,29.2,0.07915247039);
   graph->SetPoint(47,29.25,0.08150085505);
   graph->SetPoint(48,29.3,0.08837011273);
   graph->SetPoint(49,29.4,0.1034338381);
   graph->SetPoint(50,29.5,0.1202645101);
   graph->SetPoint(51,29.6,0.1388621288);
   graph->SetPoint(52,29.7,0.1592266942);
   graph->SetPoint(53,29.8,0.1813582062);
   graph->SetPoint(54,29.9,0.205256665);
   graph->SetPoint(55,30,0.2309220704);
   graph->SetPoint(56,30.1,0.2583544224);
   graph->SetPoint(57,30.2,0.2875537212);
   graph->SetPoint(58,30.3,0.3185199666);
   graph->SetPoint(59,30.35,0.3346656943);
   graph->SetPoint(60,30.4,0.3425427251);
   graph->SetPoint(61,30.5,0.3573497097);
   graph->SetPoint(62,30.6,0.370893925);
   graph->SetPoint(63,30.7,0.383175371);
   graph->SetPoint(64,30.8,0.3941940476);
   graph->SetPoint(65,30.9,0.4039499549);
   graph->SetPoint(66,31,0.4124430928);
   graph->SetPoint(67,31.1,0.4196734614);
   graph->SetPoint(68,31.2,0.4256410606);
   graph->SetPoint(69,31.3,0.4303458905);
   graph->SetPoint(70,31.4,0.433787951);
   graph->SetPoint(71,31.45,0.4350354428);
   graph->SetPoint(72,31.5,0.4378879679);
   graph->SetPoint(73,31.6,0.443147);
   graph->SetPoint(74,31.8,0.4518809917);
   graph->SetPoint(75,32,0.45823622);
   graph->SetPoint(76,32.2,0.4622126849);
   graph->SetPoint(77,32.4,0.4638103865);
   graph->SetPoint(78,32.6,0.4644462395);
   graph->SetPoint(79,32.8,0.4681861733);
   graph->SetPoint(80,33,0.4715187036);
   graph->SetPoint(81,33.2,0.4744438302);
   graph->SetPoint(82,33.4,0.4769615531);
   graph->SetPoint(83,33.6,0.4790718724);
   graph->SetPoint(84,33.8,0.4814313789);
   graph->SetPoint(85,34,0.4838474727);
   graph->SetPoint(86,34.2,0.4861363083);
   graph->SetPoint(87,34.4,0.4882978857);
   graph->SetPoint(88,34.6,0.4903322049);
   graph->SetPoint(89,34.8,0.4922939422);
   graph->SetPoint(90,35,0.4943399947);
   graph->SetPoint(91,35.2,0.4963348605);
   graph->SetPoint(92,35.4,0.4982785394);
   graph->SetPoint(93,35.6,0.5001710314);
   graph->SetPoint(94,35.8,0.5020123366);
   graph->SetPoint(95,36,0.5038701167);
   graph->SetPoint(96,36.2,0.5057245241);
   graph->SetPoint(97,36.4,0.5075566137);
   graph->SetPoint(98,36.6,0.5093663854);
   graph->SetPoint(99,36.8,0.5111538392);
   graph->SetPoint(100,37,0.5129286542);
   graph->SetPoint(101,37.2,0.5147186044);
   graph->SetPoint(102,37.4,0.5164997032);
   graph->SetPoint(103,37.6,0.5182719504);
   graph->SetPoint(104,37.8,0.520035346);
   graph->SetPoint(105,38,0.5217898902);
   graph->SetPoint(106,38.2,0.5235526438);
   graph->SetPoint(107,38.4,0.5253186023);
   graph->SetPoint(108,38.6,0.5270829886);
   graph->SetPoint(109,38.8,0.5288458028);
   graph->SetPoint(110,39,0.5306070448);
   graph->SetPoint(111,39.2,0.5323698975);
   graph->SetPoint(112,39.4,0.5341434944);
   graph->SetPoint(113,39.6,0.5359199475);
   graph->SetPoint(114,39.8,0.5376992567);
   graph->SetPoint(115,40,0.5394814221);
   graph->SetPoint(116,40,0.5394814221);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_toppdf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,20,1.708662569);
   graph->SetPoint(1,20.2,1.723131837);
   graph->SetPoint(2,20.4,1.737031449);
   graph->SetPoint(3,20.6,1.750390123);
   graph->SetPoint(4,20.8,1.763242559);
   graph->SetPoint(5,21,1.775616621);
   graph->SetPoint(6,21.2,1.787565555);
   graph->SetPoint(7,21.4,1.799153393);
   graph->SetPoint(8,21.6,1.810436502);
   graph->SetPoint(9,21.8,1.821474738);
   graph->SetPoint(10,22,1.832329894);
   graph->SetPoint(11,22.2,1.843065268);
   graph->SetPoint(12,22.4,1.853754404);
   graph->SetPoint(13,22.6,1.864460108);
   graph->SetPoint(14,22.8,1.875242527);
   graph->SetPoint(15,23,1.886157784);
   graph->SetPoint(16,23.2,1.897265203);
   graph->SetPoint(17,23.4,1.908608327);
   graph->SetPoint(18,23.6,1.920217626);
   graph->SetPoint(19,23.8,1.932117794);
   graph->SetPoint(20,24,1.944323257);
   graph->SetPoint(21,24.2,1.956840988);
   graph->SetPoint(22,24.4,1.969671194);
   graph->SetPoint(23,24.6,1.982777986);
   graph->SetPoint(24,24.8,1.996127849);
   graph->SetPoint(25,25,2.009676335);
   graph->SetPoint(26,25.2,2.023368846);
   graph->SetPoint(27,25.4,2.037141566);
   graph->SetPoint(28,25.6,2.050914337);
   graph->SetPoint(29,25.8,2.0646077);
   graph->SetPoint(30,26,2.078139541);
   graph->SetPoint(31,26.2,2.091426064);
   graph->SetPoint(32,26.4,2.10437645);
   graph->SetPoint(33,26.6,2.116895085);
   graph->SetPoint(34,26.8,2.128920009);
   graph->SetPoint(35,27,2.140384172);
   graph->SetPoint(36,27.2,2.151229868);
   graph->SetPoint(37,27.4,2.161410408);
   graph->SetPoint(38,27.6,2.170856175);
   graph->SetPoint(39,27.8,2.179576471);
   graph->SetPoint(40,28,2.187573406);
   graph->SetPoint(41,28.2,2.194858911);
   graph->SetPoint(42,28.4,2.201459797);
   graph->SetPoint(43,28.6,2.20740348);
   graph->SetPoint(44,28.8,2.212746656);
   graph->SetPoint(45,29,2.217580564);
   graph->SetPoint(46,29.2,2.221986629);
   graph->SetPoint(47,29.4,2.226055675);
   graph->SetPoint(48,29.6,2.229886152);
   graph->SetPoint(49,29.8,2.233581903);
   graph->SetPoint(50,30,2.237264921);
   graph->SetPoint(51,30.2,2.241044749);
   graph->SetPoint(52,30.4,2.245029894);
   graph->SetPoint(53,30.6,2.249326077);
   graph->SetPoint(54,30.8,2.254050053);
   graph->SetPoint(55,31,2.259302966);
   graph->SetPoint(56,31.2,2.265159136);
   graph->SetPoint(57,31.4,2.271694201);
   graph->SetPoint(58,31.6,2.278973194);
   graph->SetPoint(59,31.8,2.287053799);
   graph->SetPoint(60,32,2.296017744);
   graph->SetPoint(61,32.2,2.30584934);
   graph->SetPoint(62,32.4,2.316559934);
   graph->SetPoint(63,32.6,2.328146761);
   graph->SetPoint(64,32.8,2.340592666);
   graph->SetPoint(65,33,2.353893893);
   graph->SetPoint(66,33.2,2.367984781);
   graph->SetPoint(67,33.4,2.382784509);
   graph->SetPoint(68,33.6,2.398214355);
   graph->SetPoint(69,33.8,2.414181369);
   graph->SetPoint(70,34,2.430582111);
   graph->SetPoint(71,34.2,2.447296448);
   graph->SetPoint(72,34.4,2.464169615);
   graph->SetPoint(73,34.6,2.481055264);
   graph->SetPoint(74,34.8,2.497797064);
   graph->SetPoint(75,35,2.514230179);
   graph->SetPoint(76,35.2,2.530154024);
   graph->SetPoint(77,35.4,2.545391782);
   graph->SetPoint(78,35.6,2.559771472);
   graph->SetPoint(79,35.8,2.573115213);
   graph->SetPoint(80,36,2.585248753);
   graph->SetPoint(81,36.2,2.595977611);
   graph->SetPoint(82,36.4,2.605098241);
   graph->SetPoint(83,36.6,2.612522345);
   graph->SetPoint(84,36.8,2.618124892);
   graph->SetPoint(85,37,2.621800669);
   graph->SetPoint(86,37.2,2.623467091);
   graph->SetPoint(87,37.4,2.622965117);
   graph->SetPoint(88,37.6,2.620351168);
   graph->SetPoint(89,37.8,2.615647617);
   graph->SetPoint(90,38,2.608891768);
   graph->SetPoint(91,38.2,2.600152718);
   graph->SetPoint(92,38.4,2.58949104);
   graph->SetPoint(93,38.6,2.577038354);
   graph->SetPoint(94,38.8,2.563026293);
   graph->SetPoint(95,39,2.547653014);
   graph->SetPoint(96,39.2,2.531142859);
   graph->SetPoint(97,39.4,2.513743586);
   graph->SetPoint(98,39.6,2.495707776);
   graph->SetPoint(99,39.8,2.477372367);
   graph->SetPoint(100,40,2.45903703);
   graph->SetPoint(101,40,2.45903703);
   graph->Draw("l");
   
   TPaveText *pt = new TPaveText(6.926362e-310,0,0,6.926362e-310,"BRNDC");
   pt->SetName("test_sum_pf_paramBox");
   pt->SetBorderSize(1);
   pt->SetFillColor(0);
   pt->SetTextAlign(12);
   pt->SetTextSize(0.04);
   TText *text = pt->AddText("test_background_pf =  210 +/- 74");
   text = pt->AddText("test_signal_bw_pf =  86 +/- 619");
   pt->Draw();
   
   TH1D *frame_2dd1230__4 = new TH1D("frame_2dd1230__4","SM",100,10,120);
   frame_2dd1230__4->SetBinContent(1,40.65154);
   frame_2dd1230__4->SetMaximum(40.65154);
   frame_2dd1230__4->SetEntries(1);
   frame_2dd1230__4->SetDirectory(0);
   frame_2dd1230__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2dd1230__4->SetLineColor(ci);
   frame_2dd1230__4->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_2dd1230__4->GetXaxis()->SetLabelFont(42);
   frame_2dd1230__4->GetXaxis()->SetLabelSize(0.035);
   frame_2dd1230__4->GetXaxis()->SetTitleSize(0.035);
   frame_2dd1230__4->GetXaxis()->SetTitleFont(42);
   frame_2dd1230__4->GetYaxis()->SetTitle("Events / ( 1.1 )");
   frame_2dd1230__4->GetYaxis()->SetLabelFont(42);
   frame_2dd1230__4->GetYaxis()->SetLabelSize(0.035);
   frame_2dd1230__4->GetYaxis()->SetTitleSize(0.035);
   frame_2dd1230__4->GetYaxis()->SetTitleFont(42);
   frame_2dd1230__4->GetZaxis()->SetLabelFont(42);
   frame_2dd1230__4->GetZaxis()->SetLabelSize(0.035);
   frame_2dd1230__4->GetZaxis()->SetTitleSize(0.035);
   frame_2dd1230__4->GetZaxis()->SetTitleFont(42);
   frame_2dd1230__4->Draw("AXISSAME");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
