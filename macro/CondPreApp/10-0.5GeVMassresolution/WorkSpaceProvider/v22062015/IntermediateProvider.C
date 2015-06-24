#include "WSProvider.h"
using namespace std;

int main(int argc, char** argv) {
    double sigNormUnc = 0;
    for (int f = 1; f < argc; f++) {
        std::string arg_fth(*(argv + f));
        if (arg_fth == "sigNormUnc") {
            f++;
            std::string out(*(argv + f));
            sigNormUnc = std::atof(out.c_str());
        }
    }
    MeanErr meanerrors;
    meanerrors["a1"] = make_pair(0.010, make_pair(0.0065,0.0065));
    meanerrors["b1"] = make_pair(0.0184, make_pair(0.00985, 0.00985));
    meanerrors["m1"] = make_pair(0.9978, make_pair(0.015,0.015));
    FixedParams fixes;
    fixes["alpha"] = 1.13;
    fixes["width"] = 0.0286;
    fixes["n"] = 2.97;
    fixes["frac"] = 0.577;
    //for (double i = 25.; i < 65; i += 0.5) {
    //for (double i = 30.; i < 30.01; i += 0.5) {
    //	double i = 28;
        WSProvider * myprovider = new WSProvider(meanerrors, fixes, sigNormUnc);
        myprovider->WriteWS();
        delete myprovider;
    //}



    return 0;
}
