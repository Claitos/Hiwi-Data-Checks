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


void bluePal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t bluePalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.5; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t green[NRGBs] = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t blue[NRGBs]  = {0.40, 0.60, 0.80, 0.90, 1.00};
	Int_t blue_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		bluePalette[i] = blue_palette+i;
	}
	gStyle->SetPalette(NCont, bluePalette);
}


void greenPal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t greenPalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.5; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t green[NRGBs] = {0.40, 0.60, 0.80, 0.90, 1.00};
	Double_t blue[NRGBs]  = {0.00, 0.00, 0.00, 0.00, 0.00};
	Int_t green_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		greenPalette[i] = green_palette+i;
	}
	gStyle->SetPalette(NCont, greenPalette);
}


void yellowPal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t yellowPalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.5; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.90, 1.00, 1.00, 1.00, 1.00};
	Double_t green[NRGBs] = {0.60, 0.80, 0.90, 1.00, 1.00};
	Double_t blue[NRGBs]  = {0.00, 0.00, 0.00, 0.00, 0.00};
	Int_t yellow_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		yellowPalette[i] = yellow_palette+i;
	}
	gStyle->SetPalette(NCont, yellowPalette);
}


void redPal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t redPalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.5; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.40, 0.60, 0.80, 0.90, 1.00};
	Double_t green[NRGBs] = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t blue[NRGBs]  = {0.00, 0.00, 0.00, 0.00, 0.00};
	Int_t red_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		redPalette[i] = red_palette+i;
	}
	gStyle->SetPalette(NCont, redPalette);
}


void purplePal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t purplePalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.5; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.40, 0.60, 0.80, 0.90, 1.00};
	Double_t green[NRGBs] = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t blue[NRGBs]  = {0.40, 0.60, 0.80, 0.90, 1.00};
	Int_t purple_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		purplePalette[i] = purple_palette+i;
	}
	gStyle->SetPalette(NCont, purplePalette);
}


