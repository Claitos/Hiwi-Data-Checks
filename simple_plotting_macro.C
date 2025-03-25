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


void simple_plotting_macro() {

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
	

	TCut isTrueCasc = "fIsTrueCasc == 1";
	TCut isKF = "fIsKF == 1";
	TCut isDCA = "fIsDCAFitter == 1";
	TCut isKFDCA = "fIsKF == 1 && fIsDCAFitter == 1";
	TCut isKFandTrueCasc = "fIsKF == 1 && fIsTrueCasc == 1";

	TCut V0woMaterialProton[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22",
		"fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22",
		"fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 22"};
	TCut V0woMaterialPion[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22", 
	   "fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22",
	   "fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 22"};


	TCut V0wMaterialProton[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22",
		"fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22",
		"fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) > 22"};
	TCut V0wMaterialPion[3] = {"fV0Rad > 4.2 && fV0Rad < 9.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22", 
	   "fV0Rad > 9.2 && fV0Rad < 14.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22",
	   "fV0Rad > 14.2 && fV0Rad < 19.2 && sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) > 22"};

	TCut V0RadCutMC = "sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) > 4.5 && sqrt(pow(fV0VtxXMC,2) + pow(fV0VtxYMC,2)) < 19.2";
	TCut charge = "fCharge == -1";

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

	//-------------------------
  	// variables
  	//-------------------------

	int nbins = 160;
	float xlow = -2;
	float xup = 2;
	int sweep_range = 0;
	const char *htitle = "Pseudorapidity of #Lambda daughters";
	const char *xlabel = "#eta";
	const char *ylabel = "Entries";

	float labelsize = 0.03;
	float ylabel_offset = 1.5;
	float xlabel_offset = 1.2;

	int sweep_index = 2;


    TH1F *hProton = new TH1F("hProton", htitle, nbins, xlow, xup);
	hProton->GetXaxis()->SetTitle(xlabel);
	hProton->GetYaxis()->SetTitle(ylabel);
	hProton->GetYaxis()->SetTitleOffset(ylabel_offset);
	hProton->GetXaxis()->SetTitleOffset(xlabel_offset);
	hProton->SetMarkerColor(9); 
	hProton->SetLineColor(9);
	hProton->SetMarkerStyle(20);
	hProton->SetLineWidth(2);

    TH1F *hPion = new TH1F("hPion", htitle, nbins, xlow, xup);
	hPion->GetXaxis()->SetTitle(xlabel);
	hPion->GetYaxis()->SetTitle(ylabel);
	hPion->GetYaxis()->SetTitleOffset(ylabel_offset);
	hPion->GetXaxis()->SetTitleOffset(xlabel_offset);
	hPion->SetMarkerColor(8); 
	hPion->SetLineColor(8);
	hPion->SetMarkerStyle(20);
	hPion->SetLineWidth(2);

	//-------------------------
  	// read in data
  	//-------------------------

	int dimensions[3] = {3, 3, 39}; // Dimensions of the 3D array
	const char *filename = "Data/proton_rphi_4hits.txt"; // Name of the file to read from

	auto proton_rphi_data = read_in_3Ddata(filename, dimensions);

	// Example: Print a sample of the data
	cout << "Sample data from (0,0) from function: ";
	for (int k = 0; k < dimensions[2]; ++k) {
		cout << proton_rphi_data[0][2][k] << " ";
	}
	cout << endl;

	//-------------------------
  	// plotting
  	//-------------------------


    TCanvas *canvas = new TCanvas("canvas", "canvas", 1000, 1000);
	// canvas->SetGrid();
	// canvas->SetLogy();
	canvas->SetTicks();

	const char *pProton = "sqrt(pow(fPxProtonIURec,2) + pow(fPyProtonIURec,2) + pow(fPzProtonIURec,2))";
	const char *etaCalcProton = Form("0.5*log((%s + fPzProtonIURec)/(%s - fPzProtonIURec))", pProton, pProton);

	const char *pPion = "sqrt(pow(fPxPionIURec,2) + pow(fPyPionIURec,2) + pow(fPzPionIURec,2))";
	const char *etaCalcPion = Form("0.5*log((%s + fPzPionIURec)/(%s - fPzPionIURec))", pPion, pPion);

	Tree->Draw(Form("%s>>hProton", "fEtaProton"), isTrueCasc && V0woMaterialProton[sweep_index], "P E");
	Tree->Draw(Form("%s>>hPion", "fEtaPion"), isTrueCasc && V0woMaterialPion[sweep_index], "P E SAMES");	

	hProton->Scale(1/hProton->GetEntries());
	hPion->Scale(1/hPion->GetEntries());

	hProton->GetYaxis()->SetRangeUser(0,0.02);

	const char *label_array[3] = {"4.2 < r_{#Lambda} < 9.2 cm", "9.2 < r_{#Lambda} < 14.2 cm", "14.2 < r_{#Lambda} < 19.2 cm"};
	TLatex latexT0;
  	latexT0.SetTextSize(0.035);
	latexT0.SetTextFont(text_font);
  	latexT0.DrawLatexNDC(0.60, 0.80, "pp #sqrt{s} = 13.6 TeV");
	latexT0.DrawLatexNDC(0.60, 0.76, "#Lambda daughters");
	latexT0.DrawLatexNDC(0.60, 0.72, label_array[sweep_index]);
	latexT0.DrawLatexNDC(0.60, 0.68, Form("Total Entries: %.0f", hProton->GetEntries()));

	TLegend *leg = new TLegend(0.15, 0.7, 0.4, 0.85, "", "brNDC");
	leg->AddEntry(hProton, "Proton");
	leg->AddEntry(hPion, "Pion");
	leg->Draw();


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "pdf";

	canvas->SaveAs(Form("%s/Eta.%s", directory, format));




}