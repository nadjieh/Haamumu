#include <sstream>

void mytest(int seed = 37) {
    using namespace RooFit;
    using namespace std;
    stringstream nSig;
    nSig << 3.44;
    /////////// Data fit ////////////////
    TString fname = "hamb-shapes-UnbinnedParam-m60-Data-fit.root";
    stringstream lambda;
    lambda << -0.164329;
    stringstream alpha;
    alpha << 1.18847;
    stringstream n;
    n << 0.855308;
    stringstream meanbw;
    meanbw << 90.8576;
    stringstream sigmabw;
    sigmabw << 1;
    stringstream meancb;
    meancb << 0.361541;
    stringstream sigmacb;
    sigmacb << 1.73297;
    stringstream nBkg;
    nBkg << 295.1;
    ///////////////////////////////////

    /////////// MC fit ////////////////
    //    TString fname = "hamb-shapes-UnbinnedParam-m60-MC-fit.root";
    //    stringstream lambda;
    //    lambda << -0.144432;
    //    stringstream alpha;
    //    alpha << 1.50862;
    //    stringstream n;
    //    n << 0.495336;
    //    stringstream meanbw;
    //    meanbw << 90.8219;
    //    stringstream sigmabw;
    //    sigmabw << 1;
    //    stringstream meancb;
    //    meancb << 0.238761;
    //    stringstream sigmacb;
    //    sigmacb << 1.92614;
    //    stringstream nBkg;
    //    nBkg << 383.4;
    ///////////////////////////////////


    TString name = "test";
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 50., 70);
    //    eventSelectionamassMu.setRange("SM", 50, 70);
    TFile* ftop = new TFile("TTFullLept_Summer12_final_8_8.root", "READ");
    TTree* htop = (TTree*) ftop->Get("rds_zbb");
    RooDataSet topData("topData", "topData", htop, eventSelectionamassMu, "");
    RooRandom::randomGenerator()->SetSeed(seed);
    RooWorkspace *w = new RooWorkspace("w", "w");
    w->factory("eventSelectionamassMu[50,70]"/*,Range(SM, 50,70)"*/);
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

    w->factory("SUM::" + name + "_sum_dimu(" + name + "_signal_bw_pf[0.956,0, 1]*" + name + "_bwxCryBall_dimu,"
            + name + "_b_pf[0.044,0,1]*" + name + "_bkg_dimu)");

    if (fname == "hamb-shapes-UnbinnedParam-m60-MC-fit.root") {
        TFile* f = new TFile("mcMass.root", "READ");
        TH1D* hh = (TH1D*) f->Get("mcMass");
        RooDataHist data("data_dimu", "data", RooArgList(eventSelectionamassMu), hh);
        w->import(data);
    } else if (fname == "hamb-shapes-UnbinnedParam-m60-Data-fit.root") {
        TFile* f = new TFile("DoubleMu2012_Summer12_final_8_8.root", "READ");
        TTree* hh = (TTree*) f->Get("rds_zbb");
        RooDataSet data("data_dimu", "data", hh, eventSelectionamassMu, "");
        w->import(data);
    }

    TFile * fsig = new TFile("H2ToH1H1_H1To2Mu2B_mH2-125_mH1-60_Summer12_final_0_0.root", "read");
    TTree* hsig = (TTree*) fsig->Get("rds_zbb");
    RooDataSet sigData("sigData_dimu", "sigData", hsig, eventSelectionamassMu, "");
    w->import(sigData);
    w->factory("KeysPdf::" + name + "_sigPdf_dimu(eventSelectionamassMu,sigData_dimu)");
    w->factory(name + "_sum_dimu_norm[" + nBkg.str().c_str() + "]");
    w->factory(name + "_sigPdf_dimu_norm[" + nSig.str().c_str() + "]");
    w->writeToFile(fname);
    //w->var("eventSelectionamassMu")->setBins(55);

}
