{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Apr 23 15:44:03 2015) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",13,34,700,500);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c1_1
   TPad *c1_1 = new TPad("c1_1", "c1_1",0.01,0.51,0.24,0.99);
   c1_1->Draw();
   c1_1->cd();
   c1_1->Range(0,0,1,1);
   c1_1->SetFillColor(0);
   c1_1->SetBorderMode(0);
   c1_1->SetBorderSize(2);
   c1_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("MeanV");
   grae->SetTitle("Mean Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,30.0081);
   grae->SetPointError(0,0,0,0.0562444,0.0562444);
   grae->SetPoint(1,40,41.2314);
   grae->SetPointError(1,0,0,0.101759,0.101759);
   grae->SetPoint(2,50,49.9066);
   grae->SetPointError(2,0,0,0.0542857,0.0542857);
   grae->SetPoint(3,60,59.9015);
   grae->SetPointError(3,0,0,0.0476253,0.0476253);
   grae->Draw("ap");
   c1_1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   c1_2 = new TPad("c1_2", "c1_2",0.26,0.51,0.49,0.99);
   c1_2->Draw();
   c1_2->cd();
   c1_2->Range(0,0,1,1);
   c1_2->SetFillColor(0);
   c1_2->SetBorderMode(0);
   c1_2->SetBorderSize(2);
   c1_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("SigmaV");
   grae->SetTitle("Sigma Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,3.20532e-05);
   grae->SetPointError(0,0,0,0.0445801,0.0445801);
   grae->SetPoint(1,40,0.124012);
   grae->SetPointError(1,0,0,0.142493,0.142493);
   grae->SetPoint(2,50,0.00048053);
   grae->SetPointError(2,0,0,0.141041,0.141041);
   grae->SetPoint(3,60,5.36862e-05);
   grae->SetPointError(3,0,0,0.154788,0.154788);
   grae->Draw("ap");
   c1_2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_3
   c1_3 = new TPad("c1_3", "c1_3",0.51,0.51,0.74,0.99);
   c1_3->Draw();
   c1_3->cd();
   c1_3->Range(0,0,1,1);
   c1_3->SetFillColor(0);
   c1_3->SetBorderMode(0);
   c1_3->SetBorderSize(2);
   c1_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("WidthV");
   grae->SetTitle("Width Voig");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.551956);
   grae->SetPointError(0,0,0,0.020494,0.020494);
   grae->SetPoint(1,40,0.59528);
   grae->SetPointError(1,0,0,0.0446388,0.0446388);
   grae->SetPoint(2,50,0.74515);
   grae->SetPointError(2,0,0,0.0159013,0.0159013);
   grae->SetPoint(3,60,0.785736);
   grae->SetPointError(3,0,0,0.0247728,0.0247728);
   grae->Draw("ap");
   c1_3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_4
   c1_4 = new TPad("c1_4", "c1_4",0.76,0.51,0.99,0.99);
   c1_4->Draw();
   c1_4->cd();
   c1_4->Range(0,0,1,1);
   c1_4->SetFillColor(0);
   c1_4->SetBorderMode(0);
   c1_4->SetBorderSize(2);
   c1_4->SetFrameBorderMode(0);
   c1_4->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_5
   c1_5 = new TPad("c1_5", "c1_5",0.01,0.01,0.24,0.49);
   c1_5->Draw();
   c1_5->cd();
   c1_5->Range(0,0,1,1);
   c1_5->SetFillColor(0);
   c1_5->SetBorderMode(0);
   c1_5->SetBorderSize(2);
   c1_5->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Mean_cbs");
   grae->SetTitle("Mean CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.9632);
   grae->SetPointError(0,0,0,0.00815924,0.00815924);
   grae->SetPoint(1,40,39.9534);
   grae->SetPointError(1,0,0,0.00757414,0.00757414);
   grae->SetPoint(2,50,49.913);
   grae->SetPointError(2,0,0,0.0135183,0.0135183);
   grae->SetPoint(3,60,59.9028);
   grae->SetPointError(3,0,0,0.0159372,0.0159372);
   grae->Draw("ap");
   c1_5->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_6
   c1_6 = new TPad("c1_6", "c1_6",0.26,0.01,0.49,0.49);
   c1_6->Draw();
   c1_6->cd();
   c1_6->Range(0,0,1,1);
   c1_6->SetFillColor(0);
   c1_6->SetBorderMode(0);
   c1_6->SetBorderSize(2);
   c1_6->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Sigma_cbs");
   grae->SetTitle("Sigma CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.35239);
   grae->SetPointError(0,0,0,0.00601303,0.00601303);
   grae->SetPoint(1,40,0.437525);
   grae->SetPointError(1,0,0,0.00803017,0.00803017);
   grae->SetPoint(2,50,0.608399);
   grae->SetPointError(2,0,0,0.00953921,0.00953921);
   grae->SetPoint(3,60,0.75573);
   grae->SetPointError(3,0,0,0.0114645,0.0114645);
   grae->Draw("ap");
   c1_6->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_7
   c1_7 = new TPad("c1_7", "c1_7",0.51,0.01,0.74,0.49);
   c1_7->Draw();
   c1_7->cd();
   c1_7->Range(0,0,1,1);
   c1_7->SetFillColor(0);
   c1_7->SetBorderMode(0);
   c1_7->SetBorderSize(2);
   c1_7->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Ns");
   grae->SetTitle("N CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,2.23848);
   grae->SetPointError(0,0,0,0.184412,0.184412);
   grae->SetPoint(1,40,2.28355);
   grae->SetPointError(1,0,0,0.127433,0.127433);
   grae->SetPoint(2,50,2.28513);
   grae->SetPointError(2,0,0,0.15271,0.15271);
   grae->SetPoint(3,60,2.43433);
   grae->SetPointError(3,0,0,0.173886,0.173886);
   grae->Draw("ap");
   c1_7->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_8
   c1_8 = new TPad("c1_8", "c1_8",0.76,0.01,0.99,0.49);
   c1_8->Draw();
   c1_8->cd();
   c1_8->Range(0,0,1,1);
   c1_8->SetFillColor(0);
   c1_8->SetBorderMode(0);
   c1_8->SetBorderSize(2);
   c1_8->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("Alphas");
   grae->SetTitle("Alpha CB");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.54808);
   grae->SetPointError(0,0,0,0.0672481,0.0672481);
   grae->SetPoint(1,40,1.44788);
   grae->SetPointError(1,0,0,0.0503279,0.0503279);
   grae->SetPoint(2,50,1.53233);
   grae->SetPointError(2,0,0,0.0608989,0.0608989);
   grae->SetPoint(3,60,1.56225);
   grae->SetPointError(3,0,0,0.0592279,0.0592279);
   grae->Draw("ap");
   c1_8->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
