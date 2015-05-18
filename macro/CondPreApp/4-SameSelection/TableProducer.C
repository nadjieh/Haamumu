#include <vector>
void TableProducer(){
	TString pref = "H2ToH1H1_H1To2Mu2B_mH2-125_mH1-";
	TString mass[4] = {"30", "40", "50", "60"};
	TString midf = "_Summer12_final_";
	TString vCut[4] = {"v30", "v40", "v50", "v60"};
	TString postf = ".root";

	cout<<"| cut version | ma = 30 GeV | ma = 40 GeV | ma = 50 GeV | ma = 60 GeV |"<<endl;
	for(int i = 0; i < 4; i++){
		cout<<"| "<< vCut[i] << "|";
		for(int j = 0; j < 4; j++){
			TFile * f = TFile::Open(pref+mass[j]+midf+vCut[i]+postf);
			TTree * t = (TTree*)f->Get("rds_zbb");
			cout<<t->GetEntries()<<"|";
		}
		cout<<endl;
	}
}
