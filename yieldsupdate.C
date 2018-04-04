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

const double aaano = 35.87;

void yieldsupdate(){

	setTDRStyle();

//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/lastdaynov.root");


	vector<TDirectoryFile*> categ;


	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_lowj_t0b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_lowj_wbj") );


        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_lowj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_lowj_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_lowj_wbb") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_lowj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_lowj_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_lowj_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_lowj_wbb"));

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_highj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_highj_wbj") );


        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_highj_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_highj_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_highj_wbb") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_highj_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_highj_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_highj_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_highj_wbb"));

/*
	TDirectoryFile* t0_1b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_t0b");

        TDirectoryFile* t0_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_t0b");
	TDirectoryFile* t1_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_t1b");
	TDirectoryFile* wbb_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_wbb");

	TDirectoryFile* t0_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_t0b");
        TDirectoryFile* t1_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_t1b");
        TDirectoryFile* wbb_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_wbb");
*/



	char mass[4][100];
	sprintf(mass[0],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	sprintf(mass[1],"invariantExt_WprimeToTB_TToHad_M-1000");
	sprintf(mass[2],"invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	sprintf(mass[3],"invariantExt_QCD_HT");

	

        vector<TH1D*> m1000tass;
	vector<TH1D*> m1000w;
	vector<TH1D*> ttbarhigh;
        vector<TH1D*> qcdhigh;


	for(Int_t i=0; i<18; i++) {
		m1000tass.push_back( (TH1D*)categ[i]->Get(mass[0]) );
		m1000w.push_back( (TH1D*)categ[i]->Get(mass[1]) );
		ttbarhigh.push_back( (TH1D*)categ[i]->Get(mass[2]) );
                qcdhigh.push_back( (TH1D*)categ[i]->Get(mass[3]) );
	}

        Int_t m1000low = -1, m1000up = -1;

        Double_t sig1000t = 0, sig1000w = 0, ttbar1000 = 0, qcd1000 = 0;


	TH1D* signall = new TH1D("signall","",18,0,18);
	TH1D* signalw = new TH1D("signalw","",18,0,18);
	TH1D* ttbarr = new TH1D("ttbarr","",18,0,18);
	TH1D* qcdd = new TH1D("qcdd","",18,0,18);




	for(Int_t i=0; i<18; i++) {

                m1000low = m1000tass[i]->GetXaxis()->FindBin(900.);
                m1000up  = m1000tass[i]->GetXaxis()->FindBin(1050.);


        	sig1000t = m1000tass[i]->Integral(m1000low,m1000up);

		sig1000w = m1000w[i]->Integral(m1000low,m1000up);

        	ttbar1000 = ttbarhigh[i]->Integral(m1000low,m1000up);

        	qcd1000 = qcdhigh[i]->Integral(m1000low,m1000up);
		

		signall->SetBinContent(i+1,sig1000t);
		signalw->SetBinContent(i+1,sig1000w);
		ttbarr->SetBinContent(i+1,ttbar1000);
		qcdd->SetBinContent(i+1,qcd1000);

	}




	THStack *cateyields = new THStack("cateyield","");

	ttbarr->SetFillColor(kBlue-10);
	ttbarr->SetLineColor(kBlue-10);
	ttbarr->Scale(1000*aaano);
	qcdd->SetFillColor(kGreen-10);
	qcdd->SetLineColor(kGreen-10);
	qcdd->Scale(1000*aaano);
	signall->SetLineColor(46);
	signall->SetLineWidth(2);
	signall->Scale(1000*aaano);
	signalw->SetLineColor(kOrange-3);
        signalw->SetLineWidth(2);
        signalw->Scale(1000*aaano);

	cateyields->Add(ttbarr);
	cateyields->Add(qcdd);

	TCanvas *c1a = new TCanvas("c1a","c1a",2000,800);
        c1a->cd(1);
	c1a->SetLogy();
        cateyields->Draw("hist");
	signall->Draw("hist same");
	signalw->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");

        //cateyields->GetXaxis()->SetRangeUser(600.,1400.0);
        cateyields->GetXaxis()->SetTitle("Category");
	cateyields->GetXaxis()->SetBinLabel(1,"1b_t0b");
	cateyields->GetXaxis()->SetBinLabel(2,"1b_wbj");
	cateyields->GetXaxis()->SetBinLabel(3,"2b_t0b");
	cateyields->GetXaxis()->SetBinLabel(4,"2b_t1b");
	cateyields->GetXaxis()->SetBinLabel(5,"2b_wbb");
	cateyields->GetXaxis()->SetBinLabel(6,"2b_wbj");
	cateyields->GetXaxis()->SetBinLabel(7,"#geq3b_t0b");
	cateyields->GetXaxis()->SetBinLabel(8,"#geq3b_t1b");
	cateyields->GetXaxis()->SetBinLabel(9,"#geq3b_wbb");
	cateyields->GetXaxis()->SetBinLabel(10,"1b_t0b");
        cateyields->GetXaxis()->SetBinLabel(11,"1b_wbj");
        cateyields->GetXaxis()->SetBinLabel(12,"2b_t0b");
        cateyields->GetXaxis()->SetBinLabel(13,"2b_t1b");
        cateyields->GetXaxis()->SetBinLabel(14,"2b_wbb");
        cateyields->GetXaxis()->SetBinLabel(15,"2b_wbj");
        cateyields->GetXaxis()->SetBinLabel(16,"#geq3b_t0b");
        cateyields->GetXaxis()->SetBinLabel(17,"#geq3b_t1b");
        cateyields->GetXaxis()->SetBinLabel(18,"#geq3b_wbb");

        //cateyields->GetYaxis()->SetRangeUser(1.,16000.0);
        cateyields->GetYaxis()->SetTitle("Events");

        TLegend *legend4a = new TLegend(0.63,0.74,0.85,0.88);
        legend4a->AddEntry(signall,"1000GeV,associated","l");
	legend4a->AddEntry(signalw,"1000GeV,s-channel","l");
        legend4a->AddEntry(ttbarr,"TTbar","f");
        legend4a->AddEntry(qcdd,"QCD","f");
        legend4a->Draw("same");

//        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXO/cateyields.png");
	

//	f2->Write();
//	f2->Close();

} 

/*
        Double_t max3000 = m3000[i]->GetMaximum();
	D



ouble_t m3000low = m3000[i]->FindFirstBinAbove(max3000/2);
	Double_t m3000up = m3000[i]->FindLastBinAbove(max3000/2);

	cout << "max:" << max3000 << endl;
	cout << "low:" << m3000low << endl;
	cout << "up:" << m3000up << endl;


//	TH1D* mass_tb_qcd = (TH1D*)newtb->Get("invariant_QCD_HT");
//	TH1D* mass_tb_ttbar = (TH1D*)newtb->Get("invariant_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
 
//	TH1D* invariant_wbb_800 = (TH1D*)newwbb->Get("invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8"); 
//	TH1D* invariant_wbb_ttbar = (TH1D*)newwbb->Get("invariant_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
//	TH1D* invariant_wbb_qcd = (TH1D*)newwbb->Get("invariant_QCD_HT");

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


	THStack *invariant800a = new THStack("invariant800_a"	"invariant800_a");
	THStack *invariant800b = new THStack("invariant800_b"	"invariant800_b");

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

	TCanvas *c1 = new TCanvas("c1"	"c1",800,600);
        c1->cd(1);
        b0pttb_800->Draw("hist");
	b0pttb_3000->Draw("hist same");
	b0pttb_ttbar->Draw("hist same");
	b0pttb_qcd->Draw("hist same");

        TLegend *legend1 = new TLegend(0.64,0.72,0.92,0.98);
        legend1->AddEntry(b0pttb_800,"800GeV,t+b"	"f");
        legend1->AddEntry(b0pttb_3000,"3000GeV,t+b"	"f");
        legend1->AddEntry(b0pttb_ttbar,"TTbar,t+b"	"f");
	legend1->AddEntry(b0pttb_qcd,"QCD,t+b"	"f");
        legend1->Draw("same");

        c1->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0pttb.png");	
	
        TCanvas *c2 = new TCanvas("c2"	"c2",800,600);
        c2->cd(1);
	PtAsytb_800->Draw("hist");
	PtAsytb_3000->Draw("hist same");
	PtAsytb_ttbar->Draw("hist same");
	PtAsytb_qcd->Draw("hist same");

	TLegend *legend2 = new TLegend(0.64,0.72,0.92,0.98);
        legend2->AddEntry(PtAsytb_800,"800GeV,t+b"	"f");
        legend2->AddEntry(PtAsytb_3000,"3000GeV,t+b"	"f");
        legend2->AddEntry(PtAsytb_ttbar,"TTbar,t+b"	"f");
        legend2->AddEntry(PtAsytb_qcd,"QCD,t+b"	"f");
        legend2->Draw("same");

        c2->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsytb.png");


	TCanvas *c3 = new TCanvas("c3"	"c3",800,600);
        c3->cd(1);
        dEtatb_800->Draw("hist");
        dEtatb_3000->Draw("hist same");
        dEtatb_ttbar->Draw("hist same");
        dEtatb_qcd->Draw("hist same");

        TLegend *legend3 = new TLegend(0.64,0.72,0.92,0.98);
        legend3->AddEntry(dEtatb_800,"800GeV,t+b"	"f");
        legend3->AddEntry(dEtatb_3000,"3000GeV,t+b"	"f");
        legend3->AddEntry(dEtatb_ttbar,"TTbar,t+b"	"f");
        legend3->AddEntry(dEtatb_qcd,"QCD,t+b"	"f");
        legend3->Draw("same");

        c3->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtatb.png");

	TCanvas *c4 = new TCanvas("c4"	"c4",800,600);
        c4->cd(1);
        dPhitb_800->Draw("hist");
        dPhitb_3000->Draw("hist same");
        dPhitb_ttbar->Draw("hist same");
        dPhitb_qcd->Draw("hist same");

        TLegend *legend4 = new TLegend(0.64,0.72,0.92,0.98);
        legend4->AddEntry(dPhitb_800,"800GeV,t+b"	"f");
        legend4->AddEntry(dPhitb_3000,"3000GeV,t+b"	"f");
        legend4->AddEntry(dPhitb_ttbar,"TTbar,t+b"	"f");
        legend4->AddEntry(dPhitb_qcd,"QCD,t+b"	"f");
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


        TCanvas *c5 = new TCanvas("c5"	"c5",800,600);
        c5->cd(1);
        b0ptwbb_800->Draw("hist");
        b0ptwbb_3000->Draw("hist same");
        b0ptwbb_ttbar->Draw("hist same");
        b0ptwbb_qcd->Draw("hist same");
	

        TLegend *legend5 = new TLegend(0.64,0.72,0.92,0.98);
        legend5->AddEntry(b0pttb_800,"800GeV,w+b+b"	"f");
        legend5->AddEntry(b0pttb_3000,"3000GeV,W+b+b"	"f");
        legend5->AddEntry(b0pttb_ttbar,"TTbar,W++b"	"f");
        legend5->AddEntry(b0pttb_qcd,"QCD,W+b+b"	"f");
        legend5->Draw("same");

        c5->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_b0ptwbb.png");

        TCanvas *c6 = new TCanvas("c6"	"c6",800,600);
        c6->cd(1);
        PtAsywbb_800->Draw("hist");
        PtAsywbb_3000->Draw("hist same");
        PtAsywbb_ttbar->Draw("hist same");
        PtAsywbb_qcd->Draw("hist same");

        TLegend *legend6 = new TLegend(0.64,0.72,0.92,0.98);
        legend6->AddEntry(PtAsywbb_800,"800GeV,W+b+b"	"f");
        legend6->AddEntry(PtAsywbb_3000,"3000GeV,W+b+b"	"f");
        legend6->AddEntry(PtAsywbb_ttbar,"TTbar,W+b+b"	"f");
        legend6->AddEntry(PtAsywbb_qcd,"QCD,W+b+b"	"f");
        legend6->Draw("same");

        c6->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_PtAsywbb.png");


        TCanvas *c7 = new TCanvas("c7"	"c7",800,600);
        c7->cd(1);
        dEtawbb_800->Draw("hist");
        dEtawbb_3000->Draw("hist same");
        dEtawbb_ttbar->Draw("hist same");
        dEtawbb_qcd->Draw("hist same");

        TLegend *legend7 = new TLegend(0.64,0.72,0.92,0.98);
        legend7->AddEntry(dEtawbb_800,"800GeV,W+b+b"	"f");
        legend7->AddEntry(dEtawbb_3000,"3000GeV,W+b+b"	"f");
        legend7->AddEntry(dEtawbb_ttbar,"TTbar,W+b+b"	"f");
        legend7->AddEntry(dEtawbb_qcd,"QCD,W+b+b"	"f");
        legend7->Draw("same");

        c7->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dEtawbb.png");

        TCanvas *c8 = new TCanvas("c8"	"c8",800,600);
        c8->cd(1);
        dPhiwbb_800->Draw("hist");
        dPhiwbb_3000->Draw("hist same");
        dPhiwbb_ttbar->Draw("hist same");
        dPhiwbb_qcd->Draw("hist same");

        TLegend *legend8 = new TLegend(0.64,0.72,0.92,0.98);
        legend8->AddEntry(dPhiwbb_800,"800GeV,W+b+b"	"f");
        legend8->AddEntry(dPhiwbb_3000,"3000GeV,W+b+b"	"f");
        legend8->AddEntry(dPhiwbb_ttbar,"TTbar,W+b+b"	"f");
        legend8->AddEntry(dPhiwbb_qcd,"QCD,W+b+b"	"f");
        legend8->Draw("same");

        c8->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/new_dPhiwbb.png");


	mass_tb_800->SetFillColor(46);
	mass_tb_800->Scale(1000*aaanon);
	mass_tb_ttbar->SetFillColor(38);
        mass_tb_ttbar->Scale(1000*aaanon);
	mass_tb_qcd->SetFillColor(30);
	mass_tb_qcd->Scale(1000*aaanon);


	invariant_wbb_800->SetFillColor(kRed-7);
	invariant_wbb_800->Scale(1000*aaanon);
	invariant_wbb_ttbar->SetFillColor(kBlue-9);
	invariant_wbb_ttbar->Scale(1000*aaanon);
	invariant_wbb_qcd->SetFillColor(kGreen-3);
	invariant_wbb_qcd->Scale(1000*aaanon);


	invariant800a->Add(mass_tb_800);	
	invariant800a->Add(mass_tb_ttbar);
	invariant800a->Add(mass_tb_qcd);

	invariant800b->Add(invariant_wbb_800);
	invariant800b->Add(invariant_wbb_ttbar);
	invariant800b->Add(invariant_wbb_qcd);




	gStyle->SetOptStat(1111);

        TCanvas *c1a = new TCanvas("c1a"	"c1a",800,600);
        c1a->cd(1);
        invariant800a->Draw("hist");
        invariant800a->GetXaxis()->SetRangeUser(400.,1200.0);
	invariant800a->GetYaxis()->SetRangeUser(1.,3000.0);

        TLegend *legend4a = new TLegend(0.64,0.72,0.92,0.98);
	legend4a->AddEntry(mass_tb_800,"800GeV,t+b"	"f");
        legend4a->AddEntry(mass_tb_ttbar,"TTbar,t+b"	"f");
	legend4a->AddEntry(mass_tb_qcd,"QCD,t+b"	"f");
        legend4a->Draw("same");

        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/log_tb.png");

        TCanvas *c1b = new TCanvas("c1b"	"c1b",800,600);
        c1b->cd(1);
        invariant800b->Draw("hist");
        invariant800b->GetXaxis()->SetRangeUser(400.,1200.0);
	invariant800b->GetYaxis()->SetRangeUser(1.,5000.0);

        TLegend *legend4b = new TLegend(0.64,0.72,0.92,0.98);
        legend4b->AddEntry(invariant_wbb_800,"800GeV,W+b+b"	"f");
        legend4b->AddEntry(invariant_wbb_ttbar,"TTbar,w+b+b"	"f");
        legend4b->AddEntry(invariant_wbb_qcd,"QCD,w+b+b"	"f");
        legend4b->Draw("same");

        c1b->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/log_wbb.png");
*/



//}
