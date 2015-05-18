RooRealVar * mass = w->var("eventSelectionamassMu");
RooAbsPdf *bkg = w->pdf("test_bkg_dimu");
RooAbsData *data = w->data("data_dimu");
RooPlot *plot =  mass->frame();
data->plotOn(plot)
bkg->plotOn(plot)
TCanvas c("c","c")
plot->Draw()
RooAbsData *databkg = w->data("bkgData");
RooPlot *plot2 =  mass->frame();
databkg->plotOn(plot2)
bkg->plotOn(plot2)
TCanvas c1("c1","c1")
plot2->Draw()

