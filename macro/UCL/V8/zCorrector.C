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
void Plot(TCanvas* c) {c->Draw();}


std::vector<double> getYieldsFromCP( int option = 0,TString fname = "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V8.root") {

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
    
    
    std::cout << "Pos Loop " <<stack<< endl << endl;

    TObject* obj2;
    //TIter next2(listHist);
    TIter next2(stack->GetHists());
    int myZ = 0;
    while ((obj2 = next2())) {
      if (obj2->InheritsFrom(TH1::Class())) {
    	 std::cout << "th1_2> GetName()=" << obj2->GetName()
    	  << " th1_2-> GetTitle()=" << obj2->GetTitle()
	      << std::endl;
      	if (TString(obj2->GetTitle()).Contains("ZZ")) {
	   			ZZ = (TH1*)obj2->Clone();
	   			std::cout << "it contains ZZ" << std::endl;
	   			std::cout << "ZZ Integral=" << ZZ->Integral() << std::endl;
	 			}
	 		 	if (TString(obj2->GetTitle()).Contains("dilep")) {
			   ttdilep = (TH1*)obj2->Clone();
			   std::cout << "Integral ttdilep=" << ttdilep->Integral() << std::endl;
  		 	}
	 	 	 	if (TString(obj2->GetTitle()).Contains("lept")) {
	 	  		ttlept = (TH1*)obj2->Clone();
	 	  		std::cout << "Integral ttlept=" << ttlept->Integral() << std::endl;
   	  	}
	    	if (TString(obj2->GetTitle()).Contains("Z+j")) {
	    		if(myZ == 0){
		 	  		Zj = (TH1*)obj2->Clone();
		 	  		std::cout << "Integral Zj=" << Zj->Integral() << std::endl;
		 	  		myZ++;
	 	  		} else {
	 	  			Zj_l50 = (TH1*)obj2->Clone();
	  	 			std::cout << "Integral Zj_l50=" << Zj_l50->Integral() << std::endl;
	 	  		}
   	  	}
	  		if (TString(obj2->GetTitle()).Contains("Mll<50")) {
	  	 		Zj_l50 = (TH1*)obj2->Clone();
	  	 		std::cout << "Integral Zj_l50=" << Zj_l50->Integral() << std::endl;
	    	}	
		    if (TString(obj2->GetTitle()).Contains("ZH_125")) {
		   		ZH125 = (TH1*)obj2->Clone();
		   		std::cout << "Integral ZH125=" << ZH125->Integral() << std::endl;
		 	 	}
		 	 	if (TString(obj2->GetTitle()).Contains("WW")) {
		   		WW = (TH1*)obj2->Clone();
		   		std::cout << "Integral WW=" << WW->Integral() << std::endl;
		 	 	}
		 	 	if (TString(obj2->GetTitle()).Contains("WZ")) {
		   		WZ = (TH1*)obj2->Clone();
		   		std::cout << "Integral WZ=" << WZ->Integral() << std::endl;
		 	 	}	
		 	 	if (TString(obj2->GetTitle()).Contains("tW")) {
		   		tW = (TH1*)obj2->Clone();
		   		std::cout << "Integral tW=" << tW->Integral() << std::endl;
		 	 	}		
		 	 	if (TString(obj2->GetTitle()).Contains("#bar{t}W")) {
		   		tWbar = (TH1*)obj2->Clone();
		   		std::cout << "Integral tWbar=" << tWbar->Integral() << std::endl;
		 	 	}				 	 			 	 		 	 	
      }
    }
 
 
 
    std::cout << "Pos Loop2" << endl << endl;
    
    int nbin = data->GetNbinsX();
	int fBin = data->GetXaxis()->FindBin(20.);//0;
	int lBin = data->GetXaxis()->FindBin(70.) + 1;//nbin + 1;
    
    std::cout << "Zj Integral=" << Zj->Integral(fBin, lBin) << std::endl;
    ret.push_back(Zj->Integral(fBin, lBin));
    std::cout << "Zj_l50 Integral=" << Zj_l50->Integral(fBin, lBin) << std::endl;
    ret.push_back( Zj_l50->Integral(fBin, lBin));
    std::cout << "ttdilep Integral=" << ttdilep->Integral(fBin, lBin) << std::endl;
    ret.push_back(ttdilep->Integral(fBin, lBin));
    std::cout << "ttlept Integral=" << ttlept->Integral(fBin, lBin) << std::endl;
		ret.push_back(ttlept->Integral(fBin, lBin));        
    std::cout << "tW Integral=" << tW->Integral(fBin, lBin) << std::endl;
    std::cout << "tWbar Integral=" << tWbar->Integral(fBin, lBin) << std::endl;    
    ret.push_back(tWbar->Integral(fBin, lBin)+tW->Integral(fBin, lBin));
    std::cout << "ZZ Integral=" << ZZ->Integral(fBin, lBin) << std::endl;    
    ret.push_back(ZZ->Integral(fBin, lBin));
    std::cout << "WW Integral=" << WW->Integral(fBin, lBin) << std::endl;        
    std::cout << "WZ Integral=" << WZ->Integral(fBin, lBin) << std::endl;            
    ret.push_back(WZ->Integral(fBin, lBin)+WW->Integral(fBin, lBin));
    std::cout << "ZH125 Integral=" << ZH125->Integral(fBin, lBin) << std::endl;
    ret.push_back(ZH125->Integral(fBin, lBin));

    double sum = 0;
    for(unsigned int i = 0; i < ret.size(); i++)
    	sum+=ret[i];
    ret.push_back(sum);
    std::cout << "Data Integral=" << data->Integral(fBin, lBin) << std::endl;
    ret.push_back(data->Integral(fBin, lBin));    
    return ret;
  
}
typedef std::pair<std::string,std::vector<double> > row;
void cutFlowTable(){

  std::vector<std::string> names;
  names.push_back("||");
  names.push_back("DY (m_{ll}>50)|");
  names.push_back("DY (10<m_{ll}<50)|");
  names.push_back("t\\bar{t}(ll)|");  
  names.push_back("t\\bar{t}(lj)|");   
  names.push_back("tW|");   
  names.push_back("ZZ|");   
  names.push_back("other VV|"); 
  names.push_back("ZH(125)|");   
  names.push_back("Sum MC|"); 
  names.push_back("data|");   
  
	std::vector<row> table;
	
	table.push_back(make_pair("|Trigger",getYieldsFromCP(0)));
	table.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1)));	
	table.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3)));		
	table.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4)));
	table.push_back(make_pair("|(2,3)",getYieldsFromCP(5)));
	for(unsigned int i = 0; i< names.size(); i++)
		cout<<names[i];
	cout<<endl;
	for(unsigned int i = 0; i< table.size(); i++){
		cout<<table[i].first<<"|";
		for(unsigned int j = 0; j < table[i].second.size(); j++)
			cout<<table[i].second[j]<<"| ";
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"|";
	for(unsigned int i = 0; i< table.size(); i++){
		cout<<table[i].first;
	}
	cout<<"|"<<endl;
	cout<<"|---+---|"<<endl;
	for(unsigned int i = 1; i< names.size(); i++){
		cout<<"|"<<names[i];//<<endl;
		for(unsigned int s = 0; s < table.size(); s++){
			cout<<table[s].second[i-1]<<"|";
		}
		cout<<endl;
	}
	cout<<endl;

}

