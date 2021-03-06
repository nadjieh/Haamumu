{
//=========Macro generated from canvas: amassMu/#Delta m(a,a)
//=========  (Thu Nov 27 23:23:23 2014) by ROOT version5.34/19
   TCanvas *amassMu = new TCanvas("amassMu", "#Delta m(a,a)",506,106,500,500);
   amassMu->SetHighLightColor(2);
   amassMu->Range(0,0,1,1);
   amassMu->SetFillColor(0);
   amassMu->SetBorderMode(0);
   amassMu->SetBorderSize(2);
   amassMu->SetLogy();
   amassMu->SetTickx(1);
   amassMu->SetTicky(1);
   amassMu->SetLeftMargin(0.16);
   amassMu->SetRightMargin(0.02);
   amassMu->SetTopMargin(0.05);
   amassMu->SetBottomMargin(0.13);
   amassMu->SetFrameFillStyle(0);
   amassMu->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.15,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-19.51219,-1.951219,102.439,5.365854);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetLogy();
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.16);
   pad1->SetRightMargin(0.02);
   pad1->SetTopMargin(0.05);
   pad1->SetBottomMargin(0.13);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   
   TH1D *amassMu__11 = new TH1D("amassMu__11","",500,0,1000);
   amassMu__11->SetBinContent(6,203);
   amassMu__11->SetBinContent(7,91);
   amassMu__11->SetBinContent(8,93);
   amassMu__11->SetBinContent(9,81);
   amassMu__11->SetBinContent(10,64);
   /*amassMu__11->SetBinContent(11,49);
   amassMu__11->SetBinContent(12,43);
   amassMu__11->SetBinContent(13,69);
   amassMu__11->SetBinContent(14,58);
   amassMu__11->SetBinContent(15,60);
   amassMu__11->SetBinContent(16,46);
   amassMu__11->SetBinContent(17,57);
   amassMu__11->SetBinContent(18,66);
   amassMu__11->SetBinContent(19,80);
   amassMu__11->SetBinContent(20,61);
   amassMu__11->SetBinContent(21,53);
   amassMu__11->SetBinContent(22,61);
   amassMu__11->SetBinContent(23,53);
   amassMu__11->SetBinContent(24,46);
   amassMu__11->SetBinContent(25,50);
   amassMu__11->SetBinContent(26,40);
   amassMu__11->SetBinContent(27,46);
   amassMu__11->SetBinContent(28,40);
   amassMu__11->SetBinContent(29,42);
   amassMu__11->SetBinContent(30,42);
   amassMu__11->SetBinContent(31,35);
   amassMu__11->SetBinContent(32,26);
   amassMu__11->SetBinContent(33,30);
   amassMu__11->SetBinContent(34,23);
   amassMu__11->SetBinContent(35,26);
   amassMu__11->SetBinContent(36,40);*/
   amassMu__11->SetBinContent(37,26);
   amassMu__11->SetBinContent(38,37);
   amassMu__11->SetBinContent(39,42);
   amassMu__11->SetBinContent(40,44);
   amassMu__11->SetBinContent(41,57);
   amassMu__11->SetBinContent(42,77);
   amassMu__11->SetBinContent(43,100);
   amassMu__11->SetBinContent(44,148);
   amassMu__11->SetBinContent(45,297);
   amassMu__11->SetBinContent(46,412);
   amassMu__11->SetBinContent(47,207);
   amassMu__11->SetBinContent(48,57);
   amassMu__11->SetBinContent(49,11);
   amassMu__11->SetBinContent(50,4);
   amassMu__11->SetBinContent(51,3);
   amassMu__11->SetBinContent(52,4);
   amassMu__11->SetBinContent(54,1);
   amassMu__11->SetEntries(3301);
   amassMu__11->SetDirectory(0);
   amassMu__11->SetStats(0);
   
   amassMu__11->SetLineStyle(0);
   amassMu__11->SetMarkerStyle(20);
   amassMu__11->GetXaxis()->SetTitle("di-#mu-mass (GeV)");
   amassMu__11->GetXaxis()->SetLabelFont(42);
   amassMu__11->GetXaxis()->SetLabelOffset(0.007);
   amassMu__11->GetXaxis()->SetLabelSize(0.05);
   amassMu__11->GetXaxis()->SetTitleSize(0.06);
   amassMu__11->GetXaxis()->SetTitleOffset(0.9);
   amassMu__11->GetXaxis()->SetTitleFont(42);
   amassMu__11->GetYaxis()->SetTitle("Events / 2GeV");
   amassMu__11->GetYaxis()->SetLabelFont(42);
   amassMu__11->GetYaxis()->SetLabelOffset(0.007);
   amassMu__11->GetYaxis()->SetLabelSize(0.05);
   amassMu__11->GetYaxis()->SetTitleSize(0.06);
   amassMu__11->GetYaxis()->SetTitleOffset(1.5);
   amassMu__11->GetYaxis()->SetRangeUser(0.1,1000.);   
   amassMu__11->GetXaxis()->SetRangeUser(12,120.);   
   amassMu__11->GetYaxis()->SetTitleFont(42);
   amassMu__11->GetZaxis()->SetLabelFont(42);
   amassMu__11->GetZaxis()->SetLabelOffset(0.007);
   amassMu__11->GetZaxis()->SetLabelSize(0.05);
   amassMu__11->GetZaxis()->SetTitleSize(0.06);
   amassMu__11->GetZaxis()->SetTitleFont(42);
   amassMu__11->Draw("e");
   
   THStack *amassMuStack = new THStack();
   amassMuStack->SetName("amassMuStack");
   amassMuStack->SetTitle("MC stack");
   
   TH1F *amassMu_stack_1 = new TH1F("amassMu_stack_1","MC stack",20,0,100);
   amassMu_stack_1->GetXaxis()->SetTitle("");
   amassMu_stack_1->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   amassMu_stack_1->SetMinimum(0.001608831);
   amassMu_stack_1->SetMaximum(17441.99);
   amassMu_stack_1->SetDirectory(0);
   amassMu_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu_stack_1->SetLineColor(ci);
   amassMu_stack_1->GetXaxis()->SetLabelFont(42);
   amassMu_stack_1->GetXaxis()->SetLabelSize(0.035);
   amassMu_stack_1->GetXaxis()->SetTitleSize(0.035);
   amassMu_stack_1->GetXaxis()->SetTitleFont(42);
   amassMu_stack_1->GetYaxis()->SetLabelFont(42);
   amassMu_stack_1->GetYaxis()->SetLabelSize(0.035);
   amassMu_stack_1->GetYaxis()->SetTitleSize(0.035);
   amassMu_stack_1->GetYaxis()->SetTitleFont(42);
   amassMu_stack_1->GetZaxis()->SetLabelFont(42);
   amassMu_stack_1->GetZaxis()->SetLabelSize(0.035);
   amassMu_stack_1->GetZaxis()->SetTitleSize(0.035);
   amassMu_stack_1->GetZaxis()->SetTitleFont(42);
   amassMuStack->SetHistogram(amassMu_stack_1);
   
   
   TH1D *amassMu__1 = new TH1D("amassMu__1","ZZ",500,0,1000);
   amassMu__1->SetBinContent(6,0.0498012);
   amassMu__1->SetBinContent(7,0.2324056);
   amassMu__1->SetBinContent(8,0.2656064);
   amassMu__1->SetBinContent(9,0.2656064);
   amassMu__1->SetBinContent(10,0.2324056);
   amassMu__1->SetBinContent(11,0.1992048);
   amassMu__1->SetBinContent(12,0.1494036);
   amassMu__1->SetBinContent(13,0.2324056);
   amassMu__1->SetBinContent(14,0.083002);
   amassMu__1->SetBinContent(15,0.083002);
   amassMu__1->SetBinContent(16,0.166004);
   amassMu__1->SetBinContent(17,0.2656064);
   amassMu__1->SetBinContent(18,0.2822068);
   amassMu__1->SetBinContent(19,0.1992048);
   amassMu__1->SetBinContent(20,0.1494036);
   amassMu__1->SetBinContent(21,0.1826044);
   amassMu__1->SetBinContent(22,0.166004);
   amassMu__1->SetBinContent(23,0.1826044);
   amassMu__1->SetBinContent(24,0.166004);
   amassMu__1->SetBinContent(25,0.0498012);
   amassMu__1->SetBinContent(26,0.083002);
   amassMu__1->SetBinContent(27,0.166004);
   amassMu__1->SetBinContent(28,0.166004);
   amassMu__1->SetBinContent(29,0.1494036);
   amassMu__1->SetBinContent(30,0.1162028);
   amassMu__1->SetBinContent(31,0.0664016);
   amassMu__1->SetBinContent(32,0.0664016);
   amassMu__1->SetBinContent(33,0.0996024);
   amassMu__1->SetBinContent(34,0.083002);
   amassMu__1->SetBinContent(35,0.0498012);
   amassMu__1->SetBinContent(36,0.0664016);
   amassMu__1->SetBinContent(37,0.0664016);
   amassMu__1->SetBinContent(38,0.1162028);
   amassMu__1->SetBinContent(39,0.0996024);
   amassMu__1->SetBinContent(40,0.0996024);
   amassMu__1->SetBinContent(41,0.083002);
   amassMu__1->SetBinContent(42,0.083002);
   amassMu__1->SetBinContent(43,0.1328032);
   amassMu__1->SetBinContent(44,0.2324056);
   amassMu__1->SetBinContent(45,0.5312128);
   amassMu__1->SetBinContent(46,0.498012);
   amassMu__1->SetBinContent(47,0.2656064);
   amassMu__1->SetBinContent(48,0.0498012);
   amassMu__1->SetEntries(420);
   amassMu__1->SetDirectory(0);
   amassMu__1->SetStats(0);
   double w = amassMu__1->Integral()/amassMu__1->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__1->GetBinContent(i) != 0)
   		amassMu__1->SetBinError(i, sqrt(w*amassMu__1->GetBinContent(i)));
   }

   ci = TColor::GetColor("#ff66ff");
   amassMu__1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__1->SetLineColor(ci);
   amassMu__1->GetXaxis()->SetLabelFont(42);
   amassMu__1->GetXaxis()->SetLabelSize(0.035);
   amassMu__1->GetXaxis()->SetTitleSize(0.035);
   amassMu__1->GetXaxis()->SetTitleFont(42);
   amassMu__1->GetYaxis()->SetLabelFont(42);
   amassMu__1->GetYaxis()->SetLabelSize(0.035);
   amassMu__1->GetYaxis()->SetTitleSize(0.035);
   amassMu__1->GetYaxis()->SetTitleFont(42);
   amassMu__1->GetZaxis()->SetLabelFont(42);
   amassMu__1->GetZaxis()->SetLabelSize(0.035);
   amassMu__1->GetZaxis()->SetTitleSize(0.035);
   amassMu__1->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__1,"");
   
      TH1D *amassMu__2 = new TH1D("amassMu__2","WZ",500,0,1000);
   amassMu__2->SetBinContent(16,0.0661901);
   amassMu__2->SetBinContent(17,0.1323802);
   amassMu__2->SetBinContent(18,0.0661901);
   amassMu__2->SetBinContent(20,0.0661901);
   amassMu__2->SetBinContent(21,0.1323802);
   amassMu__2->SetBinContent(22,0.0661901);
   amassMu__2->SetBinContent(24,0.0661901);
   amassMu__2->SetBinContent(25,0.0661901);
   amassMu__2->SetBinContent(26,0.1323802);
   amassMu__2->SetBinContent(27,0.0661901);
   amassMu__2->SetBinContent(28,0.1323802);
   amassMu__2->SetBinContent(30,0.0661901);
   amassMu__2->SetBinContent(34,0.0661901);
   amassMu__2->SetBinContent(40,0.1323802);
   amassMu__2->SetBinContent(43,0.0661901);
   amassMu__2->SetBinContent(45,0.0661901);
   amassMu__2->SetBinContent(47,0.1323802);
   amassMu__2->SetEntries(23);
   amassMu__2->SetDirectory(0);
   amassMu__2->SetStats(0);
   w = amassMu__2->Integral()/amassMu__2->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__2->GetBinContent(i) != 0)
   		amassMu__2->SetBinError(i, sqrt(w*amassMu__2->GetBinContent(i)));
   }
   ci = TColor::GetColor("#66ffff");
   amassMu__2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__2->SetLineColor(ci);
   amassMu__2->GetXaxis()->SetLabelFont(42);
   amassMu__2->GetXaxis()->SetLabelSize(0.035);
   amassMu__2->GetXaxis()->SetTitleSize(0.035);
   amassMu__2->GetXaxis()->SetTitleFont(42);
   amassMu__2->GetYaxis()->SetLabelFont(42);
   amassMu__2->GetYaxis()->SetLabelSize(0.035);
   amassMu__2->GetYaxis()->SetTitleSize(0.035);
   amassMu__2->GetYaxis()->SetTitleFont(42);
   amassMu__2->GetZaxis()->SetLabelFont(42);
   amassMu__2->GetZaxis()->SetLabelSize(0.035);
   amassMu__2->GetZaxis()->SetTitleSize(0.035);
   amassMu__2->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__2,"");
   
   TH1D *amassMu__3 = new TH1D("amassMu__3","WW",500,0,1000);
   amassMu__3->SetBinContent(11,0.110315);
   amassMu__3->SetBinContent(17,0.22063);
   amassMu__3->SetBinContent(19,0.110315);
   amassMu__3->SetBinContent(20,0.110315);
   amassMu__3->SetBinContent(25,0.110315);
   amassMu__3->SetBinContent(29,0.110315);
   amassMu__3->SetBinContent(30,0.110315);
   amassMu__3->SetEntries(8);
   amassMu__3->SetDirectory(0);
   amassMu__3->SetStats(0);
   w = amassMu__3->Integral()/amassMu__3->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__3->GetBinContent(i) != 0)
   		amassMu__3->SetBinError(i, sqrt(w*amassMu__3->GetBinContent(i)));
   }

   ci = TColor::GetColor("#996633");
   amassMu__3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__3->SetLineColor(ci);
   amassMu__3->GetXaxis()->SetLabelFont(42);
   amassMu__3->GetXaxis()->SetLabelSize(0.035);
   amassMu__3->GetXaxis()->SetTitleSize(0.035);
   amassMu__3->GetXaxis()->SetTitleFont(42);
   amassMu__3->GetYaxis()->SetLabelFont(42);
   amassMu__3->GetYaxis()->SetLabelSize(0.035);
   amassMu__3->GetYaxis()->SetTitleSize(0.035);
   amassMu__3->GetYaxis()->SetTitleFont(42);
   amassMu__3->GetZaxis()->SetLabelFont(42);
   amassMu__3->GetZaxis()->SetLabelSize(0.035);
   amassMu__3->GetZaxis()->SetTitleSize(0.035);
   amassMu__3->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__3,"");
   
   TH1D *amassMu__4 = new TH1D("amassMu__4","TTF",500,0,1000);
   amassMu__4->SetBinContent(6,1.344768);
   amassMu__4->SetBinContent(7,1.613722);
   amassMu__4->SetBinContent(8,1.703373);
   amassMu__4->SetBinContent(9,1.658547);
   amassMu__4->SetBinContent(10,2.420582);
   amassMu__4->SetBinContent(11,2.599885);
   amassMu__4->SetBinContent(12,1.972326);
   amassMu__4->SetBinContent(13,2.375757);
   amassMu__4->SetBinContent(14,2.420582);
   amassMu__4->SetBinContent(15,2.555059);
   amassMu__4->SetBinContent(16,3.137792);
   amassMu__4->SetBinContent(17,3.137792);
   amassMu__4->SetBinContent(18,3.496397);
   amassMu__4->SetBinContent(19,3.451571);
   amassMu__4->SetBinContent(20,3.092966);
   amassMu__4->SetBinContent(21,3.048141);
   amassMu__4->SetBinContent(22,2.95849);
   amassMu__4->SetBinContent(23,3.003315);
   amassMu__4->SetBinContent(24,2.824013);
   amassMu__4->SetBinContent(25,2.913664);
   amassMu__4->SetBinContent(26,2.824013);
   amassMu__4->SetBinContent(27,2.330931);
   amassMu__4->SetBinContent(28,1.927501);
   amassMu__4->SetBinContent(29,2.061978);
   amassMu__4->SetBinContent(30,1.927501);
   amassMu__4->SetBinContent(31,2.017152);
   amassMu__4->SetBinContent(32,1.389594);
   amassMu__4->SetBinContent(33,1.344768);
   amassMu__4->SetBinContent(34,1.030989);
   amassMu__4->SetBinContent(35,1.075814);
   amassMu__4->SetBinContent(36,0.5379072);
   amassMu__4->SetBinContent(37,0.6275584);
   amassMu__4->SetBinContent(38,0.5827328);
   amassMu__4->SetBinContent(39,0.5827328);
   amassMu__4->SetBinContent(40,0.4034304);
   amassMu__4->SetBinContent(41,0.3137792);
   amassMu__4->SetBinContent(42,0.2689536);
   amassMu__4->SetBinContent(43,0.1793024);
   amassMu__4->SetBinContent(44,0.1793024);
   amassMu__4->SetBinContent(45,0.0448256);
   amassMu__4->SetBinContent(46,0.0896512);
   amassMu__4->SetBinContent(47,0.0448256);
   amassMu__4->SetBinContent(48,0.0448256);
   amassMu__4->SetBinContent(50,0.0896512);
   amassMu__4->SetEntries(1643);
   amassMu__4->SetDirectory(0);
   amassMu__4->SetStats(0);
   
      w = amassMu__4->Integral()/amassMu__4->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__4->GetBinContent(i) != 0)
   		amassMu__4->SetBinError(i, sqrt(w*amassMu__4->GetBinContent(i)));
   }

   ci = TColor::GetColor("#ffff66");
   amassMu__4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__4->SetLineColor(ci);
   amassMu__4->GetXaxis()->SetLabelFont(42);
   amassMu__4->GetXaxis()->SetLabelSize(0.035);
   amassMu__4->GetXaxis()->SetTitleSize(0.035);
   amassMu__4->GetXaxis()->SetTitleFont(42);
   amassMu__4->GetYaxis()->SetLabelFont(42);
   amassMu__4->GetYaxis()->SetLabelSize(0.035);
   amassMu__4->GetYaxis()->SetTitleSize(0.035);
   amassMu__4->GetYaxis()->SetTitleFont(42);
   amassMu__4->GetZaxis()->SetLabelFont(42);
   amassMu__4->GetZaxis()->SetLabelSize(0.035);
   amassMu__4->GetZaxis()->SetTitleSize(0.035);
   amassMu__4->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__4,"");
   
   TH1D *amassMu__5 = new TH1D("amassMu__5","TTS",500,0,1000);
   amassMu__5->SetBinContent(7,0.195614);
   amassMu__5->SetBinContent(8,0.391228);
   amassMu__5->SetBinContent(10,0.391228);
   amassMu__5->SetBinContent(11,0.195614);
   amassMu__5->SetBinContent(15,0.195614);
   amassMu__5->SetBinContent(17,0.782456);
   amassMu__5->SetBinContent(18,0.391228);
   amassMu__5->SetBinContent(19,0.391228);
   amassMu__5->SetBinContent(20,0.195614);
   amassMu__5->SetBinContent(21,0.586842);
   amassMu__5->SetBinContent(23,0.391228);
   amassMu__5->SetBinContent(24,0.195614);
   amassMu__5->SetBinContent(25,0.391228);
   amassMu__5->SetBinContent(26,0.586842);
   amassMu__5->SetBinContent(27,0.586842);
   amassMu__5->SetBinContent(29,1.173684);
   amassMu__5->SetBinContent(31,0.391228);
   amassMu__5->SetBinContent(32,0.195614);
   amassMu__5->SetBinContent(33,0.195614);
   amassMu__5->SetBinContent(38,0.195614);
   amassMu__5->SetEntries(41);
   amassMu__5->SetDirectory(0);
   amassMu__5->SetStats(0);
      w = amassMu__5->Integral()/amassMu__5->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__5->GetBinContent(i) != 0)
   		amassMu__5->SetBinError(i, sqrt(w*amassMu__5->GetBinContent(i)));
   }
   ci = TColor::GetColor("#339966");
   amassMu__5->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__5->SetLineColor(ci);
   amassMu__5->GetXaxis()->SetLabelFont(42);
   amassMu__5->GetXaxis()->SetLabelSize(0.035);
   amassMu__5->GetXaxis()->SetTitleSize(0.035);
   amassMu__5->GetXaxis()->SetTitleFont(42);
   amassMu__5->GetYaxis()->SetLabelFont(42);
   amassMu__5->GetYaxis()->SetLabelSize(0.035);
   amassMu__5->GetYaxis()->SetTitleSize(0.035);
   amassMu__5->GetYaxis()->SetTitleFont(42);
   amassMu__5->GetZaxis()->SetLabelFont(42);
   amassMu__5->GetZaxis()->SetLabelSize(0.035);
   amassMu__5->GetZaxis()->SetTitleSize(0.035);
   amassMu__5->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__5,"");
   
   TH1D *amassMu__6 = new TH1D("amassMu__6","Wtbar",500,0,1000);
   amassMu__6->SetBinContent(9,0.443136);
   amassMu__6->SetBinContent(15,0.886272);
   amassMu__6->SetBinContent(17,0.886272);
   amassMu__6->SetBinContent(18,0.443136);
   amassMu__6->SetBinContent(19,0.443136);
   amassMu__6->SetBinContent(20,0.443136);
   amassMu__6->SetBinContent(25,0.443136);
   amassMu__6->SetBinContent(28,0.443136);
   amassMu__6->SetBinContent(36,0.443136);
   amassMu__6->SetEntries(11);
   amassMu__6->SetDirectory(0);
   amassMu__6->SetStats(0);
   w = amassMu__6->Integral()/amassMu__6->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__6->GetBinContent(i) != 0)
   		amassMu__6->SetBinError(i, sqrt(w*amassMu__6->GetBinContent(i)));
   }
   ci = TColor::GetColor("#336600");
   amassMu__6->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__6->SetLineColor(ci);
   amassMu__6->GetXaxis()->SetLabelFont(42);
   amassMu__6->GetXaxis()->SetLabelSize(0.035);
   amassMu__6->GetXaxis()->SetTitleSize(0.035);
   amassMu__6->GetXaxis()->SetTitleFont(42);
   amassMu__6->GetYaxis()->SetLabelFont(42);
   amassMu__6->GetYaxis()->SetLabelSize(0.035);
   amassMu__6->GetYaxis()->SetTitleSize(0.035);
   amassMu__6->GetYaxis()->SetTitleFont(42);
   amassMu__6->GetZaxis()->SetLabelFont(42);
   amassMu__6->GetZaxis()->SetLabelSize(0.035);
   amassMu__6->GetZaxis()->SetTitleSize(0.035);
   amassMu__6->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__6,"");
   
   TH1D *amassMu__7 = new TH1D("amassMu__7","Wt",500,0,1000);
   amassMu__7->SetBinContent(8,0.439398);
   amassMu__7->SetBinContent(10,0.439398);
   amassMu__7->SetBinContent(14,0.439398);
   amassMu__7->SetBinContent(18,0.439398);
   amassMu__7->SetBinContent(19,0.878796);
   amassMu__7->SetBinContent(24,0.439398);
   amassMu__7->SetBinContent(28,0.439398);
   amassMu__7->SetBinContent(30,0.439398);
   amassMu__7->SetBinContent(36,0.439398);
   amassMu__7->SetBinContent(38,0.439398);
   amassMu__7->SetEntries(11);
   amassMu__7->SetDirectory(0);
   amassMu__7->SetStats(0);
   w = amassMu__7->Integral()/amassMu__7->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__7->GetBinContent(i) != 0)
   		amassMu__7->SetBinError(i, sqrt(w*amassMu__7->GetBinContent(i)));
   }
   ci = TColor::GetColor("#336600");
   amassMu__7->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__7->SetLineColor(ci);
   amassMu__7->GetXaxis()->SetLabelFont(42);
   amassMu__7->GetXaxis()->SetLabelSize(0.035);
   amassMu__7->GetXaxis()->SetTitleSize(0.035);
   amassMu__7->GetXaxis()->SetTitleFont(42);
   amassMu__7->GetYaxis()->SetLabelFont(42);
   amassMu__7->GetYaxis()->SetLabelSize(0.035);
   amassMu__7->GetYaxis()->SetTitleSize(0.035);
   amassMu__7->GetYaxis()->SetTitleFont(42);
   amassMu__7->GetZaxis()->SetLabelFont(42);
   amassMu__7->GetZaxis()->SetLabelSize(0.035);
   amassMu__7->GetZaxis()->SetTitleSize(0.035);
   amassMu__7->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__7,"");
   
   TH1D *amassMu__8 = new TH1D("amassMu__8","DY",500,0,1000);
   amassMu__8->SetBinContent(9,2.89374);
   amassMu__8->SetBinContent(12,2.89374);
   amassMu__8->SetBinContent(13,2.89374);
   amassMu__8->SetBinContent(15,8.68122);
   amassMu__8->SetBinContent(17,2.89374);
   amassMu__8->SetBinContent(18,2.89374);
   amassMu__8->SetBinContent(19,2.89374);
   amassMu__8->SetBinContent(20,14.4687);
   amassMu__8->SetBinContent(21,14.4687);
   amassMu__8->SetBinContent(22,5.78748);
   amassMu__8->SetBinContent(23,8.68122);
   amassMu__8->SetBinContent(24,2.89374);
   amassMu__8->SetBinContent(25,20.25618);
   amassMu__8->SetBinContent(26,46.29984);
   amassMu__8->SetBinContent(27,40.51236);
   amassMu__8->SetBinContent(28,60.76854);
   amassMu__8->SetBinContent(29,23.14992);
   amassMu__8->SetBinContent(30,43.4061);
   amassMu__8->SetBinContent(31,37.61862);
   amassMu__8->SetBinContent(32,37.61862);
   amassMu__8->SetBinContent(33,57.8748);
   amassMu__8->SetBinContent(34,49.19358);
   amassMu__8->SetBinContent(35,57.8748);
   amassMu__8->SetBinContent(36,37.61862);
   amassMu__8->SetBinContent(37,52.08732);
   amassMu__8->SetBinContent(38,52.08732);
   amassMu__8->SetBinContent(39,49.19358);
   amassMu__8->SetBinContent(40,89.70594);
   amassMu__8->SetBinContent(41,75.23724);
   amassMu__8->SetBinContent(42,66.55602);
   amassMu__8->SetBinContent(43,92.59968);
   amassMu__8->SetBinContent(44,219.9242);
   amassMu__8->SetBinContent(45,465.8921);
   amassMu__8->SetBinContent(46,593.2167);
   amassMu__8->SetBinContent(47,277.799);
   amassMu__8->SetBinContent(48,69.44976);
   amassMu__8->SetBinContent(49,17.36244);
   amassMu__8->SetBinContent(50,5.78748);
   amassMu__8->SetBinContent(51,5.78748);
   amassMu__8->SetEntries(939);
   amassMu__8->SetDirectory(0);
   amassMu__8->SetStats(0);
   amassMu__8->Scale(1./1.277);   
   w = amassMu__8->Integral()/amassMu__8->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__8->GetBinContent(i) != 0)
   		amassMu__8->SetBinError(i, sqrt(w*amassMu__8->GetBinContent(i)));
   }
   ci = TColor::GetColor("#ff6666");
   amassMu__8->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   amassMu__8->SetLineColor(ci);
   amassMu__8->GetXaxis()->SetLabelFont(42);
   amassMu__8->GetXaxis()->SetLabelSize(0.035);
   amassMu__8->GetXaxis()->SetTitleSize(0.035);
   amassMu__8->GetXaxis()->SetTitleFont(42);
   amassMu__8->GetYaxis()->SetLabelFont(42);
   amassMu__8->GetYaxis()->SetLabelSize(0.035);
   amassMu__8->GetYaxis()->SetTitleSize(0.035);
   amassMu__8->GetYaxis()->SetTitleFont(42);
   amassMu__8->GetZaxis()->SetLabelFont(42);
   amassMu__8->GetZaxis()->SetLabelSize(0.035);
   amassMu__8->GetZaxis()->SetTitleSize(0.035);
   amassMu__8->GetZaxis()->SetTitleFont(42);
  //  amassMu__8->Scale(1.277);  
   amassMuStack->Add(amassMu__8,"");
   
      TH1D *amassMu__9 = new TH1D("amassMu__9","DYLow",500,0,1000);
   amassMu__9->SetBinContent(6,112.7357);
   amassMu__9->SetBinContent(7,120.7883);
   amassMu__9->SetBinContent(8,112.7357);
   amassMu__9->SetBinContent(9,80.5255);
   amassMu__9->SetBinContent(10,8.05255);
   amassMu__9->SetBinContent(11,112.7357);
   amassMu__9->SetBinContent(12,72.47295);
   amassMu__9->SetBinContent(13,72.47295);
   amassMu__9->SetBinContent(14,48.3153);
   amassMu__9->SetBinContent(15,56.36785);
   amassMu__9->SetBinContent(16,8.05255);
   amassMu__9->SetBinContent(17,32.2102);
   amassMu__9->SetBinContent(18,56.36785);
   amassMu__9->SetBinContent(19,72.47295);
   amassMu__9->SetBinContent(20,96.6306);
   amassMu__9->SetBinContent(21,16.1051);
   amassMu__9->SetBinContent(22,24.15765);
   amassMu__9->SetBinContent(23,40.26275);
   amassMu__9->SetBinContent(24,96.6306);
   amassMu__9->SetBinContent(25,16.1051);
   amassMu__9->SetEntries(156);
   amassMu__9->SetDirectory(0);
   amassMu__9->SetStats(0);
   amassMu__9->Scale(1./1.169);
   w = amassMu__9->Integral()/amassMu__9->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__9->GetBinContent(i) != 0)
   		amassMu__9->SetBinError(i, sqrt(w*amassMu__9->GetBinContent(i)));
   }
   ci = TColor::GetColor("#ff6666");
   amassMu__9->SetFillColor(kRed-9);
   ci = TColor::GetColor("#000099");
   amassMu__9->SetLineColor(ci);
   amassMu__9->GetXaxis()->SetLabelFont(42);
   amassMu__9->GetXaxis()->SetLabelSize(0.035);
   amassMu__9->GetXaxis()->SetTitleSize(0.035);
   amassMu__9->GetXaxis()->SetTitleFont(42);
   amassMu__9->GetYaxis()->SetLabelFont(42);
   amassMu__9->GetYaxis()->SetLabelSize(0.035);
   amassMu__9->GetYaxis()->SetTitleSize(0.035);
   amassMu__9->GetYaxis()->SetTitleFont(42);
   amassMu__9->GetZaxis()->SetLabelFont(42);
   amassMu__9->GetZaxis()->SetLabelSize(0.035);
   amassMu__9->GetZaxis()->SetTitleSize(0.035);
   amassMu__9->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__9,"");
   
   TH1D *amassMu__10 = new TH1D("amassMu__10","ZH125",500,0,1000);
   amassMu__10->SetBinContent(7,0.000490794);
   amassMu__10->SetBinContent(10,0.000490794);
   amassMu__10->SetBinContent(11,0.000490794);
   amassMu__10->SetBinContent(12,0.000490794);
   amassMu__10->SetBinContent(16,0.000490794);
   amassMu__10->SetBinContent(17,0.001963176);
   amassMu__10->SetBinContent(18,0.001472382);
   amassMu__10->SetBinContent(19,0.002944764);
   amassMu__10->SetBinContent(20,0.001963176);
   amassMu__10->SetBinContent(21,0.000981588);
   amassMu__10->SetBinContent(22,0.001472382);
   amassMu__10->SetBinContent(23,0.001963176);
   amassMu__10->SetBinContent(24,0.001963176);
   amassMu__10->SetBinContent(25,0.001963176);
   amassMu__10->SetBinContent(26,0.000981588);
   amassMu__10->SetBinContent(27,0.001963176);
   amassMu__10->SetBinContent(28,0.000981588);
   amassMu__10->SetBinContent(29,0.001963176);
   amassMu__10->SetBinContent(30,0.001472382);
   amassMu__10->SetBinContent(31,0.000490794);
   amassMu__10->SetBinContent(32,0.00245397);
   amassMu__10->SetBinContent(33,0.000981588);
   amassMu__10->SetBinContent(34,0.001963176);
   amassMu__10->SetBinContent(35,0.001472382);
   amassMu__10->SetBinContent(36,0.001963176);
   amassMu__10->SetBinContent(37,0.002944764);
   amassMu__10->SetBinContent(38,0.00245397);
   amassMu__10->SetBinContent(39,0.002944764);
   amassMu__10->SetBinContent(40,0.005398734);
   amassMu__10->SetBinContent(41,0.005889528);
   amassMu__10->SetBinContent(42,0.00245397);
   amassMu__10->SetBinContent(43,0.009325086);
   amassMu__10->SetBinContent(44,0.01325144);
   amassMu__10->SetBinContent(45,0.01570541);
   amassMu__10->SetBinContent(46,0.02503049);
   amassMu__10->SetBinContent(47,0.01128826);
   amassMu__10->SetBinContent(48,0.001963176);
   amassMu__10->SetBinContent(49,0.000981588);
   amassMu__10->SetBinContent(51,0.000490794);
   amassMu__10->SetEntries(277);
   amassMu__10->SetEntries(213);
   amassMu__10->SetDirectory(0);
   amassMu__10->SetStats(0);
   w = amassMu__10->Integral()/amassMu__10->GetEntries();
   for(int i = 0; i<500; i++){
   	if(amassMu__10->GetBinContent(i) != 0)
   		amassMu__10->SetBinError(i, sqrt(w*amassMu__10->GetBinContent(i)));
   }
   ci = TColor::GetColor("#000099");
   amassMu__10->SetLineColor(ci);
   amassMu__10->GetXaxis()->SetLabelFont(42);
   amassMu__10->GetXaxis()->SetLabelSize(0.035);
   amassMu__10->GetXaxis()->SetTitleSize(0.035);
   amassMu__10->GetXaxis()->SetTitleFont(42);
   amassMu__10->GetYaxis()->SetLabelFont(42);
   amassMu__10->GetYaxis()->SetLabelSize(0.035);
   amassMu__10->GetYaxis()->SetTitleSize(0.035);
   amassMu__10->GetYaxis()->SetTitleFont(42);
   amassMu__10->GetZaxis()->SetLabelFont(42);
   amassMu__10->GetZaxis()->SetLabelSize(0.035);
   amassMu__10->GetZaxis()->SetTitleSize(0.035);
   amassMu__10->GetZaxis()->SetTitleFont(42);
   amassMuStack->Add(amassMu__10,"");
   amassMuStack->Draw("hist, same");
   TH1D* allMC = (TH1D*)amassMuStack->GetStack()->Last();
   
   
      TH1D *amassMu__12 = new TH1D("amassMu__12","amassMu__12",500,0,1000);
   amassMu__12->SetBinContent(6,203);
   amassMu__12->SetBinContent(7,91);
   amassMu__12->SetBinContent(8,93);
   amassMu__12->SetBinContent(9,81);
   amassMu__12->SetBinContent(10,64);
   /*amassMu__12->SetBinContent(11,49);
   amassMu__12->SetBinContent(12,43);
   amassMu__12->SetBinContent(13,69);
   amassMu__12->SetBinContent(14,58);
   amassMu__12->SetBinContent(15,60);
   amassMu__12->SetBinContent(16,46);
   amassMu__12->SetBinContent(17,57);
   amassMu__12->SetBinContent(18,66);
   amassMu__12->SetBinContent(19,80);
   amassMu__12->SetBinContent(20,61);
   amassMu__12->SetBinContent(21,53);
   amassMu__12->SetBinContent(22,61);
   amassMu__12->SetBinContent(23,53);
   amassMu__12->SetBinContent(24,46);
   amassMu__12->SetBinContent(25,50);
   amassMu__12->SetBinContent(26,40);
   amassMu__12->SetBinContent(27,46);
   amassMu__12->SetBinContent(28,40);
   amassMu__12->SetBinContent(29,42);
   amassMu__12->SetBinContent(30,42);
   amassMu__12->SetBinContent(31,35);
   amassMu__12->SetBinContent(32,26);
   amassMu__12->SetBinContent(33,30);
   amassMu__12->SetBinContent(34,23);
   amassMu__12->SetBinContent(35,26);
   amassMu__12->SetBinContent(36,40);*/
   amassMu__12->SetBinContent(37,26);
   amassMu__12->SetBinContent(38,37);
   amassMu__12->SetBinContent(39,42);
   amassMu__12->SetBinContent(40,44);
   amassMu__12->SetBinContent(41,57);
   amassMu__12->SetBinContent(42,77);
   amassMu__12->SetBinContent(43,100);
   amassMu__12->SetBinContent(44,148);
   amassMu__12->SetBinContent(45,297);
   amassMu__12->SetBinContent(46,412);
   amassMu__12->SetBinContent(47,207);
   amassMu__12->SetBinContent(48,57);
   amassMu__12->SetBinContent(49,11);
   amassMu__12->SetBinContent(50,4);
   amassMu__12->SetBinContent(51,3);
   amassMu__12->SetBinContent(52,4);
   amassMu__12->SetBinContent(54,1);
   amassMu__12->SetEntries(3301);
   amassMu__12->SetDirectory(0);
   amassMu__12->SetStats(0);
   
   amassMu__12->SetLineStyle(0);
   amassMu__12->SetMarkerStyle(20);
   amassMu__12->GetXaxis()->SetTitle("#Delta m(a,a) (GeV)");
   amassMu__12->GetXaxis()->SetLabelFont(42);
   amassMu__12->GetXaxis()->SetLabelOffset(0.007);
   amassMu__12->GetXaxis()->SetLabelSize(0.05);
   amassMu__12->GetXaxis()->SetTitleSize(0.06);
   amassMu__12->GetXaxis()->SetTitleOffset(0.9);
   amassMu__12->GetXaxis()->SetTitleFont(42);
   amassMu__12->GetYaxis()->SetTitle("Events/2GeV");
   amassMu__12->GetYaxis()->SetLabelFont(42);
   amassMu__12->GetYaxis()->SetLabelOffset(0.007);
   amassMu__12->GetYaxis()->SetLabelSize(0.05);
   amassMu__12->GetYaxis()->SetTitleSize(0.06);
   amassMu__12->GetYaxis()->SetTitleOffset(1.5);
   amassMu__12->GetYaxis()->SetTitleFont(42);
   amassMu__12->GetZaxis()->SetLabelFont(42);
   amassMu__12->GetZaxis()->SetLabelOffset(0.007);
   amassMu__12->GetZaxis()->SetLabelSize(0.05);
   amassMu__12->GetZaxis()->SetTitleSize(0.06);
   amassMu__12->GetZaxis()->SetTitleFont(42);
   amassMu__12->Draw("e, same");
   

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#ff6666");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#ff6666");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#336600");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#336600");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#339966");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#ffff66");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#000099");

   ci = TColor::GetColor("#000099");

   pad1->Modified();
   amassMu->cd();
  
