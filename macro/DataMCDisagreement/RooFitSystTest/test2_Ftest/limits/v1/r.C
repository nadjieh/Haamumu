{
//=========Macro generated from canvas: C/C
//=========  (Mon Mar  2 14:42:18 2015) by ROOT version5.34/19
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
   grae->SetTitle("Graph");
   grae->SetFillColor(3);
   grae->SetPoint(0,30,4.796875);
   grae->SetPointError(0,0,0,2.651398,7.490176);
   grae->SetPoint(1,40,5.421875);
   grae->SetPointError(1,0,0,2.827423,8.020689);
   grae->SetPoint(2,50,5.265625);
   grae->SetPointError(2,0,0,2.76651,7.81365);
   grae->SetPoint(3,60,4.953125);
   grae->SetPointError(3,0,0,2.641022,7.349932);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Graph",100,27,63);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(30);
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
   Graph_g21->GetYaxis()->SetTitle("Signal strength #it{r}");
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
   grae->SetTitle("Graph");
   grae->SetFillColor(5);
   grae->SetPoint(0,30,4.796875);
   grae->SetPointError(0,0,0,1.708909,2.944565);
   grae->SetPoint(1,40,5.421875);
   grae->SetPointError(1,0,0,1.822362,3.112103);
   grae->SetPoint(2,50,5.265625);
   grae->SetPointError(2,0,0,1.783102,3.085384);
   grae->SetPoint(3,60,4.953125);
   grae->SetPointError(3,0,0,1.681588,2.902275);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Graph",100,27,63);
   Graph_g12->SetMinimum(2.543365);
   Graph_g12->SetMaximum(9.078579);
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
   grae->SetName("g0");
   grae->SetTitle("");
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,29.99612,4.873418);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,39.96336,5.427215);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,49.98362,5.268987);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,59.95086,5.031645);
   grae->SetPointError(3,0,0,0,0);
   
   TH1F *Graph_g03 = new TH1F("Graph_g03","",100,27,63);
   Graph_g03->SetMinimum(4.734375);
   Graph_g03->SetMaximum(5.484375);
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
   
   grae->Draw("PC");
   
   TPaveText *pt = new TPaveText(0.4397126,0.9342405,0.5602874,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Graph");
   pt->Draw();
   TLegend *leg = new TLegend(0.4109195,0.5548523,0.8218391,0.8164557,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("g2ff","Expected 95%","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(3022);
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
