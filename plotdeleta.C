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
#include "TLatex.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

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


void plotdeleta(){

	setTDRStyle();

        TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/signalmay_update.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/qcdmay_update.root");



	TH1D* dr_3_t_800 = (TH1D*)f1->Get("deleta_3_t_800");
	TH1D* dr_3_nt_w_800 = (TH1D*)f1->Get("deleta_3_nt_w_800");
        TH1D* dr_3_nt_nw_800 = (TH1D*)f1->Get("deleta_3_nt_nw_800");
        TH1D* dr_3_t_3000 = (TH1D*)f1->Get("deleta_3_t_3000");
        TH1D* dr_3_nt_w_3000 = (TH1D*)f1->Get("deleta_3_nt_w_3000");
	TH1D* dr_3_nt_nw_3000 = (TH1D*)f1->Get("deleta_3_nt_nw_3000");
/*
	TH1D* dr_800_total = (TH1D*)f1->Get("deleta_3_t_800");
	TH1D* dr_3000_total = (TH1D*)f1->Get("deleta_3_t_3000");

	dr_800_total->Add(dr_3_nt_w_800);
	dr_800_total->Add(dr_3_nt_nw_800);
	dr_3000_total->Add(dr_3_nt_w_3000);
	dr_3000_total->Add(dr_3_nt_nw_3000);
*/
        TH1D* dr_ttbar_tb = (TH1D*)f1->Get("deleta_3_ttbar");
        TH1D* dr_qcd_tb = (TH1D*)f2->Get("deleta_3_qcd");

//	dr_800_total->Rebin(2);
//	dr_3000_total->Rebin(2);

	dr_3_t_800->Rebin(2);
	dr_3_t_3000->Rebin(2);

	dr_ttbar_tb->Rebin(2);
	dr_qcd_tb->Rebin(2);


	dr_3_t_800->Scale(1.0/dr_3_t_800->Integral());
        dr_3_t_3000->Scale(1.0/dr_3_t_3000->Integral());

//	dr_800_total->Scale(1.0/dr_800_total->Integral());
//	dr_3000_total->Scale(1.0/dr_3000_total->Integral());

        dr_ttbar_tb->Scale(1.0/dr_ttbar_tb->Integral());
        dr_qcd_tb->Scale(1.0/dr_qcd_tb->Integral());




	dr_3_t_800->SetLineColor(46);
	dr_3_t_800->SetLineWidth(2);
	dr_3_t_800->GetXaxis()->SetTitle("#Delta#eta(t(W+b),b)");
	dr_3_t_800->GetYaxis()->SetTitle("Normalized Entries");;
	dr_3_t_800->GetYaxis()->SetTitleOffset(1.35);
	dr_3_t_3000->SetLineColor(42);
	dr_3_t_3000->SetLineWidth(2);
/*
	dr_800_total->SetLineColor(49);
	dr_800_total->SetLineWidth(2);
	dr_3000_total->SetLineColor(21);
	dr_3000_total->SetLineWidth(2);
*/
	dr_ttbar_tb->SetLineColor(38);
	dr_ttbar_tb->SetLineWidth(2);
	dr_qcd_tb->SetLineColor(30);
	dr_qcd_tb->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        dr_3_t_800->Draw("hist");
        dr_3_t_3000->Draw("hist same");
//        dr_800_total->Draw("hist");
//        dr_3000_total->Draw("hist same");
        dr_ttbar_tb->Draw("hist same");
        dr_qcd_tb->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");


	TLegend *legend1 = new TLegend(0.63,0.74,0.85,0.88);
        legend1->AddEntry(dr_3_t_800,"800GeV","l");
        legend1->AddEntry(dr_3_t_3000,"1000GeV","l");
//        legend1->AddEntry(dr_800_total,"800GeV","l");
//        legend1->AddEntry(dr_3000_total,"1000GeV","l");
        legend1->AddEntry(dr_ttbar_tb,"TTbar","l");
        legend1->AddEntry(dr_qcd_tb,"QCD","l");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/deltaeta.png");




}
   
