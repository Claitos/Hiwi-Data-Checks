#include <TFile.h>
#include <iostream>
#include <TTree.h>
#include <TH1.h>
#include <TH2.h>
#include <TCut.h>
#include <TChain.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TStyle.h>
#include <TStopwatch.h>
using namespace std;

void track_position_uncertainty_macro() {

    TChain *Tree = new TChain("Tree");
	
	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_SI_wPreMin.root/DF_2262958443066025/O2casccandmc");      // SI pass4 Thesis

	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_wPreMin.root/DF_2266609207539576/O2casccandmc");      // GP pass4 Thesis
	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_wPreMin.root/DF_2270036700097545/O2casccandmc");      // GP pass4 Thesis
	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_wPreMin.root/DF_2248591508396059/O2casccandmc");      // GP pass4 Thesis
	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_wPreMin.root/DF_2266991212314497/O2casccandmc");      // GP pass4 Thesis

	// Tree->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass6_wPreMin.root/DF_2267098586191173/O2casccandmc");      // GP pass6 Thesis

	// Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC24f3c.root/DF_2268997031547896/O2casccandmc");   // GP pass7 LHC22o
	// Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC24f3c.root/DF_2263915935866616/O2casccandmc");   // GP pass7 LHC22o
	// Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC24f3c.root/DF_2270023726731767/O2casccandmc");   // GP pass7 LHC22o

	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2300062542593111/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2302210303516824/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2301956622048672/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2303691697534469/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2305963988611719/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2308394932611766/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2309232433186413/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2309949911070962/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2310769750710395/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2303129917305244/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2309112152576853/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2316142901210718/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2317207916632068/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2317723398525881/O2casccandmc");   // GP pass4 LHC23f
	Tree->Add("/lustre/alice/users/tweinrei/Hiwi-Trees/AO2D_LHC23k4g.root/DF_2318745949570471/O2casccandmc");   // GP pass4 LHC23f


	TChain *Tree2 = new TChain("Tree2");
	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_SI_woPreMin.root/DF_2267004450442073/O2casccandmc");      // SI pass 4 Thesis

	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_woPreMin.root/DF_2246877970309364/O2casccandmc");      // GP pass 4 Thesis
	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_woPreMin.root/DF_2247990969824158/O2casccandmc");      // GP pass 4 Thesis
	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_woPreMin.root/DF_2269186390601077/O2casccandmc");      // GP pass 4 Thesis
	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_woPreMin.root/DF_2266428812921873/O2casccandmc");      // GP pass 4 Thesis
	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass4_woPreMin.root/DF_2268142256886309/O2casccandmc");      // GP pass 4 Thesis

	// Tree2->Add("/lustre/alice/users/tweinrei/KFstudy/MC/AO2D_GP_pass6_woPreMin.root/DF_2261906078559382/O2casccandmc");      // GP pass 6 Thesis


	TCut isKF = "fIsKF == 1";
	TCut isDCA = "fIsDCAFitter == 1";
	TCut isKFDCA = "fIsKF == 1 && fIsDCAFitter == 1";
	TCut isKFandTrueCasc = "fIsKF == 1 && fIsTrueCasc == 1";
	TCut isTrueCasc = "fIsTrueCasc == 1";
	TCut charge = "fCharge == -1";


	TCut V0woMaterialProton[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22",
								 "fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22",
								 "fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22"};
	TCut V0woMaterialPion[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22", 
								"fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22",
								"fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22"};

	// TCut V0wMaterialBoth = "fV0Rad > 4.5 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22";

	TCut V0wMaterialProton[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22",
								 "fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22",
								 "fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22"};
	TCut V0wMaterialPion[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22", 
								"fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22",
								"fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22"};

	TCut V0RadCutMC = "sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) > 4.5 && sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) < 19.2";

	int text_font = 42;    // default Carolina 132
	bool draw_statbox = false;

	gStyle->SetOptStat("");
	if (draw_statbox) {gStyle->SetOptStat("neoumr");}
	gStyle->SetLabelFont(text_font);
	gStyle->SetTitleFont(text_font, "X");
	gStyle->SetTitleFont(text_font, "Y");
	gStyle->SetTitleFont(text_font);
	gStyle->SetLegendFont(text_font);
	gStyle->SetLegendTextSize(0.035);
	gStyle->SetLegendBorderSize(0);

	//const char *directory = "Tree_GP_pass4/ResiDaughtersThesis";
	const char *directory = "Plots_LHC23k4g";

    // TFile *OutputFile = TFile::Open(Form("%s/resopull.root", directory), "RECREATE");

	//-------------------------
  	// variables
  	//-------------------------

	int resclaing_factor = 10000;   // 1 cm = 10000 mum

	const char *xProtonresi = Form("fXProtonRecErr * %i", resclaing_factor);
	const char *yProtonresi = Form("fYProtonRecErr * %i", resclaing_factor);
	const char *zProtonresi = Form("fZProtonRecErr * %i", resclaing_factor);

	const char *xPionresi = Form("fXPionRecErr * %i", resclaing_factor);
	const char *yPionresi = Form("fYPionRecErr * %i", resclaing_factor);
	const char *zPionresi = Form("fZPionRecErr * %i", resclaing_factor);

	const char *xyProtonresi = Form("sqrt(pow(fXProtonRecErr,2) + pow(fYProtonRecErr,2)) * %i", resclaing_factor);
	const char *xyPionresi = Form("sqrt(pow(fXPionRecErr,2) + pow(fYPionRecErr,2)) * %i", resclaing_factor);

	const char *ptProtonMC = "sqrt(pow(fPxProtonMC,2) + pow(fPyProtonMC,2))";
	const char *ptPionMC = "sqrt(pow(fPxPionMC,2) + pow(fPyPionMC,2))";

	bool xresi = false;
	bool yresi = false;
	bool zresi = true;

	bool xyresi = false;

	//-------------------------
  	// differential proton and pion residuals 
  	//-------------------------

	int nbins2D = 100;
	float ylow2D = 0;
	float xlow2D = 0;
	float yup2D = 2000;
	float xup2D = 4;
	float zup = 10000;
	float labelsize = 0.03;
	float ylabel_offset2D = 1.3;
	float xlabel_offset2D = 1.2;

	const char *xlabel2D = "p_{T}^{MC} [GeV/c]";
	const char *ylabel2D;

	if (xresi){ylabel2D = "#sigma_{x}^{Rec} [#mum]";}
	if (yresi){ylabel2D = "#sigma_{y}^{Rec} [#mum]";}
	if (zresi){ylabel2D = "#sigma_{z}^{Rec} [#mum]";}
	if (xyresi){ylabel2D = "#sigma_{xy}^{Rec} [#mum]";}

	TH2F *hRecProton2D[6];
	for (int i = 0; i < 6; i++){hRecProton2D[i] = new TH2F(Form("hRecProton2D[%i]", i), "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);}
	if (xresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC, "GOFF");
	}
	if (yresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC, "GOFF");
	}
	if (zresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC, "GOFF");
	}
	if (xyresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC, "GOFF");
	}

	float xup2D2 = 1;

	TH2F *hRecPion2D[6];
	for (int i = 0; i < 6; i++){hRecPion2D[i] = new TH2F(Form("hRecPion2D[%i]", i), "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);}
	if(xresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC, "GOFF");		
	}
	if(yresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC, "GOFF");		
	}
	if(zresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC, "GOFF");		
	}
	if(xyresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC, "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC, "GOFF");		
	}


	//-------------------------
  	// Print TH2s for consistency
  	//-------------------------

	int canvasTH2sizeX = 1000;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;

	TCanvas *canvasT0 = new TCanvas("canvasT0", "canvasT0", canvasTH2sizeX, canvasTH2sizeY);
	canvasT0->SetTicks();

	hRecProton2D[0]->Draw("P COLZ");
	hRecProton2D[0]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecProton2D[0]->GetXaxis()->SetTitle(xlabel2D);
	hRecProton2D[0]->GetYaxis()->SetTitle(ylabel2D);
	hRecProton2D[0]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecProton2D[0]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecProton2D[0]->SetTitle(Form("4.2 < r_{#Lambda} < 9.2 cm"));

	TCanvas *canvasT1 = new TCanvas("canvasT1", "canvasT1", canvasTH2sizeX, canvasTH2sizeY);
	canvasT1->SetTicks();

	hRecProton2D[1]->Draw("P COLZ");
	hRecProton2D[1]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecProton2D[1]->GetXaxis()->SetTitle(xlabel2D);
	hRecProton2D[1]->GetYaxis()->SetTitle(ylabel2D);
	hRecProton2D[1]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecProton2D[1]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecProton2D[1]->SetTitle(Form("9.2 < r_{#Lambda} < 14.2 cm"));

	TCanvas *canvasT2 = new TCanvas("canvasT2", "canvasT2", canvasTH2sizeX, canvasTH2sizeY);
	canvasT2->SetTicks();

	hRecProton2D[2]->Draw("P COLZ");
	hRecProton2D[2]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecProton2D[2]->GetXaxis()->SetTitle(xlabel2D);
	hRecProton2D[2]->GetYaxis()->SetTitle(ylabel2D);
	hRecProton2D[2]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecProton2D[2]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecProton2D[2]->SetTitle(Form("14.2 < r_{#Lambda} < 19.2 cm"));



	TCanvas *canvasT3 = new TCanvas("canvasT3", "canvasT3", canvasTH2sizeX, canvasTH2sizeY);
	canvasT3->SetTicks();

	hRecPion2D[0]->Draw("P COLZ");
	hRecPion2D[0]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecPion2D[0]->GetXaxis()->SetTitle(xlabel2D);
	hRecPion2D[0]->GetYaxis()->SetTitle(ylabel2D);
	hRecPion2D[0]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecPion2D[0]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecPion2D[0]->SetTitle(Form("4.2 < r_{#Lambda} < 9.2 cm"));

	TCanvas *canvasT4 = new TCanvas("canvasT4", "canvasT4", canvasTH2sizeX, canvasTH2sizeY);
	canvasT4->SetTicks();

	hRecPion2D[1]->Draw("P COLZ");
	hRecPion2D[1]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecPion2D[1]->GetXaxis()->SetTitle(xlabel2D);
	hRecPion2D[1]->GetYaxis()->SetTitle(ylabel2D);
	hRecPion2D[1]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecPion2D[1]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecPion2D[1]->SetTitle(Form("9.2 < r_{#Lambda} < 14.2 cm"));

	TCanvas *canvasT5 = new TCanvas("canvasT5", "canvasT5", canvasTH2sizeX, canvasTH2sizeY);
	canvasT5->SetTicks();

	hRecPion2D[2]->Draw("P COLZ");
	hRecPion2D[2]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
	hRecPion2D[2]->GetXaxis()->SetTitle(xlabel2D);
	hRecPion2D[2]->GetYaxis()->SetTitle(ylabel2D);
	hRecPion2D[2]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecPion2D[2]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	hRecPion2D[2]->SetTitle(Form("14.2 < r_{#Lambda} < 19.2 cm"));


	//-------------------------
  	// Plot data from Notebook
  	//-------------------------

	float proton_rphi_0025[39] = {0.00305905, 0.00077607, 0.00035318, 0.00020505, 0.00013635,
								  0.00009892, 0.00007623, 0.00006141, 0.00005117, 0.00004376,
								  0.00003822, 0.00003394, 0.00003057, 0.00002785, 0.00002563,
								  0.00002377, 0.00002221, 0.00002088, 0.00001974, 0.00001875,
								  0.00001788, 0.00001712, 0.00001644, 0.00001583, 0.00001529,
								  0.00001481, 0.00001437, 0.00001397, 0.00001361, 0.00001328,
								  0.00001298, 0.0000127, 0.00001244, 0.00001221, 0.00001199,
								  0.00001179, 0.0000116, 0.00001143, 0.00001126};

	float proton_rphi_0075[39] = {0.01027484, 0.0026066, 0.00118611, 0.00068843, 0.00045756,
								  0.00033166, 0.0002553, 0.00020533, 0.00017072, 0.00014566,
								  0.00012684, 0.0001123, 0.00010078, 0.00009146, 0.0000838,
								  0.00007739, 0.00007197, 0.00006733, 0.00006332, 0.00005982,
								  0.00005674, 0.00005401, 0.00005158, 0.00004941, 0.00004745,
								  0.00004568, 0.00004407, 0.0000426, 0.00004126, 0.00004003,
								  0.00003889, 0.00003784, 0.00003687, 0.00003597, 0.00003514,
								  0.00003436, 0.00003363, 0.00003295, 0.00003231};

	float proton_rphi_0125[39] = {0.0195349, 0.00495563, 0.00225498, 0.00130877, 0.00086981,
								  0.00063042, 0.0004852, 0.00039018, 0.00032434, 0.00027664,
								  0.00024083, 0.00021314, 0.00019119, 0.00017344, 0.00015883,
								  0.00014661, 0.00013627, 0.0001274, 0.00011974, 0.00011304,
								  0.00010715, 0.00010194, 0.00009729, 0.00009312, 0.00008936,
								  0.00008595, 0.00008286, 0.00008004, 0.00007745, 0.00007508,
								  0.00007289, 0.00007087, 0.000069, 0.00006726, 0.00006564,
								  0.00006413, 0.00006272, 0.0000614, 0.00006017};

	float pion_rphi_0025[45] = {0.0005488, 0.00040612, 0.00031874, 0.00026089, 0.00022026,
								0.0001904, 0.00016764, 0.00014977, 0.00013539, 0.00012358,
								0.00011371, 0.00010535, 0.00009817, 0.00009193, 0.00008647,
								0.00008165, 0.00007736, 0.00007351, 0.00007004, 0.0000669,
								0.00006404, 0.00006143, 0.00005903, 0.00005682, 0.00005478,
								0.00005288, 0.00005112, 0.00004948, 0.00004795, 0.00004651,
								0.00004516, 0.00004389, 0.0000427, 0.00004158, 0.00004051,
								0.0000395, 0.00003855, 0.00003764, 0.00003678, 0.00003596,
								0.00003518, 0.00003443, 0.00003372, 0.00003304, 0.00003239};

	float pion_rphi_0075[45] = {0.00184321, 0.00136395, 0.00107042, 0.00087605, 0.00073956,
								0.00063922, 0.00056273, 0.00050265, 0.00045431, 0.0004146,
								0.00038142, 0.00035329, 0.00032913, 0.00030816, 0.00028978,
								0.00027354, 0.00025908, 0.00024612, 0.00023444, 0.00022385,
								0.0002142, 0.00020538, 0.00019729, 0.00018982, 0.00018292,
								0.00017652, 0.00017057, 0.00016502, 0.00015983, 0.00015497,
								0.00015041, 0.00014611, 0.00014207, 0.00013825, 0.00013464,
								0.00013122, 0.00012797, 0.00012489, 0.00012196, 0.00011917,
								0.00011651, 0.00011397, 0.00011154, 0.00010922, 0.000107};

	float pion_rphi_0125[45] = {0.00350436, 0.00259314, 0.00203505, 0.0016655, 0.00140599,
								0.00121523, 0.00106978, 0.00095556, 0.00086364, 0.00078814,
								0.00072505, 0.00067155, 0.00062562, 0.00058574, 0.00055079,
								0.00051991, 0.0004924, 0.00046776, 0.00044553, 0.00042539,
								0.00040705, 0.00039028, 0.00037487, 0.00036068, 0.00034755,
								0.00033537, 0.00032405, 0.00031349, 0.00030362, 0.00029437,
								0.00028568, 0.00027751, 0.00026981, 0.00026254, 0.00025567,
								0.00024916, 0.00024298, 0.00023711, 0.00023153, 0.00022622,
								0.00022116, 0.00021632, 0.0002117, 0.00020729, 0.00020306};

	float proton_z_0025[39] = {0.00284494, 0.00072174, 0.00032842, 0.00019061, 0.00012668,
							   0.00009182, 0.00007067, 0.00005684, 0.00004725, 0.00004031,
							   0.00003509, 0.00003106, 0.00002787, 0.00002529, 0.00002316,
							   0.00002138, 0.00001988, 0.00001859, 0.00001748, 0.0000165,
							   0.00001565, 0.00001489, 0.00001421, 0.00001361, 0.00001306,
							   0.00001257, 0.00001212, 0.00001171, 0.00001134, 0.00001099,
							   0.00001068, 0.00001038, 0.00001011, 0.00000986, 0.00000963,
							   0.00000941, 0.00000921, 0.00000902, 0.00000884};

	float proton_z_0075[39] = {0.0085806, 0.00217678, 0.00099046, 0.00057477, 0.00038188,
							   0.00027665, 0.00021278, 0.00017095, 0.00014194, 0.0001209,
							   0.00010508, 0.00009282, 0.00008308, 0.00007519, 0.00006868,
							   0.00006322, 0.00005859, 0.0000546, 0.00005115, 0.00004812,
							   0.00004544, 0.00004306, 0.00004094, 0.00003902, 0.00003729,
							   0.00003571, 0.00003427, 0.00003295, 0.00003173, 0.00003061,
							   0.00002958, 0.00002861, 0.00002771, 0.00002688, 0.00002609,
							   0.00002536, 0.00002467, 0.00002402, 0.00002341};

	float proton_z_0125[39] = {0.01438295, 0.00364875, 0.00166021, 0.00096341, 0.00064008,
							   0.00046367, 0.0003566, 0.00028647, 0.00023783, 0.00020254,
							   0.000176, 0.00015543, 0.0001391, 0.00012585, 0.00011492,
							   0.00010575, 0.00009797, 0.00009127, 0.00008546, 0.00008036,
							   0.00007586, 0.00007186, 0.00006827, 0.00006505, 0.00006212,
							   0.00005946, 0.00005703, 0.0000548, 0.00005275, 0.00005086,
							   0.0000491, 0.00004747, 0.00004595, 0.00004453, 0.0000432,
							   0.00004195, 0.00004078, 0.00003968, 0.00003864};

	float pion_z_0025[45] = {0.00051035, 0.00037766, 0.00029638, 0.00024256, 0.00020477,
							 0.00017699, 0.00015581, 0.00013917, 0.00012579, 0.00011479,
							 0.0001056, 0.00009781, 0.00009112, 0.00008532, 0.00008023,
							 0.00007573, 0.00007172, 0.00006813, 0.0000649, 0.00006197,
							 0.00005929, 0.00005685, 0.00005461, 0.00005254, 0.00005063,
							 0.00004886, 0.00004721, 0.00004567, 0.00004423, 0.00004289,
							 0.00004162, 0.00004043, 0.00003931, 0.00003825, 0.00003725,
							 0.00003631, 0.00003541, 0.00003455, 0.00003374, 0.00003297,
							 0.00003223, 0.00003153, 0.00003085, 0.00003021, 0.0000296};

	float pion_z_0075[45] = {0.00153922, 0.00113897, 0.00089382, 0.00073148, 0.00061747,
							 0.00053366, 0.00046975, 0.00041956, 0.00037917, 0.00034598,
							 0.00031825, 0.00029473, 0.00027454, 0.000257, 0.00024163,
							 0.00022805, 0.00021595, 0.0002051, 0.00019532, 0.00018646,
							 0.00017838, 0.000171, 0.00016421, 0.00015796, 0.00015217,
							 0.00014681, 0.00014181, 0.00013716, 0.0001328, 0.00012872,
							 0.00012489, 0.00012128, 0.00011788, 0.00011467, 0.00011163,
							 0.00010876, 0.00010603, 0.00010343, 0.00010096, 0.00009861,
							 0.00009637, 0.00009423, 0.00009218, 0.00009022, 0.00008835};

	float pion_z_0125[45] = {0.00258006, 0.00190916, 0.00149823, 0.00122611, 0.001035,
							 0.0008945, 0.00078738, 0.00070324, 0.00063553, 0.0005799,
							 0.00053341, 0.00049399, 0.00046013, 0.00043074, 0.00040497,
							 0.00038219, 0.00036191, 0.00034373, 0.00032733, 0.00031247,
							 0.00029893, 0.00028654, 0.00027517, 0.00026468, 0.00025498,
							 0.00024598, 0.00023761, 0.0002298, 0.0002225, 0.00021566,
							 0.00020923, 0.00020318, 0.00019748, 0.00019209, 0.000187,
							 0.00018217, 0.00017759, 0.00017324, 0.0001691, 0.00016515,
							 0.00016139, 0.0001578, 0.00015436, 0.00015108, 0.00014793};

	TH1F *hProtonRPHI[3];
	TH1F *hPionRPHI[3];

	int mtomum = 1000000;

	for (int i = 0; i < 3; i++){
		hProtonRPHI[i] = new TH1F(Form("hProtonRPHI[%i]", i), "", 40, xlow2D, xup2D);
		hPionRPHI[i] = new TH1F(Form("hProtonRPHI[%i]", i), "", 50, xlow2D, xup2D2);
		hProtonRPHI[i]->SetMarkerColor(kRed); 
		hProtonRPHI[i]->SetLineColor(kRed);
		hProtonRPHI[i]->SetMarkerStyle(20);
		hProtonRPHI[i]->SetLineWidth(2);

		hPionRPHI[i]->SetMarkerColor(kRed); 
		hPionRPHI[i]->SetLineColor(kRed);
		hPionRPHI[i]->SetMarkerStyle(20);
		hPionRPHI[i]->SetLineWidth(2);
	}

	for (int j=0; j < 39; j++){
		if (xyresi){
			hProtonRPHI[0]->SetBinContent(j+2, proton_rphi_0125[j]*mtomum);
			hProtonRPHI[1]->SetBinContent(j+2, proton_rphi_0075[j]*mtomum);
			hProtonRPHI[2]->SetBinContent(j+2, proton_rphi_0025[j]*mtomum);
		}

		if (zresi){
			hProtonRPHI[0]->SetBinContent(j+2, proton_z_0125[j]*mtomum);
			hProtonRPHI[1]->SetBinContent(j+2, proton_z_0075[j]*mtomum);
			hProtonRPHI[2]->SetBinContent(j+2, proton_z_0025[j]*mtomum);
		}
	}

	for (int j=0; j < 45; j++){
		if (xyresi){
			hPionRPHI[0]->SetBinContent(j+6, pion_rphi_0125[j]*mtomum);
			hPionRPHI[1]->SetBinContent(j+6, pion_rphi_0075[j]*mtomum);
			hPionRPHI[2]->SetBinContent(j+6, pion_rphi_0025[j]*mtomum);
		}

		if (zresi){
			hPionRPHI[0]->SetBinContent(j+6, pion_z_0125[j]*mtomum);
			hPionRPHI[1]->SetBinContent(j+6, pion_z_0075[j]*mtomum);
			hPionRPHI[2]->SetBinContent(j+6, pion_z_0025[j]*mtomum);
		}
	}

	canvasT0->cd();
	hProtonRPHI[0]->Draw("P SAMES");

	TLatex latexT0;
  	latexT0.SetTextSize(0.035);
	latexT0.SetTextFont(text_font);
	latexT0.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 12.5 cm");
	latexT0.DrawLatexNDC(0.40, 0.80, "Protons with 4 hits");
  	latexT0.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT0.DrawLatexNDC(0.60, 0.72, "Protons");

	canvasT1->cd();
	hProtonRPHI[1]->Draw("P SAMES");

	TLatex latexT1;
  	latexT1.SetTextSize(0.035);
	latexT1.SetTextFont(text_font);
	latexT1.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 7.5 cm");
	latexT1.DrawLatexNDC(0.40, 0.80, "Protons with 4 hits");
  	latexT1.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT1.DrawLatexNDC(0.60, 0.72, "Protons");

	canvasT2->cd();
	hProtonRPHI[2]->Draw("P SAMES");

	TLatex latexT2;
  	latexT2.SetTextSize(0.035);
	latexT2.SetTextFont(text_font);
	latexT2.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 2.5 cm");
	latexT2.DrawLatexNDC(0.40, 0.80, "Protons with 4 hits");
  	latexT2.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT2.DrawLatexNDC(0.60, 0.72, "Protons");

	canvasT3->cd();
	hPionRPHI[0]->Draw("P SAMES");

	TLatex latexT4;
  	latexT4.SetTextSize(0.035);
	latexT4.SetTextFont(text_font);
	latexT4.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 12.5 cm");
	latexT4.DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
  	latexT4.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT4.DrawLatexNDC(0.60, 0.72, "Pions");

	canvasT4->cd();
	hPionRPHI[1]->Draw("P SAMES");

	TLatex latexT5;
  	latexT5.SetTextSize(0.035);
	latexT5.SetTextFont(text_font);
	latexT5.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 7.5 cm");
	latexT5.DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
  	latexT5.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT5.DrawLatexNDC(0.60, 0.72, "Pions");

	canvasT5->cd();
	hPionRPHI[2]->Draw("P SAMES");

	TLatex latexT6;
  	latexT6.SetTextSize(0.035);
	latexT6.SetTextFont(text_font);
	latexT6.DrawLatexNDC(0.40, 0.84, "extrapolation distance = 2.5 cm");
	latexT6.DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
  	latexT6.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexT6.DrawLatexNDC(0.60, 0.72, "Pions");


	//-------------------------
	// Mean and Sigmas from TH2
	//-------------------------

	int nranges = 10;
	TH1D *hProton[nranges];
	TH1D *hPion[nranges];

	const char *ylabel3 = "#mu [#mum]";
	const char *ylabel4 = "#sigma [#mum]";
	
	float ylabel_offset = 1.5;
	float xlabel_offset = 1.2;

	const char *htitle; 
	if (xresi){htitle = "#sigma_{x}^{Rec} (Uncertainty)";}
	if (yresi){htitle = "#sigma_{y}^{Rec} (Uncertainty)";}
	if (zresi){htitle = "#sigma_{z}^{Rec} (Uncertainty)";}
	if (xyresi){htitle = "#sigma_{xy}^{Rec} (Uncertainty)";}

	TH1F *hMuProton[6];
	TH1F *hMuPion[6];
	TH1F *hSigmaProton[6];
	TH1F *hSigmaPion[6];

	for (int i = 0; i < 3; i++){

	hMuProton[i] = new TH1F(Form("hMuProton[%i]", i), htitle, nranges, xlow2D, xup2D);
	hMuProton[i]->GetXaxis()->SetTitle(xlabel2D);
	hMuProton[i]->GetYaxis()->SetTitle(ylabel3);
	hMuProton[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hMuProton[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hMuProton[i]->SetMarkerColor(kBlue+i); 
	hMuProton[i]->SetLineColor(kBlue+i);
	hMuProton[i]->SetMarkerStyle(20);
	hMuProton[i]->SetLineWidth(2);

	hMuPion[i] = new TH1F(Form("hMuPion[%i]", i), htitle, nranges, xlow2D, xup2D2);
	hMuPion[i]->GetXaxis()->SetTitle(xlabel2D);
	hMuPion[i]->GetYaxis()->SetTitle(ylabel3);
	hMuPion[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hMuPion[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hMuPion[i]->SetMarkerColor(kBlue+i); 
	hMuPion[i]->SetLineColor(kBlue+i);
	hMuPion[i]->SetMarkerStyle(20);
	hMuPion[i]->SetLineWidth(2);

	hSigmaProton[i] = new TH1F(Form("hSigmaProton[%i]", i), htitle, nranges, xlow2D, xup2D);
	hSigmaProton[i]->GetXaxis()->SetTitle(xlabel2D);
	hSigmaProton[i]->GetYaxis()->SetTitle(ylabel4);
	hSigmaProton[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hSigmaProton[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hSigmaProton[i]->SetMarkerColor(kBlue+i); 
	hSigmaProton[i]->SetLineColor(kBlue+i);
	hSigmaProton[i]->SetMarkerStyle(20);
	hSigmaProton[i]->SetLineWidth(2);

	hSigmaPion[i] = new TH1F(Form("hSigmaPion[%i]", i), htitle, nranges, xlow2D, xup2D2);
	hSigmaPion[i]->GetXaxis()->SetTitle(xlabel2D);
	hSigmaPion[i]->GetYaxis()->SetTitle(ylabel4);
	hSigmaPion[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hSigmaPion[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hSigmaPion[i]->SetMarkerColor(kBlue+i); 
	hSigmaPion[i]->SetLineColor(kBlue+i);
	hSigmaPion[i]->SetMarkerStyle(20);
	hSigmaPion[i]->SetLineWidth(2);

	}

	for (int i = 3; i < 6; i++){

	hMuProton[i] = new TH1F(Form("hMuProton[%i]", i), htitle, nranges, xlow2D, xup2D);
	hMuProton[i]->GetXaxis()->SetTitle(xlabel2D);
	hMuProton[i]->GetYaxis()->SetTitle(ylabel3);
	hMuProton[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hMuProton[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hMuProton[i]->SetMarkerColor(kGreen+i-3); 
	hMuProton[i]->SetLineColor(kGreen+i-3);
	hMuProton[i]->SetMarkerStyle(20);
	hMuProton[i]->SetLineWidth(2);

	hMuPion[i] = new TH1F(Form("hMuPion[%i]", i), htitle, nranges, xlow2D, xup2D2);
	hMuPion[i]->GetXaxis()->SetTitle(xlabel2D);
	hMuPion[i]->GetYaxis()->SetTitle(ylabel3);
	hMuPion[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hMuPion[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hMuPion[i]->SetMarkerColor(kGreen+i-3); 
	hMuPion[i]->SetLineColor(kGreen+i-3);
	hMuPion[i]->SetMarkerStyle(20);
	hMuPion[i]->SetLineWidth(2);

	hSigmaProton[i] = new TH1F(Form("hSigmaProton[%i]", i), htitle, nranges, xlow2D, xup2D);
	hSigmaProton[i]->GetXaxis()->SetTitle(xlabel2D);
	hSigmaProton[i]->GetYaxis()->SetTitle(ylabel4);
	hSigmaProton[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hSigmaProton[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hSigmaProton[i]->SetMarkerColor(kGreen+i-3); 
	hSigmaProton[i]->SetLineColor(kGreen+i-3);
	hSigmaProton[i]->SetMarkerStyle(20);
	hSigmaProton[i]->SetLineWidth(2);

	hSigmaPion[i] = new TH1F(Form("hSigmaPion[%i]", i), htitle, nranges, xlow2D, xup2D2);
	hSigmaPion[i]->GetXaxis()->SetTitle(xlabel2D);
	hSigmaPion[i]->GetYaxis()->SetTitle(ylabel4);
	hSigmaPion[i]->GetYaxis()->SetTitleOffset(ylabel_offset);
	hSigmaPion[i]->GetXaxis()->SetTitleOffset(xlabel_offset);
	hSigmaPion[i]->SetMarkerColor(kGreen+i-3); 
	hSigmaPion[i]->SetLineColor(kGreen+i-3);
	hSigmaPion[i]->SetMarkerStyle(20);
	hSigmaPion[i]->SetLineWidth(2);
	
	}
	

	for (int i = 0; i < 6; i++){
	for (int j = 0; j < nranges; j++){
		hProton[j] = hRecProton2D[i]->ProjectionY("hProton", (j)*(nbins2D/nranges), (j+1)*(nbins2D/nranges), "e");
		hPion[j] = hRecPion2D[i]->ProjectionY("hPion", (j)*(nbins2D/nranges), (j+1)*(nbins2D/nranges), "e");

		Double_t mu_Proton_loop =  hProton[j]->GetMean(1);
		Double_t mu_Proton_loop_err =  hProton[j]->GetMeanError(1);
		Double_t sigma_Proton_loop =  hProton[j]->GetStdDev(1);
		Double_t sigma_Proton_loop_err =  hProton[j]->GetStdDevError(1);

		Double_t mu_Pion_loop =  hPion[j]->GetMean(1);
		Double_t mu_Pion_loop_err =  hPion[j]->GetMeanError(1);
		Double_t sigma_Pion_loop =  hPion[j]->GetStdDev(1);
		Double_t sigma_Pion_loop_err =  hPion[j]->GetStdDevError(1);

		hMuProton[i]->SetBinContent(j+1, mu_Proton_loop);
   		hMuProton[i]->SetBinError(j+1, mu_Proton_loop_err);
		hSigmaProton[i]->SetBinContent(j+1, sigma_Proton_loop);
   		hSigmaProton[i]->SetBinError(j+1, sigma_Proton_loop_err);

		hMuPion[i]->SetBinContent(j+1, mu_Pion_loop);
   		hMuPion[i]->SetBinError(j+1, mu_Pion_loop_err);
		hSigmaPion[i]->SetBinContent(j+1, sigma_Pion_loop);
   		hSigmaPion[i]->SetBinError(j+1, sigma_Pion_loop_err);

		hProton[j]->Reset();
		hPion[j]->Reset();
	}
	}


	//-------------------------
  	// Draw Proton Mu and Sigma 
  	//-------------------------

	int number_draw = 3;
	
	TCanvas *canvas1 = new TCanvas("canvas1", "canvas1", 1000, 1000);
	// canvas1->SetGrid();
	// canvas1->SetLogz();
	canvas1->SetTicks();

	hMuProton[0]->Draw("P E");
	for (int i = 0; i < number_draw; i++){hMuProton[i]->Draw("P E SAMES");}
	hMuProton[0]->GetYaxis()->SetRangeUser(0, 0.15 * resclaing_factor);

	TLatex latex1;
  	latex1.SetTextSize(0.035);
	latex1.SetTextFont(text_font);
	latex1.DrawLatexNDC(0.60, 0.84, "#color[15]{This Thesis}");
	latex1.DrawLatexNDC(0.60, 0.80, "ALICE simulations");
  	latex1.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latex1.DrawLatexNDC(0.60, 0.72, "Protons");

	TLegend *leg1 = new TLegend(0.15, 0.62, 0.5, 0.87, "", "brNDC");
	leg1->AddEntry(hMuProton[0], "4.2 < r_{#Lambda} < 9.2 cm");
	leg1->AddEntry(hMuProton[1], "9.2 < r_{#Lambda} < 14.2 cm");
	leg1->AddEntry(hMuProton[2], "14.2 < r_{#Lambda} < 19.2 cm");
	// leg1->AddEntry(hMuProton[3], "4.2 < r_{#Lambda} < 9.2 cm");
	// leg1->AddEntry(hMuProton[4], "9.2 < r_{#Lambda} < 14.2 cm");
	// leg1->AddEntry(hMuProton[5], "14.2 < r_{#Lambda} < 19.2 cm");
	leg1->SetFillStyle(0);
	leg1->Draw();




	TCanvas *canvas2 = new TCanvas("canvas2", "canvas2", 1000, 1000);
	// canvas2->SetGrid();
	// canvas2->SetLogz();
	canvas2->SetTicks();

	hSigmaProton[0]->Draw("P E");
	for (int i = 0; i < number_draw; i++){hSigmaProton[i]->Draw("P E SAMES");}
	hSigmaProton[0]->GetYaxis()->SetRangeUser(0, 0.15 * resclaing_factor);

	TLatex latex2;
  	latex2.SetTextSize(0.035);
	latex2.SetTextFont(text_font);
	latex2.DrawLatexNDC(0.60, 0.84, "#color[15]{This Thesis}");
	latex2.DrawLatexNDC(0.60, 0.80, "ALICE simulations");
  	latex2.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latex2.DrawLatexNDC(0.60, 0.72, "Protons");

	TLegend *leg2 = new TLegend(0.15, 0.62, 0.5, 0.87, "", "brNDC");
	leg2->AddEntry(hSigmaProton[0], "4.2 < r_{#Lambda} < 9.2 cm");
	leg2->AddEntry(hSigmaProton[1], "9.2 < r_{#Lambda} < 14.2 cm");
	leg2->AddEntry(hSigmaProton[2], "14.2 < r_{#Lambda} < 19.2 cm");
	// leg2->AddEntry(hSigmaProton[3], "4.2 < r_{#Lambda} < 9.2 cm");
	// leg2->AddEntry(hSigmaProton[4], "9.2 < r_{#Lambda} < 14.2 cm");
	// leg2->AddEntry(hSigmaProton[5], "14.2 < r_{#Lambda} < 19.2 cm");
	leg2->SetFillStyle(0);
	leg2->Draw();



	//-------------------------
  	// Draw Pion Mu and Sigma 
  	//-------------------------


	TCanvas *canvas3 = new TCanvas("canvas3", "canvas3", 1000, 1000);
	// canvas3->SetGrid();
	// canvas3->SetLogz();
	canvas3->SetTicks();

	hMuPion[0]->Draw("P E");
	for (int i = 0; i < number_draw; i++){hMuPion[i]->Draw("P E SAMES");}
	hMuPion[0]->GetYaxis()->SetRangeUser(0, 0.15 * resclaing_factor);

	TLatex latex3;
  	latex3.SetTextSize(0.035);
	latex3.SetTextFont(text_font);
	latex3.DrawLatexNDC(0.60, 0.84, "#color[15]{This Thesis}");
	latex3.DrawLatexNDC(0.60, 0.80, "ALICE simulations");
  	latex3.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latex3.DrawLatexNDC(0.60, 0.72, "Pions");

	TLegend *leg3 = new TLegend(0.15, 0.62, 0.5, 0.87, "", "brNDC");
	leg3->AddEntry(hMuPion[0], "4.2 < r_{#Lambda} < 9.2 cm");
	leg3->AddEntry(hMuPion[1], "9.2 < r_{#Lambda} < 14.2 cm");
	leg3->AddEntry(hMuPion[2], "14.2 < r_{#Lambda} < 19.2 cm");
	// leg3->AddEntry(hMuPion[3], "4.2 < r_{#Lambda} < 9.2 cm");
	// leg3->AddEntry(hMuPion[4], "9.2 < r_{#Lambda} < 14.2 cm");
	// leg3->AddEntry(hMuPion[5], "14.2 < r_{#Lambda} < 19.2 cm");
	leg3->SetFillStyle(0);
	leg3->Draw();




	TCanvas *canvas4 = new TCanvas("canvas4", "canvas4", 1000, 1000);
	// canvas4->SetGrid();
	// canvas4->SetLogz();
	canvas4->SetTicks();

	hSigmaPion[0]->Draw("P E");
	for (int i = 0; i < number_draw; i++){hSigmaPion[i]->Draw("P E SAMES");}
	hSigmaPion[0]->GetYaxis()->SetRangeUser(0,0.15 * resclaing_factor);

	TLatex latex4;
  	latex4.SetTextSize(0.035);
	latex4.SetTextFont(text_font);
	latex4.DrawLatexNDC(0.60, 0.84, "#color[15]{This Thesis}");
	latex4.DrawLatexNDC(0.60, 0.80, "ALICE simulations");
  	latex4.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latex4.DrawLatexNDC(0.60, 0.72, "Pions");

	TLegend *leg4 = new TLegend(0.15, 0.62, 0.5, 0.87, "", "brNDC");
	leg4->AddEntry(hSigmaPion[0], "4.2 < r_{#Lambda} < 9.2 cm");
	leg4->AddEntry(hSigmaPion[1], "9.2 < r_{#Lambda} < 14.2 cm");
	leg4->AddEntry(hSigmaPion[2], "14.2 < r_{#Lambda} < 19.2 cm");
	// leg4->AddEntry(hSigmaPion[3], "4.2 < r_{#Lambda} < 9.2 cm");
	// leg4->AddEntry(hSigmaPion[4], "9.2 < r_{#Lambda} < 14.2 cm");
	// leg4->AddEntry(hSigmaPion[5], "14.2 < r_{#Lambda} < 19.2 cm");
	leg4->SetFillStyle(0);
	leg4->Draw();


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "pdf";


	

	if (xresi){
	canvas1->SaveAs(Form("%s/XErrProton.%s", directory, format));
	//canvas2->SaveAs(Form("%s/XProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/XErrPion.%s", directory, format));
	//canvas4->SaveAs(Form("%s/XPionSigma.%s", directory, format));
	}
	if (yresi){
	canvas1->SaveAs(Form("%s/YErrProton.%s", directory, format));
	//canvas2->SaveAs(Form("%s/YProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/YErrPion.%s", directory, format));
	//canvas4->SaveAs(Form("%s/YPionSigma.%s", directory, format));
	}
	if (zresi){
	canvas1->SaveAs(Form("%s/ZErrProton.%s", directory, format));
	//canvas2->SaveAs(Form("%s/ZProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/ZErrPion.%s", directory, format));
	//canvas4->SaveAs(Form("%s/ZPionSigma.%s", directory, format));

	canvasT0->SaveAs(Form("%s/ZErrProtonTH2_0.%s", directory, format));
	canvasT1->SaveAs(Form("%s/ZErrProtonTH2_1.%s", directory, format));
	canvasT2->SaveAs(Form("%s/ZErrProtonTH2_2.%s", directory, format));

	canvasT3->SaveAs(Form("%s/ZErrPionTH2_0.%s", directory, format));
	canvasT4->SaveAs(Form("%s/ZErrPionTH2_1.%s", directory, format));
	canvasT5->SaveAs(Form("%s/ZErrPionTH2_2.%s", directory, format));
	}
	if (xyresi){
	canvas1->SaveAs(Form("%s/XYErrProton.%s", directory, format));
	//canvas2->SaveAs(Form("%s/XYProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/XYErrPion.%s", directory, format));
	//canvas4->SaveAs(Form("%s/XYPionSigma.%s", directory, format));

	canvasT0->SaveAs(Form("%s/XYErrProtonTH2_0.%s", directory, format));
	canvasT1->SaveAs(Form("%s/XYErrProtonTH2_1.%s", directory, format));
	canvasT2->SaveAs(Form("%s/XYErrProtonTH2_2.%s", directory, format));

	canvasT3->SaveAs(Form("%s/XYErrPionTH2_0.%s", directory, format));
	canvasT4->SaveAs(Form("%s/XYErrPionTH2_1.%s", directory, format));
	canvasT5->SaveAs(Form("%s/XYErrPionTH2_2.%s", directory, format));
	}

}