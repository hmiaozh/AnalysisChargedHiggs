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
const int bnum = 1;
const int bnumwbj = 3;

void ctry(){

	setTDRStyle();
	
	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/refineleadb.root");
//	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/widthnewyear.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/marchwidth.root");
	
	vector<TDirectoryFile*> categ;
	vector<TDirectoryFile*> cateb;

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_thbh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh") );
	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good") );

	cateb.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh") );
        cateb.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_thbh") );
	cateb.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh") );
        cateb.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good") );


	TDirectoryFile *bkp1 = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh");
        TDirectoryFile *bkp2 = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t1b_tbh");



	char mass[9][100];
	sprintf(mass[0],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
	sprintf(mass[1],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
	sprintf(mass[2],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
	sprintf(mass[3],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	sprintf(mass[4],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	sprintf(mass[5],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-1500_13TeV_amcatnlo_pythia8");
	sprintf(mass[6],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
	sprintf(mass[7],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-2500_13TeV_amcatnlo_pythia8");
	sprintf(mass[8],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");


	char massa[11][100];
        sprintf(massa[0],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
        sprintf(massa[1],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
	sprintf(massa[2],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-650_13TeV_amcatnlo_pythia8");
        sprintf(massa[3],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        sprintf(massa[4],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        sprintf(massa[5],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1500_13TeV_amcatnlo_pythia8");
        sprintf(massa[6],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
	sprintf(massa[7],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-2500_13TeV_amcatnlo_pythia8");
        sprintf(massa[8],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	sprintf(massa[9],"invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	sprintf(massa[10],"invariantExt_QCD_HT");


	cout << "shenmegui" << endl;

	vector<TH1D*> m400;
        vector<TH1D*> m500;
	vector<TH1D*> m650;
        vector<TH1D*> m800;
        vector<TH1D*> m1000;
        vector<TH1D*> m1500;
        vector<TH1D*> m2000;
	vector<TH1D*> m2500;
        vector<TH1D*> m3000;


        vector<TH1D*> m400a;
        vector<TH1D*> m500a;
	vector<TH1D*> m650a;
        vector<TH1D*> m800a;
        vector<TH1D*> m1000a;
	vector<TH1D*> m1500a;
        vector<TH1D*> m2000a;
	vector<TH1D*> m2500a;
        vector<TH1D*> m3000a;
	vector<TH1D*> ttbarlow;
	vector<TH1D*> qcdlow;
	vector<TH1D*> ttbarhigh;
        vector<TH1D*> qcdhigh;


	for(Int_t i=0; i<4; i++) {
		if(i!=3){
		m400.push_back( (TH1D*)categ[i]->Get(mass[0]) );
		m500.push_back( (TH1D*)categ[i]->Get(mass[1]) );
		m650.push_back( (TH1D*)categ[i]->Get(mass[2]) );
		m800.push_back( (TH1D*)categ[i]->Get(mass[3]) );
		m1000.push_back( (TH1D*)categ[i]->Get(mass[4]) );
		m1500.push_back( (TH1D*)categ[i]->Get(mass[5]) );
		m2000.push_back( (TH1D*)categ[i]->Get(mass[6]) );
		m2500.push_back( (TH1D*)categ[i]->Get(mass[7]) );
		m3000.push_back( (TH1D*)categ[i]->Get(mass[8]) );
		}else{
		m400.push_back( (TH1D*)cateb[i]->Get(mass[0]) );
                m500.push_back( (TH1D*)cateb[i]->Get(mass[1]) );
                m650.push_back( (TH1D*)cateb[i]->Get(mass[2]) );
                m800.push_back( (TH1D*)cateb[i]->Get(mass[3]) );
                m1000.push_back( (TH1D*)cateb[i]->Get(mass[4]) );
                m1500.push_back( (TH1D*)cateb[i]->Get(mass[5]) );
                m2000.push_back( (TH1D*)cateb[i]->Get(mass[6]) );
                m2500.push_back( (TH1D*)cateb[i]->Get(mass[7]) );
                m3000.push_back( (TH1D*)cateb[i]->Get(mass[8]) );
		}
		m400a.push_back( (TH1D*)cateb[i]->Get(massa[0]) );
                m500a.push_back( (TH1D*)cateb[i]->Get(massa[1]) );
		m650a.push_back( (TH1D*)cateb[i]->Get(massa[2]) );
                m800a.push_back( (TH1D*)cateb[i]->Get(massa[3]) );
                m1000a.push_back( (TH1D*)cateb[i]->Get(massa[4]) );
                m1500a.push_back( (TH1D*)cateb[i]->Get(massa[5]) );
                m2000a.push_back( (TH1D*)cateb[i]->Get(massa[6]) );
		m2500a.push_back( (TH1D*)cateb[i]->Get(massa[7]) );
                m3000a.push_back( (TH1D*)cateb[i]->Get(massa[8]) );
		//ttbarlow.push_back( (TH1D*)cateb[i]->Get(mass[12]) );
		//qcdlow.push_back( (TH1D*)cateb[i]->Get(mass[13]) );
		ttbarhigh.push_back( (TH1D*)cateb[i]->Get(massa[9]) );
                qcdhigh.push_back( (TH1D*)cateb[i]->Get(massa[10]) );
		/*
		if(i==0){
			m400[0]->Add((TH1D*)bkp1->Get(mass[0]));
                        m500[0]->Add((TH1D*)bkp1->Get(mass[1]));
			m650[0]->Add((TH1D*)bkp1->Get(mass[2]));
                        m800[0]->Add((TH1D*)bkp1->Get(mass[3]));
                        m1000[0]->Add((TH1D*)bkp1->Get(mass[4]));
			m1500[0]->Add((TH1D*)bkp1->Get(mass[5]));
                        m2000[0]->Add((TH1D*)bkp1->Get(mass[6]));
			m2500[0]->Add((TH1D*)bkp1->Get(mass[7]));
                        m3000[0]->Add((TH1D*)bkp1->Get(mass[8]));
                }else if(i==1){
			m400[1]->Add((TH1D*)bkp2->Get(mass[0]));
                        m500[1]->Add((TH1D*)bkp2->Get(mass[1]));
			m650[1]->Add((TH1D*)bkp2->Get(mass[2]));
                        m800[1]->Add((TH1D*)bkp2->Get(mass[3]));
                        m1000[1]->Add((TH1D*)bkp2->Get(mass[4]));
			m1500[1]->Add((TH1D*)bkp2->Get(mass[5]));
                        m2000[1]->Add((TH1D*)bkp2->Get(mass[6]));
			m2500[1]->Add((TH1D*)bkp2->Get(mass[7]));
                        m3000[1]->Add((TH1D*)bkp2->Get(mass[8]));
                }
		*/
	}

	cout << "yaosia" << endl;


	for(Int_t i=0; i<4; i++) {
		m400[i]->Rebin(bnum);
		m500[i]->Rebin(bnum);
		
		if(i!=3){
		m650[i]->Rebin(bnum);
		m800[i]->Rebin(bnum);
		m1000[i]->Rebin(bnum);
		m1500[i]->Rebin(bnum);
		m2000[i]->Rebin(bnum);
		m2500[i]->Rebin(bnum);
		m3000[i]->Rebin(bnum);
		}else{
		m650[i]->Rebin(bnum);
                m800[i]->Rebin(bnum);
                m1000[i]->Rebin(bnum);
                m1500[i]->Rebin(bnum);
                m2000[i]->Rebin(bnum);
                m2500[i]->Rebin(bnumwbj);
                m3000[i]->Rebin(bnumwbj);
		}
/*
		m400a[i]->Rebin(3);
                m500a[i]->Rebin(3);
//              ttbarlow[i]->Rebin(3);
//              qcdlow[i]->Rebin(3);
		
		m650a[i]->Rebin(bnum);
		m800a[i]->Rebin(bnum);
                m1000a[i]->Rebin(bnum);
                m1500a[i]->Rebin(bnum);
                m2000a[i]->Rebin(bnum);
		m2500a[i]->Rebin(bnum);
                m3000a[i]->Rebin(bnum);
//		ttbarhigh[i]->Rebin(bnum);
//		qcdhigh[i]->Rebin(bnum);
*/
	}


	cout << "youzale" << endl;

	Int_t m400low = -1, m400up = -1;
        Int_t m500low = -1, m500up = -1;
	Int_t m650low = -1, m650up = -1;
        Int_t m800low = -1, m800up = -1;
        Int_t m1000low = -1, m1000up = -1;
	Int_t m1500low = -1, m1500up = -1;
        Int_t m2000low = -1, m2000up = -1;
	Int_t m2500low = -1, m2500up = -1;
        Int_t m3000low = -1, m3000up = -1;

	Double_t sig400 = 0, ttbar400 = 0, qcd400 = 0;
        Double_t sig500 = 0, ttbar500 = 0, qcd500 = 0;
	Double_t sig650 = 0, ttbar650 = 0, qcd650 = 0;
        Double_t sig800 = 0, ttbar800 = 0, qcd800 = 0;
        Double_t sig1000 = 0, ttbar1000 = 0, qcd1000 = 0;
	Double_t sig1500 = 0, ttbar1500 = 0, qcd1500 = 0;
        Double_t sig2000 = 0, ttbar2000 = 0, qcd2000 = 0;
	Double_t sig2500 = 0, ttbar2500 = 0, qcd2500 = 0;
        Double_t sig3000 = 0, ttbar3000 = 0, qcd3000 = 0;

        Double_t sig2000wbb = 0, ttbar2000wbb = 0, qcd2000wbb = 0;
        Double_t sig3000wbb = 0, ttbar3000wbb = 0, qcd3000wbb = 0;




	vector<TGraph*> cat;

	for(Int_t i=0; i<4; i++) {
		cat.push_back(new TGraph());
	}

	for(Int_t i=0; i<4; i++) {
		m400low = m400[i]->FindFirstBinAbove(m400[i]->GetMaximum()/2);
                m400up  = m400[i]->FindLastBinAbove(m400[i]->GetMaximum()/2);

		m500low = m500[i]->FindFirstBinAbove(m500[i]->GetMaximum()/2);
                m500up  = m500[i]->FindLastBinAbove(m500[i]->GetMaximum()/2);    
		
		m650low = m650[i]->FindFirstBinAbove(m650[i]->GetMaximum()/2);
                m650up  = m650[i]->FindLastBinAbove(m650[i]->GetMaximum()/2);

		m800low = m800[i]->FindFirstBinAbove(m800[i]->GetMaximum()/2);
                m800up  = m800[i]->FindLastBinAbove(m800[i]->GetMaximum()/2);

                m1000low = m1000[i]->FindFirstBinAbove(m1000[i]->GetMaximum()/2);
                m1000up  = m1000[i]->FindLastBinAbove(m1000[i]->GetMaximum()/2);

		m1500low = m1500[i]->FindFirstBinAbove(m1500[i]->GetMaximum()/2);
                m1500up  = m1500[i]->FindLastBinAbove(m1500[i]->GetMaximum()/2);

                m2000low = m2000[i]->FindFirstBinAbove(m2000[i]->GetMaximum()/2);
                m2000up  = m2000[i]->FindLastBinAbove(m2000[i]->GetMaximum()/2);

		m2500low = m2500[i]->FindFirstBinAbove(m2500[i]->GetMaximum()/2);
                m2500up  = m2500[i]->FindLastBinAbove(m2500[i]->GetMaximum()/2);

                m3000low = m3000[i]->FindFirstBinAbove(m3000[i]->GetMaximum()/2);
		m3000up  = m3000[i]->FindLastBinAbove(m3000[i]->GetMaximum()/2);

		cout << "catagory " << i << ":" << endl;
		cout << "400: " << m400low << " , " << m400low*10+90 << "		" << m400up << " , " << m400up*10+100 << endl;
                cout << "500: " << m500low << " , " << m500low*10+90 << "		" << m500up << " , " << m500up*10+100 << endl;
		cout << "650: " << m650low << " , " << m650low*10+90 << "	" << m650up << " , " << m650up*10+100 << endl;
                cout << "800: " << m800low << " , " << m800low*10+90 << "	" << m800up << " , " << m800up*10+100 << endl;
                cout << "1000: " << m1000low << " , " << m1000low*10+90 << "	" << m1000up << " , " << m1000up*10+100 << endl;
		cout << "1500: " << m1500low << " , " << m1500low*10+90 << "	" << m1500up << " , " << m1500up*10+100 << endl;
                cout << "2000: " << m2000low << " , " << m2000low*10+90 << "	" << m2000up << " , " << m2000up*10+100 << endl;
		cout << "2500: " << m2500low << " , " << m2500low*10+90 << "	" << m2500up << " , " << m2500up*10+100 << endl;
                cout << "3000: " << m3000low << " , " << m3000low*10+90 << "	" << m3000up << " , " << m3000up*10+100 << endl; 
/*
//		sig400 = m400a[i]->Integral(m400low,m400up);
//        	sig500 = m500a[i]->Integral(m500low,m500up);
		sig650 = m650a[i]->Integral(m650low,m650up);
        	sig800 = m800a[i]->Integral(m800low,m800up);
        	sig1000 = m1000a[i]->Integral(m1000low,m1000up);
		sig1500 = m1500a[i]->Integral(m1500low,m1500up);
        	sig2000 = m2000a[i]->Integral(m2000low,m2000up);
		sig2500 = m2500a[i]->Integral(m2500low,m2500up);
        	sig3000 = m3000a[i]->Integral(m3000low,m3000up);

//        	ttbar400 = ttbarlow[i]->Integral(m400low,m400up);
//        	ttbar500 = ttbarlow[i]->Integral(m500low,m500up);
		ttbar650 = ttbarlow[i]->Integral(m650low,m650up);
        	ttbar800 = ttbarhigh[i]->Integral(m800low,m800up);
        	ttbar1000 = ttbarhigh[i]->Integral(m1000low,m1000up);
		ttbar1500 = ttbarhigh[i]->Integral(m1500low,m1500up);
        	ttbar2000 = ttbarhigh[i]->Integral(m2000low,m2000up);
		ttbar2500 = ttbarhigh[i]->Integral(m2500low,m2500up);
        	ttbar3000 = ttbarhigh[i]->Integral(m3000low,m3000up);

//        	qcd400 = qcdlow[i]->Integral(m400low,m400up);
//        	qcd500 = qcdlow[i]->Integral(m500low,m500up);
		qcd650 = qcdlow[i]->Integral(m650low,m650up);
        	qcd800 = qcdhigh[i]->Integral(m800low,m800up);
        	qcd1000 = qcdhigh[i]->Integral(m1000low,m1000up);
		qcd1500 = qcdhigh[i]->Integral(m1500low,m1500up);
        	qcd2000 = qcdhigh[i]->Integral(m2000low,m2000up);
		qcd2500 = qcdhigh[i]->Integral(m2500low,m2500up);
        	qcd3000 = qcdhigh[i]->Integral(m3000low,m3000up);
		

		cout << "400: " << aaano*1000*sig400 << "\t" << aaano*1000*ttbar400 << "\t" << aaano*1000*qcd400 << endl;
		cout << "500: " << aaano*1000*sig500 << "\t" << aaano*1000*ttbar500 << "\t" << aaano*1000*qcd500 << endl;
		cout << "650: " << aaano*1000*sig650 << "\t" << aaano*1000*ttbar650 << "\t" << aaano*1000*qcd650 << endl;
		cout << "800: " << aaano*1000*sig800 << "\t" << aaano*1000*ttbar800 << "\t" << aaano*1000*qcd800 << endl;
		cout << "1000: " << aaano*1000*sig1000 << "\t" << aaano*1000*ttbar1000 << "\t" << aaano*1000*qcd1000 << endl;
		cout << "2000: " << aaano*1000*sig2000 << "\t" << aaano*1000*ttbar2000 << "\t" << aaano*1000*qcd2000 << endl;
		cout << "2500: " << aaano*1000*sig2500 << "\t" << aaano*1000*ttbar2500 << "\t" << aaano*1000*qcd2500 << endl;
		cout << "3000: " << aaano*1000*sig3000 << "\t" << aaano*1000*ttbar3000 << "\t" << aaano*1000*qcd3000 << endl;
*/

	//	cat[i]->SetPoint(0,400,30*(m400up-m400low));
	//	cat[i]->SetPoint(1,500,30*(m500up-m500low));
		if(i!=3){
		cat[i]->SetPoint(0,650,bnum*10*(m650up-m650low));
		cat[i]->SetPoint(1,800,bnum*10*(m800up-m800low));
		cat[i]->SetPoint(2,1000,bnum*10*(m1000up-m1000low));
		cat[i]->SetPoint(3,1500,bnum*10*(m1500up-m1500low));
		cat[i]->SetPoint(4,2000,bnum*10*(m2000up-m2000low));
		cat[i]->SetPoint(5,2500,bnum*10*(m2500up-m2500low));
		cat[i]->SetPoint(6,3000,bnum*10*(m3000up-m3000low));
		}else{
		cat[i]->SetPoint(0,650,bnum*10*(m650up-m650low));
                cat[i]->SetPoint(1,800,bnum*10*(m800up-m800low));
                cat[i]->SetPoint(2,1000,bnum*10*(m1000up-m1000low));
                cat[i]->SetPoint(3,1500,bnum*10*(m1500up-m1500low));
                cat[i]->SetPoint(4,2000,bnum*10*(m2000up-m2000low));
                cat[i]->SetPoint(5,2500,bnumwbj*10*(m2500up-m2500low));
                cat[i]->SetPoint(6,3000,bnumwbj*10*(m3000up-m3000low));
                }
/*
		cat[i]->SetPoint(0,800,sig800*1000*aaano/sqrt(ttbar800*1000*aaano + qcd800*1000*aaano));
                cat[i]->SetPoint(1,1000,sig1000*1000*aaano/sqrt(ttbar1000*1000*aaano + qcd1000*1000*aaano));
                cat[i]->SetPoint(2,1500,sig1500*1000*aaano/sqrt(ttbar1500*1000*aaano + qcd1500*1000*aaano));
                cat[i]->SetPoint(3,2000,sig2000*1000*aaano/sqrt(ttbar2000*1000*aaano + qcd2000*1000*aaano));
                cat[i]->SetPoint(4,3000,sig3000*1000*aaano/sqrt(ttbar3000*1000*aaano + qcd3000*1000*aaano));
*/

	}

	cat[0]->SetMarkerColor(46);
	cat[0]->SetLineColor(46);
	cat[0]->SetMarkerStyle(20);
	cat[0]->SetMarkerSize(2);

	cat[1]->SetMarkerColor(8);
	cat[1]->SetLineColor(8);
        cat[1]->SetMarkerStyle(29);
        cat[1]->SetMarkerSize(2);


	cat[2]->SetMarkerColor(38);
        cat[2]->SetLineColor(38);
        cat[2]->SetMarkerStyle(22);
        cat[2]->SetMarkerSize(2);

        cat[3]->SetMarkerColor(kPink+1);
        cat[3]->SetLineColor(kPink+1);
        cat[3]->SetMarkerStyle(21);
        cat[3]->SetMarkerSize(2);




	TCanvas *ce = new TCanvas("ce","ce",800,600);
        ce->cd(1);

	
        cat[3]->Draw("AP");
	cat[3]->GetXaxis()->SetTitle("M_{H^{+}}");
        cat[3]->GetYaxis()->SetTitle("width[GeV]");


        cat[0]->Draw("P");
        cat[1]->Draw("P");
        cat[2]->Draw("P");


        const char *lumien = "#bf{35.87 fb^{-1}(13TeV)}";
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetTextAlign(11);
        latex.DrawLatex(0.68, 0.93, lumien);
        latex.SetTextSize(0.05);
        latex.DrawLatex(0.12, 0.93, "CMS #scale[0.8]{#bf{#it{internal}}}");




        TLegend *legende = new TLegend(0.72,0.72,0.98,0.96);
	legende->AddEntry(cat[0],"t0b","P");
        legende->AddEntry(cat[1],"t1b","P");
        legende->AddEntry(cat[2],"wbb","P");
        legende->AddEntry(cat[3],"wbj","P");

        legende->Draw("same");

//        ce->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXO/corrected_width_mass.png");

/*
	THStack *cateyields = new THStack("cateyield","");

	ttbarr->SetFillColor(kBlue-10);
	ttbarr->Scale(1000*aaano);
	qcdd->SetFillColor(kGreen-10);
	qcdd->Scale(1000*aaano);
	signall->SetLineColor(kRed-10);
	signall->SetLineWidth(2);
	signall->Scale(1000*aaano);


	cateyields->Add(ttbarr);
	cateyields->Add(qcdd);

	TCanvas *c1a = new TCanvas("c1a","c1a",800,600);
        c1a->cd(1);
        cateyields->Draw("hist");
	signall->Draw("hist same");
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
        cateyields->GetYaxis()->SetTitle("Event");

        TLegend *legend4a = new TLegend(0.64,0.78,0.84,0.94);
        legend4a->AddEntry(signall,"1000GeV","l");
        legend4a->AddEntry(ttbarr,"TTbar","f");
        legend4a->AddEntry(qcdd,"QCD","f");
        legend4a->Draw("same");

//        c1a->SaveAs("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Plots/EXO/cateyields.png");
*/	

//	f2->Write();
//	f2->Close();

} 

/*



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
*/
