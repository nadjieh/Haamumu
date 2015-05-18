/* 
 * File:   AccommulativeSelection.h
 * Author: nadjieh
 *
 * Created on September 22, 2014, 10:56 AM
 */

#ifndef ACCOMMULATIVESELECTION_H
#define	ACCOMMULATIVESELECTION_H
#include "RDS.h"
#include "TString.h"
#include "TTree.h"
#include "TDirectory.h"
#include "TH1.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class AccommulativeSelection {
public:

    AccommulativeSelection(TString name_, TString var, TTree * tree, double xlow, double xhigh, int nStep, int br = 4,
            double signalmass = -1.) :
    name(name_), variable(var), xL(xlow), xH(xhigh), steps(nStep), baseRegion(br), smass(signalmass) {
        rds = new RDS(tree);
        values = new double[nStep];
        for (int i = 0; i < nStep; i++)
            values[i] = 0;
        hist = new TH1D(name, name, steps, xL, xH);
    }

    ~AccommulativeSelection() {
        delete rds;
        delete values;
    }

    void Count(bool greater = true, double weight = 1.) {
        double delta = (xH - xL) / steps;
        for (int iEvt = 0; iEvt < rds->fChain->GetEntriesFast(); iEvt++) {
            rds->GetEntry(iEvt);
            if (smass == 20.) {
                if (rds->eventSelectionmu1pt < 25.)
                    continue;
                if (rds->eventSelectionmu2pt < 8.)
                    continue;
                if (rds->jetmetjet1pt < 25.)
                    continue;
                if (rds->jetmetjet2pt < 15.)
                    continue;
                if (rds->eventSelectionMETsignificance_hamb > 6.)
                    continue;
                //                if (fabs(rds->eventSelectiondiffMassaa) > 15.)
                //                    continue;
                //if (fabs(rds->eventSelectionhMass - 125.) > 15.)//22.-15
                //    continue;
                if (!(rds->eventSelectionamassMu > 10. && rds->eventSelectionamassMu < 30.))
                    continue;
            }
            if (smass == 30.) {
                //                cout<<"I am here"<<endl;
                if (rds->eventSelectionmu1pt < 26.)
                    continue;
                if (rds->eventSelectionmu2pt < 10.)
                    continue;
                if (rds->jetmetjet1pt < 15.)
                    continue;
                if (rds->jetmetjet2pt < 15.)
                    continue;
                if (rds->eventSelectionMETsignificance_hamb > 6.)
                    continue;
                //                if (fabs(rds->eventSelectiondiffMassaa) > 10.)
                //                    continue;
                if (fabs(rds->eventSelectionhMass - 125.) > 25.)//22.-15
                    continue;
                if (!(rds->eventSelectionamassMu > 20. && rds->eventSelectionamassMu < 40.))
                    continue;
            }
            if (smass == 40.) {
                if (rds->eventSelectionmu1pt < 30.)
                    continue;
                if (rds->eventSelectionmu2pt < 17.)
                    continue;
                if (rds->jetmetjet1pt < 20.)
                    continue;
                if (rds->jetmetjet2pt < 15.)
                    continue;
                if (rds->eventSelectionMETsignificance_hamb > 6.)
                    continue;
                //                if (fabs(rds->eventSelectiondiffMassaa) > 10.)//15
                //                    continue;
                if (fabs(rds->eventSelectionhMass - 125.) > 18.)//22.-15
                    continue;
                if (!(rds->eventSelectionamassMu > 30. && rds->eventSelectionamassMu < 50.))
                    continue;
            }
            if (smass == 50.) {

                if (rds->eventSelectionmu1pt < 23.)
                    continue;
                if (rds->eventSelectionmu2pt < 10.)
                    continue;
                if (rds->jetmetjet1pt < 23.)
                    continue;
                if (rds->jetmetjet2pt < 20.)
                    continue;
                if (rds->eventSelectionMETsignificance_hamb > 6.)
                    continue;
                //                if (fabs(rds->eventSelectiondiffMassaa) > 12.)
                //                    continue;
                if (fabs(rds->eventSelectionhMass - 125.) > 18.)//22-20.
                    continue;
                if (!(rds->eventSelectionamassMu > 40. && rds->eventSelectionamassMu < 60.))
                    continue;
            }
            if (smass == 60.) {

                if (rds->eventSelectionmu1pt < 17.)
                    continue;
                if (rds->eventSelectionmu2pt < 10.)
                    continue;
                if (rds->jetmetjet1pt < 25.)
                    continue;
                if (rds->jetmetjet2pt < 20.)
                    continue;
                if (rds->eventSelectionMETsignificance_hamb > 6.)
                    continue;
                //                if (fabs(rds->eventSelectiondiffMassaa) > 16.)
                //                continue;
                if (fabs(rds->eventSelectionhMass - 125.) > 20.)//23-20.
                    continue;
                if (!(rds->eventSelectionamassMu > 50. && rds->eventSelectionamassMu < 70.))
                    continue;
            }
            if (rds->jetmetjet1CSVdisc > rds->jetmetjet2CSVdisc) {
                if (!(rds->jetmetjet1CSVdisc > 0.898))
                    continue;
            } else {
                if (!(rds->jetmetjet2CSVdisc > 0.898))
                    continue;
            }

            if (!(rds->eventSelectionamassMu > 20. && rds->eventSelectionamassMu < 70.))
                continue;


            if (baseRegion != -1) {
                if (!rds->isInRegion(baseRegion))
                    continue;
            }
            for (int i = 0; i < steps; i++) {
                double cut = xL + (i * delta);
                if (CutParserEvaluator(cut, greater)) {
                    values[i]++;
                }
            }
            if (variable == "MET_hamb")
                hist->Fill(rds->eventSelectionMET_hamb, weight);
            if (variable == "METsignificance_hamb")
                hist->Fill(rds->eventSelectionMETsignificance_hamb, weight);
            if (variable == "dphiaa")
                hist->Fill(rds->eventSelectiondphiaa, weight);
            if (variable == "aadR")
                hist->Fill(rds->eventSelectionaadR, weight);
            if (variable == "dphiHiggsMET")
                hist->Fill(rds->eventSelectiondphiHiggsMET, weight);
            if (variable == "dphiaMuMET")
                hist->Fill(rds->eventSelectiondphiaMuMET, weight);
            if (variable == "dphidiMu")
                hist->Fill(rds->eventSelectiondphidiMu, weight);
            if (variable == "dphiaBjetMET")
                hist->Fill(rds->eventSelectiondphiaBjetMET, weight);
            if (variable == "dphidiBjet")
                hist->Fill(rds->eventSelectiondphidiBjet, weight);
            if (variable == "diffMassaa")
                hist->Fill(fabs(rds->eventSelectiondiffMassaa), weight);
            if (variable == "mu1pt")
                hist->Fill(rds->eventSelectionmu1pt, weight);
            if (variable == "mu2pt")
                hist->Fill(rds->eventSelectionmu2pt, weight);
            if (variable == "jet1pt")
                hist->Fill(rds->jetmetjet1pt, weight);
            if (variable == "jet2pt")
                hist->Fill(rds->jetmetjet2pt, weight);
            if (variable == "hMass")
                hist->Fill(fabs(rds->eventSelectionhMass - 125.), weight);
            if (variable == "jet1CSV") {
                if (rds->jetmetjet1CSVdisc > rds->jetmetjet2CSVdisc)
                    hist->Fill(rds->jetmetjet1CSVdisc, weight);
                else
                    hist->Fill(rds->jetmetjet2CSVdisc, weight);
            }
            if (variable == "jet2CSV") {
                if (rds->jetmetjet1CSVdisc < rds->jetmetjet2CSVdisc)
                    hist->Fill(rds->jetmetjet1CSVdisc, weight);
                else
                    hist->Fill(rds->jetmetjet2CSVdisc, weight);
            }
        }
    }

    bool CutParserEvaluator(double cut, bool greater = true) {
        bool ret = true;
        if (variable == "MET_hamb") {
            if (greater)
                ret = (rds->eventSelectionMET_hamb) > cut;
            else
                ret = (rds->eventSelectionMET_hamb) < cut;
        }
        if (variable == "METsignificance_hamb") {
            if (greater)
                ret = (rds->eventSelectionMETsignificance_hamb) > cut;
            else
                ret = (rds->eventSelectionMETsignificance_hamb) < cut;
        }
        if (variable == "dphiaa") {
            if (greater)
                ret = (rds->eventSelectiondphiaa) > cut;
            else
                ret = (rds->eventSelectiondphiaa) < cut;
        }
        if (variable == "aadR") {
            if (greater)
                ret = (rds->eventSelectionaadR) > cut;
            else
                ret = (rds->eventSelectionaadR) < cut;
        }
        if (variable == "dphiHiggsMET") {
            if (greater)
                ret = (rds->eventSelectiondphiHiggsMET) > cut;
            else
                ret = (rds->eventSelectiondphiHiggsMET) < cut;
        }
        if (variable == "dphiaMuMET") {
            if (greater)
                ret = (rds->eventSelectiondphiaMuMET) > cut;
            else
                ret = (rds->eventSelectiondphiaMuMET) < cut;
        }
        if (variable == "dphidiMu") {
            if (greater)
                ret = (rds->eventSelectiondphidiMu) > cut;
            else
                ret = (rds->eventSelectiondphidiMu) < cut;
        }
        if (variable == "dphiaBjetMET") {
            if (greater)
                ret = (rds->eventSelectiondphiaBjetMET) > cut;
            else
                ret = (rds->eventSelectiondphiaBjetMET) < cut;
        }
        if (variable == "dphidiBjet") {
            if (greater)
                ret = (rds->eventSelectiondphidiBjet) > cut;
            else
                ret = (rds->eventSelectiondphidiBjet) < cut;
        }
        if (variable == "diffMassaa") {
            if (greater)
                ret = (fabs(rds->eventSelectiondiffMassaa)) > cut;
            else
                ret = (fabs(rds->eventSelectiondiffMassaa)) < cut;
        }
        if (variable == "hMass") {
            ret = (fabs(rds->eventSelectionhMass - 125.) < cut);
        }
        if (variable == "mu1pt") {
            ret = (rds->eventSelectionmu1pt) > cut;
        }
        if (variable == "mu2pt") {
            ret = (rds->eventSelectionmu2pt) > cut;
        }
        if (variable == "jet1pt") {
            ret = (rds->jetmetjet1pt) > cut;
        }
        if (variable == "jet2pt") {
            ret = (rds->jetmetjet2pt) > cut;
        }
        if (variable == "jet1CSV") {
            if (rds->jetmetjet1CSVdisc > rds->jetmetjet2CSVdisc)
                ret = (rds->jetmetjet1CSVdisc) > cut;
            else
                ret = (rds->jetmetjet2CSVdisc) > cut;
        }
        if (variable == "jet2CSV") {
            if (rds->jetmetjet1CSVdisc < rds->jetmetjet2CSVdisc)
                ret = (rds->jetmetjet1CSVdisc) > cut;
            else
                ret = (rds->jetmetjet2CSVdisc) > cut;
        }
        return ret;
    }

    double* GetYields()const {
        return values;
    }

    int nSteps()const {
        return steps;
    }

    TH1D * GetHist()const {
        return hist;
    }
