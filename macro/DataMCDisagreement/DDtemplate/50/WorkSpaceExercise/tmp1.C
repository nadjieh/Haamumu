{
//=========Macro generated from canvas: c/c
//=========  (Tue Jan 20 18:05:15 2015) by ROOT version5.34/19
   TCanvas *c = new TCanvas("c", "c",13,34,700,500);
   c->Range(2.499999,-19.99498,77.5,179.9548);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH1D *frame_21cd090__5 = new TH1D("frame_21cd090__5","A RooPlot of \"eventSelectionamassMu\"",100,10,70);
   frame_21cd090__5->SetBinContent(1,159.9599);
   frame_21cd090__5->SetMaximum(159.9599);
   frame_21cd090__5->SetEntries(1);
   frame_21cd090__5->SetDirectory(0);
   frame_21cd090__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_21cd090__5->SetLineColor(ci);
   frame_21cd090__5->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_21cd090__5->GetXaxis()->SetLabelFont(42);
   frame_21cd090__5->GetXaxis()->SetLabelSize(0.035);
   frame_21cd090__5->GetXaxis()->SetTitleSize(0.035);
   frame_21cd090__5->GetXaxis()->SetTitleFont(42);
   frame_21cd090__5->GetYaxis()->SetTitle("Events / ( 0.6 )");
   frame_21cd090__5->GetYaxis()->SetLabelFont(42);
   frame_21cd090__5->GetYaxis()->SetLabelSize(0.035);
   frame_21cd090__5->GetYaxis()->SetTitleSize(0.035);
   frame_21cd090__5->GetYaxis()->SetTitleFont(42);
   frame_21cd090__5->GetZaxis()->SetLabelFont(42);
   frame_21cd090__5->GetZaxis()->SetLabelSize(0.035);
   frame_21cd090__5->GetZaxis()->SetTitleSize(0.035);
   frame_21cd090__5->GetZaxis()->SetTitleFont(42);
   frame_21cd090__5->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100);
   grae->SetName("h_data_dimu");
   grae->SetTitle("Histogram of data_dimu_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,10.3,140);
   grae->SetPointError(0,0.3,0.3,11.34272,12.34272);
   grae->SetPoint(1,10.9,30);
   grae->SetPointError(1,0.3,0.3,5.446522,6.538046);
   grae->SetPoint(2,11.5,51);
   grae->SetPointError(2,0.3,0.3,7.117933,8.188122);
   grae->SetPoint(3,12.1,31);
   grae->SetPointError(3,0.3,0.3,5.537565,6.627601);
   grae->SetPoint(4,12.7,35);
   grae->SetPointError(4,0.3,0.3,5.887675,6.97241);
   grae->SetPoint(5,13.3,35);
   grae->SetPointError(5,0.3,0.3,5.887675,6.97241);
   grae->SetPoint(6,13.9,26);
   grae->SetPointError(6,0.3,0.3,5.066015,6.164324);
   grae->SetPoint(7,14.5,35);
   grae->SetPointError(7,0.3,0.3,5.887675,6.97241);
   grae->SetPoint(8,15.1,22);
   grae->SetPointError(8,0.3,0.3,4.654502,5.761366);
   grae->SetPoint(9,15.7,35);
   grae->SetPointError(9,0.3,0.3,5.887675,6.97241);
   grae->SetPoint(10,16.3,29);
   grae->SetPointError(10,0.3,0.3,5.353932,6.44702);
   grae->SetPoint(11,16.9,36);
   grae->SetPointError(11,0.3,0.3,5.971996,7.055545);
   grae->SetPoint(12,17.5,24);
   grae->SetPointError(12,0.3,0.3,4.864612,5.966932);
   grae->SetPoint(13,18.1,23);
   grae->SetPointError(13,0.3,0.3,4.760717,5.865235);
   grae->SetPoint(14,18.7,21);
   grae->SetPointError(14,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(15,19.3,23);
   grae->SetPointError(15,0.3,0.3,4.760717,5.865235);
   grae->SetPoint(16,19.9,27);
   grae->SetPointError(16,0.3,0.3,5.163771,6.260244);
   grae->SetPoint(17,20.5,17);
   grae->SetPointError(17,0.3,0.3,4.082184,5.203719);
   grae->SetPoint(18,21.1,19);
   grae->SetPointError(18,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(19,21.7,12);
   grae->SetPointError(19,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(20,22.3,16);
   grae->SetPointError(20,0.3,0.3,3.957801,5.083066);
   grae->SetPoint(21,22.9,14);
   grae->SetPointError(21,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(22,23.5,15);
   grae->SetPointError(22,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(23,24.1,25);
   grae->SetPointError(23,0.3,0.3,4.966335,6.066589);
   grae->SetPoint(24,24.7,22);
   grae->SetPointError(24,0.3,0.3,4.654502,5.761366);
   grae->SetPoint(25,25.3,21);
   grae->SetPointError(25,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(26,25.9,15);
   grae->SetPointError(26,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(27,26.5,19);
   grae->SetPointError(27,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(28,27.1,30);
   grae->SetPointError(28,0.3,0.3,5.446522,6.538046);
   grae->SetPoint(29,27.7,18);
   grae->SetPointError(29,0.3,0.3,4.202887,5.321007);
   grae->SetPoint(30,28.3,26);
   grae->SetPointError(30,0.3,0.3,5.066015,6.164324);
   grae->SetPoint(31,28.9,16);
   grae->SetPointError(31,0.3,0.3,3.957801,5.083066);
   grae->SetPoint(32,29.5,15);
   grae->SetPointError(32,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(33,30.1,20);
   grae->SetPointError(33,0.3,0.3,4.434448,5.546519);
   grae->SetPoint(34,30.7,11);
   grae->SetPointError(34,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(35,31.3,20);
   grae->SetPointError(35,0.3,0.3,4.434448,5.546519);
   grae->SetPoint(36,31.9,18);
   grae->SetPointError(36,0.3,0.3,4.202887,5.321007);
   grae->SetPoint(37,32.5,10);
   grae->SetPointError(37,0.3,0.3,3.108694,4.26695);
   grae->SetPoint(38,33.1,27);
   grae->SetPointError(38,0.3,0.3,5.163771,6.260244);
   grae->SetPoint(39,33.7,21);
   grae->SetPointError(39,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(40,34.3,24);
   grae->SetPointError(40,0.3,0.3,4.864612,5.966932);
   grae->SetPoint(41,34.9,25);
   grae->SetPointError(41,0.3,0.3,4.966335,6.066589);
   grae->SetPoint(42,35.5,18);
   grae->SetPointError(42,0.3,0.3,4.202887,5.321007);
   grae->SetPoint(43,36.1,23);
   grae->SetPointError(43,0.3,0.3,4.760717,5.865235);
   grae->SetPoint(44,36.7,24);
   grae->SetPointError(44,0.3,0.3,4.864612,5.966932);
   grae->SetPoint(45,37.3,29);
   grae->SetPointError(45,0.3,0.3,5.353932,6.44702);
   grae->SetPoint(46,37.9,20);
   grae->SetPointError(46,0.3,0.3,4.434448,5.546519);
   grae->SetPoint(47,38.5,19);
   grae->SetPointError(47,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(48,39.1,15);
   grae->SetPointError(48,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(49,39.7,29);
   grae->SetPointError(49,0.3,0.3,5.353932,6.44702);
   grae->SetPoint(50,40.3,21);
   grae->SetPointError(50,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(51,40.9,15);
   grae->SetPointError(51,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(52,41.5,15);
   grae->SetPointError(52,0.3,0.3,3.82938,4.958738);
   grae->SetPoint(53,42.1,31);
   grae->SetPointError(53,0.3,0.3,5.537565,6.627601);
   grae->SetPoint(54,42.7,21);
   grae->SetPointError(54,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(55,43.3,19);
   grae->SetPointError(55,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(56,43.9,11);
   grae->SetPointError(56,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(57,44.5,19);
   grae->SetPointError(57,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(58,45.1,14);
   grae->SetPointError(58,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(59,45.7,24);
   grae->SetPointError(59,0.3,0.3,4.864612,5.966932);
   grae->SetPoint(60,46.3,21);
   grae->SetPointError(60,0.3,0.3,4.545807,5.655182);
   grae->SetPoint(61,46.9,18);
   grae->SetPointError(61,0.3,0.3,4.202887,5.321007);
   grae->SetPoint(62,47.5,12);
   grae->SetPointError(62,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(63,48.1,20);
   grae->SetPointError(63,0.3,0.3,4.434448,5.546519);
   grae->SetPoint(64,48.7,14);
   grae->SetPointError(64,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(65,49.3,17);
   grae->SetPointError(65,0.3,0.3,4.082184,5.203719);
   grae->SetPoint(66,49.9,19);
   grae->SetPointError(66,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(67,50.5,14);
   grae->SetPointError(67,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(68,51.1,11);
   grae->SetPointError(68,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(69,51.7,13);
   grae->SetPointError(69,0.3,0.3,3.558662,4.697573);
   grae->SetPoint(70,52.3,16);
   grae->SetPointError(70,0.3,0.3,3.957801,5.083066);
   grae->SetPoint(71,52.9,20);
   grae->SetPointError(71,0.3,0.3,4.434448,5.546519);
   grae->SetPoint(72,53.5,11);
   grae->SetPointError(72,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(73,54.1,13);
   grae->SetPointError(73,0.3,0.3,3.558662,4.697573);
   grae->SetPoint(74,54.7,14);
   grae->SetPointError(74,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(75,55.3,12);
   grae->SetPointError(75,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(76,55.9,17);
   grae->SetPointError(76,0.3,0.3,4.082184,5.203719);
   grae->SetPoint(77,56.5,19);
   grae->SetPointError(77,0.3,0.3,4.320219,5.435196);
   grae->SetPoint(78,57.1,12);
   grae->SetPointError(78,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(79,57.7,11);
   grae->SetPointError(79,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(80,58.3,17);
   grae->SetPointError(80,0.3,0.3,4.082184,5.203719);
   grae->SetPoint(81,58.9,14);
   grae->SetPointError(81,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(82,59.5,17);
   grae->SetPointError(82,0.3,0.3,4.082184,5.203719);
   grae->SetPoint(83,60.1,10);
   grae->SetPointError(83,0.3,0.3,3.108694,4.26695);
   grae->SetPoint(84,60.7,13);
   grae->SetPointError(84,0.3,0.3,3.558662,4.697573);
   grae->SetPoint(85,61.3,8);
   grae->SetPointError(85,0.3,0.3,2.768386,3.945142);
   grae->SetPoint(86,61.9,14);
   grae->SetPointError(86,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(87,62.5,10);
   grae->SetPointError(87,0.3,0.3,3.108694,4.26695);
   grae->SetPoint(88,63.1,9);
   grae->SetPointError(88,0.3,0.3,2.943461,4.110204);
   grae->SetPoint(89,63.7,10);
   grae->SetPointError(89,0.3,0.3,3.108694,4.26695);
   grae->SetPoint(90,64.3,12);
   grae->SetPointError(90,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(91,64.9,11);
   grae->SetPointError(91,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(92,65.5,11);
   grae->SetPointError(92,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(93,66.1,6);
   grae->SetPointError(93,0.3,0.3,2.379931,3.583642);
   grae->SetPoint(94,66.7,12);
   grae->SetPointError(94,0.3,0.3,3.415266,4.559819);
   grae->SetPoint(95,67.3,6);
   grae->SetPointError(95,0.3,0.3,2.379931,3.583642);
   grae->SetPoint(96,67.9,14);
   grae->SetPointError(96,0.3,0.3,3.6965,4.830381);
   grae->SetPoint(97,68.5,11);
   grae->SetPointError(97,0.3,0.3,3.265579,4.416521);
   grae->SetPoint(98,69.1,6);
   grae->SetPointError(98,0.3,0.3,2.379931,3.583642);
   grae->SetPoint(99,69.7,5);
   grae->SetPointError(99,0.3,0.3,2.159691,3.382473);
   
   TH1F *Graph_Graph_h_data_dimu13 = new TH1F("Graph_Graph_h_data_dimu13","Histogram of data_dimu_plot__eventSelectionamassMu",100,4,76);
   Graph_Graph_h_data_dimu13->SetMinimum(0);
   Graph_Graph_h_data_dimu13->SetMaximum(167.293);
   Graph_Graph_h_data_dimu13->SetDirectory(0);
   Graph_Graph_h_data_dimu13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_h_data_dimu13->SetLineColor(ci);
   Graph_Graph_h_data_dimu13->GetXaxis()->SetLabelFont(42);
   Graph_Graph_h_data_dimu13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_h_data_dimu13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_h_data_dimu13->GetXaxis()->SetTitleFont(42);
   Graph_Graph_h_data_dimu13->GetYaxis()->SetLabelFont(42);
   Graph_Graph_h_data_dimu13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_h_data_dimu13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_h_data_dimu13->GetYaxis()->SetTitleFont(42);
   Graph_Graph_h_data_dimu13->GetZaxis()->SetLabelFont(42);
   Graph_Graph_h_data_dimu13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_h_data_dimu13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_h_data_dimu13->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_h_data_dimu13);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(119);
   graph->SetName("test_bkg_dimu_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of test_bkg_dimu");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,9.4,0);
   graph->SetPoint(1,9.4,33.44939175);
   graph->SetPoint(2,10,33.44939175);
   graph->SetPoint(3,10.3,36.04587154);
   graph->SetPoint(4,10.45,37.22627818);
   graph->SetPoint(5,10.6,38.3229825);
   graph->SetPoint(6,10.75,39.32316236);
   graph->SetPoint(7,10.9,40.22940772);
   graph->SetPoint(8,11.05,41.03073018);
   graph->SetPoint(9,11.2,41.73252949);
   graph->SetPoint(10,11.35,42.32607114);
   graph->SetPoint(11,11.5,42.81911306);
   graph->SetPoint(12,11.65,43.2053604);
   graph->SetPoint(13,11.8,43.49434395);
   graph->SetPoint(14,11.95,43.68217952);
   graph->SetPoint(15,12.1,43.77952427);
   graph->SetPoint(16,12.25,43.78470479);
   graph->SetPoint(17,12.4,43.70886728);
   graph->SetPoint(18,12.7,43.32587118);
   graph->SetPoint(19,13,42.67970822);
   graph->SetPoint(20,13.3,41.82195455);
   graph->SetPoint(21,13.6,40.80384728);
   graph->SetPoint(22,14.2,38.47738847);
   graph->SetPoint(23,14.8,36.03403917);
   graph->SetPoint(24,15.4,33.712453);
   graph->SetPoint(25,16,31.6458471);
   graph->SetPoint(26,16.6,29.87311692);
   graph->SetPoint(27,17.2,28.36971711);
   graph->SetPoint(28,17.8,27.08705881);
   graph->SetPoint(29,18.4,25.98295719);
   graph->SetPoint(30,19,25.03210018);
   graph->SetPoint(31,19.6,24.2198831);
   graph->SetPoint(32,20.2,23.53232796);
   graph->SetPoint(33,20.8,22.95229954);
   graph->SetPoint(34,21.4,22.46281416);
   graph->SetPoint(35,22,22.05160272);
   graph->SetPoint(36,22.6,21.71173809);
   graph->SetPoint(37,23.2,21.43802752);
   graph->SetPoint(38,23.8,21.22252999);
   graph->SetPoint(39,24.4,21.05247308);
   graph->SetPoint(40,25,20.91136197);
   graph->SetPoint(41,25.6,20.78184851);
   graph->SetPoint(42,26.2,20.64845401);
   graph->SetPoint(43,26.8,20.49924524);
   graph->SetPoint(44,27.4,20.32685134);
   graph->SetPoint(45,28,20.12973171);
   graph->SetPoint(46,28.6,19.91409111);
   graph->SetPoint(47,29.2,19.69577919);
   graph->SetPoint(48,29.8,19.50069706);
   graph->SetPoint(49,30.4,19.36222564);
   graph->SetPoint(50,31,19.31507829);
   graph->SetPoint(51,31.6,19.38644215);
   graph->SetPoint(52,32.2,19.58674926);
   graph->SetPoint(53,32.8,19.90325388);
   graph->SetPoint(54,33.4,20.29922959);
   graph->SetPoint(55,34,20.71990518);
   graph->SetPoint(56,34.6,21.10378036);
   graph->SetPoint(57,35.2,21.39581677);
   graph->SetPoint(58,35.8,21.55828433);
   graph->SetPoint(59,36.4,21.57614445);
   graph->SetPoint(60,37,21.45617153);
   graph->SetPoint(61,37.6,21.2213454);
   graph->SetPoint(62,38.2,20.9033234);
   graph->SetPoint(63,38.8,20.5356773);
   graph->SetPoint(64,39.4,20.14947495);
   graph->SetPoint(65,40,19.77145092);
   graph->SetPoint(66,40.6,19.42402643);
   graph->SetPoint(67,41.2,19.12599409);
   graph->SetPoint(68,41.8,18.89270061);
   graph->SetPoint(69,42.4,18.73494734);
   graph->SetPoint(70,43,18.65655453);
   graph->SetPoint(71,43.6,18.65147967);
   graph->SetPoint(72,44.2,18.7021561);
   graph->SetPoint(73,44.8,18.78076217);
   graph->SetPoint(74,45.4,18.85411201);
   graph->SetPoint(75,46,18.89107955);
   graph->SetPoint(76,46.6,18.86987654);
   graph->SetPoint(77,47.2,18.78215746);
   graph->SetPoint(78,47.8,18.63223609);
   graph->SetPoint(79,48.4,18.4320531);
   graph->SetPoint(80,49,18.19459032);
   graph->SetPoint(81,49.6,17.92897001);
   graph->SetPoint(82,50.2,17.6392128);
   graph->SetPoint(83,50.8,17.32637555);
   graph->SetPoint(84,51.4,16.99192962);
   graph->SetPoint(85,52,16.63982489);
   graph->SetPoint(86,52.6,16.27582055);
   graph->SetPoint(87,53.2,15.90453502);
   graph->SetPoint(88,53.8,15.52612468);
   graph->SetPoint(89,54.4,15.13476526);
   graph->SetPoint(90,55,14.72016076);
   graph->SetPoint(91,55.6,14.27176827);
   graph->SetPoint(92,56.2,13.78413635);
   graph->SetPoint(93,56.8,13.2612855);
   graph->SetPoint(94,57.4,12.71850263);
   graph->SetPoint(95,58,12.18094374);
   graph->SetPoint(96,58.6,11.67953305);
   graph->SetPoint(97,59.2,11.24539015);
   graph->SetPoint(98,59.8,10.90422898);
   graph->SetPoint(99,60.4,10.67191823);
   graph->SetPoint(100,61,10.55188669);
   graph->SetPoint(101,61.6,10.53453223);
   graph->SetPoint(102,62.2,10.59840714);
   graph->SetPoint(103,62.8,10.7127528);
   graph->SetPoint(104,63.4,10.84090579);
   graph->SetPoint(105,64,10.94412346);
   graph->SetPoint(106,64.6,10.985423);
   graph->SetPoint(107,65.2,10.93306891);
   graph->SetPoint(108,65.8,10.76338903);
   graph->SetPoint(109,66.4,10.462665);
   graph->SetPoint(110,67,10.02794221);
   graph->SetPoint(111,67.6,9.466729959);
   graph->SetPoint(112,68.2,8.795696185);
   graph->SetPoint(113,68.8,8.038578186);
   graph->SetPoint(114,69.4,7.223609715);
   graph->SetPoint(115,70,6.380795585);
   graph->SetPoint(116,70,6.380795585);
   graph->SetPoint(117,70.6,6.380795585);
   graph->SetPoint(118,70.6,0);
   
   TH1F *Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13 = new TH1F("Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13","Projection of test_bkg_dimu",119,3.28,76.72);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->SetMinimum(0);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->SetMaximum(48.16318);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->SetDirectory(0);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->SetLineColor(ci);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetXaxis()->SetLabelFont(42);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetXaxis()->SetTitleFont(42);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetYaxis()->SetLabelFont(42);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetYaxis()->SetTitleFont(42);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetZaxis()->SetLabelFont(42);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_test_bkg_dimu_Norm[eventSelectionamassMu]13);
   
   graph->Draw("l");
   
   TH1D *frame_21cd090__6 = new TH1D("frame_21cd090__6","A RooPlot of \"eventSelectionamassMu\"",100,10,70);
   frame_21cd090__6->SetBinContent(1,159.9599);
   frame_21cd090__6->SetMaximum(159.9599);
   frame_21cd090__6->SetEntries(1);
   frame_21cd090__6->SetDirectory(0);
   frame_21cd090__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_21cd090__6->SetLineColor(ci);
   frame_21cd090__6->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_21cd090__6->GetXaxis()->SetLabelFont(42);
   frame_21cd090__6->GetXaxis()->SetLabelSize(0.035);
   frame_21cd090__6->GetXaxis()->SetTitleSize(0.035);
   frame_21cd090__6->GetXaxis()->SetTitleFont(42);
   frame_21cd090__6->GetYaxis()->SetTitle("Events / ( 0.6 )");
   frame_21cd090__6->GetYaxis()->SetLabelFont(42);
   frame_21cd090__6->GetYaxis()->SetLabelSize(0.035);
   frame_21cd090__6->GetYaxis()->SetTitleSize(0.035);
   frame_21cd090__6->GetYaxis()->SetTitleFont(42);
   frame_21cd090__6->GetZaxis()->SetLabelFont(42);
   frame_21cd090__6->GetZaxis()->SetLabelSize(0.035);
   frame_21cd090__6->GetZaxis()->SetTitleSize(0.035);
   frame_21cd090__6->GetZaxis()->SetTitleFont(42);
   frame_21cd090__6->Draw("AXISSAME");
   
   TPaveText *pt = new TPaveText(0.164569,0.94,0.835431,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("A RooPlot of \"eventSelectionamassMu\"");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
