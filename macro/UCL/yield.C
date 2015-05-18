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

std::vector<TFile*> fs(TString dirname = "./forAdding/"){
  vector<TFile*> ret;
  vector<TString> names;
  names.push_back("DYjets_Summer12_final.root");
  names.push_back("DYjets_M10to50_Summer12_final.root");
  names.push_back("TTFullLept_Summer12_final.root");  
  names.push_back("TTSemiLept_Summer12_final.root");   
  names.push_back("Wtbar_Summer12_final.root");   
  names.push_back("Wt_Summer12_final.root");   
  names.push_back("ZZ_Summer12_final.root");   
  names.push_back("WW_Summer12_final.root"); 
  names.push_back("WZ_Summer12_final.root");
  names.push_back("ZH125_Summer12_final.root");   
  for(unsigned int i = 0; i< names.size(); i++)
  	ret.push_back(TFile::Open(dirname+names[i]));
  return ret;
}

std::vector<double> getNoLumiIntegrals( int option = 0) {
	std::vector<TFile*> files = fs();
	std::vector<double> ret;
	stringstream s;
	s<<"Muon/stage_"<<option<<"/selection/METsignificance_hamb";
    for(unsigned int i = 0; i< files.size(); i++){
    	ret.push_back(((TH1*)files[i]->Get(s.str().c_str()))->Integral(0, 1001));
    }
    return ret;
}


