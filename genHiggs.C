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
#include <stdio.h>
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
   fChain->SetBranchStatus("lep_d0PV",1);
   fChain->SetBranchStatus("lep_Sip",1);
   fChain->SetBranchStatus("lep_numberOfValidPixelHits",1);
   fChain->SetBranchStatus("lep_trackerLayersWithMeasurement",1);
   fChain->SetBranchStatus("lep_chi2LocalPosition",1);
   fChain->SetBranchStatus("lep_trkKink",1);
   fChain->SetBranchStatus("lep_numberOfMatchedStations",1);
   fChain->SetBranchStatus("lep_validFraction",1);
   //fChain->SetBranchStatus("lep_arbitrationType",1);
   fChain->SetBranchStatus("lep_normalizedChi2",1);
   fChain->SetBranchStatus("lep_numberOfValidMuonHits",1);     
      
   
         
  //Long64_t nentries = b_lep_pt->GetEntries();
   Long64_t nentries = fChain->GetEntries();
 
   
   TH1F *h_pt_0  = new TH1F("h_pt_0","pt of fourth lepton", 100, 0,200);
   TH1F *h_pt_1  = new TH1F("h_pt_1","pt of third lepton", 100, 0,200);
   TH1F *h_pt_2  = new TH1F("h_pt_2","pt of second lepton", 100, 0,200);
   TH1F *h_pt_3  = new TH1F("h_pt_3","pt of first lepton", 100, 0,200);
   TH1F *h_pt_3_pass  = new TH1F("h_pt_3_pass","pt of first lepton that pass th cut", 100, 0,200);
   TH1F *h_eta_0  = new TH1F("h_eta_0","eta of fourth lepton", 100, -3,3);   
   TH1F *h_eta_1  = new TH1F("h_eta_1","eta of third lepton", 100,-3,3);
   TH1F *h_eta_2  = new TH1F("h_eta_2","eta of second lepton", 100, -3,3);
   TH1F *h_eta_3  = new TH1F("h_eta_3","eta of first lepton", 100, -3,3);
   TH1F *h_candidates  = new TH1F("h_candidates","number of candidates for event", 5, -0.5,4.5);
   TH1F *h_4l_mass  = new TH1F("h_4l_mass","mass of the four leptons", 100, 70,170);
   TH1F *h_Z1_mass  = new TH1F("h_Z1_mass","mass of Z1", 100, 20,120);
   TH1F *h_Z2_mass  = new TH1F("h_Z2_mass","mass of Z2", 100, 12,120);
   TH1F *h_4l_p = new TH1F("h_4l_p","momentum of the four leptons", 50, 0.1,400);
   TH1F *h_4l_m_pass[99] = {};
   TH1F *h_NVPH  = new TH1F("h_NVPH","number of valid pixel hits", 11, -0.5,10.5);
   TH1F *h_TLWM  = new TH1F("h_TLWM","number of tracker layers with measurement", 21, -0.5,20.5);
   TH1F *h_C2LP  = new TH1F("h_C2LP","Chi 2 local position",130 , -1,12);
   TH1F *h_KINK  = new TH1F("h_KINK","track of kinks", 41, -0.5,40.5);
   TH1F *h_NOMS  = new TH1F("h_NOMS","number of matched stations", 9, -0.5,8.5);
   TH1F *h_VAFR  = new TH1F("h_VAFR","valid fraction", 100, 0,1.000001);
   TH1F *h_NOC2  = new TH1F("h_NOC2","normalised Chi 2", 100, -1,4);
   TH1F *h_NVMH  = new TH1F("h_NVMH","number of valid muon hits", 11, -0.5,10.5);
   //float eff;
   //float npass,ntot;
   float ntot;      
   ntot = 0;
   vector<float> cut_pt_first_muon;
   cut_pt_first_muon.push_back(15);
   cut_pt_first_muon.push_back(20);
   cut_pt_first_muon.push_back(25);
   cut_pt_first_muon.push_back(30);
   const int cutsize = cut_pt_first_muon.size();
   cout << cutsize << endl;
   float eff[99]={};
   float npass[99]={};
   for(Int_t u = 0; u < cutsize; u++) {
     std::string nomestringa{"h_4l_m_pass_"+std::to_string(u)};
     const char * nome{nomestringa.c_str()};
     h_4l_m_pass[u]= new TH1F(nome,"momentum of the four leptons that pass the cut", 100, 70,170);}
   
   int ntotev=0;
   int ntotevpass=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     ntotev = ntotev +1;
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
     vector<float> P4L;
     vector<float> MASSZ1;
     vector<float> MASSZ2;
     //ricostruzione dei muoni
     vector<float> NVPH3;
     vector<float> TLWM3;
     vector<float> C2LP3;
     vector<float> KINK3;
     vector<float> NOMS3;
     vector<float> VAFR3;
     vector<float> NOC23;
     vector<float> NVMH3;
     vector<float> NVPH2;
     vector<float> TLWM2;
     vector<float> C2LP2;
     vector<float> KINK2;
     vector<float> NOMS2;
     vector<float> VAFR2;
     vector<float> NOC22;
     vector<float> NVMH2;
     vector<float> NVPH1;
     vector<float> TLWM1;
     vector<float> C2LP1;
     vector<float> KINK1;
     vector<float> NOMS1;
     vector<float> VAFR1;
     vector<float> NOC21;
     vector<float> NVMH1;
     vector<float> NVPH0;
     vector<float> TLWM0;
     vector<float> C2LP0;
     vector<float> KINK0;
     vector<float> NOMS0;
     vector<float> VAFR0;
     vector<float> NOC20;
     vector<float> NVMH0; 
     
   
   
   
   
     GetEntry(jentry);

     int size = lep_pt->size();  
     
     /*for (Int_t jj = 0; jj < size; jj++) {
       cout <<lep_id->at(jj)<<endl;}*/

     if(size>3){
     int gensize = GENlep_id->size();
     for (Int_t j = 0; j < size; j++) {
       int idx1 = -1;
       int  bestidx1 = -1;
       float bestdr1 = 9999.;
       if(lep_id->at(j)==13 && abs(lep_eta->at(j))<2.4 /*&& lep_Sip->at(j)<4 && lep_d0PV->at(j)<0.005*/ ){
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
	   if(lep_id->at(i)==-13 && abs(lep_eta->at(i))<2.4 && mll1 >12 && mll1<120/* && lep_Sip->at(i)<4 && lep_d0PV->at(i)<0.005*/){
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
	       if(j!=k && lep_id->at(k)==13 && abs(lep_eta->at(k))<2.4/* && lep_Sip->at(k)<4 && lep_d0PV->at(k)<0.005*/){
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
		    if(i!=z && lep_id->at(z)==-13 && abs(lep_eta->at(z))<2.4 && mll2>12 && mll2<120/* && lep_Sip->at(z)<4 && lep_d0PV->at(z)<0.005*/){
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
		      float NVPH[4]= {lep_numberOfValidPixelHits->at(i),lep_numberOfValidPixelHits->at(j),lep_numberOfValidPixelHits->at(k),lep_numberOfValidPixelHits->at(z)};
		      float TLWM[4]= {lep_trackerLayersWithMeasurement->at(i),lep_trackerLayersWithMeasurement->at(j),lep_trackerLayersWithMeasurement->at(k),lep_trackerLayersWithMeasurement->at(z)};
		      float C2LP[4]= {lep_chi2LocalPosition->at(i),lep_chi2LocalPosition->at(j),lep_chi2LocalPosition->at(k),lep_chi2LocalPosition->at(z)};
		       float KINK[4]= {lep_trkKink->at(i),lep_trkKink->at(j),lep_trkKink->at(k),lep_trkKink->at(z)};
		        float NOMS[4]= {lep_numberOfMatchedStations->at(i),lep_numberOfMatchedStations->at(j),lep_numberOfMatchedStations->at(k),lep_numberOfMatchedStations->at(z)};
     float VAFR[4]= {lep_validFraction->at(i),lep_validFraction->at(j),lep_validFraction->at(k),lep_validFraction->at(z)};
     float NOC2[4]= {lep_normalizedChi2->at(i),lep_normalizedChi2->at(j),lep_normalizedChi2->at(k),lep_normalizedChi2->at(z)};
     float NVMH[4]= {lep_numberOfValidMuonHits->at(i),lep_numberOfValidMuonHits->at(j),lep_numberOfValidMuonHits->at(k),lep_numberOfValidMuonHits->at(z)};
		      //ordino i 2 vettori per pt con l'ordinamento a bolle dal più piccolo al più grande		  
		      int p,pass;
		      float holdpt,holdeta;
		      for (pass = 1; pass <= 4 - 1; pass++){ // controlla passi 
			for (p = 0; p <= 4 -  pass -1; p++) {// controlla ordinamento 
		      if (PT[p] > PT[p + 1]) { // confronta 
			holdpt = PT[p]; //scambia il pt
			PT[p] = PT[p + 1];
			PT[p + 1] = holdpt;
			holdeta = ETA[p]; // scambia l'eta
			ETA[p] = ETA[p + 1];
			ETA[p + 1] = holdeta;// PT e ETA sono ordinati per pt
			holdeta = NVPH[p]; // scambia	Number of Validi Pixel Hits
                        NVPH[p] = NVPH[p + 1];
                        NVPH[p + 1] = holdeta;
			holdeta = TLWM[p]; // scambia Tracker Layer with measurement
                        TLWM[p] = TLWM[p + 1];
                        TLWM[p + 1] = holdeta;
			holdeta = C2LP[p]; // scambia Chi 2 Local Position
                        C2LP[p] = C2LP[p + 1];
                        C2LP[p + 1] = holdeta;
			holdeta = KINK[p]; // scambia track KINK
                        KINK[p] = KINK[p + 1];
                        KINK[p + 1] = holdeta;
			holdeta = NOMS[p]; // scambia Number Of Matched Stations
                        NOMS[p] = NOMS[p + 1];
                        NOMS[p + 1] = holdeta;
			holdeta = VAFR[p]; // scambia Valid Fraction
                        VAFR[p] = VAFR[p + 1];
                        VAFR[p + 1] = holdeta;
			holdeta = NOC2[p]; // scambia Normalised Chi 2
                        NOC2[p] = NOC2[p + 1];
                        NOC2[p + 1] = holdeta;
			holdeta = NVMH[p]; // scambia Number of Valid Muon Hits
                        NVMH[p] = NVMH[p + 1];
                        NVMH[p + 1] = holdeta;}}}
		      float mass4l = (lepton1+lepton2+lepton3+lepton4).M();
		      float p4l = (lepton1+lepton2+lepton3+lepton4).P();
		      if(PT[3]>20 && PT[2]>10 &&  PT[0]>5 && MassZ1>40 && mass4l>70){	
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
			P4L.push_back(p4l);
			MASSZ1.push_back(MassZ1);
			MASSZ2.push_back(MassZ2);
			NVPH3.push_back(NVPH[3]);
			NVPH2.push_back(NVPH[2]);
			NVPH1.push_back(NVPH[1]);
			NVPH0.push_back(NVPH[0]);
			TLWM3.push_back(TLWM[3]);
			TLWM2.push_back(TLWM[2]);
			TLWM1.push_back(TLWM[1]);
			TLWM0.push_back(TLWM[0]);
			C2LP3.push_back(C2LP[3]);
			C2LP2.push_back(C2LP[2]);
			C2LP1.push_back(C2LP[1]);
			C2LP0.push_back(C2LP[0]);
			KINK3.push_back(KINK[3]);
			KINK2.push_back(KINK[2]);
			KINK1.push_back(KINK[1]);
			KINK0.push_back(KINK[0]);
			NOMS3.push_back(NOMS[3]);
			NOMS2.push_back(NOMS[2]);
			NOMS1.push_back(NOMS[1]);
			NOMS0.push_back(NOMS[0]);
			VAFR3.push_back(VAFR[3]);
			VAFR2.push_back(VAFR[2]);
			VAFR1.push_back(VAFR[1]);
			VAFR0.push_back(VAFR[0]);
			NOC23.push_back(NOC2[3]);
			NOC22.push_back(NOC2[2]);
			NOC21.push_back(NOC2[1]);
			NOC20.push_back(NOC2[0]);
			NVMH3.push_back(NVPH[3]);
			NVMH2.push_back(NVPH[2]);
			NVMH1.push_back(NVPH[1]);
			NVMH0.push_back(NVPH[0]);
		      }}}}}}}}}}}}}} //chiudo tutti i for e gli if sui leptoni
     int size2 = PT3.size();  
     if (size2 != 0){ntotevpass = ntotevpass +1;}
     for (Int_t w = 0; w < size2; w++) {
       for (Int_t g = w; g < size2; g++) {
	 if(indicej[w]==indicej[g] && indicek[w]==indicek[g] && indicei[w]==indicez[g] && indicei[w]==indicez[g]){
	   if(abs(MASSZ1[w]-91.2)<abs(MASSZ1[g]-91.2)){MASSZ1[g]=0;}
	   else{MASSZ1[w]=0;}}}
       if(MASSZ1[w]!=0){
	 ev = ev +1;
	 ntot = ntot + 1;	 
	 h_pt_0->Fill(PT0[w]);
	 h_pt_1->Fill(PT1[w]);
	 h_pt_2->Fill(PT2[w]);
	 h_pt_3->Fill(PT3[w]);
	 h_eta_0->Fill(ETA0[w]);
	 h_eta_1->Fill(ETA2[w]);
	 h_eta_2->Fill(ETA2[w]);
	 h_eta_3->Fill(ETA3[w]);
	 h_4l_mass->Fill(MASS4L[w]);
	 h_4l_p->Fill(P4L[w]);
	 h_Z1_mass->Fill(MASSZ1[w]); 
	 h_Z2_mass->Fill(MASSZ2[w]);	 
	 h_NVPH->Fill(NVPH3[w]);
	 h_NVPH->Fill(NVPH2[w]);
	 h_NVPH->Fill(NVPH1[w]);
	 h_NVPH->Fill(NVPH0[w]);
	 h_TLWM->Fill(TLWM3[w]);
	 h_TLWM->Fill(TLWM2[w]);
	 h_TLWM->Fill(TLWM1[w]);
	 h_TLWM->Fill(TLWM0[w]);
	 h_C2LP->Fill(C2LP3[w]);
	 h_C2LP->Fill(C2LP2[w]);
	 h_C2LP->Fill(C2LP1[w]);
	 h_C2LP->Fill(C2LP0[w]);
	 h_KINK->Fill(KINK3[w]);
	 h_KINK->Fill(KINK2[w]);
	 h_KINK->Fill(KINK1[w]);
	 h_KINK->Fill(KINK0[w]);
	 h_NOMS->Fill(NOMS3[w]);
	 h_NOMS->Fill(NOMS2[w]);
	 h_NOMS->Fill(NOMS1[w]);
	 h_NOMS->Fill(NOMS0[w]);
	 h_VAFR->Fill(VAFR3[w]);
	 h_VAFR->Fill(VAFR2[w]);
	 h_VAFR->Fill(VAFR1[w]);
	 h_VAFR->Fill(VAFR0[w]);
	 h_NOC2->Fill(NOC23[w]);
	 h_NOC2->Fill(NOC22[w]);
	 h_NOC2->Fill(NOC21[w]);
	 h_NOC2->Fill(NOC20[w]);
	 h_NVMH->Fill(NVMH3[w]);
	 h_NVMH->Fill(NVMH2[w]);
	 h_NVMH->Fill(NVMH1[w]);
	 h_NVMH->Fill(NVMH0[w]);
	 /* for(Int_t r = 0; r < cutsize; r++) {	   
	   if (PT3[w]>cut_pt_first_muon[r] ) {
	     npass[r]=npass[r] + 1;	     
	     h_4l_m_pass[r]->Fill(MASS4L[w]);
	     }}*/
	 // cout <<"all'evento numero "<< jentry<<" partecipano i muoni " << j << "  "<< i<< "  " << k<< "  " << z << endl;
       }}
     
     

     h_candidates->Fill(ev);}//chiudo il loop sugli eventi
   cout <<ntotev<<endl;
   cout <<ntotevpass<<endl;

   //Tefficency
   /* auto legend = new TLegend(0.55,0.5,0.85,0.8);  
   for(Int_t o = 0; o < cutsize; o++) { 

     TEfficiency* pEff[99] = {};  
   if(TEfficiency::CheckConsistency(* h_4l_m_pass[o],* h_4l_mass)){
     pEff[o] = new TEfficiency(* h_4l_m_pass[o],* h_4l_mass);
     pEff[o]->SetLineColor(o+1);  
     h_4l_m_pass[o]->SetLineColor(o+1); 
     pEff[o]->SetTitle("relative efficiencies; mass of 4l (Gev) ; #epsilon"); 
     if(o==0){pEff[o]->Draw();}
     else{ pEff[o]->Draw("same");}    
     std::string nomestringa2{"efficiency when the cut is "+std::to_string(cut_pt_first_muon[o])+ " GeV"};
     const char * nome2{nomestringa2.c_str()};
     legend->AddEntry(h_4l_m_pass[o],nome2,"l");         
     gPad->Update(); 
     auto graph = pEff[o]->GetPaintedGraph(); 
     graph->SetMinimum(0);
     graph->SetMaximum(1); 
     gPad->Update(); 
   }
   eff[o]=h_4l_m_pass[o]->GetEntries()/ntotev;
   cout <<"imponendo come taglio "<<cut_pt_first_muon[o]<< " GeV sul muone più energetico ottengo come numero di candidati "<< h_4l_m_pass[o]->GetEntries() << endl;}
   legend->Draw();*/

   /*TFile f("signalggHZZ.root","recreate");
   TObjArray Hlist(0);
   Hlist.Add(h_NVPH);
   Hlist.Add(h_TLWM);
   Hlist.Add(h_C2LP);
   Hlist.Add(h_KINK);
   Hlist.Add(h_NOMS);
   Hlist.Add(h_VAFR);
   Hlist.Add(h_NOC2);
   Hlist.Add(h_NVMH);
   Hlist.Write();
   f.Close();*/


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
   h_4l_mass->GetXaxis()->SetTitle("m(4l) (Gev)");
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
   MyC->SetLogy();
   h_candidates->SetLineColor(2);
   h_candidates->GetYaxis()->SetTitle("Events");
   h_candidates->GetXaxis()->SetTitle("candidates for event");
   h_candidates->GetXaxis()->CenterTitle();
   h_candidates->GetYaxis()->SetTitle("Events");
   h_candidates->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Print("./Plots/Higgs/plots.pdf]");
   MyC->Clear();
}//chiudo tutti i loop
