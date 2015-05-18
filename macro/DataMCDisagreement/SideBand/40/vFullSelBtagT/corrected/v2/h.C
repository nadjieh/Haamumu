{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Jan 11 18:21:14 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,10,700,500);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   
   TH1D *h = new TH1D("h","h",2000,-100,100);
   h->SetBinContent(0,5);
   h->SetBinContent(502,1);
   h->SetBinContent(782,1);
   h->SetBinContent(945,1);
   h->SetBinContent(952,1);
   h->SetBinContent(980,1);
   h->SetBinContent(984,1);
   h->SetBinContent(988,1);
   h->SetBinContent(990,1);
   h->SetBinContent(991,1);
   h->SetBinContent(993,1);
   h->SetBinContent(994,1);
   h->SetBinContent(996,2);
   h->SetBinContent(998,9);
   h->SetBinContent(999,10);
   h->SetBinContent(1000,23);
   h->SetBinContent(1001,21);
   h->SetBinContent(1002,8);
   h->SetBinContent(1003,2);
   h->SetBinContent(1004,3);
   h->SetBinContent(1005,1);
   h->SetBinContent(1008,2);
   h->SetBinContent(1017,1);
   h->SetBinContent(1021,2);
   h->SetEntries(100);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h->SetLineColor(ci);
   h->GetXaxis()->SetLabelFont(42);
   h->GetXaxis()->SetLabelSize(0.035);
   h->GetXaxis()->SetTitleSize(0.035);
   h->GetXaxis()->SetTitleFont(42);
   h->GetYaxis()->SetLabelFont(42);
   h->GetYaxis()->SetLabelSize(0.035);
   h->GetYaxis()->SetTitleSize(0.035);
   h->GetYaxis()->SetTitleFont(42);
   h->GetZaxis()->SetLabelFont(42);
   h->GetZaxis()->SetLabelSize(0.035);
   h->GetZaxis()->SetTitleSize(0.035);
   h->GetZaxis()->SetTitleFont(42);
   h->Draw("");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
