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


void drawsb(){

	setTDRStyle();

        TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_medium.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_loose.root");
	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_no.root");
	TFile* f4 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_08cut.root");
	TFile* f5 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_10cut.root");
	TFile* f6 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_12cut.root");
	TFile* f7 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_15cut.root");
	TFile* f8 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_18cut.root");
	TFile* f9 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_20cut.root");


	TGraph* eff_tb_ht = (TGraph*)f1->Get("eff_tb");
	TGraph* eff_wbb_ht = (TGraph*)f1->Get("eff_wbb");

	TGraph* eff_tb_nht = (TGraph*)f2->Get("eff_tb");
	TGraph* eff_wbb_nht = (TGraph*)f2->Get("eff_wbb");

	TGraph* eff_tb_no = (TGraph*)f3->Get("eff_tb");
	TGraph* eff_wbb_no = (TGraph*)f3->Get("eff_wbb");

	TGraph* eff_wbb_eta08 = (TGraph*)f4->Get("eff_wbb");
	TGraph* eff_wbb_eta10 = (TGraph*)f5->Get("eff_wbb");
	TGraph* eff_wbb_eta12 = (TGraph*)f6->Get("eff_wbb");	
	TGraph* eff_wbb_eta15 = (TGraph*)f7->Get("eff_wbb");
	TGraph* eff_wbb_eta18 = (TGraph*)f8->Get("eff_wbb");
	TGraph* eff_wbb_eta20 = (TGraph*)f9->Get("eff_wbb");

	eff_tb_ht->SetLineColor(38);
	eff_tb_ht->SetLineWidth(2);
	eff_tb_ht->SetMarkerColor(38);
	eff_tb_ht->SetMarkerSize(1.5);
	eff_tb_ht->SetMarkerStyle(22);
	eff_tb_ht->GetYaxis()->SetRangeUser(0,0.03);
	eff_tb_ht->GetXaxis()->SetTitle("M_{H^{+}}");
        eff_tb_ht->GetYaxis()->SetTitle("#surd S/B");


	eff_tb_nht->SetLineColor(46);
        eff_tb_nht->SetLineWidth(2);
        eff_tb_nht->SetMarkerColor(46);
        eff_tb_nht->SetMarkerSize(1.5);
        eff_tb_nht->SetMarkerStyle(20);

	eff_tb_no->SetLineColor(8);
        eff_tb_no->SetLineWidth(2);
        eff_tb_no->SetMarkerColor(8);
        eff_tb_no->SetMarkerSize(1.5);
        eff_tb_no->SetMarkerStyle(29);

        TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        eff_tb_ht->Draw("AP");
	eff_tb_nht->Draw("P");
	eff_tb_no->Draw("P");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

        TLegend *legend4 = new TLegend(0.63,0.74,0.85,0.88);
        legend4->AddEntry(eff_tb_ht,"tb,Medium","LP");
	legend4->AddEntry(eff_tb_nht,"tb,Loose","LP");
	legend4->AddEntry(eff_tb_no,"tb,no","LP");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/subbtag_tb.png");

        eff_wbb_ht->SetLineColor(38);
        eff_wbb_ht->SetLineWidth(2);
        eff_wbb_ht->SetMarkerColor(38);
        eff_wbb_ht->SetMarkerSize(1.5);
        eff_wbb_ht->SetMarkerStyle(22);
        eff_wbb_ht->GetYaxis()->SetRangeUser(0,0.02);
	eff_wbb_ht->GetXaxis()->SetTitle("M_{H^{+}}");
        eff_wbb_ht->GetYaxis()->SetTitle("#surd S/B");


	eff_wbb_nht->SetLineColor(46);
        eff_wbb_nht->SetLineWidth(2);
        eff_wbb_nht->SetMarkerColor(46);
        eff_wbb_nht->SetMarkerSize(1.5);
        eff_wbb_nht->SetMarkerStyle(20);

	eff_wbb_no->SetLineColor(8);
        eff_wbb_no->SetLineWidth(2);
        eff_wbb_no->SetMarkerColor(8);
        eff_wbb_no->SetMarkerSize(1.5);
        eff_wbb_no->SetMarkerStyle(29);


        TCanvas *c = new TCanvas("c","c",800,600);
        c->cd(1);
        eff_wbb_ht->Draw("AP");
	eff_wbb_nht->Draw("P");
	eff_wbb_no->Draw("P");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

        TLegend *legend = new TLegend(0.63,0.74,0.85,0.88);
        legend->AddEntry(eff_wbb_ht,"wbb,Medium","LP");
	legend->AddEntry(eff_wbb_nht,"wbb,Loose","LP");
	legend->AddEntry(eff_wbb_no,"wbb,no","LP");
        legend->Draw("same");

        c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/subbtag_wbb.png");


	eff_wbb_eta08->SetLineColor(kRed-7);
        eff_wbb_eta08->SetLineWidth(2);
        eff_wbb_eta08->SetMarkerColor(kRed-7);
        eff_wbb_eta08->SetMarkerSize(1.5);
        eff_wbb_eta08->SetMarkerStyle(20);
	eff_wbb_eta08->GetYaxis()->SetRangeUser(0,0.048);
	eff_wbb_eta08->GetXaxis()->SetTitle("M_{H^{+}}");
	eff_wbb_eta08->GetHistogram()->GetYaxis()->SetTitle("#surd S/B");
//	eff_wbb_eta08->SetTitle(";M_{H^{+}};why");
	
	eff_wbb_eta10->SetLineColor(38);
        eff_wbb_eta10->SetLineWidth(2);
        eff_wbb_eta10->SetMarkerColor(38);
        eff_wbb_eta10->SetMarkerSize(1.5);
        eff_wbb_eta10->SetMarkerStyle(21);


	eff_wbb_eta12->SetLineColor(kPink+1);
        eff_wbb_eta12->SetLineWidth(2);
        eff_wbb_eta12->SetMarkerColor(kPink+1);
        eff_wbb_eta12->SetMarkerSize(1.5);
        eff_wbb_eta12->SetMarkerStyle(22);


	eff_wbb_eta15->SetLineColor(kViolet+6);
        eff_wbb_eta15->SetLineWidth(2);
        eff_wbb_eta15->SetMarkerColor(kViolet+6);
        eff_wbb_eta15->SetMarkerSize(1.5);
        eff_wbb_eta15->SetMarkerStyle(23);

	eff_wbb_eta18->SetLineColor(kRed-1);
        eff_wbb_eta18->SetLineWidth(2);
        eff_wbb_eta18->SetMarkerColor(kRed-1);
        eff_wbb_eta18->SetMarkerSize(1.5);
        eff_wbb_eta18->SetMarkerStyle(33);
	
	eff_wbb_eta20->SetLineColor(kAzure+1);
        eff_wbb_eta20->SetLineWidth(2);
        eff_wbb_eta20->SetMarkerColor(kAzure+1);
        eff_wbb_eta20->SetMarkerSize(1.5);
        eff_wbb_eta20->SetMarkerStyle(34);

	TCanvas *ce = new TCanvas("ce","ce",800,600);
        ce->cd(1);
	
        eff_wbb_eta08->Draw("AP");
        eff_wbb_eta10->Draw("P");
        eff_wbb_eta12->Draw("P");
	eff_wbb_eta15->Draw("P");
	eff_wbb_eta18->Draw("P");
	eff_wbb_eta20->Draw("P");
	eff_wbb_no->Draw("P");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");



        TLegend *legende = new TLegend(0.6,0.7,0.85,0.88);
        legende->AddEntry(eff_wbb_eta08,"del_eta<0.8","LP");
        legende->AddEntry(eff_wbb_eta10,"del_eta<1.0","LP");
        legende->AddEntry(eff_wbb_eta12,"del_eta<1.2","LP");
	legende->AddEntry(eff_wbb_eta15,"del_eta<1.5","LP");
	legende->AddEntry(eff_wbb_eta18,"del_eta<1.8","LP");
	legende->AddEntry(eff_wbb_eta20,"del_eta<2.0","LP");
	legende->AddEntry(eff_wbb_no,"no cut","LP");
        legende->Draw("same");

        ce->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/deleta_wbb.png");
	



}
   