private:
    TString name;
    TString variable;
    RDS * rds;
    double xL;
    double xH;
    int steps;
    int baseRegion;
    double smass;
    TH1D * hist;
    double * values;
};

class Optimizer {
public:

    Optimizer(TString name_, TString var, TTree * treeSignal, std::vector<TTree*> treeBackgrounds, double xlow, double xhigh, int nStep, int br = 4,
            double smass = -1.) : name(name_) {
        signal = new AccommulativeSelection(name + "_signal", var, treeSignal, xlow, xhigh, nStep, br, smass);
        stringstream s;
        for (unsigned int i = 0; i < treeBackgrounds.size(); i++) {
            s.str("");
            s << name << "_background" << i;
            backgrounds.push_back(new AccommulativeSelection(s.str().c_str(), var, treeBackgrounds.at(i), xlow, xhigh, nStep, br, smass));
        }
        cout << "--- " << backgrounds.size() << endl;
        hSig = new TH1D(name + "_signalCount", "signal count", nStep, xlow, xhigh);
        hBkg = new TH1D(name + "_bkgCount", "backgrounds count", nStep, xlow, xhigh);
        hSqrtSpB = new TH1D(name + "_hSqrtSpB", "#sqrt{s+b}", nStep, xlow, xhigh);
    }

