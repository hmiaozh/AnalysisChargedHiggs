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


const double Mbottom = 5.0; // mass of bottom quark (4.6GeV)
const double Mw = 80.385;
const double Mtop = 173.34;
const double themc = 12;
const double smc = 12;



void lephad_cut(){

//	TFile* f1 = TFile::Open("/eos/user/h/hum/Chhiggs_tb/Apr19_z/Apr19_z.root");
//	TFile* f1 = TFile::Open("/afs/cern.ch/user/h/hum/work/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/LDOJun.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/user/h/hum/work/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ChHiggs_FullHad_test.root");
        TFile* f2 = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/workshop_fixgen_sig.root","recreate");
        TTree* t1 = (TTree*)f1->Get("tree_tb");
        
	Float_t jet_pt[20]  = {0};
	Float_t jet_eta[20] = {0};
        Float_t jet_phi[20] = {0};
        Float_t jet_e[20]   = {0};
	Float_t jet_discr[20] ={0};

        Float_t bjet_pt[10], bjet_eta[10], bjet_phi[10],bjet_e[10];

        Float_t fatjet_pt[10] ={0};
        Float_t fatjet_eta[10] ={0};
        Float_t fatjet_phi[10] ={0};
        Float_t fatjet_e[10] ={0};
        Float_t fatjet_tau1[10]={0};
        Float_t fatjet_tau2[10]={0};
        Float_t fatjet_tau3[10]={0};
	Float_t fatjet_SDMass[10]={0};
//	Int_t fatjet_bSubJet[10]={0};
//	Int_t fatjet_bSubJetLoose[10]={0};
/*
	Double_t jet_pt[20]  = {0};
        Double_t jet_eta[20] = {0};
        Double_t jet_phi[20] = {0};
        Double_t jet_e[20]   = {0};

	Double_t bjet_pt[10], bjet_eta[10], bjet_phi[10],bjet_e[10];

        Double_t jet_discr[20] ={0};

	Double_t fatjet_pt[20] ={0};
	Double_t fatjet_eta[20] ={0};
	Double_t fatjet_phi[20] ={0};
	Double_t fatjet_e[20] ={0};
	Double_t fatjet_tau1[20]={0};
	Double_t fatjet_tau2[20]={0};
	Double_t fatjet_tau3[20]={0};
//	Double_t fatjet_CorrPrunedMass[20]={0};
	Double_t fatjet_SDMass[20]={0};	
//	Int_t fatjet_bSubJet[20]={0};
*/
	Float_t bFromH_pt, bFromH_phi,bFromH_eta;
	Float_t bFromTopH_pt, bFromTopH_phi, bFromTopH_eta;
	Float_t bFromTopAss_pt, bFromTopAss_phi, bFromTopAss_eta;
	
	Float_t bBKGplus_pt, bBKGplus_phi, bBKGplus_eta;
	Float_t bBKGminus_pt, bBKGminus_phi, bBKGminus_eta;

        Float_t WFromTopH_pt, WFromTopH_phi, WFromTopH_eta;
        Float_t WFromTopAss_pt, WFromTopAss_eta, WFromTopAss_phi;
	Float_t WBKGplus_pt,WBKGplus_eta,WBKGplus_phi;
	Float_t WBKGminus_pt,WBKGminus_eta,WBKGminus_phi;

	Float_t topFromH_pt, topFromH_phi, topFromH_eta;
	Float_t topAss_pt, topAss_phi, topAss_eta;
	Float_t topBKGplus_pt, topBKGplus_phi, topBKGplus_eta;
	Float_t topBKGminus_pt, topBKGminus_phi, topBKGminus_eta;

	Double_t weight;
	Float_t ht;

        Int_t sig, mc;

        Int_t NJets, NBJets,NFatJets;

	Int_t WFromTopH_lep, WFromTopAss_lep, WBKGplus_lep, WBKGminus_lep;
	Int_t topFromH_lep, topAss_lep, topBKGplus_lep, topBKGminus_lep;

        t1->SetBranchAddress("bjet_pt", &bjet_pt);
        t1->SetBranchAddress("bjet_eta",&bjet_eta);
        t1->SetBranchAddress("bjet_phi",&bjet_phi);
        t1->SetBranchAddress("bjet_e",&bjet_e);

        t1->SetBranchAddress("jet_pt", &jet_pt);
        t1->SetBranchAddress("jet_eta",&jet_eta);
        t1->SetBranchAddress("jet_phi",&jet_phi);
        t1->SetBranchAddress("jet_e", &jet_e);
        t1->SetBranchAddress("jet_discr",&jet_discr);

	t1->SetBranchAddress("fatjet_pt", &fatjet_pt);
        t1->SetBranchAddress("fatjet_eta",&fatjet_eta);
	t1->SetBranchAddress("fatjet_phi",&fatjet_phi);
	t1->SetBranchAddress("fatjet_e",&fatjet_e);
	t1->SetBranchAddress("fatjet_tau1",&fatjet_tau1);
	t1->SetBranchAddress("fatjet_tau2",&fatjet_tau2);
	t1->SetBranchAddress("fatjet_tau3",&fatjet_tau3);
//	t1->SetBranchAddress("fatjet_CorrPrunedMass",&fatjet_CorrPrunedMass);
	t1->SetBranchAddress("fatjet_SDMass",&fatjet_SDMass);
//	t1->SetBranchAddress("fatjet_bSubJet",&fatjet_bSubJet);
//	t1->SetBranchAddress("fatjet_bSubJetLoose",&fatjet_bSubJetLoose);

	t1->SetBranchAddress("bFromH_pt", &bFromH_pt);
	t1->SetBranchAddress("bFromH_phi", &bFromH_phi);
	t1->SetBranchAddress("bFromH_eta", &bFromH_eta);

	t1->SetBranchAddress("bFromTopH_pt",&bFromTopH_pt);
	t1->SetBranchAddress("bFromTopH_phi",&bFromTopH_phi);
	t1->SetBranchAddress("bFromTopH_eta",&bFromTopH_eta);

	t1->SetBranchAddress("bFromTopAss_pt",&bFromTopAss_pt);
	t1->SetBranchAddress("bFromTopAss_phi",&bFromTopAss_phi);
	t1->SetBranchAddress("bFromTopAss_eta",&bFromTopAss_eta);

	t1->SetBranchAddress("bBKGplus_pt", &bBKGplus_pt);
	t1->SetBranchAddress("bBKGplus_phi", &bBKGplus_phi);
	t1->SetBranchAddress("bBKGplus_eta", &bBKGplus_eta);

	t1->SetBranchAddress("bBKGminus_pt", &bBKGminus_pt);
	t1->SetBranchAddress("bBKGminus_eta", &bBKGminus_eta);
	t1->SetBranchAddress("bBKGminus_phi", &bBKGminus_phi);

        t1->SetBranchAddress("WFromTopH_pt",&WFromTopH_pt);
        t1->SetBranchAddress("WFromTopH_phi",&WFromTopH_phi);
        t1->SetBranchAddress("WFromTopH_eta",&WFromTopH_eta);
	t1->SetBranchAddress("WFromTopH_lep",&WFromTopH_lep);

        t1->SetBranchAddress("WFromTopAss_pt",&WFromTopAss_pt);
        t1->SetBranchAddress("WFromTopAss_eta",&WFromTopAss_eta);
        t1->SetBranchAddress("WFromTopAss_phi",&WFromTopAss_phi);
	t1->SetBranchAddress("WFromTopAss_lep",&WFromTopAss_lep);

	t1->SetBranchAddress("WBKGplus_pt",&WBKGplus_pt);
	t1->SetBranchAddress("WBKGplus_eta",&WBKGplus_eta);
	t1->SetBranchAddress("WBKGplus_phi",&WBKGplus_phi);
	t1->SetBranchAddress("WBKGplus_lep",&WBKGplus_lep);

	t1->SetBranchAddress("WBKGminus_pt",&WBKGminus_pt);
        t1->SetBranchAddress("WBKGminus_eta",&WBKGminus_eta);
        t1->SetBranchAddress("WBKGminus_phi",&WBKGminus_phi);
	t1->SetBranchAddress("WBKGminus_lep",&WBKGminus_lep);	

	t1->SetBranchAddress("topFromH_pt",&topFromH_pt);
	t1->SetBranchAddress("topFromH_eta",&topFromH_eta);
	t1->SetBranchAddress("topFromH_phi",&topFromH_phi);
	t1->SetBranchAddress("topFromH_lep",&topFromH_lep);

        t1->SetBranchAddress("topAss_pt",&topAss_pt);
        t1->SetBranchAddress("topAss_eta",&topAss_eta);
        t1->SetBranchAddress("topAss_phi",&topAss_phi);
	t1->SetBranchAddress("topAss_lep",&topAss_lep);

        t1->SetBranchAddress("topBKGplus_pt",&topBKGplus_pt);
        t1->SetBranchAddress("topBKGplus_eta",&topBKGplus_eta);
        t1->SetBranchAddress("topBKGplus_phi",&topBKGplus_phi);
	t1->SetBranchAddress("topBKGplus_lep",&topBKGplus_lep);

        t1->SetBranchAddress("topBKGminus_pt",&topBKGminus_pt);
        t1->SetBranchAddress("topBKGminus_eta",&topBKGminus_eta);
        t1->SetBranchAddress("topBKGminus_phi",&topBKGminus_phi);
	t1->SetBranchAddress("topBKGminus_lep",&topBKGminus_lep); 

	t1->SetBranchAddress("weight",&weight);
	t1->SetBranchAddress("ht",&ht);

        t1->SetBranchAddress("sig", &sig);
        t1->SetBranchAddress("mc", &mc);
        t1->SetBranchAddress("NJets", &NJets);
        t1->SetBranchAddress("NBJets", &NBJets);
	t1->SetBranchAddress("NFatJets",&NFatJets);

	TH2D *merge_Wb = new TH2D("merge_Wb","merge_Wb",120,0.,1200.,100,0.,5.);

	TH2D *wtbchart_800 = new TH2D("wtbchart_800","wtbchart_800",4,-0.5,3.5,4,0.5,4.5);
	TH2D *wtbchart_3000 = new TH2D("wtbchart_3000","wtbchart_3000",4,-0.5,3.5,4,0.5,4.5);
	TH2D *wtbchart_ttbar = new TH2D("wtbchart_ttbar","wtbchart_ttbar",4,-0.5,3.5,4,0.5,4.5);
	TH2D *wtbchart_qcd = new TH2D("wtbchart_qcd","wtbchart_qcd",4,-0.5,3.5,4,0.5,4.5);

	TH1D *SDmass_800_lepw_wcut = new TH1D("SDmass_800_lepw_wcut","SDmass_800_lepw_wcut",68,40.,210.);
	TH1D *SDmass_800_lepw_outwcut = new TH1D("SDmass_800_lepw_outwcut","SDmass_800_lepw_outwcut",68,40.,210.);
	TH1D *SDmass_800_lepw_tcut = new TH1D("SDmass_800_lepw_tcut","SDmass_800_lepw_tcut",68,40.,210.);
        TH1D *SDmass_800_lepw_outtcut = new TH1D("SDmass_800_lepw_outtcut","SDmass_800_lepw_outtcut",68,40.,210.);
	
	TH1D *SDmass_800_hadw_wcut = new TH1D("SDmass_800_hadw_wcut","SDmass_800_hadw_wcut",68,40.,210.);
        TH1D *SDmass_800_hadw_outwcut = new TH1D("SDmass_800_hadw_outwcut","SDmass_800_hadw_outwcut",68,40.,210.);
        TH1D *SDmass_800_hadw_tcut = new TH1D("SDmass_800_hadw_tcut","SDmass_800_hadw_tcut",68,40.,210.);
        TH1D *SDmass_800_hadw_outtcut = new TH1D("SDmass_800_hadw_outtcut","SDmass_800_hadw_outtcut",68,40.,210.);

//        TH1D *SDmass_3000_w_cut = new TH1D("SDmass_3000_w_cut","SDmass_3000_w_cut",68,40.,210.);
//        TH1D *SDmass_3000_w_outcut = new TH1D("SDmass_3000_w_outcut","SDmass_3000_w_outcut",68,40.,210.);
//        TH1D *SDmass_3000_nw_cut = new TH1D("SDmass_3000_nw_cut","SDmass_3000_nw_cut",68,40.,210.);
//        TH1D *SDmass_3000_nw_outcut = new TH1D("SDmass_3000_nw_outcut","SDmass_3000_nw_outcut",68,40.,210.);	

        TH1D *SDmass_bkg_lepw_wcut = new TH1D("SDmass_bkg_lepw_wcut","SDmass_bkg_lepw_wcut",68,40.,210.);
        TH1D *SDmass_bkg_lepw_outwcut = new TH1D("SDmass_bkg_lepw_outwcut","SDmass_bkg_lepw_outwcut",68,40.,210.);
	TH1D *SDmass_bkg_lepw_tcut = new TH1D("SDmass_bkg_lepw_tcut","SDmass_bkg_lepw_tcut",68,40.,210.);
        TH1D *SDmass_bkg_lepw_outtcut = new TH1D("SDmass_bkg_lepw_outtcut","SDmass_bkg_lepw_outtcut",68,40.,210.);

	TH1D *SDmass_bkg_hadw_wcut = new TH1D("SDmass_bkg_hadw_wcut","SDmass_bkg_hadw_wcut",68,40.,210.);
        TH1D *SDmass_bkg_hadw_outwcut = new TH1D("SDmass_bkg_hadw_outwcut","SDmass_bkg_hadw_outwcut",68,40.,210.);
        TH1D *SDmass_bkg_hadw_tcut = new TH1D("SDmass_bkg_hadw_tcut","SDmass_bkg_hadw_tcut",68,40.,210.);
        TH1D *SDmass_bkg_hadw_outtcut = new TH1D("SDmass_bkg_hadw_outtcut","SDmass_bkg_hadw_outtcut",68,40.,210.);

        TH1D *SDmass_800_lept_tcut = new TH1D("SDmass_800_lept_tcut","SDmass_800_lept_tcut",68,40.,210.);
        TH1D *SDmass_800_lept_outtcut = new TH1D("SDmass_800_lept_outtcut","SDmass_800_lept_outtcut",68,40.,210.);
	TH1D *SDmass_800_lept_wcut = new TH1D("SDmass_800_lept_wcut","SDmass_800_lept_wcut",68,40.,210.);
        TH1D *SDmass_800_lept_outwcut = new TH1D("SDmass_800_lept_outwcut","SDmass_800_lept_outwcut",68,40.,210.);

	TH1D *SDmass_800_hadt_tcut = new TH1D("SDmass_800_hadt_tcut","SDmass_800_hadt_tcut",68,40.,210.);
        TH1D *SDmass_800_hadt_outtcut = new TH1D("SDmass_800_hadt_outtcut","SDmass_800_hadt_outtcut",68,40.,210.);
        TH1D *SDmass_800_hadt_wcut = new TH1D("SDmass_800_hadt_wcut","SDmass_800_hadt_wcut",68,40.,210.);
        TH1D *SDmass_800_hadt_outwcut = new TH1D("SDmass_800_hadt_outwcut","SDmass_800_hadt_outwcut",68,40.,210.);

//        TH1D *SDmass_3000_t_cut = new TH1D("SDmass_3000_t_cut","SDmass_3000_t_cut",68,40.,210.);
//        TH1D *SDmass_3000_t_outcut = new TH1D("SDmass_3000_t_outcut","SDmass_3000_t_outcut",68,40.,210.);
//        TH1D *SDmass_3000_nt_cut = new TH1D("SDmass_3000_nt_cut","SDmass_3000_nt_cut",68,40.,210.);
//        TH1D *SDmass_3000_nt_outcut = new TH1D("SDmass_3000_nt_outcut","SDmass_3000_nt_outcut",68,40.,210.);

        TH1D *SDmass_bkg_lept_tcut = new TH1D("SDmass_bkg_lept_tcut","SDmass_bkg_lept_tcut",68,40.,210.);
        TH1D *SDmass_bkg_lept_outtcut = new TH1D("SDmass_bkg_lept_outtcut","SDmass_bkg_lept_outtcut",68,40.,210.);
	TH1D *SDmass_bkg_lept_wcut = new TH1D("SDmass_bkg_lept_wcut","SDmass_bkg_lept_wcut",68,40.,210.);
        TH1D *SDmass_bkg_lept_outwcut = new TH1D("SDmass_bkg_lept_outwcut","SDmass_bkg_lept_outwcut",68,40.,210.);

	TH1D *SDmass_bkg_hadt_tcut = new TH1D("SDmass_bkg_hadt_tcut","SDmass_bkg_hadt_tcut",68,40.,210.);
        TH1D *SDmass_bkg_hadt_outtcut = new TH1D("SDmass_bkg_hadt_outtcut","SDmass_bkg_hadt_outtcut",68,40.,210.);
        TH1D *SDmass_bkg_hadt_wcut = new TH1D("SDmass_bkg_hadt_wcut","SDmass_bkg_hadt_wcut",68,40.,210.);
        TH1D *SDmass_bkg_hadt_outwcut = new TH1D("SDmass_bkg_hadt_outwcut","SDmass_bkg_hadt_outwcut",68,40.,210.);



	TH1D *SDmass_800_b_tcut = new TH1D("SDmass_800_b_tcut","SDmass_800_b_tcut",68,40.,210.);
        TH1D *SDmass_800_b_outtcut = new TH1D("SDmass_800_b_outtcut","SDmass_800_b_outtcut",68,40.,210.);
        TH1D *SDmass_800_b_wcut = new TH1D("SDmass_800_b_wcut","SDmass_800_b_wcut",68,40.,210.);
        TH1D *SDmass_800_b_outwcut = new TH1D("SDmass_800_b_outwcut","SDmass_800_b_outwcut",68,40.,210.);

	TH1D *SDmass_bkg_b_tcut = new TH1D("SDmass_bkg_b_tcut","SDmass_bkg_b_tcut",68,40.,210.);
        TH1D *SDmass_bkg_b_outtcut = new TH1D("SDmass_bkg_b_outtcut","SDmass_bkg_b_outtcut",68,40.,210.);
        TH1D *SDmass_bkg_b_wcut = new TH1D("SDmass_bkg_b_wcut","SDmass_bkg_b_wcut",68,40.,210.);
        TH1D *SDmass_bkg_b_outwcut = new TH1D("SDmass_bkg_b_outwcut","SDmass_bkg_b_outwcut",68,40.,210.);


	TH1D *SDmass_800_no_wcut = new TH1D("SDmass_800_no_wcut","SDmass_800_no_wcut",68,40.,210.);
        TH1D *SDmass_800_no_outwcut = new TH1D("SDmass_800_no_outwcut","SDmass_800_no_outwcut",68,40.,210.);
        TH1D *SDmass_800_no_tcut = new TH1D("SDmass_800_no_tcut","SDmass_800_no_tcut",68,40.,210.);
        TH1D *SDmass_800_no_outtcut = new TH1D("SDmass_800_no_outtcut","SDmass_800_no_outtcut",68,40.,210.);

        TH1D *SDmass_bkg_no_wcut = new TH1D("SDmass_bkg_no_wcut","SDmass_bkg_no_wcut",68,40.,210.);
        TH1D *SDmass_bkg_no_outwcut = new TH1D("SDmass_bkg_no_outwcut","SDmass_bkg_no_outwcut",68,40.,210.);
	TH1D *SDmass_bkg_no_tcut = new TH1D("SDmass_bkg_no_tcut","SDmass_bkg_no_tcut",68,40.,210.);
        TH1D *SDmass_bkg_no_outtcut = new TH1D("SDmass_bkg_no_outtcut","SDmass_bkg_no_outtcut",68,40.,210.);

	TH1D *SDmass_qcd_wcut = new TH1D("SDmass_qcd_wcut","SDmass_qcd_wcut",68,40.,210.);
        TH1D *SDmass_qcd_outwcut = new TH1D("SDmass_qcd_outwcut","SDmass_qcd_outwcut",68,40.,210.);
        TH1D *SDmass_qcd_tcut = new TH1D("SDmass_qcd_tcut","SDmass_qcd_tcut",68,40.,210.);
        TH1D *SDmass_qcd_outtcut = new TH1D("SDmass_qcd_outtcut","SDmass_qcd_outtcut",68,40.,210.);
	
	TH1D *tau21_1000_w = new TH1D("tau21_1000_w","tau21_1000_w",60,0.,1.2);
	TH1D *tau21_1000_notw = new TH1D("tau21_1000_notw","tau21_1000_notw",60,0.,1.2);
	TH1D *tau21_3000 = new TH1D("tau21_3000","tau21_3000",60,0.,1.2);
	TH1D *tau21_ttbar_w = new TH1D("tau21_ttbar_w","tau21_ttbar_w",60,0.,1.2);
	TH1D *tau21_ttbar_notw = new TH1D("tau21_ttbar_notw","tau21_ttbar_notw",60,0.,1.2);
	TH1D *tau21_qcd = new TH1D("tau21_qcd","tau21_qcd",60,0.,1.2);

	TH1D *tau32_1000_top = new TH1D("tau32_1000_top","tau32_1000_top",60,0.,1.2);
	TH1D *tau32_1000_nottop = new TH1D("tau32_1000_nottop","tau32_1000_nottop",60,0.,1.2);
        TH1D *tau32_3000 = new TH1D("tau32_3000","tau32_3000",60,0.,1.2);
        TH1D *tau32_ttbar_top = new TH1D("tau32_ttbar_top","tau32_ttbar_top",60,0.,1.2);
	TH1D *tau32_ttbar_nottop = new TH1D("tau32_ttbar_nottop","tau32_ttbar_nottop",60,0.,1.2);
        TH1D *tau32_qcd = new TH1D("tau32_qcd","tau32_qcd",60,0.,1.2);



//        TH1D *SDmass_3000_no_tcut = new TH1D("SDmass_3000_no_tcut","SDmass_3000_no_tcut",68,40.,210.);
//        TH1D *SDmass_3000_no_outtcut = new TH1D("SDmass_3000_no_outtcut","SDmass_3000_no_outtcut",68,40.,210.);
//        TH1D *SDmass_3000_no_wcut = new TH1D("SDmass_3000_no_wcut","SDmass_3000_no_wcut",68,40.,210.);
//        TH1D *SDmass_3000_no_outwcut = new TH1D("SDmass_3000_no_outwcut","SDmass_3000_no_outwcut",68,40.,210.);

	TH1D *invirant_800_thbh = new TH1D("invirant_800_thbh","invirant_800_thbh",60,100,700);
	TH1D *invirant_800_thb = new TH1D("invirant_800_thb","invirant_800_thb",60,100,700);
	TH1D *invirant_800_tbh = new TH1D("invirant_800_tbh","invirant_800_tbh",60,100,700);
	TH1D *invirant_800_tb = new TH1D("invirant_800_tb","invirant_800_tb",60,100,700);

	TH1D *invirant_3000_thbh = new TH1D("invirant_3000_thbh","invirant_3000_thbh",120,2400,3600);
        TH1D *invirant_3000_thb = new TH1D("invirant_3000_thb","invirant_3000_thb",120,2400,3600);
	TH1D *invirant_3000_tbh = new TH1D("invirant_3000_tbh","invirant_3000_tbh",120,2400,3600);
	TH1D *invirant_3000_tb = new TH1D("invirant_3000_tb","invirant_3000_tb",120,2400,3600);

        TH1D *invirant_ttbar800_tb = new TH1D("invirant_ttbar800_tb","invirant_ttbar800_tb",80,400,1200);
	TH1D *invirant_ttbar3000_tb = new TH1D("invirant_ttbar3000_tb","invirant_ttbar3000_tb",120,2400,3600);
	TH1D *invirant_qcd800_tb = new TH1D("invirant_qcd800_tb","invirant_qcd800_tb",80,400,1200);
        TH1D *invirant_qcd3000_tb = new TH1D("invirant_qcd3000_tb","invirant_qcd3000_tb",120,2400,3600);

	TH1D *invariant_3_t_800 = new TH1D("invariant_3_t_800","invariant_3_t_800",60,100,700);
        TH1D *invariant_3_t_3000= new TH1D("invariant_3_t_3000","invariant_3_t_3000",120,2400,3600);
        TH1D *invariant_3_nt_w_800 = new TH1D("invariant_3_nt_w_800","invariant_3_nt_w_800",60,100,700);
        TH1D *invariant_3_nt_w_3000 = new TH1D("invariant_3_nt_w_3000","invariant_3_nt_w_3000",120,2400,3600);
        TH1D *invariant_3_nt_nw_800 = new TH1D("invariant_3_nt_nw_800","invariant_3_nt_nw_800",60,100,700);
        TH1D *invariant_3_nt_nw_3000 = new TH1D("invariant_3_nt_nw_3000","invariant_3_nt_nw_3000",120,2400,3600);

	TH1D *invariant_3_ttbar = new TH1D("invariant_3_ttbar","invariant_3_ttbar",80,400,1200);
	TH1D *invariant_3_qcd = new TH1D("invariant_3_qcd","invariant_3_qcd",80,400,1200);

	TH1D *dr_800_thbh = new TH1D("dr_800_thbh","dr_800_thbh",100,0,4.0);
        TH1D *dr_800_thb = new TH1D("dr_800_thb","dr_800_thb",100,0,4.0);
        TH1D *dr_800_tbh = new TH1D("dr_800_tbh","dr_800_tbh",100,0,4.0);
        TH1D *dr_800_tb = new TH1D("dr_800_tb","dr_800_tb",100,0,4.0);

	TH1D *dr_3_t_800 = new TH1D("dr_3_t_800","dr_3_t_800",100,0,4.0);
	TH1D *dr_3_nt_w_800 = new TH1D("dr_3_nt_w_800","dr_3_nt_w_800",100,0,4.0);
	TH1D *dr_3_nt_nw_800 = new TH1D("dr_3_nt_nw_800","dr_3_nt_nw_800",100,0,4.0);

	TH1D *dr_3_ttbar = new TH1D("dr_3_ttbar","dr_3_ttbar",100,0,4.0);
	TH1D *dr_3_qcd = new TH1D("dr_3_qcd","dr_3_qcd",100,0,4.0);

	TH1D *dr_3000_thbh = new TH1D("dr_3000_thbh","dr_3000_thbh",100,0,4.0);
        TH1D *dr_3000_thb = new TH1D("dr_3000_thb","dr_3000_thb",100,0,4.0);
        TH1D *dr_3000_tbh = new TH1D("dr_3000_tbh","dr_3000_tbh",100,0,4.0);
        TH1D *dr_3000_tb = new TH1D("dr_3000_tb","dr_3000_tb",100,0,4.0);

	TH1D *dr_ttbar_tb = new TH1D("dr_ttbar_tb","dr_ttbar_tb",100,0,4.0);
        TH1D *dr_qcd_tb = new TH1D("dr_qcd_tb","dr_qcd_tb",100,0,4.0);

	TH1D *deleta_800_thbh = new TH1D("deleta_800_thbh","deleta_800_thbh",100,0,5.0);
        TH1D *deleta_800_thb = new TH1D("deleta_800_thb","deleta_800_thb",100,0,5.0);
        TH1D *deleta_800_tbh = new TH1D("deleta_800_tbh","deleta_800_tbh",100,0,5.0);
        TH1D *deleta_800_tb = new TH1D("deleta_800_tb","deleta_800_tb",100,0,5.0);

        TH1D *deleta_3_t_800 = new TH1D("deleta_3_t_800","deleta_3_t_800",100,0,5.0);
        TH1D *deleta_3_nt_w_800 = new TH1D("deleta_3_nt_w_800","deleta_3_nt_w_800",100,0,5.0);
        TH1D *deleta_3_nt_nw_800 = new TH1D("deleta_3_nt_nw_800","deleta_3_nt_nw_800",100,0,5.0);
	TH1D *deleta_3_t_3000 = new TH1D("deleta_3_t_3000","deleta_3_t_3000",100,0,5.0);
        TH1D *deleta_3_nt_w_3000 = new TH1D("deleta_3_nt_w_3000","deleta_3_nt_w_3000",100,0,5.0);
        TH1D *deleta_3_nt_nw_3000 = new TH1D("deleta_3_nt_nw_3000","deleta_3_nt_nw_3000",100,0,5.0);




        TH1D *deleta_3_ttbar = new TH1D("deleta_3_ttbar","deleta_3_ttbar",100,0,5.0);
        TH1D *deleta_3_qcd = new TH1D("deleta_3_qcd","deleta_3_qcd",100,0,5.0);

        TH1D *deleta_ttbar_tb = new TH1D("deleta_ttbar_tb","deleta_ttbar_tb",100,0,5.0);
        TH1D *deleta_qcd_tb = new TH1D("deleta_qcd_tb","deleta_qcd_tb",100,0,5.0);


	TH1D *debug_thb = new TH1D("debug_thb","debug_thb",80,400,2400); 
        TH1D *debug_th_pt = new TH1D("debug_th_pt","debug_th_pt",100,400,1200);
        TH1D *debug_th_bsubjet = new TH1D("debug_th_bsubjet","debug_th_bsubjet",2,0.,2.);
                                
        TH1D *debug_tb = new TH1D("debug_tb","debug_tb",80,400,2400);
        TH1D *debug_t_pt = new TH1D("debug_t_pt","debug_t_pt",100,400,1200);
        TH1D *debug_t_bsubjet = new TH1D("debug_t_bsubjet","debug_t_bsubjet",2,0.,2.);


	TH1D *pt_800_thbh = new TH1D("pt_800_thbh","pt_800_thbh",80,400,2400);
        TH1D *pt_800_thb = new TH1D("pt_800_thb","pt_800_thb",80,400,2400);
        TH1D *pt_800_tbh = new TH1D("pt_800_tbh","pt_800_tbh",80,400,2400);
        TH1D *pt_800_tb = new TH1D("pt_800_tb","pt_800_tb",80,400,2400);

        TH1D *pt_3000_thbh = new TH1D("pt_3000_thbh","pt_3000_thbh",120,400,3600);
        TH1D *pt_3000_thb = new TH1D("pt_3000_thb","pt_3000_thb",120,400,3600);
        TH1D *pt_3000_tbh = new TH1D("pt_3000_tbh","pt_3000_tbh",120,400,3600);
        TH1D *pt_3000_tb = new TH1D("pt_3000_tb","pt_3000_tb",120,400,3600);

        TH1D *pt_ttbar_tb = new TH1D("pt_ttbar_tb","pt_ttbar_tb",80,400,2400);
        TH1D *pt_qcd_tb = new TH1D("pt_qcd_tb","pt_qcd_tb",80,400,2400);

	TH1D *ndb_pt_800 = new TH1D("ndb_pt_800","ndb_pt_800",100,40,1200);
        TH1D *ndb_pt_ttbar = new TH1D("ndb_pt_ttbar","ndb_pt_ttbar",100,40,1200);
        TH1D *ndb_pt_qcd = new TH1D("ndb_pt_qcd","ndb_pt_qcd",100,40,1200);

	TH1D *ndW_pt_800 = new TH1D("ndW_pt_800","ndW_pt_800",100,200,1200);
        TH1D *ndW_pt_ttbar = new TH1D("ndW_pt_ttbar","ndW_pt_ttbar",100,200,1200);
        TH1D *ndW_pt_qcd = new TH1D("ndW_pt_qcd","ndW_pt_qcd",100,200,1200);

	TH1D *W_pt_800 = new TH1D("W_pt_800","W_pt_800",100,200,1200);
	TH1D *W_pt_ttbar = new TH1D("W_pt_ttbar","W_pt_ttbar",100,200,1200);
	TH1D *W_pt_qcd = new TH1D("W_pt_qcd","W_pt_qcd",100,200,1200);

	TH1D *b_pt_800 = new TH1D("b_pt_800","b_pt_800",100,40,1200);
//	TH1D *b_pt_3000 = new TH1D("b_pt_3000","b_pt_3000",100,40,1200);
        TH1D *b_pt_ttbar = new TH1D("b_pt_ttbar","b_pt_ttbar",100,40,1200);
        TH1D *b_pt_qcd = new TH1D("b_pt_qcd","b_pt_qcd",100,40,1200);

	TH1D *top_pt_800 = new TH1D("top_pt_800","top_pt_800",100,400,1200);
        TH1D *top_pt_ttbar = new TH1D("top_pt_ttbar","top_pt_ttbar",100,400,1200);
        TH1D *top_pt_qcd = new TH1D("top_pt_qcd","top_pt_qcd",100,400,1200);

	TH1D *top_pt_800_cut = new TH1D("top_pt_800_cut","top_pt_800_cut",100,400,1200);
        TH1D *top_pt_ttbar_cut = new TH1D("top_pt_ttbar_cut","top_pt_ttbar_cut",100,400,1200);
        TH1D *top_pt_qcd_cut = new TH1D("top_pt_qcd_cut","top_pt_qcd_cut",100,400,1200);

	TH1D *top_pt_3_800_yes = new TH1D("top_pt_3_800_yes","top_pt_3_800_yes",100,400,1200);
	TH1D *top_pt_3_800_no = new TH1D("top_pt_3_800_no","top_pt_3_800_no",100,400,1200);
	TH1D *top_pt_3_ttbar = new TH1D("top_pt_3_ttbar","top_pt_3_ttbar",100,400,1200);
	TH1D *top_pt_3_qcd = new TH1D("top_pt_3_qcd","top_pt_3_qcd",100,400,1200);

	TH1D *top_m_3_800_yes = new TH1D("top_m_3_800_yes","top_m_3_800_yes",100,75,275);
        TH1D *top_m_3_800_no = new TH1D("top_m_3_800_no","top_m_3_800_no",100,75,275);
        TH1D *top_m_3_ttbar = new TH1D("top_m_3_ttbar","top_m_3_ttbar",100,75,275);
        TH1D *top_m_3_qcd = new TH1D("top_m_3_qcd","top_m_3_qcd",100,75,275);


	TH1D *top_pt_800_yes = new TH1D("top_pt_800_yes","top_pt_800_yes",100,400,1200);
	TH1D *top_pt_800_no = new TH1D("top_pt_800_no","top_pt_800_no",100,400,1200);
/*
	TH1D *HT_800 = new TH1D("HT_800","HT_800",100,800,5800);
	TH1D *HT_3000 = new TH1D("HT_3000","HT_3000",100,800,5800);
	TH1D *HT_ttbar = new TH1D("HT_ttbar","HT_ttbar",100,800,5800);
	TH1D *HT_qcd = new TH1D("HT_qcd","HT_qcd",100,800,5800);

	TH1D *DRWth_lep = new TH1D("DRWth_lep","DRWth_lep",120,0.,4.);
	TH1D *DRWtass_lep = new TH1D("DRWtass_lep","DRWtass_lep",120,0.,4.);
	TH1D *DRWplus_lep = new TH1D("DRWplus_lep","DRWplus_lep",120,0.,4.);
	TH1D *DRWminus_lep = new TH1D("DRWminus_lep","DRWminus_lep",120,0.,4.);

	TH1D *DRWth_had_b = new TH1D("DRWth_had_b","DRWth_had_b",120,0.,4.);
	TH1D *DRWth_had_n = new TH1D("DRWth_had_n","DRWth_had_n",120,0.,4.);
        TH1D *DRWtass_had = new TH1D("DRWtass_had","DRWtass_had",120,0.,4.);
        TH1D *DRWplus_had = new TH1D("DRWplus_had","DRWplus_had",120,0.,4.);
        TH1D *DRWminus_had = new TH1D("DRWminus_had","DRWminus_had",120,0.,4.);

	TH1D *DRtoph_lep = new TH1D("DRtoph_lep","DRtoph_lep",120,0.,4.);
	TH1D *DRtass_lep = new TH1D("DRtass_lep","DRtass_lep",120,0.,4.);
	TH1D *DRtopplus_lep = new TH1D("DRtopplus_lep","DRtopplus_lep",120,0.,4.);
	TH1D *DRtopminus_lep = new TH1D("DRtopminus_lep","DRtopminus_lep",120,0.,4.);
	
	TH1D *DRtoph_had_b = new TH1D("DRtoph_had_b","DRtoph_had_b",120,0.,4.);
	TH1D *DRtoph_had_n = new TH1D("DRtoph_had_n","DRtoph_had_n",120,0.,4.);
        TH1D *DRtass_had = new TH1D("DRtass_had","DRtass_had",120,0.,4.);
        TH1D *DRtopplus_had = new TH1D("DRtopplus_had","DRtopplus_had",120,0.,4.);
        TH1D *DRtopminus_had = new TH1D("DRtopminus_had","DRtopminus_had",120,0.,4.);

	TH1D *DRbh = new TH1D("DRbh","DRbh",120,0.,4.);
	TH1D *DRrebkg = new TH1D("DRrebkg","DRrebkg",120,0.,4.);
	TH1D *DRbplus = new TH1D("DRbplus","DRbplus",120,0.,4.);
	TH1D *DRbminus = new TH1D("DRbminus","DRbminus",120,0.,4.);

	TH2D *DRPt_toph = new TH2D("DRPt_toph","DRPt_toph",100,400,1000,100,0,1);
	TH2D *DRPt_tass = new TH2D("DRPt_tass","DRPt_tass",100,400,1000,100,0,1);
	TH2D *DRPt_topplus = new TH2D("DRPt_topplus","DRPt_topplus",100,400,1000,100,0,1);
	TH2D *DRPt_topminus = new TH2D("DRPt_topminus","DRPt_topminus",100,400,1000,100,0,1);

	TH2D *DRPt_Wth = new TH2D("DRPt_Wth","DRPt_Wth",100,200,1000,100,0,1);
	TH2D *DRPt_Wtass = new TH2D("DRPt_Wtass","DRPt_Wtass",100,200,1000,100,0,1);
	TH2D *DRPt_Wplus = new TH2D("DRPt_Wplus","DRPt_Wplus",100,200,1000,100,0,1);
	TH2D *DRPt_Wminus = new TH2D("DRPt_Wminus","DRPt_Wminus",100,200,1000,100,0,1);

	TH1D *DRleadingbh = new TH1D("DRleadingbh","DRleadingbh",120,0.,4.);

	TH1D *topWdist_800 = new TH1D("topWdist_800","topWdist_800",5,0,5); //1:at least a top,a W; 2:at least a top, no W; 3: at least a W. no top;4:nothing 
	TH1D *topWdist_ttbar = new TH1D("topWdist_ttbar","topWdist_ttbar",5,0,5);
	TH1D *topWdist_qcd = new TH1D("topWdist_qcd","topWdist_qcd",5,0,5);
*/
	TH1D *nbjets_800 = new TH1D("nbjets_800","nbjets_800",4,0,4);
	TH1D *nbjets_3000 = new TH1D("nbjets_3000","nbjets_3000",4,0,4);
	TH1D *nbjets_ttbar = new TH1D("nbjets_ttbar","nbjets_ttbar",4,0,4);
	TH1D *nbjets_qcd = new TH1D("nbjets_qcd","nbjets_qcd",4,0,4);
/*
	TH1D *njets_800 = new TH1D("njets_800","njets_800",7,0,7);
	TH1D *njets_3000 = new TH1D("njets_3000","njets_3000",7,0,7);
	TH1D *njets_ttbar = new TH1D("njets_ttbar","njets_ttbar",7,0,7);
	TH1D *njets_qcd = new TH1D("njets_qcd","njets_qcd",7,0,7);
*/


        for(UInt_t i=0; i < t1->GetEntries(); i++) {
//	for(UInt_t i=0; i < 500000; i++) {

                t1->GetEntry(i);

		if(ht < 800.) continue;
		if(   ( (sig!=1) || ((mc!=themc) && (mc!=smc)) ) && ( (sig!=0) || ((mc!=103) && (mc!=500)) )   ) continue;
//		if(   ( (sig!=1) || (mc!=themc)  ) && ( (sig!=0) || ((mc!=103) && (mc!=500)) )   ) continue;
		if(NBJets == 0) continue;

		TLorentzVector topfromhiggs, topass, bfromhiggs, bfromth, bfromgluon, Wfromhiggs, Wfromgluon;
                if(sig == 1){
                topfromhiggs.SetPtEtaPhiM(topFromH_pt,topFromH_eta,topFromH_phi,Mtop);
                topass.SetPtEtaPhiM(topAss_pt,topAss_eta,topAss_phi,Mtop);
                bfromhiggs.SetPtEtaPhiM(bFromH_pt,bFromH_eta,bFromH_phi,Mbottom);
                bfromth.SetPtEtaPhiM(bFromTopH_pt,bFromTopH_eta,bFromTopH_phi,Mbottom);
                bfromgluon.SetPtEtaPhiM(bFromTopAss_pt,bFromTopAss_eta,bFromTopAss_phi,Mbottom);
                Wfromhiggs.SetPtEtaPhiM(WFromTopH_pt,WFromTopH_eta,WFromTopH_phi,Mw);
                Wfromgluon.SetPtEtaPhiM(WFromTopAss_pt,WFromTopAss_eta,WFromTopAss_phi,Mw);
                }

                TLorentzVector topbkgp, topbkgm, bbkgp, bbkgm, wbkgp, wbkgm;
                if(sig == 0 && mc == 103){
                topbkgp.SetPtEtaPhiM(topBKGplus_pt,topBKGplus_eta,topBKGplus_phi,Mtop);
                topbkgm.SetPtEtaPhiM(topBKGminus_pt,topBKGminus_eta,topBKGminus_phi,Mtop);
                bbkgp.SetPtEtaPhiM(bBKGplus_pt,bBKGplus_eta,bBKGplus_phi,Mbottom);
                bbkgm.SetPtEtaPhiM(bBKGminus_pt,bBKGminus_eta,bBKGminus_phi,Mbottom);
                wbkgp.SetPtEtaPhiM(WBKGplus_pt,WBKGplus_eta,WBKGplus_phi,Mw);
                wbkgm.SetPtEtaPhiM(WBKGminus_pt,WBKGminus_eta,WBKGminus_phi,Mw);
                }


		if(sig == 1) merge_Wb->Fill(topFromH_pt,bfromth.DeltaR(Wfromhiggs),weight);
		


		Int_t flag_lb[10] = {0};
		Int_t leadingokb = -1;
		for(Int_t mm = 0; mm < TMath::Min(NBJets,10); mm++){
			TLorentzVector ab;
                	ab.SetPtEtaPhiE(bjet_pt[mm],bjet_eta[mm],bjet_phi[mm],bjet_e[mm]);
			for(Int_t kfjet=0; kfjet<TMath::Min(NFatJets,5); kfjet++){
                		TLorentzVector AK8jet;
                        	AK8jet.SetPtEtaPhiE(fatjet_pt[kfjet],fatjet_eta[kfjet],fatjet_phi[kfjet],fatjet_e[kfjet]);
                        	if(fatjet_pt[kfjet] > 400. && fatjet_tau3[kfjet]/fatjet_tau2[kfjet] < 0.81 && fatjet_SDMass[kfjet] > 105 && fatjet_SDMass[kfjet] < 220){ if(ab.DeltaR(AK8jet) < 1.2) flag_lb[mm] = 1; }
                	}
		}

		for(Int_t mm = 0; mm < TMath::Min(NBJets,10); mm++){
			if(flag_lb[mm] == 1) continue;
			leadingokb = mm; break;
		}


/*		if(leadingokb < 0) continue;
                TLorentzVector leadingb;
                leadingb.SetPtEtaPhiE(bjet_pt[leadingokb],bjet_eta[leadingokb],bjet_phi[leadingokb],bjet_e[leadingokb]);
                if(sig == 1 && mc == themc) b_pt_800->Fill(bjet_pt[leadingokb], weight);
                else if(sig == 0 && mc == 103) b_pt_ttbar->Fill(bjet_pt[leadingokb], weight);
                else if(sig == 0 && mc == 500) b_pt_qcd->Fill(bjet_pt[leadingokb], weight);
*/

/*
		
                TLorentzVector topfromhiggs, topass, bfromhiggs, bfromth, bfromgluon, Wfromhiggs, Wfromgluon;
		if(sig == 1){
		topfromhiggs.SetPtEtaPhiM(topFromH_pt,topFromH_eta,topFromH_phi,Mtop);
		topass.SetPtEtaPhiM(topAss_pt,topAss_eta,topAss_phi,Mtop);
		bfromhiggs.SetPtEtaPhiM(bFromH_pt,bFromH_eta,bFromH_phi,Mbottom);
		bfromth.SetPtEtaPhiM(bFromTopH_pt,bFromTopH_eta,bFromTopH_phi,Mbottom);
		bfromgluon.SetPtEtaPhiM(bFromTopAss_pt,bFromTopAss_eta,bFromTopAss_phi,Mbottom);
                Wfromhiggs.SetPtEtaPhiM(WFromTopH_pt,WFromTopH_eta,WFromTopH_phi,Mw);
                Wfromgluon.SetPtEtaPhiM(WFromTopAss_pt,WFromTopAss_eta,WFromTopAss_phi,Mw);
		}

		TLorentzVector topbkgp, topbkgm, bbkgp, bbkgm, wbkgp, wbkgm;
		if(sig == 0 && mc == 103){
		topbkgp.SetPtEtaPhiM(topBKGplus_pt,topBKGplus_eta,topBKGplus_phi,Mtop);
		topbkgm.SetPtEtaPhiM(topBKGminus_pt,topBKGminus_eta,topBKGminus_phi,Mtop);
		bbkgp.SetPtEtaPhiM(bBKGplus_pt,bBKGplus_eta,bBKGplus_phi,Mbottom);
                bbkgm.SetPtEtaPhiM(bBKGminus_pt,bBKGminus_eta,bBKGminus_phi,Mbottom);
		wbkgp.SetPtEtaPhiM(WBKGplus_pt,WBKGplus_eta,WBKGplus_phi,Mw);
                wbkgm.SetPtEtaPhiM(WBKGminus_pt,WBKGminus_eta,WBKGminus_phi,Mw);
		}

*/	
		

		Int_t numtop_sig = 0;
		Int_t numW_sig = 0;
		Int_t numtop_3000 = 0;
                Int_t numW_3000 = 0;
		Int_t numtop_ttbar = 0;
		Int_t numW_ttbar = 0;
		Int_t numtop_qcd = 0;
                Int_t numW_qcd = 0;


		Double_t minWth = 99., minWta = 99.; TLorentzVector wth, wtass;
		Double_t minWbkg1 = 99., minWbkg2 = 99.; TLorentzVector wbkg1, wbkg2;

		Double_t minbh = 99., minbth = 99., minbta = 99.; TLorentzVector bh, bth, bta;
		Double_t minbbkg1 = 99., minbbkg2 = 99.; TLorentzVector bbkg1, bbkg2;

		Double_t mintoph = 99., mintopa = 99.;  TLorentzVector toph, tass;
		Double_t mintopbkg1 = 99., mintopbkg2 = 99.; TLorentzVector topbkg1, topbkg2;
		Int_t topsnum1 = -1;
		Int_t topsnum2 = -1;
		Int_t topbnum1 = -1;
                Int_t topbnum2 = -1;
		Int_t Wsnum1 = -1;
		Int_t Wsnum2 = -1;
		Int_t Wbnum1 = -1;
                Int_t Wbnum2 = -1;
		Int_t bsnum1 = -1;
		Int_t bsnum2 = -1;
		Int_t bsnum3 = -1;
		Int_t bbnum1 = -1;
		Int_t bbnum2 = -1;


		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

                        if(fatjet_pt[j] < 400.) continue;

			TLorentzVector maybetop;
			maybetop.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);

			if (sig == 1){
                        	Double_t deltoph = maybetop.DeltaR(topfromhiggs);
				Double_t deltopa = maybetop.DeltaR(topass);
                                if (deltoph < mintoph){ mintoph = deltoph; toph = maybetop; topsnum1 = j;}
				if (deltopa < mintopa){ mintopa = deltopa; tass = maybetop; topsnum2 = j;}
                        }else if(sig == 0 && mc == 103){
                                Double_t deltopbkg1 = maybetop.DeltaR(topbkgp);
				Double_t deltopbkg2 = maybetop.DeltaR(topbkgm);
                                if (deltopbkg1 < mintopbkg1){ mintopbkg1 = deltopbkg1; topbkg1 = maybetop; topbnum1 = j;} 
				if (deltopbkg2 < mintopbkg2){ mintopbkg2 = deltopbkg2; topbkg2 = maybetop; topbnum2 = j;}
                        }
		}


		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

			if(fatjet_pt[j] < 200.) continue;
		
			if(sig == 1) if( (mintoph < 0.3 && j == topsnum1) || (mintopa < 0.2 && j == topsnum2) ) continue;
			if(sig == 0 && mc == 103) if( (mintopbkg1 < 0.2 && j == topbnum1) || (mintopbkg2 < 0.2 && j == topbnum2) ) continue;


			TLorentzVector maybeW;
			maybeW.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);

			if (sig == 1){
				Double_t delWth = maybeW.DeltaR(Wfromhiggs);
				Double_t delWta = maybeW.DeltaR(Wfromgluon);
				if (delWth < minWth){ minWth = delWth; wth = maybeW; Wsnum1 = j;}
				if (delWta < minWta){ minWta = delWta; wtass = maybeW; Wsnum2 = j;}
			}else if(sig == 0 && mc == 103){
				Double_t delWbkg1 = maybeW.DeltaR(wbkgp);
				Double_t delWbkg2 = maybeW.DeltaR(wbkgm);
				if (delWbkg1 < minWbkg1){ minWbkg1 = delWbkg1; wbkg1 = maybeW; Wbnum1 = j; }
				if (delWbkg2 < minWbkg2){ minWbkg2 = delWbkg2; wbkg2 = maybeW; Wbnum2 = j; }
			}

		}

		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

