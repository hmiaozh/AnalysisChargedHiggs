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



void wslastone(){


//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mergept.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");


	setTDRStyle();

	TDirectoryFile* t0b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");
	TDirectoryFile* t1b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
//        TDirectoryFile* wbb = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
//        TDirectoryFile* wbj = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


	TH2D* PtAsytb_10000 = (TH2D*)t0b->Get("Pt_Mass_tb_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
//        TH1D* PtAsytb_3000 =  (TH1D*)t0b->Get("PtAsyHj_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH2D* PtAsytb_ttbar = (TH2D*)t1b->Get("Pt_Mass_tb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH2D* PtAsytb_1000 = (TH2D*)t1b->Get("Pt_Mass_tb_QCD_HT");
/*
	PtAsytb_1000->Scale(1.0/PtAsytb_1000->Integral());
        PtAsytb_3000->Scale(1.0/PtAsytb_3000->Integral());
        PtAsytb_ttbar->Scale(1.0/PtAsytb_ttbar->Integral());
        PtAsytb_qcd->Scale(1.0/PtAsytb_qcd->Integral());


        PtAsytb_1000->SetLineColor(46);
        PtAsytb_1000->SetLineWidth(2);
//        PtAsytb_1000->GetYaxis()->SetRangeUser(0,0.054);
        PtAsytb_3000->SetLineColor(42);
        PtAsytb_3000->SetLineWidth(2);
        PtAsytb_ttbar->SetLineColor(38);
        PtAsytb_ttbar->SetLineWidth(2);
        PtAsytb_qcd->SetLineColor(30);
        PtAsytb_qcd->SetLineWidth(2);
*/
        
        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
        PtAsytb_1000->Draw("colz");
	PtAsytb_1000->GetXaxis()->SetTitle("M_{H^{+}}[GeV]");
	PtAsytb_1000->GetYaxis()->SetTitle("P_{T H^{+}} [GeV]");
	PtAsytb_1000->GetYaxis()->SetTitleOffset(1.5);
	PtAsytb_1000->GetYaxis()->SetRangeUser(400,1800);
	PtAsytb_1000->GetXaxis()->SetRangeUser(100,3200);

        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legend2 = new TLegend(0.64,0.72,0.92,0.98);
        legend2->AddEntry(PtAsytb_1000,"M-1000","l");
  //      legend2->Draw("same");

//        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/leftover_PtAsy_wbj.png");





/*
	TH2D *wtbchart_800 = (TH2D*)f1->Get("merge_Wb");
	
	TCanvas *c99 = new TCanvas("c99","c99",800,600);
	c99->cd(1);
	wtbchart_800->Draw("colz");
	wtbchart_800->GetXaxis()->SetTitle("P_{T top}[GeV]");
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
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");



//	c99->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/DR_Wb.png");

*/




}
