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



void newnsubcut(){


	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/lastdaynov.root");
	TFile* f4 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/fixfixgen.root");
	TFile* f7 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/qcdffgg.root");

	TDirectoryFile* ff = (TDirectoryFile*)f3->Get("ChargedHiggsTopBottom/Baseline");
	TDirectoryFile* ff1 = (TDirectoryFile*)f4->Get("ChargedHiggsTopBottom/Baseline");
	TDirectoryFile* ff2 = (TDirectoryFile*)f7->Get("ChargedHiggsTopBottom/Baseline");	


	TH1D* m800_w_cut = (TH1D*)ff1->Get("SDMass_lepw_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_ncut = (TH1D*)ff1->Get("SDMass_lepw_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_tcut = (TH1D*)ff1->Get("SDMass_lepw_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_ntcut = (TH1D*)ff1->Get("SDMass_lepw_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* bkg_w_cut = (TH1D*)ff1->Get("SDMass_lepw_wcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_w_ncut = (TH1D*)ff1->Get("SDMass_lepw_outwcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* bkg_w_tcut = (TH1D*)ff1->Get("SDMass_lepw_tcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* bkg_w_ntcut = (TH1D*)ff1->Get("SDMass_lepw_outtcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");

	TH1D* bkg_qcd_wcut = (TH1D*)ff->Get("SDMass_wcut_none_QCD_HT");
        TH1D* bkg_qcd_nwcut = (TH1D*)ff->Get("SDMass_outwcut_none_QCD_HT");
        TH1D* bkg_qcd_tcut = (TH1D*)ff->Get("SDMass_tcut_none_QCD_HT");
        TH1D* bkg_qcd_ntcut = (TH1D*)ff->Get("SDMass_outtcut_none_QCD_HT");


	TH1D* m800_t_cut = (TH1D*)ff1->Get("SDMass_lept_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_ncut = (TH1D*)ff1->Get("SDMass_lept_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_wcut = (TH1D*)ff1->Get("SDMass_lept_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_nwcut = (TH1D*)ff1->Get("SDMass_lept_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* bkg_t_cut = (TH1D*)ff1->Get("SDMass_lept_tcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_t_ncut = (TH1D*)ff1->Get("SDMass_lept_outtcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_t_wcut = (TH1D*)ff1->Get("SDMass_lept_wcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_t_nwcut = (TH1D*)ff1->Get("SDMass_lept_outwcut_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");



	TH1D* m800_hadw_cut = (TH1D*)ff->Get("SDMass_wcut_W_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_ncut = (TH1D*)ff->Get("SDMass_outwcut_W_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_tcut = (TH1D*)ff->Get("SDMass_tcut_W_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_ntcut = (TH1D*)ff->Get("SDMass_outtcut_W_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* m800_hadt_cut = (TH1D*)ff->Get("SDMass_tcut_top_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_ncut = (TH1D*)ff->Get("SDMass_outtcut_top_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_wcut = (TH1D*)ff->Get("SDMass_wcut_top_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_nwcut = (TH1D*)ff->Get("SDMass_outwcut_top_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* m800_b_wcut = (TH1D*)ff->Get("SDMass_wcut_bottom_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_nwcut = (TH1D*)ff->Get("SDMass_outwcut_bottom_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_tcut = (TH1D*)ff->Get("SDMass_tcut_bottom_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_ntcut = (TH1D*)ff->Get("SDMass_outtcut_bottom_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* SDmass_800_no_tcut = (TH1D*)ff->Get("SDMass_tcut_none_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* SDmass_800_no_outtcut = (TH1D*)ff->Get("SDMass_outtcut_none_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* SDmass_800_no_wcut = (TH1D*)ff->Get("SDMass_wcut_none_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* SDmass_800_no_outwcut = (TH1D*)ff->Get("SDMass_outwcut_none_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* bkg_hadw_cut = (TH1D*)ff->Get("SDMass_wcut_W_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadw_ncut = (TH1D*)ff->Get("SDMass_outwcut_W_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadw_tcut = (TH1D*)ff->Get("SDMass_tcut_W_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadw_ntcut = (TH1D*)ff->Get("SDMass_outtcut_W_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");

	TH1D* bkg_hadt_cut = (TH1D*)ff->Get("SDMass_tcut_top_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadt_ncut = (TH1D*)ff->Get("SDMass_outtcut_top_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadt_wcut = (TH1D*)ff->Get("SDMass_wcut_top_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_hadt_nwcut = (TH1D*)ff->Get("SDMass_outwcut_top_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");

	TH1D* bkg_b_wcut = (TH1D*)ff->Get("SDMass_wcut_bottom_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_b_nwcut = (TH1D*)ff->Get("SDMass_outwcut_bottom_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_b_tcut = (TH1D*)ff->Get("SDMass_tcut_bottom_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* bkg_b_ntcut = (TH1D*)ff->Get("SDMass_outtcut_bottom_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");

	TH1D* SDmass_bkg_no_tcut = (TH1D*)ff->Get("SDMass_tcut_none_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* SDmass_bkg_no_outtcut = (TH1D*)ff->Get("SDMass_outtcut_none_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* SDmass_bkg_no_wcut = (TH1D*)ff->Get("SDMass_wcut_none_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* SDmass_bkg_no_outwcut = (TH1D*)ff->Get("SDMass_outwcut_none_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");




	THStack *cutwall = new THStack("cutwall","tau21<0.6");
        THStack *ncutwall = new THStack("ncutwall","tau21>0.6");
        THStack *cuttall = new THStack("cuttall","tau32<0.81");
        THStack *ncuttall = new THStack("ncuttall","tau32>0.81");

	
	
	setTDRStyle();



//1
	m800_w_cut->SetLineColor(46);
        m800_w_cut->SetLineWidth(2);
        m800_w_cut->Scale(extra*1000*lumin);
        m800_t_wcut->SetLineColor(42);
        m800_t_wcut->SetLineWidth(2);
        m800_t_wcut->Scale(extra*1000*lumin);
	m800_b_wcut->SetLineColor(21);
	m800_b_wcut->SetLineWidth(2);
        m800_b_wcut->Scale(extra*1000*lumin);

        SDmass_800_no_wcut->SetLineColor(49);
        SDmass_800_no_wcut->SetLineWidth(2);
        SDmass_800_no_wcut->Scale(extra*1000*lumin);


	m800_hadw_cut->SetLineColor(2);
	m800_hadw_cut->SetLineWidth(2);
	m800_hadw_cut->Scale(extra*1000*lumin);
	m800_hadt_wcut->SetLineColor(6);
	m800_hadt_wcut->SetLineWidth(2);
	m800_hadt_wcut->Scale(extra*1000*lumin);



	bkg_w_cut->SetLineColor(29);
        bkg_w_cut->SetFillColor(29);
        bkg_w_cut->Scale(1000*lumin);
	bkg_t_wcut->SetLineColor(8);
        bkg_t_wcut->SetFillColor(8);
        bkg_t_wcut->Scale(1000*lumin);
	SDmass_bkg_no_wcut->SetLineColor(40);
        SDmass_bkg_no_wcut->SetFillColor(40);
        SDmass_bkg_no_wcut->Scale(1000*lumin);


	bkg_hadw_cut->SetLineColor(9);
	bkg_hadw_cut->SetFillColor(9);
	bkg_hadw_cut->Scale(1000*lumin);
	bkg_hadt_wcut->SetLineColor(38);
	bkg_hadt_wcut->SetFillColor(38);
	bkg_hadt_wcut->Scale(1000*lumin);
	bkg_b_wcut->SetLineColor(kOrange-2);
	bkg_b_wcut->SetFillColor(kOrange-2);
        bkg_b_wcut->Scale(1000*lumin);
	bkg_qcd_wcut->SetLineColor(30);
	bkg_qcd_wcut->SetFillColor(30);
        bkg_qcd_wcut->Scale(1000*lumin);



	cutwall->Add(bkg_hadw_cut);
	cutwall->Add(bkg_hadt_wcut);
//	cutwall->Add(bkg_w_cut);
//	cutwall->Add(bkg_t_wcut);
	cutwall->Add(bkg_b_wcut);
	cutwall->Add(SDmass_bkg_no_wcut);
	cutwall->Add(bkg_qcd_wcut);


//2

        m800_w_ncut->SetLineColor(46);
        m800_w_ncut->SetLineWidth(2);
        m800_w_ncut->Scale(extra*1000*lumin);	
        m800_t_nwcut->SetLineColor(42);
        m800_t_nwcut->SetLineWidth(2);
        m800_t_nwcut->Scale(extra*1000*lumin);
	m800_b_nwcut->SetLineColor(21);
        m800_b_nwcut->SetLineWidth(2);
        m800_b_nwcut->Scale(extra*1000*lumin);
        SDmass_800_no_outwcut->SetLineColor(49);
        SDmass_800_no_outwcut->SetLineWidth(2);
        SDmass_800_no_outwcut->Scale(extra*1000*lumin);

	m800_hadw_ncut->SetLineColor(2);
        m800_hadw_ncut->SetLineWidth(2);
        m800_hadw_ncut->Scale(extra*1000*lumin);
        m800_hadt_nwcut->SetLineColor(6);
        m800_hadt_nwcut->SetLineWidth(2);
        m800_hadt_nwcut->Scale(extra*1000*lumin);

        bkg_w_ncut->SetFillColor(29);
        bkg_w_ncut->Scale(1000*lumin);
        bkg_t_nwcut->SetFillColor(8);
        bkg_t_nwcut->Scale(1000*lumin);
        SDmass_bkg_no_outwcut->SetFillColor(40);
        SDmass_bkg_no_outwcut->Scale(1000*lumin);

	bkg_hadw_ncut->SetFillColor(9);
        bkg_hadw_ncut->Scale(1000*lumin);
        bkg_hadt_nwcut->SetFillColor(38);
        bkg_hadt_nwcut->Scale(1000*lumin);
	bkg_b_nwcut->SetFillColor(24);
        bkg_b_nwcut->Scale(1000*lumin);
	bkg_qcd_nwcut->SetFillColor(30);
        bkg_qcd_nwcut->Scale(1000*lumin);

	ncutwall->Add(bkg_hadw_ncut);
	ncutwall->Add(bkg_hadt_nwcut);
	ncutwall->Add(bkg_w_ncut);
	ncutwall->Add(bkg_t_nwcut);
	ncutwall->Add(bkg_b_nwcut);
	ncutwall->Add(SDmass_bkg_no_outwcut);
	ncutwall->Add(bkg_qcd_nwcut);

	cout << "zenmele" << endl;

//3

        m800_t_cut->SetLineColor(42);
        m800_t_cut->SetLineWidth(2);
        m800_t_cut->Scale(extra*1000*lumin);
        m800_w_tcut->SetLineColor(46);
        m800_w_tcut->SetLineWidth(2);
        m800_w_tcut->Scale(extra*1000*lumin);
	m800_b_tcut->SetLineColor(21);
        m800_b_tcut->SetLineWidth(2);
        m800_b_tcut->Scale(extra*1000*lumin);
        SDmass_800_no_tcut->SetLineColor(49);
        SDmass_800_no_tcut->SetLineWidth(2);
        SDmass_800_no_tcut->Scale(extra*1000*lumin);

        m800_hadw_tcut->SetLineColor(2);
        m800_hadw_tcut->SetLineWidth(2);
        m800_hadw_tcut->Scale(extra*1000*lumin);
        m800_hadt_cut->SetLineColor(6);
        m800_hadt_cut->SetLineWidth(2);
        m800_hadt_cut->Scale(extra*1000*lumin);

	bkg_t_cut->SetLineColor(8);
        bkg_t_cut->SetFillColor(8);
        bkg_t_cut->Scale(1000*lumin);
	bkg_w_tcut->SetLineColor(29);
        bkg_w_tcut->SetFillColor(29);
        bkg_w_tcut->Scale(1000*lumin);
	SDmass_bkg_no_tcut->SetLineColor(40);
        SDmass_bkg_no_tcut->SetFillColor(40);
        SDmass_bkg_no_tcut->Scale(1000*lumin);

	bkg_hadw_tcut->SetLineColor(9);
	bkg_hadw_tcut->SetFillColor(9);
        bkg_hadw_tcut->Scale(1000*lumin);
	bkg_hadt_cut->SetLineColor(38);
        bkg_hadt_cut->SetFillColor(38);
        bkg_hadt_cut->Scale(1000*lumin);
	bkg_b_tcut->SetLineColor(kOrange-2);
	bkg_b_tcut->SetFillColor(kOrange-2);
        bkg_b_tcut->Scale(1000*lumin);
	bkg_qcd_tcut->SetLineColor(30);
	bkg_qcd_tcut->SetFillColor(30);
        bkg_qcd_tcut->Scale(1000*lumin);


	cuttall->Add(bkg_hadw_tcut);
	cuttall->Add(bkg_hadt_cut);
//	cuttall->Add(bkg_w_tcut);
//	cuttall->Add(bkg_t_cut);
	cuttall->Add(bkg_b_tcut);
	cuttall->Add(SDmass_bkg_no_tcut);
	cuttall->Add(bkg_qcd_tcut);
//4

        m800_t_ncut->SetLineColor(42);
        m800_t_ncut->SetLineWidth(2);
        m800_t_ncut->Scale(extra*1000*lumin);
        m800_w_ntcut->SetLineColor(46);
        m800_w_ntcut->SetLineWidth(2);
        m800_w_ntcut->Scale(extra*1000*lumin);
	m800_b_ntcut->SetLineColor(21);
        m800_b_ntcut->SetLineWidth(2);
        m800_b_ntcut->Scale(extra*1000*lumin);
        SDmass_800_no_outtcut->SetLineColor(49);
        SDmass_800_no_outtcut->SetLineWidth(2);
        SDmass_800_no_outtcut->Scale(extra*1000*lumin);

        m800_hadw_ntcut->SetLineColor(2);
        m800_hadw_ntcut->SetLineWidth(2);
        m800_hadw_ntcut->Scale(extra*1000*lumin);
        m800_hadt_ncut->SetLineColor(6);
        m800_hadt_ncut->SetLineWidth(2);
        m800_hadt_ncut->Scale(extra*1000*lumin);

        bkg_t_ncut->SetFillColor(8);
        bkg_t_ncut->Scale(1000*lumin);
        bkg_w_ntcut->SetFillColor(29);
        bkg_w_ntcut->Scale(1000*lumin);
        SDmass_bkg_no_outtcut->SetFillColor(40);
        SDmass_bkg_no_outtcut->Scale(1000*lumin);

	bkg_hadw_ntcut->SetFillColor(9);
        bkg_hadw_ntcut->Scale(1000*lumin);
        bkg_hadt_ncut->SetFillColor(38);
        bkg_hadt_ncut->Scale(1000*lumin);
	bkg_b_ntcut->SetFillColor(24);
        bkg_b_ntcut->Scale(1000*lumin);
	bkg_qcd_ntcut->SetFillColor(30);
        bkg_qcd_ntcut->Scale(1000*lumin);

	ncuttall->Add(bkg_hadw_ntcut);
	ncuttall->Add(bkg_hadt_ncut);
	ncuttall->Add(bkg_w_ntcut);
	ncuttall->Add(bkg_t_ncut);
	ncuttall->Add(bkg_b_ntcut);
	ncuttall->Add(SDmass_bkg_no_outtcut);
	ncuttall->Add(bkg_qcd_ntcut);


	cout  << "aoch" << endl;

        TCanvas *c4 = new TCanvas("c4","c4",800,600);
	c4->SetLogy();
        c4->Divide(2,2);
        c4->cd(1);
//	c4->SetLogy();
        cutwall->Draw("hist");
//	cutwall->GetYaxis()->SetRangeUser(1.0,1600000);
	cutwall->GetXaxis()->SetTitle("SDMass[GeV]");
	cutwall->GetYaxis()->SetTitle("Events");
//        m800_w_cut->Draw("same");
//        m800_t_wcut->Draw("same");
	m800_b_wcut->Draw("hist same");
	SDmass_800_no_wcut->Draw("hist same");
        m800_hadw_cut->Draw("hist same");
        m800_hadt_wcut->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");




        TLegend *legend11a = new TLegend(0.42,0.72,0.67,0.94);
//        legend11->AddEntry(m800_w_cut,"800GeV,leptonic W","l");
//        legend11->AddEntry(m800_t_wcut,"800GeV,leptonic top","l");
	legend11a->AddEntry(m800_b_wcut,"1000GeV,b","l");
	legend11a->AddEntry(m800_hadw_cut,"1000GeV,hadronic W","l");
	legend11a->AddEntry(m800_hadt_wcut,"1000GeV,hadronic top","l");
        legend11a->AddEntry(SDmass_800_no_wcut,"1000GeV,no","l");
//        legend11a->AddEntry(bkg_w_cut,"TTbar,leptonic W","f");
//	legend11a->AddEntry(bkg_t_wcut,"TTbar,leptonic top","f");
        legend11a->Draw("same");

	TLegend *legend11b = new TLegend(0.67,0.72,0.92,0.94);
	legend11b->AddEntry(bkg_hadw_cut,"TTbar,hadronic W","f");
        legend11b->AddEntry(bkg_hadt_wcut,"TTbar,hadronic top","f");
        legend11b->AddEntry(bkg_b_wcut,"TTbar,b","f");
        legend11b->AddEntry(SDmass_bkg_no_wcut,"TTbar,no","f");
        legend11b->AddEntry(bkg_qcd_wcut,"QCD","f");
        legend11b->Draw("same");


        c4->cd(2);
        ncutwall->Draw("hist");
	ncutwall->GetXaxis()->SetTitle("SDMass[GeV]");
	ncutwall->GetYaxis()->SetTitle("Events");
//        m800_w_ncut->Draw("same");
//        m800_t_nwcut->Draw("same");
	m800_b_nwcut->Draw("hist same");
	SDmass_800_no_outwcut->Draw("hist same");
	m800_hadw_ncut->Draw("hist same");
        m800_hadt_nwcut->Draw("hist same");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "cms");

        TLegend *legend12 = new TLegend(0.67,0.72,0.92,0.94);
//        legend12->AddEntry(m800_w_ncut,"1000GeV,leptonic W","l");
//        legend12->AddEntry(m800_t_nwcut,"1000GeV,leptonic top","l");
	legend12->AddEntry(m800_b_nwcut,"1000GeV,b","l");
	legend12->AddEntry(m800_hadw_ncut,"1000GeV,hadronic W","l");
        legend12->AddEntry(m800_hadt_nwcut,"1000GeV,hadronic top","l");
	legend12->AddEntry(SDmass_800_no_outwcut,"1000GeV,no","l");
//        legend12->AddEntry(bkg_w_ncut,"TTbar,leptonic W","f");
//        legend12->AddEntry(bkg_t_nwcut,"TTbar,leptonic top","f");
	legend12->AddEntry(bkg_hadw_ncut,"TTbar,hadronic W","f");
        legend12->AddEntry(bkg_hadt_nwcut,"TTbar,hadronic top","f");
	legend12->AddEntry(bkg_b_nwcut,"TTbar,b","f");
	legend12->AddEntry(SDmass_bkg_no_outwcut,"TTbar,no","f");
	legend12->AddEntry(bkg_qcd_nwcut,"QCD");
        legend12->Draw("same");

        c4->cd(3);
        cuttall->Draw("hist");
	cuttall->GetXaxis()->SetTitle("SDMass[GeV]");
	cuttall->GetYaxis()->SetTitle("Events");
//        m800_t_cut->Draw("same");
//        m800_w_tcut->Draw("same");
	m800_b_tcut->Draw("hist same");
	SDmass_800_no_tcut->Draw("hist same");
	m800_hadw_tcut->Draw("hist same");
        m800_hadt_cut->Draw("hist same");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");



        TLegend *legend22a = new TLegend(0.42,0.72,0.67,0.94);
//        legend22->AddEntry(m800_t_cut,"800GeV,leptonic top","l");
//        legend22->AddEntry(m800_w_tcut,"800GeV,leptonic W","l");
	legend22a->AddEntry(m800_b_tcut,"1000GeV,b","l");
	legend22a->AddEntry(m800_hadw_tcut,"1000GeV,hadronic W","l");
        legend22a->AddEntry(m800_hadt_cut,"1000GeV,hadronic top","l");
	legend22a->AddEntry(SDmass_800_no_tcut,"1000GeV,no","l");
//        legend22->AddEntry(bkg_t_cut,"TTbar,leptonic top","f");
//        legend22->AddEntry(bkg_w_tcut,"TTbar,leptonic W","f");
        legend22a->Draw("same");

	TLegend *legend22b = new TLegend(0.67,0.72,0.92,0.94);
	legend22b->AddEntry(bkg_hadw_tcut,"TTbar,hadronic W","f");
        legend22b->AddEntry(bkg_hadt_cut,"TTbar,hadronic top","f");
        legend22b->AddEntry(bkg_b_tcut,"TTbar,b","f");
        legend22b->AddEntry(SDmass_bkg_no_tcut,"TTbar,no","f");
        legend22b->AddEntry(bkg_qcd_tcut,"QCD","f");
        legend22b->Draw("same");


        c4->cd(4);
        ncuttall->SetMinimum(0);
        ncuttall->SetMaximum(2200000);
        ncuttall->Draw("hist");
	ncuttall->GetXaxis()->SetTitle("SDMass[GeV]");
	ncuttall->GetYaxis()->SetTitle("Events");
//        m800_t_ncut->Draw("same");
//        m800_w_ntcut->Draw("same");
	m800_b_ntcut->Draw("hist same");
	SDmass_800_no_outtcut->Draw("hist same");
	m800_hadw_ntcut->Draw("hist same");
        m800_hadt_ncut->Draw("hist same");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "cms");



        TLegend *legend33 = new TLegend(0.67,0.72,0.92,0.94);
//        legend33->AddEntry(m800_t_ncut,"1000GeV,leptonic top","l");
//        legend33->AddEntry(m800_w_ntcut,"1000GeV,leptonic W","l");
	legend33->AddEntry(m800_b_ntcut,"1000GeV,b","l");
	legend33->AddEntry(m800_hadw_ntcut,"1000GeV,hadronic W","l");
        legend33->AddEntry(m800_hadt_ncut,"1000GeV,hadronic top","l");
	legend33->AddEntry(SDmass_800_no_outtcut,"800GeV,no","l");
//        legend33->AddEntry(bkg_t_ncut,"TTbar,leptonic top","f");
//        legend33->AddEntry(bkg_w_ntcut,"TTbar,leptonic W","f");
	legend33->AddEntry(bkg_hadw_ntcut,"TTbar,hadronic W","f");
        legend33->AddEntry(bkg_hadt_ncut,"TTbar,hadronic top","f");
	legend33->AddEntry(bkg_b_ntcut,"TTbar,b","f");
	legend33->AddEntry(SDmass_bkg_no_outtcut,"TTbar,no","f");
	legend33->AddEntry(bkg_qcd_ntcut,"QCD","f");
        legend33->Draw("same");

//        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/w_top_identification.png");







}
