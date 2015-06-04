{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Mon Jun  1 12:46:05 2015) by ROOT version5.34/19
   TCanvas *Graphs = new TCanvas("Graphs", "Graphs",0,0,1600,800);
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
   gre->SetPoint(0,30,29.96016);
   gre->SetPointError(0,0,0.005778214);
   gre->SetPoint(1,40,39.94906);
   gre->SetPointError(1,0,0.007568712);
   gre->SetPoint(2,50,49.89927);
   gre->SetPointError(2,0,0.009162322);
   gre->SetPoint(3,60,59.89839);
   gre->SetPointError(3,0,0.01023596);
   gre->Draw("alp");
   Graphs_1->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_2
   Graphs_2 = new TPad("Graphs_2", "Graphs_2",0.3433333,0.01,0.6566667,0.99);
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
   gre->SetPoint(0,30,0.2826306);
   gre->SetPointError(0,0,0.01050701);
   gre->SetPoint(1,40,0.383193);
   gre->SetPointError(1,0,0.01306745);
   gre->SetPoint(2,50,0.4820418);
   gre->SetPointError(2,0,0.01733213);
   gre->SetPoint(3,60,0.5930222);
   gre->SetPointError(3,0,0.0182853);
   gre->Draw("alp");
   Graphs_2->Modified();
   Graphs->cd();
  
// ------------>Primitives in pad: Graphs_3
   Graphs_3 = new TPad("Graphs_3", "Graphs_3",0.6766667,0.01,0.99,0.99);
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
   gre->SetPoint(0,30,0.4975296);
   gre->SetPointError(0,0,0.02410772);
   gre->SetPoint(1,40,0.7001759);
   gre->SetPointError(1,0,0.03174385);
   gre->SetPoint(2,50,0.8360851);
   gre->SetPointError(2,0,0.03984086);
   gre->SetPoint(3,60,1.062316);
   gre->SetPointError(3,0,0.04043948);
   gre->Draw("alp");
   Graphs_3->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
}
