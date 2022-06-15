#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <math.h>
#include "RooFormulaVar.h"
#include "RooRealVar.h"
 #include "RooDataSet.h"
 #include "RooGaussian.h"
 #include "RooConstVar.h"
 #include "RooChebychev.h"
 #include "RooAddPdf.h"
 #include "RooSimultaneous.h"
 #include "RooCategory.h"
 #include "TCanvas.h"
 #include "TAxis.h"
 #include "RooPlot.h"
#include<fstream>
#include <string>
using namespace RooFit;
const int DIM = 5; // number of H masses
const int DIM1 = 4; // number of H decay modes
const int DIM2 = 6; // number of H decay modes
float LUM=59000;

void sigTH1(TFile* f1, float S1,TFile* f2, float S2,TFile* f3, float S3,TFile* f4, float S4, TFile* f5, float S5,TH1F *hist[DIM1][DIM]) {
  TH1F* h_num_eventi;
  float num_event;
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  auto T1 = (TTree*)f1->Get("passedEvents");
  float lum = LUM;

  // 4 mu
  T1->Draw("mass4l >> h01(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist1 = (TH1F*)gDirectory->Get("h01");
  hist1->Scale(S1*lum/num_event);
  hist1->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist1->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f2->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  auto T2 = (TTree*)f2->Get("passedEvents");
  T2->Draw("mass4l >> h02(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist2 = (TH1F*)gDirectory->Get("h02");
  hist2->Scale(S2*lum/num_event);
  hist2->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f3->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  auto T3 = (TTree*)f3->Get("passedEvents");
  T3->Draw("mass4l >> h03(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist3 = (TH1F*)gDirectory->Get("h03");
  hist3->Scale(S3*lum/num_event);
  hist3->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist3->GetYaxis()->SetTitle("Events");
  ///
  h_num_eventi = (TH1F*) f4->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  auto T4 = (TTree*)f4->Get("passedEvents");
  T4->Draw("mass4l >> h04(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist4 = (TH1F*)gDirectory->Get("h04");
  hist4->Scale(S4*lum/num_event);
  hist4->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist4->GetYaxis()->SetTitle("Events");
  h_num_eventi = (TH1F*) f5->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  auto T5 = (TTree*)f5->Get("passedEvents");
  T5->Draw("mass4l >> h05(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist5 = (TH1F*)gDirectory->Get("h05");
  hist5->Scale(S5*lum/num_event);
  hist5->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist5->GetYaxis()->SetTitle("Events");
  hist[0][1]= hist2;
  hist[0][2]= hist3;
  hist[0][3]= hist4;
  hist[0][4]= hist5;

  // 4 e
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T1->Draw("mass4l >> h11(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  hist1 = (TH1F*)gDirectory->Get("h11");
  hist1->Scale(S1*lum/num_event);
  hist1->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist1->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f2->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T2->Draw("mass4l >> h12(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  hist2 = (TH1F*)gDirectory->Get("h12");
  hist2->Scale(S2*lum/num_event);
  hist2->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f3->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T3->Draw("mass4l >> h13(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  hist3 = (TH1F*)gDirectory->Get("h13");
  hist3->Scale(S3*lum/num_event);
  hist3->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist3->GetYaxis()->SetTitle("Events");
  ///
  h_num_eventi = (TH1F*) f4->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T4->Draw("mass4l >> h14(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  hist4 = (TH1F*)gDirectory->Get("h14");
  hist4->Scale(S4*lum/num_event);
  hist4->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist4->GetYaxis()->SetTitle("Events");
  h_num_eventi = (TH1F*) f5->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T5->Draw("mass4l >> h15(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  hist5 = (TH1F*)gDirectory->Get("h15");
  hist5->Scale(S5*lum/num_event);
  hist5->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist5->GetYaxis()->SetTitle("Events");


  hist[1][0]= hist1;
  hist[1][1]= hist2;
  hist[1][2]= hist3;
  hist[1][3]= hist4;
  hist[1][4]= hist5;

  // 2e2mu
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T1->Draw("mass4l >> h21(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  hist1 = (TH1F*)gDirectory->Get("h21");
  hist1->Scale(S1*lum/num_event);
  hist1->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist1->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f2->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T2->Draw("mass4l >> h22(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  hist2 = (TH1F*)gDirectory->Get("h22");
  hist2->Scale(S2*lum/num_event);
  hist2->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f3->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T3->Draw("mass4l >> h23(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  hist3 = (TH1F*)gDirectory->Get("h23");
  hist3->Scale(S3*lum/num_event);
  hist3->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist3->GetYaxis()->SetTitle("Events");
  ///
  h_num_eventi = (TH1F*) f4->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T4->Draw("mass4l >> h24(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  hist4 = (TH1F*)gDirectory->Get("h24");
  hist4->Scale(S4*lum/num_event);
  hist4->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist4->GetYaxis()->SetTitle("Events");
  h_num_eventi = (TH1F*) f5->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T5->Draw("mass4l >> h25(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  hist5 = (TH1F*)gDirectory->Get("h25");
  hist5->Scale(S5*lum/num_event);
  hist5->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist5->GetYaxis()->SetTitle("Events");


  hist[2][0]= hist1;
  hist[2][1]= hist2;
  hist[2][2]= hist3;
  hist[2][3]= hist4;
  hist[2][4]= hist5;


 // 2mu2e
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T1->Draw("mass4l >> h31(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  hist1 = (TH1F*)gDirectory->Get("h31");
  hist1->Scale(S1*lum/num_event);
  hist1->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist1->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f2->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T2->Draw("mass4l >> h32(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  hist2 = (TH1F*)gDirectory->Get("h32");
  hist2->Scale(S2*lum/num_event);
  hist2->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  ////
  h_num_eventi = (TH1F*) f3->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T3->Draw("mass4l >> h33(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  hist3 = (TH1F*)gDirectory->Get("h33");
  hist3->Scale(S3*lum/num_event);
  hist3->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist3->GetYaxis()->SetTitle("Events");
  ///
  h_num_eventi = (TH1F*) f4->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T4->Draw("mass4l >> h34(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  hist4 = (TH1F*)gDirectory->Get("h34");
  hist4->Scale(S4*lum/num_event);
  hist4->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist4->GetYaxis()->SetTitle("Events");
  h_num_eventi = (TH1F*) f5->Get("sumWeights");
  num_event = h_num_eventi->Integral();
  T5->Draw("mass4l >> h35(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  hist5 = (TH1F*)gDirectory->Get("h35");
  hist5->Scale(S5*lum/num_event);
  hist5->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist5->GetYaxis()->SetTitle("Events");


  hist[3][0]= hist1;
  hist[3][1]= hist2;
  hist[3][2]= hist3;
  hist[3][3]= hist4;
  hist[3][4]= hist5;
}


void Fun(){
  gSystem->Load("/afs/cern.ch/user/d/dtroiano/CMSDAS2020/CMSSW_10_6_8/lib/slc7_amd64_gcc700/libHiggsAnalysisCombinedLimit.so");

  TFile* f1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/GluGluHToZZTo4L_M120_2018_skimmed.root","read");
  float s1 =  0.008663298;
  TFile* f2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/GluGluHToZZTo4L_M124_2018_skimmed.root","read");
  float s2 =  0.012327354;
  TFile* f3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/GluGluHToZZTo4L_M125_2018_skimmed.root","read");
  float s3 =  0.01333521;
  TFile* f4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/GluGluHToZZTo4L_M126_2018_skimmed.root","read");
  float s4 =  0.014371789;
  TFile* f5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/GluGluHToZZTo4L_M130_2018_skimmed.root","read");
  float s5 =  0.01333521;
  TH1F *sig_ggH[DIM1][DIM];
  sigTH1( f1,s1,f2,s2,f3,s3,f4,s4,f5,s5,sig_ggH);

  TFile* f1_1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/VBF_HToZZTo4L_M120_2018_skimmed.root","read");
  float s1_1 =  0.0006528165;
  TFile* f2_1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/VBF_HToZZTo4L_M124_2018_skimmed.root","read");
  float s2_1 = 0.0009537624;
  TFile* f3_1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/VBF_HToZZTo4L_M125_2018_skimmed.root","read");
  float s3_1 =  0.001038159;
  TFile* f4_1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/VBF_HToZZTo4L_M126_2018_skimmed.root","read");
  float s4_1 =  0.0011259752;
  TFile* f5_1 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/VBF_HToZZTo4L_M130_2018_skimmed.root","read");
  float s5_1 =  0.00138718988;
  TH1F *sig_VBF[DIM1][DIM];
  sigTH1( f1_1,s1_1,f2_1,s2_1,f3_1,s3_1,f4_1,s4_1,f5_1,s5_1,sig_VBF);
  TFile* f1_2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WplusH_HToZZTo4L_M120_2018_skimmed.root","read");
  float s1_2 =  0.00015860;
  TFile* f2_2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WplusH_HToZZTo4L_M124_2018_skimmed.root","read");
  float s2_2 = 0.0002154715;
  TFile* f3_2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WplusH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s3_2 =  0.0002305562;
  TFile* f4_2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WplusH_HToZZTo4L_M126_2018_skimmed.root","read");
  float s4_2 =  0.0002456155435;
  TFile* f5_2 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WplusH_HToZZTo4L_M130_2018_skimmed.root","read");
  float s5_2 =  0.000305724;
  TH1F *sig_WpH[DIM1][DIM];
  sigTH1( f1_2,s1_2,f2_2,s2_2,f3_2,s3_2,f4_2,s4_2,f5_2,s5_2,sig_WpH);

  TFile* f1_3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WminusH_HToZZTo4L_M120_2018_skimmed.root","read");
  float s1_3 =  0.000101067;
  TFile* f2_3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WminusH_HToZZTo4L_M124_2018_skimmed.root","read");
  float s2_3 = 0.000136724;
  TFile* f3_3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WminusH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s3_3 =  0.000146235;
  TFile* f4_3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WminusH_HToZZTo4L_M126_2018_skimmed.root","read");
  float s4_3 =  0.0001556698761;
  TFile* f5_3 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/WminusH_HToZZTo4L_M130_2018_skimmed.root","read");
  float s5_3 =  0.00019283;
  TH1F *sig_WmH[DIM1][DIM];
  sigTH1( f1_3,s1_3,f2_3,s2_3,f3_3,s3_3,f4_3,s4_3,f5_3,s5_3,sig_WmH);

  TFile* f1_4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ZH_HToZZ_4LFilter_M120_2018_skimmed.root","read");
  float s1_4 =  0.0004475133065;
  TFile* f2_4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ZH_HToZZ_4LFilter_M124_2018_skimmed.root","read");
  float s2_4 = 0.00061534;
  TFile* f3_4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ZH_HToZZ_4LFilter_M125_2018_skimmed.root","read");
  float s3_4 =  0.000662058;
  TFile* f4_4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ZH_HToZZ_4LFilter_M126_2018_skimmed.root","read");
  float s4_4 =  0.0007081419478;
  TFile* f5_4 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ZH_HToZZ_4LFilter_M130_2018_skimmed.root","read");
  float s5_4 =  0.00089169;
  TH1F *sig_ZH[DIM1][DIM];
  sigTH1( f1_4,s1_4,f2_4,s2_4,f3_4,s3_4,f4_4,s4_4,f5_4,s5_4,sig_ZH);

  TFile* f1_5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ttH_HToZZ_4LFilter_M120_2018_skimmed.root","read");
  float s1_5 =  0.0002624871906;
  TFile* f2_5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ttH_HToZZ_4LFilter_M124_2018_skimmed.root","read");
  float s2_5 = 0.0003628096931;
  TFile* f3_5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ttH_HToZZ_4LFilter_M125_2018_skimmed.root","read");
  float s3_5 =  0.0003901903;
  TFile* f4_5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ttH_HToZZ_4LFilter_M126_2018_skimmed.root","read");
  float s4_5 =  0.0004184164042;
  TFile* f5_5 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/ttH_HToZZ_4LFilter_M130_2018_skimmed.root","read");
  float s5_5 = 0.0005285016991;
  TH1F *sig_ttH[DIM1][DIM];
  sigTH1( f1_5,s1_5,f2_5,s2_5,f3_5,s3_5,f4_5,s4_5,f5_5,s5_5,sig_ttH);

  TFile* f1_6 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/bbH_HToZZTo4L_M120_2018_skimmed.root","read");
  float s1_6 =  0.0001527384;
  TFile* f2_6 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/bbH_HToZZTo4L_M124_2018_skimmed.root","read");
  float s2_6 = 0.0001379724;
  TFile* f3_6 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/bbH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s3_6 =  0.000134688;
  TFile* f4_6 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/bbH_HToZZTo4L_M126_2018_skimmed.root","read");
  float s4_6 =  0.000131376;
  TFile* f5_6 = TFile::Open("/eos/cms/store/group/phys_higgs/cmshzz4l/xBF/Run2/UL/MC/2018/bbH_HToZZTo4L_M130_2018_skimmed.root","read");
  float s5_6 = 0.0001187904;
  TH1F *sig_bbH[DIM1][DIM];
  sigTH1( f1_6,s1_6,f2_6,s2_6,f3_6,s3_6,f4_6,s4_6,f5_6,s5_6,sig_bbH);

  THStack *SIG_WH[DIM1][DIM];
  TH1F *sig_WH[DIM1][DIM];
  for(int j=0; j<DIM1; j++){
    for(int i=0; i<DIM; i++){
    SIG_WH[j][i]= new THStack;
    sig_WH[j][i]= new TH1F;
    SIG_WH[j][i]->Add(sig_WpH[j][i]);
    SIG_WH[j][i]->Add(sig_WmH[j][i]);
    sig_WH[j][i]= (TH1F*)SIG_WH[j][i]->GetStack()->Last();}}

  TH1F *sig_list[DIM2][DIM1][DIM];
  for(int j=0; j<DIM1; j++){
    for(int i=0; i<DIM; i++){
      sig_list[0][j][i]= sig_ggH[j][i];
      sig_list[1][j][i]= sig_VBF[j][i];
      sig_list[2][j][i]= sig_WH[j][i];
      sig_list[3][j][i]= sig_ZH[j][i];
      sig_list[4][j][i]= sig_ttH[j][i];
      sig_list[5][j][i]= sig_bbH[j][i];  }}

  /// FIT with Roofit

//TCanvas *myC[DIM2][DIM1];



  std::vector<TString> massPointName;
  massPointName.push_back("120");
  massPointName.push_back("124");
  massPointName.push_back("125");
  massPointName.push_back("126");
  massPointName.push_back("130");

  std::vector<Float_t> massPoint;
  massPoint.push_back(120);
  massPoint.push_back(124);
  massPoint.push_back(125);
  massPoint.push_back(126);
  massPoint.push_back(130);

  std::vector<TString> sourceName;
  sourceName.push_back("signal ggH");
  sourceName.push_back("signal VBF");
  sourceName.push_back("signal WH");
  sourceName.push_back("signal ZH");
  sourceName.push_back("signal ttH");
  sourceName.push_back("signal bbH");

  std::vector<TString> decayName;
  decayName.push_back("4mu");
  decayName.push_back("4e");
  decayName.push_back("2e2mu");
  decayName.push_back("2mu2e");


  ofstream f;
    f.open ("results.txt");
    //TFile f("./results.txt","recreate");

  Double_t xMin = 105;
  Double_t xMax = 140;
for(int s = 0; s <  DIM2; s++){
    f << sourceName.at(s) << "\n";
  for(int d = 0; d <  DIM1; d++){
    f << decayName.at(d) << "\n";
    cout<<"###########        "<<d<<"     ###########"<<endl;

     // VARIABLES
  std::vector<RooDoubleCB> DSCB;
  std::vector<RooFormulaVar> mean;
  std::vector<RooFormulaVar> sigma;
  std::vector<RooFormulaVar> alphaL;
  std::vector<RooFormulaVar> expL;
  std::vector<RooFormulaVar> alphaR;
  std::vector<RooFormulaVar> expR;
  std::vector<RooRealVar> massPointFit;
  std::vector<TString> cat_name;


  std::string nomestringa1;

  if(d==0){ nomestringa1 = "m(4#mu) (GeV)";}
  if(d==1){nomestringa1 = "m(4e) (GeV)" ;}
  if(d==2){nomestringa1 = "m(2e2#mu) (GeV)";}
  if(d==3){nomestringa1 = "m(2#mu2e) (GeV)";}
  const char * nome1{nomestringa1.c_str()};
  RooRealVar xVar("xVar", nome1/*"m(4#mu) (GeV)"*/, xMin, xMax);
  // parameters of the double side Crystall Balls
  RooRealVar DSCB_mean_p0("mean_p0", "mean_p0", 125, 115, 135);
  RooRealVar DSCB_sigma_p0("sigma_p0", "sigma_p0", 1, 0.1, 10);
  RooRealVar DSCB_alphaL_p0("alphaL_p0", "alphaL_p0", 1, 0.1, 30);
  RooRealVar DSCB_expL_p0("expL_p0", "expL_p0", 1, 0.1, 30);
  RooRealVar DSCB_alphaR_p0("alphaR_p0", "alphaR_p0", 1, 0.1, 30);
  RooRealVar DSCB_expR_p0("expR_p0", "expR_p0", 1, 0.1, 50);
  RooRealVar DSCB_mean_p1("mean_p1", "mean_p1", -2, 2);
  RooRealVar DSCB_sigma_p1("sigma_p1", "sigma_p1", -0.25, 0.25);
  RooRealVar DSCB_alphaL_p1("alphaL_p1", "alphaL_p1", -0.25, 0.25);
  RooRealVar DSCB_expL_p1("expL_p1", "expL_p1", -0.25, 0.25);
  RooRealVar DSCB_alphaR_p1("alphaR_p1", "alphaR_p1", -0.25, 0.25);
  RooRealVar DSCB_expR_p1("expR_p1", "expR_p1", -0.25, 0.25);
for(int mP = 0; mP <  massPointName.size(); mP++){
     cat_name.push_back("M" + massPointName.at(mP));
     massPointFit.push_back(RooRealVar("massPointFit_" + massPointName.at(mP), "massPointFit_" + massPointName.at(mP), massPoint.at(mP)));}
  for(int mP = 0; mP <  massPointName.size(); mP++){
   mean.push_back(RooFormulaVar("mean_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_mean_p0, DSCB_mean_p1, massPointFit.at(mP))));
   sigma.push_back(RooFormulaVar("sigma_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_sigma_p0, DSCB_sigma_p1, massPointFit.at(mP))));
   alphaL.push_back(RooFormulaVar("alphaL_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_alphaL_p0, DSCB_alphaL_p1, massPointFit.at(mP))));
   expL.push_back(RooFormulaVar("expL_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_expL_p0, DSCB_expL_p1, massPointFit.at(mP))));
   alphaR.push_back(RooFormulaVar("alphaR_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_alphaR_p0, DSCB_alphaR_p1, massPointFit.at(mP))));
   expR.push_back(RooFormulaVar("expR_" + massPointName.at(mP), "@0 + @1 * (@2 - 125)", RooArgList(DSCB_expR_p0, DSCB_expR_p1, massPointFit.at(mP))));
 }
 // Double Side Crystall Balls
 for(int mP = 0; mP <  massPoint.size(); mP++){
   DSCB.push_back(RooDoubleCB("DSCB_" + massPointName.at(mP), "DSCB_" + massPointName.at(mP), xVar, mean.at(mP), sigma.at(mP), alphaL.at(mP), expL.at(mP), alphaR.at(mP), expR.at(mP)));
 }
 // FIT PROCEDURE
 RooCategory rc_signals = RooCategory("signals","signals");
 for(int mP = 0; mP <  massPoint.size(); mP++){
   rc_signals.defineType(cat_name.at(mP));
 }

 std::vector<RooDataHist> h_Higgs;

 RooSimultaneous sim_pdf("sim_pdf", "Simultaneous pdf", rc_signals);
for(int mP = 0; mP <  massPoint.size(); mP++){
  sim_pdf.addPdf(DSCB.at(mP), cat_name.at(mP));
  h_Higgs.push_back(RooDataHist("h_HiggsMass_" + massPointName.at(mP), "h_HiggsMass_" + massPointName.at(mP), RooArgSet(xVar), sig_list[s][d][mP]/*sig_ggH[d][mP]*/));
 }
RooDataHist rds_all_signals("combData","combined data", RooArgSet(xVar),Index(rc_signals),
                                        Import(cat_name.at(0), h_Higgs.at(0)),
                                        Import(cat_name.at(1), h_Higgs.at(1)),
                                        Import(cat_name.at(2), h_Higgs.at(2)),
                                        Import(cat_name.at(3), h_Higgs.at(3)),
                             Import(cat_name.at(4), h_Higgs.at(4)));

 DSCB_mean_p1.setConstant();
 DSCB_sigma_p1.setConstant();
 DSCB_alphaL_p1.setConstant();
 DSCB_expL_p1.setConstant();
 DSCB_alphaR_p1.setConstant();
 DSCB_expR_p1.setConstant();

 RooFitResult* r_125;
 r_125 = DSCB.at(2).fitTo(h_Higgs.at(2), Save(kTRUE), SumW2Error(kTRUE), Verbose(kFALSE), PrintLevel(-1), Warnings(kFALSE), NumCPU(12), Timer(kTRUE));
 r_125->Print();

 DSCB_mean_p0.setConstant();
 DSCB_sigma_p0.setConstant();
 DSCB_alphaL_p0.setConstant();
 DSCB_expL_p0.setConstant();
 DSCB_alphaR_p0.setConstant();
 DSCB_expR_p0.setConstant();
 f << "mean_p0     "<< DSCB_mean_p0.getVal()<< " +/- "<< DSCB_mean_p0.getError()<<"\n";
 f << "sigma_p0    "<< DSCB_sigma_p0.getVal()<<" +/- "<< DSCB_sigma_p0.getError()<< "\n";
 f << "alphaL_p0   "<< DSCB_alphaL_p0.getVal()<<" +/- "<< DSCB_alphaL_p0.getError()<< "\n";
 f << "expL_p0     "<< DSCB_expL_p0.getVal()<< " +/- "<< DSCB_expL_p0.getError()<<"\n";
 f << "alphaR_p0   "<< DSCB_alphaR_p0.getVal()<< " +/- "<< DSCB_alphaR_p0.getError()<<"\n";
   DSCB_mean_p1.setConstant(kFALSE);
 DSCB_sigma_p1.setConstant(kFALSE);
 DSCB_alphaL_p1.setConstant(kFALSE);
 DSCB_expL_p1.setConstant(kFALSE);
 DSCB_alphaR_p1.setConstant(kFALSE);
 DSCB_expR_p1.setConstant(kFALSE);

 RooFitResult* r_all;
 r_all = sim_pdf.fitTo(rds_all_signals, Save(kTRUE), SumW2Error(kTRUE), Verbose(kFALSE), PrintLevel(-1), Warnings(kFALSE), NumCPU(12), Timer(kTRUE));
   r_all->Print();
 f << "mean_p1     "<< DSCB_mean_p1.getVal()<< " +/- "<< DSCB_mean_p1.getError()<<"\n";
 f << "sigma_p1    "<< DSCB_sigma_p1.getVal()<<" +/- "<< DSCB_sigma_p1.getError()<< "\n";
 f << "alphaL_p1   "<< DSCB_alphaL_p1.getVal()<<" +/- "<< DSCB_alphaL_p1.getError()<< "\n";
 f << "expL_p1     "<< DSCB_expL_p1.getVal()<< " +/- "<< DSCB_expL_p1.getError()<<"\n";
 f << "alphaR_p1   "<< DSCB_alphaR_p1.getVal()<< " +/- "<< DSCB_alphaR_p1.getError()<<"\n";
 f << "expR_p1     "<< DSCB_expR_p1.getVal()<< " +/- "<< DSCB_alphaR_p1.getError()<<"\n";

 //PLOT
  std::string nomestringa{std::to_string(s)+std::to_string(d)};
  const char * nome{nomestringa.c_str()};
  //myC[s][d] = new TCanvas(nome/*"myC"*/,"Plot1", 1200,800);
  //myC[s][d]->Divide(2,3);
  //myC[s][d]->cd(1);
 int color_shift=0;
 //for(int mP = 0; mP <  massPoint.size(); mP++){
 //myC[s][d]->cd(mP+2);
 //TString title = sourceName.at(s) + "   " + massPointName.at(mP);
 //RooPlot* xframe = xVar.frame(Title(title/*cat_name.at(mP)*/));
 //TString cut = Form("signals==signals::%s", cat_name[mP].Data());
 //rds_all_signals.plotOn(xframe, LineColor(kPink+color_shift),Cut(cut));
 //sim_pdf.plotOn(xframe,Slice(rc_signals, cat_name.at(mP)),ProjWData(RooArgSet(rc_signals), rds_all_signals),LineColor(kPink+color_shift));          //sim_pdf.paramOn(xframe, RooFit::Layout(0.13, 0.5, 0.9),Slice(rc_signals, cat_name.at(mP)),ProjWData(RooArgSet(rc_signals), rds_all_signals),LineColor(kPink+color_shift));
 //xframe->Draw();
 //color_shift = color_shift +1;}
   /*if(mP == 0){
     TString fit_param_latex = Form("#chi^{2}/dof = %.3f", xframe->chiSquare(r_all->floatParsFinal().getSize())/ r_all->floatParsFinal().getSize());
     TLatex *tex1;
      tex1 = new TLatex(0.65,0.85, fit_param_latex);
     tex1->SetNDC();
     tex1->Draw();}*/
  }//close the for on the decay channels
    }//close the for on the sources
  //myfile.close();
 f.close();
}// cloe the main
