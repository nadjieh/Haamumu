{
//=========Macro generated from canvas: C/C
//=========  (Wed May 13 18:59:42 2015) by ROOT version5.34/19
   TCanvas *C = new TCanvas("C", "C",0,0,1185,658);
   C->Range(0,0,1,1);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: C_1
   TPad *C_1 = new TPad("C_1", "C_1",0.01,0.51,0.24,0.99);
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
   grae->SetPoint(0,30,29.98182);
   grae->SetPointError(0,0,0,0.0005795806,5.449465e-06);
   grae->SetPoint(1,40,39.95788);
   grae->SetPointError(1,0,0,0.0001422755,0.0001395867);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.001933375,0.001459286);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.001284517,0.0003720207);
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
   gre->SetPoint(0,30,29.98182);
   gre->SetPointError(0,0,0.006705251);
   gre->SetPoint(1,40,39.95788);
   gre->SetPointError(1,0,0.006455383);
   gre->SetPoint(2,50,49.92739);
   gre->SetPointError(2,0,0.00901934);
   gre->SetPoint(3,60,59.92653);
   gre->SetPointError(3,0,0.01173615);
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
   grae->SetPoint(0,30,29.98182);
   grae->SetPointError(0,0,0,0.0005795806,5.449465e-06);
   grae->SetPoint(1,40,39.95788);
   grae->SetPointError(1,0,0,0.0001422755,0.0001395867);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.001933375,0.001459286);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.001284517,0.0003720207);
   grae->Draw("p|>");
   C_1->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_2
   C_2 = new TPad("C_2", "C_2",0.26,0.51,0.49,0.99);
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
   grae->SetPoint(0,30,0.2626502);
   grae->SetPointError(0,0,0,0.006140816,0.006452005);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0001546841);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001975279,0.004211177);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0008342907,4.249021e-06);
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
   gre->SetPoint(0,30,0.2626502);
   gre->SetPointError(0,0,0.01366939);
   gre->SetPoint(1,40,0.4121476);
   gre->SetPointError(1,0,0.01159685);
   gre->SetPoint(2,50,0.522387);
   gre->SetPointError(2,0,0.01915432);
   gre->SetPoint(3,60,0.6019119);
   gre->SetPointError(3,0,0.02203727);
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
   grae->SetPoint(0,30,0.2626502);
   grae->SetPointError(0,0,0,0.006140816,0.006452005);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0001546841);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001975279,0.004211177);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0008342907,4.249021e-06);
   grae->Draw("p|>");
   C_2->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_3
   C_3 = new TPad("C_3", "C_3",0.51,0.51,0.74,0.99);
   C_3->Draw();
   C_3->cd();
   C_3->Range(0,0,1,1);
   C_3->SetFillColor(0);
   C_3->SetBorderMode(0);
   C_3->SetBorderSize(2);
   C_3->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean_cb");
   grae->SetTitle("mean_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("mean_cbStat");
   gre->SetTitle("mean_cb");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,29.87947);
   gre->SetPointError(0,0,0.01985296);
   gre->SetPoint(1,40,39.737);
   gre->SetPointError(1,0,0.06351425);
   gre->SetPoint(2,50,49.64195);
   gre->SetPointError(2,0,0.07862462);
   gre->SetPoint(3,60,59.68974);
   gre->SetPointError(3,0,0.06440656);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean_cb");
   grae->SetTitle("mean_cb");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   grae->Draw("p|>");
   C_3->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_4
   C_4 = new TPad("C_4", "C_4",0.76,0.51,0.99,0.99);
   C_4->Draw();
   C_4->cd();
   C_4->Range(0,0,1,1);
   C_4->SetFillColor(0);
   C_4->SetBorderMode(0);
   C_4->SetBorderSize(2);
   C_4->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("sigma_cb");
   grae->SetTitle("sigma_cb");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.5346017);
   grae->SetPointError(0,0,0,0.01061698,0.01120148);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.01190164);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.0154785,0.02302831);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.005549079,0.006334122);
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
   gre->SetPoint(0,30,0.5346017);
   gre->SetPointError(0,0,0.0273445);
   gre->SetPoint(1,40,0.8982298);
   gre->SetPointError(1,0,0.06397683);
   gre->SetPoint(2,50,1.106017);
   gre->SetPointError(2,0,0.09537667);
   gre->SetPoint(3,60,1.193986);
   gre->SetPointError(3,0,0.07823012);
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
   grae->SetPoint(0,30,0.5346017);
   grae->SetPointError(0,0,0,0.01061698,0.01120148);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.01190164);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.0154785,0.02302831);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.005549079,0.006334122);
   grae->Draw("p|>");
   C_4->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_5
   C_5 = new TPad("C_5", "C_5",0.01,0.01,0.24,0.49);
   C_5->Draw();
   C_5->cd();
   C_5->Range(0,0,1,1);
   C_5->SetFillColor(0);
   C_5->SetBorderMode(0);
   C_5->SetBorderSize(2);
   C_5->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("widthStat");
   gre->SetTitle("width");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,29.87947);
   gre->SetPointError(0,0,0.01985296);
   gre->SetPoint(1,40,39.737);
   gre->SetPointError(1,0,0.06351425);
   gre->SetPoint(2,50,49.64195);
   gre->SetPointError(2,0,0.07862462);
   gre->SetPoint(3,60,59.68974);
   gre->SetPointError(3,0,0.06440656);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("width");
   grae->SetTitle("width");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.87947);
   grae->SetPointError(0,0,0,0.0001576561,4.726107e-06);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.01059009,0.01036359);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.0190667,0.00802534);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,0.02232884,0.02270682);
   grae->Draw("p|>");
   C_5->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_6
   C_6 = new TPad("C_6", "C_6",0.26,0.01,0.49,0.49);
   C_6->Draw();
   C_6->cd();
   C_6->Range(0,0,1,1);
   C_6->SetFillColor(0);
   C_6->SetBorderMode(0);
   C_6->SetBorderSize(2);
   C_6->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("n");
   grae->SetTitle("n");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.969983);
   grae->SetPointError(0,0,0,0.07830033,0.08884695);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0014026);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.06993785,0.07117535);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.0493131,0.04885718);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("nStat");
   gre->SetTitle("n");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,1.969983);
   gre->SetPointError(0,0,0.1556854);
   gre->SetPoint(1,40,2.399169);
   gre->SetPointError(1,0,0.2131461);
   gre->SetPoint(2,50,1.983956);
   gre->SetPointError(2,0,0.1546523);
   gre->SetPoint(3,60,1.922008);
   gre->SetPointError(3,0,0.1165036);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("n");
   grae->SetTitle("n");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,1.969983);
   grae->SetPointError(0,0,0,0.07830033,0.08884695);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0014026);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.06993785,0.07117535);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.0493131,0.04885718);
   grae->Draw("p|>");
   C_6->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_7
   C_7 = new TPad("C_7", "C_7",0.51,0.01,0.74,0.49);
   C_7->Draw();
   C_7->cd();
   C_7->Range(0,0,1,1);
   C_7->SetFillColor(0);
   C_7->SetBorderMode(0);
   C_7->SetBorderSize(2);
   C_7->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("alpha");
   grae->SetTitle("alpha");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,1.474416);
   grae->SetPointError(0,0,0,0.000371194,0.008386376);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,0.001989542,0.005409373);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002682861);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.01022805,0.00281023);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("alphaStat");
   gre->SetTitle("alpha");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,1.474416);
   gre->SetPointError(0,0,0.07578345);
   gre->SetPoint(1,40,1.216039);
   gre->SetPointError(1,0,0.07230666);
   gre->SetPoint(2,50,1.287164);
   gre->SetPointError(2,0,0.08697325);
   gre->SetPoint(3,60,1.322775);
   gre->SetPointError(3,0,0.07369161);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("alpha");
   grae->SetTitle("alpha");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,1.474416);
   grae->SetPointError(0,0,0,0.000371194,0.008386376);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,0.001989542,0.005409373);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002682861);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.01022805,0.00281023);
   grae->Draw("p|>");
   C_7->Modified();
   C->cd();
  
