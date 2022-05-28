#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <math.h>
using namespace RooFit;
int DIM = 5;
float LUM=59000;
  
Double_t DoubleSidedCB2(double x, double mu, double width, double a1, double p1, double a2, double p2)
{
  double u   = (x-mu)/width;
  double A1  = TMath::Power(p1/TMath::Abs(a1),p1)*TMath::Exp(-a1*a1/2);
  double A2  = TMath::Power(p2/TMath::Abs(a2),p2)*TMath::Exp(-a2*a2/2);
  double B1  = p1/TMath::Abs(a1) - TMath::Abs(a1);
  double B2  = p2/TMath::Abs(a2) - TMath::Abs(a2);

  double result(1);
  if      (u<-a1) result *= A1*TMath::Power(B1-u,-p1);
  else if (u<a2)  result *= TMath::Exp(-u*u/2);
  else            result *= A2*TMath::Power(B2+u,-p2);
  return result;
}


double DoubleSidedCB(double* x, double *par)
{
  return(par[0] * DoubleSidedCB2(x[0], par[1],par[2],par[3],par[4],par[5],par[6]));
}





void sigTH1(TFile* f1, float S, TH1F  *hist[DIM]) { 
  TH1F* h_num_eventi;
  float num_event;
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();  
  cout<<"file  "<<f1<<endl;
  cout<<"numero eventi  "<<num_event<<endl;
  auto T = (TTree*)f1->Get("passedEvents");
  float lum = LUM;   
  T->Draw("mass4l >> h01(3500, 105, 140)", "mass4l >105 && mass4l<140 ","goff");
  TH1F *hist1 = (TH1F*)gDirectory->Get("h01");
  hist1->Scale(S*lum/num_event);  
  hist1->GetXaxis()->SetTitle("m(4l) (GeV)");
  hist1->GetYaxis()->SetTitle("Events");
  T->Draw("mass4l >> h02(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==1","goff");
  TH1F *hist2 = (TH1F*)gDirectory->Get("h02");
  hist2->Scale(S*lum/num_event);  
  hist2->GetXaxis()->SetTitle("m(4mu) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  T->Draw("mass4l >> h03(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==2","goff");
  TH1F *hist3 = (TH1F*)gDirectory->Get("h03");
  hist3->Scale(S*lum/num_event);  
  hist3->GetXaxis()->SetTitle("m(4e) (GeV)");
  hist3->GetYaxis()->SetTitle("Events");
  T->Draw("mass4l >> h04(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==3","goff");
  TH1F *hist4 = (TH1F*)gDirectory->Get("h04");
  hist4->Scale(S*lum/num_event);  
  hist4->GetXaxis()->SetTitle("m(2e2mu) (GeV)");
  hist4->GetYaxis()->SetTitle("Events");
  T->Draw("mass4l >> h05(3500, 105, 140)", "mass4l >105 && mass4l<140 && finalState==4","goff");
  TH1F *hist5 = (TH1F*)gDirectory->Get("h05");
  hist5->Scale(S*lum/num_event);  
  hist5->GetXaxis()->SetTitle("m(2mu2e) (GeV)");
  hist5->GetYaxis()->SetTitle("Events");
  hist[0]= hist1;
  hist[1]= hist2;
  hist[2]= hist3;
  hist[3]= hist4;
  hist[4]= hist5;
}

void bkgTH1(TFile* f1, float S, TH1F  *hist[DIM]) { 
  TH1F* h_num_eventi;
  float num_event; 
  h_num_eventi = (TH1F*) f1->Get("sumWeights");
  num_event = h_num_eventi->Integral();  
  cout<<"file  "<<f1<<endl;
  cout<<"numero eventi  "<<num_event<<endl;
  float lum = LUM;
  auto T = (TTree*)f1->Get("passedEvents");     
  T->Draw("mass4l >> h01(35, 105, 140)", "mass4l >105 && mass4l<140","goff");
  TH1F *hist2 = (TH1F*)gDirectory->Get("h01");
  cout<<hist2->GetEntries()<<endl;
  cout<<hist2->Integral()<<endl;
  hist2->Scale(S*lum/num_event);
  cout<<hist2->Integral()<<endl;
  hist2->SetFillColor(4);
  hist2->SetLineColor(4);
  hist2->SetFillStyle(3335);
  hist2->GetXaxis()->SetTitle("m(4l) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  hist[0]= hist2;
}



void Masses(){ 
  gSystem->Load("/afs/cern.ch/user/d/dtroiano/CMSDAS2020/CMSSW_10_6_8/lib/slc7_amd64_gcc700/libHiggsAnalysisCombinedLimit.so");
  gStyle->SetOptStat(0000);      
  TFile* f1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluHToZZTo4L_M125_2018_skimmed.root","read");
  float s1 =  0.01333521;
  TH1F  *sig_ggH[DIM];
  sigTH1( f1,s1,sig_ggH);
  TFile* f2 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/VBF_HToZZTo4L_M125_2018_skimmed.root","read");
  float s2 = 0.001038159; 
  TH1F *sig_VBF[DIM];
  sigTH1( f2,s2,sig_VBF);
  TFile* f3 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/WplusH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s3 = 0.0002305562; 
  TH1F *sig_WpH[DIM];
  sigTH1( f3,s3,sig_WpH);
  TFile* f4 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/WminusH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s4 = 0.000146235; 
  TH1F *sig_WmH[DIM];
  sigTH1( f4,s4,sig_WmH);
  TFile* f5 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/ZH_HToZZ_4LFilter_M125_2018_skimmed.root","read");
  float s5 = 0.000662058; 
  TH1F *sig_ZH[DIM];
  sigTH1( f5,s5,sig_ZH);
  TFile* f6 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/ttH_HToZZ_4LFilter_M125_2018_skimmed.root","read");
  float s6 = 0.0003901903; 
  TH1F *sig_ttH[DIM];
  sigTH1( f6,s6,sig_ttH);
  TFile* f7 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/bbH_HToZZTo4L_M125_2018_skimmed.root","read");
  float s7 = 0.000134688; 
  TH1F *sig_bbH[DIM];
  sigTH1( f7,s7,sig_bbH);
  TFile* f8 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/tHq_HToZZTo4L_M125_2018_skimmed.root","read");
  float s8 = 0.0000857830; 
  TH1F *sig_tHq[DIM];
  sigTH1( f8,s8,sig_tHq);
  ///////////////////////////////////
  //////////// bkg samples
  /*TFile* f1_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/DYJetsToLL_M-50_M125_2018_skimmed.root","read");
  TH1F *bkg_DY[DIM];
  float s1_1 = 6104;
  bkgTH1( f1_1, s1_1, bkg_DY);  
  TFile* f2_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/TTTo2L2Nu_M125_2018_skimmed.root","read");
  TH1F *bkg_tt[DIM];
  float s2_1 = 87.31;
  bkgTH1( f2_1, s2_1, bkg_tt);   
  TFile* f3_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/WZTo3LNu_M125_2018_skimmed.root","read");
  TH1F *bkg_WZ[DIM];
  float s3_1 = 4.430;
  bkgTH1( f3_1, s3_1, bkg_WZ);    
  TFile* f4_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/ZZTo4L_M125_2018_skimmed.root","read");
  TH1F *bkg_ZZ[DIM];
  float s4_1 = 1.212;
  bkgTH1( f4_1, s4_1, bkg_ZZ);
  //bkg_ZZ[0]->Draw();
  TFile* f5_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo2e2mu_M125_2018_skimmed.root","read");
  float s5_1 = 0.00319; 
  TH1F *bkg_2e2mu[DIM];
  bkgTH1( f5_1, s5_1, bkg_2e2mu);
  TFile* f6_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo2e2tau_M125_2018_skimmed.root","read");  
  TH1F *bkg_2e2tau[DIM];
  bkgTH1( f6_1, s5_1, bkg_2e2tau);
  TFile* f7_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo2mu2tau_M125_2018_skimmed.root","read");  
  TH1F *bkg_2mu2tau[DIM];
  bkgTH1( f7_1, s5_1, bkg_2mu2tau);
  TFile* f8_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo4e_M125_2018_skimmed.root","read");
  TH1F *bkg_4e[DIM];
  float s6_1 = 0.00159;
  bkgTH1( f8_1, s6_1, bkg_4e);
  TFile* f9_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo4mu_M125_2018_skimmed.root","read");
  TH1F *bkg_4mu[DIM];
  bkgTH1( f9_1, s6_1, bkg_4mu);
  TFile* f10_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ2/GluGluToContinToZZTo4tau_M125_2018_skimmed.root","read");
  TH1F *bkg_4tau[DIM];
  bkgTH1( f10_1, s6_1, bkg_4tau);*/
 
  
  THStack *SIG_WH[DIM];
  TH1F *sig_WH[DIM];
  int i,j;
  for(i=0; i<DIM; i++){
    SIG_WH[i]= new THStack;
    sig_WH[i]= new TH1F;
    SIG_WH[i]->Add(sig_WpH[i]);
    SIG_WH[i]->Add(sig_WmH[i]); 
    sig_WH[i]= (TH1F*)SIG_WH[i]->GetStack()->Last();}
  
  int nsources =7;
  TH1F *th1_list[nsources][DIM];
  int k;
  for(k=0;k<DIM;k++){//for on the variables
    th1_list[0][k]= sig_ggH[k];
    th1_list[1][k]= sig_VBF[k];
    th1_list[2][k]= sig_WH[k];
    th1_list[3][k]= sig_ZH[k];
    th1_list[4][k]= sig_ttH[k];
    th1_list[5][k]= sig_bbH[k];
    th1_list[6][k]= sig_tHq[k];    
  }//close the for on the variables

  /*
  TCanvas *myC = new TCanvas("myC","Plot 1", 1200,800);
  gStyle->SetOptFit(1);
  for(i=0;i<nsources;i++){
    for(j=0;j<DIM;j++){
      myC->Clear();
      /// fit with a TF1
      TF1 *dcb = new TF1("dcb","DoubleSidedCB",105,140,7);
      dcb->SetLineColor(2);
      double par[7];
      par[0]=200;
      par[1]=124.5;
      par[2]=1.5;
      par[3]=1;
      par[4]=1;
      par[5]=1;
      par[6]=1;
      dcb->SetParameters(&par[0]);
      dcb->SetParName(0,"Constant");
      dcb->SetParName(1,"#mu");
      dcb->SetParName(2,"#sigma");
      dcb->SetParName(3,"#alfa_{1}");
      dcb->SetParName(4,"n_{1}");
      dcb->SetParName(5,"#alfa_{2}");
      dcb->SetParName(6,"n_{2}");
      dcb->SetParLimits(2,0,20);
      if(i==0){th1_list[i][j]->SetTitle("signal gg #rightarrow H");}
      if(i==1){th1_list[i][j]->SetTitle("signal qq #rightarrow Hqq");}
      if(i==2){th1_list[i][j]->SetTitle("signal q#bar{q} #rightarrow WH");}
      if(i==3){th1_list[i][j]->SetTitle("signal q#bar{q} #rightarrow ZH");}
      if(i==4){th1_list[i][j]->SetTitle("signal gg #rightarrow ttH");}
      if(i==5){th1_list[i][j]->SetTitle("signal gg #rightarrow bbH");}
      if(i==6){th1_list[i][j]->SetTitle("signal q#bar{q} /qg #rightarrow tHq");}
      th1_list[i][j]->Fit("dcb");
      th1_list[i][j]->Draw("hist");  
      dcb->SetLineWidth(6);
      dcb->Draw("same");    
      if(i==0 && j==0){myC->Print("./Plots/plots.pdf[");}
      myC->Print("./Plots/plots.pdf");
      if(i== nsources-1 && j== DIM -1){myC->Print("./Plots/plots.pdf]");}
    }}
*/
  TCanvas *myC = new TCanvas("myC","Plot 1", 1200,800);
  gStyle->SetOptFit(1);
  for(i=0;i<nsources;i++){
    for(j=0;j<DIM;j++){
      myC->Clear();
      /// fit with RooFit      
      if(i==0){th1_list[i][j]->SetTitle("signal gg #rightarrow H");}
      if(i==1){th1_list[i][j]->SetTitle("signal qq #rightarrow Hqq");}
      if(i==2){th1_list[i][j]->SetTitle("signal q#bar{q} #rightarrow WH");}
      if(i==3){th1_list[i][j]->SetTitle("signal q#bar{q} #rightarrow ZH");}
      if(i==4){th1_list[i][j]->SetTitle("signal gg #rightarrow ttH");}
      if(i==5){th1_list[i][j]->SetTitle("signal gg #rightarrow bbH");}
      if(i==6){th1_list[i][j]->SetTitle("signal q#bar{q} /qg #rightarrow tHq");}
       /////// RooFit
      Double_t xMin = 105; 
      Double_t xMax = 140;
      Int_t nBins = th1_list[i][j]->GetNbinsX();
      RooRealVar xVar("xVar", "m(4l) (GeV)", xMin, xMax); 
      xVar.setBins(nBins);  
      RooDataHist* Hist = new RooDataHist(th1_list[i][j]->GetName(), th1_list[i][j]->GetTitle(), RooArgSet(xVar), Import(*th1_list[i][j],kFALSE));
  ////////////
      RooRealVar mCB("#mu", "meanCB", 125,124, 126);
      RooRealVar sigmaCB("#sigma_{CB}", "sigma1CB", 1.5, 1, 2.5);
      RooRealVar alpha1("#alpha1","alpha1",1.4, 0.1, 3);
      RooRealVar nSigma1("n1","nSigma1", 2, 0.1, 3);
      RooRealVar alpha2("#alpha2","alpha2",1.4, 0.1, 3);
      RooRealVar nSigma2("n2","nSigma2", 2, 0.1, 3);

 
      RooDoubleCB* sigCBPdf = new RooDoubleCB("sigCBPdf","sigCBPdf",xVar,mCB,sigmaCB,alpha1,nSigma1,alpha2,nSigma2);  
  //RooCrystalBall* sigCBPdf = new RooCrystalBall("sigCBPdf","DoubleSidedCB",xVar,mCB,sigmaCB,alpha1,nSigma1,alpha2,nSigma2);
  //sigCBPdf->fitTo(*Hist, Extended(kTRUE), Minos(kTRUE));
  sigCBPdf->fitTo(*Hist, RooFit::Save(true));
  RooRealVar xVar1("xVar", "m(4l) (GeV)", xMin, xMax);
  th1_list[i][j]->Rebin(100);
  Int_t nBins1 = th1_list[i][j]->GetNbinsX();
  xVar1.setBins(nBins1);  
  RooDataHist* Hist1 = new RooDataHist(th1_list[i][j]->GetName(), th1_list[i][j]->GetTitle(), RooArgSet(xVar1), Import(*th1_list[i][j],kFALSE));
  RooPlot* xframe = xVar.frame(); 
  xframe->SetXTitle(th1_list[i][j]->GetXaxis()->GetTitle());
  xframe->SetYTitle("Events");
  xframe->SetTitle(th1_list[i][j]->GetTitle());
  Hist1->plotOn(xframe);
  sigCBPdf->plotOn(xframe,  LineColor(kRed));
  
  //linea magiga
  sigCBPdf->plotOn(xframe); 
  
  sigCBPdf->paramOn(xframe, Parameters(RooArgSet(mCB,sigmaCB,alpha1,nSigma1,alpha2,nSigma2)), Layout(0.65,0.9,0.9));
  xframe->Draw();  
  if(i==0 && j==0){myC->Print("./Plots/plots.pdf[");}
  myC->Print("./Plots/plots.pdf");
  if(i== nsources-1 && j== DIM -1){myC->Print("./Plots/plots.pdf]");}
    }}


}//close the main