    void Count(bool greater = true) {
        if (myWeights.size() != 0) {
            cout << "signal weight " << myWeights[0] << endl;
            signal->Count(greater, myWeights[0]);
        } else
            signal->Count(greater);
        for (unsigned int i = 0; i < backgrounds.size(); i++) {
            if (myWeights.size() != 0) {
                cout << "bkg weight " << i + 1 << "\t" << myWeights[i + 1] << endl;
                backgrounds[i]->Count(greater, myWeights[i + 1]);
            } else
                backgrounds[i]->Count(greater);
        }
    }

    void Fill(std::vector<double> weights, bool greater = true) {//0: signal, rest: bkgs
        int n = signal->nSteps();
        myWeights.clear();
        for (unsigned int s = 0; s < weights.size(); s++)
            myWeights.push_back(weights[s]);
        cout << "--- " << myWeights.size() << endl;
        this->Count(greater);

        double* signals = signal->GetYields();
        for (int i = 0; i < n; i++) {
            hSig->SetBinContent(i + 1, signals[i]);
        }
        if (weights.size() != 0)
            hSig->Scale(weights[0]);

        std::vector<double*> bkgs;
        for (unsigned int i = 0; i < backgrounds.size(); i++) {
            bkgs.push_back(backgrounds[i]->GetYields());
        }
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (unsigned int j = 0; j < bkgs.size(); j++) {
                if (weights.size() != 0) {
                    sum += (bkgs[j][i]) * weights[j + 1];
                } else {
                    sum += (bkgs[j][i]);
                }
            }
            hBkg->SetBinContent(i + 1, sum);
            hSqrtSpB->SetBinContent(i + 1, sqrt(sum + hSig->GetBinContent(i + 1)));
        }
    }

    void Write(TDirectory * d) {
        TH1D * sumBkg = (TH1D*) backgrounds[0]->GetHist()->Clone("sumBkg");
        TH1D * soverb = (TH1D*) hSig->Clone(name + "_SoverB");
        TH1D * significance = (TH1D*) hSig->Clone(name + "_significance");
        soverb->Divide(hBkg);
        significance->Divide(hSqrtSpB);
        d->cd();
        hSig->Write();
        hBkg->Write();
        hSqrtSpB->Write();
        signal->GetHist()->Write();
        for (int i = 0; i < backgrounds.size(); i++) {
            backgrounds[i]->GetHist()->Write();
            if (i > 0)
                sumBkg->Add(backgrounds[i]->GetHist());
        }
        sumBkg->Write();
        soverb->Write();
        significance->Write();
        d->cd();
    }

    ~Optimizer() {
        delete signal;
        for (unsigned int i = 0; i < backgrounds.size(); i++)
            delete backgrounds[i];
    }
private:
    TString name;
    AccommulativeSelection * signal;
    std::vector<AccommulativeSelection *> backgrounds;
    TH1D * hSig;
    TH1D * hBkg;
    TH1D * hSqrtSpB;
    std::vector<double> myWeights;
};
#endif	/* ACCOMMULATIVESELECTION_H */

/*
 * if (rds->eventSelectionmu1pt < 25.)
                continue;
            if (fabs(rds->eventSelectionmu1eta) > 2.1)
                continue;
            if (rds->eventSelectionmu2pt < 10.)
                continue;
            if (rds->jetmetjet1pt < 20.)
                continue;
            if (fabs(rds->jetmetjet1eta) > 2.0)
                continue;
            if (rds->jetmetjet2pt < 18.)
                continue;
            if (!(rds->jetmetjet1CSVdisc > 0.679))
                continue;
            if (fabs(rds->eventSelectiondiffMassaa) > 15.)
                continue;
            if (fabs(rds->eventSelectionhMass - 125.) > 15.)
                continue;
            if (rds->eventSelectionhPt > 70.)
                continue;
 */
