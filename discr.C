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
#include "TGraphAsymmErrors.h"
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

//const double lumin = 5.768;
const double lumin = 35.87;
const double extra = 1;
const double scaf = 1000.*lumin;
const double scafqcd = 1000.*lumin;


const int binnum = 120;
const int bkgtype = 13;
const int proalltype = 14;
const int prosepatype = 6;    //6--discr;13--sepa type
const int errtype = 9;
const int colorbkg[bkgtype] = {kBlue-10,kGreen-10,kGreen-10,kGreen-10,kGreen-10,kGreen-10,kAzure-9,kGray,kGray,kGray,kGray,kGray,kOrange-9};
TString bkgname[bkgtype] = {"TT_TuneCUETP8M2T4_13TeV-powheg-pythia8","WJetsToLNu_HT","DYJets","WJetsToQQ_HT","ZJetsToNuNu_HT","ZJetsToQQ_HT","Other","TTW","TTZ","TTG","TTTT","ttH","QCD_HT"};
TString bkgshort[bkgtype] = {"ttbar","electroweak","electroweak","electroweak","electroweak","electroweak","Other","rares","rares","rares","rares","rares","QCD"};
TString proname[proalltype] = {"ST","HT","NBjets","Njets","NFatjets","Met","SDMass","top_pt","W_pt","fat_pt","tau32","tau21","ele_pt","muon_pt"};
TString prosepaname[prosepatype] = {"Discr_100","Discr_300","Discr_500","Discr_700","Discr_900","Discr_1100"};
TString errtypeup[errtype] = {"CSVRCERR1Up","CSVRCERR2Up","CSVRHFUp","CSVRHFSTAT1Up","CSVRHFSTAT2Up","CSVRLFUp","CSVRLFSTAT1Up","CSVRLFSTAT2Up","JESANDCSVUp"};
TString errtypedown[errtype] = {"CSVRCERR1Down","CSVRCERR2Down","CSVRHFDown","CSVRHFSTAT1Down","CSVRHFSTAT2Down","CSVRLFDown","CSVRLFSTAT1Down","CSVRLFSTAT2Down","JESANDCSVDown"};

