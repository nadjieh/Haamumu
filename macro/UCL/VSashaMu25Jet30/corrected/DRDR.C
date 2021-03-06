{
//=========Macro generated from canvas: diMudR/#Delta R (#mu,#mu)
//=========  (Sat Sep 13 10:19:45 2014) by ROOT version5.34/19
   TCanvas *diMudR = new TCanvas("diMudR", "#Delta R (#mu,#mu)",3,24,500,500);
   diMudR->SetHighLightColor(2);
   diMudR->Range(0,0,1,1);
   diMudR->SetFillColor(0);
   diMudR->SetBorderMode(0);
   diMudR->SetBorderSize(2);
   diMudR->SetLogy();
   diMudR->SetTickx(1);
   diMudR->SetTicky(1);
   diMudR->SetLeftMargin(0.16);
   diMudR->SetRightMargin(0.02);
   diMudR->SetTopMargin(0.05);
   diMudR->SetBottomMargin(0.13);
   diMudR->SetFrameFillStyle(0);
   diMudR->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.15,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-0.9756097,-156.6725,5.121951,1048.501);
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
   
   TH1F *diMudR__81 = new TH1F("diMudR__81","data",10,0,5);
   diMudR__81->GetXaxis()->SetTitle("");
   diMudR__81->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__81->SetBinContent(1,437);
   diMudR__81->SetBinContent(2,911);
   diMudR__81->SetEntries(1348);
   diMudR__81->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("diMudR");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1348   ");
   text = ptstats->AddText("Mean  = 0.6444");
   text = ptstats->AddText("RMS   = 0.2282");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   diMudR__81->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(diMudR__81);
   diMudR__81->SetLineStyle(0);
   diMudR__81->SetMarkerStyle(20);
   diMudR__81->GetXaxis()->SetTitle("#Delta R (#mu,#mu)");
   diMudR__81->GetXaxis()->SetLabelFont(42);
   diMudR__81->GetXaxis()->SetLabelOffset(0.007);
   diMudR__81->GetXaxis()->SetLabelSize(0.05);
   diMudR__81->GetXaxis()->SetTitleSize(0.06);
   diMudR__81->GetXaxis()->SetTitleOffset(0.9);
   diMudR__81->GetXaxis()->SetTitleFont(42);
   diMudR__81->GetYaxis()->SetTitle("Events/0.5");
   diMudR__81->GetYaxis()->SetLabelFont(42);
   diMudR__81->GetYaxis()->SetLabelOffset(0.007);
   diMudR__81->GetYaxis()->SetLabelSize(0.05);
   diMudR__81->GetYaxis()->SetTitleSize(0.06);
   diMudR__81->GetYaxis()->SetTitleOffset(1.5);
   diMudR__81->GetYaxis()->SetTitleFont(42);
   diMudR__81->GetZaxis()->SetLabelFont(42);
   diMudR__81->GetZaxis()->SetLabelOffset(0.007);
   diMudR__81->GetZaxis()->SetLabelSize(0.05);
   diMudR__81->GetZaxis()->SetTitleSize(0.06);
   diMudR__81->GetZaxis()->SetTitleFont(42);
   diMudR__81->Draw("e");
   
   THStack *diMudRStack = new THStack();
   diMudRStack->SetName("diMudRStack");
   diMudRStack->SetTitle("MC stack");
   
   TH1F *diMudR_stack_6 = new TH1F("diMudR_stack_6","MC stack",10,0,5);
   diMudR_stack_6->GetXaxis()->SetTitle("");
   diMudR_stack_6->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR_stack_6->SetMinimum(0);
   diMudR_stack_6->SetMaximum(892.8338);
   diMudR_stack_6->SetDirectory(0);
   diMudR_stack_6->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   diMudR_stack_6->SetLineColor(ci);
   diMudR_stack_6->GetXaxis()->SetLabelFont(42);
   diMudR_stack_6->GetXaxis()->SetLabelSize(0.035);
   diMudR_stack_6->GetXaxis()->SetTitleSize(0.035);
   diMudR_stack_6->GetXaxis()->SetTitleFont(42);
   diMudR_stack_6->GetYaxis()->SetLabelFont(42);
   diMudR_stack_6->GetYaxis()->SetLabelSize(0.035);
   diMudR_stack_6->GetYaxis()->SetTitleSize(0.035);
   diMudR_stack_6->GetYaxis()->SetTitleFont(42);
   diMudR_stack_6->GetZaxis()->SetLabelFont(42);
   diMudR_stack_6->GetZaxis()->SetLabelSize(0.035);
   diMudR_stack_6->GetZaxis()->SetTitleSize(0.035);
   diMudR_stack_6->GetZaxis()->SetTitleFont(42);
   diMudRStack->SetHistogram(diMudR_stack_6);
   
   
   TH1F *diMudR__82 = new TH1F("diMudR__82","ZZ",10,0,5);
   diMudR__82->GetXaxis()->SetTitle("");
   diMudR__82->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__82->SetBinContent(1,1.014186);
   diMudR__82->SetBinContent(2,4.071723);
   diMudR__82->SetBinError(1,0.1297533);
   diMudR__82->SetBinError(2,0.2599852);
   diMudR__82->SetEntries(322);
   diMudR__82->SetDirectory(0);

   ci = TColor::GetColor("#ff66ff");
   diMudR__82->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__82->SetLineColor(ci);
   diMudR__82->GetXaxis()->SetLabelFont(42);
   diMudR__82->GetXaxis()->SetLabelSize(0.035);
   diMudR__82->GetXaxis()->SetTitleSize(0.035);
   diMudR__82->GetXaxis()->SetTitleFont(42);
   diMudR__82->GetYaxis()->SetLabelFont(42);
   diMudR__82->GetYaxis()->SetLabelSize(0.035);
   diMudR__82->GetYaxis()->SetTitleSize(0.035);
   diMudR__82->GetYaxis()->SetTitleFont(42);
   diMudR__82->GetZaxis()->SetLabelFont(42);
   diMudR__82->GetZaxis()->SetLabelSize(0.035);
   diMudR__82->GetZaxis()->SetTitleSize(0.035);
   diMudR__82->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__82,"");
   
   TH1F *diMudR__83 = new TH1F("diMudR__83","WZ",10,0,5);
   diMudR__83->GetXaxis()->SetTitle("");
   diMudR__83->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__83->SetBinContent(1,0.3855859);
   diMudR__83->SetBinContent(2,3.108701);
   diMudR__83->SetBinError(1,0.159756);
   diMudR__83->SetBinError(2,0.4536136);
   diMudR__83->SetEntries(53);
   diMudR__83->SetDirectory(0);

   ci = TColor::GetColor("#66ffff");
   diMudR__83->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__83->SetLineColor(ci);
   diMudR__83->GetXaxis()->SetLabelFont(42);
   diMudR__83->GetXaxis()->SetLabelSize(0.035);
   diMudR__83->GetXaxis()->SetTitleSize(0.035);
   diMudR__83->GetXaxis()->SetTitleFont(42);
   diMudR__83->GetYaxis()->SetLabelFont(42);
   diMudR__83->GetYaxis()->SetLabelSize(0.035);
   diMudR__83->GetYaxis()->SetTitleSize(0.035);
   diMudR__83->GetYaxis()->SetTitleFont(42);
   diMudR__83->GetZaxis()->SetLabelFont(42);
   diMudR__83->GetZaxis()->SetLabelSize(0.035);
   diMudR__83->GetZaxis()->SetTitleSize(0.035);
   diMudR__83->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__83,"");
   
   TH1F *diMudR__84 = new TH1F("diMudR__84","WW",10,0,5);
   diMudR__84->GetXaxis()->SetTitle("");
   diMudR__84->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__84->SetBinContent(1,0.176346);
   diMudR__84->SetBinContent(2,0.707839);
   diMudR__84->SetBinError(1,0.1394763);
   diMudR__84->SetBinError(2,0.2794377);
   diMudR__84->SetEntries(10);
   diMudR__84->SetDirectory(0);

   ci = TColor::GetColor("#996633");
   diMudR__84->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__84->SetLineColor(ci);
   diMudR__84->GetXaxis()->SetLabelFont(42);
   diMudR__84->GetXaxis()->SetLabelSize(0.035);
   diMudR__84->GetXaxis()->SetTitleSize(0.035);
   diMudR__84->GetXaxis()->SetTitleFont(42);
   diMudR__84->GetYaxis()->SetLabelFont(42);
   diMudR__84->GetYaxis()->SetLabelSize(0.035);
   diMudR__84->GetYaxis()->SetTitleSize(0.035);
   diMudR__84->GetYaxis()->SetTitleFont(42);
   diMudR__84->GetZaxis()->SetLabelFont(42);
   diMudR__84->GetZaxis()->SetLabelSize(0.035);
   diMudR__84->GetZaxis()->SetTitleSize(0.035);
   diMudR__84->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__84,"");
   
   TH1F *diMudR__85 = new TH1F("diMudR__85","t#bar{t} dilep",10,0,5);
   diMudR__85->GetXaxis()->SetTitle("");
   diMudR__85->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__85->SetBinContent(1,42.30946);
   diMudR__85->SetBinContent(2,190.5051);
   diMudR__85->SetBinError(1,1.370528);
   diMudR__85->SetBinError(2,2.908188);
   diMudR__85->SetEntries(5808);
   diMudR__85->SetDirectory(0);

   ci = TColor::GetColor("#ffff66");
   diMudR__85->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__85->SetLineColor(ci);
   diMudR__85->GetXaxis()->SetLabelFont(42);
   diMudR__85->GetXaxis()->SetLabelSize(0.035);
   diMudR__85->GetXaxis()->SetTitleSize(0.035);
   diMudR__85->GetXaxis()->SetTitleFont(42);
   diMudR__85->GetYaxis()->SetLabelFont(42);
   diMudR__85->GetYaxis()->SetLabelSize(0.035);
   diMudR__85->GetYaxis()->SetTitleSize(0.035);
   diMudR__85->GetYaxis()->SetTitleFont(42);
   diMudR__85->GetZaxis()->SetLabelFont(42);
   diMudR__85->GetZaxis()->SetLabelSize(0.035);
   diMudR__85->GetZaxis()->SetTitleSize(0.035);
   diMudR__85->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__85,"");
   
   TH1F *diMudR__86 = new TH1F("diMudR__86","t#bar{t} lept",10,0,5);
   diMudR__86->GetXaxis()->SetTitle("");
   diMudR__86->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__86->SetBinContent(2,0.7627841);
   diMudR__86->SetBinError(2,0.3863577);
   diMudR__86->SetEntries(4);
   diMudR__86->SetDirectory(0);

   ci = TColor::GetColor("#339966");
   diMudR__86->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__86->SetLineColor(ci);
   diMudR__86->GetXaxis()->SetLabelFont(42);
   diMudR__86->GetXaxis()->SetLabelSize(0.035);
   diMudR__86->GetXaxis()->SetTitleSize(0.035);
   diMudR__86->GetXaxis()->SetTitleFont(42);
   diMudR__86->GetYaxis()->SetLabelFont(42);
   diMudR__86->GetYaxis()->SetLabelSize(0.035);
   diMudR__86->GetYaxis()->SetTitleSize(0.035);
   diMudR__86->GetYaxis()->SetTitleFont(42);
   diMudR__86->GetZaxis()->SetLabelFont(42);
   diMudR__86->GetZaxis()->SetLabelSize(0.035);
   diMudR__86->GetZaxis()->SetTitleSize(0.035);
   diMudR__86->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__86,"");
   
   TH1F *diMudR__87 = new TH1F("diMudR__87","tW",10,0,5);
   diMudR__87->GetXaxis()->SetTitle("");
   diMudR__87->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__87->SetBinContent(1,7.11918);
   diMudR__87->SetBinContent(2,20.62788);
   diMudR__87->SetBinError(1,1.768659);
   diMudR__87->SetBinError(2,3.010623);
   diMudR__87->SetEntries(71);
   diMudR__87->SetDirectory(0);

   ci = TColor::GetColor("#336600");
   diMudR__87->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__87->SetLineColor(ci);
   diMudR__87->GetXaxis()->SetLabelFont(42);
   diMudR__87->GetXaxis()->SetLabelSize(0.035);
   diMudR__87->GetXaxis()->SetTitleSize(0.035);
   diMudR__87->GetXaxis()->SetTitleFont(42);
   diMudR__87->GetYaxis()->SetLabelFont(42);
   diMudR__87->GetYaxis()->SetLabelSize(0.035);
   diMudR__87->GetYaxis()->SetTitleSize(0.035);
   diMudR__87->GetYaxis()->SetTitleFont(42);
   diMudR__87->GetZaxis()->SetLabelFont(42);
   diMudR__87->GetZaxis()->SetLabelSize(0.035);
   diMudR__87->GetZaxis()->SetTitleSize(0.035);
   diMudR__87->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__87,"");
   
   TH1F *diMudR__88 = new TH1F("diMudR__88","#bar{t}W",10,0,5);
   diMudR__88->GetXaxis()->SetTitle("");
   diMudR__88->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__88->SetBinContent(1,7.72869);
   diMudR__88->SetBinContent(2,24.85226);
   diMudR__88->SetBinError(1,1.850638);
   diMudR__88->SetBinError(2,3.318574);
   diMudR__88->SetEntries(77);
   diMudR__88->SetDirectory(0);

   ci = TColor::GetColor("#336600");
   diMudR__88->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__88->SetLineColor(ci);
   diMudR__88->GetXaxis()->SetLabelFont(42);
   diMudR__88->GetXaxis()->SetLabelSize(0.035);
   diMudR__88->GetXaxis()->SetTitleSize(0.035);
   diMudR__88->GetXaxis()->SetTitleFont(42);
   diMudR__88->GetYaxis()->SetLabelFont(42);
   diMudR__88->GetYaxis()->SetLabelSize(0.035);
   diMudR__88->GetYaxis()->SetTitleSize(0.035);
   diMudR__88->GetYaxis()->SetTitleFont(42);
   diMudR__88->GetZaxis()->SetLabelFont(42);
   diMudR__88->GetZaxis()->SetLabelSize(0.035);
   diMudR__88->GetZaxis()->SetTitleSize(0.035);
   diMudR__88->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__88,"");
   
   TH1F *diMudR__89 = new TH1F("diMudR__89","Z+j",10,0,5);
   diMudR__89->GetXaxis()->SetTitle("");
   diMudR__89->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__89->SetBinContent(1,13.12347);
   diMudR__89->SetBinContent(2,234.1387);
   diMudR__89->SetBinError(1,5.453309);
   diMudR__89->SetBinError(2,23.03416);
   diMudR__89->SetEntries(110);
   diMudR__89->SetDirectory(0);

   ci = TColor::GetColor("#ff6666");
   diMudR__89->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   diMudR__89->SetLineColor(ci);
   diMudR__89->GetXaxis()->SetLabelFont(42);
   diMudR__89->GetXaxis()->SetLabelSize(0.035);
   diMudR__89->GetXaxis()->SetTitleSize(0.035);
   diMudR__89->GetXaxis()->SetTitleFont(42);
   diMudR__89->GetYaxis()->SetLabelFont(42);
   diMudR__89->GetYaxis()->SetLabelSize(0.035);
   diMudR__89->GetYaxis()->SetTitleSize(0.035);
   diMudR__89->GetYaxis()->SetTitleFont(42);
   diMudR__89->GetZaxis()->SetLabelFont(42);
   diMudR__89->GetZaxis()->SetLabelSize(0.035);
   diMudR__89->GetZaxis()->SetTitleSize(0.035);
   diMudR__89->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__89,"");
   
   TH1F *diMudR__90 = new TH1F("diMudR__90","Z+j",10,0,5);
   diMudR__90->GetXaxis()->SetTitle("");
   diMudR__90->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__90->SetBinContent(1,261.0075);
   diMudR__90->SetBinContent(2,370.8666);
   diMudR__90->SetBinError(1,42.40199);
   diMudR__90->SetBinError(2,50.54388);
   diMudR__90->SetEntries(97);
   diMudR__90->SetDirectory(0);

   ci = TColor::GetColor("#ff6666");
   diMudR__90->SetFillColor(kRed-9);
   ci = TColor::GetColor("#000099");
   diMudR__90->SetLineColor(ci);
   diMudR__90->GetXaxis()->SetLabelFont(42);
   diMudR__90->GetXaxis()->SetLabelSize(0.035);
   diMudR__90->GetXaxis()->SetTitleSize(0.035);
   diMudR__90->GetXaxis()->SetTitleFont(42);
   diMudR__90->GetYaxis()->SetLabelFont(42);
   diMudR__90->GetYaxis()->SetLabelSize(0.035);
   diMudR__90->GetYaxis()->SetTitleSize(0.035);
   diMudR__90->GetYaxis()->SetTitleFont(42);
   diMudR__90->GetZaxis()->SetLabelFont(42);
   diMudR__90->GetZaxis()->SetLabelSize(0.035);
   diMudR__90->GetZaxis()->SetTitleSize(0.035);
   diMudR__90->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__90,"");
   
   TH1F *diMudR__91 = new TH1F("diMudR__91","ZH_125",10,0,5);
   diMudR__91->GetXaxis()->SetTitle("");
   diMudR__91->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__91->SetBinContent(1,0.04860648);
   diMudR__91->SetBinContent(2,0.6762021);
   diMudR__91->SetBinError(1,0.004884237);
   diMudR__91->SetBinError(2,0.01821746);
   diMudR__91->SetEntries(1581);
   diMudR__91->SetDirectory(0);

   ci = TColor::GetColor("#000099");
   diMudR__91->SetLineColor(ci);
   diMudR__91->GetXaxis()->SetLabelFont(42);
   diMudR__91->GetXaxis()->SetLabelSize(0.035);
   diMudR__91->GetXaxis()->SetTitleSize(0.035);
   diMudR__91->GetXaxis()->SetTitleFont(42);
   diMudR__91->GetYaxis()->SetLabelFont(42);
   diMudR__91->GetYaxis()->SetLabelSize(0.035);
   diMudR__91->GetYaxis()->SetTitleSize(0.035);
   diMudR__91->GetYaxis()->SetTitleFont(42);
   diMudR__91->GetZaxis()->SetLabelFont(42);
   diMudR__91->GetZaxis()->SetLabelSize(0.035);
   diMudR__91->GetZaxis()->SetTitleSize(0.035);
   diMudR__91->GetZaxis()->SetTitleFont(42);
   diMudRStack->Add(diMudR__91,"");
   diMudRStack->Draw("hist, same");
   
   diMudRStack = new THStack();
   diMudRStack->SetName("diMudRStack");
   diMudRStack->SetTitle("MC stack - not stacked");
   diMudRStack->Draw("nostack, hist, same");
   
   TH1F *diMudR__92 = new TH1F("diMudR__92","m_{a} = 40 GeV",10,0,5);
   diMudR__92->GetXaxis()->SetTitle("");
   diMudR__92->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__92->SetBinContent(1,0.07514053);
   diMudR__92->SetBinContent(2,0.9647496);
   diMudR__92->SetBinError(1,0.03819511);
   diMudR__92->SetBinError(2,0.1368605);
   diMudR__92->SetEntries(57);
   diMudR__92->SetDirectory(0);
   diMudR__92->SetLineStyle(0);
   diMudR__92->SetMarkerStyle(20);
   diMudR__92->GetXaxis()->SetLabelFont(42);
   diMudR__92->GetXaxis()->SetLabelOffset(0.007);
   diMudR__92->GetXaxis()->SetLabelSize(0.05);
   diMudR__92->GetXaxis()->SetTitleSize(0.06);
   diMudR__92->GetXaxis()->SetTitleOffset(0.9);
   diMudR__92->GetXaxis()->SetTitleFont(42);
   diMudR__92->GetYaxis()->SetLabelFont(42);
   diMudR__92->GetYaxis()->SetLabelOffset(0.007);
   diMudR__92->GetYaxis()->SetLabelSize(0.05);
   diMudR__92->GetYaxis()->SetTitleSize(0.06);
   diMudR__92->GetYaxis()->SetTitleOffset(1.5);
   diMudR__92->GetYaxis()->SetTitleFont(42);
   diMudR__92->GetZaxis()->SetLabelFont(42);
   diMudR__92->GetZaxis()->SetLabelOffset(0.007);
   diMudR__92->GetZaxis()->SetLabelSize(0.05);
   diMudR__92->GetZaxis()->SetTitleSize(0.06);
   diMudR__92->GetZaxis()->SetTitleFont(42);
   diMudR__92->Draw("hist, same");
   
   TH1F *diMudR__93 = new TH1F("diMudR__93","m_{a} = 50 GeV",10,0,5);
   diMudR__93->GetXaxis()->SetTitle("");
   diMudR__93->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__93->SetBinContent(2,0.2754818);
   diMudR__93->SetBinError(2,0.07344189);
   diMudR__93->SetEntries(12);
   diMudR__93->SetDirectory(0);
   diMudR__93->SetLineStyle(0);
   diMudR__93->SetMarkerStyle(20);
   diMudR__93->GetXaxis()->SetLabelFont(42);
   diMudR__93->GetXaxis()->SetLabelOffset(0.007);
   diMudR__93->GetXaxis()->SetLabelSize(0.05);
   diMudR__93->GetXaxis()->SetTitleSize(0.06);
   diMudR__93->GetXaxis()->SetTitleOffset(0.9);
   diMudR__93->GetXaxis()->SetTitleFont(42);
   diMudR__93->GetYaxis()->SetLabelFont(42);
   diMudR__93->GetYaxis()->SetLabelOffset(0.007);
   diMudR__93->GetYaxis()->SetLabelSize(0.05);
   diMudR__93->GetYaxis()->SetTitleSize(0.06);
   diMudR__93->GetYaxis()->SetTitleOffset(1.5);
   diMudR__93->GetYaxis()->SetTitleFont(42);
   diMudR__93->GetZaxis()->SetLabelFont(42);
   diMudR__93->GetZaxis()->SetLabelOffset(0.007);
   diMudR__93->GetZaxis()->SetLabelSize(0.05);
   diMudR__93->GetZaxis()->SetTitleSize(0.06);
   diMudR__93->GetZaxis()->SetTitleFont(42);
   diMudR__93->Draw("hist, same");
   
   TH1F *diMudR__94 = new TH1F("diMudR__94","m_{a} = 60 GeV",10,0,5);
   diMudR__94->GetXaxis()->SetTitle("");
   diMudR__94->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__94->SetBinContent(2,0.0180338);
   diMudR__94->SetBinError(2,0.0186791);
   diMudR__94->SetEntries(1);
   diMudR__94->SetDirectory(0);
   diMudR__94->SetLineStyle(0);
   diMudR__94->SetMarkerStyle(20);
   diMudR__94->GetXaxis()->SetLabelFont(42);
   diMudR__94->GetXaxis()->SetLabelOffset(0.007);
   diMudR__94->GetXaxis()->SetLabelSize(0.05);
   diMudR__94->GetXaxis()->SetTitleSize(0.06);
   diMudR__94->GetXaxis()->SetTitleOffset(0.9);
   diMudR__94->GetXaxis()->SetTitleFont(42);
   diMudR__94->GetYaxis()->SetLabelFont(42);
   diMudR__94->GetYaxis()->SetLabelOffset(0.007);
   diMudR__94->GetYaxis()->SetLabelSize(0.05);
   diMudR__94->GetYaxis()->SetTitleSize(0.06);
   diMudR__94->GetYaxis()->SetTitleOffset(1.5);
   diMudR__94->GetYaxis()->SetTitleFont(42);
   diMudR__94->GetZaxis()->SetLabelFont(42);
   diMudR__94->GetZaxis()->SetLabelOffset(0.007);
   diMudR__94->GetZaxis()->SetLabelSize(0.05);
   diMudR__94->GetZaxis()->SetTitleSize(0.06);
   diMudR__94->GetZaxis()->SetTitleFont(42);
   diMudR__94->Draw("hist, same");
   
   TH1F *diMudR__95 = new TH1F("diMudR__95","data",10,0,5);
   diMudR__95->GetXaxis()->SetTitle("");
   diMudR__95->GetYaxis()->SetTitle("Events @ 19.7 fb^{-1}");
   diMudR__95->SetBinContent(1,437);
   diMudR__95->SetBinContent(2,911);
   diMudR__95->SetEntries(1348);
   diMudR__95->SetDirectory(0);
   
   ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   text = ptstats->AddText("diMudR");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1348   ");
   text = ptstats->AddText("Mean  = 0.6444");
   text = ptstats->AddText("RMS   = 0.2282");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   diMudR__95->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(diMudR__95);
   diMudR__95->SetLineStyle(0);
   diMudR__95->SetMarkerStyle(20);
   diMudR__95->GetXaxis()->SetTitle("#Delta R (#mu,#mu)");
   diMudR__95->GetXaxis()->SetLabelFont(42);
   diMudR__95->GetXaxis()->SetLabelOffset(0.007);
   diMudR__95->GetXaxis()->SetLabelSize(0.05);
   diMudR__95->GetXaxis()->SetTitleSize(0.06);
   diMudR__95->GetXaxis()->SetTitleOffset(0.9);
   diMudR__95->GetXaxis()->SetTitleFont(42);
   diMudR__95->GetYaxis()->SetTitle("Events/0.5");
   diMudR__95->GetYaxis()->SetLabelFont(42);
   diMudR__95->GetYaxis()->SetLabelOffset(0.007);
   diMudR__95->GetYaxis()->SetLabelSize(0.05);
   diMudR__95->GetYaxis()->SetTitleSize(0.06);
   diMudR__95->GetYaxis()->SetTitleOffset(1.5);
   diMudR__95->GetYaxis()->SetTitleFont(42);
   diMudR__95->GetZaxis()->SetLabelFont(42);
   diMudR__95->GetZaxis()->SetLabelOffset(0.007);
   diMudR__95->GetZaxis()->SetLabelSize(0.05);
   diMudR__95->GetZaxis()->SetTitleSize(0.06);
   diMudR__95->GetZaxis()->SetTitleFont(42);
   diMudR__95->Draw("e, same");
   

   TLegend *leg = new TLegend(0.5,0.67,0.88,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("diMudR__81","Data","LEP");
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("diMudR__91","ZH_125","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("diMudR__90","Z+j (10-50 GeV)","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("diMudR__89","Z+j (> 50 GeV)","f");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("diMudR__88","tW","f");
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
   entry=leg->AddEntry("diMudR__86","t#bar{t} lept","f");
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
   entry=leg->AddEntry("diMudR__85","t#bar{t} dilep","f");
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
   entry=leg->AddEntry("diMudR__84","WW","f");
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
   entry=leg->AddEntry("diMudR__83","WZ","f");
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
   entry=leg->AddEntry("diMudR__82","ZZ","f");
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

diMudR->cd();

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
   diMudR->cd();
  
// ------------>Primitives in pad: pad2
   pad2 = new TPad("pad2", "pad1",0,0,1,0.15);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-0.9756097,-1.634146,5.121951,3.243902);
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
   
   TH1F *ratio__96 = new TH1F("ratio__96","ZH_125",10,0,5);
   ratio__96->SetBinContent(1,1./0.7618148);
   ratio__96->SetBinContent(2,1./0.9333895);
   ratio__96->SetBinError(1,0.1046089);
   ratio__96->SetBinError(2,0.06862102);
   ratio__96->SetMinimum(-1);
   ratio__96->SetMaximum(3);
   ratio__96->SetEntries(183.6022);
   ratio__96->SetDirectory(0);
   ratio__96->SetStats(0);

   ci = TColor::GetColor("#000099");
   ratio__96->SetLineColor(ci);
   ratio__96->SetMarkerStyle(20);
   ratio__96->GetXaxis()->SetLabelFont(42);
   ratio__96->GetXaxis()->SetLabelSize(0.035);
   ratio__96->GetXaxis()->SetTitleSize(0.035);
   ratio__96->GetXaxis()->SetTitleFont(42);
   ratio__96->GetYaxis()->SetTitle("Data/MC");
   ratio__96->GetYaxis()->SetLabelFont(42);
   ratio__96->GetYaxis()->SetLabelSize(0.17);
   ratio__96->GetYaxis()->SetTitleSize(0.24);
   ratio__96->GetYaxis()->SetTitleOffset(0.35);
   ratio__96->GetYaxis()->SetTitleFont(42);
   ratio__96->GetZaxis()->SetLabelFont(42);
   ratio__96->GetZaxis()->SetLabelSize(0.035);
   ratio__96->GetZaxis()->SetTitleSize(0.035);
   ratio__96->GetZaxis()->SetTitleFont(42);
   ratio__96->Draw("ep");
   
   pt = new TPaveText(0.473871,0.9106118,0.526129,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("ZH_125");
   pt->Draw();
   pad2->Modified();
   diMudR->cd();
      tex = new TLatex(0.925,0.87,"");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   diMudR->Modified();
   diMudR->cd();
   diMudR->SetSelected(diMudR);

}
