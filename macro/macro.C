#include "TString.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
void DrawAndSave2D(TString fname){
  TString outName = "jetbjet"+fname+".gif";
  TString outNameSel = "jetbjetsel"+fname+".gif";
	TFile * f = TFile::Open("delphesHists_ma"+fname+".root");
	if(f == NULL)
		f = TFile::Open("delphesHists_"+fname+"_run02.root");
  TH2D * h = (TH2D*)f->Get("jettag");
  TH2D * h2 = (TH2D*)f->Get("jettag_dimu");
  TCanvas a;
  a.cd();
  h->Draw("COLZ");
  a.SaveAs(outName);

  TCanvas b;
  b.cd();
  h2->Draw("COLZ");
  b.SaveAs(outNameSel);
}

void Save1D(TString fname = "plots.root"){
	TFile * f = TFile::Open(fname);
	TList * l = f->GetListOfKeys();
	TCanvas * c = 0;
	for(int i = 0; i < l->GetSize(); i++){
		TString s = l->At(i)->GetName();	
		if(s == "jettag" || s == "jettag_dimu")
			continue;
		s = s + ".gif";
		c = (TCanvas*)f->Get(l->At(i)->GetName());
		cout<<c<<" "<<s<<endl;
		c->Draw();
		c->BuildLegend();
		c->SaveAs(s);
	}
}


void doJob(){
	vector<TString> v;
	for(int i = 25; i < 65; i+=5){
		stringstream s;
		s << i;
		v.push_back(s.str().c_str());
	}
	
	for(unsigned int s = 0; s < v.size(); s++){
		DrawAndSave2D(v[s]);
	}
	
}
