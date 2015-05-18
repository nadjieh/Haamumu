#include <sstream>
#include <fstream>
#include <iostream>

void cardMaker(TString mass, double bkgUnc) {
    ofstream myfile;
    myfile.open("hamb_shape_" + mass + "_ws.txt");
    myfile << "imax 1" << endl;
    myfile << "jmax 1  number of backgrounds" << endl;
    myfile << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl;
    myfile << "\n------------" << endl;
    myfile << "shapes\tsigPdf\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_sigPdf_dimu" << endl;
    myfile << "shapes\tsum\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:test_sum_dimu" << endl;
    myfile << "shapes\tdata_obs\tdimu\thamb-shapes-UnbinnedParam-m" + mass + "-Data-fit.root w:data_dimu" << endl;
    myfile << "------------" << endl;
    myfile << "bin\tdimu" << endl;
    myfile << "observation\t-1.0" << endl;
    myfile << "------------" << endl;
    myfile << "bin\tdimu\tdimu" << endl;
    myfile << "process\tsigPdf\tsum" << endl;
    myfile << "process\t0\t1" << endl;
    myfile << "rate\t1.0\t1.0" << endl;
    myfile << "------------" << endl;
    myfile << "lumi_8TeV\tlnN\t1.026\t-" << endl;
    myfile << "test_sigPdf_dimu_norm\tlnN\t1.3\t-" << endl;
    myfile << "test_sum_dimu_norm\tlnN\t-\t"<<1 + bkgUnc << endl;
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
    double bL = std::atof(mass.str().c_str()) - 10;
    double bH = std::atof(mass.str().c_str()) + 10;
    TString pf = "5";
    nSig << 3.45;
    nBkg <<  584.2;
    double bkgUnc = fabs(580.593-621.068)/621.068; //50%
    bwRatio << 0.8;
    bRatio << 0.2;
    stringstream range;
    range << bL << "," << bH;
    cout << "Mass: " << mass.str() << endl;
    cout << "Range: " << range.str() << endl;
    TString Range = range.str().c_str();
    TString Mass = mass.str().c_str();
    /////// Data-fit ////////////////
    //TString fname = "hamb-shapes-UnbinnedParam-m" + Mass + "-Data-fit.root";
	//stringstream lambda; lambda << -0.142632;
	//stringstream alpha; alpha << 0.442134;
	//stringstream n; n <<  1.1164;
	//stringstream meanbw; meanbw <<  91.1748;
	//stringstream sigmabw; sigmabw <<  1.37039;
	//stringstream meancb; meancb <<  1.09073;
	//stringstream sigmacb; sigmacb <<  0.325402;
    ///////////////////////////////
    /////////// Data-fit ////////////////
    TString fname = "hamb-shapes-UnbinnedParam-m"+Mass+"-Data-fit.root";
    stringstream lambda; lambda << -0.246033;
    stringstream alpha; alpha << 0.827119;
    stringstream n; n <<  1.56967;
    stringstream meanbw; meanbw <<  89.7583;
    stringstream sigmabw; sigmabw <<  1;
    stringstream meancb; meancb <<  1.3922;
    stringstream sigmacb; sigmacb <<  1.57199;
///////////////////////////////////


    TString name = "test";
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", bL, bH);
    TFile* ftop = new TFile("TTFullLept_Summer12_final_" + pf + ".root", "READ");
    TTree* htop = (TTree*) ftop->Get("rds_zbb");
    RooDataSet topData("topData", "topData", htop, eventSelectionamassMu, "");
    RooRandom::randomGenerator()->SetSeed(seed);
    RooWorkspace *w = new RooWorkspace("w", "w");
    w->factory("eventSelectionamassMu[" + Range + "]"/*,Range(SM, 50,70)"*/);
    w->import(topData);
    w->factory("KeysPdf::topPdf_dimu(eventSelectionamassMu,topData)");
    w->factory("Exponential::" + name + "_expo_dimu(eventSelectionamassMu," + name + "_lambda[" + lambda.str().c_str() + "])");
    w->var(name + "_lambda")->setConstant(kTRUE);
    w->factory(name + "_frac[0.5,0.0,1.0]");
    w->factory("AddPdf::" + name + "_bkg_dimu(topPdf_dimu," + name + "_expo_dimu," + name + "_frac)");

    w->factory("BreitWigner::" + name + "_gauss_bw_dimu(eventSelectionamassMu," + name +
            "_mean_bw_pf[" + meanbw.str().c_str() + "]," + name + "_sigma_bw_pf[" + sigmabw.str().c_str() + "])");
    w->var(name + "_mean_bw_pf")->setConstant(kTRUE);
    w->var(name + "_sigma_bw_pf")->setConstant(kTRUE);

    w->factory("CBShape::" + name + "_cball_dimu(eventSelectionamassMu," + name +
            "_mean_cb_pf[" + meancb.str().c_str() + "]," + name + "_sigma_cb_pf[" + sigmacb.str().c_str() + "],"
            + name + "_alpha_pf[" + alpha.str().c_str() + "]," + name + "_n_pf[" + n.str().c_str() + "])");
    w->var(name + "_mean_cb_pf")->setConstant(kTRUE);
    w->var(name + "_sigma_cb_pf")->setConstant(kTRUE);
    w->var(name + "_alpha_pf")->setConstant(kTRUE);
    w->var(name + "_n_pf")->setConstant(kTRUE);

    w->factory("FFTConvPdf::" + name + "_bwxCryBall_dimu(eventSelectionamassMu," + name + "_gauss_bw_dimu," + name + "_cball_dimu)");

    w->factory("SUM::" + name + "_sum_dimu(" + name + "_signal_bw_pf[" + bwRatio.str().c_str() + ",0, 1]*" + name + "_bwxCryBall_dimu,"
            + name + "_b_pf[" + bRatio.str().c_str() + ",0,1]*" + name + "_bkg_dimu)");

    TFile* f = new TFile("DoubleMu2012_Summer12_final_" + pf + ".root", "READ");
    TTree* hh = (TTree*) f->Get("rds_zbb");
    RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
    w->import(data);

    TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-" + Mass + "_Summer12_final_" + pf + ".root", "read");
    TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
    w->import(sigData);
    w->factory("KeysPdf::" + name + "_sigPdf_dimu(eventSelectionamassMu,sigData_dimu)");
    w->factory(name + "_sum_dimu_norm[" + nBkg.str().c_str() + "]");
    w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
    w->writeToFile(fname);
    //w->var("eventSelectionamassMu")->setBins(55);
    cardMaker(Mass, bkgUnc);

}
