{
//========= Macro generated from object: residualNsmb2/N_{est}-N_{exp}
//========= by ROOT version5.34/19
   
   TH1D *residualNsmb2 = new TH1D("residualNsmb2","N_{est}-N_{exp}",2000,-10,10);
   residualNsmb2->SetBinContent(948,1);
   residualNsmb2->SetBinContent(988,1);
   residualNsmb2->SetBinContent(991,2);
   residualNsmb2->SetBinContent(993,1);
   residualNsmb2->SetBinContent(994,1);
   residualNsmb2->SetBinContent(996,4);
   residualNsmb2->SetBinContent(997,5);
   residualNsmb2->SetBinContent(998,1);
   residualNsmb2->SetBinContent(999,5);
   residualNsmb2->SetBinContent(1000,5);
   residualNsmb2->SetBinContent(1001,4);
   residualNsmb2->SetBinContent(1002,17);
   residualNsmb2->SetBinContent(1003,14);
   residualNsmb2->SetBinContent(1004,15);
   residualNsmb2->SetBinContent(1005,6);
   residualNsmb2->SetBinContent(1006,6);
   residualNsmb2->SetBinContent(1007,1);
   residualNsmb2->SetBinContent(1008,3);
   residualNsmb2->SetBinContent(1009,4);
   residualNsmb2->SetBinContent(1012,2);
   residualNsmb2->SetBinContent(1013,1);
   residualNsmb2->SetBinContent(1015,1);
   residualNsmb2->SetEntries(100);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   residualNsmb2->SetLineColor(ci);
   residualNsmb2->GetXaxis()->SetLabelFont(42);
   residualNsmb2->GetXaxis()->SetLabelSize(0.035);
   residualNsmb2->GetXaxis()->SetTitleSize(0.035);
   residualNsmb2->GetXaxis()->SetTitleFont(42);
   residualNsmb2->GetYaxis()->SetLabelFont(42);
   residualNsmb2->GetYaxis()->SetLabelSize(0.035);
   residualNsmb2->GetYaxis()->SetTitleSize(0.035);
   residualNsmb2->GetYaxis()->SetTitleFont(42);
   residualNsmb2->GetZaxis()->SetLabelFont(42);
   residualNsmb2->GetZaxis()->SetLabelSize(0.035);
   residualNsmb2->GetZaxis()->SetTitleSize(0.035);
   residualNsmb2->GetZaxis()->SetTitleFont(42);
   residualNsmb2->Draw("");
}
