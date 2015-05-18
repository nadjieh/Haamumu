{
//=========Macro generated from canvas: C/C
//=========  (Mon Mar  2 14:57:32 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",56,98,650,630);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   C->Range(-1.373333,-439.3166,1.087619,3195.577);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetLeftMargin(0.1517028);
   C->SetRightMargin(0.03560372);
   C->SetTopMargin(0.05400697);
   C->SetBottomMargin(0.1202091);
   C->SetFrameFillStyle(0);
   C->SetFrameBorderMode(0);
   C->SetFrameFillStyle(0);
   C->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");
   grae->SetFillColor(3);
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,7.954193,22.47053);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,8.482269,24.06207);
   grae->SetPoint(2,50,15.79688);
   grae->SetPointError(2,0,0,8.29953,23.44095);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,7.923065,22.0498);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Expected 2 #sigma",100,27,63);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(80);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetTitle("m_{a_{1}} (GeV)");
   Graph_g21->GetXaxis()->SetRange(10,91);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.05);
   Graph_g21->GetXaxis()->SetTitleOffset(0.81);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetTitle("#sigma(gg#rightarrowH) #times Br(H#rightarrowa_{1}a_{1}#rightarrow#mu^{+}#mu^{-}b#bar{b}) fb");
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleSize(0.05);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");
   grae->SetFillColor(5);
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,5.126726,8.833694);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,5.467087,9.336308);
   grae->SetPoint(2,50,15.79688);
   grae->SetPointError(2,0,0,5.349306,9.256153);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,5.044765,8.706825);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Expected 1 #sigma",100,27,63);
   Graph_g12->SetMinimum(7.630091);
   Graph_g12->SetMaximum(27.23573);
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
   grae->SetPoint(0,30,14.39062);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,40,16.26562);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,49.98362,15.8745);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,14.85938);
   grae->SetPointError(3,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,27,63);
   Graph_g003->SetMinimum(14.20312);
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
   
   grae->Draw("PC");
   
   TPaveText *pt = new TPaveText(0.3808046,0.9342405,0.6191954,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 2 #sigma");
   pt->Draw();
   
        tex = new TLatex(55.71154,74.80649,"CMS");
   tex->SetLineWidth(2);
   tex->Draw();

      tex = new TLatex(52.61897,69.03233,"Preliminary");
   tex->SetTextFont(52);
   tex->SetTextSize(0.04139073);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(50.04457,81.42026,"19.7 fb^{-1} (8TeV)");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04139073);
   tex->SetLineWidth(2);
   tex->Draw();   
   TLegend *leg = new TLegend(0.4109195,0.5548523,0.8218391,0.8164557,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("g2ff","Expected 95%","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(kBlue);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("g1ff","Expected 68%","lpf");
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
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
