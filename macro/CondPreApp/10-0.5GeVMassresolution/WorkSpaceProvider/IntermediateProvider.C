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
    meanerrors["a1"] = make_pair(0.009, make_pair(0.0001,0.0001));
    meanerrors["b1"] = make_pair(0.0166, make_pair(0.0002, 0.0002));
    meanerrors["m1"] = make_pair(-0.063, make_pair(0.0038,0.0038));
    FixedParams fixes;
    fixes["alpha"] = 1.06;
    fixes["width"] = 0.035;
    fixes["n"] = 3.22;
    fixes["frac"] = 0.607;
    //for (double i = 25.; i < 65; i += 0.5) {
    //for (double i = 30.; i < 30.01; i += 0.5) {
    //	double i = 28;
        WSProvider * myprovider = new WSProvider(meanerrors, fixes, sigNormUnc);
        myprovider->WriteWS();
        delete myprovider;
    //}



    return 0;
}
