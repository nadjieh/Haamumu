{
//=========Macro generated from canvas: c1_n20/c1_n20
//=========  (Wed Feb 18 14:21:27 2015) by ROOT version5.34/19
   TCanvas *c1_n20 = new TCanvas("c1_n20", "c1_n20",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n20->SetHighLightColor(2);
   c1_n20->Range(0,0,1,1);
   c1_n20->SetFillColor(0);
   c1_n20->SetBorderMode(0);
   c1_n20->SetBorderSize(2);
   c1_n20->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetPoint(0,0.5,0.005770484891);
   graph->SetPoint(1,1.5,0.006131900127);
   graph->SetPoint(2,2.5,1);
   graph->SetPoint(3,3.5,1);
   graph->SetPoint(4,4.5,1.219357948e-12);
   graph->SetPoint(5,5.5,1.147803741e-09);
   graph->SetPoint(6,6.5,1);
   graph->Draw("ap");
   c1_n20->Modified();
   c1_n20->cd();
   c1_n20->SetSelected(c1_n20);
}
