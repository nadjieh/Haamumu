{
//========= Macro generated from object: residualNsm2/N_{est}-N_{exp}
//========= by ROOT version5.34/19
   
   TH1D *residualNsm2 = new TH1D("residualNsm2","N_{est}-N_{exp}",2000,-10,10);
   residualNsm2->SetBinContent(989,4);
   residualNsm2->SetBinContent(991,2);
   residualNsm2->SetBinContent(992,2);
   residualNsm2->SetBinContent(993,1);
   residualNsm2->SetBinContent(994,1);
   residualNsm2->SetBinContent(995,3);
   residualNsm2->SetBinContent(996,4);
   residualNsm2->SetBinContent(997,3);
   residualNsm2->SetBinContent(998,9);
   residualNsm2->SetBinContent(999,13);
   residualNsm2->SetBinContent(1000,27);
   residualNsm2->SetBinContent(1001,18);
   residualNsm2->SetBinContent(1002,6);
   residualNsm2->SetBinContent(1003,1);
   residualNsm2->SetBinContent(1004,1);
   residualNsm2->SetBinContent(1005,2);
   residualNsm2->SetBinContent(1006,1);
   residualNsm2->SetBinContent(1007,1);
   residualNsm2->SetBinContent(1014,1);
   residualNsm2->SetEntries(100);

   ci = TColor::GetColor("#000099");
   residualNsm2->SetLineColor(ci);
   residualNsm2->GetXaxis()->SetLabelFont(42);
   residualNsm2->GetXaxis()->SetLabelSize(0.035);
   residualNsm2->GetXaxis()->SetTitleSize(0.035);
   residualNsm2->GetXaxis()->SetTitleFont(42);
   residualNsm2->GetYaxis()->SetLabelFont(42);
   residualNsm2->GetYaxis()->SetLabelSize(0.035);
   residualNsm2->GetYaxis()->SetTitleSize(0.035);
   residualNsm2->GetYaxis()->SetTitleFont(42);
   residualNsm2->GetZaxis()->SetLabelFont(42);
   residualNsm2->GetZaxis()->SetLabelSize(0.035);
   residualNsm2->GetZaxis()->SetTitleSize(0.035);
   residualNsm2->GetZaxis()->SetTitleFont(42);
   residualNsm2->Draw("");
}
