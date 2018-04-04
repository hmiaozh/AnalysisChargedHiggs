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
#include "TH2D.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
const char *cmsl = "CMS #scale[0.8]{#bf{#it{internal}}}";

const double lumin = 5.768;
//const double lumin = 2.546;
const double extra = 1;
const double scaf = 1000.*lumin;
const double scafqcd = 1000.*lumin;

const int bkgtype = 13;
const int proalltype = 11;
const int prosepatype = 6;
const int colorbkg[bkgtype] = {kBlue-9,kGreen+3,kGreen-6,kGreen-10,kOrange+7,kOrange+1,kOrange-9,kYellow-10,kOrange-2,kRed+1,kGray,kGray+3,kCyan+4};
TString bkgname[bkgtype] = {"TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","QCD_HT100to200","QCD_HT200to300","QCD_HT300to500","QCD_HT500to700","QCD_HT700to1000","QCD_HT1000to1500","QCD_HT1500to2000","QCD_HT2000toInf","DYJetsToLL_M-50_HT","WJetsToLNu_HT","WJetsToQQ_HT","ZJetsToNuNu_HT"};
TString bkgshort[bkgtype] = {"ttbar","QCD1","QCD2","QCD3","QCD4","QCD5","QCD6","QCD7","QCD8","DY","WJetsLNu","WJetsNuNu","ZNuNu"};
TString proname[proalltype] = {"HT","NBjets","Njets","NFatjets","Met","SDMass","top_pt","W_pt","fat_pt","tau32","tau21"};
//TString prosepaname[prosepatype] = {"ST","HT","invariantExt","num_lo_bj","num_lo_j","num_lo_fj","top_pt","W_pt","TAU32","TAU21","PtTopH","PtB1","softdropM"};
TString prosepaname[prosepatype] = {"Discr_100","Discr_300","Discr_500","Discr_700","Discr_900","Discr_1100"};

