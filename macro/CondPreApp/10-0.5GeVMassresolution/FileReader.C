void presyst(TString s) {
    TFile * fin = TFile::Open("graphs.root");
    TList * l = fin->GetListOfKeys();
    TCanvas C("C", "C", 3, 58, 1185, 658);
    C.Divide(2,2);
    TGraphAsymmErrors * gra = 0;
    TGraphErrors * gr = 0;
    //Loop for line
    Int_t I = 0;
    TKey *key3;
    TIter nextkey3(fin->GetListOfKeys());
    while ((key3 = (TKey*) nextkey3())) {
        const char *classname = key3->GetClassName();
        TClass *cl = gROOT->GetClass(classname);
        if (!cl) continue;
        if (!cl->InheritsFrom(TGraphAsymmErrors::Class()))
            continue;
        gra = (TGraphAsymmErrors*) fin->Get(key3->GetName());
        C.cd(I + 1);
        gra->Draw("alp");
        I++;
    }
    
    TKey *key;
    TIter nextkey(fin->GetListOfKeys());
    //Loop for stat uncertainty
    Int_t nStat = 0;
    I = 0;
    while ((key = (TKey*) nextkey())) {
        const char *classname = key->GetClassName();
        TClass *cl = gROOT->GetClass(classname);
        if (!cl) continue;
        if (cl->InheritsFrom(TGraphAsymmErrors::Class()))
            continue;
        nStat++;
        gr = (TGraphErrors*) fin->Get(key->GetName());
        gr->SetMarkerColor(kRed);
        gr->SetLineWidth(2);
        gr->SetLineColor(kBlue);
        C.cd(I + 1);
        gr->Draw("p");
        I++;
    }

    //Loop for syst uncertainty
    I = 0;
    TKey *key2;
    TIter nextkey2(fin->GetListOfKeys());

    while ((key2 = (TKey*) nextkey2())) {
        const char *classname = key2->GetClassName();
        TClass *cl = gROOT->GetClass(classname);
        if (!cl) continue;
        if (!cl->InheritsFrom(TGraphAsymmErrors::Class()))
            continue;
        gra = (TGraphAsymmErrors*) fin->Get(key2->GetName());
        gra->SetMarkerColor(kRed);
        gra->SetLineWidth(2);
        gra->SetLineColor(kGreen);
        //        gra->SetLineStyle(kDashed);
        gra->SetMarkerStyle(4);
        C.cd(I + 1);
        gra->Draw("p|>");
        I++;
    }

    C.SaveAs(s + "_figs.C");
}

int FileReader() {
    gStyle->SetEndErrorSize(6);
    /*presyst("b");
    presyst("JES");
    presyst("JER");
    presyst("mu");
    presyst("pu");*/
    presyst("AllSyst");
    return 0;
}
