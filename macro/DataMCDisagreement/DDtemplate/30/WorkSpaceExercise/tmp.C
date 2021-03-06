{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Jan 29 22:36:54 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",13,34,700,500);
   Canvas_1->Range(-9.125001,-0.02084688,72.125,0.1876219);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *amassMu__1 = new TH1D("amassMu__1","amassMu",1000,0,1000);
   amassMu__1->SetBinContent(26,0.1314286);
   amassMu__1->SetBinContent(27,0.09142857);
   amassMu__1->SetBinContent(28,0.09714286);
   amassMu__1->SetBinContent(29,0.09142857);
   amassMu__1->SetBinContent(30,0.12);
   amassMu__1->SetBinContent(31,0.09142857);
   amassMu__1->SetBinContent(32,0.1028571);
   amassMu__1->SetBinContent(33,0.08571429);
   amassMu__1->SetBinContent(34,0.09142857);
   amassMu__1->SetBinContent(35,0.09714286);
   amassMu__1->SetBinError(26,0.02740475);
   amassMu__1->SetBinError(27,0.02285714);
   amassMu__1->SetBinError(28,0.0235606);
   amassMu__1->SetBinError(29,0.02285714);
   amassMu__1->SetBinError(30,0.02618615);
   amassMu__1->SetBinError(31,0.02285714);
   amassMu__1->SetBinError(32,0.02424366);
   amassMu__1->SetBinError(33,0.02213133);
   amassMu__1->SetBinError(34,0.02285714);
   amassMu__1->SetBinError(35,0.0235606);
   amassMu__1->SetEntries(175);
   amassMu__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 175    ");
   text = ptstats->AddText("Mean  =  29.82");
   text = ptstats->AddText("RMS   =   2.91");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   amassMu__1->SetLineColor(ci);
   amassMu__1->GetXaxis()->SetRange(0,64);
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
   amassMu__1->Draw("E");
   
   TPaveText *pt = new TPaveText(0.4124138,0.94,0.5875862,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu");
   pt->Draw();
   
   TH1D *amassMu__2 = new TH1D("amassMu__2","amassMu",1000,0,1000);
   amassMu__2->SetBinContent(26,0.09139785);
   amassMu__2->SetBinContent(27,0.06989247);
   amassMu__2->SetBinContent(28,0.1612903);
   amassMu__2->SetBinContent(29,0.06451613);
   amassMu__2->SetBinContent(30,0.09677419);
   amassMu__2->SetBinContent(31,0.07526882);
   amassMu__2->SetBinContent(32,0.1182796);
   amassMu__2->SetBinContent(33,0.1021505);
   amassMu__2->SetBinContent(34,0.1182796);
   amassMu__2->SetBinContent(35,0.1021505);
   amassMu__2->SetBinError(26,0.02216723);
   amassMu__2->SetBinError(27,0.01938468);
   amassMu__2->SetBinError(28,0.02944745);
   amassMu__2->SetBinError(29,0.0186242);
   amassMu__2->SetBinError(30,0.0228099);
   amassMu__2->SetBinError(31,0.02011644);
   amassMu__2->SetBinError(32,0.02521729);
   amassMu__2->SetBinError(33,0.02343494);
   amassMu__2->SetBinError(34,0.02521729);
   amassMu__2->SetBinError(35,0.02343494);
   amassMu__2->SetEntries(186);
   amassMu__2->SetDirectory(0);
   
   ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   text = ptstats->AddText("amassMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 186    ");
   text = ptstats->AddText("Mean  =  40.14");
   text = ptstats->AddText("RMS   =  2.882");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu__2);

   ci = TColor::GetColor("#000099");
   amassMu__2->SetLineColor(ci);
   amassMu__2->GetXaxis()->SetRange(0,64);
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
   amassMu__2->Draw("ESAMES");
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
