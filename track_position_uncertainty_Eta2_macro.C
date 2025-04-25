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


vector<vector<float>> read_in_2Ddata(const char *filename, int dimensions[2]) {
	// Open the file
	ifstream file(filename);

	// Skip the first line
	string dummyLine;
	getline(file, dummyLine);

	// 3D array to store values
	vector<vector<float>> data(dimensions[0], vector<float>(dimensions[1]));

	// Read values from the file into the array
	for (int i = 0; i < dimensions[0]; i++) {
		for (int j = 0; j < dimensions[1]; j++) {
			file >> data[i][j];
		}
	}

	file.close(); // Close the file
	return data;
}


void track_position_uncertainty_Eta2_macro() {

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


	TCut V0RadCutMC = "sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) > 4.5 && sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) < 19.2";

	const char *eta_norm_proton = "sqrt(pow(fEtaProton,2))";
	TCut EtaProton[6] = {Form("0 < %s < 1", eta_norm_proton),
						 Form("%s > 0.0 && %s < 0.2", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.2 && %s < 0.4", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.4 && %s < 0.6", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.6 && %s < 0.8", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.8 && %s < 1.0", eta_norm_proton, eta_norm_proton)};

	const char *eta_norm_pion = "sqrt(pow(fEtaPion,2))";
	TCut EtaPion[6] = {Form("0 < %s < 1", eta_norm_pion),
					   Form("%s > 0.0 && %s < 0.2", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.2 && %s < 0.4", eta_norm_pion, eta_norm_pion),
		 			   Form("%s > 0.4 && %s < 0.6", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.6 && %s < 0.8", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.8 && %s < 1.0", eta_norm_pion, eta_norm_pion)};


	const char *ptProtonMC = "sqrt(pow(fPxProtonMC,2) + pow(fPyProtonMC,2))";
	const char *ptPionMC = "sqrt(pow(fPxPionMC,2) + pow(fPyPionMC,2))";

	float ptProtonMeans[3] = {1.078, 1.267, 1.433};
	float pTProtonOffset = 0.2;
	TCut pTCutProton[3] = {Form("%s > %f - %f && %s < %f + %f", ptProtonMC, ptProtonMeans[0], pTProtonOffset, ptProtonMC, ptProtonMeans[0], pTProtonOffset),
						 Form("%s > %f - %f && %s < %f + %f", ptProtonMC, ptProtonMeans[1], pTProtonOffset, ptProtonMC, ptProtonMeans[1], pTProtonOffset),
						 Form("%s > %f - %f && %s < %f + %f", ptProtonMC, ptProtonMeans[2], pTProtonOffset, ptProtonMC, ptProtonMeans[2], pTProtonOffset)};


	float ptPionMeans[3] = {0.245, 0.272, 0.304};
	float pTPionOffset = 0.05;
	TCut pTCutPion[3] = {Form("%s > %f - %f && %s < %f + %f", ptPionMC, ptPionMeans[0], pTPionOffset, ptPionMC, ptPionMeans[0], pTPionOffset),
						 Form("%s > %f - %f && %s < %f + %f", ptPionMC, ptPionMeans[1], pTPionOffset, ptPionMC, ptPionMeans[1], pTPionOffset),
						 Form("%s > %f - %f && %s < %f + %f", ptPionMC, ptPionMeans[2], pTPionOffset, ptPionMC, ptPionMeans[2], pTPionOffset)};

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
	const char *directory = "Plots_LHC23k4g_Eta2";

    // TFile *OutputFile = TFile::Open(Form("%s/resopull.root", directory), "RECREATE");

	//-------------------------
  	// variables
  	//-------------------------

	int resclaing_factor = 10000;   // 1 cm = 10000 mum

	const char *zProtonresi = Form("fZProtonRecErr * %i", resclaing_factor);
	const char *zPionresi = Form("fZPionRecErr * %i", resclaing_factor);

	const char *xyProtonresi = Form("sqrt(pow(fXProtonRecErr,2) + pow(fYProtonRecErr,2)) * %i", resclaing_factor);
	const char *xyPionresi = Form("sqrt(pow(fXPionRecErr,2) + pow(fYPionRecErr,2)) * %i", resclaing_factor);

	bool zresi = true;
	bool xyresi = false;

	int pseudorapidity_iter = 0; // 0 = 0 < eta < 2, 1 = 0 < eta < 0.2, 2 = 0.2 < eta < 0.4, 3 = 0.4 < eta < 0.6, 4 = 0.6 < eta < 0.8, 5 = 0.8 < eta < 1.0

	//-------------------------
  	// differential proton and pion residuals 
  	//-------------------------

	int nbins2D = 100;
	float ylow2D = 0;
	float xlow2D = 0;
	float yup2D = 2000;
	float xup2D = 1;
	float zup = 10000;
	float labelsize = 0.03;
	float ylabel_offset2D = 1.3;
	float xlabel_offset2D = 1.2;

	const char *xlabel2D = "|#eta|";
	const char *ylabel2D;

	if (zresi){ylabel2D = "#sigma_{z}^{Rec} [#mum]";}
	if (xyresi){ylabel2D = "#sigma_{xy}^{Rec} [#mum]";}

	TH2F *hRecProton2D[6];
	for (int i = 0; i < 6; i++){hRecProton2D[i] = new TH2F(Form("hRecProton2D[%i]", i), "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);}
	if (zresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", zProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && pTCutProton[0], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", zProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && pTCutProton[1], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", zProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && pTCutProton[2], "GOFF");
	}
	if (xyresi){
	Tree->Draw(Form("%s:%s>>hRecProton2D[0]", xyProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[0] && V0RadCutMC && pTCutProton[0], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[1]", xyProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[1] && V0RadCutMC && pTCutProton[1], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecProton2D[2]", xyProtonresi, eta_norm_proton), isTrueCasc && V0woMaterialProton[2] && V0RadCutMC && pTCutProton[2], "GOFF");
	}

	float xup2D2 = 1;

	TH2F *hRecPion2D[6];
	for (int i = 0; i < 6; i++){hRecPion2D[i] = new TH2F(Form("hRecPion2D[%i]", i), "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);}
	if(zresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", zPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && pTCutPion[0], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", zPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && pTCutPion[1], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", zPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && pTCutPion[2], "GOFF");
	}
	if(xyresi){
	Tree->Draw(Form("%s:%s>>hRecPion2D[0]", xyPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[0] && V0RadCutMC && pTCutPion[0], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[1]", xyPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[1] && V0RadCutMC && pTCutPion[1], "GOFF");
	Tree->Draw(Form("%s:%s>>hRecPion2D[2]", xyPionresi, eta_norm_pion), isTrueCasc && V0woMaterialPion[2] && V0RadCutMC && pTCutPion[2], "GOFF");	
	}


	//-------------------------
  	// Print TH2s for consistency
  	//-------------------------

	int canvasTH2sizeX = 1050;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;

	const char *extrapolation_radii_str[3] = {"4.2 < r_{#Lambda} < 9.2 cm", "9.2 < r_{#Lambda} < 14.2 cm", "14.2 < r_{#Lambda} < 19.2 cm"};

	TCanvas *canvas2D[6];
	for (int i = 0; i < 6; i++){
		canvas2D[i] = new TCanvas(Form("canvas2D[%i]", i), "", canvasTH2sizeX, canvasTH2sizeY);
		canvas2D[i]->SetTicks();
		canvas2D[i]->SetRightMargin(0.125);}

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

	int dimensions_proton[2] = {3, 100}; // Dimensions of the 3D array
	int dimensions_pion[2] = {3, 100};   // Dimensions of the 3D array
	const char *filename1 = "DataEta/proton_rphi_4hits.txt"; // Name of the file to read from
	const char *filename2 = "DataEta/pion_rphi_4hits.txt";	  // Name of the file to read from
	const char *filename3 = "DataEta/proton_z_4hits.txt";	  // Name of the file to read from
	const char *filename4 = "DataEta/pion_z_4hits.txt";	  // Name of the file to read from

	auto proton_rphi_data = read_in_2Ddata(filename1, dimensions_proton);
	auto pion_rphi_data = read_in_2Ddata(filename2, dimensions_pion);
	auto proton_z_data = read_in_2Ddata(filename3, dimensions_proton);
	auto pion_z_data = read_in_2Ddata(filename4, dimensions_pion);

	TH1F *hProtonRPHI[3];
	TH1F *hPionRPHI[3];

	int mtomum = 1000000;

	float xlowAnalytic = 0;
	float xupAnalyticProton = 1.0;
	float xupAnalyticPion = 1.0;

	for (int i = 0; i < 3; i++){
		hProtonRPHI[i] = new TH1F(Form("hProtonRPHI[%i]", i), "", 100, xlowAnalytic, xupAnalyticProton);
		hProtonRPHI[i]->SetMarkerColor(kRed); 
		hProtonRPHI[i]->SetLineColor(kRed);
		hProtonRPHI[i]->SetMarkerStyle(20);
		hProtonRPHI[i]->SetLineWidth(2);

		hPionRPHI[i] = new TH1F(Form("hPionRPHI[%i]", i), "", 100, xlowAnalytic, xupAnalyticPion);
		hPionRPHI[i]->SetMarkerColor(kRed); 
		hPionRPHI[i]->SetLineColor(kRed);
		hPionRPHI[i]->SetMarkerStyle(20);
		hPionRPHI[i]->SetLineWidth(2);
	}

	for (int j=0; j < 100; j++){
		for (int k=0; k < 3; k++){
			if (xyresi){hProtonRPHI[k]->SetBinContent(j+1, proton_rphi_data[2-k][j]*mtomum);}
			if (zresi){hProtonRPHI[k]->SetBinContent(j+1, proton_z_data[2-k][j]*mtomum);}
		}
	}

	for (int j=0; j < 100; j++){
		for (int k=0; k < 3; k++){
			if (xyresi){hPionRPHI[k]->SetBinContent(j+1, pion_rphi_data[2-k][j]*mtomum);}
			if (zresi){hPionRPHI[k]->SetBinContent(j+1, pion_z_data[2-k][j]*mtomum);}
		}
	}


	const char *pseudorapidity_iter_str[6] = {"0 < |#eta| < 1", "0 < |#eta| < 0.2", "0.2 < |#eta| < 0.4",
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
		latexT[i].DrawLatexNDC(0.60, 0.72, Form("%.3f < p_{T} < %.3f", ptProtonMeans[i]-pTProtonOffset, ptProtonMeans[i]+pTProtonOffset));
	}

	for (int i = 3; i < 6; i++){
		canvas2D[i]->cd();
		hPionRPHI[i-3]->Draw("P SAMES");
		latexT[i].DrawLatexNDC(0.40, 0.84, extrapolation_distances_str[i-3]);
		latexT[i].DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
		latexT[i].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
		latexT[i].DrawLatexNDC(0.60, 0.72, Form("%.3f < p_{T} < %.3f", ptPionMeans[i-3]-pTPionOffset, ptPionMeans[i-3]+pTPionOffset));
	}


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "png";

	if (zresi){
	for (int i = 0; i < 3; i++){canvas2D[i]->SaveAs(Form("%s/ZErrProtonTH2_%i_pt.%s", directory, i, format));}
	for (int i = 3; i < 6; i++){canvas2D[i]->SaveAs(Form("%s/ZErrPionTH2_%i_pt.%s", directory, i-3, format));}
	}

	if (xyresi){
	for (int i = 0; i < 3; i++){canvas2D[i]->SaveAs(Form("%s/XYErrProtonTH2_%i_pt.%s", directory, i, format));}
	for (int i = 3; i < 6; i++){canvas2D[i]->SaveAs(Form("%s/XYErrPionTH2_%i_pt.%s", directory, i-3, format));}
	}

}