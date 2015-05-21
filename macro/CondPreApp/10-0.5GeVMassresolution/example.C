int example(){
RooRealVar mass("mass", "mass", 20, 70);
    RooFormulaVar sigma_cb("sigma_cb", "-0.4756193+0.04638364*mass -0.0004420156*(mass^2) -7.566989e-07*(mass^3) -1.041907e-08*(mass^4) +8.410242e-10*(mass^5)"
            , RooArgList(mass));
    RooRealVar mean("mean", "mean", 30.);
    RooFormulaVar sigma("sigma", "(0.010226*mass)-0.0215593", RooArgList(mass));
    //    RooRealVar sigma("sigma", "sigma", 0.285);
    RooRealVar width("width", "width", 0.033);
    RooVoigtian Voig("tmp", "", mass, mean, width, sigma);
    RooRealVar n("n", "", 3.12);
    RooRealVar alpha("alpha", "", 1.09);
    RooCBShape CB("cball", "crystal ball", mass, mean, sigma_cb, alpha, n);
    RooRealVar frac("frac", "frac", 0.612);
    RooAddPdf Voig2("sum", "Gaussian crystal ball and Voig PDF", RooArgList(Voig, CB), RooArgList(frac));

    RooDataSet * D = Voig2.generate(mass, 6000);
    
    RooFormulaVar mean_("mean_", "@0", RooArgList(mass));    
    RooRealVar width_("width_", "width", 0.033);
    RooVoigtian Voig_("tmp_", "", mass, mean_, width_, sigma);    
    RooRealVar n_("n_", "", 3.12);  
    RooRealVar alpha_("alpha_", "", 1.09);   
    RooCBShape CB_("cball_", "crystal ball", mass, mean_, sigma_cb, alpha_, n_);       
    RooRealVar frac_("frac_", "frac", 0.612);    
    RooAddPdf Voig2_("sum_", "Gaussian crystal ball and Voig PDF", RooArgList(Voig_, CB_), RooArgList(frac_));    
    Voig2_.fitTo(*D, RooFit::Save());

    RooPlot * p = mass.frame(RooFit::Title(""));
    D->plotOn(p);
    Voig2_.plotOn(p, RooFit::LineColor(kBlack));
    Voig2_.plotOn(p, RooFit::Components(Voig_), RooFit::LineColor(kBlue));
    Voig2_.plotOn(p, RooFit::Components(CB_), RooFit::LineColor(kRed));

	p->Draw();
}
