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




void leadingb_ptcut(){

//	TFile* f1 = TFile::Open("/eos/user/h/hum/Chhiggs_tb/Apr19_z/Apr19_z.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/user/h/hum/work/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Jun_z/Jun_z.root");
//        TFile* f2 = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mass_st_bpt.root","recreate");
        TTree* t1 = (TTree*)f1->Get("tree_tb");
        
	Float_t jet_pt[20]  = {0};
        Float_t jet_eta[20] = {0};
        Float_t jet_phi[20] = {0};
        Float_t jet_e[20]   = {0};

	Float_t bjet_pt[10], bjet_eta[10], bjet_phi[10],bjet_e[10];

        Float_t jet_discr[20] ={0};

	Float_t fatjet_pt[20] ={0};
	Float_t fatjet_eta[20] ={0};
	Float_t fatjet_phi[20] ={0};
	Float_t fatjet_e[20] ={0};
	Float_t fatjet_tau1[20]={0};
	Float_t fatjet_tau2[20]={0};
	Float_t fatjet_tau3[20]={0};
	Float_t fatjet_SDMass[20]={0};	
	Int_t fatjet_bSubJet[20]={0};

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
	t1->SetBranchAddress("fatjet_bSubJet",&fatjet_bSubJet);

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


	vector<TH1D*> thbh_1000;
	vector<TH1D*> thb_1000;
	vector<TH1D*> tbh_1000;
	vector<TH1D*> tb_1000;

	vector<TH1D*> tb_ttbar;
	vector<TH1D*> tb_qcd;

	vector<TH1D*> wbb_t_1000;
	vector<TH1D*> wbb_ntw_1000;
	vector<TH1D*> wbb_ntnw_1000;

	vector<TH1D*> wbb_ttbar;
	vector<TH1D*> wbb_qcd;


	char thbhname[50];
	char thbname[50];
	char tbhname[50];
	char tbname[50];
	char ttbartbname[50];	
	char qcdtbname[50];

	char tname[50];
	char ntwname[50];
	char ntnwname[50];
	char ttbarwbbname[50];
	char qcdwbbname[50];

	for (Int_t i=0; i<21; i++) {
		sprintf(thbhname,"invariant_1000_thbh_%ibpt",20+i*5);
		sprintf(thbname,"invariant_1000_thb_%ibpt",20+i*5);
		sprintf(tbhname,"invariant_1000_tbh_%ibpt",20+i*5);
		sprintf(tbname,"invariant_1000_tb_%ibpt",20+i*5);
		sprintf(ttbartbname,"invariant_ttbar_tb_%ibpt",20+i*5);
		sprintf(qcdtbname,"invariant_qcd_tb_%ibpt",20+i*5);

		sprintf(tname,"invariant_1000_wbb_t_%ibpt",20+i*5);
		sprintf(ntwname,"invariant_1000_wbb_ntw_%ibpt",20+i*5);
		sprintf(ntnwname,"invariant_1000_wbb_ntnw_%ibpt",20+i*5);
		sprintf(ttbarwbbname,"invariant_ttbar_wbb_%ibpt",20+i*5);
		sprintf(qcdwbbname,"invariant_qcd_wbb_%ibpt",20+i*5);


		thbh_1000.push_back(new TH1D(thbhname,"",120,500,1500));
		thb_1000.push_back(new TH1D(thbname,"",120,500,1500));
		tbh_1000.push_back(new TH1D(tbhname,"",120,500,1500));
		tb_1000.push_back(new TH1D(tbname,"",120,500,1500));
		tb_ttbar.push_back(new TH1D(ttbartbname,"",120,500,1500));
		tb_qcd.push_back(new TH1D(qcdtbname,"",120,500,1500));

		wbb_t_1000.push_back(new TH1D(tname,"",120,500,1500));
		wbb_ntw_1000.push_back(new TH1D(ntwname,"",120,500,1500));
		wbb_ntnw_1000.push_back(new TH1D(ntnwname,"",120,500,1500));
		wbb_ttbar.push_back(new TH1D(ttbarwbbname,"",120,500,1500));
		wbb_qcd.push_back(new TH1D(qcdwbbname,"",120,500,1500));
	}

	TGraph* eff_tb = new TGraph(21);
        TGraph* eff_wbb = new TGraph(21);
/*
	TH1D *invirant_1000_thbh = new TH1D("invirant_1000_thbh","invirant_1000_thbh",120,500,1500);
        TH1D *invirant_1000_thb = new TH1D("invirant_1000_thb","invirant_1000_thb",120,500,1500);
        TH1D *invirant_1000_tbh = new TH1D("invirant_1000_tbh","invirant_1000_tbh",120,500,1500);
        TH1D *invirant_1000_tb = new TH1D("invirant_1000_tb","invirant_1000_tb",120,500,1500);

        TH1D *invirant_ttbar_tb = new TH1D("invirant_ttbar_tb","invirant_ttbar_tb",80,200,3600);
	TH1D *invirant_qcd_tb = new TH1D("invirant_qcd_tb","invirant_qcd_tb",80,200,3600);


	TH1D *invariant_3_t_1000= new TH1D("invariant_3_t_1000","invariant_3_t_1000",120,500,1500);
        TH1D *invariant_3_nt_w_1000 = new TH1D("invariant_3_nt_w_1000","invariant_3_nt_w_1000",120,500,1500);
        TH1D *invariant_3_nt_nw_1000 = new TH1D("invariant_3_nt_nw_1000","invariant_3_nt_nw_1000",120,500,1500);
	

	TH1D *invariant_ttbar_wbb = new TH1D("invariant_ttbar_wbb","invariant_ttbar_wbb",80,200,3600);
	TH1D *invariant_qcd_wbb = new TH1D("invariant_qcd_wbb","invariant_qcd_wbb",80,200,3600);
*/



        for(UInt_t i=0; i < t1->GetEntries(); i++) {
//	for(UInt_t i=0; i < 10000000; i++) {

                t1->GetEntry(i);

		if(ht < 800.) continue;
//		if(   ( (sig!=1) || ((mc!=11) && (mc!=14) && (mc!=7) && (mc!=9) && (mc!=12) && (mc!=13)) ) && ( (sig!=0) || ((mc!=103) && (mc!=500)) )   ) continue;
		if(   ( (sig!=1) || (mc!=12)  ) && ( (sig!=0) || ((mc!=103) && (mc!=500)) )   ) continue;
		if(NBJets == 0) continue;
		if(topFromH_lep == 1) continue;


		Int_t flag_lb[10] = {0};
		Int_t leadingokb = -1;
		for(Int_t mm = 0; mm < TMath::Min(NBJets,10); mm++){
			TLorentzVector ab;
                	ab.SetPtEtaPhiE(bjet_pt[mm],bjet_eta[mm],bjet_phi[mm],bjet_e[mm]);
			for(Int_t kfjet=0; kfjet<TMath::Min(NFatJets,5); kfjet++){
                		TLorentzVector AK8jet;
                        	AK8jet.SetPtEtaPhiE(fatjet_pt[kfjet],fatjet_eta[kfjet],fatjet_phi[kfjet],fatjet_e[kfjet]);
                        	if( fatjet_tau3[kfjet]/fatjet_tau2[kfjet] < 0.81 && fatjet_SDMass[kfjet] > 110 && fatjet_SDMass[kfjet] < 220 && fatjet_pt[kfjet] > 400. && fatjet_bSubJet[kfjet] > 0.5 ){ if(ab.DeltaR(AK8jet) < 1.2) flag_lb[mm] = 1; }
                	}
		}

		for(Int_t mm = 0; mm < TMath::Min(NBJets,10); mm++){
			if(flag_lb[mm] == 1) continue;
			leadingokb = mm; break;
		}

		if(leadingokb < 0) continue;
		TLorentzVector leadingb;
                leadingb.SetPtEtaPhiE(bjet_pt[leadingokb],bjet_eta[leadingokb],bjet_phi[leadingokb],bjet_e[leadingokb]);

		
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

                        if(fatjet_pt[j] < 200.) continue;

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



                Int_t numtop = 0;
		
		Double_t mintopmass = 999.;
		TLorentzVector w1, b1, t1;
		Int_t orderW = -1, orderb = -1;

		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

//			if(fatjet_pt[j] < 200.) continue;
			if(fatjet_tau1[j] == 0 || fatjet_tau2[j] == 0) continue;	
	
			TLorentzVector temp;
			temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);
		

			if(fatjet_pt[j] > 200. && fatjet_tau2[j]/fatjet_tau1[j] < 0.6 && fatjet_SDMass[j] > 50 && fatjet_SDMass[j] < 110 && fatjet_bSubJet[j] < 0.5  ){
				
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
			if(fatjet_pt[j] > 400. && fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 110 && fatjet_SDMass[j] < 220 && fatjet_bSubJet[j] > 0.5 ){ 
				numtop++;
                        }


				
		}


		if(leadingb.DeltaR(t1) > 1.2 && mintopmass < 65. && numtop == 0){
			
			for(Int_t k = 0; k < 21; k++){
				
				if(leadingb.Pt() > 20.+ 5.*k){
					if(sig == 1 && mc == 12){if(t1.DeltaR(topfromhiggs) < 0.3) wbb_t_1000[k]->Fill((t1+leadingb).M(),weight);}
					else if(sig == 0 && mc == 103) wbb_ttbar[k]->Fill((t1+leadingb).M(),weight);
					else if(sig == 0 && mc == 500) wbb_qcd[k]->Fill((t1+leadingb).M(),weight);
				}
			}
		}

/*			
		if(leadingb.DeltaR(t1) > 1.2 && mintopmass < 65. && numtop == 0){

		  if(sig == 1){
                        if(t1.DeltaR(topfromhiggs) < 0.3){
                                if(mc == 7) invariant_3_t_400->Fill((t1+leadingb).M(),weight);
				else if(mc == 9) invariant_3_t_500->Fill((t1+leadingb).M(),weight);
				else if(mc == 11) invariant_3_t_800->Fill((t1+leadingb).M(),weight);
				else if(mc == 12) invariant_3_t_1000->Fill((t1+leadingb).M(),weight);
				else if(mc == 13) invariant_3_t_2000->Fill((t1+leadingb).M(),weight);
				else if(mc == 14) invariant_3_t_3000->Fill((t1+leadingb).M(),weight);
			}else if(orderW == Wsnum1 && minWth < 0.3){
				if(mc == 7) invariant_3_nt_w_400->Fill((t1+leadingb).M(),weight); 
				else if(mc == 9) invariant_3_nt_w_500->Fill((t1+leadingb).M(),weight);
				else if(mc == 11) invariant_3_nt_w_800->Fill((t1+leadingb).M(),weight);
				else if(mc == 12) invariant_3_nt_w_1000->Fill((t1+leadingb).M(),weight);
				else if(mc == 13) invariant_3_nt_w_2000->Fill((t1+leadingb).M(),weight);
				else if(mc == 14) invariant_3_nt_w_3000->Fill((t1+leadingb).M(),weight);
			}else{
				if(mc == 7) invariant_3_nt_nw_400->Fill((t1+leadingb).M(),weight);
				else if(mc == 9) invariant_3_nt_nw_500->Fill((t1+leadingb).M(),weight);
				else if(mc == 11) invariant_3_nt_nw_800->Fill((t1+leadingb).M(),weight);
				else if(mc == 12) invariant_3_nt_nw_1000->Fill((t1+leadingb).M(),weight);
				else if(mc == 13) invariant_3_nt_nw_2000->Fill((t1+leadingb).M(),weight);
				else if(mc == 14) invariant_3_nt_nw_3000->Fill((t1+leadingb).M(),weight);
                        }
		  }else if(sig == 0 && mc == 103) {
			invariant_ttbar_wbb->Fill((t1+leadingb).M(),weight); 
		  }else if(sig == 0 && mc == 500) {
			invariant_qcd_wbb->Fill((t1+leadingb).M(),weight); 
		  }
		}
*/

		Double_t minpthiggs = 9999.;
		TLorentzVector thetop;
		Int_t thetop_order = -1;
                for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

			if(fatjet_pt[j] < 400.) continue;
			if(fatjet_tau2[j] == 0) continue;

                	TLorentzVector temp;
                	temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);	
			

			if(fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 110 && fatjet_SDMass[j] < 220 && fatjet_bSubJet[j] > 0.5 ){

				Double_t delpthiggs = (temp+leadingb).Pt();
				if(delpthiggs < minpthiggs){
					minpthiggs = delpthiggs;
	 				thetop = temp;
					thetop_order = j;
				}
			}
		}	

		if(thetop_order > 0){

	        	for(Int_t k = 0; k < 21; k++){

                               	if(leadingb.Pt() > 20.+ 5.*k){
                                       	if(sig == 1 && mc == 12){if(thetop.DeltaR(topfromhiggs) < 0.3 && thetop_order == topsnum1 && leadingb.DeltaR(bfromhiggs) < 0.2) thbh_1000[k]->Fill((leadingb+thetop).M(),weight);}
                                       	else if(sig == 0 && mc == 103) tb_ttbar[k]->Fill((thetop+leadingb).M(),weight);
                                       	else if(sig == 0 && mc == 500) tb_qcd[k]->Fill((thetop+leadingb).M(),weight);
                                }
                        }
		}



		/*		if(sig == 1){
					if( temp.DeltaR(topfromhiggs) < 0.3 && j == topsnum1 && leadingb.DeltaR(bfromhiggs) < 0.2 ){
						if(mc == 7) invirant_400_thbh->Fill( (leadingb+temp).M(),weight ); 
						else if(mc == 9) invirant_500_thbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 11) invirant_800_thbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 12) invirant_1000_thbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 13) invirant_2000_thbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 14) invirant_3000_thbh->Fill( (leadingb+temp).M(),weight ); 
                                	}else if ( temp.DeltaR(topfromhiggs) < 0.3 && j == topsnum1 ){
						if(mc == 7) invirant_400_thb->Fill( (leadingb+temp).M(),weight ); 
						else if(mc == 9) invirant_500_thb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 11) invirant_800_thb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 12) invirant_1000_thb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 13) invirant_2000_thb->Fill( (leadingb+temp).M(),weight );
						else if(mc == 14) invirant_3000_thb->Fill( (leadingb+temp).M(),weight ); 
					}else if( leadingb.DeltaR(bfromhiggs) < 0.2 ){
                                                if(mc == 7) invirant_400_tbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 9) invirant_500_tbh->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 11) invirant_800_tbh->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 12) invirant_1000_tbh->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 13) invirant_2000_tbh->Fill( (leadingb+temp).M(),weight );
						else if(mc == 14) invirant_3000_tbh->Fill( (leadingb+temp).M(),weight ); 
                                        }else{
						if(mc == 7) invirant_400_tb->Fill( (leadingb+temp).M(),weight );
						else if(mc == 9) invirant_500_tb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 11) invirant_800_tb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 12) invirant_1000_tb->Fill( (leadingb+temp).M(),weight );
                                                else if(mc == 13) invirant_2000_tb->Fill( (leadingb+temp).M(),weight );
						else if(mc == 14) invirant_3000_tb->Fill( (leadingb+temp).M(),weight); 
                                        }

				}else if(sig == 0 && mc == 103) {
					invirant_ttbar_tb->Fill( (leadingb+temp).M(),weight ); 
				}else if(sig == 0 && mc == 500) {
					invirant_qcd_tb->Fill( (leadingb+temp).M(),weight ); 
				}

			}

		}
*/



	}


	for(Int_t k = 0; k < 21; k++){


//		Int_t m1000low = -1, m1000up = -1;
//		Int_t m1000lowwbb = -1, m1000upwbb = -1;	

//		Double_t sig1000 = 0, ttbar1000 = 0, qcd1000 = 0;
//		Double_t sig1000wbb = 0, ttbar1000wbb = 0, qcd1000wbb = 0;

		Int_t m1000low = thbh_1000[k]->FindFirstBinAbove(thbh_1000[k]->GetMaximum()/2);
        	Int_t m1000up  = thbh_1000[k]->FindLastBinAbove(thbh_1000[k]->GetMaximum()/2);
	
		Int_t m1000lowwbb = wbb_t_1000[k]->FindFirstBinAbove(wbb_t_1000[k]->GetMaximum()/2);
        	Int_t m1000upwbb  = wbb_t_1000[k]->FindLastBinAbove(wbb_t_1000[k]->GetMaximum()/2);

		Double_t sig1000 = thbh_1000[k]->Integral(m1000low,m1000up);
		Double_t ttbar1000 = tb_ttbar[k]->Integral(m1000low,m1000up);
		Double_t qcd1000 = tb_qcd[k]->Integral(m1000low,m1000up);

		Double_t sig1000wbb = wbb_t_1000[k]->Integral(m1000lowwbb,m1000upwbb);
		Double_t ttbar1000wbb = wbb_ttbar[k]->Integral(m1000lowwbb,m1000upwbb);
		Double_t qcd1000wbb = wbb_qcd[k]->Integral(m1000lowwbb,m1000upwbb);

		eff_tb->SetPoint(k,20.+5.*k,(double)sig1000/sqrt((double)(ttbar1000+qcd1000)));
		eff_wbb->SetPoint(k,20.+5.*k,(double)sig1000wbb/sqrt((double)(ttbar1000wbb+qcd1000wbb)));
	}


	eff_tb->SetLineColor(46);
        eff_tb->SetLineWidth(2);
        eff_tb->SetMarkerColor(38);
        eff_tb->SetMarkerSize(1.5);
        eff_tb->SetMarkerStyle(21);
//        eff_tb->GetYaxis()->SetRangeUser(0,0.064);


	TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        eff_tb->Draw("ACP");

        TLegend *legend4 = new TLegend(0.72,0.72,0.98,0.96);
        legend4->AddEntry(eff_tb,"ROC tb","CP");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/effsb_leadingbcut_tb.png");

        eff_wbb->SetLineColor(46);
        eff_wbb->SetLineWidth(2);
        eff_wbb->SetMarkerColor(38);
        eff_wbb->SetMarkerSize(1.5);
        eff_wbb->SetMarkerStyle(21);
     //   eff_wbb->GetYaxis()->SetRangeUser(0,0.064);

	TCanvas *c = new TCanvas("c","c",800,600);
        c->cd(1);
        eff_wbb->Draw("ACP");

        TLegend *legend = new TLegend(0.72,0.72,0.98,0.96);
        legend->AddEntry(eff_wbb,"ROC wbb","CP");
        legend->Draw("same");

        c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/effsb_leadingbcut_wbb.png");







}
   
