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



void leftover(){


//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mergept.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ChHiggs_FullHad_wprifix.root");

	setTDRStyle();

	TDirectoryFile* t0b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
//	TDirectoryFile* t1b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
//        TDirectoryFile* wbb = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
//        TDirectoryFile* wbj = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	TDirectoryFile* wprime = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


	TH1D* nbjets_1000 = (TH1D*)t0b->Get("num_lo_bj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* nbjets_ttbar = (TH1D*)t0b->Get("num_lo_bj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* nbjets_qcd = (TH1D*)t0b->Get("num_lo_bj_QCD_HT");
	TH1D* nbjets_w = (TH1D*)wprime->Get("num_lo_bj_WprimeToTB_TToHad_M-1000");

	TH1D* nfjets_1000 =  (TH1D*)t0b->Get("num_lo_fj_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* nfjets_ttbar = (TH1D*)t0b->Get("num_lo_fj_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* nfjets_qcd = (TH1D*)t0b->Get("num_lo_fj_QCD_HT");
	TH1D* nfjets_w = (TH1D*)wprime->Get("num_lo_fj_WprimeToTB_TToHad_M-1000");
	
        TH1D* njets_1000 = (TH1D*)t0b->Get("num_lo_j_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* njets_ttbar = (TH1D*)t0b->Get("num_lo_j_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* njets_qcd = (TH1D*)t0b->Get("num_lo_j_QCD_HT");
	TH1D* njets_w = (TH1D*)wprime->Get("num_lo_j_WprimeToTB_TToHad_M-1000");


	THStack *numofb = new THStack("numofb","#bjets distribution");
      	THStack *numofj = new THStack("numofj","#jets distribution");
	THStack *numoffj = new THStack("numoffj","#fatjets distribution");

        nbjets_1000->SetLineColor(kRed-4);
        nbjets_1000->SetLineWidth(2);
        nbjets_1000->Scale(10*1000*lumin);
	nbjets_w->SetLineColor(kOrange-3);
	nbjets_w->SetLineWidth(2);
	nbjets_w->Scale(10);
        nbjets_ttbar->SetFillColor(kBlue-10);
        nbjets_ttbar->SetLineColor(kBlue-10);
        nbjets_ttbar->Scale(1000*lumin);
        nbjets_qcd->SetFillColor(kGreen-10);
        nbjets_qcd->SetLineColor(kGreen-10);
        nbjets_qcd->Scale(1000*lumin);
        numofb->Add(nbjets_ttbar);
        numofb->Add(nbjets_qcd);

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;


	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        c3->SetLogy();
        numofb->Draw("hist");
        numofb->GetXaxis()->SetTitle("number of remaining bjets");
        numofb->GetXaxis()->SetBinLabel(1,"0");
        numofb->GetXaxis()->SetBinLabel(2,"1");
        numofb->GetXaxis()->SetBinLabel(3,"2");
	numofb->GetXaxis()->SetBinLabel(4,"3");
	numofb->GetXaxis()->SetBinLabel(5,"4");
	numofb->GetXaxis()->SetBinLabel(6,"5");
	numofb->GetXaxis()->SetBinLabel(7,"6");
	numofb->GetXaxis()->SetBinLabel(8,"7");
	numofb->GetXaxis()->SetBinLabel(9,"8");
        numofb->GetXaxis()->SetBinLabel(10,"#geq 9bjets");
        numofb->GetYaxis()->SetTitle("Events");
        nbjets_1000->Draw("hist same");
	nbjets_w->Draw("hist same");
	
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");


        TLegend *legendx = new TLegend(0.63,0.74,0.85,0.88);
        legendx->AddEntry(nbjets_1000,"Ch-higgs,1000GeV","l");
	legendx->AddEntry(nbjets_w,"WPrime,1000GeV","l");
        legendx->AddEntry(nbjets_ttbar,"TTbar","f");
        legendx->AddEntry(nbjets_qcd,"QCD","f");
        legendx->Draw("same");

    //    c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_numofb_wbj.png");



	njets_1000->SetLineColor(kRed-4);
        njets_1000->SetLineWidth(2);
        njets_1000->Scale(1000*lumin);
	njets_w->SetLineColor(kOrange-3);
        njets_w->SetLineWidth(2);
        njets_w->Scale(1000*lumin);
        njets_ttbar->SetFillColor(kBlue-10);
        njets_ttbar->SetLineColor(kBlue-10);
        njets_ttbar->Scale(1000*lumin);
        njets_qcd->SetFillColor(kGreen-10);
        njets_qcd->SetLineColor(kGreen-10);
        njets_qcd->Scale(1000*lumin);
        numofj->Add(njets_ttbar);
        numofj->Add(njets_qcd);



        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
        c2->SetLogy();
        numofj->Draw("hist");
        numofj->GetXaxis()->SetTitle("number of remaining jets");
        numofj->GetXaxis()->SetBinLabel(1,"0");
        numofj->GetXaxis()->SetBinLabel(2,"1");
        numofj->GetXaxis()->SetBinLabel(3,"2");
        numofj->GetXaxis()->SetBinLabel(4,"3");
        numofj->GetXaxis()->SetBinLabel(5,"4");
        numofj->GetXaxis()->SetBinLabel(6,"5");
        numofj->GetXaxis()->SetBinLabel(7,"6");
        numofj->GetXaxis()->SetBinLabel(8,"7");
        numofj->GetXaxis()->SetBinLabel(9,"8");
        numofj->GetXaxis()->SetBinLabel(10,"#geq 9jets");
        numofj->GetYaxis()->SetTitle("Events");
        njets_1000->Draw("hist same");
	njets_w->Draw("hist same");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legendy = new TLegend(0.63,0.74,0.85,0.88);
        legendy->AddEntry(njets_1000,"associated production","l");
	legendy->AddEntry(njets_w,"s-channel","l");
        legendy->AddEntry(njets_ttbar,"TTbar","f");
        legendy->AddEntry(njets_qcd,"QCD","f");
        legendy->Draw("same");

  //      c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_numofj_wbj.png");


        nfjets_1000->SetLineColor(kRed-4);
        nfjets_1000->SetLineWidth(2);
        nfjets_1000->Scale(10*1000*lumin);
	nfjets_w->SetLineColor(kOrange-3);
        nfjets_w->SetLineWidth(2);
        nfjets_w->Scale(10);
	nfjets_ttbar->SetFillColor(kBlue-10);
        nfjets_ttbar->SetLineColor(kBlue-10);
        nfjets_ttbar->Scale(1000*lumin);
    
	cout << "whose problem" << endl;

	    nfjets_qcd->SetFillColor(kGreen-10);
        nfjets_qcd->SetLineColor(kGreen-10);
        nfjets_qcd->Scale(1000*lumin);
        numoffj->Add(nfjets_ttbar);
        numoffj->Add(nfjets_qcd);

	cout << "nandaoshuo" << endl;


        TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        c1->SetLogy();
        numoffj->Draw("hist");
        numoffj->GetXaxis()->SetTitle("number of remaining fatjets");
        numoffj->GetXaxis()->SetBinLabel(1,"0");
        numoffj->GetXaxis()->SetBinLabel(2,"1");
        numoffj->GetXaxis()->SetBinLabel(3,"2");
        numoffj->GetXaxis()->SetBinLabel(4,"3");
        numoffj->GetXaxis()->SetBinLabel(5,"4");
        numoffj->GetXaxis()->SetBinLabel(6,"5");
        numoffj->GetXaxis()->SetBinLabel(7,"6");
        numoffj->GetXaxis()->SetBinLabel(8,"7");
        numoffj->GetXaxis()->SetBinLabel(9,"8");
        numoffj->GetXaxis()->SetBinLabel(10,"#geq 9fatjets");
        numoffj->GetYaxis()->SetTitle("Events");
        nfjets_1000->Draw("hist same");
	nfjets_w->Draw("hist same");


	cout << "hey!" << endl;


        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legendz = new TLegend(0.63,0.74,0.85,0.88);
        legendz->AddEntry(nfjets_1000,"Ch-higgs,1000GeV","l");
	legendz->AddEntry(nfjets_w,"WPrime,1000GeV","l");
        legendz->AddEntry(nfjets_ttbar,"TTbar","f");
        legendz->AddEntry(nfjets_qcd,"QCD","f");
        legendz->Draw("same");

//        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_numoffj_wbj.png");



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
