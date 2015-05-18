/* 
 * File:   HambHists.h
 * Author: nadjieh
 *
 * Created on August 18, 2014, 7:49 AM
 */

#ifndef HAMBHISTS_H
#define	HAMBHISTS_H
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TString.h"
#include "TDirectory.h"
#include "HambObjectProperty.h"
#include "../../Base/BaseAnalysis/interface/TH2Ext.h"
#include <vector>
#include <string>
using namespace std;

class HambHist {
public:

    HambHist(TString name, std::vector<ObjectProperty<Hamb>*> input) : Name(name) {
        for (unsigned int i = 0; i < input.size(); i++) {
            for (unsigned int j = i + 1; j < input.size(); j++) {
                correlationPlots.push_back(input[i]->GetH2(input[j],
                        string(name + "_" + input[i]->PropertyName.c_str() + "_" + input[j]->PropertyName.c_str())));
            }
        }
        int i = (int) input.size() - 1;
        while (i >= 0) {
            cout << "----- " << i << endl;
            int j = i - 1;
            while (j >= 0) {
                cout << j << endl;
                correlationPlots_inv.push_back(input[i]->GetH2(input[j],
                        string(name + "_inv_" + input[i]->PropertyName.c_str() + "_" + input[j]->PropertyName.c_str())));
                j = j - 1;
            }
            i = i - 1;
        }
    }

    virtual ~HambHist() {
        for (unsigned int s = 0; s < correlationPlots.size(); s++) {
            delete correlationPlots[s];
        }
    }

    void SetName(TString s) {
        Name = s;
    }

    TString GetName(TString s)const {
        return Name;
    }

    void Fill(Hamb * c, double weight) {
        for (unsigned int s = 0; s < correlationPlots.size(); s++) {
            correlationPlots[s]->Fill(c, weight);
        }
        for (unsigned int s = 0; s < correlationPlots_inv.size(); s++) {
            correlationPlots_inv[s]->Fill(c, weight);
        }
    }

    void WriteAll(TDirectory * d) {
        d->mkdir(Name)->cd();
        for (unsigned int s = 0; s < correlationPlots.size(); s++) {
            cout << correlationPlots[s] << endl;
            correlationPlots[s]->Write();
        }
        for (unsigned int s = 0; s < correlationPlots_inv.size(); s++) {
            cout << correlationPlots_inv[s] << endl;
            correlationPlots_inv[s]->Write();
        }
    }
private:
    TString Name;
    std::vector<TH2Ext<Hamb>*> correlationPlots;
    std::vector<TH2Ext<Hamb>*> correlationPlots_inv;
};

#endif	/* HAMBHISTS_H */

