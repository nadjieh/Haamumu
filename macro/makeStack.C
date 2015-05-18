#include <vector>
#include <iostream>
#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TColor.h"
#include "TColorWheel.h"
#include "TCanvas.h"
#include "TString.h"
using namespace std;
void makeStack(){
std::vector<TFile*> files;
std::vector<TString> names;
std::vector<TString> titles;
std::vector<Color_t> colors;
std::vector<double> weights;
int p = -7;
files.push_back(TFile::Open("rdssashaDY76.root")); names.push_back("DY"); titles.push_back("Z+jets (>50 GeV)");colors.push_back(kRed + p);weights.push_back(2.26606);
files.push_back(TFile::Open("rdssashaDYLow76.root"));names.push_back("DYLow");titles.push_back("Z+jets (10-50 GeV)");colors.push_back(kRed - 9);weights.push_back(6.88842);
files.push_back(TFile::Open("rdssashaTTF76.root"));names.push_back("TTFull");titles.push_back("t#bar{t} dilep");colors.push_back(kYellow + p);weights.push_back(0.0443774);
//files.push_back(TFile::Open("rdssashaTTS76.root"));names.push_back("TTS");titles.push_back("t#bar{t} lept");colors.push_back(kTeal + p);weights.push_back(0.195614);
files.push_back(TFile::Open("rdssashaWt76.root"));names.push_back("Wt");titles.push_back("Wt");colors.push_back(kSpring + p);weights.push_back(0.439398);
files.push_back(TFile::Open("rdssashaWtbar76.root"));names.push_back("Wtbar");titles.push_back("W#bar{t}");colors.push_back(kSpring + p);weights.push_back(0.443136);
files.push_back(TFile::Open("rdssashaWW76.root"));names.push_back("WW");titles.push_back("WW");colors.push_back(kOrange + p);weights.push_back(0.110315);
files.push_back(TFile::Open("rdssashaWZ76.root"));names.push_back("WZ");titles.push_back("WZ)");colors.push_back(kRed + p);weights.push_back(0.0661901);
files.push_back(TFile::Open("rdssashaZH12576.root"));names.push_back("ZH");titles.push_back("ZH_125");colors.push_back(kWhite);weights.push_back(0.000490794);
files.push_back(TFile::Open("rdssashaZZ76.root"));names.push_back("ZZ");titles.push_back("ZZ");colors.push_back(kMagenta + p);weights.push_back(0.0166004);

TFile * f = TFile::Open("rdssashaData76.root");
TH2D * h = (TH2D*)f->Get("step_7/step_7_Mll_DRMuMu_DRMuMuvsHamb_Mll");
TH1D* data = h->ProjectionX("data");

cout<<data->Integral()<<endl;


std::vector<TH1D*> hists;

for(unsigned int s = 0; s < files.size(); s++){
	hists.push_back(((TH2D*)files[s]->Get("step_7/step_7_Mll_DRMuMu_DRMuMuvsHamb_Mll"))->ProjectionX(names[s]));
	unsigned int s2 = hists.size() - 1;
	hists[s2]->SetFillColor(colors[s]);
	hists[s2]->SetTitle(titles[s]);
	hists[s2]->Scale(weights[s]*1.6);
}

   THStack *amassMu = new THStack();
   amassMu->SetName("amassMu");
   amassMu->SetTitle("MC stack"); 
   for(unsigned int s = 0; s < hists.size(); s++){
   	amassMu->Add(hists[s],"");   
   }
cout<<((TH1D*)amassMu->GetStack()->Last())->Integral()<<endl;

TCanvas c;
data->Draw("EHIST");
c.cd();
amassMu->Draw();
data->Draw("EHISTSAMES");
c.SaveAs("TMP.C");

}

