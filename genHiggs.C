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

  
 //mie modifiche 
   fChain->SetBranchStatus("*",0);    
   fChain->SetBranchStatus("lep_pt",1);
   fChain->SetBranchStatus("lep_id",1);
   fChain->SetBranchStatus("lep_eta",1);  
   fChain->SetBranchStatus("lep_phi",1); 
   fChain->SetBranchStatus("lep_mass",1);
   fChain->SetBranchStatus("GENlep_phi",1);
   fChain->SetBranchStatus("GENlep_id",1);
   fChain->SetBranchStatus("GENlep_eta",1);
   fChain->SetBranchStatus("GENlep_MomId",1);
   fChain->SetBranchStatus("GENlep_MomMomId",1);
   
  //Long64_t nentries = b_lep_pt->GetEntries();
   Long64_t nentries = fChain->GetEntries();
   
   TH1F *h_pt_0  = new TH1F("h_pt_0","pt of foyrth lepton", 100, 0,200);
   TH1F *h_pt_1  = new TH1F("h_pt_1","pt of third lepton", 100, 0,200);
   TH1F *h_pt_2  = new TH1F("h_pt_2","pt of second lepton", 100, 0,200);
   TH1F *h_pt_3  = new TH1F("h_pt_3","pt of first lepton", 100, 0,200);
   TH1F *h_eta_0  = new TH1F("h_eta_0","eta of fourth lepton", 100, -3,3);   
   TH1F *h_eta_1  = new TH1F("h_eta_1","eta of third lepton", 100,-3,3);
   TH1F *h_eta_2  = new TH1F("h_eta_2","eta of second lepton", 100, -3,3);
   TH1F *h_eta_3  = new TH1F("h_eta_3","eta of first lepton", 100, -3,3);
   TH1F *h_candidates  = new TH1F("h_candidates","number of candidates for event", 5, -0.5,4.5);
   TH1F *h_4l_mass  = new TH1F("h_4l_mass","mass of the four leptons", 100, 70,200);
   TH1F *h_Z1_mass  = new TH1F("h_Z1_mass","mass of Z1", 120, 0,120);
   TH1F *h_Z2_mass  = new TH1F("h_Z2_mass","mass of Z2", 100, 12,120);

   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     float ev = 0;
     vector<int> indicej;
     vector<int> indicei;
     vector<int> indicek;
     vector<int> indicez;
     vector<float> PT3;
     vector<float> PT2;
     vector<float> PT1;
     vector<float> PT0;
     vector<float> ETA3;
     vector<float> ETA2;
     vector<float> ETA1;
     vector<float> ETA0;
     vector<float> MASS4L;
     vector<float> MASSZ1;
     vector<float> MASSZ2;
   
   
   
   
     GetEntry(jentry);

     int size = lep_pt->size();  
     if(size>3){
     int gensize = GENlep_id->size();
     for (Int_t j = 0; j < size; j++) {
       int idx1 = -1;
       int  bestidx1 = -1;
       float bestdr1 = 9999.;
       if(lep_id->at(j)==13 && abs(lep_eta->at(j))<2.4 ){
	 TLorentzVector lepton1;
	 lepton1.SetPtEtaPhiM(lep_pt->at(j),lep_eta->at(j),lep_phi->at(j),lep_mass->at(j));
	 for (Int_t r = 0; r < gensize; r++) {
	  idx1 = idx1 +1;
	  if(GENlep_id->at(r)==13 && abs(GENlep_eta->at(r))<2.4){
	    float dr1 = deltaR(GENlep_eta->at(r),GENlep_phi->at(r), lep_eta->at(j), lep_phi->at(j));
	    if (dr1 < 0.1 && dr1 < bestdr1) {
	      bestidx1 = idx1;
	      bestdr1 = dr1;}}}
	 if(bestidx1>-1 &&  GENlep_MomId->at(bestidx1)==23 &&  GENlep_MomMomId->at(bestidx1)==25){
	   for (Int_t i = 0; i < size; i++){
	     int idx2 = -1;
	     int  bestidx2 = -1;
	     float bestdr2 = 9999.;
	   TLorentzVector lepton2;
	   lepton2.SetPtEtaPhiM(lep_pt->at(i),lep_eta->at(i),lep_phi->at(i),lep_mass->at(i));
	   float mll1 = (lepton1+lepton2).M();	   
	   if(lep_id->at(i)==-13 && abs(lep_eta->at(i))<2.4 && mll1 >12 && mll1<120){
	     for (Int_t t = 0; t < gensize; t++) {
	       idx2 = idx2 +1;
	       if(GENlep_id->at(t)==-13 && abs(GENlep_eta->at(t))<2.4){
		 float dr2 = deltaR(GENlep_eta->at(t),GENlep_phi->at(t), lep_eta->at(i), lep_phi->at(i));
		 if (dr2 < 0.1 && dr2 < bestdr2) {
		   bestidx2 = idx2;
		   bestdr2 = dr2;}}}
	     if(bestidx2>-1 &&  GENlep_MomId->at(bestidx2)==23 &&  GENlep_MomMomId->at(bestidx2)==25){
	     for (Int_t k = j; k < size; k++) {
	       int idx3 = -1;
	       int  bestidx3 = -1;
	       float bestdr3 = 9999.;
	       if(j!=k && lep_id->at(k)==13 && abs(lep_eta->at(k))<2.4){
		  TLorentzVector lepton3;
		  lepton3.SetPtEtaPhiM(lep_pt->at(k),lep_eta->at(k),lep_phi->at(k),lep_mass->at(k));
		  for (Int_t q = 0; q < gensize; q++) {
		    idx3 = idx3 +1;
		    if(GENlep_id->at(q)==13 && abs(GENlep_eta->at(q))<2.4){
		      float dr3 = deltaR(GENlep_eta->at(q),GENlep_phi->at(q), lep_eta->at(k), lep_phi->at(k));
		      if (dr3 < 0.1 && dr3 < bestdr3) {
			bestidx3 = idx3;
			bestdr3 = dr3;}}}
		  if(bestidx3>-1 && bestidx3 != bestidx1 && GENlep_MomId->at(bestidx3)==23 &&  GENlep_MomMomId->at(bestidx3)==25){
		  for (Int_t z = 0; z < size; z++){
		    int idx4 = -1;
		    int  bestidx4 = -1;
		    float bestdr4 = 9999.;
		    TLorentzVector lepton4;
		    lepton4.SetPtEtaPhiM(lep_pt->at(z),lep_eta->at(z),lep_phi->at(z),lep_mass->at(z));
		    float mll2 = (lepton3+lepton4).M();
		    if(i!=z && lep_id->at(z)==-13 && abs(lep_eta->at(z))<2.4 && mll2>12 && mll2<120){
		      for (Int_t y = 0; y < gensize; y++) {
			idx4 = idx4 +1;
			if(GENlep_id->at(y)==-13 && abs(GENlep_eta->at(y))<2.4){
			  float dr4 = deltaR(GENlep_eta->at(y),GENlep_phi->at(y), lep_eta->at(z), lep_phi->at(z));
			  if (dr4 < 0.1 && dr4 < bestdr4) {
			    bestidx4 = idx4;
			    bestdr4 = dr4;}}}
		      if(bestidx4>-1 && bestidx4 != bestidx2 &&  GENlep_MomId->at(bestidx4)==23 &&  GENlep_MomMomId->at(bestidx4)==25){
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
			indicej.push_back(j);
			indicei.push_back(i);
			indicek.push_back(k);
			indicez.push_back(z);
			PT3.push_back(PT[3]);
			PT2.push_back(PT[2]);
			PT1.push_back(PT[1]);
			PT0.push_back(PT[0]);
			ETA3.push_back(ETA[3]);
			ETA2.push_back(ETA[2]);
			ETA1.push_back(ETA[1]);
			ETA0.push_back(ETA[0]);
			MASS4L.push_back(mass4l);
			MASSZ1.push_back(MassZ1);
			MASSZ2.push_back(MassZ2);			
		      }}}}}}}}}}}}}} //chiudo tutti i for e gli if sui leptoni
     int size2 = PT3.size();  
     for (Int_t w = 0; w < size2; w++) {
       for (Int_t g = w; g < size2; g++) {
	 if(indicej[w]==indicej[g] && indicek[w]==indicek[g] && indicei[w]==indicez[g] && indicei[w]==indicez[g]){
	   if(abs(MASSZ1[w]-91.2)<abs(MASSZ1[g]-91.2)){MASSZ1[g]=0;}
	   else{MASSZ1[w]=0;}}}
       if(MASSZ1[w]!=0){
	 ev = ev +1;
	 h_pt_0->Fill(PT0[w]);
	 h_pt_1->Fill(PT1[w]);
	 h_pt_2->Fill(PT2[w]);
	 h_pt_3->Fill(PT3[w]);
	 h_eta_0->Fill(ETA0[w]);
	 h_eta_1->Fill(ETA2[w]);
	 h_eta_2->Fill(ETA2[w]);
	 h_eta_3->Fill(ETA3[w]);
	 h_4l_mass->Fill(MASS4L[w]);
	 h_Z1_mass->Fill(MASSZ1[w]); 
	 h_Z2_mass->Fill(MASSZ2[w]); 
	 // cout <<"all'evento numero "<< jentry<<" partecipano i muoni " << j << "  "<< i<< "  " << k<< "  " << z << endl;
}}
     

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