//                        if(fatjet_pt[j] < 40.) continue;

                        if(sig == 1) if( (mintoph < 0.3 && j == topsnum1) || (mintopa < 0.2 && j == topsnum2) ) continue;
                        if(sig == 0 && mc == 103) if( (mintopbkg1 < 0.2 && j == topbnum1) || (mintopbkg2 < 0.2 && j == topbnum2) ) continue;

			if(sig == 1) if( (minWth < 0.3 && j == Wsnum1) || (minWta < 0.2 && j == Wsnum2) ) continue;
                        if(sig == 0 && mc == 103) if( (minWbkg1 < 0.2 && j == Wbnum1) || (minWbkg2 < 0.2 && j == Wbnum2) ) continue;


                        TLorentzVector maybeW;
                        maybeW.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);

                        if (sig == 1){
                                Double_t delbh = maybeW.DeltaR(bfromhiggs);
				Double_t delbth = maybeW.DeltaR(bfromth);
				Double_t delbta = maybeW.DeltaR(bfromgluon);
                                if (delbh < minbh){ minbh = delbh; bh = maybeW;  bsnum1 = j;}
				if (delbth < minbth){ minbth = delbth; bth = maybeW; bsnum2 = j;}
				if (delbta < minbta){ minbta = delbta; bta = maybeW; bsnum3 = j;}
                        }else if(sig == 0 && mc == 103){
				Double_t delbbkg1 = maybeW.DeltaR(bbkgp);
				Double_t delbbkg2 = maybeW.DeltaR(bbkgm);
				if (delbbkg1 < minbbkg1){ minbbkg1 = delbbkg1; bbkg1 = maybeW; bbnum1 = j; }
				if (delbbkg2 < minbbkg2){ minbbkg2 = delbbkg2; bbkg2 = maybeW; bbnum2 = j; }
                        }

                }


