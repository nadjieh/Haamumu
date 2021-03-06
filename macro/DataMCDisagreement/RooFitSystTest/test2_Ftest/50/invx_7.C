{
//=========Macro generated from canvas: invx_7/invx_7
//=========  (Sun Mar  1 11:43:04 2015) by ROOT version5.34/19
   TCanvas *invx_7 = new TCanvas("invx_7", "invx_7",0,0,600,800);
   invx_7->SetHighLightColor(2);
   invx_7->Range(0,0,1,1);
   invx_7->SetFillColor(0);
   invx_7->SetBorderMode(0);
   invx_7->SetBorderSize(2);
   invx_7->SetFrameBorderMode(0);
   
   TH1D *frame_123568f0__21 = new TH1D("frame_123568f0__21","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_123568f0__21->SetBinContent(1,39.50898);
   frame_123568f0__21->SetMaximum(39.50898);
   frame_123568f0__21->SetEntries(1);
   frame_123568f0__21->SetDirectory(0);
   frame_123568f0__21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_123568f0__21->SetLineColor(ci);
   frame_123568f0__21->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_123568f0__21->GetXaxis()->SetLabelFont(42);
   frame_123568f0__21->GetXaxis()->SetLabelSize(0.035);
   frame_123568f0__21->GetXaxis()->SetTitleSize(0.035);
   frame_123568f0__21->GetXaxis()->SetTitleFont(42);
   frame_123568f0__21->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_123568f0__21->GetYaxis()->SetLabelFont(42);
   frame_123568f0__21->GetYaxis()->SetLabelSize(0.035);
   frame_123568f0__21->GetYaxis()->SetTitleSize(0.035);
   frame_123568f0__21->GetYaxis()->SetTitleFont(42);
   frame_123568f0__21->GetZaxis()->SetLabelFont(42);
   frame_123568f0__21->GetZaxis()->SetLabelSize(0.035);
   frame_123568f0__21->GetZaxis()->SetTitleSize(0.035);
   frame_123568f0__21->GetZaxis()->SetTitleFont(42);
   frame_123568f0__21->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(50);
   grae->SetName("h_ControlData");
   grae->SetTitle("Histogram of ControlData_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,20.5,28);
   grae->SetPointError(0,0.5,0.5,5.259711,6.354446);
   grae->SetPoint(1,21.5,25);
   grae->SetPointError(1,0.5,0.5,4.966335,6.066589);
   grae->SetPoint(2,22.5,27);
   grae->SetPointError(2,0.5,0.5,5.163771,6.260244);
   grae->SetPoint(3,23.5,26);
   grae->SetPointError(3,0.5,0.5,5.066015,6.164324);
   grae->SetPoint(4,24.5,23);
   grae->SetPointError(4,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(5,25.5,31);
   grae->SetPointError(5,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(6,26.5,23);
   grae->SetPointError(6,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(7,27.5,31);
   grae->SetPointError(7,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(8,28.5,20);
   grae->SetPointError(8,0.5,0.5,4.434448,5.546519);
   grae->SetPoint(9,29.5,26);
   grae->SetPointError(9,0.5,0.5,5.066015,6.164324);
   grae->SetPoint(10,30.5,25);
   grae->SetPointError(10,0.5,0.5,4.966335,6.066589);
   grae->SetPoint(11,31.5,19);
   grae->SetPointError(11,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(12,32.5,24);
   grae->SetPointError(12,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(13,33.5,23);
   grae->SetPointError(13,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(14,34.5,31);
   grae->SetPointError(14,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(15,35.5,27);
   grae->SetPointError(15,0.5,0.5,5.163771,6.260244);
   grae->SetPoint(16,36.5,26);
   grae->SetPointError(16,0.5,0.5,5.066015,6.164324);
   grae->SetPoint(17,37.5,31);
   grae->SetPointError(17,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(18,38.5,20);
   grae->SetPointError(18,0.5,0.5,4.434448,5.546519);
   grae->SetPoint(19,39.5,31);
   grae->SetPointError(19,0.5,0.5,5.537565,6.627601);
   grae->SetPoint(20,40.5,15);
   grae->SetPointError(20,0.5,0.5,3.82938,4.958738);
   grae->SetPoint(21,41.5,29);
   grae->SetPointError(21,0.5,0.5,5.353932,6.44702);
   grae->SetPoint(22,42.5,18);
   grae->SetPointError(22,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(23,43.5,26);
   grae->SetPointError(23,0.5,0.5,5.066015,6.164324);
   grae->SetPoint(24,44.5,15);
   grae->SetPointError(24,0.5,0.5,3.82938,4.958738);
   grae->SetPoint(25,45.5,30);
   grae->SetPointError(25,0.5,0.5,5.446522,6.538046);
   grae->SetPoint(26,46.5,29);
   grae->SetPointError(26,0.5,0.5,5.353932,6.44702);
   grae->SetPoint(27,47.5,22);
   grae->SetPointError(27,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(28,48.5,17);
   grae->SetPointError(28,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(29,49.5,21);
   grae->SetPointError(29,0.5,0.5,4.545807,5.655182);
   grae->SetPoint(30,50.5,29);
   grae->SetPointError(30,0.5,0.5,5.353932,6.44702);
   grae->SetPoint(31,51.5,21);
   grae->SetPointError(31,0.5,0.5,4.545807,5.655182);
   grae->SetPoint(32,52.5,14);
   grae->SetPointError(32,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(33,53.5,17);
   grae->SetPointError(33,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(34,54.5,20);
   grae->SetPointError(34,0.5,0.5,4.434448,5.546519);
   grae->SetPoint(35,55.5,24);
   grae->SetPointError(35,0.5,0.5,4.864612,5.966932);
   grae->SetPoint(36,56.5,21);
   grae->SetPointError(36,0.5,0.5,4.545807,5.655182);
   grae->SetPoint(37,57.5,14);
   grae->SetPointError(37,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(38,58.5,9);
   grae->SetPointError(38,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(39,59.5,17);
   grae->SetPointError(39,0.5,0.5,4.082184,5.203719);
   grae->SetPoint(40,60.5,7);
   grae->SetPointError(40,0.5,0.5,2.58147,3.770281);
   grae->SetPoint(41,61.5,9);
   grae->SetPointError(41,0.5,0.5,2.943461,4.110204);
   grae->SetPoint(42,62.5,12);
   grae->SetPointError(42,0.5,0.5,3.415266,4.559819);
   grae->SetPoint(43,63.5,14);
   grae->SetPointError(43,0.5,0.5,3.6965,4.830381);
   grae->SetPoint(44,64.5,11);
   grae->SetPointError(44,0.5,0.5,3.265579,4.416521);
   grae->SetPoint(45,65.5,16);
   grae->SetPointError(45,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(46,66.5,23);
   grae->SetPointError(46,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(47,67.5,16);
   grae->SetPointError(47,0.5,0.5,3.957801,5.083066);
   grae->SetPoint(48,68.5,18);
   grae->SetPointError(48,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(49,69.5,16);
   grae->SetPointError(49,0.5,0.5,3.957801,5.083066);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(106);
   graph->SetName("pdfext_7_Norm[eventSelectionamassMu]");
   graph->SetTitle("Projection of pdfext_7");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,19.5,0);
   graph->SetPoint(1,19.5,30.63282337);
   graph->SetPoint(2,20,30.63282337);
   graph->SetPoint(3,20.5,30.18083806);
   graph->SetPoint(4,21,29.75464433);
   graph->SetPoint(5,21.5,29.3524553);
   graph->SetPoint(6,22,28.97264271);
   graph->SetPoint(7,22.5,28.61371891);
   graph->SetPoint(8,23,28.27432125);
   graph->SetPoint(9,23.5,27.95319847);
   graph->SetPoint(10,24,27.64919868);
   graph->SetPoint(11,24.5,27.3612589);
   graph->SetPoint(12,25,27.08839572);
   graph->SetPoint(13,25.5,26.82969715);
   graph->SetPoint(14,26,26.58431534);
   graph->SetPoint(15,26.5,26.35146008);
   graph->SetPoint(16,27,26.13039304);
   graph->SetPoint(17,27.5,25.92042263);
   graph->SetPoint(18,28,25.72089933);
   graph->SetPoint(19,28.5,25.53121159);
   graph->SetPoint(20,29,25.35078204);
   graph->SetPoint(21,29.5,25.17906414);
   graph->SetPoint(22,30,25.01553908);
   graph->SetPoint(23,30.5,24.85971307);
   graph->SetPoint(24,31,24.71111478);
   graph->SetPoint(25,31.5,24.56929307);
   graph->SetPoint(26,32,24.43381489);
   graph->SetPoint(27,32.5,24.3042634);
   graph->SetPoint(28,33,24.18023625);
   graph->SetPoint(29,33.5,24.06134397);
   graph->SetPoint(30,34,23.94720854);
   graph->SetPoint(31,34.5,23.8374621);
   graph->SetPoint(32,35,23.73174572);
   graph->SetPoint(33,35.5,23.62970838);
   graph->SetPoint(34,36,23.53100589);
   graph->SetPoint(35,36.5,23.43530012);
   graph->SetPoint(36,37,23.34225814);
   graph->SetPoint(37,37.5,23.25155156);
   graph->SetPoint(38,38,23.16285591);
   graph->SetPoint(39,38.5,23.0758501);
   graph->SetPoint(40,39,22.99021604);
   graph->SetPoint(41,39.5,22.90563819);
   graph->SetPoint(42,40,22.8218034);
   graph->SetPoint(43,40.5,22.73840061);
   graph->SetPoint(44,41,22.65512082);
   graph->SetPoint(45,41.5,22.57165703);
   graph->SetPoint(46,42,22.4877043);
   graph->SetPoint(47,42.5,22.40295988);
   graph->SetPoint(48,43,22.31712345);
   graph->SetPoint(49,43.5,22.22989742);
   graph->SetPoint(50,44,22.14098731);
   graph->SetPoint(51,44.5,22.05010221);
   graph->SetPoint(52,45,21.95695538);
   graph->SetPoint(53,45.5,21.86126481);
   graph->SetPoint(54,46,21.76275397);
   graph->SetPoint(55,46.5,21.66115256);
   graph->SetPoint(56,47,21.5561974);
   graph->SetPoint(57,47.5,21.44763328);
   graph->SetPoint(58,48,21.33521397);
   graph->SetPoint(59,48.5,21.21870322);
   graph->SetPoint(60,49,21.09787582);
   graph->SetPoint(61,49.5,20.97251869);
   graph->SetPoint(62,50,20.84243198);
   graph->SetPoint(63,50.5,20.70743022);
   graph->SetPoint(64,51,20.56734342);
   graph->SetPoint(65,51.5,20.42201815);
   graph->SetPoint(66,52,20.27131867);
   graph->SetPoint(67,52.5,20.11512793);
   graph->SetPoint(68,53,19.95334853);
   graph->SetPoint(69,53.5,19.78590364);
   graph->SetPoint(70,54,19.61273781);
   graph->SetPoint(71,54.5,19.43381768);
   graph->SetPoint(72,55,19.24913254);
   graph->SetPoint(73,55.5,19.05869486);
   graph->SetPoint(74,56,18.86254055);
   graph->SetPoint(75,56.5,18.66072914);
   graph->SetPoint(76,57,18.45334383);
   graph->SetPoint(77,57.5,18.24049131);
   graph->SetPoint(78,58,18.02230144);
   graph->SetPoint(79,58.5,17.79892676);
   graph->SetPoint(80,59,17.57054182);
   graph->SetPoint(81,59.5,17.33734235);
   graph->SetPoint(82,60,17.09954428);
   graph->SetPoint(83,60.5,16.85738257);
   graph->SetPoint(84,61,16.61110993);
   graph->SetPoint(85,61.5,16.36099539);
   graph->SetPoint(86,62,16.10732276);
   graph->SetPoint(87,62.5,15.85038901);
   graph->SetPoint(88,63,15.59050249);
   graph->SetPoint(89,63.5,15.32798122);
   graph->SetPoint(90,64,15.06315098);
   graph->SetPoint(91,64.5,14.79634352);
   graph->SetPoint(92,65,14.52789462);
   graph->SetPoint(93,65.5,14.25814232);
   graph->SetPoint(94,66,13.98742504);
   graph->SetPoint(95,66.5,13.71607983);
   graph->SetPoint(96,67,13.44444068);
   graph->SetPoint(97,67.5,13.17283687);
   graph->SetPoint(98,68,12.90159148);
   graph->SetPoint(99,68.5,12.63101992);
   graph->SetPoint(100,69,12.36142866);
   graph->SetPoint(101,69.5,12.09311403);
   graph->SetPoint(102,70,11.82636115);
   graph->SetPoint(103,70,11.82636115);
   graph->SetPoint(104,70.5,11.82636115);
   graph->SetPoint(105,70.5,0);
   graph->Draw("l");
   
   TH1D *frame_123568f0__22 = new TH1D("frame_123568f0__22","A RooPlot of \"eventSelectionamassMu\"",100,20,70);
   frame_123568f0__22->SetBinContent(1,39.50898);
   frame_123568f0__22->SetMaximum(39.50898);
   frame_123568f0__22->SetEntries(1);
   frame_123568f0__22->SetDirectory(0);
   frame_123568f0__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_123568f0__22->SetLineColor(ci);
   frame_123568f0__22->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_123568f0__22->GetXaxis()->SetLabelFont(42);
   frame_123568f0__22->GetXaxis()->SetLabelSize(0.035);
   frame_123568f0__22->GetXaxis()->SetTitleSize(0.035);
   frame_123568f0__22->GetXaxis()->SetTitleFont(42);
   frame_123568f0__22->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_123568f0__22->GetYaxis()->SetLabelFont(42);
   frame_123568f0__22->GetYaxis()->SetLabelSize(0.035);
   frame_123568f0__22->GetYaxis()->SetTitleSize(0.035);
   frame_123568f0__22->GetYaxis()->SetTitleFont(42);
   frame_123568f0__22->GetZaxis()->SetLabelFont(42);
   frame_123568f0__22->GetZaxis()->SetLabelSize(0.035);
   frame_123568f0__22->GetZaxis()->SetTitleSize(0.035);
   frame_123568f0__22->GetZaxis()->SetTitleFont(42);
   frame_123568f0__22->Draw("AXISSAME");
   invx_7->Modified();
   invx_7->cd();
   invx_7->SetSelected(invx_7);
}
