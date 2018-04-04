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
#include "TPaveStats.h"
#include "TH1D.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double lumin = 35.87;

void triggerstudy(){

	setTDRStyle();

	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/isoMu.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/triggerCorpT.root");
//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/triggerv6.root");

//	TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/Baseline");
        TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
	TDirectoryFile* signal1= (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_Mu");
/*

	TH1D* ht_1000  = (TH1D*)signal->Get("HT_IsoMu24_WprimeToTB_TToHad_M-800");
	TH1D* ht_10001  = (TH1D*)signal->Get("HT_PFHT900_WprimeToTB_TToHad_M-800");
	TH1D* ht_10002  = (TH1D*)signal->Get("HT_AK8PFHT700_WprimeToTB_TToHad_M-800");
	TH1D* ht_10003  = (TH1D*)signal->Get("HT_AK8PFJet450_WprimeToTB_TToHad_M-800");
	TH1D* ht_10004  = (TH1D*)signal->Get("HT_AK8PFJet360_WprimeToTB_TToHad_M-800");
//	TH1D* ht_10001  = (TH1D*)signal->Get("fatpt_CSVp20HT_WprimeToTB_TToHad_M-800");
//        TH1D* ht_10002  = (TH1D*)signal->Get("fatpt_CSVp20_WprimeToTB_TToHad_M-800");
	TH1D* ht_10005  = (TH1D*)signal->Get("HT_CSVp56h_WprimeToTB_TToHad_M-800");
	TH1D* ht_10006  = (TH1D*)signal->Get("HT_CSVp56l_WprimeToTB_TToHad_M-800");
//	TH1D* ht_10005  = (TH1D*)signal->Get("fatpt_wide900_WprimeToTB_TToHad_M-800");
//        TH1D* ht_10006  = (TH1D*)signal->Get("fatpt_wide950_WprimeToTB_TToHad_M-800");
	TH1D* ht_or  = (TH1D*)signal->Get("HT_OR_WprimeToTB_TToHad_M-800");

*/
	TH1D* ht_1000  = (TH1D*)signal->Get("HT_IsoMu24_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10001 = (TH1D*)signal->Get("HT_PFHT900_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10002 = (TH1D*)signal->Get("HT_AK8PFHT700_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10003 = (TH1D*)signal->Get("HT_AK8PFJet450_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* ht_10004 = (TH1D*)signal->Get("HT_AK8PFJet360_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
//	TH1D* ht_10001 = (TH1D*)signal->Get("HT_CSVp20HT_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
//        TH1D* ht_10002 = (TH1D*)signal->Get("HT_CSVp20_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10005 = (TH1D*)signal->Get("HT_CSVp56h_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10006 = (TH1D*)signal->Get("HT_CSVp56l_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
//	TH1D* ht_10005 = (TH1D*)signal->Get("HT_wide900_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
//        TH1D* ht_10006 = (TH1D*)signal->Get("HT_wide950_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* ht_or   = (TH1D*)signal->Get("HT_OR_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");

/*
        TH1D* ht_1000  = (TH1D*)signal->Get("HT_IsoMu24_Data");
        TH1D* ht_10001 = (TH1D*)signal->Get("HT_PFHT900_Data");
        TH1D* ht_10002 = (TH1D*)signal->Get("HT_AK8PFHT700_Data");
        TH1D* ht_10003 = (TH1D*)signal->Get("HT_AK8PFJet450_Data");
	TH1D* ht_10004 = (TH1D*)signal->Get("HT_AK8PFJet360_Data");
	TH1D* ht_10005 = (TH1D*)signal->Get("HT_CSVp56h_Data");
        TH1D* ht_10006 = (TH1D*)signal->Get("HT_CSVp56l_Data");
        TH1D* ht_or   = (TH1D*)signal->Get("HT_OR_Data");
*/
	TGraphErrors* eff_10001 = new TGraphErrors(40);
	TGraphErrors* eff_10002 = new TGraphErrors(40);
	TGraphErrors* eff_10003 = new TGraphErrors(40);
	TGraphErrors* eff_10004 = new TGraphErrors(40);
	TGraphErrors* eff_10005 = new TGraphErrors(40);
	TGraphErrors* eff_10006 = new TGraphErrors(40);
	TGraphErrors* eff_or    = new TGraphErrors(40);

	for(int i = 0; i<40; i++){
	
		double htcut = (double)(i*20) + 400. ;  //step 20, 400-1200 for HT; 200 -1000 for fatjet_pt; step 25,400-1400 for invaM

		int lowbin = ht_1000->GetXaxis()->FindBin(htcut);
//		cout << lowbin << endl;
	
		double ded_1000 = ht_1000->Integral(lowbin,800);  //160 for fatpt, 800 for HT, 360 for invaraint mass
		double no_10001 = ht_10001->Integral(lowbin,800);
		double no_10002 = ht_10002->Integral(lowbin,800);
		double no_10003 = ht_10003->Integral(lowbin,800);
		double no_10004 = ht_10004->Integral(lowbin,800);	
		double no_10005 = ht_10005->Integral(lowbin,800);
		double no_10006 = ht_10006->Integral(lowbin,800);
		double no_or    = ht_or ->Integral(lowbin,800);	

		double p1 = no_10001/ded_1000;
		double p2 = no_10002/ded_1000;
		double p3 = no_10003/ded_1000;
		double p4 = no_10004/ded_1000;
		double p5 = no_10005/ded_1000;
		double p6 = no_10006/ded_1000;
		double por = no_or/ded_1000;
		double e1 = sqrt((1/(ded_1000*1000*lumin))*p1*(1-p1));
		double e2 = sqrt((1/(ded_1000*1000*lumin))*p2*(1-p2));
		double e3 = sqrt((1/(ded_1000*1000*lumin))*p3*(1-p3));
		double e4 = sqrt((1/(ded_1000*1000*lumin))*p4*(1-p4));
		double e5 = sqrt((1/(ded_1000*1000*lumin))*p5*(1-p5));
                double e6 = sqrt((1/(ded_1000*1000*lumin))*p6*(1-p6));
		double eor = sqrt((1/(ded_1000*1000*lumin))*por*(1-por));

		eff_10001->SetPoint(i,htcut,p1); 
		eff_10002->SetPoint(i,htcut,p2);
		eff_10003->SetPoint(i,htcut,p3);
		eff_10004->SetPoint(i,htcut,p4);
		eff_10005->SetPoint(i,htcut,p5);
                eff_10006->SetPoint(i,htcut,p6);
		eff_or   ->SetPoint(i,htcut,por);
		eff_10001->SetPointError(i,20,e1);
		eff_10002->SetPointError(i,20,e2);
		eff_10003->SetPointError(i,20,e3);
		eff_10004->SetPointError(i,20,e4);
		eff_10005->SetPointError(i,20,e5);
                eff_10006->SetPointError(i,20,e6);
		eff_or   ->SetPointError(i,20,eor);
	}


	ht_1000->Scale(10.0/ht_1000->Integral());
	ht_1000->SetLineColor(kBlue-10);
	ht_1000->SetFillColor(kBlue-10);

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
	eff_10001->GetXaxis()->SetTitle("pT_fatjet[GeV]");
	eff_10001->GetYaxis()->SetTitle("#epsilon(M-800GeV)");
	eff_10001->GetYaxis()->SetRangeUser(0,1.2);
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
	eff_10005->SetLineColor(kOrange);
        eff_10005->SetLineWidth(2);
        eff_10005->SetMarkerColor(kOrange);
        eff_10005->SetMarkerSize(1.2);
        eff_10005->SetMarkerStyle(30);
        eff_10006->SetLineColor(kGray);
        eff_10006->SetLineWidth(2);
        eff_10006->SetMarkerColor(kGray);
        eff_10006->SetMarkerSize(1.2);
        eff_10006->SetMarkerStyle(31);

	ht_1000->GetYaxis()->SetRangeUser(0,1.2);
//	ht_1000->GetXaxis()->SetRangeUser(150,1050);  //for fatPt
	ht_1000->GetXaxis()->SetRangeUser(360,1250);  //for HT-1250, for invaM-1450
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
	c1->SetGridx();
	c1->SetGridy();
	ht_1000->Draw("hist");
        eff_10001->Draw("P");
        eff_10002->Draw("P");
	eff_10003->Draw("P");
	eff_10004->Draw("P");
	eff_10005->Draw("P");
        eff_10006->Draw("P");
	eff_or->Draw("P");


        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


	TLegend *legend1 = new TLegend(0.63,0.24,0.85,0.48);
	legend1->SetFillStyle(0);
        legend1->SetBorderSize(0);
        legend1->AddEntry(eff_10001,"PFHT900","P");
        legend1->AddEntry(eff_10002,"AK8PFHT700","P");
        legend1->AddEntry(eff_10003,"Ak8PFJet450","P");
	legend1->AddEntry(eff_10004,"AK8PFJet360","P");
//	legend1->AddEntry(eff_10001,"CSVp20HT","P");
//        legend1->AddEntry(eff_10002,"CSVp20","P");
        legend1->AddEntry(eff_10005,"CSVp56h","P");
        legend1->AddEntry(eff_10006,"CSVp56l","P");
//	legend1->AddEntry(eff_10005,"wide900","P");
//        legend1->AddEntry(eff_10006,"wide950","P");
	legend1->AddEntry(eff_or,"OR","P");
	legend1->AddEntry(ht_1000,"H_{T}","f");
        legend1->Draw("same");

/*
	ht_0b->SetLineColor(46);
	ht_0b->SetLineWidth(2);
	ht_0b->GetXaxis()->SetRangeUser(800,2000);
	ht_1b->SetLineColor(38);
	ht_1b->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        ht_0b->Draw("hist");
	ht_1b->Draw("hist sames");
	c1->Update();

	TPaveStats *st0 = (TPaveStats*)ht_0b->FindObject("stats");
        st0->SetX1NDC(0.54);
        st0->SetX2NDC(0.75);
	st0->SetTextColor(46);
	st0->SetLineColor(46);
	TPaveStats *st1 = (TPaveStats*)ht_1b->FindObject("stats");
        st1->SetX1NDC(0.75);
        st1->SetX2NDC(0.96);

	c1->Modified();

        TLegend *legend1 = new TLegend(0.78,0.74,0.98,0.98);
        legend1->AddEntry(ht_0b,"Control","l");
        legend1->AddEntry(ht_1b,"Signal","l");
        legend1->Draw("same");
*/
        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar20_trigger_HT_t0b_at.png");




}
