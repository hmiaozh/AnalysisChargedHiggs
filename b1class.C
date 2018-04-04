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

void b1class(){
	
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


	TDirectoryFile* wbb_ntnw_b_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_ntnw_bh");
	TDirectoryFile* wbb_ntnw_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_ntnw_nb");
	TDirectoryFile* wbb_th_bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh");
	TDirectoryFile* wbb_th_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_nb");
	TDirectoryFile* wbb_wh_bh_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_wh_bh");
	TDirectoryFile* wbb_wh_nb_combined = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_wh_nb");



	TH1D* t0b = (TH1D*)t0b_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hb = (TH1D*)t0hb_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0bh = (TH1D*)t0bh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hbh = (TH1D*)t0hbh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* t0hbh_copy = (TH1D*)t0hbh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* t1b = (TH1D*)t1b_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hb = (TH1D*)t1hb_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1bh = (TH1D*)t1bh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hbh = (TH1D*)t1hbh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        TH1D* t1hbh_copy = (TH1D*)t1hbh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* good = (TH1D*)wbj_good->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");  
	TH1D* bad = (TH1D*)wbj_bad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* good_copy = (TH1D*)wbj_good->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");

	TH1D* ntnw_b = (TH1D*)wbb_ntnw_b_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* ntnw_nb = (TH1D*)wbb_ntnw_nb_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_bh = (TH1D*)wbb_th_bh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_nb = (TH1D*)wbb_th_nb_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* wh_bh = (TH1D*)wbb_wh_bh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* wh_nb = (TH1D*)wbb_wh_nb_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	TH1D* th_bh_copy = (TH1D*)wbb_th_bh_combined->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	
	cout << "heyhey" << endl;
	
	//wrong
	t0b->Add(t0hb);
	//t0b->Add(t0bh);
	t0b->SetLineColor(42);
	t0b->SetLineWidth(2);
	//all
	t0hbh_copy->Add(t0b);
	t0hbh_copy->Add(t0bh);
	t0hbh_copy->SetLineColor(8);
	t0hbh_copy->SetLineWidth(2);
	//right
	t0hbh->Add(t0bh);
	t0hbh->SetLineColor(46);
	t0hbh->SetLineWidth(2);

	t0b->Rebin(2);
	t0hbh_copy->Rebin(2);
	t0hbh->Rebin(2);

	//wrong
	t1b->Add(t1hb);
        //t1b->Add(t1bh);
        t1b->SetLineColor(42);
        t1b->SetLineWidth(2);
	//all
        t1hbh_copy->Add(t1b);
	t1hbh_copy->Add(t1bh);
        t1hbh_copy->SetLineColor(8);
        t1hbh_copy->SetLineWidth(2);
	//right
	t1hbh->Add(t1bh);
        t1hbh->SetLineColor(46);
        t1hbh->SetLineWidth(2);

        t1b->Rebin(2);
        t1hbh_copy->Rebin(2);
        t1hbh->Rebin(2);





	TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
//	c1a->SetGrid();
        t0hbh_copy->Draw("hist");
        t0b->Draw("hist same");
        t0hbh->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}"; 
	TLatex latex;
	latex.SetNDC();
	latex.SetTextSize(0.04);
	latex.SetTextAlign(11);
	latex.DrawLatex(0.68, 0.93, lumien);
	latex.SetTextSize(0.05);
	latex.DrawLatex(0.12, 0.93, "cms");


//        t0hbh_copy->GetXaxis()->SetRangeUser(600.,1400.0);
        t0hbh_copy->GetXaxis()->SetTitle("P_{T} B1_{t(0)b}[GeV]");
	t0hbh_copy->GetYaxis()->SetTitle("Events");
	t0hbh_copy->GetYaxis()->SetTitleOffset(1.8);

	TLegend *legend4a = new TLegend(0.63,0.74,0.85,0.88);
        legend4a->AddEntry(t0hbh,"right combination","l");
        legend4a->AddEntry(t0b,"wrong combination","l");
        legend4a->AddEntry(t0hbh_copy,"all","l");
        legend4a->Draw("same");

	c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar24_gen_650_PtB1_t0b_new.png");


	TCanvas *c0a = new TCanvas("c0a","c0a",800,600);
        c0a->cd(1);

	t1hbh_copy->Draw("hist");
        t1b->Draw("hist same");
        t1hbh->Draw("hist same");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms");