std::vector<double> getEntriesFromCP( int option = 0,TString fname = "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root", bool integ = true) {

    TFile * file = TFile::Open(fname);
    //TFile * file = TFile::Open(gDirectory->GetName());
    std::vector<double> ret;
    if (file == 0) {
      std::cout << "Not found input file, aborting" << std::endl;
      return ret;
    
    }
	double sigScale = 1.;
    std::cout << "Processing file: " << file->GetName() << std::endl;
    std::stringstream myD;
    myD << "Muon/stage_"<<option<<";1"<<endl;
    TDirectory * d_ = (TDirectory *)file->Get(myD.str().c_str());    
    cout<< myD.str()<<"\t"<<d_<<"\t"<<d_->GetTitle()<<endl;
    std::cout<<"------------ " <<d_->GetTitle()<<std::endl;
    std::stringstream step;
    step << "Muon/stage_"<<option<<"/selection;1"<<endl;
    TDirectory * d = (TDirectory *)file->Get(step.str().c_str());
    
    std::cout << "d->ls()" << std::endl;
    d->ls();
    
    std::cout << endl << "canvas->ls()" << std::endl;
    TCanvas* mlpa_canvas = (TCanvas*)d->Get("METsignificance_hamb");
    TList * list = mlpa_canvas->GetListOfPrimitives();
    for(int i =0; i< list->GetSize(); i++){ cout<<"---- "<<list->At(i)->GetName()<<endl;}

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
    std::vector<TH1*> signals;
    while ((obj = next())) {
    	if (obj->InheritsFrom(THStack::Class())) {
			std::cout << "stack-> GetName()=" << obj->GetName()
              << " stack-> GetTitle()=" << obj->GetTitle() << std::endl;
			if (firstStack) {
				stack = (THStack*)obj->Clone();
				firstStack = false;
			} 		
		}

      if (obj->InheritsFrom(TH1::Class()) && firstData) {
		std::cout << "th1> GetName()=" << obj->GetName()
            << " th1-> GetTitle()=" << obj->GetTitle() << std::endl;	      
		data = (TH1*)obj->Clone();
      //std::cout << "Integral=" << data->Integral() << std::endl;
		data->Draw();
		firstData = false; 
      }
	  if (obj->InheritsFrom(TH1::Class())) {
	  	if(TString(obj->GetTitle()).Contains("GeV"))
	  		signals.push_back((TH1*)obj->Clone());
	  }
    }//while canvas
    
    
    std::cout << "Pos Loop, signal size is: " <<signals.size()<<"\t"<<stack<< endl << endl;

    TObject* obj2;
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
	   			std::cout << "ZZ GetEntries=" << ZZ->GetEntries() << std::endl;
	 			}
	 		 	if (TString(obj2->GetTitle()).Contains("dilep")) {
			   ttdilep = (TH1*)obj2->Clone();
			   std::cout << "GetEntries ttdilep=" << ttdilep->GetEntries() << std::endl;
  		 	}
	 	 	 	if (TString(obj2->GetTitle()).Contains("lept")) {
	 	  		ttlept = (TH1*)obj2->Clone();
	 	  		std::cout << "GetEntries ttlept=" << ttlept->GetEntries() << std::endl;
   	  	}
	    if (TString(obj2->GetTitle()).Contains("Z+j")) {
	    		if(myZ == 0){
		 	  		Zj = (TH1*)obj2->Clone();
		 	  		std::cout << "GetEntries Zj=" << Zj->GetEntries() << std::endl;
		 	  		myZ++;
	 	  		} else {
	 	  			Zj_l50 = (TH1*)obj2->Clone();
	  	 			std::cout << "GetEntries Zj_l50=" << Zj_l50->GetEntries() << std::endl;
	 	  		}
   	  	}
	  		if (TString(obj2->GetTitle()).Contains("Mll<50")) {
	  	 		Zj_l50 = (TH1*)obj2->Clone();
	  	 		std::cout << "GetEntries Zj_l50=" << Zj_l50->GetEntries() << std::endl;
	    	}	
		    if (TString(obj2->GetTitle()).Contains("ZH_125")) {
		   		ZH125 = (TH1*)obj2->Clone();
		   		std::cout << "GetEntries ZH125=" << ZH125->GetEntries() << std::endl;
		 	 	}
		 	 	if (TString(obj2->GetTitle()).Contains("WW")) {
		   		WW = (TH1*)obj2->Clone();
		   		std::cout << "GetEntries WW=" << WW->GetEntries() << std::endl;
		 	 	}
		 	 	if (TString(obj2->GetTitle()).Contains("WZ")) {
		   		WZ = (TH1*)obj2->Clone();
		   		std::cout << "GetEntries WZ=" << WZ->GetEntries() << std::endl;
		 	 	}	
		 	 	if (TString(obj2->GetTitle()).Contains("tW")) {
		   		tW = (TH1*)obj2->Clone();
		   		std::cout << "GetEntries tW=" << tW->GetEntries() << std::endl;
		 	 	}		
		 	 	if (TString(obj2->GetTitle()).Contains("#bar{t}W")) {
		   		tWbar = (TH1*)obj2->Clone();
		   		std::cout << "GetEntries tWbar=" << tWbar->GetEntries() << std::endl;
		 	 	}				 	 			 	 		 	 	
      }
    }


    std::cout << "Pos Loop2, signal size is: " <<signals.size()<<"\t"<<stack<< endl << endl;
    int nbin = data->GetNbinsX();

    
    std::cout << "Zj GetEntries=" << Zj->GetEntries() << std::endl;
    ret.push_back(Zj->GetEntries());
    std::cout << "Zj_l50 GetEntries=" << Zj_l50->GetEntries() << std::endl;
    ret.push_back( Zj_l50->GetEntries());
    std::cout << "ttdilep GetEntries=" << ttdilep->GetEntries() << std::endl;
    ret.push_back(ttdilep->GetEntries());
    std::cout << "ttlept GetEntries=" << ttlept->GetEntries() << std::endl;
	ret.push_back(ttlept->GetEntries());        
    std::cout << "tW GetEntries=" << tW->GetEntries() << std::endl;
    std::cout << "tWbar GetEntries=" << tWbar->GetEntries() << std::endl;    
    if(integ){       
	    ret.push_back(tWbar->GetEntries()+tW->GetEntries());
	}else{
		ret.push_back(tWbar->GetEntries());
		ret.push_back(tW->GetEntries());
	}
    std::cout << "ZZ GetEntries=" << ZZ->GetEntries() << std::endl;    
    ret.push_back(ZZ->GetEntries());
    std::cout << "WW GetEntries=" << WW->GetEntries() << std::endl;        
    std::cout << "WZ GetEntries=" << WZ->GetEntries() << std::endl;     
    if(integ){       
	    ret.push_back(WZ->GetEntries()+WW->GetEntries());
	}else{
		ret.push_back(WZ->GetEntries());
		ret.push_back(WW->GetEntries());
	}
    std::cout << "ZH125 GetEntries=" << ZH125->GetEntries() << std::endl;
    ret.push_back(ZH125->GetEntries());

    double sum = 0;
    for(unsigned int i = 0; i < ret.size(); i++)
    	sum+=ret[i];
    ret.push_back(sum);
    std::cout << "Data GetEntries=" << data->GetEntries() << std::endl;
    ret.push_back(data->GetEntries());    
    for(unsigned int i = 0; i< signals.size(); i++){
    	ret.push_back(signals[i]->GetEntries()/sigScale);
    }
    return ret;
  
}

