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
#include <string>
#include <vector>
#include <math.h>
#include "tdrstyle.C"

const double aaano = 35.87;

void sbofnsub(){

	setTDRStyle();

	TFile* f1 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/lownsub.root");
	TFile* f2 = TFile::Open("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/ntufile/nsub.root");

	vector<TDirectoryFile*> categ;
	vector<TDirectoryFile*> cateb;

	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh") );
	categ.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_tbh") );
//	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbb_th_bh") );
//	categ.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_wbj_good") );

	cateb.push_back( (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b") );
        cateb.push_back( (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t0b") );



	TDirectoryFile *bkp1 = (TDirectoryFile*)f1->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");
        TDirectoryFile *bkp2 = (TDirectoryFile*)f2->Get("ChargedHiggsTopBottom/OneBOneFat_t0b_thbh");



	char mass[7][100];
	sprintf(mass[0],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
	sprintf(mass[1],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
	sprintf(mass[2],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
	sprintf(mass[3],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
	sprintf(mass[4],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-1500_13TeV_amcatnlo_pythia8");
	sprintf(mass[5],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
	sprintf(mass[6],"invariant_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");


	char massa[9][100];
        sprintf(massa[0],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-400_13TeV_amcatnlo_pythia8");
        sprintf(massa[1],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8");
        sprintf(massa[2],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-800_13TeV_amcatnlo_pythia8");
        sprintf(massa[3],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1000_13TeV_amcatnlo_pythia8");
        sprintf(massa[4],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-1500_13TeV_amcatnlo_pythia8");
        sprintf(massa[5],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-2000_13TeV_amcatnlo_pythia8");
        sprintf(massa[6],"invariantExt_ChargedHiggs_HplusTB_HplusToTB_M-3000_13TeV_amcatnlo_pythia8");
	sprintf(massa[7],"invariantExt_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8");
	sprintf(massa[8],"invariantExt_QCD_HT");



	vector<TH1D*> m400;
        vector<TH1D*> m500;
        vector<TH1D*> m800;
        vector<TH1D*> m1000;
        vector<TH1D*> m1500;
        vector<TH1D*> m2000;
        vector<TH1D*> m3000;


        vector<TH1D*> m400a;
        vector<TH1D*> m500a;
        vector<TH1D*> m800a;
        vector<TH1D*> m1000a;
	vector<TH1D*> m1500a;
        vector<TH1D*> m2000a;
        vector<TH1D*> m3000a;
	vector<TH1D*> ttbarlow;
	vector<TH1D*> qcdlow;
	vector<TH1D*> ttbarhigh;
        vector<TH1D*> qcdhigh;


	for(Int_t i=0; i<2; i++) {

		m400.push_back( (TH1D*)categ[i]->Get(mass[0]) );
		m500.push_back( (TH1D*)categ[i]->Get(mass[1]) );
		m800.push_back( (TH1D*)categ[i]->Get(mass[2]) );
		m1000.push_back( (TH1D*)categ[i]->Get(mass[3]) );
		m1500.push_back( (TH1D*)categ[i]->Get(mass[4]) );
		m2000.push_back( (TH1D*)categ[i]->Get(mass[5]) );
		m3000.push_back( (TH1D*)categ[i]->Get(mass[6]) );
		
		m400a.push_back( (TH1D*)cateb[i]->Get(massa[0]) );
                m500a.push_back( (TH1D*)cateb[i]->Get(massa[1]) );
                m800a.push_back( (TH1D*)cateb[i]->Get(massa[2]) );
                m1000a.push_back( (TH1D*)cateb[i]->Get(massa[3]) );
                m1500a.push_back( (TH1D*)cateb[i]->Get(massa[4]) );
                m2000a.push_back( (TH1D*)cateb[i]->Get(massa[5]) );
                m3000a.push_back( (TH1D*)cateb[i]->Get(massa[6]) );
		//ttbarlow.push_back( (TH1D*)cateb[i]->Get(mass[12]) );
		//qcdlow.push_back( (TH1D*)cateb[i]->Get(mass[13]) );
		ttbarhigh.push_back( (TH1D*)cateb[i]->Get(massa[7]) );
                qcdhigh.push_back( (TH1D*)cateb[i]->Get(massa[8]) );

		if(i==0){
			m400[0]->Add((TH1D*)bkp1->Get(mass[0]));
                        m500[0]->Add((TH1D*)bkp1->Get(mass[1]));
                        m800[0]->Add((TH1D*)bkp1->Get(mass[2]));
                        m1000[0]->Add((TH1D*)bkp1->Get(mass[3]));
			m1500[0]->Add((TH1D*)bkp1->Get(mass[4]));
                        m2000[0]->Add((TH1D*)bkp1->Get(mass[5]));
                        m3000[0]->Add((TH1D*)bkp1->Get(mass[6]));
                }else if(i==1){
			m400[1]->Add((TH1D*)bkp2->Get(mass[0]));
                        m500[1]->Add((TH1D*)bkp2->Get(mass[1]));
                        m800[1]->Add((TH1D*)bkp2->Get(mass[2]));
                        m1000[1]->Add((TH1D*)bkp2->Get(mass[3]));
			m1500[1]->Add((TH1D*)bkp2->Get(mass[4]));
                        m2000[1]->Add((TH1D*)bkp2->Get(mass[5]));
                        m3000[1]->Add((TH1D*)bkp2->Get(mass[6]));
                }

	}


	for(Int_t i=0; i<2; i++) {
		m400[i]->Rebin(3);
		m500[i]->Rebin(3);
		
		m800[i]->Rebin(2);
		m1000[i]->Rebin(2);
		m1500[i]->Rebin(2);
		m2000[i]->Rebin(2);
		m3000[i]->Rebin(2);

		m400a[i]->Rebin(3);
                m500a[i]->Rebin(3);
//              ttbarlow[i]->Rebin(3);
//              qcdlow[i]->Rebin(3);
		
		m800a[i]->Rebin(2);
                m1000a[i]->Rebin(2);
                m1500a[i]->Rebin(2);
                m2000a[i]->Rebin(2);
                m3000a[i]->Rebin(2);
		ttbarhigh[i]->Rebin(2);
		qcdhigh[i]->Rebin(2);
	}



	Int_t m400low = -1, m400up = -1;
        Int_t m500low = -1, m500up = -1;
        Int_t m800low = -1, m800up = -1;
        Int_t m1000low = -1, m1000up = -1;
	Int_t m1500low = -1, m1500up = -1;
        Int_t m2000low = -1, m2000up = -1;
        Int_t m3000low = -1, m3000up = -1;

	Double_t sig400 = 0, ttbar400 = 0, qcd400 = 0;
        Double_t sig500 = 0, ttbar500 = 0, qcd500 = 0;
        Double_t sig800 = 0, ttbar800 = 0, qcd800 = 0;
        Double_t sig1000 = 0, ttbar1000 = 0, qcd1000 = 0;
	Double_t sig1500 = 0, ttbar1500 = 0, qcd1500 = 0;
        Double_t sig2000 = 0, ttbar2000 = 0, qcd2000 = 0;
        Double_t sig3000 = 0, ttbar3000 = 0, qcd3000 = 0;

        Double_t sig2000wbb = 0, ttbar2000wbb = 0, qcd2000wbb = 0;
        Double_t sig3000wbb = 0, ttbar3000wbb = 0, qcd3000wbb = 0;




	vector<TGraph*> cat;

	for(Int_t i=0; i<2; i++) {
		cat.push_back(new TGraph());
	}

	for(Int_t i=0; i<2; i++) {
/*		m400low = m400[i]->FindFirstBinAbove(m400[i]->GetMaximum()/2);
                m400up  = m400[i]->FindLastBinAbove(m400[i]->GetMaximum()/2);

		m500low = m500[i]->FindFirstBinAbove(m500[i]->GetMaximum()/2);
                m500up  = m500[i]->FindLastBinAbove(m500[i]->GetMaximum()/2);    */
		
		m800low = m800[i]->FindFirstBinAbove(m800[i]->GetMaximum()/2);
                m800up  = m800[i]->FindLastBinAbove(m800[i]->GetMaximum()/2);

                m1000low = m1000[i]->FindFirstBinAbove(m1000[i]->GetMaximum()/2);
                m1000up  = m1000[i]->FindLastBinAbove(m1000[i]->GetMaximum()/2);

		m1500low = m1500[i]->FindFirstBinAbove(m1500[i]->GetMaximum()/2);
                m1500up  = m1500[i]->FindLastBinAbove(m1500[i]->GetMaximum()/2);

                m2000low = m2000[i]->FindFirstBinAbove(m2000[i]->GetMaximum()/2);
                m2000up  = m2000[i]->FindLastBinAbove(m2000[i]->GetMaximum()/2);

                m3000low = m3000[i]->FindFirstBinAbove(m3000[i]->GetMaximum()/2);
                m3000up  = m3000[i]->FindLastBinAbove(m3000[i]->GetMaximum()/2);

		cout << "catagory " << i << ":" << endl;
//		cout << "400: " << m400low << "		" << m400up << endl;
//                cout << "500: " << m500low << "		" << m500up << endl;
                cout << "800: " << m800low << "		" << m800up << endl;
                cout << "1000: " << m1000low << "	" << m1000up << endl;
		cout << "1500: " << m1500low << "       " << m1500up << endl;
                cout << "2000: " << m2000low << "	" << m2000up << endl;
                cout << "3000: " << m3000low << "	" << m3000up << endl; 

//		sig400 = m400a[i]->Integral(m400low,m400up);
//        	sig500 = m500a[i]->Integral(m500low,m500up);
        	sig800 = m800a[i]->Integral(m800low,m800up);
        	sig1000 = m1000a[i]->Integral(m1000low,m1000up);
		sig1500 = m1500a[i]->Integral(m1500low,m1500up);
        	sig2000 = m2000a[i]->Integral(m2000low,m2000up);
        	sig3000 = m3000a[i]->Integral(m3000low,m3000up);

//        	ttbar400 = ttbarlow[i]->Integral(m400low,m400up);
//        	ttbar500 = ttbarlow[i]->Integral(m500low,m500up);
        	ttbar800 = ttbarhigh[i]->Integral(m800low,m800up);
        	ttbar1000 = ttbarhigh[i]->Integral(m1000low,m1000up);
		ttbar1500 = ttbarhigh[i]->Integral(m1500low,m1500up);
        	ttbar2000 = ttbarhigh[i]->Integral(m2000low,m2000up);
        	ttbar3000 = ttbarhigh[i]->Integral(m3000low,m3000up);

//        	qcd400 = qcdlow[i]->Integral(m400low,m400up);
//        	qcd500 = qcdlow[i]->Integral(m500low,m500up);
        	qcd800 = qcdhigh[i]->Integral(m800low,m800up);
        	qcd1000 = qcdhigh[i]->Integral(m1000low,m1000up);
		qcd1500 = qcdhigh[i]->Integral(m1500low,m1500up);
        	qcd2000 = qcdhigh[i]->Integral(m2000low,m2000up);
        	qcd3000 = qcdhigh[i]->Integral(m3000low,m3000up);
		

		cout << "400: " << aaano*1000*sig400 << "\t" << aaano*1000*ttbar400 << "\t" << aaano*1000*qcd400 << endl;
		cout << "500: " << aaano*1000*sig500 << "\t" << aaano*1000*ttbar500 << "\t" << aaano*1000*qcd500 << endl;
		cout << "800: " << aaano*1000*sig800 << "\t" << aaano*1000*ttbar800 << "\t" << aaano*1000*qcd800 << endl;
		cout << "1000: " << aaano*1000*sig1000 << "\t" << aaano*1000*ttbar1000 << "\t" << aaano*1000*qcd1000 << endl;
		cout << "2000: " << aaano*1000*sig2000 << "\t" << aaano*1000*ttbar2000 << "\t" << aaano*1000*qcd2000 << endl;
		cout << "3000: " << aaano*1000*sig3000 << "\t" << aaano*1000*ttbar3000 << "\t" << aaano*1000*qcd3000 << endl;

/*
	//	cat[i]->SetPoint(0,400,30*(m400up-m400low));
	//	cat[i]->SetPoint(1,500,30*(m500up-m500low));
		cat[i]->SetPoint(0,800,20*(m800up-m800low));
		cat[i]->SetPoint(1,1000,20*(m1000up-m1000low));
		cat[i]->SetPoint(2,1500,20*(m1500up-m1500low));
		cat[i]->SetPoint(3,2000,20*(m2000up-m2000low));
		cat[i]->SetPoint(4,3000,20*(m3000up-m3000low));
*/

		cat[i]->SetPoint(0,800,sig800*1000*aaano/sqrt(ttbar800*1000*aaano + qcd800*1000*aaano));
                cat[i]->SetPoint(1,1000,sig1000*1000*aaano/sqrt(ttbar1000*1000*aaano + qcd1000*1000*aaano));
                cat[i]->SetPoint(2,1500,sig1500*1000*aaano/sqrt(ttbar1500*1000*aaano + qcd1500*1000*aaano));
                cat[i]->SetPoint(3,2000,sig2000*1000*aaano/sqrt(ttbar2000*1000*aaano + qcd2000*1000*aaano));
                cat[i]->SetPoint(4,3000,sig3000*1000*aaano/sqrt(ttbar3000*1000*aaano + qcd3000*1000*aaano));


	}

	cat[0]->SetMarkerColor(46);
	cat[0]->SetLineColor(46);
	cat[0]->SetMarkerStyle(20);
	cat[0]->SetMarkerSize(1.5);

	cat[1]->SetMarkerColor(8);
	cat[1]->SetLineColor(8);
        cat[1]->SetMarkerStyle(29);
        cat[1]->SetMarkerSize(1.5);




	TCanvas *ce = new TCanvas("ce","ce",800,600);
        ce->cd(1);
	
        cat[1]->Draw("CAP");
        cat[0]->Draw("CP");

        TLegend *legende = new TLegend(0.72,0.72,0.98,0.96);
        legende->AddEntry(cat[0],"tau32<0.67","P");
        legende->AddEntry(cat[1],"tau32<0.81","P");
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
