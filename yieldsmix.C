#include "TH1.h"
#include "THStack.h"
#include "TF1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "RooGlobalFunc.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TLegend.h"
#include "TRandom.h"
#include "TLatex.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double aaano = 35.87;
const int bkgtype = 11;
TString bkgshort[bkgtype] = {"ttbar","electroweak","electroweak","electroweak","ST","rares","rares","rares","rares","rares","QCD"};
const int colorbkg[bkgtype] = {kBlue-10,kGreen-10,kGreen-10,kGreen-10,kAzure-9,kGray,kGray,kGray,kGray,kGray,kOrange-9};

void yieldsmix(){

	setTDRStyle();

//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/freze2limit.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/PyieldsAll.root");	

	vector<TDirectoryFile*> categ;

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_lowj_t0b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_lowj_t1b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_lowj_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_lowj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_lowj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_lowj_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_lowj_wbb") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_lowj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_lowj_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_lowj_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_lowj_wbb"));
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_lowj_wbj"));

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_highj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_highj_t1b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_highj_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_highj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_highj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_highj_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_highj_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_highj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_highj_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_highj_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_highj_wbb"));
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_highj_wbj"));

/*
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_one_t0b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_one_t1b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_one_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_one_wbj") );


        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_two_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_two_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_two_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_two_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_three_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_three_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_three_wbb"));
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat1l_three_wbj"));
*/
	char mass_b[11][100];
	char mass_s[2][100];
	sprintf(mass_s[0],"HT_3000_above_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	sprintf(mass_s[1],"HT_3000_above_WprimeToTB_TToHad_M-3000");
	sprintf(mass_b[0],"HT_3000_above_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
/*	sprintf(mass_b[1],"HT_all_WJets");
        sprintf(mass_b[2],"HT_all_DYJets");
        sprintf(mass_b[3],"HT_all_ZJets");
        sprintf(mass_b[4],"HT_all_ST");
        sprintf(mass_b[5],"HT_all_TTW");
        sprintf(mass_b[6],"HT_all_TTZ");
        sprintf(mass_b[7],"HT_all_TTG");
        sprintf(mass_b[8],"HT_all_TTTT");
        sprintf(mass_b[9],"HT_all_ttH");
*/
	sprintf(mass_b[1],"invariantExt_WJets");
        sprintf(mass_b[2],"invariantExt_DYJets");
        sprintf(mass_b[3],"invariantExt_ZJets");
        sprintf(mass_b[4],"invariantExt_ST");
        sprintf(mass_b[5],"invariantExt_TTW");
        sprintf(mass_b[6],"invariantExt_TTZ");
        sprintf(mass_b[7],"invariantExt_TTG");
        sprintf(mass_b[8],"invariantExt_TTTT");
        sprintf(mass_b[9],"invariantExt_ttH");

	sprintf(mass_b[10],"HT_3000_above_QCD_HT");

	
	TH1D* ycb[11];
	for(int m=0; m<11; m++){
		ycb[m] = new TH1D(mass_b[m],mass_b[m],24,0,24);
	}
	TH1D* signall = new TH1D("signall","",24,0,24);
        TH1D* signalw = new TH1D("signalw","",24,0,24);	

/*
	TH1D* biaogan = (TH1D*)categ[0]->Get(mass_b[0]);
	int m1000low = biaogan->GetXaxis()->FindBin(900.);
        int m1000up  = biaogan->GetXaxis()->FindBin(1050.);

	cout << biaogan->Integral() << endl;
*/

	for(Int_t i=0; i<24; i++) {
		TH1D* ht[11];
		double sig1000t = 0;
		double sig1000w = 0;
		TH1D* m1000tass = (TH1D*)categ[i]->Get(mass_s[0]);
		TH1D* m1000w = (TH1D*)categ[i]->Get(mass_s[1]);
		if(m1000tass != NULL) sig1000t = m1000tass->Integral();
		if(m1000w != NULL) sig1000w = m1000w->Integral();
		signall->SetBinContent(i+1,sig1000t);
                signalw->SetBinContent(i+1,sig1000w);
		for(int j=0; j<11; j++){
			double bkgnum = 0;
			ht[j] = (TH1D*)categ[i]->Get(mass_b[j]);
			if(ht[j] != NULL){
				if(j==0 || j==10) bkgnum = ht[j]->Integral();
				else bkgnum = ht[j]->Integral(292,360);
			}
			ycb[j]->SetBinContent(i+1,bkgnum);
		}			
	}


	THStack *cateyields = new THStack("cateyield","");

	signall->SetLineColor(kRed);
	signall->SetLineWidth(2);
	signall->Scale(1000*aaano);
	signalw->SetLineColor(kRed-9);
        signalw->SetLineWidth(2);
        signalw->Scale(1000*aaano);
	for(int m=0; m<11; m++){
		ycb[m]->SetFillColor(colorbkg[m]);
		ycb[m]->SetLineColor(colorbkg[m]);
		ycb[m]->Scale(1000*aaano);
		cateyields->Add(ycb[m]);
	}	


	TCanvas *c1a = new TCanvas("c1a","c1a",2000,800);
//	TCanvas *c1a = new TCanvas("c1a","c1a",1200,748);
        c1a->cd(1);
	c1a->SetLogy();
	c1a->SetGridy();
        c1a->SetGridx();
        cateyields->Draw("hist");
	signall->Draw("hist same");
	signalw->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


	cateyields->GetXaxis()->SetTitle("Category(low->high)");
	cateyields->GetXaxis()->SetTitleSize(0.04);
	cateyields->GetXaxis()->SetTitleOffset(1.2);
        cateyields->GetXaxis()->SetBinLabel(1,"1b_t0b");
	cateyields->GetXaxis()->SetBinLabel(2,"1b_t1b");
	cateyields->GetXaxis()->SetBinLabel(3,"1b_wbb");
        cateyields->GetXaxis()->SetBinLabel(4,"1b_wbj");
	cateyields->GetXaxis()->SetBinLabel(5,"2b_t0b");
        cateyields->GetXaxis()->SetBinLabel(6,"2b_t1b");
        cateyields->GetXaxis()->SetBinLabel(7,"2b_wbb");
        cateyields->GetXaxis()->SetBinLabel(8,"2b_wbj");
	cateyields->GetXaxis()->SetBinLabel(9,"#geq3b_t0b");
        cateyields->GetXaxis()->SetBinLabel(10,"#geq3b_t1b");
        cateyields->GetXaxis()->SetBinLabel(11,"#geq3b_wbb");
	cateyields->GetXaxis()->SetBinLabel(12,"#geq3b_wbj");
	cateyields->GetXaxis()->SetBinLabel(13,"1b_t0b");
        cateyields->GetXaxis()->SetBinLabel(14,"1b_t1b");
        cateyields->GetXaxis()->SetBinLabel(15,"1b_wbb");
        cateyields->GetXaxis()->SetBinLabel(16,"1b_wbj");
        cateyields->GetXaxis()->SetBinLabel(17,"2b_t0b");
        cateyields->GetXaxis()->SetBinLabel(18,"2b_t1b");
        cateyields->GetXaxis()->SetBinLabel(19,"2b_wbb");
        cateyields->GetXaxis()->SetBinLabel(20,"2b_wbj");
	cateyields->GetXaxis()->SetBinLabel(21,"#geq3b_t0b");
        cateyields->GetXaxis()->SetBinLabel(22,"#geq3b_t1b");
        cateyields->GetXaxis()->SetBinLabel(23,"#geq3b_wbb");
        cateyields->GetXaxis()->SetBinLabel(24,"#geq3b_wbj");
        //cateyields->GetYaxis()->SetRangeUser(1.,16000.0);
        cateyields->GetYaxis()->SetTitle("Events");
	cateyields->GetYaxis()->SetTitleOffset(0.8);

	TLegend *legend0 = new TLegend(0.4,0.69,0.64,0.9);
        legend0->SetFillStyle(0);
        legend0->SetBorderSize(0);
        legend0->AddEntry(signall,"Associated M-3000","l");
        legend0->AddEntry(signalw,"s-channel M-3000","l");
        legend0->Draw("same");


        TLegend *legend1 = new TLegend(0.64,0.69,0.9,0.9);
        legend1->SetFillStyle(0);
        legend1->SetBorderSize(0);
        for(int j=bkgtype-1; j>=0; j--){
            if(j>0 && colorbkg[j]==colorbkg[j-1] && ycb[j-1] != NULL)continue;
            legend1->AddEntry(ycb[j],bkgshort[j],"f");
        }
	legend1->Draw("same");

        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar29_sr_above_yields_3000.png");
	


} 

