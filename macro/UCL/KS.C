//Not all this includes are really needed
#include <TStyle.h>
#include <TCanvas.h>
#include <TFrame.h>
#include "THStack.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TPad.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "TLegend.h"
#include "TFile.h"
#include "TROOT.h"
#include "TF1.h"
#include "TDirectory.h"
using namespace std;



std::vector<double> getKS( int option = 0,TString fname = "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V5.root") {

    TFile * file = TFile::Open(fname);
    //TFile * file = TFile::Open(gDirectory->GetName());
    std::vector<double> ret;
    if (file == 0) {
      std::cout << "Not found input file, abborting" << std::endl;
      return ret;
    
    }

    std::cout << "Processing file: " << file->GetName() << std::endl;
    std::stringstream step;
    step << "Muon/stage_"<<option<<"/selection;1"<<endl;
    TDirectory * d = (TDirectory *)file->Get(step.str().c_str());
    
    std::cout << "d->ls()" << std::endl;
    d->ls();
    
    std::cout << endl << "canvas->ls()" << std::endl;
    TCanvas* mlpa_canvas = (TCanvas*)d->Get("amassMu");
    TList * list = mlpa_canvas->GetListOfPrimitives();
    for(int i =0; i< list->GetSize(); i++){ cout<<list->At(i)->GetName()<<endl;}

    TPad* pad = (TPad*)mlpa_canvas->GetPrimitive("pad1");
    std::cout<<pad<<"----------"<<endl;
    //Plot(mlpa_canvas);
    
    //mlpa_canvas->Draw();
    pad->ls();
    std::cout << std::endl;

    TObject* obj;
    TIter next(pad->GetListOfPrimitives());
    bool firstStack = true;
    bool firstData = true;
    
    TH1* data = 0;
    TH1* ZZ = 0;
    TH1* WZ = 0;
    TH1* WW = 0;
    TH1* ttdilep = 0;
    TH1* ttlept = 0;
    TH1* tW = 0;
    TH1* tWbar = 0;
    TH1* Zj = 0;
    TH1* Zj_l50 = 0;
    TH1* ZH125 = 0;   
    THStack* stack = 0;
    TH1* allMC = 0;
    
    while ((obj = next())) {
      if (obj->InheritsFrom(THStack::Class())) {
				std::cout << "stack-> GetName()=" << obj->GetName()
              << " stack-> GetTitle()=" << obj->GetTitle() << std::endl;
	
				if (firstStack) {
	  		 		stack = (THStack*)obj->Clone();
				} 
				firstStack = false;
    	}

      if (obj->InheritsFrom(TH1::Class()) && firstData) {
				std::cout << "th1> GetName()=" << obj->GetName()
              << " th1-> GetTitle()=" << obj->GetTitle() << std::endl;
	      
	      data = (TH1*)obj->Clone();
	      //std::cout << "Integral=" << data->Integral() << std::endl;
	      data->Draw();
	      firstData = false;
      }

    }//while canvas
    int nbin = data->GetNbinsX();
    
    std::cout << "Pos Loop " <<stack<< endl << endl;
	allMC = (TH1*)stack->GetStack()->Last();
	
	allMC->Scale(1./allMC->Integral(0,nbin+1));
	data->Scale(1./data->Integral(0,nbin+1));	
	cout<<"KS Test: "<<data->KolmogorovTest(allMC)<<endl;
}   

void print(){
	for(int i = 0; i< 6; i++){
		if (i == 2) continue;
		getKS(i);	
	}


}


