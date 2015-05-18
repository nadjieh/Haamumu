/* 
 * File:   HambObjectProperty.h
 * Author: nadjieh
 *
 * Created on August 18, 2014, 9:00 AM
 */

#ifndef HAMBOBJECTPROPERTY_H
#define	HAMBOBJECTPROPERTY_H

#include "../../Base/BaseAnalysis/interface/ObjectProperty.h"

using namespace std;

class Hamb {
public:

    Hamb(double a, double b, double c, double d, double e) : diffMassaa(a), aMassMu(b), METsignificance_hamb(c), hMass(d), DRMu(e) {
    }
    double diffMassaa;
    double aMassMu;
    double METsignificance_hamb;
    double hMass;
    double DRMu;
};

class Mll : public ObjectProperty<Hamb> {
public:

    Mll() : ObjectProperty<Hamb>("Mll", "m_{#mu#mu}", 0., 10000., 10000, "Hamb", 1) {
    };

    virtual ~Mll() {
    };

    virtual std::vector<double> ReadValue(const Hamb * c)const {
        std::vector<double> values;
        values.clear();
        values.push_back(c->aMassMu);
        return (values);
    };
};

class DiffM : public ObjectProperty<Hamb> {
public:

    DiffM() : ObjectProperty<Hamb>("DiffM", "|m_{#mu#mu}-m_{bb}|", 0., 1000., 1000, "Hamb", 2) {
    };

    virtual ~DiffM() {
    };

    virtual std::vector<double> ReadValue(const Hamb * c)const {
        std::vector<double> values;
        values.clear();
        values.push_back(c->diffMassaa);
        return (values);
    };
};

class MetSig : public ObjectProperty<Hamb> {
public:

    MetSig() : ObjectProperty<Hamb>("MetSig", "MET Significance", 0., 1000., 1000, "Hamb", 2) {
    };

    virtual ~MetSig() {
    };

    virtual std::vector<double> ReadValue(const Hamb * c)const {
        std::vector<double> values;
        values.clear();
        values.push_back(c->METsignificance_hamb);
        return (values);
    };
};

class HiggsMass : public ObjectProperty<Hamb> {
public:

    HiggsMass() : ObjectProperty<Hamb>("HiggsMass", "mH", 0., 1000., 1000, "Hamb", 2) {
    };

    virtual ~HiggsMass() {
    };

    virtual std::vector<double> ReadValue(const Hamb * c)const {
        std::vector<double> values;
        values.clear();
        values.push_back(c->hMass);
        return (values);
    };
};

class DRMuMu : public ObjectProperty<Hamb> {
public:

    DRMuMu() : ObjectProperty<Hamb>("DRMuMu", "DRMu", 0., 10., 100, "Hamb", 2) {
    };

    virtual ~DRMuMu() {
    };

    virtual std::vector<double> ReadValue(const Hamb * c)const {
        std::vector<double> values;
        values.clear();
        values.push_back(c->DRMu);
        return (values);
    };
};
#endif	/* HAMBOBJECTPROPERTY_H */

