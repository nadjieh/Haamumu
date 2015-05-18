{
//=========Macro generated from canvas: amassMu/#Delta m(a,a)
//=========  (Thu Nov 27 23:23:23 2014) by ROOT version5.34/19
   TCanvas *amassMu = new TCanvas("amassMu", "#Delta m(a,a)",506,106,600,500);
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
   
   TH1D *amassMu__11 = new TH1D("amassMu__11","data",500,0,1000);
   amassMu__11->SetBinContent(11,128);
   amassMu__11->SetBinContent(12,123);
   amassMu__11->SetBinContent(13,157);
   amassMu__11->SetBinContent(14,159);
   amassMu__11->SetBinContent(15,171);
   amassMu__11->SetBinContent(16,187);
   amassMu__11->SetBinContent(17,191);
   amassMu__11->SetBinContent(18,198);
   amassMu__11->SetBinContent(19,210);
   amassMu__11->SetBinContent(20,237);
   amassMu__11->SetBinContent(21,234);
   amassMu__11->SetBinContent(22,240);
   amassMu__11->SetBinContent(23,253);
   amassMu__11->SetBinContent(24,251);
   amassMu__11->SetBinContent(25,234);
   amassMu__11->SetBinContent(26,253);
   amassMu__11->SetBinContent(27,259);
   amassMu__11->SetBinContent(28,265);
   amassMu__11->SetBinContent(29,255);
   amassMu__11->SetBinContent(30,245);
   amassMu__11->SetBinContent(31,266);
   amassMu__11->SetBinContent(32,273);
   amassMu__11->SetBinContent(33,225);
   amassMu__11->SetBinContent(34,235);
   amassMu__11->SetBinContent(35,246);
   amassMu__11->SetEntries(5495);
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
   amassMu__11->GetXaxis()->SetRangeUser(0,101.);   
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
   amassMu__1->SetBinContent(11,0.0498012);
   amassMu__1->SetBinContent(12,0.0996024);
   amassMu__1->SetBinContent(13,0.0166004);
   amassMu__1->SetBinContent(14,0.083002);
   amassMu__1->SetBinContent(15,0.0498012);
   amassMu__1->SetBinContent(16,0.0664016);
   amassMu__1->SetBinContent(17,0.0996024);
   amassMu__1->SetBinContent(18,0.1328032);
   amassMu__1->SetBinContent(19,0.083002);
   amassMu__1->SetBinContent(20,0.0664016);
   amassMu__1->SetBinContent(21,0.0664016);
   amassMu__1->SetBinContent(22,0.0664016);
   amassMu__1->SetBinContent(23,0.0498012);
   amassMu__1->SetBinContent(24,0.0166004);
   amassMu__1->SetBinContent(25,0.0332008);
   amassMu__1->SetBinContent(26,0.0332008);
   amassMu__1->SetBinContent(27,0.0332008);
   amassMu__1->SetBinContent(28,0.0166004);
   amassMu__1->SetBinContent(29,0.0166004);
   amassMu__1->SetBinContent(30,0.0498012);
   amassMu__1->SetBinContent(32,0.0332008);
   amassMu__1->SetBinContent(33,0.0664016);
   amassMu__1->SetBinContent(34,0.0166004);
   amassMu__1->SetBinContent(35,0.0166004);
   amassMu__1->SetEntries(76);
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
   amassMu__2->SetBinContent(13,0.1323802);
   amassMu__2->SetBinContent(14,0.0661901);
   amassMu__2->SetBinContent(16,0.1323802);
   amassMu__2->SetBinContent(17,0.1323802);
   amassMu__2->SetBinContent(18,0.0661901);
   amassMu__2->SetBinContent(19,0.1323802);
   amassMu__2->SetBinContent(20,0.1985703);
   amassMu__2->SetBinContent(21,0.2647604);
   amassMu__2->SetBinContent(23,0.0661901);
   amassMu__2->SetBinContent(24,0.1323802);
   amassMu__2->SetBinContent(27,0.0661901);
   amassMu__2->SetBinContent(29,0.0661901);
   amassMu__2->SetBinContent(32,0.2647604);
   amassMu__2->SetBinContent(34,0.0661901);
   amassMu__2->SetBinContent(35,0.0661901);
   amassMu__2->SetEntries(28);
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
   amassMu__3->SetBinContent(13,0.22063);
   amassMu__3->SetBinContent(14,0.22063);
   amassMu__3->SetBinContent(15,0.330945);
   amassMu__3->SetBinContent(16,0.110315);
   amassMu__3->SetBinContent(17,0.22063);
   amassMu__3->SetBinContent(18,0.22063);
   amassMu__3->SetBinContent(19,0.330945);
   amassMu__3->SetBinContent(20,0.66189);
   amassMu__3->SetBinContent(21,0.110315);
   amassMu__3->SetBinContent(22,0.44126);
   amassMu__3->SetBinContent(23,0.551575);
   amassMu__3->SetBinContent(24,0.44126);
   amassMu__3->SetBinContent(25,0.110315);
   amassMu__3->SetBinContent(26,0.551575);
   amassMu__3->SetBinContent(27,0.22063);
   amassMu__3->SetBinContent(28,0.110315);
   amassMu__3->SetBinContent(29,0.66189);
   amassMu__3->SetBinContent(31,0.22063);
   amassMu__3->SetBinContent(32,0.44126);
   amassMu__3->SetBinContent(33,0.330945);
   amassMu__3->SetBinContent(34,0.110315);
   amassMu__3->SetBinContent(35,0.110315);
   amassMu__3->SetEntries(62);
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
   amassMu__4->SetBinContent(11,128.8288);
   amassMu__4->SetBinContent(12,143.666);
   amassMu__4->SetBinContent(13,152.4967);
   amassMu__4->SetBinContent(14,165.003);
   amassMu__4->SetBinContent(15,169.6201);
   amassMu__4->SetBinContent(16,189.7916);
   amassMu__4->SetBinContent(17,195.7534);
   amassMu__4->SetBinContent(18,206.0633);
   amassMu__4->SetBinContent(19,223.0522);
   amassMu__4->SetBinContent(20,227.3554);
   amassMu__4->SetBinContent(21,240.1756);
   amassMu__4->SetBinContent(22,237.3067);
   amassMu__4->SetBinContent(23,249.1855);
   amassMu__4->SetBinContent(24,248.9614);
   amassMu__4->SetBinContent(25,258.4644);
   amassMu__4->SetBinContent(26,257.3886);
   amassMu__4->SetBinContent(27,259.0023);
   amassMu__4->SetBinContent(28,265.6813);
   amassMu__4->SetBinContent(29,262.1849);
   amassMu__4->SetBinContent(30,261.1539);
   amassMu__4->SetBinContent(31,260.0333);
   amassMu__4->SetBinContent(32,258.7334);
   amassMu__4->SetBinContent(33,260.0333);
   amassMu__4->SetBinContent(34,258.2851);
   amassMu__4->SetBinContent(35,243.403);
   amassMu__4->SetEntries(125411);
   amassMu__4->SetDirectory(0);
   amassMu__4->SetStats(0);
    //amassMu__4->Scale(0.9);
   
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
   amassMu__5->SetBinContent(11,3.129824);
   amassMu__5->SetBinContent(12,3.521052);
   amassMu__5->SetBinContent(13,4.303508);
   amassMu__5->SetBinContent(14,4.499122);
   amassMu__5->SetBinContent(15,6.064034);
   amassMu__5->SetBinContent(16,4.303508);
   amassMu__5->SetBinContent(17,8.215788);
   amassMu__5->SetBinContent(18,6.650876);
   amassMu__5->SetBinContent(19,7.82456);
   amassMu__5->SetBinContent(20,7.042104);
   amassMu__5->SetBinContent(21,10.36754);
   amassMu__5->SetBinContent(22,9.976314);
   amassMu__5->SetBinContent(23,7.82456);
   amassMu__5->SetBinContent(24,9.193858);
   amassMu__5->SetBinContent(25,9.585086);
   amassMu__5->SetBinContent(26,9.976314);
   amassMu__5->SetBinContent(27,9.976314);
   amassMu__5->SetBinContent(28,10.56316);
   amassMu__5->SetBinContent(29,9.585086);
   amassMu__5->SetBinContent(30,7.433332);
   amassMu__5->SetBinContent(31,9.389472);
   amassMu__5->SetBinContent(32,7.237718);
   amassMu__5->SetBinContent(33,9.7807);
   amassMu__5->SetBinContent(34,7.433332);
   amassMu__5->SetBinContent(35,5.86842);
   amassMu__5->SetEntries(970);
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
   amassMu__6->SetBinContent(11,3.545088);
   amassMu__6->SetBinContent(12,3.101952);
   amassMu__6->SetBinContent(13,4.874496);
   amassMu__6->SetBinContent(14,5.317632);
   amassMu__6->SetBinContent(15,5.760768);
   amassMu__6->SetBinContent(16,3.101952);
   amassMu__6->SetBinContent(17,4.874496);
   amassMu__6->SetBinContent(18,6.203904);
   amassMu__6->SetBinContent(19,3.988224);
   amassMu__6->SetBinContent(20,4.874496);
   amassMu__6->SetBinContent(21,6.64704);
   amassMu__6->SetBinContent(22,8.419584);
   amassMu__6->SetBinContent(23,4.874496);
   amassMu__6->SetBinContent(24,3.988224);
   amassMu__6->SetBinContent(25,6.203904);
   amassMu__6->SetBinContent(26,8.86272);
   amassMu__6->SetBinContent(27,4.874496);
   amassMu__6->SetBinContent(28,4.874496);
   amassMu__6->SetBinContent(29,5.760768);
   amassMu__6->SetBinContent(30,6.203904);
   amassMu__6->SetBinContent(31,6.203904);
   amassMu__6->SetBinContent(32,5.317632);
   amassMu__6->SetBinContent(33,6.203904);
   amassMu__6->SetBinContent(34,5.760768);
   amassMu__6->SetBinContent(35,4.874496);
   amassMu__6->SetEntries(304);
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
   amassMu__7->SetBinContent(11,1.757592);
   amassMu__7->SetBinContent(12,1.757592);
   amassMu__7->SetBinContent(13,3.954582);
   amassMu__7->SetBinContent(14,5.712174);
   amassMu__7->SetBinContent(15,8.348562);
   amassMu__7->SetBinContent(16,3.954582);
   amassMu__7->SetBinContent(17,5.712174);
   amassMu__7->SetBinContent(18,3.075786);
   amassMu__7->SetBinContent(19,5.712174);
   amassMu__7->SetBinContent(20,6.151572);
   amassMu__7->SetBinContent(21,6.151572);
   amassMu__7->SetBinContent(22,4.833378);
   amassMu__7->SetBinContent(23,8.348562);
   amassMu__7->SetBinContent(24,8.348562);
   amassMu__7->SetBinContent(25,6.59097);
   amassMu__7->SetBinContent(26,6.151572);
   amassMu__7->SetBinContent(27,5.712174);
   amassMu__7->SetBinContent(28,5.712174);
   amassMu__7->SetBinContent(29,3.515184);
   amassMu__7->SetBinContent(30,7.909164);
   amassMu__7->SetBinContent(31,7.030368);
   amassMu__7->SetBinContent(32,7.909164);
   amassMu__7->SetBinContent(33,5.272776);
   amassMu__7->SetBinContent(34,6.59097);
   amassMu__7->SetBinContent(35,9.227358);
   amassMu__7->SetEntries(331);
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
   amassMu__8->SetBinContent(12,5.78748);
   amassMu__8->SetBinContent(13,2.89374);
   amassMu__8->SetBinContent(16,2.89374);
   amassMu__8->SetBinContent(17,5.78748);
   amassMu__8->SetBinContent(18,14.4687);
   amassMu__8->SetBinContent(19,2.89374);
   amassMu__8->SetBinContent(20,2.89374);
   amassMu__8->SetBinContent(21,2.89374);
   amassMu__8->SetBinContent(22,2.89374);
   amassMu__8->SetBinContent(24,5.78748);
   amassMu__8->SetBinContent(26,2.89374);
   amassMu__8->SetBinContent(29,2.89374);
   amassMu__8->SetBinContent(30,2.89374);
   amassMu__8->SetBinContent(31,5.78748);
   amassMu__8->SetBinContent(32,5.78748);
   amassMu__8->SetBinContent(33,2.89374);
   amassMu__8->SetBinContent(35,5.78748);
   amassMu__8->SetEntries(27);
   amassMu__8->SetDirectory(0);
   amassMu__8->SetStats(0);
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
    amassMu__8->Scale(1.277);  
   amassMuStack->Add(amassMu__8,"");
   
      TH1D *amassMu__9 = new TH1D("amassMu__9","DYLow",500,0,1000);
   amassMu__9->SetBinContent(13,16.1051);
   amassMu__9->SetBinContent(23,16.1051);
   amassMu__9->SetEntries(4);
   amassMu__9->SetDirectory(0);
   amassMu__9->SetStats(0);
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
   amassMu__10->SetBinContent(11,0.008834292);
   amassMu__10->SetBinContent(12,0.006871116);
   amassMu__10->SetBinContent(13,0.006380322);
   amassMu__10->SetBinContent(14,0.01128826);
   amassMu__10->SetBinContent(15,0.01226985);
   amassMu__10->SetBinContent(16,0.01423303);
   amassMu__10->SetBinContent(17,0.008834292);
   amassMu__10->SetBinContent(18,0.01128826);
   amassMu__10->SetBinContent(19,0.01177906);
   amassMu__10->SetBinContent(20,0.01030667);
   amassMu__10->SetBinContent(21,0.01374223);
   amassMu__10->SetBinContent(22,0.01325144);
   amassMu__10->SetBinContent(23,0.01128826);
   amassMu__10->SetBinContent(24,0.00736191);
   amassMu__10->SetBinContent(25,0.006871116);
   amassMu__10->SetBinContent(26,0.00490794);
   amassMu__10->SetBinContent(27,0.006871116);
   amassMu__10->SetBinContent(28,0.001472382);
   amassMu__10->SetBinContent(29,0.002944764);
   amassMu__10->SetBinContent(30,0.003926352);
   amassMu__10->SetBinContent(31,0.000981588);
   amassMu__10->SetBinContent(32,0.00245397);
   amassMu__10->SetBinContent(33,0.004417146);
   amassMu__10->SetBinContent(34,0.007852704);
   amassMu__10->SetBinContent(35,0.004417146);
   amassMu__10->SetEntries(397);
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
      TList * l = amassMuStack->GetHists();
   /*for(int i = 0; i<l->GetSize(); i++){
   	((TH1D*)l->At(i))->Scale(0.88);
   }*/
   amassMuStack->Add(amassMu__10,"");
   amassMuStack->Draw("hist, same");
   TH1D* allMC = (TH1D*)amassMuStack->GetStack()->Last();

   
      TH1D *amassMu__12 = new TH1D("amassMu__12","data",500,0,1000);
   amassMu__12->SetBinContent(11,128);
   amassMu__12->SetBinContent(12,123);
   amassMu__12->SetBinContent(13,157);
   amassMu__12->SetBinContent(14,159);
   amassMu__12->SetBinContent(15,171);
   amassMu__12->SetBinContent(16,187);
   amassMu__12->SetBinContent(17,191);
   amassMu__12->SetBinContent(18,198);
   amassMu__12->SetBinContent(19,210);
   amassMu__12->SetBinContent(20,237);
   amassMu__12->SetBinContent(21,234);
   amassMu__12->SetBinContent(22,240);
   amassMu__12->SetBinContent(23,253);
   amassMu__12->SetBinContent(24,251);
   amassMu__12->SetBinContent(25,234);
   amassMu__12->SetBinContent(26,253);
   amassMu__12->SetBinContent(27,259);
   amassMu__12->SetBinContent(28,265);
   amassMu__12->SetBinContent(29,255);
   amassMu__12->SetBinContent(30,245);
   amassMu__12->SetBinContent(31,266);
   amassMu__12->SetBinContent(32,273);
   amassMu__12->SetBinContent(33,225);
   amassMu__12->SetBinContent(34,235);
   amassMu__12->SetBinContent(35,246);
   amassMu__12->SetEntries(5495);
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
  TLegend *leg = new TLegend(0.0915323,0.0539588,0.9915323,0.980218,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("aptMu__113","Data, 19.7 fb^{-1} @ 8 TeV","LEP");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__123","ZH_125","f");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__122","Z+j (10-50 GeV)","f");

   ci = TColor::GetColor("#ff9999");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__121","Z+j (> 50 GeV)","f");

   ci = TColor::GetColor("#ff6666");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__120","tW","f");

   ci = TColor::GetColor("#336600");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__118","t#bar{t} lept","f");

   ci = TColor::GetColor("#339966");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__117","t#bar{t} dilep","f");

   ci = TColor::GetColor("#ffff66");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__116","WW","f");

   ci = TColor::GetColor("#996633");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__115","WZ","f");

   ci = TColor::GetColor("#66ffff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__114","ZZ","f");

   ci = TColor::GetColor("#ff66ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
/*
   entry=leg->AddEntry("aptMu__124","m_{a} = 40 GeV","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineStyle(7);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__125","m_{a} = 50 GeV","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(8);
   entry->SetLineStyle(5);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("aptMu__126","m_{a} = 60 GeV","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(kBlue+2);
   entry->SetLineStyle(3);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);*/
   leg->Draw();
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
   
   cout<< amassMu__12->Integral()<<endl;
      cout<< allMC->Integral()<<endl;
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
         ratio___16->GetXaxis()->SetRangeUser(0,101.);   
   ratio___16->Draw("ep");
   pad2->Modified();

   amassMu->Modified();
   amassMu->cd();
   amassMu->SetSelected(amassMu);

}
