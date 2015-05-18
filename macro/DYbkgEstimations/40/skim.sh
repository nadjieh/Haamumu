./doSkim step 8 mc DYjets_M10to50_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc DYjets_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc TTFullLept_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc TTSemiLept_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc Wtbar_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc Wt_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc WW_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc WZ_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc ZH125_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 mc ZZ_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 data DoubleMu2012A_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 data DoubleMu2012B_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 data DoubleMu2012C_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
./doSkim step 8 data DoubleMu2012D_Summer12_final_8.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 6. AddCut 9999. AddCut 18.
rm -f DoubleMu2012_Summer12_final_8_8.root
hadd DoubleMu2012_Summer12_final_8_8.root DoubleMu2012*_Summer12_final_8_8.root 
rm -f DoubleMu2012A_Summer12_final_8_8.root DoubleMu2012B_Summer12_final_8_8.root DoubleMu2012C_Summer12_final_8_8.root DoubleMu2012D_Summer12_final_8_8.root

