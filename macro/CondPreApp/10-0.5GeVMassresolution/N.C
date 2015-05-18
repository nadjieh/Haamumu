{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Mon May 18 14:05:41 2015) by ROOT version5.34/19
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",13,34,700,500);
   Canvas_1->Range(22.5,0.5,67.5,5.5);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("nStat");
   gre->SetTitle("n");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,3.109128);
   gre->SetPointError(0,0,0.2233929);
   gre->SetPoint(1,40,3.240993);
   gre->SetPointError(1,0,0.2095636);
   gre->SetPoint(2,50,3.21847);
   gre->SetPointError(2,0,0.1954251);
   gre->SetPoint(3,60,3.011234);
   gre->SetPointError(3,0,0.1499382);
   
   TH1F *Graph_nStat1 = new TH1F("Graph_nStat1","n",100,27,63);
   Graph_nStat1->SetMinimum(1);
   Graph_nStat1->SetMaximum(5);
   Graph_nStat1->SetDirectory(0);
   Graph_nStat1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_nStat1->SetLineColor(ci);
   Graph_nStat1->GetXaxis()->SetLabelFont(42);
   Graph_nStat1->GetXaxis()->SetLabelSize(0.035);
   Graph_nStat1->GetXaxis()->SetTitleSize(0.035);
   Graph_nStat1->GetXaxis()->SetTitleFont(42);
   Graph_nStat1->GetYaxis()->SetLabelFont(42);
   Graph_nStat1->GetYaxis()->SetLabelSize(0.035);
   Graph_nStat1->GetYaxis()->SetTitleSize(0.035);
   Graph_nStat1->GetYaxis()->SetTitleFont(42);
   Graph_nStat1->GetZaxis()->SetLabelFont(42);
   Graph_nStat1->GetZaxis()->SetLabelSize(0.035);
   Graph_nStat1->GetZaxis()->SetTitleSize(0.035);
   Graph_nStat1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_nStat1);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol0",27,63);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(1.115143);
   PrevFitTMP->SetNDF(3);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,3.122446);
   PrevFitTMP->SetParError(0,0.09387544);
   PrevFitTMP->SetParLimits(0,0,0);
   gre->GetListOfFunctions()->Add(PrevFitTMP);
   gre->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4799425,0.94,0.5200575,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("n");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
