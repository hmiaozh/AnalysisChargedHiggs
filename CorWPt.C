#include "TH1.h"
#include "TF1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TRandom.h"
#include <string>
#include <vector>
#include <math.h>


void CorWPt(){


	TFile *outf = new TFile("Results/CorWPT_oldfile.root","recreate");

	TProfile* ratio = new TProfile("ratio","ratio",9,200,2000,"e");
	ratio->Sumw2();

	TGraphErrors* ratioPT = new TGraphErrors(9);

	ratioPT->SetPoint(0,300,1.03989);
	ratioPT->SetPoint(1,500,1.05108);
	ratioPT->SetPoint(2,700,1.06214);
	ratioPT->SetPoint(3,900,1.06898);
        ratioPT->SetPoint(4,1100,1.07486);
        ratioPT->SetPoint(5,1300,1.07838);
        ratioPT->SetPoint(6,1500,1.08079);
        ratioPT->SetPoint(7,1700,1.08726);
	ratioPT->SetPoint(8,1950,1.10641);

	ratioPT->SetPointError(0,100,2.74515e-04);
        ratioPT->SetPointError(1,100,4.84345e-04);
        ratioPT->SetPointError(2,100,8.48802e-04);
        ratioPT->SetPointError(3,100,1.05435e-03);
        ratioPT->SetPointError(4,100,1.35637e-03);
        ratioPT->SetPointError(5,100,1.79512e-03);
        ratioPT->SetPointError(6,100,2.26825e-03);
        ratioPT->SetPointError(7,100,4.95919e-03);
        ratioPT->SetPointError(8,200,9.99608e-03);

	ratio->Fill(300,1.03989,2.74515e-04);
        ratio->Fill(500,1.05108,4.84345e-04);
        ratio->Fill(700,1.06214,8.48802e-04); 
        ratio->Fill(900,1.06898,1.05435e-03);
        ratio->Fill(1100,1.07486,1.35637e-03);
        ratio->Fill(1300,1.07525,1.74007e-03);
        ratio->Fill(1500,1.07556,2.26825e-03);
        ratio->Fill(1700,1.08585,4.60090e-03);
        ratio->Fill(1999,1.10641,9.93523e-03);

/*
	ratio->Fill(300,1.0/1.03989,2.74515e-04/(1.03989*1.03989));
	ratio->Fill(500,1.0/1.05108,4.84345e-04/(1.05108*1.05108));
	ratio->Fill(700,1.0/1.06214,8.48802e-04/(1.06214*1.06214)); 
	ratio->Fill(900,1.0/1.06898,1.05435e-03/(1.06898*1.06898));
	ratio->Fill(1100,1.0/1.07486,1.35637e-03/(1.07486*1.07486));
	ratio->Fill(1300,1.0/1.07525,1.74007e-03/(1.07525*1.07525));
	ratio->Fill(1500,1.0/1.07556,2.26825e-03/(1.07556*1.07556));
	ratio->Fill(1700,1.0/1.08585,4.60090e-03/(1.08585*1.08585));
	ratio->Fill(1999,1.0/1.10641,9.93523e-03/(1.10641*1.10641));
*/

//	TFile *outf = new TFile("Results/CorWPT.root","recreate");

	ratioPT->Write();

	outf->Write();
  	outf->Close();

}