/*
		if(sig == 1){
			if (mintoph < 5.) {
			//	DRPt_toph->Fill(fatjet_pt[topsnum1],toph.DeltaR(topfromhiggs));
				if(topFromH_lep == 1) DRtoph_lep->Fill(toph.DeltaR(topfromhiggs)); 
				else if(topFromH_lep == 0 && minbh < 0.2 && toph == bh) DRtoph_had_b->Fill(toph.DeltaR(topfromhiggs));
				else if(topFromH_lep == 0 && (minbh > 0.2 || toph != bh))DRtoph_had_n->Fill(toph.DeltaR(topfromhiggs));
			}
			if (mintopa < 5.) {
			//	DRPt_tass->Fill(fatjet_pt[topsnum2],tass.DeltaR(topass));
				if(topAss_lep == 1) DRtass_lep->Fill(tass.DeltaR(topass));
				else DRtass_had->Fill(tass.DeltaR(topass));
			}

			if (minbh < 5.) {
				DRbh->Fill(bh.DeltaR(bfromhiggs));
			}
		
			if (minWth < 5.) {
                        //      DRPt_Wth->Fill(fatjet_pt[Wsnum1],wth.DeltaR(Wfromhiggs));
                        	if(WFromTopH_lep == 1) DRWth_lep->Fill(wth.DeltaR(Wfromhiggs));
                                else if(WFromTopH_lep == 0 && minbh < 0.2 && wth == bh) DRWth_had_b->Fill(wth.DeltaR(Wfromhiggs));
				else if(WFromTopH_lep == 0 && (minbh < 0.2 || wth == bh)) DRWth_had_n->Fill(wth.DeltaR(Wfromhiggs));
                        }
                        if (minWta < 5.) {
                        //      DRPt_Wtass->Fill(fatjet_pt[Wsnum2],wtass.DeltaR(Wfromgluon));
                        	if(WFromTopAss_lep == 1) DRWtass_lep->Fill(wtass.DeltaR(Wfromgluon));
                                else DRWtass_had->Fill(wtass.DeltaR(Wfromgluon));
                        }

	
		}else if(sig == 0 && mc == 103){
                	if (mintopbkg1 < 5.) {
			//	DRPt_topplus->Fill(fatjet_pt[topbnum1],topbkg1.DeltaR(topbkgp));
				if(topBKGplus_lep == 1) DRtopplus_lep->Fill(topbkg1.DeltaR(topbkgp));
				else DRtopplus_had->Fill(topbkg1.DeltaR(topbkgp));
			}
			if (mintopbkg2 < 5.) {
			//	DRPt_topminus->Fill(fatjet_pt[topbnum2],topbkg2.DeltaR(topbkgm));
				if(topBKGminus_lep == 1) DRtopminus_lep->Fill(topbkg2.DeltaR(topbkgm));
				else DRtopminus_had->Fill(topbkg2.DeltaR(topbkgm));
			}


			if (minWbkg1 < 5.) {
                        //      DRPt_Wplus->Fill(fatjet_pt[Wbnum1],wbkg1.DeltaR(wbkgp));
                        	if(WBKGplus_lep == 1 && WBKGminus_lep == 1) DRWplus_lep->Fill(wbkg1.DeltaR(wbkgp));
                                else if(WBKGplus_lep == 0 && WBKGminus_lep == 0) DRWplus_had->Fill(wbkg1.DeltaR(wbkgp));
                        }
                        if (minWbkg2 < 5.) {
			//      DRPt_Wminus->Fill(fatjet_pt[Wbnum2],wbkg2.DeltaR(wbkgm));
				if(WBKGminus_lep == 1 && WBKGplus_lep == 1) DRWminus_lep->Fill(wbkg2.DeltaR(wbkgm));
                                else if (WBKGplus_lep == 0 && WBKGminus_lep == 0) DRWminus_had->Fill(wbkg2.DeltaR(wbkgm));
                        }
			if (minbbkg1 < 5.) DRbplus->Fill(bbkg1.DeltaR(bbkgp));
			if (minbbkg2 < 5.) DRbminus->Fill(bbkg2.DeltaR(bbkgm));
		}

*/

		Double_t mintopmass = 999.;
		TLorentzVector w1, b1, t1;
		Int_t orderW = -1, orderb = -1;

		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

			if(fatjet_tau1[j] == 0 || fatjet_tau2[j] == 0) continue;	
