{
//=========Macro generated from canvas: c1_n2/
//=========  (Sun Jan 11 11:48:40 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "",13,34,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TH1D *frame_19b9b10__3 = new TH1D("frame_19b9b10__3","SM",100,10,120);
   frame_19b9b10__3->SetBinContent(1,271.3016);
   frame_19b9b10__3->SetMinimum(-13.00008);
   frame_19b9b10__3->SetMaximum(271.3016);
   frame_19b9b10__3->SetEntries(1);
   frame_19b9b10__3->SetDirectory(0);
   frame_19b9b10__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_19b9b10__3->SetLineColor(ci);
   frame_19b9b10__3->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_19b9b10__3->GetXaxis()->SetLabelFont(42);
   frame_19b9b10__3->GetXaxis()->SetLabelSize(0.035);
   frame_19b9b10__3->GetXaxis()->SetTitleSize(0.035);
   frame_19b9b10__3->GetXaxis()->SetTitleFont(42);
   frame_19b9b10__3->GetYaxis()->SetTitle("Events / ( 2 )");
   frame_19b9b10__3->GetYaxis()->SetLabelFont(42);
   frame_19b9b10__3->GetYaxis()->SetLabelSize(0.035);
   frame_19b9b10__3->GetYaxis()->SetTitleSize(0.035);
   frame_19b9b10__3->GetYaxis()->SetTitleFont(42);
   frame_19b9b10__3->GetZaxis()->SetLabelFont(42);
   frame_19b9b10__3->GetZaxis()->SetLabelSize(0.035);
   frame_19b9b10__3->GetZaxis()->SetTitleSize(0.035);
   frame_19b9b10__3->GetZaxis()->SetTitleFont(42);
   frame_19b9b10__3->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(55);
   grae->SetName("h_data");
   grae->SetTitle("Histogram of data_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,11,108.1497);
   grae->SetPointError(0,1,1,10.3995,10.3995);
   grae->SetPoint(1,13,99.56754);
   grae->SetPointError(1,1,1,9.978354,9.978354);
   grae->SetPoint(2,15,87.59809);
   grae->SetPointError(2,1,1,9.359385,9.359385);
   grae->SetPoint(3,17,50.73723);
   grae->SetPointError(3,1,1,7.123007,7.123007);
   grae->SetPoint(4,19,10.01019);
   grae->SetPointError(4,1,1,3.163888,3.163888);
   grae->SetPoint(5,21,89.90784);
   grae->SetPointError(5,1,1,9.481975,9.481975);
   grae->SetPoint(6,23,84.21545);
   grae->SetPointError(6,1,1,9.176898,9.176898);
   grae->SetPoint(7,25,65.29664);
   grae->SetPointError(7,1,1,8.080634,8.080634);
   grae->SetPoint(8,27,38.88144);
   grae->SetPointError(8,1,1,6.235498,6.235498);
   grae->SetPoint(9,29,40.25997);
   grae->SetPointError(9,1,1,6.345075,6.345075);
   grae->SetPoint(10,31,10.23275);
   grae->SetPointError(10,1,1,3.198868,3.198868);
   grae->SetPoint(11,33,44.65645);
   grae->SetPointError(11,1,1,6.682548,6.682548);
   grae->SetPoint(12,35,48.28322);
   grae->SetPointError(12,1,1,6.948613,6.948613);
   grae->SetPoint(13,37,57.86723);
   grae->SetPointError(13,1,1,7.607051,7.607051);
   grae->SetPoint(14,39,79.44395);
   grae->SetPointError(14,1,1,8.913134,8.913134);
   grae->SetPoint(15,41,24.58332);
   grae->SetPointError(15,1,1,4.958157,4.958157);
   grae->SetPoint(16,43,20.87948);
   grae->SetPointError(16,1,1,4.569407,4.569407);
   grae->SetPoint(17,45,66.52814);
   grae->SetPointError(17,1,1,8.156479,8.156479);
   grae->SetPoint(18,47,64.99706);
   grae->SetPointError(18,1,1,8.062075,8.062075);
   grae->SetPoint(19,49,40.99996);
   grae->SetPointError(19,1,1,6.403121,6.403121);
   grae->SetPoint(20,51,38.56832);
   grae->SetPointError(20,1,1,6.21034,6.21034);
   grae->SetPoint(21,53,27.47079);
   grae->SetPointError(21,1,1,5.241258,5.241258);
   grae->SetPoint(22,55,39.96801);
   grae->SetPointError(22,1,1,6.322026,6.322026);
   grae->SetPoint(23,57,14.63212);
   grae->SetPointError(23,1,1,3.825196,3.825196);
   grae->SetPoint(24,59,25.35553);
   grae->SetPointError(24,1,1,5.035428,5.035428);
   grae->SetPoint(25,61,24.36665);
   grae->SetPointError(25,1,1,4.936259,4.936259);
   grae->SetPoint(26,63,24.65531);
   grae->SetPointError(26,1,1,4.965411,4.965411);
   grae->SetPoint(27,65,37.01222);
   grae->SetPointError(27,1,1,6.083767,6.083767);
   grae->SetPoint(28,67,31.88676);
   grae->SetPointError(28,1,1,5.646837,5.646837);
   grae->SetPoint(29,69,34.90722);
   grae->SetPointError(29,1,1,5.908234,5.908234);
   grae->SetPoint(30,71,26.80531);
   grae->SetPointError(30,1,1,5.177384,5.177384);
   grae->SetPoint(31,73,29.75622);
   grae->SetPointError(31,1,1,5.454927,5.454927);
   grae->SetPoint(32,75,32.35656);
   grae->SetPointError(32,1,1,5.688282,5.688282);
   grae->SetPoint(33,77,31.9339);
   grae->SetPointError(33,1,1,5.651008,5.651008);
   grae->SetPoint(34,79,56.01997);
   grae->SetPointError(34,1,1,7.484649,7.484649);
   grae->SetPoint(35,81,33.56815);
   grae->SetPointError(35,1,1,5.793803,5.793803);
   grae->SetPoint(36,83,27.95322);
   grae->SetPointError(36,1,1,5.287081,5.287081);
   grae->SetPoint(37,85,48.82315);
   grae->SetPointError(37,1,1,6.987357,6.987357);
   grae->SetPoint(38,87,117.4653);
   grae->SetPointError(38,1,1,10.83814,10.83814);
   grae->SetPoint(39,89,179.3943);
   grae->SetPointError(39,1,1,13.39382,13.39382);
   grae->SetPoint(40,91,242.7969);
   grae->SetPointError(40,1,1,15.58194,15.58194);
   grae->SetPoint(41,93,110.4298);
   grae->SetPointError(41,1,1,10.50856,10.50856);
   grae->SetPoint(42,95,20.34807);
   grae->SetPointError(42,1,1,4.510883,4.510883);
   grae->SetPoint(43,97,1.736884);
   grae->SetPointError(43,1,1,1.317909,1.317909);
   grae->SetPoint(44,99,0.007123238);
   grae->SetPointError(44,1,1,0.08439928,0.08439928);
   grae->SetPoint(45,101,2.692953);
   grae->SetPointError(45,1,1,1.641022,1.641022);
   grae->SetPoint(46,103,0);
   grae->SetPointError(46,1,1,0,0);
   grae->SetPoint(47,105,0);
   grae->SetPointError(47,1,1,0,0);
   grae->SetPoint(48,107,0);
   grae->SetPointError(48,1,1,0,0);
   grae->SetPoint(49,109,0);
   grae->SetPointError(49,1,1,0,0);
   grae->SetPoint(50,111,0);
   grae->SetPointError(50,1,1,0,0);
   grae->SetPoint(51,113,0);
   grae->SetPointError(51,1,1,0,0);
   grae->SetPoint(52,115,0);
   grae->SetPointError(52,1,1,0,0);
   grae->SetPoint(53,117,0);
   grae->SetPointError(53,1,1,0,0);
   grae->SetPoint(54,119,0);
   grae->SetPointError(54,1,1,0,0);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(117);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,23.63802154);
   graph->SetPoint(1,30.2,23.86744428);
   graph->SetPoint(2,30.4,24.09644592);
   graph->SetPoint(3,30.6,24.3322155);
   graph->SetPoint(4,30.8,24.57007063);
   graph->SetPoint(5,31,24.81119874);
   graph->SetPoint(6,31.2,25.05685165);
   graph->SetPoint(7,31.4,25.30820054);
   graph->SetPoint(8,31.6,25.59134476);
   graph->SetPoint(9,31.8,25.89999205);
   graph->SetPoint(10,32,26.22817232);
   graph->SetPoint(11,32.2,26.57633776);
   graph->SetPoint(12,32.4,26.94474277);
   graph->SetPoint(13,32.6,27.37987595);
   graph->SetPoint(14,32.8,28.0149325);
   graph->SetPoint(15,33,28.73369718);
   graph->SetPoint(16,33.2,29.53477726);
   graph->SetPoint(17,33.4,30.41649643);
   graph->SetPoint(18,33.6,31.37692162);
   graph->SetPoint(19,33.65,31.62911542);
   graph->SetPoint(20,33.7,32.1139063);
   graph->SetPoint(21,33.8,33.15712391);
   graph->SetPoint(22,33.9,34.29815941);
   graph->SetPoint(23,34,35.53659239);
   graph->SetPoint(24,34.1,36.87199236);
   graph->SetPoint(25,34.2,38.30418236);
   graph->SetPoint(26,34.3,39.83284288);
   graph->SetPoint(27,34.4,41.45765695);
   graph->SetPoint(28,34.5,43.17831232);
   graph->SetPoint(29,34.6,44.99450353);
   graph->SetPoint(30,34.7,46.90593382);
   graph->SetPoint(31,34.75,47.8973589);
   graph->SetPoint(32,34.8,48.32239673);
   graph->SetPoint(33,34.9,49.08972623);
   graph->SetPoint(34,35,49.74628552);
   graph->SetPoint(35,35.1,50.29150744);
   graph->SetPoint(36,35.2,50.72513258);
   graph->SetPoint(37,35.3,51.04726307);
   graph->SetPoint(38,35.4,51.25771843);
   graph->SetPoint(39,35.5,51.35633904);
   graph->SetPoint(40,35.6,51.34298698);
   graph->SetPoint(41,35.7,51.21754667);
   graph->SetPoint(42,35.8,50.97992547);
   graph->SetPoint(43,35.85,50.81908779);
   graph->SetPoint(44,35.9,50.89627869);
   graph->SetPoint(45,36,51.03601082);
   graph->SetPoint(46,36.2,51.25586621);
   graph->SetPoint(47,36.4,51.39600997);
   graph->SetPoint(48,36.6,51.45809129);
   graph->SetPoint(49,36.8,51.44310078);
   graph->SetPoint(50,37,51.38124865);
   graph->SetPoint(51,37.2,51.35702787);
   graph->SetPoint(52,37.4,51.30023513);
   graph->SetPoint(53,37.6,51.21430375);
   graph->SetPoint(54,37.8,51.10214176);
   graph->SetPoint(55,38,50.96673523);
   graph->SetPoint(56,38.2,50.82929583);
   graph->SetPoint(57,38.4,50.68779213);
   graph->SetPoint(58,38.6,50.54080658);
   graph->SetPoint(59,38.8,50.39182109);
   graph->SetPoint(60,39,50.24405013);
   graph->SetPoint(61,39.2,50.10228076);
   graph->SetPoint(62,39.4,49.97432507);
   graph->SetPoint(63,39.6,49.85924429);
   graph->SetPoint(64,39.8,49.75853583);
   graph->SetPoint(65,40,49.67384271);
   graph->SetPoint(66,40.2,49.60640485);
   graph->SetPoint(67,40.4,49.55938733);
   graph->SetPoint(68,40.6,49.53305401);
   graph->SetPoint(69,40.8,49.52657587);
   graph->SetPoint(70,41,49.53888039);
   graph->SetPoint(71,41.2,49.5690867);
   graph->SetPoint(72,41.4,49.61637313);
   graph->SetPoint(73,41.6,49.68040578);
   graph->SetPoint(74,41.8,49.75921848);
   graph->SetPoint(75,42,49.85019356);
   graph->SetPoint(76,42.2,49.95147925);
   graph->SetPoint(77,42.4,50.06120441);
   graph->SetPoint(78,42.6,50.17819081);
   graph->SetPoint(79,42.8,50.30056404);
   graph->SetPoint(80,43,50.42622979);
   graph->SetPoint(81,43.2,50.55352296);
   graph->SetPoint(82,43.4,50.68100618);
   graph->SetPoint(83,43.6,50.80750252);
   graph->SetPoint(84,43.8,50.93217158);
   graph->SetPoint(85,44,51.05344079);
   graph->SetPoint(86,44.2,51.17050106);
   graph->SetPoint(87,44.4,51.28254196);
   graph->SetPoint(88,44.6,51.38885033);
   graph->SetPoint(89,44.8,51.48910583);
   graph->SetPoint(90,45,51.58236418);
   graph->SetPoint(91,45.2,51.66826063);
   graph->SetPoint(92,45.4,51.74655164);
   graph->SetPoint(93,45.6,51.81697867);
   graph->SetPoint(94,45.8,51.87944764);
   graph->SetPoint(95,46,51.93395436);
   graph->SetPoint(96,46.2,51.98017263);
   graph->SetPoint(97,46.4,52.01859343);
   graph->SetPoint(98,46.6,52.04947234);
   graph->SetPoint(99,46.8,52.07315976);
   graph->SetPoint(100,47,52.09028842);
   graph->SetPoint(101,47.2,52.10102096);
   graph->SetPoint(102,47.4,52.10618198);
   graph->SetPoint(103,47.6,52.10643672);
   graph->SetPoint(104,47.8,52.10240461);
   graph->SetPoint(105,48,52.09474634);
   graph->SetPoint(106,48.2,52.08411684);
   graph->SetPoint(107,48.4,52.07089849);
   graph->SetPoint(108,48.6,52.05562655);
   graph->SetPoint(109,48.8,52.03861283);
   graph->SetPoint(110,49,52.02005667);
   graph->SetPoint(111,49.2,52.0002052);
   graph->SetPoint(112,49.4,51.97884155);
   graph->SetPoint(113,49.6,51.9558453);
   graph->SetPoint(114,49.8,51.93093744);
   graph->SetPoint(115,50,51.90374978);
   graph->SetPoint(116,50,51.90374978);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_expo_pf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,0.0001936204421);
   graph->SetPoint(1,30.2,0.0001870053973);
   graph->SetPoint(2,30.4,0.0001806163556);
   graph->SetPoint(3,30.6,0.0001744455956);
   graph->SetPoint(4,30.8,0.0001684856597);
   graph->SetPoint(5,31,0.0001627293451);
   graph->SetPoint(6,31.2,0.0001571696951);
   graph->SetPoint(7,31.4,0.0001517999905);
   graph->SetPoint(8,31.6,0.000146613742);
   graph->SetPoint(9,31.8,0.0001416046817);
   graph->SetPoint(10,32,0.000136766756);
   graph->SetPoint(11,32.2,0.0001320941181);
   graph->SetPoint(12,32.4,0.000127581121);
   graph->SetPoint(13,32.6,0.0001232223104);
   graph->SetPoint(14,32.8,0.0001190124187);
   graph->SetPoint(15,33,0.000114946358);
   graph->SetPoint(16,33.2,0.0001110192142);
   graph->SetPoint(17,33.4,0.0001072262414);
   graph->SetPoint(18,33.6,0.0001035628556);
   graph->SetPoint(19,33.8,0.0001000246294);
   graph->SetPoint(20,34,9.660728669e-05);
   graph->SetPoint(21,34.2,9.330669756e-05);
   graph->SetPoint(22,34.4,9.01188731e-05);
   graph->SetPoint(23,34.6,8.703996071e-05);
   graph->SetPoint(24,34.8,8.406623939e-05);
   graph->SetPoint(25,35,8.11941153e-05);
   graph->SetPoint(26,35.2,7.842011736e-05);
   graph->SetPoint(27,35.4,7.574089309e-05);
   graph->SetPoint(28,35.6,7.315320456e-05);
   graph->SetPoint(29,35.8,7.065392443e-05);
   graph->SetPoint(30,36,6.824003224e-05);
   graph->SetPoint(31,36.2,6.590861071e-05);
   graph->SetPoint(32,36.4,6.365684222e-05);
   graph->SetPoint(33,36.6,6.148200543e-05);
   graph->SetPoint(34,36.8,5.938147197e-05);
   graph->SetPoint(35,37,5.735270326e-05);
   graph->SetPoint(36,37.2,5.539324745e-05);
   graph->SetPoint(37,37.4,5.350073648e-05);
   graph->SetPoint(38,37.6,5.167288316e-05);
   graph->SetPoint(39,37.8,4.990747848e-05);
   graph->SetPoint(40,38,4.820238887e-05);
   graph->SetPoint(41,38.2,4.655555367e-05);
   graph->SetPoint(42,38.4,4.496498261e-05);
   graph->SetPoint(43,38.6,4.342875343e-05);
   graph->SetPoint(44,38.8,4.194500954e-05);
   graph->SetPoint(45,39,4.051195778e-05);
   graph->SetPoint(46,39.2,3.912786625e-05);
   graph->SetPoint(47,39.4,3.779106222e-05);
   graph->SetPoint(48,39.6,3.649993012e-05);
   graph->SetPoint(49,39.8,3.525290956e-05);
   graph->SetPoint(50,40,3.404849348e-05);
   graph->SetPoint(51,40.2,3.288522628e-05);
   graph->SetPoint(52,40.4,3.176170213e-05);
   graph->SetPoint(53,40.6,3.067656319e-05);
   graph->SetPoint(54,40.8,2.962849803e-05);
   graph->SetPoint(55,41,2.861624003e-05);
   graph->SetPoint(56,41.2,2.763856585e-05);
   graph->SetPoint(57,41.4,2.669429391e-05);
   graph->SetPoint(58,41.6,2.578228303e-05);
   graph->SetPoint(59,41.8,2.490143102e-05);
   graph->SetPoint(60,42,2.405067332e-05);
   graph->SetPoint(61,42.2,2.322898177e-05);
   graph->SetPoint(62,42.4,2.243536333e-05);
   graph->SetPoint(63,42.6,2.166885887e-05);
   graph->SetPoint(64,42.8,2.092854204e-05);
   graph->SetPoint(65,43,2.021351815e-05);
   graph->SetPoint(66,43.2,1.952292305e-05);
   graph->SetPoint(67,43.4,1.885592215e-05);
   graph->SetPoint(68,43.6,1.821170934e-05);
   graph->SetPoint(69,43.8,1.758950607e-05);
   graph->SetPoint(70,44,1.698856038e-05);
   graph->SetPoint(71,44.2,1.640814601e-05);
   graph->SetPoint(72,44.4,1.58475615e-05);
   graph->SetPoint(73,44.6,1.530612937e-05);
   graph->SetPoint(74,44.8,1.478319527e-05);
   graph->SetPoint(75,45,1.427812722e-05);
   graph->SetPoint(76,45.2,1.379031483e-05);
   graph->SetPoint(77,45.4,1.331916856e-05);
   graph->SetPoint(78,45.6,1.2864119e-05);
   graph->SetPoint(79,45.8,1.242461622e-05);
   graph->SetPoint(80,46,1.200012906e-05);
   graph->SetPoint(81,46.2,1.15901445e-05);
   graph->SetPoint(82,46.4,1.119416707e-05);
   graph->SetPoint(83,46.6,1.081171822e-05);
   graph->SetPoint(84,46.8,1.044233573e-05);
   graph->SetPoint(85,47,1.008557321e-05);
   graph->SetPoint(86,47.2,9.740999474e-06);
   graph->SetPoint(87,47.4,9.408198109e-06);
   graph->SetPoint(88,47.6,9.086766906e-06);
   graph->SetPoint(89,47.8,8.776317404e-06);
   graph->SetPoint(90,48,8.476474413e-06);
   graph->SetPoint(91,48.2,8.186875561e-06);
   graph->SetPoint(92,48.4,7.907170858e-06);
   graph->SetPoint(93,48.6,7.637022269e-06);
   graph->SetPoint(94,48.8,7.37610331e-06);
   graph->SetPoint(95,49,7.124098651e-06);
   graph->SetPoint(96,49.2,6.880703734e-06);
   graph->SetPoint(97,49.4,6.645624407e-06);
   graph->SetPoint(98,49.6,6.418576568e-06);
   graph->SetPoint(99,49.8,6.199285821e-06);
   graph->SetPoint(100,50,5.987487146e-06);
   graph->SetPoint(101,50,5.987487146e-06);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_toppdf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,22.55403448);
   graph->SetPoint(1,30.2,22.73713226);
   graph->SetPoint(2,30.4,22.91487696);
   graph->SetPoint(3,30.6,23.08803852);
   graph->SetPoint(4,30.8,23.25747832);
   graph->SetPoint(5,31,23.42438381);
   graph->SetPoint(6,31.2,23.59000681);
   graph->SetPoint(7,31.4,23.75551851);
   graph->SetPoint(8,31.6,23.92204517);
   graph->SetPoint(9,31.8,24.09061997);
   graph->SetPoint(10,32,24.26226531);
   graph->SetPoint(11,32.2,24.43743338);
   graph->SetPoint(12,32.4,24.61637858);
   graph->SetPoint(13,32.6,24.79901575);
   graph->SetPoint(14,32.8,24.98489362);
   graph->SetPoint(15,33,25.17321892);
   graph->SetPoint(16,33.2,25.36259892);
   graph->SetPoint(17,33.4,25.55135731);
   graph->SetPoint(18,33.6,25.73756102);
   graph->SetPoint(19,33.8,25.91902355);
   graph->SetPoint(20,34,26.09325622);
   graph->SetPoint(21,34.2,26.25722644);
   graph->SetPoint(22,34.4,26.40869736);
   graph->SetPoint(23,34.6,26.54515636);
   graph->SetPoint(24,34.8,26.66419842);
   graph->SetPoint(25,35,26.76358739);
   graph->SetPoint(26,35.2,26.84030947);
   graph->SetPoint(27,35.4,26.89314518);
   graph->SetPoint(28,35.6,26.92103843);
   graph->SetPoint(29,35.8,26.92297646);
   graph->SetPoint(30,36,26.89831276);
   graph->SetPoint(31,36.2,26.84632005);
   graph->SetPoint(32,36.4,26.76659122);
   graph->SetPoint(33,36.6,26.66077547);
   graph->SetPoint(34,36.8,26.52986341);
   graph->SetPoint(35,37,26.3752273);
   graph->SetPoint(36,37.2,26.1986077);
   graph->SetPoint(37,37.4,26.00126928);
   graph->SetPoint(38,37.6,25.78664539);
   graph->SetPoint(39,37.8,25.55764403);
   graph->SetPoint(40,38,25.31725128);
   graph->SetPoint(41,38.2,25.06863414);
   graph->SetPoint(42,38.4,24.81505428);
   graph->SetPoint(43,38.6,24.56014667);
   graph->SetPoint(44,38.8,24.30739321);
   graph->SetPoint(45,39,24.06000839);
   graph->SetPoint(46,39.2,23.82103332);
   graph->SetPoint(47,39.4,23.59327008);
   graph->SetPoint(48,39.6,23.38010673);
   graph->SetPoint(49,39.8,23.1830407);
   graph->SetPoint(50,40,23.00371499);
   graph->SetPoint(51,40.2,22.84336954);
   graph->SetPoint(52,40.4,22.70280636);
   graph->SetPoint(53,40.6,22.58298246);
   graph->SetPoint(54,40.8,22.48373049);
   graph->SetPoint(55,41,22.40397794);
   graph->SetPoint(56,41.2,22.34284393);
   graph->SetPoint(57,41.4,22.2991465);
   graph->SetPoint(58,41.6,22.27151781);
   graph->SetPoint(59,41.8,22.25888464);
   graph->SetPoint(60,42,22.25862931);
   graph->SetPoint(61,42.2,22.26890005);
   graph->SetPoint(62,42.4,22.28782572);
   graph->SetPoint(63,42.6,22.31355869);
   graph->SetPoint(64,42.8,22.3444209);
   graph->SetPoint(65,43,22.37850547);
   graph->SetPoint(66,43.2,22.41414731);
   graph->SetPoint(67,43.4,22.44990904);
   graph->SetPoint(68,43.6,22.48448268);
   graph->SetPoint(69,43.8,22.51665166);
   graph->SetPoint(70,44,22.54516826);
   graph->SetPoint(71,44.2,22.5692234);
   graph->SetPoint(72,44.4,22.58800666);
   graph->SetPoint(73,44.6,22.60080486);
   graph->SetPoint(74,44.8,22.60699565);
   graph->SetPoint(75,45,22.60572335);
   graph->SetPoint(76,45.2,22.59670776);
   graph->SetPoint(77,45.4,22.57970535);
   graph->SetPoint(78,45.6,22.55445758);
   graph->SetPoint(79,45.8,22.52079866);
   graph->SetPoint(80,46,22.47851863);
   graph->SetPoint(81,46.2,22.427469);
   graph->SetPoint(82,46.4,22.36814075);
   graph->SetPoint(83,46.6,22.30078945);
   graph->SetPoint(84,46.8,22.22576552);
   graph->SetPoint(85,47,22.14350544);
   graph->SetPoint(86,47.2,22.05422943);
   graph->SetPoint(87,47.4,21.95881702);
   graph->SetPoint(88,47.6,21.85793345);
   graph->SetPoint(89,47.8,21.75219817);
   graph->SetPoint(90,48,21.6422178);
   graph->SetPoint(91,48.2,21.52849217);
   graph->SetPoint(92,48.4,21.41153762);
   graph->SetPoint(93,48.6,21.29188941);
   graph->SetPoint(94,48.8,21.16985934);
   graph->SetPoint(95,49,21.04564677);
   graph->SetPoint(96,49.2,20.91933165);
   graph->SetPoint(97,49.4,20.79074615);
   graph->SetPoint(98,49.6,20.65981667);
   graph->SetPoint(99,49.8,20.52626417);
   graph->SetPoint(100,50,20.38972049);
   graph->SetPoint(101,50,20.38972049);
   graph->Draw("l");
   
   graph = new TGraph(117);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_bwxCryBall_pf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,1.08379344);
   graph->SetPoint(1,30.2,1.13012501);
   graph->SetPoint(2,30.4,1.181388338);
   graph->SetPoint(3,30.6,1.244002534);
   graph->SetPoint(4,30.8,1.312423822);
   graph->SetPoint(5,31,1.386652201);
   graph->SetPoint(6,31.2,1.466687672);
   graph->SetPoint(7,31.4,1.552530233);
   graph->SetPoint(8,31.6,1.66915298);
   graph->SetPoint(9,31.8,1.809230471);
   graph->SetPoint(10,32,1.96577024);
   graph->SetPoint(11,32.2,2.138772288);
   graph->SetPoint(12,32.4,2.328236613);
   graph->SetPoint(13,32.6,2.580736985);
   graph->SetPoint(14,32.8,3.029919866);
   graph->SetPoint(15,33,3.560363312);
   graph->SetPoint(16,33.2,4.172067321);
   graph->SetPoint(17,33.4,4.865031893);
   graph->SetPoint(18,33.6,5.63925703);
   graph->SetPoint(19,33.65,5.845510277);
   graph->SetPoint(20,33.7,6.284774641);
   graph->SetPoint(21,33.8,7.238000332);
   graph->SetPoint(22,33.9,8.290821975);
   graph->SetPoint(23,34,9.443239569);
   graph->SetPoint(24,34.1,10.69525312);
   graph->SetPoint(25,34.2,12.04686261);
   graph->SetPoint(26,34.3,13.49806806);
   graph->SetPoint(27,34.4,15.04886947);
   graph->SetPoint(28,34.5,16.69926682);
   graph->SetPoint(29,34.6,18.44926012);
   graph->SetPoint(30,34.7,20.29884938);
   graph->SetPoint(31,34.75,21.26099249);
   graph->SetPoint(32,34.8,21.65811425);
   graph->SetPoint(33,34.9,22.37316246);
   graph->SetPoint(34,35,22.98261693);
   graph->SetPoint(35,35.1,23.48647767);
   graph->SetPoint(36,35.2,23.88474469);
   graph->SetPoint(37,35.3,24.17741796);
   graph->SetPoint(38,35.4,24.36449751);
   graph->SetPoint(39,35.5,24.44598332);
   graph->SetPoint(40,35.6,24.4218754);
   graph->SetPoint(41,35.7,24.29217374);
   graph->SetPoint(42,35.8,24.05687835);
   graph->SetPoint(43,35.85,23.89963301);
   graph->SetPoint(44,35.9,23.98221375);
   graph->SetPoint(45,36,24.13762982);
   graph->SetPoint(46,36.2,24.40948025);
   graph->SetPoint(47,36.4,24.62935509);
   graph->SetPoint(48,36.6,24.79725434);
   graph->SetPoint(49,36.8,24.91317798);
   graph->SetPoint(50,37,25.00596399);
   graph->SetPoint(51,37.2,25.15836477);
   graph->SetPoint(52,37.4,25.29891234);
   graph->SetPoint(53,37.6,25.42760669);
   graph->SetPoint(54,37.8,25.54444783);
   graph->SetPoint(55,38,25.64943574);
   graph->SetPoint(56,38.2,25.76061513);
   graph->SetPoint(57,38.4,25.87269288);
   graph->SetPoint(58,38.6,25.98061648);
   graph->SetPoint(59,38.8,26.08438593);
   graph->SetPoint(60,39,26.18400123);
   graph->SetPoint(61,39.2,26.2812083);
   graph->SetPoint(62,39.4,26.3810172);
   graph->SetPoint(63,39.6,26.47910106);
   graph->SetPoint(64,39.8,26.57545988);
   graph->SetPoint(65,40,26.67009367);
   graph->SetPoint(66,40.2,26.76300242);
   graph->SetPoint(67,40.4,26.85654921);
   graph->SetPoint(68,40.6,26.95004087);
   graph->SetPoint(69,40.8,27.04281575);
   graph->SetPoint(70,41,27.13487383);
   graph->SetPoint(71,41.2,27.22621513);
   graph->SetPoint(72,41.4,27.31719994);
   graph->SetPoint(73,41.6,27.40886219);
   graph->SetPoint(74,41.8,27.50030895);
   graph->SetPoint(75,42,27.59154021);
   graph->SetPoint(76,42.2,27.68255598);
   graph->SetPoint(77,42.4,27.77335625);
   graph->SetPoint(78,42.6,27.86461045);
   graph->SetPoint(79,42.8,27.95612222);
   graph->SetPoint(80,43,28.04770411);
   graph->SetPoint(81,43.2,28.13935613);
   graph->SetPoint(82,43.4,28.23107828);
   graph->SetPoint(83,43.6,28.32300163);
   graph->SetPoint(84,43.8,28.41550234);
   graph->SetPoint(85,44,28.50825555);
   graph->SetPoint(86,44.2,28.60126125);
   graph->SetPoint(87,44.4,28.69451946);
   graph->SetPoint(88,44.6,28.78803016);
   graph->SetPoint(89,44.8,28.88209539);
   graph->SetPoint(90,45,28.97662656);
   graph->SetPoint(91,45.2,29.07153908);
   graph->SetPoint(92,45.4,29.16683297);
   graph->SetPoint(93,45.6,29.26250822);
   graph->SetPoint(94,45.8,29.35863655);
   graph->SetPoint(95,46,29.45542373);
   graph->SetPoint(96,46.2,29.55269204);
   graph->SetPoint(97,46.4,29.65044149);
   graph->SetPoint(98,46.6,29.74867208);
   graph->SetPoint(99,46.8,29.8473838);
   graph->SetPoint(100,47,29.94677289);
   graph->SetPoint(101,47.2,30.04678179);
   graph->SetPoint(102,47.4,30.14735555);
   graph->SetPoint(103,47.6,30.24849418);
   graph->SetPoint(104,47.8,30.35019767);
   graph->SetPoint(105,48,30.45252007);
   graph->SetPoint(106,48.2,30.55561648);
   graph->SetPoint(107,48.4,30.65935296);
   graph->SetPoint(108,48.6,30.76372951);
   graph->SetPoint(109,48.8,30.86874611);
   graph->SetPoint(110,49,30.97440278);
   graph->SetPoint(111,49.2,31.08086667);
   graph->SetPoint(112,49.4,31.18808875);
   graph->SetPoint(113,49.6,31.29602222);
   graph->SetPoint(114,49.8,31.40466706);
   graph->SetPoint(115,50,31.5140233);
   graph->SetPoint(116,50,31.5140233);
   graph->Draw("l");
   
   TPaveText *pt = new TPaveText(6.918927e-310,0,0,6.918928e-310,"BRNDC");
   pt->SetName("test_sum_pf_paramBox");
   pt->SetBorderSize(1);
   pt->SetFillColor(0);
   pt->SetTextAlign(12);
   pt->SetTextSize(0.04);
   TText *text = pt->AddText("test_signal_bw_pf =  0.84 +/- 0.04");
   pt->Draw();
   
   TH1D *frame_19b9b10__4 = new TH1D("frame_19b9b10__4","SM",100,10,120);
   frame_19b9b10__4->SetBinContent(1,271.3016);
   frame_19b9b10__4->SetMinimum(-13.00008);
   frame_19b9b10__4->SetMaximum(271.3016);
   frame_19b9b10__4->SetEntries(1);
   frame_19b9b10__4->SetDirectory(0);
   frame_19b9b10__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_19b9b10__4->SetLineColor(ci);
   frame_19b9b10__4->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_19b9b10__4->GetXaxis()->SetLabelFont(42);
   frame_19b9b10__4->GetXaxis()->SetLabelSize(0.035);
   frame_19b9b10__4->GetXaxis()->SetTitleSize(0.035);
   frame_19b9b10__4->GetXaxis()->SetTitleFont(42);
   frame_19b9b10__4->GetYaxis()->SetTitle("Events / ( 2 )");
   frame_19b9b10__4->GetYaxis()->SetLabelFont(42);
   frame_19b9b10__4->GetYaxis()->SetLabelSize(0.035);
   frame_19b9b10__4->GetYaxis()->SetTitleSize(0.035);
   frame_19b9b10__4->GetYaxis()->SetTitleFont(42);
   frame_19b9b10__4->GetZaxis()->SetLabelFont(42);
   frame_19b9b10__4->GetZaxis()->SetLabelSize(0.035);
   frame_19b9b10__4->GetZaxis()->SetTitleSize(0.035);
   frame_19b9b10__4->GetZaxis()->SetTitleFont(42);
   frame_19b9b10__4->Draw("AXISSAME");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
