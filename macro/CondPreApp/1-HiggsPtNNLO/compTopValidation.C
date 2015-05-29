#include <iomanip>
#include <iostream>
const bool savePDF = false;
const bool saveEPS = false;
const bool saveGIF = true;
const bool savePNG = false;
const bool saveC   = false;

void compTopValidation()
{
   gROOT->SetStyle("Plain");
   gStyle->SetOptStat(1);
   
   bool log = true;
   DrawMine(log, "30");		
   DrawMine(log, "40");		
   DrawMine(log, "50");		
   DrawMine(log, "60");		
}

void DrawMine(bool yLogScale, TString Mass,int rebin=1){
   TCanvas *canvas= new TCanvas("canvas","canvas",10,10,800,600);
   canvas->Print("figs/plotsPtRW_"+ Mass +".ps[");    
   TFile f_old("rdsM"+Mass+".root");
   TFile f_new("hPtRw_rdsM"+Mass+".root");   
   TH1* h_old = (TH1*) f_old.Get("amassMu");
   TH1* h_new = (TH1*) f_new.Get("amassMu");	
   std::cout<<h_new->Integral()/h_old->Integral()<<endl;
   h_old->GetXaxis()->SetRangeUser(20.,70.);
   h_new->GetXaxis()->SetRangeUser(20.,70.);



   TLegend *tleg = new TLegend(0.35,0.75,0.5,0.89);
   tleg->SetTextSize(0.045);
   tleg->SetBorderSize(0);
   tleg->SetFillColor(10);
   tleg->AddEntry(h_new, "Reweighted" , "lp");
   tleg->AddEntry(h_old, "Original" , "le");


   double max = -999.;
   if( h_old->GetMaximum()>h_new->GetMaximum() ) max = h_old->GetMaximum();
   else                                          max = h_new->GetMaximum();
   h_old->SetMaximum(max*1.3);


   h_old->SetLineColor(kBlue);
   h_old->SetLineWidth(3);
   if(h_new->Integral() != 0 && h_old->Integral() != 0 && !(TString(h_old->GetName()).Contains("res")))
	h_old->DrawNormalized("eh");
   else 
	h_old->Draw("eh");     

   h_new->SetMarkerStyle(23);
   h_new->SetMarkerSize(2);
   h_new->SetLineWidth(3);
   h_new->SetLineColor(kRed);
   if(h_new->Integral() != 0 && h_old->Integral() != 0 && !(TString(h_old->GetName()).Contains("res")))
	h_new->DrawNormalized("esames");
   else 
	h_new->Draw("esames");   	

   gPad->Update();
   TPaveStats* stats1 = (TPaveStats*)gPad->GetPrimitive("stats");
   Double_t coords[4];
   coords[0] = stats1->GetX1NDC();
   coords[1] = stats1->GetX2NDC();
   coords[2] = stats1->GetY1NDC();
   coords[3] = stats1->GetY2NDC();
   stats1->SetTextColor(kRed);
   stats1->Draw();
   gPad->Update();

   TPaveStats* stats2 =(TPaveStats*)gPad->GetPrimitive("stats");  
   stats2->SetX1NDC(coords[0]);
   stats2->SetX2NDC(coords[1]);
   stats2->SetY1NDC(2 * coords[2] - coords[3]);
   stats2->SetY2NDC(coords[2]);
   stats2->SetTextColor(kBlue);
   stats2->Draw();

   
   tleg->Draw("same");

   TLatex* text_norm = new TLatex(0.92, 0.43, "Normalized to Unity");
   text_norm->SetTextAngle(270);  
   text_norm->SetNDC(true);
   text_norm->SetTextFont(42);
   text_norm->SetTextSize(0.04); 
   
   if   (yLogScale )
   	canvas->SetLogy(1);
   else
    canvas->SetLogy(0);
    
	if(h_old->GetXaxis()->GetXmax() == 1000. && fabs(h_new->GetMean()) < 50){
		canvas->SetLogx(1);
   } else {
   		canvas->SetLogx(0);
   }
   canvas->Print("figs/plotsPtRW_"+ Mass+ ".ps");	
   
   if(savePDF) canvas->SaveAs("figs/plotsPtRW_" + Mass + ".pdf");
   if(saveEPS) canvas->SaveAs("figs/plotsPtRW_" + Mass + ".eps");
   if(saveGIF) {
     if(yLogScale)
       canvas->SaveAs("figs/plotsPtRW_" + Mass + "_log.gif");
     else
       canvas->SaveAs("figs/plotsPtRW_" + Mass + ".gif");
   }
   if(savePNG) canvas->SaveAs("figs/plotsPtRW_" + Mass + ".png");
   if(saveC)   canvas->Print("figs/plotsPtRW_" + Mass + ".C"); 
}

  
