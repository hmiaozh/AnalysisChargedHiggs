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
#include "TLatex.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double aaano = 35.87;

void btry(){

	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/lateAug.root");
	TFile* f2 = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/lalala.root","recreate");

	vector<TDirectoryFile*> categ;

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_tbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good") );

	TDirectoryFile *bkp1 = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");
	TDirectoryFile *bkp2 = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_thbh");




	char mass[14][100];
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

	for(Int_t i=0; i<4; i++) {

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
//		ttbarlow.push_back( (TH1D*)categ[i]->Get(mass[12]) );
//		qcdlow.push_back( (TH1D*)categ[i]->Get(mass[13]) );
//		ttbarhigh.push_back( (TH1D*)categ[i]->Get(mass[12]) );
//                qcdhigh.push_back( (TH1D*)categ[i]->Get(mass[13]) );
		if(i==0){
			m800_long[0]->Add((TH1D*)bkp1->Get(mass[8]));
			m1000_long[0]->Add((TH1D*)bkp1->Get(mass[9]));
			m2000_long[0]->Add((TH1D*)bkp1->Get(mass[10]));
			m3000_long[0]->Add((TH1D*)bkp1->Get(mass[11]));
		}else if(i==1){
			m800_long[1]->Add((TH1D*)bkp2->Get(mass[8]));
                        m1000_long[1]->Add((TH1D*)bkp2->Get(mass[9]));
                        m2000_long[1]->Add((TH1D*)bkp2->Get(mass[10]));
                        m3000_long[1]->Add((TH1D*)bkp2->Get(mass[11]));
		}
		


	}


	for(Int_t i=0; i<4; i++) {
		m400_long[i]->Rebin(3);
		m500_long[i]->Rebin(3);
//		ttbarlow[i]->Rebin(3);
//		qcdlow[i]->Rebin(3);

	
		m800_long[i]->Rebin(5);
		m1000_long[i]->Rebin(4);
		m2000_long[i]->Rebin(5);
		m3000_long[i]->Rebin(5);
//		ttbarhigh[i]->Rebin(4);
//		qcdhigh[i]->Rebin(4);
	}

	for(Int_t i=0; i<4; i++) {
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
//		m800.push_back(new TH1D(xname[8],"",18,550.,1090.));
//		m1000.push_back(new TH1D(xname[9],"",20,700.,1300.));
//		m2000.push_back(new TH1D(xname[10],"",30,1600.,2500.));
//		m3000.push_back(new TH1D(xname[11],"",40,2350.,3550.));

//		m800.push_back(new TH1D(xname[8],"",28,540.,1100.));
//                m1000.push_back(new TH1D(xname[9],"",13,710.,1360.));
//                m2000.push_back(new TH1D(xname[10],"",25,1500.,2500.));
//                m3000.push_back(new TH1D(xname[11],"",65,2200.,3500.));

                m800.push_back(new TH1D(xname[8],"",11,550.,1100.));
                m1000.push_back(new TH1D(xname[9],"",17,660.,1340.));
                m2000.push_back(new TH1D(xname[10],"",20,1600.,2600.));
                m3000.push_back(new TH1D(xname[11],"",28,2200.,3600.));




	}


	cout << "aha" << endl;

	for(Int_t i=0; i<4; i++) {

/*		for(Int_t j=1; j<17; j++){
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
		
		for(Int_t j=1; j<19; j++){
                        Double_t bincont = m800_long[i]->GetBinContent(j+15);
                        m800[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<21; j++){
                        Double_t bincont = m1000_long[i]->GetBinContent(j+20);
                        m1000[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<31; j++){	
                        Double_t bincont = m2000_long[i]->GetBinContent(j+50);
                        m2000[i]->SetBinContent(j,bincont);
		}

		for(Int_t j=1; j<41; j++){
                        Double_t bincont = m3000_long[i]->GetBinContent(j+75);
                        m3000[i]->SetBinContent(j,bincont);
		}
*/
/*  
              for(Int_t j=1; j<29; j++){
                        Double_t bincont = m800_long[i]->GetBinContent(j+22);
                        m800[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<31; j++){
                        Double_t bincont = m1000_long[i]->GetBinContent(j+30);
                        m1000[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<51; j++){
                        Double_t bincont = m2000_long[i]->GetBinContent(j+70);
                        m2000[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<66; j++){
                        Double_t bincont = m3000_long[i]->GetBinContent(j+105);
                        m3000[i]->SetBinContent(j,bincont);
                }

*/
                for(Int_t j=1; j<12; j++){
                        Double_t bincont = m800_long[i]->GetBinContent(j+9);
                        m800[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<18; j++){
                        Double_t bincont = m1000_long[i]->GetBinContent(j+14);
                        m1000[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<21; j++){
                        Double_t bincont = m2000_long[i]->GetBinContent(j+30);
                        m2000[i]->SetBinContent(j,bincont);
                }

                for(Int_t j=1; j<29; j++){
                        Double_t bincont = m3000_long[i]->GetBinContent(j+42);
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
//	cat[1] = new TGraph(6);
//	cat[2] = new TGraph(6);
//	cat[3] = new TGraph(6);
//	cat[0] = new TGraph(6);

	for(Int_t i=0; i<4; i++) {
/*		m180low = m180[i]->FindFirstBinAbove(m180[i]->GetMaximum()/2);
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
*/		
		m800low = m800[i]->FindFirstBinAbove(m800[i]->GetMaximum()/2);
                m800up  = m800[i]->FindLastBinAbove(m800[i]->GetMaximum()/2);

                m1000low = m1000[i]->FindFirstBinAbove(m1000[i]->GetMaximum()/2);
                m1000up  = m1000[i]->FindLastBinAbove(m1000[i]->GetMaximum()/2);

                m2000low = m2000[i]->FindFirstBinAbove(m2000[i]->GetMaximum()/2);
                m2000up  = m2000[i]->FindLastBinAbove(m2000[i]->GetMaximum()/2);

                m3000low = m3000[i]->FindFirstBinAbove(m3000[i]->GetMaximum()/2);
                m3000up  = m3000[i]->FindLastBinAbove(m3000[i]->GetMaximum()/2);

		double width800 = 50.*(m800up-m800low);
                double width1000 = 40.*(m1000up-m1000low);
                double width2000 = 50.*(m2000up-m2000low);
                double width3000 = 50.*(m3000up-m3000low);



		cout << "catagory " << i << ":" << endl;
//		cout << "180: " << m180low << "	" << m180up << endl;
//		cout << "200: " << m200low << "	" << m200up << endl;
//		cout << "220: " << m220low << "	" << m220up << endl;
//		cout << "250: " << m250low << "	" << m250up << endl;
//                cout << "300: " << m300low << "	" << m300up << endl;
//                cout << "350: " << m350low << "	" << m350up << endl;
//		cout << "400: " << m400low << "	" << m400up << endl;
//                cout << "500: " << m500low << "	" << m500up << endl;
                cout << "800: " << m800low << "	" << m800up << "  width: " << width800 << endl;
                cout << "1000: " << m1000low << " " << m1000up << "  width: " << width1000 << endl;
                cout << "2000: " << m2000low << " " << m2000up << "  width: " << width2000 << endl;
                cout << "3000: " << m3000low << " " << m3000up << "  width: " << width3000 << endl; 
/*
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
*/



	//	cat[i]->SetPoint(1,400,30*(m400up-m400low));
	//	cat[i]->SetPoint(2,500,30*(m500up-m500low));
		cat[i]->SetPoint(0,800,width800);
		cat[i]->SetPoint(1,1000,width1000);
		cat[i]->SetPoint(2,2000,width2000);
		cat[i]->SetPoint(3,3000,width3000);


//		signall->SetBinContent(i+1,sig1000);
//		ttbarr->SetBinContent(i+1,ttbar1000);
//		qcdd->SetBinContent(i+1,qcd1000);

	}

	cat[0]->SetMarkerColor(46);
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
	
	cat[3]->GetXaxis()->SetTitle("M_{H^{+}}");
	cat[3]->GetYaxis()->SetTitle("width[GeV]");
	cat[3]->Draw("ACP");
        cat[0]->Draw("CP");
        cat[1]->Draw("CP");
        cat[2]->Draw("CP");

	const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");


        TLegend *legende = new TLegend(0.72,0.72,0.98,0.96);
        legende->AddEntry(cat[0],"t0b","LP");
        legende->AddEntry(cat[1],"t1b","LP");
        legende->AddEntry(cat[2],"wbb","LP");
        legende->AddEntry(cat[3],"wbj","LP");
        legende->Draw("same");

//        ce->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXOup/corrected_width_mass_b.png");


//	f2->Write();
//	f2->Close();

} 

