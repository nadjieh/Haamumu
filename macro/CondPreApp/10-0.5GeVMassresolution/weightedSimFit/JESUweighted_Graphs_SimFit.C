{
//=========Macro generated from canvas: Graphs/Graphs
//=========  (Sun May 31 15:00:35 2015) by ROOT version5.34/19
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
   gre->SetPoint(0,30,29.95684);
   gre->SetPointError(0,0,0.005560718);
   gre->SetPoint(1,40,39.95026);
   gre->SetPointError(1,0,0.007402431);
   gre->SetPoint(2,50,49.90658);
   gre->SetPointError(2,0,0.008999205);
   gre->SetPoint(3,60,59.89667);
   gre->SetPointError(3,0,0.009791715);
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
   gre->SetPoint(0,30,0.2777833);
   gre->SetPointError(0,0,0.01019139);
   gre->SetPoint(1,40,0.3693486);
   gre->SetPointError(1,0,0.0145256);
   gre->SetPoint(2,50,0.4803666);
   gre->SetPointError(2,0,0.01659219);
   gre->SetPoint(3,60,0.5828459);
   gre->SetPointError(3,0,0.01840218);
   gre->Draw("alp");
      TF1 * jesu = new TF1("jesu","pol1",25.,65.);
   gre->Fit(jesu);
   cout<<"|Up|"<<jesu->GetParameter(0)<<"|"<<jesu->GetParameter(1)<<endl;   
   cout<<"\t\tSigmaJESU = new TF1(\"SigmaJESU\",\""<<jesu->GetParameter(0)<<"+("<<jesu->GetParameter(1)<<"*x)\",20.,70.);         "       <<        endl;
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
   gre->SetPoint(0,30,0.4974659);
   gre->SetPointError(0,0,0.02146012);
   gre->SetPoint(1,40,0.6643337);
   gre->SetPointError(1,0,0.03425098);
   gre->SetPoint(2,50,0.8316404);
   gre->SetPointError(2,0,0.03800033);
   gre->SetPoint(3,60,1.069806);
   gre->SetPointError(3,0,0.03770747);
   gre->Draw("alp");

   Graphs_3->Modified();
   Graphs->cd();
   Graphs->Modified();
   Graphs->cd();
   Graphs->SetSelected(Graphs);
}
