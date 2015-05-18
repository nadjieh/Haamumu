#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
string settitles(string s){
	string ret="";
	if(s == string("allW_BJet_Pt"))
		ret = string("p_{T}^{b-jets} (GeV)");
	if(s == string("Default_allWcosTheta"))
		ret = string("cos(#theta_{l}*)");
	if(s == string("allW_Muon_Pt"))
		ret = string("p_{T}^{l}");
	if(s == string("EtaFwD_allWcosTheta"))
		ret = string("cos(#theta_{l}*)");
	if(s == string("allW_FwD_Eta"))
		ret = string("#eta_{jet}^{FwD}");
	if(s == string("allW_Jet_Pt"))
		ret = string("p_{T}^{jets} (GeV)");
	if(s == string("allW_finalMT"))
		ret = string("m_{T}^{W} (GeV)");
	if(s == string("allW_Met_Pt"))
		ret = string("E_{T}^{miss} (GeV)");
	if(s == string("Default_allW_topMass"))
		ret = string("m_{lb#nu} (GeV)");
	return ret;
}
string setYtitles(string s){
	string ret=string("Events @ 19.7 fb^{-1}");
	if(s == string("allW_Jet_Pt"))
		ret = string("Jets @ 19.7 fb^{-1}");
	return ret;
}
string getlegend(int nHist, string s){

  stringstream c;
  string leg = "   TLegend *leg = new TLegend(0.5,0.67,0.88,0.88,NULL,\"brNDC\");\n";
   leg+="   leg->SetBorderSize(0);\n";
   leg+="   leg->SetTextFont(62);\n";
   leg+="   leg->SetLineColor(1);\n";
   leg+="   leg->SetLineStyle(1);\n";
   leg+="   leg->SetLineWidth(1);\n";
   leg+="   leg->SetFillColor(0);\n";
   leg+="   leg->SetFillStyle(1001);\n";
   c.str("");
   c<<s<<"__"<<nHist - 1;
   leg+="   TLegendEntry *entry=leg->AddEntry(\""+c.str()+"\",\"Data\",\"LEP\");\n";
   leg+="   entry->SetLineColor(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(20);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
   c.str("");
   c<<s<<"__"<<nHist + 9;   
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"ZH_125\",\"f\");\n";
   leg+="   entry->SetFillStyle(1001);\n";
   leg+="   entry->SetLineColor(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
   c.str("");
   c<<s<<"__"<<nHist + 8; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"Z+j (10-50 GeV)\",\"f\");\n";
   leg+="   entry->SetFillStyle(1001);\n";
   leg+="   entry->SetLineColor(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
   c.str("");
   c<<s<<"__"<<nHist + 7; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"Z+j (> 50 GeV)\",\"f\");\n";
   leg+="   entry->SetFillStyle(1001);\n";
   leg+="   entry->SetLineColor(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist + 6; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"tW\",\"f\");\n";

   leg+="   ci = TColor::GetColor(\"#ff6666\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist + 4; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"t#bar{t} lept\",\"f\");\n";

   leg+="   ci = TColor::GetColor(\"#ff6666\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist + 3; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"t#bar{t} dilep\",\"f\");\n";

   leg+="   ci = TColor::GetColor(\"#336600\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist + 2; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"WW\",\"f\");\n";
   leg+="   ci = TColor::GetColor(\"#336600\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist + 1; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"WZ\",\"f\");\n";

   leg+="   ci = TColor::GetColor(\"#339966\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
      c.str("");
   c<<s<<"__"<<nHist; 
   leg+="   entry=leg->AddEntry(\""+c.str()+"\",\"ZZ\",\"f\");\n";

   leg+="   ci = TColor::GetColor(\"#ffff66\");\n";
   leg+="   entry->SetFillColor(ci);\n";
   leg+="   entry->SetFillStyle(1001);\n";

   leg+="   ci = TColor::GetColor(\"#000099\");\n";
   leg+="   entry->SetLineColor(ci);\n";
   leg+="   entry->SetLineStyle(1);\n";
   leg+="   entry->SetLineWidth(1);\n";
   leg+="   entry->SetMarkerColor(1);\n";
   leg+="   entry->SetMarkerStyle(21);\n";
   leg+="   entry->SetMarkerSize(1);\n";
   leg+="   entry->SetTextFont(62);\n";
   leg+="   pad1->cd();\n";
   leg+="   leg->Draw();\n";
   leg+="   pad1->Modified();\n";


/*  leg+="   c->Modified();\n";
  leg+="   c->cd();\n";
  leg+="   c->SetSelected(c);\n}\n";*/

 return leg;
}