typedef std::vector<std::pair<int, double> > StatInfo;
std::vector<double> getYieldsFromCP( int option = 0,TString fname = "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",  bool integ = true, StatInfo * stat =0) {

    TFile * file = TFile::Open(fname);
    //TFile * file = TFile::Open(gDirectory->GetName());
    std::vector<double> ret;
    if (file == 0) {
      std::cout << "Not found input file, abborting" << std::endl;
      return ret;
    
    }
	double sigScale = 50.;
    std::cout << "Processing file: " << file->GetName() << std::endl;
    std::stringstream myD;
    myD << "Muon/stage_"<<option<<";1"<<endl;
    TDirectory * d_ = (TDirectory *)file->Get(myD.str().c_str());    
    cout<< myD.str()<<"\t"<<d_<<"\t"<<d_->GetTitle()<<endl;
    std::cout<<"------------ " <<d_->GetTitle()<<std::endl;
    std::stringstream step;
    step << "Muon/stage_"<<option<<"/selection;1"<<endl;
    TDirectory * d = (TDirectory *)file->Get(step.str().c_str());
    
    std::cout << "d->ls()" << std::endl;
    d->ls();
    
    std::cout << endl << "canvas->ls()" << std::endl;
    TCanvas* mlpa_canvas = (TCanvas*)d->Get("METsignificance_hamb");
    TList * list = mlpa_canvas->GetListOfPrimitives();
    for(int i =0; i< list->GetSize(); i++){ cout<<"---- "<<list->At(i)->GetName()<<endl;}

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
    std::vector<TH1*> signals;
    while ((obj = next())) {
    	if (obj->InheritsFrom(THStack::Class())) {
			std::cout << "stack-> GetName()=" << obj->GetName()
              << " stack-> GetTitle()=" << obj->GetTitle() << std::endl;
			if (firstStack) {
				stack = (THStack*)obj->Clone();
				firstStack = false;
			} 		
		}

      if (obj->InheritsFrom(TH1::Class()) && firstData) {
		std::cout << "th1> GetName()=" << obj->GetName()
            << " th1-> GetTitle()=" << obj->GetTitle() << std::endl;	      
		data = (TH1*)obj->Clone();
      //std::cout << "Integral=" << data->Integral() << std::endl;
		data->Draw();
		firstData = false; 
      }
	  if (obj->InheritsFrom(TH1::Class())) {
	  	if(TString(obj->GetTitle()).Contains("GeV"))
	  		signals.push_back((TH1*)obj->Clone());
	  }
    }//while canvas
    
    
    std::cout << "Pos Loop, signal size is: " <<signals.size()<<"\t"<<stack<< endl << endl;

    TObject* obj2;
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

	
    std::cout << "Pos Loop2, signal size is: " <<signals.size()<<"\t"<<stack<< endl << endl;
    int nbin = data->GetNbinsX();

    
    std::cout << "Zj Integral=" << Zj->Integral(0, nbin + 1) << std::endl;
    ret.push_back(Zj->Integral(0, nbin + 1));
    stat->push_back(make_pair(Zj->GetEntries(), Zj->Integral(0, nbin + 1)/Zj->GetEntries()));
    std::cout << "Zj_l50 Integral=" << Zj_l50->Integral(0, nbin + 1) << std::endl;
    ret.push_back( Zj_l50->Integral(0, nbin + 1));
    stat->push_back(make_pair(Zj_l50->GetEntries(), Zj_l50->Integral(0, nbin + 1)/Zj_l50->GetEntries()));    
    std::cout << "ttdilep Integral=" << ttdilep->Integral(0, nbin + 1) << std::endl;
    ret.push_back(ttdilep->Integral(0, nbin + 1));
    stat->push_back(make_pair(ttdilep->GetEntries(), ttdilep->Integral(0, nbin + 1)/ttdilep->GetEntries()));
    std::cout << "ttlept Integral=" << ttlept->Integral(0, nbin + 1) << std::endl;
	ret.push_back(ttlept->Integral(0, nbin + 1));       
    stat->push_back(make_pair(ttlept->GetEntries(), ttlept->Integral(0, nbin + 1)/ttlept->GetEntries()));	 
    std::cout << "tW Integral=" << tW->Integral(0, nbin + 1) << std::endl;
    std::cout << "tWbar Integral=" << tWbar->Integral(0, nbin + 1) << std::endl;    
    stat->push_back(make_pair(tW->GetEntries(), tW->Integral(0, nbin + 1)/tW->GetEntries()));	 
    stat->push_back(make_pair(tWbar->GetEntries(), tWbar->Integral(0, nbin + 1)/tWbar->GetEntries()));	     
    if(integ){
    	ret.push_back(tWbar->Integral(0, nbin + 1)+tW->Integral(0, nbin + 1));
    }else{
    	ret.push_back(tWbar->Integral(0, nbin + 1));
    	ret.push_back(tW->Integral(0, nbin + 1));
    }
    std::cout << "ZZ Integral=" << ZZ->Integral(0, nbin + 1) << std::endl;    
    ret.push_back(ZZ->Integral(0, nbin + 1));
    stat->push_back(make_pair(ZZ->GetEntries(), ZZ->Integral(0, nbin + 1)/ZZ->GetEntries()));	         
    std::cout << "WW Integral=" << WW->Integral(0, nbin + 1) << std::endl;        
    std::cout << "WZ Integral=" << WZ->Integral(0, nbin + 1) << std::endl;
    stat->push_back(make_pair(WW->GetEntries(), WW->Integral(0, nbin + 1)/WW->GetEntries()));
    stat->push_back(make_pair(WZ->GetEntries(), WZ->Integral(0, nbin + 1)/WZ->GetEntries()));	             	         
    if(integ){        
    	ret.push_back(WZ->Integral(0, nbin + 1)+WW->Integral(0, nbin + 1));
    } else {
    	ret.push_back(WZ->Integral(0, nbin + 1));
    	ret.push_back(WW->Integral(0, nbin + 1));
    }
    std::cout << "ZH125 Integral=" << ZH125->Integral(0, nbin + 1) << std::endl;
    stat->push_back(make_pair(ZH125->GetEntries(), ZH125->Integral(0, nbin + 1)/ZH125->GetEntries()));	             	             
    ret.push_back(ZH125->Integral(0, nbin + 1));

    double sum = 0;
    for(unsigned int i = 0; i < ret.size(); i++)
    	sum+=ret[i];
    ret.push_back(sum);
    std::cout << "Data Integral=" << data->Integral(0, nbin + 1) << std::endl;
    ret.push_back(data->Integral(0, nbin + 1));    
    for(unsigned int i = 0; i< signals.size(); i++){
    	ret.push_back(signals[i]->Integral(0, nbin + 1)/sigScale);
    }
    return ret;
  
}
typedef std::pair<std::string,std::vector<double> > row;
void cutFlowTable(int cat = 0){

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
  names.push_back("m_a = 40 GeV|");     
  names.push_back("m_a = 50 GeV|");     
  names.push_back("m_a = 60 GeV|");         
  
	std::vector<row> table;
	
	table.push_back(make_pair("|Trigger",getYieldsFromCP(0)));
	table.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1+cat)));	
	table.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3+cat)));		
	table.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4+cat)));
	table.push_back(make_pair("|(2,3)",getYieldsFromCP(5+cat)));
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

