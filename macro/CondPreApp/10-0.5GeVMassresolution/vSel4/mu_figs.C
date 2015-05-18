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
   grae->SetPointError(0,0,0,8.180065e-05,1.642693e-05);
   grae->SetPoint(1,40,39.95788);
   grae->SetPointError(1,0,0,8.235525e-05,0.0001599665);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.0001290078,3.475199e-05);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.0002571381,1.031035e-05);
   grae->Draw("alp");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("mean");
   grae->SetTitle("mean");
   grae->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(4);
   grae->SetPoint(0,30,29.98182);
   grae->SetPointError(0,0,0,8.180065e-05,1.642693e-05);
   grae->SetPoint(1,40,39.95788);
   grae->SetPointError(1,0,0,8.235525e-05,0.0001599665);
   grae->SetPoint(2,50,49.92739);
   grae->SetPointError(2,0,0,0.0001290078,3.475199e-05);
   grae->SetPoint(3,60,59.92653);
   grae->SetPointError(3,0,0,0.0002571381,1.031035e-05);
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
   grae->SetPointError(0,0,0,0.0001240556,0.0001022321);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0002830954);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001723592,0.001712747);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0003927726,0.000196556);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.0001240556,0.0001022321);
   grae->SetPoint(1,40,0.4121476);
   grae->SetPointError(1,0,0,3.961372e-05,0.0002830954);
   grae->SetPoint(2,50,0.522387);
   grae->SetPointError(2,0,0,0.001723592,0.001712747);
   grae->SetPoint(3,60,0.6019119);
   grae->SetPointError(3,0,0,0.0003927726,0.000196556);
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
   grae->SetPointError(0,0,0,0.0001576561,9.908952e-05);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.0001272642,0.0009357522);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.01126171,0.01151975);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,2.103235e-05,0.0001513857);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.0001576561,9.908952e-05);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.0001272642,0.0009357522);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.01126171,0.01151975);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,2.103235e-05,0.0001513857);
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
   grae->SetPointError(0,0,0,0.0002034146,0.0001652313);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.001210825);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.01096017,0.01109148);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.0005892971,0.0003390487);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.0002034146,0.0001652313);
   grae->SetPoint(1,40,0.8982298);
   grae->SetPointError(1,0,0,0.0001551381,0.001210825);
   grae->SetPoint(2,50,1.106017);
   grae->SetPointError(2,0,0,0.01096017,0.01109148);
   grae->SetPoint(3,60,1.193986);
   grae->SetPointError(3,0,0,0.0005892971,0.0003390487);
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
   grae->SetPointError(0,0,0,0.0001576561,9.908952e-05);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.0001272642,0.0009357522);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.01126171,0.01151975);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,2.103235e-05,0.0001513857);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.0001576561,9.908952e-05);
   grae->SetPoint(1,40,39.737);
   grae->SetPointError(1,0,0,0.0001272642,0.0009357522);
   grae->SetPoint(2,50,49.64195);
   grae->SetPointError(2,0,0,0.01126171,0.01151975);
   grae->SetPoint(3,60,59.68974);
   grae->SetPointError(3,0,0,2.103235e-05,0.0001513857);
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
   grae->SetPointError(0,0,0,0.00131443,0.0003100239);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0005309982);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.0007048926,0.00106313);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.00357452,0.003705736);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.00131443,0.0003100239);
   grae->SetPoint(1,40,2.399169);
   grae->SetPointError(1,0,0,0.0003680305,0.0005309982);
   grae->SetPoint(2,50,1.983956);
   grae->SetPointError(2,0,0,0.0007048926,0.00106313);
   grae->SetPoint(3,60,1.922008);
   grae->SetPointError(3,0,0,0.00357452,0.003705736);
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
   grae->SetPointError(0,0,0,0.000169312,1.416845e-05);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,5.396273e-05,0.0007412415);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002552561);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.002791229,0.002379577);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.000169312,1.416845e-05);
   grae->SetPoint(1,40,1.216039);
   grae->SetPointError(1,0,0,5.396273e-05,0.0007412415);
   grae->SetPoint(2,50,1.287164);
   grae->SetPointError(2,0,0,0.002682861,0.002552561);
   grae->SetPoint(3,60,1.322775);
   grae->SetPointError(3,0,0,0.002791229,0.002379577);
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
   grae->SetPointError(0,0,0,0.0003181861,0.0003723973);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.0009100234);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.004995325,0.005097642);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.0006156748,0.0002345964);
   grae->Draw("alp");
   
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
   grae->SetPointError(0,0,0,0.0003181861,0.0003723973);
   grae->SetPoint(1,40,0.6968665);
   grae->SetPointError(1,0,0,0.0001378189,0.0009100234);
   grae->SetPoint(2,50,0.7026572);
   grae->SetPointError(2,0,0,0.004995325,0.005097642);
   grae->SetPoint(3,60,0.6172068);
   grae->SetPointError(3,0,0,0.0006156748,0.0002345964);
   grae->Draw("p|>");
   C_8->Modified();
   C->cd();
   C->Modified();
   C->cd();
   C->SetSelected(C);
}
