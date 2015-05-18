void FileProvider(TString mass = "50", bool blind = true){
	//Reading Data
	TString fname = "dataMass"+mass+".root";
	TFile * fData = TFile::Open(fname);
	TH1D * hData = (TH1D*)fData->Get("data");
	TH1D * data_obs = new TH1D("data_obs","data_obs",30,10.,70.);
	for(int i = 6; i < 36; i++){
		int binContent = hData->GetBinContent(i);
		if(!blind)
			data_obs->SetBinContent(i - 5, binContent);
	}
	
	//Reading Background
	fname = "bkg"+mass+".root";
	TFile * fBkg = TFile::Open(fname);	
	TH1D * hBkg = (TH1D*)fBkg->Get("bkg");
	
	//Reading Signal
	fname = "sig"+mass+".root";
	TFile * fSig = TFile::Open(fname);	
	TH1D * hSig = (TH1D*)fSig->Get("signal");
		
	//Save in output
	fname = "dimuDD"+mass+".root";
	if(blind)
		fname = "dimuDD"+mass+"_blind.root";
	TFile * fOut = new TFile(fname,"recreate");
	fOut->mkdir("dimu")->cd();
	data_obs->Write();
	hBkg->Write();
	hSig->Write();
	fOut->cd();
	fOut->Close();
}
