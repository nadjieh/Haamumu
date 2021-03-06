{
//=========Macro generated from canvas: c1_n4/c1_n4
//=========  (Tue Dec 30 19:12:02 2014) by ROOT version5.34/19
   TCanvas *c1_n4 = new TCanvas("c1_n4", "c1_n4",13,34,700,500);
   c1_n4->Range(0,0,1,1);
   c1_n4->SetFillColor(0);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetFrameBorderMode(0);
   
   TH1D *frame_7cf19a0__7 = new TH1D("frame_7cf19a0__7","High stats histogram pdf with interpolation",110,10,120);
   frame_7cf19a0__7->SetBinContent(1,14185.75);
   frame_7cf19a0__7->SetMaximum(14185.75);
   frame_7cf19a0__7->SetEntries(1);
   frame_7cf19a0__7->SetDirectory(0);
   frame_7cf19a0__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_7cf19a0__7->SetLineColor(ci);
   frame_7cf19a0__7->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_7cf19a0__7->GetXaxis()->SetLabelFont(42);
   frame_7cf19a0__7->GetXaxis()->SetLabelSize(0.035);
   frame_7cf19a0__7->GetXaxis()->SetTitleSize(0.035);
   frame_7cf19a0__7->GetXaxis()->SetTitleFont(42);
   frame_7cf19a0__7->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_7cf19a0__7->GetYaxis()->SetLabelFont(42);
   frame_7cf19a0__7->GetYaxis()->SetLabelSize(0.035);
   frame_7cf19a0__7->GetYaxis()->SetTitleSize(0.035);
   frame_7cf19a0__7->GetYaxis()->SetTitleFont(42);
   frame_7cf19a0__7->GetZaxis()->SetLabelFont(42);
   frame_7cf19a0__7->GetZaxis()->SetLabelSize(0.035);
   frame_7cf19a0__7->GetZaxis()->SetTitleSize(0.035);
   frame_7cf19a0__7->GetZaxis()->SetTitleFont(42);
   frame_7cf19a0__7->Draw("FUNC");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(110);
   grae->SetName("h_test_bkgData_binned");
   grae->SetTitle("Histogram of test_bkgData_binned_plot__eventSelectionamassMu");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,10.5,13394);
   grae->SetPointError(0,0.5,0.5,115.2335,116.2335);
   grae->SetPoint(1,11.5,11449);
   grae->SetPointError(1,0.5,0.5,106.5012,107.5012);
   grae->SetPoint(2,12.5,10059);
   grae->SetPointError(2,0.5,0.5,99.79581,100.7958);
   grae->SetPoint(3,13.5,8847);
   grae->SetPointError(3,0.5,0.5,93.55982,94.55982);
   grae->SetPoint(4,14.5,7476);
   grae->SetPointError(4,0.5,0.5,85.96531,86.96531);
   grae->SetPoint(5,15.5,6482);
   grae->SetPointError(5,0.5,0.5,80.01242,81.01242);
   grae->SetPoint(6,16.5,5660);
   grae->SetPointError(6,0.5,0.5,74.73463,75.73463);
   grae->SetPoint(7,17.5,4919);
   grae->SetPointError(7,0.5,0.5,69.63737,70.63737);
   grae->SetPoint(8,18.5,4241);
   grae->SetPointError(8,0.5,0.5,64.62488,65.62488);
   grae->SetPoint(9,19.5,3665);
   grae->SetPointError(9,0.5,0.5,60.04131,61.04131);
   grae->SetPoint(10,20.5,3184);
   grae->SetPointError(10,0.5,0.5,55.92916,56.92916);
   grae->SetPoint(11,21.5,2718);
   grae->SetPointError(11,0.5,0.5,51.63684,52.63684);
   grae->SetPoint(12,22.5,2435);
   grae->SetPointError(12,0.5,0.5,48.84825,49.84825);
   grae->SetPoint(13,23.5,2102);
   grae->SetPointError(13,0.5,0.5,45.3503,46.3503);
   grae->SetPoint(14,24.5,1776);
   grae->SetPointError(14,0.5,0.5,41.64558,42.64558);
   grae->SetPoint(15,25.5,1575);
   grae->SetPointError(15,0.5,0.5,39.18942,40.18942);
   grae->SetPoint(16,26.5,1396);
   grae->SetPointError(16,0.5,0.5,36.86643,37.86643);
   grae->SetPoint(17,27.5,1146);
   grae->SetPointError(17,0.5,0.5,33.35631,34.35631);
   grae->SetPoint(18,28.5,973);
   grae->SetPointError(18,0.5,0.5,30.69695,31.69695);
   grae->SetPoint(19,29.5,851);
   grae->SetPointError(19,0.5,0.5,28.67619,29.67619);
   grae->SetPoint(20,30.5,775);
   grae->SetPointError(20,0.5,0.5,27.34331,28.34331);
   grae->SetPoint(21,31.5,627);
   grae->SetPointError(21,0.5,0.5,24.54496,25.54496);
   grae->SetPoint(22,32.5,555);
   grae->SetPointError(22,0.5,0.5,23.06374,24.06374);
   grae->SetPoint(23,33.5,482);
   grae->SetPointError(23,0.5,0.5,21.46019,22.46019);
   grae->SetPoint(24,34.5,384);
   grae->SetPointError(24,0.5,0.5,19.1023,20.1023);
   grae->SetPoint(25,35.5,360);
   grae->SetPointError(25,0.5,0.5,18.48025,19.48025);
   grae->SetPoint(26,36.5,346);
   grae->SetPointError(26,0.5,0.5,18.10779,19.10779);
   grae->SetPoint(27,37.5,289);
   grae->SetPointError(27,0.5,0.5,16.50735,17.50735);
   grae->SetPoint(28,38.5,244);
   grae->SetPointError(28,0.5,0.5,15.1285,16.1285);
   grae->SetPoint(29,39.5,213);
   grae->SetPointError(29,0.5,0.5,14.10308,15.10308);
   grae->SetPoint(30,40.5,173);
   grae->SetPointError(30,0.5,0.5,12.66245,13.66245);
   grae->SetPoint(31,41.5,161);
   grae->SetPointError(31,0.5,0.5,12.19843,13.19843);
   grae->SetPoint(32,42.5,137);
   grae->SetPointError(32,0.5,0.5,11.21537,12.21537);
   grae->SetPoint(33,43.5,118);
   grae->SetPointError(33,0.5,0.5,10.37428,11.37428);
   grae->SetPoint(34,44.5,104);
   grae->SetPointError(34,0.5,0.5,9.710289,10.71029);
   grae->SetPoint(35,45.5,106);
   grae->SetPointError(35,0.5,0.5,9.807764,10.80776);
   grae->SetPoint(36,46.5,86);
   grae->SetPointError(36,0.5,0.5,9.255555,10.30959);
   grae->SetPoint(37,47.5,68);
   grae->SetPointError(37,0.5,0.5,8.225883,9.28666);
   grae->SetPoint(38,48.5,45);
   grae->SetPointError(38,0.5,0.5,6.683179,7.757905);
   grae->SetPoint(39,49.5,55);
   grae->SetPointError(39,0.5,0.5,7.39358,8.461166);
   grae->SetPoint(40,50.5,47);
   grae->SetPointError(40,0.5,0.5,6.831172,7.904289);
   grae->SetPoint(41,51.5,37);
   grae->SetPointError(41,0.5,0.5,6.055143,7.137555);
   grae->SetPoint(42,52.5,35);
   grae->SetPointError(42,0.5,0.5,5.887675,6.97241);
   grae->SetPoint(43,53.5,30);
   grae->SetPointError(43,0.5,0.5,5.446522,6.538046);
   grae->SetPoint(44,54.5,19);
   grae->SetPointError(44,0.5,0.5,4.320219,5.435196);
   grae->SetPoint(45,55.5,18);
   grae->SetPointError(45,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(46,56.5,22);
   grae->SetPointError(46,0.5,0.5,4.654502,5.761366);
   grae->SetPoint(47,57.5,23);
   grae->SetPointError(47,0.5,0.5,4.760717,5.865235);
   grae->SetPoint(48,58.5,18);
   grae->SetPointError(48,0.5,0.5,4.202887,5.321007);
   grae->SetPoint(49,59.5,10);
   grae->SetPointError(49,0.5,0.5,3.108694,4.26695);
   grae->SetPoint(50,60.5,6);
   grae->SetPointError(50,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(51,61.5,6);
   grae->SetPointError(51,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(52,62.5,4);
   grae->SetPointError(52,0.5,0.5,1.914339,3.162753);
   grae->SetPoint(53,63.5,5);
   grae->SetPointError(53,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(54,64.5,6);
   grae->SetPointError(54,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(55,65.5,6);
   grae->SetPointError(55,0.5,0.5,2.379931,3.583642);
   grae->SetPoint(56,66.5,4);
   grae->SetPointError(56,0.5,0.5,1.914339,3.162753);
   grae->SetPoint(57,67.5,4);
   grae->SetPointError(57,0.5,0.5,1.914339,3.162753);
   grae->SetPoint(58,68.5,5);
   grae->SetPointError(58,0.5,0.5,2.159691,3.382473);
   grae->SetPoint(59,69.5,3);
   grae->SetPointError(59,0.5,0.5,1.632705,2.918186);
   grae->SetPoint(60,70.5,4);
   grae->SetPointError(60,0.5,0.5,1.914339,3.162753);
   grae->SetPoint(61,71.5,0);
   grae->SetPointError(61,0.5,0.5,0,1.147874);
   grae->SetPoint(62,72.5,3);
   grae->SetPointError(62,0.5,0.5,1.632705,2.918186);
   grae->SetPoint(63,73.5,0);
   grae->SetPointError(63,0.5,0.5,0,1.147874);
   grae->SetPoint(64,74.5,2);
   grae->SetPointError(64,0.5,0.5,1.291815,2.63786);
   grae->SetPoint(65,75.5,3);
   grae->SetPointError(65,0.5,0.5,1.632705,2.918186);
   grae->SetPoint(66,76.5,2);
   grae->SetPointError(66,0.5,0.5,1.291815,2.63786);
   grae->SetPoint(67,77.5,1);
   grae->SetPointError(67,0.5,0.5,0.8272462,2.299527);
   grae->SetPoint(68,78.5,1);
   grae->SetPointError(68,0.5,0.5,0.8272462,2.299527);
   grae->SetPoint(69,79.5,0);
   grae->SetPointError(69,0.5,0.5,0,1.147874);
   grae->SetPoint(70,80.5,0);
   grae->SetPointError(70,0.5,0.5,0,1.147874);
   grae->SetPoint(71,81.5,0);
   grae->SetPointError(71,0.5,0.5,0,1.147874);
   grae->SetPoint(72,82.5,0);
   grae->SetPointError(72,0.5,0.5,0,1.147874);
   grae->SetPoint(73,83.5,0);
   grae->SetPointError(73,0.5,0.5,0,1.147874);
   grae->SetPoint(74,84.5,0);
   grae->SetPointError(74,0.5,0.5,0,1.147874);
   grae->SetPoint(75,85.5,0);
   grae->SetPointError(75,0.5,0.5,0,1.147874);
   grae->SetPoint(76,86.5,0);
   grae->SetPointError(76,0.5,0.5,0,1.147874);
   grae->SetPoint(77,87.5,0);
   grae->SetPointError(77,0.5,0.5,0,1.147874);
   grae->SetPoint(78,88.5,0);
   grae->SetPointError(78,0.5,0.5,0,1.147874);
   grae->SetPoint(79,89.5,0);
   grae->SetPointError(79,0.5,0.5,0,1.147874);
   grae->SetPoint(80,90.5,0);
   grae->SetPointError(80,0.5,0.5,0,1.147874);
   grae->SetPoint(81,91.5,0);
   grae->SetPointError(81,0.5,0.5,0,1.147874);
   grae->SetPoint(82,92.5,0);
   grae->SetPointError(82,0.5,0.5,0,1.147874);
   grae->SetPoint(83,93.5,0);
   grae->SetPointError(83,0.5,0.5,0,1.147874);
   grae->SetPoint(84,94.5,0);
   grae->SetPointError(84,0.5,0.5,0,1.147874);
   grae->SetPoint(85,95.5,0);
   grae->SetPointError(85,0.5,0.5,0,1.147874);
   grae->SetPoint(86,96.5,0);
   grae->SetPointError(86,0.5,0.5,0,1.147874);
   grae->SetPoint(87,97.5,0);
   grae->SetPointError(87,0.5,0.5,0,1.147874);
   grae->SetPoint(88,98.5,0);
   grae->SetPointError(88,0.5,0.5,0,1.147874);
   grae->SetPoint(89,99.5,0);
   grae->SetPointError(89,0.5,0.5,0,1.147874);
   grae->SetPoint(90,100.5,0);
   grae->SetPointError(90,0.5,0.5,0,1.147874);
   grae->SetPoint(91,101.5,0);
   grae->SetPointError(91,0.5,0.5,0,1.147874);
   grae->SetPoint(92,102.5,0);
   grae->SetPointError(92,0.5,0.5,0,1.147874);
   grae->SetPoint(93,103.5,0);
   grae->SetPointError(93,0.5,0.5,0,1.147874);
   grae->SetPoint(94,104.5,0);
   grae->SetPointError(94,0.5,0.5,0,1.147874);
   grae->SetPoint(95,105.5,0);
   grae->SetPointError(95,0.5,0.5,0,1.147874);
   grae->SetPoint(96,106.5,0);
   grae->SetPointError(96,0.5,0.5,0,1.147874);
   grae->SetPoint(97,107.5,0);
   grae->SetPointError(97,0.5,0.5,0,1.147874);
   grae->SetPoint(98,108.5,0);
   grae->SetPointError(98,0.5,0.5,0,1.147874);
   grae->SetPoint(99,109.5,0);
   grae->SetPointError(99,0.5,0.5,0,1.147874);
   grae->SetPoint(100,110.5,0);
   grae->SetPointError(100,0.5,0.5,0,1.147874);
   grae->SetPoint(101,111.5,0);
   grae->SetPointError(101,0.5,0.5,0,1.147874);
   grae->SetPoint(102,112.5,0);
   grae->SetPointError(102,0.5,0.5,0,1.147874);
   grae->SetPoint(103,113.5,0);
   grae->SetPointError(103,0.5,0.5,0,1.147874);
   grae->SetPoint(104,114.5,0);
   grae->SetPointError(104,0.5,0.5,0,1.147874);
   grae->SetPoint(105,115.5,0);
   grae->SetPointError(105,0.5,0.5,0,1.147874);
   grae->SetPoint(106,116.5,0);
   grae->SetPointError(106,0.5,0.5,0,1.147874);
   grae->SetPoint(107,117.5,0);
   grae->SetPointError(107,0.5,0.5,0,1.147874);
   grae->SetPoint(108,118.5,0);
   grae->SetPointError(108,0.5,0.5,0,1.147874);
   grae->SetPoint(109,119.5,0);
   grae->SetPointError(109,0.5,0.5,0,1.147874);
   grae->Draw("p");
   
   TH1D *frame_7cf19a0__8 = new TH1D("frame_7cf19a0__8","High stats histogram pdf with interpolation",110,10,120);
   frame_7cf19a0__8->SetBinContent(1,14185.75);
   frame_7cf19a0__8->SetMaximum(14185.75);
   frame_7cf19a0__8->SetEntries(1);
   frame_7cf19a0__8->SetDirectory(0);
   frame_7cf19a0__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_7cf19a0__8->SetLineColor(ci);
   frame_7cf19a0__8->GetXaxis()->SetTitle("eventSelectionamassMu");
   frame_7cf19a0__8->GetXaxis()->SetLabelFont(42);
   frame_7cf19a0__8->GetXaxis()->SetLabelSize(0.035);
   frame_7cf19a0__8->GetXaxis()->SetTitleSize(0.035);
   frame_7cf19a0__8->GetXaxis()->SetTitleFont(42);
   frame_7cf19a0__8->GetYaxis()->SetTitle("Events / ( 1 )");
   frame_7cf19a0__8->GetYaxis()->SetLabelFont(42);
   frame_7cf19a0__8->GetYaxis()->SetLabelSize(0.035);
   frame_7cf19a0__8->GetYaxis()->SetTitleSize(0.035);
   frame_7cf19a0__8->GetYaxis()->SetTitleFont(42);
   frame_7cf19a0__8->GetZaxis()->SetLabelFont(42);
   frame_7cf19a0__8->GetZaxis()->SetLabelSize(0.035);
   frame_7cf19a0__8->GetZaxis()->SetTitleSize(0.035);
   frame_7cf19a0__8->GetZaxis()->SetTitleFont(42);
   frame_7cf19a0__8->Draw("AXISSAME");
   c1_n4->Modified();
   c1_n4->cd();
   c1_n4->SetSelected(c1_n4);
}
