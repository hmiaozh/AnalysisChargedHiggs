#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "TProfile.h"
#include "TGraph.h"
#include "TFile.h"
#include "TTree.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include "TLatex.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"
/*
const double Mbottom = 5.0; // mass of bottom quark (4.6GeV)
const double Mw = 80.385;
const double Mtop = 173.34;

Int_t isWfromtopH(TLorentzVector recofatj, TLorentzVector genWth, TLorentzVector genWtass){  //1 = from top from higgs, 2 = from associated top, 0 = don't know

        if(recofatj.DeltaR(genWth) < 0.3) return 1;
	else if(recofatj.DeltaR(genWtass) < 0.3) return 2;
        else return 0;

}
*/


void asydrawsb(){

	setTDRStyle();
/*
        TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_10cut.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_12cut.root");
	TFile* f3 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_14cut.root");
	TFile* f4 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_16cut.root");
	TFile* f5 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_18cut.root");
	TFile* f6 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_20cut.root");
	TFile* f7 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_22cut.root");
	TFile* f8 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_24cut.root");
	TFile* f9 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_26cut.root");
	TFile* f10 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_28cut.root");
	TFile* f11 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_30cut.root");
*/
	TGraph* eff_t0b = new TGraph(13); eff_t0b->SetName("eff_t0b");
	TGraph* eff_t1b = new TGraph(13); eff_t1b->SetName("eff_t1b");
	TGraph* eff_wbb = new TGraph(13); eff_wbb->SetName("eff_wbb");
	TGraph* eff_wbj = new TGraph(13); eff_wbj->SetName("eff_wbj");

	for(Int_t i = 0; i < 13; i++){

	char filename[100];
	sprintf(filename,"/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/asypt_%icut.root",i*2+6);

	TFile* f1 = TFile::Open(filename);

	TH1D* t0b_800_thbh = (TH1D*)f1->Get("invirant_800_thbh");
	TH1D* t0b_1000_thbh = (TH1D*)f1->Get("invirant_1000_thbh");
	TH1D* t0b_2000_thbh = (TH1D*)f1->Get("invirant_2000_thbh");
	TH1D* t0b_3000_thbh = (TH1D*)f1->Get("invirant_3000_thbh");
	TH1D* t0b_ttbar800 = (TH1D*)f1->Get("invirant_ttbar800_t0b");
	TH1D* t0b_ttbar1000 = (TH1D*)f1->Get("invirant_ttbar1000_t0b");
	TH1D* t0b_ttbar2000 = (TH1D*)f1->Get("invirant_ttbar2000_t0b");
	TH1D* t0b_ttbar3000 = (TH1D*)f1->Get("invirant_ttbar3000_t0b");
        TH1D* t0b_qcd800 = (TH1D*)f1->Get("invirant_qcd800_t0b");
	TH1D* t0b_qcd1000 = (TH1D*)f1->Get("invirant_qcd1000_t0b");
	TH1D* t0b_qcd2000 = (TH1D*)f1->Get("invirant_qcd2000_t0b");
	TH1D* t0b_qcd3000 = (TH1D*)f1->Get("invirant_qcd3000_t0b");


	TH1D* t1b_800_thbh = (TH1D*)f1->Get("t1b_800_thbh");
        TH1D* t1b_1000_thbh = (TH1D*)f1->Get("t1b_1000_thbh");
        TH1D* t1b_2000_thbh = (TH1D*)f1->Get("t1b_2000_thbh");
        TH1D* t1b_3000_thbh = (TH1D*)f1->Get("t1b_3000_thbh");
	TH1D* t1b_ttbar800 = (TH1D*)f1->Get("invirant_ttbar800_t1b");
        TH1D* t1b_ttbar1000 = (TH1D*)f1->Get("invirant_ttbar1000_t1b");
        TH1D* t1b_ttbar2000 = (TH1D*)f1->Get("invirant_ttbar2000_t1b");
        TH1D* t1b_ttbar3000 = (TH1D*)f1->Get("invirant_ttbar3000_t1b");
        TH1D* t1b_qcd800 = (TH1D*)f1->Get("invirant_qcd800_t1b");
        TH1D* t1b_qcd1000 = (TH1D*)f1->Get("invirant_qcd1000_t1b");
        TH1D* t1b_qcd2000 = (TH1D*)f1->Get("invirant_qcd2000_t1b");
        TH1D* t1b_qcd3000 = (TH1D*)f1->Get("invirant_qcd3000_t1b");


	TH1D* invariant_3_t_800 = (TH1D*)f1->Get("invariant_3_t_800");
	TH1D* invariant_3_t_1000 = (TH1D*)f1->Get("invariant_3_t_1000");
	TH1D* invariant_3_t_2000 = (TH1D*)f1->Get("invariant_3_t_2000");
	TH1D* invariant_3_t_3000 = (TH1D*)f1->Get("invariant_3_t_3000");
	TH1D* invariant_ttbar800_wbb = (TH1D*)f1->Get("invariant_ttbar800_wbb");
	TH1D* invariant_ttbar1000_wbb = (TH1D*)f1->Get("invariant_ttbar1000_wbb");
	TH1D* invariant_ttbar2000_wbb = (TH1D*)f1->Get("invariant_ttbar2000_wbb");
	TH1D* invariant_ttbar3000_wbb = (TH1D*)f1->Get("invariant_ttbar3000_wbb");
        TH1D* invariant_qcd800_wbb = (TH1D*)f1->Get("invariant_qcd800_wbb");
	TH1D* invariant_qcd1000_wbb = (TH1D*)f1->Get("invariant_qcd1000_wbb");
	TH1D* invariant_qcd2000_wbb = (TH1D*)f1->Get("invariant_qcd2000_wbb");
	TH1D* invariant_qcd3000_wbb = (TH1D*)f1->Get("invariant_qcd3000_wbb");

	TH1D* invariant_wbj_800 = (TH1D*)f1->Get("invariant_wbj_800");
	TH1D* invariant_wbj_1000 = (TH1D*)f1->Get("invariant_wbj_1000");
	TH1D* invariant_wbj_2000 = (TH1D*)f1->Get("invariant_wbj_2000");
	TH1D* invariant_wbj_3000 = (TH1D*)f1->Get("invariant_wbj_3000");
	TH1D* invariant_ttbar800_wbj = (TH1D*)f1->Get("invariant_ttbar800_wbj");
	TH1D* invariant_ttbar1000_wbj = (TH1D*)f1->Get("invariant_ttbar1000_wbj");
	TH1D* invariant_ttbar2000_wbj = (TH1D*)f1->Get("invariant_ttbar2000_wbj");
	TH1D* invariant_ttbar3000_wbj = (TH1D*)f1->Get("invariant_ttbar3000_wbj");
	TH1D* invariant_qcd800_wbj = (TH1D*)f1->Get("invariant_qcd800_wbj");
	TH1D* invariant_qcd1000_wbj = (TH1D*)f1->Get("invariant_qcd1000_wbj");
	TH1D* invariant_qcd2000_wbj = (TH1D*)f1->Get("invariant_qcd2000_wbj");
	TH1D* invariant_qcd3000_wbj = (TH1D*)f1->Get("invariant_qcd3000_wbj");


        Double_t sig800t0b = 0, ttbar800t0b = 0, qcd800t0b = 0;
        Double_t sig1000t0b = 0, ttbar1000t0b = 0, qcd1000t0b = 0;
        Double_t sig2000t0b = 0, ttbar2000t0b = 0, qcd2000t0b = 0;
        Double_t sig3000t0b = 0, ttbar3000t0b = 0, qcd3000t0b = 0;

	Double_t sig800t1b = 0, ttbar800t1b = 0, qcd800t1b = 0;
        Double_t sig1000t1b = 0, ttbar1000t1b = 0, qcd1000t1b = 0;
        Double_t sig2000t1b = 0, ttbar2000t1b = 0, qcd2000t1b = 0;
        Double_t sig3000t1b = 0, ttbar3000t1b = 0, qcd3000t1b = 0;

        Double_t sig800wbb = 0, ttbar800wbb = 0, qcd800wbb = 0;
        Double_t sig1000wbb = 0, ttbar1000wbb = 0, qcd1000wbb = 0;
        Double_t sig2000wbb = 0, ttbar2000wbb = 0, qcd2000wbb = 0;
        Double_t sig3000wbb = 0, ttbar3000wbb = 0, qcd3000wbb = 0;

	Double_t sig800wbj = 0, ttbar800wbj = 0, qcd800wbj = 0;
        Double_t sig1000wbj = 0, ttbar1000wbj = 0, qcd1000wbj = 0;
        Double_t sig2000wbj = 0, ttbar2000wbj = 0, qcd2000wbj = 0;
        Double_t sig3000wbj = 0, ttbar3000wbj = 0, qcd3000wbj = 0;

	sig800t0b = t0b_800_thbh->Integral();
	sig1000t0b = t0b_1000_thbh->Integral();
	sig2000t0b = t0b_2000_thbh->Integral();
	sig3000t0b = t0b_3000_thbh->Integral();
	ttbar800t0b = t0b_ttbar800->Integral();
        ttbar1000t0b = t0b_ttbar1000->Integral();
        ttbar2000t0b = t0b_ttbar2000->Integral();
        ttbar3000t0b = t0b_ttbar3000->Integral();
	qcd800t0b = t0b_qcd800->Integral();
        qcd1000t0b = t0b_qcd1000->Integral();
        qcd2000t0b = t0b_qcd2000->Integral();
        qcd3000t0b = t0b_qcd3000->Integral();


	sig800t1b = t1b_800_thbh->Integral();
        sig1000t1b = t1b_1000_thbh->Integral();
        sig2000t1b = t1b_2000_thbh->Integral();
        sig3000t1b = t1b_3000_thbh->Integral();
        ttbar800t1b = t1b_ttbar800->Integral();
        ttbar1000t1b = t1b_ttbar1000->Integral();
        ttbar2000t1b = t1b_ttbar2000->Integral();
        ttbar3000t1b = t1b_ttbar3000->Integral();
        qcd800t1b = t1b_qcd800->Integral();
        qcd1000t1b = t1b_qcd1000->Integral();
        qcd2000t1b = t1b_qcd2000->Integral();
        qcd3000t1b = t1b_qcd3000->Integral();


	sig800wbb = invariant_3_t_800->Integral();
        sig1000wbb = invariant_3_t_1000->Integral();
        sig2000wbb = invariant_3_t_2000->Integral();
        sig3000wbb = invariant_3_t_3000->Integral();
	ttbar800wbb = invariant_ttbar800_wbb->Integral();
        ttbar1000wbb = invariant_ttbar1000_wbb->Integral();
        ttbar2000wbb = invariant_ttbar2000_wbb->Integral();
        ttbar3000wbb = invariant_ttbar3000_wbb->Integral();
	qcd800wbb = invariant_qcd800_wbb->Integral();
        qcd1000wbb = invariant_qcd1000_wbb->Integral();
        qcd2000wbb = invariant_qcd2000_wbb->Integral();
        qcd3000wbb = invariant_qcd3000_wbb->Integral();

	
	sig800wbj = invariant_wbj_800->Integral();
	sig1000wbj = invariant_wbj_1000->Integral();
	sig2000wbj = invariant_wbj_2000->Integral();
	sig3000wbj = invariant_wbj_3000->Integral();
	ttbar800wbj = invariant_ttbar800_wbj->Integral();
	ttbar1000wbj = invariant_ttbar1000_wbj->Integral();
	ttbar2000wbj = invariant_ttbar2000_wbj->Integral();
	ttbar3000wbj = invariant_ttbar3000_wbj->Integral();
	qcd800wbj = invariant_qcd800_wbj->Integral();
	qcd1000wbj = invariant_qcd1000_wbj->Integral();
	qcd2000wbj = invariant_qcd2000_wbj->Integral();
	qcd3000wbj = invariant_qcd3000_wbj->Integral();



	Double_t sorb_t0b = (double)sig3000t0b/sqrt((double)(ttbar3000t0b+qcd3000t0b));
	Double_t sorb_t1b = (double)sig3000t1b/sqrt((double)(ttbar3000t1b+qcd3000t1b));
	Double_t sorb_wbb = (double)sig3000wbb/sqrt((double)(ttbar3000wbb+qcd3000wbb));
	Double_t sorb_wbj = (double)sig3000wbj/sqrt((double)(ttbar3000wbj+qcd3000wbj));

	eff_t0b->SetPoint(i,(double)(i*2+6)/100.,sorb_t0b);
	eff_t1b->SetPoint(i,(double)(i*2+6)/100.,sorb_t1b);
	eff_wbb->SetPoint(i,(double)(i*2+6)/100.,sorb_wbb);
	eff_wbj->SetPoint(i,(double)(i*2+6)/100.,sorb_wbj);
	}


	eff_t0b->SetLineColor(38);
	eff_t0b->SetLineWidth(2);
	eff_t0b->SetMarkerColor(38);
	eff_t0b->SetMarkerSize(1.5);
	eff_t0b->SetMarkerStyle(22);
	eff_t0b->GetYaxis()->SetRangeUser(0,0.05);
	eff_t0b->GetXaxis()->SetTitle("AsyPt_cut");
        eff_t0b->GetYaxis()->SetTitle("#surd S/B");

	eff_t1b->SetLineColor(46);
        eff_t1b->SetLineWidth(2);
        eff_t1b->SetMarkerColor(46);
        eff_t1b->SetMarkerSize(1.5);
        eff_t1b->SetMarkerStyle(20);

	eff_wbb->SetLineColor(8);
        eff_wbb->SetLineWidth(2);
        eff_wbb->SetMarkerColor(8);
        eff_wbb->SetMarkerSize(1.5);
        eff_wbb->SetMarkerStyle(29);

	eff_wbj->SetLineColor(9);
	eff_wbj->SetLineWidth(2);
	eff_wbj->SetMarkerColor(9);
	eff_wbj->SetMarkerSize(1.5);
	eff_wbj->SetMarkerStyle(30);


        TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        eff_t0b->Draw("AP");
	eff_t1b->Draw("P");
	eff_wbb->Draw("P");
	eff_wbj->Draw("P");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

        TLegend *legend4 = new TLegend(0.63,0.74,0.85,0.88);
        legend4->AddEntry(eff_t0b,"t0b","LP");
	legend4->AddEntry(eff_t1b,"t1b","LP");
	legend4->AddEntry(eff_wbb,"wbb","LP");
	legend4->AddEntry(eff_wbj,"wbj","LP");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/newstage/asyPt_cut_3000.png");
/*
        eff_wbb_ht->SetLineColor(38);
        eff_wbb_ht->SetLineWidth(2);
        eff_wbb_ht->SetMarkerColor(38);
        eff_wbb_ht->SetMarkerSize(1.5);
        eff_wbb_ht->SetMarkerStyle(22);
        eff_wbb_ht->GetYaxis()->SetRangeUser(0,0.02);
	eff_wbb_ht->GetXaxis()->SetTitle("M_{H^{+}}");
        eff_wbb_ht->GetYaxis()->SetTitle("#surd S/B");


	eff_wbb_nht->SetLineColor(46);
        eff_wbb_nht->SetLineWidth(2);
        eff_wbb_nht->SetMarkerColor(46);
        eff_wbb_nht->SetMarkerSize(1.5);
        eff_wbb_nht->SetMarkerStyle(20);

	eff_wbb_no->SetLineColor(8);
        eff_wbb_no->SetLineWidth(2);
        eff_wbb_no->SetMarkerColor(8);
        eff_wbb_no->SetMarkerSize(1.5);
        eff_wbb_no->SetMarkerStyle(29);


        TCanvas *c = new TCanvas("c","c",800,600);
        c->cd(1);
        eff_wbb_ht->Draw("AP");
	eff_wbb_nht->Draw("P");
	eff_wbb_no->Draw("P");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

        TLegend *legend = new TLegend(0.63,0.74,0.85,0.88);
        legend->AddEntry(eff_wbb_ht,"wbb,Medium","LP");
	legend->AddEntry(eff_wbb_nht,"wbb,Loose","LP");
	legend->AddEntry(eff_wbb_no,"wbb,no","LP");
        legend->Draw("same");

        c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/subbtag_wbb.png");


	eff_wbb_eta08->SetLineColor(kRed-7);
        eff_wbb_eta08->SetLineWidth(2);
        eff_wbb_eta08->SetMarkerColor(kRed-7);
        eff_wbb_eta08->SetMarkerSize(1.5);
        eff_wbb_eta08->SetMarkerStyle(20);
	eff_wbb_eta08->GetYaxis()->SetRangeUser(0,0.048);
	eff_wbb_eta08->GetXaxis()->SetTitle("M_{H^{+}}");
	eff_wbb_eta08->GetHistogram()->GetYaxis()->SetTitle("#surd S/B");
//	eff_wbb_eta08->SetTitle(";M_{H^{+}};why");
	
	eff_wbb_eta10->SetLineColor(38);
        eff_wbb_eta10->SetLineWidth(2);
        eff_wbb_eta10->SetMarkerColor(38);
        eff_wbb_eta10->SetMarkerSize(1.5);
        eff_wbb_eta10->SetMarkerStyle(21);


	eff_wbb_eta12->SetLineColor(kPink+1);
        eff_wbb_eta12->SetLineWidth(2);
        eff_wbb_eta12->SetMarkerColor(kPink+1);
        eff_wbb_eta12->SetMarkerSize(1.5);
        eff_wbb_eta12->SetMarkerStyle(22);


	eff_wbb_eta15->SetLineColor(kViolet+6);
        eff_wbb_eta15->SetLineWidth(2);
        eff_wbb_eta15->SetMarkerColor(kViolet+6);
        eff_wbb_eta15->SetMarkerSize(1.5);
        eff_wbb_eta15->SetMarkerStyle(23);

	eff_wbb_eta18->SetLineColor(kRed-1);
        eff_wbb_eta18->SetLineWidth(2);
        eff_wbb_eta18->SetMarkerColor(kRed-1);
        eff_wbb_eta18->SetMarkerSize(1.5);
        eff_wbb_eta18->SetMarkerStyle(33);
	
	eff_wbb_eta20->SetLineColor(kAzure+1);
        eff_wbb_eta20->SetLineWidth(2);
        eff_wbb_eta20->SetMarkerColor(kAzure+1);
        eff_wbb_eta20->SetMarkerSize(1.5);
        eff_wbb_eta20->SetMarkerStyle(34);

	TCanvas *ce = new TCanvas("ce","ce",800,600);
        ce->cd(1);
	
        eff_wbb_eta08->Draw("AP");
        eff_wbb_eta10->Draw("P");
        eff_wbb_eta12->Draw("P");
	eff_wbb_eta15->Draw("P");
	eff_wbb_eta18->Draw("P");
	eff_wbb_eta20->Draw("P");
	eff_wbb_no->Draw("P");

        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");



        TLegend *legende = new TLegend(0.6,0.7,0.85,0.88);
        legende->AddEntry(eff_wbb_eta08,"del_eta<0.8","LP");
        legende->AddEntry(eff_wbb_eta10,"del_eta<1.0","LP");
        legende->AddEntry(eff_wbb_eta12,"del_eta<1.2","LP");
	legende->AddEntry(eff_wbb_eta15,"del_eta<1.5","LP");
	legende->AddEntry(eff_wbb_eta18,"del_eta<1.8","LP");
	legende->AddEntry(eff_wbb_eta20,"del_eta<2.0","LP");
	legende->AddEntry(eff_wbb_no,"no cut","LP");
        legende->Draw("same");

        ce->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/deleta_wbb.png");
*/	



}
   
