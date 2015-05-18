#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <iostream>

using namespace std;

void a(){
std::vector<TFile*> files1, files2;
files1.push_back(TFile::Open("DoubleMu2012_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("DoubleMu2012_Summer12_final_1.root"));
files1.push_back(TFile::Open("DYjets_M10to50_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("DYjets_M10to50_Summer12_final_1.root"));
files1.push_back(TFile::Open("DYjets_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("DYjets_Summer12_final_1.root"));
files1.push_back(TFile::Open("TTFullLept_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("TTFullLept_Summer12_final_1.root"));
files1.push_back(TFile::Open("TTSemiLept_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("TTSemiLept_Summer12_final_1.root"));
files1.push_back(TFile::Open("Wtbar_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("Wtbar_Summer12_final_1.root"));
files1.push_back(TFile::Open("Wt_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("Wt_Summer12_final_1.root"));
files1.push_back(TFile::Open("WW_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("WW_Summer12_final_1.root"));
files1.push_back(TFile::Open("WZ_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("WZ_Summer12_final_1.root"));
files1.push_back(TFile::Open("ZH125_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("ZH125_Summer12_final_1.root"));
files1.push_back(TFile::Open("ZZ_Summer12_final_1_1.root"));
files2.push_back(TFile::Open("ZZ_Summer12_final_1.root"));
files1.push_back(TFile::Open("HTo2Mu2B_mH125_ma40_Summer12_final_1.root"));
files1.push_back(TFile::Open("HTo2Mu2B_mH125_ma50_Summer12_final_1.root"));
files1.push_back(TFile::Open("HTo2Mu2B_mH125_ma60_Summer12_final_1.root"));
for(unsigned int i = 0; i< files1.size(); i++){
	TTree * t = (TTree*)files1[i]->Get("rds_zbb");
	double mass;
	int n = 0;
	t->SetBranchAddress("eventSelectionamassMu",&mass);
	for(int s = 0; s < t->GetEntriesFast(); s++){
		t->GetEntry(s);
		if(mass < 20 || mass > 70)
			continue;
		n++;
	}
		
	cout<<t->GetEntries()<<"\t"<<n <<endl;
}
cout<<"------------------- big files:"<<endl;
for(unsigned int i = 0; i< files2.size(); i++){
	TTree * t = (TTree*)files2[i]->Get("rds_zbb");
	double mass;
	int n = 0;
	t->SetBranchAddress("eventSelectionamassMu",&mass);
	for(int s = 0; s < t->GetEntriesFast(); s++){
		t->GetEntry(s);
		if(mass < 20 || mass > 70)
			continue;
		n++;
	}
		
	cout<<t->GetEntries()<<"\t"<<n <<endl;
}
}
