#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <math.h>
int DIM =20+10+8;//number of variables


  
 



void listsigTH1(TFile* f1, TFile* f2, float S, TH1F  *list[DIM], const int size1, const int size2) {
      TH1F* h_num_eventi;
      float num_event;
      h_num_eventi = (TH1F*) f2->Get("sumWeights");
      num_event = h_num_eventi->Integral();      
      float lum = 59;
      TH1F* h_NVPH;
      h_NVPH = (TH1F*) f1->Get("h_NVPH");
      h_NVPH->Scale(S*lum/num_event);
      TH1F* h_TLWM;
      h_TLWM = (TH1F*) f1->Get("h_TLWM");
      h_TLWM->Scale(S*lum/num_event);
      TH1F* h_C2LP;
      h_C2LP = (TH1F*) f1->Get("h_C2LP");
      h_C2LP->Scale(S*lum/num_event);
      TH1F* h_KINK;
      h_KINK = (TH1F*) f1->Get("h_KINK");
      h_KINK->Scale(S*lum/num_event);
      TH1F* h_NOMS;
      h_NOMS = (TH1F*) f1->Get("h_NOMS");
      h_NOMS->Scale(S*lum/num_event);
      TH1F* h_VAFR;
      h_VAFR = (TH1F*) f1->Get("h_VAFR");
      h_VAFR->Scale(S*lum/num_event);
      TH1F* h_NOC2;
      h_NOC2 = (TH1F*) f1->Get("h_NOC2");
      h_NOC2->Scale(S*lum/num_event);
      TH1F* h_NVMH;
      h_NVMH = (TH1F*) f1->Get("h_NVMH");
      h_NVMH->Scale(S*lum/num_event);
      //////////
      TH1F* h_NVPH_0;
      h_NVPH_0 = (TH1F*) f1->Get("h_NVPH_0");
      h_NVPH_0->Scale(S*lum/num_event);
      TH1F* h_TLWM_0;
      h_TLWM_0 = (TH1F*) f1->Get("h_TLWM_0");
      h_TLWM_0->Scale(S*lum/num_event);
      TH1F* h_C2LP_0;
      h_C2LP_0 = (TH1F*) f1->Get("h_C2LP_0");
      h_C2LP_0->Scale(S*lum/num_event);
      TH1F* h_KINK_0;
      h_KINK_0 = (TH1F*) f1->Get("h_KINK_0");
      h_KINK_0->Scale(S*lum/num_event);
      TH1F* h_NOMS_0;
      h_NOMS_0 = (TH1F*) f1->Get("h_NOMS_0");
      h_NOMS_0->Scale(S*lum/num_event);
      TH1F* h_VAFR_0;
      h_VAFR_0 = (TH1F*) f1->Get("h_VAFR_0");
      h_VAFR_0->Scale(S*lum/num_event);
      TH1F* h_NOC2_0;
      h_NOC2_0 = (TH1F*) f1->Get("h_NOC2_0");
      h_NOC2_0->Scale(S*lum/num_event);
      TH1F* h_NVMH_0;
      h_NVMH_0 = (TH1F*) f1->Get("h_NVMH_0");
      h_NVMH_0->Scale(S*lum/num_event);
      /////////
      TH1F* h_PT_0;
      h_PT_0 = (TH1F*) f1->Get("h_pt_0");
      h_PT_0->Scale(S*lum/num_event);
      TH1F* h_PT_1;
      h_PT_1 = (TH1F*) f1->Get("h_pt_1");
      h_PT_1->Scale(S*lum/num_event);
      TH1F* h_PT_2;
      h_PT_2 = (TH1F*) f1->Get("h_pt_2");
      h_PT_2->Scale(S*lum/num_event);
      TH1F* h_PT_3;
      h_PT_3 = (TH1F*) f1->Get("h_pt_3");
      h_PT_3->Scale(S*lum/num_event);
      //////////
      int i;
      for(i=0;i<size1+size2;i++){
	string nomestringa;
	if(i<size1){nomestringa = "h_NVPH_pt0_pass_"+std::to_string(i);}
	else{ nomestringa = "h_NVPH_VAFR0_pass_"+std::to_string(i-size1);}
	//std::cout <<nomestringa<< std::endl;
	const char * nome{nomestringa.c_str()};
	
	TH1F* h_pass;
	h_pass = (TH1F*) f1->Get(nome);
	h_pass->Scale(S*lum/num_event);
	h_pass->SetFillColor(2);
	h_pass->SetLineColor(2);
	h_pass->SetFillStyle(3335);
	list[19+1+i]= h_pass;
      }
         
      h_NVPH_0->SetFillColor(2);
      h_NVPH_0->SetLineColor(2);
      h_TLWM_0->SetFillColor(2);
      h_TLWM_0->SetLineColor(2);
      h_C2LP_0->SetFillColor(2);
      h_C2LP_0->SetLineColor(2);
      h_KINK_0->SetFillColor(2);
      h_KINK_0->SetLineColor(2);
      h_NOMS_0->SetFillColor(2);
      h_NOMS_0->SetLineColor(2);
      h_VAFR_0->SetFillColor(2);
      h_VAFR_0->SetLineColor(2);
      h_NOC2_0->SetFillColor(2);
      h_NOC2_0->SetLineColor(2);
      h_NVMH_0->SetFillColor(2);
      h_NVMH_0->SetLineColor(2);
      h_NVPH_0->SetFillStyle(3335);
      h_TLWM_0->SetFillStyle(3335);
      h_C2LP_0->SetFillStyle(3335);
      h_KINK_0->SetFillStyle(3335);
      h_NOMS_0->SetFillStyle(3335);
      h_VAFR_0->SetFillStyle(3335);
      h_NOC2_0->SetFillStyle(3335);
      h_NVMH_0->SetFillStyle(3335);
      /////////////
      h_NVPH->SetFillColor(2);
      h_NVPH->SetLineColor(2);
      h_TLWM->SetFillColor(2);
      h_TLWM->SetLineColor(2);
      h_C2LP->SetFillColor(2);
      h_C2LP->SetLineColor(2);
      h_KINK->SetFillColor(2);
      h_KINK->SetLineColor(2);
      h_NOMS->SetFillColor(2);
      h_NOMS->SetLineColor(2);
      h_VAFR->SetFillColor(2);
      h_VAFR->SetLineColor(2);
      h_NOC2->SetFillColor(2);
      h_NOC2->SetLineColor(2);
      h_NVMH->SetFillColor(2);
      h_NVMH->SetLineColor(2);
      h_NVPH->SetFillStyle(3335);
      h_TLWM->SetFillStyle(3335);
      h_C2LP->SetFillStyle(3335);
      h_KINK->SetFillStyle(3335);
      h_NOMS->SetFillStyle(3335);
      h_VAFR->SetFillStyle(3335);
      h_NOC2->SetFillStyle(3335);
      h_NVMH->SetFillStyle(3335);
      //////////
      h_PT_3->SetFillColor(2);
      h_PT_3->SetLineColor(2);
      h_PT_3->SetFillStyle(3335);
      h_PT_2->SetFillColor(2);
      h_PT_2->SetLineColor(2);
      h_PT_2->SetFillStyle(3335);
      h_PT_1->SetFillColor(2);
      h_PT_1->SetLineColor(2);
      h_PT_1->SetFillStyle(3335);
      h_PT_0->SetFillColor(2);
      h_PT_0->SetLineColor(2);
      h_PT_0->SetFillStyle(3335);
      


      list[0]= h_NVPH;
      list[1]= h_TLWM;
      list[2]= h_C2LP;
      list[3]= h_KINK;
      list[4]= h_NOMS;
      list[5]= h_VAFR;
      list[6]= h_NOC2;
      list[7]= h_NVMH;
      list[8]= h_NVPH_0;
      list[9]= h_TLWM_0;
      list[10]= h_C2LP_0;
      list[11]= h_KINK_0;
      list[12]= h_NOMS_0;
      list[13]= h_VAFR_0;
      list[14]= h_NOC2_0;
      list[15]= h_NVMH_0; 
      list[16]= h_PT_0; 
      list[17]= h_PT_1; 
      list[18]= h_PT_2; 
      list[19]= h_PT_3; 
   
}

