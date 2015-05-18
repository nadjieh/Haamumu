{
//=========Macro generated from canvas: c_17c5ad0_projection_2001/Canvas_1_n2
//=========  (Mon Jan 19 19:15:50 2015) by ROOT version5.34/19
   TCanvas *c_17c5ad0_projection_2001 = new TCanvas("c_17c5ad0_projection_2001", "Canvas_1_n2",13,34,700,500);
   c_17c5ad0_projection_2001->Range(2.499999,-5.745314,77.5,249.2078);
   c_17c5ad0_projection_2001->SetFillColor(0);
   c_17c5ad0_projection_2001->SetBorderMode(0);
   c_17c5ad0_projection_2001->SetBorderSize(2);
   c_17c5ad0_projection_2001->SetGridx();
   c_17c5ad0_projection_2001->SetGridy();
   c_17c5ad0_projection_2001->SetFrameBorderMode(0);
   c_17c5ad0_projection_2001->SetFrameBorderMode(0);
   
   TH1D *slice_px_of_amassMuhMass123 = new TH1D("slice_px_of_amassMuhMass123","ProjectionX of biny=[0,19] [y=-1.0..19.0]",30,10,70);
   slice_px_of_amassMuhMass123->SetBinContent(0,778);
   slice_px_of_amassMuhMass123->SetBinContent(1,214);
   slice_px_of_amassMuhMass123->SetBinContent(2,106);
   slice_px_of_amassMuhMass123->SetBinContent(3,94);
   slice_px_of_amassMuhMass123->SetBinContent(4,90);
   slice_px_of_amassMuhMass123->SetBinContent(5,76);
   slice_px_of_amassMuhMass123->SetBinContent(6,56);
   slice_px_of_amassMuhMass123->SetBinContent(7,47);
   slice_px_of_amassMuhMass123->SetBinContent(8,70);
   slice_px_of_amassMuhMass123->SetBinContent(9,68);
   slice_px_of_amassMuhMass123->SetBinContent(10,66);
   slice_px_of_amassMuhMass123->SetBinContent(11,45);
   slice_px_of_amassMuhMass123->SetBinContent(12,60);
   slice_px_of_amassMuhMass123->SetBinContent(13,67);
   slice_px_of_amassMuhMass123->SetBinContent(14,83);
   slice_px_of_amassMuhMass123->SetBinContent(15,64);
   slice_px_of_amassMuhMass123->SetBinContent(16,59);
   slice_px_of_amassMuhMass123->SetBinContent(17,65);
   slice_px_of_amassMuhMass123->SetBinContent(18,58);
   slice_px_of_amassMuhMass123->SetBinContent(19,55);
   slice_px_of_amassMuhMass123->SetBinContent(20,57);
   slice_px_of_amassMuhMass123->SetBinContent(21,43);
   slice_px_of_amassMuhMass123->SetBinContent(22,51);
   slice_px_of_amassMuhMass123->SetBinContent(23,42);
   slice_px_of_amassMuhMass123->SetBinContent(24,45);
   slice_px_of_amassMuhMass123->SetBinContent(25,47);
   slice_px_of_amassMuhMass123->SetBinContent(26,38);
   slice_px_of_amassMuhMass123->SetBinContent(27,32);
   slice_px_of_amassMuhMass123->SetBinContent(28,33);
   slice_px_of_amassMuhMass123->SetBinContent(29,30);
   slice_px_of_amassMuhMass123->SetBinContent(30,29);
   slice_px_of_amassMuhMass123->SetBinContent(31,1693);
   slice_px_of_amassMuhMass123->SetEntries(4361);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("slice_px_of_amassMuhMass123");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 4361   ");
   text = ptstats->AddText("Mean  =  33.54");
   text = ptstats->AddText("RMS   =  17.21");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   slice_px_of_amassMuhMass123->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(slice_px_of_amassMuhMass123);
   slice_px_of_amassMuhMass123->SetFillColor(38);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   slice_px_of_amassMuhMass123->SetLineColor(ci);
   slice_px_of_amassMuhMass123->GetXaxis()->SetRange(1,30);
   slice_px_of_amassMuhMass123->GetXaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass123->GetXaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass123->GetXaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass123->GetXaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass123->GetYaxis()->SetTitle("Number of Entries");
   slice_px_of_amassMuhMass123->GetYaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass123->GetYaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass123->GetYaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass123->GetYaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass123->GetZaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass123->GetZaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass123->GetZaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass123->GetZaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass123->Draw("");
   
   TPaveText *pt = new TPaveText(0.1695977,0.9342405,0.8304023,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("ProjectionX of biny=[0,19] [y=-1.0..19.0]");
   pt->Draw();
   c_17c5ad0_projection_2001->Modified();
   c_17c5ad0_projection_2001->cd();
   c_17c5ad0_projection_2001->SetSelected(c_17c5ad0_projection_2001);
}
