#include <string>
#include <iostream>
#include <vector>
#include <c++/4.6/bits/stl_vector.h>
#include <c++/4.6/bits/basic_string.h>
#include "TTree.h"
#include "TFile.h"
#include "TH1.h"
#include "TLorentzVector.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TColorWheel.h"
#include "TKey.h"
#include "TClass.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TString.h"

using namespace std;

/*
 * 
 */
std::vector<string> StructureFinder(TDirectory * f) {
    cout << f->GetName() << "--------------------------" << endl;
    TKey *key;
    TIter nextkey(f->GetListOfKeys());
    TDirectory * dir = 0;
    TList * l2 = 0;
    vector<string> directHists;
    directHists.clear();
    while ((key = (TKey*) nextkey())) {
        const char *classname = key->GetClassName();
        TClass *cl = gROOT->GetClass(classname);
        if (!cl) continue;
        directHists.push_back(string(key->GetName()));
    }
    return directHists;
}

int main(int argc, char** argv) {
    std::string outfilename;
    std::string run;
    std::vector<Color_t> Colors;
    std::vector<TString> names;
    std::vector<TFile*> files;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "run") {
            f++;
            std::string in(*(argv + f));
            run = in;
        } else if (arg_fth == "input") {
            f++;
            std::string in(*(argv + f));
            std::string inputfilename;
            inputfilename = "./delphesHists_" + in + "_run0" + run + ".root";
            files.push_back(TFile::Open(inputfilename.c_str()));
            if (in == "ZMuMubb")
                names.push_back("Z(#rightarrow#mu#mu)bb");
            else if ("ttDiMu")
                names.push_back("tt#rightarrow#mu#mu+jets");

            if (in == "ZMuMubb") {
                Colors.push_back(kYellow);
            } else if (in == "ttDiMu") {
                Colors.push_back(kCyan);
            }
        } else if (arg_fth == "siginput") {
            f++;
            std::string in(*(argv + f));
            std::string inputfilename;
            inputfilename = "./delphesHists_ma" + in + ".root";
            files.push_back(TFile::Open(inputfilename.c_str()));
            names.push_back(string("m_{a} = " + in + " GeV").c_str());
            if (in == "25") {
                Colors.push_back(kOrange);
            } else if (in == "30") {
                Colors.push_back(kBlue);
            } else if (in == "35") {
                Colors.push_back(kOrange);
            } else if (in == "40")
                Colors.push_back(kBlack);
            else if (in == "45")
                Colors.push_back(kAzure);
            else if (in == "50") {
                Colors.push_back(kGreen + 1);
            } else if (in == "55")
                Colors.push_back(kGray);
            else if (in == "60") {
                Colors.push_back(kRed);
            }
        } else if (arg_fth == "output") {
            f++;
            std::string in(*(argv + f));
            outfilename = in;
        }
    }
    if (files.size() == 0)
        return 0;
    if (files[0] == NULL)
        return 0;
    std::vector<string> hists = StructureFinder(files[0]);
    std::vector<double> maxima;
    for (unsigned int i = 0; i < hists.size(); i++) {
        TString name = hists[i].c_str();
        double max = 0;
        for (unsigned int j = 0; j < files.size(); j++) {
            TH1D * h = (TH1D*) files[j]->Get(name);
            if (h == NULL)
                return 0;
            h->Scale(1. / h->Integral());
            if (h->GetMaximum() > max)
                max = h->GetMaximum();
        }
        maxima.push_back(max);
    }


    TCanvas * c = 0;
    TFile * outf = new TFile(outfilename.c_str(), "recreate");
    for (unsigned int i = 0; i < hists.size(); i++) {
        TString name = hists[i].c_str();
        c = new TCanvas(name);
        c->cd();
        for (unsigned int j = 0; j < files.size(); j++) {
            cout << "File: " << files[j]->GetName() << endl;
            TH1D * h = (TH1D*) files[j]->Get(name);
            if (h == NULL)
                return 0;
            h->SetLineColor(Colors[j]);
            h->SetLineWidth(2);
            h->SetStats(kFALSE);
            h->SetTitle(names[j]);
            std::string myS = h->GetTitle();
            cout<<myS<<"\t"<<myS.find("GeV")<<endl;
            if(!(myS.find("GeV") > 0 && myS.find("GeV") < myS.size())) {
            	h->SetFillColor(Colors[j]);
            	h->SetFillStyle(3003);
            }
            if (j == 0) {
                h->SetMaximum(maxima[i] + 0.05);
                h->DrawNormalized();
            } else
                h->DrawNormalized("sames");
        }
        outf->cd();
        c->Write();
    }
    outf->Close();
    return 1;
}