void listTH1(TFile* f1, TFile* f2, float S, TH1F  *list[DIM] , const int size1, const int size2) {
      TH1F* h_num_eventi;
      float num_event;
      h_num_eventi = (TH1F*) f2->Get("sumWeights");
      num_event = h_num_eventi->Integral();      
      float lum = 59;
      TH1F* h_NVPH;
      h_NVPH = (TH1F*) f1->Get("h_NVPH");
      h_NVPH->Scale(S*lum/num_event);
      TH1F* h_TLWM;
      h_TLWM = (TH1F*) f1->Get("h_TLWM");
      h_TLWM->Scale(S*lum/num_event);
      TH1F* h_C2LP;
      h_C2LP = (TH1F*) f1->Get("h_C2LP");
      h_C2LP->Scale(S*lum/num_event);
      TH1F* h_KINK;
      h_KINK = (TH1F*) f1->Get("h_KINK");
      h_KINK->Scale(S*lum/num_event);
      TH1F* h_NOMS;
      h_NOMS = (TH1F*) f1->Get("h_NOMS");
      h_NOMS->Scale(S*lum/num_event);
      TH1F* h_VAFR;
      h_VAFR = (TH1F*) f1->Get("h_VAFR");
      h_VAFR->Scale(S*lum/num_event);
      TH1F* h_NOC2;
      h_NOC2 = (TH1F*) f1->Get("h_NOC2");
      h_NOC2->Scale(S*lum/num_event);
      TH1F* h_NVMH;
      h_NVMH = (TH1F*) f1->Get("h_NVMH");
      h_NVMH->Scale(S*lum/num_event);
      //////////
      TH1F* h_NVPH_0;
      h_NVPH_0 = (TH1F*) f1->Get("h_NVPH_0");
      h_NVPH_0->Scale(S*lum/num_event);
      TH1F* h_TLWM_0;
      h_TLWM_0 = (TH1F*) f1->Get("h_TLWM_0");
      h_TLWM_0->Scale(S*lum/num_event);
      TH1F* h_C2LP_0;
      h_C2LP_0 = (TH1F*) f1->Get("h_C2LP_0");
      h_C2LP_0->Scale(S*lum/num_event);
      TH1F* h_KINK_0;
      h_KINK_0 = (TH1F*) f1->Get("h_KINK_0");
      h_KINK_0->Scale(S*lum/num_event);
      TH1F* h_NOMS_0;
      h_NOMS_0 = (TH1F*) f1->Get("h_NOMS_0");
      h_NOMS_0->Scale(S*lum/num_event);
      TH1F* h_VAFR_0;
      h_VAFR_0 = (TH1F*) f1->Get("h_VAFR_0");
      h_VAFR_0->Scale(S*lum/num_event);
      TH1F* h_NOC2_0;
      h_NOC2_0 = (TH1F*) f1->Get("h_NOC2_0");
      h_NOC2_0->Scale(S*lum/num_event);
      TH1F* h_NVMH_0;
      h_NVMH_0 = (TH1F*) f1->Get("h_NVMH_0");
      h_NVMH_0->Scale(S*lum/num_event);
      /////////
      TH1F* h_PT_0;
      h_PT_0 = (TH1F*) f1->Get("h_pt_0");
      h_PT_0->Scale(S*lum/num_event);
      TH1F* h_PT_1;
      h_PT_1 = (TH1F*) f1->Get("h_pt_1");
      h_PT_1->Scale(S*lum/num_event);
      TH1F* h_PT_2;
      h_PT_2 = (TH1F*) f1->Get("h_pt_2");
      h_PT_2->Scale(S*lum/num_event);
      TH1F* h_PT_3;
      h_PT_3 = (TH1F*) f1->Get("h_pt_3");
      h_PT_3->Scale(S*lum/num_event);
      int i;
      for(i=0;i<size1+size2;i++){
	string nomestringa;
	if(i<size1){nomestringa = "h_NVPH_pt0_pass_"+std::to_string(i);}
	else{ nomestringa = "h_NVPH_VAFR0_pass_"+std::to_string(i-size1);}
	//std::cout <<nomestringa<< std::endl;
	const char * nome{nomestringa.c_str()};
	
	TH1F* h_pass;
	h_pass = (TH1F*) f1->Get(nome);
	h_pass->Scale(S*lum/num_event);
	h_pass->SetFillColor(4);
	h_pass->SetLineColor(4);
	h_pass->SetFillStyle(3354);
	list[19+1+i]= h_pass;
      }
         
      h_NVPH_0->SetFillColor(4);
      h_NVPH_0->SetLineColor(4);
      h_TLWM_0->SetFillColor(4);
      h_TLWM_0->SetLineColor(4);
      h_C2LP_0->SetFillColor(4);
      h_C2LP_0->SetLineColor(4);
      h_KINK_0->SetFillColor(4);
      h_KINK_0->SetLineColor(4);
      h_NOMS_0->SetFillColor(4);
      h_NOMS_0->SetLineColor(4);
      h_VAFR_0->SetFillColor(4);
      h_VAFR_0->SetLineColor(4);
      h_NOC2_0->SetFillColor(4);
      h_NOC2_0->SetLineColor(4);
      h_NVMH_0->SetFillColor(4);
      h_NVMH_0->SetLineColor(4);
      h_NVPH_0->SetFillStyle(3354);
      h_TLWM_0->SetFillStyle(3354);
      h_C2LP_0->SetFillStyle(3354);
      h_KINK_0->SetFillStyle(3354);
      h_NOMS_0->SetFillStyle(3354);
      h_VAFR_0->SetFillStyle(3354);
      h_NOC2_0->SetFillStyle(3354);
      h_NVMH_0->SetFillStyle(3354);
      /////////////
      h_NVPH->SetFillColor(4);
      h_NVPH->SetLineColor(4);
      h_TLWM->SetFillColor(4);
      h_TLWM->SetLineColor(4);
      h_C2LP->SetFillColor(4);
      h_C2LP->SetLineColor(4);
      h_KINK->SetFillColor(4);
      h_KINK->SetLineColor(4);
      h_NOMS->SetFillColor(4);
      h_NOMS->SetLineColor(4);
      h_VAFR->SetFillColor(4);
      h_VAFR->SetLineColor(4);
      h_NOC2->SetFillColor(4);
      h_NOC2->SetLineColor(4);
      h_NVMH->SetFillColor(4);
      h_NVMH->SetLineColor(4);
      h_NVPH->SetFillStyle(3354);
      h_TLWM->SetFillStyle(3354);
      h_C2LP->SetFillStyle(3354);
      h_KINK->SetFillStyle(3354);
      h_NOMS->SetFillStyle(3354);
      h_VAFR->SetFillStyle(3354);
      h_NOC2->SetFillStyle(3354);
      h_NVMH->SetFillStyle(3354);
      //////////
      h_PT_3->SetFillColor(4);
      h_PT_3->SetLineColor(4);
      h_PT_3->SetFillStyle(3354);
      h_PT_2->SetFillColor(4);
      h_PT_2->SetLineColor(4);
      h_PT_2->SetFillStyle(3354);
      h_PT_1->SetFillColor(4);
      h_PT_1->SetLineColor(4);
      h_PT_1->SetFillStyle(3354);
      h_PT_0->SetFillColor(4);
      h_PT_0->SetLineColor(4);
      h_PT_0->SetFillStyle(3354);

      list[0]= h_NVPH;
      list[1]= h_TLWM;
      list[2]= h_C2LP;
      list[3]= h_KINK;
      list[4]= h_NOMS;
      list[5]= h_VAFR;
      list[6]= h_NOC2;
      list[7]= h_NVMH;
      list[8]= h_NVPH_0;
      list[9]= h_TLWM_0;
      list[10]= h_C2LP_0;
      list[11]= h_KINK_0;
      list[12]= h_NOMS_0;
      list[13]= h_VAFR_0;
      list[14]= h_NOC2_0;
      list[15]= h_NVMH_0; 
      list[16]= h_PT_0; 
      list[17]= h_PT_1; 
      list[18]= h_PT_2; 
      list[19]= h_PT_3; 
   
}
void prova(){ 
  gStyle->SetOptStat(0000);  
  vector<float> cut_pt_last_muon;      
  vector<float> cut_VAFR_last_muon;
  cut_pt_last_muon.push_back(15);
  cut_pt_last_muon.push_back(20);
  cut_pt_last_muon.push_back(25);
  cut_pt_last_muon.push_back(35);
  cut_pt_last_muon.push_back(45);
  cut_pt_last_muon.push_back(55);
  cut_pt_last_muon.push_back(65);
  cut_pt_last_muon.push_back(75);
  cut_pt_last_muon.push_back(80);
  cut_pt_last_muon.push_back(85);
  cut_VAFR_last_muon.push_back(0.4);
  cut_VAFR_last_muon.push_back(0.5);
  cut_VAFR_last_muon.push_back(0.6);
  cut_VAFR_last_muon.push_back(0.7);  
  cut_VAFR_last_muon.push_back(0.8); 
  cut_VAFR_last_muon.push_back(0.85); 
  cut_VAFR_last_muon.push_back(0.9); 
  cut_VAFR_last_muon.push_back(0.95);
  const int cutsize2 = cut_VAFR_last_muon.size();
  const int cutsize1 = cut_pt_last_muon.size();
  TFile* f1 = TFile::Open("./signalggHZZ.root","read");
  TFile* f1_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluHToZZTo4L_M125_2018_skimmed_DONATO.root","read");
  float s1 = 0.01218; 
  TH1F *list_sig[DIM];
  listsigTH1( f1, f1_1, s1, list_sig, cutsize1, cutsize2);
  //list_sig[1]->Draw();
  TFile* f2 = TFile::Open("./bkg2e2mu.root","read");
  TFile* f2_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo2e2mu_M125_2018_skimmed_DONATO.root","read");
  float s2 = 0.00319; 
  TH1F *list_2e2mu[DIM];
  listTH1( f2, f2_1, s2, list_2e2mu, cutsize1, cutsize2);
  TFile* f3 = TFile::Open("./bkg2e2tau.root","read");
  TFile* f3_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo2e2tau_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_2e2tau[DIM];
  listTH1( f3, f3_1, s2, list_2e2tau, cutsize1, cutsize2);
  TFile* f4 = TFile::Open("./bkg2mu2tau.root","read");
  TFile* f4_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo2mu2tau_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_2mu2tau[DIM];
  listTH1( f4, f4_1, s2, list_2mu2tau, cutsize1, cutsize2);
  TFile* f5 = TFile::Open("./bkg4e.root","read");
  TFile* f5_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo4e_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_4e[DIM];
  float s3 = 0.00159;
  listTH1( f5, f5_1, s3, list_4e, cutsize1, cutsize2);
  //list_2mu2tau[14]->Draw();
  TFile* f6 = TFile::Open("./bkg4mu.root","read");
  TFile* f6_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo4mu_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_4mu[DIM];
  listTH1( f6, f6_1, s3, list_4mu, cutsize1, cutsize2);
  TFile* f7 = TFile::Open("./bkg4tau.root","read");
  TFile* f7_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/GluGluToContinToZZTo4tau_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_4tau[DIM];
  listTH1( f7, f7_1, s3, list_4tau, cutsize1, cutsize2);
  TFile* f8 = TFile::Open("./bkgDYjets.root","read");
  TFile* f8_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/DYJetsToLL_M-50_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_DY[DIM];
  float s4 = 6104;
  listTH1( f8, f8_1, s4, list_DY, cutsize1, cutsize2);
  TFile* f9 = TFile::Open("./tt2l2nu.root","read");
  TFile* f9_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/TTTo2L2Nu_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_tt[DIM];
  float s5 = 87.31;
  listTH1( f9, f9_1, s5, list_tt, cutsize1, cutsize2);
  TFile* f10 = TFile::Open("./bkgZW.root","read");
  TFile* f10_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/WZTo3LNu_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_WZ[DIM];
  float s6 = 4.430;
  listTH1( f10, f10_1, s6, list_WZ, cutsize1, cutsize2);
  TFile* f11 = TFile::Open("./bkgqqZZ4l.root","read");
  TFile* f11_1 = TFile::Open("/eos/user/d/dtroiano/entupleserHZZ1/ZZTo4L_M125_2018_skimmed_DONATO.root","read");
  TH1F *list_ZZ[DIM];
  float s7 = 1.212;
  listTH1( f11, f11_1, s7, list_ZZ, cutsize1, cutsize2);
  vector<string> sources;
  sources.push_back("list_2e2mu");
  sources.push_back("list_2e2tau");
  sources.push_back("list_2mu2tau");
  sources.push_back("list_4e");
  sources.push_back("list_4mu");
  sources.push_back("list_4tau");
  sources.push_back("list_DY");
  sources.push_back("list_tt");
  sources.push_back("list_WZ");
  sources.push_back("list_ZZ");  
  int nsources = sources.size();
  cout << nsources<<endl;
  TH1F *th1_list[nsources][DIM];
  int k;
  for(k=0;k<DIM;k++){//for on the variables
    th1_list[0][k]= list_2e2mu[k];
    th1_list[1][k]= list_2e2tau[k];
    th1_list[2][k]= list_2mu2tau[k];
    th1_list[3][k]= list_4e[k];
    th1_list[4][k]= list_4mu[k];
    th1_list[5][k]= list_4tau[k];
    th1_list[6][k]= list_DY[k];
    th1_list[7][k]= list_tt[k];
    th1_list[8][k]= list_WZ[k];
    th1_list[9][k]= list_ZZ[k];
  }//close the for on the variables
  //th1_list[4][14]->Draw();
  
  
  THStack *hs_BKG[DIM];  
  int j,i;
  for(j=0;j<DIM;j++){//for on the variables
     hs_BKG[j]= new THStack();
    for(i=0;i<nsources;i++){//for on the sources
      hs_BKG[j]->Add(th1_list[i][j]);      
    }//close the for on the sources
    hs_BKG[j]->SetMinimum(1);
    std::string s{th1_list[i][j]->GetTitle()};
    std::string nomestringa{"signal vs bkg; "+ s + "; Events"};
    //std::cout <<nomestringa<< std::endl;
    const char * nome{nomestringa.c_str()};
    hs_BKG[j]->SetTitle(nome);
    }//close the for on the variables


  //renormalization of the signal
  /* int z;
  for(z=0;z<DIM;z++){
    float areasig= list_sig[z]->Integral();
    cout<<"area del segnale "<<z<< " = "<< areasig<<endl;
    TH1F *last = (TH1F*)hs_BKG[z]->GetStack()->Last();
    //float areabkg= hs_ggZZ[z]->Integral();
    float areabkg= last->Integral();
    cout<<"area del fondo "<<z<< " = "<< areabkg<<endl;
    list_sig[z]->Scale(areabkg/areasig);
    }*/

  auto legend = new TLegend(0.5,0.8,0.8,0.9);
  legend->AddEntry(list_sig[1],"signal","f");
  legend->AddEntry(th1_list[0][0],"background","f");

  //efficiency
  //without cuts
  TH1F *last3 = (TH1F*)hs_BKG[0]->GetStack()->Last();
  cout<<list_sig[0]->Integral()/sqrt(last3->Integral())<<endl;
  ///
  Float_t eff1[cutsize1]; 
  Float_t eff2[cutsize2]; 
  Float_t zeros1[cutsize1]; 
  Float_t zeros2[cutsize2];
  Float_t eff1_er[cutsize1]; 
  Float_t eff2_er[cutsize2]; 
  Float_t cut_pt[cutsize1]; 
  Float_t cut_VAFR[cutsize2];
  int p;
  for(p=0;p<cutsize1 + cutsize2;p++){ 
    Float_t Sig = list_sig[19+1+p]->Integral();
    TH1F *last2 = (TH1F*)hs_BKG[19 + 1 + p]->GetStack()->Last();
    Float_t Bkg = last2->Integral();
    Float_t ratio = Sig/sqrt(Bkg);
    Float_t err= sqrt((Sig/Bkg)+0.25*(Sig/Bkg)*(Sig/Bkg));
    if(p<cutsize1){
    eff1[p] = ratio;
    eff1_er[p] = err;
    zeros1[p] = 0;
    cut_pt[p] = cut_pt_last_muon[p];
    //cout<<eff1[p]<<endl;
    //cout<<eff1_er[p]<<endl;
}
    else{
      eff2[p-cutsize1] = ratio;
      eff2_er[p-cutsize1] = err;
      zeros2[p-cutsize1] = 0;
      cut_VAFR[p-cutsize1] = cut_VAFR_last_muon[p-cutsize1];
      //cout<<eff2[p-cutsize1]<<endl;
      //cout<<eff2_er[p-cutsize1]<<endl;
}
  }    
    
  TGraphErrors *gr1 = new TGraphErrors(cutsize1, cut_pt, eff1, zeros1, eff1_er);
  TGraphErrors *gr2 = new TGraphErrors(cutsize2, cut_VAFR, eff2, zeros2, eff2_er);
  //plot on the cut on the pt on the last muon  
  TCanvas *MyC1 = new TCanvas("myC1","Plot 1", 1000,800); 
  gr1->SetMarkerColor(2);
  gr1->SetMarkerStyle(21);
  gr1->SetMarkerSize(1);
  gr1->SetTitle("upper limit on the last muon");  
  gr1->GetXaxis()->SetTitle("p_{t} (GeV)");
  gr1->GetYaxis()->SetTitle("S/#sqrt{B}");
  MyC1->cd();
  //MyC1->SetLogy();  gr1->SetMaximum(-0.01); gr1->SetMinimum(-1);
  gr1->Draw("AP");
  //plot on the cut on the pt on the last muon  
  TCanvas *MyC2 = new TCanvas("myC2","Plot 2", 1000,800);   
  gr2->SetMarkerColor(2);
  gr2->SetMarkerStyle(21);
  gr2->SetMarkerSize(1);
  gr2->SetTitle("lower limit on the last muon");
  gr2->GetXaxis()->SetTitle("valid fraction");
  gr2->GetYaxis()->SetTitle("S/#sqrt{B}");
  MyC2->cd();
  //MyC2->SetLogy(); gr2->SetMaximum(-0.01); gr2->SetMinimum(-1);
  gr2->Draw("AP");
  
  






  //hs_ggZZ[13]->Draw("hist");
  //TCanvas
    
  /* TCanvas *MyC = new TCanvas("myC","Plot", 1000,800); 
  int y;
  for(y=0;y<DIM;y++){
    MyC->Clear();
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0);
    pad1->SetLogy();
    pad1->Draw();
    pad1->cd();
    hs_BKG[y]->SetMaximum(10);
    hs_BKG[y]->SetMinimum(0.000001);
    hs_BKG[y]->Draw("hist");
    list_sig[y]->Draw("histsame");
    legend->Draw();
    MyC->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->Draw();
    pad2->cd();
    TH1F *last1 = (TH1F*)hs_BKG[y]->GetStack()->Last();
    // Define the ratio plot
    TH1F *h3 = (TH1F*)list_sig[y]->Clone("h3");
    h3->SetLineColor(kBlack);
    h3->SetMinimum(0.0);  // Define Y ..
    h3->SetMaximum(3); // .. range
    //h3->Sumw2();
    h3->SetStats(0);      // No statistics on lower plot
    h3->Divide(last1);
    h3->SetMarkerStyle(21);
    h3->Draw("ep"); 
    float xmin= last1->FindFirstBinAbove();
    float xmax= last1->FindLastBinAbove();
    TLine *line=new TLine(xmin,1.,xmax,1.);    
    line->SetLineColor(2);
    line->Draw("same");
    h3->SetTitle("");
    
    // Y axis ratio plot settings
    h3->GetYaxis()->SetTitle("ratio signal/background ");
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(15);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings
    const char * title{list_sig[y]->GetTitle()};
    h3->GetXaxis()->SetTitle(title);
    h3->GetXaxis()->CenterTitle();
    h3->GetXaxis()->SetTitleSize(20);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(4.);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
    if(y==0){MyC->Print("./histos.pdf[");}
    MyC->Print("./histos.pdf");
    if(y==DIM-1){MyC->Print("./histos.pdf]");}
  }//close the canvas
  */
  
    


}//close the main
