#include <iostream>
#include <sstream>
#include <vector>

void cardMaker(TString iPD, TString mass, double bkgUnc, bool binned = false, float nSig = 0, float nBkg = 0, int ndata = 0) {
	TString outname = "hamb_shape_" + mass + "-" + iPD + "_ws.txt";
	ofstream myfile;
    myfile.open(outname);
    myfile << "imax 1" << endl;
    myfile << "jmax 1  number of backgrounds" << endl;
    myfile << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl;

   	myfile << "\n------------" << endl;
    myfile << "shapes\tsigPdf\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit-" + iPD + ".root w:test_sigPdf_dimu" << endl;
   	myfile << "shapes\tbkg\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit-" + iPD + ".root w:test_bkg_dimu" << endl;
   	myfile << "shapes\tdata_obs\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit-" + iPD + ".root w:data_dimu" << endl;
   	myfile << "------------" << endl;
   	myfile << "bin\tdimu" << endl;
   	myfile << "observation\t-1.0" << endl;
   	myfile << "------------" << endl;
   	myfile << "bin\tdimu\tdimu" << endl;
   	myfile << "process\tsigPdf\tbkg" << endl;
   	myfile << "process\t0\t1" << endl;
   	myfile << "rate\t1.0\t1.0" << endl;
   	myfile << "------------" << endl;
   	myfile << "lumi_8TeV\tlnN\t1.026\t-" << endl;
   	myfile << "test_sigPdf_dimu_norm\tlnN\t1.3\t-" << endl;
   	myfile << "test_bkg_dimu_norm\tlnN\t-\t" << 1 + bkgUnc << endl;
    myfile.close();
}

void WorkSpaceMaker(TString iPD, RooKeysPdf * bkgPdf, RooDataSet * bkgData, int seed){
 	using namespace RooFit;
    using namespace std;
    int nbin = 50;
    bool binned = true;
    stringstream nSig;
    stringstream nBkg;
    stringstream bwRatio;
    stringstream bRatio;
    stringstream mass = "40";
    double bL = 20.;//std::atof(mass.str().c_str()) - 10;
    double bH = 70.;//std::atof(mass.str().c_str()) + 10;
    TString pf = "4_4";
    nSig <<3.45;
    nBkg << 552;
    double bkgUnc = 1;//(510-424.)/424.; //50%
    bwRatio << 0.2;
    bRatio << 0.8;
    stringstream range;
    range << bL << "," << bH;
    cout << "Mass: " << mass.str() << endl;
    cout << "Range: " << range.str() << endl;
    TString Range = range.str().c_str();
    TString Mass = mass.str().c_str();
    ///	Data-fit ////////////////
    TString fname = "hamb-shapes-UnbinnedParam-m" + Mass + "-Data-fit-" + iPD + ".root";
	TString name = "test";
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", bL, bH);
    RooRandom::randomGenerator()->SetSeed(seed);
    RooWorkspace *w = new RooWorkspace("w", "w");
    w->factory("eventSelectionamassMu[" + Range + "]"/*,Range(SM, 50,70)"*/);
    bkgPdf->SetName(name+"_bkg_dimu");
    bkgData->SetName("bkgData");
    w->import(*bkgData);
    w->import(*bkgPdf);
   	TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
   	TTree* hh = (TTree*) f->Get("rds_zbb");
   	RooDataSet * data = new RooDataSet("data_dimu", "data", hh, eventSelectionamassMu, "");
   	w->import(*data);
   	TH1D * hData = data->createHistogram("data_obs",eventSelectionamassMu,Binning(nbin));
   	double frac = (double)hData->Integral()/(double)nbin;
   	nBkg.str("");
   	nBkg << hData->Integral() - (5 * frac);
   	delete hData;
   	delete data;
   	TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
   	TTree* hsig = (TTree*) fsig->Get("rds_zbb");
   	RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
   	w->import(sigData);
   	w->factory("KeysPdf::" + name + "_sigPdf_dimu(eventSelectionamassMu,sigData_dimu)");
   	   
   	w->factory(name + "_bkg_dimu_norm[" + nBkg.str().c_str() + "]");
   	w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
   	w->writeToFile(fname);
   	cout<<"---"<<endl;
	delete hsig;
   	cout<<"----"<<endl;
	delete fsig;
   	cout<<"-----"<<endl;

   	delete hh;
   	delete f;
	delete w;
   	cardMaker(iPD, Mass, bkgUnc, binned);
}

void ProduceBootstrap(int seed = 37){
  //**** General Settings
  using namespace RooFit;
  using namespace std;
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  RooRandom::randomGenerator()->SetSeed(seed);
  int NPD = 100;  
  TFile * input = TFile::Open("keyspdfs.root");
  RooWorkspace *w2 = (RooWorkspace*)input->Get("keyspdfs");
  RooRealVar *var = w2->var("eventSelectionamassMu");
  stringstream s;
  RooKeysPdf * pdfPD = 0;
  RooDataSet * PD = 0;  
  for(int i = 0; i < NPD; i++){
    s.str("");
    s <<"mypdf_"<<i+1;  
    TString pdfname = s.str().c_str();
    s.str("");
    s <<"data_"<<i+1;  
    TString dataname = s.str().c_str(); 
    cout<<dataname<<endl;   
    pdfPD = (RooKeysPdf*)w2->pdf(pdfname);
    cout<<"----- "<<endl;
    PD = (RooDataSet*)w2->data(dataname);
    cout<<"Data "<<PD<<", pdf "<<pdfPD<<endl;
    s.str("");
    s << i + 1;
    TString myI = s.str().c_str();
    WorkSpaceMaker(myI, pdfPD, PD, seed);
    
    //delete pdfPD;
    //delete PD;    
  }
}
