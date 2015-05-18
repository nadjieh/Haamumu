{
//========= Macro generated from object: pullNsm3/N_{est}-N_{truth}/#delta N
//========= by ROOT version5.34/19
   
   TH1D *pullNsm3 = new TH1D("pullNsm3","N_{est}-N_{truth}/#delta N",20000,-100,100);
   pullNsm3->SetBinContent(0,100);
   pullNsm3->SetEntries(100);

   ci = TColor::GetColor("#000099");
   pullNsm3->SetLineColor(ci);
   pullNsm3->GetXaxis()->SetLabelFont(42);
   pullNsm3->GetXaxis()->SetLabelSize(0.035);
   pullNsm3->GetXaxis()->SetTitleSize(0.035);
   pullNsm3->GetXaxis()->SetTitleFont(42);
   pullNsm3->GetYaxis()->SetLabelFont(42);
   pullNsm3->GetYaxis()->SetLabelSize(0.035);
   pullNsm3->GetYaxis()->SetTitleSize(0.035);
   pullNsm3->GetYaxis()->SetTitleFont(42);
   pullNsm3->GetZaxis()->SetLabelFont(42);
   pullNsm3->GetZaxis()->SetLabelSize(0.035);
   pullNsm3->GetZaxis()->SetTitleSize(0.035);
   pullNsm3->GetZaxis()->SetTitleFont(42);
   pullNsm3->Draw("");
}
