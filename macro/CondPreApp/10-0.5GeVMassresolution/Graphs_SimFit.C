{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Fri May 29 11:11:23 2015) by ROOT version5.34/19
   TCanvas *Graphs = new TCanvas("Graphs", "Graphs",3,24,1185,716);
   Graphs->SetHighLightColor(2);
   Graphs->Range(0,0,1,1);
   Graphs->SetFillColor(0);
   Graphs->SetBorderMode(0);
   Graphs->SetBorderSize(2);
   Graphs->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Graphs_1
   TPad *Graphs_1 = new TPad("Graphs_1", "Graphs_1",0.01,0.01,0.3233333,0.99);
   Graphs_1->Draw();
   Graphs_1->cd();
   Graphs_1->Range(24.88235,22.46773,67.23529,67.39797);
   Graphs_1->SetFillColor(0);
   Graphs_1->SetBorderMode(0);
   Graphs_1->SetBorderSize(2);
   Graphs_1->SetLeftMargin(0.05);
   Graphs_1->SetFrameBorderMode(0);
   Graphs_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("Mean");
   gre->SetTitle("Mean");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,29.96153);
   gre->SetPointError(0,0,0.005427939);
   gre->SetPoint(1,40,39.95142);
   gre->SetPointError(1,0,0.007200891);
   gre->SetPoint(2,50,49.9037);
   gre->SetPointError(2,0,0.008560994);
   gre->SetPoint(3,60,59.89987);
   gre->SetPointError(3,0,0.009723945);
   
   TH1F *Graph_Mean1 = new TH1F("Graph_Mean1","Mean",100,27,63);
   Graph_Mean1->SetMinimum(26.96075);
   Graph_Mean1->SetMaximum(62.90494);
   Graph_Mean1->SetDirectory(0);
   Graph_Mean1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Mean1->SetLineColor(ci);
   Graph_Mean1->GetXaxis()->SetLabelFont(42);
   Graph_Mean1->GetXaxis()->SetLabelSize(0.035);
   Graph_Mean1->GetXaxis()->SetTitleSize(0.035);
   Graph_Mean1->GetXaxis()->SetTitleFont(42);
   Graph_Mean1->GetYaxis()->SetLabelFont(42);
   Graph_Mean1->GetYaxis()->SetLabelSize(0.035);
   Graph_Mean1->GetYaxis()->SetTitleSize(0.035);
   Graph_Mean1->GetYaxis()->SetTitleFont(42);
   Graph_Mean1->GetZaxis()->SetLabelFont(42);
   Graph_Mean1->GetZaxis()->SetLabelSize(0.035);
   Graph_Mean1->GetZaxis()->SetTitleSize(0.035);
   Graph_Mean1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Mean1);
   
   gre->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4250104,0.94,0.5749896,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Mean");
   pt->Draw();
   Graphs_1->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_2
   Graphs_2 = new TPad("Graphs_2", "Graphs_2",0.3433333,0.01,0.6566667,0.99);
   Graphs_2->Draw();
   Graphs_2->cd();
   Graphs_2->Range(24.88235,0.1908319,67.23529,0.6761071);
   Graphs_2->SetFillColor(0);
   Graphs_2->SetBorderMode(0);
   Graphs_2->SetBorderSize(2);
   Graphs_2->SetLeftMargin(0.05);
   Graphs_2->SetFrameBorderMode(0);
   Graphs_2->SetFrameBorderMode(0);
   
   gre = new TGraphErrors(4);
   gre->SetName("Sigma");
   gre->SetTitle("Sigma");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.2787429);
   gre->SetPointError(0,0,0.007031842);
   gre->SetPoint(1,40,0.3743713);
   gre->SetPointError(1,0,0.009210511);
   gre->SetPoint(2,50,0.4821505);
   gre->SetPointError(2,0,0.01117084);
   gre->SetPoint(3,60,0.5838269);
   gre->SetPointError(3,0,0.01140096);
   
   TH1F *Graph_Sigma2 = new TH1F("Graph_Sigma2","Sigma",100,27,63);
   Graph_Sigma2->SetMinimum(0.2393594);
   Graph_Sigma2->SetMaximum(0.6275795);
   Graph_Sigma2->SetDirectory(0);
   Graph_Sigma2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Sigma2->SetLineColor(ci);
   Graph_Sigma2->GetXaxis()->SetLabelFont(42);
   Graph_Sigma2->GetXaxis()->SetLabelSize(0.035);
   Graph_Sigma2->GetXaxis()->SetTitleSize(0.035);
   Graph_Sigma2->GetXaxis()->SetTitleFont(42);
   Graph_Sigma2->GetYaxis()->SetLabelFont(42);
   Graph_Sigma2->GetYaxis()->SetLabelSize(0.035);
   Graph_Sigma2->GetYaxis()->SetTitleSize(0.035);
   Graph_Sigma2->GetYaxis()->SetTitleFont(42);
   Graph_Sigma2->GetZaxis()->SetLabelFont(42);
   Graph_Sigma2->GetZaxis()->SetLabelSize(0.035);
   Graph_Sigma2->GetZaxis()->SetTitleSize(0.035);
   Graph_Sigma2->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Sigma2);
   
   
   TF1 *Pol1 = new TF1("Pol1","pol1",27,63);
   Pol1->SetFillColor(19);
   Pol1->SetFillStyle(0);
   Pol1->SetLineColor(2);
   Pol1->SetLineWidth(2);
   Pol1->SetChisquare(0.326662);
   Pol1->SetNDF(2);
   Pol1->GetXaxis()->SetLabelFont(42);
   Pol1->GetXaxis()->SetLabelSize(0.035);
   Pol1->GetXaxis()->SetTitleSize(0.035);
   Pol1->GetXaxis()->SetTitleFont(42);
   Pol1->GetYaxis()->SetLabelFont(42);
   Pol1->GetYaxis()->SetLabelSize(0.035);
   Pol1->GetYaxis()->SetTitleSize(0.035);
   Pol1->GetYaxis()->SetTitleFont(42);
   Pol1->SetParameter(0,-0.02817524);
   Pol1->SetParError(0,0.01738391);
   Pol1->SetParLimits(0,0,0);
   Pol1->SetParameter(1,0.01017779);
   Pol1->SetParError(1,0.0004123951);
   Pol1->SetParLimits(1,0,0);
   gre->GetListOfFunctions()->Add(Pol1);
   gre->Draw("alp");
   
   pt = new TPaveText(0.4120125,0.94,0.5879875,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Sigma");
   pt->Draw();
      tex = new TLatex(28.31541,0.606782,"Ev(#sigma) =");
   tex->SetTextAngle(359.7894);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(46.65692,0.6217875,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(56.42576,0.6217875,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(28.20149,0.5842739," p0Sigma +");
   tex->SetTextColor(4);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(37.87544,0.5782717,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(28.20149,0.5602652," p1Sigma * mass");
   tex->SetTextColor(4);
   tex->SetLineWidth(2);
   tex->Draw();
   Graphs_2->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_3
   Graphs_3 = new TPad("Graphs_3", "Graphs_3",0.6766667,0.01,0.99,0.99);
   Graphs_3->Draw();
   Graphs_3->cd();
   Graphs_3->Range(24.88235,0.3142734,67.23529,1.211499);
   Graphs_3->SetFillColor(0);
   Graphs_3->SetBorderMode(0);
   Graphs_3->SetBorderSize(2);
   Graphs_3->SetLeftMargin(0.05);
   Graphs_3->SetFrameBorderMode(0);
   Graphs_3->SetFrameBorderMode(0);
   
   gre = new TGraphErrors(4);
   gre->SetName("Sigma_cb");
   gre->SetTitle("Sigma_cb");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.477997);
   gre->SetPointError(0,0,0.01418597);
   gre->SetPoint(1,40,0.6468398);
   gre->SetPointError(1,0,0.01882981);
   gre->SetPoint(2,50,0.802282);
   gre->SetPointError(2,0,0.0221238);
   gre->SetPoint(3,60,1.038351);
   gre->SetPointError(3,0,0.02361044);
   
   TH1F *Graph_Sigma_cb3 = new TH1F("Graph_Sigma_cb3","Sigma_cb",100,27,63);
   Graph_Sigma_cb3->SetMinimum(0.403996);
   Graph_Sigma_cb3->SetMaximum(1.121776);
   Graph_Sigma_cb3->SetDirectory(0);
   Graph_Sigma_cb3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Sigma_cb3->SetLineColor(ci);
   Graph_Sigma_cb3->GetXaxis()->SetLabelFont(42);
   Graph_Sigma_cb3->GetXaxis()->SetLabelSize(0.035);
   Graph_Sigma_cb3->GetXaxis()->SetTitleSize(0.035);
   Graph_Sigma_cb3->GetXaxis()->SetTitleFont(42);
   Graph_Sigma_cb3->GetYaxis()->SetLabelFont(42);
   Graph_Sigma_cb3->GetYaxis()->SetLabelSize(0.035);
   Graph_Sigma_cb3->GetYaxis()->SetTitleSize(0.035);
   Graph_Sigma_cb3->GetYaxis()->SetTitleFont(42);
   Graph_Sigma_cb3->GetZaxis()->SetLabelFont(42);
   Graph_Sigma_cb3->GetZaxis()->SetLabelSize(0.035);
   Graph_Sigma_cb3->GetZaxis()->SetTitleSize(0.035);
   Graph_Sigma_cb3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Sigma_cb3);
   
   
   TF1 *Pol2 = new TF1("Pol2","pol2",27,63);
   Pol2->SetFillColor(19);
   Pol2->SetFillStyle(0);
   Pol2->SetLineColor(2);
   Pol2->SetLineWidth(2);
   Pol2->SetChisquare(1.058198);
   Pol2->SetNDF(1);
   Pol2->GetXaxis()->SetLabelFont(42);
   Pol2->GetXaxis()->SetLabelSize(0.035);
   Pol2->GetXaxis()->SetTitleSize(0.035);
   Pol2->GetXaxis()->SetTitleFont(42);
   Pol2->GetYaxis()->SetLabelFont(42);
   Pol2->GetYaxis()->SetLabelSize(0.035);
   Pol2->GetYaxis()->SetTitleSize(0.035);
   Pol2->GetYaxis()->SetTitleFont(42);
   Pol2->SetParameter(0,0.1924287);
   Pol2->SetParError(0,0.1780336);
   Pol2->SetParLimits(0,0,0);
   Pol2->SetParameter(1,0.005194728);
   Pol2->SetParError(1,0.008607503);
   Pol2->SetParLimits(1,0,0);
   Pol2->SetParameter(2,0.0001466569);
   Pol2->SetParError(2,9.789726e-05);
   Pol2->SetParLimits(2,0,0);
   gre->GetListOfFunctions()->Add(Pol2);
   gre->Draw("alp");
   
   pt = new TPaveText(0.3680195,0.94,0.6319805,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Sigma_cb");
   pt->Draw();
      tex = new TLatex(29.44406,1.088873,"Ev(#sigma_{CB}) = ");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(29.34602,1.037547,"p0SigmaCB +");

   ci = TColor::GetColor("#339933");
   tex->SetTextColor(ci);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(29.34602,0.9987062,"p1SigmaCB * mass +");

   ci = TColor::GetColor("#339933");
   tex->SetTextColor(ci);
   tex->SetTextSize(0.04638219);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(29.34602,0.9598653,"p2SigmaCB * mass^{2}");

   ci = TColor::GetColor("#339933");
   tex->SetTextColor(ci);
   tex->SetLineWidth(2);
   tex->Draw();
   Graphs_3->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
   Graphs->ToggleToolBar();
}
