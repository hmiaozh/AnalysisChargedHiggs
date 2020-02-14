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
#include "TEnv.h"

const char *lumien = "#scale[1.2]{#bf{35.9 fb^{-1} (13TeV)}}";
const char *cmsl = "CMS #scale[0.75]{#bf{#it{Preliminary}}}";


const char *below = "below";
const char *in = "in";
const char *above = "above";
const char *belowwindow = "[0, 910]GeV";
const char *inwindow = "[910, 1050]GeV";
const char *abovewindow = "[1050, #infty]GeV";
//const double lumin = 5.768;
const double lumin = 35.9;
const double extra = 1;
const double scaf = 1000.*lumin;
const double scafqcd = 1000.*lumin;

const int bkgtype = 11;
const int proalltype = 16;
const int prosepatype = 2;    //6--discr;13--sepa type
const int colorbkg[bkgtype] = {kGreen-10,kGreen-10,kGreen-10,kViolet-4,kViolet-4,kViolet-4,kViolet-4,kViolet-4,kViolet-4,kBlue-10,kOrange+1};
TString bkgname[bkgtype] = {"WJets","DYJets","ZJets","ST","TTW","TTZ","TTG","TTTT","ttH","TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","QCD_HT"};
TString bkgshort[bkgtype] = {"EWK","EWK","EWK","t,tW,t#bar{t}+X","Top","Top","Top","Top","Top","t#bar{t}","QCD"};
TString proname[proalltype] = {"ST","HT","NBjets","Njets","NSubJet","NSubJetB","NSubJetBLoose","SDMass","subCSV1","subCSV2","subCSV3","subCSVmax","tau32","tau21","ele_pt","muon_pt"};
TString prosepaname[prosepatype] = {"invariantExt","num_lo_j"};


