./doSkim step 6 mc DYjets_M10to50_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc DYjets_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc TTFullLept_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc TTSemiLept_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc Wtbar_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc Wt_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc WW_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc WZ_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc ZH125_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 mc ZZ_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 data DoubleMu2012A_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 data DoubleMu2012B_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 data DoubleMu2012C_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.
./doSkim step 6 data DoubleMu2012D_Summer12_final_6.root AddCut 24. AddCut 8. AddCut 20. AddCut 15. AddCut 99999. AddCut 9999. AddCut 18.

rm -f DoubleMu2012_Summer12_final_6_6.root
hadd DoubleMu2012_Summer12_final_6_6.root DoubleMu2012*_Summer12_final_6_6.root 
rm -f DoubleMu2012A_Summer12_final_6_6.root DoubleMu2012B_Summer12_final_6_6.root DoubleMu2012C_Summer12_final_6_6.root DoubleMu2012D_Summer12_final_6_6.root

./doTemplateFitDYData name Data variable amassMu 10. 120 range 50 70 step 8  data DoubleMu2012_Summer12_final_6_6.root  mc DYjets_M10to50_Summer12_final_6_6.root  0.4  37835275  15465.5  1  mc DYjets_Summer12_final_6_6.root  0.4  30459503  4474.2  1  mc TTFullLept_Summer12_final_6_6.root  1  11997823   27.3  0 mc TTSemiLept_Summer12_final_6_6.root  0.05  10997349  109.2  1  mc Wtbar_Summer12_final_6_6.root  0.05  493460  11.1  1  mc Wt_Summer12_final_6_6.root  0.05  497658  11.1  1  mc WW_Summer12_final_6_6.root  0.05  10000431  56.  1  mc WZ_Summer12_final_6_6.root  0.05  10000283  33.6  1  mc ZH125_Summer12_final_6_6.root  0.01  999462  0.0249  1  mc ZZ_Summer12_final_6_6.root  0.05  9799908  8.258  1 meanbw 3000 meantt 500 meanb 2000 
