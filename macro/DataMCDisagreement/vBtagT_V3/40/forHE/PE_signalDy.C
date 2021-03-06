{
//=========Macro generated from canvas: c1/
//=========  (Thu Jan 22 15:40:22 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TH1D *frame_28dba10__5 = new TH1D("frame_28dba10__5","SM",100,10,120);
   frame_28dba10__5->SetBinContent(1,374.0417);
   frame_28dba10__5->SetMinimum(-18.34233);
   frame_28dba10__5->SetMaximum(374.0417);
   frame_28dba10__5->SetEntries(1);
   frame_28dba10__5->SetDirectory(0);
   frame_28dba10__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_28dba10__5->SetLineColor(ci);
   frame_28dba10__5->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_28dba10__5->GetXaxis()->SetLabelFont(42);
   frame_28dba10__5->GetXaxis()->SetLabelSize(0.035);
   frame_28dba10__5->GetXaxis()->SetTitleSize(0.035);
   frame_28dba10__5->GetXaxis()->SetTitleFont(42);
   frame_28dba10__5->GetYaxis()->SetTitle("Events / ( 2 )");
   frame_28dba10__5->GetYaxis()->SetLabelFont(42);
   frame_28dba10__5->GetYaxis()->SetLabelSize(0.035);
   frame_28dba10__5->GetYaxis()->SetTitleSize(0.035);
   frame_28dba10__5->GetYaxis()->SetTitleFont(42);
   frame_28dba10__5->GetZaxis()->SetLabelFont(42);
   frame_28dba10__5->GetZaxis()->SetLabelSize(0.035);
   frame_28dba10__5->GetZaxis()->SetTitleSize(0.035);
   frame_28dba10__5->GetZaxis()->SetTitleFont(42);
   frame_28dba10__5->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(55);
   grae->SetName("h_data");
   grae->SetTitle("Histogram of data_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,11,178.9506);
   grae->SetPointError(0,1,1,37.90183,37.90183);
   grae->SetPoint(1,13,158.8987);
   grae->SetPointError(1,1,1,35.64227,35.64227);
   grae->SetPoint(2,15,119.017);
   grae->SetPointError(2,1,1,30.7305,30.7305);
   grae->SetPoint(3,17,63.14054);
   grae->SetPointError(3,1,1,21.73955,21.73955);
   grae->SetPoint(4,19,33.99279);
   grae->SetPointError(4,1,1,15.84207,15.84207);
   grae->SetPoint(5,21,110.02);
   grae->SetPointError(5,1,1,29.42629,29.42629);
   grae->SetPoint(6,23,101.6865);
   grae->SetPointError(6,1,1,28.13418,28.13418);
   grae->SetPoint(7,25,80.05356);
   grae->SetPointError(7,1,1,24.65364,24.65364);
   grae->SetPoint(8,27,51.46426);
   grae->SetPointError(8,1,1,19.73133,19.73133);
   grae->SetPoint(9,29,52.52863);
   grae->SetPointError(9,1,1,18.39124,18.39124);
   grae->SetPoint(10,31,43.01888);
   grae->SetPointError(10,1,1,17.8771,17.8771);
   grae->SetPoint(11,33,62.87487);
   grae->SetPointError(11,1,1,21.0918,21.0918);
   grae->SetPoint(12,35,62.05833);
   grae->SetPointError(12,1,1,21.1618,21.1618);
   grae->SetPoint(13,37,75.19132);
   grae->SetPointError(13,1,1,23.4451,23.4451);
   grae->SetPoint(14,39,100.4555);
   grae->SetPointError(14,1,1,26.58554,26.58554);
   grae->SetPoint(15,41,90);
   grae->SetPointError(15,1,1,25,25);
   grae->SetPoint(16,43,84);
   grae->SetPointError(16,1,1,24,24);
   grae->SetPoint(17,45,83.8799);
   grae->SetPointError(17,1,1,24.06009,24.06009);
   grae->SetPoint(18,47,79.01791);
   grae->SetPointError(18,1,1,24.24754,24.24754);
   grae->SetPoint(19,49,55.93753);
   grae->SetPointError(19,1,1,16.84988,16.84988);
   grae->SetPoint(20,51,55.10165);
   grae->SetPointError(20,1,1,11.09978,11.09978);
   grae->SetPoint(21,53,39.12961);
   grae->SetPointError(21,1,1,9.360424,9.360424);
   grae->SetPoint(22,55,66.13436);
   grae->SetPointError(22,1,1,12.30582,12.30582);
   grae->SetPoint(23,57,22.89739);
   grae->SetPointError(23,1,1,6.939594,6.939594);
   grae->SetPoint(24,59,37.87001);
   grae->SetPointError(24,1,1,9.167624,9.167624);
   grae->SetPoint(25,61,35.98163);
   grae->SetPointError(25,1,1,8.998375,8.998375);
   grae->SetPoint(26,63,38.85435);
   grae->SetPointError(26,1,1,9.409573,9.409573);
   grae->SetPoint(27,65,54.91222);
   grae->SetPointError(27,1,1,11.27309,11.27309);
   grae->SetPoint(28,67,42.7378);
   grae->SetPointError(28,1,1,9.969364,9.969364);
   grae->SetPoint(29,69,47.62465);
   grae->SetPointError(29,1,1,10.5473,10.5473);
   grae->SetPoint(30,71,30.2612);
   grae->SetPointError(30,1,1,9.439673,9.439673);
   grae->SetPoint(31,73,40.33432);
   grae->SetPointError(31,1,1,10.98684,10.98684);
   grae->SetPoint(32,75,37.58533);
   grae->SetPointError(32,1,1,10.59009,10.59009);
   grae->SetPoint(33,77,36.17453);
   grae->SetPointError(33,1,1,10.428,10.428);
   grae->SetPoint(34,79,70.01313);
   grae->SetPointError(34,1,1,14.55892,14.55892);
   grae->SetPoint(35,81,43.42534);
   grae->SetPointError(35,1,1,11.44905,11.44905);
   grae->SetPoint(36,83,36.37188);
   grae->SetPointError(36,1,1,10.47018,10.47018);
   grae->SetPoint(37,85,58.37624);
   grae->SetPointError(37,1,1,13.29091,13.29091);
   grae->SetPoint(38,87,137.6136);
   grae->SetPointError(38,1,1,20.47018,20.47018);
   grae->SetPoint(39,89,213.0517);
   grae->SetPointError(39,1,1,25.45822,25.45822);
   grae->SetPoint(40,91,324.7588);
   grae->SetPointError(40,1,1,31.44722,31.44722);
   grae->SetPoint(41,93,138.8553);
   grae->SetPointError(41,1,1,20.56515,20.56515);
   grae->SetPoint(42,95,25.49613);
   grae->SetPointError(42,1,1,8.807565,8.807565);
   grae->SetPoint(43,97,1.863433);
   grae->SetPointError(43,1,1,2.370127,2.370127);
   grae->SetPoint(44,99,0.04662269);
   grae->SetPointError(44,1,1,0.04856566,0.04856566);
   grae->SetPoint(45,101,2.772382);
   grae->SetPointError(45,1,1,2.908978,2.908978);
   grae->SetPoint(46,103,0);
   grae->SetPointError(46,1,1,0,0);
   grae->SetPoint(47,105,0.0004371958);
   grae->SetPointError(47,1,1,0.0004922808,0.0004922808);
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
   
   TGraph *graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,42.29823252);
   graph->SetPoint(1,30.2,43.19437033);
   graph->SetPoint(2,30.4,44.10420664);
   graph->SetPoint(3,30.6,45.02710318);
   graph->SetPoint(4,30.8,45.96239826);
   graph->SetPoint(5,31,46.90939378);
   graph->SetPoint(6,31.2,47.86735983);
   graph->SetPoint(7,31.4,48.83553506);
   graph->SetPoint(8,31.6,49.81312862);
   graph->SetPoint(9,31.8,50.79931757);
   graph->SetPoint(10,32,51.79324942);
   graph->SetPoint(11,32.2,52.79404324);
   graph->SetPoint(12,32.4,53.80079017);
   graph->SetPoint(13,32.6,54.8125546);
   graph->SetPoint(14,32.8,55.82837545);
   graph->SetPoint(15,33,56.8472655);
   graph->SetPoint(16,33.2,57.86821452);
   graph->SetPoint(17,33.4,58.89018998);
   graph->SetPoint(18,33.6,59.91213841);
   graph->SetPoint(19,33.8,60.93298699);
   graph->SetPoint(20,34,61.95164478);
   graph->SetPoint(21,34.2,62.96700448);
   graph->SetPoint(22,34.4,63.97794413);
   graph->SetPoint(23,34.6,64.98332887);
   graph->SetPoint(24,34.8,65.98201272);
   graph->SetPoint(25,35,66.97284044);
   graph->SetPoint(26,35.2,67.95464942);
   graph->SetPoint(27,35.4,68.92627169);
   graph->SetPoint(28,35.6,69.88653594);
   graph->SetPoint(29,35.8,70.8342696);
   graph->SetPoint(30,36,71.76830093);
   graph->SetPoint(31,36.2,72.68746113);
   graph->SetPoint(32,36.4,73.59058652);
   graph->SetPoint(33,36.6,74.47652072);
   graph->SetPoint(34,36.8,75.34411687);
   graph->SetPoint(35,37,76.19223979);
   graph->SetPoint(36,37.2,77.01976825);
   graph->SetPoint(37,37.4,77.82559712);
   graph->SetPoint(38,37.6,78.60863961);
   graph->SetPoint(39,37.8,79.36782942);
   graph->SetPoint(40,38,80.10212295);
   graph->SetPoint(41,38.2,80.81050141);
   graph->SetPoint(42,38.4,81.49197292);
   graph->SetPoint(43,38.6,82.14557457);
   graph->SetPoint(44,38.8,82.77037446);
   graph->SetPoint(45,39,83.36547366);
   graph->SetPoint(46,39.2,83.93000809);
   graph->SetPoint(47,39.4,84.46315042);
   graph->SetPoint(48,39.6,84.96411179);
   graph->SetPoint(49,39.8,85.43214354);
   graph->SetPoint(50,40,85.86653885);
   graph->SetPoint(51,40.2,86.26663423);
   graph->SetPoint(52,40.4,86.63181101);
   graph->SetPoint(53,40.6,86.96149668);
   graph->SetPoint(54,40.8,87.25516614);
   graph->SetPoint(55,41,87.51234286);
   graph->SetPoint(56,41.2,87.73259991);
   graph->SetPoint(57,41.4,87.91556095);
   graph->SetPoint(58,41.6,88.06090098);
   graph->SetPoint(59,41.8,88.16834713);
   graph->SetPoint(60,42,88.23767918);
   graph->SetPoint(61,42.2,88.26873009);
   graph->SetPoint(62,42.4,88.26138634);
   graph->SetPoint(63,42.6,88.21558815);
   graph->SetPoint(64,42.8,88.1313296);
   graph->SetPoint(65,43,88.00865861);
   graph->SetPoint(66,43.2,87.84767683);
   graph->SetPoint(67,43.4,87.64853936);
   graph->SetPoint(68,43.6,87.41145436);
   graph->SetPoint(69,43.8,87.13668258);
   graph->SetPoint(70,44,86.82453672);
   graph->SetPoint(71,44.2,86.47538072);
   graph->SetPoint(72,44.4,86.08962887);
   graph->SetPoint(73,44.6,85.66774491);
   graph->SetPoint(74,44.8,85.21024087);
   graph->SetPoint(75,45,84.71767601);
   graph->SetPoint(76,45.2,84.19065544);
   graph->SetPoint(77,45.4,83.62982879);
   graph->SetPoint(78,45.6,83.03588877);
   graph->SetPoint(79,45.8,82.40956955);
   graph->SetPoint(80,46,81.75164517);
   graph->SetPoint(81,46.2,81.06292782);
   graph->SetPoint(82,46.4,80.34426599);
   graph->SetPoint(83,46.6,79.59654269);
   graph->SetPoint(84,46.8,78.82067347);
   graph->SetPoint(85,47,78.01760445);
   graph->SetPoint(86,47.2,77.18831031);
   graph->SetPoint(87,47.4,76.33379219);
   graph->SetPoint(88,47.6,75.45507559);
   graph->SetPoint(89,47.8,74.55320822);
   graph->SetPoint(90,48,73.62925782);
   graph->SetPoint(91,48.2,72.68430997);
   graph->SetPoint(92,48.4,71.7194659);
   graph->SetPoint(93,48.6,70.73584024);
   graph->SetPoint(94,48.8,69.73455885);
   graph->SetPoint(95,49,68.71675655);
   graph->SetPoint(96,49.2,67.68357497);
   graph->SetPoint(97,49.4,66.63616036);
   graph->SetPoint(98,49.6,65.5756614);
   graph->SetPoint(99,49.8,64.50322707);
   graph->SetPoint(100,50,63.42000457);
   graph->SetPoint(101,50,63.42000457);
   graph->Draw("l");
   
   graph = new TGraph(102);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[dytt]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,35.04406794);
   graph->SetPoint(1,30.2,36.0515253);
   graph->SetPoint(2,30.4,37.07097291);
   graph->SetPoint(3,30.6,38.10180357);
   graph->SetPoint(4,30.8,39.14337721);
   graph->SetPoint(5,31,40.19502118);
   graph->SetPoint(6,31.2,41.25603058);
   graph->SetPoint(7,31.4,42.32566872);
   graph->SetPoint(8,31.6,43.40316763);
   graph->SetPoint(9,31.8,44.48772869);
   graph->SetPoint(10,32,45.57852331);
   graph->SetPoint(11,32.2,46.67469375);
   graph->SetPoint(12,32.4,47.77535395);
   graph->SetPoint(13,32.6,48.87959052);
   graph->SetPoint(14,32.8,49.9864638);
   graph->SetPoint(15,33,51.09500895);
   graph->SetPoint(16,33.2,52.20423719);
   graph->SetPoint(17,33.4,53.3131371);
   graph->SetPoint(18,33.6,54.42067602);
   graph->SetPoint(19,33.8,55.52580146);
   graph->SetPoint(20,34,56.62744266);
   graph->SetPoint(21,34.2,57.72451221);
   graph->SetPoint(22,34.4,58.81590773);
   graph->SetPoint(23,34.6,59.90051358);
   graph->SetPoint(24,34.8,60.97720272);
   graph->SetPoint(25,35,62.04483855);
   graph->SetPoint(26,35.2,63.10227684);
   graph->SetPoint(27,35.4,64.14836771);
   graph->SetPoint(28,35.6,65.1819577);
   graph->SetPoint(29,35.8,66.20189174);
   graph->SetPoint(30,36,67.20701537);
   graph->SetPoint(31,36.2,68.19617678);
   graph->SetPoint(32,36.4,69.16822906);
   graph->SetPoint(33,36.6,70.12203231);
   graph->SetPoint(34,36.8,71.05645589);
   graph->SetPoint(35,37,71.97038064);
   graph->SetPoint(36,37.2,72.86270103);
   graph->SetPoint(37,37.4,73.73232745);
   graph->SetPoint(38,37.6,74.57818836);
   graph->SetPoint(39,37.8,75.3992325);
   graph->SetPoint(40,38,76.19443107);
   graph->SetPoint(41,38.2,76.96277983);
   graph->SetPoint(42,38.4,77.70330124);
   graph->SetPoint(43,38.6,78.41504654);
   graph->SetPoint(44,38.8,79.09709773);
   graph->SetPoint(45,39,79.74856957);
   graph->SetPoint(46,39.2,80.36861147);
   graph->SetPoint(47,39.4,80.95640937);
   graph->SetPoint(48,39.6,81.51118749);
   graph->SetPoint(49,39.8,82.03221005);
   graph->SetPoint(50,40,82.51878289);
   graph->SetPoint(51,40.2,82.97025502);
   graph->SetPoint(52,40.4,83.38602004);
   graph->SetPoint(53,40.6,83.76551756);
   graph->SetPoint(54,40.8,84.10823438);
   graph->SetPoint(55,41,84.4137057);
   graph->SetPoint(56,41.2,84.68151617);
   graph->SetPoint(57,41.4,84.91130079);
   graph->SetPoint(58,41.6,85.10274579);
   graph->SetPoint(59,41.8,85.25558931);
   graph->SetPoint(60,42,85.369622);
   graph->SetPoint(61,42.2,85.44468751);
   graph->SetPoint(62,42.4,85.48068285);
   graph->SetPoint(63,42.6,85.47755859);
   graph->SetPoint(64,42.8,85.43531904);
   graph->SetPoint(65,43,85.35402218);
   graph->SetPoint(66,43.2,85.23377953);
   graph->SetPoint(67,43.4,85.07475594);
   graph->SetPoint(68,43.6,84.87716918);
   graph->SetPoint(69,43.8,84.64128943);
   graph->SetPoint(70,44,84.36743872);
   graph->SetPoint(71,44.2,84.05599013);
   graph->SetPoint(72,44.4,83.70736698);
   graph->SetPoint(73,44.6,83.32204187);
   graph->SetPoint(74,44.8,82.90053561);
   graph->SetPoint(75,45,82.44341604);
   graph->SetPoint(76,45.2,81.95129676);
   graph->SetPoint(77,45.4,81.42483576);
   graph->SetPoint(78,45.6,80.86473395);
   graph->SetPoint(79,45.8,80.27173362);
   graph->SetPoint(80,46,79.64661677);
   graph->SetPoint(81,46.2,78.99020341);
   graph->SetPoint(82,46.4,78.3033498);
   graph->SetPoint(83,46.6,77.58694654);
   graph->SetPoint(84,46.8,76.84191666);
   graph->SetPoint(85,47,76.06921368);
   graph->SetPoint(86,47.2,75.26981954);
   graph->SetPoint(87,47.4,74.44474252);
   graph->SetPoint(88,47.6,73.59501517);
   graph->SetPoint(89,47.8,72.72169213);
   graph->SetPoint(90,48,71.82584797);
   graph->SetPoint(91,48.2,70.908575);
   graph->SetPoint(92,48.4,69.97098106);
   graph->SetPoint(93,48.6,69.01418731);
   graph->SetPoint(94,48.8,68.03932601);
   graph->SetPoint(95,49,67.04753833);
   graph->SetPoint(96,49.2,66.0399721);
   graph->SetPoint(97,49.4,65.0177797);
   graph->SetPoint(98,49.6,63.98211584);
   graph->SetPoint(99,49.8,62.93413545);
   graph->SetPoint(100,50,61.87499158);
   graph->SetPoint(101,50,61.87499158);
   graph->Draw("l");
   
   graph = new TGraph(112);
   graph->SetName("test_sum_pf_Norm[eventSelectionamassMu]_Comp[test_bwxCryBall_pf]_Range[fit_nll_test_sum_pf_data]_NormRange[fit_nll_test_sum_pf_data]");
   graph->SetTitle("Projection of Gaussian crystal ball and exponential PDF_pf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetPoint(0,30,5.571108687e-05);
   graph->SetPoint(1,30.1,6.12174913e-05);
   graph->SetPoint(2,30.2,6.705073869e-05);
   graph->SetPoint(3,30.3,7.321082903e-05);
   graph->SetPoint(4,30.35,7.64134403e-05);
   graph->SetPoint(5,30.4,7.801294335e-05);
   graph->SetPoint(6,30.5,8.101756367e-05);
   graph->SetPoint(7,30.6,8.376300295e-05);
   graph->SetPoint(8,30.7,8.624926119e-05);
   graph->SetPoint(9,30.8,8.847633839e-05);
   graph->SetPoint(10,30.9,9.044423455e-05);
   graph->SetPoint(11,31,9.215294967e-05);
   graph->SetPoint(12,31.1,9.360248376e-05);
   graph->SetPoint(13,31.2,9.479283681e-05);
   graph->SetPoint(14,31.3,9.572400882e-05);
   graph->SetPoint(15,31.4,9.639599979e-05);
   graph->SetPoint(16,31.45,9.663480238e-05);
   graph->SetPoint(17,31.5,9.723476565e-05);
   graph->SetPoint(18,31.6,9.835142533e-05);
   graph->SetPoint(19,31.8,0.0001002516773);
   graph->SetPoint(20,32,0.0001017078395);
   graph->SetPoint(21,32.2,0.0001027199119);
   graph->SetPoint(22,32.4,0.0001032878944);
   graph->SetPoint(23,32.6,0.0001036611722);
   graph->SetPoint(24,32.8,0.0001045553721);
   graph->SetPoint(25,33,0.0001053524526);
   graph->SetPoint(26,33.2,0.0001060524139);
   graph->SetPoint(27,33.4,0.000106655256);
   graph->SetPoint(28,33.6,0.0001071609787);
   graph->SetPoint(29,33.8,0.0001077195818);
   graph->SetPoint(30,34,0.0001082870652);
   graph->SetPoint(31,34.2,0.0001088214291);
   graph->SetPoint(32,34.4,0.0001093226735);
   graph->SetPoint(33,34.6,0.0001097907985);
   graph->SetPoint(34,34.8,0.000110239418);
   graph->SetPoint(35,35,0.0001107075982);
   graph->SetPoint(36,35.2,0.0001111616001);
   graph->SetPoint(37,35.4,0.0001116014238);
   graph->SetPoint(38,35.6,0.0001120270692);
   graph->SetPoint(39,35.8,0.0001124385363);
   graph->SetPoint(40,36,0.0001128533495);
   graph->SetPoint(41,36.2,0.0001132663683);
   graph->SetPoint(42,36.4,0.0001136726859);
   graph->SetPoint(43,36.6,0.0001140723023);
   graph->SetPoint(44,36.8,0.0001144652175);
   graph->SetPoint(45,37,0.0001148539865);
   graph->SetPoint(46,37.2,0.0001152459408);
   graph->SetPoint(47,37.4,0.0001156347487);
   graph->SetPoint(48,37.6,0.0001160204101);
   graph->SetPoint(49,37.8,0.0001164029251);
   graph->SetPoint(50,38,0.0001167822936);
   graph->SetPoint(51,38.2,0.0001171630457);
   graph->SetPoint(52,38.4,0.0001175438525);
   graph->SetPoint(53,38.6,0.0001179234457);
   graph->SetPoint(54,38.8,0.0001183018252);
   graph->SetPoint(55,39,0.0001186789911);
   graph->SetPoint(56,39.2,0.000119055784);
   graph->SetPoint(57,39.4,0.0001194346161);
   graph->SetPoint(58,39.6,0.0001198134042);
   graph->SetPoint(59,39.8,0.0001201921483);
   graph->SetPoint(60,40,0.0001205708483);
   graph->SetPoint(61,40.2,0.0001209495042);
   graph->SetPoint(62,40.4,0.0001213299354);
   graph->SetPoint(63,40.6,0.000121711608);
   graph->SetPoint(64,40.8,0.0001220940128);
   graph->SetPoint(65,41,0.0001224771497);
   graph->SetPoint(66,41.2,0.0001228610188);
   graph->SetPoint(67,41.4,0.0001232460226);
   graph->SetPoint(68,41.6,0.0001236333166);
   graph->SetPoint(69,41.8,0.0001240219029);
   graph->SetPoint(70,42,0.0001244117815);
   graph->SetPoint(71,42.2,0.0001248029524);
   graph->SetPoint(72,42.4,0.0001251954157);
   graph->SetPoint(73,42.6,0.000125590195);
   graph->SetPoint(74,42.8,0.00012598699);
   graph->SetPoint(75,43,0.0001263855142);
   graph->SetPoint(76,43.2,0.0001267857675);
   graph->SetPoint(77,43.4,0.00012718775);
   graph->SetPoint(78,43.6,0.0001275917242);
   graph->SetPoint(79,43.8,0.0001279984438);
   graph->SetPoint(80,44,0.0001284072579);
   graph->SetPoint(81,44.2,0.0001288181666);
   graph->SetPoint(82,44.4,0.0001292311698);
   graph->SetPoint(83,44.6,0.0001296462675);
   graph->SetPoint(84,44.8,0.0001300642219);
   graph->SetPoint(85,45,0.0001304848093);
   graph->SetPoint(86,45.2,0.0001309078164);
   graph->SetPoint(87,45.4,0.0001313332431);
   graph->SetPoint(88,45.6,0.0001317610896);
   graph->SetPoint(89,45.8,0.0001321915748);
   graph->SetPoint(90,46,0.0001326253271);
   graph->SetPoint(91,46.2,0.0001330618039);
   graph->SetPoint(92,46.4,0.000133501005);
   graph->SetPoint(93,46.6,0.0001339429306);
   graph->SetPoint(94,46.8,0.0001343875805);
   graph->SetPoint(95,47,0.0001348356528);
   graph->SetPoint(96,47.2,0.0001352869426);
   graph->SetPoint(97,47.4,0.0001357412545);
   graph->SetPoint(98,47.6,0.0001361985887);
   graph->SetPoint(99,47.8,0.000136658945);
   graph->SetPoint(100,48,0.0001371225396);
   graph->SetPoint(101,48.2,0.0001375899924);
   graph->SetPoint(102,48.4,0.0001380607681);
   graph->SetPoint(103,48.6,0.0001385348666);
   graph->SetPoint(104,48.8,0.0001390122879);
   graph->SetPoint(105,49,0.000139493032);
   graph->SetPoint(106,49.2,0.0001399778285);
   graph->SetPoint(107,49.4,0.0001404664632);
   graph->SetPoint(108,49.6,0.0001409587321);
   graph->SetPoint(109,49.8,0.000141454635);
   graph->SetPoint(110,50,0.000141954172);
   graph->SetPoint(111,50,0.000141954172);
   graph->Draw("l");
   
   TH1D *frame_28dba10__6 = new TH1D("frame_28dba10__6","SM",100,10,120);
   frame_28dba10__6->SetBinContent(1,374.0417);
   frame_28dba10__6->SetMinimum(-18.34233);
   frame_28dba10__6->SetMaximum(374.0417);
   frame_28dba10__6->SetEntries(1);
   frame_28dba10__6->SetDirectory(0);
   frame_28dba10__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_28dba10__6->SetLineColor(ci);
   frame_28dba10__6->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_28dba10__6->GetXaxis()->SetLabelFont(42);
   frame_28dba10__6->GetXaxis()->SetLabelSize(0.035);
   frame_28dba10__6->GetXaxis()->SetTitleSize(0.035);
   frame_28dba10__6->GetXaxis()->SetTitleFont(42);
   frame_28dba10__6->GetYaxis()->SetTitle("Events / ( 2 )");
   frame_28dba10__6->GetYaxis()->SetLabelFont(42);
   frame_28dba10__6->GetYaxis()->SetLabelSize(0.035);
   frame_28dba10__6->GetYaxis()->SetTitleSize(0.035);
   frame_28dba10__6->GetYaxis()->SetTitleFont(42);
   frame_28dba10__6->GetZaxis()->SetLabelFont(42);
   frame_28dba10__6->GetZaxis()->SetLabelSize(0.035);
   frame_28dba10__6->GetZaxis()->SetTitleSize(0.035);
   frame_28dba10__6->GetZaxis()->SetTitleFont(42);
   frame_28dba10__6->Draw("AXISSAME");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