void diffYield(){

  std::vector<std::string> names;
  names.push_back("||");
  names.push_back("DY (m_{ll}>50)|");
  names.push_back("DY (10<m_{ll}<50)|");
  names.push_back("t\\bar{t}(ll)|");  
  names.push_back("t\\bar{t}(lj)|");   
  names.push_back("tW|");   
  names.push_back("ZZ|");   
  names.push_back("other VV|"); 
  names.push_back("ZH(125)|");   
  names.push_back("Sum MC|"); 
  names.push_back("data|"); 
  
  TString incfile = "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V6.root";
  std::vector<row> tableInc;
  tableInc.push_back(make_pair("|Trigger",getYieldsFromCP(0,incfile)));
	tableInc.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1,incfile)));	
	tableInc.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3,incfile)));		
	tableInc.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4,incfile)));
	tableInc.push_back(make_pair("|(2,3)",getYieldsFromCP(5,incfile)));
	
	TString exfile = "../V4/mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_v4_v2.root";
  std::vector<row> tableEx;
  tableEx.push_back(make_pair("|Trigger",getYieldsFromCP(0,exfile)));
	tableEx.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1,exfile)));	
	tableEx.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3,exfile)));		
	tableEx.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4,exfile)));
	tableEx.push_back(make_pair("|(2,3)",getYieldsFromCP(5,exfile)));
	
	cout<<"|";
	for(unsigned int i = 0; i< tableEx.size(); i++){
		cout<<tableEx[i].first;
	}
	cout<<"|"<<endl;
	cout<<"|---+---|"<<endl;
	
	for(unsigned int i = 1; i< names.size(); i++){
		cout<<"|"<<names[i];//<<endl;
		for(unsigned int s = 0; s < tableInc.size(); s++){
			cout<<tableInc[s].second[i-1] - tableEx[s].second[i-1] <<"|";
		}
		cout<<endl;
	}
	cout<<endl;
}


