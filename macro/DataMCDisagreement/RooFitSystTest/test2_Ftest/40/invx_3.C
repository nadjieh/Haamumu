{
//=========Macro generated from canvas: invx_3/invx_3
//=========  (Sun Feb 22 16:14:52 2015) by ROOT version5.34/19
   TCanvas *invx_3 = new TCanvas("invx_3", "invx_3",0,0,600,800);
   invx_3->SetHighLightColor(2);
   invx_3->Range(0,0,1,1);
   invx_3->SetFillColor(0);
   invx_3->SetBorderMode(0);
   invx_3->SetBorderSize(2);
   invx_3->SetFrameBorderMode(0);
   
   TH1D *frame_e95e2f0__3 = new TH1D("frame_e95e2f0__3","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_e95e2f0__3->SetBinContent(1,41.7927);
   frame_e95e2f0__3->SetMaximum(41.7927);
   frame_e95e2f0__3->SetEntries(1);
   frame_e95e2f0__3->SetDirectory(0);
   frame_e95e2f0__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_e95e2f0__3->SetLineColor(ci);
   frame_e95e2f0__3->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_e95e2f0__3->GetXaxis()->SetLabelFont(42);
   frame_e95e2f0__3->GetXaxis()->SetLabelSize(0.035);
   frame_e95e2f0__3->GetXaxis()->SetTitleSize(0.035);
   frame_e95e2f0__3->GetXaxis()->SetTitleFont(42);
   frame_e95e2f0__3->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_e95e2f0__3->GetYaxis()->SetLabelFont(42);
   frame_e95e2f0__3->GetYaxis()->SetLabelSize(0.035);
   frame_e95e2f0__3->GetYaxis()->SetTitleSize(0.035);
   frame_e95e2f0__3->GetYaxis()->SetTitleFont(42);
   frame_e95e2f0__3->GetZaxis()->SetLabelFont(42);
   frame_e95e2f0__3->GetZaxis()->SetLabelSize(0.035);
   frame_e95e2f0__3->GetZaxis()->SetTitleSize(0.035);
   frame_e95e2f0__3->GetZaxis()->SetTitleFont(42);
   frame_e95e2f0__3->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(50);
   grae->SetName("h_ControlData");
   grae->SetTitle("Histogram of ControlData_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,20.5,28);
   grae->SetPointError(0,0.5,0.5,5.259711,6.354446);
   grae->SetPoint(1,21.5,24);
   grae->SetPointError(1,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(2,22.5,22);
   grae->SetPointError(2,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(3,23.5,18);
   grae->SetPointError(3,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(4,24.5,24);
   grae->SetPointError(4,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(5,25.5,31);
   grae->SetPointError(5,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(6,26.5,22);
   grae->SetPointError(6,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(7,27.5,31);
   grae->SetPointError(7,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(8,28.5,24);
   grae->SetPointError(8,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(9,29.5,22);
   grae->SetPointError(9,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(10,30.5,18);
   grae->SetPointError(10,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(11,31.5,20);
   grae->SetPointError(11,0.5,0.5,4.434448,5.546519);
   grae->SetPoint(12,32.5,24);
   grae->SetPointError(12,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(13,33.5,24);
   grae->SetPointError(13,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(14,34.5,33);
   grae->SetPointError(14,0.5,0.5,5.715302,6.802567);
   grae->SetPoint(15,35.5,28);
   grae->SetPointError(15,0.5,0.5,5.259711,6.354446);
   grae->SetPoint(16,36.5,22);
   grae->SetPointError(16,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(17,37.5,32);
   grae->SetPointError(17,0.5,0.5,5.627135,6.715753);
   grae->SetPoint(18,38.5,16);
   grae->SetPointError(18,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(19,39.5,28);
   grae->SetPointError(19,0.5,0.5,5.259711,6.354446);
   grae->SetPoint(20,40.5,17);
   grae->SetPointError(20,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(21,41.5,28);
   grae->SetPointError(21,0.5,0.5,5.259711,6.354446);
   grae->SetPoint(22,42.5,19);
   grae->SetPointError(22,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(23,43.5,22);
   grae->SetPointError(23,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(24,44.5,15);
   grae->SetPointError(24,0.5,0.5,3.82938,4.958738);
   grae->SetPoint(25,45.5,26);
   grae->SetPointError(25,0.5,0.5,5.066015,6.164324);
   grae->SetPoint(26,46.5,23);
   grae->SetPointError(26,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(27,47.5,19);
   grae->SetPointError(27,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(28,48.5,14);
   grae->SetPointError(28,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(29,49.5,19);
   grae->SetPointError(29,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(30,50.5,23);
   grae->SetPointError(30,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(31,51.5,17);
   grae->SetPointError(31,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(32,52.5,14);
   grae->SetPointError(32,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(33,53.5,13);
   grae->SetPointError(33,0.5,0.5,3.558662,4.697573);
   grae->SetPoint(34,54.5,17);
   grae->SetPointError(34,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(35,55.5,24);
   grae->SetPointError(35,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(36,56.5,19);
   grae->SetPointError(36,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(37,57.5,8);
   grae->SetPointError(37,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(38,58.5,9);
   grae->SetPointError(38,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(39,59.5,18);
   grae->SetPointError(39,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(40,60.5,5);
   grae->SetPointError(40,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(41,61.5,9);
   grae->SetPointError(41,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(42,62.5,9);
   grae->SetPointError(42,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(43,63.5,8);
   grae->SetPointError(43,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(44,64.5,8);
   grae->SetPointError(44,0.5,0.5,2.768386,3.945142);
   grae->SetPoint(45,65.5,16);
   grae->SetPointError(45,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(46,66.5,21);
   grae->SetPointError(46,0.5,0.5,4.545807,5.655182);
   grae->SetPoint(47,67.5,15);
   grae->SetPointError(47,0.5,0.5,3.82938,4.958738);
   grae->SetPoint(48,68.5,16);
   grae->SetPointError(48,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(49,69.5,13);
   grae->SetPointError(49,0.5,0.5,3.558662,4.697573);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(106);
   graph->SetName("pdfext_3_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of pdfext_3");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,19.5,0);
   graph->SetPoint(1,19.5,27.51239636);
   graph->SetPoint(2,20,27.51239636);
   graph->SetPoint(3,20.5,27.2190333);
   graph->SetPoint(4,21,26.94360425);
   graph->SetPoint(5,21.5,26.68475374);
   graph->SetPoint(6,22,26.44123817);
   graph->SetPoint(7,22.5,26.21191288);
   graph->SetPoint(8,23,25.99572085);
   graph->SetPoint(9,23.5,25.79168292);
   graph->SetPoint(10,24,25.59888921);
   graph->SetPoint(11,24.5,25.41649156);
   graph->SetPoint(12,25,25.24369694);
   graph->SetPoint(13,25.5,25.07976165);
   graph->SetPoint(14,26,24.92398615);
   graph->SetPoint(15,26.5,24.77571059);
   graph->SetPoint(16,27,24.63431077);
   graph->SetPoint(17,27.5,24.49919463);
   graph->SetPoint(18,28,24.36979913);
   graph->SetPoint(19,28.5,24.24558752);
   graph->SetPoint(20,29,24.12604688);
   graph->SetPoint(21,29.5,24.01068604);
   graph->SetPoint(22,30,23.89903366);
   graph->SetPoint(23,30.5,23.79063665);
   graph->SetPoint(24,31,23.68505874);
   graph->SetPoint(25,31.5,23.58187928);
   graph->SetPoint(26,32,23.48069217);
   graph->SetPoint(27,32.5,23.38110506);
   graph->SetPoint(28,33,23.28273857);
   graph->SetPoint(29,33.5,23.18522575);
   graph->SetPoint(30,34,23.08821163);
   graph->SetPoint(31,34.5,22.99135288);
   graph->SetPoint(32,35,22.89431761);
   graph->SetPoint(33,35.5,22.79678522);
   graph->SetPoint(34,36,22.69844641);
   graph->SetPoint(35,36.5,22.59900322);
   graph->SetPoint(36,37,22.49816913);
   graph->SetPoint(37,37.5,22.39566931);
   graph->SetPoint(38,38,22.29124084);
   graph->SetPoint(39,38.5,22.184633);
   graph->SetPoint(40,39,22.07560767);
   graph->SetPoint(41,39.5,21.96393966);
   graph->SetPoint(42,40,21.84941711);
   graph->SetPoint(43,40.5,21.73184196);
   graph->SetPoint(44,41,21.61103033);
   graph->SetPoint(45,41.5,21.48681296);
   graph->SetPoint(46,42,21.35903561);
   graph->SetPoint(47,42.5,21.22755949);
   graph->SetPoint(48,43,21.09226159);
   graph->SetPoint(49,43.5,20.95303506);
   graph->SetPoint(50,44,20.80978943);
   graph->SetPoint(51,44.5,20.66245094);
   graph->SetPoint(52,45,20.51096262);
   graph->SetPoint(53,45.5,20.35528453);
   graph->SetPoint(54,46,20.19539369);
   graph->SetPoint(55,46.5,20.03128416);
   graph->SetPoint(56,47,19.86296686);
   graph->SetPoint(57,47.5,19.69046947);
   graph->SetPoint(58,48,19.5138361);
   graph->SetPoint(59,48.5,19.333127);
   graph->SetPoint(60,49,19.14841812);
   graph->SetPoint(61,49.5,18.95980059);
   graph->SetPoint(62,50,18.76738018);
   graph->SetPoint(63,50.5,18.5712766);
   graph->SetPoint(64,51,18.37162282);
   graph->SetPoint(65,51.5,18.16856423);
   graph->SetPoint(66,52,17.96225783);
   graph->SetPoint(67,52.5,17.75287134);
   graph->SetPoint(68,53,17.54058221);
   graph->SetPoint(69,53.5,17.32557664);
   graph->SetPoint(70,54,17.10804863);
   graph->SetPoint(71,54.5,16.88819888);
   graph->SetPoint(72,55,16.66623377);
   graph->SetPoint(73,55.5,16.44236431);
   graph->SetPoint(74,56,16.21680511);
   graph->SetPoint(75,56.5,15.98977331);
   graph->SetPoint(76,57,15.76148763);
   graph->SetPoint(77,57.5,15.5321673);
   graph->SetPoint(78,58,15.30203118);
   graph->SetPoint(79,58.5,15.07129682);
   graph->SetPoint(80,59,14.8401796);
   graph->SetPoint(81,59.5,14.60889189);
   graph->SetPoint(82,60,14.3776423);
   graph->SetPoint(83,60.5,14.146635);
   graph->SetPoint(84,61,13.91606902);
   graph->SetPoint(85,61.5,13.68613769);
   graph->SetPoint(86,62,13.45702811);
   graph->SetPoint(87,62.5,13.22892069);
   graph->SetPoint(88,63,13.00198873);
   graph->SetPoint(89,63.5,12.77639808);
   graph->SetPoint(90,64,12.55230689);
   graph->SetPoint(91,64.5,12.32986533);
   graph->SetPoint(92,65,12.10921547);
   graph->SetPoint(93,65.5,11.89049111);
   graph->SetPoint(94,66,11.67381778);
   graph->SetPoint(95,66.5,11.45931265);
   graph->SetPoint(96,67,11.24708459);
   graph->SetPoint(97,67.5,11.03723423);
   graph->SetPoint(98,68,10.82985406);
   graph->SetPoint(99,68.5,10.62502853);
   graph->SetPoint(100,69,10.42283426);
   graph->SetPoint(101,69.5,10.22334021);
   graph->SetPoint(102,70,10.02660786);
   graph->SetPoint(103,70,10.02660786);
   graph->SetPoint(104,70.5,10.02660786);
   graph->SetPoint(105,70.5,0);
   graph->Draw("l");
   
   TH1D *frame_e95e2f0__4 = new TH1D("frame_e95e2f0__4","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_e95e2f0__4->SetBinContent(1,41.7927);
   frame_e95e2f0__4->SetMaximum(41.7927);
   frame_e95e2f0__4->SetEntries(1);
   frame_e95e2f0__4->SetDirectory(0);
   frame_e95e2f0__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_e95e2f0__4->SetLineColor(ci);
   frame_e95e2f0__4->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_e95e2f0__4->GetXaxis()->SetLabelFont(42);
   frame_e95e2f0__4->GetXaxis()->SetLabelSize(0.035);
   frame_e95e2f0__4->GetXaxis()->SetTitleSize(0.035);
   frame_e95e2f0__4->GetXaxis()->SetTitleFont(42);
   frame_e95e2f0__4->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_e95e2f0__4->GetYaxis()->SetLabelFont(42);
   frame_e95e2f0__4->GetYaxis()->SetLabelSize(0.035);
   frame_e95e2f0__4->GetYaxis()->SetTitleSize(0.035);
   frame_e95e2f0__4->GetYaxis()->SetTitleFont(42);
   frame_e95e2f0__4->GetZaxis()->SetLabelFont(42);
   frame_e95e2f0__4->GetZaxis()->SetLabelSize(0.035);
   frame_e95e2f0__4->GetZaxis()->SetTitleSize(0.035);
   frame_e95e2f0__4->GetZaxis()->SetTitleFont(42);
   frame_e95e2f0__4->Draw("AXISSAME");
   invx_3->Modified();
   invx_3->cd();
   invx_3->SetSelected(invx_3);
}
