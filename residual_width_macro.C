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

void residual_width_macro() {

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

	const char *xProtonresi = "fXProtonRec - fV0VtxXMC";
	const char *yProtonresi = "fYProtonRec - fV0VtxYMC";
	const char *zProtonresi = "fZProtonRec - fV0VtxZMC";

	const char *xPionresi = "fXPionRec - fV0VtxXMC";
	const char *yPionresi = "fYPionRec - fV0VtxYMC";
	const char *zPionresi = "fZPionRec - fV0VtxZMC";

	const char *ptProtonMC = "sqrt(pow(fPxProtonMC,2) + pow(fPyProtonMC,2))";
	const char *ptPionMC = "sqrt(pow(fPxPionMC,2) + pow(fPyPionMC,2))";

	bool xresi = true;
	bool yresi = false;
	bool zresi = false;

	//-------------------------
  	// differential proton and pion residuals 
  	//-------------------------

	int nbins2D = 50;
	float ylow2D = -0.2;
	float xlow2D = 0;
	float yup2D = 0.2;
	float xup2D = 4;
	float zup = 10000;
	float labelsize = 0.03;
	float ylabel_offset2D = 1.3;
	float xlabel_offset2D = 1.2;

	const char *xlabel2D = "p_{T}^{MC} [GeV/c]";
	const char *ylabel2D = "x^{Rec} - x^{MC} [cm]";

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
	if (xresi){htitle = "x^{Rec} - x^{MC}";}
	if (yresi){htitle = "y^{Rec} - y^{MC}";}
	if (zresi){htitle = "z^{Rec} - z^{MC}";}

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
	
	int rescale_factor = 10000;   // for cm  in microns 

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

		hMuProton[i]->SetBinContent(j+1, mu_Proton_loop * rescale_factor);
   		hMuProton[i]->SetBinError(j+1, mu_Proton_loop_err * rescale_factor);
		hSigmaProton[i]->SetBinContent(j+1, sigma_Proton_loop * rescale_factor);
   		hSigmaProton[i]->SetBinError(j+1, sigma_Proton_loop_err * rescale_factor);

		hMuPion[i]->SetBinContent(j+1, mu_Pion_loop * rescale_factor);
   		hMuPion[i]->SetBinError(j+1, mu_Pion_loop_err * rescale_factor);
		hSigmaPion[i]->SetBinContent(j+1, sigma_Pion_loop * rescale_factor);
   		hSigmaPion[i]->SetBinError(j+1, sigma_Pion_loop_err * rescale_factor);

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

	TLine *l1 = new TLine(xlow2D,0,xup2D,0);
	// l1->SetLineColor(6);
	l1->SetLineWidth(3);
	l1->SetLineStyle(2);
	l1->Draw();
	
	for (int i = 0; i < number_draw; i++){hMuProton[i]->Draw("P E SAMES");}
	hMuProton[0]->GetYaxis()->SetRangeUser(-0.02 * rescale_factor,0.02 * rescale_factor);

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
	hSigmaProton[0]->GetYaxis()->SetRangeUser(0,0.15 * rescale_factor);

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

	TLine *l3 = new TLine(xlow2D,0,xup2D2,0);
	// l3->SetLineColor(6);
	l3->SetLineWidth(3);
	l3->SetLineStyle(2);
	l3->Draw();
	
	for (int i = 0; i < number_draw; i++){hMuPion[i]->Draw("P E SAMES");}
	hMuPion[0]->GetYaxis()->SetRangeUser(-0.02 * rescale_factor,0.02 * rescale_factor);

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
	hSigmaPion[0]->GetYaxis()->SetRangeUser(0,0.15 * rescale_factor);

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
	canvas1->SaveAs(Form("%s/XProtonMu.%s", directory, format));
	canvas2->SaveAs(Form("%s/XProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/XPionMu.%s", directory, format));
	canvas4->SaveAs(Form("%s/XPionSigma.%s", directory, format));
	}
	if (yresi){
	canvas1->SaveAs(Form("%s/YProtonMu.%s", directory, format));
	canvas2->SaveAs(Form("%s/YProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/YPionMu.%s", directory, format));
	canvas4->SaveAs(Form("%s/YPionSigma.%s", directory, format));
	}
	if (zresi){
	canvas1->SaveAs(Form("%s/ZProtonMu.%s", directory, format));
	canvas2->SaveAs(Form("%s/ZProtonSigma.%s", directory, format));

	canvas3->SaveAs(Form("%s/ZPionMu.%s", directory, format));
	canvas4->SaveAs(Form("%s/ZPionSigma.%s", directory, format));
	}

}