void track_position_uncertainty_Eta_macro() {

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
	TCut EtaProton[5] = {Form("%s > 0.0 && %s < 0.2", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.2 && %s < 0.4", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.4 && %s < 0.6", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.6 && %s < 0.8", eta_norm_proton, eta_norm_proton),
						 Form("%s > 0.8 && %s < 1.0", eta_norm_proton, eta_norm_proton)};

	const char *eta_norm_pion = "sqrt(pow(fEtaPion,2))";
	TCut EtaPion[5] = {Form("%s > 0.0 && %s < 0.2", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.2 && %s < 0.4", eta_norm_pion, eta_norm_pion),
		 			   Form("%s > 0.4 && %s < 0.6", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.6 && %s < 0.8", eta_norm_pion, eta_norm_pion),
					   Form("%s > 0.8 && %s < 1.0", eta_norm_pion, eta_norm_pion)};
	

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
	const char *directory = "Plots_LHC23k4g_Overlay";

    // TFile *OutputFile = TFile::Open(Form("%s/resopull.root", directory), "RECREATE");

	//-------------------------
  	// variables
  	//-------------------------

	int resclaing_factor = 10000;   // 1 cm = 10000 mum

	const char *zProtonresi = Form("fZProtonRecErr * %i", resclaing_factor);
	const char *zPionresi = Form("fZPionRecErr * %i", resclaing_factor);

	const char *xyProtonresi = Form("sqrt(pow(fXProtonRecErr,2) + pow(fYProtonRecErr,2)) * %i", resclaing_factor);
	const char *xyPionresi = Form("sqrt(pow(fXPionRecErr,2) + pow(fYPionRecErr,2)) * %i", resclaing_factor);

	const char *ptProtonMC = "sqrt(pow(fPxProtonMC,2) + pow(fPyProtonMC,2))";
	const char *ptPionMC = "sqrt(pow(fPxPionMC,2) + pow(fPyPionMC,2))";

	bool zresi = false;
	bool xyresi = true;

	int extr_dis_iter = 1; // 0 = 4.2 < r < 9.2, 1 = 9.2 < r < 14.2, 2 = 14.2 < r < 19.2

	//-------------------------
  	// differential proton and pion track position uncertainties
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

	if (zresi){ylabel2D = "#sigma_{z}^{Rec} [#mum]";}
	if (xyresi){ylabel2D = "#sigma_{xy}^{Rec} [#mum]";}

	TH2F *hRecProton2D[5];
	for (int i = 0; i < 5; i++){
		hRecProton2D[i] = new TH2F(Form("hRecProton2D[%i]", i), "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);
		if (zresi){Tree->Draw(Form("%s:%s>>hRecProton2D[%i]", zProtonresi, ptProtonMC, i), isTrueCasc && V0woMaterialProton[extr_dis_iter] && V0RadCutMC && EtaProton[i], "GOFF");}
		if (xyresi){Tree->Draw(Form("%s:%s>>hRecProton2D[%i]", xyProtonresi, ptProtonMC, i), isTrueCasc && V0woMaterialProton[extr_dis_iter] && V0RadCutMC && EtaProton[i], "GOFF");}
	}
	

	float xup2D2 = 1;
	TH2F *hRecPion2D[5];
	for (int i = 0; i < 5; i++){
		hRecPion2D[i] = new TH2F(Form("hRecPion2D[%i]", i), "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);
		if (zresi){Tree->Draw(Form("%s:%s>>hRecPion2D[%i]", zPionresi, ptPionMC, i), isTrueCasc && V0woMaterialPion[extr_dis_iter] && V0RadCutMC && EtaPion[i], "GOFF");}
		if (xyresi){Tree->Draw(Form("%s:%s>>hRecPion2D[%i]", xyPionresi, ptPionMC, i), isTrueCasc && V0woMaterialPion[extr_dis_iter] && V0RadCutMC && EtaPion[i], "GOFF");}
	}

	//-------------------------
  	// Print TH2s
  	//-------------------------

	TExec *execBlue = new TExec("execBlue", "bluePal();");
	TExec *execGreen = new TExec("execGreen", "greenPal();");
	TExec *execYellow = new TExec("execYellow", "yellowPal();");
	TExec *execRed = new TExec("execRed", "redPal();");
	TExec *execPurple = new TExec("execPurple", "purplePal();");

	TExec *execColors[5]; execColors[0] = execYellow; execColors[1] = execGreen; execColors[2] = execBlue; execColors[3] = execPurple; execColors[4] = execRed;


	int canvasTH2sizeX = 1050;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;


	TCanvas *canvasProton = new TCanvas("canvasProton", "", canvasTH2sizeX, canvasTH2sizeY);
	canvasProton->SetTicks();
	canvasProton->SetRightMargin(0.125);

	hRecProton2D[0]->Draw("AXIS");
	for (int i = 0; i < 5; i++){
		hRecProton2D[i]->SetMinimum(50);         // Set the minimum value for the color scale
		execColors[i]->Draw();
		hRecProton2D[i]->Draw("P COLZ SAME");
		hRecProton2D[i]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
		hRecProton2D[i]->GetXaxis()->SetTitle(xlabel2D);
		hRecProton2D[i]->GetYaxis()->SetTitle(ylabel2D);
		hRecProton2D[i]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
		hRecProton2D[i]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
	}

	TCanvas *canvasPion = new TCanvas("canvasPion", "", canvasTH2sizeX, canvasTH2sizeY);
	canvasPion->SetTicks();
	canvasPion->SetRightMargin(0.125);

	hRecPion2D[0]->Draw("AXIS");
	for (int i = 0; i < 5; i++){
		hRecPion2D[i]->SetMinimum(50);         // Set the minimum value for the color scale
		execColors[i]->Draw();
		hRecPion2D[i]->Draw("P COLZ SAME");
		hRecPion2D[i]->GetYaxis()->SetRangeUser(0, 0.15*resclaing_factor);
		hRecPion2D[i]->GetXaxis()->SetTitle(xlabel2D);
		hRecPion2D[i]->GetYaxis()->SetTitle(ylabel2D);
		hRecPion2D[i]->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
		hRecPion2D[i]->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);
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

	TH1F *hProtonRPHI[6];
	TH1F *hPionRPHI[6];

	int mtomum = 1000000;

	float xlowAnalytic = 0.1;
	float xupAnalyticProton = 4.0;
	float xupAnalyticPion = 1.0;

	int colors[6] = {1, 401, 417, 600, 617, 633};  // colors for the histograms 1 = black, 400 = yellow, 416 = green, 600 = blue, 616 = purple, 632 = red

	for (int i = 0; i < 6; i++){
		hProtonRPHI[i] = new TH1F(Form("hProtonRPHI[%i]", i), "", 39, xlowAnalytic, xupAnalyticProton);
		hProtonRPHI[i]->SetMarkerColor(colors[i]); 
		hProtonRPHI[i]->SetLineColor(colors[i]);
		hProtonRPHI[i]->SetMarkerStyle(20);
		hProtonRPHI[i]->SetLineWidth(2);

		hPionRPHI[i] = new TH1F(Form("hPionRPHI[%i]", i), "", 45, xlowAnalytic, xupAnalyticPion);
		hPionRPHI[i]->SetMarkerColor(colors[i]); 
		hPionRPHI[i]->SetLineColor(colors[i]);
		hPionRPHI[i]->SetMarkerStyle(20);
		hPionRPHI[i]->SetLineWidth(2);
	}

	for (int j=0; j < 39; j++){
		for (int k=0; k < 6; k++){
			if (xyresi){hProtonRPHI[k]->SetBinContent(j+1, proton_rphi_data[k][2-extr_dis_iter][j]*mtomum);}
			if (zresi){hProtonRPHI[k]->SetBinContent(j+1, proton_z_data[k][2-extr_dis_iter][j]*mtomum);}
		}
	}

	for (int j=0; j < 45; j++){
		for (int k=0; k < 6; k++){
			if (xyresi){hPionRPHI[k]->SetBinContent(j+1, pion_rphi_data[k][2-extr_dis_iter][j]*mtomum);}
			if (zresi){hPionRPHI[k]->SetBinContent(j+1, pion_z_data[k][2-extr_dis_iter][j]*mtomum);}
		}
	}


	const char *pseudorapidity_iter_str[5] = {"0 < |#eta| < 0.2", "0.2 < |#eta| < 0.4", "0.4 < |#eta| < 0.6", "0.6 < |#eta| < 0.8", "0.8 < |#eta| < 1.0"};
	const char *extrapolation_distances_str[3] = {"extrapolation distance = 12.5 cm", "extrapolation distance = 7.5 cm", "extrapolation distance = 2.5 cm"};
	const char *extrapolation_radii_str[3] = {"4.2 < r_{#Lambda} < 9.2 cm", "9.2 < r_{#Lambda} < 14.2 cm", "14.2 < r_{#Lambda} < 19.2 cm"};

	
	TLatex latexProton;
	latexProton.SetTextSize(0.035);
	latexProton.SetTextFont(text_font);

	TLatex latexPion;
	latexPion.SetTextSize(0.035);
	latexPion.SetTextFont(text_font);


	canvasProton->cd();
	latexProton.DrawLatexNDC(0.40, 0.84, extrapolation_distances_str[extr_dis_iter]);
	latexProton.DrawLatexNDC(0.40, 0.80, "Protons with 4 hits");
	latexProton.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexProton.DrawLatexNDC(0.60, 0.72, extrapolation_radii_str[extr_dis_iter]);

	for (int i = 1; i < 6; i++){hProtonRPHI[i]->Draw("P SAMES");}

	TLegend *legProton = new TLegend(0.5, 0.45, 0.8, 0.65, "", "brNDC");
	for (int i = 0; i < 5; i++){legProton->AddEntry(hProtonRPHI[i+1], pseudorapidity_iter_str[i]);}
	legProton->Draw();


	canvasPion->cd();
	latexPion.DrawLatexNDC(0.40, 0.84, extrapolation_distances_str[extr_dis_iter]);
	latexPion.DrawLatexNDC(0.40, 0.80, "Pions with 4 hits");
	latexPion.DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");
	latexPion.DrawLatexNDC(0.60, 0.72, extrapolation_radii_str[extr_dis_iter]);

	for (int i = 1; i < 6; i++){hPionRPHI[i]->Draw("P SAMES");}

	TLegend *legPion = new TLegend(0.5, 0.45, 0.8, 0.65, "", "brNDC");
	for (int i = 0; i < 5; i++){legPion->AddEntry(hPionRPHI[i+1], pseudorapidity_iter_str[i]);}
	legPion->Draw();


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "png";

	if (zresi){
		canvasProton->SaveAs(Form("%s/ZErrProton_Rad%i.%s", directory, extr_dis_iter, format));
		canvasPion->SaveAs(Form("%s/ZErrPion_Rad%i.%s", directory, extr_dis_iter, format));
	}

	if (xyresi){
		canvasProton->SaveAs(Form("%s/XYErrProton_Rad%i.%s", directory, extr_dis_iter, format));
		canvasPion->SaveAs(Form("%s/XYErrPion_Rad%i.%s", directory, extr_dis_iter, format));
	}

}