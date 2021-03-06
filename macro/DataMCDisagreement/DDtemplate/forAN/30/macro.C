#include "../../../../../interface/RDSData.h"
#include <iostream>
#include <algorithm>
#include <map>
#include "TMath.h"
#include "TString.h" 
using namespace std;
void macro(bool blind = true){
	TString doblind = "";
	if(blind)
		doblind = "_4";
	gSystem->Load("~/lib/libDelphesTree.2014");
	TFile * f = TFile::Open("rdssignalData2244"+doblind+".root");
	TFile * g = TFile::Open("rdscontrolData2244"+doblind+".root");
	TH1D * hf = (TH1D*)f->Get("amassMu");
	hf->SetNameTitle("signal","signal");
	hf->Sumw2();
	hf->Scale(1./hf->Integral());
	cout<<hf->GetEntries()<<endl;
	int fsize = hf->GetEntries();	
	TH1D * hg = (TH1D*)g->Get("amassMu");
	hg->SetNameTitle("control","control");
	hg->Sumw2();
	hg->Scale(1./hg->Integral());
	cout<<hg->GetEntries()<<endl;	
	int gsize = hg->GetEntries();
	//hg->Rebin(4);
	//hf->Rebin(4);
	cout <<"KS for nBins "<<hg->GetXaxis()->GetNbins()<<": "<<hf->KolmogorovTest(hg)<<endl;
	hg->Draw();
	hf->SetLineColor(kRed);	
	hf->Draw("sames");
	TFile * F = TFile::Open("DoubleMu2012_Summer12_final_4_4_22"+doblind+".root");
	TTree * tf = (TTree*)F->Get("rds_zbb");
	RDSData * rdsf = new RDSData(tf);;
	TFile * G = TFile::Open("DoubleMu2012_Summer12_final_CR2244_4_4"+doblind+".root");
	TTree * tg = (TTree*)G->Get("rds_zbb");	
	RDSData * rdsg = new RDSData(tg);	
	double fentry[1135];
	double gentry[873];
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
