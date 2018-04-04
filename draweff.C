#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "TProfile.h"
#include "TGraph.h"
#include "TFile.h"
#include "TTree.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include <string>
#include <vector>
#include <math.h>

/*
const double Mbottom = 5.0; // mass of bottom quark (4.6GeV)
const double Mw = 80.385;
const double Mtop = 173.34;

Int_t isWfromtopH(TLorentzVector recofatj, TLorentzVector genWth, TLorentzVector genWtass){  //1 = from top from higgs, 2 = from associated top, 0 = don't know

        if(recofatj.DeltaR(genWth) < 0.3) return 1;
	else if(recofatj.DeltaR(genWtass) < 0.3) return 2;
        else return 0;

}
*/


void draweff(){

        TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/eff_mistag_medium.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/eff_mistag_loose.root");
	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/eff_mistag_no.root");


	TGraph* eff_top_medium = (TGraph*)f1->Get("eff_top");
	TGraph* eff_QCD_medium = (TGraph*)f1->Get("eff_QCD");

	TGraph* eff_top_loose = (TGraph*)f2->Get("eff_top");
        TGraph* eff_QCD_loose = (TGraph*)f2->Get("eff_QCD");

	TGraph* eff_top_no = (TGraph*)f3->Get("eff_top");
        TGraph* eff_QCD_no = (TGraph*)f3->Get("eff_QCD");

	eff_top_loose->SetLineColor(46);
	eff_top_loose->SetLineWidth(2);
	eff_top_loose->SetMarkerColor(46);
	eff_top_loose->SetMarkerSize(1.5);
	eff_top_loose->SetMarkerStyle(20);
	eff_top_loose->GetYaxis()->SetRangeUser(0.1,0.56);

	eff_top_medium->SetLineColor(38);
        eff_top_medium->SetLineWidth(2);
        eff_top_medium->SetMarkerColor(38);
        eff_top_medium->SetMarkerSize(1.5);
        eff_top_medium->SetMarkerStyle(22);

	eff_top_no->SetLineColor(8);
        eff_top_no->SetLineWidth(2);
        eff_top_no->SetMarkerColor(8);
        eff_top_no->SetMarkerSize(1.5);
        eff_top_no->SetMarkerStyle(29);

	eff_QCD_loose->SetLineColor(46);
        eff_QCD_loose->SetLineWidth(2);
        eff_QCD_loose->SetMarkerColor(46);
        eff_QCD_loose->SetMarkerSize(1.5);
        eff_QCD_loose->SetMarkerStyle(20);
	eff_QCD_loose->GetYaxis()->SetRangeUser(0,0.15);


	eff_QCD_medium->SetLineColor(38);
        eff_QCD_medium->SetLineWidth(2);
        eff_QCD_medium->SetMarkerColor(38);
        eff_QCD_medium->SetMarkerSize(1.5);
        eff_QCD_medium->SetMarkerStyle(22);

	eff_QCD_no->SetLineColor(8);
        eff_QCD_no->SetLineWidth(2);
        eff_QCD_no->SetMarkerColor(8);
        eff_QCD_no->SetMarkerSize(1.5);
        eff_QCD_no->SetMarkerStyle(29);

        TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        eff_top_loose->Draw("ACP");
	eff_top_medium->Draw("CP");
	eff_top_no->Draw("CP");	

        TLegend *legend4 = new TLegend(0.72,0.72,0.98,0.96);
        legend4->AddEntry(eff_top_medium,"eff,Medium","LP");
	legend4->AddEntry(eff_top_loose,"eff,Loose","LP");
	legend4->AddEntry(eff_top_no,"eff,no","LP");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/eff_diffbtag.png");


        TCanvas *c = new TCanvas("c","c",800,600);
        c->cd(1);
        eff_QCD_loose->Draw("ACP");
	eff_QCD_medium->Draw("CP");
	eff_QCD_no->Draw("CP");

        TLegend *legend = new TLegend(0.72,0.72,0.98,0.96);
        legend->AddEntry(eff_QCD_medium,"mistag,Medium","LP");
	legend->AddEntry(eff_QCD_loose,"mistag,Loose","LP");
	legend->AddEntry(eff_QCD_no,"mistag,no","LP");
        legend->Draw("same");

        c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/mistag_diffbtag.png");




}
   
