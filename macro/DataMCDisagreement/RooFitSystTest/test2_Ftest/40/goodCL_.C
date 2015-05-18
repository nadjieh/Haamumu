{
//=========Macro generated from canvas: c1_n9/c1_n9
//=========  (Fri Feb 13 10:35:19 2015) by ROOT version5.34/19
   TCanvas *c1_n9 = new TCanvas("c1_n9", "c1_n9",3,24,700,502);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n9->SetHighLightColor(2);
   c1_n9->Range(-0.8868926,-13.45989,7.982033,1.542756);
   c1_n9->SetFillColor(0);
   c1_n9->SetBorderMode(0);
   c1_n9->SetBorderSize(2);
   c1_n9->SetLogy();
   c1_n9->SetFrameBorderMode(0);
   c1_n9->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,0.5,0.005770484891);
   graph->SetPoint(1,1.495993956,0.006425685461);
   graph->SetPoint(2,2.5,1);
   graph->SetPoint(3,3.5,1);
   graph->SetPoint(4,4.5,1.219357948e-12);
   graph->SetPoint(5,5.5,1.147803741e-09);
   graph->SetPoint(6,6.49558194,1.002531652);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,7.09514);
   Graph_Graph01->SetMinimum(1.097422e-12);
   Graph_Graph01->SetMaximum(1.102785);
   Graph_Graph01->SetDirectory(0);
   Graph_Graph01->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01->SetLineColor(ci);
   Graph_Graph01->GetXaxis()->SetTitle("Degree of polynom (n, n+1)");
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   Graph_Graph01->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleOffset(0.91);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle("good CL (1 - FTestI)");
   Graph_Graph01->GetYaxis()->SetLabelFont(42);
   Graph_Graph01->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph01);
   
   graph->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.4397126,0.9342405,0.5602874,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Graph");
   pt->Draw();
   c1_n9->Modified();
   c1_n9->cd();
   c1_n9->SetSelected(c1_n9);
}
