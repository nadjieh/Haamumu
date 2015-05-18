./doSkim step 6 mc DYjets_M10to50_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc DYjets_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc TTFullLept_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc TTSemiLept_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc Wtbar_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc Wt_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc WW_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc WZ_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc ZH125_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 mc ZZ_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 data DoubleMu2012A_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 data DoubleMu2012B_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 data DoubleMu2012C_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.
./doSkim step 6 data DoubleMu2012D_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 9999.

rm -f DoubleMu2012_Summer12_final_6_6.root
hadd DoubleMu2012_Summer12_final_6_6.root DoubleMu2012*_Summer12_final_6_6.root 
rm -f DoubleMu2012A_Summer12_final_6_6.root DoubleMu2012B_Summer12_final_6_6.root DoubleMu2012C_Summer12_final_6_6.root DoubleMu2012D_Summer12_final_6_6.root
