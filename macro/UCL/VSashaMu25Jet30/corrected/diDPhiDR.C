{
//=========Macro generated from canvas: dphidiMu/#Delta #phi (#mu,#mu)
//=========  (Sat Sep 13 20:04:52 2014) by ROOT version5.34/19
   TCanvas *dphidiMu = new TCanvas("dphidiMu", "#Delta #phi (#mu,#mu)",279,48,500,500);
   dphidiMu->SetHighLightColor(2);
   dphidiMu->Range(0,0,1,1);
   dphidiMu->SetFillColor(0);
   dphidiMu->SetBorderMode(0);
   dphidiMu->SetBorderSize(2);
   dphidiMu->SetTickx(1);
   dphidiMu->SetTicky(1);
   dphidiMu->SetLeftMargin(0.16);
   dphidiMu->SetRightMargin(0.02);
   dphidiMu->SetTopMargin(0.05);
   dphidiMu->SetBottomMargin(0.13);
   dphidiMu->SetFrameFillStyle(0);
   dphidiMu->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.15,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-0.6146341,-24.75389,3.226829,165.6607);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
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
   
   TH1F *dphidiMu__1 = new TH1F("dphidiMu__1","data",20,0,3.15);
   dphidiMu__1->GetXaxis()->SetTitle("");
   dphidiMu__1->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__1->SetBinContent(0,672);
   dphidiMu__1->SetBinContent(1,117);
   dphidiMu__1->SetBinContent(2,137);
   dphidiMu__1->SetBinContent(3,119);
   dphidiMu__1->SetBinContent(4,119);
   dphidiMu__1->SetBinContent(5,97);
   dphidiMu__1->SetBinContent(6,78);
   dphidiMu__1->SetBinContent(7,9);
   dphidiMu__1->SetEntries(1348);
   dphidiMu__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("dphidiMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1348   ");
   text = ptstats->AddText("Mean  = 0.4396");
   text = ptstats->AddText("RMS   = 0.2644");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   dphidiMu__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(dphidiMu__1);
   dphidiMu__1->SetLineStyle(0);
   dphidiMu__1->SetMarkerStyle(20);
   dphidiMu__1->GetXaxis()->SetTitle("#Delta #phi (#mu,#mu)");
   dphidiMu__1->GetXaxis()->SetLabelFont(42);
   dphidiMu__1->GetXaxis()->SetLabelOffset(0.007);
   dphidiMu__1->GetXaxis()->SetLabelSize(0.05);
   dphidiMu__1->GetXaxis()->SetTitleSize(0.06);
   dphidiMu__1->GetXaxis()->SetTitleOffset(0.9);
   dphidiMu__1->GetXaxis()->SetTitleFont(42);
   dphidiMu__1->GetYaxis()->SetTitle("Events/0.2");
   dphidiMu__1->GetYaxis()->SetLabelFont(42);
   dphidiMu__1->GetYaxis()->SetLabelOffset(0.007);
   dphidiMu__1->GetYaxis()->SetLabelSize(0.05);
   dphidiMu__1->GetYaxis()->SetTitleSize(0.06);
   dphidiMu__1->GetYaxis()->SetTitleOffset(1.5);
   dphidiMu__1->GetYaxis()->SetTitleFont(42);
   dphidiMu__1->GetZaxis()->SetLabelFont(42);
   dphidiMu__1->GetZaxis()->SetLabelOffset(0.007);
   dphidiMu__1->GetZaxis()->SetLabelSize(0.05);
   dphidiMu__1->GetZaxis()->SetTitleSize(0.06);
   dphidiMu__1->GetZaxis()->SetTitleFont(42);
   dphidiMu__1->Draw("e");
   
   THStack *dphidiMuStack = new THStack();
   dphidiMuStack->SetName("dphidiMuStack");
   dphidiMuStack->SetTitle("MC stack");
   
   TH1F *dphidiMu_stack_1 = new TH1F("dphidiMu_stack_1","MC stack",20,0,3.15);
   dphidiMu_stack_1->GetXaxis()->SetTitle("");
   dphidiMu_stack_1->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu_stack_1->SetMinimum(-0.261559);
   dphidiMu_stack_1->SetMaximum(149.6384);
   dphidiMu_stack_1->SetDirectory(0);
   dphidiMu_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   dphidiMu_stack_1->SetLineColor(ci);
   dphidiMu_stack_1->GetXaxis()->SetLabelFont(42);
   dphidiMu_stack_1->GetXaxis()->SetLabelSize(0.035);
   dphidiMu_stack_1->GetXaxis()->SetTitleSize(0.035);
   dphidiMu_stack_1->GetXaxis()->SetTitleFont(42);
   dphidiMu_stack_1->GetYaxis()->SetLabelFont(42);
   dphidiMu_stack_1->GetYaxis()->SetLabelSize(0.035);
   dphidiMu_stack_1->GetYaxis()->SetTitleSize(0.035);
   dphidiMu_stack_1->GetYaxis()->SetTitleFont(42);
   dphidiMu_stack_1->GetZaxis()->SetLabelFont(42);
   dphidiMu_stack_1->GetZaxis()->SetLabelSize(0.035);
   dphidiMu_stack_1->GetZaxis()->SetTitleSize(0.035);
   dphidiMu_stack_1->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->SetHistogram(dphidiMu_stack_1);
   
   
   TH1F *dphidiMu__2 = new TH1F("dphidiMu__2","ZZ",20,0,3.15);
   dphidiMu__2->GetXaxis()->SetTitle("");
   dphidiMu__2->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__2->SetBinContent(0,2.577734);
   dphidiMu__2->SetBinContent(1,0.3466424);
   dphidiMu__2->SetBinContent(2,0.3953645);
   dphidiMu__2->SetBinContent(3,0.5384425);
   dphidiMu__2->SetBinContent(4,0.2637066);
   dphidiMu__2->SetBinContent(5,0.4957214);
   dphidiMu__2->SetBinContent(6,0.4176379);
   dphidiMu__2->SetBinContent(7,0.05065949);
   dphidiMu__2->SetBinError(0,0.206861);
   dphidiMu__2->SetBinError(1,0.07585782);
   dphidiMu__2->SetBinError(2,0.08101369);
   dphidiMu__2->SetBinError(3,0.09454297);
   dphidiMu__2->SetBinError(4,0.06616374);
   dphidiMu__2->SetBinError(5,0.09071485);
   dphidiMu__2->SetBinError(6,0.08326443);
   dphidiMu__2->SetBinError(7,0.02899946);
   dphidiMu__2->SetEntries(322);
   dphidiMu__2->SetDirectory(0);

   ci = TColor::GetColor("#ff66ff");
   dphidiMu__2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__2->SetLineColor(ci);
   dphidiMu__2->GetXaxis()->SetLabelFont(42);
   dphidiMu__2->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__2->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__2->GetXaxis()->SetTitleFont(42);
   dphidiMu__2->GetYaxis()->SetLabelFont(42);
   dphidiMu__2->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__2->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__2->GetYaxis()->SetTitleFont(42);
   dphidiMu__2->GetZaxis()->SetLabelFont(42);
   dphidiMu__2->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__2->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__2->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__2,"");
   
   TH1F *dphidiMu__3 = new TH1F("dphidiMu__3","WZ",20,0,3.15);
   dphidiMu__3->GetXaxis()->SetTitle("");
   dphidiMu__3->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__3->SetBinContent(0,1.886581);
   dphidiMu__3->SetBinContent(1,0.290352);
   dphidiMu__3->SetBinContent(2,0.2021696);
   dphidiMu__3->SetBinContent(3,0.4585251);
   dphidiMu__3->SetBinContent(4,0.2629426);
   dphidiMu__3->SetBinContent(5,0.1846161);
   dphidiMu__3->SetBinContent(6,0.2091001);
   dphidiMu__3->SetBinError(0,0.3533738);
   dphidiMu__3->SetBinError(1,0.1386306);
   dphidiMu__3->SetBinError(2,0.115679);
   dphidiMu__3->SetBinError(3,0.174212);
   dphidiMu__3->SetBinError(4,0.131925);
   dphidiMu__3->SetBinError(5,0.110543);
   dphidiMu__3->SetBinError(6,0.1176451);
   dphidiMu__3->SetEntries(53);
   dphidiMu__3->SetDirectory(0);

   ci = TColor::GetColor("#66ffff");
   dphidiMu__3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__3->SetLineColor(ci);
   dphidiMu__3->GetXaxis()->SetLabelFont(42);
   dphidiMu__3->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__3->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__3->GetXaxis()->SetTitleFont(42);
   dphidiMu__3->GetYaxis()->SetLabelFont(42);
   dphidiMu__3->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__3->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__3->GetYaxis()->SetTitleFont(42);
   dphidiMu__3->GetZaxis()->SetLabelFont(42);
   dphidiMu__3->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__3->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__3->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__3,"");
   
   TH1F *dphidiMu__4 = new TH1F("dphidiMu__4","WW",20,0,3.15);
   dphidiMu__4->GetXaxis()->SetTitle("");
   dphidiMu__4->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__4->SetBinContent(1,0.07268661);
   dphidiMu__4->SetBinContent(2,0.1250197);
   dphidiMu__4->SetBinContent(3,0.2156176);
   dphidiMu__4->SetBinContent(4,0.3531398);
   dphidiMu__4->SetBinContent(5,0.1177212);
   dphidiMu__4->SetBinError(1,0.08954575);
   dphidiMu__4->SetBinError(2,0.1174376);
   dphidiMu__4->SetBinError(3,0.1542268);
   dphidiMu__4->SetBinError(4,0.1973745);
   dphidiMu__4->SetBinError(5,0.1139581);
   dphidiMu__4->SetEntries(10);
   dphidiMu__4->SetDirectory(0);

   ci = TColor::GetColor("#996633");
   dphidiMu__4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__4->SetLineColor(ci);
   dphidiMu__4->GetXaxis()->SetLabelFont(42);
   dphidiMu__4->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__4->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__4->GetXaxis()->SetTitleFont(42);
   dphidiMu__4->GetYaxis()->SetLabelFont(42);
   dphidiMu__4->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__4->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__4->GetYaxis()->SetTitleFont(42);
   dphidiMu__4->GetZaxis()->SetLabelFont(42);
   dphidiMu__4->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__4->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__4->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__4,"");
   
   TH1F *dphidiMu__5 = new TH1F("dphidiMu__5","t#bar{t} dilep",20,0,3.15);
   dphidiMu__5->GetXaxis()->SetTitle("");
   dphidiMu__5->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__5->SetBinContent(0,118.2206);
   dphidiMu__5->SetBinContent(1,17.13869);
   dphidiMu__5->SetBinContent(2,18.46516);
   dphidiMu__5->SetBinContent(3,21.42878);
   dphidiMu__5->SetBinContent(4,21.55733);
   dphidiMu__5->SetBinContent(5,18.75476);
   dphidiMu__5->SetBinContent(6,14.30124);
   dphidiMu__5->SetBinContent(7,2.948008);
   dphidiMu__5->SetBinError(0,2.290951);
   dphidiMu__5->SetBinError(1,0.8722841);
   dphidiMu__5->SetBinError(2,0.9054109);
   dphidiMu__5->SetBinError(3,0.9753665);
   dphidiMu__5->SetBinError(4,0.9782878);
   dphidiMu__5->SetBinError(5,0.9124833);
   dphidiMu__5->SetBinError(6,0.7968122);
   dphidiMu__5->SetBinError(7,0.3617708);
   dphidiMu__5->SetEntries(5808);
   dphidiMu__5->SetDirectory(0);

   ci = TColor::GetColor("#ffff66");
   dphidiMu__5->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__5->SetLineColor(ci);
   dphidiMu__5->GetXaxis()->SetLabelFont(42);
   dphidiMu__5->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__5->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__5->GetXaxis()->SetTitleFont(42);
   dphidiMu__5->GetYaxis()->SetLabelFont(42);
   dphidiMu__5->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__5->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__5->GetYaxis()->SetTitleFont(42);
   dphidiMu__5->GetZaxis()->SetLabelFont(42);
   dphidiMu__5->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__5->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__5->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__5,"");
   
   TH1F *dphidiMu__6 = new TH1F("dphidiMu__6","t#bar{t} lept",20,0,3.15);
   dphidiMu__6->GetXaxis()->SetTitle("");
   dphidiMu__6->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__6->SetBinContent(0,0.671962);
   dphidiMu__6->SetBinContent(4,0.09082209);
   dphidiMu__6->SetBinError(0,0.3626279);
   dphidiMu__6->SetBinError(4,0.1333167);
   dphidiMu__6->SetEntries(4);
   dphidiMu__6->SetDirectory(0);

   ci = TColor::GetColor("#339966");
   dphidiMu__6->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__6->SetLineColor(ci);
   dphidiMu__6->GetXaxis()->SetLabelFont(42);
   dphidiMu__6->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__6->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__6->GetXaxis()->SetTitleFont(42);
   dphidiMu__6->GetYaxis()->SetLabelFont(42);
   dphidiMu__6->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__6->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__6->GetYaxis()->SetTitleFont(42);
   dphidiMu__6->GetZaxis()->SetLabelFont(42);
   dphidiMu__6->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__6->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__6->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__6,"");
   
   TH1F *dphidiMu__7 = new TH1F("dphidiMu__7","tW",20,0,3.15);
   dphidiMu__7->GetXaxis()->SetTitle("");
   dphidiMu__7->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__7->SetBinContent(0,13.39529);
   dphidiMu__7->SetBinContent(1,1.943939);
   dphidiMu__7->SetBinContent(2,1.353081);
   dphidiMu__7->SetBinContent(3,3.030199);
   dphidiMu__7->SetBinContent(4,2.819124);
   dphidiMu__7->SetBinContent(5,4.030117);
   dphidiMu__7->SetBinContent(6,1.175309);
   dphidiMu__7->SetBinError(0,2.42608);
   dphidiMu__7->SetBinError(1,0.9242096);
   dphidiMu__7->SetBinError(2,0.7710651);
   dphidiMu__7->SetBinError(3,1.153891);
   dphidiMu__7->SetBinError(4,1.112977);
   dphidiMu__7->SetBinError(5,1.330724);
   dphidiMu__7->SetBinError(6,0.7186296);
   dphidiMu__7->SetEntries(71);
   dphidiMu__7->SetDirectory(0);

   ci = TColor::GetColor("#336600");
   dphidiMu__7->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__7->SetLineColor(ci);
   dphidiMu__7->GetXaxis()->SetLabelFont(42);
   dphidiMu__7->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__7->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__7->GetXaxis()->SetTitleFont(42);
   dphidiMu__7->GetYaxis()->SetLabelFont(42);
   dphidiMu__7->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__7->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__7->GetYaxis()->SetTitleFont(42);
   dphidiMu__7->GetZaxis()->SetLabelFont(42);
   dphidiMu__7->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__7->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__7->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__7,"");
   
   TH1F *dphidiMu__8 = new TH1F("dphidiMu__8","#bar{t}W",20,0,3.15);
   dphidiMu__8->GetXaxis()->SetTitle("");
   dphidiMu__8->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__8->SetBinContent(0,18.29774);
   dphidiMu__8->SetBinContent(1,1.511279);
   dphidiMu__8->SetBinContent(2,3.664922);
   dphidiMu__8->SetBinContent(3,2.533788);
   dphidiMu__8->SetBinContent(4,3.372515);
   dphidiMu__8->SetBinContent(5,2.342875);
   dphidiMu__8->SetBinContent(6,0.4495154);
   dphidiMu__8->SetBinContent(7,0.4083171);
   dphidiMu__8->SetBinError(0,2.847523);
   dphidiMu__8->SetBinError(1,0.8183536);
   dphidiMu__8->SetBinError(2,1.274386);
   dphidiMu__8->SetBinError(3,1.059629);
   dphidiMu__8->SetBinError(4,1.222491);
   dphidiMu__8->SetBinError(5,1.018927);
   dphidiMu__8->SetBinError(6,0.4463144);
   dphidiMu__8->SetBinError(7,0.4253706);
   dphidiMu__8->SetEntries(77);
   dphidiMu__8->SetDirectory(0);

   ci = TColor::GetColor("#336600");
   dphidiMu__8->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__8->SetLineColor(ci);
   dphidiMu__8->GetXaxis()->SetLabelFont(42);
   dphidiMu__8->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__8->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__8->GetXaxis()->SetTitleFont(42);
   dphidiMu__8->GetYaxis()->SetLabelFont(42);
   dphidiMu__8->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__8->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__8->GetYaxis()->SetTitleFont(42);
   dphidiMu__8->GetZaxis()->SetLabelFont(42);
   dphidiMu__8->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__8->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__8->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__8,"");
   
   TH1F *dphidiMu__9 = new TH1F("dphidiMu__9","Z+j",20,0,3.15);
   dphidiMu__9->GetXaxis()->SetTitle("");
   dphidiMu__9->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__9->SetBinContent(0,116.7119);
   dphidiMu__9->SetBinContent(1,12.29725);
   dphidiMu__9->SetBinContent(2,21.54579);
   dphidiMu__9->SetBinContent(3,10.72908);
   dphidiMu__9->SetBinContent(4,19.30503);
   dphidiMu__9->SetBinContent(5,22.25445);
   dphidiMu__9->SetBinContent(6,34.42245);
   dphidiMu__9->SetBinContent(7,9.996213);
   dphidiMu__9->SetBinError(0,16.26273);
   dphidiMu__9->SetBinError(1,5.278854);
   dphidiMu__9->SetBinError(2,6.987423);
   dphidiMu__9->SetBinError(3,4.930795);
   dphidiMu__9->SetBinError(4,6.614104);
   dphidiMu__9->SetBinError(5,7.101404);
   dphidiMu__9->SetBinError(6,8.831952);
   dphidiMu__9->SetBinError(7,4.759415);
   dphidiMu__9->SetEntries(110);
   dphidiMu__9->SetDirectory(0);

   ci = TColor::GetColor("#ff6666");
   dphidiMu__9->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   dphidiMu__9->SetLineColor(ci);
   dphidiMu__9->GetXaxis()->SetLabelFont(42);
   dphidiMu__9->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__9->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__9->GetXaxis()->SetTitleFont(42);
   dphidiMu__9->GetYaxis()->SetLabelFont(42);
   dphidiMu__9->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__9->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__9->GetYaxis()->SetTitleFont(42);
   dphidiMu__9->GetZaxis()->SetLabelFont(42);
   dphidiMu__9->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__9->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__9->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__9,"");
   
   TH1F *dphidiMu__10 = new TH1F("dphidiMu__10","Z+j",20,0,3.15);
   dphidiMu__10->GetXaxis()->SetTitle("");
   dphidiMu__10->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__10->SetBinContent(0,299.1354);
   dphidiMu__10->SetBinContent(1,83.83932);
   dphidiMu__10->SetBinContent(2,54.39445);
   dphidiMu__10->SetBinContent(3,32.19522);
   dphidiMu__10->SetBinContent(4,94.42375);
   dphidiMu__10->SetBinContent(5,42.71976);
   dphidiMu__10->SetBinContent(6,18.8117);
   dphidiMu__10->SetBinContent(7,6.354531);
   dphidiMu__10->SetBinError(0,45.39349);
   dphidiMu__10->SetBinError(1,24.03165);
   dphidiMu__10->SetBinError(2,19.35695);
   dphidiMu__10->SetBinError(3,14.89208);
   dphidiMu__10->SetBinError(4,25.50353);
   dphidiMu__10->SetBinError(5,17.15434);
   dphidiMu__10->SetBinError(6,11.38345);
   dphidiMu__10->SetBinError(7,6.61609);
   dphidiMu__10->SetEntries(97);
   dphidiMu__10->SetDirectory(0);

   ci = TColor::GetColor("#ff6666");
   dphidiMu__10->SetFillColor(kRed-9);
   ci = TColor::GetColor("#000099");
   dphidiMu__10->SetLineColor(ci);
   dphidiMu__10->GetXaxis()->SetLabelFont(42);
   dphidiMu__10->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__10->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__10->GetXaxis()->SetTitleFont(42);
   dphidiMu__10->GetYaxis()->SetLabelFont(42);
   dphidiMu__10->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__10->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__10->GetYaxis()->SetTitleFont(42);
   dphidiMu__10->GetZaxis()->SetLabelFont(42);
   dphidiMu__10->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__10->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__10->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__10,"");
   
   TH1F *dphidiMu__11 = new TH1F("dphidiMu__11","ZH_125",20,0,3.15);
   dphidiMu__11->GetXaxis()->SetTitle("");
   dphidiMu__11->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__11->SetBinContent(0,0.3586245);
   dphidiMu__11->SetBinContent(1,0.04143403);
   dphidiMu__11->SetBinContent(2,0.04465713);
   dphidiMu__11->SetBinContent(3,0.058189);
   dphidiMu__11->SetBinContent(4,0.06441072);
   dphidiMu__11->SetBinContent(5,0.06691773);
   dphidiMu__11->SetBinContent(6,0.07293291);
   dphidiMu__11->SetBinContent(7,0.01764258);
   dphidiMu__11->SetBinError(0,0.0132669);
   dphidiMu__11->SetBinError(1,0.004509498);
   dphidiMu__11->SetBinError(2,0.004681608);
   dphidiMu__11->SetBinError(3,0.005344045);
   dphidiMu__11->SetBinError(4,0.005622491);
   dphidiMu__11->SetBinError(5,0.005730866);
   dphidiMu__11->SetBinError(6,0.005982896);
   dphidiMu__11->SetBinError(7,0.002942596);
   dphidiMu__11->SetEntries(1581);
   dphidiMu__11->SetDirectory(0);

   ci = TColor::GetColor("#000099");
   dphidiMu__11->SetLineColor(ci);
   dphidiMu__11->GetXaxis()->SetLabelFont(42);
   dphidiMu__11->GetXaxis()->SetLabelSize(0.035);
   dphidiMu__11->GetXaxis()->SetTitleSize(0.035);
   dphidiMu__11->GetXaxis()->SetTitleFont(42);
   dphidiMu__11->GetYaxis()->SetLabelFont(42);
   dphidiMu__11->GetYaxis()->SetLabelSize(0.035);
   dphidiMu__11->GetYaxis()->SetTitleSize(0.035);
   dphidiMu__11->GetYaxis()->SetTitleFont(42);
   dphidiMu__11->GetZaxis()->SetLabelFont(42);
   dphidiMu__11->GetZaxis()->SetLabelSize(0.035);
   dphidiMu__11->GetZaxis()->SetTitleSize(0.035);
   dphidiMu__11->GetZaxis()->SetTitleFont(42);
   dphidiMuStack->Add(dphidiMu__11,"");
   dphidiMuStack->Draw("hist, same");
   
   dphidiMuStack = new THStack();
   dphidiMuStack->SetName("dphidiMuStack");
   dphidiMuStack->SetTitle("MC stack - not stacked");
   dphidiMuStack->Draw("nostack, hist, same");
   
   TH1F *dphidiMu__12 = new TH1F("dphidiMu__12","m_{a} = 40 GeV",20,0,3.15);
   dphidiMu__12->GetXaxis()->SetTitle("");
   dphidiMu__12->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__12->SetBinContent(0,0.5555955);
   dphidiMu__12->SetBinContent(1,0.03659799);
   dphidiMu__12->SetBinContent(2,0.09270991);
   dphidiMu__12->SetBinContent(3,0.05719519);
   dphidiMu__12->SetBinContent(4,0.04226442);
   dphidiMu__12->SetBinContent(5,0.08233259);
   dphidiMu__12->SetBinContent(6,0.1187404);
   dphidiMu__12->SetBinContent(7,0.05445414);
   dphidiMu__12->SetBinError(0,0.1038604);
   dphidiMu__12->SetBinError(1,0.02665626);
   dphidiMu__12->SetBinError(2,0.04242617);
   dphidiMu__12->SetBinError(3,0.03332349);
   dphidiMu__12->SetBinError(4,0.02864561);
   dphidiMu__12->SetBinError(5,0.03998127);
   dphidiMu__12->SetBinError(6,0.04801423);
   dphidiMu__12->SetBinError(7,0.03251518);
   dphidiMu__12->SetEntries(57);
   dphidiMu__12->SetDirectory(0);
   dphidiMu__12->SetLineStyle(0);
   dphidiMu__12->SetMarkerStyle(20);
   dphidiMu__12->GetXaxis()->SetLabelFont(42);
   dphidiMu__12->GetXaxis()->SetLabelOffset(0.007);
   dphidiMu__12->GetXaxis()->SetLabelSize(0.05);
   dphidiMu__12->GetXaxis()->SetTitleSize(0.06);
   dphidiMu__12->GetXaxis()->SetTitleOffset(0.9);
   dphidiMu__12->GetXaxis()->SetTitleFont(42);
   dphidiMu__12->GetYaxis()->SetLabelFont(42);
   dphidiMu__12->GetYaxis()->SetLabelOffset(0.007);
   dphidiMu__12->GetYaxis()->SetLabelSize(0.05);
   dphidiMu__12->GetYaxis()->SetTitleSize(0.06);
   dphidiMu__12->GetYaxis()->SetTitleOffset(1.5);
   dphidiMu__12->GetYaxis()->SetTitleFont(42);
   dphidiMu__12->GetZaxis()->SetLabelFont(42);
   dphidiMu__12->GetZaxis()->SetLabelOffset(0.007);
   dphidiMu__12->GetZaxis()->SetLabelSize(0.05);
   dphidiMu__12->GetZaxis()->SetTitleSize(0.06);
   dphidiMu__12->GetZaxis()->SetTitleFont(42);
   dphidiMu__12->Draw("hist, same");
   
   TH1F *dphidiMu__13 = new TH1F("dphidiMu__13","m_{a} = 50 GeV",20,0,3.15);
   dphidiMu__13->GetXaxis()->SetTitle("");
   dphidiMu__13->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__13->SetBinContent(0,0.1401516);
   dphidiMu__13->SetBinContent(1,0.02232719);
   dphidiMu__13->SetBinContent(2,0.02169208);
   dphidiMu__13->SetBinContent(3,0.0198646);
   dphidiMu__13->SetBinContent(4,0.07144628);
   dphidiMu__13->SetBinError(0,0.05238374);
   dphidiMu__13->SetBinError(1,0.02090809);
   dphidiMu__13->SetBinError(2,0.02060858);
   dphidiMu__13->SetBinError(3,0.01972138);
   dphidiMu__13->SetBinError(4,0.03740135);
   dphidiMu__13->SetEntries(12);
   dphidiMu__13->SetDirectory(0);
   dphidiMu__13->SetLineStyle(0);
   dphidiMu__13->SetMarkerStyle(20);
   dphidiMu__13->GetXaxis()->SetLabelFont(42);
   dphidiMu__13->GetXaxis()->SetLabelOffset(0.007);
   dphidiMu__13->GetXaxis()->SetLabelSize(0.05);
   dphidiMu__13->GetXaxis()->SetTitleSize(0.06);
   dphidiMu__13->GetXaxis()->SetTitleOffset(0.9);
   dphidiMu__13->GetXaxis()->SetTitleFont(42);
   dphidiMu__13->GetYaxis()->SetLabelFont(42);
   dphidiMu__13->GetYaxis()->SetLabelOffset(0.007);
   dphidiMu__13->GetYaxis()->SetLabelSize(0.05);
   dphidiMu__13->GetYaxis()->SetTitleSize(0.06);
   dphidiMu__13->GetYaxis()->SetTitleOffset(1.5);
   dphidiMu__13->GetYaxis()->SetTitleFont(42);
   dphidiMu__13->GetZaxis()->SetLabelFont(42);
   dphidiMu__13->GetZaxis()->SetLabelOffset(0.007);
   dphidiMu__13->GetZaxis()->SetLabelSize(0.05);
   dphidiMu__13->GetZaxis()->SetTitleSize(0.06);
   dphidiMu__13->GetZaxis()->SetTitleFont(42);
   dphidiMu__13->Draw("hist, same");
   
   TH1F *dphidiMu__14 = new TH1F("dphidiMu__14","m_{a} = 60 GeV",20,0,3.15);
   dphidiMu__14->GetXaxis()->SetTitle("");
   dphidiMu__14->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__14->SetBinContent(5,0.0180338);
   dphidiMu__14->SetBinError(5,0.0186791);
   dphidiMu__14->SetEntries(1);
   dphidiMu__14->SetDirectory(0);
   dphidiMu__14->SetLineStyle(0);
   dphidiMu__14->SetMarkerStyle(20);
   dphidiMu__14->GetXaxis()->SetLabelFont(42);
   dphidiMu__14->GetXaxis()->SetLabelOffset(0.007);
   dphidiMu__14->GetXaxis()->SetLabelSize(0.05);
   dphidiMu__14->GetXaxis()->SetTitleSize(0.06);
   dphidiMu__14->GetXaxis()->SetTitleOffset(0.9);
   dphidiMu__14->GetXaxis()->SetTitleFont(42);
   dphidiMu__14->GetYaxis()->SetLabelFont(42);
   dphidiMu__14->GetYaxis()->SetLabelOffset(0.007);
   dphidiMu__14->GetYaxis()->SetLabelSize(0.05);
   dphidiMu__14->GetYaxis()->SetTitleSize(0.06);
   dphidiMu__14->GetYaxis()->SetTitleOffset(1.5);
   dphidiMu__14->GetYaxis()->SetTitleFont(42);
   dphidiMu__14->GetZaxis()->SetLabelFont(42);
   dphidiMu__14->GetZaxis()->SetLabelOffset(0.007);
   dphidiMu__14->GetZaxis()->SetLabelSize(0.05);
   dphidiMu__14->GetZaxis()->SetTitleSize(0.06);
   dphidiMu__14->GetZaxis()->SetTitleFont(42);
   dphidiMu__14->Draw("hist, same");
   
   TH1F *dphidiMu__15 = new TH1F("dphidiMu__15","data",20,0,3.15);
   dphidiMu__15->GetXaxis()->SetTitle("");
   dphidiMu__15->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   dphidiMu__15->SetBinContent(0,672);
   dphidiMu__15->SetBinContent(1,117);
   dphidiMu__15->SetBinContent(2,137);
   dphidiMu__15->SetBinContent(3,119);
   dphidiMu__15->SetBinContent(4,119);
   dphidiMu__15->SetBinContent(5,97);
   dphidiMu__15->SetBinContent(6,78);
   dphidiMu__15->SetBinContent(7,9);
   dphidiMu__15->SetEntries(1348);
   dphidiMu__15->SetDirectory(0);
   
   ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   text = ptstats->AddText("dphidiMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1348   ");
   text = ptstats->AddText("Mean  = 0.4396");
   text = ptstats->AddText("RMS   = 0.2644");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   dphidiMu__15->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(dphidiMu__15);
   dphidiMu__15->SetLineStyle(0);
   dphidiMu__15->SetMarkerStyle(20);
   dphidiMu__15->GetXaxis()->SetTitle("#Delta #phi (#mu,#mu)");
   dphidiMu__15->GetXaxis()->SetLabelFont(42);
   dphidiMu__15->GetXaxis()->SetLabelOffset(0.007);
   dphidiMu__15->GetXaxis()->SetLabelSize(0.05);
   dphidiMu__15->GetXaxis()->SetTitleSize(0.06);
   dphidiMu__15->GetXaxis()->SetTitleOffset(0.9);
   dphidiMu__15->GetXaxis()->SetTitleFont(42);
   dphidiMu__15->GetYaxis()->SetTitle("Events/0.2");
   dphidiMu__15->GetYaxis()->SetLabelFont(42);
   dphidiMu__15->GetYaxis()->SetLabelOffset(0.007);
   dphidiMu__15->GetYaxis()->SetLabelSize(0.05);
   dphidiMu__15->GetYaxis()->SetTitleSize(0.06);
   dphidiMu__15->GetYaxis()->SetTitleOffset(1.5);
   dphidiMu__15->GetYaxis()->SetTitleFont(42);
   dphidiMu__15->GetZaxis()->SetLabelFont(42);
   dphidiMu__15->GetZaxis()->SetLabelOffset(0.007);
   dphidiMu__15->GetZaxis()->SetLabelSize(0.05);
   dphidiMu__15->GetZaxis()->SetTitleSize(0.06);
   dphidiMu__15->GetZaxis()->SetTitleFont(42);
   dphidiMu__15->Draw("e, same");
   

   TLegend *leg = new TLegend(0.5,0.67,0.88,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("dphidiMu__1","Data","LEP");
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("dphidiMu__11","ZH_125","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("dphidiMu__10","Z+j (10-50 GeV)","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("dphidiMu__9","Z+j (> 50 GeV)","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("dphidiMu__8","tW","f");
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
   entry=leg->AddEntry("dphidiMu__6","t#bar{t} lept","f");
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
   entry=leg->AddEntry("dphidiMu__5","t#bar{t} dilep","f");
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
   entry=leg->AddEntry("dphidiMu__4","WW","f");
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
   entry=leg->AddEntry("dphidiMu__3","WZ","f");
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
   entry=leg->AddEntry("dphidiMu__2","ZZ","f");
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
   pad1->cd();
   leg->Draw();
   pad1->Modified();

dphidiMu->cd();

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

   ci = TColor::GetColor("#000099");
   
   TPaveText *pt = new TPaveText(0.4466532,0.94,0.5533468,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("data");
   pt->Draw();
   pad1->Modified();
   dphidiMu->cd();
  
// ------------>Primitives in pad: pad2
   pad2 = new TPad("pad2", "pad1",0,0,1,0.15);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-0.6146341,-0.5599176,3.226829,3.747141);
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
   
   TH1F *ratio__16 = new TH1F("ratio__16","ZH_125",20,0,3.15);
   ratio__16->SetBinContent(0,1./0.8500832);
   ratio__16->SetBinContent(1,1./1.004116);
   ratio__16->SetBinContent(2,1./0.7313184);
   ratio__16->SetBinContent(3,1./0.5982171);
   ratio__16->SetBinContent(4,1./1.197586);
   ratio__16->SetBinContent(5,1./0.9378034);
   ratio__16->SetBinContent(6,1./0.8956395);
   ratio__16->SetBinContent(7,1./2.197263);
   ratio__16->SetBinError(0,0.07916614);
   ratio__16->SetBinError(1,0.2302415);
   ratio__16->SetBinError(2,0.1631936);
   ratio__16->SetBinError(3,0.1436314);
   ratio__16->SetBinError(4,0.2476664);
   ratio__16->SetBinError(5,0.214692);
   ratio__16->SetBinError(6,0.2112573);
   ratio__16->SetBinError(7,1.166344);
   ratio__16->SetEntries(35.45809);
   ratio__16->SetDirectory(0);
   ratio__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   ratio__16->SetLineColor(ci);
   ratio__16->SetMarkerStyle(20);
   ratio__16->GetXaxis()->SetLabelFont(42);
   ratio__16->GetXaxis()->SetLabelSize(0.035);
   ratio__16->GetXaxis()->SetTitleSize(0.035);
   ratio__16->GetXaxis()->SetTitleFont(42);
   ratio__16->GetYaxis()->SetTitle("Data/MC");
   ratio__16->GetYaxis()->SetLabelFont(42);
   ratio__16->GetYaxis()->SetLabelSize(0.17);
   ratio__16->GetYaxis()->SetTitleSize(0.24);
   ratio__16->GetYaxis()->SetTitleOffset(0.35);
   ratio__16->GetYaxis()->SetTitleFont(42);
   ratio__16->GetZaxis()->SetLabelFont(42);
   ratio__16->GetZaxis()->SetLabelSize(0.035);
   ratio__16->GetZaxis()->SetTitleSize(0.035);
   ratio__16->GetZaxis()->SetTitleFont(42);
   ratio__16->Draw("ep");
   
   pt = new TPaveText(0.473871,0.9106118,0.526129,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("ZH_125");
   pt->Draw();
   pad2->Modified();
   dphidiMu->cd();
      tex = new TLatex(0.925,0.87,"");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   dphidiMu->Modified();
   dphidiMu->cd();
   dphidiMu->SetSelected(dphidiMu);

}
