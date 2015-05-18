{
//========= Macro generated from object: residualNsm3/N_{est}-N_{truth}
//========= by ROOT version5.34/19
   
   TH1D *residualNsm3 = new TH1D("residualNsm3","N_{est}-N_{truth}",20000,-1000,1000);
   residualNsm3->SetBinContent(0,100);
   residualNsm3->SetEntries(100);

   ci = TColor::GetColor("#000099");
   residualNsm3->SetLineColor(ci);
   residualNsm3->GetXaxis()->SetLabelFont(42);
   residualNsm3->GetXaxis()->SetLabelSize(0.035);
   residualNsm3->GetXaxis()->SetTitleSize(0.035);
   residualNsm3->GetXaxis()->SetTitleFont(42);
   residualNsm3->GetYaxis()->SetLabelFont(42);
   residualNsm3->GetYaxis()->SetLabelSize(0.035);
   residualNsm3->GetYaxis()->SetTitleSize(0.035);
   residualNsm3->GetYaxis()->SetTitleFont(42);
   residualNsm3->GetZaxis()->SetLabelFont(42);
   residualNsm3->GetZaxis()->SetLabelSize(0.035);
   residualNsm3->GetZaxis()->SetTitleSize(0.035);
   residualNsm3->GetZaxis()->SetTitleFont(42);
   residualNsm3->Draw("");
}
