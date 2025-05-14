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
	float yup2D = 250;
	float xup2D = 4;
	float zup = 10000;
	float labelsize = 0.03;
	float ylabel_offset2D = 1.3;
	float xlabel_offset2D = 1.2;

	const char *xlabel2D = "p_{T}^{MC} [GeV/c]";
	const char *ylabel2D;

	if (zresi){ylabel2D = "#sigma_{z}^{Rec} [#mum]";}
	if (xyresi){ylabel2D = "#sigma_{xy}^{Rec} [#mum]";}

	TH2F *hRecProton2D = new TH2F("hRecProton2D", "", nbins2D, xlow2D, xup2D, nbins2D, ylow2D, yup2D);
	if (zresi){Tree->Draw(Form("%s:%s>>hRecProton2D", zProtonresi, ptProtonMC), isTrueCasc && IUProton_layers && V0RadCutMC, "GOFF");}
	if (xyresi){Tree->Draw(Form("%s:%s>>hRecProton2D", xyProtonresi, ptProtonMC), isTrueCasc && IUProton_layers && V0RadCutMC, "GOFF");}

	float xup2D2 = 1;

	TH2F *hRecPion2D = new TH2F("hRecPion2D", "", nbins2D, xlow2D, xup2D2, nbins2D, ylow2D, yup2D);
	if(zresi){Tree->Draw(Form("%s:%s>>hRecPion2D", zPionresi, ptPionMC), isTrueCasc && IUPion_layers && V0RadCutMC, "GOFF");}
	if(xyresi){Tree->Draw(Form("%s:%s>>hRecPion2D", xyPionresi, ptPionMC), isTrueCasc && IUPion_layers && V0RadCutMC, "GOFF");}


	//-------------------------
  	// Print TH2s for consistency
  	//-------------------------

	int canvasTH2sizeX = 1000;
	int canvasTH2sizeY = 1000;

	float ylabel_offsetTH2 = 1.5;
	float xlabel_offsetTH2 = 1.2;

	TCanvas *canvas2D[2];
	for (int i = 0; i < 2; i++){
		canvas2D[i] = new TCanvas(Form("canvas2D[%i]", i), "", canvasTH2sizeX, canvasTH2sizeY);
		canvas2D[i]->SetTicks();
	}

	canvas2D[0]->cd();
	hRecProton2D->Draw("P COLZ");
	hRecProton2D->GetYaxis()->SetRangeUser(0, 0.025*resclaing_factor);
	hRecProton2D->GetXaxis()->SetTitle(xlabel2D);
	hRecProton2D->GetYaxis()->SetTitle(ylabel2D);
	hRecProton2D->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecProton2D->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);

	canvas2D[1]->cd();
	hRecPion2D->Draw("P COLZ");
	hRecPion2D->GetYaxis()->SetRangeUser(0, 0.025*resclaing_factor);
	hRecPion2D->GetXaxis()->SetTitle(xlabel2D);
	hRecPion2D->GetYaxis()->SetTitle(ylabel2D);
	hRecPion2D->GetYaxis()->SetTitleOffset(ylabel_offsetTH2);
	hRecPion2D->GetXaxis()->SetTitleOffset(xlabel_offsetTH2);


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

	int mtomum = 1000000;

	float xlowAnalytic = 0.1;
	float xupAnalyticProton = 4.0;
	float xupAnalyticPion = 1.0;

	TH1F *hProtonRPHI = new TH1F("hProtonRPHI", "", 39, xlowAnalytic, xupAnalyticProton);
	hProtonRPHI->SetMarkerColor(kRed); 
	hProtonRPHI->SetLineColor(kRed);
	hProtonRPHI->SetMarkerStyle(20);
	hProtonRPHI->SetLineWidth(2);
	TH1F *hPionRPHI = new TH1F("hPionRPHI", "", 45, xlowAnalytic, xupAnalyticPion);
	hPionRPHI->SetMarkerColor(kRed); 
	hPionRPHI->SetLineColor(kRed);
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

	
	TLatex latexT[2];

	for (int i = 0; i < 2; i++){
		latexT[i].SetTextSize(0.035);
		latexT[i].SetTextFont(text_font);
	}

	canvas2D[0]->cd();
	hProtonRPHI->Draw("P SAMES");
	latexT[0].DrawLatexNDC(0.40, 0.84, "extrapolation distance = 1cm");
	latexT[0].DrawLatexNDC(0.40, 0.80, "Protons with 7 hits");
	latexT[0].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");


	canvas2D[1]->cd();
	hPionRPHI->Draw("P SAMES");
	latexT[1].DrawLatexNDC(0.40, 0.84, "extrapolation distance = 1cm");
	latexT[1].DrawLatexNDC(0.40, 0.80, "Pions with 7 hits");
	latexT[1].DrawLatexNDC(0.60, 0.76, "pp #sqrt{s} = 13.6 TeV");


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "png";

	if (xresi){}

	if (yresi){}

	if (zresi){
	canvas2D[0]->SaveAs(Form("%s/ZErrProton7.%s", directory, format));
	canvas2D[1]->SaveAs(Form("%s/ZErrPion7.%s", directory, format));
	}

	if (xyresi){
	canvas2D[0]->SaveAs(Form("%s/XYErrProton7.%s", directory, format));
	canvas2D[1]->SaveAs(Form("%s/XYErrPion7.%s", directory, format));
	}

}