#include "../../../../../interface/RDSData.h"
#include <iostream>
#include <algorithm>
#include "TMath.h"
using namespace std;
void macro(bool blind = true){
	gSystem->Load("~/lib/libDelphesTree.2014");
	TString doblind = "";
	if(blind)
		doblind = "_4";	
	TFile * f = TFile::Open("rdssignalData"+doblind+".root");
	TFile * g = TFile::Open("rdscontrolData"+doblind+".root");
	TH1D * hf = (TH1D*)f->Get("amassMu");
	hf->SetNameTitle("signal","signal");
	hf->Sumw2();
	hf->Scale(1./hf->Integral());
	int fsize = hf->GetEntries();		
	cout<<hf->GetEntries()<<endl;	
	TH1D * hg = (TH1D*)g->Get("amassMu");
	hg->SetNameTitle("control","control");
	hg->Sumw2();
	hg->Scale(1./hg->Integral());
	cout<<hg->GetEntries()<<endl;
	int gsize = hg->GetEntries();	
	cout <<"KS for nBins "<<hg->GetXaxis()->GetNbins()<<": "<<hf->KolmogorovTest(hg)<<endl;
	hg->Draw();
	hf->SetLineColor(kRed);	
	hf->Draw("sames");
	TFile * F = TFile::Open("DoubleMu2012_Summer12_final_4_4"+doblind+".root");
	TTree * tf = (TTree*)F->Get("rds_zbb");
	RDSData * rdsf = new RDSData(tf);;
	TFile * G = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4"+doblind+".root");
	TTree * tg = (TTree*)G->Get("rds_zbb");	
	RDSData * rdsg = new RDSData(tg);	
	double fentry[761];
	double gentry[588];
	int nf = 0;	
	int ng = 0;	
	for (int eventNumber = 0; eventNumber < rdsf->fChain->GetEntriesFast(); eventNumber++) {
        rdsf->GetEntry(eventNumber);
        if(rdsf->eventSelectionamassMu < 20)
        	continue;
        fentry[nf] = rdsf->eventSelectionamassMu;
        nf++;
    }
	for (int eventNumber = 0; eventNumber < rdsg->fChain->GetEntriesFast(); eventNumber++) {
        rdsg->GetEntry(eventNumber);
        if(rdsg->eventSelectionamassMu < 20)
        	continue;
        gentry[ng] = rdsg->eventSelectionamassMu;
        ng++;
    }
    std::sort(fentry, fentry + fsize); 
    std::sort(gentry, gentry + gsize);     
  	cout<<nf<<"\t"<<ng<<endl;
    double KS = TMath::KolmogorovTest( fsize,fentry, gsize,gentry,"D");
	cout <<"KS for unbinned: "<<KS<<endl;  
	
	/*
	 * KS for nBins 1000: 0.554699
	 * 1193	975
	 * Kolmogorov Probability = 0.443466, Max Dist = 0.0373254
	 * KS for unbinned: 0.443466
	 */  
}
