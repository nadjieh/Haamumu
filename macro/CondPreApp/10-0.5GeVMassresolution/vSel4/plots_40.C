{
//=========Macro generated from canvas: c1/c1
//=========  (Wed May 13 15:45:38 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TH1D *frame_82ac870__3 = new TH1D("frame_82ac870__3","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_82ac870__3->SetBinContent(1,5256.482);
   frame_82ac870__3->SetMaximum(5256.482);
   frame_82ac870__3->SetEntries(2);
   frame_82ac870__3->SetDirectory(0);
   frame_82ac870__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_82ac870__3->SetLineColor(ci);
   frame_82ac870__3->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_82ac870__3->GetXaxis()->SetLabelFont(42);
   frame_82ac870__3->GetXaxis()->SetLabelSize(0.035);
   frame_82ac870__3->GetXaxis()->SetTitleSize(0.035);
   frame_82ac870__3->GetXaxis()->SetTitleFont(42);
   frame_82ac870__3->GetYaxis()->SetTitle("Events / ( 0.5 )");
   frame_82ac870__3->GetYaxis()->SetLabelFont(42);
   frame_82ac870__3->GetYaxis()->SetLabelSize(0.035);
   frame_82ac870__3->GetYaxis()->SetTitleSize(0.035);
   frame_82ac870__3->GetYaxis()->SetTitleFont(42);
   frame_82ac870__3->GetZaxis()->SetLabelFont(42);
   frame_82ac870__3->GetZaxis()->SetLabelSize(0.035);
   frame_82ac870__3->GetZaxis()->SetTitleSize(0.035);
   frame_82ac870__3->GetZaxis()->SetTitleFont(42);
   frame_82ac870__3->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100);
   grae->SetName("h_data_dimu40");
   grae->SetTitle("Histogram of data_dimu40_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,20.25,0);
   grae->SetPointError(0,0.25,0.25,0,1.147874);
   grae->SetPoint(1,20.75,0);
   grae->SetPointError(1,0.25,0.25,0,1.147874);
   grae->SetPoint(2,21.25,1);
   grae->SetPointError(2,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(3,21.75,1);
   grae->SetPointError(3,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(4,22.25,1);
   grae->SetPointError(4,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(5,22.75,0);
   grae->SetPointError(5,0.25,0.25,0,1.147874);
   grae->SetPoint(6,23.25,1);
   grae->SetPointError(6,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(7,23.75,2);
   grae->SetPointError(7,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(8,24.25,2);
   grae->SetPointError(8,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(9,24.75,2);
   grae->SetPointError(9,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(10,25.25,6);
   grae->SetPointError(10,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(11,25.75,5);
   grae->SetPointError(11,0.25,0.25,2.159691,3.382473);
   grae->SetPoint(12,26.25,0);
   grae->SetPointError(12,0.25,0.25,0,1.147874);
   grae->SetPoint(13,26.75,2);
   grae->SetPointError(13,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(14,27.25,4);
   grae->SetPointError(14,0.25,0.25,1.914339,3.162753);
   grae->SetPoint(15,27.75,3);
   grae->SetPointError(15,0.25,0.25,1.632705,2.918186);
   grae->SetPoint(16,28.25,2);
   grae->SetPointError(16,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(17,28.75,3);
   grae->SetPointError(17,0.25,0.25,1.632705,2.918186);
   grae->SetPoint(18,29.25,4);
   grae->SetPointError(18,0.25,0.25,1.914339,3.162753);
   grae->SetPoint(19,29.75,6);
   grae->SetPointError(19,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(20,30.25,5);
   grae->SetPointError(20,0.25,0.25,2.159691,3.382473);
   grae->SetPoint(21,30.75,6);
   grae->SetPointError(21,0.25,0.25,2.379931,3.583642);
   grae->SetPoint(22,31.25,10);
   grae->SetPointError(22,0.25,0.25,3.108694,4.26695);
   grae->SetPoint(23,31.75,13);
   grae->SetPointError(23,0.25,0.25,3.558662,4.697573);
   grae->SetPoint(24,32.25,10);
   grae->SetPointError(24,0.25,0.25,3.108694,4.26695);
   grae->SetPoint(25,32.75,5);
   grae->SetPointError(25,0.25,0.25,2.159691,3.382473);
   grae->SetPoint(26,33.25,15);
   grae->SetPointError(26,0.25,0.25,3.82938,4.958738);
   grae->SetPoint(27,33.75,14);
   grae->SetPointError(27,0.25,0.25,3.6965,4.830381);
   grae->SetPoint(28,34.25,22);
   grae->SetPointError(28,0.25,0.25,4.654502,5.761366);
   grae->SetPoint(29,34.75,17);
   grae->SetPointError(29,0.25,0.25,4.082184,5.203719);
   grae->SetPoint(30,35.25,38);
   grae->SetPointError(30,0.25,0.25,6.137163,7.218484);
   grae->SetPoint(31,35.75,40);
   grae->SetPointError(31,0.25,0.25,6.298,7.377261);
   grae->SetPoint(32,36.25,42);
   grae->SetPointError(32,0.25,0.25,6.454831,7.53218);
   grae->SetPoint(33,36.75,55);
   grae->SetPointError(33,0.25,0.25,7.39358,8.461166);
   grae->SetPoint(34,37.25,99);
   grae->SetPointError(34,0.25,0.25,9.933044,10.9834);
   grae->SetPoint(35,37.75,130);
   grae->SetPointError(35,0.25,0.25,10.91271,11.91271);
   grae->SetPoint(36,38.25,228);
   grae->SetPointError(36,0.25,0.25,14.60794,15.60794);
   grae->SetPoint(37,38.75,542);
   grae->SetPointError(37,0.25,0.25,22.78626,23.78626);
   grae->SetPoint(38,39.25,1707);
   grae->SetPointError(38,0.25,0.25,40.81888,41.81888);
   grae->SetPoint(39,39.75,4418);
   grae->SetPointError(39,0.25,0.25,65.96992,66.96992);
   grae->SetPoint(40,40.25,3851);
   grae->SetPointError(40,0.25,0.25,61.55844,62.55844);
   grae->SetPoint(41,40.75,1208);
   grae->SetPointError(41,0.25,0.25,34.25989,35.25989);
   grae->SetPoint(42,41.25,246);
   grae->SetPointError(42,0.25,0.25,15.19235,16.19235);
   grae->SetPoint(43,41.75,59);
   grae->SetPointError(43,0.25,0.25,7.659312,8.724565);
   grae->SetPoint(44,42.25,21);
   grae->SetPointError(44,0.25,0.25,4.545807,5.655182);
   grae->SetPoint(45,42.75,4);
   grae->SetPointError(45,0.25,0.25,1.914339,3.162753);
   grae->SetPoint(46,43.25,2);
   grae->SetPointError(46,0.25,0.25,1.291815,2.63786);
   grae->SetPoint(47,43.75,1);
   grae->SetPointError(47,0.25,0.25,0.8272462,2.299527);
   grae->SetPoint(48,44.25,1);
   grae->SetPointError(48,0.25,0.25,0.8272462,2.299527);
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
   grae->SetPoint(63,51.75,0);
   grae->SetPointError(63,0.25,0.25,0,1.147874);
   grae->SetPoint(64,52.25,1);
   grae->SetPointError(64,0.25,0.25,0.8272462,2.299527);
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
   grae->SetPoint(80,60.25,1);
   grae->SetPointError(80,0.25,0.25,0.8272462,2.299527);
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
   
   TGraph *graph = new TGraph(144);
   graph->SetName("sumDraw_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of Gaussian crystal ball and Voig PDF");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetPoint(0,19.5,0);
   graph->SetPoint(1,19.5,1.048836205);
   graph->SetPoint(2,20,1.048836205);
   graph->SetPoint(3,20.5,1.11287764);
   graph->SetPoint(4,21,1.182613482);
   graph->SetPoint(5,21.5,1.258717116);
   graph->SetPoint(6,22,1.341962395);
   graph->SetPoint(7,22.5,1.433241915);
   graph->SetPoint(8,23,1.533589247);
   graph->SetPoint(9,23.5,1.644206129);
   graph->SetPoint(10,24,1.766495902);
   graph->SetPoint(11,24.5,1.902104895);
   graph->SetPoint(12,25,2.052973947);
   graph->SetPoint(13,25.5,2.221403003);
   graph->SetPoint(14,26,2.410132667);
   graph->SetPoint(15,26.5,2.622447966);
   graph->SetPoint(16,27,2.862311439);
   graph->SetPoint(17,27.5,3.134535354);
   graph->SetPoint(18,28,3.445006616);
   graph->SetPoint(19,28.5,3.800983496);
   graph->SetPoint(20,29,4.211491353);
   graph->SetPoint(21,29.5,4.687856632);
   graph->SetPoint(22,30,5.244436667);
   graph->SetPoint(23,30.5,5.899631073);
   graph->SetPoint(24,31,6.67730477);
   graph->SetPoint(25,31.5,7.608823891);
   graph->SetPoint(26,32,8.736022643);
   graph->SetPoint(27,32.5,10.11561602);
   graph->SetPoint(28,33,11.82591438);
   graph->SetPoint(29,33.5,13.97730568);
   graph->SetPoint(30,34,16.72910097);
   graph->SetPoint(31,34.5,20.31751743);
   graph->SetPoint(32,35,25.1039721);
   graph->SetPoint(33,35.5,31.66222696);
   graph->SetPoint(34,36,40.94415844);
   graph->SetPoint(35,36.5,54.61577267);
   graph->SetPoint(36,37,75.79374754);
   graph->SetPoint(37,37.5,110.8288592);
   graph->SetPoint(38,37.75,137.4763504);
   graph->SetPoint(39,38,174.2977178);
   graph->SetPoint(40,38.25,227.6173677);
   graph->SetPoint(41,38.375,264.6342775);
   graph->SetPoint(42,38.5,313.6482104);
   graph->SetPoint(43,38.625,382.932952);
   graph->SetPoint(44,38.75,483.1642121);
   graph->SetPoint(45,38.8125,548.3229777);
   graph->SetPoint(46,38.875,627.7774824);
   graph->SetPoint(47,38.9375,725.645758);
   graph->SetPoint(48,39,846.6293024);
   graph->SetPoint(49,39.0625,995.7501929);
   graph->SetPoint(50,39.125,1177.923651);
   graph->SetPoint(51,39.1875,1397.364352);
   graph->SetPoint(52,39.25,1656.855051);
   graph->SetPoint(53,39.3125,1956.94242);
   graph->SetPoint(54,39.375,2295.161052);
   graph->SetPoint(55,39.4375,2665.414073);
   graph->SetPoint(56,39.5,3057.648556);
   graph->SetPoint(57,39.625,3849.125894);
   graph->SetPoint(58,39.6875,4211.817501);
   graph->SetPoint(59,39.75,4526.019429);
   graph->SetPoint(60,39.8125,4772.896951);
   graph->SetPoint(61,39.875,4936.649354);
   graph->SetPoint(62,39.9375,5006.173451);
   graph->SetPoint(63,40,4976.282945);
   graph->SetPoint(64,40.0625,4848.29829);
   graph->SetPoint(65,40.125,4629.915275);
   graph->SetPoint(66,40.1875,4334.372227);
   graph->SetPoint(67,40.25,3979.043572);
   graph->SetPoint(68,40.5,2351.874963);
   graph->SetPoint(69,40.5625,1979.51333);
   graph->SetPoint(70,40.625,1644.095004);
   graph->SetPoint(71,40.6875,1350.426663);
   graph->SetPoint(72,40.75,1099.827326);
   graph->SetPoint(73,40.8125,890.8205895);
   graph->SetPoint(74,40.875,719.9376282);
   graph->SetPoint(75,40.9375,582.5103476);
   graph->SetPoint(76,41,473.3655534);
   graph->SetPoint(77,41.0625,387.3680261);
   graph->SetPoint(78,41.125,319.7951582);
   graph->SetPoint(79,41.1875,266.553087);
   graph->SetPoint(80,41.25,224.2617066);
   graph->SetPoint(81,41.375,162.4531868);
   graph->SetPoint(82,41.5,119.9063157);
   graph->SetPoint(83,41.75,65.59328228);
   graph->SetPoint(84,42,34.50477248);
   graph->SetPoint(85,42.5,8.4277288);
   graph->SetPoint(86,43,2.234699278);
   graph->SetPoint(87,43.5,0.9924109413);
   graph->SetPoint(88,44,0.6753962501);
   graph->SetPoint(89,44.5,0.5241481238);
   graph->SetPoint(90,45,0.422810791);
   graph->SetPoint(91,45.5,0.3486795282);
   graph->SetPoint(92,46,0.2925583917);
   graph->SetPoint(93,46.5,0.2490204235);
   graph->SetPoint(94,47,0.2145546616);
   graph->SetPoint(95,47.5,0.1867981719);
   graph->SetPoint(96,48,0.1641119587);
   graph->SetPoint(97,48.5,0.1453296569);
   graph->SetPoint(98,49,0.1296026203);
   graph->SetPoint(99,49.5,0.116301271);
   graph->SetPoint(100,50,0.1049504766);
   graph->SetPoint(101,50.5,0.09518615316);
   graph->SetPoint(102,51,0.08672547536);
   graph->SetPoint(103,51.5,0.07934602015);
   graph->SetPoint(104,52,0.07287090598);
   graph->SetPoint(105,52.5,0.06715803333);
   graph->SetPoint(106,53,0.062092181);
   graph->SetPoint(107,53.5,0.05757912293);
   graph->SetPoint(108,54,0.05354119551);
   graph->SetPoint(109,54.5,0.04991392044);
   graph->SetPoint(110,55,0.04664340498);
   graph->SetPoint(111,55.5,0.04368432164);
   graph->SetPoint(112,56,0.04099832402);
   graph->SetPoint(113,56.5,0.03855279448);
   graph->SetPoint(114,57,0.03631984643);
   graph->SetPoint(115,57.5,0.03427552369);
   graph->SetPoint(116,58,0.03239915365);
   graph->SetPoint(117,58.5,0.03067282142);
   graph->SetPoint(118,59,0.02908093963);
   graph->SetPoint(119,59.5,0.02760989464);
   graph->SetPoint(120,60,0.02624775393);
   graph->SetPoint(121,60.5,0.02498402288);
   graph->SetPoint(122,61,0.02380944173);
   graph->SetPoint(123,61.5,0.02271581508);
   graph->SetPoint(124,62,0.02169586844);
   graph->SetPoint(125,62.5,0.02074312667);
   graph->SetPoint(126,63,0.01985181084);
   graph->SetPoint(127,63.5,0.01901675026);
   graph->SetPoint(128,64,0.01823330727);
   graph->SetPoint(129,64.5,0.01749731253);
   graph->SetPoint(130,65,0.01680500948);
   graph->SetPoint(131,65.5,0.01615300615);
   graph->SetPoint(132,66,0.01553823357);
   graph->SetPoint(133,66.5,0.0149579095);
   graph->SetPoint(134,67,0.01440950689);
   graph->SetPoint(135,67.5,0.01389072626);
   graph->SetPoint(136,68,0.01339947158);
   graph->SetPoint(137,68.5,0.01293382901);
   graph->SetPoint(138,69,0.01249204826);
   graph->SetPoint(139,69.5,0.01207252602);
   graph->SetPoint(140,70,0.01167379148);
   graph->SetPoint(141,70,0.01167379148);
   graph->SetPoint(142,70.5,0.01167379148);
   graph->SetPoint(143,70.5,0);
   graph->Draw("l");
   
   TH1D *frame_82ac870__4 = new TH1D("frame_82ac870__4","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_82ac870__4->SetBinContent(1,5256.482);
   frame_82ac870__4->SetMaximum(5256.482);
   frame_82ac870__4->SetEntries(2);
   frame_82ac870__4->SetDirectory(0);
   frame_82ac870__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_82ac870__4->SetLineColor(ci);
   frame_82ac870__4->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_82ac870__4->GetXaxis()->SetLabelFont(42);
   frame_82ac870__4->GetXaxis()->SetLabelSize(0.035);
   frame_82ac870__4->GetXaxis()->SetTitleSize(0.035);
   frame_82ac870__4->GetXaxis()->SetTitleFont(42);
   frame_82ac870__4->GetYaxis()->SetTitle("Events / ( 0.5 )");
   frame_82ac870__4->GetYaxis()->SetLabelFont(42);
   frame_82ac870__4->GetYaxis()->SetLabelSize(0.035);
   frame_82ac870__4->GetYaxis()->SetTitleSize(0.035);
   frame_82ac870__4->GetYaxis()->SetTitleFont(42);
   frame_82ac870__4->GetZaxis()->SetLabelFont(42);
   frame_82ac870__4->GetZaxis()->SetLabelSize(0.035);
   frame_82ac870__4->GetZaxis()->SetTitleSize(0.035);
   frame_82ac870__4->GetZaxis()->SetTitleFont(42);
   frame_82ac870__4->Draw("AXISSAME");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
