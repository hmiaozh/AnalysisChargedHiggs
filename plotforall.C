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

void plotforall(){


	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/SoHot.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/a1000ffgg.root");
	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/ttffgg.root");
	TFile* f4 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/qcdffgg.root");

	TDirectoryFile* t0b_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
	TDirectoryFile* t1b_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
	TDirectoryFile* wbb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
        TDirectoryFile* wbj_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	TDirectoryFile* wbj_a1000    = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	TDirectoryFile* wbj_tt = (TDirectoryFile*)f3->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	TDirectoryFile* wbj_qcd = (TDirectoryFile*)f4->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


	TH1D* mass_t0b_1000 = (TH1D*)t0b_combined->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	TH1D* mass_t0b_qcd = (TH1D*)t0b_combined->Get("invariantExt_QCD_HT");
	TH1D* mass_t0b_ttbar = (TH1D*)t0b_combined->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
 
	TH1D* mass_t1b_1000 = (TH1D*)t1b_combined->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* mass_t1b_qcd = (TH1D*)t1b_combined->Get("invariantExt_QCD_HT");
        TH1D* mass_t1b_ttbar = (TH1D*)t1b_combined->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");

	TH1D* invariant_wbj_1000a = (TH1D*)wbj_a1000->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
//	TH1D* invariant_wbb_ttbar = (TH1D*)wbb_tt->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
//	TH1D* invariant_wbb_qcd = (TH1D*)wbb_qcd->Get("invariantExt_QCD_HT");
	TH1D* invariant_wbb_1000 = (TH1D*)wbb_combined->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8"); 
	TH1D* invariant_wbb_ttbar = (TH1D*)wbb_combined->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* invariant_wbb_qcd = (TH1D*)wbb_combined->Get("invariantExt_QCD_HT");


//	TH1D* invariant_wbj_1000 = (TH1D*)wbj_a1000->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
//	TH1D* invariant_wbj_ttbar = (TH1D*)wbj_tt->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
//	TH1D* invariant_wbj_qcd = (TH1D*)wbj_qcd->Get("invariantExt_QCD_HT");
	TH1D* invariant_wbj_1000 = (TH1D*)wbj_combined->Get("invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* invariant_wbj_ttbar = (TH1D*)wbj_combined->Get("invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* invariant_wbj_qcd = (TH1D*)wbj_combined->Get("invariantExt_QCD_HT");


	mass_t0b_1000->Rebin(2);
	mass_t0b_qcd->Rebin(2);
	mass_t0b_ttbar->Rebin(2);

	mass_t1b_1000->Rebin(2);
	mass_t1b_qcd->Rebin(2);
	mass_t1b_ttbar->Rebin(2);

	invariant_wbj_1000a->Rebin(2);
	invariant_wbb_1000->Rebin(2);
	invariant_wbb_ttbar->Rebin(2);
	invariant_wbb_qcd->Rebin(2);

	invariant_wbj_1000->Rebin(2);
	invariant_wbj_ttbar->Rebin(2);
	invariant_wbj_qcd->Rebin(2);


	invariant_wbj_1000a->Scale(1.0/invariant_wbj_1000a->Integral());
	invariant_wbj_1000->Scale(1.0/invariant_wbj_1000->Integral());

/*
	TH1D* b0pttb_800 = (TH1D*)tbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* b0pttb_3000 = (TH1D*)tbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* b0pttb_ttbar = (TH1D*)tbhad->Get("PtB1_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* b0pttb_qcd = (TH1D*)tbhad->Get("PtB1_QCD_HT");

	TH1D* PtAsytb_800 = (TH1D*)tbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* PtAsytb_3000 =  (TH1D*)tbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* PtAsytb_ttbar = (TH1D*)tbhad->Get("PtAsytb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* PtAsytb_qcd = (TH1D*)tbhad->Get("PtAsytb_QCD_HT");

	TH1D* dEtatb_800 =  (TH1D*)tbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* dEtatb_3000 =  (TH1D*)tbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* dEtatb_ttbar = (TH1D*)tbhad->Get("dEtatb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* dEtatb_qcd = (TH1D*)tbhad->Get("dEtatb_QCD_HT");

	TH1D* dPhitb_800 = (TH1D*)tbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* dPhitb_3000 = (TH1D*)tbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* dPhitb_ttbar = (TH1D*)tbhad->Get("dPhitb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* dPhitb_qcd = (TH1D*)tbhad->Get("dPhitb_QCD_HT");


	TH1D* b0ptwbb_800 = (TH1D*)wbbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* b0ptwbb_3000 = (TH1D*)wbbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* b0ptwbb_ttbar = (TH1D*)wbbhad->Get("PtB1_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* b0ptwbb_qcd = (TH1D*)wbbhad->Get("PtB1_QCD_HT");

        TH1D* PtAsywbb_800 = (TH1D*)wbbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* PtAsywbb_3000 = (TH1D*)wbbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* PtAsywbb_ttbar = (TH1D*)wbbhad->Get("PtAsytb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* PtAsywbb_qcd = (TH1D*)wbbhad->Get("PtAsytb_QCD_HT");

        TH1D* dEtawbb_800 = (TH1D*)wbbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* dEtawbb_3000 = (TH1D*)wbbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dEtawbb_ttbar = (TH1D*)wbbhad->Get("dEtatb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dEtawbb_qcd = (TH1D*)wbbhad->Get("dEtatb_QCD_HT");

        TH1D* dPhiwbb_800 = (TH1D*)wbbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* dPhiwbb_3000 = (TH1D*)wbbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dPhiwbb_ttbar = (TH1D*)wbbhad->Get("dPhitb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dPhiwbb_qcd = (TH1D*)wbbhad->Get("dPhitb_QCD_HT");

*/
	THStack *invariant_t0b = new THStack("invariant_t0b","invariant_t0b");
	THStack *invariant_t1b = new THStack("invariant_t1b","invariant_t1b");
	THStack *invariant_tb = new THStack("invariant_tb","invariant_tb");
	THStack *invariant_wbb = new THStack("invariant_wbb","invariant_wbb");
        THStack *invariant_wbj = new THStack("invariant_wbj","invariant_wbj");

/*	b0pttb_800->Scale(1.0/b0pttb_800->Integral());
	b0pttb_3000->Scale(1.0/b0pttb_3000->Integral());
	b0pttb_ttbar->Scale(1.0/b0pttb_ttbar->Integral());
	b0pttb_qcd->Scale(1.0/b0pttb_qcd->Integral());

	PtAsytb_800->Scale(1.0/PtAsytb_800->Integral());
	PtAsytb_3000->Scale(1.0/PtAsytb_3000->Integral());
	PtAsytb_ttbar->Scale(1.0/PtAsytb_ttbar->Integral());
	PtAsytb_qcd->Scale(1.0/PtAsytb_qcd->Integral());

	dEtatb_800->Scale(1.0/dEtatb_800->Integral());
	dEtatb_3000->Scale(1.0/dEtatb_3000->Integral());
	dEtatb_ttbar->Scale(1.0/dEtatb_ttbar->Integral());
	dEtatb_qcd->Scale(1.0/dEtatb_qcd->Integral());

	dPhitb_800->Scale(1.0/dPhitb_800->Integral());
	dPhitb_3000->Scale(1.0/dPhitb_3000->Integral());
	dPhitb_ttbar->Scale(1.0/dPhitb_ttbar->Integral());
	dPhitb_qcd->Scale(1.0/dPhitb_qcd->Integral());

	b0ptwbb_800->Scale(1.0/b0ptwbb_800->Integral());
	b0ptwbb_3000->Scale(1.0/b0ptwbb_3000->Integral());
	b0ptwbb_ttbar->Scale(1.0/b0ptwbb_ttbar->Integral());
	b0ptwbb_qcd->Scale(1.0/b0ptwbb_qcd->Integral());

	PtAsywbb_800->Scale(1.0/PtAsywbb_800->Integral());
	PtAsywbb_3000->Scale(1.0/PtAsywbb_3000->Integral());
	PtAsywbb_ttbar->Scale(1.0/PtAsywbb_ttbar->Integral());
	PtAsywbb_qcd->Scale(1.0/PtAsywbb_qcd->Integral());

	dEtawbb_800->Scale(1.0/dEtawbb_800->Integral());
	dEtawbb_3000->Scale(1.0/dEtawbb_3000->Integral());
	dEtawbb_ttbar->Scale(1.0/dEtawbb_ttbar->Integral());
	dEtawbb_qcd->Scale(1.0/dEtawbb_qcd->Integral());

	dPhiwbb_800->Scale(1.0/dPhiwbb_800->Integral());
	dPhiwbb_3000->Scale(1.0/dPhiwbb_3000->Integral());
	dPhiwbb_ttbar->Scale(1.0/dPhiwbb_ttbar->Integral());
	dPhiwbb_qcd->Scale(1.0/dPhiwbb_qcd->Integral());

	b0pttb_800->SetLineColor(46);
	b0pttb_800->SetLineWidth(2);
	b0pttb_800->GetYaxis()->SetRangeUser(0,0.034);
	b0pttb_3000->SetLineColor(42);
	b0pttb_3000->SetLineWidth(2);
	b0pttb_ttbar->SetLineColor(38);
	b0pttb_ttbar->SetLineWidth(2);
	b0pttb_qcd->SetLineColor(30);
	b0pttb_qcd->SetLineWidth(2);

	PtAsytb_800->SetLineColor(46);
	PtAsytb_800->SetLineWidth(2);
	PtAsytb_800->GetYaxis()->SetRangeUser(0,0.054);
	PtAsytb_3000->SetLineColor(42);
	PtAsytb_3000->SetLineWidth(2);
	PtAsytb_ttbar->SetLineColor(38);
	PtAsytb_ttbar->SetLineWidth(2);
	PtAsytb_qcd->SetLineColor(30);
	PtAsytb_qcd->SetLineWidth(2);

	dEtatb_800->SetLineColor(46);
	dEtatb_800->SetLineWidth(2);
	dEtatb_800->GetXaxis()->SetRangeUser(0,4.);
	dEtatb_3000->SetLineColor(42);
	dEtatb_3000->SetLineWidth(2);
	dEtatb_ttbar->SetLineColor(38);
	dEtatb_ttbar->SetLineWidth(2);
	dEtatb_qcd->SetLineColor(30);
	dEtatb_qcd->SetLineWidth(2);

	dPhitb_800->SetLineColor(46);
	dPhitb_800->SetLineWidth(2);
	dPhitb_800->GetYaxis()->SetRangeUser(0,0.1);
	dPhitb_3000->SetLineColor(42);
	dPhitb_3000->SetLineWidth(2);
	dPhitb_ttbar->SetLineColor(38);
	dPhitb_ttbar->SetLineWidth(2);
	dPhitb_qcd->SetLineColor(30);
	dPhitb_qcd->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        b0pttb_800->Draw("hist");
	b0pttb_3000->Draw("hist same");
	b0pttb_ttbar->Draw("hist same");
	b0pttb_qcd->Draw("hist same");

        TLegend *legend1 = new TLegend(0.64,0.72,0.92,0.98);
        legend1->AddEntry(b0pttb_800,"800GeV,t+b","f");
        legend1->AddEntry(b0pttb_3000,"3000GeV,t+b","f");
        legend1->AddEntry(b0pttb_ttbar,"TTbar,t+b","f");
	legend1->AddEntry(b0pttb_qcd,"QCD,t+b","f");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0pttb.png");	
	
        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
	PtAsytb_800->Draw("hist");
	PtAsytb_3000->Draw("hist same");
	PtAsytb_ttbar->Draw("hist same");
	PtAsytb_qcd->Draw("hist same");

	TLegend *legend2 = new TLegend(0.64,0.72,0.92,0.98);
        legend2->AddEntry(PtAsytb_800,"800GeV,t+b","f");
        legend2->AddEntry(PtAsytb_3000,"3000GeV,t+b","f");
        legend2->AddEntry(PtAsytb_ttbar,"TTbar,t+b","f");
        legend2->AddEntry(PtAsytb_qcd,"QCD,t+b","f");
        legend2->Draw("same");

        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsytb.png");


	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        dEtatb_800->Draw("hist");
        dEtatb_3000->Draw("hist same");
        dEtatb_ttbar->Draw("hist same");
        dEtatb_qcd->Draw("hist same");

        TLegend *legend3 = new TLegend(0.64,0.72,0.92,0.98);
        legend3->AddEntry(dEtatb_800,"800GeV,t+b","f");
        legend3->AddEntry(dEtatb_3000,"3000GeV,t+b","f");
        legend3->AddEntry(dEtatb_ttbar,"TTbar,t+b","f");
        legend3->AddEntry(dEtatb_qcd,"QCD,t+b","f");
        legend3->Draw("same");

        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtatb.png");

	TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        dPhitb_800->Draw("hist");
        dPhitb_3000->Draw("hist same");
        dPhitb_ttbar->Draw("hist same");
        dPhitb_qcd->Draw("hist same");

        TLegend *legend4 = new TLegend(0.64,0.72,0.92,0.98);
        legend4->AddEntry(dPhitb_800,"800GeV,t+b","f");
        legend4->AddEntry(dPhitb_3000,"3000GeV,t+b","f");
        legend4->AddEntry(dPhitb_ttbar,"TTbar,t+b","f");
        legend4->AddEntry(dPhitb_qcd,"QCD,t+b","f");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dPhitb.png");


	b0ptwbb_800->SetLineColor(46);
        b0ptwbb_800->SetLineWidth(2);
	b0ptwbb_800->GetYaxis()->SetRangeUser(0,0.024);
        b0ptwbb_3000->SetLineColor(42);
        b0ptwbb_3000->SetLineWidth(2);
        b0ptwbb_ttbar->SetLineColor(38);
        b0ptwbb_ttbar->SetLineWidth(2);
        b0ptwbb_qcd->SetLineColor(30);
        b0ptwbb_qcd->SetLineWidth(2);

        PtAsywbb_800->SetLineColor(46);
        PtAsywbb_800->SetLineWidth(2);
//	PtAsywbb_800->GetYaxis()->SetRangeUser(0,0.04);
        PtAsywbb_3000->SetLineColor(42);
        PtAsywbb_3000->SetLineWidth(2);
        PtAsywbb_ttbar->SetLineColor(38);
        PtAsywbb_ttbar->SetLineWidth(2);
        PtAsywbb_qcd->SetLineColor(30);
        PtAsywbb_qcd->SetLineWidth(2);

        dEtawbb_800->SetLineColor(46);
        dEtawbb_800->SetLineWidth(2);
	dEtawbb_800->GetXaxis()->SetRangeUser(0,4.);
        dEtawbb_3000->SetLineColor(42);
        dEtawbb_3000->SetLineWidth(2);
        dEtawbb_ttbar->SetLineColor(38);
        dEtawbb_ttbar->SetLineWidth(2);
        dEtawbb_qcd->SetLineColor(30);
        dEtawbb_qcd->SetLineWidth(2);

        dPhiwbb_800->SetLineColor(46);
        dPhiwbb_800->SetLineWidth(2);
	dPhiwbb_800->GetYaxis()->SetRangeUser(0,0.064);
        dPhiwbb_3000->SetLineColor(42);
        dPhiwbb_3000->SetLineWidth(2);
        dPhiwbb_ttbar->SetLineColor(38);
        dPhiwbb_ttbar->SetLineWidth(2);
        dPhiwbb_qcd->SetLineColor(30);
        dPhiwbb_qcd->SetLineWidth(2);


        TCanvas *c5 = new TCanvas("c5","c5",800,600);
        c5->cd(1);
        b0ptwbb_800->Draw("hist");
        b0ptwbb_3000->Draw("hist same");
        b0ptwbb_ttbar->Draw("hist same");
        b0ptwbb_qcd->Draw("hist same");
	

        TLegend *legend5 = new TLegend(0.64,0.72,0.92,0.98);
        legend5->AddEntry(b0pttb_800,"800GeV,w+b+b","f");
        legend5->AddEntry(b0pttb_3000,"3000GeV,W+b+b","f");
        legend5->AddEntry(b0pttb_ttbar,"TTbar,W++b","f");
        legend5->AddEntry(b0pttb_qcd,"QCD,W+b+b","f");
        legend5->Draw("same");

        c5->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0ptwbb.png");

        TCanvas *c6 = new TCanvas("c6","c6",800,600);
        c6->cd(1);
        PtAsywbb_800->Draw("hist");
        PtAsywbb_3000->Draw("hist same");
        PtAsywbb_ttbar->Draw("hist same");
        PtAsywbb_qcd->Draw("hist same");

        TLegend *legend6 = new TLegend(0.64,0.72,0.92,0.98);
        legend6->AddEntry(PtAsywbb_800,"800GeV,W+b+b","f");
        legend6->AddEntry(PtAsywbb_3000,"3000GeV,W+b+b","f");
        legend6->AddEntry(PtAsywbb_ttbar,"TTbar,W+b+b","f");
        legend6->AddEntry(PtAsywbb_qcd,"QCD,W+b+b","f");
        legend6->Draw("same");

        c6->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsywbb.png");


        TCanvas *c7 = new TCanvas("c7","c7",800,600);
        c7->cd(1);
        dEtawbb_800->Draw("hist");
        dEtawbb_3000->Draw("hist same");
        dEtawbb_ttbar->Draw("hist same");
        dEtawbb_qcd->Draw("hist same");

        TLegend *legend7 = new TLegend(0.64,0.72,0.92,0.98);
        legend7->AddEntry(dEtawbb_800,"800GeV,W+b+b","f");
        legend7->AddEntry(dEtawbb_3000,"3000GeV,W+b+b","f");
        legend7->AddEntry(dEtawbb_ttbar,"TTbar,W+b+b","f");
        legend7->AddEntry(dEtawbb_qcd,"QCD,W+b+b","f");
        legend7->Draw("same");

        c7->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtawbb.png");

        TCanvas *c8 = new TCanvas("c8","c8",800,600);
        c8->cd(1);
        dPhiwbb_800->Draw("hist");
        dPhiwbb_3000->Draw("hist same");
        dPhiwbb_ttbar->Draw("hist same");
        dPhiwbb_qcd->Draw("hist same");

        TLegend *legend8 = new TLegend(0.64,0.72,0.92,0.98);
        legend8->AddEntry(dPhiwbb_800,"800GeV,W+b+b","f");
        legend8->AddEntry(dPhiwbb_3000,"3000GeV,W+b+b","f");
        legend8->AddEntry(dPhiwbb_ttbar,"TTbar,W+b+b","f");
        legend8->AddEntry(dPhiwbb_qcd,"QCD,W+b+b","f");
        legend8->Draw("same");

        c8->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dPhiwbb.png");
*/

	mass_t0b_1000->SetFillColor(kRed-10);
	mass_t0b_1000->Scale(1000*lumin);
	mass_t0b_1000->SetLineColor(kRed-10);
	mass_t0b_ttbar->SetFillColor(kBlue-10);
        mass_t0b_ttbar->Scale(1000*lumin);
	mass_t0b_ttbar->SetLineColor(kBlue-10);
	mass_t0b_qcd->SetFillColor(kGreen-10);
	mass_t0b_qcd->Scale(1000*lumin);
	mass_t0b_qcd->SetLineColor(kGreen-10);

	mass_t1b_1000->SetFillColor(kRed-10);
        mass_t1b_1000->Scale(1000*lumin);
	mass_t1b_1000->SetLineColor(kRed-10);
        mass_t1b_ttbar->SetFillColor(kBlue-10);
        mass_t1b_ttbar->Scale(1000*lumin);
	mass_t1b_ttbar->SetLineColor(kBlue-10);
        mass_t1b_qcd->SetFillColor(kGreen-10);
        mass_t1b_qcd->Scale(1000*lumin);
	mass_t1b_qcd->SetLineColor(kGreen-10);

//	invariant_wbb_1000->SetFillColor(kRed-10);
//	invariant_wbb_1000->Scale(1000*lumin);
	invariant_wbb_1000->SetLineColor(kRed-3);
	invariant_wbj_1000a->SetLineColor(kBlue-3);
	invariant_wbb_ttbar->SetFillColor(kBlue-10);
	invariant_wbb_ttbar->Scale(1000*lumin);
	invariant_wbb_ttbar->SetLineColor(kBlue-10);
	invariant_wbb_qcd->SetFillColor(kGreen-10);
	invariant_wbb_qcd->Scale(1000*lumin);
	invariant_wbb_qcd->SetLineColor(kGreen-10);

//	invariant_wbj_1000->SetFillColor(kRed-10);
//        invariant_wbj_1000->Scale(1000*lumin);
	invariant_wbj_1000->SetLineColor(kRed-3);
        invariant_wbj_ttbar->SetFillColor(kBlue-10);
        invariant_wbj_ttbar->Scale(1000*lumin);
	invariant_wbj_ttbar->SetLineColor(kBlue-10);
        invariant_wbj_qcd->SetFillColor(kGreen-10);
        invariant_wbj_qcd->Scale(1000*lumin);
	invariant_wbj_qcd->SetLineColor(kGreen-10);



	invariant_t0b->Add(mass_t0b_1000);	
	invariant_t0b->Add(mass_t0b_ttbar);
	invariant_t0b->Add(mass_t0b_qcd);

	invariant_t1b->Add(mass_t1b_1000);
        invariant_t1b->Add(mass_t1b_ttbar);
        invariant_t1b->Add(mass_t1b_qcd);

	invariant_wbb->Add(invariant_wbb_1000);
	invariant_wbb->Add(invariant_wbb_ttbar);
	invariant_wbb->Add(invariant_wbb_qcd);
	
	invariant_wbj->Add(invariant_wbj_1000);
        invariant_wbj->Add(invariant_wbj_ttbar);
        invariant_wbj->Add(invariant_wbj_qcd);



	setTDRStyle();
//	gStyle->SetOptStat(1111);


	TCanvas *cha = new TCanvas("cha","cha",800,600);
	cha->cd(1);

	invariant_wbj_1000->Draw("hist");
	invariant_wbj_1000a->Draw("hist same");





        TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
        invariant_t0b->Draw("hist");
        invariant_t0b->GetXaxis()->SetRangeUser(600.,1400.0);
	invariant_t0b->GetXaxis()->SetTitle("M_{t+b}[GeV]");
	invariant_t0b->GetYaxis()->SetRangeUser(1.,16000.0);
	invariant_t0b->GetYaxis()->SetTitle("Event");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legend4a = new TLegend(0.63,0.74,0.85,0.88);
	legend4a->AddEntry(mass_t0b_1000,"1000GeV,t(0)+b","f");
        legend4a->AddEntry(mass_t0b_ttbar,"TTbar,t(0)+b","f");
	legend4a->AddEntry(mass_t0b_qcd,"QCD,t(0)+b","f");
        legend4a->Draw("same");

//        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/invariant_t0b.png");
///////
        TCanvas *c1b = new TCanvas("c1b","c1b",800,600);
        c1b->cd(1);
        invariant_t1b->Draw("hist");
        invariant_t1b->GetXaxis()->SetRangeUser(600.,1400.0);
	invariant_t1b->GetXaxis()->SetTitle("M_{t+b}[GeV]");
//	invariant_t1b->GetYaxis()->SetRangeUser(1.,5000.0);
	invariant_t1b->GetYaxis()->SetTitle("Events");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legend4b = new TLegend(0.63,0.74,0.85,0.88);
        legend4b->AddEntry(mass_t1b_1000,"800GeV,t(b)+b","f");
        legend4b->AddEntry(mass_t1b_ttbar,"TTbar,t(b)+b","f");
        legend4b->AddEntry(mass_t1b_qcd,"QCD,t(b)+b","f");
        legend4b->Draw("same");

//        c1b->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/invariant_t1b.png");
/////////
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);

	mass_t0b_1000->Add(mass_t1b_1000);
	mass_t0b_ttbar->Add(mass_t1b_ttbar);
	mass_t0b_qcd->Add(mass_t1b_qcd);
/*
	mass_t0b_1000->SetFillColor(kRed-10);
        mass_t0b_1000->Scale(1000*lumin);
        mass_t0b_ttbar->SetFillColor(kBlue-10);
        mass_t0b_ttbar->Scale(1000*lumin);
        mass_t0b_qcd->SetFillColor(kGreen-10);
        mass_t0b_qcd->Scale(1000*lumin);
*/
	invariant_tb->Add(mass_t0b_1000);
        invariant_tb->Add(mass_t0b_ttbar);
        invariant_tb->Add(mass_t0b_qcd);


        invariant_tb->Draw("hist");
        invariant_tb->GetXaxis()->SetRangeUser(600.,1400.0);
	invariant_tb->GetXaxis()->SetTitle("M_{t+b}[GeV]");
//        invariant_tb->GetYaxis()->SetRangeUser(1.,16000.0);
	invariant_tb->GetYaxis()->SetTitle("Events");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

        TLegend *legend4 = new TLegend(0.63,0.74,0.85,0.88);
        legend4->AddEntry(mass_t0b_1000,"1000GeV,t+b","f");
        legend4->AddEntry(mass_t0b_ttbar,"TTbar,t+b","f");
        legend4->AddEntry(mass_t0b_qcd,"QCD,t+b","f");
        legend4->Draw("same");

//        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/invariant_tb.png");





	TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
        invariant_wbb->Draw("hist");
        invariant_wbb->GetXaxis()->SetRangeUser(600.,1400.0);
	invariant_wbb->GetXaxis()->SetTitle("M_{W+b+b}[GeV]");
	invariant_wbb->GetYaxis()->SetTitle("Events");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");



	TLegend *legend2 = new TLegend(0.63,0.74,0.85,0.88);
        legend2->AddEntry(invariant_wbb_1000,"1000GeV,W+b+b","f");
        legend2->AddEntry(invariant_wbb_ttbar,"TTbar,W+b+b","f");
        legend2->AddEntry(invariant_wbb_qcd,"QCD,W+b+b","f");
        legend2->Draw("same");

 //       c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/invariant_wbb.png");
////////

	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        invariant_wbj->Draw("hist");
        invariant_wbj->GetXaxis()->SetRangeUser(600.,1400.0);
	invariant_wbj->GetXaxis()->SetTitle("M_{W+b+j}[GeV]");
        invariant_wbj->GetYaxis()->SetTitle("Events");
	
	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");
	

        TLegend *legend3 = new TLegend(0.63,0.74,0.85,0.88);
        legend3->AddEntry(invariant_wbj_1000,"1000GeV,W+b+j","f");
        legend3->AddEntry(invariant_wbj_ttbar,"TTbar,W+b+j","f");
        legend3->AddEntry(invariant_wbj_qcd,"QCD,W+b+j","f");
        legend3->Draw("same");

//        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/invariant_wbj.png");




}
