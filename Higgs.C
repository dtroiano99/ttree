#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "DataFormats/Math/interface/deltaR.h"
#include "TVector3.h"
#include "Math/GenVector/PtEtaPhiM4D.h"
void MyClass::Loop()
{
   if (fChain == 0) return;
fChain->SetBranchStatus("*",0);    
   fChain->SetBranchStatus("lep_pt",1);
   fChain->SetBranchStatus("lep_id",1);
   fChain->SetBranchStatus("lep_eta",1);  
   fChain->SetBranchStatus("lep_phi",1); 
   fChain->SetBranchStatus("lep_mass",1);
   //fChain->SetBranchStatus("GENlep_phi",1);
   //fChain->SetBranchStatus("GENlep_id",1);
   //fChain->SetBranchStatus("GENlep_eta",1);
   
  //Long64_t nentries = b_lep_pt->GetEntries();
   Long64_t nentries = fChain->GetEntries();
   
   TH1F *h_pt_0  = new TH1F("h_pt_0","pt of first lepton", 100, 0,200);
   TH1F *h_pt_1  = new TH1F("h_pt_1","pt of second lepton", 100, 0,200);
   TH1F *h_pt_2  = new TH1F("h_pt_2","pt of third lepton", 100, 0,200);
   TH1F *h_pt_3  = new TH1F("h_pt_3","pt of fourth lepton", 100, 0,200);
   TH1F *h_eta_0  = new TH1F("h_eta_0","eta of first lepton", 100, -3,3);   
   TH1F *h_eta_1  = new TH1F("h_eta_1","eta of second lepton", 100,-3,3);
   TH1F *h_eta_2  = new TH1F("h_eta_2","eta of third lepton", 100, -3,3);
   TH1F *h_eta_3  = new TH1F("h_eta_3","eta of fourth lepton", 100, -3,3);
   TH1F *h_candidates  = new TH1F("h_candidates","number of candidates for event", 11, -0.5,10.5);
   TH1F *h_4l_mass  = new TH1F("h_4l_mass","mass of the four leptons", 100, 70,200);
   TH1F *h_Z1_mass  = new TH1F("h_Z1_mass","mass of Z1", 100, 12,120);
   TH1F *h_Z2_mass  = new TH1F("h_Z2_mass","mass of Z2", 100, 12,120);

   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     float ev = 0;
   
     GetEntry(jentry);

     int size = lep_pt->size();  
     if(size>3){
     //int gensize = GENlep_id->size();
     for (Int_t j = 0; j < size; j++) {
       if(lep_id->at(j)==13 && abs(lep_eta->at(j))<2.4 ){
	 TLorentzVector lepton1;
	 lepton1.SetPtEtaPhiM(lep_pt->at(j),lep_eta->at(j),lep_phi->at(j),lep_mass->at(j));
	 for (Int_t i = 0; i < size; i++){
	   TLorentzVector lepton2;
	   lepton2.SetPtEtaPhiM(lep_pt->at(i),lep_eta->at(i),lep_phi->at(i),lep_mass->at(i));
	   float mll1 = (lepton1+lepton2).M();
	   if(lep_id->at(i)==-13 && abs(lep_eta->at(i))<2.4 && mll1 >12 && mll1<120){	    
	      for (Int_t k = j; k < size; k++) {
		if(j!=k && lep_id->at(k)==13 && abs(lep_eta->at(k))<2.4){
		  TLorentzVector lepton3;
		  lepton3.SetPtEtaPhiM(lep_pt->at(k),lep_eta->at(k),lep_phi->at(k),lep_mass->at(k));		  
		  for (Int_t z = 0; z < size; z++){
		    TLorentzVector lepton4;
		    lepton4.SetPtEtaPhiM(lep_pt->at(z),lep_eta->at(z),lep_phi->at(z),lep_mass->at(z));
		    float mll2 = (lepton3+lepton4).M();
		    if(i!=z && lep_id->at(z)==-13 && abs(lep_eta->at(z))<2.4 && mll2>12 && mll2<120){		      
		      float MassZ1,MassZ2;
		      if(abs(mll1-91.2)<abs(mll2-91.2)){
			MassZ1 =mll1;
			MassZ2 =mll2;}
		      else {			
			MassZ1 =mll2;
			MassZ2 =mll1;}		      
		      float PT[4] = {lep_pt->at(i),lep_pt->at(j),lep_pt->at(k),lep_pt->at(z)};
		      float ETA[4] = {lep_eta->at(i),lep_eta->at(j),lep_eta->at(k),lep_eta->at(z)};
		      //ordino i 2 vettori per pt con l'ordinamento a bolle dal più piccolo al più grande		  
		      int p,pass;
		      float holdpt,holdeta;
		      for (pass = 1; pass <= 4 - 1; pass++){ // controlla passi 
			for (p = 0; p <= 4 -  pass -1; p++) {// controlla ordinamento 
		      if (PT[p] > PT[p + 1]) { // confronta 
			holdpt = PT[p]; //scambia 
			PT[p] = PT[p + 1];
			PT[p + 1] = holdpt;
			holdeta = ETA[p]; // scambia 
			ETA[p] = ETA[p + 1];
			ETA[p + 1] = holdeta;}}}// PT e ETA sono ordinati per pt
		      float mass4l = (lepton1+lepton2+lepton3+lepton4).M();;
		      if(PT[3]>20 && PT[2]>10 && MassZ1>40 && mass4l>70){
			ev = ev +1;
			h_pt_0->Fill(PT[3]);
			h_pt_1->Fill(PT[2]);
			h_pt_2->Fill(PT[1]);
			h_pt_3->Fill(PT[0]);
			h_eta_0->Fill(ETA[3]);
			h_eta_1->Fill(ETA[2]);
			h_eta_2->Fill(ETA[1]);
			h_eta_3->Fill(ETA[0]);
			h_4l_mass->Fill(mass4l);
			h_Z1_mass->Fill(MassZ1); 
			h_Z2_mass->Fill(MassZ2);         
			cout <<"all'evento numero "<< jentry<<" partecipano i muoni " << j << "  "<< i<< "  " << k<< "  " << z << endl;
		      }}}}}}}}}} //chiudo tutti i for e gli if sui leptoni
     h_candidates->Fill(ev);}//chiudo il loop sugli eventi
   //grafici pt
   TCanvas *MyC = new TCanvas("myC","Plot", 1000,800);
   MyC->cd(); 
   h_pt_0->SetLineColor(2);
   h_pt_0->GetYaxis()->SetTitle("Events");
   h_pt_0->GetXaxis()->SetTitle("pt (Gev)");
   h_pt_0->GetXaxis()->CenterTitle();
   h_pt_0->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf[");
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_pt_1->SetLineColor(2);
   h_pt_1->GetYaxis()->SetTitle("Events");
   h_pt_1->GetXaxis()->SetTitle("pt (Gev)");
   h_pt_1->GetXaxis()->CenterTitle();
   h_pt_1->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_pt_2->SetLineColor(2);
   h_pt_2->GetYaxis()->SetTitle("Events");
   h_pt_2->GetXaxis()->SetTitle("pt (Gev)");
   h_pt_2->GetXaxis()->CenterTitle();
   h_pt_2->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_pt_3->SetLineColor(2);
   h_pt_3->GetYaxis()->SetTitle("Events");
   h_pt_3->GetXaxis()->SetTitle("pt (Gev)");
   h_pt_3->GetXaxis()->CenterTitle();
   h_pt_3->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   //grafici eta
   MyC->cd(); 
   h_eta_0->SetLineColor(2);
   h_eta_0->GetYaxis()->SetTitle("Events");
   h_eta_0->GetXaxis()->SetTitle(" #eta ");
   h_eta_0->GetXaxis()->CenterTitle();
   h_eta_0->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_eta_1->SetLineColor(2);
   h_eta_1->GetYaxis()->SetTitle("Events");
   h_eta_1->GetXaxis()->SetTitle(" #eta ");
   h_eta_1->GetXaxis()->CenterTitle();
   h_eta_1->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_eta_2->SetLineColor(2);
   h_eta_2->GetYaxis()->SetTitle("Events");
   h_eta_2->GetXaxis()->SetTitle(" #eta ");
   h_eta_2->GetXaxis()->CenterTitle();
   h_eta_2->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_eta_3->SetLineColor(2);
   h_eta_3->GetYaxis()->SetTitle("Events");
   h_eta_3->GetXaxis()->SetTitle(" #eta ");
   h_eta_3->GetXaxis()->CenterTitle();
   h_eta_3->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   //massa dei 4 leptoni
   MyC->cd(); 
   h_4l_mass->SetLineColor(2);
   h_4l_mass->GetYaxis()->SetTitle("Events");
   h_4l_mass->GetXaxis()->SetTitle("mass of 4l (Gev)");
   h_4l_mass->GetXaxis()->CenterTitle();
   h_4l_mass->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   //massa delle Z0
   MyC->cd(); 
   h_Z1_mass->SetLineColor(2);
   h_Z1_mass->GetYaxis()->SetTitle("Events");
   h_Z1_mass->GetXaxis()->SetTitle("mass of Z1 (Gev)");
   h_Z1_mass->GetXaxis()->CenterTitle();
   h_Z1_mass->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   MyC->cd(); 
   h_Z2_mass->SetLineColor(2);
   h_Z2_mass->GetYaxis()->SetTitle("Events");
   h_Z2_mass->GetXaxis()->SetTitle("mass of Z2 (Gev)");
   h_Z2_mass->GetXaxis()->CenterTitle();
   h_Z2_mass->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   //histo candidati
   MyC->cd(); 
   h_candidates->SetLineColor(2);
   h_candidates->GetYaxis()->SetTitle("Events");
   h_candidates->GetXaxis()->SetTitle("candidates for event");
   h_candidates->GetXaxis()->CenterTitle();
   h_candidates->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Print("./Plots/Higgs/plots.pdf]");
   MyC->Clear();}//chiudo tutti i loop
