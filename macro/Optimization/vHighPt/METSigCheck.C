#include <vector>
#include <iostream>
#include <string>
#include <TFile.h>
#include <TH1.h>
using namespace std;
void METSigCheck(){
std::vector<TFile*> files;
std::vector<double> N;
std::vector<double> xsec;
double lumi = 19700;
files.push_back(TFile::Open("rdsdphiBoptDYLow.root")); N.push_back(37835275); xsec.push_back(13229.7);
files.push_back(TFile::Open("rdsdphiBoptDY.root")); N.push_back(30459503); xsec.push_back(3503.71);
files.push_back(TFile::Open("rdsdphiBoptTTF.root")); N.push_back(12119013); xsec.push_back( 27.3 );
files.push_back(TFile::Open("rdsdphiBoptTTS.root")); N.push_back(10997349); xsec.push_back(109.2);
files.push_back(TFile::Open("rdsdphiBoptWtbar.root")); N.push_back(493460); xsec.push_back(11.1);
files.push_back(TFile::Open("rdsdphiBoptWt.root")); N.push_back(497658); xsec.push_back(11.1);
files.push_back(TFile::Open("rdsdphiBoptWW.root")); N.push_back(10000431); xsec.push_back(56.);
files.push_back(TFile::Open("rdsdphiBoptWZ.root")); N.push_back(10000283); xsec.push_back(33.6);
files.push_back(TFile::Open("rdsdphiBoptZH125.root")); N.push_back(999462); xsec.push_back(0.0249);
files.push_back(TFile::Open("rdsdphiBoptZZ.root")); N.push_back(9799908); xsec.push_back(8.258);
files.push_back(TFile::Open("rdsdphiBopt40.root")); N.push_back(101467); xsec.push_back(0.003);
files.push_back(TFile::Open("rdsdphiBopt50.root")); N.push_back(100617); xsec.push_back(0.003);
files.push_back(TFile::Open("rdsdphiBopt60.root")); N.push_back(101822); xsec.push_back(0.003);
cout<<"|| total |  cut = 1.|cut = 2.|cut = 3.|cut = 4.|cut = 5.| cut = 6.|cut = 7.|cut = 8.| cut = 9.|cut = 10.|"<<endl;
for(unsigned int s = 0; s < files.size(); s++){
	TH1D * h = (TH1D*)files[s]->Get("METSIGN");
	double w = xsec[s]*lumi/N[s];
	h->Scale(w);
	int pos1 = string(files[s]->GetName()).find("pt");
	int pos2 = string(files[s]->GetName()).find(".root");	
	string name = string(files[s]->GetName()).substr(pos1+2, pos2 - pos1 -2);
	cout<<"|"<<name<<"|";
	for(int i = 0; i < h->GetXaxis()->GetNbins(); i++){
		cout<<h->GetBinContent(i+1)<<"|";
	}
	cout<<endl;
}


}
