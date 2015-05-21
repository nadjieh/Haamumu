{
//=========Macro generated from canvas: C/C
//=========  (Tue May 19 18:22:35 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",6,82,1185,658);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.01,0.3233333,0.99);
   C_1->Draw();
   C_1->cd();
   C_1->Range(0,0,1,1);
   C_1->SetFillColor(0);
   C_1->SetBorderMode(0);
   C_1->SetBorderSize(2);
   C_1->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,0.000469783,0.0003624168);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.002615954,6.510632e-05);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,0.0003537819,0.001917164);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.001134244,0.002011169);
   grae->Draw("alp");
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("meanStat");
   gre->SetTitle("mean");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,29.95972);
   gre->SetPointError(0,0,0.005422914);
   gre->SetPoint(1,40,39.94931);
   gre->SetPointError(1,0,0.007195136);
   gre->SetPoint(2,50,49.90091);
   gre->SetPointError(2,0,0.008555621);
   gre->SetPoint(3,60,59.89713);
   gre->SetPointError(3,0,0.009706139);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.95972);
   grae->SetPointError(0,0,0,0.000469783,0.0003624168);
   grae->SetPoint(1,40,39.94931);
   grae->SetPointError(1,0,0,0.002615954,6.510632e-05);
   grae->SetPoint(2,50,49.90091);
   grae->SetPointError(2,0,0,0.0003537819,0.001917164);
   grae->SetPoint(3,60,59.89713);
   grae->SetPointError(3,0,0,0.001134244,0.002011169);
   grae->Draw("p|>");
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.3433333,0.01,0.6566667,0.99);
   C_2->Draw();
   C_2->cd();
   C_2->Range(0,0,1,1);
   C_2->SetFillColor(0);
   C_2->SetBorderMode(0);
   C_2->SetBorderSize(2);
   C_2->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,0.000660352,0.000373533);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,0.001197973,0.002276693);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.001257286,0.001466029);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.003686261,0.001385643);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigmaStat");
   gre->SetTitle("sigma");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,0.2858389);
   gre->SetPointError(0,0,0.006380716);
   gre->SetPoint(1,40,0.3810689);
   gre->SetPointError(1,0,0.008510948);
   gre->SetPoint(2,50,0.487961);
   gre->SetPointError(2,0,0.01039632);
   gre->SetPoint(3,60,0.591851);
   gre->SetPointError(3,0,0.0110008);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma");
   grae->SetTitle("sigma");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.2858389);
   grae->SetPointError(0,0,0,0.000660352,0.000373533);
   grae->SetPoint(1,40,0.3810689);
   grae->SetPointError(1,0,0,0.001197973,0.002276693);
   grae->SetPoint(2,50,0.487961);
   grae->SetPointError(2,0,0,0.001257286,0.001466029);
   grae->SetPoint(3,60,0.591851);
   grae->SetPointError(3,0,0,0.003686261,0.001385643);
   grae->Draw("p|>");
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.6766667,0.01,0.99,0.99);
   C_3->Draw();
   C_3->cd();
   C_3->Range(0,0,1,1);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,0.00381145,0.00224625);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,0.002884949,0.003348689);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.0006770472,0.002235592);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.004106113,0.003843322);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("sigma_cbStat");
   gre->SetTitle("sigma_cb");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,0.5096423);
   gre->SetPointError(0,0,0.01356009);
   gre->SetPoint(1,40,0.6835205);
   gre->SetPointError(1,0,0.01814551);
   gre->SetPoint(2,50,0.841637);
   gre->SetPointError(2,0,0.02155012);
   gre->SetPoint(3,60,1.071645);
   gre->SetPointError(3,0,0.02345126);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.5096423);
   grae->SetPointError(0,0,0,0.00381145,0.00224625);
   grae->SetPoint(1,40,0.6835205);
   grae->SetPointError(1,0,0,0.002884949,0.003348689);
   grae->SetPoint(2,50,0.841637);
   grae->SetPointError(2,0,0,0.0006770472,0.002235592);
   grae->SetPoint(3,60,1.071645);
   grae->SetPointError(3,0,0,0.004106113,0.003843322);
   grae->Draw("p|>");
   C_3->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
