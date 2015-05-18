{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Fri Jan 23 15:19:12 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",385,24,700,502);
   c1_n2->Range(26.1,-12.5,63.9,112.5);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 95%");
   grae->SetFillColor(3);
   grae->SetLineColor(3);  
   grae->SetMarkerColor(3);    
   grae->SetPoint(0,30,12.51562);
   grae->SetPointError(0,0,0,6.67337,18.91138);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,8.083557,22.5663);
   grae->SetPoint(2,50,16.26562);
   grae->SetPointError(2,0,0,8.132812,22.74864);
   grae->SetPoint(3,60,11.85938);
   grae->SetPointError(3,0,0,6.323456,17.8677);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Expected 2 #sigma",100,27,63);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(100);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a1} (GeV)");
   Graph_g21->GetXaxis()->SetRange(9,92);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.035);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetTitle("#sigma(gg#rightarrowH)#timesBr(H#rightarrowa1a1#rightarrow#mu#mubb)");
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleSize(0.035);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 68%");
   grae->SetFillColor(5);
   grae->SetLineColor(5);   
   grae->SetMarkerColor(5);
   grae->SetPoint(0,30,12.51562);
   grae->SetPointError(0,0,0,4.24906,7.483173);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,5.146952,8.878349);
   grae->SetPoint(2,50,16.26562);
   grae->SetPointError(2,0,0,5.210083,8.882461);
   grae->SetPoint(3,60,11.85938);
   grae->SetPointError(3,0,0,4.026263,6.948981);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Expected 1 #sigma",100,27,63);
   Graph_g12->SetMinimum(6.101621);
   Graph_g12->SetMaximum(26.87958);
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
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,12.51562);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,39.94914,15.98101);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,16.26562);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,11.85938);
   grae->SetPointError(3,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,27,63);
   Graph_g003->SetMinimum(11.41876);
   Graph_g003->SetMaximum(16.70624);
   Graph_g003->SetDirectory(0);
   Graph_g003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g003->SetLineColor(ci);
   Graph_g003->GetXaxis()->SetLabelFont(42);
   Graph_g003->GetXaxis()->SetLabelSize(0.035);
   Graph_g003->GetXaxis()->SetTitleSize(0.035);
   Graph_g003->GetXaxis()->SetTitleFont(42);
   Graph_g003->GetYaxis()->SetLabelFont(42);
   Graph_g003->GetYaxis()->SetLabelSize(0.035);
   Graph_g003->GetYaxis()->SetTitleSize(0.035);
   Graph_g003->GetYaxis()->SetTitleFont(42);
   Graph_g003->GetZaxis()->SetLabelFont(42);
   Graph_g003->GetZaxis()->SetLabelSize(0.035);
   Graph_g003->GetZaxis()->SetTitleSize(0.035);
   Graph_g003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g003);
   
   grae->Draw("PC");
   
   TPaveText *pt = new TPaveText(0.466954,0.7067511,0.704023,0.7679325,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 2 #sigma");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.4109195,0.5548523,0.8218391,0.8164557,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("g2","Expected 95%","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("g1","Expected 68%","lpf");
   entry->SetFillColor(5);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