// ------------>Primitives in pad: C_8
   C_8 = new TPad("C_8", "C_8",0.76,0.01,0.99,0.49);
   C_8->Draw();
   C_8->cd();
   C_8->Range(0,0,1,1);
   C_8->SetFillColor(0);
   C_8->SetBorderMode(0);
   C_8->SetBorderSize(2);
   C_8->SetFrameBorderMode(0);
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("frac");
   grae->SetTitle("frac");
   grae->SetFillColor(1);
   grae->SetPoint(0,30,0.549942);
   grae->SetPointError(0,0,0,0.02769746,0.02885475);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.005052632);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.007027193,0.01084936);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.001799883,0.001800258);
   grae->Draw("alp");
   
   gre = new TGraphErrors(4);
   gre->SetName("fracStat");
   gre->SetTitle("frac");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetPoint(0,30,0.549942);
   gre->SetPointError(0,0,0.053217);
   gre->SetPoint(1,40,0.6968665);
   gre->SetPointError(1,0,0.03641596);
   gre->SetPoint(2,50,0.7026572);
   gre->SetPointError(2,0,0.04639769);
   gre->SetPoint(3,60,0.6172068);
   gre->SetPointError(3,0,0.04857021);
   gre->Draw("p");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("frac");
   grae->SetTitle("frac");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,0.549942);
   grae->SetPointError(0,0,0,0.02769746,0.02885475);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.005052632);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.007027193,0.01084936);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.001799883,0.001800258);
   grae->Draw("p|>");
   C_8->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