void Paper_plot_massfull(){
	
	setTDRStyle();
//	gEnv->Print();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/postplot.root");
	//TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/lastplot.root");
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


      for(int k=1; k<2; k++){
	for(int i=0; i<prosepatype-1; i++){
                THStack *ths_all = new THStack(prosepaname[i],prosepaname[i]);
                TH1D* ht[bkgtype];
		//TH1D* ht_data= (TH1D*)tbs[k]->Get(Form("%s_Data",proname[i].Data()));
		TH1D* ht_ap = (TH1D*)tbs[k]->Get(Form("%s_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8",prosepaname[i].Data()));
		TH1D* ht_wp = (TH1D*)tbs[k]->Get(Form("%s_WprimeToTB_TToHad_M-1000",prosepaname[i].Data()));
		//ht_data->Rebin(4);
		ht_ap->Rebin(4);
		ht_wp->Rebin(4);
                ht_ap->SetLineColor(kRed);
		ht_ap->SetLineWidth(2);
		ht_ap->Scale(scaf);
		ht_wp->SetLineColor(kRed-9);
                ht_wp->SetLineWidth(2);
		ht_wp->Scale(scaf);
                for(int j=0; j<bkgtype; j++){
			ht[j] = (TH1D*)tb[k]->Get(Form("%s_%s",prosepaname[i].Data(),bkgname[j].Data()));
			if(ht[j] == NULL) continue;
			ht[j]->Rebin(4);
                        ht[j]->SetFillColor(colorbkg[j]);
                        ht[j]->SetLineColor(colorbkg[j]);
			ht[j]->Scale(scaf);
                        ths_all->Add(ht[j]);
                }
		if(ht[0] == NULL) continue;

                TCanvas *c1 = new TCanvas("c1","c1",800,600);
//begin up
                TPad *pad_up = new TPad("pad_up", "pad_up", 0., 0.25, 1., 1.);
                TPad *pad_dn = new TPad("pad_dn", "pad_dn", 0., 0., 1., 0.25);

//              pad_up->SetTopMargin(0.05);
                pad_up->SetBottomMargin(0);
                pad_up->SetLeftMargin(0.13);
                pad_up->SetRightMargin(0.07);
                pad_up->SetTickx(1);
                pad_up->SetTicky(1);
                pad_up->SetLogy();
		//pad_up->SetGridx();
                //pad_up->SetGridy();

                pad_dn->SetTopMargin(0);
                pad_dn->SetBottomMargin(0.50);
                pad_dn->SetLeftMargin(0.13);
                pad_dn->SetRightMargin(0.07);
                pad_dn->SetTickx(1);
                pad_dn->SetTicky(1);

                pad_up->Draw();
                pad_up->cd();


//end

/*
                c1->cd();
		c1->SetLogy();
		c1->SetGridx();
		c1->SetGridy();
*/	
                ths_all->Draw("hist");

//		ths_all->GetXaxis()->SetTitle(prosepaname[i]);		
/*
		ths_all->GetXaxis()->SetTitle("#remaining jets");
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
		ths_all->GetXaxis()->SetRangeUser(100.,3700.0);
        	ths_all->SetMaximum(24000.0);
        	ths_all->SetMinimum(4);


                ths_all->GetYaxis()->SetTitle("Events");
		ths_all->GetYaxis()->SetTitleFont(43);
		ths_all->GetYaxis()->SetTitleOffset(0.84444);
		ths_all->GetYaxis()->SetTitleSize(32);

		//ht_data->Draw("P E X0 SAME");
		ht_ap->Draw("hist same");
		ht_wp->Draw("hist same");

                TLatex latex;
                latex.SetNDC();
                latex.SetTextSize(0.04);
                latex.SetTextAlign(11);
                latex.DrawLatex(0.75, 0.93, lumien);
                latex.SetTextSize(0.05);
                latex.DrawLatex(0.15, 0.84, cmsl);

		TLegend *legend0 = new TLegend(0.42,0.78,0.74,0.89);
                legend0->SetFillStyle(0);
                legend0->SetBorderSize(0);
		//legend0->AddEntry(ht_data,"Data","PE");
		legend0->AddEntry(ht_ap,"Associated m_{H^{+}} = 1 TeV","l");
		legend0->AddEntry(ht_wp,"s-channel m_{H^{+}} = 1 TeV","l");
		legend0->Draw("same");


		TLegend *legend1 = new TLegend(0.74,0.68,1.01,0.89);
		legend1->SetFillStyle(0);
                legend1->SetBorderSize(0);
                for(int j=bkgtype-1; j>=0; j--){
			if(ht[j] == NULL) continue;
			if(j>0 && colorbkg[j]==colorbkg[j-1] && ht[j-1] != NULL)continue;
                        legend1->AddEntry(ht[j],bkgshort[j],"f");
                }
                legend1->Draw("same");



		c1->cd();
                pad_dn->Draw();
                pad_dn->cd();
                //pad_dn->SetGridy();

                TH1D* hRatio = new TH1D("","",360,100,3700);

                hRatio->GetXaxis()->SetTitle("m_{t(b)b} [GeV]");
                //hRatio->GetXaxis()->SetRangeUser(50.,135.);
                hRatio->GetYaxis()->SetTitle("#splitline{Mass}{Window}");
                //hRatio->GetYaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetRangeUser(-10000,10000);
                hRatio->GetYaxis()->SetTitleOffset(0.85);
                hRatio->GetXaxis()->SetTitleOffset(4.8);
                hRatio->GetXaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetTitleFont(43);
                hRatio->GetXaxis()->SetTitleFont(43);
                hRatio->GetYaxis()->SetLabelSize(0);
                hRatio->GetXaxis()->SetLabelSize(24);
                hRatio->GetYaxis()->SetTitleSize(22);
                hRatio->GetXaxis()->SetTitleSize(28);
//              hRatio->GetYaxis()->SetNdivisions(502);
                hRatio->Draw("SAME");

                latex.SetNDC();
                latex.SetTextSize(0.14);
		latex.SetTextFont(12);
                latex.SetTextAlign(11);
                latex.DrawLatex(0.18, 0.83, below);
		latex.DrawLatex(0.32, 0.83, in);
		latex.DrawLatex(0.59, 0.83, above);
                latex.SetTextSize(0.12);
                latex.DrawLatex(0.16, 0.59, belowwindow);
		latex.DrawLatex(0.29, 0.59, inwindow);
		latex.DrawLatex(0.57, 0.59, abovewindow);


                c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2019May/May07_full_%s_cate%i.C",prosepaname[i].Data(),k));
		c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2019May/May07_full_%s_cate%i.png",prosepaname[i].Data(),k));
		c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2019May/May07_full_%s_cate%i.pdf",prosepaname[i].Data(),k));
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
