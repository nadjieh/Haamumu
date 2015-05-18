using namespace std;
#include <sstream>
void 
macroSasha(){
	TFile * f = new TFile ("data.root","read");
	TString step = "Muon/stage_";
	TCanvas C;
	C.SetTitle("HLT_Mu8_Mu17");
	TCanvas C2;
	C2.SetTitle("#mu#mu (25, 2.1) + ==1b (30, 2.4)");
	TCanvas C3;
	C3.SetTitle("#mu#mu (25, 2.1) + >=1b (30, 2.4)");		
    stringstream s;
	for(int i = 0; i < 9; i++){
		s.str("");
		s << step << i<<"/selection/amassMu";
		TH1D * h = (TH1D*)f->Get(s.str().c_str());
		h->Rebin(20);
		h->SetLineColor(kAzure + i);
		h->SetLineWidth(2);
		h->GetXaxis()->SetRangeUser(0,70.);
		h->SetStats(0);
		if( i == 0){
			C.cd();
			h->SetTitle("no cut");
 			h->Draw("EHIST");
 		} else if (i < 5) {
 		    C2.cd();
 		    if( i == 1){
 		    	h->SetTitle("no cut");
	 			h->Draw("EHIST");
	 		} else if(i == 2){
	 			h->SetTitle("METSig < 10");
	 			h->Draw("ESAMES");	 			
	 		} else if(i == 3){
	 			h->SetTitle("DR(#mu#mu) < 1.0");
	 			h->Draw("ESAMES");	 			
	 		} else if(i == 4){
	 			h->SetTitle("METSig < 10 & DR(#mu#mu) < 1.0");
	 			h->Draw("ESAMES");	 			
	 		}	 		
	 	} else {
	 	    C3.cd();
 		    if( i == 5){
 		    	h->SetTitle("no cut");
	 			h->Draw("EHIST");
	 		} else if(i == 6){
	 			h->SetTitle("METSig < 10");
	 			h->Draw("ESAMES");	 			
	 		} else if(i == 7){
	 			h->SetTitle("DR(#mu#mu) < 1.0");
	 			h->Draw("ESAMES");	 			
	 		} else if(i == 8){
	 			h->SetTitle("METSig < 10 & DR(#mu#mu) < 1.0");
	 			h->Draw("ESAMES");	 			
	 		}	 		
	 	} 
	}
	
	C.cd();
	tex = new TLatex(16.01652,17800,"HLT_Mu8_Mu17");
    tex->SetLineWidth(2);
    tex->Draw();
	C.SaveAs("myMass1.C");
	C2.cd();
	tex = new TLatex(16.01652,370.8151,"#mu#mu (25, 2.1) + ==1b (30, 2.4)");
    tex->SetLineWidth(2);
    tex->Draw();
	C2.SaveAs("myMass2.C");
	C3.cd();
	tex = new TLatex(16.01652,484.5419,"#mu#mu (25, 2.1) + >=1b (30, 2.4)");
    tex->SetLineWidth(2);
    tex->Draw();
	C3.SaveAs("myMass3.C");	
}
