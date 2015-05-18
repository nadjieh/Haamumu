{
//========= Macro generated from object: TPave/Legend of markers/lines/boxes to represent obj's
//========= by ROOT version5.34/19
   
   TLegend *leg = new TLegend(0.6,0.7,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("SSVHEdiscDisc1","Data","LEP");
   entry->SetLineColor(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","ZH_125","f");
   entry->SetFillStyle(1001);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","Z+j","f");

   ci = TColor::GetColor("#ff6666");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
  
   entry=leg->AddEntry("SSVHEdiscDisc1","tW","f");

   ci = TColor::GetColor("#336600");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","t#bar{t} lept","f");

   ci = TColor::GetColor("#339966");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","t#bar{t} dilep","f");

   ci = TColor::GetColor("#ffff66");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","WW","f");

   ci = TColor::GetColor("#996633");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","WZ","f");

   ci = TColor::GetColor("#66ffff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SSVHEdiscDisc1","ZZ","f");

   ci = TColor::GetColor("#ff66ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   
   entry=leg->AddEntry("SSVHEdiscDisc1","m_{a} = 60 GeV","l");
//   entry->SetFillColor(kRed);
//   entry->SetFillStyle(1001);


   entry->SetLineColor(kRed);
   entry->SetLineStyle(9);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(kRed);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
      
   entry=leg->AddEntry("SSVHEdiscDisc1","m_{a} = 50 GeV","l");
//   entry->SetFillColor(kRed);
//   entry->SetFillStyle(1001);


   entry->SetLineColor(kBlue);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(kBlue);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   
      entry=leg->AddEntry("SSVHEdiscDisc1","m_{a} = 40 GeV","l");
//   entry->SetFillColor(kRed);
//   entry->SetFillStyle(1001);


   entry->SetLineColor(kBlack);
   //entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(kBlack);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
}