void showBkg(int cat = 8, bool integOnly = false){
  std::vector<std::string> names;
  names.push_back("||");
  names.push_back("DY (m_{ll}>50)|");
  names.push_back("DY (10<m_{ll}<50)|");
  names.push_back("t\\bar{t}(ll)|");  
  names.push_back("t\\bar{t}(lj)|");  
  if(integOnly) 
	  names.push_back("tW|");   
  else{
  	  names.push_back("tWbar|");
  	  names.push_back("tW|");  	  
  }
  names.push_back("ZZ|");   
  if(integOnly) 
	  names.push_back("other VV|"); 
  else {
   	  names.push_back("WW|");
  	  names.push_back("WZ|");  
  }
  names.push_back("ZH(125)|");   
  std::vector<row> table;
  std::vector<row> table2;
  if(integOnly)
  	table.push_back(make_pair("|(2,3)",getYieldsFromCP(cat,  "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",integOnly)));
  else{
  	table2.push_back(make_pair("|(2,3)",getNoLumiIntegrals(cat)));  	
  	table.push_back(make_pair("|(2,3)",getYieldsFromCP(cat, "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",integOnly)));
  }
  for(unsigned int i = 0; i< names.size(); i++)
	cout<<names[i];
  cout<<endl;
  for(unsigned int i = 0; i< table.size(); i++){
	cout<<table[i].first<<"|";
	for(unsigned int j = 0; j < table[i].second.size(); j++)
		cout<<table[i].second[j]<<"| ";
	cout<<endl;
  }
  if(!integOnly){
  	for(unsigned int i = 0; i< table2.size(); i++){
		cout<<table2[i].first<<"|";
		for(unsigned int j = 0; j < table2[i].second.size(); j++)
			cout<<table2[i].second[j]<<"| ";
		cout<<endl;
  	}
  }
  cout<<endl;
  cout<<"|";
  for(unsigned int i = 0; i< table.size(); i++){
  	cout<<table[i].first;
	if(!integOnly)
		cout<<"|Entries| Beta";		
  }
  cout<<"|"<<endl;
  cout<<"|---+---|"<<endl;
  for(unsigned int i = 1; i< names.size(); i++){
	cout<<"|"<<names[i];//<<endl;
	for(unsigned int s = 0; s < table.size(); s++){
		cout<<table[s].second[i-1]<<"|";
	    if(!integOnly)
			cout<<table2[s].second[i-1]<<"|"<<table[s].second[i-1]/table2[s].second[i-1]<<"|";
	}
	cout<<endl;
  }
  cout<<endl;
}


