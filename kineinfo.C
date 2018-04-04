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
const double amp = 1.2/2;


void kineinfo(){

//	gROOT->LoadMacro("tdrstyle.C");
	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/refineMtop.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/refine2Mtop.root");

	//TDirectoryFile* zerob = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/NoB");
        TDirectoryFile* signal = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
	TDirectoryFile* mirror = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");


	TH1D* ht_0b_b = (TH1D*)signal->Get("Masstbefore_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	TH1D* ht_0b_l = (TH1D*)signal->Get("Masstbefore_WprimeToTB_TToHad_M-1000");
	TH1D* ht_sr_b = (TH1D*)signal->Get("Masstbefore_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* ht_sr_l = (TH1D*)mirror->Get("Masstbefore_QCD_HT");
//	TH1D* ht_mr_b = (TH1D*)signal->Get("Masst_ST");
//	TH1D* ht_mr_l = (TH1D*)signal->Get("Masst_DYJets");

/*
	for(int i=1; i<40; i++){
	if(ht_0b_b->GetBinContent(i+1) > amp*(ht_0b_b->GetBinContent(i)+ht_0b_b->GetBinContent(i+2)))
	 ht_0b_b->SetBinContent(i+1,(ht_0b_b->GetBinContent(i)+ht_0b_b->GetBinContent(i+2))/2);
	if(ht_0b_l->GetBinContent(i+1) > amp*(ht_0b_l->GetBinContent(i)+ht_0b_l->GetBinContent(i+2)))
	ht_0b_l->SetBinContent(i+1,(ht_0b_l->GetBinContent(i)+ht_0b_l->GetBinContent(i+2))/2);
	if(ht_sr_b->GetBinContent(i+1) > amp*(ht_sr_b->GetBinContent(i)+ht_sr_b->GetBinContent(i+2)))
                        ht_sr_b->SetBinContent(i+1,(ht_sr_b->GetBinContent(i)+ht_sr_b->GetBinContent(i+2))/2);
                if(ht_sr_l->GetBinContent(i+1) > amp*(ht_sr_l->GetBinContent(i)+ht_sr_l->GetBinContent(i+2)))
                        ht_sr_l->SetBinContent(i+1,(ht_sr_l->GetBinContent(i)+ht_sr_l->GetBinContent(i+2))/2);
	}


*/
	//ht_0b_b->Rebin();
	//ht_0b_l->Rebin();
	//ht_sr_b->Rebin();
	ht_sr_l->Rebin(2);

	int m1000low = ht_sr_l->GetXaxis()->FindBin(100.);
        int m1000up  = ht_sr_l->GetXaxis()->FindBin(300.);

        cout << m1000low << "," << m1000up << endl;


	ht_0b_b->Scale(1.0/ht_0b_b->Integral());
	ht_0b_l->Scale(1.0/ht_0b_l->Integral());
	ht_sr_b->Scale(1.0/ht_sr_b->Integral());
	ht_sr_l->Scale(1.0/ht_sr_l->Integral(m1000low,m1000up));
//	ht_mr_b->Scale(1.0/ht_mr_b->Integral());
//	ht_mr_l->Scale(1.0/ht_mr_l->Integral());


	ht_0b_b->SetLineColor(kRed);
	ht_0b_b->SetLineWidth(2);
	ht_0b_l->GetXaxis()->SetRangeUser(100.,300.0);
	ht_0b_l->GetXaxis()->SetTitle("M_{top(W+b)}[GeV]");
	ht_0b_l->GetYaxis()->SetTitle("Normalized Entries");
//	ht_0b_l->GetYaxis()->SetRangeUser(0.,0.13);
	ht_0b_l->GetYaxis()->SetTitleOffset(1.8);
	ht_0b_l->SetLineColor(kRed-9);
	ht_0b_l->SetLineWidth(2);
	ht_sr_b->SetLineColor(38);
	ht_sr_b->SetLineWidth(2);
	ht_sr_l->SetLineColor(8);
	ht_sr_l->SetLineWidth(2);
//	ht_mr_b->SetLineColor(2);
//	ht_mr_b->SetLineWidth(2);
//	ht_mr_l->SetLineColor(6);
//	ht_mr_l->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
	c1->SetGridx();
        c1->SetGridy();
        ht_0b_l->Draw("hist");
        ht_0b_b->Draw("hist same");
	ht_sr_b->Draw("hist same");
	ht_sr_l->Draw("hist same");
//	ht_mr_b->Draw("hist same");
//	ht_mr_l->Draw("hist same");

        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");

	TLegend *legend1 = new TLegend(0.6,0.64,0.88,0.88);
	legend1->SetFillStyle(0);
        legend1->SetBorderSize(0);
        legend1->AddEntry(ht_0b_b,"associated,M-1000","l");
        legend1->AddEntry(ht_0b_l,"s-channel,M-1000","l");
	legend1->AddEntry(ht_sr_b,"TTBar","l");
	legend1->AddEntry(ht_sr_l,"QCD","l");
//	legend1->AddEntry(ht_mr_b,"ST","l");
//	legend1->AddEntry(ht_mr_l,"DY","l");
        legend1->Draw("same");

//	c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar28_kineinfo_Mtop_wbj_v2.png");


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
