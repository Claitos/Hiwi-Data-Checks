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

	TCut IUProton_layers = "sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2)) < 2.9";
	TCut IUPion_layers = "sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2)) < 2.9";

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

	int nbins = 500;
	float xlow = 0;
	float xup = 5;
	int sweep_range = 0;
	const char *htitle = "Decay radii of #Lambda daughters";
	const char *xlabel = "r_{vertex} [cm]";
	const char *ylabel = "Entries";

	float labelsize = 0.03;
	float ylabel_offset = 1.5;
	float xlabel_offset = 1.2;

	int sweep_index = 2;
	bool plot_with_Lambda = true;


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

	TH1F *hLambda = new TH1F("hLambda", htitle, nbins, xlow, xup);
	hLambda->GetXaxis()->SetTitle(xlabel);
	hLambda->GetYaxis()->SetTitle(ylabel);
	hLambda->GetYaxis()->SetTitleOffset(ylabel_offset);
	hLambda->GetXaxis()->SetTitleOffset(xlabel_offset);
	hLambda->SetMarkerColor(7); 
	hLambda->SetLineColor(7);
	hLambda->SetMarkerStyle(20);
	hLambda->SetLineWidth(2);

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

	const char *IUProton = "sqrt(pow(fXProtonIURec,2) + pow(fYProtonIURec,2))";
	const char *IUPion = "sqrt(pow(fXPionIURec,2) + pow(fYPionIURec,2))";

	Tree->Draw(Form("%s>>hProton", IUProton), isTrueCasc && IUProton_layers, "P E");
	Tree->Draw(Form("%s>>hPion", IUPion), isTrueCasc && IUPion_layers, "P E SAMES");
	if (plot_with_Lambda) {Tree->Draw(Form("%s>>hLambda", "fV0Rad"), isTrueCasc && IUProton_layers && IUPion_layers, "P E SAMES");}	

	hProton->Scale(1/hProton->GetEntries());
	hPion->Scale(1/hPion->GetEntries());
	if (plot_with_Lambda) {hLambda->Scale(1/hLambda->GetEntries());}

	hProton->GetYaxis()->SetRangeUser(0,0.1);

	const char *label_array[3] = {"4.2 < r_{#Lambda} < 9.2 cm", "9.2 < r_{#Lambda} < 14.2 cm", "14.2 < r_{#Lambda} < 19.2 cm"};
	TLatex latexT0;
  	latexT0.SetTextSize(0.035);
	latexT0.SetTextFont(text_font);
  	latexT0.DrawLatexNDC(0.60, 0.80, "pp #sqrt{s} = 13.6 TeV");
	latexT0.DrawLatexNDC(0.60, 0.76, "#Lambda daughters");
	latexT0.DrawLatexNDC(0.60, 0.72, "");
	latexT0.DrawLatexNDC(0.40, 0.68, Form("Total Entries Proton: %.0f", hProton->GetEntries()));
	latexT0.DrawLatexNDC(0.40, 0.64, Form("Total Entries Pion: %.0f", hPion->GetEntries()));
	if (plot_with_Lambda) {latexT0.DrawLatexNDC(0.40, 0.60, Form("Total Entries Lambda: %.0f", hLambda->GetEntries()));}

	TLegend *leg = new TLegend(0.15, 0.7, 0.4, 0.85, "", "brNDC");
	leg->AddEntry(hProton, "Proton");
	leg->AddEntry(hPion, "Pion");
	if (plot_with_Lambda) {leg->AddEntry(hLambda, "Lambda");}
	leg->Draw();


	//-------------------------
  	// I/O
  	//-------------------------

	const char *format = "png";

	canvas->SaveAs(Form("%s/IU.%s", directory, format));




}