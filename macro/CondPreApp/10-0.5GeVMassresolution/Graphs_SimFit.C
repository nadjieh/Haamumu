{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Wed May 20 19:17:39 2015) by ROOT version5.34/19
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
   gre->SetPoint(0,30,29.96442);
   gre->SetPointError(0,0,0.005452715);
   gre->SetPoint(1,40,39.95492);
   gre->SetPointError(1,0,0.007224478);
   gre->SetPoint(2,50,49.90816);
   gre->SetPointError(2,0,0.008587357);
   gre->SetPoint(3,60,59.90445);
   gre->SetPointError(3,0,0.009743853);
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
   gre->SetPoint(0,30,0.2763362);
   gre->SetPointError(0,0,0.007557318);
   gre->SetPoint(1,40,0.372343);
   gre->SetPointError(1,0,0.009703192);
   gre->SetPoint(2,50,0.4806699);
   gre->SetPointError(2,0,0.01170227);
   gre->SetPoint(3,60,0.5808082);
   gre->SetPointError(3,0,0.01162557);
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
   gre->SetPoint(0,30,0.4537363);
   gre->SetPointError(0,0,0.01471267);
   gre->SetPoint(1,40,0.6189305);
   gre->SetPointError(1,0,0.01915956);
   gre->SetPoint(2,50,0.7721469);
   gre->SetPointError(2,0,0.02252145);
   gre->SetPoint(3,60,1.01087);
   gre->SetPointError(3,0,0.02357416);
   gre->Draw("alp");
   Graphs_3->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
}
