{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sun Jan 25 16:07:59 2015) by ROOT version5.34/19
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
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,6.623383,18.76972);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,8.083557,22.5663);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,8.00766,22.54148);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,6.525238,18.25606);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Expected 95%",100,27,63);
   Graph_g21->SetMinimum(2.516387);
   Graph_g21->SetMaximum(41.90171);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a1} (GeV)");   
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.035);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetTitle("#sigma(gg#rightarrowH)#timesBr(H#rightarrowa1a1#rightarrow#mu#mubb)");   
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
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,4.217232,7.427118);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,5.146952,8.878349);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,5.098628,8.908244);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,4.205719,7.125363);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Expected 1 #sigma",100,27,63);
   Graph_g12->SetMinimum(6.436005);
   Graph_g12->SetMaximum(26.67276);
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
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,12.42188);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,15.79688);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,16.07812);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,12.32812);
   grae->SetPointError(3,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,27,63);
   Graph_g003->SetMinimum(11.95312);
   Graph_g003->SetMaximum(16.45312);
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
   
   grae->Draw("p");
   
   TPaveText *pt = new TPaveText(0.3743391,0.9342405,0.6256609,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 95%");
   pt->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
