{
//========= Macro generated from object: pullNsm/N_{est}-N_{exp}/#delta N
//========= by ROOT version5.34/19
   
   TH1D *pullNsm = new TH1D("pullNsm","N_{est}-N_{exp}/#delta N",1000,-0.5,0.5);
   pullNsm->SetBinContent(494,1);
   pullNsm->SetBinContent(495,5);
   pullNsm->SetBinContent(496,3);
   pullNsm->SetBinContent(497,6);
   pullNsm->SetBinContent(498,5);
   pullNsm->SetBinContent(499,11);
   pullNsm->SetBinContent(500,32);
   pullNsm->SetBinContent(501,25);
   pullNsm->SetBinContent(502,4);
   pullNsm->SetBinContent(503,3);
   pullNsm->SetBinContent(504,2);
   pullNsm->SetBinContent(505,2);
   pullNsm->SetBinContent(506,1);
   pullNsm->SetEntries(100);

   ci = TColor::GetColor("#000099");
   pullNsm->SetLineColor(ci);
   pullNsm->GetXaxis()->SetLabelFont(42);
   pullNsm->GetXaxis()->SetLabelSize(0.035);
   pullNsm->GetXaxis()->SetTitleSize(0.035);
   pullNsm->GetXaxis()->SetTitleFont(42);
   pullNsm->GetYaxis()->SetLabelFont(42);
   pullNsm->GetYaxis()->SetLabelSize(0.035);
   pullNsm->GetYaxis()->SetTitleSize(0.035);
   pullNsm->GetYaxis()->SetTitleFont(42);
   pullNsm->GetZaxis()->SetLabelFont(42);
   pullNsm->GetZaxis()->SetLabelSize(0.035);
   pullNsm->GetZaxis()->SetTitleSize(0.035);
   pullNsm->GetZaxis()->SetTitleFont(42);
   pullNsm->Draw("");
}