void myRead(string s,string name) {//"bpt_Ele.C" 
  string line;
  string preline;
  ifstream myfile (name.c_str());
  ofstream myfileOUT ((string("corrected/")+name).c_str());
  int iLine = 0;
  //string s = "allW_BJet_Pt";
  string q = "\"\"";
  string myLine = string("   ")+s+string("->Add(")+s+string(",")+q+string(");");
  cout<<"---- "<<myLine<<endl;
  string errName = "Draw(\"PE1sames\");";
  if (myfile.is_open())
  {
    bool isleg = false;
    bool histFound = false;    
    int nHist = 0;
    while ( myfile.good() )
    {
//cout<<      iLine<<endl;
      preline = line;
      getline (myfile,line);
      if(string(line) == ("   THStack *"+s+" = new THStack();")){
	   myfileOUT<<"   THStack *"+s+"Stack = new THStack();\n";
	   iLine++;
	   continue;
      }
      if(string(line) == ("   "+s+" = new THStack();")){
	   myfileOUT<<"   "+s+"Stack = new THStack();\n";
	   iLine++;
	   continue;
      }
	  if(string(line).find("   TH1F *"+s) == 0 ){
		myfileOUT<<line<<endl;
		int pos = string(line).find("=");
		string myStr =  string(line).substr(9, pos-10);
		myfileOUT<<"   "<<myStr<<"->GetXaxis()->SetTitle(\""<<settitles(s)<<"\");"<<endl;
		myfileOUT<<"   "<<myStr<<"->GetYaxis()->SetTitle(\""<<setYtitles(s)<<"\");"<<endl;
	   iLine++;
	   continue;
	  }
	  if(iLine == 263){
	  	cout<<string(line)<<endl;
	  	cout<<"   "+s+"Stack->SetTitle(\""+s+"Stack\");\n";
	  }
      if(string(line) == ("   "+s+"->SetName(\""+s+"\");")){
       cout<<"SetName ---------"<<endl;
	   myfileOUT<<"   "+s+"Stack->SetName(\""+s+"Stack\");\n";
	   cout<<"   "+s+"Stack->SetName(\""+s+"Stack\");\n"<<endl;
	   iLine++;
	   continue;
      }
      if(string(line) == ("   "+s+"->SetTitle(\"MC stack\");")){
       cout<<"SetTitle ---------"<<endl;
	   myfileOUT<<"   "+s+"Stack->SetTitle(\"MC stack\");\n";
	   iLine++;
	   continue;
      }
      if(string(line) == ("   "+s+"->SetTitle(\"MC stack - not stacked\");")){
       cout<<"SetTitle ---------"<<endl;
	   myfileOUT<<"   "+s+"Stack->SetTitle(\"MC stack - not stacked\");\n";
	   iLine++;
	   continue;
      }
      
      if(string(line) == ("   "+s+"->Draw(\"nostack, hist, same\");")){  
	   myfileOUT<<"   "+s+"Stack->Draw(\"nostack, hist, same\");\n";
	   iLine++;
	   continue;
      }
      
      if(string(line) == ("   "+s+"->Draw(\"hist, same\");")){  
	   myfileOUT<<"   "+s+"Stack->Draw(\"hist, same\");\n";
	   iLine++;
	   continue;
      }
      if (string(line).find("leg") < string(line).size() && !isleg) {
       myfileOUT<<"\n"<<getlegend(nHist, s)<<endl;
       myfileOUT<<s<<"->cd();"<<endl;
       isleg = true;
	   iLine++;
	   continue;      
      }
      if (string(line).find("leg") < string(line).size() && isleg) {
	   iLine++;
	   continue;      
      }
      if (string(line).find("entry") < string(line).size()){
 	   iLine++;
	   continue;      
      }     
      
      if(string(line).find("SetHistogram(") != 0 && string(line).find("SetHistogram(") < string(line).size()){
		int pos = preline.find("->GetZaxis()");
		string myStr = preline.substr(3, pos-3);
		cout<<myStr<<endl;
		myfileOUT<<"   "+s+"Stack->SetHistogram("+myStr+");\n";
	   iLine++;
	   continue;
      }
      stringstream sq;
      sq.str("");
      sq << nHist + 8;
      if(string(line) == ("   "+s+"__"+sq.str()+"->SetFillColor(ci);")){
       myfileOUT<<"   "+s+"__"+sq.str()+"->SetFillColor(kRed-9);";
	   iLine++;
	   continue;
      }

      if(string(line) == ("   "+s+"->SetTitle(\""+s+"\");")){
	   iLine++;
	   continue;
      }
      sq.str("");
      sq << nHist + 14;
      if(string(line).find("   ratio__"+sq.str()+"->SetBinContent") == 0){
       int pos = string(line).find(",");
       string s1 = string(line).substr(0,pos);
       string s2 = string(line).substr(pos+1,string(line).size()-pos);
	   myfileOUT<<s1<<",1./"<<s2<<endl;
	   iLine++;
	   continue;
      }
      if(string(line).find("   ratio__"+sq.str()+"->GetYaxis()->SetTitle(\"MC") == 0){
      	myfileOUT<<"   ratio__"+sq.str()+"->GetYaxis()->SetTitle(\"Data/MC\");"<<endl;
      	iLine++;
	   continue;
      }

      if(string(line) == ("}")){
	   iLine++;
	   continue;
      }
	  if(string(line) == myLine){

      	cout <<"before: " <<line << endl;
      	cout <<"before: " <<preline << endl;
		int pos = preline.find("__");
		int len = preline.find("-");
		string myStr = preline.substr(pos,len-pos);
		string number = myStr.substr(2,myStr.size() -2);
		if(!histFound){
	    	histFound = true;
	    	
	    	nHist = (int)atof(number.c_str());
	    	cout<<"NHIST "<<number<<"\t"<<nHist<<endl;
	    }
     	cout <<"after: " << string("   ")+s+string("->Add(")+s+myStr+string(",")+q+string(");")<< endl;
		myfileOUT <<string("   ")+s+string("Stack->Add(")+s+myStr+string(",")+q+string(");")<< endl;
	  } else {
		myfileOUT<<line<<endl;
	  }
	  iLine++;
    }
    myfile.close();
    
    myfileOUT<<"}\n";
    myfileOUT.close();
  }

  else cout << "Unable to open file"; 

}




void doJob(){

	//myRead("allW_BJet_Pt","bpt_Ele.C");
	/*myRead("METsignificance_hamb","METSigDR.C");
	myRead("aptMu","diMuPt.C");
    myRead("dphidiMu","diDPhi.C");
    myRead("dphidiMu","diDPhiDR.C");
	myRead("MET_hamb","MET.C");
	myRead("METsignificance_hamb","METSig.C");
	myRead("aptMu","diMuPtDR.C");
	myRead("diMudR","DRDR.C");
	myRead("MET_hamb","METDR.C");*/
	myRead("amassMu","myMass08.C");
	myRead("aptMu","diMuPt08.C");
	myRead("dphidiMu","dphidiMu.C");
	myRead("MET_hamb","MET08.C");
	myRead("METsignificance_hamb","METSig08.C");

}
