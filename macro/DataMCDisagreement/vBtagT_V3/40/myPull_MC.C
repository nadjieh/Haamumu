{
//========= Macro generated from object: pullNsm2/N_{est}-N_{exp}/#delta N
//========= by ROOT version5.34/19
   
   TH1D *pullNsm2 = new TH1D("pullNsm2","N_{est}-N_{exp}/#delta N",20000,-100,100);
   pullNsm2->SetBinContent(0,48);
   pullNsm2->SetBinContent(20001,52);
   pullNsm2->SetEntries(100);

   ci = TColor::GetColor("#000099");
   pullNsm2->SetLineColor(ci);
   pullNsm2->GetXaxis()->SetLabelFont(42);
   pullNsm2->GetXaxis()->SetLabelSize(0.035);
   pullNsm2->GetXaxis()->SetTitleSize(0.035);
   pullNsm2->GetXaxis()->SetTitleFont(42);
   pullNsm2->GetYaxis()->SetLabelFont(42);
   pullNsm2->GetYaxis()->SetLabelSize(0.035);
   pullNsm2->GetYaxis()->SetTitleSize(0.035);
   pullNsm2->GetYaxis()->SetTitleFont(42);
   pullNsm2->GetZaxis()->SetLabelFont(42);
   pullNsm2->GetZaxis()->SetLabelSize(0.035);
   pullNsm2->GetZaxis()->SetTitleSize(0.035);
   pullNsm2->GetZaxis()->SetTitleFont(42);
   pullNsm2->Draw("");
}
