{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Feb 18 14:21:27 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetPoint(0,0.5,8.351200391);
   graph->SetPoint(1,1.5,8.237635269);
   graph->SetPoint(2,2.5,-39.08259197);
   graph->SetPoint(3,3.5,-24.12730098);
   graph->SetPoint(4,4.5,96.15167862);
   graph->SetPoint(5,5.5,59.75106912);
   graph->SetPoint(6,6.5,-14.64780351);
   graph->Draw("ap");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
