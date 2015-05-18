#include <sstream>
#include <fstream>
#include <iostream>

void cardMaker(TString mass, double bkgUnc) {
    ofstream myfile;
    myfile.open("hamb_shape_" + mass + "_ws.txt");
    myfile << "imax 1" << endl;
    myfile << "jmax 1  number of backgrounds" << endl;
    myfile << "kmax 5  number of nuisance parameters (sources of systematical uncertainties)" << endl;
    myfile << "\n------------" << endl;
    myfile << "shapes\tsigPdf\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_sigPdf_dimu" << endl;
    myfile << "shapes\texpo\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_expo_dimu" << endl;
    myfile << "shapes\tbwcb\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_bwxCryBall_dimu" << endl;
    myfile << "shapes\tdytt\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_dytt_dimu" << endl;        
    myfile << "shapes\tdata_obs\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:data_dimu" << endl;
    myfile << "------------" << endl;
    myfile << "bin\tdimu" << endl;
    myfile << "observation\t-1.0" << endl;
    myfile << "------------" << endl;
    myfile << "bin\tdimu\tdimu\tdimu\tdimu" << endl;
    myfile << "process\tsigPdf\texpo\tbwcb\tdytt" << endl;
    myfile << "process\t0\t1\t2\t3" << endl;
    myfile << "rate\t1.0\t1.0\t1.0\t1.0" << endl;
    myfile << "------------" << endl;
    myfile << "lumi_8TeV\tlnN\t1.026\t-\t-\t-" << endl;
    myfile << "test_sigPdf_dimu_norm\tlnN\t1.3\t-\t-\t-" << endl;
    myfile << "test_expo_dimu_norm\tlnU\t-\t"<<1 + bkgUnc<<"\t-\t-" << endl;
    myfile << "test_bwcb_dimu_norm\tlnU\t-\t-\t"<<1 + bkgUnc<<"\t-" << endl;
    myfile << "test_dytt_dimu_norm\tlnU\t-\t-\t-\t"<<1 + bkgUnc<< endl;
    myfile.close();
}

void mytest(int seed = 37) {
    using namespace RooFit;
    using namespace std;
    stringstream nSig;
    stringstream nBkg;
    stringstream bwRatio;
    stringstream bRatio;
    stringstream mass = "40";
    double bL = 10;//std::atof(mass.str().c_str()) - 10;
    double bH = 120.;//std::atof(mass.str().c_str()) + 10;
    TString pf = "5";
    nSig << 3.45;
    nBkg <<  584.2;
    double bkgUnc = 1;// fabs(580.593-621.068)/621.068; //50%
    bwRatio << 0.8;
    bRatio << 0.2;
    stringstream range;
    range << bL << "," << bH;
    cout << "Mass: " << mass.str() << endl;
    cout << "Range: " << range.str() << endl;
    TString Range = range.str().c_str();
    TString Mass = mass.str().c_str();

    TString fname = "hamb-shapes-UnbinnedParam-m"+Mass+"-Data-fit.root";

    TString name = "test";
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", bL, bH);
    RooRandom::randomGenerator()->SetSeed(seed);
    RooWorkspace *w = new RooWorkspace("w", "w");
    w->factory("eventSelectionamassMu[" + Range + "]"/*,Range(SM, 50,70)"*/);
	RooRealVar mean_bw(name + "_mean_bw", "Mean", 90.8, 60, 120);
    w->factory(name + "_mean_bw[90.8, 60, 120]");	
  	RooRealVar mean_cb(name + "_mean_cb", "Mean", 1.0, 0., 50.);
    w->factory(name + "_mean_cb[1.0, 0., 50.]");	  	
  	RooRealVar sigma_bw(name + "_sigma_bw", "Width", 6.5, 1.0, 260.0);
  	w->factory(name + "_sigma_bw[6.5, 1.0, 260.0]");	
    RooRealVar sigma_cb(name + "_sigma_cb", "Width", 2.3, 0., 260.0);
  	w->factory(name + "_sigma_cb[2.3, 0., 260.0]");	    
	RooRealVar n(name + "_n", "", 0.0, 5.0);
  	w->factory(name + "_n[2.3, 0., 260.0]");	    	
	RooRealVar alpha(name + "_alpha", "", 0.0, 5.0);
  	w->factory(name + "_alpha[2.3, 0., 260.0]");	    	
	RooRealVar lambda(name + "_lambda", "slope", -0.1, -5., 0.);
	w->factory(name + "_lambda[-0.1, -5., 0.]");	      	
	RooRealVar mean_dytt(name + "_mean_dytt", "mean_dytt", 42.48403, 32.,52.);
  	w->factory(name + "_mean_dytt[42.48403, 32.,52.]");	    	
	RooRealVar sigma_dytt(name + "_sigma_dytt", "sigma_dytt", 9.348124,8.,10.);
  	w->factory(name + "_sigma_dytt[9.348124, 8., 10.]");	    	

    w->factory("Exponential::" + name + "_expo_dimu(eventSelectionamassMu," + name + "_lambda)");
    w->factory("BreitWigner::" + name + "_gauss_bw_dimu(eventSelectionamassMu," + name +
            "_mean_bw," + name + "_sigma_bw)");
    w->factory("CBShape::" + name + "_cball_dimu(eventSelectionamassMu," + name +
            "_mean_cb," + name + "_sigma_cb,"
            + name + "_alpha," + name + "_n)");
    w->factory("FFTConvPdf::" + name + "_bwxCryBall_dimu(eventSelectionamassMu," + name + "_gauss_bw_dimu," + name + "_cball_dimu)");
    w->factory("Gaussian::"+ name + "_dytt_dimu(eventSelectionamassMu,"+name+"_mean_dytt,"+name+"_sigma_dytt)"); 

  	w->factory(name + "_bwxCryBall_dimu_norm[ 2700]");	    	
  	w->factory(name + "_expo_dimu_norm[500]");	    	
  	w->factory(name + "_dytt_dimu_norm[500]");	 
    
    TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
    TTree* hh = (TTree*) f->Get("rds_zbb");
    RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
    w->import(data);

    TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
    TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
    w->import(sigData);
    w->factory("KeysPdf::" + name + "_sigPdf_dimu(eventSelectionamassMu,sigData_dimu)");
    w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
    w->writeToFile(fname);
    //w->var("eventSelectionamassMu")->setBins(55);
    cardMaker(Mass, bkgUnc);

}
