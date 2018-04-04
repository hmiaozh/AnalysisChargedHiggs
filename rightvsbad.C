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

void rightvsbad(){
	
	setTDRStyle();

//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/kinematic.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/refineleadb.root");

	TDirectoryFile* t0b_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tb");
	TDirectoryFile* t0hb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thb");
	TDirectoryFile* t0bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh");
	TDirectoryFile* t0hbh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");


	TDirectoryFile* t1b_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_tb");
        TDirectoryFile* t1hb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_thb");
        TDirectoryFile* t1bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_tbh");
        TDirectoryFile* t1hbh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_thbh");

	TDirectoryFile* wbj_good = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good");
	TDirectoryFile* wbj_bad = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_bad");


	TDirectoryFile* wbb_ntnw_bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_ntnw_bh");
	TDirectoryFile* wbb_ntnw_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_ntnw_nb");
	TDirectoryFile* wbb_th_bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh");
	TDirectoryFile* wbb_th_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_nb");
	TDirectoryFile* wbb_wh_bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_wh_bh");
	TDirectoryFile* wbb_wh_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_wh_nb");



	TH1D* t0b = (TH1D*)t0b_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hb = (TH1D*)t0hb_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0bh = (TH1D*)t0bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hbh = (TH1D*)t0hbh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hbh_copy = (TH1D*)t0hbh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* t1b = (TH1D*)t1b_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hb = (TH1D*)t1hb_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1bh = (TH1D*)t1bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hbh = (TH1D*)t1hbh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hbh_copy = (TH1D*)t1hbh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* good = (TH1D*)wbj_good->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");  
	TH1D* bad = (TH1D*)wbj_bad->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* good_copy = (TH1D*)wbj_good->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* ntnw_bh = (TH1D*)wbb_ntnw_bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* ntnw_nb = (TH1D*)wbb_ntnw_nb_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_bh = (TH1D*)wbb_th_bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_nb = (TH1D*)wbb_th_nb_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* wh_bh = (TH1D*)wbb_wh_bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* wh_nb = (TH1D*)wbb_wh_nb_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_bh_copy = (TH1D*)wbb_th_bh_combined->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	
	cout << "heyhey" << endl;


	//wrong
	t0b->Add(t0hb);
	t0b->Add(t0bh);
	//all
	t0hbh_copy->Add(t0b);
	//t0hbh_copy->Add(t0bh);
	//right
	//t0hbh->Add(t0bh);


	//wrong
	t1b->Add(t1hb);
        t1b->Add(t1bh);
	//all
        t1hbh_copy->Add(t1b);
	//t1hbh_copy->Add(t1bh);
	//right
	//t1hbh->Add(t1bh);


	good_copy->Add(bad);


	ntnw_nb->Add(wh_nb);
	ntnw_nb->Add(ntnw_bh);
	ntnw_nb->Add(th_nb);
	ntnw_nb->Add(wh_bh);

	th_bh_copy->Add(ntnw_nb);
	//th_bh_copy->Add(ntnw_bh);
	//th_bh_copy->Add(wh_bh);


	//th_bh->Add(wh_bh);
	//th_bh->Add(ntnw_bh);
	
        vector<TH1D*> right;	
	vector<TH1D*> wrong;

	right.push_back(t0hbh);
	right.push_back(t1hbh);
	right.push_back(th_bh);
	right.push_back(good);

	wrong.push_back(t0b);
	wrong.push_back(t1b);
	wrong.push_back(ntnw_nb);
	wrong.push_back(bad);

	for(Int_t i=0; i<4; i++) {

		Double_t sig500 = 0, ttbar500 = 0, qcd500 = 0;

		if(i<2){
		sig500 = right[i]->Integral(50,58);
		ttbar500 = wrong[i]->Integral(50,58);
		}else{
		sig500 = right[i]->Integral(51,58);
                ttbar500 = wrong[i]->Integral(51,58);
		}
		
		cout << "650: " << lumin*1000*sig500 << "\t" << lumin*1000*ttbar500 << "\t" <<sig500/ttbar500 <<endl;	
	}
}

