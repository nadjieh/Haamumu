{
//========= Macro generated from object: residualNsm/N_{est}-N_{exp}
//========= by ROOT version5.34/19
   
   TH1D *residualNsm = new TH1D("residualNsm","N_{est}-N_{exp}",2000,-10,10);
   residualNsm->SetBinContent(969,2);
   residualNsm->SetBinContent(970,2);
   residualNsm->SetBinContent(971,10);
   residualNsm->SetBinContent(972,5);
   residualNsm->SetBinContent(973,6);
   residualNsm->SetBinContent(974,8);
   residualNsm->SetBinContent(975,12);
   residualNsm->SetBinContent(976,3);
   residualNsm->SetBinContent(977,11);
   residualNsm->SetBinContent(978,13);
   residualNsm->SetBinContent(979,8);
   residualNsm->SetBinContent(980,6);
   residualNsm->SetBinContent(981,12);
   residualNsm->SetBinContent(982,19);
   residualNsm->SetBinContent(983,12);
   residualNsm->SetBinContent(984,14);
   residualNsm->SetBinContent(985,13);
   residualNsm->SetBinContent(986,7);
   residualNsm->SetBinContent(987,10);
   residualNsm->SetBinContent(988,14);
   residualNsm->SetBinContent(989,10);
   residualNsm->SetBinContent(990,17);
   residualNsm->SetBinContent(991,23);
   residualNsm->SetBinContent(992,17);
   residualNsm->SetBinContent(993,19);
   residualNsm->SetBinContent(994,24);
   residualNsm->SetBinContent(995,26);
   residualNsm->SetBinContent(996,36);
   residualNsm->SetBinContent(997,48);
   residualNsm->SetBinContent(998,53);
   residualNsm->SetBinContent(999,79);
   residualNsm->SetBinContent(1000,187);
   residualNsm->SetBinContent(1001,134);
   residualNsm->SetBinContent(1002,53);
   residualNsm->SetBinContent(1003,27);
   residualNsm->SetBinContent(1004,21);
   residualNsm->SetBinContent(1005,7);
   residualNsm->SetBinContent(1006,5);
   residualNsm->SetBinContent(1007,7);
   residualNsm->SetBinContent(1008,7);
   residualNsm->SetBinContent(1009,2);
   residualNsm->SetBinContent(1010,1);
   residualNsm->SetBinContent(1011,3);
   residualNsm->SetBinContent(1012,1);
   residualNsm->SetBinContent(1013,2);
   residualNsm->SetBinContent(1014,1);
   residualNsm->SetBinContent(1020,1);
   residualNsm->SetBinContent(1027,1);
   residualNsm->SetBinContent(1029,1);
   residualNsm->SetEntries(1000);

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
