{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Nov 16 22:27:59 2014) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",351,79,700,502);
   c1_n2->Range(35,-2.644541,65,31.09472);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");
   grae->SetFillColor(3);
   grae->SetPoint(0,40,15.84375);
   grae->SetPointError(0,0,0,6.281799,9.627757);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,2.703049,5.684751);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,2.669769,5.737521);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Expected 2 #sigma",100,38,62);
   Graph_g21->SetMinimum(0.7293852);
   Graph_g21->SetMaximum(27.72079);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a_{1}} (GeV)");
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.05);
   Graph_g21->GetXaxis()->SetTitleOffset(0.8);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetTitle("#sigma (gg#rightarrowh) #times Br(h#rightarrow2a_{1}#rightarrow 2b 2#mu) @ 95% CL ( fb^{-1} )");
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(3);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");
   grae->SetFillColor(5);
   grae->SetPoint(0,40,15.84375);
   grae->SetPointError(0,0,0,3.778895,3.978693);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,1.678847,2.519895);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,1.658177,2.544185);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Expected 1 #sigma",100,38,62);
   Graph_g12->SetMinimum(2.407043);
   Graph_g12->SetMaximum(21.40566);
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
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,40,16.00458);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,50,5.695312);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,60,5.648438);
   grae->SetPointError(2,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,38,62);
   Graph_g003->SetMinimum(4.628907);
   Graph_g003->SetMaximum(16.86328);
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
   
   TPaveText *pt = new TPaveText(0.3808046,0.9342405,0.6191954,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 2 #sigma");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.579023,0.5801688,0.8793103,0.8818565,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Expected 2 #sigma","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected 1 #sigma","lpf");
   entry->SetFillColor(5);
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
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