//        t1hbh_copy->GetXaxis()->SetRangeUser(600.,1400.0);
        t1hbh_copy->GetXaxis()->SetTitle("P_{T} B1_{t(b)b}[GeV]");
        t1hbh_copy->GetYaxis()->SetTitle("Events");
	t1hbh_copy->GetYaxis()->SetTitleOffset(1.8);

        TLegend *legend41a = new TLegend(0.63,0.74,0.85,0.88);
        legend41a->AddEntry(t1hbh,"right combination","l");
        legend41a->AddEntry(t1b,"wrong combination","l");
        legend41a->AddEntry(t1hbh_copy,"all","l");
        legend41a->Draw("same");

        c0a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar24_gen_650_PtB1_t1b_new.png");


	good_copy->Add(bad);
	good_copy->SetLineColor(8);
	good_copy->SetLineWidth(2);

	good->SetLineColor(46);
	good->SetLineWidth(2);

	bad->SetLineColor(42);
	bad->SetLineWidth(2);

	good_copy->Rebin(2);
	good->Rebin(2);
	bad->Rebin(2);


	//wrong
	ntnw_nb->Add(wh_nb);
	//ntnw_nb->Add(ntnw_b);
	ntnw_nb->Add(th_nb);
	//ntnw_nb->Add(wh_bh);
	ntnw_nb->SetLineColor(42);
	ntnw_nb->SetLineWidth(2);
	//all
	th_bh_copy->Add(ntnw_nb);
	th_bh_copy->Add(ntnw_b);
	th_bh_copy->Add(wh_bh);
	th_bh_copy->SetLineColor(8);
	th_bh_copy->SetLineWidth(2);
	//good
	th_bh->Add(ntnw_b);
	th_bh->Add(wh_bh);
	th_bh->SetLineColor(46);
	th_bh->SetLineWidth(2);
	
	
	ntnw_nb->Rebin(2);
	th_bh_copy->Rebin(2);
	th_bh->Rebin(2);

	TCanvas *c1b = new TCanvas("c1b","c1b",800,600);
        c1b->cd(1);
        th_bh_copy->Draw("hist");
        th_bh->Draw("hist same");
        ntnw_nb->Draw("hist same");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "cms");


//        th_bh_copy->GetXaxis()->SetRangeUser(600.,1400.0);
        th_bh_copy->GetXaxis()->SetTitle("P_{T} B1_{Wbb}[GeV]");
        th_bh_copy->GetYaxis()->SetTitle("Events");
	th_bh_copy->GetYaxis()->SetTitleOffset(1.8);

	TLegend *legend4b = new TLegend(0.63,0.74,0.85,0.88);
        legend4b->AddEntry(th_bh,"right combination","l");
        legend4b->AddEntry(ntnw_nb,"wrong combination","l");
        legend4b->AddEntry(th_bh_copy,"all","l");
        legend4b->Draw("same");

        c1b->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar24_gen_650_PtB1_wbb_new.png");	


	TCanvas *c1bj = new TCanvas("c1bj","c1bj",800,600);
        c1bj->cd(1);
	good_copy->Draw("hist");
	good->Draw("hist same");
	bad->Draw("hist same");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.2, 0.93, "cms");

//	good_copy->GetXaxis()->SetRangeUser(600.,1400.0);
	good_copy->GetXaxis()->SetTitle("P_{T} B1_{Wbj}[GeV]");
	good_copy->GetYaxis()->SetTitle("Events");
//	good_copy->GetYaxis()->SetRangeUser(0.,0.001);
	good_copy->GetYaxis()->SetTitleOffset(1.8);

	TLegend *legend4bj = new TLegend(0.63,0.74,0.85,0.88);
        legend4bj->AddEntry(good,"right combination","l");
        legend4bj->AddEntry(bad,"wrong combination","l");
        legend4bj->AddEntry(good_copy,"all","l");
        legend4bj->Draw("same");

        c1bj->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar24_gen_650_PtB1_wbj_new.png");






//	setTDRStyle();


}
