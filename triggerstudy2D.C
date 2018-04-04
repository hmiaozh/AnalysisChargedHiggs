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
#include "TGraph2DErrors.h"
#include "RooGlobalFunc.h"
#include "TCanvas.h"
#include "TPaveStats.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile2D.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double lumin = 35.87;

void triggerstudy2D(){

	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/triggerCorpT.root");

//	TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/Baseline");
        TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");

/*
	TH2D* ht_1000  = (TH2D*)signal->Get("fatpt_HT_IsoMu24_WprimeToTB_TToHad_M-800");
	TH2D* ht_10001  = (TH2D*)signal->Get("fatpt_HT_PFHT900_WprimeToTB_TToHad_M-800");
	TH2D* ht_10002  = (TH2D*)signal->Get("fatpt_HT_AK8PFHT700_WprimeToTB_TToHad_M-800");
	TH2D* ht_10003  = (TH2D*)signal->Get("fatpt_HT_AK8PFJet450_WprimeToTB_TToHad_M-800");
	TH2D* ht_10004  = (TH2D*)signal->Get("fatpt_HT_AK8PFJet360_WprimeToTB_TToHad_M-800");
	TH2D* ht_or  = (TH2D*)signal->Get("fatpt_HT_OR_WprimeToTB_TToHad_M-800");
*/

	TH2D* ht_1000  = (TH2D*)signal->Get("fatpt_HT_IsoMu24_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH2D* ht_10001 = (TH2D*)signal->Get("fatpt_HT_PFHT900_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH2D* ht_10002 = (TH2D*)signal->Get("fatpt_HT_AK8PFHT700_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH2D* ht_10003 = (TH2D*)signal->Get("fatpt_HT_AK8PFJet450_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH2D* ht_10004 = (TH2D*)signal->Get("fatpt_HT_AK8PFJet360_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH2D* ht_or   = (TH2D*)signal->Get("fatpt_HT_OR_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");

/*
        TH2D* ht_1000  = (TH2D*)signal->Get("HT_IsoMu24_Data");
        TH2D* ht_10001 = (TH2D*)signal->Get("HT_PFHT900_Data");
        TH2D* ht_10002 = (TH2D*)signal->Get("HT_AK8PFHT700_Data");
        TH2D* ht_10003 = (TH2D*)signal->Get("HT_AK8PFJet450_Data");
	TH2D* ht_10004 = (TH2D*)signal->Get("HT_AK8PFJet360_Data");
        TH2D* ht_or   = (TH2D*)signal->Get("HT_OR_Data");
*/
	TGraph2DErrors* eff_10001 = new TGraph2DErrors();
	TGraph2DErrors* eff_10002 = new TGraph2DErrors();
	TGraph2DErrors* eff_10003 = new TGraph2DErrors();
	TGraph2DErrors* eff_10004 = new TGraph2DErrors();
	TGraph2DErrors* eff_or    = new TGraph2DErrors();

	TProfile2D* eff2_or = new TProfile2D("eff2_or","eff2_or",20,400,1000,10,200,500);

	for(int i = 0; i<20; i++){
	  for(int j = 0; j<10; j++){
	
		double htcut = (double)(i*30) + 400. ;  //step 20 400-1200, for HT, 200 -1000 for fatjet_pt step 25,400-1400 for invaM
		double fatptcut = (double)(j*30) + 200. ; 

		int lowbinx = ht_1000->GetXaxis()->FindBin(htcut);
		int lowbiny = ht_1000->GetYaxis()->FindBin(fatptcut);
//		cout << lowbin << endl;
	
		double ded_1000 = ht_1000->Integral(lowbinx,800,lowbiny,160);  //160 for fatpt, 800 for HT, 360 for invaraint mass
//		double no_10001 = ht_10001->Integral(lowbinx,800,lowbiny,160);
//		double no_10002 = ht_10002->Integral(lowbinx,800,lowbiny,160);
//		double no_10003 = ht_10003->Integral(lowbinx,800,lowbiny,160);
//		double no_10004 = ht_10004->Integral(lowbinx,800,lowbiny,160);	
		double no_or    = ht_or ->Integral(lowbinx,800,lowbiny,160);	

//		double p1 = no_10001/ded_1000;
//		double p2 = no_10002/ded_1000;
//		double p3 = no_10003/ded_1000;
//		double p4 = no_10004/ded_1000;
		double por = no_or/ded_1000;

		eff2_or->Fill(htcut,fatptcut,por);
/*
		double e1 = sqrt((1/(ded_1000*1000*lumin))*p1*(1-p1));
		double e2 = sqrt((1/(ded_1000*1000*lumin))*p2*(1-p2));
		double e3 = sqrt((1/(ded_1000*1000*lumin))*p3*(1-p3));
		double e4 = sqrt((1/(ded_1000*1000*lumin))*p4*(1-p4));
		double eor = sqrt((1/(ded_1000*1000*lumin))*por*(1-por));

		eff_10001->SetPoint(i,htcut,fatptcut,p1); 
		eff_10002->SetPoint(i,htcut,fatptcut,p2);
		eff_10003->SetPoint(i,htcut,fatptcut,p3);
		eff_10004->SetPoint(i,htcut,fatptcut,p4);
		eff_or   ->SetPoint(i,htcut,fatptcut,por);
		eff_10001->SetPointError(i,20,20,e1);
		eff_10002->SetPointError(i,20,20,e2);
		eff_10003->SetPointError(i,20,20,e3);
		eff_10004->SetPointError(i,20,20,e4);
		eff_or   ->SetPointError(i,20,20,eor);
*/



	  }
	}

//	gStyle->SetPalette(1);
	gStyle->SetPaintTextFormat("4.2f");


/*
	eff_or->SetLineColor(kBlack);
	eff_or->SetLineWidth(2);
	eff_or->SetMarkerColor(kBlack);
	eff_or->SetMarkerSize(1.0);
	eff_or->SetMarkerStyle(21);

	eff_10001->SetLineColor(8);
	eff_10001->SetLineWidth(2);
	eff_10001->SetMarkerColor(8);
	eff_10001->SetMarkerSize(1.2);
	eff_10001->SetMarkerStyle(20);
//	eff_10001->GetXaxis()->SetRangeUser(0.,4000.0);
	eff_10001->GetXaxis()->SetTitle("HT[GeV]");
	eff_10001->GetYaxis()->SetTitle("PT_fatjet[GeV]");
	eff_10001->GetYaxis()->SetTitleOffset(0.8);
	eff_10002->SetLineColor(kRed-7);
	eff_10002->SetLineWidth(2);
	eff_10002->SetMarkerColor(kRed-7);
	eff_10002->SetMarkerSize(1.2);
	eff_10002->SetMarkerStyle(33);
	eff_10003->SetLineColor(kOrange+7);
	eff_10003->SetLineWidth(2);
	eff_10003->SetMarkerColor(kOrange+7);
	eff_10003->SetMarkerSize(1.2);
	eff_10003->SetMarkerStyle(22);
	eff_10004->SetLineColor(9);
        eff_10004->SetLineWidth(2);
	eff_10004->SetMarkerColor(9);
        eff_10004->SetMarkerSize(1.2);
        eff_10004->SetMarkerStyle(22);
*/


	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
/*
        eff_10001->Draw("P");
        eff_10002->Draw("P");
	eff_10003->Draw("P");
	eff_10004->Draw("P");
	eff_or->Draw("P");
*/

	eff2_or->Draw("COLZ TEXT");
	eff2_or->GetXaxis()->SetTitle("HT[GeV]");
        eff2_or->GetYaxis()->SetTitle("PT_fatjet[GeV]");


        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");

/*
	TLegend *legend1 = new TLegend(0.63,0.74,0.85,0.88);
        legend1->AddEntry(eff_10001,"PFHT900","P");
        legend1->AddEntry(eff_10002,"AK8PFHT700","P");
        legend1->AddEntry(eff_10003,"Ak8PFJet450","P");
	legend1->AddEntry(eff_10004,"AK8PFJet360","P");
	legend1->AddEntry(eff_or,"OR","P");
	legend1->AddEntry(ht_1000,"HT","f");
        legend1->Draw("same");
*/
        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar20_trigger2D_wbj_at.png");




}
