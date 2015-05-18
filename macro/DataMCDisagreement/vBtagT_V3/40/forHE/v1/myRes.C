{
//========= Macro generated from object: residualNsm/N_{est}-N_{exp}
//========= by ROOT version5.34/19
   
   TH1D *residualNsm = new TH1D("residualNsm","N_{est}-N_{exp}",2000,-10,10);
   residualNsm->SetBinContent(992,4);
   residualNsm->SetBinContent(993,1);
   residualNsm->SetBinContent(994,3);
   residualNsm->SetBinContent(995,1);
   residualNsm->SetBinContent(996,7);
   residualNsm->SetBinContent(997,11);
   residualNsm->SetBinContent(998,4);
   residualNsm->SetBinContent(999,8);
   residualNsm->SetBinContent(1000,24);
   residualNsm->SetBinContent(1001,22);
   residualNsm->SetBinContent(1002,6);
   residualNsm->SetBinContent(1004,2);
   residualNsm->SetBinContent(1005,1);
   residualNsm->SetBinContent(1006,4);
   residualNsm->SetBinContent(1008,1);
   residualNsm->SetBinContent(1010,1);
   residualNsm->SetEntries(100);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   residualNsm->SetLineColor(ci);
   residualNsm->GetXaxis()->SetLabelFont(42);
   residualNsm->GetXaxis()->SetLabelSize(0.035);
   residualNsm->GetXaxis()->SetTitleSize(0.035);
   residualNsm->GetXaxis()->SetTitleFont(42);
   residualNsm->GetYaxis()->SetLabelFont(42);
   residualNsm->GetYaxis()->SetLabelSize(0.035);
   residualNsm->GetYaxis()->SetTitleSize(0.035);
   residualNsm->GetYaxis()->SetTitleFont(42);
   residualNsm->GetZaxis()->SetLabelFont(42);
   residualNsm->GetZaxis()->SetLabelSize(0.035);
   residualNsm->GetZaxis()->SetTitleSize(0.035);
   residualNsm->GetZaxis()->SetTitleFont(42);
   residualNsm->Draw("");
}
