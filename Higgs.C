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
   /*fChain->SetBranchStatus("GENlep_phi",1);
   fChain->SetBranchStatus("GENlep_id",1);
   fChain->SetBranchStatus("GENlep_eta",1);
   fChain->SetBranchStatus("GENlep_MomId",1);
   fChain->SetBranchStatus("GENlep_MomMomId",1);*/
   fChain->SetBranchStatus("lep_d0PV",1);
   fChain->SetBranchStatus("lep_Sip",1);
      
   
  //Long64_t nentries = b_lep_pt->GetEntries();
   Long64_t nentries = fChain->GetEntries();
   float nbin, min,max;
   nbin =50;
   min=0.1;
   max=400;
   
   TH1F *h_pt_0  = new TH1F("h_pt_0","pt of fourth lepton", 100, 0,200);
   TH1F *h_pt_1  = new TH1F("h_pt_1","pt of third lepton", 100, 0,200);
   TH1F *h_pt_2  = new TH1F("h_pt_2","pt of second lepton", 100, 0,200);
   TH1F *h_pt_3  = new TH1F("h_pt_3","pt of first lepton", 100, 0,200);
   TH1F *h_pt_3_1  = new TH1F("h_pt_3_1","pt of first lepton that pass th cut", 100, 0,200);
   TH1F *h_eta_0  = new TH1F("h_eta_0","eta of fourth lepton", 100, -3,3);   
   TH1F *h_eta_1  = new TH1F("h_eta_1","eta of third lepton", 100,-3,3);
   TH1F *h_eta_2  = new TH1F("h_eta_2","eta of second lepton", 100, -3,3);
   TH1F *h_eta_3  = new TH1F("h_eta_3","eta of first lepton", 100, -3,3);
   TH1F *h_candidates  = new TH1F("h_candidates","number of candidates for event", 5, -0.5,4.5);
   TH1F *h_candidates_1  = new TH1F("h_candidates_1","number of candidates for event that pass the cuts", 5, -0.5,4.5);
   TH1F *h_4l_mass  = new TH1F("h_4l_mass","mass of the four leptons", 330, 70,400);
   TH1F *h_4l_mass_1  = new TH1F("h_4l_mass_1","mass of the four leptons that pass the cuts", 330, 70,400);
   TH1F *h_Z1_mass  = new TH1F("h_Z1_mass","mass of Z1", 100, 20,120);
   TH1F *h_Z1_mass_1  = new TH1F("h_Z1_mass_1","mass of Z1 that pass the cuts ", 100, 20,120);
   TH1F *h_Z2_mass  = new TH1F("h_Z2_mass","mass of Z2", 100, 12,120);
   TH1F *h_4l_p = new TH1F("h_4l_p","momentum of the four leptons", nbin, min,max);
   TH1F *h_4l_m_pass[99] = {};
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
     h_4l_m_pass[u]= new TH1F(nome,"mass of the four leptons that pass the cut",4, 70,144/* 330, 70,400*/);}
   
   int ntotev=0;
   int ntotevpass=0;
   int ntotevpass_1=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     ntotev = ntotev +1;
     float ev = 0;
     float ev_1 = 0;
     vector<int> indicej;
     vector<int> indicei;
     vector<int> indicek;
     vector<int> indicez;
     vector<int> indicej_1;
     vector<int> indicei_1;
     vector<int> indicek_1;
     vector<int> indicez_1;
     vector<float> PT3;
     vector<float> PT3_1;
     vector<float> PT2;
     vector<float> PT1;
     vector<float> PT0;
     vector<float> ETA3;
     vector<float> ETA2;
     vector<float> ETA1;
     vector<float> ETA0;
     vector<float> MASS4L;
     vector<float> MASS4L_1;
     vector<float> P4L;
     vector<float> MASSZ1;
     vector<float> MASSZ1_1;
     vector<float> MASSZ2;
   
   
   
   
     GetEntry(jentry);

     int size = lep_pt->size();  
     
     /*for (Int_t jj = 0; jj < size; jj++) {
       cout <<lep_id->at(jj)<<endl;}*/

     if(size>3){     
     for (Int_t j = 0; j < size; j++) {       
       if(lep_id->at(j)==13 && abs(lep_eta->at(j))<2.4/* && lep_Sip->at(j)<4 && lep_d0PV->at(j)<0.005*/ ){
	 TLorentzVector lepton1;
	 lepton1.SetPtEtaPhiM(lep_pt->at(j),lep_eta->at(j),lep_phi->at(j),lep_mass->at(j));	 
	   for (Int_t i = 0; i < size; i++){
	     TLorentzVector lepton2;
	     lepton2.SetPtEtaPhiM(lep_pt->at(i),lep_eta->at(i),lep_phi->at(i),lep_mass->at(i));
	   float mll1 = (lepton1+lepton2).M();	   
	   if(lep_id->at(i)==-13 && abs(lep_eta->at(i))<2.4 && mll1 >12 && mll1<120/* && lep_Sip->at(i)<4 && lep_d0PV->at(i)<0.005*/){	     
	     for (Int_t k = j; k < size; k++) {	       
	       if(j!=k && lep_id->at(k)==13 && abs(lep_eta->at(k))<2.4/* && lep_Sip->at(k)<4 && lep_d0PV->at(k)<0.005*/){
		  TLorentzVector lepton3;
		  lepton3.SetPtEtaPhiM(lep_pt->at(k),lep_eta->at(k),lep_phi->at(k),lep_mass->at(k));		  
		  for (Int_t z = 0; z < size; z++){
		    
		    TLorentzVector lepton4;
		    lepton4.SetPtEtaPhiM(lep_pt->at(z),lep_eta->at(z),lep_phi->at(z),lep_mass->at(z));
		    float mll2 = (lepton3+lepton4).M();
		    if(i!=z && lep_id->at(z)==-13 && abs(lep_eta->at(z))<2.4 && mll2>12 && mll2<120/* && lep_Sip->at(z)<4 && lep_d0PV->at(z)<0.005*/){	      
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
			if(lep_Sip->at(j)<4 && lep_d0PV->at(j)<0.005  && lep_Sip->at(i)<4 && lep_d0PV->at(i)<0.005 && lep_Sip->at(k)<4 && lep_d0PV->at(k)<0.005 && lep_Sip->at(z)<4 && lep_d0PV->at(z)<0.005){
			  indicej_1.push_back(j);
			  indicei_1.push_back(i);
			  indicek_1.push_back(k);
			  indicez_1.push_back(z);
			  PT3_1.push_back(PT[3]);
			  MASS4L_1.push_back(mass4l);
			  MASSZ1_1.push_back(MassZ1);
			}}}}}}}}}}} //chiudo tutti i for e gli if sui leptoni
     int size2 = PT3.size();  
     int size3 = PT3_1.size();      
     if (size2 != 0){ntotevpass = ntotevpass +1;}
     if (size3 != 0){ntotevpass_1 = ntotevpass_1 +1;}
     for (Int_t q = 0; q < size3; q++) {
       for (Int_t e = q; e < size3; e++) {
	 if(indicej_1[q]==indicej_1[e] && indicek_1[q]==indicek_1[e] && indicei_1[q]==indicez_1[e] && indicei_1[q]==indicez_1[e]){
	   if(abs(MASSZ1_1[q]-91.2)<abs(MASSZ1_1[e]-91.2)){MASSZ1_1[e]=0;}
	   else{MASSZ1_1[q]=0;}}}
       if(MASSZ1_1[q]!=0){
	 ev_1 = ev_1 +1;	 
	 h_pt_3_1->Fill(PT3_1[q]);
	 h_4l_mass_1->Fill(MASS4L_1[q]);
	 h_Z1_mass_1->Fill(MASSZ1_1[q]); 
       }}
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
	 /*for(Int_t r = 0; r < cutsize; r++) {	   *
	   if (PT3[w]>cut_pt_first_muon[r] ) {
	     npass[r]=npass[r] + 1;	     
	     h_4l_m_pass[r]->Fill(MASS4L[w]);
	     }}*/
	 // cout <<"all'evento numero "<< jentry<<" partecipano i muoni " << j << "  "<< i<< "  " << k<< "  " << z << endl;
        }}
      
     
       h_candidates_1->Fill(ev_1);

     h_candidates->Fill(ev);}//chiudo il loop sugli eventi
   cout <<ntotev<<endl;
   cout <<ntotevpass<<endl;
   cout <<ntotevpass_1<<endl;
   cout << h_pt_3_1->GetEntries()<<endl;
  

   //Tefficency
   /* auto legend = new TLegend(0.53,0.4,0.85,0.7);  
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
   //h_pt_3_1->SetLineColor(3);
   h_pt_3->GetYaxis()->SetTitle("Events");
   h_pt_3->GetXaxis()->SetTitle("pt (Gev)");
   h_pt_3->GetXaxis()->CenterTitle();
   h_pt_3->Draw();
   h_pt_3_1->Draw("same");
   auto legend1 = new TLegend(0.6,0.3,0.85,0.65); 
   legend1->AddEntry(h_pt_3,"first cuts list","l");
   legend1->AddEntry(h_pt_3_1,"second cuts list","l");
   legend1->Draw();
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
   h_4l_mass_1->Draw("same");
   auto legend2 = new TLegend(0.6,0.45,0.85,0.65); 
   legend2->AddEntry(h_4l_mass,"first cuts list","l");
   legend2->AddEntry(h_4l_mass_1,"second cuts list","l");
   legend2->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Clear();
   //massa delle Z0
   MyC->cd(); 
   h_Z1_mass->SetLineColor(2);
   h_Z1_mass->GetYaxis()->SetTitle("Events");
   h_Z1_mass->GetXaxis()->SetTitle("mass of Z1 (Gev)");
   h_Z1_mass->GetXaxis()->CenterTitle();
   h_Z1_mass->Draw();
   h_Z1_mass_1->Draw("same");
   auto legend3 = new TLegend(0.2,0.6,0.6,0.85); 
   legend3->AddEntry(h_Z1_mass,"first cuts list","l");
   legend3->AddEntry(h_Z1_mass_1,"second cuts list","l");
   legend3->Draw();
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
   h_candidates->Draw(); 
   h_candidates_1->Draw("same");
   auto legend4 = new TLegend(0.45,0.6,0.7,0.85); 
   legend4->AddEntry(h_candidates,"first cuts list","l");
   legend4->AddEntry(h_candidates_1,"second cuts list","l");
   legend4->Draw();
   MyC->Print("./Plots/Higgs/plots.pdf");
   MyC->Print("./Plots/Higgs/plots.pdf]");
   MyC->Clear();
}//chiudo tutti i loop	
