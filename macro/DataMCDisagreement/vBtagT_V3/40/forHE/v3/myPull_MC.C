{
//========= Macro generated from object: pullNsm2/N_{est}-N_{exp}/#delta N
//========= by ROOT version5.34/19
   
   TH1D *pullNsm2 = new TH1D("pullNsm2","N_{est}-N_{exp}/#delta N",1000,-0.5,0.5);
   pullNsm2->SetBinContent(494,3);
   pullNsm2->SetBinContent(495,3);
   pullNsm2->SetBinContent(496,3);
   pullNsm2->SetBinContent(497,2);
   pullNsm2->SetBinContent(498,8);
   pullNsm2->SetBinContent(499,12);
   pullNsm2->SetBinContent(500,38);
   pullNsm2->SetBinContent(501,23);
   pullNsm2->SetBinContent(502,2);
   pullNsm2->SetBinContent(503,3);
   pullNsm2->SetBinContent(504,2);
   pullNsm2->SetBinContent(508,1);
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
