#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
void MyClass::Loop()
{
  if (fChain == 0) return;

  
   //mie modifiche 
   fChain->SetBranchStatus("*",0);    
   fChain->SetBranchStatus("lep_pt",1);
   fChain->SetBranchStatus("lep_id",1);
   fChain->SetBranchStatus("lep_eta",1);   
  //Long64_t nentries = b_lep_pt->GetEntries();
   Long64_t nentries = fChain->GetEntries();
   
   TH1F *myHisto1  = new TH1F("myHisto1","muons_pt", 100, 0,200);
   TH1F *myHisto2  = new TH1F("myHisto2","muons_eta", 100, -3,3);
   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
     GetEntry(jentry);

     int size = lep_pt->size();  
     for (Int_t j = 0; j < size; j++) {
       if(lep_id->at(j)==13 && abs(lep_eta->at(j))<2.4){
	 myHisto1->Fill(lep_pt->at(j));}
 
       //cout << lep_pt->at(j)<< endl;
      
     }}
   fChain->SetBranchStatus("*",0);    
   fChain->SetBranchStatus("lep_eta",1);
   fChain->SetBranchStatus("lep_id",1);
   Long64_t nentries2 = fChain->GetEntries();
   for (Long64_t jentry2=0; jentry2<nentries2;jentry2++) {
   
     GetEntry(jentry2);

     int size2 = lep_eta->size();  
     for (Int_t i = 0; i < size2; i++) {
       if(lep_id->at(i)==13&& abs(lep_eta->at(i))<2.4){
	 myHisto2->Fill(lep_eta->at(i));}
 
       //cout << lep_pt->at(j)<< endl;
      
     }}
   TCanvas *MyC = new TCanvas("myC","Plot", 1000,800);
   MyC->cd(); 
   myHisto1->SetLineColor(2);
   myHisto1->GetYaxis()->SetTitle("Events");
   myHisto1->GetXaxis()->SetTitle("pt (Gev)");
   myHisto1->GetXaxis()->CenterTitle();
   myHisto1->Draw();
   MyC->SaveAs("./Plots/Muons_Pt.png");
   MyC->Clear();
   //grafico eta
   MyC->cd(); 
   myHisto2->SetLineColor(2);
   myHisto2->GetYaxis()->SetTitle("Events");
   myHisto2->GetXaxis()->SetTitle(" #eta ");
   myHisto2->GetXaxis()->CenterTitle();
   myHisto2->Draw();
   MyC->SaveAs("./Plots/Muons_Eta.png");
   MyC->Clear();}
