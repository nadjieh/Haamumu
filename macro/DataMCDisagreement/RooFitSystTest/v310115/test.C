#include <iostream>

void test(){
	using namespace RooFit;
	using namespace std;	
	RooRealVar x ("x","x", 20.,70.);
	/*RooRealVar mean ("mean","mean", 40.);	
	RooRealVar width ("width","width", 5.);	
	RooGaussian gauss("mygauss","original",x, mean, width);*/
	
	RooRealVar a0("a0","a0",0.5) ;
    RooRealVar a1("a1","a1",2.5) ;
    RooRealVar a2("a2","a2",1) ;
    RooRealVar a3("a3","a3",4) ;    
    RooRealVar a4("a4","a4",3.5) ;        
    //RooPolynomial gauss("p3","original",x,RooArgList(a0,a1,a2,a3,a4),0) ;
    RooGenericPdf gauss("gp","original","x*(2+sin(x*a0))",RooArgSet(x,a0)) ; 
	
	RooRandom::randomGenerator()->SetSeed(38);
	RooDataSet * pd = gauss.generate(x,1500);
	RooKeysPdf keypdf1("keypdf1", "nominal (1)", x, *pd, RooKeysPdf::MirrorBoth, 1);
	RooKeysPdf keypdf2("keypdf2", "up (2)", x, *pd, RooKeysPdf::MirrorBoth, 2);	
	RooKeysPdf keypdf05("keypdf05", "down (0.5)", x, *pd, RooKeysPdf::MirrorBoth, 0.5);	
	RooKeysPdf keypdf3("keypdf3", "up (3)", x, *pd, RooKeysPdf::MirrorBoth, 3);	
	RooKeysPdf keypdf03("keypdf03", "down (0.3)", x, *pd, RooKeysPdf::MirrorBoth, 0.3);		
	RooKeysPdf keypdf4("keypdf4", "up (4)", x, *pd, RooKeysPdf::MirrorBoth, 4);	
	RooKeysPdf keypdf02("keypdf02", "down (0.2)", x, *pd, RooKeysPdf::MirrorBoth, 0.2);		
	
	RooPlot * p0 = x.frame();
	pd->plotOn(p0, RooFit::MarkerStyle(24));	
	gauss.plotOn(p0, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));	
		
	RooPlot * p1 = x.frame();
	pd->plotOn(p1, RooFit::MarkerStyle(24));
	keypdf1.plotOn(p1, RooFit::LineColor(kRed));
	keypdf2.plotOn(p1, RooFit::LineColor(kGreen));	
	keypdf05.plotOn(p1, RooFit::LineColor(kCyan));	
			
	RooPlot * p2 = x.frame();
	pd->plotOn(p2, RooFit::MarkerStyle(24));
	keypdf1.plotOn(p2, RooFit::LineColor(kRed));
	keypdf3.plotOn(p2, RooFit::LineColor(kGreen));	
	keypdf03.plotOn(p2, RooFit::LineColor(kCyan));	
		
	RooPlot * p3 = x.frame();
	pd->plotOn(p3, RooFit::MarkerStyle(24));
	keypdf1.plotOn(p3, RooFit::LineColor(kRed));
	keypdf4.plotOn(p3, RooFit::LineColor(kGreen));	
	keypdf02.plotOn(p3, RooFit::LineColor(kCyan));

	TCanvas Canv;
	Canv.Divide(2,2);
	Canv.cd(1);
	p0->Draw();
	Canv.cd(2);
	p1->Draw();	
	Canv.cd(3);
	p2->Draw();
	Canv.cd(4);
	p3->Draw();		
	Canv.SaveAs("fig.C");
	
	RooPlot * p5 = x.frame();
	pd->plotOn(p5, RooFit::MarkerStyle(24));	
	gauss.plotOn(p5, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));	
		
	RooPlot * p6 = x.frame();
	pd->plotOn(p6, RooFit::MarkerStyle(24));
	keypdf2.plotOn(p6, RooFit::LineColor(kGreen));	
	keypdf05.plotOn(p6, RooFit::LineColor(kCyan));	
	gauss.plotOn(p6, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));	
			
	RooPlot * p7 = x.frame();
	pd->plotOn(p7, RooFit::MarkerStyle(24));
	keypdf3.plotOn(p7, RooFit::LineColor(kGreen));	
	keypdf03.plotOn(p7, RooFit::LineColor(kCyan));	
	gauss.plotOn(p7, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));		
		
	RooPlot * p8 = x.frame();
	pd->plotOn(p8, RooFit::MarkerStyle(24));
	keypdf4.plotOn(p8, RooFit::LineColor(kGreen));	
	keypdf02.plotOn(p8, RooFit::LineColor(kCyan));
	gauss.plotOn(p8, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));		

	TCanvas Canv2;
	Canv2.Divide(2,2);
	Canv2.cd(1);
	p5->Draw();
	Canv2.cd(2);
	p6->Draw();	
	Canv2.cd(3);
	p7->Draw();
	Canv2.cd(4);
	p8->Draw();	
	
	Canv2.SaveAs("fig2.C");

	RooPlot * p9 = x.frame();
	pd->plotOn(p9, RooFit::MarkerStyle(24));	
	keypdf1.plotOn(p9, RooFit::LineColor(kRed));	
	gauss.plotOn(p9, RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));		
	TCanvas Canv3;	
	p9->Draw();
	Canv3.SaveAs("fig3.C");	
	
}
