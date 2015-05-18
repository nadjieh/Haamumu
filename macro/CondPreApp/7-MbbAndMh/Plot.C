void ReadFile(TString m = "", TString name = "diffMassaa"){
	TFile * signal = TFile::Open("rdsM"+m+".root");
	TFile * dy = TFile::Open("rdsDY"+m+".root");
	TFile * dyl = TFile::Open("rdsDYL"+m+".root");
	TH1D * hsig = (TH1D*)signal->Get(name);
	hsig->SetTitle("m_{a} = "+m+"GeV");	
	TH1D * hdy = (TH1D*)dy->Get(name);	
	hdy->SetLineColor(kRed);
	hdy->SetTitle("DY");	
	TH1D * hdyl = (TH1D*)dyl->Get(name);		
	hdyl->SetLineColor(kGreen);
	hdyl->SetTitle("DYLow");	

	TCanvas C;
	C.cd();
	hsig->DrawNormalized("");		
	hdy->DrawNormalized("HISTSAME");
	hdyl->DrawNormalized("HISTSAME");
	hsig->DrawNormalized("HISTSAME");	
	C.SaveAs("mbb_"+m+".C");	
}


void Plot(){
	ReadFile("30","amassBjet");
	ReadFile("40","amassBjet");	
	ReadFile("50","amassBjet");	
	ReadFile("60","amassBjet");
}
