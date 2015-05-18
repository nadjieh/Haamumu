
void test(){
    using namespace RooFit;
    using namespace std;
RooRealVar eventSelectionamassMu("eventSelectionamassMu", "eventSelectionamassMu",20,70);
TFile* fbkg = new TFile("DoubleMu2012_Summer12_final_CR_4_4.root", "READ");
TTree* hbkg = (TTree*) fbkg->Get("rds_zbb");
RooDataSet bkgData("bkgData", "bkgData", hbkg, eventSelectionamassMu, "");
TH1D * hBKG = bkgData.createHistogram("bkgData",eventSelectionamassMu,RooFit::Binning(100));
hBKG->SetBinContent(25, hBKG->GetBinContent(25)+hBKG->GetBinError(25));
RooDataHist mydata("mydata","mydata",eventSelectionamassMu, hBKG);
RooHistPdf mypdf("mypdf","mypdf",eventSelectionamassMu, mydata);
RooDataSet * newdata = mypdf.generate(eventSelectionamassMu,hbkg->GetEntriesFast());
RooKeysPdf orig("orig","orig", eventSelectionamassMu, bkgData);
RooKeysPdf changed("changed","changed", eventSelectionamassMu, *newdata);
RooPlot* p3 = eventSelectionamassMu.frame();
changed.plotOn(p3, RooFit::LineColor(kBlue));
orig.plotOn(p3, RooFit::LineColor(kRed));
p3->Draw();
}
