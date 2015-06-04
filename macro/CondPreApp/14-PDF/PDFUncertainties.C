/* 
 * File:   PDFUncertainties.C
 * Author: Nadjieh
 *
 * Created on May 27, 2015, 7:14 PM
 */

#include <vector>
#include <sstream>
#include"TFile.h"
#include"TString.h"
#include"TH1.h"
#include "../../../interface/RDS.h"
#include "../../../interface/RDSData.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int step = 1000;
    std::vector<RDSData*> rds;
    std::vector<TString> names;
    TString treename = "rds_zbb";
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "treeName") {
            f++;
            std::string out(*(argv + f));
            treename = out.c_str();
        } else if (arg_fth == "step") {
            f++;
            std::string out(*(argv + f));
            step = (int) atof(out.c_str());
        } else if (arg_fth == "mc") {
            f++;
            std::string out(*(argv + f));
            TFile * fdata = TFile::Open(out.c_str());
            rds.push_back(new RDS((TTree*) fdata->Get(treename)));
            int pos = out.find("_5");
            names.push_back(out.substr(0, pos).c_str());
        }
    }
    TH1D * mass = new TH1D("eventSelectionamassMu", "", 100, 20., 70.);
    std::vector<TH1D *> pdfs;
    stringstream pdfname;
    for (int i = 0; i < 50; i++) {
        pdfname.str("");
        pdfname << "massPdf_" << i;
        TString Name = pdfname.str().c_str();
        pdfs.push_back(new TH1D(Name, "", 100, 20., 70.));
    }
    stringstream n;
    n << step;
    for (unsigned int i = 0; i < rds.size(); i++) {
        double X0 = 0;
        std::vector<double> Xpdf(50);
        cout << "before event loop " << rds[i]->fChain << endl;
        cout << rds[i]->fChain->GetEntriesFast() << endl;
        for (int iPar = 0; iPar < 50; iPar++) {
            for (int eventNumber = 0; eventNumber < rds[i]->fChain->GetEntriesFast(); eventNumber++) {
                rds[i]->GetEntry(eventNumber);
                double w0 = 1;
                double wUp = 1;
                double wDown = 1;
                w0 *= ((RDS*) rds[i])->getWeight();
                if (iPar == 0) {
                    X0 += w0;
                    mass->Fill(rds[i]->eventSelectionamassMu, w0);
                }
                if (iPar % 2 == 0) {
                    wUp *= (w0 * ((RDS*) rds[i])->GetPDFWeightXsec(iPar));
                    Xpdf[iPar] += wUp;
                    pdfs[iPar]->Fill(rds[i]->eventSelectionamassMu, wUp);
                } else {
                    wDown *= (w0 * ((RDS*) rds[i])->GetPDFWeightXsec(iPar));
                    Xpdf[iPar] += wDown;
                    pdfs[iPar]->Fill(rds[i]->eventSelectionamassMu, wDown);
                }
            }
        }
        TFile * fout = new TFile(names[i]+"_PDF.root", "recreate");
        fout->cd();
        mass->Write();
        for (unsigned int j = 0; j < pdfs.size(); j++)
            pdfs[j]->Write();
        fout->Close();
        double dXplus = 0;
        double dXminus = 0;
        for (unsigned int j = 0; j < 25; j++) {//0: minus
            cout << "UP: " << Xpdf[j + 1] << "\tDOWN: " << Xpdf[j] << endl;
            double dxp = Xpdf[j + 1] - X0;
            double dxm = Xpdf[j] - X0;
            double max = dxp;
            if (dxm > max)
                max = dxm;
            if (max < 0)
                max = 0;
            dXplus += pow(max, 2);

            max = (-dxp);
            if ((-dxm) > max)
                max = (-dxm);
            if (max < 0)
                max = 0;
            dXminus += pow(max, 2);
        }
        cout << "---- " << X0 << " + " << sqrt(dXplus) << " - " << sqrt(dXminus) << endl;
    }
    return 0;
}