void datamc(){
	
	setTDRStyle();



	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/btagcheck.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/confildata1.root");

	TDirectoryFile* all = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/NoBOneW");
	TDirectoryFile* allbug = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/NoBOneW");
	TDirectoryFile* tb[4];
	TDirectoryFile* tbbug[4];
	tb[0] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t0b");
	tb[1] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t1b");
	tb[2] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbb");
	tb[3] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbj");
/*
	tbbug[0] = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t0b");
        tbbug[1] = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t1b");
        tbbug[2] = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbb");
        tbbug[3] = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbj");
*/

	for(int i=0; i<proalltype; i++){
		if(i==6 || i==7) continue;
//if(i>=5) continue;
		THStack *ths_all = new THStack(proname[i],proname[i]);
		TH1D* hbkg;
		TH1D* ht[bkgtype];
		TH1D* ht_data= (TH1D*)allbug->Get(Form("%s_Data",proname[i].Data()));
		if(i==0)ht_data->Rebin(8);
		else if(i>=6)ht_data->Rebin(4);
		ht_data->SetMarkerColor(1);
                ht_data->SetLineColor(1);
                ht_data->SetMarkerSize(1);
                ht_data->SetMarkerStyle(20);
		for(int j=0; j<bkgtype; j++){
//			cout << "nani:" << j << endl;
			if(j==1 || j==2 || j==3 ) continue;
			ht[j] = (TH1D*)all->Get(Form("%s_%s",proname[i].Data(),bkgname[j].Data()));
			if(j==0)hbkg = (TH1D*)ht[j]->Clone("hbkg");
                        else hbkg->Add(ht[j]);
			if(i==0)ht[j]->Rebin(8);
			else if(i>=6)ht[j]->Rebin(4);
			ht[j]->SetFillColor(colorbkg[j]);
			ht[j]->SetLineColor(colorbkg[j]);
			ht[j]->Scale(scaf);
			ths_all->Add(ht[j]);
		}
		if(i==0)hbkg->Rebin(8);
		else if(i>=6)hbkg->Rebin(4);
		hbkg->Scale(scaf);

		TCanvas *c1 = new TCanvas("c1","c1",800,1000);
		TPad *pad_up = new TPad("pad_up", "pad_up", 0., 0.2, 1., 1.);
        	TPad *pad_dn = new TPad("pad_dn", "pad_dn", 0., 0., 1., 0.2);

//		pad_up->SetTopMargin(0.05);
        	pad_up->SetBottomMargin(0);
//        	pad_up->SetLeftMargin(0.15);
//        	pad_up->SetRightMargin(0.05);
        	pad_up->SetTickx(1);
        	pad_up->SetTicky(1);
		pad_up->SetLogy();

        	pad_dn->SetTopMargin(0);
        	pad_dn->SetBottomMargin(0.50);
//        	pad_dn->SetLeftMargin(0.15);
//        	pad_dn->SetRightMargin(0.05);
        	pad_dn->SetTickx(1);
        	pad_dn->SetTicky(1);

		pad_up->Draw();
        	pad_up->cd();

        //	c1->cd(1);
        	ths_all->Draw("hist");
        	ths_all->GetYaxis()->SetTitle("Events");
		ht_data->Draw("P E X0 SAME");

		TLatex latex;
        	latex.SetNDC();
        	latex.SetTextSize(0.04);
        	latex.SetTextAlign(11);
        	latex.DrawLatex(0.68, 0.93, lumien);
        	latex.SetTextSize(0.05);
        	latex.DrawLatex(0.12, 0.93, cmsl);

        	TLegend *legend1 = new TLegend(0.63,0.7,0.87,0.9);
        	legend1->AddEntry(ht_data,"Data","PE");
		for(int j=0; j<bkgtype; j++){
			if(j==1 || j==2 || j==3 ) continue;
        		legend1->AddEntry(ht[j],bkgshort[j],"f");
		}
		legend1->Draw("same");

		c1->cd();
		pad_dn->Draw();
        	pad_dn->cd();
        	pad_dn->SetGridy();


		TH1D* hRatio = (TH1D*)ht_data->Clone("hRatio");
		hRatio->Divide(hbkg);
//		for(int q = 0; q < 60; q++)
//			cout << "QCDHTReweighting spline " << (q+1)*80. << " " << hRatio->GetBinContent(q+1) << " " << 0 << endl;
		hRatio->GetXaxis()->SetTitle(proname[i]);
		hRatio->GetYaxis()->SetTitle("Data/MC");
		hRatio->GetYaxis()->SetLabelFont(43);
		hRatio->GetYaxis()->SetRangeUser(0.4,1.6);
		hRatio->GetYaxis()->SetTitleOffset(2.0);
        	hRatio->GetXaxis()->SetTitleOffset(5.0);
        	hRatio->GetXaxis()->SetLabelFont(43);
        	hRatio->GetYaxis()->SetTitleFont(43);
        	hRatio->GetXaxis()->SetTitleFont(43);
        	hRatio->GetYaxis()->SetLabelSize(16);
        	hRatio->GetXaxis()->SetLabelSize(20);
        	hRatio->GetYaxis()->SetTitleSize(24);
        	hRatio->GetXaxis()->SetTitleSize(24);
//		hRatio->GetYaxis()->SetNdivisions(502);
		hRatio->Draw("P E X0 SAME");	

		c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/Nov17/nov13_QCDcontrol_0b1w_%s.png",proname[i].Data()));
	}
/*
      for(int k=0; k<4; k++){
	for(int i=0; i<prosepatype; i++){
//		if( i==0 || i==6 || i==7) continue;
//     		if( (k==0 || k==1) && (i==7 || i ==9)) continue;
//		if( (k==2 || k==3) && (i==6 || i ==8)) continue;  
                THStack *ths_all = new THStack(prosepaname[i],prosepaname[i]);
		TH1D* hbkg;
                TH1D* ht[bkgtype];
                TH1D* ht_data= (TH1D*)tb[k]->Get(Form("%s_Data",prosepaname[i].Data()));
		if(ht_data == NULL) continue;
//                if(i==0 || i==1 || i==2)ht_data->Rebin(8);
//		else if(i>=6 && i<12) ht_data->Rebin(4);  
		ht_data->Rebin(4);
                ht_data->SetMarkerColor(1);
                ht_data->SetLineColor(1);
                ht_data->SetMarkerSize(1);
                ht_data->SetMarkerStyle(20);
                for(int j=0; j<bkgtype; j++){
//			if(j==1 || j==2 || j==3) continue;
                        ht[j] = (TH1D*)tb[k]->Get(Form("%s_%s",prosepaname[i].Data(),bkgname[j].Data()));
			if(ht[j] == NULL) continue;
			if(j==0)hbkg = (TH1D*)ht[j]->Clone("hbkg");
                	else hbkg->Add(ht[j]);
//                        if(i==0 || i==1 || i==2)ht[j]->Rebin(8);
//			else if(i>=6 && i<12) ht[j]->Rebin(4);  
			ht[j]->Rebin(4);
                        ht[j]->SetFillColor(colorbkg[j]);
                        ht[j]->SetLineColor(colorbkg[j]);
			ht[j]->Scale(scaf);
                        ths_all->Add(ht[j]);
                }
//		if(i==0 || i==1 || i==2)hbkg->Rebin(8);
//                else if(i>=6 && i <12)hbkg->Rebin(4); 
		hbkg->Rebin(4);
		hbkg->Scale(scaf);

                TCanvas *c1 = new TCanvas("c1","c1",800,1000);

		TPad *pad_up = new TPad("pad_up", "pad_up", 0., 0.2, 1., 1.);
                TPad *pad_dn = new TPad("pad_dn", "pad_dn", 0., 0., 1., 0.2);

		pad_up->SetBottomMargin(0);
		pad_up->SetTickx(1);
                pad_up->SetTicky(1);
                pad_up->SetLogy();

		pad_dn->SetTopMargin(0);
                pad_dn->SetBottomMargin(0.50);
		pad_dn->SetTickx(1);
                pad_dn->SetTicky(1);

                pad_up->Draw();
                pad_up->cd();

                ths_all->Draw("hist");
                ths_all->GetXaxis()->SetTitle(prosepaname[i]);
                ths_all->GetYaxis()->SetTitle("Events");
                ht_data->Draw("P E X0 SAME");

                TLatex latex;
                latex.SetNDC();
                latex.SetTextSize(0.04);
                latex.SetTextAlign(11);
                latex.DrawLatex(0.68, 0.93, lumien);
                latex.SetTextSize(0.05);
                latex.DrawLatex(0.12, 0.93, cmsl);

		TLegend *legend1 = new TLegend(0.42,0.72,0.64,0.9);
//                TLegend *legend1 = new TLegend(0.63,0.7,0.87,0.9);
                legend1->AddEntry(ht_data,"Data","PE");
                for(int j=0; j<bkgtype; j++){
//			if(j==1 || j==2 || j==3) continue;
			if(ht[j] == NULL) continue;
                        legend1->AddEntry(ht[j],bkgshort[j],"f");
                }
                legend1->Draw("same");

		c1->cd();
                pad_dn->Draw();
                pad_dn->cd();
                pad_dn->SetGridy();


                TH1D* hRatio = (TH1D*)ht_data->Clone("hRatio");
                hRatio->Divide(hbkg);

		hRatio->GetXaxis()->SetTitle(prosepaname[i]);
                hRatio->GetYaxis()->SetTitle("Data/MC");
                hRatio->GetYaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetRangeUser(0.4,1.6);
                hRatio->GetYaxis()->SetTitleOffset(2.0);
                hRatio->GetXaxis()->SetTitleOffset(5.0);
                hRatio->GetXaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetTitleFont(43);
                hRatio->GetXaxis()->SetTitleFont(43);
                hRatio->GetYaxis()->SetLabelSize(16);
                hRatio->GetXaxis()->SetLabelSize(20);
                hRatio->GetYaxis()->SetTitleSize(24);
                hRatio->GetXaxis()->SetTitleSize(24);
//              hRatio->GetYaxis()->SetNdivisions(502);
		hRatio->Draw("P E X0 SAME");


                c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/Nov17/nov13_QCDcontrol_%s_%i.png",prosepaname[i].Data(),k));
        }
     }
*/




/*
	double m800_0b = 1000*lumin*(nbjets_800->Integral(1,2));
	double m800_1b = 1000*lumin*(nbjets_800->Integral(2,3));
	double m800_2b = 1000*lumin*(nbjets_800->Integral(3,4));
	double m800_3b = 1000*lumin*(nbjets_800->Integral(4,5));

	double ttbar_0b = 1000*lumin*(nbjets_ttbar->Integral(1,2));
        double ttbar_1b = 1000*lumin*(nbjets_ttbar->Integral(2,3));
        double ttbar_2b = 1000*lumin*(nbjets_ttbar->Integral(3,4));
        double ttbar_3b = 1000*lumin*(nbjets_ttbar->Integral(4,5));

	double qcd_0b = 1000*lumin*(nbjets_qcd->Integral(1,2));
        double qcd_1b = 1000*lumin*(nbjets_qcd->Integral(2,3));
        double qcd_2b = 1000*lumin*(nbjets_qcd->Integral(3,4));
        double qcd_3b = 1000*lumin*(nbjets_qcd->Integral(4,5));

	cout << "1000: " << m800_0b << ", " << m800_1b << ", " << m800_2b << ", " << m800_3b << endl;
	cout << "ttbar: " << ttbar_0b << ", " << ttbar_1b << ", " << ttbar_2b << ", " << ttbar_3b << endl;
	cout << "qcd: " << qcd_0b << ", " << qcd_1b << ", " << qcd_2b << ", " << qcd_3b << endl;
*/



}
