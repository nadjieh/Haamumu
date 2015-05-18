{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Mon May 18 12:57:07 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",154,45,700,530);
   Canvas_1->Range(22.50808,0.3621372,67.49192,1.737863);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("alphaStat");
   gre->SetTitle("alpha");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,1.064504);
   gre->SetPointError(0,0,0.1719671);
   gre->SetPoint(1,40,1.073714);
   gre->SetPointError(1,0,0.129445);
   gre->SetPoint(2,50,1.074731);
   gre->SetPointError(2,0,0.21664);
   gre->SetPoint(3,60,1.114558);
   gre->SetPointError(3,0,0.1293831);
   
   TH1F *Graph_alphaStat1 = new TH1F("Graph_alphaStat1","alpha",100,27,63);
   Graph_alphaStat1->SetMinimum(0.5);
   Graph_alphaStat1->SetMaximum(1.6);
   Graph_alphaStat1->SetDirectory(0);
   Graph_alphaStat1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_alphaStat1->SetLineColor(ci);
   Graph_alphaStat1->GetXaxis()->SetLabelFont(42);
   Graph_alphaStat1->GetXaxis()->SetLabelSize(0.035);
   Graph_alphaStat1->GetXaxis()->SetTitleSize(0.035);
   Graph_alphaStat1->GetXaxis()->SetTitleFont(42);
   Graph_alphaStat1->GetYaxis()->SetLabelFont(42);
   Graph_alphaStat1->GetYaxis()->SetLabelSize(0.035);
   Graph_alphaStat1->GetYaxis()->SetTitleSize(0.035);
   Graph_alphaStat1->GetYaxis()->SetTitleFont(42);
   Graph_alphaStat1->GetZaxis()->SetLabelFont(42);
   Graph_alphaStat1->GetZaxis()->SetLabelSize(0.035);
   Graph_alphaStat1->GetZaxis()->SetTitleSize(0.035);
   Graph_alphaStat1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_alphaStat1);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol0",27,63);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(0.0760578);
   PrevFitTMP->SetNDF(3);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,1.086033);
   PrevFitTMP->SetParError(0,0.07569258);
   PrevFitTMP->SetParLimits(0,0,0);
   gre->GetListOfFunctions()->Add(PrevFitTMP);
   gre->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4447414,0.9342405,0.5552586,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("alpha");
   pt->Draw();
      tex = new TLatex(30.97487,1.523087,"p0 = 1.0859 #pm 0.0757");
   tex->SetLineWidth(2);
   tex->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
   Canvas_1->ToggleToolBar();
}
