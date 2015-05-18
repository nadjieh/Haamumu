void FileProvider(TString mass = "30", bool blind = false){
	//Reading Data
	TString fname = "dataMass"+mass+".root";
	TFile * fData = TFile::Open(fname);
	TH1D * hData = (TH1D*)fData->Get("data");
	TH1D * data_obs = new TH1D("data_obs","data_obs",10,20.,40.);
	for(int i = 11; i < 21; i++){
		int binContent = hData->GetBinContent(i);
		if(!blind)
			data_obs->SetBinContent(i - 10, binContent);
	}
	
	//Reading Background
	fname = "bkg"+mass+".root";
	TFile * fBkg = TFile::Open(fname);	
	TH1D * hBkgtmp = (TH1D*)fBkg->Get("bkg");
	hBkgtmp->SetName("hBkgtmp");
	TH1D * hBkg = new TH1D("bkg","bkg",10,20.,40.);
	for(int i = 6; i < 16; i++){
		hBkg->SetBinContent(i - 5, hBkgtmp->GetBinContent(i));
	}	
	
	//Reading Signal
	fname = "sig"+mass+".root";
	TFile * fSig = TFile::Open(fname);	
	TH1D * hSigtmp = (TH1D*)fSig->Get("signal");
	hSigtmp->SetName("hSigtmp");
	TH1D * hSig = new TH1D("signal","signal",10,20.,40.);
	for(int i = 6; i < 16; i++){
		hSig->SetBinContent(i - 5, hSigtmp->GetBinContent(i));
	}
			
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
