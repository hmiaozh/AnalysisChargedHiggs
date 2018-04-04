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
#include <string>
#include <vector>
#include <math.h>

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


void effsb(){

        TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mass_deleta_08cut.root");
//	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/mass_qcd_nht.root");

	TFile* outf = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/sb_deleta_08cut.root","recreate");

	TH1D* invirant_400_thbh = (TH1D*)f1->Get("invirant_400_thbh");
        TH1D* invirant_400_thb = (TH1D*)f1->Get("invirant_400_thb");
        TH1D* invirant_400_tbh = (TH1D*)f1->Get("invirant_400_tbh");
        TH1D* invirant_400_tb = (TH1D*)f1->Get("invirant_400_tb");

	TH1D* invirant_500_thbh = (TH1D*)f1->Get("invirant_500_thbh");
        TH1D* invirant_500_thb = (TH1D*)f1->Get("invirant_500_thb");
        TH1D* invirant_500_tbh = (TH1D*)f1->Get("invirant_500_tbh");
        TH1D* invirant_500_tb = (TH1D*)f1->Get("invirant_500_tb");

	TH1D* invirant_800_thbh = (TH1D*)f1->Get("invirant_800_thbh");
        TH1D* invirant_800_thb = (TH1D*)f1->Get("invirant_800_thb");
        TH1D* invirant_800_tbh = (TH1D*)f1->Get("invirant_800_tbh");
        TH1D* invirant_800_tb = (TH1D*)f1->Get("invirant_800_tb");

	TH1D* invirant_1000_thbh = (TH1D*)f1->Get("invirant_1000_thbh");
	TH1D* invirant_1000_thb = (TH1D*)f1->Get("invirant_1000_thb");
	TH1D* invirant_1000_tbh = (TH1D*)f1->Get("invirant_1000_tbh");
	TH1D* invirant_1000_tb = (TH1D*)f1->Get("invirant_1000_tb");

	TH1D* invirant_2000_thbh = (TH1D*)f1->Get("invirant_2000_thbh");
        TH1D* invirant_2000_thb = (TH1D*)f1->Get("invirant_2000_thb");
        TH1D* invirant_2000_tbh = (TH1D*)f1->Get("invirant_2000_tbh");
        TH1D* invirant_2000_tb = (TH1D*)f1->Get("invirant_2000_tb");

	TH1D* invirant_3000_thbh = (TH1D*)f1->Get("invirant_3000_thbh");
        TH1D* invirant_3000_thb = (TH1D*)f1->Get("invirant_3000_thb");
        TH1D* invirant_3000_tbh = (TH1D*)f1->Get("invirant_3000_tbh");
        TH1D* invirant_3000_tb = (TH1D*)f1->Get("invirant_3000_tb");

	TH1D* invariant_3_t_400 = (TH1D*)f1->Get("invariant_3_t_400");
        TH1D* invariant_3_nt_w_400 = (TH1D*)f1->Get("invariant_3_nt_w_400");
        TH1D* invariant_3_nt_nw_400 = (TH1D*)f1->Get("invariant_3_nt_nw_400");

	TH1D* invariant_3_t_500 = (TH1D*)f1->Get("invariant_3_t_500");
        TH1D* invariant_3_nt_w_500 = (TH1D*)f1->Get("invariant_3_nt_w_500");
        TH1D* invariant_3_nt_nw_500 = (TH1D*)f1->Get("invariant_3_nt_nw_500");

	TH1D* invariant_3_t_800 = (TH1D*)f1->Get("invariant_3_t_800");
	TH1D* invariant_3_nt_w_800 = (TH1D*)f1->Get("invariant_3_nt_w_800");
	TH1D* invariant_3_nt_nw_800 = (TH1D*)f1->Get("invariant_3_nt_nw_800");

	TH1D* invariant_3_t_1000 = (TH1D*)f1->Get("invariant_3_t_1000");
        TH1D* invariant_3_nt_w_1000 = (TH1D*)f1->Get("invariant_3_nt_w_1000");
        TH1D* invariant_3_nt_nw_1000 = (TH1D*)f1->Get("invariant_3_nt_nw_1000");

	TH1D* invariant_3_t_2000 = (TH1D*)f1->Get("invariant_3_t_2000");
        TH1D* invariant_3_nt_w_2000 = (TH1D*)f1->Get("invariant_3_nt_w_2000");
        TH1D* invariant_3_nt_nw_2000 = (TH1D*)f1->Get("invariant_3_nt_nw_2000");

	TH1D* invariant_3_t_3000 = (TH1D*)f1->Get("invariant_3_t_3000");
        TH1D* invariant_3_nt_w_3000 = (TH1D*)f1->Get("invariant_3_nt_w_3000");
        TH1D* invariant_3_nt_nw_3000 = (TH1D*)f1->Get("invariant_3_nt_nw_3000");

	TH1D* invirant_ttbar_tb = (TH1D*)f1->Get("invirant_ttbar_tb");
        TH1D* invirant_qcd_tb = (TH1D*)f1->Get("invirant_qcd_tb");
	
	TH1D* invariant_ttbar_wbb = (TH1D*)f1->Get("invariant_ttbar_wbb");
        TH1D* invariant_qcd_wbb = (TH1D*)f1->Get("invariant_qcd_wbb");

	TGraph* eff_tb = new TGraph(6); eff_tb->SetName("eff_tb");
	TGraph* eff_wbb = new TGraph(6); eff_wbb->SetName("eff_wbb");


	Int_t m400low = -1, m400up = -1;
	Int_t m500low = -1, m500up = -1;
	Int_t m800low = -1, m800up = -1;
	Int_t m1000low = -1, m1000up = -1;
	Int_t m2000low = -1, m2000up = -1;
	Int_t m3000low = -1, m3000up = -1;

	Int_t m400lowwbb = -1, m400upwbb = -1;
        Int_t m500lowwbb = -1, m500upwbb = -1;
        Int_t m800lowwbb = -1, m800upwbb = -1;
        Int_t m1000lowwbb = -1, m1000upwbb = -1;
        Int_t m2000lowwbb = -1, m2000upwbb = -1;
        Int_t m3000lowwbb = -1, m3000upwbb = -1;


	Double_t sig400 = 0, ttbar400 = 0, qcd400 = 0;
	Double_t sig500 = 0, ttbar500 = 0, qcd500 = 0;
	Double_t sig800 = 0, ttbar800 = 0, qcd800 = 0;
	Double_t sig1000 = 0, ttbar1000 = 0, qcd1000 = 0;
	Double_t sig2000 = 0, ttbar2000 = 0, qcd2000 = 0;
	Double_t sig3000 = 0, ttbar3000 = 0, qcd3000 = 0;

	Double_t sig400wbb = 0, ttbar400wbb = 0, qcd400wbb = 0;
        Double_t sig500wbb = 0, ttbar500wbb = 0, qcd500wbb = 0;
        Double_t sig800wbb = 0, ttbar800wbb = 0, qcd800wbb = 0;
        Double_t sig1000wbb = 0, ttbar1000wbb = 0, qcd1000wbb = 0;
        Double_t sig2000wbb = 0, ttbar2000wbb = 0, qcd2000wbb = 0;
        Double_t sig3000wbb = 0, ttbar3000wbb = 0, qcd3000wbb = 0;




	m400low = invirant_400_thbh->FindFirstBinAbove(invirant_400_thbh->GetMaximum()/2);
	m400up  = invirant_400_thbh->FindLastBinAbove(invirant_400_thbh->GetMaximum()/2);

	m500low = invirant_500_thbh->FindFirstBinAbove(invirant_500_thbh->GetMaximum()/2);
	m500up  = invirant_500_thbh->FindLastBinAbove(invirant_500_thbh->GetMaximum()/2);
	
	m800low = invirant_800_thbh->FindFirstBinAbove(invirant_800_thbh->GetMaximum()/2);
        m800up  = invirant_800_thbh->FindLastBinAbove(invirant_800_thbh->GetMaximum()/2);

	m1000low = invirant_1000_thbh->FindFirstBinAbove(invirant_1000_thbh->GetMaximum()/2);
        m1000up  = invirant_1000_thbh->FindLastBinAbove(invirant_1000_thbh->GetMaximum()/2);	

	m2000low = invirant_2000_thbh->FindFirstBinAbove(invirant_2000_thbh->GetMaximum()/2);
        m2000up  = invirant_2000_thbh->FindLastBinAbove(invirant_2000_thbh->GetMaximum()/2);

	m3000low = invirant_3000_thbh->FindFirstBinAbove(invirant_3000_thbh->GetMaximum()/2);
        m3000up  = invirant_3000_thbh->FindLastBinAbove(invirant_3000_thbh->GetMaximum()/2);

		
	m400lowwbb = invariant_3_t_400->FindFirstBinAbove(invariant_3_t_400->GetMaximum()/2);
        m400upwbb  = invariant_3_t_400->FindLastBinAbove(invariant_3_t_400->GetMaximum()/2);

        m500lowwbb = invariant_3_t_500->FindFirstBinAbove(invariant_3_t_500->GetMaximum()/2);
        m500upwbb  = invariant_3_t_500->FindLastBinAbove(invariant_3_t_500->GetMaximum()/2);

        m800lowwbb = invariant_3_t_800->FindFirstBinAbove(invariant_3_t_800->GetMaximum()/2);
        m800upwbb  = invariant_3_t_800->FindLastBinAbove(invariant_3_t_800->GetMaximum()/2);

        m1000lowwbb = invariant_3_t_1000->FindFirstBinAbove(invariant_3_t_1000->GetMaximum()/2);
        m1000upwbb  = invariant_3_t_1000->FindLastBinAbove(invariant_3_t_1000->GetMaximum()/2);

        m2000lowwbb = invariant_3_t_2000->FindFirstBinAbove(invariant_3_t_2000->GetMaximum()/2);
        m2000upwbb  = invariant_3_t_2000->FindLastBinAbove(invariant_3_t_2000->GetMaximum()/2);

        m3000lowwbb = invariant_3_t_3000->FindFirstBinAbove(invariant_3_t_3000->GetMaximum()/2);
        m3000upwbb  = invariant_3_t_3000->FindLastBinAbove(invariant_3_t_3000->GetMaximum()/2);




        sig400 = invirant_400_thbh->Integral(m400low,m400up);
	sig500 = invirant_500_thbh->Integral(m500low,m500up);
	sig800 = invirant_800_thbh->Integral(m800low,m800up);
	sig1000 = invirant_1000_thbh->Integral(m1000low,m1000up);
	sig2000 = invirant_2000_thbh->Integral(m2000low,m2000up);
	sig3000 = invirant_3000_thbh->Integral(m3000low,m3000up);

	ttbar400 = invirant_ttbar_tb->Integral(m400low,m400up);
	ttbar500 = invirant_ttbar_tb->Integral(m500low,m500up);
	ttbar800 = invirant_ttbar_tb->Integral(m800low,m800up);
	ttbar1000 = invirant_ttbar_tb->Integral(m1000low,m1000up);
	ttbar2000 = invirant_ttbar_tb->Integral(m2000low,m2000up);
	ttbar3000 = invirant_ttbar_tb->Integral(m3000low,m3000up);

	qcd400 = invirant_qcd_tb->Integral(m400low,m400up);
	qcd500 = invirant_qcd_tb->Integral(m500low,m500up);
	qcd800 = invirant_qcd_tb->Integral(m800low,m800up);
	qcd1000 = invirant_qcd_tb->Integral(m1000low,m1000up);
	qcd2000 = invirant_qcd_tb->Integral(m2000low,m2000up);
	qcd3000 = invirant_qcd_tb->Integral(m3000low,m3000up);


	sig400wbb = invariant_3_t_400->Integral(m400lowwbb,m400upwbb);
        sig500wbb = invariant_3_t_500->Integral(m500lowwbb,m500upwbb);
        sig800wbb = invariant_3_t_800->Integral(m800lowwbb,m800upwbb);
        sig1000wbb = invariant_3_t_1000->Integral(m1000lowwbb,m1000upwbb);
        sig2000wbb = invariant_3_t_2000->Integral(m2000lowwbb,m2000upwbb);
        sig3000wbb = invariant_3_t_3000->Integral(m3000lowwbb,m3000upwbb);

        ttbar400wbb = invariant_ttbar_wbb->Integral(m400lowwbb,m400upwbb);
        ttbar500wbb = invariant_ttbar_wbb->Integral(m500lowwbb,m500upwbb);
        ttbar800wbb = invariant_ttbar_wbb->Integral(m800lowwbb,m800upwbb);
        ttbar1000wbb = invariant_ttbar_wbb->Integral(m1000lowwbb,m1000upwbb);
        ttbar2000wbb = invariant_ttbar_wbb->Integral(m2000lowwbb,m2000upwbb);
        ttbar3000wbb = invariant_ttbar_wbb->Integral(m3000lowwbb,m3000upwbb);

        qcd400wbb = invariant_qcd_wbb->Integral(m400lowwbb,m400upwbb);
        qcd500wbb = invariant_qcd_wbb->Integral(m500lowwbb,m500upwbb);
        qcd800wbb = invariant_qcd_wbb->Integral(m800lowwbb,m800upwbb);
        qcd1000wbb = invariant_qcd_wbb->Integral(m1000lowwbb,m1000upwbb);
        qcd2000wbb = invariant_qcd_wbb->Integral(m2000lowwbb,m2000upwbb);
        qcd3000wbb = invariant_qcd_wbb->Integral(m3000lowwbb,m3000upwbb);



	cout << "sig400:" << sig400 << endl;
	cout << "sig500:" << sig500 << endl;
	cout << "sig800:" << sig800 << endl;
	cout << "sig1000:" << sig1000 << endl;
	cout << "sig2000:" << sig2000 << endl;
	cout << "sig3000:" << sig3000 << endl;


	eff_tb->SetPoint(0,400,(double)sig400/sqrt((double)(ttbar400+qcd400)));
	eff_tb->SetPoint(1,500,(double)sig500/sqrt((double)(ttbar500+qcd500)));
	eff_tb->SetPoint(2,800,(double)sig800/sqrt((double)(ttbar800+qcd800)));
	eff_tb->SetPoint(3,1000,(double)sig1000/sqrt((double)(ttbar1000+qcd1000)));
	eff_tb->SetPoint(4,2000,(double)sig2000/sqrt((double)(ttbar2000+qcd2000)));
	eff_tb->SetPoint(5,3000,(double)sig3000/sqrt((double)(ttbar3000+qcd3000)));

//	cout << "eff:" << (double)sig400/sqrt((double)(ttbar400+qcd400)) << endl;
//	cout << "eff:" << (double)sig500/sqrt((double)(ttbar500+qcd500)) << endl;
//	cout << "eff:" << (double)sig800/sqrt((double)(ttbar800+qcd800)) << endl;
//	cout << "eff:" << (double)sig1000/sqrt((double)(ttbar1000+qcd1000)) << endl;
	
	eff_wbb->SetPoint(0,400,(double)sig400wbb/sqrt((double)(ttbar400wbb+qcd400wbb)));
        eff_wbb->SetPoint(1,500,(double)sig500wbb/sqrt((double)(ttbar500wbb+qcd500wbb)));
        eff_wbb->SetPoint(2,800,(double)sig800wbb/sqrt((double)(ttbar800wbb+qcd800wbb)));
        eff_wbb->SetPoint(3,1000,(double)sig1000wbb/sqrt((double)(ttbar1000wbb+qcd1000wbb)));
        eff_wbb->SetPoint(4,2000,(double)sig2000wbb/sqrt((double)(ttbar2000wbb+qcd2000wbb)));
        eff_wbb->SetPoint(5,3000,(double)sig3000wbb/sqrt((double)(ttbar3000wbb+qcd3000wbb)));

	
	eff_tb->Write();
	eff_wbb->Write();

	outf->Write();
	outf->Close();


/*
	eff_tb->SetLineColor(42);
	eff_tb->SetLineWidth(2);
	eff_tb->SetMarkerColor(38);
	eff_tb->SetMarkerSize(1.5);
	eff_tb->SetMarkerStyle(21);
	eff_tb->GetYaxis()->SetRangeUser(0,0.064);



        TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        eff_tb->Draw("ACP");

        TLegend *legend4 = new TLegend(0.72,0.72,0.98,0.96);
        legend4->AddEntry(eff_tb,"effciency","CP");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/effsb_tb.png");

        eff_wbb->SetLineColor(42);
        eff_wbb->SetLineWidth(2);
        eff_wbb->SetMarkerColor(38);
        eff_wbb->SetMarkerSize(1.5);
        eff_wbb->SetMarkerStyle(21);
     //   eff_wbb->GetYaxis()->SetRangeUser(0,0.064);



        TCanvas *c = new TCanvas("c","c",800,600);
        c->cd(1);
        eff_wbb->Draw("ACP");

        TLegend *legend = new TLegend(0.72,0.72,0.98,0.96);
        legend->AddEntry(eff_wbb,"effciency","CP");
        legend->Draw("same");

        c->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/effsb_wbb.png");



        TCanvas *c4 = new TCanvas("c4","c4",800,600);
        c4->cd(1);
        ndb_pt_800->Draw("hist");
        ndb_pt_ttbar->Draw("hist same");
        ndb_pt_qcd->Draw("hist same");

        TLegend *legend4 = new TLegend(0.72,0.72,0.98,0.96);
        legend4->AddEntry(ndb_pt_800,"800GeV","l");
        legend4->AddEntry(ndb_pt_ttbar,"TTbar","l");
        legend4->AddEntry(ndb_pt_qcd,"QCD","l");
        legend4->Draw("same");

        c4->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/Bostonp/dr_2nd_b.png");



        DRPt_toph->Scale(1.0/DRPt_toph->Integral());
        DRPt_tass->Scale(1.0/DRPt_tass->Integral());
        DRPt_topplus->Scale(1.0/DRPt_topplus->Integral());
        DRPt_topminus->Scale(1.0/DRPt_topminus->Integral());

        DRPt_Wth->Scale(1.0/DRPt_Wth->Integral());
        DRPt_Wtass->Scale(1.0/DRPt_Wtass->Integral());
        DRPt_Wplus->Scale(1.0/DRPt_Wplus->Integral());
        DRPt_Wminus->Scale(1.0/DRPt_Wminus->Integral());
*/	



}
   
