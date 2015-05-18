int Test(){
    using namespace RooFit;
    using namespace std;
    RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu", 20, 70);
    TFile * input = TFile::Open("DoubleMu2012_Summer12_final_CR_4_4.root");
    TTree * tree = (TTree*) input->Get("rds_zbb");
    RooDataSet * data = new RooDataSet("ControlData", "The original control data", tree, eventSelectionamassMu, "");
    TH1D * hdata = (TH1D*)data->createHistogram("hdata", eventSelectionamassMu, RooFit::Binning(50));
    RooDataHist datahist("datahist", "datahist", eventSelectionamassMu, hdata);
    RooRealVar * p2 = new RooRealVar("p2","",-10,10);
    RooRealVar  p3("p3","",-10,10); 
    RooRealVar  p1("p1","",-10,10);     
    RooRealVar  n("n","",0.,(2*tree->GetEntries()));           
    RooPolynomial  * pol1 = new RooPolynomial("pol1","",eventSelectionamassMu,RooArgList(*p2));
    RooGenericPdf * gen1 = new RooGenericPdf("gen1","","p3*eventSelectionamassMu",RooArgList(p3,eventSelectionamassMu));
    RooExtendPdf * genext1 = new RooExtendPdf("genext1","",*gen1, n);
	RooFormulaVar func("func","p1+p3*eventSelectionamassMu",RooArgSet(p1,p3,eventSelectionamassMu)) ;
    
    pol1->fitTo(datahist);
    genext1->fitTo(datahist);    
    //func.chi2FitTo(datahist);
    RooPlot * plot = eventSelectionamassMu.frame();
    datahist.plotOn(plot);
    pol1->plotOn(plot);
    genext1->plotOn(plot, LineColor(kRed));
	//func.plotOn(plot, LineColor(kRed));            
    plot->Draw();
}
