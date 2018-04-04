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



void plot_may(){


	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/st_0b_24may.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/qcd_0b_24may.root");
	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");

	TDirectoryFile* ff = (TDirectoryFile*)f3->Get("ChargedHiggsTopBottom/OneBOneFat");
/*
	TH1D* m800_w_cut = (TH1D*)f1->Get("SDmass_800_lepw_wcut");
	TH1D* m800_w_ncut = (TH1D*)f1->Get("SDmass_800_lepw_outwcut");
	TH1D* m800_w_tcut = (TH1D*)f1->Get("SDmass_800_lepw_tcut");
	TH1D* m800_w_ntcut = (TH1D*)f1->Get("SDmass_800_lepw_outtcut");

        TH1D* m800_hadw_cut = (TH1D*)f1->Get("SDmass_800_hadw_wcut");
        TH1D* m800_hadw_ncut = (TH1D*)f1->Get("SDmass_800_hadw_outwcut");
        TH1D* m800_hadw_tcut = (TH1D*)f1->Get("SDmass_800_hadw_tcut");
        TH1D* m800_hadw_ntcut = (TH1D*)f1->Get("SDmass_800_hadw_outtcut");
	
	TH1D* m800_b_wcut = (TH1D*)f1->Get("SDmass_800_b_wcut");
        TH1D* m800_b_nwcut = (TH1D*)f1->Get("SDmass_800_b_outwcut");
        TH1D* m800_b_tcut = (TH1D*)f1->Get("SDmass_800_b_tcut");
        TH1D* m800_b_ntcut = (TH1D*)f1->Get("SDmass_800_b_outtcut");
*/

	TH1D* m800_w_cut = (TH1D*)ff->Get("SDMass_lepw_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_ncut = (TH1D*)ff->Get("SDMass_lepw_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_tcut = (TH1D*)ff->Get("SDMass_lepw_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_w_ntcut = (TH1D*)ff->Get("SDMass_lepw_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

        TH1D* m800_hadw_cut = (TH1D*)ff->Get("SDMass_hadw_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_ncut = (TH1D*)ff->Get("SDMass_hadw_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_tcut = (TH1D*)ff->Get("SDMass_hadw_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadw_ntcut = (TH1D*)ff->Get("SDMass_hadw_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        
        TH1D* m800_b_wcut = (TH1D*)ff->Get("SDMass_b_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_nwcut = (TH1D*)ff->Get("SDMass_b_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_tcut = (TH1D*)ff->Get("SDMass_b_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_b_ntcut = (TH1D*)ff->Get("SDMass_b_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

	TH1D* bkg_w_cut = (TH1D*)f1->Get("SDmass_bkg_lepw_wcut");
        TH1D* bkg_w_ncut = (TH1D*)f1->Get("SDmass_bkg_lepw_outwcut");
	TH1D* bkg_w_tcut = (TH1D*)f1->Get("SDmass_bkg_lepw_tcut");
	TH1D* bkg_w_ntcut = (TH1D*)f1->Get("SDmass_bkg_lepw_outtcut");

	TH1D* bkg_hadw_cut = (TH1D*)f1->Get("SDmass_bkg_hadw_wcut");
        TH1D* bkg_hadw_ncut = (TH1D*)f1->Get("SDmass_bkg_hadw_outwcut");
        TH1D* bkg_hadw_tcut = (TH1D*)f1->Get("SDmass_bkg_hadw_tcut");
        TH1D* bkg_hadw_ntcut = (TH1D*)f1->Get("SDmass_bkg_hadw_outtcut");

	TH1D* bkg_b_wcut = (TH1D*)f1->Get("SDmass_bkg_b_wcut");
        TH1D* bkg_b_nwcut = (TH1D*)f1->Get("SDmass_bkg_b_outwcut");
        TH1D* bkg_b_tcut = (TH1D*)f1->Get("SDmass_bkg_b_tcut");
        TH1D* bkg_b_ntcut = (TH1D*)f1->Get("SDmass_bkg_b_outtcut");

	TH1D* bkg_qcd_wcut = (TH1D*)f2->Get("SDmass_qcd_wcut");
        TH1D* bkg_qcd_nwcut = (TH1D*)f2->Get("SDmass_qcd_outwcut");
        TH1D* bkg_qcd_tcut = (TH1D*)f2->Get("SDmass_qcd_tcut");
        TH1D* bkg_qcd_ntcut = (TH1D*)f2->Get("SDmass_qcd_outtcut");

/*
	TH1D* m800_t_cut = (TH1D*)f1->Get("SDmass_800_lept_tcut");
        TH1D* m800_t_ncut = (TH1D*)f1->Get("SDmass_800_lept_outtcut");
	TH1D* m800_t_wcut = (TH1D*)f1->Get("SDmass_800_lept_wcut");
        TH1D* m800_t_nwcut = (TH1D*)f1->Get("SDmass_800_lept_outwcut");

	TH1D* m800_hadt_cut = (TH1D*)f1->Get("SDmass_800_hadt_tcut");
        TH1D* m800_hadt_ncut = (TH1D*)f1->Get("SDmass_800_hadt_outtcut");
        TH1D* m800_hadt_wcut = (TH1D*)f1->Get("SDmass_800_hadt_wcut");
        TH1D* m800_hadt_nwcut = (TH1D*)f1->Get("SDmass_800_hadt_outwcut");
*/

	TH1D* m800_t_cut = (TH1D*)ff->Get("SDMass_lept_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_ncut = (TH1D*)ff->Get("SDMass_lept_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_wcut = (TH1D*)ff->Get("SDMass_lept_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_t_nwcut = (TH1D*)ff->Get("SDMass_lept_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

        TH1D* m800_hadt_cut = (TH1D*)ff->Get("SDMass_hadt_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_ncut = (TH1D*)ff->Get("SDMass_hadt_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_wcut = (TH1D*)ff->Get("SDMass_hadt_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        TH1D* m800_hadt_nwcut = (TH1D*)ff->Get("SDMass_hadt_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");

        TH1D* bkg_t_cut = (TH1D*)f1->Get("SDmass_bkg_lept_tcut");
        TH1D* bkg_t_ncut = (TH1D*)f1->Get("SDmass_bkg_lept_outtcut");
	TH1D* bkg_t_wcut = (TH1D*)f1->Get("SDmass_bkg_lept_wcut");
        TH1D* bkg_t_nwcut = (TH1D*)f1->Get("SDmass_bkg_lept_outwcut");

	TH1D* bkg_hadt_cut = (TH1D*)f1->Get("SDmass_bkg_hadt_tcut");
        TH1D* bkg_hadt_ncut = (TH1D*)f1->Get("SDmass_bkg_hadt_outtcut");
        TH1D* bkg_hadt_wcut = (TH1D*)f1->Get("SDmass_bkg_hadt_wcut");
        TH1D* bkg_hadt_nwcut = (TH1D*)f1->Get("SDmass_bkg_hadt_outwcut");

	TH1D* SDmass_800_no_tcut = (TH1D*)ff->Get("SDMass_no_tcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	TH1D* SDmass_800_no_outtcut = (TH1D*)ff->Get("SDMass_no_outtcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	TH1D* SDmass_800_no_wcut = (TH1D*)ff->Get("SDMass_no_wcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	TH1D* SDmass_800_no_outwcut = (TH1D*)ff->Get("SDMass_no_outwcut_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");


//	TH1D* SDmass_800_no_tcut = (TH1D*)f1->Get("SDmass_800_no_tcut");
//	TH1D* SDmass_800_no_outtcut = (TH1D*)f1->Get("SDmass_800_no_outtcut");
        TH1D* SDmass_bkg_no_tcut = (TH1D*)f1->Get("SDmass_bkg_no_tcut");
        TH1D* SDmass_bkg_no_outtcut = (TH1D*)f1->Get("SDmass_bkg_no_outtcut");
//        TH1D* SDmass_800_no_wcut = (TH1D*)f1->Get("SDmass_800_no_wcut");
//        TH1D* SDmass_800_no_outwcut = (TH1D*)f1->Get("SDmass_800_no_outwcut");
        TH1D* SDmass_bkg_no_wcut = (TH1D*)f1->Get("SDmass_bkg_no_wcut");
        TH1D* SDmass_bkg_no_outwcut = (TH1D*)f1->Get("SDmass_bkg_no_outwcut");

//	TH1D* topWdist_800 = (TH1D*)f1->Get("topWdist_800");
//	TH1D* topWdist_ttbar = (TH1D*)f1->Get("topWdist_ttbar");
//	TH1D* topWdist_qcd = (TH1D*)f1->Get("topWdist_qcd");


	TH1D* nbjets_800 = (TH1D*)f1->Get("nbjets_800");
	TH1D* nbjets_ttbar = (TH1D*)f1->Get("nbjets_ttbar");
	TH1D* nbjets_qcd = (TH1D*)f2->Get("nbjets_qcd");

//	TH1D* njets_800 = (TH1D*)f1->Get("njets_800");
//        TH1D* njets_ttbar = (TH1D*)f1->Get("njets_ttbar");
//        TH1D* njets_qcd = (TH1D*)f1->Get("njets_qcd");

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


	TH2D *wtbchart_800 = (TH2D*)f1->Get("wtbchart_800");
	TH2D *wtbchart_ttbar = (TH2D*)f1->Get("wtbchart_ttbar");
	TH2D *wtbchart_qcd = (TH2D*)f2->Get("wtbchart_qcd");
/*
	TH1D *tau21_1000_w = (TH1D*)f1->Get("tau21_1000_w");
	TH1D *tau21_1000_notw = (TH1D*)f1->Get("tau21_1000_notw");
	TH1D *tau21_ttbar_w = (TH1D*)f1->Get("tau21_ttbar_w");
	TH1D *tau21_ttbar_notw = (TH1D*)f1->Get("tau21_ttbar_notw");
	TH1D *tau21_qcd = (TH1D*)f2->Get("tau21_qcd");

	TH1D *tau32_1000_top = (TH1D*)f1->Get("tau32_1000_top");
	TH1D *tau32_1000_nottop = (TH1D*)f1->Get("tau32_1000_nottop");
        TH1D *tau32_ttbar_top = (TH1D*)f1->Get("tau32_ttbar_top");
	TH1D *tau32_ttbar_nottop = (TH1D*)f1->Get("tau32_ttbar_nottop");
        TH1D *tau32_qcd = (TH1D*)f2->Get("tau32_qcd");

	tau21_1000_w->Scale(1.0/tau21_1000_w->Integral());
	tau21_1000_notw->Scale(1.0/tau21_1000_notw->Integral());
	tau21_ttbar_w->Scale(1.0/tau21_ttbar_w->Integral());
	tau21_ttbar_notw->Scale(1.0/tau21_ttbar_notw->Integral());
	tau21_qcd->Scale(1.0/tau21_qcd->Integral());

	tau32_1000_top->Scale(1.0/tau32_1000_top->Integral());
	tau32_1000_nottop->Scale(1.0/tau32_1000_nottop->Integral());
	tau32_ttbar_top->Scale(1.0/tau32_ttbar_top->Integral());
	tau32_ttbar_nottop->Scale(1.0/tau32_ttbar_nottop->Integral());
	tau32_qcd->Scale(1.0/tau32_qcd->Integral());

*/


	THStack *numofb = new THStack("numofb","#b distribution");
//	THStack *numofj = new THStack("numofj","#jets distribution");


//	THStack *sigrange = new THStack("sigrange","#top#Wdistribution");

	THStack *cutwall = new THStack("cutwall","tau21<0.6");
        THStack *ncutwall = new THStack("ncutwall","tau21>0.6");
        THStack *cuttall = new THStack("cuttall","tau32<0.81");
        THStack *ncuttall = new THStack("ncuttall","tau32>0.81");

	THStack *invariant800a = new THStack("invariant800_a","invariant800_a");
	THStack *invariant800b = new THStack("invariant800_b","invariant800_b");
	THStack *invariant3000 = new THStack("invariant3000","invariant3000");
	
	
	setTDRStyle();

/*	tau21_1000_w->SetLineColor(46);
	tau21_1000_w->SetLineWidth(2);
	tau21_1000_notw->SetLineColor(49);
        tau21_1000_notw->SetLineWidth(2);
	tau21_ttbar_w->SetLineColor(38);
	tau21_ttbar_w->SetLineWidth(2);
	tau21_ttbar_notw->SetLineColor(40);
        tau21_ttbar_notw->SetLineWidth(2);
	tau21_qcd->SetLineColor(30);
	tau21_qcd->SetLineWidth(2);


	tau32_1000_top->SetLineColor(46);
        tau32_1000_top->SetLineWidth(2);
	tau32_1000_nottop->SetLineColor(49);
        tau32_1000_nottop->SetLineWidth(2);
        tau32_ttbar_top->SetLineColor(38);
        tau32_ttbar_top->SetLineWidth(2);
	tau32_ttbar_nottop->SetLineColor(40);
        tau32_ttbar_nottop->SetLineWidth(2);
        tau32_qcd->SetLineColor(30);
        tau32_qcd->SetLineWidth(2);
*/


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

/*	mass_thbh_800->SetFillColor(46);
	mass_thbh_800->Scale(1000*lumin);
	mass_thbh_3000->SetFillColor(46);
	mass_thbh_3000->Scale(1000*lumin);

	mass_thb_800->SetFillColor(49);
	mass_thb_800->Scale(1000*lumin);
	mass_thb_3000->SetFillColor(49);
	mass_thb_3000->Scale(1000*lumin);

	mass_tbh_800->SetFillColor(42);
        mass_tbh_800->Scale(1000*lumin);
        mass_tbh_3000->SetFillColor(42);
        mass_tbh_3000->Scale(1000*lumin);

	mass_tb_800->SetFillColor(21);
        mass_tb_800->Scale(1000*lumin);
        mass_tb_3000->SetFillColor(21);
        mass_tb_3000->Scale(1000*lumin);

	invariant_3_nt_nw_800->SetFillColor(kRed-10);
	invariant_3_nt_nw_800->Scale(1000*lumin);
	invariant_3_nt_nw_3000->SetFillColor(kRed-10);
	invariant_3_nt_nw_3000->Scale(1000*lumin);

	invariant_3_nt_w_800->SetFillColor(kRed-9);
	invariant_3_nt_w_800->Scale(1000*lumin);
	invariant_3_nt_w_3000->SetFillColor(kRed-9);
	invariant_3_nt_w_3000->Scale(1000*lumin);

	invariant_3_t_800->SetFillColor(kRed-7);
	invariant_3_t_800->Scale(1000*lumin);
	invariant_3_t_3000->SetFillColor(kRed-7);
	invariant_3_t_3000->Scale(1000*lumin);

	invariant_3_ttbar->SetFillColor(kBlue-9);
	invariant_3_ttbar->Scale(1000*lumin);

	invariant_3_qcd->SetFillColor(kGreen-3);
	invariant_3_qcd->Scale(1000*lumin);

	mass_tb_ttbar800->SetFillColor(38);
	mass_tb_ttbar800->Scale(1000*lumin);
	mass_tb_ttbar3000->SetFillColor(38);
        mass_tb_ttbar3000->Scale(1000*lumin);

	mass_tb_qcd800->SetFillColor(30);
        mass_tb_qcd800->Scale(1000*lumin);
        mass_tb_qcd3000->SetFillColor(30);
        mass_tb_qcd3000->Scale(1000*lumin);

	invariant800a->Add(mass_tb_qcd800);
	invariant800b->Add(invariant_3_qcd);
	invariant800a->Add(mass_tb_ttbar800);
	invariant800b->Add(invariant_3_ttbar);

	invariant800b->Add(invariant_3_nt_nw_800);
	invariant800b->Add(invariant_3_nt_w_800);
	invariant800a->Add(mass_tb_800);
	invariant800a->Add(mass_thb_800);
	invariant800a->Add(mass_tbh_800);
	invariant800b->Add(invariant_3_t_800);
	invariant800a->Add(mass_thbh_800);


	invariant800a->Add(mass_thbh_800);
	invariant800a->Add(mass_tbh_800);
	invariant800a->Add(mass_thb_800);
	invariant800a->Add(mass_tb_800);
	
	invariant800a->Add(mass_tb_ttbar800);
	invariant800a->Add(mass_tb_qcd800);

	invariant800b->Add(invariant_3_t_800);
	invariant800b->Add(invariant_3_nt_w_800);
	invariant800b->Add(invariant_3_nt_nw_800);

	invariant800b->Add(invariant_3_ttbar);
	invariant800b->Add(invariant_3_qcd);


	invariant3000->Add(mass_tb_qcd3000);
	invariant3000->Add(mass_tb_ttbar3000);

	invariant3000->Add(invariant_3_nt_nw_3000);
        invariant3000->Add(invariant_3_nt_w_3000);
	invariant3000->Add(mass_tb_3000);
	invariant3000->Add(mass_thb_3000);
	invariant3000->Add(mass_tbh_3000);
	invariant3000->Add(invariant_3_t_3000);
	invariant3000->Add(mass_thbh_3000);
	

	topWdist_800->SetFillColor(46);
	topWdist_800->Scale(1000*lumin);
        topWdist_ttbar->SetFillColor(38);
	topWdist_ttbar->Scale(20*lumin);
	topWdist_qcd->SetFillColor(30);
        topWdist_qcd->Scale(1*lumin);
	sigrange->Add(topWdist_800);
	sigrange->Add(topWdist_ttbar);
	sigrange->Add(topWdist_qcd);
*/	

	nbjets_800->SetLineColor(46);
	nbjets_800->SetLineWidth(2);
	nbjets_800->Scale(100*1000*lumin);
	nbjets_ttbar->SetFillColor(kBlue-10);
	nbjets_ttbar->SetLineColor(kBlue-10);
	nbjets_ttbar->Scale(1000*lumin);
	nbjets_qcd->SetFillColor(kGreen-10);
	nbjets_qcd->SetLineColor(kGreen-10);
	nbjets_qcd->Scale(1000*lumin);
//	numofb->Add(nbjets_800);
	numofb->Add(nbjets_ttbar);
	numofb->Add(nbjets_qcd);

/*
	njets_800->SetFillColor(46);
        njets_800->Scale(1000*lumin);
        njets_ttbar->SetFillColor(38);
        njets_ttbar->Scale(16*lumin);
        njets_qcd->SetFillColor(30);
        njets_qcd->Scale(0.4*lumin);
        numofj->Add(njets_qcd);
        numofj->Add(njets_ttbar);
        numofj->Add(njets_800);
//	numofj->GetXaxis()->SetTitle("# of jets");
*/


//	gStyle->SetOptStat(1000);

//	gStyle->SetPalette(kOcean);



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
     //   ncuttall->SetMinimum(0);
      //  ncuttall->SetMaximum(2200);
        ncuttall->Draw("hist");
	ncuttall->GetXaxis()->SetTitle("SDMass[GeV]");
	ncuttall->GetYaxis()->SetTitle("Events");
      //  ncutt->GetXaxis()->SetRangeUser(105.,210.0);
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

/*
	TCanvas *c = new TCanvas("c","c",800,600);
	c->cd(1);
	sigrange->Draw("hist");

	TLegend *legend = new TLegend(0.72,0.84,0.92,0.98);
        legend->AddEntry(topWdist_800,"800GeV","f");
        legend->AddEntry(topWdist_ttbar,"ttbar","f");
	legend->AddEntry(topWdist_qcd,"QCD","f");
        legend->Draw("same");

	c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/subb_wtnum.png");


        TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
        invariant800a->Draw("hist");
        invariant800a->GetXaxis()->SetRangeUser(400.,1200.0);

        TLegend *legend4a = new TLegend(0.64,0.72,0.92,0.98);
        legend4a->AddEntry(mass_thbh_800,"800GeV,top+b","f");
        legend4a->AddEntry(mass_thb_800,"800GeV,top+otherb","f");
	legend4a->AddEntry(mass_tbh_800,"800GeV,othertop+b","f");
	legend4a->AddEntry(mass_tb_800,"800GeV,othertop+otherb","f");
        legend4a->AddEntry(mass_tb_ttbar800,"TTbar,top+b","f");
	legend4a->AddEntry(mass_tb_qcd800,"QCD,top+b","f");
        legend4a->Draw("same");

//        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/fixgen_mass800a_newall.png");

        TCanvas *c1b = new TCanvas("c1b","c1b",800,600);
        c1b->cd(1);
        invariant800b->Draw("hist");
        invariant800b->GetXaxis()->SetRangeUser(400.,1200.0);

        TLegend *legend4b = new TLegend(0.64,0.72,0.92,0.98);
        legend4b->AddEntry(invariant_3_t_800,"800GeV,top(w+b)+b","f");
        legend4b->AddEntry(invariant_3_nt_w_800,"800GeV,othertop(w+b)+b","f");
        legend4b->AddEntry(invariant_3_nt_nw_800,"800GeV,otherw+b+b","f");
        legend4b->AddEntry(invariant_3_ttbar,"TTbar,w+b+b","f");
        legend4b->AddEntry(invariant_3_qcd,"QCD,w+b+b","f");
        legend4b->Draw("same");

//        c1b->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/fixgen_mass800b_newall.png");




        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
        invariant3000->Draw("hist");

        TLegend *legend5 = new TLegend(0.72,0.84,0.92,0.98);
        legend5->AddEntry(mass_thbh_3000,"3000GeV,bfromhiggs+topfromhiggs","f");
        legend5->AddEntry(mass_thb_3000,"3000GeV,otherb+topfromhiggs","f");
        legend5->AddEntry(mass_tbh_3000,"3000GeV,bfromhiggs+othertop","f");
        legend5->AddEntry(mass_tb_3000,"3000GeV,otherb+othertop","f");
        legend5->AddEntry(mass_tb_ttbar3000,"TTbar","f");
        legend5->AddEntry(mass_tb_qcd3000,"QCD","f");
	legend5->Draw("same");

//        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/fixgen_mass3000_newall.png");
*/
	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
	c3->SetLogy();
        numofb->Draw("hist");
	numofb->GetXaxis()->SetTitle("number of bjets (|#eta|<2.4)");
	numofb->GetXaxis()->SetBinLabel(1,"0b");
	numofb->GetXaxis()->SetBinLabel(2,"1b");
	numofb->GetXaxis()->SetBinLabel(3,"2b");
        numofb->GetXaxis()->SetBinLabel(4,"#geq 3b");
	numofb->GetYaxis()->SetTitle("Events");
	nbjets_800->Draw("hist same");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legendx = new TLegend(0.63,0.74,0.85,0.88);
        legendx->AddEntry(nbjets_800,"1000GeV","l");
        legendx->AddEntry(nbjets_ttbar,"TTbar","f");
        legendx->AddEntry(nbjets_qcd,"QCD","f");
        legendx->Draw("same");

//        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/numofb.png");


	TCanvas *c99 = new TCanvas("c99","c99",800,600);
	c99->cd(1);
	wtbchart_800->Draw("colz");
	wtbchart_800->GetXaxis()->SetTitle("number of bjets (|#eta|<2.4)");
	wtbchart_800->GetXaxis()->SetBinLabel(1,"0b");
        wtbchart_800->GetXaxis()->SetBinLabel(2,"1b");
        wtbchart_800->GetXaxis()->SetBinLabel(3,"2b");
        wtbchart_800->GetXaxis()->SetBinLabel(4,"#geq 3b");
//	wtbchart_800->GetYaxis()->SetTitle("number of W and top");
	wtbchart_800->GetYaxis()->SetBinLabel(1,"#geq 1W, #geq 1top");
	wtbchart_800->GetYaxis()->SetBinLabel(2,"#geq 1W, 0 top");
	wtbchart_800->GetYaxis()->SetBinLabel(3,"0 W, #geq 1top");
	wtbchart_800->GetYaxis()->SetBinLabel(4,"0 W, 0 top");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");



//	c99->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/W_top_b_1000.png");




        TCanvas *c98 = new TCanvas("c98","c98",800,600);
        c98->cd(1);
        wtbchart_ttbar->Draw("colz");
        wtbchart_ttbar->GetXaxis()->SetTitle("number of bjets (|#eta|<2.4)");
        wtbchart_ttbar->GetXaxis()->SetBinLabel(1,"0b");
        wtbchart_ttbar->GetXaxis()->SetBinLabel(2,"1b");
        wtbchart_ttbar->GetXaxis()->SetBinLabel(3,"2b");
        wtbchart_ttbar->GetXaxis()->SetBinLabel(4,"#geq 3b");
//        wtbchart_ttbar->GetYaxis()->SetTitle("number of W and top");
        wtbchart_ttbar->GetYaxis()->SetBinLabel(1,"#geq 1W, #geq 1top");
        wtbchart_ttbar->GetYaxis()->SetBinLabel(2,"#geq 1W, 0 top");
        wtbchart_ttbar->GetYaxis()->SetBinLabel(3,"0 W, #geq 1top");
        wtbchart_ttbar->GetYaxis()->SetBinLabel(4,"0 W, 0 top");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");


  //      c98->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/W_top_b_ttbar.png");


	TCanvas *c97 = new TCanvas("c97","c97",800,600);
        c97->cd(1);
        wtbchart_qcd->Draw("colz");
        wtbchart_qcd ->GetXaxis()->SetTitle("number of bjets (|#eta|<2.4)");
        wtbchart_qcd->GetXaxis()->SetBinLabel(1,"0b");
        wtbchart_qcd->GetXaxis()->SetBinLabel(2,"1b");
        wtbchart_qcd->GetXaxis()->SetBinLabel(3,"2b");
        wtbchart_qcd->GetXaxis()->SetBinLabel(4,"#geq 3b");
//        wtbchart_qcd->GetYaxis()->SetTitle("number of W and top");
        wtbchart_qcd->GetYaxis()->SetBinLabel(1,"#geq 1W, #geq 1top");
        wtbchart_qcd->GetYaxis()->SetBinLabel(2,"#geq 1W, 0 top");
        wtbchart_qcd->GetYaxis()->SetBinLabel(3,"0 W, #geq 1top");
        wtbchart_qcd->GetYaxis()->SetBinLabel(4,"0 W, 0 top");

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");


    //    c97->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/W_top_b_qcd.png");
/*

	TCanvas *c96 = new TCanvas("c96","c96",800,600);
        c96->cd(1);
	tau21_qcd->Draw("hist");
	tau21_qcd->GetXaxis()->SetTitle("#tau21(#tau2/#tau1)");
	tau21_qcd->GetYaxis()->SetTitle("Nomalized entries");
	tau21_ttbar_notw->Draw("hist same");
	tau21_ttbar_w->Draw("hist same");
	tau21_1000_notw->Draw("hist same");
	tau21_1000_w->Draw("hist same");
	
	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");

	TLegend *legend96 = new TLegend(0.63,0.74,0.85,0.88);
        legend96->AddEntry(tau21_1000_w,"1000GeV,W","l");
	legend96->AddEntry(tau21_1000_notw,"1000GeV,not W","l");
        legend96->AddEntry(tau21_ttbar_w,"TTbar,W","l");
	legend96->AddEntry(tau21_ttbar_notw,"TTbar,not W","l");
	legend96->AddEntry(tau21_qcd,"QCD","l");
        legend96->Draw("same");

        c96->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/tau21.png");	

	TCanvas *c95 = new TCanvas("c95","c95",800,600);
        c95->cd(1);
        tau32_qcd->Draw("hist");
        tau32_qcd->GetXaxis()->SetTitle("#tau32(#tau3/#tau2)");
        tau32_qcd->GetYaxis()->SetTitle("Nomalized entries");
        tau32_ttbar_nottop->Draw("hist same");
	tau32_ttbar_top->Draw("hist same");
        tau32_1000_nottop->Draw("hist same");
	tau32_1000_top->Draw("hist same");	

	latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");


        TLegend *legend95 = new TLegend(0.63,0.74,0.85,0.88);
        legend95->AddEntry(tau32_1000_top,"1000GeV,top","l");
	legend95->AddEntry(tau32_1000_nottop,"1000GeV,not top","l");
        legend95->AddEntry(tau32_ttbar_top,"TTbar,top","l");
	legend95->AddEntry(tau32_ttbar_nottop,"TTbar,not top","l");
        legend95->AddEntry(tau32_qcd,"QCD","l");
        legend95->Draw("same");

        c95->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/tau32.png");

*/


/*
        TCanvas *cx = new TCanvas("cx","cx",800,600);
        cx->cd(1);
        numofj->Draw("hist");
	numofj->GetXaxis()->SetTitle("# of jets");

        TLegend *legendxx = new TLegend(0.72,0.84,0.92,0.98);
        legendxx->AddEntry(njets_800,"800GeV","f");
        legendxx->AddEntry(njets_ttbar,"TTbar","f");
        legendxx->AddEntry(njets_qcd,"QCD","f");
        legendxx->Draw("same");

  //      cx->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/bothcut_numofj.png");
*/


}
