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

void groomedtau(){

	setTDRStyle();

//	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ChHiggs_FullHad_ORA.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/updffggall.root");

        TDirectoryFile* ff = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/Baseline");
//	TDirectoryFile* signal1= (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");


	TH1D *tau21_w = (TH1D*)ff->Get("tau21_W_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D *tau21_qcd = (TH1D*)ff->Get("tau21_none_QCD_HT");

	TH1D *tau32_top = (TH1D*)ff->Get("tau32_top_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D *tau32_qcd = (TH1D*)ff->Get("tau32_none_QCD_HT");
	

	double tot_w = tau21_w->Integral();
	double tot_q1 = tau21_qcd->Integral();
	double tot_t = tau32_top->Integral();
	double tot_q2 = tau32_qcd->Integral();

	TGraphErrors* eff_tau21 = new TGraphErrors(26);
	TGraphErrors* eff_tau32 = new TGraphErrors(26);
//	TGraphErrors* eff_10002 = new TGraphErrors(40);
//	TGraphErrors* eff_10003 = new TGraphErrors(40);


	for(int i = 0; i<26; i++){
	
		double t21cut = i*0.02 + 0.3 ;
		double t32cut = i*0.02 + 0.4 ;

		int t21bin = tau21_w->GetXaxis()->FindBin(t21cut);
		int t32bin = tau32_top->GetXaxis()->FindBin(t32cut);
//		cout << lowbin << endl;
	
		double t21W = tau21_w->Integral(1,t21bin);
		double t21Q = tau21_qcd->Integral(1,t21bin);

		double t32T = tau32_top->Integral(1,t32bin);
                double t32Q = tau32_qcd->Integral(1,t32bin);



		eff_tau21->SetPoint(i,t21W/tot_w,t21Q/tot_q1); 
		eff_tau32->SetPoint(i,t32T/tot_t,t32Q/tot_q2);
	}



	eff_tau21->SetLineColor(8);
	eff_tau21->SetLineWidth(2);
	eff_tau21->SetMarkerColor(8);
	eff_tau21->SetMarkerSize(1.5);
	eff_tau21->SetMarkerStyle(20);
//	eff_tau21->GetXaxis()->SetRangeUser(0.,4000.0);
	eff_tau21->GetXaxis()->SetTitle("Signal efficiency");
	eff_tau21->GetYaxis()->SetTitle("Background acceptance");
	eff_tau21->GetYaxis()->SetRangeUser(0,1);
	eff_tau21->GetYaxis()->SetTitleOffset(0.8);

	eff_tau32->SetLineColor(kRed-7);
	eff_tau32->SetLineWidth(2);
	eff_tau32->SetMarkerColor(kRed-7);
	eff_tau32->SetMarkerSize(1.5);
	eff_tau32->SetMarkerStyle(33);
/*
	eff_10003->SetLineWidth(2);
	eff_10003->SetMarkerColor(kOrange-3);
	eff_10003->SetMarkerSize(1.5);
	eff_10003->SetMarkerStyle(22);
	eff_10004->SetLineColor(9);
        eff_10004->SetLineWidth(2);
	eff_10004->SetMarkerColor(9);
        eff_10004->SetMarkerSize(1.5);
        eff_10004->SetMarkerStyle(22);
*/

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        eff_tau21->Draw("AP");
        eff_tau32->Draw("P");
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
        legend1->AddEntry(eff_tau21,"tau21","P");
        legend1->AddEntry(eff_tau32,"tau32","P");
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