// ------------>Primitives in pad: pad2
   pad2 = new TPad("pad2", "pad1",0,0,1,0.15);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-19.51219,0.5320169,102.439,1.500287);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetGridy();
   pad2->SetTickx(1);
   pad2->SetTicky(1);
   pad2->SetLeftMargin(0.16);
   pad2->SetRightMargin(0.02);
   pad2->SetTopMargin(0.05);
   pad2->SetBottomMargin(0.13);
   pad2->SetFrameFillStyle(0);
   pad2->SetFrameBorderMode(0);
   pad2->SetFrameFillStyle(0);
   pad2->SetFrameBorderMode(0);

   TH1D *ratio___16 =  (TH1D*)  amassMu__12->Clone("ratio");
   ratio___16->Divide(allMC);
   

   ci = TColor::GetColor("#000099");
   ratio___16->SetLineColor(ci);
   ratio___16->SetMarkerStyle(20);
   ratio___16->GetXaxis()->SetLabelFont(42);
   ratio___16->GetXaxis()->SetLabelSize(0.035);
   ratio___16->GetXaxis()->SetTitleSize(0.035);
   ratio___16->GetXaxis()->SetTitleFont(42);
   ratio___16->GetYaxis()->SetTitle("Data / MC");
   ratio___16->GetYaxis()->SetLabelFont(42);
   ratio___16->GetYaxis()->SetLabelSize(0.17);
   ratio___16->GetYaxis()->SetTitleSize(0.24);
   ratio___16->GetYaxis()->SetTitleOffset(0.35);
   ratio___16->GetYaxis()->SetTitleFont(42);
   ratio___16->GetZaxis()->SetLabelFont(42);
   ratio___16->GetZaxis()->SetLabelSize(0.035);
   ratio___16->GetZaxis()->SetTitleSize(0.035);
   ratio___16->GetZaxis()->SetTitleFont(42);
      ratio___16->GetYaxis()->SetNdivisions(504,kFALSE);
   ratio___16->GetYaxis()->SetRangeUser(-1.,3.);
         ratio___16->GetXaxis()->SetRangeUser(12,120.);   
   ratio___16->Draw("ep");
   pad2->Modified();

   amassMu->Modified();
   amassMu->cd();
   amassMu->SetSelected(amassMu);

}