//			if(fatjet_pt[j] < 200.) continue;
	
			TLorentzVector temp;
			temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);
		

			if(sig == 1 && mc == themc) {
				if( (j == Wsnum1 && minWth < 0.3 && WFromTopH_lep == 0) || (j == Wsnum2 && minWta < 0.2 && WFromTopAss_lep == 0) )tau21_1000_w->Fill(fatjet_tau2[j]/fatjet_tau1[j], weight); 				    else tau21_1000_notw->Fill(fatjet_tau2[j]/fatjet_tau1[j], weight);

				if( (mintoph < 0.3 && j == topsnum1 && topFromH_lep == 0) || (mintopa < 0.2 && j == topsnum2 && topAss_lep == 0) )tau32_1000_top->Fill(fatjet_tau3[j]/fatjet_tau2[j], weight);
				else tau32_1000_nottop->Fill(fatjet_tau3[j]/fatjet_tau2[j], weight);
			} else if (sig == 0 && mc == 103) {
				if( (j == Wbnum1 && minWbkg1 < 0.2 && WBKGplus_lep == 0) || (j == Wbnum2 && minWbkg2 < 0.2 && WBKGminus_lep == 0) )tau21_ttbar_w->Fill(fatjet_tau2[j]/fatjet_tau1[j], weight); 
				else tau21_ttbar_notw->Fill(fatjet_tau2[j]/fatjet_tau1[j], weight); 

				if( (mintopbkg1 < 0.2 && j == topbnum1 && topBKGplus_lep == 0) || (mintopbkg2 < 0.2 && j == topbnum2 && topBKGminus_lep == 0) )tau32_ttbar_top->Fill(fatjet_tau3[j]/fatjet_tau2[j], weight);
				else tau32_ttbar_nottop->Fill(fatjet_tau3[j]/fatjet_tau2[j], weight);
			}else if (sig == 0 && mc == 500) {tau21_qcd->Fill(fatjet_tau2[j]/fatjet_tau1[j], weight); tau32_qcd->Fill(fatjet_tau3[j]/fatjet_tau2[j], weight);}


			if(fatjet_pt[j] > 200. && fatjet_tau2[j]/fatjet_tau1[j] < 0.6 && fatjet_SDMass[j] > 65 && fatjet_SDMass[j] < 105  ){
				if(sig == 1 && mc == themc) {numW_sig++; W_pt_800->Fill(fatjet_pt[j],weight);}
				else if (sig == 1 && mc == smc) {numW_3000++;}
				else if (sig == 0 && mc == 103) {numW_ttbar++; W_pt_ttbar->Fill(fatjet_pt[j],weight);}
				else if (sig == 0 && mc == 500) {numW_qcd++; W_pt_qcd->Fill(fatjet_pt[j],weight);}
				
				for(Int_t ib = 0; ib < TMath::Min(NBJets,10) ; ib++){
					if(flag_lb[ib] == 1 || ib == leadingokb) continue; 
					TLorentzVector secondb;
					secondb.SetPtEtaPhiE(bjet_pt[ib],bjet_eta[ib],bjet_phi[ib],bjet_e[ib]);
					TLorentzVector mayt = temp + secondb;
					Double_t deltopmass = fabs(mayt.M() - Mtop);
					if (deltopmass < mintopmass){
						t1 = mayt;
						w1 = temp; orderW = j;
						b1 = secondb; orderb = ib;
						mintopmass = deltopmass;
					}
				}		
			}

			if(fatjet_pt[j] > 400. && fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220  ){
				if(sig == 1 && mc == themc) {numtop_sig++; top_pt_800->Fill(fatjet_pt[j],weight);}
				else if (sig == 1 && mc == smc) {numtop_3000++;}
				else if (sig == 0 && mc == 103) {numtop_ttbar++; top_pt_ttbar->Fill(fatjet_pt[j],weight);}
				else if (sig == 0 && mc == 500) {numtop_qcd++; top_pt_qcd->Fill(fatjet_pt[j],weight);}
                        }


				
			if(sig == 1){
				//lep top
				if( (mintoph < 0.3 && j == topsnum1 && topFromH_lep == 1) || (mintopa < 0.2 && j == topsnum2 && topAss_lep == 1) ) {
					if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
                                        	if(mc == themc) SDmass_800_lept_tcut->Fill(fatjet_SDMass[j],weight);
//                                                        else if(mc == smc) SDmass_3000_t_cut->Fill(fatjet_SDMass[j],weight);
                                        }else{
                                        	if(mc == themc) SDmass_800_lept_outtcut->Fill(fatjet_SDMass[j],weight);
//                                                        else if(mc == smc) SDmass_3000_t_outcut->Fill(fatjet_SDMass[j],weight);
                                        }

					if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
						if(mc == themc) SDmass_800_lept_wcut->Fill(fatjet_SDMass[j],weight);
					}else{
						if(mc == themc) SDmass_800_lept_outwcut->Fill(fatjet_SDMass[j],weight);
					}
				//had top
				}else if( (mintoph < 0.3 && j == topsnum1 && topFromH_lep == 0) || (mintopa < 0.2 && j == topsnum2 && topAss_lep == 0) ) {
					if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
                                                if(mc == themc) SDmass_800_hadt_tcut->Fill(fatjet_SDMass[j],weight);
					}else{
                                                if(mc == themc) SDmass_800_hadt_outtcut->Fill(fatjet_SDMass[j],weight);
					}

                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
                                                if(mc == themc) SDmass_800_hadt_wcut->Fill(fatjet_SDMass[j],weight);
                                        }else{
                                                if(mc == themc) SDmass_800_hadt_outwcut->Fill(fatjet_SDMass[j],weight);
                                        }
				//lep W
				}else if( (j == Wsnum1 && minWth < 0.3 && WFromTopH_lep == 1) || (j == Wsnum2 && minWta < 0.2 && WFromTopAss_lep == 1) ) {
					if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
						if(mc == themc) SDmass_800_lepw_wcut->Fill(fatjet_SDMass[j],weight);
					//		else if(mc == smc) SDmass_3000_w_cut->Fill(fatjet_SDMass[j],weight);
					}else{
						if(mc == themc) SDmass_800_lepw_outwcut->Fill(fatjet_SDMass[j],weight);
                                        //                else if(mc == smc) SDmass_3000_w_outcut->Fill(fatjet_SDMass[j],weight);
                                        }
					
					if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
                                                if(mc == themc) SDmass_800_lepw_tcut->Fill(fatjet_SDMass[j],weight);
                                        }else{
                                                if(mc == themc) SDmass_800_lepw_outtcut->Fill(fatjet_SDMass[j],weight);
                                        }
				//had W
				}else if( (j == Wsnum1 && minWth < 0.3 && WFromTopH_lep == 0) || (j == Wsnum2 && minWta < 0.2 && WFromTopAss_lep == 0) ) {
                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
                                                if(mc == themc) SDmass_800_hadw_wcut->Fill(fatjet_SDMass[j],weight);
					}else{
                                                if(mc == themc) SDmass_800_hadw_outwcut->Fill(fatjet_SDMass[j],weight);
                                        }

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
                                                if(mc == themc) SDmass_800_hadw_tcut->Fill(fatjet_SDMass[j],weight); 
                                        }else{
                                                if(mc == themc) SDmass_800_hadw_outtcut->Fill(fatjet_SDMass[j],weight);
                                        }
				//b
				}else if( (j == bsnum1 && minbh < 0.2) || (j == bsnum2 && minbth < 0.3) || (j == bsnum3 && minbta < 0.3) ){
                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
						if(mc == themc) SDmass_800_b_wcut->Fill(fatjet_SDMass[j],weight);
                                        }else{
						if(mc == themc) SDmass_800_b_outwcut->Fill(fatjet_SDMass[j],weight);
					}

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
						if(mc == themc) SDmass_800_b_tcut->Fill(fatjet_SDMass[j],weight);
                                        }else{
						if(mc == themc) SDmass_800_b_outtcut->Fill(fatjet_SDMass[j],weight);
					}
				}else{
					if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6){
                                        	if(mc == themc) SDmass_800_no_wcut->Fill(fatjet_SDMass[j],weight);
                                                     //   else if(mc == smc) SDmass_3000_nw_cut->Fill(fatjet_SDMass[j],weight);
                                        }else{
                                        	if(mc == themc) SDmass_800_no_outwcut->Fill(fatjet_SDMass[j],weight);
                                                   //     else if(mc == smc) SDmass_3000_nw_outcut->Fill(fatjet_SDMass[j],weight);
                                        }

					if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81){
						if(mc == themc) SDmass_800_no_tcut->Fill(fatjet_SDMass[j],weight);
					}else{
						if(mc == themc) SDmass_800_no_outtcut->Fill(fatjet_SDMass[j],weight);
					}
                                }
				
			}else if(sig == 0 && mc == 103){
				//lep top
                                if( (mintopbkg1 < 0.2 && j == topbnum1 && topBKGplus_lep == 1) || (mintopbkg2 < 0.2 && j == topbnum2 && topBKGminus_lep == 1) ) {
                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81)SDmass_bkg_lept_tcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_lept_outtcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_lept_wcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_lept_outwcut->Fill(fatjet_SDMass[j],weight);
				//had top
				}else if( (mintopbkg1 < 0.2 && j == topbnum1 && topBKGplus_lep == 0) || (mintopbkg2 < 0.2 && j == topbnum2 && topBKGminus_lep == 0) ) {
                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81)SDmass_bkg_hadt_tcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_hadt_outtcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_hadt_wcut->Fill(fatjet_SDMass[j],weight); 
                                        else SDmass_bkg_hadt_outwcut->Fill(fatjet_SDMass[j],weight); 
				//lep W
                                }else if( (j == Wbnum1 && minWbkg1 < 0.2 && WBKGplus_lep == 1) || (j == Wbnum2 && minWbkg2 < 0.2 && WBKGminus_lep == 1) ) {
                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_lepw_wcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_lepw_outwcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81) SDmass_bkg_lepw_tcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_lepw_outtcut->Fill(fatjet_SDMass[j],weight);
				//had W
				}else if( (j == Wbnum1 && minWbkg1 < 0.2 && WBKGplus_lep == 0) || (j == Wbnum2 && minWbkg2 < 0.2 && WBKGminus_lep == 0) ) {
                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_hadw_wcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_hadw_outwcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81) SDmass_bkg_hadw_tcut->Fill(fatjet_SDMass[j],weight); 
                                        else SDmass_bkg_hadw_outtcut->Fill(fatjet_SDMass[j],weight);
				//b
				}else if( (j == bbnum1 && minbbkg1 < 0.2) || (j == bbnum2 && minbbkg2 < 0.2) ) {
					if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_b_wcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_b_outwcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81) SDmass_bkg_b_tcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_b_outtcut->Fill(fatjet_SDMass[j],weight);
                                }else{
                                        if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_bkg_no_wcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_no_outwcut->Fill(fatjet_SDMass[j],weight);

                                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81) SDmass_bkg_no_tcut->Fill(fatjet_SDMass[j],weight);
                                        else SDmass_bkg_no_outtcut->Fill(fatjet_SDMass[j],weight);
                                }

			}else if(sig == 0 && mc == 500){
				if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81)SDmass_qcd_tcut->Fill(fatjet_SDMass[j],weight);
                                else SDmass_qcd_outtcut->Fill(fatjet_SDMass[j],weight);

                                if(fatjet_tau2[j]/fatjet_tau1[j] < 0.6) SDmass_qcd_wcut->Fill(fatjet_SDMass[j],weight);
				else SDmass_qcd_outwcut->Fill(fatjet_SDMass[j],weight);
			}						
		}


