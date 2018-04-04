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
const int bkgtype = 3;
const int gentype = 5;
TString bkgname[bkgtype] = {"ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8","TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","QCD_HT"};
TString bkgshort[bkgtype] = {"M-1000","tt","QCD"};
TString topname[gentype] = {"TopH_100","TopH_300","TopH_500","TopH_700","TopH_900"};
TString Wname[gentype] = {"WH_100","WH_300","WH_500","WH_700","WH_900"};
//TString topname[gentype] = {"TopH_100","TopH_300","TopH_500","TopH_700","TopH_900","TopH_1100","TopH_1200plus"};
//TString Wname[gentype] = {"WH_100","WH_300","WH_500","WH_700","WH_900","WH_1100","WH_1200plus"};


void ptnsub(){

	setTDRStyle();


	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/marcor.root");

	vector<TDirectoryFile*> signal;
	vector<TDirectoryFile*> mirror;

	signal.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b") );
        signal.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b") );
	signal.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb") );
	signal.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj") );


        mirror.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t0b") );
        mirror.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t1b") );
        mirror.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbb") );
        mirror.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbj") );



	for(int i=0; i<4; i++){

	  vector<TH1D*> signal_m;
          vector<TH1D*> mirror_m;
          vector<TH1D*> signal_tt;
          vector<TH1D*> mirror_tt;
          vector<TH1D*> signal_qcd;
          vector<TH1D*> mirror_qcd;

	  for(int j=0; j<gentype; j++){
		char haname[100];
		if(i<2) sprintf(haname,Form("%s_%s",topname[j].Data(),bkgname[0].Data()));
		else sprintf(haname,Form("%s_%s",Wname[j].Data(),bkgname[0].Data()));
		signal_m.push_back(  (TH1D*)signal[i]->Get(haname) );
		mirror_m.push_back(  (TH1D*)mirror[i]->Get(haname) );

		char hanamet[100];
                if(i<2) sprintf(hanamet,Form("%s_%s",topname[j].Data(),bkgname[1].Data()));
                else sprintf(hanamet,Form("%s_%s",Wname[j].Data(),bkgname[1].Data()));
                signal_tt.push_back(  (TH1D*)signal[i]->Get(hanamet) );
                mirror_tt.push_back(  (TH1D*)mirror[i]->Get(hanamet) );

		char hanameq[100];
                if(i<2) sprintf(hanameq,Form("%s_%s",topname[j].Data(),bkgname[2].Data()));
                else sprintf(hanameq,Form("%s_%s",Wname[j].Data(),bkgname[2].Data()));
                signal_qcd.push_back(  (TH1D*)signal[i]->Get(hanameq) );
                mirror_qcd.push_back(  (TH1D*)mirror[i]->Get(hanameq) );
	  


		signal_m[j]->Rebin(4);
                mirror_m[j]->Rebin(4);
		signal_tt[j]->Rebin(4);
		mirror_tt[j]->Rebin(4);
		signal_qcd[j]->Rebin(4);
		mirror_qcd[j]->Rebin(4);


		signal_m[j]->Scale(1.0/signal_m[j]->Integral());
		mirror_m[j]->Scale(1.0/mirror_m[j]->Integral());
		signal_tt[j]->Scale(1.0/signal_tt[j]->Integral());
		mirror_tt[j]->Scale(1.0/mirror_tt[j]->Integral());
		signal_qcd[j]->Scale(1.0/signal_qcd[j]->Integral());
		mirror_qcd[j]->Scale(1.0/mirror_qcd[j]->Integral());


		signal_m[j]->SetLineColor(kRed);
		mirror_m[j]->SetLineColor(38);
		signal_tt[j]->SetLineColor(42);
		mirror_tt[j]->SetLineColor(28);
		signal_qcd[j]->SetLineColor(8);
		mirror_qcd[j]->SetLineColor(6);

		signal_m[j]->SetLineWidth(2);
		mirror_m[j]->SetLineWidth(2);
		signal_tt[j]->SetLineWidth(2);
		mirror_tt[j]->SetLineWidth(2);
		signal_qcd[j]->SetLineWidth(2);
		mirror_qcd[j]->SetLineWidth(2);


		TCanvas *c1 = new TCanvas("c1","c1",800,600);

        	c1->cd(1);
		c1->SetGridx();
        	c1->SetGridy();
		mirror_qcd[j]->Draw("hist");
		//signal_m[j]->Draw("hist same");
		//mirror_m[j]->Draw("hist same");
        	//signal_tt[j]->Draw("hist same");
		//mirror_tt[j]->Draw("hist same");
		signal_qcd[j]->Draw("hist same");
		//mirror_qcd[j]->Draw("hist same");

		signal_m[j]->GetXaxis()->SetTitle("P_{T}[GeV]");
		signal_m[j]->GetYaxis()->SetTitle("Normalized Entries");
		signal_m[j]->GetYaxis()->SetTitleOffset(1.35);


		const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
          	TLatex latex;

		latex.SetNDC();
        	latex.SetTextSize(0.04);
       	 	latex.SetTextAlign(11);
        	latex.DrawLatex(0.68, 0.93, lumien);
        	latex.SetTextSize(0.05);
        	latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");

        	TLegend *legend1 = new TLegend(0.64,0.72,0.8,0.88);
		legend1->SetFillStyle(0);
        	legend1->SetBorderSize(0);
		legend1->SetTextFont(42);
		legend1->SetTextSize(0.03);
        	//legend1->AddEntry(signal_m[j],"SR M-1000","l");
        	//legend1->AddEntry(mirror_m[j],"CR M-1000","l");
		//legend1->AddEntry(signal_tt[j],"SR tt","l");
                //legend1->AddEntry(mirror_tt[j],"CR tt","l");
		legend1->AddEntry(signal_qcd[j],"SR qcd","l");
                legend1->AddEntry(mirror_qcd[j],"CR qcd","l");
        	legend1->Draw("same");


		char xname[500];

                sprintf(xname,"/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/2018Mar/mar1_qcd_pt%i_category_%i.png",j,i); 

        	c1->SaveAs(xname);
	  }
	}

/*
	TH1D* mass_tb_800 = (TH1D*)newtb->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* mass_tb_qcd = (TH1D*)newtb->Get("invariant_QCD_HT");
	TH1D* mass_tb_ttbar = (TH1D*)newtb->Get("invariant_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
 
	TH1D* invariant_wbb_800 = (TH1D*)newwbb->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8"); 
	TH1D* invariant_wbb_ttbar = (TH1D*)newwbb->Get("invariant_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* invariant_wbb_qcd = (TH1D*)newwbb->Get("invariant_QCD_HT");

	TH1D* b0pttb_800 = (TH1D*)tbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* b0pttb_3000 = (TH1D*)tbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* b0pttb_ttbar = (TH1D*)tbhad->Get("PtB1_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* b0pttb_qcd = (TH1D*)tbhad->Get("PtB1_QCD_HT");

	TH1D* PtAsytb_800 = (TH1D*)tbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* PtAsytb_3000 =  (TH1D*)tbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* PtAsytb_ttbar = (TH1D*)tbhad->Get("PtAsytb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* PtAsytb_qcd = (TH1D*)tbhad->Get("PtAsytb_QCD_HT");

	TH1D* dEtatb_800 =  (TH1D*)tbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* dEtatb_3000 =  (TH1D*)tbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* dEtatb_ttbar = (TH1D*)tbhad->Get("dEtatb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* dEtatb_qcd = (TH1D*)tbhad->Get("dEtatb_QCD_HT");

	TH1D* dPhitb_800 = (TH1D*)tbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	TH1D* dPhitb_3000 = (TH1D*)tbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	TH1D* dPhitb_ttbar = (TH1D*)tbhad->Get("dPhitb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	TH1D* dPhitb_qcd = (TH1D*)tbhad->Get("dPhitb_QCD_HT");


	TH1D* b0ptwbb_800 = (TH1D*)wbbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* b0ptwbb_3000 = (TH1D*)wbbhad->Get("PtB1_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* b0ptwbb_ttbar = (TH1D*)wbbhad->Get("PtB1_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* b0ptwbb_qcd = (TH1D*)wbbhad->Get("PtB1_QCD_HT");

        TH1D* PtAsywbb_800 = (TH1D*)wbbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* PtAsywbb_3000 = (TH1D*)wbbhad->Get("PtAsytb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* PtAsywbb_ttbar = (TH1D*)wbbhad->Get("PtAsytb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* PtAsywbb_qcd = (TH1D*)wbbhad->Get("PtAsytb_QCD_HT");

        TH1D* dEtawbb_800 = (TH1D*)wbbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* dEtawbb_3000 = (TH1D*)wbbhad->Get("dEtatb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dEtawbb_ttbar = (TH1D*)wbbhad->Get("dEtatb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dEtawbb_qcd = (TH1D*)wbbhad->Get("dEtatb_QCD_HT");

        TH1D* dPhiwbb_800 = (TH1D*)wbbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        TH1D* dPhiwbb_3000 = (TH1D*)wbbhad->Get("dPhitb_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        TH1D* dPhiwbb_ttbar = (TH1D*)wbbhad->Get("dPhitb_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        TH1D* dPhiwbb_qcd = (TH1D*)wbbhad->Get("dPhitb_QCD_HT");


	THStack *invariant800a = new THStack("invariant800_a","invariant800_a");
	THStack *invariant800b = new THStack("invariant800_b","invariant800_b");

	b0pttb_800->Scale(1.0/b0pttb_800->Integral());
	b0pttb_3000->Scale(1.0/b0pttb_3000->Integral());
	b0pttb_ttbar->Scale(1.0/b0pttb_ttbar->Integral());
	b0pttb_qcd->Scale(1.0/b0pttb_qcd->Integral());

	PtAsytb_800->Scale(1.0/PtAsytb_800->Integral());
	PtAsytb_3000->Scale(1.0/PtAsytb_3000->Integral());
	PtAsytb_ttbar->Scale(1.0/PtAsytb_ttbar->Integral());
	PtAsytb_qcd->Scale(1.0/PtAsytb_qcd->Integral());

	dEtatb_800->Scale(1.0/dEtatb_800->Integral());
	dEtatb_3000->Scale(1.0/dEtatb_3000->Integral());
	dEtatb_ttbar->Scale(1.0/dEtatb_ttbar->Integral());
	dEtatb_qcd->Scale(1.0/dEtatb_qcd->Integral());

	dPhitb_800->Scale(1.0/dPhitb_800->Integral());
	dPhitb_3000->Scale(1.0/dPhitb_3000->Integral());
	dPhitb_ttbar->Scale(1.0/dPhitb_ttbar->Integral());
	dPhitb_qcd->Scale(1.0/dPhitb_qcd->Integral());

	b0ptwbb_800->Scale(1.0/b0ptwbb_800->Integral());
	b0ptwbb_3000->Scale(1.0/b0ptwbb_3000->Integral());
	b0ptwbb_ttbar->Scale(1.0/b0ptwbb_ttbar->Integral());
	b0ptwbb_qcd->Scale(1.0/b0ptwbb_qcd->Integral());

	PtAsywbb_800->Scale(1.0/PtAsywbb_800->Integral());
	PtAsywbb_3000->Scale(1.0/PtAsywbb_3000->Integral());
	PtAsywbb_ttbar->Scale(1.0/PtAsywbb_ttbar->Integral());
	PtAsywbb_qcd->Scale(1.0/PtAsywbb_qcd->Integral());

	dEtawbb_800->Scale(1.0/dEtawbb_800->Integral());
	dEtawbb_3000->Scale(1.0/dEtawbb_3000->Integral());
	dEtawbb_ttbar->Scale(1.0/dEtawbb_ttbar->Integral());
	dEtawbb_qcd->Scale(1.0/dEtawbb_qcd->Integral());

	dPhiwbb_800->Scale(1.0/dPhiwbb_800->Integral());
	dPhiwbb_3000->Scale(1.0/dPhiwbb_3000->Integral());
	dPhiwbb_ttbar->Scale(1.0/dPhiwbb_ttbar->Integral());
	dPhiwbb_qcd->Scale(1.0/dPhiwbb_qcd->Integral());

	b0pttb_800->SetLineColor(46);
	b0pttb_800->SetLineWidth(2);
	b0pttb_800->GetYaxis()->SetRangeUser(0,0.034);
	b0pttb_3000->SetLineColor(42);
	b0pttb_3000->SetLineWidth(2);
	b0pttb_ttbar->SetLineColor(38);
	b0pttb_ttbar->SetLineWidth(2);
	b0pttb_qcd->SetLineColor(30);
	b0pttb_qcd->SetLineWidth(2);

	PtAsytb_800->SetLineColor(46);
	PtAsytb_800->SetLineWidth(2);
	PtAsytb_800->GetYaxis()->SetRangeUser(0,0.054);
	PtAsytb_3000->SetLineColor(42);
	PtAsytb_3000->SetLineWidth(2);
	PtAsytb_ttbar->SetLineColor(38);
	PtAsytb_ttbar->SetLineWidth(2);
	PtAsytb_qcd->SetLineColor(30);
	PtAsytb_qcd->SetLineWidth(2);

	dEtatb_800->SetLineColor(46);
	dEtatb_800->SetLineWidth(2);
	dEtatb_800->GetXaxis()->SetRangeUser(0,4.);
	dEtatb_3000->SetLineColor(42);
	dEtatb_3000->SetLineWidth(2);
	dEtatb_ttbar->SetLineColor(38);
	dEtatb_ttbar->SetLineWidth(2);
	dEtatb_qcd->SetLineColor(30);
	dEtatb_qcd->SetLineWidth(2);

	dPhitb_800->SetLineColor(46);
	dPhitb_800->SetLineWidth(2);
	dPhitb_800->GetYaxis()->SetRangeUser(0,0.1);
	dPhitb_3000->SetLineColor(42);
	dPhitb_3000->SetLineWidth(2);
	dPhitb_ttbar->SetLineColor(38);
	dPhitb_ttbar->SetLineWidth(2);
	dPhitb_qcd->SetLineColor(30);
	dPhitb_qcd->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
        c1->cd(1);
        b0pttb_800->Draw("hist");
	b0pttb_3000->Draw("hist same");
	b0pttb_ttbar->Draw("hist same");
	b0pttb_qcd->Draw("hist same");

        TLegend *legend1 = new TLegend(0.64,0.72,0.92,0.98);
        legend1->AddEntry(b0pttb_800,"800GeV,t+b","f");
        legend1->AddEntry(b0pttb_3000,"3000GeV,t+b","f");
        legend1->AddEntry(b0pttb_ttbar,"TTbar,t+b","f");
	legend1->AddEntry(b0pttb_qcd,"QCD,t+b","f");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0pttb.png");	
	
        TCanvas *c2 = new TCanvas("c2","c2",800,600);
        c2->cd(1);
	PtAsytb_800->Draw("hist");
	PtAsytb_3000->Draw("hist same");
	PtAsytb_ttbar->Draw("hist same");
	PtAsytb_qcd->Draw("hist same");

	TLegend *legend2 = new TLegend(0.64,0.72,0.92,0.98);
        legend2->AddEntry(PtAsytb_800,"800GeV,t+b","f");
        legend2->AddEntry(PtAsytb_3000,"3000GeV,t+b","f");
        legend2->AddEntry(PtAsytb_ttbar,"TTbar,t+b","f");
        legend2->AddEntry(PtAsytb_qcd,"QCD,t+b","f");
        legend2->Draw("same");

        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsytb.png");


	TCanvas *c3 = new TCanvas("c3","c3",800,600);
        c3->cd(1);
        dEtatb_800->Draw("hist");
        dEtatb_3000->Draw("hist same");
        dEtatb_ttbar->Draw("hist same");
        dEtatb_qcd->Draw("hist same");

        TLegend *legend3 = new TLegend(0.64,0.72,0.92,0.98);
        legend3->AddEntry(dEtatb_800,"800GeV,t+b","f");
        legend3->AddEntry(dEtatb_3000,"3000GeV,t+b","f");
        legend3->AddEntry(dEtatb_ttbar,"TTbar,t+b","f");
        legend3->AddEntry(dEtatb_qcd,"QCD,t+b","f");
        legend3->Draw("same");

        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtatb.png");

	TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        dPhitb_800->Draw("hist");
        dPhitb_3000->Draw("hist same");
        dPhitb_ttbar->Draw("hist same");
        dPhitb_qcd->Draw("hist same");

        TLegend *legend4 = new TLegend(0.64,0.72,0.92,0.98);
        legend4->AddEntry(dPhitb_800,"800GeV,t+b","f");
        legend4->AddEntry(dPhitb_3000,"3000GeV,t+b","f");
        legend4->AddEntry(dPhitb_ttbar,"TTbar,t+b","f");
        legend4->AddEntry(dPhitb_qcd,"QCD,t+b","f");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dPhitb.png");


	b0ptwbb_800->SetLineColor(46);
        b0ptwbb_800->SetLineWidth(2);
	b0ptwbb_800->GetYaxis()->SetRangeUser(0,0.024);
        b0ptwbb_3000->SetLineColor(42);
        b0ptwbb_3000->SetLineWidth(2);
        b0ptwbb_ttbar->SetLineColor(38);
        b0ptwbb_ttbar->SetLineWidth(2);
        b0ptwbb_qcd->SetLineColor(30);
        b0ptwbb_qcd->SetLineWidth(2);

        PtAsywbb_800->SetLineColor(46);
        PtAsywbb_800->SetLineWidth(2);
//	PtAsywbb_800->GetYaxis()->SetRangeUser(0,0.04);
        PtAsywbb_3000->SetLineColor(42);
        PtAsywbb_3000->SetLineWidth(2);
        PtAsywbb_ttbar->SetLineColor(38);
        PtAsywbb_ttbar->SetLineWidth(2);
        PtAsywbb_qcd->SetLineColor(30);
        PtAsywbb_qcd->SetLineWidth(2);

        dEtawbb_800->SetLineColor(46);
        dEtawbb_800->SetLineWidth(2);
	dEtawbb_800->GetXaxis()->SetRangeUser(0,4.);
        dEtawbb_3000->SetLineColor(42);
        dEtawbb_3000->SetLineWidth(2);
        dEtawbb_ttbar->SetLineColor(38);
        dEtawbb_ttbar->SetLineWidth(2);
        dEtawbb_qcd->SetLineColor(30);
        dEtawbb_qcd->SetLineWidth(2);

        dPhiwbb_800->SetLineColor(46);
        dPhiwbb_800->SetLineWidth(2);
	dPhiwbb_800->GetYaxis()->SetRangeUser(0,0.064);
        dPhiwbb_3000->SetLineColor(42);
        dPhiwbb_3000->SetLineWidth(2);
        dPhiwbb_ttbar->SetLineColor(38);
        dPhiwbb_ttbar->SetLineWidth(2);
        dPhiwbb_qcd->SetLineColor(30);
        dPhiwbb_qcd->SetLineWidth(2);


        TCanvas *c5 = new TCanvas("c5","c5",800,600);
        c5->cd(1);
        b0ptwbb_800->Draw("hist");
        b0ptwbb_3000->Draw("hist same");
        b0ptwbb_ttbar->Draw("hist same");
        b0ptwbb_qcd->Draw("hist same");
	

        TLegend *legend5 = new TLegend(0.64,0.72,0.92,0.98);
        legend5->AddEntry(b0pttb_800,"800GeV,w+b+b","f");
        legend5->AddEntry(b0pttb_3000,"3000GeV,W+b+b","f");
        legend5->AddEntry(b0pttb_ttbar,"TTbar,W++b","f");
        legend5->AddEntry(b0pttb_qcd,"QCD,W+b+b","f");
        legend5->Draw("same");

        c5->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0ptwbb.png");

        TCanvas *c6 = new TCanvas("c6","c6",800,600);
        c6->cd(1);
        PtAsywbb_800->Draw("hist");
        PtAsywbb_3000->Draw("hist same");
        PtAsywbb_ttbar->Draw("hist same");
        PtAsywbb_qcd->Draw("hist same");

        TLegend *legend6 = new TLegend(0.64,0.72,0.92,0.98);
        legend6->AddEntry(PtAsywbb_800,"800GeV,W+b+b","f");
        legend6->AddEntry(PtAsywbb_3000,"3000GeV,W+b+b","f");
        legend6->AddEntry(PtAsywbb_ttbar,"TTbar,W+b+b","f");
        legend6->AddEntry(PtAsywbb_qcd,"QCD,W+b+b","f");
        legend6->Draw("same");

        c6->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsywbb.png");


        TCanvas *c7 = new TCanvas("c7","c7",800,600);
        c7->cd(1);
        dEtawbb_800->Draw("hist");
        dEtawbb_3000->Draw("hist same");
        dEtawbb_ttbar->Draw("hist same");
        dEtawbb_qcd->Draw("hist same");

        TLegend *legend7 = new TLegend(0.64,0.72,0.92,0.98);
        legend7->AddEntry(dEtawbb_800,"800GeV,W+b+b","f");
        legend7->AddEntry(dEtawbb_3000,"3000GeV,W+b+b","f");
        legend7->AddEntry(dEtawbb_ttbar,"TTbar,W+b+b","f");
        legend7->AddEntry(dEtawbb_qcd,"QCD,W+b+b","f");
        legend7->Draw("same");

        c7->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtawbb.png");

        TCanvas *c8 = new TCanvas("c8","c8",800,600);
        c8->cd(1);
        dPhiwbb_800->Draw("hist");
        dPhiwbb_3000->Draw("hist same");
        dPhiwbb_ttbar->Draw("hist same");
        dPhiwbb_qcd->Draw("hist same");

        TLegend *legend8 = new TLegend(0.64,0.72,0.92,0.98);
        legend8->AddEntry(dPhiwbb_800,"800GeV,W+b+b","f");
        legend8->AddEntry(dPhiwbb_3000,"3000GeV,W+b+b","f");
        legend8->AddEntry(dPhiwbb_ttbar,"TTbar,W+b+b","f");
        legend8->AddEntry(dPhiwbb_qcd,"QCD,W+b+b","f");
        legend8->Draw("same");

        c8->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dPhiwbb.png");


	mass_tb_800->SetFillColor(46);
	mass_tb_800->Scale(1000*lumin);
	mass_tb_ttbar->SetFillColor(38);
        mass_tb_ttbar->Scale(1000*lumin);
	mass_tb_qcd->SetFillColor(30);
	mass_tb_qcd->Scale(1000*lumin);


	invariant_wbb_800->SetFillColor(kRed-7);
	invariant_wbb_800->Scale(1000*lumin);
	invariant_wbb_ttbar->SetFillColor(kBlue-9);
	invariant_wbb_ttbar->Scale(1000*lumin);
	invariant_wbb_qcd->SetFillColor(kGreen-3);
	invariant_wbb_qcd->Scale(1000*lumin);


	invariant800a->Add(mass_tb_800);	
	invariant800a->Add(mass_tb_ttbar);
	invariant800a->Add(mass_tb_qcd);

	invariant800b->Add(invariant_wbb_800);
	invariant800b->Add(invariant_wbb_ttbar);
	invariant800b->Add(invariant_wbb_qcd);




	gStyle->SetOptStat(1111);

        TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
        invariant800a->Draw("hist");
        invariant800a->GetXaxis()->SetRangeUser(400.,1200.0);
	invariant800a->GetYaxis()->SetRangeUser(1.,3000.0);

        TLegend *legend4a = new TLegend(0.64,0.72,0.92,0.98);
	legend4a->AddEntry(mass_tb_800,"800GeV,t+b","f");
        legend4a->AddEntry(mass_tb_ttbar,"TTbar,t+b","f");
	legend4a->AddEntry(mass_tb_qcd,"QCD,t+b","f");
        legend4a->Draw("same");

        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/log_tb.png");

        TCanvas *c1b = new TCanvas("c1b","c1b",800,600);
        c1b->cd(1);
        invariant800b->Draw("hist");
        invariant800b->GetXaxis()->SetRangeUser(400.,1200.0);
	invariant800b->GetYaxis()->SetRangeUser(1.,5000.0);

        TLegend *legend4b = new TLegend(0.64,0.72,0.92,0.98);
        legend4b->AddEntry(invariant_wbb_800,"800GeV,W+b+b","f");
        legend4b->AddEntry(invariant_wbb_ttbar,"TTbar,w+b+b","f");
        legend4b->AddEntry(invariant_wbb_qcd,"QCD,w+b+b","f");
        legend4b->Draw("same");

        c1b->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/log_wbb.png");
*/



}
