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

void HTsovb(){

	setTDRStyle();

	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/freze1limit.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/freze0limit.root");

        TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_highj_t1b");
	TDirectoryFile* signal1= (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_one_highj_t1b");

//	TH1D* ht_1000  = (TH1D*)signal->Get("HT_IsoMu24_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* ht_10001 = (TH1D*)signal->Get("HT_1000_in_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* ht_10002 = (TH1D*)signal->Get("HT_1000_in_QCD_HT");
	TH1D* ht_or   = (TH1D*)signal->Get("HT_1000_in_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");


	TH1D* ht_10003 = (TH1D*)signal1->Get("HT_1000_in_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* ht_10004 = (TH1D*)signal1->Get("HT_1000_in_QCD_HT");
        TH1D* ht_or1   = (TH1D*)signal1->Get("HT_1000_in_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");


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
	TGraphErrors* eff_or1   = new TGraphErrors(40);
	TGraphErrors* eff_or    = new TGraphErrors(40);

	for(int i = 0; i<40; i++){
	
		double htcut = (double)(i*25) + 800. ;  //step 20, 400-1200 for HT; 200 -1000 for fatjet_pt; step 25,400-1400 for invaM

		int lowbin = ht_or->GetXaxis()->FindBin(htcut);
//		cout << lowbin << endl;
	
		double no_10001 = ht_10001->Integral(lowbin,800);
		double no_10002 = ht_10002->Integral(lowbin,800);
		double ded_1000 = no_10001 + no_10002;
		double no_or    = ht_or ->Integral(lowbin,800);	
	
		double no_10003 = ht_10003->Integral(lowbin,800);
                double no_10004 = ht_10004->Integral(lowbin,800);
                double ded_10001 = no_10003 + no_10004;
                double no_or1    = ht_or1 ->Integral(lowbin,800);


		double por = no_or/ded_1000;
		double por1 = no_or1/ded_10001;
		double eor = sqrt((1/(ded_1000*1000*lumin))*por*(1-por));
		double eor1 = sqrt((1/(ded_10001*1000*lumin))*por1*(1-por1));


		eff_or   ->SetPoint(i,htcut,por);
		eff_or   ->SetPointError(i,25,eor);
		
		eff_or1   ->SetPoint(i,htcut,por1);
                eff_or1   ->SetPointError(i,25,eor1);

	}


	ht_or->Scale(1.0/ht_or->Integral());
	ht_or->SetLineColor(kBlue-10);
	ht_or->SetFillColor(kBlue-10);

	eff_or->SetLineColor(kBlack);
	eff_or->SetLineWidth(2);
	eff_or->SetMarkerColor(kBlack);
	eff_or->SetMarkerSize(1.0);
	eff_or->SetMarkerStyle(21);

	eff_or1->SetLineColor(8);
	eff_or1->SetLineWidth(2);
	eff_or1->SetMarkerColor(8);
	eff_or1->SetMarkerSize(1.2);
	eff_or1->SetMarkerStyle(20);
//	eff_10001->GetXaxis()->SetRangeUser(0.,4000.0);
	eff_or1->GetXaxis()->SetTitle("pT_fatjet[GeV]");
	eff_or1->GetYaxis()->SetTitle("#epsilon(M-800GeV)");
	eff_or1->GetYaxis()->SetRangeUser(0,1.2);
	eff_or1->GetYaxis()->SetTitleOffset(0.8);
        
/*
	eff_10005->SetMarkerColor(kOrange);
        eff_10005->SetMarkerSize(1.2);
        eff_10005->SetMarkerStyle(30);
        eff_10006->SetLineColor(kGray);
        eff_10006->SetLineWidth(2);
        eff_10006->SetMarkerColor(kGray);
        eff_10006->SetMarkerSize(1.2);
        eff_10006->SetMarkerStyle(31);
*/
	ht_or->GetYaxis()->SetRangeUser(0,0.12);
	ht_or->GetXaxis()->SetRangeUser(760,1850);  //for HT-1250, for invaM-1450
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
	c1->SetGridx();
	c1->SetGridy();
	ht_or->Draw("hist");
        eff_or1->Draw("P");
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
        legend1->AddEntry(eff_or1,"old","P");
	legend1->AddEntry(eff_or,"new","P");
	legend1->AddEntry(ht_or,"H_{T}","f");
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
 //       c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar20_trigger_HT_t0b_at.png");




}
