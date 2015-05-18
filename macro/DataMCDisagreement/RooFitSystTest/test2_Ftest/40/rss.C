{
//=========Macro generated from canvas: c1_n21/c1_n21
//=========  (Wed Feb 18 14:21:27 2015) by ROOT version5.34/19
   TCanvas *c1_n21 = new TCanvas("c1_n21", "c1_n21",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n21->SetHighLightColor(2);
   c1_n21->Range(0,0,1,1);
   c1_n21->SetFillColor(0);
   c1_n21->SetBorderMode(0);
   c1_n21->SetBorderSize(2);
   c1_n21->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetPoint(0,2300.5,1959.567839);
   graph->SetPoint(1,1959.568055,1667.336014);
   graph->SetPoint(2,1667.012979,11085.45234);
   graph->SetPoint(3,11081.57764,23891.06426);
   graph->SetPoint(4,23902.6114,7504.119195);
   graph->SetPoint(5,7148.168597,2991.416559);
   graph->SetPoint(6,3020.73996,4638.423768);
   graph->Draw("ap");
   c1_n21->Modified();
   c1_n21->cd();
   c1_n21->SetSelected(c1_n21);
}
