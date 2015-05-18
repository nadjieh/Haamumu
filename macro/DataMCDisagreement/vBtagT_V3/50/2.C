{
//=========Macro generated from canvas: c_17c5ad0_projection_2001/Canvas_1_n2
//=========  (Mon Jan 19 19:16:05 2015) by ROOT version5.34/19
   TCanvas *c_17c5ad0_projection_2001 = new TCanvas("c_17c5ad0_projection_2001", "Canvas_1_n2",13,34,700,500);
   c_17c5ad0_projection_2001->Range(2.499999,-20.74531,77.5,234.2078);
   c_17c5ad0_projection_2001->SetFillColor(0);
   c_17c5ad0_projection_2001->SetBorderMode(0);
   c_17c5ad0_projection_2001->SetBorderSize(2);
   c_17c5ad0_projection_2001->SetGridx();
   c_17c5ad0_projection_2001->SetGridy();
   c_17c5ad0_projection_2001->SetFrameBorderMode(0);
   c_17c5ad0_projection_2001->SetFrameBorderMode(0);
   
   TH1D *slice_px_of_amassMuhMass125 = new TH1D("slice_px_of_amassMuhMass125","ProjectionX of biny=[20,39] [y=19.0..39.0]",30,10,70);
   slice_px_of_amassMuhMass125->SetBinContent(0,615);
   slice_px_of_amassMuhMass125->SetBinContent(1,199);
   slice_px_of_amassMuhMass125->SetBinContent(2,101);
   slice_px_of_amassMuhMass125->SetBinContent(3,81);
   slice_px_of_amassMuhMass125->SetBinContent(4,75);
   slice_px_of_amassMuhMass125->SetBinContent(5,58);
   slice_px_of_amassMuhMass125->SetBinContent(6,52);
   slice_px_of_amassMuhMass125->SetBinContent(7,49);
   slice_px_of_amassMuhMass125->SetBinContent(8,57);
   slice_px_of_amassMuhMass125->SetBinContent(9,55);
   slice_px_of_amassMuhMass125->SetBinContent(10,46);
   slice_px_of_amassMuhMass125->SetBinContent(11,46);
   slice_px_of_amassMuhMass125->SetBinContent(12,49);
   slice_px_of_amassMuhMass125->SetBinContent(13,62);
   slice_px_of_amassMuhMass125->SetBinContent(14,57);
   slice_px_of_amassMuhMass125->SetBinContent(15,49);
   slice_px_of_amassMuhMass125->SetBinContent(16,45);
   slice_px_of_amassMuhMass125->SetBinContent(17,46);
   slice_px_of_amassMuhMass125->SetBinContent(18,46);
   slice_px_of_amassMuhMass125->SetBinContent(19,49);
   slice_px_of_amassMuhMass125->SetBinContent(20,39);
   slice_px_of_amassMuhMass125->SetBinContent(21,50);
   slice_px_of_amassMuhMass125->SetBinContent(22,31);
   slice_px_of_amassMuhMass125->SetBinContent(23,47);
   slice_px_of_amassMuhMass125->SetBinContent(24,34);
   slice_px_of_amassMuhMass125->SetBinContent(25,30);
   slice_px_of_amassMuhMass125->SetBinContent(26,14);
   slice_px_of_amassMuhMass125->SetBinContent(27,25);
   slice_px_of_amassMuhMass125->SetBinContent(28,29);
   slice_px_of_amassMuhMass125->SetBinContent(29,38);
   slice_px_of_amassMuhMass125->SetBinContent(30,33);
   slice_px_of_amassMuhMass125->SetBinContent(31,4689);
   slice_px_of_amassMuhMass125->SetEntries(6896);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("slice_px_of_amassMuhMass125");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 6896   ");
   text = ptstats->AddText("Mean  =  32.99");
   text = ptstats->AddText("RMS   =  17.55");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   slice_px_of_amassMuhMass125->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(slice_px_of_amassMuhMass125);
   slice_px_of_amassMuhMass125->SetFillColor(38);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   slice_px_of_amassMuhMass125->SetLineColor(ci);
   slice_px_of_amassMuhMass125->GetXaxis()->SetRange(1,30);
   slice_px_of_amassMuhMass125->GetXaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass125->GetXaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass125->GetXaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass125->GetXaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass125->GetYaxis()->SetTitle("Number of Entries");
   slice_px_of_amassMuhMass125->GetYaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass125->GetYaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass125->GetYaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass125->GetYaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass125->GetZaxis()->SetLabelFont(42);
   slice_px_of_amassMuhMass125->GetZaxis()->SetLabelSize(0.035);
   slice_px_of_amassMuhMass125->GetZaxis()->SetTitleSize(0.035);
   slice_px_of_amassMuhMass125->GetZaxis()->SetTitleFont(42);
   slice_px_of_amassMuhMass125->Draw("");
   
   TPaveText *pt = new TPaveText(0.1566667,0.9342405,0.8433333,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("ProjectionX of biny=[20,39] [y=19.0..39.0]");
   pt->Draw();
   c_17c5ad0_projection_2001->Modified();
   c_17c5ad0_projection_2001->cd();
   c_17c5ad0_projection_2001->SetSelected(c_17c5ad0_projection_2001);
}
