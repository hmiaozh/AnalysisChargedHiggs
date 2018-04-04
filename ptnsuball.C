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

const double lumin = 35.87;
const int bkgtype = 3;
const int gentype = 5;
TString bkgname[bkgtype] = {"ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8","TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","QCD_HT"};
TString bkgshort[bkgtype] = {"M-1000","tt","QCD"};
TString topname[gentype] = {"toplike_300","toplike_500","toplike_700","toplike_900","toplike_1100"};
TString nontopname[gentype] = {"nontoplike_300","nontoplike_500","nontoplike_700","nontoplike_900","nontoplike_1100"};
TString Wname[gentype] = {"Wlike_300","Wlike_500","Wlike_700","Wlike_900","Wlike_1100"};
TString nonWname[gentype] = {"nonWlike_300","nonWlike_500","nonWlike_700","nonWlike_900","nonWlike_1100"};
//TString topname[gentype] = {"TopH_100","TopH_300","TopH_500","TopH_700","TopH_900","TopH_1100","TopH_1200plus"};
//TString Wname[gentype] = {"WH_100","WH_300","WH_500","WH_700","WH_900","WH_1100","WH_1200plus"};


void ptnsuball(){

	setTDRStyle();


	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/marcor.root");

	vector<TDirectoryFile*> signal;
	vector<TDirectoryFile*> mirror;

	signal.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/Baseline") );

        mirror.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/Baseline") );




	  vector<TH1D*> signal_m;
          vector<TH1D*> mirror_m;
          vector<TH1D*> signal_tt;
          vector<TH1D*> mirror_tt;
          vector<TH1D*> signal_qcd;
          vector<TH1D*> mirror_qcd;

	  for(int j=0; j<gentype; j++){
		char haname1[100];
		char haname2[100];
		sprintf(haname1,Form("%s_%s",topname[j].Data(),bkgname[0].Data()));
		sprintf(haname2,Form("%s_%s",nontopname[j].Data(),bkgname[0].Data()));
		signal_m.push_back(  (TH1D*)signal[0]->Get(haname1) );
		mirror_m.push_back(  (TH1D*)mirror[0]->Get(haname2) );

		char hanamet1[100];
		char hanamet2[100];
                sprintf(hanamet1,Form("%s_%s",topname[j].Data(),bkgname[1].Data()));
                sprintf(hanamet2,Form("%s_%s",nontopname[j].Data(),bkgname[1].Data()));
                signal_tt.push_back(  (TH1D*)signal[0]->Get(hanamet1) );
                mirror_tt.push_back(  (TH1D*)mirror[0]->Get(hanamet2) );

		char hanameq1[100];
		char hanameq2[100];
                sprintf(hanameq1,Form("%s_%s",topname[j].Data(),bkgname[2].Data()));
                sprintf(hanameq2,Form("%s_%s",nontopname[j].Data(),bkgname[2].Data()));
                signal_qcd.push_back(  (TH1D*)signal[0]->Get(hanameq1) );
                mirror_qcd.push_back(  (TH1D*)mirror[0]->Get(hanameq2) );
	  


		signal_m[j]->Rebin(2);
                mirror_m[j]->Rebin(2);
		signal_tt[j]->Rebin(2);
		mirror_tt[j]->Rebin(2);
		signal_qcd[j]->Rebin(2);
		mirror_qcd[j]->Rebin(2);


		signal_m[j]->Scale(1.0/signal_m[j]->Integral());
		mirror_m[j]->Scale(1.0/mirror_m[j]->Integral());
		signal_tt[j]->Scale(1.0/signal_tt[j]->Integral());
		mirror_tt[j]->Scale(1.0/mirror_tt[j]->Integral());
		signal_qcd[j]->Scale(1.0/signal_qcd[j]->Integral());
		mirror_qcd[j]->Scale(1.0/mirror_qcd[j]->Integral());


		signal_m[j]->SetLineColor(kRed);
		mirror_m[j]->SetLineColor(38);
		signal_tt[j]->SetLineColor(42);
		mirror_tt[j]->SetLineColor(28);
		signal_qcd[j]->SetLineColor(8);
		mirror_qcd[j]->SetLineColor(6);

		signal_m[j]->SetLineWidth(2);
		mirror_m[j]->SetLineWidth(2);
		signal_tt[j]->SetLineWidth(2);
		mirror_tt[j]->SetLineWidth(2);
		signal_qcd[j]->SetLineWidth(2);
		mirror_qcd[j]->SetLineWidth(2);


		TCanvas *c1 = new TCanvas("c1","c1",800,600);

        	c1->cd(1);
		c1->SetGridx();
        	c1->SetGridy();
		mirror_qcd[j]->Draw("hist");
		//signal_m[j]->Draw("hist same");
		//mirror_m[j]->Draw("hist same");
        	//signal_tt[j]->Draw("hist same");
		//mirror_tt[j]->Draw("hist same");
		signal_qcd[j]->Draw("hist same");
		//mirror_qcd[j]->Draw("hist same");

		mirror_qcd[j]->GetXaxis()->SetTitle("P_{T}[GeV]");
		mirror_qcd[j]->GetYaxis()->SetTitle("Normalized Entries");
		mirror_qcd[j]->GetYaxis()->SetTitleOffset(1.35);


		const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
          	TLatex latex;

		latex.SetNDC();
        	latex.SetTextSize(0.04);
       	 	latex.SetTextAlign(11);
        	latex.DrawLatex(0.68, 0.93, lumien);
        	latex.SetTextSize(0.05);
        	latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");

        	TLegend *legend1 = new TLegend(0.64,0.72,0.8,0.88);
		legend1->SetFillStyle(0);
        	legend1->SetBorderSize(0);
		legend1->SetTextFont(42);
		legend1->SetTextSize(0.03);
        	//legend1->AddEntry(signal_m[j],"SR M-1000","l");
        	//legend1->AddEntry(mirror_m[j],"CR M-1000","l");
		//legend1->AddEntry(signal_tt[j],"SR tt","l");
                //legend1->AddEntry(mirror_tt[j],"CR tt","l");
		legend1->AddEntry(signal_qcd[j],"SR qcd","l");
                legend1->AddEntry(mirror_qcd[j],"CR qcd","l");
        	legend1->Draw("same");


		char xname[500];

                sprintf(xname,"/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar1_qcd_toppt%i_baseline.png",j); 

        	c1->SaveAs(xname);
	  }




}
