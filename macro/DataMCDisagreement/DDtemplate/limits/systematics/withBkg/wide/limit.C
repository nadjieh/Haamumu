#include <vector>
#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TGraphAsymmErrors.h>
using namespace std;
typedef std::vector<double> numbers;
numbers GetNumbers(TFile * f, double xsec = 1.){
	numbers ret;
	TTree * t = (TTree*) f->Get("limit");
	Double_t limit_ = 0;
	TBranch *limit  = t->GetBranch("limit");
    limit->SetAddress(&limit_);
    Float_t quant_ = 0;
	TBranch *quant  = t->GetBranch("quantileExpected");
    quant->SetAddress(&quant_);
    double res[5]={-1.,-1.,-1.-1.,-1.};
	for(int i = 0; i < t->GetEntriesFast(); i++){
		cout<<i<<endl;
		t->GetEntry(i);
		cout<<quant_<<" "<<limit_<<endl;
		if(fabs(quant_ - 0.5) < 0.001)
			res[2] = xsec*limit_;
		else if(fabs(quant_ - 0.025) < 0.001)
			res[0] = xsec*limit_;
		else if(fabs(quant_ - 0.16) < 0.001)
			res[1] = xsec*limit_;	
		else if(fabs(quant_ - 0.84) < 0.001)
			res[3] = xsec*limit_;
		else if(fabs(quant_ - 0.975) < 0.001)
			res[4] = xsec*limit_;								
	}
	for(int i = 0; i<5; i++){
		if(i != 2)
			ret.push_back(fabs(res[i] - res[2]));
		else
			ret.push_back(res[i]);
	}
	return ret;
}

TGraphAsymmErrors * GetGraph(std::vector<numbers> input, double * massesX, int nSigma = 1){
	int nPoint = input.size();
	double y[4];
	double eyl[4];
	double eyh[4];	
	double exl[4];
	double exh[4];	
	for(int i = 0; i < nPoint; i++){
		exl[i] = 0;
		exh[i] = 0;
	}
	
	for(unsigned int iNumbers = 0; iNumbers < input.size(); iNumbers++){
		y[iNumbers] = input[iNumbers][2];
		if(nSigma == 0){
			eyl[iNumbers] = 0;
			eyh[iNumbers] = 0;
		}
		if(nSigma == 1){
			eyl[iNumbers] = input[iNumbers][1];
			eyh[iNumbers] = input[iNumbers][3];
		}
		if(nSigma == 2){
			eyl[iNumbers] = input[iNumbers][0];
			eyh[iNumbers] = input[iNumbers][4];
		}
	}
	return new TGraphAsymmErrors(nPoint, massesX,y,exl,exh,eyl,eyh);
}

void limit(){

	std::vector<TFile*> fs;
	fs.push_back( TFile::Open("higgsCombineTest.Asymptotic.mH30.root"));
	fs.push_back( TFile::Open("higgsCombineTest.Asymptotic.mH40.root"));
	fs.push_back( TFile::Open("higgsCombineTest.Asymptotic.mH50.root"));	
	fs.push_back( TFile::Open("higgsCombineTest.Asymptotic.mH60.root"));
	std::vector<numbers> mynumbers;
	std::vector<numbers> mynumbersXsec;	
	int n = (int)fs.size();
	
	double mass[4]={30., 40.,50.,60.};
	
	for(unsigned int s = 0; s < fs.size(); s++){
		cout<<"--------------- "<<endl;
		mynumbers.push_back(GetNumbers(fs[s]));
		mynumbersXsec.push_back(GetNumbers(fs[s],3.));		
	}
	
	TGraphAsymmErrors * g0 = GetGraph(mynumbers,mass,0);
	g0->SetName("g0");
	g0->SetMarkerStyle(20);
	
	TGraphAsymmErrors * g00 = GetGraph(mynumbersXsec,mass,0);
	g00->SetName("g00");
	g00->SetLineStyle(2);
	g00->SetLineWidth(2);
	g00->SetLineColor(kBlue);
	
	TGraphAsymmErrors * g1 = GetGraph(mynumbers,mass,1);
	g1->SetName("g1");
	g1->SetFillColor(kYellow);
		
	TGraphAsymmErrors * g11 = GetGraph(mynumbersXsec,mass,1);
	g11->SetName("g1");
	g11->SetFillColor(kYellow);		
	g11->SetTitle("Expected 1 #sigma");
		
	TGraphAsymmErrors * g2 = GetGraph(mynumbers,mass,2);
	g2->SetName("g2");
	g2->SetFillColor(kGreen);
	
	TGraphAsymmErrors * g22 = GetGraph(mynumbersXsec,mass,2);
	g22->SetName("g2");
	g22->SetFillColor(kGreen);
	g22->SetTitle("Expected 2 #sigma");
	
	
	TCanvas c;
	c.cd();
	
	g2->Draw("ap3");
	g1->Draw("p3");
	g0->Draw("p");
	c.SaveAs("myLimitR.C");
	
	TCanvas c2;
	c2.cd();
	
	g22->Draw("ap3");
	g11->Draw("p3");
	g00->Draw("p");
	c2.SaveAs("myLimitXsec.C");

}
