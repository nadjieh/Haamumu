/* 
 * File:   MassInterpolator.h
 * Author: nadjieh
 *
 * Created on May 5, 2015, 5:35 PM
 */

#ifndef MASSINTERPOLATOR_H
#define	MASSINTERPOLATOR_H
#include <vector>
#include <sstream>
#include <iostream>
#include "TF1.h"
#include "TString.h"
#include "RooAddPdf.h"
#include "RooVoigtian.h"
#include "RooCBShape.h"
#include "RooRealVar.h"
using namespace std;
class MassInterpolator {
public:

    MassInterpolator(std::map<TString, TF1*> paramf, std::map<TString, std::pair<double, double> > errs) {
        var = new RooRealVar("eventSelectionamassMu", "eventSelectionamassMu", 20., 70.);
        std::map<TString, TF1*>::const_iterator it = paramf.begin();
        for(; it != paramf.end(); it++){
            paramFunctions[it->first] = it->second;
        }
        std::map<TString, TF1*>::const_iterator itt = errs.begin();
        for(; itt != errs.end(); itt++){
            paramErrors[itt->first] = itt->second;
        }
    }

    ~MassInterpolator() {
    }

    RooAddPdf * A1MassShapeConstructor(double mass) {
        stringstream massstr;
        massstr << mass;
        TString massTS = massstr.str().c_str();
        RooRealVar * mean = new RooRealVar("mean" + massTS, "mean" + massTS, paramFunctions["mean"]->Eval(mass), paramFunctions["mean"]->Eval(mass) - paramErrors["mean"].first, paramFunctions["mean"]->Eval(mass) + paramErrors["mean"].second);
        RooRealVar * sigma = new RooRealVar("sigma" + massTS, "sigma" + massTS, paramFunctions["sigma"]->Eval(mass), paramFunctions["sigma"]->Eval(mass) - paramErrors["mean"].first, paramFunctions["mean"]->Eval(mass) + paramErrors["sigma"].second);
        RooRealVar * width = new RooRealVar("width" + massTS, "width" + massTS, paramFunctions["width"]->Eval(mass), paramFunctions["width"]->Eval(mass) - paramErrors["width"].first, paramFunctions["width"]->Eval(mass) + paramErrors["width"].second);
        RooVoigtian * Voig = new RooVoigtian("Voig" + massTS, "Voig" + massTS, *var, *mean, *width, *sigma);

        RooRealVar * mean_cb = new RooRealVar("mean_cb" + massTS, "Mean" + massTS, paramFunctions["mean_cb"]->Eval(mass), paramFunctions["mean_cb"]->Eval(mass) - paramErrors["mean_cb"].first, paramFunctions["mean_cb"]->Eval(mass) + paramErrors["mean_cb"].second);
        RooRealVar * sigma_cb = new RooRealVar("sigma_cb" + massTS, "Width" + massTS, paramFunctions["sigma_cb"]->Eval(mass), paramFunctions["sigma_cb"]->Eval(mass) - paramErrors["sigma_cb"].first, paramFunctions["sigma_cb"]->Eval(mass) + paramErrors["sigma_cb"].second);
        RooRealVar * n = new RooRealVar("n" + massTS, "n" + massTS, paramFunctions["n"]->Eval(mass), paramFunctions["n"]->Eval(mass) - paramErrors["n"].first, paramFunctions["n"]->Eval(mass) + paramErrors["n"].second);
        RooRealVar * alpha = new RooRealVar("alpha" + massTS, "alpha" + massTS, paramFunctions["alpha"]->Eval(mass), paramFunctions["alpha"]->Eval(mass) - paramErrors["alpha"].first, paramFunctions["alpha"]->Eval(mass) + paramErrors["alpha"].second);
        RooCBShape * CB = new RooCBShape("cball", "crystal ball", *var, *mean_cb, *sigma_cb, *alpha, *n);
        RooRealVar * frac = new RooRealVar("frac", "frac", paramFunctions["frac"]->Eval(mass), paramFunctions["frac"]->Eval(mass) - paramErrors["frac"].first, paramFunctions["frac"]->Eval(mass) + paramErrors["frac"].second);
        RooAddPdf * Voig2 = new RooAddPdf("sum" + massTS, "Gaussian crystal ball and Voig PDF", RooArgList(*Voig, *CB), RooArgList(*frac));
        return Voig2;
    }
private:
    /*
     * each entry is a TF1 modeling the parameter over the mass range.
     */
    std::map<TString, TF1*> paramFunctions;
    /*
     * each entry is an down/up (syst+stat) uncertainty for the parameter over the mass range.
     * numbers are all positive
     */
    std::map<TString, std::pair<double, double> > paramErrors;
    RooRealVar * var;
};


#endif	/* MASSINTERPOLATOR_H */

