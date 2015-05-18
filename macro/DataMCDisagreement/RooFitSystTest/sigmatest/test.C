#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
#include "TF1.h"
using namespace std;

TF1 *f1, *f2;
double finter(double *x, double *par)
{
    return (f1->EvalPar(x,par) - f2->EvalPar(x,par));
}

double fint(double start,double end) {                               
       TF1 *fint = new TF1("fint",finter,start,end,0);
       double xint = fint->GetMinimumX();
       return xint;
}

int fint3 ()
{
   f1=new TF1("f1","x^2 + 4",0,10);
   f2=new TF1("f2","x + 3",0,10);
   cout << "x_int = " << fint(0,8) << endl;
}