/*
		if(sig == 1 && mc == themc){
			if(numtop_sig > 0 && numW_sig > 0) topWdist_800->Fill(1,weight);
			else if(numtop_sig > 0 && numW_sig == 0) topWdist_800->Fill(2,weight);
			else if(numtop_sig == 0 && numW_sig > 0) topWdist_800->Fill(3,weight);
			else if(numtop_sig == 0 && numW_sig == 0) topWdist_800->Fill(4,weight);
		}else if(sig == 0 && mc == 103){
			if(numtop_ttbar > 0 && numW_ttbar > 0) topWdist_ttbar->Fill(1,weight);
			else if(numtop_ttbar > 0 && numW_ttbar == 0) topWdist_ttbar->Fill(2,weight);
			else if(numtop_ttbar == 0 && numW_ttbar > 0) topWdist_ttbar->Fill(3,weight);
			else if(numtop_ttbar == 0 && numW_ttbar == 0) topWdist_ttbar->Fill(4,weight);
		}else if(sig == 0 && mc == 500){
                        if(numtop_qcd > 0 && numW_qcd > 0) topWdist_qcd->Fill(1,weight);
                        else if(numtop_qcd > 0 && numW_qcd == 0) topWdist_qcd->Fill(2,weight);
                        else if(numtop_qcd == 0 && numW_qcd > 0) topWdist_qcd->Fill(3,weight);
                        else if(numtop_qcd == 0 && numW_qcd == 0) topWdist_qcd->Fill(4,weight);
                }
*/

		if(topFromH_lep == 1) continue;


		Int_t numbjets = 0;
                for(Int_t ijet = 0; ijet < TMath::Min(NJets,10) ; ijet++){
			TLorentzVector Mayb;
                        Mayb.SetPtEtaPhiE(jet_pt[ijet],jet_eta[ijet],jet_phi[ijet],jet_e[ijet]);
                        Int_t flag_over = 0;
                        for(Int_t jfjet=0; jfjet<TMath::Min(NFatJets,5); jfjet++){
                                TLorentzVector AK8j;
                                AK8j.SetPtEtaPhiE(fatjet_pt[jfjet],fatjet_eta[jfjet],fatjet_phi[jfjet],fatjet_e[jfjet]);
                                if( fatjet_tau3[jfjet]/fatjet_tau2[jfjet] < 0.81 && fatjet_SDMass[jfjet] > 105 && fatjet_SDMass[jfjet] < 220 ){ if(Mayb.DeltaR(AK8j) < 1.2) flag_over = 1; }
                        }
                        if(flag_over == 1) continue;
//                      numjets++;
			if(jet_discr[ijet] > 0.8484)numbjets++;
		}

                if(numbjets >= 3){
                        if(sig == 1 && mc == themc) {
                                nbjets_800->Fill(3,weight);
                                if(numtop_sig > 0 && numW_sig > 0) wtbchart_800->Fill(3,1,weight);
                                else if(numtop_sig > 0 && numW_sig == 0) wtbchart_800->Fill(3,2,weight);
                                else if(numtop_sig == 0 && numW_sig > 0) wtbchart_800->Fill(3,3,weight);
                                else if(numtop_sig == 0 && numW_sig == 0) wtbchart_800->Fill(3,4,weight);
                        }else if(sig == 1 && mc == smc){
                                nbjets_3000->Fill(3,weight);
                                if(numtop_3000 > 0 && numW_3000 > 0) wtbchart_3000->Fill(3,1,weight);
                                else if(numtop_3000 > 0 && numW_3000 == 0) wtbchart_3000->Fill(3,2,weight);
                                else if(numtop_3000 == 0 && numW_3000 > 0) wtbchart_3000->Fill(3,3,weight);
                                else if(numtop_3000 == 0 && numW_3000 == 0) wtbchart_3000->Fill(3,4,weight);
                        }else if(sig == 0 && mc == 103){
                                nbjets_ttbar->Fill(3,weight);
                                if(numtop_ttbar > 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(3,1,weight);
                                else if(numtop_ttbar > 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(3,2,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(3,3,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(3,4,weight);
                        }else if(sig == 0 && mc == 500){
                                nbjets_qcd->Fill(3,weight);
                                if(numtop_qcd > 0 && numW_qcd > 0) wtbchart_qcd->Fill(3,1,weight);
                                else if(numtop_qcd > 0 && numW_qcd == 0) wtbchart_qcd->Fill(3,2,weight);
                                else if(numtop_qcd == 0 && numW_qcd > 0) wtbchart_qcd->Fill(3,3,weight);
                                else if(numtop_qcd == 0 && numW_qcd == 0) wtbchart_qcd->Fill(3,4,weight);
                        }
                }else{
                        if(sig == 1 && mc == themc) {
                                nbjets_800->Fill(numbjets,weight);
                                if(numtop_sig > 0 && numW_sig > 0) wtbchart_800->Fill(numbjets,1,weight);
                                else if(numtop_sig > 0 && numW_sig == 0) wtbchart_800->Fill(numbjets,2,weight);
                                else if(numtop_sig == 0 && numW_sig > 0) wtbchart_800->Fill(numbjets,3,weight);
                                else if(numtop_sig == 0 && numW_sig == 0) wtbchart_800->Fill(numbjets,4,weight);
                        }else if(sig == 1 && mc == smc) {
                                nbjets_3000->Fill(numbjets,weight);
                                if(numtop_3000 > 0 && numW_3000 > 0) wtbchart_3000->Fill(numbjets,1,weight);
                                else if(numtop_3000 > 0 && numW_3000 == 0) wtbchart_3000->Fill(numbjets,2,weight);
                                else if(numtop_3000 == 0 && numW_3000 > 0) wtbchart_3000->Fill(numbjets,3,weight);
                                else if(numtop_3000 == 0 && numW_3000 == 0) wtbchart_3000->Fill(numbjets,4,weight);
                        }else if(sig == 0 && mc == 103) {
                                nbjets_ttbar->Fill(numbjets,weight);
                                if(numtop_ttbar > 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(numbjets,1,weight);
                                else if(numtop_ttbar > 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(numbjets,2,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(numbjets,3,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(numbjets,4,weight);
                        }else if(sig == 0 && mc == 500) {
                                nbjets_qcd->Fill(numbjets,weight);
                                if(numtop_qcd > 0 && numW_qcd > 0) wtbchart_qcd->Fill(numbjets,1,weight);
                                else if(numtop_qcd > 0 && numW_qcd == 0) wtbchart_qcd->Fill(numbjets,2,weight);
                                else if(numtop_qcd == 0 && numW_qcd > 0) wtbchart_qcd->Fill(numbjets,3,weight);
                                else if(numtop_qcd == 0 && numW_qcd == 0) wtbchart_qcd->Fill(numbjets,4,weight);
                        }
                }




/*
		if(sig == 1 && mc == themc) HT_800->Fill(ht,weight);
		else if(sig == 1 && mc == smc) HT_3000->Fill(ht,weight);
		else if(sig == 0 && mc == 103) HT_ttbar->Fill(ht,weight);
		else if(sig == 0 && mc == 500) HT_qcd->Fill(ht,weight);
*/
                if(leadingokb < 0) continue;
                TLorentzVector leadingb;
                leadingb.SetPtEtaPhiE(bjet_pt[leadingokb],bjet_eta[leadingokb],bjet_phi[leadingokb],bjet_e[leadingokb]);		

		if(leadingb.Pt() > 40. && leadingb.DeltaR(t1) > 1.2 && orderW > 0){

		  if(sig == 1 && numtop_sig == 0 && numtop_3000 == 0){
			if (mc == themc) {ndb_pt_800->Fill(bjet_pt[orderb],weight);ndW_pt_800->Fill(fatjet_pt[orderW],weight);}
                        if(t1.DeltaR(topfromhiggs) < 0.3){
                                if(mc == themc) {
					invariant_3_t_800->Fill((t1+leadingb).M(),weight);
					dr_3_t_800->Fill(leadingb.DeltaR(t1), weight);
					deleta_3_t_800->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );	 
					top_pt_3_800_yes->Fill(t1.Pt(),weight);
					top_m_3_800_yes->Fill(t1.M(),weight);
				}else if(mc == smc) {
					invariant_3_t_3000->Fill((t1+leadingb).M(),weight);
					deleta_3_t_3000->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
				}
			}else if(orderW == Wsnum1 && minWth < 0.3){
				if(mc == themc) {
					invariant_3_nt_w_800->Fill((t1+leadingb).M(),weight); 
					dr_3_nt_w_800->Fill(leadingb.DeltaR(t1), weight); 
					deleta_3_nt_w_800->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
					top_pt_3_800_no->Fill(t1.Pt(),weight);
					top_m_3_800_no->Fill(t1.M(),weight);	
				}else if(mc == smc) {
					invariant_3_nt_w_3000->Fill((t1+leadingb).M(),weight);
					deleta_3_nt_w_3000->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
				}
			}else{
				if(mc == themc) {
					invariant_3_nt_nw_800->Fill((t1+leadingb).M(),weight); 
					dr_3_nt_nw_800->Fill(leadingb.DeltaR(t1), weight); 
					deleta_3_nt_nw_800->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
					top_pt_3_800_no->Fill(t1.Pt(),weight);
					top_m_3_800_no->Fill(t1.M(),weight);	
				}else if(mc == smc) {
					invariant_3_nt_nw_3000->Fill((t1+leadingb).M(),weight);
					deleta_3_nt_nw_3000->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
				}
                        }
		  }else if(sig == 0 && mc == 103 && numtop_ttbar == 0) {
			ndb_pt_ttbar->Fill(bjet_pt[orderb],weight);
			ndW_pt_ttbar->Fill(fatjet_pt[orderW],weight);
			invariant_3_ttbar->Fill((t1+leadingb).M(),weight); 
			dr_3_ttbar->Fill(leadingb.DeltaR(t1), weight); 
			deleta_3_ttbar->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
			top_pt_3_ttbar->Fill(t1.Pt(),weight);
			top_m_3_ttbar->Fill(t1.M(),weight);
		  }else if(sig == 0 && mc == 500 && numtop_qcd == 0) {
			ndb_pt_qcd->Fill(bjet_pt[orderb],weight);
			ndW_pt_qcd->Fill(fatjet_pt[orderW],weight);
			invariant_3_qcd->Fill((t1+leadingb).M(),weight); 
			dr_3_qcd->Fill(leadingb.DeltaR(t1), weight); 
			deleta_3_qcd->Fill( fabs(t1.Eta()-leadingb.Eta()),weight );
			top_pt_3_qcd->Fill(t1.Pt(),weight);
			top_m_3_qcd->Fill(t1.M(),weight);
		  }
		}


		Double_t minpthiggs = 9999.;
                TLorentzVector thetop;
                Int_t thetop_order = -1;

                for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

			if(fatjet_pt[j] < 400.) continue;
			if(fatjet_tau2[j] == 0) continue;

                	TLorentzVector temp;
                	temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);	
			

			if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220){

				Double_t delpthiggs = (temp+leadingb).Pt();
                                if(delpthiggs < minpthiggs){
                                        minpthiggs = delpthiggs;
                                        thetop = temp;
                                        thetop_order = j;
                                }
			}
		}


		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

                        if(fatjet_pt[j] < 400.) continue;
                        if(fatjet_tau2[j] == 0) continue;

                        TLorentzVector temp;
                        temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);


                        if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220 ){

				if( temp.DeltaR(topfromhiggs) < 0.3 && j == topsnum1 ){
					debug_thb->Fill( (leadingb+temp).Pt(),weight );
					debug_th_pt->Fill(fatjet_pt[j],weight);
	//				debug_th_bsubjet->Fill(fatjet_bSubJet[j],weight);
				}else{
					debug_tb->Fill( (leadingb+temp).Pt(),weight );
                                        debug_t_pt->Fill(fatjet_pt[j],weight);
          //                              debug_t_bsubjet->Fill(fatjet_bSubJet[j],weight);
                                }
			}
		}






		if(thetop_order > 0 && leadingb.Pt() > 40.){
	
			if(sig == 1){
				if( thetop.DeltaR(topfromhiggs) < 0.3 && thetop_order == topsnum1 && leadingb.DeltaR(bfromhiggs) < 0.2 ){
					if(mc == themc) {
						invirant_800_thbh->Fill( (leadingb+thetop).M(),weight ); 
						pt_800_thbh->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_800_thbh->Fill(thetop.DeltaR(leadingb),weight );
						deleta_800_thbh->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
						top_pt_800_yes->Fill(fatjet_pt[thetop_order],weight);
						top_pt_800_cut->Fill(fatjet_pt[thetop_order],weight);
					}else if(mc == smc) {
						invirant_3000_thbh->Fill( (leadingb+thetop).M(),weight ); 
						pt_3000_thbh->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_3000_thbh->Fill(thetop.DeltaR(leadingb),weight );
					}
                               	}else if ( thetop.DeltaR(topfromhiggs) < 0.3 && thetop_order == topsnum1 ){
					if(mc == themc) {
						invirant_800_thb->Fill( (leadingb+thetop).M(),weight ); 
						pt_800_thb->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_800_thb->Fill(thetop.DeltaR(leadingb),weight );
						deleta_800_thb->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
						top_pt_800_yes->Fill(fatjet_pt[thetop_order],weight);
						top_pt_800_cut->Fill(fatjet_pt[thetop_order],weight);
					}else if(mc == smc) {
						invirant_3000_thb->Fill( (leadingb+thetop).M(),weight ); 
						pt_3000_thb->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_3000_thb->Fill(thetop.DeltaR(leadingb),weight );
					}
				}else if( leadingb.DeltaR(bfromhiggs) < 0.2 ){
                                        if(mc == themc) {
						invirant_800_tbh->Fill( (leadingb+thetop).M(),weight ); 
						pt_800_tbh->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_800_tbh->Fill(thetop.DeltaR(leadingb),weight ); 
						deleta_800_tbh->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
						top_pt_800_no->Fill(fatjet_pt[thetop_order],weight);
						top_pt_800_cut->Fill(fatjet_pt[thetop_order],weight);
					}else if(mc == smc) {
						invirant_3000_tbh->Fill( (leadingb+thetop).M(),weight ); 
						pt_3000_tbh->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_3000_tbh->Fill(thetop.DeltaR(leadingb),weight );
					}
                                }else{
					if(mc == themc) {
						invirant_800_tb->Fill( (leadingb+thetop).M(),weight ); 
						pt_800_tb->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_800_tb->Fill(thetop.DeltaR(leadingb),weight );
						deleta_800_tb->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
						top_pt_800_no->Fill(fatjet_pt[thetop_order],weight);
						top_pt_800_cut->Fill(fatjet_pt[thetop_order],weight);
					}else if(mc == smc) {
						invirant_3000_tb->Fill( (leadingb+thetop).M(),weight); 
						pt_3000_tb->Fill( (leadingb+thetop).Pt(),weight ); 
						dr_3000_tb->Fill(thetop.DeltaR(leadingb),weight );
					}
                               }

			}else if(sig == 0 && mc == 103) {
				invirant_ttbar800_tb->Fill( (leadingb+thetop).M(),weight ); 
				invirant_ttbar3000_tb->Fill( (leadingb+thetop).M(),weight ); 
				pt_ttbar_tb->Fill( (leadingb+thetop).Pt(),weight );
				dr_ttbar_tb->Fill(thetop.DeltaR(leadingb),weight );
				deleta_ttbar_tb->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
				top_pt_ttbar_cut->Fill(fatjet_pt[thetop_order],weight);
			}else if(sig == 0 && mc == 500) {
				invirant_qcd800_tb->Fill( (leadingb+thetop).M(),weight ); 
				invirant_qcd3000_tb->Fill( (leadingb+thetop).M(),weight ); 
				pt_qcd_tb->Fill( (leadingb+thetop).Pt(),weight );
				dr_qcd_tb->Fill(thetop.DeltaR(leadingb),weight );
				deleta_qcd_tb->Fill( fabs(thetop.Eta()-leadingb.Eta()),weight );
				top_pt_qcd_cut->Fill(fatjet_pt[thetop_order],weight);
			}

		}

/*
//		Int_t numjets = 0;
		Int_t numbjets = 0;
                for(Int_t ijet = 0; ijet < TMath::Min(NJets,10) ; ijet++){
                       // if (jet_discr[ijet] < 0.8484) continue;
                        TLorentzVector Mayb;
                        Mayb.SetPtEtaPhiE(jet_pt[ijet],jet_eta[ijet],jet_phi[ijet],jet_e[ijet]);
                        Int_t flag_over = 0;
                        for(Int_t jfjet=0; jfjet<TMath::Min(NFatJets,5); jfjet++){
                                TLorentzVector AK8j;
                                AK8j.SetPtEtaPhiE(fatjet_pt[jfjet],fatjet_eta[jfjet],fatjet_phi[jfjet],fatjet_e[jfjet]);
				if( fatjet_tau3[jfjet]/fatjet_tau2[jfjet] < 0.81 && fatjet_SDMass[jfjet] > 105 && fatjet_SDMass[jfjet] < 220 ){ if(Mayb.DeltaR(AK8j) < 1.2) flag_over = 1; }
                        }
                        if(flag_over == 1) continue;
//			numjets++;
			if(jet_discr[ijet] > 0.8484)numbjets++;
                }


		if(numjets >= 6){
			if(sig == 1 && mc == 11) njets_800->Fill(6,weight);
			else if(sig == 1 && mc == smc) njets_3000->Fill(6,weight);
			else if(sig == 0 && mc == 103)njets_ttbar->Fill(6,weight);
			else if(sig == 0 && mc == 500)njets_qcd->Fill(6,weight);
		}else{
			if(sig == 1 && mc == 11) njets_800->Fill(numjets,weight);
                        else if(sig == 1 && mc == smc) njets_3000->Fill(numjets,weight);
                        else if(sig == 0 && mc == 103)njets_ttbar->Fill(numjets,weight);
                        else if(sig == 0 && mc == 500)njets_qcd->Fill(numjets,weight); 
                }	


                if(numbjets >= 3){
                        if(sig == 1 && mc == themc) {
				nbjets_800->Fill(3,weight);
				if(numtop_sig > 0 && numW_sig > 0) wtbchart_800->Fill(3,1,weight);
                        	else if(numtop_sig > 0 && numW_sig == 0) wtbchart_800->Fill(3,2,weight);
                        	else if(numtop_sig == 0 && numW_sig > 0) wtbchart_800->Fill(3,3,weight);
                        	else if(numtop_sig == 0 && numW_sig == 0) wtbchart_800->Fill(3,4,weight);
			}else if(sig == 1 && mc == smc){
				nbjets_3000->Fill(3,weight);
				if(numtop_3000 > 0 && numW_3000 > 0) wtbchart_3000->Fill(3,1,weight);
                                else if(numtop_3000 > 0 && numW_3000 == 0) wtbchart_3000->Fill(3,2,weight);
                                else if(numtop_3000 == 0 && numW_3000 > 0) wtbchart_3000->Fill(3,3,weight);
                                else if(numtop_3000 == 0 && numW_3000 == 0) wtbchart_3000->Fill(3,4,weight);
                        }else if(sig == 0 && mc == 103){
				nbjets_ttbar->Fill(3,weight);
				if(numtop_ttbar > 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(3,1,weight);
                                else if(numtop_ttbar > 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(3,2,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(3,3,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(3,4,weight);
                        }else if(sig == 0 && mc == 500){
				nbjets_qcd->Fill(3,weight);
				if(numtop_qcd > 0 && numW_qcd > 0) wtbchart_qcd->Fill(3,1,weight);
                                else if(numtop_qcd > 0 && numW_qcd == 0) wtbchart_qcd->Fill(3,2,weight);
                                else if(numtop_qcd == 0 && numW_qcd > 0) wtbchart_qcd->Fill(3,3,weight);
                                else if(numtop_qcd == 0 && numW_qcd == 0) wtbchart_qcd->Fill(3,4,weight);
                        }
                }else{
                        if(sig == 1 && mc == themc) {
				nbjets_800->Fill(numbjets,weight);
				if(numtop_sig > 0 && numW_sig > 0) wtbchart_800->Fill(numbjets,1,weight);
                                else if(numtop_sig > 0 && numW_sig == 0) wtbchart_800->Fill(numbjets,2,weight);
                                else if(numtop_sig == 0 && numW_sig > 0) wtbchart_800->Fill(numbjets,3,weight);
                                else if(numtop_sig == 0 && numW_sig == 0) wtbchart_800->Fill(numbjets,4,weight);
                        }else if(sig == 1 && mc == smc) {
				nbjets_3000->Fill(numbjets,weight);
				if(numtop_3000 > 0 && numW_3000 > 0) wtbchart_3000->Fill(numbjets,1,weight);
                                else if(numtop_3000 > 0 && numW_3000 == 0) wtbchart_3000->Fill(numbjets,2,weight);
                                else if(numtop_3000 == 0 && numW_3000 > 0) wtbchart_3000->Fill(numbjets,3,weight);
                                else if(numtop_3000 == 0 && numW_3000 == 0) wtbchart_3000->Fill(numbjets,4,weight);
                        }else if(sig == 0 && mc == 103) {
				nbjets_ttbar->Fill(numbjets,weight);
				if(numtop_ttbar > 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(numbjets,1,weight);
                                else if(numtop_ttbar > 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(numbjets,2,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar > 0) wtbchart_ttbar->Fill(numbjets,3,weight);
                                else if(numtop_ttbar == 0 && numW_ttbar == 0) wtbchart_ttbar->Fill(numbjets,4,weight);
                        }else if(sig == 0 && mc == 500) {
				nbjets_qcd->Fill(numbjets,weight);
				if(numtop_qcd > 0 && numW_qcd > 0) wtbchart_qcd->Fill(numbjets,1,weight);
                                else if(numtop_qcd > 0 && numW_qcd == 0) wtbchart_qcd->Fill(numbjets,2,weight);
                                else if(numtop_qcd == 0 && numW_qcd > 0) wtbchart_qcd->Fill(numbjets,3,weight);
                                else if(numtop_qcd == 0 && numW_qcd == 0) wtbchart_qcd->Fill(numbjets,4,weight);
                        }        
		}




		if(nbig!=0){
                	if(sig == 1 && mc == 11) tau21_800_big -> Fill(tau21_big/nbig);
                        else if(sig == 1 && mc == smc) tau21_3000_big -> Fill(tau21_big/nbig);
                        else if(sig == 0) tau21_bkg_big -> Fill(tau21_big/nbig);
                }
                if(nsmall!=0){
                	if(sig == 1 && mc == 11) tau21_800_small -> Fill(tau21_small/nsmall);
                        else if(sig == 1 && mc == smc) tau21_3000_small -> Fill(tau21_small/nsmall);
                        else if(sig == 0) tau21_bkg_small -> Fill(tau21_small/nsmall);
                }

		TLorentzVector leadingb;
		leadingb.SetPtEtaPhiE(bjet_pt[0],bjet_eta[0],bjet_phi[0],bjet_e[0]);
		if(sig == 1 && mc == 11) DRWlbl_800->Fill(leadingb.DeltaR(leadingW));
		else if(sig == 1 && mc == smc) DRWlbl_3000->Fill(leadingb.DeltaR(leadingW));
		else if(sig == 0) DRWlbl_bkg->Fill(leadingb.DeltaR(leadingW));

		
		Int_t bnum = 0;
		for(Int_t ijet = 0; ijet < TMath::Min(NJets,10) ; ijet++){
                        if (jet_discr[ijet] > 0.8484) bnum++;
		}


		if(numW<2 && bnum<3){
			if(sig == 1 && mc == 11) wbchart_800->Fill(bnum,numW);
			else if(sig == 1 && mc == smc) wbchart_3000->Fill(bnum,numW);
			else if(sig == 0) wbchart_bkg->Fill(bnum,numW);
		}else if(numW>1 && bnum<3){
			if(sig == 1 && mc == 11) wbchart_800->Fill(bnum,2);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(bnum,2);
                        else if(sig == 0) wbchart_bkg->Fill(bnum,2);
                }else if(numW<2 && bnum>2){
			if(sig == 1 && mc == 11) wbchart_800->Fill(3,numW);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(3,numW);
                        else if(sig == 0) wbchart_bkg->Fill(3,numW);
                }else if(numW>1 && bnum>2){
			if(sig == 1 && mc == 11) wbchart_800->Fill(3,2);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(3,2);
                        else if(sig == 0) wbchart_bkg->Fill(3,2);
                }




                if(numW>0 && numW<3 && NBJets>0 && NBJets<3){
                        if(sig == 1 && mc == 11) wbchart_800->Fill(NBJets,numW);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(NBJets,numW);
                        else if(sig == 0) wbchart_bkg->Fill(NBJets,numW);
                }else if(numW>2 && NBJets>0 && NBJets<3){
                        if(sig == 1 && mc == 11) wbchart_800->Fill(NBJets,3);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(NBJets,3);
                        else if(sig == 0) wbchart_bkg->Fill(NBJets,3);
                }else if(numW>0 && numW<3 && NBJets>2){
                        if(sig == 1 && mc == 11) wbchart_800->Fill(3,numW);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(3,numW);
                        else if(sig == 0) wbchart_bkg->Fill(3,numW);
                }else if(numW>2 && NBJets>2){
                        if(sig == 1 && mc == 11) wbchart_800->Fill(3,3);
                        else if(sig == 1 && mc == smc) wbchart_3000->Fill(3,3);
                        else if(sig == 0) wbchart_bkg->Fill(3,3);
                }

*/




	}

	
	debug_thb->Scale(1.0/debug_thb->Integral());
	debug_th_pt->Scale(1.0/debug_th_pt->Integral());
	debug_th_bsubjet->Scale(1.0/debug_th_bsubjet->Integral());

	debug_tb->Scale(1.0/debug_tb->Integral());
	debug_t_pt->Scale(1.0/debug_t_pt->Integral());
	debug_t_bsubjet->Scale(1.0/debug_t_bsubjet->Integral());


	pt_800_thbh->Scale(1.0/pt_800_thbh->Integral());
	pt_800_thb->Scale(1.0/pt_800_thb->Integral());
	pt_800_tbh->Scale(1.0/pt_800_tbh->Integral());
	pt_800_tb->Scale(1.0/pt_800_tb->Integral());

	pt_ttbar_tb->Scale(1.0/pt_ttbar_tb->Integral());
	pt_qcd_tb->Scale(1.0/pt_qcd_tb->Integral());
	

	deleta_800_thbh->Scale(1.0/deleta_800_thbh->Integral());
	deleta_800_thb->Scale(1.0/deleta_800_thb->Integral());
	deleta_800_tbh->Scale(1.0/deleta_800_tbh->Integral());
	deleta_800_tb->Scale(1.0/deleta_800_tb->Integral());

	deleta_ttbar_tb->Scale(1.0/deleta_ttbar_tb->Integral());
	deleta_qcd_tb->Scale(1.0/deleta_qcd_tb->Integral());

	deleta_3_t_800->Scale(1.0/deleta_3_t_800->Integral());
	deleta_3_nt_w_800->Scale(1.0/deleta_3_nt_w_800->Integral());
	deleta_3_nt_nw_800->Scale(1.0/deleta_3_nt_nw_800->Integral());

	deleta_3_ttbar->Scale(1.0/deleta_3_ttbar->Integral());
	deleta_3_qcd->Scale(1.0/deleta_3_qcd->Integral());



        wtbchart_800->Scale(1.0/wtbchart_800->Integral());
	wtbchart_3000->Scale(1.0/wtbchart_3000->Integral());
	wtbchart_ttbar->Scale(1.0/wtbchart_ttbar->Integral());
	wtbchart_qcd->Scale(1.0/wtbchart_qcd->Integral());