void discr(){
	
	setTDRStyle();



	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/endofnov.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/Mo_CR1lAllData.root");

	TDirectoryFile* all = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat");
	TDirectoryFile* allbug = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat");
	TDirectoryFile* tb[4];
	TDirectoryFile* tbbug[4];
	tb[0] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t0b");
	tb[1] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t1b");
	tb[2] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbb");
	tb[3] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbj");

	tbbug[0] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t0b");
        tbbug[1] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_t1b");
        tbbug[2] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbb");
        tbbug[3] = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_wbj");

      for(int k=0; k<4; k++){
	for(int i=0; i<prosepatype; i++){
		double sumup[binnum/5] = {0};
		double sumdown[binnum/5] = {0};	

                THStack *ths_all = new THStack(prosepaname[i],prosepaname[i]);
		TH1D* hbkg;
                TH1D* ht[bkgtype];

                TH1D* ht_data= (TH1D*)tbbug[k]->Get(Form("%s_Data",prosepaname[i].Data()));
		if(ht_data == NULL) continue;
		ht_data->Rebin(5);
                ht_data->SetMarkerColor(1);
                ht_data->SetLineColor(1);
                ht_data->SetMarkerSize(1);
                ht_data->SetMarkerStyle(20);

                for(int j=0; j<bkgtype; j++){
                        ht[j] = (TH1D*)tb[k]->Get(Form("%s_%s",prosepaname[i].Data(),bkgname[j].Data()));
			if(ht[j] == NULL) continue;
			if(j==0)hbkg = (TH1D*)ht[j]->Clone("hbkg");
                	else hbkg->Add(ht[j]);
			ht[j]->Rebin(5);
                        ht[j]->SetFillColor(colorbkg[j]);
                        ht[j]->SetLineColor(colorbkg[j]);
			ht[j]->Scale(scaf);
                        ths_all->Add(ht[j]);

			for(int l=0; l<errtype; l++){
				TH1D* h_up = (TH1D*)tb[k]->Get(Form("%s_%s_%s",prosepaname[i].Data(),bkgname[j].Data(),errtypeup[l].Data()));
				TH1D* h_down = (TH1D*)tb[k]->Get(Form("%s_%s_%s",prosepaname[i].Data(),bkgname[j].Data(),errtypedown[l].Data()));
				if(h_up == NULL || h_down == NULL) continue;
				h_up->Rebin(5); h_up->Scale(scaf);
				h_down->Rebin(5); h_down->Scale(scaf);
				for(int m=0; m<binnum/5; m++){
					double uperr = (h_up->GetBinContent(m+1) - ht[j]->GetBinContent(m+1))/ht[j]->GetBinContent(m+1);
					double downerr = (h_down->GetBinContent(m+1) - ht[j]->GetBinContent(m+1))/ht[j]->GetBinContent(m+1);
					sumup[m] += uperr*uperr;
					sumdown[m] += downerr*downerr;
				}
			}

                }


		if(ht[0] == NULL) continue;
		hbkg->Rebin(5);
		hbkg->Scale(scaf);

                TCanvas *c1 = new TCanvas("c1","c1",800,1000);

		TPad *pad_up = new TPad("pad_up", "pad_up", 0., 0.2, 1., 1.);
                TPad *pad_dn = new TPad("pad_dn", "pad_dn", 0., 0., 1., 0.2);

		pad_up->SetBottomMargin(0);
		pad_up->SetLeftMargin(0.12);
                pad_up->SetRightMargin(0.07);
		pad_up->SetTickx(1);
                pad_up->SetTicky(1);
                pad_up->SetLogy();

		pad_dn->SetTopMargin(0);
                pad_dn->SetBottomMargin(0.50);
		pad_dn->SetLeftMargin(0.12);
                pad_dn->SetRightMargin(0.07);
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
                latex.DrawLatex(0.67, 0.93, lumien);
                latex.SetTextSize(0.05);
                latex.DrawLatex(0.12, 0.93, cmsl);

		TLegend *legend1 = new TLegend(0.7,0.69,0.94,0.9);
		legend1->SetFillStyle(0);
                legend1->SetBorderSize(0);
                legend1->AddEntry(ht_data,"Data","PE");
                for(int j=0; j<bkgtype; j++){
			if(ht[j] == NULL) continue;
			if(j>0 && colorbkg[j]==colorbkg[j-1] && ht[j-1] != NULL)continue;
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
                hRatio->GetYaxis()->SetRangeUser(0.,2.0);
                hRatio->GetYaxis()->SetTitleOffset(2.0);
                hRatio->GetXaxis()->SetTitleOffset(5.0);
                hRatio->GetXaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetTitleFont(43);
                hRatio->GetXaxis()->SetTitleFont(43);
                hRatio->GetYaxis()->SetLabelSize(12);
                hRatio->GetXaxis()->SetLabelSize(20);
                hRatio->GetYaxis()->SetTitleSize(24);
                hRatio->GetXaxis()->SetTitleSize(24);
//              hRatio->GetYaxis()->SetNdivisions(502);
		hRatio->Draw("P E X0 SAME");

		double xn[binnum/5];
		double yn[binnum/5];
		double xerr1[binnum/5];
		double xerr2[binnum/5];
		for(int p=0; p<binnum/5; p++){
			xn[p] = 0.025+p*0.05;
			yn[p] = 1.0;
			xerr1[p] = 0.025;
			xerr2[p] = 0.025;
			cout << sumup[p] << endl;
		}
		TGraphAsymmErrors* gr = new TGraphAsymmErrors(binnum/5,xn,yn,xerr1,xerr2,sumup,sumdown);
		gr->SetFillColor(kBlack);
		gr->SetFillStyle(3003);
		gr->Draw("E2");


                c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/DecAN/dec06_qcd_mirror_%s_%i.png",prosepaname[i].Data(),k));
        }//end type properties
      }//end t0b,t1b,wbb,tbj

/*
	for(int i=0; i<proalltype; i++){
                if(i==6 || i==7) continue;
                THStack *ths_all = new THStack(proname[i],proname[i]);
                TH1D* hbkg;
                TH1D* ht[bkgtype];
                TH1D* ht_data= (TH1D*)allbug->Get(Form("%s_Data",proname[i].Data()));
                if(ht_data == NULL) continue;
                if(i==0 || i==1)ht_data->Rebin(8);
                else if(i>=6)ht_data->Rebin(4);
                ht_data->SetMarkerColor(1);
                ht_data->SetLineColor(1);
                ht_data->SetMarkerSize(1);
                ht_data->SetMarkerStyle(20);
                for(int j=0; j<bkgtype; j++){
                        ht[j] = (TH1D*)all->Get(Form("%s_%s",proname[i].Data(),bkgname[j].Data()));
                        if(ht[j] == NULL) continue;
                        if(j==0)hbkg = (TH1D*)ht[j]->Clone("hbkg");
                        else hbkg->Add(ht[j]);
                        if(i==0 || i==1)ht[j]->Rebin(8);
                        else if(i>=6)ht[j]->Rebin(4);
                        ht[j]->SetFillColor(colorbkg[j]);
                        ht[j]->SetLineColor(colorbkg[j]);
                        ht[j]->Scale(scaf);
                        ths_all->Add(ht[j]);
                }
                if(i==0 || i==1)hbkg->Rebin(8);
                else if(i>=6)hbkg->Rebin(4);
                hbkg->Scale(scaf);


                TCanvas *c1 = new TCanvas("c1","c1",800,1000);
                TPad *pad_up = new TPad("pad_up", "pad_up", 0., 0.2, 1., 1.);
                TPad *pad_dn = new TPad("pad_dn", "pad_dn", 0., 0., 1., 0.2);

                pad_up->SetBottomMargin(0);
                pad_up->SetLeftMargin(0.12);
                pad_up->SetRightMargin(0.07);
                pad_up->SetTickx(1);
                pad_up->SetTicky(1);
                pad_up->SetLogy();

                pad_dn->SetTopMargin(0);
                pad_dn->SetBottomMargin(0.50);
                pad_dn->SetLeftMargin(0.12);
                pad_dn->SetRightMargin(0.07);
                pad_dn->SetTickx(1);
                pad_dn->SetTicky(1);

                pad_up->Draw();
                pad_up->cd();

                ths_all->Draw("hist");
                ths_all->GetYaxis()->SetTitle("Events");
                ht_data->Draw("P E X0 SAME");

                TLatex latex;
                latex.SetNDC();
                latex.SetTextSize(0.04);
                latex.SetTextAlign(11);
                latex.DrawLatex(0.67, 0.93, lumien);
                latex.SetTextSize(0.05);
                latex.DrawLatex(0.12, 0.93, cmsl);

                TLegend *legend1 = new TLegend(0.7,0.69,0.94,0.9);
                legend1->SetFillStyle(0);
                legend1->SetBorderSize(0);
                legend1->AddEntry(ht_data,"Data","PE");
                for(int j=0; j<bkgtype; j++){
                        if(ht[j] == NULL) continue;
                        if(j>0 && colorbkg[j]==colorbkg[j-1] && ht[j-1] != NULL)continue;
                        legend1->AddEntry(ht[j],bkgshort[j],"f");
                }
                legend1->Draw("same");

                c1->cd();
                pad_dn->Draw();
                pad_dn->cd();
                pad_dn->SetGridy();


                TH1D* hRatio = (TH1D*)ht_data->Clone("hRatio");
                hRatio->Divide(hbkg);
                hRatio->GetXaxis()->SetTitle(proname[i]);
                hRatio->GetYaxis()->SetTitle("Data/MC");
                hRatio->GetYaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetRangeUser(0.4,1.6);
                hRatio->GetYaxis()->SetTitleOffset(2.0);
                hRatio->GetXaxis()->SetTitleOffset(5.0);
                hRatio->GetXaxis()->SetLabelFont(43);
                hRatio->GetYaxis()->SetTitleFont(43);
                hRatio->GetXaxis()->SetTitleFont(43);
                hRatio->GetYaxis()->SetLabelSize(12);
                hRatio->GetXaxis()->SetLabelSize(20);
                hRatio->GetYaxis()->SetTitleSize(24);
                hRatio->GetXaxis()->SetTitleSize(24);
                hRatio->Draw("P E X0 SAME");    

                c1->SaveAs(Form("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/NovAN/nov28_qcd_mirror_%s.png",proname[i].Data()));
        }
*/





}
