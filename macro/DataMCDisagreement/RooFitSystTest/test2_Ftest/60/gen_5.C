{
//=========Macro generated from canvas: gen_5/gen_5
//=========  (Sun Mar  1 12:03:25 2015) by ROOT version5.34/19
   TCanvas *gen_5 = new TCanvas("gen_5", "gen_5",0,0,600,800);
   gen_5->SetHighLightColor(2);
   gen_5->Range(0,0,1,1);
   gen_5->SetFillColor(0);
   gen_5->SetBorderMode(0);
   gen_5->SetBorderSize(2);
   gen_5->SetFrameBorderMode(0);
   
   TH1D *frame_96f6c70__25 = new TH1D("frame_96f6c70__25","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_96f6c70__25->SetBinContent(1,29.14943);
   frame_96f6c70__25->SetMaximum(29.14943);
   frame_96f6c70__25->SetEntries(1);
   frame_96f6c70__25->SetDirectory(0);
   frame_96f6c70__25->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_96f6c70__25->SetLineColor(ci);
   frame_96f6c70__25->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_96f6c70__25->GetXaxis()->SetLabelFont(42);
   frame_96f6c70__25->GetXaxis()->SetLabelSize(0.035);
   frame_96f6c70__25->GetXaxis()->SetTitleSize(0.035);
   frame_96f6c70__25->GetXaxis()->SetTitleFont(42);
   frame_96f6c70__25->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_96f6c70__25->GetYaxis()->SetLabelFont(42);
   frame_96f6c70__25->GetYaxis()->SetLabelSize(0.035);
   frame_96f6c70__25->GetYaxis()->SetTitleSize(0.035);
   frame_96f6c70__25->GetYaxis()->SetTitleFont(42);
   frame_96f6c70__25->GetZaxis()->SetLabelFont(42);
   frame_96f6c70__25->GetZaxis()->SetLabelSize(0.035);
   frame_96f6c70__25->GetZaxis()->SetTitleSize(0.035);
   frame_96f6c70__25->GetZaxis()->SetTitleFont(42);
   frame_96f6c70__25->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(50);
   grae->SetName("h_ControlData");
   grae->SetTitle("Histogram of ControlData_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,20.5,14);
   grae->SetPointError(0,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(1,21.5,11);
   grae->SetPointError(1,0.5,0.5,3.265579,4.416521);
   grae->SetPoint(2,22.5,5);
   grae->SetPointError(2,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(3,23.5,11);
   grae->SetPointError(3,0.5,0.5,3.265579,4.416521);
   grae->SetPoint(4,24.5,10);
   grae->SetPointError(4,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(5,25.5,13);
   grae->SetPointError(5,0.5,0.5,3.558662,4.697573);
   grae->SetPoint(6,26.5,6);
   grae->SetPointError(6,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(7,27.5,9);
   grae->SetPointError(7,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(8,28.5,8);
   grae->SetPointError(8,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(9,29.5,6);
   grae->SetPointError(9,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(10,30.5,8);
   grae->SetPointError(10,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(11,31.5,5);
   grae->SetPointError(11,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(12,32.5,5);
   grae->SetPointError(12,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(13,33.5,11);
   grae->SetPointError(13,0.5,0.5,3.265579,4.416521);
   grae->SetPoint(14,34.5,8);
   grae->SetPointError(14,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(15,35.5,7);
   grae->SetPointError(15,0.5,0.5,2.58147,3.770281);
   grae->SetPoint(16,36.5,5);
   grae->SetPointError(16,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(17,37.5,16);
   grae->SetPointError(17,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(18,38.5,7);
   grae->SetPointError(18,0.5,0.5,2.58147,3.770281);
   grae->SetPoint(19,39.5,19);
   grae->SetPointError(19,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(20,40.5,10);
   grae->SetPointError(20,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(21,41.5,8);
   grae->SetPointError(21,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(22,42.5,9);
   grae->SetPointError(22,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(23,43.5,13);
   grae->SetPointError(23,0.5,0.5,3.558662,4.697573);
   grae->SetPoint(24,44.5,12);
   grae->SetPointError(24,0.5,0.5,3.415266,4.559819);
   grae->SetPoint(25,45.5,17);
   grae->SetPointError(25,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(26,46.5,19);
   grae->SetPointError(26,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(27,47.5,17);
   grae->SetPointError(27,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(28,48.5,13);
   grae->SetPointError(28,0.5,0.5,3.558662,4.697573);
   grae->SetPoint(29,49.5,17);
   grae->SetPointError(29,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(30,50.5,20);
   grae->SetPointError(30,0.5,0.5,4.434448,5.546519);
   grae->SetPoint(31,51.5,16);
   grae->SetPointError(31,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(32,52.5,10);
   grae->SetPointError(32,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(33,53.5,10);
   grae->SetPointError(33,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(34,54.5,18);
   grae->SetPointError(34,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(35,55.5,21);
   grae->SetPointError(35,0.5,0.5,4.545807,5.655182);
   grae->SetPoint(36,56.5,15);
   grae->SetPointError(36,0.5,0.5,3.82938,4.958738);
   grae->SetPoint(37,57.5,12);
   grae->SetPointError(37,0.5,0.5,3.415266,4.559819);
   grae->SetPoint(38,58.5,10);
   grae->SetPointError(38,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(39,59.5,12);
   grae->SetPointError(39,0.5,0.5,3.415266,4.559819);
   grae->SetPoint(40,60.5,6);
   grae->SetPointError(40,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(41,61.5,8);
   grae->SetPointError(41,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(42,62.5,9);
   grae->SetPointError(42,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(43,63.5,13);
   grae->SetPointError(43,0.5,0.5,3.558662,4.697573);
   grae->SetPoint(44,64.5,7);
   grae->SetPointError(44,0.5,0.5,2.58147,3.770281);
   grae->SetPoint(45,65.5,14);
   grae->SetPointError(45,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(46,66.5,22);
   grae->SetPointError(46,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(47,67.5,16);
   grae->SetPointError(47,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(48,68.5,16);
   grae->SetPointError(48,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(49,69.5,14);
   grae->SetPointError(49,0.5,0.5,3.6965,4.830381);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(106);
   graph->SetName("pdfext_5_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of pdfext_5");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,19.5,0);
   graph->SetPoint(1,19.5,8.884114252);
   graph->SetPoint(2,20,8.884114252);
   graph->SetPoint(3,20.5,8.856461036);
   graph->SetPoint(4,21,8.83444045);
   graph->SetPoint(5,21.5,8.817956211);
   graph->SetPoint(6,22,8.806910916);
   graph->SetPoint(7,22.5,8.801206021);
   graph->SetPoint(8,23,8.800741821);
   graph->SetPoint(9,23.5,8.805417426);
   graph->SetPoint(10,24,8.815130739);
   graph->SetPoint(11,24.5,8.829778434);
   graph->SetPoint(12,25,8.849255935);
   graph->SetPoint(13,25.5,8.873457392);
   graph->SetPoint(14,26,8.902275662);
   graph->SetPoint(15,26.5,8.935602282);
   graph->SetPoint(16,27,8.973327452);
   graph->SetPoint(17,27.5,9.01534001);
   graph->SetPoint(18,28,9.06152741);
   graph->SetPoint(19,28.5,9.1117757);
   graph->SetPoint(20,29,9.165969502);
   graph->SetPoint(21,29.5,9.223991988);
   graph->SetPoint(22,30,9.285724857);
   graph->SetPoint(23,30.5,9.351048314);
   graph->SetPoint(24,31,9.41984105);
   graph->SetPoint(25,31.5,9.491980215);
   graph->SetPoint(26,32,9.567341401);
   graph->SetPoint(27,32.5,9.645798617);
   graph->SetPoint(28,33,9.727224267);
   graph->SetPoint(29,33.5,9.811489129);
   graph->SetPoint(30,34,9.898462332);
   graph->SetPoint(31,34.5,9.988011335);
   graph->SetPoint(32,35,10.0800019);
   graph->SetPoint(33,35.5,10.17429809);
   graph->SetPoint(34,36,10.2707622);
   graph->SetPoint(35,36.5,10.3692548);
   graph->SetPoint(36,37,10.46963465);
   graph->SetPoint(37,37.5,10.57175874);
   graph->SetPoint(38,38,10.67548219);
   graph->SetPoint(39,38.5,10.78065832);
   graph->SetPoint(40,39,10.88713854);
   graph->SetPoint(41,39.5,10.99477239);
   graph->SetPoint(42,40,11.10340749);
   graph->SetPoint(43,40.5,11.21288953);
   graph->SetPoint(44,41,11.32306224);
   graph->SetPoint(45,41.5,11.43376737);
   graph->SetPoint(46,42,11.54484465);
   graph->SetPoint(47,42.5,11.65613182);
   graph->SetPoint(48,43,11.76746454);
   graph->SetPoint(49,43.5,11.87867642);
   graph->SetPoint(50,44,11.98959898);
   graph->SetPoint(51,44.5,12.10006162);
   graph->SetPoint(52,45,12.2098916);
   graph->SetPoint(53,45.5,12.31891405);
   graph->SetPoint(54,46,12.42695188);
   graph->SetPoint(55,46.5,12.53382583);
   graph->SetPoint(56,47,12.63935442);
   graph->SetPoint(57,47.5,12.74335389);
   graph->SetPoint(58,48,12.84563825);
   graph->SetPoint(59,48.5,12.94601919);
   graph->SetPoint(60,49,13.04430613);
   graph->SetPoint(61,49.5,13.1403061);
   graph->SetPoint(62,50,13.23382382);
   graph->SetPoint(63,50.5,13.32466162);
   graph->SetPoint(64,51,13.41261941);
   graph->SetPoint(65,51.5,13.49749471);
   graph->SetPoint(66,52,13.57908258);
   graph->SetPoint(67,52.5,13.65717559);
   graph->SetPoint(68,53,13.73156387);
   graph->SetPoint(69,53.5,13.80203501);
   graph->SetPoint(70,54,13.86837406);
   graph->SetPoint(71,54.5,13.93036354);
   graph->SetPoint(72,55,13.98778337);
   graph->SetPoint(73,55.5,14.04041089);
   graph->SetPoint(74,56,14.0880208);
   graph->SetPoint(75,56.5,14.13038517);
   graph->SetPoint(76,57,14.16727341);
   graph->SetPoint(77,57.5,14.19845223);
   graph->SetPoint(78,58,14.22368564);
   graph->SetPoint(79,58.5,14.2427349);
   graph->SetPoint(80,59,14.25535854);
   graph->SetPoint(81,59.5,14.2613123);
   graph->SetPoint(82,60,14.26034913);
   graph->SetPoint(83,60.5,14.25221915);
   graph->SetPoint(84,61,14.23666966);
   graph->SetPoint(85,61.5,14.21344506);
   graph->SetPoint(86,62,14.1822869);
   graph->SetPoint(87,62.5,14.14293379);
   graph->SetPoint(88,63,14.09512144);
   graph->SetPoint(89,63.5,14.03858259);
   graph->SetPoint(90,64,13.97304701);
   graph->SetPoint(91,64.5,13.89824146);
   graph->SetPoint(92,65,13.8138897);
   graph->SetPoint(93,65.5,13.71971244);
   graph->SetPoint(94,66,13.61542733);
   graph->SetPoint(95,66.5,13.50074893);
   graph->SetPoint(96,67,13.37538871);
   graph->SetPoint(97,67.5,13.23905498);
   graph->SetPoint(98,68,13.09145292);
   graph->SetPoint(99,68.5,12.93228454);
   graph->SetPoint(100,69,12.76124864);
   graph->SetPoint(101,69.5,12.57804081);
   graph->SetPoint(102,70,12.3823534);
   graph->SetPoint(103,70,12.3823534);
   graph->SetPoint(104,70.5,12.3823534);
   graph->SetPoint(105,70.5,0);
   graph->Draw("l");
   
   TH1D *frame_96f6c70__26 = new TH1D("frame_96f6c70__26","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_96f6c70__26->SetBinContent(1,29.14943);
   frame_96f6c70__26->SetMaximum(29.14943);
   frame_96f6c70__26->SetEntries(1);
   frame_96f6c70__26->SetDirectory(0);
   frame_96f6c70__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_96f6c70__26->SetLineColor(ci);
   frame_96f6c70__26->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_96f6c70__26->GetXaxis()->SetLabelFont(42);
   frame_96f6c70__26->GetXaxis()->SetLabelSize(0.035);
   frame_96f6c70__26->GetXaxis()->SetTitleSize(0.035);
   frame_96f6c70__26->GetXaxis()->SetTitleFont(42);
   frame_96f6c70__26->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_96f6c70__26->GetYaxis()->SetLabelFont(42);
   frame_96f6c70__26->GetYaxis()->SetLabelSize(0.035);
   frame_96f6c70__26->GetYaxis()->SetTitleSize(0.035);
   frame_96f6c70__26->GetYaxis()->SetTitleFont(42);
   frame_96f6c70__26->GetZaxis()->SetLabelFont(42);
   frame_96f6c70__26->GetZaxis()->SetLabelSize(0.035);
   frame_96f6c70__26->GetZaxis()->SetTitleSize(0.035);
   frame_96f6c70__26->GetZaxis()->SetTitleFont(42);
   frame_96f6c70__26->Draw("AXISSAME");
   gen_5->Modified();
   gen_5->cd();
   gen_5->SetSelected(gen_5);
}
