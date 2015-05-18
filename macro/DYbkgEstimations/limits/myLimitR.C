{
//=========Macro generated from canvas: c1/#Delta m(a,a)
//=========  (Sun Nov 30 13:59:48 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "#Delta m(a,a)",509,130,500,502);
   c1->SetHighLightColor(2);
   c1->Range(35.98634,-30.12195,60.57171,201.5854);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.16);
   c1->SetRightMargin(0.02);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("");
   grae->SetFillColor(3);
   grae->SetFillStyle(3021);
   grae->SetPoint(0,40,30.625);
   grae->SetPointError(0,0,0,15.37231,42.83125);
   grae->SetPoint(1,50,33.8125);
   grae->SetPointError(1,0,0,16.70813,45.66081);
   grae->SetPoint(2,60,33.375);
   grae->SetPointError(2,0,0,16.36157,44.03068);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","",100,38,62);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(190);
   Graph_g21->SetDirectory(0);
      Graph_g21->GetXaxis()->SetRangeUser(40.01,59.99);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a1} (GeV)");
   Graph_g21->GetXaxis()->SetRange(9,92);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.05);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetTitle("Signal strength, #it{r} ");
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleSize(0.07);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("");
   grae->SetFillColor(5);
   grae->SetFillStyle(3014);
   grae->SetPoint(0,40,30.625);
   grae->SetPointError(0,0,0,9.787842,16.72394);
   grae->SetPoint(1,50,33.8125);
   grae->SetPointError(1,0,0,10.57311,17.92548);
   grae->SetPoint(2,60,33.375);
   grae->SetPointError(2,0,0,10.41772,17.16141);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","",100,38,62);
   Graph_g12->SetMinimum(17.74708);
   Graph_g12->SetMaximum(54.82806);
   Graph_g12->SetDirectory(0);
   Graph_g12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g12->SetLineColor(ci);
   Graph_g12->GetXaxis()->SetLabelFont(42);
   Graph_g12->GetXaxis()->SetLabelSize(0.035);
   Graph_g12->GetXaxis()->SetTitleSize(0.035);
   Graph_g12->GetXaxis()->SetTitleFont(42);
   Graph_g12->GetYaxis()->SetLabelFont(42);
   Graph_g12->GetYaxis()->SetLabelSize(0.035);
   Graph_g12->GetYaxis()->SetTitleSize(0.035);
   Graph_g12->GetYaxis()->SetTitleFont(42);
   Graph_g12->GetZaxis()->SetLabelFont(42);
   Graph_g12->GetZaxis()->SetLabelSize(0.035);
   Graph_g12->GetZaxis()->SetTitleSize(0.035);
   Graph_g12->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g12);
   
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g0");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,40,30.625);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50.01388,32.4488);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,33.375);
   grae->SetPointError(2,0,0,0,0);
   
   TH1F *Graph_g03 = new TH1F("Graph_g03","",100,38,62);
   Graph_g03->SetMinimum(30.30625);
   Graph_g03->SetMaximum(34.13125);
   Graph_g03->SetDirectory(0);
   Graph_g03->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g03->SetLineColor(ci);
   Graph_g03->GetXaxis()->SetLabelFont(42);
   Graph_g03->GetXaxis()->SetLabelSize(0.035);
   Graph_g03->GetXaxis()->SetTitleSize(0.035);
   Graph_g03->GetXaxis()->SetTitleFont(42);
   Graph_g03->GetYaxis()->SetLabelFont(42);
   Graph_g03->GetYaxis()->SetLabelSize(0.035);
   Graph_g03->GetYaxis()->SetTitleSize(0.035);
   Graph_g03->GetYaxis()->SetTitleFont(42);
   Graph_g03->GetZaxis()->SetLabelFont(42);
   Graph_g03->GetZaxis()->SetLabelSize(0.035);
   Graph_g03->GetZaxis()->SetTitleSize(0.035);
   Graph_g03->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g03);
   
   grae->Draw("PL");
   
   TLegend *leg = new TLegend(0.5402299,0.6434599,0.8793103,0.8818565,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Expected 95%","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(3021);
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected 68%","lpf");
   entry->SetFillColor(5);
   entry->SetFillStyle(3014);
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
