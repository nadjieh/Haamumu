{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Tue Jun 23 15:48:34 2015) by ROOT version5.34/18
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",13,36,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(80);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,25,8.929688);
   grae->SetPointError(0,0,0,4.517166,10.5296);
   grae->SetPoint(1,25.5,9.070312);
   grae->SetPointError(1,0,0,4.588303,10.54515);
   grae->SetPoint(2,26,9.164062);
   grae->SetPointError(2,0,0,4.635727,10.65415);
   grae->SetPoint(3,26.5,9.257812);
   grae->SetPointError(3,0,0,4.646988,10.80494);
   grae->SetPoint(4,27,9.421875);
   grae->SetPointError(4,0,0,4.766144,10.83975);
   grae->SetPoint(5,27.5,9.515625);
   grae->SetPointError(5,0,0,4.776398,11.06287);
   grae->SetPoint(6,28,9.609375);
   grae->SetPointError(6,0,0,4.823456,11.21526);
   grae->SetPoint(7,28.5,9.703125);
   grae->SetPointError(7,0,0,4.832611,11.32468);
   grae->SetPoint(8,29,9.890625);
   grae->SetPointError(8,0,0,4.96463,11.37904);
   grae->SetPoint(9,29.5,9.984375);
   grae->SetPointError(9,0,0,5.011688,11.4869);
   grae->SetPoint(10,30,10.07812);
   grae->SetPointError(10,0,0,5.019379,11.70162);
   grae->SetPoint(11,30.5,10.26562);
   grae->SetPointError(11,0,0,5.152863,11.81047);
   grae->SetPoint(12,31,10.35938);
   grae->SetPointError(12,0,0,5.159454,11.91833);
   grae->SetPoint(13,31.5,10.54688);
   grae->SetPointError(13,0,0,5.294037,12.08576);
   grae->SetPoint(14,32,10.64062);
   grae->SetPointError(14,0,0,5.29953,12.2419);
   grae->SetPoint(15,32.5,10.82812);
   grae->SetPointError(15,0,0,5.414062,12.27621);
   grae->SetPoint(16,33,10.92188);
   grae->SetPointError(16,0,0,5.439606,12.43317);
   grae->SetPoint(17,33.5,11.10938);
   grae->SetPointError(17,0,0,5.53299,12.59507);
   grae->SetPoint(18,34,11.20312);
   grae->SetPointError(18,0,0,5.535919,12.75334);
   grae->SetPoint(19,34.5,11.39062);
   grae->SetPointError(19,0,0,5.673065,12.91393);
   grae->SetPoint(20,35,11.57812);
   grae->SetPointError(20,0,0,5.766449,12.98553);
   grae->SetPoint(21,35.5,11.67188);
   grae->SetPointError(21,0,0,5.767548,13.28695);
   grae->SetPoint(22,36,11.85938);
   grae->SetPointError(22,0,0,5.860199,13.30097);
   grae->SetPoint(23,36.5,12.04688);
   grae->SetPointError(23,0,0,5.95285,13.48294);
   grae->SetPoint(24,37,12.23438);
   grae->SetPointError(24,0,0,6.045502,13.66402);
   grae->SetPoint(25,37.5,12.32812);
   grae->SetPointError(25,0,0,6.067749,13.8267);
   grae->SetPoint(26,38,12.51562);
   grae->SetPointError(26,0,0,6.184479,13.97814);
   grae->SetPoint(27,38.5,12.70312);
   grae->SetPointError(27,0,0,6.27713,14.03208);
   grae->SetPoint(28,39,12.79688);
   grae->SetPointError(28,0,0,6.273468,14.19661);
   grae->SetPoint(29,39.5,12.98438);
   grae->SetPointError(29,0,0,6.365387,14.34275);
   grae->SetPoint(30,40,13.17188);
   grae->SetPointError(30,0,0,6.508759,14.48711);
   grae->SetPoint(31,40.5,13.26562);
   grae->SetPointError(31,0,0,6.503265,14.65343);
   grae->SetPoint(32,41,13.45312);
   grae->SetPointError(32,0,0,6.595184,14.63096);
   grae->SetPoint(33,41.5,13.54688);
   grae->SetPointError(33,0,0,6.641144,14.73292);
   grae->SetPoint(34,42,13.64062);
   grae->SetPointError(34,0,0,6.687103,14.83488);
   grae->SetPoint(35,42.5,13.73438);
   grae->SetPointError(35,0,0,6.733063,14.93684);
   grae->SetPoint(36,43,13.82812);
   grae->SetPointError(36,0,0,6.779022,15.0388);
   grae->SetPoint(37,43.5,13.92188);
   grae->SetPointError(37,0,0,6.824982,15.14075);
   grae->SetPoint(38,44,13.92188);
   grae->SetPointError(38,0,0,6.770599,15.17435);
   grae->SetPoint(39,44.5,14.01562);
   grae->SetPointError(39,0,0,6.870941,15.07031);
   grae->SetPoint(40,45,14.01562);
   grae->SetPointError(40,0,0,6.816193,15.24271);
   grae->SetPoint(41,45.5,14.01562);
   grae->SetPointError(41,0,0,6.816193,15.24271);
   grae->SetPoint(42,46,14.01562);
   grae->SetPointError(42,0,0,6.816193,15.07031);
   grae->SetPoint(43,46.5,14.01562);
   grae->SetPointError(43,0,0,6.843567,15.07031);
   grae->SetPoint(44,47,13.92188);
   grae->SetPointError(44,0,0,6.770599,15.14075);
   grae->SetPoint(45,47.5,13.92188);
   grae->SetPointError(45,0,0,6.824982,14.90144);
   grae->SetPoint(46,48,13.82812);
   grae->SetPointError(46,0,0,6.752014,14.8687);
   grae->SetPoint(47,48.5,13.73438);
   grae->SetPointError(47,0,0,6.706238,14.7679);
   grae->SetPoint(48,49,13.64062);
   grae->SetPointError(48,0,0,6.687103,14.66709);
   grae->SetPoint(49,49.5,13.54688);
   grae->SetPointError(49,0,0,6.641144,14.50005);
   grae->SetPoint(50,50,13.35938);
   grae->SetPointError(50,0,0,6.49704,14.52901);
   grae->SetPoint(51,50.5,13.26562);
   grae->SetPointError(51,0,0,6.503265,14.26387);
   grae->SetPoint(52,51,13.07812);
   grae->SetPointError(52,0,0,6.36026,14.22313);
   grae->SetPoint(53,51.5,12.98438);
   grae->SetPointError(53,0,0,6.365387,13.96146);
   grae->SetPoint(54,52,12.79688);
   grae->SetPointError(54,0,0,6.273468,13.91726);
   grae->SetPoint(55,52.5,12.60938);
   grae->SetPointError(55,0,0,6.156921,13.77421);
   grae->SetPoint(56,53,12.51562);
   grae->SetPointError(56,0,0,6.13559,13.61139);
   grae->SetPoint(57,53.5,12.32812);
   grae->SetPointError(57,0,0,6.043671,13.40747);
   grae->SetPoint(58,54,12.14062);
   grae->SetPointError(58,0,0,5.951752,13.26215);
   grae->SetPoint(59,54.5,12.04688);
   grae->SetPointError(59,0,0,5.905792,13.10159);
   grae->SetPoint(60,55,11.85938);
   grae->SetPointError(60,0,0,5.813873,12.89768);
   grae->SetPoint(61,55.5,11.67188);
   grae->SetPointError(61,0,0,5.721954,12.89295);
   grae->SetPoint(62,56,11.57812);
   grae->SetPointError(62,0,0,5.675995,12.59181);
   grae->SetPoint(63,56.5,11.48438);
   grae->SetPointError(63,0,0,5.652466,12.48985);
   grae->SetPoint(64,57,11.29688);
   grae->SetPointError(64,0,0,5.538116,12.47871);
   grae->SetPoint(65,57.5,11.20312);
   grae->SetPointError(65,0,0,5.492157,12.23805);
   grae->SetPoint(66,58,11.10938);
   grae->SetPointError(66,0,0,5.446198,12.13564);
   grae->SetPoint(67,58.5,11.01562);
   grae->SetPointError(67,0,0,5.400238,11.98006);
   grae->SetPoint(68,59,10.92188);
   grae->SetPointError(68,0,0,5.354279,11.93082);
   grae->SetPoint(69,59.5,10.82812);
   grae->SetPointError(69,0,0,5.308319,11.82841);
   grae->SetPoint(70,60,10.82812);
   grae->SetPointError(70,0,0,5.350616,11.64295);
   grae->SetPoint(71,60.5,10.73438);
   grae->SetPointError(71,0,0,5.26236,11.67418);
   grae->SetPoint(72,61,10.64062);
   grae->SetPointError(72,0,0,5.2164,11.62359);
   grae->SetPoint(73,61.5,10.64062);
   grae->SetPointError(73,0,0,5.237183,11.52086);
   grae->SetPoint(74,62,10.54688);
   grae->SetPointError(74,0,0,5.170441,11.47027);
   grae->SetPoint(75,62.5,10.45312);
   grae->SetPointError(75,0,0,5.124481,11.39354);
   grae->SetPoint(76,63,10.40625);
   grae->SetPointError(76,0,0,5.101501,11.31733);
   grae->SetPoint(77,63.5,10.35938);
   grae->SetPointError(77,0,0,5.078522,11.13893);
   grae->SetPoint(78,64,10.26562);
   grae->SetPointError(78,0,0,5.032562,11.16439);
   grae->SetPoint(79,64.5,10.17188);
   grae->SetPointError(79,0,0,4.986603,11.06244);
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(80);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");

   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,25,8.929688);
   grae->SetPointError(0,0,0,2.805583,4.449264);
   grae->SetPoint(1,25.5,9.070312);
   grae->SetPointError(1,0,0,2.885612,4.447022);
   grae->SetPoint(2,26,9.164062);
   grae->SetPointError(2,0,0,2.915437,4.492986);
   grae->SetPoint(3,26.5,9.257812);
   grae->SetPointError(3,0,0,2.92252,4.612754);
   grae->SetPoint(4,27,9.421875);
   grae->SetPointError(4,0,0,2.997458,4.619388);
   grae->SetPoint(5,27.5,9.515625);
   grae->SetPointError(5,0,0,3.003907,4.665351);
   grae->SetPoint(6,28,9.609375);
   grae->SetPointError(6,0,0,3.01466,4.787922);
   grae->SetPoint(7,28.5,9.703125);
   grae->SetPointError(7,0,0,3.020382,4.834634);
   grae->SetPoint(8,29,9.890625);
   grae->SetPointError(8,0,0,3.122287,4.849208);
   grae->SetPoint(9,29.5,9.984375);
   grae->SetPointError(9,0,0,3.112729,4.895172);
   grae->SetPoint(10,30,10.07812);
   grae->SetPointError(10,0,0,3.117505,5.02148);
   grae->SetPoint(11,30.5,10.26562);
   grae->SetPointError(11,0,0,3.240668,5.033064);
   grae->SetPoint(12,31,10.35938);
   grae->SetPointError(12,0,0,3.224659,5.079028);
   grae->SetPoint(13,31.5,10.54688);
   grae->SetPointError(13,0,0,3.329453,5.086876);
   grae->SetPoint(14,32,10.64062);
   grae->SetPointError(14,0,0,3.312206,5.216921);
   grae->SetPoint(15,32.5,10.82812);
   grae->SetPointError(15,0,0,3.404938,5.222526);
   grae->SetPoint(16,33,10.92188);
   grae->SetPointError(16,0,0,3.378505,5.354812);
   grae->SetPoint(17,33.5,11.10938);
   grae->SetPointError(17,0,0,3.479732,5.358175);
   grae->SetPoint(18,34,11.20312);
   grae->SetPointError(18,0,0,3.459949,5.492705);
   grae->SetPoint(19,34.5,11.39062);
   grae->SetPointError(19,0,0,3.523506,5.493826);
   grae->SetPoint(20,35,11.57812);
   grae->SetPointError(20,0,0,3.626555,5.584259);
   grae->SetPoint(21,35.5,11.67188);
   grae->SetPointError(21,0,0,3.582188,5.722525);
   grae->SetPoint(22,36,11.85938);
   grae->SetPointError(22,0,0,3.662624,5.719909);
   grae->SetPoint(23,36.5,12.04688);
   grae->SetPointError(23,0,0,3.743784,5.762323);
   grae->SetPoint(24,37,12.23438);
   grae->SetPointError(24,0,0,3.802053,5.803242);
   grae->SetPoint(25,37.5,12.32812);
   grae->SetPointError(25,0,0,3.768641,5.945992);
   grae->SetPoint(26,38,12.51562);
   grae->SetPointError(26,0,0,3.841141,5.93665);
   grae->SetPoint(27,38.5,12.70312);
   grae->SetPointError(27,0,0,3.898686,6.025589);
   grae->SetPoint(28,39,12.79688);
   grae->SetPointError(28,0,0,3.896411,6.172076);
   grae->SetPoint(29,39.5,12.98438);
   grae->SetPointError(29,0,0,3.978367,6.158997);
   grae->SetPoint(30,40,13.17188);
   grae->SetPointError(30,0,0,4.04255,6.142928);
   grae->SetPoint(31,40.5,13.26562);
   grae->SetPointError(31,0,0,4.039138,6.292405);
   grae->SetPoint(32,41,13.45312);
   grae->SetPointError(32,0,0,4.147752,6.274093);
   grae->SetPoint(33,41.5,13.54688);
   grae->SetPointError(33,0,0,4.150715,6.317815);
   grae->SetPoint(34,42,13.64062);
   grae->SetPointError(34,0,0,4.153318,6.361537);
   grae->SetPoint(35,42.5,13.73438);
   grae->SetPointError(35,0,0,4.181863,6.40526);
   grae->SetPoint(36,43,13.82812);
   grae->SetPointError(36,0,0,4.210409,6.448982);
   grae->SetPoint(37,43.5,13.92188);
   grae->SetPointError(37,0,0,4.238953,6.492704);
   grae->SetPoint(38,44,13.92188);
   grae->SetPointError(38,0,0,4.205177,6.548196);
   grae->SetPoint(39,44.5,14.01562);
   grae->SetPointError(39,0,0,4.267499,6.536425);
   grae->SetPoint(40,45,14.01562);
   grae->SetPointError(40,0,0,4.233494,6.536425);
   grae->SetPoint(41,45.5,14.01562);
   grae->SetPointError(41,0,0,4.233494,6.536425);
   grae->SetPoint(42,46,14.01562);
   grae->SetPointError(42,0,0,4.233494,6.536425);
   grae->SetPoint(43,46.5,14.01562);
   grae->SetPointError(43,0,0,4.250497,6.536425);
   grae->SetPoint(44,47,13.92188);
   grae->SetPointError(44,0,0,4.205177,6.492704);
   grae->SetPoint(45,47.5,13.92188);
   grae->SetPointError(45,0,0,4.238953,6.381716);
   grae->SetPoint(46,48,13.82812);
   grae->SetPointError(46,0,0,4.193634,6.448982);
   grae->SetPoint(47,48.5,13.73438);
   grae->SetPointError(47,0,0,4.165202,6.40526);
   grae->SetPoint(48,49,13.64062);
   grae->SetPointError(48,0,0,4.153318,6.361537);
   grae->SetPoint(49,49.5,13.54688);
   grae->SetPointError(49,0,0,4.150715,6.209819);
   grae->SetPoint(50,50,13.35938);
   grae->SetPointError(50,0,0,4.035271,6.230372);
   grae->SetPoint(51,50.5,13.26562);
   grae->SetPointError(51,0,0,4.039138,6.18665);
   grae->SetPoint(52,51,13.07812);
   grae->SetPointError(52,0,0,3.950317,6.099206);
   grae->SetPoint(53,51.5,12.98438);
   grae->SetPointError(53,0,0,4.003232,6.055484);
   grae->SetPoint(54,52,12.79688);
   grae->SetPointError(54,0,0,3.896411,5.968041);
   grae->SetPoint(55,52.5,12.60938);
   grae->SetPointError(55,0,0,3.824025,5.98112);
   grae->SetPoint(56,53,12.51562);
   grae->SetPointError(56,0,0,3.85871,5.836874);
   grae->SetPoint(57,53.5,12.32812);
   grae->SetPointError(57,0,0,3.753686,5.74943);
   grae->SetPoint(58,54,12.14062);
   grae->SetPointError(58,0,0,3.696596,5.758773);
   grae->SetPoint(59,54.5,12.04688);
   grae->SetPointError(59,0,0,3.71419,5.618265);
   grae->SetPoint(60,55,11.85938);
   grae->SetPointError(60,0,0,3.61096,5.530821);
   grae->SetPoint(61,55.5,11.67188);
   grae->SetPointError(61,0,0,3.55387,5.536427);
   grae->SetPoint(62,56,11.57812);
   grae->SetPointError(62,0,0,3.525325,5.399656);
   grae->SetPoint(63,56.5,11.48438);
   grae->SetPointError(63,0,0,3.554871,5.355934);
   grae->SetPoint(64,57,11.29688);
   grae->SetPointError(64,0,0,3.439689,5.35855);
   grae->SetPoint(65,57.5,11.20312);
   grae->SetPointError(65,0,0,3.411145,5.31408);
   grae->SetPoint(66,58,11.10938);
   grae->SetPointError(66,0,0,3.382599,5.269611);
   grae->SetPoint(67,58.5,11.01562);
   grae->SetPointError(67,0,0,3.354054,5.137324);
   grae->SetPoint(68,59,10.92188);
   grae->SetPointError(68,0,0,3.325509,5.180672);
   grae->SetPoint(69,59.5,10.82812);
   grae->SetPointError(69,0,0,3.296964,5.136203);
   grae->SetPoint(70,60,10.82812);
   grae->SetPointError(70,0,0,3.323234,5.04988);
   grae->SetPoint(71,60.5,10.73438);
   grae->SetPointError(71,0,0,3.288975,5.006158);
   grae->SetPoint(72,61,10.64062);
   grae->SetPointError(72,0,0,3.239874,5.047265);
   grae->SetPoint(73,61.5,10.64062);
   grae->SetPointError(73,0,0,3.293697,4.877608);
   grae->SetPoint(74,62,10.54688);
   grae->SetPointError(74,0,0,3.211328,4.918715);
   grae->SetPoint(75,62.5,10.45312);
   grae->SetPointError(75,0,0,3.182784,4.916659);
   grae->SetPoint(76,63,10.40625);
   grae->SetPointError(76,0,0,3.168511,4.853132);
   grae->SetPoint(77,63.5,10.35938);
   grae->SetPointError(77,0,0,3.174076,4.831271);
   grae->SetPoint(78,64,10.26562);
   grae->SetPointError(78,0,0,3.125693,4.787549);
   grae->SetPoint(79,64.5,10.17188);
   grae->SetPointError(79,0,0,3.097147,4.743826);
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(80);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,25,8.929688);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,25.5,9.070312);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,26,9.164062);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,26.5,9.257812);
   grae->SetPointError(3,0,0,0,0);
   grae->SetPoint(4,27,9.421875);
   grae->SetPointError(4,0,0,0,0);
   grae->SetPoint(5,27.5,9.515625);
   grae->SetPointError(5,0,0,0,0);
   grae->SetPoint(6,28,9.609375);
   grae->SetPointError(6,0,0,0,0);
   grae->SetPoint(7,28.5,9.703125);
   grae->SetPointError(7,0,0,0,0);
   grae->SetPoint(8,29,9.890625);
   grae->SetPointError(8,0,0,0,0);
   grae->SetPoint(9,29.5,9.984375);
   grae->SetPointError(9,0,0,0,0);
   grae->SetPoint(10,30,10.07812);
   grae->SetPointError(10,0,0,0,0);
   grae->SetPoint(11,30.5,10.26562);
   grae->SetPointError(11,0,0,0,0);
   grae->SetPoint(12,31,10.35938);
   grae->SetPointError(12,0,0,0,0);
   grae->SetPoint(13,31.5,10.54688);
   grae->SetPointError(13,0,0,0,0);
   grae->SetPoint(14,32,10.64062);
   grae->SetPointError(14,0,0,0,0);
   grae->SetPoint(15,32.5,10.82812);
   grae->SetPointError(15,0,0,0,0);
   grae->SetPoint(16,33,10.92188);
   grae->SetPointError(16,0,0,0,0);
   grae->SetPoint(17,33.5,11.10938);
   grae->SetPointError(17,0,0,0,0);
   grae->SetPoint(18,34,11.20312);
   grae->SetPointError(18,0,0,0,0);
   grae->SetPoint(19,34.5,11.39062);
   grae->SetPointError(19,0,0,0,0);
   grae->SetPoint(20,35,11.57812);
   grae->SetPointError(20,0,0,0,0);
   grae->SetPoint(21,35.5,11.67188);
   grae->SetPointError(21,0,0,0,0);
   grae->SetPoint(22,36,11.85938);
   grae->SetPointError(22,0,0,0,0);
   grae->SetPoint(23,36.5,12.04688);
   grae->SetPointError(23,0,0,0,0);
   grae->SetPoint(24,37,12.23438);
   grae->SetPointError(24,0,0,0,0);
   grae->SetPoint(25,37.5,12.32812);
   grae->SetPointError(25,0,0,0,0);
   grae->SetPoint(26,38,12.51562);
   grae->SetPointError(26,0,0,0,0);
   grae->SetPoint(27,38.5,12.70312);
   grae->SetPointError(27,0,0,0,0);
   grae->SetPoint(28,39,12.79688);
   grae->SetPointError(28,0,0,0,0);
   grae->SetPoint(29,39.5,12.98438);
   grae->SetPointError(29,0,0,0,0);
   grae->SetPoint(30,40,13.17188);
   grae->SetPointError(30,0,0,0,0);
   grae->SetPoint(31,40.5,13.26562);
   grae->SetPointError(31,0,0,0,0);
   grae->SetPoint(32,41,13.45312);
   grae->SetPointError(32,0,0,0,0);
   grae->SetPoint(33,41.5,13.54688);
   grae->SetPointError(33,0,0,0,0);
   grae->SetPoint(34,42,13.64062);
   grae->SetPointError(34,0,0,0,0);
   grae->SetPoint(35,42.5,13.73438);
   grae->SetPointError(35,0,0,0,0);
   grae->SetPoint(36,43,13.82812);
   grae->SetPointError(36,0,0,0,0);
   grae->SetPoint(37,43.5,13.92188);
   grae->SetPointError(37,0,0,0,0);
   grae->SetPoint(38,44,13.92188);
   grae->SetPointError(38,0,0,0,0);
   grae->SetPoint(39,44.5,14.01562);
   grae->SetPointError(39,0,0,0,0);
   grae->SetPoint(40,45,14.01562);
   grae->SetPointError(40,0,0,0,0);
   grae->SetPoint(41,45.5,14.01562);
   grae->SetPointError(41,0,0,0,0);
   grae->SetPoint(42,46,14.01562);
   grae->SetPointError(42,0,0,0,0);
   grae->SetPoint(43,46.5,14.01562);
   grae->SetPointError(43,0,0,0,0);
   grae->SetPoint(44,47,13.92188);
   grae->SetPointError(44,0,0,0,0);
   grae->SetPoint(45,47.5,13.92188);
   grae->SetPointError(45,0,0,0,0);
   grae->SetPoint(46,48,13.82812);
   grae->SetPointError(46,0,0,0,0);
   grae->SetPoint(47,48.5,13.73438);
   grae->SetPointError(47,0,0,0,0);
   grae->SetPoint(48,49,13.64062);
   grae->SetPointError(48,0,0,0,0);
   grae->SetPoint(49,49.5,13.54688);
   grae->SetPointError(49,0,0,0,0);
   grae->SetPoint(50,50,13.35938);
   grae->SetPointError(50,0,0,0,0);
   grae->SetPoint(51,50.5,13.26562);
   grae->SetPointError(51,0,0,0,0);
   grae->SetPoint(52,51,13.07812);
   grae->SetPointError(52,0,0,0,0);
   grae->SetPoint(53,51.5,12.98438);
   grae->SetPointError(53,0,0,0,0);
   grae->SetPoint(54,52,12.79688);
   grae->SetPointError(54,0,0,0,0);
   grae->SetPoint(55,52.5,12.60938);
   grae->SetPointError(55,0,0,0,0);
   grae->SetPoint(56,53,12.51562);
   grae->SetPointError(56,0,0,0,0);
   grae->SetPoint(57,53.5,12.32812);
   grae->SetPointError(57,0,0,0,0);
   grae->SetPoint(58,54,12.14062);
   grae->SetPointError(58,0,0,0,0);
   grae->SetPoint(59,54.5,12.04688);
   grae->SetPointError(59,0,0,0,0);
   grae->SetPoint(60,55,11.85938);
   grae->SetPointError(60,0,0,0,0);
   grae->SetPoint(61,55.5,11.67188);
   grae->SetPointError(61,0,0,0,0);
   grae->SetPoint(62,56,11.57812);
   grae->SetPointError(62,0,0,0,0);
   grae->SetPoint(63,56.5,11.48438);
   grae->SetPointError(63,0,0,0,0);
   grae->SetPoint(64,57,11.29688);
   grae->SetPointError(64,0,0,0,0);
   grae->SetPoint(65,57.5,11.20312);
   grae->SetPointError(65,0,0,0,0);
   grae->SetPoint(66,58,11.10938);
   grae->SetPointError(66,0,0,0,0);
   grae->SetPoint(67,58.5,11.01562);
   grae->SetPointError(67,0,0,0,0);
   grae->SetPoint(68,59,10.92188);
   grae->SetPointError(68,0,0,0,0);
   grae->SetPoint(69,59.5,10.82812);
   grae->SetPointError(69,0,0,0,0);
   grae->SetPoint(70,60,10.82812);
   grae->SetPointError(70,0,0,0,0);
   grae->SetPoint(71,60.5,10.73438);
   grae->SetPointError(71,0,0,0,0);
   grae->SetPoint(72,61,10.64062);
   grae->SetPointError(72,0,0,0,0);
   grae->SetPoint(73,61.5,10.64062);
   grae->SetPointError(73,0,0,0,0);
   grae->SetPoint(74,62,10.54688);
   grae->SetPointError(74,0,0,0,0);
   grae->SetPoint(75,62.5,10.45312);
   grae->SetPointError(75,0,0,0,0);
   grae->SetPoint(76,63,10.40625);
   grae->SetPointError(76,0,0,0,0);
   grae->SetPoint(77,63.5,10.35938);
   grae->SetPointError(77,0,0,0,0);
   grae->SetPoint(78,64,10.26562);
   grae->SetPointError(78,0,0,0,0);
   grae->SetPoint(79,64.5,10.17188);
   grae->SetPointError(79,0,0,0,0);
   grae->Draw("p");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