void showOneRegion(int cat = 8, bool integOnly = true){
  std::vector<std::string> names;
  names.push_back("||");
  names.push_back("DY (m_{ll}>50)|");
  names.push_back("DY (10<m_{ll}<50)|");
  names.push_back("t\\bar{t}(ll)|");  
  names.push_back("t\\bar{t}(lj)|");  
  if(integOnly) 
	  names.push_back("tW|");   
  else{
  	  names.push_back("tWbar|");
  	  names.push_back("tW|");  	  
  }
  names.push_back("ZZ|");   
  if(integOnly) 
	  names.push_back("other VV|"); 
  else {
   	  names.push_back("WW|");
  	  names.push_back("WZ|");  
  }
  names.push_back("ZH(125)|");   
  names.push_back("Sum MC|"); 
  names.push_back("data|"); 
  names.push_back("m_a = 40 GeV|");     
  names.push_back("m_a = 50 GeV|");     
  names.push_back("m_a = 60 GeV|"); 
  std::vector<row> table;
  std::vector<row> table2;
  if(integOnly)
  	table.push_back(make_pair("|(2,3)",getYieldsFromCP(cat,  "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",integOnly)));
  else{
  	table2.push_back(make_pair("|(2,3)",getEntriesFromCP(cat, "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",integOnly)));  	
  	table.push_back(make_pair("|(2,3)",getYieldsFromCP(cat, "mergedPlots_2012ABCD_V1_hamb_allMC_btagSFs_V13-vSig.root",integOnly)));
  }
  for(unsigned int i = 0; i< names.size(); i++)
	cout<<names[i];
  cout<<endl;
  for(unsigned int i = 0; i< table.size(); i++){
	cout<<table[i].first<<"|";
	for(unsigned int j = 0; j < table[i].second.size(); j++)
		cout<<table[i].second[j]<<"| ";
	cout<<endl;
  }
  if(!integOnly){
  	for(unsigned int i = 0; i< table2.size(); i++){
		cout<<table2[i].first<<"|";
		for(unsigned int j = 0; j < table2[i].second.size(); j++)
			cout<<table2[i].second[j]<<"| ";
		cout<<endl;
  	}
  }
  cout<<endl;
  cout<<"|";
  for(unsigned int i = 0; i< table.size(); i++){
  	cout<<table[i].first;
	if(!integOnly)
		cout<<"|Entries| Beta";		
  }
  cout<<"|"<<endl;
  cout<<"|---+---|"<<endl;
  for(unsigned int i = 1; i< names.size(); i++){
	cout<<"|"<<names[i];//<<endl;
	for(unsigned int s = 0; s < table.size(); s++){
		cout<<table[s].second[i-1]<<"|";
	    if(!integOnly)
			cout<<table2[s].second[i-1]<<"|"<<table[s].second[i-1]/table2[s].second[i-1]<<"|";
	}
	cout<<endl;
  }
  cout<<endl;
}

