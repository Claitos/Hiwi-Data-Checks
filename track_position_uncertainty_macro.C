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

vector<vector<vector<float>>> read_in_3Ddata(const char *filename, int dimensions[3]) {
	// Open the file
	ifstream file(filename);

	// Skip the first line
	string dummyLine;
	getline(file, dummyLine);

	// 3D array to store values
	vector<vector<vector<float>>> data(dimensions[0], vector<vector<float>>(dimensions[1],  vector<float>(dimensions[2])));

	// Read values from the file into the array
	for (int i = 0; i < dimensions[0]; i++) {
		for (int j = 0; j < dimensions[1]; j++) {
			for (int k = 0; k < dimensions[2]; k++) {
				file >> data[i][j][k];
			}
		}
	}

	file.close(); // Close the file
	return data;
}

void track_position_uncertainty_macro() {

	//-------------------------
	// Load data	
	//-------------------------	

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

	//-------------------------
  	// Cuts
  	//-------------------------

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

	const char *eta_norm_proton = "sqrt(pow(fEtaProton,2))";
	TCut EtaProton[6] = {Form("0 < %s < 2", eta_norm_proton),
						 Form("0 < %s < 0.2", eta_norm_proton),
						 Form("0.2 < %s < 0.4", eta_norm_proton),
						 Form("0.4 < %s < 0.6", eta_norm_proton),
						 Form("0.6 < %s < 0.8", eta_norm_proton),
						 Form("0.8 < %s < 1.0", eta_norm_proton)};

	const char *eta_norm_pion = "sqrt(pow(fEtaPion,2))";
	TCut EtaPion[6] = {Form("0 < %s < 2", eta_norm_pion),
					   Form("0 < %s < 0.2", eta_norm_pion),
					   Form("0.2 < %s < 0.4", eta_norm_pion),
					   Form("0.4 < %s < 0.6", eta_norm_pion),
					   Form("0.6 < %s < 0.8", eta_norm_pion),
					   Form("0.8 < %s < 1.0", eta_norm_pion)};
	

	//-------------------------
  	// Style
  	//-------------------------

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
	const char *directory = "Plots_LHC23k4g_Eta";

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

	int pseudorapidity_iter = 5;

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
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", xProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", xProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	}
	if (yresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", yProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", yProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	}
	if (zresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", zProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	}
	if (xyresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[3]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[0] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[4]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[1] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[5]", xyProtonresi, ptProtonMC), isTrueCasc && V0wMaterialProton[2] && V0RadCutMC && EtaProton[pseudorapidity_iter], "GOFF");
	}

	float xup2D2 = 1;

	TH2F *hRecPion2D[6];
	for (int i = 0; i < 6; i++){hRecPion2D[i] = new TH2F(Form("hRecPion2D[%i]", i), "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);}
	if(xresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", xPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", xPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");		
	}
	if(yresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", yPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", yPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");		
	}
	if(zresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", zPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");		
	}
	if(xyresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[3]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[0] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[4]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[1] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[5]", xyPionresi, ptPionMC), isTrueCasc && V0wMaterialPion[2] && V0RadCutMC && EtaPion[pseudorapidity_iter], "GOFF");		
	}


	//-------------------------
  	// Print TH2s for consistency
  	//-------------------------

	int canvasTH2sizeX = 1000;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;

	const char *extrapolation_radii_str[3] = {"4.2 < r_{#Lambda} < 9.2 cm", "9.2 < r_{#Lambda} < 14.2 cm", "14.2 < r_{#Lambda} < 19.2 cm"};

	TCanvas *canvas2D[6];
	for (int i = 0; i < 6; i++){
		canvas2D[i] = new TCanvas(Form("canvas2D[%i]", i), "", canvasTH2sizeX, canvasTH2sizeY);
		canvas2D[i]->SetTicks();}

	for (int i = 0; i < 3; i++){
		canvas2D[i]->cd();
		hRecProton2D[i]->Draw("P COLZ");
		hRecProton2D[i]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
		hRecProton2D[i]->GetXaxis()->SetTitle(xlabel2D);
		hRecProton2D[i]->GetYaxis()->SetTitle(ylabel2D);
		hRecProton2D[i]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
		hRecProton2D[i]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
		hRecProton2D[i]->SetTitle(extrapolation_radii_str[i]);
	}

	for (int i = 0; i < 3; i++){
		canvas2D[i+3]->cd();
		hRecPion2D[i]->Draw("P COLZ");
		hRecPion2D[i]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
		hRecPion2D[i]->GetXaxis()->SetTitle(xlabel2D);
		hRecPion2D[i]->GetYaxis()->SetTitle(ylabel2D);
		hRecPion2D[i]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
		hRecPion2D[i]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
		hRecPion2D[i]->SetTitle(extrapolation_radii_str[i]);
	}

	//-------------------------
  	// Plot data from Notebook
  	//-------------------------

	int dimensions_proton[3] = {6, 3, 39}; // Dimensions of the 3D array
	int dimensions_pion[3] = {6, 3, 45};   // Dimensions of the 3D array
	const char *filename1 = "Data/proton_rphi_4hits.txt"; // Name of the file to read from
	const char *filename2 = "Data/pion_rphi_4hits.txt";	  // Name of the file to read from
	const char *filename3 = "Data/proton_z_4hits.txt";	  // Name of the file to read from
	const char *filename4 = "Data/pion_z_4hits.txt";	  // Name of the file to read from

	auto proton_rphi_data = read_in_3Ddata(filename1, dimensions_proton);
	auto pion_rphi_data = read_in_3Ddata(filename2, dimensions_pion);
	auto proton_z_data = read_in_3Ddata(filename3, dimensions_proton);
	auto pion_z_data = read_in_3Ddata(filename4, dimensions_pion);

	TH1F *hProtonRPHI[3];
	TH1F *hPionRPHI[3];

	int mtomum = 1000000;

	float xlowAnalytic = 0.1;
	float xupAnalyticProton = 4.0;
	float xupAnalyticPion = 1.0;

	for (int i = 0; i < 3; i++){
		hProtonRPHI[i] = new TH1F(Form("hProtonRPHI[%i]", i), "", 39, xlowAnalytic, xupAnalyticProton);
		hProtonRPHI[i]->SetMarkerColor(kRed); 
		hProtonRPHI[i]->SetLineColor(kRed);
		hProtonRPHI[i]->SetMarkerStyle(20);
		hProtonRPHI[i]->SetLineWidth(2);

		hPionRPHI[i] = new TH1F(Form("hPionRPHI[%i]", i), "", 45, xlowAnalytic, xupAnalyticPion);
		hPionRPHI[i]->SetMarkerColor(kRed); 
		hPionRPHI[i]->SetLineColor(kRed);
		hPionRPHI[i]->SetMarkerStyle(20);
		hPionRPHI[i]->SetLineWidth(2);
	}

	for (int j=0; j < 39; j++){
		for (int k=0; k < 3; k++){
			if (xyresi){hProtonRPHI[k]->SetBinContent(j+1, proton_rphi_data[pseudorapidity_iter][2-k][j]*mtomum);}
			if (zresi){hProtonRPHI[k]->SetBinContent(j+1, proton_z_data[pseudorapidity_iter][2-k][j]*mtomum);}
		}
	}

	for (int j=0; j < 45; j++){
		for (int k=0; k < 3; k++){
			if (xyresi){hPionRPHI[k]->SetBinContent(j+1, pion_rphi_data[pseudorapidity_iter][2-k][j]*mtomum);}
			if (zresi){hPionRPHI[k]->SetBinContent(j+1, pion_z_data[pseudorapidity_iter][2-k][j]*mtomum);}
		}
	}


	const char *pseudorapidity_iter_str[6] = {"0 < |#eta| < 2", "0 < |#eta| < 0.2", "0.2 < |#eta| < 0.4",
											  "0.4 < |#eta| < 0.6", "0.6 < |#eta| < 0.8", "0.8 < |#eta| < 1.0"};

	const char *extrapolation_distances_str[3] = {"extrapolation distance = 12.5 cm", "extrapolation distance = 7.5 cm", "extrapolation distance = 2.5 cm"};

	
	TLatex latexT[6];

	for (int i = 0; i < 6; i++){
		latexT[i].SetTextSize(0.035);
		latexT[i].SetTextFont(text_font);
	}

	for (int i = 0; i < 3; i++){
		canvas2D[i]->cd();
		hProtonRPHI[i]->Draw("P SAMES");
		latexT[i].DrawLatexNDC(0.40, 0.84, extrapolation_distances_str[i]);
		latexT[i].DrawLatexNDC(0.40, 0.80, "Protons with 4 hits");
		latexT[i].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
		latexT[i].DrawLatexNDC(0.60, 0.72, pseudorapidity_iter_str[pseudorapidity_iter]);
	}

	for (int i = 3; i < 6; i++){
		canvas2D[i]->cd();
		hPionRPHI[i-3]->Draw("P SAMES");
		latexT[i].DrawLatexNDC(0.40, 0.84, extrapolation_distances_str[i-3]);
		latexT[i].DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
		latexT[i].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
		latexT[i].DrawLatexNDC(0.60, 0.72, pseudorapidity_iter_str[pseudorapidity_iter]);
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
	// canvas1->SaveAs(Form("%s/XErrProton.%s", directory, format));
	// //canvas2->SaveAs(Form("%s/XProtonSigma.%s", directory, format));

	// canvas3->SaveAs(Form("%s/XErrPion.%s", directory, format));
	// //canvas4->SaveAs(Form("%s/XPionSigma.%s", directory, format));
	}

	if (yresi){
	// canvas1->SaveAs(Form("%s/YErrProton.%s", directory, format));
	// //canvas2->SaveAs(Form("%s/YProtonSigma.%s", directory, format));

	// canvas3->SaveAs(Form("%s/YErrPion.%s", directory, format));
	// //canvas4->SaveAs(Form("%s/YPionSigma.%s", directory, format));
	}

	if (zresi){
	// canvas1->SaveAs(Form("%s/ZErrProton.%s", directory, format));
	// //canvas2->SaveAs(Form("%s/ZProtonSigma.%s", directory, format));

	// canvas3->SaveAs(Form("%s/ZErrPion.%s", directory, format));
	// //canvas4->SaveAs(Form("%s/ZPionSigma.%s", directory, format));

	for (int i = 0; i < 3; i++){canvas2D[i]->SaveAs(Form("%s/ZErrProtonTH2_%i_eta%i.%s", directory, i, pseudorapidity_iter, format));}

	for (int i = 3; i < 6; i++){canvas2D[i]->SaveAs(Form("%s/ZErrPionTH2_%i_eta%i.%s", directory, i-3, pseudorapidity_iter, format));}
	}

	if (xyresi){
	// canvas1->SaveAs(Form("%s/XYErrProton.%s", directory, format));
	// //canvas2->SaveAs(Form("%s/XYProtonSigma.%s", directory, format));

	// canvas3->SaveAs(Form("%s/XYErrPion.%s", directory, format));
	// //canvas4->SaveAs(Form("%s/XYPionSigma.%s", directory, format));

	for (int i = 0; i < 3; i++){canvas2D[i]->SaveAs(Form("%s/XYErrProtonTH2_%i_eta%i.%s", directory, i, pseudorapidity_iter, format));}
	
	for (int i = 3; i < 6; i++){canvas2D[i]->SaveAs(Form("%s/XYErrPionTH2_%i_eta%i.%s", directory, i-3, pseudorapidity_iter, format));}
	}

}