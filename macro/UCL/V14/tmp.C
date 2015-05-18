//////////////////////////////////////////////////////////////////////////
//
// 'SPECIAL PDFS' RooFit tutorial macro #706
// 
// Histogram based p.d.f.s and functions
//
//
//
// 07/2008 - Wouter Verkerke 
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooPolynomial.h"
#include "RooHistPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit ;


void tmp()
{
  // C r e a t e   p d f   f o r   s a m p l i n g 
  // ---------------------------------------------

  RooRealVar x("x","x",0,20) ;
  RooPolynomial p("p","p",x,RooArgList(RooConst(0.01),RooConst(-0.01),RooConst(0.0004))) ;



  // C r e a t e   l o w   s t a t s   h i s t o g r a m
  // ---------------------------------------------------

  // Sample 500 events from p
  x.setBins(20) ;
  RooDataSet* data1 = p.generate(x,500) ;
  
  // Create a binned dataset with 20 bins and 500 events
  RooDataHist* hist1 = data1->binnedClone() ;

  // Represent data in dh as pdf in x
  RooHistPdf histpdf1("histpdf1","histpdf1",x,*hist1,0) ;

  // Plot unbinned data and histogram pdf overlaid
  RooPlot* frame1 = x.frame(Title("Low statistics histogram pdf"),Bins(100)) ;
  data1->plotOn(frame1) ;
  histpdf1.plotOn(frame1) ;  
  

 


  TCanvas* c = new TCanvas("rf706_histpdf","rf706_histpdf",800,400) ;  
  c->Divide(2) ;
  c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame1->GetYaxis()->SetTitleOffset(1.4) ; frame1->Draw() ;
 // c->cd(2) ; gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitleOffset(1.8) ; frame2->Draw() ;


}
