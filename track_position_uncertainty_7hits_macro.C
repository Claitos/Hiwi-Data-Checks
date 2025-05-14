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


void bluePal(){
	const Int_t NRGBs = 5;
	const Int_t NCont = 255; 

	Int_t bluePalette[NCont];
	
	Double_t stops[NRGBs] = {0.00, 0.25, 0.50, 0.75, 1.00};
	Float_t alpha = 0.7; // Set transparency (0 = fully transparent, 1 = fully opaque)

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
	Float_t alpha = 0.7; // Set transparency (0 = fully transparent, 1 = fully opaque)

	Double_t red[NRGBs]   = {0.00, 0.00, 0.00, 0.00, 0.00};
	Double_t green[NRGBs] = {0.40, 0.60, 0.80, 0.90, 1.00};
	Double_t blue[NRGBs]  = {0.00, 0.00, 0.00, 0.00, 0.00};
	Int_t green_palette = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont, alpha);

	for (int i = 0; i < NCont; i++){
		greenPalette[i] = green_palette+i;
	}
	gStyle->SetPalette(NCont, greenPalette);
}


void track_position_uncertainty_7hits_macro() {

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

	TCut IUProton_layers = "sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 2.9";
	TCut IUPion_layers = "sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 2.9";

	TCut V0RadCutMC = "sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) > 0 && sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) < 2.5";

	TCut V0woMaterialProton = "fV0Rad > 17.2 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22";
	TCut V0woMaterialPion = "fV0Rad > 17.2 && fV0Rad < 19.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22";

	TCut V0RadCutMC4hits = "sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) > 4.5 && sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) < 19.2";

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
	const char *directory = "Plots_LHC23k4g_7hits";

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

	bool zresi = true;
	bool xyresi = false;

	//-------------------------
  	// differential proton and pion residuals 
  	//-------------------------

	int nbins2D = 100;
	float ylow2D = 0;
	float xlow2D = 0;
	float yup2D = 500;
	float xup2D = 4;
	float zup = 10000;
	float labelsize = 0.03;
	float ylabel_offset2D = 1.3;
	float xlabel_offset2D = 1.2;

	const char *xlabel2D = "p_{T}^{MC} [GeV/c]";
	const char *ylabel2D;

	if (zresi){ylabel2D = "#sigma_{z}^{Rec} [#mum]";}
	if (xyresi){ylabel2D = "#sigma_{xy}^{Rec} [#mum]";}

	TH2F *hRecProton7 = new TH2F("hRecProton7", "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);
	if (zresi){Tree->Draw(Form("%s:%s>>hRecProton7", zProtonresi, ptProtonMC), isTrueCasc && IUProton_layers && V0RadCutMC, "GOFF");}
	if (xyresi){Tree->Draw(Form("%s:%s>>hRecProton7", xyProtonresi, ptProtonMC), isTrueCasc && IUProton_layers && V0RadCutMC, "GOFF");}

	float xup2D2 = 1;

	TH2F *hRecPion7 = new TH2F("hRecPion7", "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);
	if(zresi){Tree->Draw(Form("%s:%s>>hRecPion7", zPionresi, ptPionMC), isTrueCasc && IUPion_layers && V0RadCutMC, "GOFF");}
	if(xyresi){Tree->Draw(Form("%s:%s>>hRecPion7", xyPionresi, ptPionMC), isTrueCasc && IUPion_layers && V0RadCutMC, "GOFF");}


	TH2F *hRecProton4 = new TH2F("hRecProton4", "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);
	if (zresi){Tree->Draw(Form("%s:%s>>hRecProton4", zProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton && V0RadCutMC4hits, "GOFF");}
	if (xyresi){Tree->Draw(Form("%s:%s>>hRecProton4", xyProtonresi, ptProtonMC), isTrueCasc && V0woMaterialProton && V0RadCutMC4hits, "GOFF");}

	TH2F *hRecPion4 = new TH2F("hRecPion4", "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);
	if (zresi){Tree->Draw(Form("%s:%s>>hRecPion4", zPionresi, ptPionMC), isTrueCasc && V0woMaterialPion && V0RadCutMC4hits, "GOFF");}
	if (xyresi){Tree->Draw(Form("%s:%s>>hRecPion4", xyPionresi, ptPionMC), isTrueCasc && V0woMaterialPion && V0RadCutMC4hits, "GOFF");}


	//-------------------------
  	// Print TH2s for consistency
  	//-------------------------

	TExec *execBlue = new TExec("execBlue", "bluePal();");
	TExec *execGreen = new TExec("execGreen", "greenPal();");

	int canvasTH2sizeX = 1050;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;

	int minimum = 10;

	TCanvas *canvas2D[2];
	for (int i = 0; i < 2; i++){
		canvas2D[i] = new TCanvas(Form("canvas2D[%i]", i), "", canvasTH2sizeX, canvasTH2sizeY);
		canvas2D[i]->SetTicks();
		canvas2D[i]->SetRightMargin(0.125);
	}

	canvas2D[0]->cd();
	hRecProton7->Draw("AXIS");
	hRecProton4->SetMinimum(minimum);         // Set the minimum value for the color scale
	execBlue->Draw();
	hRecProton4->Draw("P COLZ SAME");
	hRecProton7->SetMinimum(minimum);         // Set the minimum value for the color scale
	execGreen->Draw();
	hRecProton7->Draw("P COLZ SAME");
	hRecProton7->GetYaxis()->SetRangeUser(0, 0.05*resclaing_factor);
	hRecProton7->GetXaxis()->SetTitle(xlabel2D);
	hRecProton7->GetYaxis()->SetTitle(ylabel2D);
	hRecProton7->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecProton7->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);

	canvas2D[1]->cd();
	hRecPion7->Draw("AXIS");
	hRecPion4->SetMinimum(minimum);         // Set the minimum value for the color scale
	execBlue->Draw();
	hRecPion4->Draw("P COLZ SAME");
	hRecPion7->SetMinimum(minimum);         // Set the minimum value for the color scale
	execGreen->Draw();
	hRecPion7->Draw("P COLZ SAME");
	hRecPion7->GetYaxis()->SetRangeUser(0, 0.05*resclaing_factor);
	hRecPion7->GetXaxis()->SetTitle(xlabel2D);
	hRecPion7->GetYaxis()->SetTitle(ylabel2D);
	hRecPion7->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecPion7->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);


	//-------------------------
  	// Plot data from Notebook
  	//-------------------------

	int dimensions_proton[2] = {3, 39}; // Dimensions of the 3D array
	int dimensions_pion[2] = {3, 45};   // Dimensions of the 3D array
	const char *filename1 = "Data/proton_rphi_7hits.txt"; // Name of the file to read from
	const char *filename2 = "Data/pion_rphi_7hits.txt";	  // Name of the file to read from
	const char *filename3 = "Data/proton_z_7hits.txt";	  // Name of the file to read from
	const char *filename4 = "Data/pion_z_7hits.txt";	  // Name of the file to read from

	auto proton_rphi_data = read_in_2Ddata(filename1, dimensions_proton);
	auto pion_rphi_data = read_in_2Ddata(filename2, dimensions_pion);
	auto proton_z_data = read_in_2Ddata(filename3, dimensions_proton);
	auto pion_z_data = read_in_2Ddata(filename4, dimensions_pion);

	int mtomum = 1000000;   // 1 m = 1000000 mum

	float xlowAnalytic = 0.1;
	float xupAnalyticProton = 4.0;
	float xupAnalyticPion = 1.0;

	TH1F *hProtonRPHI = new TH1F("hProtonRPHI", "", 39, xlowAnalytic, xupAnalyticProton);
	hProtonRPHI->SetMarkerColor(kGreen+1); 
	hProtonRPHI->SetLineColor(kGreen+1);
	hProtonRPHI->SetMarkerStyle(20);
	hProtonRPHI->SetLineWidth(2);
	TH1F *hPionRPHI = new TH1F("hPionRPHI", "", 45, xlowAnalytic, xupAnalyticPion);
	hPionRPHI->SetMarkerColor(kGreen+1); 
	hPionRPHI->SetLineColor(kGreen+1);
	hPionRPHI->SetMarkerStyle(20);
	hPionRPHI->SetLineWidth(2);


	for (int j=0; j < 39; j++){
		if (xyresi){hProtonRPHI->SetBinContent(j+1, proton_rphi_data[0][j]*mtomum);}
		if (zresi){hProtonRPHI->SetBinContent(j+1, proton_z_data[0][j]*mtomum);}
	}

	for (int j=0; j < 45; j++){
		if (xyresi){hPionRPHI->SetBinContent(j+1, pion_rphi_data[0][j]*mtomum);}
		if (zresi){hPionRPHI->SetBinContent(j+1, pion_z_data[0][j]*mtomum);}
	}

	



	const char *filename5 = "Data/proton_rphi_4hits_1cm.txt"; // Name of the file to read from
	const char *filename6 = "Data/pion_rphi_4hits_1cm.txt";	  // Name of the file to read from
	const char *filename7 = "Data/proton_z_4hits_1cm.txt";	  // Name of the file to read from
	const char *filename8 = "Data/pion_z_4hits_1cm.txt";	  // Name of the file to read from

	auto proton_rphi_data_4 = read_in_2Ddata(filename5, dimensions_proton);
	auto pion_rphi_data_4 = read_in_2Ddata(filename6, dimensions_pion);
	auto proton_z_data_4 = read_in_2Ddata(filename7, dimensions_proton);
	auto pion_z_data_4 = read_in_2Ddata(filename8, dimensions_pion);

	TH1F *hProtonRPHI_4 = new TH1F("hProtonRPHI_4", "", 39, xlowAnalytic, xupAnalyticProton);
	hProtonRPHI_4->SetMarkerColor(kBlue+1); 
	hProtonRPHI_4->SetLineColor(kBlue+1);
	hProtonRPHI_4->SetMarkerStyle(20);
	hProtonRPHI_4->SetLineWidth(2);
	TH1F *hPionRPHI_4 = new TH1F("hPionRPHI_4", "", 45, xlowAnalytic, xupAnalyticPion);
	hPionRPHI_4->SetMarkerColor(kBlue+1); 
	hPionRPHI_4->SetLineColor(kBlue+1);
	hPionRPHI_4->SetMarkerStyle(20);
	hPionRPHI_4->SetLineWidth(2);

	for (int j=0; j < 39; j++){
		if (xyresi){hProtonRPHI_4->SetBinContent(j+1, proton_rphi_data_4[0][j]*mtomum);}
		if (zresi){hProtonRPHI_4->SetBinContent(j+1, proton_z_data_4[0][j]*mtomum);}
	}

	for (int j=0; j < 45; j++){
		if (xyresi){hPionRPHI_4->SetBinContent(j+1, pion_rphi_data_4[0][j]*mtomum);}
		if (zresi){hPionRPHI_4->SetBinContent(j+1, pion_z_data_4[0][j]*mtomum);}
	}


	
	TLatex latexT[2];

	for (int i = 0; i < 2; i++){
		latexT[i].SetTextSize(0.035);
		latexT[i].SetTextFont(text_font);
	}

	TH1F* h_dummyblue = new TH1F("h_dummyblue", "", 1, 0, 1);
    h_dummyblue->SetFillColor(kBlue+1);  // Set fill color to blue
    h_dummyblue->SetLineColor(kBlue+1);  // Optional: for border color
    h_dummyblue->SetMarkerStyle(0);    // No marker

	TH1F* h_dummygreen = new TH1F("h_dummygreen", "", 1, 0, 1);
	h_dummygreen->SetFillColor(kGreen+1);  // Set fill color to green
	h_dummygreen->SetLineColor(kGreen+1);  // Optional: for border color
	h_dummygreen->SetMarkerStyle(0);    // No marker

	canvas2D[0]->cd();
	hProtonRPHI->Draw("P SAMES");
	hProtonRPHI_4->Draw("P SAMES");
	latexT[0].DrawLatexNDC(0.40, 0.84, "extrapolation distance = 1cm");
	latexT[0].DrawLatexNDC(0.40, 0.80, "#theta = 90^{#circ}");
	latexT[0].DrawLatexNDC(0.60, 0.72, "Protons");
	latexT[0].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");

	TLegend *leg1 = new TLegend(0.3, 0.45, 0.8, 0.65, "", "brNDC");
	leg1->AddEntry(hProtonRPHI, "7 hits");
	leg1->AddEntry(hProtonRPHI_4, "4 hits");
	leg1->AddEntry(h_dummygreen, "7 hits with 0.5 < r_{#Lambda} < 2.5 cm", "F");
	leg1->AddEntry(h_dummyblue, "4 hits with 17.2 < r_{#Lambda} < 19.2 cm", "F");
	leg1->Draw();


	canvas2D[1]->cd();
	hPionRPHI->Draw("P SAMES");
	hPionRPHI_4->Draw("P SAMES");
	latexT[1].DrawLatexNDC(0.40, 0.84, "extrapolation distance = 1cm");
	latexT[1].DrawLatexNDC(0.40, 0.80, "#theta = 90^{#circ}");
	latexT[1].DrawLatexNDC(0.60, 0.72, "Pions");
	latexT[1].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");

	TLegend *leg2 = new TLegend(0.3, 0.45, 0.8, 0.65, "", "brNDC");
	leg2->AddEntry(hPionRPHI, "7 hits");
	leg2->AddEntry(hPionRPHI_4, "4 hits");
	leg2->AddEntry(h_dummygreen, "7 hits with 0.5 < r_{#Lambda} < 2.5 cm", "F");
	leg2->AddEntry(h_dummyblue, "4 hits with 17.2 < r_{#Lambda} < 19.2 cm", "F");
	leg2->Draw();


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "png";

	if (zresi){
	canvas2D[0]->SaveAs(Form("%s/ZErrProton7.%s", directory, format));
	canvas2D[1]->SaveAs(Form("%s/ZErrPion7.%s", directory, format));
	}

	if (xyresi){
	canvas2D[0]->SaveAs(Form("%s/XYErrProton7.%s", directory, format));
	canvas2D[1]->SaveAs(Form("%s/XYErrPion7.%s", directory, format));
	}

}