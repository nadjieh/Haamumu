{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Jan 20 13:33:45 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",474,185,700,500);
   Canvas_1->Range(2.499999,-0.3497766,77.5,2.216336);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *amassMu = new TH1D("amassMu","amassMu",500,0,1000);
   amassMu->SetBinContent(7,0.0005395101);
   amassMu->SetBinContent(9,0.0008243916);
   amassMu->SetBinContent(10,0.0006017838);
   amassMu->SetBinContent(11,0.003511386);
   amassMu->SetBinContent(12,0.006935557);
   amassMu->SetBinContent(13,0.01550856);
   amassMu->SetBinContent(14,0.05707354);
   amassMu->SetBinContent(15,1.826924);
   amassMu->SetBinContent(16,1.43005);
   amassMu->SetBinContent(17,0.003670326);
   amassMu->SetBinContent(23,0.0005371263);
   amassMu->SetBinContent(24,0.000640421);
   amassMu->SetBinContent(25,0.0006544046);
   amassMu->SetBinContent(27,0.001292892);
   amassMu->SetBinContent(29,0.0006226917);
   amassMu->SetBinContent(30,0.0006136054);
   amassMu->SetBinError(7,0.0006022152);
   amassMu->SetBinError(9,0.0007444212);
   amassMu->SetBinError(10,0.0006360221);
   amassMu->SetBinError(11,0.001536354);
   amassMu->SetBinError(12,0.002159199);
   amassMu->SetBinError(13,0.003228774);
   amassMu->SetBinError(14,0.006193974);
   amassMu->SetBinError(15,0.03504388);
   amassMu->SetBinError(16,0.0310047);
   amassMu->SetBinError(17,0.00157074);
   amassMu->SetBinError(23,0.0006008834);
   amassMu->SetBinError(24,0.0006561222);
   amassMu->SetBinError(25,0.0006632467);
   amassMu->SetBinError(27,0.0009322514);
   amassMu->SetBinError(29,0.0006469765);
   amassMu->SetBinError(30,0.0006422388);
   amassMu->SetEntries(5776);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("amassMu");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 5776   ");
   text = ptstats->AddText("Mean  =  29.81");
   text = ptstats->AddText("RMS   =  1.472");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   amassMu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(amassMu);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   amassMu->SetLineColor(ci);
   amassMu->GetXaxis()->SetRange(6,35);
   amassMu->GetXaxis()->SetLabelFont(42);
   amassMu->GetXaxis()->SetLabelSize(0.035);
   amassMu->GetXaxis()->SetTitleSize(0.035);
   amassMu->GetXaxis()->SetTitleFont(42);
   amassMu->GetYaxis()->SetLabelFont(42);
   amassMu->GetYaxis()->SetLabelSize(0.035);
   amassMu->GetYaxis()->SetTitleSize(0.035);
   amassMu->GetYaxis()->SetTitleFont(42);
   amassMu->GetZaxis()->SetLabelFont(42);
   amassMu->GetZaxis()->SetLabelSize(0.035);
   amassMu->GetZaxis()->SetTitleSize(0.035);
   amassMu->GetZaxis()->SetTitleFont(42);
   amassMu->Draw("");
   
   TPaveText *pt = new TPaveText(0.4124138,0.94,0.5875862,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("amassMu");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
   
   TH1D * sig = new TH1D("signal","signal",30,10.,70.);
   for(int i = 6; i < 36; i++){
   	sig->SetBinContent(i - 5, amassMu->GetBinContent(i));
   	sig->SetBinError(i - 5, amassMu->GetBinError(i));   	
   }
   TFile * fSig = new TFile("sig30.root","recreate");
   fSig->cd();
   sig->Write();
   fSig->Close();
}
