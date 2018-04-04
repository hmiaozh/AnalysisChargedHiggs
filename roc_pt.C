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


const double Mbottom = 5.0; // mass of bottom quark (4.6GeV)
const double Mw = 80.385;
const double Mtop = 173.34;



void roc_pt(){

        TFile* f1 = TFile::Open("/afs/cern.ch/user/h/hum/work/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Jun_z/Jun_z.root");
	TFile* f2 = new TFile("/afs/cern.ch/work/h/hum/public/CMSSW_8_0_26_patch1/src/ChargedHiggs/Analysis/Results/eff_mistag_no.root","recreate");
        TTree* t1 = (TTree*)f1->Get("tree_tb");

        Float_t fatjet_pt[20] ={0};
        Float_t fatjet_eta[20] ={0};
        Float_t fatjet_phi[20] ={0};
        Float_t fatjet_e[20] ={0};
        Float_t fatjet_tau1[20]={0};
        Float_t fatjet_tau2[20]={0};
        Float_t fatjet_tau3[20]={0};
        Float_t fatjet_SDMass[20]={0};
	Int_t fatjet_bSubJet[20]={0};
	Int_t fatjet_bSubJetLoose[20]={0};


        Float_t WFromTopH_pt, WFromTopH_phi, WFromTopH_eta;
        Float_t WFromTopAss_pt, WFromTopAss_eta, WFromTopAss_phi;
	Float_t WBKGplus_pt,WBKGplus_eta,WBKGplus_phi;
        Float_t WBKGminus_pt,WBKGminus_eta,WBKGminus_phi;	

        Float_t topFromH_pt, topFromH_phi, topFromH_eta;
        Float_t topAss_pt, topAss_phi, topAss_eta;
        Float_t topBKGplus_pt, topBKGplus_phi, topBKGplus_eta;
        Float_t topBKGminus_pt, topBKGminus_phi, topBKGminus_eta;

	Int_t sig, mc;
	Int_t NFatJets;

        t1->SetBranchAddress("fatjet_pt", &fatjet_pt);
        t1->SetBranchAddress("fatjet_eta",&fatjet_eta);
        t1->SetBranchAddress("fatjet_phi",&fatjet_phi);
        t1->SetBranchAddress("fatjet_e",&fatjet_e);
        t1->SetBranchAddress("fatjet_tau1",&fatjet_tau1);
        t1->SetBranchAddress("fatjet_tau2",&fatjet_tau2);
        t1->SetBranchAddress("fatjet_tau3",&fatjet_tau3);
        t1->SetBranchAddress("fatjet_SDMass",&fatjet_SDMass);
	t1->SetBranchAddress("fatjet_bSubJet",&fatjet_bSubJet);
	t1->SetBranchAddress("fatjet_bSubJetLoose",&fatjet_bSubJetLoose);

        t1->SetBranchAddress("WFromTopH_pt",&WFromTopH_pt);
        t1->SetBranchAddress("WFromTopH_phi",&WFromTopH_phi);
        t1->SetBranchAddress("WFromTopH_eta",&WFromTopH_eta);

        t1->SetBranchAddress("WFromTopAss_pt",&WFromTopAss_pt);
        t1->SetBranchAddress("WFromTopAss_eta",&WFromTopAss_eta);
        t1->SetBranchAddress("WFromTopAss_phi",&WFromTopAss_phi);
	
        t1->SetBranchAddress("WBKGplus_pt",&WBKGplus_pt);
        t1->SetBranchAddress("WBKGplus_eta",&WBKGplus_eta);
        t1->SetBranchAddress("WBKGplus_phi",&WBKGplus_phi);

        t1->SetBranchAddress("WBKGminus_pt",&WBKGminus_pt);
        t1->SetBranchAddress("WBKGminus_eta",&WBKGminus_eta);
        t1->SetBranchAddress("WBKGminus_phi",&WBKGminus_phi);


        t1->SetBranchAddress("topFromH_pt",&topFromH_pt);
        t1->SetBranchAddress("topFromH_eta",&topFromH_eta);
        t1->SetBranchAddress("topFromH_phi",&topFromH_phi);

        t1->SetBranchAddress("topAss_pt",&topAss_pt);
        t1->SetBranchAddress("topAss_eta",&topAss_eta);
        t1->SetBranchAddress("topAss_phi",&topAss_phi);

        t1->SetBranchAddress("topBKGplus_pt",&topBKGplus_pt);
        t1->SetBranchAddress("topBKGplus_eta",&topBKGplus_eta);
        t1->SetBranchAddress("topBKGplus_phi",&topBKGplus_phi);

        t1->SetBranchAddress("topBKGminus_pt",&topBKGminus_pt);
        t1->SetBranchAddress("topBKGminus_eta",&topBKGminus_eta);
        t1->SetBranchAddress("topBKGminus_phi",&topBKGminus_phi);

        t1->SetBranchAddress("sig", &sig);
        t1->SetBranchAddress("mc", &mc);

	t1->SetBranchAddress("NFatJets",&NFatJets);



	TGraph* eff_top = new TGraph(21); eff_top->SetName("eff_top");
//        TGraph* eff_W = new TGraph(21); eff_W->SetName("eff_W");
	TGraph* eff_QCD = new TGraph(21); eff_QCD->SetName("eff_QCD");

	Double_t efftop[21] = {0.};
	Double_t effW[21] = {0.};
	Double_t effqcd[21] = {0.};

	UInt_t numtruetop[21] = {0}, numtrueW[21] = {0};
	UInt_t numbothtop[21] = {0}, numbothW[21] = {0};
	UInt_t numfj[21] = {0}, numqcdtop[21] = {0}, numqcdW = 0;	

        for(UInt_t i=0; i < t1->GetEntries(); i++) {

        	t1->GetEntry(i);
		
		TLorentzVector Wfromhiggs,Wfromgluon,wbkgp,wbkgm;
                Wfromhiggs.SetPtEtaPhiM(WFromTopH_pt,WFromTopH_eta,WFromTopH_phi,Mw);
                Wfromgluon.SetPtEtaPhiM(WFromTopAss_pt,WFromTopAss_eta,WFromTopAss_phi,Mw);
                wbkgp.SetPtEtaPhiM(WBKGplus_pt,WBKGplus_eta,WBKGplus_phi,Mw);
                wbkgm.SetPtEtaPhiM(WBKGminus_pt,WBKGminus_eta,WBKGminus_phi,Mw);

                TLorentzVector topfromhiggs, topass, topbkgp, topbkgm;
                topfromhiggs.SetPtEtaPhiM(topFromH_pt,topFromH_eta,topFromH_phi,Mtop);
                topass.SetPtEtaPhiM(topAss_pt,topAss_eta,topAss_phi,Mtop);
                topbkgp.SetPtEtaPhiM(topBKGplus_pt,topBKGplus_eta,topBKGplus_phi,Mtop);
                topbkgm.SetPtEtaPhiM(topBKGminus_pt,topBKGminus_eta,topBKGminus_phi,Mtop);	

		for(Int_t j=0; j<TMath::Min(NFatJets,5); j++){

//			if(fatjet_subjet_btag[j] < 0.5) continue;

                        TLorentzVector temp;
                        temp.SetPtEtaPhiE(fatjet_pt[j],fatjet_eta[j],fatjet_phi[j],fatjet_e[j]);
	
			if(sig == 0 && mc == 500){
				for(Int_t k = 0; k < 21; k++){
					Double_t fjcut = 200. + 20. * k;
					if (fatjet_pt[j] > fjcut){
						numfj[k]++;
				//		if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220 && fatjet_bSubJetLoose[j] > 0.5 ) numqcdtop[k]++;
						if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220) numqcdtop[k]++;
					}
				}
//				if (fatjet_pt[j] > 200. && fatjet_tau2[j]/fatjet_tau1[j] < 0.6 && fatjet_SDMass[j] > 50 && fatjet_SDMass[j] < 110 ) numqcdW++;
			}else if(sig == 0 && mc == 103){
				if (temp.DeltaR(topbkgp) < 0.2 || temp.DeltaR(topbkgm) < 0.2) {
					for(Int_t k = 0; k < 21; k++){
						Double_t topcut = 200. + 20. * k;
						if (fatjet_pt[j] > topcut){
							numtruetop[k] ++;
				//			if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220 && fatjet_bSubJetLoose[j] > 0.5 ) numbothtop[k] ++;
							if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220) numbothtop[k] ++;
						}
					}
		//		}else if(temp.DeltaR(wbkgp) < 0.2 || temp.DeltaR(wbkgm) < 0.2) {
		//			for(Int_t k = 0; k < 21; k++){
                //                                Double_t Wcut = 100. + 10. * k;
                //                                if (fatjet_pt[j] > Wcut){ 
                //                                        numtrueW[k] ++;
                //                                        if (fatjet_tau2[j]/fatjet_tau1[j] < 0.6 && fatjet_SDMass[j] > 50 && fatjet_SDMass[j] < 110 ) numbothW[k] ++;
                //                                }
                //                        }
                                }
			}else if(sig == 1){
                                if (temp.DeltaR(topfromhiggs) < 0.3 || temp.DeltaR(topass) < 0.2) {
                                        for(Int_t k = 0; k < 21; k++){
                                                Double_t topcut = 200. + 20. * k;
                                                if (fatjet_pt[j] > topcut){ 
                                                        numtruetop[k] ++;
                                //                        if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220 && fatjet_bSubJetLoose[j] > 0.5 ) numbothtop[k] ++;
							if (fatjet_tau3[j]/fatjet_tau2[j] < 0.81 && fatjet_SDMass[j] > 105 && fatjet_SDMass[j] < 220) numbothtop[k] ++;
                                                }
                                        }
              //                  }else if(temp.DeltaR(Wfromhiggs) < 0.3 || temp.DeltaR(Wfromgluon) < 0.2) {
              //                          for(Int_t k = 0; k < 21; k++){
              //                                  Double_t Wcut = 100. + 10. * k;
              //                                  if (fatjet_pt[j] > Wcut){  
              //                                          numtrueW[k] ++;
              //                                          if (fatjet_tau2[j]/fatjet_tau1[j] < 0.6 && fatjet_SDMass[j] > 50 && fatjet_SDMass[j] < 110 ) numbothW[k] ++;
              //                                  }
              //                          }
                                }
                        }

		}

	}

//	cout << "number of jet:" << numfj << endl;
//	cout << "number of top jet:" << numqcdtop << endl;
//	cout << "number of W jet:" << numqcdW << endl;

	for(Int_t m=0; m<21; m++){

		efftop[m] = (double)numbothtop[m]/(double)numtruetop[m];
//		effW[m] = (double)numbothW[m]/(double)numtrueW[m];
		effqcd[m] = (double)numqcdtop[m]/(double)numfj[m];
			
		eff_top->SetPoint(m,200.+20.*m,efftop[m]);
//		eff_W->SetPoint(m,100.+10.*m,effW[m]);
		eff_QCD->SetPoint(m,200.+20.*m,effqcd[m]);
	}

	eff_top->Write();
//	eff_W->Write();
	eff_QCD->Write();

	f2->Write();
        f2->Close();

}










