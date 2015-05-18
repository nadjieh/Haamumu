{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Feb 13 10:19:46 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",249,46,700,502);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(-0.8875001,-72.89116,7.9875,129.9602);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,0.4896551268,8.420585058);
   graph->SetPoint(1,1.5,8.237635269);
   graph->SetPoint(2,2.491630731,-39.9385061);
   graph->SetPoint(3,3.5,-24.12730098);
   graph->SetPoint(4,4.5,96.15167862);
   graph->SetPoint(5,5.5,59.75106912);
   graph->SetPoint(6,6.5,-14.64780351);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,7.1);
   Graph_Graph01->SetMinimum(-52.60602);
   Graph_Graph01->SetMaximum(109.6751);
   Graph_Graph01->SetDirectory(0);
   Graph_Graph01->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01->SetLineColor(ci);
   Graph_Graph01->GetXaxis()->SetTitle("Degree of the polynom (n, n+1)");
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   Graph_Graph01->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleOffset(0.89);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle("F-test value");
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
   
   TPaveText *pt = new TPaveText(0.4403736,0.9345992,0.5596264,0.9957806,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Graph");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
