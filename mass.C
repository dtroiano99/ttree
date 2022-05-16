#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <math.h>
using namespace RooFit;
int DIM = 1;
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
  T->Draw("mass4l >> h01(35, 105, 140)", "mass4l >105 && mass4l<140","goff");
  TH1F *hist2 = (TH1F*)gDirectory->Get("h01");
  hist2->Scale(S*lum/num_event);
  hist2->SetFillColor(2);
  hist2->SetLineColor(2);
  hist2->SetFillStyle(3354);
  hist2->GetXaxis()->SetTitle("m(4l) (GeV)");
  hist2->GetYaxis()->SetTitle("Events");
  hist[0]= hist2;
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



void mass(){ 
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
  bkgTH1( f3_1, s3_1, bkg_WZ);  */  
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
  bkgTH1( f10_1, s6_1, bkg_4tau);
 
  THStack *SIG = new THStack("SIG","");
  SIG->Add(sig_ggH[0]);
  SIG->Add(sig_VBF[0]);
  SIG->Add(sig_WpH[0]);
  SIG->Add(sig_WmH[0]);
  SIG->Add(sig_ZH[0]);
  SIG->Add(sig_ttH[0]);
  SIG->Add(sig_bbH[0]);
  SIG->Add(sig_tHq[0]);
  SIG->SetTitle("signal; m(4l) (GeV); Events");

  THStack *BKG = new THStack("BKG","");
  /*BKG->Add(bkg_DY[0]);
  BKG->Add(bkg_tt[0]);
  BKG->Add(bkg_WZ[0]);*/
  BKG->Add(bkg_ZZ[0]);
  BKG->Add(bkg_2e2mu[0]);
  BKG->Add(bkg_2e2tau[0]);
  BKG->Add(bkg_2mu2tau[0]);
  BKG->Add(bkg_4e[0]);
  BKG->Add(bkg_4mu[0]);
  BKG->Add(bkg_4tau[0]);
  BKG->SetTitle("background; m(4l) (GeV); Events");
  
  THStack *BKGggZZ = new THStack("BKGggZZ","");
  /*BKG->Add(bkg_DY[0]);
  BKG->Add(bkg_tt[0]);
  BKG->Add(bkg_WZ[0]);*/ 
  BKGggZZ->Add(bkg_2e2mu[0]);
  BKGggZZ->Add(bkg_2e2tau[0]);
  BKGggZZ->Add(bkg_2mu2tau[0]);
  BKGggZZ->Add(bkg_4e[0]);
  BKGggZZ->Add(bkg_4mu[0]);
  BKGggZZ->Add(bkg_4tau[0]);
  BKGggZZ->SetTitle("background ggZZ; m(4l) (GeV); Events");
  
  THStack *TOT = new THStack("TOT","");
  TOT->Add(sig_ggH[0]);
  TOT->Add(sig_VBF[0]);
  TOT->Add(sig_WpH[0]);
  TOT->Add(sig_WmH[0]);
  TOT->Add(sig_ZH[0]);
  TOT->Add(sig_ttH[0]);
  TOT->Add(sig_bbH[0]);
  TOT->Add(sig_tHq[0]);
  TOT->Add(bkg_ZZ[0]);
  TOT->Add(bkg_2e2mu[0]);
  TOT->Add(bkg_2e2tau[0]);
  TOT->Add(bkg_2mu2tau[0]);
  TOT->Add(bkg_4e[0]);
  TOT->Add(bkg_4mu[0]);
  TOT->Add(bkg_4tau[0]);
  TOT->SetTitle("signal + background; m(4l) (GeV); Events");

  TH1F *lastsig = (TH1F*)SIG->GetStack()->Last();
  TH1F *lastbkg = (TH1F*)BKG->GetStack()->Last();
  cout<<lastsig->Integral()/sqrt(lastbkg->Integral())<<endl;//sensitività
  TH1F *lasttot = (TH1F*)TOT->GetStack()->Last();
  TH1F *lastbkgggZZ = (TH1F*)BKGggZZ->GetStack()->Last();
  //renormalization of the signal

   /*for(z=0;z<VAR;z++){
    float areasig= listsig->Integral();    
    //cout<<"area del segnale  = "<< areasig<<endl;   
    float areabkg= lastbkg->Integral();    
    //cout<<"area del fondo "<<z<< " = "<< areabkg<<endl;
    listsig->Scale(areabkg/areasig);
    }*/

  /*auto legend1 = new TLegend(0.15,0.8,0.4,0.9);
  legend1->AddEntry(sig_ggH[0],"signal","f");
  legend1->AddEntry(bkg_4mu[0],"background","f");

 
  
  TCanvas *myC = new TCanvas("myC","Plot 1", 1000,800);   
  lastsig->GetXaxis()->SetTitle("m(4l) (GeV)");
  lastsig->GetYaxis()->SetTitle("Events");  
  lastsig->SetTitle("Signal vs Background");  
  myC->cd();
  lastsig->Draw("hist");
  lastbkg->Draw("histsame");  
  legend1->Draw();*/
  TCanvas *myC1 = new TCanvas("myC1","Plot 2", 1000,800);   
  myC1->SetLogy();
  lasttot->GetXaxis()->SetTitle("m(4l) (GeV)");
  lasttot->GetYaxis()->SetTitle("Events");  
  lasttot->SetTitle("Signal + Background");  
  myC1->cd();
  lasttot->SetLineColor(1);
  lasttot->SetFillColor(0);
  lasttot->GetYaxis()->SetRangeUser(0.0001,30);
  lasttot->Draw("hist");
  /*sig_ggH[0];
  sig_VBF[0];
  sig_WpH[0;
  sig_WmH[0];
  sig_ZH[0];
  sig_ttH[0];
  sig_bbH[0];
  sig_tHq[0];
  bkg_ZZ[0];
  bkg_2e2mu[0];
  bkg_2e2tau[0];
  bkg_2mu2tau[0];
  bkg_4e[0];
  bkg_4mu[0];
  bkg_4tau[0];*/
  sig_ggH[0]->SetLineColor(1);
  sig_VBF[0]->SetLineColor(2);
  sig_WpH[0]->SetLineColor(3);
  sig_WmH[0]->SetLineColor(4);
  sig_ZH[0]->SetLineColor(kOrange);
  sig_ttH[0]->SetLineColor(6);
  sig_bbH[0]->SetLineColor(7);
  sig_tHq[0]->SetLineColor(14);
  //////////  
  sig_ggH[0]->SetMarkerColor(1);
  sig_VBF[0]->SetMarkerColor(2);
  sig_WpH[0]->SetMarkerColor(3);
  sig_WmH[0]->SetMarkerColor(4);
  sig_ZH[0]->SetMarkerColor(kOrange);
  sig_ttH[0]->SetMarkerColor(6);
  sig_bbH[0]->SetMarkerColor(7);
  sig_tHq[0]->SetMarkerColor(14);
  ///////
  sig_ggH[0]->SetMarkerStyle(8);
  sig_VBF[0]->SetMarkerStyle(8);
  sig_WpH[0]->SetMarkerStyle(8);
  sig_WmH[0]->SetMarkerStyle(8);
  sig_ZH[0]->SetMarkerStyle(8);
  sig_ttH[0]->SetMarkerStyle(8);
  sig_bbH[0]->SetMarkerStyle(8);
  sig_tHq[0]->SetMarkerStyle(8);
  ///////
  lastbkgggZZ->SetFillColor(2);
  lastbkgggZZ->SetLineColor(2);
  lastbkgggZZ->SetFillStyle(3354);
  sig_ggH[0]->Draw("same");
  sig_VBF[0]->Draw("same");
  sig_WpH[0]->Draw("same");
  sig_WmH[0]->Draw("same");
  sig_ZH[0]->Draw("same");
  sig_ttH[0]->Draw("same");
  sig_bbH[0]->Draw("same");
  sig_tHq[0]->Draw("same");
  bkg_ZZ[0]->Draw("histsame");
  lastbkgggZZ->Draw("histsame");
  auto legend2 = new TLegend(0.9,0.4,1.0,0.9);
  legend2->AddEntry(lasttot,"sig + bkg","f");
  legend2->AddEntry(lastbkgggZZ,"ggZZ","f");
  legend2->AddEntry(bkg_ZZ[0],"qqZZ","f");
  legend2->AddEntry(sig_ggH[0],"ggH","lp");
  legend2->AddEntry(sig_VBF[0],"VBF","lp");
  legend2->AddEntry(sig_ZH[0],"ZH","lp");
  legend2->AddEntry(sig_WpH[0],"W+H","lp");
  legend2->AddEntry(sig_WmH[0],"W-H","lp");
  legend2->AddEntry(sig_ttH[0],"ttH","lp");
  legend2->AddEntry(sig_bbH[0],"bbH","lp");
  legend2->AddEntry(sig_tHq[0],"tHq","lp");
  
  legend2->Draw();
  /////////////
  ////    mass4l fit
  /////////////
  /////// RooFit
  Double_t xMin = 105; 
  Double_t xMax = 140;
  Int_t nBins = lastsig->GetNbinsX();
  RooRealVar xVar("xVar", "m(4l) (GeV)", xMin, xMax); 
  xVar.setBins(nBins);  
  RooDataHist* Hist = new RooDataHist(lastsig->GetName(), lastsig->GetTitle(), RooArgSet(xVar), Import(*lastsig,kFALSE));
  ////////////
  RooRealVar mCB("mean", "meanCB", 124,123.5, 124.5);
  RooRealVar sigmaCB("#sigma_{CB}", "sigma1CB", 1, 0, 1.5);
  RooRealVar alpha1("#alpha1","alpha1",1.4, 0.1, 3);
  RooRealVar nSigma1("n#sigma1","nSigma1", 2, 0.1, 5);
  RooRealVar alpha2("#alpha2","alpha2",1.4, 0.1, 3);
  RooRealVar nSigma2("n#sigma2","nSigma2", 2, 0.1, 5);

 
  RooCBShape* sigCBPdf = new RooCBShape("sigCBPdf","sigCBPdf",xVar,mCB,sigmaCB,alpha1,nSigma1);  
  //RooCrystalBall* sigCBPdf = new RooCrystalBall("sigCBPdf","DoubleSidedCB",xVar,mCB,sigmaCB,alpha1,nSigma1,alpha2,nSigma2);
  //sigCBPdf->fitTo(*Hist, Extended(kTRUE), Minos(kTRUE));
  sigCBPdf->fitTo(*Hist, RooFit::Save(true));
  RooPlot* xframe = xVar.frame();
  xframe->SetTitle( "signal" ); 
  xframe->SetYTitle("Events");
  Hist->plotOn(xframe);
  sigCBPdf->plotOn(xframe,  LineColor(kGreen));
  //linea magiga
  sigCBPdf->plotOn(xframe);   
  RooPlot *framePull = xVar.frame();
  framePull->SetTitle("Pulls bin-by.bin");
  framePull->addObject((TObject*)xframe->pullHist(),"p");
  framePull->SetMinimum(-6);
  framePull->SetMaximum(6);
  TCanvas *myC2 = new TCanvas("myC","FitPlot", 700, 700); 
  myC2->Divide(0,2);
  myC2->cd(2);
  gPad->SetPad(0.,0.,1.,0.3);
  framePull->Draw();
  TLine *line1=new TLine(105,0.,140,0.);    
  line1->SetLineColor(2);
  line1->Draw("same");
  TLine *line2=new TLine(105,3.,140,3.);    
  line2->SetLineColor(3);
  line2->Draw("same");
  TLine *line3=new TLine(105,-3.,140,-3.);    
  line3->SetLineColor(3);
  line3->Draw("same");
  myC2->cd(1);
  gPad->SetPad(0.,0.3,1.,1.);
  xframe->Draw(); 
  
  /// fit with a TF1
  TF1 *dcb = new TF1("dcb","DoubleSidedCB",4.7,5.7,7);
  dcb->SetLineColor(4);
  double par[7];
  par[0]=200;
  par[1]=124.5;
  par[2]=1.5;
  par[3]=1;
  par[4]=1;
  par[5]=1;
  par[6]=1;
  dcb->SetParameters(&par[0]);
  TCanvas *C = new TCanvas("C","C",700,700);
  lastsig->Draw("PE1");
  gStyle->SetOptStat(0);
  lastsig->SetTitle("signal ;m(4l) (GeV); Events");
  lastsig->Fit("dcb");
  TLegend *LEG = new TLegend(0.6,0.8,0.89,0.89);
  LEG->AddEntry(dcb,"Double Sided Crystal Ball");
  LEG->SetBorderSize(0);
  LEG->Draw("sames");
  double chi=dcb->GetChisquare();
  std::cout <<"Chi squared/nof=   "<<chi/(nBins-7)<< std::endl;
 
 







}//close the main
