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
#include "TH2D.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double lumin = 35.87;

void intermediate(){

	setTDRStyle();

//	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ChHiggs_FullHad_ORA.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");

        TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");
	TDirectoryFile* signal1= (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");

	TH2D* ht_10001 = (TH2D*)signal->Get("Pt_Mass_tb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH2D* ht_10002 = (TH2D*)signal1->Get("Pt_Mass_tb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH2D* ht_10003 = (TH2D*)signal1->Get("Pt_Mass_tb_QCD_HT");
	
/*
	TH1D* ht_1000  = (TH1D*)signal->Get("HT_WprimeToTB_TToHad_M-800");
        TH1D* ht_10001 = (TH1D*)signal->Get("HT_PFHT900_WprimeToTB_TToHad_M-800");
        TH1D* ht_10002 = (TH1D*)signal->Get("HT_AK8PFHT700_WprimeToTB_TToHad_M-800");
        TH1D* ht_10003 = (TH1D*)signal->Get("HT_PFJet400_WprimeToTB_TToHad_M-800");
        TH1D* ht_10004 = (TH1D*)signal->Get("HT_DiPFJet300_WprimeToTB_TToHad_M-800");	
	TH1D* ht_or   = (TH1D*)signal1->Get("HT_OR_WprimeToTB_TToHad_M-800");
*/

	TGraphErrors* eff_t0b = new TGraphErrors(10);
//	TGraphErrors* eff_10002 = new TGraphErrors(40);
//	TGraphErrors* eff_10003 = new TGraphErrors(40);

	double m1000low = ht_10001->GetXaxis()->FindBin(860.);
        double m1000up  = ht_10001->GetXaxis()->FindBin(1080.);

	for(int i = 0; i<10; i++){
	
		double htcut = (double)(i*40) + 400. ;

		int lowbin = ht_10001->GetYaxis()->FindBin(htcut);
//		cout << lowbin << endl;
	
		double no_10001 = ht_10001->Integral(m1000low,m1000up,lowbin,320);
		double no_10002 = ht_10002->Integral(m1000low,m1000up,lowbin,320);
		double no_10003 = ht_10003->Integral(m1000low,m1000up,lowbin,320);


		cout << no_10001 << "," << no_10002 << "," << no_10003 << endl;

		double p1 = no_10001/TMath::Sqrt(no_10002+no_10003);
//		double p2 = no_10002/ded_1000;
//		double p3 = no_10003/ded_1000;
//		double e1 = sqrt(ded_1000*p1*(1-p1));
//		double e2 = sqrt(ded_1000*p2*(1-p2));
//		double e3 = sqrt(ded_1000*p3*(1-p3));

		eff_t0b->SetPoint(i,htcut,p1); 
//		eff_10002->SetPoint(i,htcut,p2);
//		eff_10003->SetPoint(i,htcut,p3);
	//	eff_10001->SetPointError(i,20,e1);
	//	eff_10002->SetPointError(i,20,e2);
	//	eff_10003->SetPointError(i,20,e3);
	}



	eff_t0b->SetLineColor(8);
	eff_t0b->SetLineWidth(2);
	eff_t0b->SetMarkerColor(8);
	eff_t0b->SetMarkerSize(1.5);
	eff_t0b->SetMarkerStyle(20);
//	eff_10001->GetXaxis()->SetRangeUser(0.,4000.0);
/*	eff_10001->GetXaxis()->SetTitle("HT_cut[GeV]");
	eff_10001->GetYaxis()->SetTitle("#epsilon(M-800GeV)");
	eff_10001->GetYaxis()->SetRangeUser(0,1.2);
	eff_10001->GetYaxis()->SetTitleOffset(0.8);
	eff_10002->SetLineColor(kRed-7);
	eff_10002->SetLineWidth(2);
	eff_10002->SetMarkerColor(kRed-7);
	eff_10002->SetMarkerSize(1.5);
	eff_10002->SetMarkerStyle(33);
	eff_10003->SetLineColor(kOrange-3);
	eff_10003->SetLineWidth(2);
	eff_10003->SetMarkerColor(kOrange-3);
	eff_10003->SetMarkerSize(1.5);
	eff_10003->SetMarkerStyle(22);
	eff_10004->SetLineColor(9);
        eff_10004->SetLineWidth(2);
	eff_10004->SetMarkerColor(9);
        eff_10004->SetMarkerSize(1.5);
        eff_10004->SetMarkerStyle(22);

	ht_1000->GetYaxis()->SetRangeUser(0,1.2);
	ht_1000->GetXaxis()->SetRangeUser(360,1250);
*/
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        eff_t0b->Draw("AP");
//        eff_10002->Draw("P");
//	eff_10003->Draw("P");
//	eff_10004->Draw("P");


        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


	TLegend *legend1 = new TLegend(0.63,0.74,0.85,0.88);
        legend1->AddEntry(eff_t0b,"PFHT900","P");
//        legend1->AddEntry(eff_10002,"AK8PFHT700","P");
  //      legend1->AddEntry(eff_10003,"PFJet400","P");
//	legend1->AddEntry(eff_10004,"DiPFJet300","P");
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
//        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/mirror_ht.png");
/*
	mass_wcut_0b->Scale(1.0/mass_wcut_0b->Integral());
	mass_outwcut_0b->Scale(1.0/mass_outwcut_0b->Integral());
	mass_tcut_0b->Scale(1.0/mass_tcut_0b->Integral());
	mass_outtcut_0b->Scale(1.0/mass_outtcut_0b->Integral());

	toppt_0b->Scale(1.0/toppt_0b->Integral());
	Wpt_0b->Scale(1.0/Wpt_0b->Integral());
	tau21_in_0b->Scale(1.0/tau21_in_0b->Integral());

	tau32_in_0b->Scale(1.0/tau32_in_0b->Integral());

        mass_wcut_1b->Scale(1.0/mass_wcut_1b->Integral());
        mass_outwcut_1b->Scale(1.0/mass_outwcut_1b->Integral());
        mass_tcut_1b->Scale(1.0/mass_tcut_1b->Integral());
        mass_outtcut_1b->Scale(1.0/mass_outtcut_1b->Integral());

        toppt_1b->Scale(1.0/toppt_1b->Integral());
        Wpt_1b->Scale(1.0/Wpt_1b->Integral());
        tau21_in_1b->Scale(1.0/tau21_in_1b->Integral());

        tau32_in_1b->Scale(1.0/tau32_in_1b->Integral());


	mass_wcut_0b->SetLineColor(46);
	mass_wcut_0b->SetLineWidth(2);
	mass_wcut_0b->GetYaxis()->SetRangeUser(0,0.06);
	mass_wcut_1b->SetLineColor(38);
	mass_wcut_1b->SetLineWidth(2);

	mass_outwcut_0b->SetLineColor(46);
	mass_outwcut_0b->SetLineWidth(2);
//	mass_outwcut_0b->GetYaxis()->SetRangeUser(0,0.054);
	mass_outwcut_1b->SetLineColor(38);
	mass_outwcut_1b->SetLineWidth(2);

	mass_tcut_0b->SetLineColor(46);
	mass_tcut_0b->SetLineWidth(2);
//	mass_tcut_0b->GetXaxis()->SetRangeUser(0,4.);
	mass_tcut_1b->SetLineColor(38);
	mass_tcut_1b->SetLineWidth(2);

        mass_outtcut_0b->SetLineColor(46);
        mass_outtcut_0b->SetLineWidth(2);
//      mass_outtcut_0b->GetXaxis()->SetRangeUser(0,4.);
	mass_outtcut_1b->SetLineColor(38);
        mass_outtcut_1b->SetLineWidth(2);



	toppt_0b->SetLineColor(46);
	toppt_0b->SetLineWidth(2);
//	toppt_0b->GetYaxis()->SetRangeUser(0,0.1);
	toppt_1b->SetLineColor(38);
	toppt_1b->SetLineWidth(2);

        Wpt_0b->SetLineColor(46);
        Wpt_0b->SetLineWidth(2);
//        Wpt_0b->GetYaxis()->SetRangeUser(0,0.1);
        Wpt_1b->SetLineColor(38);
        Wpt_1b->SetLineWidth(2);


	tau21_in_0b->SetLineColor(46);
        tau21_in_0b->SetLineWidth(2);
        tau21_in_0b->GetYaxis()->SetRangeUser(0,0.035);
        tau21_in_1b->SetLineColor(38);
        tau21_in_1b->SetLineWidth(2);


	tau32_in_0b->SetLineColor(46);
        tau32_in_0b->SetLineWidth(2);
        tau32_in_0b->GetYaxis()->SetRangeUser(0,0.07);
        tau32_in_1b->SetLineColor(38);
        tau32_in_1b->SetLineWidth(2);



	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        mass_wcut_0b->Draw("hist");
	mass_wcut_1b->Draw("hist same");

        TLegend *legend1 = new TLegend(0.7,0.72,0.98,0.98);
        legend1->AddEntry(mass_wcut_0b,"Control","l");
        legend1->AddEntry(mass_wcut_1b,"Signal","l");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_sdmass_wcut.png");	
	
        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
	mass_outwcut_0b->Draw("hist");
	mass_outwcut_1b->Draw("hist same");

	TLegend *legend2 = new TLegend(0.7,0.72,0.98,0.98);
        legend2->AddEntry(mass_outwcut_0b,"Control","l");
        legend2->AddEntry(mass_outwcut_1b,"Signal","l");
        legend2->Draw("same");

        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_sdmass_outwcut.png");


	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        mass_tcut_0b->Draw("hist");
        mass_tcut_1b->Draw("hist same");

        TLegend *legend3 = new TLegend(0.7,0.72,0.98,0.98);
        legend3->AddEntry(mass_tcut_0b,"Control","l");
        legend3->AddEntry(mass_tcut_1b,"Signal","l");
        legend3->Draw("same");

        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_sdmass_tcut.png");

	TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        mass_outtcut_0b->Draw("hist");
        mass_outtcut_1b->Draw("hist same");

        TLegend *legend4 = new TLegend(0.7,0.72,0.98,0.98);
        legend4->AddEntry(mass_outtcut_0b,"Control","l");
        legend4->AddEntry(mass_outtcut_1b,"Signal","l");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_sdmass_outtcut.png");


	TCanvas *c5 = new TCanvas("c5","c5",800,600);
        c5->cd(1);
        toppt_0b->Draw("hist");
        toppt_1b->Draw("hist same");
	

        TLegend *legend5 = new TLegend(0.7,0.72,0.98,0.98);
        legend5->AddEntry(toppt_0b,"Control","l");
        legend5->AddEntry(toppt_1b,"Signal","l");
        legend5->Draw("same");

        c5->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_toppt.png");

        TCanvas *c6 = new TCanvas("c6","c6",800,600);
        c6->cd(1);
        Wpt_0b->Draw("hist");
        Wpt_1b->Draw("hist same");

        TLegend *legend6 = new TLegend(0.7,0.72,0.98,0.98);
        legend6->AddEntry(Wpt_0b,"Control","l");
        legend6->AddEntry(Wpt_1b,"Signal","l");
        legend6->Draw("same");

        c6->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_wpt.png");


        TCanvas *c7 = new TCanvas("c7","c7",800,600);
        c7->cd(1);
        tau21_in_0b->Draw("hist");
        tau21_in_1b->Draw("hist same");

        TLegend *legend7 = new TLegend(0.7,0.72,0.98,0.98);
        legend7->AddEntry(tau21_in_0b,"control","l");
        legend7->AddEntry(tau21_in_1b,"signal","l");
        legend7->Draw("same");

        c7->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_tau21.png");

        TCanvas *c8 = new TCanvas("c8","c8",800,600);
        c8->cd(1);
        tau32_in_0b->Draw("hist");
        tau32_in_1b->Draw("hist same");

        TLegend *legend8 = new TLegend(0.7,0.72,0.98,0.98);
        legend8->AddEntry(tau32_in_0b,"Control","l");
        legend8->AddEntry(tau32_in_1b,"Signal","l");
        legend8->Draw("same");

        c8->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/cs_tau32.png");

*/




}
