./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 20. AddCut 40.
mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_CR_4_4.root
./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut -1. AddCut 40.
mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_4_4.root
./doSkim step 0 mc input.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut -1. AddCut 20.
mv input_0.root H2ToH1H1_H1To2Mu2B_mH2-125_mH1-40_Summer12_final_4_4.root
./doSkim step 0 mc input.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 20. AddCut 40.
mv input_0.root input_NewCR.root
