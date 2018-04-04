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
#include "TH2D.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
const char *cmsl = "CMS #scale[0.8]{#bf{#it{internal}}}";

//const double lumin = 5.768;
const double lumin = 35.87;
const double extra = 1;
const double scaf = 1000.*lumin;
const double scafqcd = 1000.*lumin;

const int bkgtype = 11;
const int proalltype = 16;
const int prosepatype = 2;    //6--discr;13--sepa type
const int colorbkg[bkgtype] = {kBlue-10,kGreen-10,kGreen-10,kGreen-10,kAzure-9,kGray,kGray,kGray,kGray,kGray,kOrange-9};
TString bkgname[bkgtype] = {"TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","WJets","DYJets","ZJets","ST","TTW","TTZ","TTG","TTTT","ttH","QCD_HT"};
TString bkgshort[bkgtype] = {"ttbar","electroweak","electroweak","electroweak","ST","rares","rares","rares","rares","rares","QCD"};
TString proname[proalltype] = {"ST","HT","NBjets","Njets","NSubJet","NSubJetB","NSubJetBLoose","SDMass","subCSV1","subCSV2","subCSV3","subCSVmax","tau32","tau21","ele_pt","muon_pt"};
TString prosepaname[prosepatype] = {"invariantExt","num_lo_j"};


void plot_mass(){
	
	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/finalplot.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/lastplot.root");
//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/ending17.root");

	TDirectoryFile* all = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat");
	TDirectoryFile* tb[4];
	TDirectoryFile* tbs[4];
	tb[0] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
	tb[1] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
	tb[2] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
	tb[3] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	
	tbs[0] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
        tbs[1] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
        tbs[2] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
        tbs[3] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


      for(int k=3; k<4; k++){
	for(int i=0; i<prosepatype-1; i++){
                THStack *ths_all = new THStack(prosepaname[i],prosepaname[i]);
                TH1D* ht[bkgtype];
		TH1D* ht_ap = (TH1D*)tbs[k]->Get(Form("%s_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8",prosepaname[i].Data()));
		TH1D* ht_wp = (TH1D*)tbs[k]->Get(Form("%s_WprimeToTB_TToHad_M-1000",prosepaname[i].Data()));
                ht_ap->SetLineColor(kRed);
		ht_ap->SetLineWidth(2);
		ht_ap->Scale(scaf);
		ht_wp->SetLineColor(kRed-9);
                ht_wp->SetLineWidth(2);
		ht_wp->Scale(scaf);
                for(int j=0; j<bkgtype; j++){
			ht[j] = (TH1D*)tb[k]->Get(Form("%s_%s",prosepaname[i].Data(),bkgname[j].Data()));
			if(ht[j] == NULL) continue;
//			ht[j]->Rebin(4);
                        ht[j]->SetFillColor(colorbkg[j]);
                        ht[j]->SetLineColor(colorbkg[j]);
			ht[j]->Scale(scaf);
                        ths_all->Add(ht[j]);
                }
		if(ht[0] == NULL) continue;

                TCanvas *c1 = new TCanvas("c1","c1",800,600);

                c1->cd();
		c1->SetLogy();
		c1->SetGridx();
		c1->SetGridy();
	
                ths_all->Draw("hist");

//		ths_all->GetXaxis()->SetTitle(prosepaname[i]);		
/*
		ths_all->GetXaxis()->SetTitle("number of remaining jets");
        	ths_all->GetXaxis()->SetBinLabel(1,"0");
        	ths_all->GetXaxis()->SetBinLabel(2,"1");
        	ths_all->GetXaxis()->SetBinLabel(3,"2");
        	ths_all->GetXaxis()->SetBinLabel(4,"3");
        	ths_all->GetXaxis()->SetBinLabel(5,"4");
        	ths_all->GetXaxis()->SetBinLabel(6,"5");
        	ths_all->GetXaxis()->SetBinLabel(7,"6");
        	ths_all->GetXaxis()->SetBinLabel(8,"7");
        	ths_all->GetXaxis()->SetBinLabel(9,"8");
        	ths_all->GetXaxis()->SetBinLabel(10,"#geq 9jets");
*/
		ths_all->GetXaxis()->SetTitle("M_{Wbj}[GeV]");
		ths_all->GetXaxis()->SetRangeUser(750.,1250.0);
		ths_all->GetYaxis()->SetRangeUser(1,10000);
                ths_all->GetYaxis()->SetTitle("Events");

		ht_ap->Draw("hist same");
		ht_wp->Draw("hist same");

                TLatex latex;
                latex.SetNDC();
                latex.SetTextSize(0.04);
                latex.SetTextAlign(11);
                latex.DrawLatex(0.67, 0.93, lumien);
                latex.SetTextSize(0.05);
                latex.DrawLatex(0.12, 0.93, cmsl);

		TLegend *legend0 = new TLegend(0.4,0.69,0.64,0.9);
                legend0->SetFillStyle(0);
                legend0->SetBorderSize(0);
		legend0->AddEntry(ht_ap,"Associated M-1000","l");
		legend0->AddEntry(ht_wp,"s-channel M-1000","l");
		legend0->Draw("same");


		TLegend *legend1 = new TLegend(0.64,0.69,0.9,0.9);
		legend1->SetFillStyle(0);
                legend1->SetBorderSize(0);
                for(int j=bkgtype-1; j>=0; j--){
			if(ht[j] == NULL) continue;
			if(j>0 && colorbkg[j]==colorbkg[j-1] && ht[j-1] != NULL)continue;
                        legend1->AddEntry(ht[j],bkgshort[j],"f");
                }
                legend1->Draw("same");



                c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar29_signal_%s_cate%i.png",prosepaname[i].Data(),k));
        }
     }





/*
	double m800_0b = 1000*lumin*(nbjets_800->Integral(1,2));
	double m800_1b = 1000*lumin*(nbjets_800->Integral(2,3));
	double m800_2b = 1000*lumin*(nbjets_800->Integral(3,4));
	double m800_3b = 1000*lumin*(nbjets_800->Integral(4,5));

	double ttbar_0b = 1000*lumin*(nbjets_ttbar->Integral(1,2));
        double ttbar_1b = 1000*lumin*(nbjets_ttbar->Integral(2,3));
        double ttbar_2b = 1000*lumin*(nbjets_ttbar->Integral(3,4));
        double ttbar_3b = 1000*lumin*(nbjets_ttbar->Integral(4,5));

	double qcd_0b = 1000*lumin*(nbjets_qcd->Integral(1,2));
        double qcd_1b = 1000*lumin*(nbjets_qcd->Integral(2,3));
        double qcd_2b = 1000*lumin*(nbjets_qcd->Integral(3,4));
        double qcd_3b = 1000*lumin*(nbjets_qcd->Integral(4,5));

	cout << "1000: " << m800_0b << ", " << m800_1b << ", " << m800_2b << ", " << m800_3b << endl;
	cout << "ttbar: " << ttbar_0b << ", " << ttbar_1b << ", " << ttbar_2b << ", " << ttbar_3b << endl;
	cout << "qcd: " << qcd_0b << ", " << qcd_1b << ", " << qcd_2b << ", " << qcd_3b << endl;
*/



}
