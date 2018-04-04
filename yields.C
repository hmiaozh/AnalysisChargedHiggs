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

void yields(){

	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/SoHot.root");
	TFile* f2 = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/lalala.root","recreate");

	vector<TDirectoryFile*> categ;
/*
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_tbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good") );
*/


	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_t0b") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_one_wbj") );


        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_t0b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_t1b") );
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_wbb") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_two_wbj") );

        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_t0b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_t1b"));
        categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneMirrorFat_three_wbb"));

/*
	TDirectoryFile* t0_1b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_one_t0b");

        TDirectoryFile* t0_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_t0b");
	TDirectoryFile* t1_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_t1b");
	TDirectoryFile* wbb_2b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_two_wbb");

	TDirectoryFile* t0_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_t0b");
        TDirectoryFile* t1_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_t1b");
        TDirectoryFile* wbb_3b = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_three_wbb");
*/

/*	char mass[14][100];
        sprintf(mass[0],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-180_13TeV_amcatnlo_pythia8");
        sprintf(mass[1],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-200_13TeV_amcatnlo_pythia8");
        sprintf(mass[2],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-220_13TeV_amcatnlo_pythia8");
        sprintf(mass[3],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-250_13TeV_amcatnlo_pythia8");
        sprintf(mass[4],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-300_13TeV_amcatnlo_pythia8");
        sprintf(mass[5],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-350_13TeV_amcatnlo_pythia8");
        sprintf(mass[6],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
        sprintf(mass[7],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
        sprintf(mass[8],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        sprintf(mass[9],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        sprintf(mass[10],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
        sprintf(mass[11],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
        sprintf(mass[12],"invariant_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
        sprintf(mass[13],"invariant_QCD_HT");
*/


	char mass[14][100];
	sprintf(mass[0],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-180_13TeV_amcatnlo_pythia8");
	sprintf(mass[1],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-200_13TeV_amcatnlo_pythia8");
	sprintf(mass[2],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-220_13TeV_amcatnlo_pythia8");
	sprintf(mass[3],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-250_13TeV_amcatnlo_pythia8");
	sprintf(mass[4],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-300_13TeV_amcatnlo_pythia8");
	sprintf(mass[5],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-350_13TeV_amcatnlo_pythia8");
	sprintf(mass[6],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
	sprintf(mass[7],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
	sprintf(mass[8],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	sprintf(mass[9],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	sprintf(mass[10],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
	sprintf(mass[11],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	sprintf(mass[12],"invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	sprintf(mass[13],"invariant_QCD_HT");


	vector<TH1D*> m180_long;
        vector<TH1D*> m200_long;
        vector<TH1D*> m220_long;
        vector<TH1D*> m250_long;
        vector<TH1D*> m300_long;
        vector<TH1D*> m350_long;
        vector<TH1D*> m400_long;
        vector<TH1D*> m500_long;
        vector<TH1D*> m800_long;
        vector<TH1D*> m1000_long;
        vector<TH1D*> m2000_long;
        vector<TH1D*> m3000_long;
	vector<TH1D*> ttbarlow;
	vector<TH1D*> qcdlow;
	vector<TH1D*> ttbarhigh;
        vector<TH1D*> qcdhigh;

	vector<TH1D*> m180;
	vector<TH1D*> m200;
	vector<TH1D*> m220;
	vector<TH1D*> m250;
	vector<TH1D*> m300;
	vector<TH1D*> m350;
	vector<TH1D*> m400;
        vector<TH1D*> m500;
        vector<TH1D*> m800;
        vector<TH1D*> m1000;
        vector<TH1D*> m2000;
        vector<TH1D*> m3000;

	for(Int_t i=0; i<9; i++) {

		m180_long.push_back( (TH1D*)categ[i]->Get(mass[0]) );
		m200_long.push_back( (TH1D*)categ[i]->Get(mass[1]) );
		m220_long.push_back( (TH1D*)categ[i]->Get(mass[2]) );
		m250_long.push_back( (TH1D*)categ[i]->Get(mass[3]) );
		m300_long.push_back( (TH1D*)categ[i]->Get(mass[4]) );
		m350_long.push_back( (TH1D*)categ[i]->Get(mass[5]) );
		m400_long.push_back( (TH1D*)categ[i]->Get(mass[6]) );
		m500_long.push_back( (TH1D*)categ[i]->Get(mass[7]) );
		m800_long.push_back( (TH1D*)categ[i]->Get(mass[8]) );
		m1000_long.push_back( (TH1D*)categ[i]->Get(mass[9]) );
		m2000_long.push_back( (TH1D*)categ[i]->Get(mass[10]) );
		m3000_long.push_back( (TH1D*)categ[i]->Get(mass[11]) );
		ttbarlow.push_back( (TH1D*)categ[i]->Get(mass[12]) );
		qcdlow.push_back( (TH1D*)categ[i]->Get(mass[13]) );
		ttbarhigh.push_back( (TH1D*)categ[i]->Get(mass[12]) );
                qcdhigh.push_back( (TH1D*)categ[i]->Get(mass[13]) );
	}


	for(Int_t i=0; i<9; i++) {
		m400_long[i]->Rebin(3);
		m500_long[i]->Rebin(3);
		ttbarlow[i]->Rebin(3);
		qcdlow[i]->Rebin(3);

	
		m800_long[i]->Rebin(4);
		m1000_long[i]->Rebin(4);
		m2000_long[i]->Rebin(4);
		m3000_long[i]->Rebin(4);
		ttbarhigh[i]->Rebin(4);
		qcdhigh[i]->Rebin(4);
	}

	for(Int_t i=0; i<9; i++) {
		char xname[12][50];


		sprintf(xname[0],"m180_category_%i",i);  //category = 0-6: 1/2/3 bjet, t1b/t0b/2bb
		sprintf(xname[1],"m200_category_%i",i);
		sprintf(xname[2],"m220_category_%i",i);
		sprintf(xname[3],"m250_category_%i",i);
		sprintf(xname[4],"m300_category_%i",i);  //category = 0-6: 1/2/3 bjet, t1b/t0b/2bb
                sprintf(xname[5],"m350_category_%i",i);
                sprintf(xname[6],"m400_category_%i",i);
                sprintf(xname[7],"m500_category_%i",i);
		sprintf(xname[8],"m800_category_%i",i);  //category = 0-6: 1/2/3 bjet, t1b/t0b/2bb
                sprintf(xname[9],"m1000_category_%i",i);
                sprintf(xname[10],"m2000_category_%i",i);
                sprintf(xname[11],"m3000_category_%i",i);		



		m180.push_back(new TH1D(xname[0],"",16,100.,260.));
		m200.push_back(new TH1D(xname[1],"",16,120.,280.));
		m220.push_back(new TH1D(xname[2],"",16,140.,300.));
		m250.push_back(new TH1D(xname[3],"",16,170.,330.));
		m300.push_back(new TH1D(xname[4],"",18,210.,390.));
		m350.push_back(new TH1D(xname[5],"",18,260.,440.));
		m400.push_back(new TH1D(xname[6],"",8,280.,520.));
		m500.push_back(new TH1D(xname[7],"",9,370.,640.));
		m800.push_back(new TH1D(xname[8],"",15,500.,1100.));
		m1000.push_back(new TH1D(xname[9],"",17,660.,1340.));
		m2000.push_back(new TH1D(xname[10],"",25,1500.,2500.));
		m3000.push_back(new TH1D(xname[11],"",29,2420.,3580.));

	}


	cout << "aha" << endl;

	for(Int_t i=0; i<9; i++) {

		for(Int_t j=1; j<17; j++){
			Double_t bincont = m180_long[i]->GetBinContent(j);
			m180[i]->SetBinContent(j,bincont);

			bincont = m200_long[i]->GetBinContent(j+2);
                        m200[i]->SetBinContent(j,bincont);

			bincont = m220_long[i]->GetBinContent(j+4);
                        m220[i]->SetBinContent(j,bincont);
	
			bincont = m250_long[i]->GetBinContent(j+7);
                        m250[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<19; j++){
			Double_t bincont = m300_long[i]->GetBinContent(j+11);
                        m300[i]->SetBinContent(j,bincont);

			bincont = m350_long[i]->GetBinContent(j+16);
                        m350[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<9; j++){
			Double_t bincont = m400_long[i]->GetBinContent(j+6);
                        m400[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<10; j++){
                        Double_t bincont = m500_long[i]->GetBinContent(j+9);
                        m500[i]->SetBinContent(j,bincont);
		}
		
		for(Int_t j=1; j<16; j++){
                        Double_t bincont = m800_long[i]->GetBinContent(j+10);
                        m800[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<18; j++){
                        Double_t bincont = m1000_long[i]->GetBinContent(j+14);
                        m1000[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<26; j++){	
                        Double_t bincont = m2000_long[i]->GetBinContent(j+35);
                        m2000[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<30; j++){
                        Double_t bincont = m3000_long[i]->GetBinContent(j+58);
                        m3000[i]->SetBinContent(j,bincont);
		}
	}


	cout << "what's wrong" << endl;



	Int_t m180low = -1, m180up = -1;
        Int_t m200low = -1, m200up = -1;
        Int_t m220low = -1, m220up = -1;
        Int_t m250low = -1, m250up = -1;
        Int_t m300low = -1, m300up = -1;
        Int_t m350low = -1, m350up = -1;
	Int_t m400low = -1, m400up = -1;
        Int_t m500low = -1, m500up = -1;
        Int_t m800low = -1, m800up = -1;
        Int_t m1000low = -1, m1000up = -1;
        Int_t m2000low = -1, m2000up = -1;
        Int_t m3000low = -1, m3000up = -1;

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


	TH1D* signall = new TH1D("signall","",9,0,9);
	TH1D* ttbarr = new TH1D("ttbarr","",9,0,9);
	TH1D* qcdd = new TH1D("qcdd","",9,0,9);


	vector<TGraph*> cat;

	for(Int_t i=0; i<4; i++) {
	cat.push_back(new TGraph(4));
	}

	for(Int_t i=0; i<9; i++) {
		m180low = m180[i]->FindFirstBinAbove(m180[i]->GetMaximum()/2);
		m180up  = m180[i]->FindLastBinAbove(m180[i]->GetMaximum()/2);

		m200low = m200[i]->FindFirstBinAbove(m200[i]->GetMaximum()/2);
                m200up  = m200[i]->FindLastBinAbove(m200[i]->GetMaximum()/2);

		m220low = m220[i]->FindFirstBinAbove(m220[i]->GetMaximum()/2);
                m220up  = m220[i]->FindLastBinAbove(m220[i]->GetMaximum()/2);
	
		m250low = m250[i]->FindFirstBinAbove(m250[i]->GetMaximum()/2);
                m250up  = m250[i]->FindLastBinAbove(m250[i]->GetMaximum()/2);

		m300low = m300[i]->FindFirstBinAbove(m300[i]->GetMaximum()/2);
                m300up  = m300[i]->FindLastBinAbove(m300[i]->GetMaximum()/2);

		m350low = m350[i]->FindFirstBinAbove(m350[i]->GetMaximum()/2);
                m350up  = m350[i]->FindLastBinAbove(m350[i]->GetMaximum()/2);

		m400low = m400[i]->FindFirstBinAbove(m400[i]->GetMaximum()/2);
                m400up  = m400[i]->FindLastBinAbove(m400[i]->GetMaximum()/2);

		m500low = m500[i]->FindFirstBinAbove(m500[i]->GetMaximum()/2);
                m500up  = m500[i]->FindLastBinAbove(m500[i]->GetMaximum()/2);
		
		m800low = m800[i]->FindFirstBinAbove(m800[i]->GetMaximum()/2);
                m800up  = m800[i]->FindLastBinAbove(m800[i]->GetMaximum()/2);

                m1000low = m1000[i]->FindFirstBinAbove(m1000[i]->GetMaximum()/2);
                m1000up  = m1000[i]->FindLastBinAbove(m1000[i]->GetMaximum()/2);

                m2000low = m2000[i]->FindFirstBinAbove(m2000[i]->GetMaximum()/2);
                m2000up  = m2000[i]->FindLastBinAbove(m2000[i]->GetMaximum()/2);

                m3000low = m3000[i]->FindFirstBinAbove(m3000[i]->GetMaximum()/2);
                m3000up  = m3000[i]->FindLastBinAbove(m3000[i]->GetMaximum()/2);

		cout << "catagory " << i << ":" << endl;
		cout << "180: " << m180low << "	" << m180up << endl;
		cout << "200: " << m200low << "	" << m200up << endl;
		cout << "220: " << m220low << "	" << m220up << endl;
		cout << "250: " << m250low << "	" << m250up << endl;
                cout << "300: " << m300low << "	" << m300up << endl;
                cout << "350: " << m350low << "	" << m350up << endl;
		cout << "400: " << m400low << "	" << m400up << endl;
                cout << "500: " << m500low << "	" << m500up << endl;
                cout << "800: " << m800low << "	" << m800up << endl;
                cout << "1000: " << m1000low << "	" << m1000up << endl;
                cout << "2000: " << m2000low << "	" << m2000up << endl;
                cout << "3000: " << m3000low << "	" << m3000up << endl; 

		sig400 = m400[i]->Integral(m400low,m400up);
        	sig500 = m500[i]->Integral(m500low,m500up);
        	sig800 = m800[i]->Integral(m800low,m800up);
        	sig1000 = m1000[i]->Integral(m1000low,m1000up);
        	sig2000 = m2000[i]->Integral(m2000low,m2000up);
        	sig3000 = m3000[i]->Integral(m3000low,m3000up);

        	ttbar400 = ttbarlow[i]->Integral(m400low,m400up);
        	ttbar500 = ttbarlow[i]->Integral(m500low,m500up);
        	ttbar800 = ttbarhigh[i]->Integral(m800low,m800up);
        	ttbar1000 = ttbarhigh[i]->Integral(m1000low,m1000up);
        	ttbar2000 = ttbarhigh[i]->Integral(m2000low,m2000up);
        	ttbar3000 = ttbarhigh[i]->Integral(m3000low,m3000up);

        	qcd400 = qcdlow[i]->Integral(m400low,m400up);
        	qcd500 = qcdlow[i]->Integral(m500low,m500up);
        	qcd800 = qcdhigh[i]->Integral(m800low,m800up);
        	qcd1000 = qcdhigh[i]->Integral(m1000low,m1000up);
        	qcd2000 = qcdhigh[i]->Integral(m2000low,m2000up);
        	qcd3000 = qcdhigh[i]->Integral(m3000low,m3000up);
		

		cout << "400: " << aaano*1000*sig400 << "\t" << aaano*1000*ttbar400 << "\t" << aaano*1000*qcd400 << endl;
		cout << "500: " << aaano*1000*sig500 << "\t" << aaano*1000*ttbar500 << "\t" << aaano*1000*qcd500 << endl;
		cout << "800: " << aaano*1000*sig800 << "\t" << aaano*1000*ttbar800 << "\t" << aaano*1000*qcd800 << endl;
		cout << "1000: " << aaano*1000*sig1000 << "\t" << aaano*1000*ttbar1000 << "\t" << aaano*1000*qcd1000 << endl;
		cout << "2000: " << aaano*1000*sig2000 << "\t" << aaano*1000*ttbar2000 << "\t" << aaano*1000*qcd2000 << endl;
		cout << "3000: " << aaano*1000*sig3000 << "\t" << aaano*1000*ttbar3000 << "\t" << aaano*1000*qcd3000 << endl;

/*
		cat[i]->SetPoint(0,400,30*(m400up-m400low));
		cat[i]->SetPoint(1,500,30*(m500up-m500low));
		cat[i]->SetPoint(0,800,40*(m800up-m800low));
		cat[i]->SetPoint(1,1000,40*(m1000up-m1000low));
		cat[i]->SetPoint(2,2000,40*(m2000up-m2000low));
		cat[i]->SetPoint(3,3000,40*(m3000up-m3000low));
*/

		signall->SetBinContent(i+1,sig1000);
		ttbarr->SetBinContent(i+1,ttbar1000);
		qcdd->SetBinContent(i+1,qcd1000);

	}

/*	cat[0]->SetMarkerColor(46);
	cat[0]->SetLineColor(46);
	cat[0]->SetMarkerStyle(20);
	cat[0]->SetMarkerSize(1.5);

	cat[1]->SetMarkerColor(8);
	cat[1]->SetLineColor(8);
        cat[1]->SetMarkerStyle(29);
        cat[1]->SetMarkerSize(1.5);

	cat[2]->SetMarkerColor(38);
	cat[2]->SetLineColor(38);
        cat[2]->SetMarkerStyle(22);
        cat[2]->SetMarkerSize(1.5);

	cat[3]->SetMarkerColor(kPink+1);
	cat[3]->SetLineColor(kPink+1);
        cat[3]->SetMarkerStyle(21);
        cat[3]->SetMarkerSize(1.5);


	TCanvas *ce = new TCanvas("ce","ce",800,600);
        ce->cd(1);
	
	cat[3]->Draw("CAP");
        cat[0]->Draw("CP");
        cat[1]->Draw("CP");
        cat[2]->Draw("CP");

        TLegend *legende = new TLegend(0.72,0.72,0.98,0.96);
        legende->AddEntry(cat[0],"t0b","P");
        legende->AddEntry(cat[1],"t1b","P");
        legende->AddEntry(cat[2],"wbb","P");
        legende->AddEntry(cat[3],"wbj","P");
        legende->Draw("same");

        ce->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXO/corrected_width_mass.png");
*/

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


	cateyields->Add(ttbarr);
	cateyields->Add(qcdd);

	TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
	c1a->SetLogy();
        cateyields->Draw("hist");
	signall->Draw("hist same");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "cms #scale[0.8]{#bf{#it{internal}}}");

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

        //cateyields->GetYaxis()->SetRangeUser(1.,16000.0);
        cateyields->GetYaxis()->SetTitle("Events");

        TLegend *legend4a = new TLegend(0.63,0.74,0.85,0.88);
        legend4a->AddEntry(signall,"1000GeV","l");
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
