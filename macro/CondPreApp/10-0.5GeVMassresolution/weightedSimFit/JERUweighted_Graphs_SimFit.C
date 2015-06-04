{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Sun May 31 15:03:30 2015) by ROOT version5.34/19
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
   gre->SetPoint(0,30,29.95964);
   gre->SetPointError(0,0,0.005814387);
   gre->SetPoint(1,40,39.94906);
   gre->SetPointError(1,0,0.007604734);
   gre->SetPoint(2,50,49.90056);
   gre->SetPointError(2,0,0.00920395);
   gre->SetPoint(3,60,59.89656);
   gre->SetPointError(3,0,0.01032271);
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
   gre->SetPoint(0,30,0.2819715);
   gre->SetPointError(0,0,0.01136064);
   gre->SetPoint(1,40,0.3780802);
   gre->SetPointError(1,0,0.01492441);
   gre->SetPoint(2,50,0.4817312);
   gre->SetPointError(2,0,0.01882287);
   gre->SetPoint(3,60,0.5898698);
   gre->SetPointError(3,0,0.02062487);
   gre->Draw("alp");
   TF1 * jeru = new TF1("jeru","pol1",25.,65.);
   gre->Fit(jeru);
   cout<<"|Up|"<<jeru->GetParameter(0)<<"|"<<jeru->GetParameter(1)<<endl;   
   cout<<"\t\tSigmaJERU = new TF1(\"SigmaJERU\",\""<<jeru->GetParameter(0)<<"+("<<jeru->GetParameter(1)<<"*x)\",20.,70.);      "       <<        endl;   
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
   gre->SetPoint(0,30,0.4993356);
   gre->SetPointError(0,0,0.02402623);
   gre->SetPoint(1,40,0.6896452);
   gre->SetPointError(1,0,0.04064219);
   gre->SetPoint(2,50,0.8384349);
   gre->SetPointError(2,0,0.04178323);
   gre->SetPoint(3,60,1.053885);
   gre->SetPointError(3,0,0.04260025);
   gre->Draw("alp");

   Graphs_3->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
}