/*
        W_pt_800->Scale(1.0/W_pt_800->Integral());
        W_pt_ttbar->Scale(1.0/W_pt_ttbar->Integral());
        W_pt_qcd->Scale(1.0/W_pt_qcd->Integral());

        top_pt_800->Scale(1.0/top_pt_800->Integral());
        top_pt_ttbar->Scale(1.0/top_pt_ttbar->Integral());
        top_pt_qcd->Scale(1.0/top_pt_qcd->Integral());

        HT_800->Scale(1.0/HT_800->Integral());
        HT_3000->Scale(1.0/HT_3000->Integral());
        HT_ttbar->Scale(1.0/HT_ttbar->Integral());
        HT_qcd->Scale(1.0/HT_qcd->Integral());


        tau21_wth->Scale(1.0/tau21_wth->Integral());
        tau21_wtass->Scale(1.0/tau21_wtass->Integral());
        tau21_wplus->Scale(1.0/tau21_wplus->Integral());
        tau21_wminus->Scale(1.0/tau21_wminus->Integral());
        tau21_w->Scale(1.0/tau21_w->Integral());
        tau21_notw->Scale(1.0/tau21_notw->Integral());
        tau21_tot->Scale(1.0/tau21_tot->Integral());

        pt_wth->Scale(1.0/pt_wth->Integral());
        pt_wtass->Scale(1.0/pt_wtass->Integral());
        pt_wplus->Scale(1.0/pt_wplus->Integral());
        pt_wminus->Scale(1.0/pt_wminus->Integral());
        pt_w->Scale(1.0/pt_w->Integral());
        pt_notw->Scale(1.0/pt_notw->Integral());
        pt_tot->Scale(1.0/pt_tot->Integral());

        tau21_800_big->Scale(1.0/tau21_800_big->Integral());
        tau21_3000_big->Scale(1.0/tau21_3000_big->Integral());
        tau21_bkg_big->Scale(1.0/tau21_bkg_big->Integral());

        tau21_800_small->Scale(1.0/tau21_800_small->Integral());
        tau21_3000_small->Scale(1.0/tau21_3000_small->Integral());
        tau21_bkg_small->Scale(1.0/tau21_bkg_small->Integral());

        DRWlbl_800->Scale(1.0/DRWlbl_800->Integral());
        DRWlbl_3000->Scale(1.0/DRWlbl_3000->Integral());
        DRWlbl_bkg->Scale(1.0/DRWlbl_bkg->Integral());

        SDmass_800_tot->Scale(1.0/SDmass_800_tot->Integral());
        SDmass_800_cut->Scale(1.0/SDmass_800_cut->Integral());
        SDmass_800_outcut->Scale(1.0/SDmass_800_outcut->Integral());

        SDmass_3000_tot->Scale(1.0/SDmass_3000_tot->Integral());
        SDmass_3000_cut->Scale(1.0/SDmass_3000_cut->Integral());
        SDmass_3000_outcut->Scale(1.0/SDmass_3000_outcut->Integral());


        DRWth_lep->Scale(1.0/DRWth_lep->Integral());
        DRWtass_lep->Scale(1.0/DRWtass_lep->Integral());
        DRWplus_lep->Scale(1.0/DRWplus_lep->Integral());
        DRWminus_lep->Scale(1.0/DRWminus_lep->Integral());

        DRWth_had_b->Scale(1.0/DRWth_had_b->Integral());
	DRWth_had_n->Scale(1.0/DRWth_had_n->Integral());
        DRWtass_had->Scale(1.0/DRWtass_had->Integral());
        DRWplus_had->Scale(1.0/DRWplus_had->Integral());
        DRWminus_had->Scale(1.0/DRWminus_had->Integral());

        DRtoph_lep->Scale(1.0/DRtoph_lep->Integral());
        DRtass_lep->Scale(1.0/DRtass_lep->Integral());
        DRtopplus_lep->Scale(1.0/DRtopplus_lep->Integral());
        DRtopminus_lep->Scale(1.0/DRtopminus_lep->Integral());

        DRtoph_had_b->Scale(1.0/DRtoph_had_b->Integral());
	DRtoph_had_n->Scale(1.0/DRtoph_had_n->Integral());
        DRtass_had->Scale(1.0/DRtass_had->Integral());
        DRtopplus_had->Scale(1.0/DRtopplus_had->Integral());
        DRtopminus_had->Scale(1.0/DRtopminus_had->Integral());

        DRPt_toph->Scale(1.0/DRPt_toph->Integral());
        DRPt_tass->Scale(1.0/DRPt_tass->Integral());
        DRPt_topplus->Scale(1.0/DRPt_topplus->Integral());
        DRPt_topminus->Scale(1.0/DRPt_topminus->Integral());

        DRPt_Wth->Scale(1.0/DRPt_Wth->Integral());
        DRPt_Wtass->Scale(1.0/DRPt_Wtass->Integral());
        DRPt_Wplus->Scale(1.0/DRPt_Wplus->Integral());
        DRPt_Wminus->Scale(1.0/DRPt_Wminus->Integral());
*/	

//	cout<<"wrong count:"<< numb_wrong << "wrong jet count:" << numnotb_wrong << ",total:" << tot << endl;

        f2->Write();
        f2->Close();

}
   
