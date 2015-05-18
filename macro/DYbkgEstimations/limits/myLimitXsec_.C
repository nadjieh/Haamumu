{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Nov 30 01:27:32 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "#Delta m(a,a)",506,106,500,500);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(0,0,1,1);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetTickx(1);
   c1_n2->SetTicky(1);
   c1_n2->SetLeftMargin(0.16);
   c1_n2->SetRightMargin(0.02);
   c1_n2->SetTopMargin(0.05);
   c1_n2->SetBottomMargin(0.13);
   c1_n2->SetFrameFillStyle(0);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");
   grae->SetFillColor(3);
   grae->SetPoint(0,40,31.21875);
   grae->SetPointError(0,0,0,22.92627,35.22847);
   grae->SetPoint(1,50,20.15625);
   grae->SetPointError(1,0,0,9.48761,18.78253);
   grae->SetPoint(2,60,19.40625);
   grae->SetPointError(2,0,0,11.71198,20.91614);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","",100,38,62);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(100);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a} (GeV)");
   Graph_g21->GetXaxis()->SetRange(9,92);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.035);
   Graph_g21->GetXaxis()->SetTitleFont(42);
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
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("");
   grae->SetFillColor(5);
   grae->SetPoint(0,39.97069,31.27637);
   grae->SetPointError(0,0,0,12.44825,16.05267);
   grae->SetPoint(1,50,20.20042);
   grae->SetPointError(1,0,0,5.892694,8.436087);
   grae->SetPoint(2,59.9931,19.40928);
   grae->SetPointError(2,0,0,6.908235,9.514561);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","",100,38,62);
   Graph_g12->SetMinimum(9.020674);
   Graph_g12->SetMaximum(50.74876);
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
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetMarkerColor(4);
   grae->SetPoint(0,40,31.21875);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,19.93671);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,19.40625);
   grae->SetPointError(2,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,38,62);
   Graph_g003->SetMinimum(18.225);
   Graph_g003->SetMaximum(32.4);
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
   
   grae->Draw("PL");
   
   TPaveText *pt = new TPaveText(0.6106322,0.742616,0.8477011,0.7848101,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 2 #sigma");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.5402299,0.6434599,0.8793103,0.8818565,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Expected 95%","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected 68%","lpf");
   entry->SetFillColor(5);
   entry->SetFillStyle(1001);
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
