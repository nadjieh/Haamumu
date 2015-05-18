#./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 20. AddCut 40.
#mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_CR_4_4.root
#./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 0. AddCut 20.
#mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_4_4.root
./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 20. AddCut 38.
mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_CRDown_4_4.root
./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 20. AddCut 42.
mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_CRUp_4_4.root
./doSkim step 0 data DoubleMu2012_Summer12_final_0_0.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 20. AddCut 1000.
mv DoubleMu2012_Summer12_final_0_0_0.root DoubleMu2012_Summer12_final_CRWide_4_4.root
./doSkim step 0 mc H2ToH1H1_H1To2Mu2B_mH2-125_mH1-50_Summer12_final_4.root AddCut 24. AddCut 8. AddCut 18. AddCut 15. AddCut 6. AddCut 20. AddCut 40.
mv H2ToH1H1_H1To2Mu2B_mH2-125_mH1-50_Summer12_final_4_0.root input_4.root