void diffYield(TString  incfile ,TString exfile, int cat = 0){

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
  names.push_back("m_a = 40 GeV|");     
  names.push_back("m_a = 50 GeV|");     
  names.push_back("m_a = 60 GeV|"); 
  StatInfo * stat = new StatInfo();
  std::vector<row> tableInc;
  tableInc.push_back(make_pair("|Trigger",getYieldsFromCP(0,incfile)));
	tableInc.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1+cat,incfile)));	
	tableInc.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3+cat,incfile)));		
	tableInc.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4+cat,incfile)));
	tableInc.push_back(make_pair("|(2,3)",getYieldsFromCP(5+cat,incfile)));
	
  std::vector<row> tableEx;
  tableEx.push_back(make_pair("|Trigger",getYieldsFromCP(0,exfile)));
	tableEx.push_back(make_pair("|\\ge 2\\mu, \\ge 2b, 20 < m_{\\mu\\mu} < 70",getYieldsFromCP(1+cat,exfile)));	
	tableEx.push_back(make_pair("|Met-signifcance (2)",getYieldsFromCP(3+cat,exfile)));		
	tableEx.push_back(make_pair("|\\Delta m(a,a) < 30 (3)",getYieldsFromCP(4+cat,exfile)));
	tableEx.push_back(make_pair("|(2,3)",getYieldsFromCP(5+cat,exfile)));
	
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


