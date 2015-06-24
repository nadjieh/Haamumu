{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Sun Jun 14 15:16:45 2015) by ROOT version5.34/19
   TCanvas *Graphs = new TCanvas("Graphs", "Graphs",0,0,1600,800);
   Graphs->SetHighLightColor(2);
   Graphs->Range(0,0,1,1);
   Graphs->SetFillColor(0);
   Graphs->SetBorderMode(0);
   Graphs->SetBorderSize(2);
   Graphs->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Graphs_1
   TPad *Graphs_1 = new TPad("Graphs_1", "Graphs_1",0.01,0.51,0.24,0.99);
   Graphs_1->Draw();
   Graphs_1->cd();
   Graphs_1->Range(0,0,1,1);
   Graphs_1->SetFillColor(0);
   Graphs_1->SetBorderMode(0);
   Graphs_1->SetBorderSize(2);
   Graphs_1->SetLeftMargin(0.05);
   Graphs_1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("Mean");
   gre->SetTitle("Mean");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,29.95858);
   gre->SetPointError(0,0,0.006181047);
   gre->SetPoint(1,40,39.94656);
   gre->SetPointError(1,0,0.008243594);
   gre->SetPoint(2,50,49.90414);
   gre->SetPointError(2,0,0.009817385);
   gre->SetPoint(3,60,59.89826);
   gre->SetPointError(3,0,0.01098931);
   gre->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("MeanbDown");
   gre->SetTitle("MeanbDown");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,29.95879);
   gre->SetPointError(0,0,0.006197363);
   gre->SetPoint(1,40,39.94658);
   gre->SetPointError(1,0,0.008282347);
   gre->SetPoint(2,50,49.90818);
   gre->SetPointError(2,0,0.01043588);
   gre->SetPoint(3,60,59.89852);
   gre->SetPointError(3,0,0.01097638);
   gre->Draw("lp");
   Graphs_1->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_2
   Graphs_2 = new TPad("Graphs_2", "Graphs_2",0.26,0.51,0.49,0.99);
   Graphs_2->Draw();
   Graphs_2->cd();
   Graphs_2->Range(0,0,1,1);
   Graphs_2->SetFillColor(0);
   Graphs_2->SetBorderMode(0);
   Graphs_2->SetBorderSize(2);
   Graphs_2->SetLeftMargin(0.05);
   Graphs_2->SetFrameBorderMode(0);
   
   gre = new TGraphErrors(4);
   gre->SetName("Sigma");
   gre->SetTitle("Sigma");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.290046);
   gre->SetPointError(0,0,0.01907824);
   gre->SetPoint(1,40,0.3750509);
   gre->SetPointError(1,0,0.02926995);
   gre->SetPoint(2,50,0.4744997);
   gre->SetPointError(2,0,0.04251392);
   gre->SetPoint(3,60,0.5847943);
   gre->SetPointError(3,0,0.03252513);
   gre->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("SigmabDown");
   gre->SetTitle("SigmabDown");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,0.2894238);
   gre->SetPointError(0,0,0.02138781);
   gre->SetPoint(1,40,0.3743712);
   gre->SetPointError(1,0,0.03292003);
   gre->SetPoint(2,50,0.4789836);
   gre->SetPointError(2,0,0.04646223);
   gre->SetPoint(3,60,0.583735);
   gre->SetPointError(3,0,0.0329945);
   gre->Draw("lp");
   Graphs_2->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_3
   Graphs_3 = new TPad("Graphs_3", "Graphs_3",0.51,0.51,0.74,0.99);
   Graphs_3->Draw();
   Graphs_3->cd();
   Graphs_3->Range(0,0,1,1);
   Graphs_3->SetFillColor(0);
   Graphs_3->SetBorderMode(0);
   Graphs_3->SetBorderSize(2);
   Graphs_3->SetLeftMargin(0.05);
   Graphs_3->SetFrameBorderMode(0);
   
   gre = new TGraphErrors(4);
   gre->SetName("Sigma_cb");
   gre->SetTitle("Sigma_cb");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.5100873);
   gre->SetPointError(0,0,0.03934521);
   gre->SetPoint(1,40,0.6763777);
   gre->SetPointError(1,0,0.06013699);
   gre->SetPoint(2,50,0.8196444);
   gre->SetPointError(2,0,0.06586182);
   gre->SetPoint(3,60,1.05092);
   gre->SetPointError(3,0,0.0598879);
   gre->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("Sigma_cbbDown");
   gre->SetTitle("Sigma_cbbDown");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,0.5090396);
   gre->SetPointError(0,0,0.04329329);
   gre->SetPoint(1,40,0.6770554);
   gre->SetPointError(1,0,0.06655048);
   gre->SetPoint(2,50,0.8186151);
   gre->SetPointError(2,0,0.0742227);
   gre->SetPoint(3,60,1.048106);
   gre->SetPointError(3,0,0.06025205);
   gre->Draw("lp");
   Graphs_3->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_4
   Graphs_4 = new TPad("Graphs_4", "Graphs_4",0.76,0.51,0.99,0.99);
   Graphs_4->Draw();
   Graphs_4->cd();
   Graphs_4->Range(0,0,1,1);
   Graphs_4->SetFillColor(0);
   Graphs_4->SetBorderMode(0);
   Graphs_4->SetBorderSize(2);
   Graphs_4->SetLeftMargin(0.05);
   Graphs_4->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(4);
   graph->SetName("Width");
   graph->SetTitle("Width");
   graph->SetFillColor(1);
   graph->SetLineColor(0);
   graph->SetMarkerColor(0);
   graph->SetPoint(0,30,0.00325342034);
   graph->SetPoint(1,40,0.0838679909);
   graph->SetPoint(2,50,0.00325342034);
   graph->SetPoint(3,60,0.0838679909);
   graph->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("Width");
   gre->SetTitle("Width");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.04295271);
   gre->SetPointError(0,0,0.01434878);
   gre->SetPoint(1,40,0.02764905);
   gre->SetPointError(1,0,0.02182932);
   gre->SetPoint(2,50,0.05756835);
   gre->SetPointError(2,0,0.02777882);
   gre->SetPoint(3,60,0.02853778);
   gre->SetPointError(3,0,0.0187434);
   gre->Draw("lp");
   
   gre = new TGraphErrors(4);
   gre->SetName("WidthbDown");
   gre->SetTitle("WidthbDown");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,0.04315932);
   gre->SetPointError(0,0,0.01472178);
   gre->SetPoint(1,40,0.02704864);
   gre->SetPointError(1,0,0.02298186);
   gre->SetPoint(2,50,0.04479322);
   gre->SetPointError(2,0,0.02509677);
   gre->SetPoint(3,60,0.02922997);
   gre->SetPointError(3,0,0.01907959);
   gre->Draw("lp");
   Graphs_4->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_5
   Graphs_5 = new TPad("Graphs_5", "Graphs_5",0.01,0.01,0.24,0.49);
   Graphs_5->Draw();
   Graphs_5->cd();
   Graphs_5->Range(0,0,1,1);
   Graphs_5->SetFillColor(0);
   Graphs_5->SetBorderMode(0);
   Graphs_5->SetBorderSize(2);
   Graphs_5->SetLeftMargin(0.05);
   Graphs_5->SetFrameBorderMode(0);
   
   graph = new TGraph(4);
   graph->SetName("N");
   graph->SetTitle("N");
   graph->SetFillColor(1);
   graph->SetLineColor(0);
   graph->SetMarkerColor(0);
   graph->SetPoint(0,30,1.868091138);
   graph->SetPoint(1,40,4.85296488);
   graph->SetPoint(2,50,1.868091138);
   graph->SetPoint(3,60,4.85296488);
   graph->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("N");
   gre->SetTitle("N");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,3.244394);
   gre->SetPointError(0,0,0.7997434);
   gre->SetPoint(1,40,3.262713);
   gre->SetPointError(1,0,0.6028268);
   gre->SetPoint(2,50,3.220279);
   gre->SetPointError(2,0,0.7100905);
   gre->SetPoint(3,60,2.975253);
   gre->SetPointError(3,0,0.4191292);
   gre->Draw("lp");
   
   gre = new TGraphErrors(4);
   gre->SetName("N");
   gre->SetTitle("N");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,3.221163);
   gre->SetPointError(0,0,0.8860486);
   gre->SetPoint(1,40,3.244797);
   gre->SetPointError(1,0,0.6647864);
   gre->SetPoint(2,50,3.261567);
   gre->SetPointError(2,0,0.8171455);
   gre->SetPoint(3,60,2.957492);
   gre->SetPointError(3,0,0.4089328);
   gre->Draw("lp");
   Graphs_5->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_6
   Graphs_6 = new TPad("Graphs_6", "Graphs_6",0.26,0.01,0.49,0.49);
   Graphs_6->Draw();
   Graphs_6->cd();
   Graphs_6->Range(0,0,1,1);
   Graphs_6->SetFillColor(0);
   Graphs_6->SetBorderMode(0);
   Graphs_6->SetBorderSize(2);
   Graphs_6->SetLeftMargin(0.05);
   Graphs_6->SetFrameBorderMode(0);
   
   graph = new TGraph(4);
   graph->SetName("Alpha");
   graph->SetTitle("Alpha");
   graph->SetFillColor(1);
   graph->SetLineColor(0);
   graph->SetMarkerColor(0);
   graph->SetPoint(0,30,0.6316605322);
   graph->SetPoint(1,40,1.565375175);
   graph->SetPoint(2,50,0.6316605322);
   graph->SetPoint(3,60,1.565375175);
   graph->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("Alpha");
   gre->SetTitle("Alpha");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,1.019416);
   gre->SetPointError(0,0,0.2074091);
   gre->SetPoint(1,40,1.085271);
   gre->SetPointError(1,0,0.1661705);
   gre->SetPoint(2,50,1.08708);
   gre->SetPointError(2,0,0.2218907);
   gre->SetPoint(3,60,1.133119);
   gre->SetPointError(3,0,0.1411355);
   gre->Draw("lp");
   
   gre = new TGraphErrors(4);
   gre->SetName("AlphabDown");
   gre->SetTitle("AlphabDown");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,1.025512);
   gre->SetPointError(0,0,0.2359359);
   gre->SetPoint(1,40,1.091698);
   gre->SetPointError(1,0,0.1869845);
   gre->SetPoint(2,50,1.05488);
   gre->SetPointError(2,0,0.249599);
   gre->SetPoint(3,60,1.138424);
   gre->SetPointError(3,0,0.1397592);
   gre->Draw("lp");
   Graphs_6->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_7
   Graphs_7 = new TPad("Graphs_7", "Graphs_7",0.51,0.01,0.74,0.49);
   Graphs_7->Draw();
   Graphs_7->cd();
   Graphs_7->Range(0,0,1,1);
   Graphs_7->SetFillColor(0);
   Graphs_7->SetBorderMode(0);
   Graphs_7->SetBorderSize(2);
   Graphs_7->SetLeftMargin(0.05);
   Graphs_7->SetFrameBorderMode(0);
   
   graph = new TGraph(4);
   graph->SetName("Frac");
   graph->SetTitle("Frac");
   graph->SetFillColor(1);
   graph->SetLineColor(0);
   graph->SetMarkerColor(0);
   graph->SetPoint(0,30,0.3812238046);
   graph->SetPoint(1,40,0.891299448);
   graph->SetPoint(2,50,0.3812238046);
   graph->SetPoint(3,60,0.891299448);
   graph->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("Frac");
   gre->SetTitle("Frac");
   gre->SetFillColor(1);
   gre->SetPoint(0,30,0.6523356);
   gre->SetPointError(0,0,0.09041394);
   gre->SetPoint(1,40,0.5863207);
   gre->SetPointError(1,0,0.09521651);
   gre->SetPoint(2,50,0.6076257);
   gre->SetPointError(2,0,0.1126714);
   gre->SetPoint(3,60,0.5767429);
   gre->SetPointError(3,0,0.07355287);
   gre->Draw("lp");
   
   gre = new TGraphErrors(4);
   gre->SetName("FracbDown");
   gre->SetTitle("FracbDown");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);
   gre->SetPoint(0,30,0.6494444);
   gre->SetPointError(0,0,0.1030547);
   gre->SetPoint(1,40,0.5843996);
   gre->SetPointError(1,0,0.1067366);
   gre->SetPoint(2,50,0.6064163);
   gre->SetPointError(2,0,0.1298865);
   gre->SetPoint(3,60,0.5736165);
   gre->SetPointError(3,0,0.07453839);
   gre->Draw("lp");
   Graphs_7->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_8
   Graphs_8 = new TPad("Graphs_8", "Graphs_8",0.76,0.01,0.99,0.49);
   Graphs_8->Draw();
   Graphs_8->cd();
   Graphs_8->Range(0,0,1,1);
   Graphs_8->SetFillColor(0);
   Graphs_8->SetBorderMode(0);
   Graphs_8->SetBorderSize(2);
   Graphs_8->SetFrameBorderMode(0);
   Graphs_8->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
}
