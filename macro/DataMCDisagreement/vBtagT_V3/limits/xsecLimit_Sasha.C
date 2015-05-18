{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Wed Jan  7 17:34:19 2015) by ROOT version5.34/19
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",3,24,700,502);
   c1_n2->Range(26.55,-12.5,63.45,112.5);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4);
   grae->SetName("g2");
   grae->SetTitle("Expected 2 #sigma");
   grae->SetFillColor(3);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,6.477081,18.57393);
   grae->SetPoint(1,40,16.82812);
   grae->SetPointError(1,0,0,8.775604,24.42831);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,8.079071,22.70871);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,7.72728,21.3275);
   
   TH1F *Graph_g21 = new TH1F("Graph_g21","Expected 2 #sigma",100,27,63);
   Graph_g21->SetMinimum(0);
   Graph_g21->SetMaximum(100);
   Graph_g21->SetDirectory(0);
   Graph_g21->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g21->SetLineColor(ci);
   Graph_g21->GetXaxis()->SetRange(10,91);
   Graph_g21->GetXaxis()->SetLabelFont(42);
   Graph_g21->GetXaxis()->SetLabelSize(0.035);
   Graph_g21->GetXaxis()->SetTitleSize(0.035);
   Graph_g21->GetXaxis()->SetTitleFont(42);
   Graph_g21->GetYaxis()->SetLabelFont(42);
   Graph_g21->GetYaxis()->SetLabelSize(0.035);
   Graph_g21->GetYaxis()->SetTitleSize(0.035);
   Graph_g21->GetYaxis()->SetTitleFont(42);
   Graph_g21->GetZaxis()->SetLabelFont(42);
   Graph_g21->GetZaxis()->SetLabelSize(0.035);
   Graph_g21->GetZaxis()->SetTitleSize(0.035);
   Graph_g21->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g21);
   
   grae->Draw("ap3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g1");
   grae->SetTitle("Expected 1 #sigma");
   grae->SetFillColor(5);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,4.174682,7.223644);
   grae->SetPoint(1,40,16.82812);
   grae->SetPointError(1,0,0,5.587592,9.457947);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,5.144096,8.897409);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,4.920104,8.390963);
   
   TH1F *Graph_g12 = new TH1F("Graph_g12","Expected 1 #sigma",100,27,63);
   Graph_g12->SetMinimum(6.340175);
   Graph_g12->SetMaximum(28.09933);
   Graph_g12->SetDirectory(0);
   Graph_g12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g12->SetLineColor(ci);
   Graph_g12->GetXaxis()->SetLabelFont(42);
   Graph_g12->GetXaxis()->SetLabelSize(0.035);
   Graph_g12->GetXaxis()->SetTitleSize(0.035);
   Graph_g12->GetXaxis()->SetTitleFont(42);
   Graph_g12->GetYaxis()->SetLabelFont(42);
   Graph_g12->GetYaxis()->SetLabelSize(0.035);
   Graph_g12->GetYaxis()->SetTitleSize(0.035);
   Graph_g12->GetYaxis()->SetTitleFont(42);
   Graph_g12->GetZaxis()->SetLabelFont(42);
   Graph_g12->GetZaxis()->SetLabelSize(0.035);
   Graph_g12->GetZaxis()->SetTitleSize(0.035);
   Graph_g12->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g12);
   
   grae->Draw("p3");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("g00");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   grae->SetPoint(0,30,12.32812);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,39.96336,17.03586);
   grae->SetPointError(1,0,0,0,0);
   grae->SetPoint(2,50,15.60938);
   grae->SetPointError(2,0,0,0,0);
   grae->SetPoint(3,60,14.92969);
   grae->SetPointError(3,0,0,0,0);
   
   TH1F *Graph_g003 = new TH1F("Graph_g003","Graph",100,27,63);
   Graph_g003->SetMinimum(11.87812);
   Graph_g003->SetMaximum(17.27812);
   Graph_g003->SetDirectory(0);
   Graph_g003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_g003->SetLineColor(ci);
   Graph_g003->GetXaxis()->SetLabelFont(42);
   Graph_g003->GetXaxis()->SetLabelSize(0.035);
   Graph_g003->GetXaxis()->SetTitleSize(0.035);
   Graph_g003->GetXaxis()->SetTitleFont(42);
   Graph_g003->GetYaxis()->SetLabelFont(42);
   Graph_g003->GetYaxis()->SetLabelSize(0.035);
   Graph_g003->GetYaxis()->SetTitleSize(0.035);
   Graph_g003->GetYaxis()->SetTitleFont(42);
   Graph_g003->GetZaxis()->SetLabelFont(42);
   Graph_g003->GetZaxis()->SetLabelSize(0.035);
   Graph_g003->GetZaxis()->SetTitleSize(0.035);
   Graph_g003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g003);
   
   grae->Draw("PC");
   //=================================
   double median[3] = {18.5,17.5,8.2};   
   double sigma1m[3] = {10.2,9.5,4.3};
   double sigma1p[3] = {26.2,27.8,12.6};             
   double sigma2m[3] = {6.6,6.9,3.0};   
   double sigma2p[3] = {30.8,38.8,18.6};
   double y[3];
   double el1[3];
   double eh1[3];
   double el2[3];
   double eh2[3];  
   double xsec = 2;
   for(int i = 0; i < 3; i++){
   	el1[i] = xsec*fabs(sigma1m[i]-median[i]);
   	eh1[i] = xsec*fabs(sigma1p[i]-median[i]);   
   	el2[i] = xsec*fabs(sigma2m[i]-median[i]);
   	eh2[i] = xsec*fabs(sigma2p[i]-median[i]); 
   	y[i] = xsec * median[i];
   } 
   //=================================
   double massesX[3] = {40.,50.,60};
   double eX[3] = {0.,0.,0};
   TGraph* sasha0 = new TGraph(3, massesX,y);
   sasha0->SetLineWidth(3);
   sasha0->SetLineStyle(2);
   TGraphAsymmErrors* sasha1 = new TGraphAsymmErrors(3, massesX,y,eX,eX, el1,eh1);  
   sasha1->SetFillColor(kOrange);       
   //sasha1->SetFillStyle(3023);        
   TGraphAsymmErrors* sasha2 = new TGraphAsymmErrors(3, massesX,y,eX,eX, el2,eh2); 
   sasha2->SetFillColor(kAzure+5);     
   sasha2->SetFillStyle(3008);
   sasha2->Draw("p3");
   sasha1->Draw("p3");   
   sasha0->Draw("pc");   
   TPaveText *pt = new TPaveText(0.3808046,0.9342405,0.6191954,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Expected 2 #sigma");
   pt->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
