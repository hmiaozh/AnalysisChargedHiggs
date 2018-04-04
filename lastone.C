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



const double lumin = 35.87;
const double extra = 1;



void lastone(){


//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mergept.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/goodday.root");


	setTDRStyle();

	TDirectoryFile* t0b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
//	TDirectoryFile* t1b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
//        TDirectoryFile* wbb = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
//        TDirectoryFile* wbj = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


	TH1D* PtAsytb_1000 = (TH1D*)t0b->Get("PtAsyHj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* PtAsytb_3000 =  (TH1D*)t0b->Get("PtAsyHj_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* PtAsytb_ttbar = (TH1D*)t0b->Get("PtAsyHj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* PtAsytb_qcd = (TH1D*)t0b->Get("PtAsyHj_QCD_HT");

	PtAsytb_1000->Scale(1.0/PtAsytb_1000->Integral());
        PtAsytb_3000->Scale(1.0/PtAsytb_3000->Integral());
        PtAsytb_ttbar->Scale(1.0/PtAsytb_ttbar->Integral());
        PtAsytb_qcd->Scale(1.0/PtAsytb_qcd->Integral());



	TH1D* dEtatb_1000 =  (TH1D*)t0b->Get("dEtaHj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* dEtatb_3000 =  (TH1D*)t0b->Get("dEtaHj_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dEtatb_ttbar = (TH1D*)t0b->Get("dEtaHj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dEtatb_qcd = (TH1D*)t0b->Get("dEtaHj_QCD_HT");

	dEtatb_1000->Scale(1.0/dEtatb_1000->Integral());
        dEtatb_3000->Scale(1.0/dEtatb_3000->Integral());
        dEtatb_ttbar->Scale(1.0/dEtatb_ttbar->Integral());
        dEtatb_qcd->Scale(1.0/dEtatb_qcd->Integral());


	
        TH1D* dPhitb_1000 = (TH1D*)t0b->Get("dPhiHj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* dPhitb_3000 = (TH1D*)t0b->Get("dPhiHj_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dPhitb_ttbar = (TH1D*)t0b->Get("dPhiHj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dPhitb_qcd = (TH1D*)t0b->Get("dPhiHj_QCD_HT");

	dPhitb_1000->Scale(1.0/dPhitb_1000->Integral());
        dPhitb_3000->Scale(1.0/dPhitb_3000->Integral());
        dPhitb_ttbar->Scale(1.0/dPhitb_ttbar->Integral());
        dPhitb_qcd->Scale(1.0/dPhitb_qcd->Integral());



	TH1D* b0pttb_1000 = (TH1D*)t0b->Get("dRHj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* b0pttb_3000 = (TH1D*)t0b->Get("dRHj_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* b0pttb_ttbar = (TH1D*)t0b->Get("dRHj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* b0pttb_qcd = (TH1D*)t0b->Get("dRHj_QCD_HT");

	b0pttb_1000->Scale(1.0/b0pttb_1000->Integral());
        b0pttb_3000->Scale(1.0/b0pttb_3000->Integral());
        b0pttb_ttbar->Scale(1.0/b0pttb_ttbar->Integral());
        b0pttb_qcd->Scale(1.0/b0pttb_qcd->Integral());



	b0pttb_1000->SetLineColor(46);
        b0pttb_1000->SetLineWidth(2);
//        b0pttb_1000->GetYaxis()->SetRangeUser(0,0.034);
        b0pttb_3000->SetLineColor(42);
        b0pttb_3000->SetLineWidth(2);
        b0pttb_ttbar->SetLineColor(38);
        b0pttb_ttbar->SetLineWidth(2);
        b0pttb_qcd->SetLineColor(30);
        b0pttb_qcd->SetLineWidth(2);

        PtAsytb_1000->SetLineColor(46);
        PtAsytb_1000->SetLineWidth(2);
//        PtAsytb_1000->GetYaxis()->SetRangeUser(0,0.054);
        PtAsytb_3000->SetLineColor(42);
        PtAsytb_3000->SetLineWidth(2);
        PtAsytb_ttbar->SetLineColor(38);
        PtAsytb_ttbar->SetLineWidth(2);
        PtAsytb_qcd->SetLineColor(30);
        PtAsytb_qcd->SetLineWidth(2);

        dEtatb_1000->SetLineColor(46);
        dEtatb_1000->SetLineWidth(2);
//        dEtatb_1000->GetXaxis()->SetRangeUser(0,4.);
        dEtatb_3000->SetLineColor(42);
        dEtatb_3000->SetLineWidth(2);
        dEtatb_ttbar->SetLineColor(38);
        dEtatb_ttbar->SetLineWidth(2);
        dEtatb_qcd->SetLineColor(30);
        dEtatb_qcd->SetLineWidth(2);

        dPhitb_1000->SetLineColor(46);
        dPhitb_1000->SetLineWidth(2);
//        dPhitb_1000->GetYaxis()->SetRangeUser(0,0.1);
        dPhitb_3000->SetLineColor(42);
        dPhitb_3000->SetLineWidth(2);
        dPhitb_ttbar->SetLineColor(38);
        dPhitb_ttbar->SetLineWidth(2);
        dPhitb_qcd->SetLineColor(30);
        dPhitb_qcd->SetLineWidth(2);


	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        b0pttb_qcd->Draw("hist");
        b0pttb_3000->Draw("hist same");
        b0pttb_ttbar->Draw("hist same");
        b0pttb_1000->Draw("hist same");

        TLegend *legend1 = new TLegend(0.64,0.72,0.92,0.98);
        legend1->AddEntry(b0pttb_1000,"1000GeV","l");
        legend1->AddEntry(b0pttb_3000,"3000GeV","l");
        legend1->AddEntry(b0pttb_ttbar,"TTbar","l");
        legend1->AddEntry(b0pttb_qcd,"QCD","l");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_DR_wbj.png");        
        
        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
        PtAsytb_qcd->Draw("hist");
        PtAsytb_3000->Draw("hist same");
        PtAsytb_ttbar->Draw("hist same");
        PtAsytb_1000->Draw("hist same");

        TLegend *legend2 = new TLegend(0.64,0.72,0.92,0.98);
        legend2->AddEntry(PtAsytb_1000,"1000GeV","l");
        legend2->AddEntry(PtAsytb_3000,"3000GeV","l");
        legend2->AddEntry(PtAsytb_ttbar,"TTbar","l");
        legend2->AddEntry(PtAsytb_qcd,"QCD","l");
        legend2->Draw("same");

        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_PtAsy_wbj.png");


        TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        dEtatb_1000->Draw("hist");
        dEtatb_3000->Draw("hist same");
        dEtatb_ttbar->Draw("hist same");
        dEtatb_qcd->Draw("hist same");

        TLegend *legend3 = new TLegend(0.64,0.72,0.92,0.98);
        legend3->AddEntry(dEtatb_1000,"1000GeV","l");
        legend3->AddEntry(dEtatb_3000,"3000GeV","l");
        legend3->AddEntry(dEtatb_ttbar,"TTbar","l");
        legend3->AddEntry(dEtatb_qcd,"QCD","l");
        legend3->Draw("same");

        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_dEta_wbj.png");


	TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        dPhitb_qcd->Draw("hist");
        dPhitb_3000->Draw("hist same");
        dPhitb_ttbar->Draw("hist same");
        dPhitb_1000->Draw("hist same");

        TLegend *legend4 = new TLegend(0.64,0.72,0.92,0.98);
        legend4->AddEntry(dPhitb_1000,"1000GeV","l");
        legend4->AddEntry(dPhitb_3000,"3000GeV","l");
        legend4->AddEntry(dPhitb_ttbar,"TTbar","l");
        legend4->AddEntry(dPhitb_qcd,"QCD","l");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_dPhi_wbj.png");













/*
	TH2D *wtbchart_800 = (TH2D*)f1->Get("merge_Wb");
	
	TCanvas *c99 = new TCanvas("c99","c99",800,600);
	c99->cd(1);
	wtbchart_800->Draw("colz");
	wtbchart_800->GetXaxis()->SetTitle("P_{T top}");
	wtbchart_800->GetYaxis()->SetTitle("#Delta(W,b)");
	wtbchart_800->GetYaxis()->SetRangeUser(0.0,4.0);
	wtbchart_800->GetZaxis()->SetRangeUser(0.00005,0.0024);

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");



	c99->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/DR_Wb.png");
*/





}
