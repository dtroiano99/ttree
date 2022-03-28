#ifndef MyClass_h
#define MyClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "string"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class MyClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxjet_csvv2 = 1;

   // Declaration of leaf types
   ULong64_t       Run;
   ULong64_t       Event;
   ULong64_t       LumiSect;
   Int_t           nVtx;
   Int_t           nInt;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         BS_x;
   Float_t         BS_y;
   Float_t         BS_z;
   Float_t         BS_xErr;
   Float_t         BS_yErr;
   Float_t         BS_zErr;
   Float_t         BeamWidth_x;
   Float_t         BeamWidth_y;
   Float_t         BeamWidth_xErr;
   Float_t         BeamWidth_yErr;
   Int_t           finalState;
   string          *triggersPassed;
   Bool_t          passedTrig;
   Bool_t          passedFullSelection;
   Bool_t          passedZ4lSelection;
   Bool_t          passedQCDcut;
   Bool_t          passedZ1LSelection;
   Bool_t          passedZ4lZ1LSelection;
   Bool_t          passedZ4lZXCRSelection;
   Bool_t          passedZXCRSelection;
   Int_t           nZXCRFailedLeptons;
   Float_t         genWeight;
   Float_t         k_ggZZ;
   Float_t         k_qqZZ_qcd_dPhi;
   Float_t         k_qqZZ_qcd_M;
   Float_t         k_qqZZ_qcd_Pt;
   Float_t         k_qqZZ_ewk;
   vector<float>   *qcdWeights;
   vector<float>   *nnloWeights;
   vector<float>   *pdfWeights;
   Float_t         pdfRMSup;
   Float_t         pdfRMSdown;
   Float_t         pdfENVup;
   Float_t         pdfENVdown;
   Float_t         pileupWeight;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDn;
   Float_t         dataMCWeight;
   Float_t         eventWeight;
   Float_t         prefiringWeight;
   Float_t         crossSection;
   vector<float>   *lep_d0BS;
   vector<float>   *lep_d0PV;
   vector<float>   *lep_numberOfValidPixelHits;
   vector<float>   *lep_trackerLayersWithMeasurement;
   vector<float>   *lep_chi2LocalPosition;
   vector<float>   *lep_trkKink;
   vector<float>   *lep_numberOfMatchedStations;
   vector<float>   *lep_validFraction;
   vector<float>   *lep_arbitrationType;
   vector<float>   *lep_normalizedChi2;
   vector<float>   *lep_numberOfValidMuonHits;
   vector<float>   *lep_p;
   vector<float>   *lep_ecalEnergy;
   vector<int>     *lep_isEB;
   vector<int>     *lep_isEE;
   vector<double>  *singleBS_Lep_pt;
   vector<double>  *singleBS_Lep_ptError;
   vector<double>  *singleBS_Lep_eta;
   vector<double>  *singleBS_Lep_phi;
   vector<double>  *singleBS_Lep_mass;
   vector<double>  *singleBS_Lep_d0;
   vector<double>  *vtxLep_BS_pt;
   vector<double>  *vtxLep_BS_pt_NoRoch;
   vector<double>  *vtxLep_BS_ptError;
   vector<double>  *vtxLep_BS_eta;
   vector<double>  *vtxLep_BS_phi;
   vector<double>  *vtxLep_BS_mass;
   vector<double>  *vtxLep_BS_d0;
   vector<double>  *vtxLep_pt;
   vector<double>  *vtxLep_ptError;
   vector<double>  *vtxLep_eta;
   vector<double>  *vtxLep_phi;
   vector<double>  *vtxLep_mass;
   vector<double>  *singleBS_FSR_Lep_pt;
   vector<double>  *singleBS_FSR_Lep_eta;
   vector<double>  *singleBS_FSR_Lep_phi;
   vector<double>  *singleBS_FSR_Lep_mass;
   vector<double>  *vtxLepFSR_BS_pt;
   vector<double>  *vtxLepFSR_BS_eta;
   vector<double>  *vtxLepFSR_BS_phi;
   vector<double>  *vtxLepFSR_BS_mass;
   vector<double>  *vtxLepFSR_pt;
   vector<double>  *vtxLepFSR_eta;
   vector<double>  *vtxLepFSR_phi;
   vector<double>  *vtxLepFSR_mass;
   vector<float>   *singleBS_RecoLep_pt;
   vector<float>   *singleBS_RecoLep_ptError;
   vector<float>   *singleBS_RecoLep_eta;
   vector<float>   *singleBS_RecoLep_phi;
   vector<float>   *singleBS_RecoLep_mass;
   vector<float>   *singleBS_RecoLep_d0;
   vector<float>   *vtxRecoLep_BS_pt;
   vector<float>   *vtxRecoLep_BS_ptError;
   vector<float>   *vtxRecoLep_BS_eta;
   vector<float>   *vtxRecoLep_BS_phi;
   vector<float>   *vtxRecoLep_BS_mass;
   vector<float>   *vtxRecoLep_BS_d0;
   vector<float>   *vtxRecoLep_pt;
   vector<float>   *vtxRecoLep_ptError;
   vector<float>   *vtxRecoLep_eta;
   vector<float>   *vtxRecoLep_phi;
   vector<float>   *vtxRecoLep_mass;
   vector<double>  *commonPV_x;
   vector<double>  *commonPV_y;
   vector<double>  *commonPV_z;
   vector<double>  *commonBS_x;
   vector<double>  *commonBS_y;
   vector<double>  *commonBS_z;
   vector<double>  *lep_pt_UnS;
   vector<double>  *lep_pterrold_UnS;
   vector<float>   *lep_errPre_Scale;
   vector<float>   *lep_errPost_Scale;
   vector<float>   *lep_errPre_noScale;
   vector<float>   *lep_errPost_noScale;
   vector<float>   *lep_pt_FromMuonBestTrack;
   vector<float>   *lep_eta_FromMuonBestTrack;
   vector<float>   *lep_phi_FromMuonBestTrack;
   vector<float>   *lep_position_x;
   vector<float>   *lep_position_y;
   vector<float>   *lep_position_z;
   vector<float>   *lep_pt_genFromReco;
   vector<int>     *lep_id;
   vector<float>   *lep_pt;
   vector<float>   *lep_pterr;
   vector<float>   *lep_pterrold;
   vector<float>   *lep_eta;
   vector<float>   *lep_phi;
   vector<float>   *lep_mass;
   vector<float>   *lepFSR_pt;
   vector<float>   *lepFSR_eta;
   vector<float>   *lepFSR_phi;
   vector<float>   *lepFSR_mass;
   Int_t           lep_Hindex[4];
   vector<int>     *lep_genindex;
   vector<int>     *lep_matchedR03_PdgId;
   vector<int>     *lep_matchedR03_MomId;
   vector<int>     *lep_matchedR03_MomMomId;
   vector<int>     *lep_missingHits;
   vector<float>   *lep_mva;
   vector<int>     *lep_ecalDriven;
   vector<int>     *lep_tightId;
   vector<int>     *lep_tightIdSUS;
   vector<int>     *lep_tightIdHiPt;
   vector<float>   *lep_Sip;
   vector<float>   *lep_IP;
   vector<float>   *lep_isoNH;
   vector<float>   *lep_isoCH;
   vector<float>   *lep_isoPhot;
   vector<float>   *lep_isoPU;
   vector<float>   *lep_isoPUcorr;
   vector<float>   *lep_RelIso;
   vector<float>   *lep_RelIsoNoFSR;
   vector<float>   *lep_MiniIso;
   vector<float>   *lep_ptRatio;
   vector<float>   *lep_ptRel;
   vector<string>  *lep_filtersMatched;
   vector<float>   *lep_dataMC;
   vector<float>   *lep_dataMCErr;
   vector<float>   *dataMC_VxBS;
   vector<float>   *dataMCErr_VxBS;
   Int_t           nisoleptons;
   Float_t         muRho;
   Float_t         elRho;
   Float_t         pTL1;
   Float_t         pTL2;
   Float_t         pTL3;
   Float_t         pTL4;
   Int_t           idL1;
   Int_t           idL2;
   Int_t           idL3;
   Int_t           idL4;
   Float_t         etaL1;
   Float_t         etaL2;
   Float_t         etaL3;
   Float_t         etaL4;
   Float_t         mL1;
   Float_t         mL2;
   Float_t         mL3;
   Float_t         mL4;
   Float_t         pTErrL1;
   Float_t         pTErrL2;
   Float_t         pTErrL3;
   Float_t         pTErrL4;
   Float_t         phiL1;
   Float_t         phiL2;
   Float_t         phiL3;
   Float_t         phiL4;
   Float_t         pTL1FSR;
   Float_t         pTL2FSR;
   Float_t         pTL3FSR;
   Float_t         pTL4FSR;
   Float_t         etaL1FSR;
   Float_t         etaL2FSR;
   Float_t         etaL3FSR;
   Float_t         etaL4FSR;
   Float_t         phiL1FSR;
   Float_t         phiL2FSR;
   Float_t         phiL3FSR;
   Float_t         phiL4FSR;
   Float_t         mL1FSR;
   Float_t         mL2FSR;
   Float_t         mL3FSR;
   Float_t         mL4FSR;
   Float_t         pTErrL1FSR;
   Float_t         pTErrL2FSR;
   Float_t         pTErrL3FSR;
   Float_t         pTErrL4FSR;
   vector<int>     *tau_id;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_mass;
   vector<float>   *pho_pt;
   vector<float>   *pho_eta;
   vector<float>   *pho_phi;
   vector<float>   *photonCutBasedIDLoose;
   vector<float>   *H_pt;
   vector<float>   *H_eta;
   vector<float>   *H_phi;
   vector<float>   *H_mass;
   vector<float>   *H_noFSR_pt;
   vector<float>   *H_noFSR_eta;
   vector<float>   *H_noFSR_phi;
   vector<float>   *H_noFSR_mass;
   Float_t         mass4l;
   Float_t         mass4l_noFSR;
   Float_t         mass4lErr;
   Float_t         mass4lREFIT;
   Float_t         mass4lErrREFIT;
   Float_t         massZ1REFIT;
   Float_t         massZ2REFIT;
   Float_t         mass4l_singleBS;
   Float_t         mass4l_singleBS_FSR;
   Float_t         mass4lErr_singleBS;
   Float_t         mass4lREFIT_singleBS;
   Float_t         mass4lErrREFIT_singleBS;
   Float_t         massZ1REFIT_singleBS;
   Float_t         massZ2REFIT_singleBS;
   Float_t         mass4l_vtx_BS;
   Float_t         mass4l_vtxFSR_BS;
   Float_t         mass4lErr_vtx_BS;
   Float_t         mass4lREFIT_vtx_BS;
   Float_t         mass4lErrREFIT_vtx_BS;
   Float_t         massZ1REFIT_vtx_BS;
   Float_t         massZ2REFIT_vtx_BS;
   Float_t         mass4l_vtx;
   Float_t         mass4l_vtxFSR;
   Float_t         mass4lErr_vtx;
   Float_t         mass4lREFIT_vtx;
   Float_t         mass4lErrREFIT_vtx;
   Float_t         mass4mu;
   Float_t         mass4e;
   Float_t         mass2e2mu;
   Float_t         pT4l;
   Float_t         eta4l;
   Float_t         phi4l;
   Float_t         rapidity4l;
   Float_t         cosTheta1;
   Float_t         cosTheta2;
   Float_t         cosThetaStar;
   Float_t         Phi;
   Float_t         Phi1;
   Float_t         mass3l;
   Float_t         massZ_vtx_chi2_BS;
   Float_t         massZ_vtx_chi2;
   Float_t         mass2l_vtx;
   Float_t         mass2l_vtx_BS;
   vector<float>   *Z_pt;
   vector<float>   *Z_eta;
   vector<float>   *Z_phi;
   vector<float>   *Z_mass;
   vector<float>   *Z_noFSR_pt;
   vector<float>   *Z_noFSR_eta;
   vector<float>   *Z_noFSR_phi;
   vector<float>   *Z_noFSR_mass;
   Int_t           Z_Hindex[2];
   Float_t         massZ1;
   Float_t         massErrH_vtx;
   Float_t         massH_vtx_chi2_BS;
   Float_t         massH_vtx_chi2;
   Float_t         massZ1_Z1L;
   Float_t         massZ2;
   Float_t         pTZ1;
   Float_t         pTZ2;
   Float_t         met;
   Float_t         met_phi;
   Float_t         met_jesup;
   Float_t         met_phi_jesup;
   Float_t         met_jesdn;
   Float_t         met_phi_jesdn;
   Float_t         met_uncenup;
   Float_t         met_phi_uncenup;
   Float_t         met_uncendn;
   Float_t         met_phi_uncendn;
   vector<int>     *jet_iscleanH4l;
   Int_t           jet1index;
   Int_t           jet2index;
   vector<float>   *jet_pt;
   vector<float>   *jet_pt_raw;
   vector<float>   *jet_relpterr;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_phierr;
   vector<float>   *jet_bTagEffi;
   vector<float>   *jet_cTagEffi;
   vector<float>   *jet_udsgTagEffi;
   vector<float>   *jet_mass;
   vector<int>     *jet_jesup_iscleanH4l;
   vector<float>   *jet_jesup_pt;
   vector<float>   *jet_jesup_eta;
   vector<float>   *jet_jesup_phi;
   vector<float>   *jet_jesup_mass;
   vector<int>     *jet_jesdn_iscleanH4l;
   vector<float>   *jet_jesdn_pt;
   vector<float>   *jet_jesdn_eta;
   vector<float>   *jet_jesdn_phi;
   vector<float>   *jet_jesdn_mass;
   vector<int>     *jet_jerup_iscleanH4l;
   vector<float>   *jet_jerup_pt;
   vector<float>   *jet_jerup_eta;
   vector<float>   *jet_jerup_phi;
   vector<float>   *jet_jerup_mass;
   vector<int>     *jet_jerdn_iscleanH4l;
   vector<float>   *jet_jerdn_pt;
   vector<float>   *jet_jerdn_eta;
   vector<float>   *jet_jerdn_phi;
   vector<float>   *jet_jerdn_mass;
   vector<float>   *jet_pumva;
   vector<float>   *jet_csvv2;
   vector<float>   *jet_csvv2_;
   vector<int>     *jet_isbtag;
   vector<int>     *jet_hadronFlavour;
   vector<int>     *jet_partonFlavour;
   vector<float>   *jet_QGTagger;
   vector<float>   *jet_QGTagger_jesup;
   vector<float>   *jet_QGTagger_jesdn;
   vector<float>   *jet_axis2;
   vector<float>   *jet_ptD;
   vector<int>     *jet_mult;
   Int_t           njets_pt30_eta4p7;
   Int_t           njets_pt30_eta4p7_jesup;
   Int_t           njets_pt30_eta4p7_jesdn;
   Int_t           njets_pt30_eta4p7_jerup;
   Int_t           njets_pt30_eta4p7_jerdn;
   Float_t         pt_leadingjet_pt30_eta4p7;
   Float_t         pt_leadingjet_pt30_eta4p7_jesup;
   Float_t         pt_leadingjet_pt30_eta4p7_jesdn;
   Float_t         pt_leadingjet_pt30_eta4p7_jerup;
   Float_t         pt_leadingjet_pt30_eta4p7_jerdn;
   Float_t         absrapidity_leadingjet_pt30_eta4p7;
   Float_t         absrapidity_leadingjet_pt30_eta4p7_jesup;
   Float_t         absrapidity_leadingjet_pt30_eta4p7_jesdn;
   Float_t         absrapidity_leadingjet_pt30_eta4p7_jerup;
   Float_t         absrapidity_leadingjet_pt30_eta4p7_jerdn;
   Float_t         absdeltarapidity_hleadingjet_pt30_eta4p7;
   Float_t         absdeltarapidity_hleadingjet_pt30_eta4p7_jesup;
   Float_t         absdeltarapidity_hleadingjet_pt30_eta4p7_jesdn;
   Float_t         absdeltarapidity_hleadingjet_pt30_eta4p7_jerup;
   Float_t         absdeltarapidity_hleadingjet_pt30_eta4p7_jerdn;
   Int_t           nbjets_pt30_eta4p7;
   Int_t           nvjets_pt40_eta2p4;
   Float_t         DijetMass;
   Float_t         DijetDEta;
   Float_t         DijetFisher;
   Int_t           njets_pt30_eta2p5;
   Int_t           njets_pt30_eta2p5_jesup;
   Int_t           njets_pt30_eta2p5_jesdn;
   Int_t           njets_pt30_eta2p5_jerup;
   Int_t           njets_pt30_eta2p5_jerdn;
   Float_t         pt_leadingjet_pt30_eta2p5;
   Float_t         pt_leadingjet_pt30_eta2p5_jesup;
   Float_t         pt_leadingjet_pt30_eta2p5_jesdn;
   Float_t         pt_leadingjet_pt30_eta2p5_jerup;
   Float_t         pt_leadingjet_pt30_eta2p5_jerdn;
   vector<int>     *mergedjet_iscleanH4l;
   vector<float>   *mergedjet_pt;
   vector<float>   *mergedjet_eta;
   vector<float>   *mergedjet_phi;
   vector<float>   *mergedjet_mass;
   vector<float>   *mergedjet_tau1;
   vector<float>   *mergedjet_tau2;
   vector<float>   *mergedjet_btag;
   vector<float>   *mergedjet_L1;
   vector<float>   *mergedjet_softdropmass;
   vector<float>   *mergedjet_prunedmass;
   vector<int>     *mergedjet_nsubjet;
   vector<vector<float> > *mergedjet_subjet_pt;
   vector<vector<float> > *mergedjet_subjet_eta;
   vector<vector<float> > *mergedjet_subjet_phi;
   vector<vector<float> > *mergedjet_subjet_mass;
   vector<vector<float> > *mergedjet_subjet_btag;
   vector<vector<int> > *mergedjet_subjet_partonFlavour;
   vector<vector<int> > *mergedjet_subjet_hadronFlavour;
   Int_t           nFSRPhotons;
   vector<float>   *allfsrPhotons_dR;
   vector<float>   *allfsrPhotons_iso;
   vector<float>   *allfsrPhotons_pt;
   vector<int>     *fsrPhotons_lepindex;
   vector<float>   *fsrPhotons_pt;
   vector<float>   *fsrPhotons_pterr;
   vector<float>   *fsrPhotons_eta;
   vector<float>   *fsrPhotons_phi;
   vector<float>   *fsrPhotons_dR;
   vector<float>   *fsrPhotons_iso;
   Float_t         theta12;
   Float_t         theta13;
   Float_t         theta14;
   Float_t         minM3l;
   Float_t         Z4lmaxP;
   Float_t         minDeltR;
   Float_t         m3l_soft;
   Float_t         minMass2Lep;
   Float_t         maxMass2Lep;
   Float_t         thetaPhoton;
   Float_t         thetaPhotonZ;
   Int_t           EventCat;
   Int_t           GENfinalState;
   Bool_t          passedFiducialSelection;
   vector<float>   *GENlep_pt;
   vector<float>   *GENlep_eta;
   vector<float>   *GENlep_phi;
   vector<float>   *GENlep_mass;
   vector<int>     *GENlep_id;
   vector<int>     *GENlep_status;
   vector<int>     *GENlep_MomId;
   vector<int>     *GENlep_MomMomId;
   Int_t           GENlep_Hindex[4];
   vector<float>   *GENlep_isoCH;
   vector<float>   *GENlep_isoNH;
   vector<float>   *GENlep_isoPhot;
   vector<float>   *GENlep_RelIso;
   vector<float>   *GENH_pt;
   vector<float>   *GENH_eta;
   vector<float>   *GENH_phi;
   vector<float>   *GENH_mass;
   Float_t         GENmass4l;
   Float_t         GENmass4mu;
   Float_t         GENmass4e;
   Float_t         GENmass2e2mu;
   Float_t         GENpT4l;
   Float_t         GENeta4l;
   Float_t         GENrapidity4l;
   Float_t         GENcosTheta1;
   Float_t         GENcosTheta2;
   Float_t         GENcosThetaStar;
   Float_t         GENPhi;
   Float_t         GENPhi1;
   Float_t         GENMH;
   vector<float>   *GENZ_pt;
   vector<float>   *GENZ_eta;
   vector<float>   *GENZ_phi;
   vector<float>   *GENZ_mass;
   vector<int>     *GENZ_DaughtersId;
   vector<int>     *GENZ_MomId;
   Float_t         GENmassZ1;
   Float_t         GENmassZ2;
   Float_t         GENpTZ1;
   Float_t         GENpTZ2;
   Float_t         GENdPhiZZ;
   Float_t         GENmassZZ;
   Float_t         GENpTZZ;
   Float_t         GENHmass;
   Int_t           stage0cat;
   Int_t           stage1cat;
   Int_t           stage1p1cat;
   Int_t           stage1p2cat;
   Int_t           passedFiducialRivet;
   Float_t         GENpT4lRivet;
   Int_t           GENnjets_pt30_eta4p7Rivet;
   Float_t         GENpt_leadingjet_pt30_eta4p7Rivet;
   vector<float>   *GENjet_pt;
   vector<float>   *GENjet_eta;
   vector<float>   *GENjet_phi;
   vector<float>   *GENjet_mass;
   Int_t           GENnjets_pt30_eta4p7;
   Float_t         GENpt_leadingjet_pt30_eta4p7;
   Float_t         GENabsrapidity_leadingjet_pt30_eta4p7;
   Float_t         GENabsdeltarapidity_hleadingjet_pt30_eta4p7;
   Int_t           GENnjets_pt30_eta2p5;
   Float_t         GENpt_leadingjet_pt30_eta2p5;
   Int_t           lheNj;
   Int_t           lheNb;
   Int_t           nGenStatus2bHad;
   Float_t         me_0plus_JHU;
   Float_t         me_qqZZ_MCFM;
   Float_t         p0plus_m4l;
   Float_t         bkg_m4l;
   Float_t         D_bkg_kin;
   Float_t         D_bkg_kin_vtx_BS;
   Float_t         D_bkg;
   Float_t         Dgg10_VAMCFM;
   Float_t         D_g4;
   Float_t         D_g1g4;
   Float_t         D_VBF;
   Float_t         D_VBF1j;
   Float_t         D_HadWH;
   Float_t         D_HadZH;
   Float_t         D_bkg_VBFdec;
   Float_t         D_bkg_VHdec;
   Float_t         D_VBF_QG;
   Float_t         D_VBF1j_QG;
   Float_t         D_HadWH_QG;
   Float_t         D_HadZH_QG;

   // List of branches
   TBranch        *b_Run;   //!
   TBranch        *b_Event;   //!
   TBranch        *b_LumiSect;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_nInt;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_BS_x;   //!
   TBranch        *b_BS_y;   //!
   TBranch        *b_BS_z;   //!
   TBranch        *b_BS_xErr;   //!
   TBranch        *b_BS_yErr;   //!
   TBranch        *b_BS_zErr;   //!
   TBranch        *b_BeamWidth_x;   //!
   TBranch        *b_BeamWidth_y;   //!
   TBranch        *b_BeamWidth_xErr;   //!
   TBranch        *b_BeamWidth_yErr;   //!
   TBranch        *b_finalState;   //!
   TBranch        *b_triggersPassed;   //!
   TBranch        *b_passedTrig;   //!
   TBranch        *b_passedFullSelection;   //!
   TBranch        *b_passedZ4lSelection;   //!
   TBranch        *b_passedQCDcut;   //!
   TBranch        *b_passedZ1LSelection;   //!
   TBranch        *b_passedZ4lZ1LSelection;   //!
   TBranch        *b_passedZ4lZXCRSelection;   //!
   TBranch        *b_passedZXCRSelection;   //!
   TBranch        *b_nZXCRFailedLeptons;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_k_ggZZ;   //!
   TBranch        *b_k_qqZZ_qcd_dPhi;   //!
   TBranch        *b_k_qqZZ_qcd_M;   //!
   TBranch        *b_k_qqZZ_qcd_Pt;   //!
   TBranch        *b_k_qqZZ_ewk;   //!
   TBranch        *b_qcdWeights;   //!
   TBranch        *b_nnloWeights;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_pdfRMSup;   //!
   TBranch        *b_pdfRMSdown;   //!
   TBranch        *b_pdfENVup;   //!
   TBranch        *b_pdfENVdown;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_pileupWeightUp;   //!
   TBranch        *b_pileupWeightDn;   //!
   TBranch        *b_dataMCWeight;   //!
   TBranch        *b_eventWeight;   //!
   TBranch        *b_prefiringWeight;   //!
   TBranch        *b_crossSection;   //!
   TBranch        *b_lep_d0BS;   //!
   TBranch        *b_lep_d0PV;   //!
   TBranch        *b_lep_numberOfValidPixelHits;   //!
   TBranch        *b_lep_trackerLayersWithMeasurement;   //!
   TBranch        *b_lep_chi2LocalPosition;   //!
   TBranch        *b_lep_trkKink;   //!
   TBranch        *b_lep_numberOfMatchedStations;   //!
   TBranch        *b_lep_validFraction;   //!
   TBranch        *b_lep_arbitrationType;   //!
   TBranch        *b_lep_normalizedChi2;   //!
   TBranch        *b_lep_numberOfValidMuonHits;   //!
   TBranch        *b_lep_p;   //!
   TBranch        *b_lep_ecalEnergy;   //!
   TBranch        *b_lep_isEB;   //!
   TBranch        *b_lep_isEE;   //!
   TBranch        *b_singleBS_Lep_pt;   //!
   TBranch        *b_singleBS_Lep_ptError;   //!
   TBranch        *b_singleBS_Lep_eta;   //!
   TBranch        *b_singleBS_Lep_phi;   //!
   TBranch        *b_singleBS_Lep_mass;   //!
   TBranch        *b_singleBS_Lep_d0;   //!
   TBranch        *b_vtxLep_BS_pt;   //!
   TBranch        *b_vtxLep_BS_pt_NoRoch;   //!
   TBranch        *b_vtxLep_BS_ptError;   //!
   TBranch        *b_vtxLep_BS_eta;   //!
   TBranch        *b_vtxLep_BS_phi;   //!
   TBranch        *b_vtxLep_BS_mass;   //!
   TBranch        *b_vtxLep_BS_d0;   //!
   TBranch        *b_vtxLep_pt;   //!
   TBranch        *b_vtxLep_ptError;   //!
   TBranch        *b_vtxLep_eta;   //!
   TBranch        *b_vtxLep_phi;   //!
   TBranch        *b_vtxLep_mass;   //!
   TBranch        *b_singleBS_FSR_Lep_pt;   //!
   TBranch        *b_singleBS_FSR_Lep_eta;   //!
   TBranch        *b_singleBS_FSR_Lep_phi;   //!
   TBranch        *b_singleBS_FSR_Lep_mass;   //!
   TBranch        *b_vtxLepFSR_BS_pt;   //!
   TBranch        *b_vtxLepFSR_BS_eta;   //!
   TBranch        *b_vtxLepFSR_BS_phi;   //!
   TBranch        *b_vtxLepFSR_BS_mass;   //!
   TBranch        *b_vtxLepFSR_pt;   //!
   TBranch        *b_vtxLepFSR_eta;   //!
   TBranch        *b_vtxLepFSR_phi;   //!
   TBranch        *b_vtxLepFSR_mass;   //!
   TBranch        *b_singleBS_RecoLep_pt;   //!
   TBranch        *b_singleBS_RecoLep_ptError;   //!
   TBranch        *b_singleBS_RecoLep_eta;   //!
   TBranch        *b_singleBS_RecoLep_phi;   //!
   TBranch        *b_singleBS_RecoLep_mass;   //!
   TBranch        *b_singleBS_RecoLep_d0;   //!
   TBranch        *b_vtxRecoLep_BS_pt;   //!
   TBranch        *b_vtxRecoLep_BS_ptError;   //!
   TBranch        *b_vtxRecoLep_BS_eta;   //!
   TBranch        *b_vtxRecoLep_BS_phi;   //!
   TBranch        *b_vtxRecoLep_BS_mass;   //!
   TBranch        *b_vtxRecoLep_BS_d0;   //!
   TBranch        *b_vtxRecoLep_pt;   //!
   TBranch        *b_vtxRecoLep_ptError;   //!
   TBranch        *b_vtxRecoLep_eta;   //!
   TBranch        *b_vtxRecoLep_phi;   //!
   TBranch        *b_vtxRecoLep_mass;   //!
   TBranch        *b_commonPV_x;   //!
   TBranch        *b_commonPV_y;   //!
   TBranch        *b_commonPV_z;   //!
   TBranch        *b_commonBS_x;   //!
   TBranch        *b_commonBS_y;   //!
   TBranch        *b_commonBS_z;   //!
   TBranch        *b_lep_pt_UnS;   //!
   TBranch        *b_lep_pterrold_UnS;   //!
   TBranch        *b_lep_errPre_Scale;   //!
   TBranch        *b_lep_errPost_Scale;   //!
   TBranch        *b_lep_errPre_noScale;   //!
   TBranch        *b_lep_errPost_noScale;   //!
   TBranch        *b_lep_pt_FromMuonBestTrack;   //!
   TBranch        *b_lep_eta_FromMuonBestTrack;   //!
   TBranch        *b_lep_phi_FromMuonBestTrack;   //!
   TBranch        *b_lep_position_x;   //!
   TBranch        *b_lep_position_y;   //!
   TBranch        *b_lep_position_z;   //!
   TBranch        *b_lep_pt_genFromReco;   //!
   TBranch        *b_lep_id;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_pterr;   //!
   TBranch        *b_lep_pterrold;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_mass;   //!
   TBranch        *b_lepFSR_pt;   //!
   TBranch        *b_lepFSR_eta;   //!
   TBranch        *b_lepFSR_phi;   //!
   TBranch        *b_lepFSR_mass;   //!
   TBranch        *b_lep_Hindex;   //!
   TBranch        *b_lep_genindex;   //!
   TBranch        *b_lep_matchedR03_PdgId;   //!
   TBranch        *b_lep_matchedR03_MomId;   //!
   TBranch        *b_lep_matchedR03_MomMomId;   //!
   TBranch        *b_lep_missingHits;   //!
   TBranch        *b_lep_mva;   //!
   TBranch        *b_lep_ecalDriven;   //!
   TBranch        *b_lep_tightId;   //!
   TBranch        *b_lep_tightIdSUS;   //!
   TBranch        *b_lep_tightIdHiPt;   //!
   TBranch        *b_lep_Sip;   //!
   TBranch        *b_lep_IP;   //!
   TBranch        *b_lep_isoNH;   //!
   TBranch        *b_lep_isoCH;   //!
   TBranch        *b_lep_isoPhot;   //!
   TBranch        *b_lep_isoPU;   //!
   TBranch        *b_lep_isoPUcorr;   //!
   TBranch        *b_lep_RelIso;   //!
   TBranch        *b_lep_RelIsoNoFSR;   //!
   TBranch        *b_lep_MiniIso;   //!
   TBranch        *b_lep_ptRatio;   //!
   TBranch        *b_lep_ptRel;   //!
   TBranch        *b_lep_filtersMatched;   //!
   TBranch        *b_lep_dataMC;   //!
   TBranch        *b_lep_dataMCErr;   //!
   TBranch        *b_dataMC_VxBS;   //!
   TBranch        *b_dataMCErr_VxBS;   //!
   TBranch        *b_nisoleptons;   //!
   TBranch        *b_muRho;   //!
   TBranch        *b_elRho;   //!
   TBranch        *b_pTL1;   //!
   TBranch        *b_pTL2;   //!
   TBranch        *b_pTL3;   //!
   TBranch        *b_pTL4;   //!
   TBranch        *b_idL1;   //!
   TBranch        *b_idL2;   //!
   TBranch        *b_idL3;   //!
   TBranch        *b_idL4;   //!
   TBranch        *b_etaL1;   //!
   TBranch        *b_etaL2;   //!
   TBranch        *b_etaL3;   //!
   TBranch        *b_etaL4;   //!
   TBranch        *b_mL1;   //!
   TBranch        *b_mL2;   //!
   TBranch        *b_mL3;   //!
   TBranch        *b_mL4;   //!
   TBranch        *b_pTErrL1;   //!
   TBranch        *b_pTErrL2;   //!
   TBranch        *b_pTErrL3;   //!
   TBranch        *b_pTErrL4;   //!
   TBranch        *b_phiL1;   //!
   TBranch        *b_phiL2;   //!
   TBranch        *b_phiL3;   //!
   TBranch        *b_phiL4;   //!
   TBranch        *b_pTL1FSR;   //!
   TBranch        *b_pTL2FSR;   //!
   TBranch        *b_pTL3FSR;   //!
   TBranch        *b_pTL4FSR;   //!
   TBranch        *b_etaL1FSR;   //!
   TBranch        *b_etaL2FSR;   //!
   TBranch        *b_etaL3FSR;   //!
   TBranch        *b_etaL4FSR;   //!
   TBranch        *b_phiL1FSR;   //!
   TBranch        *b_phiL2FSR;   //!
   TBranch        *b_phiL3FSR;   //!
   TBranch        *b_phiL4FSR;   //!
   TBranch        *b_mL1FSR;   //!
   TBranch        *b_mL2FSR;   //!
   TBranch        *b_mL3FSR;   //!
   TBranch        *b_mL4FSR;   //!
   TBranch        *b_pTErrL1FSR;   //!
   TBranch        *b_pTErrL2FSR;   //!
   TBranch        *b_pTErrL3FSR;   //!
   TBranch        *b_pTErrL4FSR;   //!
   TBranch        *b_tau_id;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_mass;   //!
   TBranch        *b_pho_pt;   //!
   TBranch        *b_pho_eta;   //!
   TBranch        *b_pho_phi;   //!
   TBranch        *b_photonCutBasedIDLoose;   //!
   TBranch        *b_H_pt;   //!
   TBranch        *b_H_eta;   //!
   TBranch        *b_H_phi;   //!
   TBranch        *b_H_mass;   //!
   TBranch        *b_H_noFSR_pt;   //!
   TBranch        *b_H_noFSR_eta;   //!
   TBranch        *b_H_noFSR_phi;   //!
   TBranch        *b_H_noFSR_mass;   //!
   TBranch        *b_mass4l;   //!
   TBranch        *b_mass4l_noFSR;   //!
   TBranch        *b_mass4lErr;   //!
   TBranch        *b_mass4lREFIT;   //!
   TBranch        *b_mass4lErrREFIT;   //!
   TBranch        *b_massZ1REFIT;   //!
   TBranch        *b_massZ2REFIT;   //!
   TBranch        *b_mass4l_singleBS;   //!
   TBranch        *b_mass4l_singleBS_FSR;   //!
   TBranch        *b_mass4lErr_singleBS;   //!
   TBranch        *b_mass4lREFIT_singleBS;   //!
   TBranch        *b_mass4lErrREFIT_singleBS;   //!
   TBranch        *b_massZ1REFIT_singleBS;   //!
   TBranch        *b_massZ2REFIT_singleBS;   //!
   TBranch        *b_mass4l_vtx_BS;   //!
   TBranch        *b_mass4l_vtxFSR_BS;   //!
   TBranch        *b_mass4lErr_vtx_BS;   //!
   TBranch        *b_mass4lREFIT_vtx_BS;   //!
   TBranch        *b_mass4lErrREFIT_vtx_BS;   //!
   TBranch        *b_massZ1REFIT_vtx_BS;   //!
   TBranch        *b_massZ2REFIT_vtx_BS;   //!
   TBranch        *b_mass4l_vtx;   //!
   TBranch        *b_mass4l_vtxFSR;   //!
   TBranch        *b_mass4lErr_vtx;   //!
   TBranch        *b_mass4lREFIT_vtx;   //!
   TBranch        *b_mass4lErrREFIT_vtx;   //!
   TBranch        *b_mass4mu;   //!
   TBranch        *b_mass4e;   //!
   TBranch        *b_mass2e2mu;   //!
   TBranch        *b_pT4l;   //!
   TBranch        *b_eta4l;   //!
   TBranch        *b_phi4l;   //!
   TBranch        *b_rapidity4l;   //!
   TBranch        *b_cosTheta1;   //!
   TBranch        *b_cosTheta2;   //!
   TBranch        *b_cosThetaStar;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Phi1;   //!
   TBranch        *b_mass3l;   //!
   TBranch        *b_massZ_vtx_chi2_BS;   //!
   TBranch        *b_massZ_vtx_chi2;   //!
   TBranch        *b_mass2l_vtx;   //!
   TBranch        *b_mass2l_vtx_BS;   //!
   TBranch        *b_Z_pt;   //!
   TBranch        *b_Z_eta;   //!
   TBranch        *b_Z_phi;   //!
   TBranch        *b_Z_mass;   //!
   TBranch        *b_Z_noFSR_pt;   //!
   TBranch        *b_Z_noFSR_eta;   //!
   TBranch        *b_Z_noFSR_phi;   //!
   TBranch        *b_Z_noFSR_mass;   //!
   TBranch        *b_Z_Hindex;   //!
   TBranch        *b_massZ1;   //!
   TBranch        *b_massErrH_vtx;   //!
   TBranch        *b_massH_vtx_chi2_BS;   //!
   TBranch        *b_massH_vtx_chi2;   //!
   TBranch        *b_massZ1_Z1L;   //!
   TBranch        *b_massZ2;   //!
   TBranch        *b_pTZ1;   //!
   TBranch        *b_pTZ2;   //!
   TBranch        *b_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_jesup;   //!
   TBranch        *b_met_phi_jesup;   //!
   TBranch        *b_met_jesdn;   //!
   TBranch        *b_met_phi_jesdn;   //!
   TBranch        *b_met_uncenup;   //!
   TBranch        *b_met_phi_uncenup;   //!
   TBranch        *b_met_uncendn;   //!
   TBranch        *b_met_phi_uncendn;   //!
   TBranch        *b_jet_iscleanH4l;   //!
   TBranch        *b_jet1index;   //!
   TBranch        *b_jet2index;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_pt_raw;   //!
   TBranch        *b_jet_relpterr;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_phierr;   //!
   TBranch        *b_jet_bTagEffi;   //!
   TBranch        *b_jet_cTagEffi;   //!
   TBranch        *b_jet_udsgTagEffi;   //!
   TBranch        *b_jet_mass;   //!
   TBranch        *b_jet_jesup_iscleanH4l;   //!
   TBranch        *b_jet_jesup_pt;   //!
   TBranch        *b_jet_jesup_eta;   //!
   TBranch        *b_jet_jesup_phi;   //!
   TBranch        *b_jet_jesup_mass;   //!
   TBranch        *b_jet_jesdn_iscleanH4l;   //!
   TBranch        *b_jet_jesdn_pt;   //!
   TBranch        *b_jet_jesdn_eta;   //!
   TBranch        *b_jet_jesdn_phi;   //!
   TBranch        *b_jet_jesdn_mass;   //!
   TBranch        *b_jet_jerup_iscleanH4l;   //!
   TBranch        *b_jet_jerup_pt;   //!
   TBranch        *b_jet_jerup_eta;   //!
   TBranch        *b_jet_jerup_phi;   //!
   TBranch        *b_jet_jerup_mass;   //!
   TBranch        *b_jet_jerdn_iscleanH4l;   //!
   TBranch        *b_jet_jerdn_pt;   //!
   TBranch        *b_jet_jerdn_eta;   //!
   TBranch        *b_jet_jerdn_phi;   //!
   TBranch        *b_jet_jerdn_mass;   //!
   TBranch        *b_jet_pumva;   //!
   TBranch        *b_jet_csvv2;   //!
   TBranch        *b_jet_csvv2_;   //!
   TBranch        *b_jet_isbtag;   //!
   TBranch        *b_jet_hadronFlavour;   //!
   TBranch        *b_jet_partonFlavour;   //!
   TBranch        *b_jet_QGTagger;   //!
   TBranch        *b_jet_QGTagger_jesup;   //!
   TBranch        *b_jet_QGTagger_jesdn;   //!
   TBranch        *b_jet_axis2;   //!
   TBranch        *b_jet_ptD;   //!
   TBranch        *b_jet_mult;   //!
   TBranch        *b_njets_pt30_eta4p7;   //!
   TBranch        *b_njets_pt30_eta4p7_jesup;   //!
   TBranch        *b_njets_pt30_eta4p7_jesdn;   //!
   TBranch        *b_njets_pt30_eta4p7_jerup;   //!
   TBranch        *b_njets_pt30_eta4p7_jerdn;   //!
   TBranch        *b_pt_leadingjet_pt30_eta4p7;   //!
   TBranch        *b_pt_leadingjet_pt30_eta4p7_jesup;   //!
   TBranch        *b_pt_leadingjet_pt30_eta4p7_jesdn;   //!
   TBranch        *b_pt_leadingjet_pt30_eta4p7_jerup;   //!
   TBranch        *b_pt_leadingjet_pt30_eta4p7_jerdn;   //!
   TBranch        *b_absrapidity_leadingjet_pt30_eta4p7;   //!
   TBranch        *b_absrapidity_leadingjet_pt30_eta4p7_jesup;   //!
   TBranch        *b_absrapidity_leadingjet_pt30_eta4p7_jesdn;   //!
   TBranch        *b_absrapidity_leadingjet_pt30_eta4p7_jerup;   //!
   TBranch        *b_absrapidity_leadingjet_pt30_eta4p7_jerdn;   //!
   TBranch        *b_absdeltarapidity_hleadingjet_pt30_eta4p7;   //!
   TBranch        *b_absdeltarapidity_hleadingjet_pt30_eta4p7_jesup;   //!
   TBranch        *b_absdeltarapidity_hleadingjet_pt30_eta4p7_jesdn;   //!
   TBranch        *b_absdeltarapidity_hleadingjet_pt30_eta4p7_jerup;   //!
   TBranch        *b_absdeltarapidity_hleadingjet_pt30_eta4p7_jerdn;   //!
   TBranch        *b_nbjets_pt30_eta4p7;   //!
   TBranch        *b_nvjets_pt40_eta2p4;   //!
   TBranch        *b_DijetMass;   //!
   TBranch        *b_DijetDEta;   //!
   TBranch        *b_DijetFisher;   //!
   TBranch        *b_njets_pt30_eta2p5;   //!
   TBranch        *b_njets_pt30_eta2p5_jesup;   //!
   TBranch        *b_njets_pt30_eta2p5_jesdn;   //!
   TBranch        *b_njets_pt30_eta2p5_jerup;   //!
   TBranch        *b_njets_pt30_eta2p5_jerdn;   //!
   TBranch        *b_pt_leadingjet_pt30_eta2p5;   //!
   TBranch        *b_pt_leadingjet_pt30_eta2p5_jesup;   //!
   TBranch        *b_pt_leadingjet_pt30_eta2p5_jesdn;   //!
   TBranch        *b_pt_leadingjet_pt30_eta2p5_jerup;   //!
   TBranch        *b_pt_leadingjet_pt30_eta2p5_jerdn;   //!
   TBranch        *b_mergedjet_iscleanH4l;   //!
   TBranch        *b_mergedjet_pt;   //!
   TBranch        *b_mergedjet_eta;   //!
   TBranch        *b_mergedjet_phi;   //!
   TBranch        *b_mergedjet_mass;   //!
   TBranch        *b_mergedjet_tau1;   //!
   TBranch        *b_mergedjet_tau2;   //!
   TBranch        *b_mergedjet_btag;   //!
   TBranch        *b_mergedjet_L1;   //!
   TBranch        *b_mergedjet_softdropmass;   //!
   TBranch        *b_mergedjet_prunedmass;   //!
   TBranch        *b_mergedjet_nsubjet;   //!
   TBranch        *b_mergedjet_subjet_pt;   //!
   TBranch        *b_mergedjet_subjet_eta;   //!
   TBranch        *b_mergedjet_subjet_phi;   //!
   TBranch        *b_mergedjet_subjet_mass;   //!
   TBranch        *b_mergedjet_subjet_btag;   //!
   TBranch        *b_mergedjet_subjet_partonFlavour;   //!
   TBranch        *b_mergedjet_subjet_hadronFlavour;   //!
   TBranch        *b_nFSRPhotons;   //!
   TBranch        *b_allfsrPhotons_dR;   //!
   TBranch        *b_allfsrPhotons_iso;   //!
   TBranch        *b_allfsrPhotons_pt;   //!
   TBranch        *b_fsrPhotons_lepindex;   //!
   TBranch        *b_fsrPhotons_pt;   //!
   TBranch        *b_fsrPhotons_pterr;   //!
   TBranch        *b_fsrPhotons_eta;   //!
   TBranch        *b_fsrPhotons_phi;   //!
   TBranch        *b_fsrPhotons_dR;   //!
   TBranch        *b_fsrPhotons_iso;   //!
   TBranch        *b_theta12;   //!
   TBranch        *b_theta13;   //!
   TBranch        *b_theta14;   //!
   TBranch        *b_minM3l;   //!
   TBranch        *b_Z4lmaxP;   //!
   TBranch        *b_minDeltR;   //!
   TBranch        *b_m3l_soft;   //!
   TBranch        *b_minMass2Lep;   //!
   TBranch        *b_maxMass2Lep;   //!
   TBranch        *b_thetaPhoton;   //!
   TBranch        *b_thetaPhotonZ;   //!
   TBranch        *b_EventCat;   //!
   TBranch        *b_GENfinalState;   //!
   TBranch        *b_passedFiducialSelection;   //!
   TBranch        *b_GENlep_pt;   //!
   TBranch        *b_GENlep_eta;   //!
   TBranch        *b_GENlep_phi;   //!
   TBranch        *b_GENlep_mass;   //!
   TBranch        *b_GENlep_id;   //!
   TBranch        *b_GENlep_status;   //!
   TBranch        *b_GENlep_MomId;   //!
   TBranch        *b_GENlep_MomMomId;   //!
   TBranch        *b_GENlep_Hindex;   //!
   TBranch        *b_GENlep_isoCH;   //!
   TBranch        *b_GENlep_isoNH;   //!
   TBranch        *b_GENlep_isoPhot;   //!
   TBranch        *b_GENlep_RelIso;   //!
   TBranch        *b_GENH_pt;   //!
   TBranch        *b_GENH_eta;   //!
   TBranch        *b_GENH_phi;   //!
   TBranch        *b_GENH_mass;   //!
   TBranch        *b_GENmass4l;   //!
   TBranch        *b_GENmass4mu;   //!
   TBranch        *b_GENmass4e;   //!
   TBranch        *b_GENmass2e2mu;   //!
   TBranch        *b_GENpT4l;   //!
   TBranch        *b_GENeta4l;   //!
   TBranch        *b_GENrapidity4l;   //!
   TBranch        *b_GENcosTheta1;   //!
   TBranch        *b_GENcosTheta2;   //!
   TBranch        *b_GENcosThetaStar;   //!
   TBranch        *b_GENPhi;   //!
   TBranch        *b_GENPhi1;   //!
   TBranch        *b_GENMH;   //!
   TBranch        *b_GENZ_pt;   //!
   TBranch        *b_GENZ_eta;   //!
   TBranch        *b_GENZ_phi;   //!
   TBranch        *b_GENZ_mass;   //!
   TBranch        *b_GENZ_DaughtersId;   //!
   TBranch        *b_GENZ_MomId;   //!
   TBranch        *b_GENmassZ1;   //!
   TBranch        *b_GENmassZ2;   //!
   TBranch        *b_GENpTZ1;   //!
   TBranch        *b_GENpTZ2;   //!
   TBranch        *b_GENdPhiZZ;   //!
   TBranch        *b_GENmassZZ;   //!
   TBranch        *b_GENpTZZ;   //!
   TBranch        *b_GENHmass;   //!
   TBranch        *b_stage0cat;   //!
   TBranch        *b_stage1cat;   //!
   TBranch        *b_stage1p1cat;   //!
   TBranch        *b_stage1p2cat;   //!
   TBranch        *b_passedFiducialRivet;   //!
   TBranch        *b_GENpT4lRivet;   //!
   TBranch        *b_GENnjets_pt30_eta4p7Rivet;   //!
   TBranch        *b_GENpt_leadingjet_pt30_eta4p7Rivet;   //!
   TBranch        *b_GENjet_pt;   //!
   TBranch        *b_GENjet_eta;   //!
   TBranch        *b_GENjet_phi;   //!
   TBranch        *b_GENjet_mass;   //!
   TBranch        *b_GENnjets_pt30_eta4p7;   //!
   TBranch        *b_GENpt_leadingjet_pt30_eta4p7;   //!
   TBranch        *b_GENabsrapidity_leadingjet_pt30_eta4p7;   //!
   TBranch        *b_GENabsdeltarapidity_hleadingjet_pt30_eta4p7;   //!
   TBranch        *b_GENnjets_pt30_eta2p5;   //!
   TBranch        *b_GENpt_leadingjet_pt30_eta2p5;   //!
   TBranch        *b_lheNj;   //!
   TBranch        *b_lheNb;   //!
   TBranch        *b_nGenStatus2bHad;   //!
   TBranch        *b_me_0plus_JHU;   //!
   TBranch        *b_me_qqZZ_MCFM;   //!
   TBranch        *b_p0plus_m4l;   //!
   TBranch        *b_bkg_m4l;   //!
   TBranch        *b_D_bkg_kin;   //!
   TBranch        *b_D_bkg_kin_vtx_BS;   //!
   TBranch        *b_D_bkg;   //!
   TBranch        *b_Dgg10_VAMCFM;   //!
   TBranch        *b_D_g4;   //!
   TBranch        *b_D_g1g4;   //!
   TBranch        *b_D_VBF;   //!
   TBranch        *b_D_VBF1j;   //!
   TBranch        *b_D_HadWH;   //!
   TBranch        *b_D_HadZH;   //!
   TBranch        *b_D_bkg_VBFdec;   //!
   TBranch        *b_D_bkg_VHdec;   //!
   TBranch        *b_D_VBF_QG;   //!
   TBranch        *b_D_VBF1j_QG;   //!
   TBranch        *b_D_HadWH_QG;   //!
   TBranch        *b_D_HadZH_QG;   //!

   MyClass(TTree *tree=0);
   virtual ~MyClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyClass_cxx
MyClass::MyClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("HZZ_signal_ntuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("HZZ_signal_ntuple.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("HZZ_signal_ntuple.root:/Ana");
      dir->GetObject("passedEvents",tree);

   }
   Init(tree);
}

MyClass::~MyClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}
Bool_t MyClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
void MyClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   triggersPassed = 0;
   qcdWeights = 0;
   nnloWeights = 0;
   pdfWeights = 0;
   lep_d0BS = 0;
   lep_d0PV = 0;
   lep_numberOfValidPixelHits = 0;
   lep_trackerLayersWithMeasurement = 0;
   lep_chi2LocalPosition = 0;
   lep_trkKink = 0;
   lep_numberOfMatchedStations = 0;
   lep_validFraction = 0;
   lep_arbitrationType = 0;
   lep_normalizedChi2 = 0;
   lep_numberOfValidMuonHits = 0;
   lep_p = 0;
   lep_ecalEnergy = 0;
   lep_isEB = 0;
   lep_isEE = 0;
   singleBS_Lep_pt = 0;
   singleBS_Lep_ptError = 0;
   singleBS_Lep_eta = 0;
   singleBS_Lep_phi = 0;
   singleBS_Lep_mass = 0;
   singleBS_Lep_d0 = 0;
   vtxLep_BS_pt = 0;
   vtxLep_BS_pt_NoRoch = 0;
   vtxLep_BS_ptError = 0;
   vtxLep_BS_eta = 0;
   vtxLep_BS_phi = 0;
   vtxLep_BS_mass = 0;
   vtxLep_BS_d0 = 0;
   vtxLep_pt = 0;
   vtxLep_ptError = 0;
   vtxLep_eta = 0;
   vtxLep_phi = 0;
   vtxLep_mass = 0;
   singleBS_FSR_Lep_pt = 0;
   singleBS_FSR_Lep_eta = 0;
   singleBS_FSR_Lep_phi = 0;
   singleBS_FSR_Lep_mass = 0;
   vtxLepFSR_BS_pt = 0;
   vtxLepFSR_BS_eta = 0;
   vtxLepFSR_BS_phi = 0;
   vtxLepFSR_BS_mass = 0;
   vtxLepFSR_pt = 0;
   vtxLepFSR_eta = 0;
   vtxLepFSR_phi = 0;
   vtxLepFSR_mass = 0;
   singleBS_RecoLep_pt = 0;
   singleBS_RecoLep_ptError = 0;
   singleBS_RecoLep_eta = 0;
   singleBS_RecoLep_phi = 0;
   singleBS_RecoLep_mass = 0;
   singleBS_RecoLep_d0 = 0;
   vtxRecoLep_BS_pt = 0;
   vtxRecoLep_BS_ptError = 0;
   vtxRecoLep_BS_eta = 0;
   vtxRecoLep_BS_phi = 0;
   vtxRecoLep_BS_mass = 0;
   vtxRecoLep_BS_d0 = 0;
   vtxRecoLep_pt = 0;
   vtxRecoLep_ptError = 0;
   vtxRecoLep_eta = 0;
   vtxRecoLep_phi = 0;
   vtxRecoLep_mass = 0;
   commonPV_x = 0;
   commonPV_y = 0;
   commonPV_z = 0;
   commonBS_x = 0;
   commonBS_y = 0;
   commonBS_z = 0;
   lep_pt_UnS = 0;
   lep_pterrold_UnS = 0;
   lep_errPre_Scale = 0;
   lep_errPost_Scale = 0;
   lep_errPre_noScale = 0;
   lep_errPost_noScale = 0;
   lep_pt_FromMuonBestTrack = 0;
   lep_eta_FromMuonBestTrack = 0;
   lep_phi_FromMuonBestTrack = 0;
   lep_position_x = 0;
   lep_position_y = 0;
   lep_position_z = 0;
   lep_pt_genFromReco = 0;
   lep_id = 0;
   lep_pt = 0;
   lep_pterr = 0;
   lep_pterrold = 0;
   lep_eta = 0;
   lep_phi = 0;
   lep_mass = 0;
   lepFSR_pt = 0;
   lepFSR_eta = 0;
   lepFSR_phi = 0;
   lepFSR_mass = 0;
   lep_genindex = 0;
   lep_matchedR03_PdgId = 0;
   lep_matchedR03_MomId = 0;
   lep_matchedR03_MomMomId = 0;
   lep_missingHits = 0;
   lep_mva = 0;
   lep_ecalDriven = 0;
   lep_tightId = 0;
   lep_tightIdSUS = 0;
   lep_tightIdHiPt = 0;
   lep_Sip = 0;
   lep_IP = 0;
   lep_isoNH = 0;
   lep_isoCH = 0;
   lep_isoPhot = 0;
   lep_isoPU = 0;
   lep_isoPUcorr = 0;
   lep_RelIso = 0;
   lep_RelIsoNoFSR = 0;
   lep_MiniIso = 0;
   lep_ptRatio = 0;
   lep_ptRel = 0;
   lep_filtersMatched = 0;
   lep_dataMC = 0;
   lep_dataMCErr = 0;
   dataMC_VxBS = 0;
   dataMCErr_VxBS = 0;
   tau_id = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_mass = 0;
   pho_pt = 0;
   pho_eta = 0;
   pho_phi = 0;
   photonCutBasedIDLoose = 0;
   H_pt = 0;
   H_eta = 0;
   H_phi = 0;
   H_mass = 0;
   H_noFSR_pt = 0;
   H_noFSR_eta = 0;
   H_noFSR_phi = 0;
   H_noFSR_mass = 0;
   Z_pt = 0;
   Z_eta = 0;
   Z_phi = 0;
   Z_mass = 0;
   Z_noFSR_pt = 0;
   Z_noFSR_eta = 0;
   Z_noFSR_phi = 0;
   Z_noFSR_mass = 0;
   jet_iscleanH4l = 0;
   jet_pt = 0;
   jet_pt_raw = 0;
   jet_relpterr = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_phierr = 0;
   jet_bTagEffi = 0;
   jet_cTagEffi = 0;
   jet_udsgTagEffi = 0;
   jet_mass = 0;
   jet_jesup_iscleanH4l = 0;
   jet_jesup_pt = 0;
   jet_jesup_eta = 0;
   jet_jesup_phi = 0;
   jet_jesup_mass = 0;
   jet_jesdn_iscleanH4l = 0;
   jet_jesdn_pt = 0;
   jet_jesdn_eta = 0;
   jet_jesdn_phi = 0;
   jet_jesdn_mass = 0;
   jet_jerup_iscleanH4l = 0;
   jet_jerup_pt = 0;
   jet_jerup_eta = 0;
   jet_jerup_phi = 0;
   jet_jerup_mass = 0;
   jet_jerdn_iscleanH4l = 0;
   jet_jerdn_pt = 0;
   jet_jerdn_eta = 0;
   jet_jerdn_phi = 0;
   jet_jerdn_mass = 0;
   jet_pumva = 0;
   jet_csvv2 = 0;
   jet_csvv2_ = 0;
   jet_isbtag = 0;
   jet_hadronFlavour = 0;
   jet_partonFlavour = 0;
   jet_QGTagger = 0;
   jet_QGTagger_jesup = 0;
   jet_QGTagger_jesdn = 0;
   jet_axis2 = 0;
   jet_ptD = 0;
   jet_mult = 0;
   mergedjet_iscleanH4l = 0;
   mergedjet_pt = 0;
   mergedjet_eta = 0;
   mergedjet_phi = 0;
   mergedjet_mass = 0;
   mergedjet_tau1 = 0;
   mergedjet_tau2 = 0;
   mergedjet_btag = 0;
   mergedjet_L1 = 0;
   mergedjet_softdropmass = 0;
   mergedjet_prunedmass = 0;
   mergedjet_nsubjet = 0;
   mergedjet_subjet_pt = 0;
   mergedjet_subjet_eta = 0;
   mergedjet_subjet_phi = 0;
   mergedjet_subjet_mass = 0;
   mergedjet_subjet_btag = 0;
   mergedjet_subjet_partonFlavour = 0;
   mergedjet_subjet_hadronFlavour = 0;
   allfsrPhotons_dR = 0;
   allfsrPhotons_iso = 0;
   allfsrPhotons_pt = 0;
   fsrPhotons_lepindex = 0;
   fsrPhotons_pt = 0;
   fsrPhotons_pterr = 0;
   fsrPhotons_eta = 0;
   fsrPhotons_phi = 0;
   fsrPhotons_dR = 0;
   fsrPhotons_iso = 0;
   GENlep_pt = 0;
   GENlep_eta = 0;
   GENlep_phi = 0;
   GENlep_mass = 0;
   GENlep_id = 0;
   GENlep_status = 0;
   GENlep_MomId = 0;
   GENlep_MomMomId = 0;
   GENlep_isoCH = 0;
   GENlep_isoNH = 0;
   GENlep_isoPhot = 0;
   GENlep_RelIso = 0;
   GENH_pt = 0;
   GENH_eta = 0;
   GENH_phi = 0;
   GENH_mass = 0;
   GENZ_pt = 0;
   GENZ_eta = 0;
   GENZ_phi = 0;
   GENZ_mass = 0;
   GENZ_DaughtersId = 0;
   GENZ_MomId = 0;
   GENjet_pt = 0;
   GENjet_eta = 0;
   GENjet_phi = 0;
   GENjet_mass = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("LumiSect", &LumiSect, &b_LumiSect);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("nInt", &nInt, &b_nInt);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("BS_x", &BS_x, &b_BS_x);
   fChain->SetBranchAddress("BS_y", &BS_y, &b_BS_y);
   fChain->SetBranchAddress("BS_z", &BS_z, &b_BS_z);
   fChain->SetBranchAddress("BS_xErr", &BS_xErr, &b_BS_xErr);
   fChain->SetBranchAddress("BS_yErr", &BS_yErr, &b_BS_yErr);
   fChain->SetBranchAddress("BS_zErr", &BS_zErr, &b_BS_zErr);
   fChain->SetBranchAddress("BeamWidth_x", &BeamWidth_x, &b_BeamWidth_x);
   fChain->SetBranchAddress("BeamWidth_y", &BeamWidth_y, &b_BeamWidth_y);
   fChain->SetBranchAddress("BeamWidth_xErr", &BeamWidth_xErr, &b_BeamWidth_xErr);
   fChain->SetBranchAddress("BeamWidth_yErr", &BeamWidth_yErr, &b_BeamWidth_yErr);
   fChain->SetBranchAddress("finalState", &finalState, &b_finalState);
   fChain->SetBranchAddress("triggersPassed", &triggersPassed, &b_triggersPassed);
   fChain->SetBranchAddress("passedTrig", &passedTrig, &b_passedTrig);
   fChain->SetBranchAddress("passedFullSelection", &passedFullSelection, &b_passedFullSelection);
   fChain->SetBranchAddress("passedZ4lSelection", &passedZ4lSelection, &b_passedZ4lSelection);
   fChain->SetBranchAddress("passedQCDcut", &passedQCDcut, &b_passedQCDcut);
   fChain->SetBranchAddress("passedZ1LSelection", &passedZ1LSelection, &b_passedZ1LSelection);
   fChain->SetBranchAddress("passedZ4lZ1LSelection", &passedZ4lZ1LSelection, &b_passedZ4lZ1LSelection);
   fChain->SetBranchAddress("passedZ4lZXCRSelection", &passedZ4lZXCRSelection, &b_passedZ4lZXCRSelection);
   fChain->SetBranchAddress("passedZXCRSelection", &passedZXCRSelection, &b_passedZXCRSelection);
   fChain->SetBranchAddress("nZXCRFailedLeptons", &nZXCRFailedLeptons, &b_nZXCRFailedLeptons);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("k_ggZZ", &k_ggZZ, &b_k_ggZZ);
   fChain->SetBranchAddress("k_qqZZ_qcd_dPhi", &k_qqZZ_qcd_dPhi, &b_k_qqZZ_qcd_dPhi);
   fChain->SetBranchAddress("k_qqZZ_qcd_M", &k_qqZZ_qcd_M, &b_k_qqZZ_qcd_M);
   fChain->SetBranchAddress("k_qqZZ_qcd_Pt", &k_qqZZ_qcd_Pt, &b_k_qqZZ_qcd_Pt);
   fChain->SetBranchAddress("k_qqZZ_ewk", &k_qqZZ_ewk, &b_k_qqZZ_ewk);
   fChain->SetBranchAddress("qcdWeights", &qcdWeights, &b_qcdWeights);
   fChain->SetBranchAddress("nnloWeights", &nnloWeights, &b_nnloWeights);
   fChain->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   fChain->SetBranchAddress("pdfRMSup", &pdfRMSup, &b_pdfRMSup);
   fChain->SetBranchAddress("pdfRMSdown", &pdfRMSdown, &b_pdfRMSdown);
   fChain->SetBranchAddress("pdfENVup", &pdfENVup, &b_pdfENVup);
   fChain->SetBranchAddress("pdfENVdown", &pdfENVdown, &b_pdfENVdown);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("pileupWeightUp", &pileupWeightUp, &b_pileupWeightUp);
   fChain->SetBranchAddress("pileupWeightDn", &pileupWeightDn, &b_pileupWeightDn);
   fChain->SetBranchAddress("dataMCWeight", &dataMCWeight, &b_dataMCWeight);
   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);
   fChain->SetBranchAddress("prefiringWeight", &prefiringWeight, &b_prefiringWeight);
   fChain->SetBranchAddress("crossSection", &crossSection, &b_crossSection);
   fChain->SetBranchAddress("lep_d0BS", &lep_d0BS, &b_lep_d0BS);
   fChain->SetBranchAddress("lep_d0PV", &lep_d0PV, &b_lep_d0PV);
   fChain->SetBranchAddress("lep_numberOfValidPixelHits", &lep_numberOfValidPixelHits, &b_lep_numberOfValidPixelHits);
   fChain->SetBranchAddress("lep_trackerLayersWithMeasurement", &lep_trackerLayersWithMeasurement, &b_lep_trackerLayersWithMeasurement);
   fChain->SetBranchAddress("lep_chi2LocalPosition", &lep_chi2LocalPosition, &b_lep_chi2LocalPosition);
   fChain->SetBranchAddress("lep_trkKink", &lep_trkKink, &b_lep_trkKink);
   fChain->SetBranchAddress("lep_numberOfMatchedStations", &lep_numberOfMatchedStations, &b_lep_numberOfMatchedStations);
   fChain->SetBranchAddress("lep_validFraction", &lep_validFraction, &b_lep_validFraction);
   fChain->SetBranchAddress("lep_arbitrationType", &lep_arbitrationType, &b_lep_arbitrationType);
   fChain->SetBranchAddress("lep_normalizedChi2", &lep_normalizedChi2, &b_lep_normalizedChi2);
   fChain->SetBranchAddress("lep_numberOfValidMuonHits", &lep_numberOfValidMuonHits, &b_lep_numberOfValidMuonHits);
   fChain->SetBranchAddress("lep_p", &lep_p, &b_lep_p);
   fChain->SetBranchAddress("lep_ecalEnergy", &lep_ecalEnergy, &b_lep_ecalEnergy);
   fChain->SetBranchAddress("lep_isEB", &lep_isEB, &b_lep_isEB);
   fChain->SetBranchAddress("lep_isEE", &lep_isEE, &b_lep_isEE);
   fChain->SetBranchAddress("singleBS_Lep_pt", &singleBS_Lep_pt, &b_singleBS_Lep_pt);
   fChain->SetBranchAddress("singleBS_Lep_ptError", &singleBS_Lep_ptError, &b_singleBS_Lep_ptError);
   fChain->SetBranchAddress("singleBS_Lep_eta", &singleBS_Lep_eta, &b_singleBS_Lep_eta);
   fChain->SetBranchAddress("singleBS_Lep_phi", &singleBS_Lep_phi, &b_singleBS_Lep_phi);
   fChain->SetBranchAddress("singleBS_Lep_mass", &singleBS_Lep_mass, &b_singleBS_Lep_mass);
   fChain->SetBranchAddress("singleBS_Lep_d0", &singleBS_Lep_d0, &b_singleBS_Lep_d0);
   fChain->SetBranchAddress("vtxLep_BS_pt", &vtxLep_BS_pt, &b_vtxLep_BS_pt);
   fChain->SetBranchAddress("vtxLep_BS_pt_NoRoch", &vtxLep_BS_pt_NoRoch, &b_vtxLep_BS_pt_NoRoch);
   fChain->SetBranchAddress("vtxLep_BS_ptError", &vtxLep_BS_ptError, &b_vtxLep_BS_ptError);
   fChain->SetBranchAddress("vtxLep_BS_eta", &vtxLep_BS_eta, &b_vtxLep_BS_eta);
   fChain->SetBranchAddress("vtxLep_BS_phi", &vtxLep_BS_phi, &b_vtxLep_BS_phi);
   fChain->SetBranchAddress("vtxLep_BS_mass", &vtxLep_BS_mass, &b_vtxLep_BS_mass);
   fChain->SetBranchAddress("vtxLep_BS_d0", &vtxLep_BS_d0, &b_vtxLep_BS_d0);
   fChain->SetBranchAddress("vtxLep_pt", &vtxLep_pt, &b_vtxLep_pt);
   fChain->SetBranchAddress("vtxLep_ptError", &vtxLep_ptError, &b_vtxLep_ptError);
   fChain->SetBranchAddress("vtxLep_eta", &vtxLep_eta, &b_vtxLep_eta);
   fChain->SetBranchAddress("vtxLep_phi", &vtxLep_phi, &b_vtxLep_phi);
   fChain->SetBranchAddress("vtxLep_mass", &vtxLep_mass, &b_vtxLep_mass);
   fChain->SetBranchAddress("singleBS_FSR_Lep_pt", &singleBS_FSR_Lep_pt, &b_singleBS_FSR_Lep_pt);
   fChain->SetBranchAddress("singleBS_FSR_Lep_eta", &singleBS_FSR_Lep_eta, &b_singleBS_FSR_Lep_eta);
   fChain->SetBranchAddress("singleBS_FSR_Lep_phi", &singleBS_FSR_Lep_phi, &b_singleBS_FSR_Lep_phi);
   fChain->SetBranchAddress("singleBS_FSR_Lep_mass", &singleBS_FSR_Lep_mass, &b_singleBS_FSR_Lep_mass);
   fChain->SetBranchAddress("vtxLepFSR_BS_pt", &vtxLepFSR_BS_pt, &b_vtxLepFSR_BS_pt);
   fChain->SetBranchAddress("vtxLepFSR_BS_eta", &vtxLepFSR_BS_eta, &b_vtxLepFSR_BS_eta);
   fChain->SetBranchAddress("vtxLepFSR_BS_phi", &vtxLepFSR_BS_phi, &b_vtxLepFSR_BS_phi);
   fChain->SetBranchAddress("vtxLepFSR_BS_mass", &vtxLepFSR_BS_mass, &b_vtxLepFSR_BS_mass);
   fChain->SetBranchAddress("vtxLepFSR_pt", &vtxLepFSR_pt, &b_vtxLepFSR_pt);
   fChain->SetBranchAddress("vtxLepFSR_eta", &vtxLepFSR_eta, &b_vtxLepFSR_eta);
   fChain->SetBranchAddress("vtxLepFSR_phi", &vtxLepFSR_phi, &b_vtxLepFSR_phi);
   fChain->SetBranchAddress("vtxLepFSR_mass", &vtxLepFSR_mass, &b_vtxLepFSR_mass);
   fChain->SetBranchAddress("singleBS_RecoLep_pt", &singleBS_RecoLep_pt, &b_singleBS_RecoLep_pt);
   fChain->SetBranchAddress("singleBS_RecoLep_ptError", &singleBS_RecoLep_ptError, &b_singleBS_RecoLep_ptError);
   fChain->SetBranchAddress("singleBS_RecoLep_eta", &singleBS_RecoLep_eta, &b_singleBS_RecoLep_eta);
   fChain->SetBranchAddress("singleBS_RecoLep_phi", &singleBS_RecoLep_phi, &b_singleBS_RecoLep_phi);
   fChain->SetBranchAddress("singleBS_RecoLep_mass", &singleBS_RecoLep_mass, &b_singleBS_RecoLep_mass);
   fChain->SetBranchAddress("singleBS_RecoLep_d0", &singleBS_RecoLep_d0, &b_singleBS_RecoLep_d0);
   fChain->SetBranchAddress("vtxRecoLep_BS_pt", &vtxRecoLep_BS_pt, &b_vtxRecoLep_BS_pt);
   fChain->SetBranchAddress("vtxRecoLep_BS_ptError", &vtxRecoLep_BS_ptError, &b_vtxRecoLep_BS_ptError);
   fChain->SetBranchAddress("vtxRecoLep_BS_eta", &vtxRecoLep_BS_eta, &b_vtxRecoLep_BS_eta);
   fChain->SetBranchAddress("vtxRecoLep_BS_phi", &vtxRecoLep_BS_phi, &b_vtxRecoLep_BS_phi);
   fChain->SetBranchAddress("vtxRecoLep_BS_mass", &vtxRecoLep_BS_mass, &b_vtxRecoLep_BS_mass);
   fChain->SetBranchAddress("vtxRecoLep_BS_d0", &vtxRecoLep_BS_d0, &b_vtxRecoLep_BS_d0);
   fChain->SetBranchAddress("vtxRecoLep_pt", &vtxRecoLep_pt, &b_vtxRecoLep_pt);
   fChain->SetBranchAddress("vtxRecoLep_ptError", &vtxRecoLep_ptError, &b_vtxRecoLep_ptError);
   fChain->SetBranchAddress("vtxRecoLep_eta", &vtxRecoLep_eta, &b_vtxRecoLep_eta);
   fChain->SetBranchAddress("vtxRecoLep_phi", &vtxRecoLep_phi, &b_vtxRecoLep_phi);
   fChain->SetBranchAddress("vtxRecoLep_mass", &vtxRecoLep_mass, &b_vtxRecoLep_mass);
   fChain->SetBranchAddress("commonPV_x", &commonPV_x, &b_commonPV_x);
   fChain->SetBranchAddress("commonPV_y", &commonPV_y, &b_commonPV_y);
   fChain->SetBranchAddress("commonPV_z", &commonPV_z, &b_commonPV_z);
   fChain->SetBranchAddress("commonBS_x", &commonBS_x, &b_commonBS_x);
   fChain->SetBranchAddress("commonBS_y", &commonBS_y, &b_commonBS_y);
   fChain->SetBranchAddress("commonBS_z", &commonBS_z, &b_commonBS_z);
   fChain->SetBranchAddress("lep_pt_UnS", &lep_pt_UnS, &b_lep_pt_UnS);
   fChain->SetBranchAddress("lep_pterrold_UnS", &lep_pterrold_UnS, &b_lep_pterrold_UnS);
   fChain->SetBranchAddress("lep_errPre_Scale", &lep_errPre_Scale, &b_lep_errPre_Scale);
   fChain->SetBranchAddress("lep_errPost_Scale", &lep_errPost_Scale, &b_lep_errPost_Scale);
   fChain->SetBranchAddress("lep_errPre_noScale", &lep_errPre_noScale, &b_lep_errPre_noScale);
   fChain->SetBranchAddress("lep_errPost_noScale", &lep_errPost_noScale, &b_lep_errPost_noScale);
   fChain->SetBranchAddress("lep_pt_FromMuonBestTrack", &lep_pt_FromMuonBestTrack, &b_lep_pt_FromMuonBestTrack);
   fChain->SetBranchAddress("lep_eta_FromMuonBestTrack", &lep_eta_FromMuonBestTrack, &b_lep_eta_FromMuonBestTrack);
   fChain->SetBranchAddress("lep_phi_FromMuonBestTrack", &lep_phi_FromMuonBestTrack, &b_lep_phi_FromMuonBestTrack);
   fChain->SetBranchAddress("lep_position_x", &lep_position_x, &b_lep_position_x);
   fChain->SetBranchAddress("lep_position_y", &lep_position_y, &b_lep_position_y);
   fChain->SetBranchAddress("lep_position_z", &lep_position_z, &b_lep_position_z);
   fChain->SetBranchAddress("lep_pt_genFromReco", &lep_pt_genFromReco, &b_lep_pt_genFromReco);
   fChain->SetBranchAddress("lep_id", &lep_id, &b_lep_id);
   fChain->SetBranchAddress("lep_pt", &lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_pterr", &lep_pterr, &b_lep_pterr);
   fChain->SetBranchAddress("lep_pterrold", &lep_pterrold, &b_lep_pterrold);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_mass", &lep_mass, &b_lep_mass);
   fChain->SetBranchAddress("lepFSR_pt", &lepFSR_pt, &b_lepFSR_pt);
   fChain->SetBranchAddress("lepFSR_eta", &lepFSR_eta, &b_lepFSR_eta);
   fChain->SetBranchAddress("lepFSR_phi", &lepFSR_phi, &b_lepFSR_phi);
   fChain->SetBranchAddress("lepFSR_mass", &lepFSR_mass, &b_lepFSR_mass);
   fChain->SetBranchAddress("lep_Hindex", lep_Hindex, &b_lep_Hindex);
   fChain->SetBranchAddress("lep_genindex", &lep_genindex, &b_lep_genindex);
   fChain->SetBranchAddress("lep_matchedR03_PdgId", &lep_matchedR03_PdgId, &b_lep_matchedR03_PdgId);
   fChain->SetBranchAddress("lep_matchedR03_MomId", &lep_matchedR03_MomId, &b_lep_matchedR03_MomId);
   fChain->SetBranchAddress("lep_matchedR03_MomMomId", &lep_matchedR03_MomMomId, &b_lep_matchedR03_MomMomId);
   fChain->SetBranchAddress("lep_missingHits", &lep_missingHits, &b_lep_missingHits);
   fChain->SetBranchAddress("lep_mva", &lep_mva, &b_lep_mva);
   fChain->SetBranchAddress("lep_ecalDriven", &lep_ecalDriven, &b_lep_ecalDriven);
   fChain->SetBranchAddress("lep_tightId", &lep_tightId, &b_lep_tightId);
   fChain->SetBranchAddress("lep_tightIdSUS", &lep_tightIdSUS, &b_lep_tightIdSUS);
   fChain->SetBranchAddress("lep_tightIdHiPt", &lep_tightIdHiPt, &b_lep_tightIdHiPt);
   fChain->SetBranchAddress("lep_Sip", &lep_Sip, &b_lep_Sip);
   fChain->SetBranchAddress("lep_IP", &lep_IP, &b_lep_IP);
   fChain->SetBranchAddress("lep_isoNH", &lep_isoNH, &b_lep_isoNH);
   fChain->SetBranchAddress("lep_isoCH", &lep_isoCH, &b_lep_isoCH);
   fChain->SetBranchAddress("lep_isoPhot", &lep_isoPhot, &b_lep_isoPhot);
   fChain->SetBranchAddress("lep_isoPU", &lep_isoPU, &b_lep_isoPU);
   fChain->SetBranchAddress("lep_isoPUcorr", &lep_isoPUcorr, &b_lep_isoPUcorr);
   fChain->SetBranchAddress("lep_RelIso", &lep_RelIso, &b_lep_RelIso);
   fChain->SetBranchAddress("lep_RelIsoNoFSR", &lep_RelIsoNoFSR, &b_lep_RelIsoNoFSR);
   fChain->SetBranchAddress("lep_MiniIso", &lep_MiniIso, &b_lep_MiniIso);
   fChain->SetBranchAddress("lep_ptRatio", &lep_ptRatio, &b_lep_ptRatio);
   fChain->SetBranchAddress("lep_ptRel", &lep_ptRel, &b_lep_ptRel);
   fChain->SetBranchAddress("lep_filtersMatched", &lep_filtersMatched, &b_lep_filtersMatched);
   fChain->SetBranchAddress("lep_dataMC", &lep_dataMC, &b_lep_dataMC);
   fChain->SetBranchAddress("lep_dataMCErr", &lep_dataMCErr, &b_lep_dataMCErr);
   fChain->SetBranchAddress("dataMC_VxBS", &dataMC_VxBS, &b_dataMC_VxBS);
   fChain->SetBranchAddress("dataMCErr_VxBS", &dataMCErr_VxBS, &b_dataMCErr_VxBS);
   fChain->SetBranchAddress("nisoleptons", &nisoleptons, &b_nisoleptons);
   fChain->SetBranchAddress("muRho", &muRho, &b_muRho);
   fChain->SetBranchAddress("elRho", &elRho, &b_elRho);
   fChain->SetBranchAddress("pTL1", &pTL1, &b_pTL1);
   fChain->SetBranchAddress("pTL2", &pTL2, &b_pTL2);
   fChain->SetBranchAddress("pTL3", &pTL3, &b_pTL3);
   fChain->SetBranchAddress("pTL4", &pTL4, &b_pTL4);
   fChain->SetBranchAddress("idL1", &idL1, &b_idL1);
   fChain->SetBranchAddress("idL2", &idL2, &b_idL2);
   fChain->SetBranchAddress("idL3", &idL3, &b_idL3);
   fChain->SetBranchAddress("idL4", &idL4, &b_idL4);
   fChain->SetBranchAddress("etaL1", &etaL1, &b_etaL1);
   fChain->SetBranchAddress("etaL2", &etaL2, &b_etaL2);
   fChain->SetBranchAddress("etaL3", &etaL3, &b_etaL3);
   fChain->SetBranchAddress("etaL4", &etaL4, &b_etaL4);
   fChain->SetBranchAddress("mL1", &mL1, &b_mL1);
   fChain->SetBranchAddress("mL2", &mL2, &b_mL2);
   fChain->SetBranchAddress("mL3", &mL3, &b_mL3);
   fChain->SetBranchAddress("mL4", &mL4, &b_mL4);
   fChain->SetBranchAddress("pTErrL1", &pTErrL1, &b_pTErrL1);
   fChain->SetBranchAddress("pTErrL2", &pTErrL2, &b_pTErrL2);
   fChain->SetBranchAddress("pTErrL3", &pTErrL3, &b_pTErrL3);
   fChain->SetBranchAddress("pTErrL4", &pTErrL4, &b_pTErrL4);
   fChain->SetBranchAddress("phiL1", &phiL1, &b_phiL1);
   fChain->SetBranchAddress("phiL2", &phiL2, &b_phiL2);
   fChain->SetBranchAddress("phiL3", &phiL3, &b_phiL3);
   fChain->SetBranchAddress("phiL4", &phiL4, &b_phiL4);
   fChain->SetBranchAddress("pTL1FSR", &pTL1FSR, &b_pTL1FSR);
   fChain->SetBranchAddress("pTL2FSR", &pTL2FSR, &b_pTL2FSR);
   fChain->SetBranchAddress("pTL3FSR", &pTL3FSR, &b_pTL3FSR);
   fChain->SetBranchAddress("pTL4FSR", &pTL4FSR, &b_pTL4FSR);
   fChain->SetBranchAddress("etaL1FSR", &etaL1FSR, &b_etaL1FSR);
   fChain->SetBranchAddress("etaL2FSR", &etaL2FSR, &b_etaL2FSR);
   fChain->SetBranchAddress("etaL3FSR", &etaL3FSR, &b_etaL3FSR);
   fChain->SetBranchAddress("etaL4FSR", &etaL4FSR, &b_etaL4FSR);
   fChain->SetBranchAddress("phiL1FSR", &phiL1FSR, &b_phiL1FSR);
   fChain->SetBranchAddress("phiL2FSR", &phiL2FSR, &b_phiL2FSR);
   fChain->SetBranchAddress("phiL3FSR", &phiL3FSR, &b_phiL3FSR);
   fChain->SetBranchAddress("phiL4FSR", &phiL4FSR, &b_phiL4FSR);
   fChain->SetBranchAddress("mL1FSR", &mL1FSR, &b_mL1FSR);
   fChain->SetBranchAddress("mL2FSR", &mL2FSR, &b_mL2FSR);
   fChain->SetBranchAddress("mL3FSR", &mL3FSR, &b_mL3FSR);
   fChain->SetBranchAddress("mL4FSR", &mL4FSR, &b_mL4FSR);
   fChain->SetBranchAddress("pTErrL1FSR", &pTErrL1FSR, &b_pTErrL1FSR);
   fChain->SetBranchAddress("pTErrL2FSR", &pTErrL2FSR, &b_pTErrL2FSR);
   fChain->SetBranchAddress("pTErrL3FSR", &pTErrL3FSR, &b_pTErrL3FSR);
   fChain->SetBranchAddress("pTErrL4FSR", &pTErrL4FSR, &b_pTErrL4FSR);
   fChain->SetBranchAddress("tau_id", &tau_id, &b_tau_id);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_mass", &tau_mass, &b_tau_mass);
   fChain->SetBranchAddress("pho_pt", &pho_pt, &b_pho_pt);
   fChain->SetBranchAddress("pho_eta", &pho_eta, &b_pho_eta);
   fChain->SetBranchAddress("pho_phi", &pho_phi, &b_pho_phi);
   fChain->SetBranchAddress("photonCutBasedIDLoose", &photonCutBasedIDLoose, &b_photonCutBasedIDLoose);
   fChain->SetBranchAddress("H_pt", &H_pt, &b_H_pt);
   fChain->SetBranchAddress("H_eta", &H_eta, &b_H_eta);
   fChain->SetBranchAddress("H_phi", &H_phi, &b_H_phi);
   fChain->SetBranchAddress("H_mass", &H_mass, &b_H_mass);
   fChain->SetBranchAddress("H_noFSR_pt", &H_noFSR_pt, &b_H_noFSR_pt);
   fChain->SetBranchAddress("H_noFSR_eta", &H_noFSR_eta, &b_H_noFSR_eta);
   fChain->SetBranchAddress("H_noFSR_phi", &H_noFSR_phi, &b_H_noFSR_phi);
   fChain->SetBranchAddress("H_noFSR_mass", &H_noFSR_mass, &b_H_noFSR_mass);
   fChain->SetBranchAddress("mass4l", &mass4l, &b_mass4l);
   fChain->SetBranchAddress("mass4l_noFSR", &mass4l_noFSR, &b_mass4l_noFSR);
   fChain->SetBranchAddress("mass4lErr", &mass4lErr, &b_mass4lErr);
   fChain->SetBranchAddress("mass4lREFIT", &mass4lREFIT, &b_mass4lREFIT);
   fChain->SetBranchAddress("mass4lErrREFIT", &mass4lErrREFIT, &b_mass4lErrREFIT);
   fChain->SetBranchAddress("massZ1REFIT", &massZ1REFIT, &b_massZ1REFIT);
   fChain->SetBranchAddress("massZ2REFIT", &massZ2REFIT, &b_massZ2REFIT);
   fChain->SetBranchAddress("mass4l_singleBS", &mass4l_singleBS, &b_mass4l_singleBS);
   fChain->SetBranchAddress("mass4l_singleBS_FSR", &mass4l_singleBS_FSR, &b_mass4l_singleBS_FSR);
   fChain->SetBranchAddress("mass4lErr_singleBS", &mass4lErr_singleBS, &b_mass4lErr_singleBS);
   fChain->SetBranchAddress("mass4lREFIT_singleBS", &mass4lREFIT_singleBS, &b_mass4lREFIT_singleBS);
   fChain->SetBranchAddress("mass4lErrREFIT_singleBS", &mass4lErrREFIT_singleBS, &b_mass4lErrREFIT_singleBS);
   fChain->SetBranchAddress("massZ1REFIT_singleBS", &massZ1REFIT_singleBS, &b_massZ1REFIT_singleBS);
   fChain->SetBranchAddress("massZ2REFIT_singleBS", &massZ2REFIT_singleBS, &b_massZ2REFIT_singleBS);
   fChain->SetBranchAddress("mass4l_vtx_BS", &mass4l_vtx_BS, &b_mass4l_vtx_BS);
   fChain->SetBranchAddress("mass4l_vtxFSR_BS", &mass4l_vtxFSR_BS, &b_mass4l_vtxFSR_BS);
   fChain->SetBranchAddress("mass4lErr_vtx_BS", &mass4lErr_vtx_BS, &b_mass4lErr_vtx_BS);
   fChain->SetBranchAddress("mass4lREFIT_vtx_BS", &mass4lREFIT_vtx_BS, &b_mass4lREFIT_vtx_BS);
   fChain->SetBranchAddress("mass4lErrREFIT_vtx_BS", &mass4lErrREFIT_vtx_BS, &b_mass4lErrREFIT_vtx_BS);
   fChain->SetBranchAddress("massZ1REFIT_vtx_BS", &massZ1REFIT_vtx_BS, &b_massZ1REFIT_vtx_BS);
   fChain->SetBranchAddress("massZ2REFIT_vtx_BS", &massZ2REFIT_vtx_BS, &b_massZ2REFIT_vtx_BS);
   fChain->SetBranchAddress("mass4l_vtx", &mass4l_vtx, &b_mass4l_vtx);
   fChain->SetBranchAddress("mass4l_vtxFSR", &mass4l_vtxFSR, &b_mass4l_vtxFSR);
   fChain->SetBranchAddress("mass4lErr_vtx", &mass4lErr_vtx, &b_mass4lErr_vtx);
   fChain->SetBranchAddress("mass4lREFIT_vtx", &mass4lREFIT_vtx, &b_mass4lREFIT_vtx);
   fChain->SetBranchAddress("mass4lErrREFIT_vtx", &mass4lErrREFIT_vtx, &b_mass4lErrREFIT_vtx);
   fChain->SetBranchAddress("mass4mu", &mass4mu, &b_mass4mu);
   fChain->SetBranchAddress("mass4e", &mass4e, &b_mass4e);
   fChain->SetBranchAddress("mass2e2mu", &mass2e2mu, &b_mass2e2mu);
   fChain->SetBranchAddress("pT4l", &pT4l, &b_pT4l);
   fChain->SetBranchAddress("eta4l", &eta4l, &b_eta4l);
   fChain->SetBranchAddress("phi4l", &phi4l, &b_phi4l);
   fChain->SetBranchAddress("rapidity4l", &rapidity4l, &b_rapidity4l);
   fChain->SetBranchAddress("cosTheta1", &cosTheta1, &b_cosTheta1);
   fChain->SetBranchAddress("cosTheta2", &cosTheta2, &b_cosTheta2);
   fChain->SetBranchAddress("cosThetaStar", &cosThetaStar, &b_cosThetaStar);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Phi1", &Phi1, &b_Phi1);
   fChain->SetBranchAddress("mass3l", &mass3l, &b_mass3l);
   fChain->SetBranchAddress("massZ_vtx_chi2_BS", &massZ_vtx_chi2_BS, &b_massZ_vtx_chi2_BS);
   fChain->SetBranchAddress("massZ_vtx_chi2", &massZ_vtx_chi2, &b_massZ_vtx_chi2);
   fChain->SetBranchAddress("mass2l_vtx", &mass2l_vtx, &b_mass2l_vtx);
   fChain->SetBranchAddress("mass2l_vtx_BS", &mass2l_vtx_BS, &b_mass2l_vtx_BS);
   fChain->SetBranchAddress("Z_pt", &Z_pt, &b_Z_pt);
   fChain->SetBranchAddress("Z_eta", &Z_eta, &b_Z_eta);
   fChain->SetBranchAddress("Z_phi", &Z_phi, &b_Z_phi);
   fChain->SetBranchAddress("Z_mass", &Z_mass, &b_Z_mass);
   fChain->SetBranchAddress("Z_noFSR_pt", &Z_noFSR_pt, &b_Z_noFSR_pt);
   fChain->SetBranchAddress("Z_noFSR_eta", &Z_noFSR_eta, &b_Z_noFSR_eta);
   fChain->SetBranchAddress("Z_noFSR_phi", &Z_noFSR_phi, &b_Z_noFSR_phi);
   fChain->SetBranchAddress("Z_noFSR_mass", &Z_noFSR_mass, &b_Z_noFSR_mass);
   fChain->SetBranchAddress("Z_Hindex", Z_Hindex, &b_Z_Hindex);
   fChain->SetBranchAddress("massZ1", &massZ1, &b_massZ1);
   fChain->SetBranchAddress("massErrH_vtx", &massErrH_vtx, &b_massErrH_vtx);
   fChain->SetBranchAddress("massH_vtx_chi2_BS", &massH_vtx_chi2_BS, &b_massH_vtx_chi2_BS);
   fChain->SetBranchAddress("massH_vtx_chi2", &massH_vtx_chi2, &b_massH_vtx_chi2);
   fChain->SetBranchAddress("massZ1_Z1L", &massZ1_Z1L, &b_massZ1_Z1L);
   fChain->SetBranchAddress("massZ2", &massZ2, &b_massZ2);
   fChain->SetBranchAddress("pTZ1", &pTZ1, &b_pTZ1);
   fChain->SetBranchAddress("pTZ2", &pTZ2, &b_pTZ2);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_jesup", &met_jesup, &b_met_jesup);
   fChain->SetBranchAddress("met_phi_jesup", &met_phi_jesup, &b_met_phi_jesup);
   fChain->SetBranchAddress("met_jesdn", &met_jesdn, &b_met_jesdn);
   fChain->SetBranchAddress("met_phi_jesdn", &met_phi_jesdn, &b_met_phi_jesdn);
   fChain->SetBranchAddress("met_uncenup", &met_uncenup, &b_met_uncenup);
   fChain->SetBranchAddress("met_phi_uncenup", &met_phi_uncenup, &b_met_phi_uncenup);
   fChain->SetBranchAddress("met_uncendn", &met_uncendn, &b_met_uncendn);
   fChain->SetBranchAddress("met_phi_uncendn", &met_phi_uncendn, &b_met_phi_uncendn);
   fChain->SetBranchAddress("jet_iscleanH4l", &jet_iscleanH4l, &b_jet_iscleanH4l);
   fChain->SetBranchAddress("jet1index", &jet1index, &b_jet1index);
   fChain->SetBranchAddress("jet2index", &jet2index, &b_jet2index);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_pt_raw", &jet_pt_raw, &b_jet_pt_raw);
   fChain->SetBranchAddress("jet_relpterr", &jet_relpterr, &b_jet_relpterr);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_phierr", &jet_phierr, &b_jet_phierr);
   fChain->SetBranchAddress("jet_bTagEffi", &jet_bTagEffi, &b_jet_bTagEffi);
   fChain->SetBranchAddress("jet_cTagEffi", &jet_cTagEffi, &b_jet_cTagEffi);
   fChain->SetBranchAddress("jet_udsgTagEffi", &jet_udsgTagEffi, &b_jet_udsgTagEffi);
   fChain->SetBranchAddress("jet_mass", &jet_mass, &b_jet_mass);
   fChain->SetBranchAddress("jet_jesup_iscleanH4l", &jet_jesup_iscleanH4l, &b_jet_jesup_iscleanH4l);
   fChain->SetBranchAddress("jet_jesup_pt", &jet_jesup_pt, &b_jet_jesup_pt);
   fChain->SetBranchAddress("jet_jesup_eta", &jet_jesup_eta, &b_jet_jesup_eta);
   fChain->SetBranchAddress("jet_jesup_phi", &jet_jesup_phi, &b_jet_jesup_phi);
   fChain->SetBranchAddress("jet_jesup_mass", &jet_jesup_mass, &b_jet_jesup_mass);
   fChain->SetBranchAddress("jet_jesdn_iscleanH4l", &jet_jesdn_iscleanH4l, &b_jet_jesdn_iscleanH4l);
   fChain->SetBranchAddress("jet_jesdn_pt", &jet_jesdn_pt, &b_jet_jesdn_pt);
   fChain->SetBranchAddress("jet_jesdn_eta", &jet_jesdn_eta, &b_jet_jesdn_eta);
   fChain->SetBranchAddress("jet_jesdn_phi", &jet_jesdn_phi, &b_jet_jesdn_phi);
   fChain->SetBranchAddress("jet_jesdn_mass", &jet_jesdn_mass, &b_jet_jesdn_mass);
   fChain->SetBranchAddress("jet_jerup_iscleanH4l", &jet_jerup_iscleanH4l, &b_jet_jerup_iscleanH4l);
   fChain->SetBranchAddress("jet_jerup_pt", &jet_jerup_pt, &b_jet_jerup_pt);
   fChain->SetBranchAddress("jet_jerup_eta", &jet_jerup_eta, &b_jet_jerup_eta);
   fChain->SetBranchAddress("jet_jerup_phi", &jet_jerup_phi, &b_jet_jerup_phi);
   fChain->SetBranchAddress("jet_jerup_mass", &jet_jerup_mass, &b_jet_jerup_mass);
   fChain->SetBranchAddress("jet_jerdn_iscleanH4l", &jet_jerdn_iscleanH4l, &b_jet_jerdn_iscleanH4l);
   fChain->SetBranchAddress("jet_jerdn_pt", &jet_jerdn_pt, &b_jet_jerdn_pt);
   fChain->SetBranchAddress("jet_jerdn_eta", &jet_jerdn_eta, &b_jet_jerdn_eta);
   fChain->SetBranchAddress("jet_jerdn_phi", &jet_jerdn_phi, &b_jet_jerdn_phi);
   fChain->SetBranchAddress("jet_jerdn_mass", &jet_jerdn_mass, &b_jet_jerdn_mass);
   fChain->SetBranchAddress("jet_pumva", &jet_pumva, &b_jet_pumva);
   fChain->SetBranchAddress("jet_csvv2", &jet_csvv2, &b_jet_csvv2);
   fChain->SetBranchAddress("jet_csvv2_", &jet_csvv2_, &b_jet_csvv2_);
   fChain->SetBranchAddress("jet_isbtag", &jet_isbtag, &b_jet_isbtag);
   fChain->SetBranchAddress("jet_hadronFlavour", &jet_hadronFlavour, &b_jet_hadronFlavour);
   fChain->SetBranchAddress("jet_partonFlavour", &jet_partonFlavour, &b_jet_partonFlavour);
   fChain->SetBranchAddress("jet_QGTagger", &jet_QGTagger, &b_jet_QGTagger);
   fChain->SetBranchAddress("jet_QGTagger_jesup", &jet_QGTagger_jesup, &b_jet_QGTagger_jesup);
   fChain->SetBranchAddress("jet_QGTagger_jesdn", &jet_QGTagger_jesdn, &b_jet_QGTagger_jesdn);
   fChain->SetBranchAddress("jet_axis2", &jet_axis2, &b_jet_axis2);
   fChain->SetBranchAddress("jet_ptD", &jet_ptD, &b_jet_ptD);
   fChain->SetBranchAddress("jet_mult", &jet_mult, &b_jet_mult);
   fChain->SetBranchAddress("njets_pt30_eta4p7", &njets_pt30_eta4p7, &b_njets_pt30_eta4p7);
   fChain->SetBranchAddress("njets_pt30_eta4p7_jesup", &njets_pt30_eta4p7_jesup, &b_njets_pt30_eta4p7_jesup);
   fChain->SetBranchAddress("njets_pt30_eta4p7_jesdn", &njets_pt30_eta4p7_jesdn, &b_njets_pt30_eta4p7_jesdn);
   fChain->SetBranchAddress("njets_pt30_eta4p7_jerup", &njets_pt30_eta4p7_jerup, &b_njets_pt30_eta4p7_jerup);
   fChain->SetBranchAddress("njets_pt30_eta4p7_jerdn", &njets_pt30_eta4p7_jerdn, &b_njets_pt30_eta4p7_jerdn);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta4p7", &pt_leadingjet_pt30_eta4p7, &b_pt_leadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta4p7_jesup", &pt_leadingjet_pt30_eta4p7_jesup, &b_pt_leadingjet_pt30_eta4p7_jesup);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta4p7_jesdn", &pt_leadingjet_pt30_eta4p7_jesdn, &b_pt_leadingjet_pt30_eta4p7_jesdn);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta4p7_jerup", &pt_leadingjet_pt30_eta4p7_jerup, &b_pt_leadingjet_pt30_eta4p7_jerup);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta4p7_jerdn", &pt_leadingjet_pt30_eta4p7_jerdn, &b_pt_leadingjet_pt30_eta4p7_jerdn);
   fChain->SetBranchAddress("absrapidity_leadingjet_pt30_eta4p7", &absrapidity_leadingjet_pt30_eta4p7, &b_absrapidity_leadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("absrapidity_leadingjet_pt30_eta4p7_jesup", &absrapidity_leadingjet_pt30_eta4p7_jesup, &b_absrapidity_leadingjet_pt30_eta4p7_jesup);
   fChain->SetBranchAddress("absrapidity_leadingjet_pt30_eta4p7_jesdn", &absrapidity_leadingjet_pt30_eta4p7_jesdn, &b_absrapidity_leadingjet_pt30_eta4p7_jesdn);
   fChain->SetBranchAddress("absrapidity_leadingjet_pt30_eta4p7_jerup", &absrapidity_leadingjet_pt30_eta4p7_jerup, &b_absrapidity_leadingjet_pt30_eta4p7_jerup);
   fChain->SetBranchAddress("absrapidity_leadingjet_pt30_eta4p7_jerdn", &absrapidity_leadingjet_pt30_eta4p7_jerdn, &b_absrapidity_leadingjet_pt30_eta4p7_jerdn);
   fChain->SetBranchAddress("absdeltarapidity_hleadingjet_pt30_eta4p7", &absdeltarapidity_hleadingjet_pt30_eta4p7, &b_absdeltarapidity_hleadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("absdeltarapidity_hleadingjet_pt30_eta4p7_jesup", &absdeltarapidity_hleadingjet_pt30_eta4p7_jesup, &b_absdeltarapidity_hleadingjet_pt30_eta4p7_jesup);
   fChain->SetBranchAddress("absdeltarapidity_hleadingjet_pt30_eta4p7_jesdn", &absdeltarapidity_hleadingjet_pt30_eta4p7_jesdn, &b_absdeltarapidity_hleadingjet_pt30_eta4p7_jesdn);
   fChain->SetBranchAddress("absdeltarapidity_hleadingjet_pt30_eta4p7_jerup", &absdeltarapidity_hleadingjet_pt30_eta4p7_jerup, &b_absdeltarapidity_hleadingjet_pt30_eta4p7_jerup);
   fChain->SetBranchAddress("absdeltarapidity_hleadingjet_pt30_eta4p7_jerdn", &absdeltarapidity_hleadingjet_pt30_eta4p7_jerdn, &b_absdeltarapidity_hleadingjet_pt30_eta4p7_jerdn);
   fChain->SetBranchAddress("nbjets_pt30_eta4p7", &nbjets_pt30_eta4p7, &b_nbjets_pt30_eta4p7);
   fChain->SetBranchAddress("nvjets_pt40_eta2p4", &nvjets_pt40_eta2p4, &b_nvjets_pt40_eta2p4);
   fChain->SetBranchAddress("DijetMass", &DijetMass, &b_DijetMass);
   fChain->SetBranchAddress("DijetDEta", &DijetDEta, &b_DijetDEta);
   fChain->SetBranchAddress("DijetFisher", &DijetFisher, &b_DijetFisher);
   fChain->SetBranchAddress("njets_pt30_eta2p5", &njets_pt30_eta2p5, &b_njets_pt30_eta2p5);
   fChain->SetBranchAddress("njets_pt30_eta2p5_jesup", &njets_pt30_eta2p5_jesup, &b_njets_pt30_eta2p5_jesup);
   fChain->SetBranchAddress("njets_pt30_eta2p5_jesdn", &njets_pt30_eta2p5_jesdn, &b_njets_pt30_eta2p5_jesdn);
   fChain->SetBranchAddress("njets_pt30_eta2p5_jerup", &njets_pt30_eta2p5_jerup, &b_njets_pt30_eta2p5_jerup);
   fChain->SetBranchAddress("njets_pt30_eta2p5_jerdn", &njets_pt30_eta2p5_jerdn, &b_njets_pt30_eta2p5_jerdn);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta2p5", &pt_leadingjet_pt30_eta2p5, &b_pt_leadingjet_pt30_eta2p5);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta2p5_jesup", &pt_leadingjet_pt30_eta2p5_jesup, &b_pt_leadingjet_pt30_eta2p5_jesup);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta2p5_jesdn", &pt_leadingjet_pt30_eta2p5_jesdn, &b_pt_leadingjet_pt30_eta2p5_jesdn);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta2p5_jerup", &pt_leadingjet_pt30_eta2p5_jerup, &b_pt_leadingjet_pt30_eta2p5_jerup);
   fChain->SetBranchAddress("pt_leadingjet_pt30_eta2p5_jerdn", &pt_leadingjet_pt30_eta2p5_jerdn, &b_pt_leadingjet_pt30_eta2p5_jerdn);
   fChain->SetBranchAddress("mergedjet_iscleanH4l", &mergedjet_iscleanH4l, &b_mergedjet_iscleanH4l);
   fChain->SetBranchAddress("mergedjet_pt", &mergedjet_pt, &b_mergedjet_pt);
   fChain->SetBranchAddress("mergedjet_eta", &mergedjet_eta, &b_mergedjet_eta);
   fChain->SetBranchAddress("mergedjet_phi", &mergedjet_phi, &b_mergedjet_phi);
   fChain->SetBranchAddress("mergedjet_mass", &mergedjet_mass, &b_mergedjet_mass);
   fChain->SetBranchAddress("mergedjet_tau1", &mergedjet_tau1, &b_mergedjet_tau1);
   fChain->SetBranchAddress("mergedjet_tau2", &mergedjet_tau2, &b_mergedjet_tau2);
   fChain->SetBranchAddress("mergedjet_btag", &mergedjet_btag, &b_mergedjet_btag);
   fChain->SetBranchAddress("mergedjet_L1", &mergedjet_L1, &b_mergedjet_L1);
   fChain->SetBranchAddress("mergedjet_softdropmass", &mergedjet_softdropmass, &b_mergedjet_softdropmass);
   fChain->SetBranchAddress("mergedjet_prunedmass", &mergedjet_prunedmass, &b_mergedjet_prunedmass);
   fChain->SetBranchAddress("mergedjet_nsubjet", &mergedjet_nsubjet, &b_mergedjet_nsubjet);
   fChain->SetBranchAddress("mergedjet_subjet_pt", &mergedjet_subjet_pt, &b_mergedjet_subjet_pt);
   fChain->SetBranchAddress("mergedjet_subjet_eta", &mergedjet_subjet_eta, &b_mergedjet_subjet_eta);
   fChain->SetBranchAddress("mergedjet_subjet_phi", &mergedjet_subjet_phi, &b_mergedjet_subjet_phi);
   fChain->SetBranchAddress("mergedjet_subjet_mass", &mergedjet_subjet_mass, &b_mergedjet_subjet_mass);
   fChain->SetBranchAddress("mergedjet_subjet_btag", &mergedjet_subjet_btag, &b_mergedjet_subjet_btag);
   fChain->SetBranchAddress("mergedjet_subjet_partonFlavour", &mergedjet_subjet_partonFlavour, &b_mergedjet_subjet_partonFlavour);
   fChain->SetBranchAddress("mergedjet_subjet_hadronFlavour", &mergedjet_subjet_hadronFlavour, &b_mergedjet_subjet_hadronFlavour);
   fChain->SetBranchAddress("nFSRPhotons", &nFSRPhotons, &b_nFSRPhotons);
   fChain->SetBranchAddress("allfsrPhotons_dR", &allfsrPhotons_dR, &b_allfsrPhotons_dR);
   fChain->SetBranchAddress("allfsrPhotons_iso", &allfsrPhotons_iso, &b_allfsrPhotons_iso);
   fChain->SetBranchAddress("allfsrPhotons_pt", &allfsrPhotons_pt, &b_allfsrPhotons_pt);
   fChain->SetBranchAddress("fsrPhotons_lepindex", &fsrPhotons_lepindex, &b_fsrPhotons_lepindex);
   fChain->SetBranchAddress("fsrPhotons_pt", &fsrPhotons_pt, &b_fsrPhotons_pt);
   fChain->SetBranchAddress("fsrPhotons_pterr", &fsrPhotons_pterr, &b_fsrPhotons_pterr);
   fChain->SetBranchAddress("fsrPhotons_eta", &fsrPhotons_eta, &b_fsrPhotons_eta);
   fChain->SetBranchAddress("fsrPhotons_phi", &fsrPhotons_phi, &b_fsrPhotons_phi);
   fChain->SetBranchAddress("fsrPhotons_dR", &fsrPhotons_dR, &b_fsrPhotons_dR);
   fChain->SetBranchAddress("fsrPhotons_iso", &fsrPhotons_iso, &b_fsrPhotons_iso);
   fChain->SetBranchAddress("theta12", &theta12, &b_theta12);
   fChain->SetBranchAddress("theta13", &theta13, &b_theta13);
   fChain->SetBranchAddress("theta14", &theta14, &b_theta14);
   fChain->SetBranchAddress("minM3l", &minM3l, &b_minM3l);
   fChain->SetBranchAddress("Z4lmaxP", &Z4lmaxP, &b_Z4lmaxP);
   fChain->SetBranchAddress("minDeltR", &minDeltR, &b_minDeltR);
   fChain->SetBranchAddress("m3l_soft", &m3l_soft, &b_m3l_soft);
   fChain->SetBranchAddress("minMass2Lep", &minMass2Lep, &b_minMass2Lep);
   fChain->SetBranchAddress("maxMass2Lep", &maxMass2Lep, &b_maxMass2Lep);
   fChain->SetBranchAddress("thetaPhoton", &thetaPhoton, &b_thetaPhoton);
   fChain->SetBranchAddress("thetaPhotonZ", &thetaPhotonZ, &b_thetaPhotonZ);
   fChain->SetBranchAddress("EventCat", &EventCat, &b_EventCat);
   fChain->SetBranchAddress("GENfinalState", &GENfinalState, &b_GENfinalState);
   fChain->SetBranchAddress("passedFiducialSelection", &passedFiducialSelection, &b_passedFiducialSelection);
   fChain->SetBranchAddress("GENlep_pt", &GENlep_pt, &b_GENlep_pt);
   fChain->SetBranchAddress("GENlep_eta", &GENlep_eta, &b_GENlep_eta);
   fChain->SetBranchAddress("GENlep_phi", &GENlep_phi, &b_GENlep_phi);
   fChain->SetBranchAddress("GENlep_mass", &GENlep_mass, &b_GENlep_mass);
   fChain->SetBranchAddress("GENlep_id", &GENlep_id, &b_GENlep_id);
   fChain->SetBranchAddress("GENlep_status", &GENlep_status, &b_GENlep_status);
   fChain->SetBranchAddress("GENlep_MomId", &GENlep_MomId, &b_GENlep_MomId);
   fChain->SetBranchAddress("GENlep_MomMomId", &GENlep_MomMomId, &b_GENlep_MomMomId);
   fChain->SetBranchAddress("GENlep_Hindex", GENlep_Hindex, &b_GENlep_Hindex);
   fChain->SetBranchAddress("GENlep_isoCH", &GENlep_isoCH, &b_GENlep_isoCH);
   fChain->SetBranchAddress("GENlep_isoNH", &GENlep_isoNH, &b_GENlep_isoNH);
   fChain->SetBranchAddress("GENlep_isoPhot", &GENlep_isoPhot, &b_GENlep_isoPhot);
   fChain->SetBranchAddress("GENlep_RelIso", &GENlep_RelIso, &b_GENlep_RelIso);
   fChain->SetBranchAddress("GENH_pt", &GENH_pt, &b_GENH_pt);
   fChain->SetBranchAddress("GENH_eta", &GENH_eta, &b_GENH_eta);
   fChain->SetBranchAddress("GENH_phi", &GENH_phi, &b_GENH_phi);
   fChain->SetBranchAddress("GENH_mass", &GENH_mass, &b_GENH_mass);
   fChain->SetBranchAddress("GENmass4l", &GENmass4l, &b_GENmass4l);
   fChain->SetBranchAddress("GENmass4mu", &GENmass4mu, &b_GENmass4mu);
   fChain->SetBranchAddress("GENmass4e", &GENmass4e, &b_GENmass4e);
   fChain->SetBranchAddress("GENmass2e2mu", &GENmass2e2mu, &b_GENmass2e2mu);
   fChain->SetBranchAddress("GENpT4l", &GENpT4l, &b_GENpT4l);
   fChain->SetBranchAddress("GENeta4l", &GENeta4l, &b_GENeta4l);
   fChain->SetBranchAddress("GENrapidity4l", &GENrapidity4l, &b_GENrapidity4l);
   fChain->SetBranchAddress("GENcosTheta1", &GENcosTheta1, &b_GENcosTheta1);
   fChain->SetBranchAddress("GENcosTheta2", &GENcosTheta2, &b_GENcosTheta2);
   fChain->SetBranchAddress("GENcosThetaStar", &GENcosThetaStar, &b_GENcosThetaStar);
   fChain->SetBranchAddress("GENPhi", &GENPhi, &b_GENPhi);
   fChain->SetBranchAddress("GENPhi1", &GENPhi1, &b_GENPhi1);
   fChain->SetBranchAddress("GENMH", &GENMH, &b_GENMH);
   fChain->SetBranchAddress("GENZ_pt", &GENZ_pt, &b_GENZ_pt);
   fChain->SetBranchAddress("GENZ_eta", &GENZ_eta, &b_GENZ_eta);
   fChain->SetBranchAddress("GENZ_phi", &GENZ_phi, &b_GENZ_phi);
   fChain->SetBranchAddress("GENZ_mass", &GENZ_mass, &b_GENZ_mass);
   fChain->SetBranchAddress("GENZ_DaughtersId", &GENZ_DaughtersId, &b_GENZ_DaughtersId);
   fChain->SetBranchAddress("GENZ_MomId", &GENZ_MomId, &b_GENZ_MomId);
   fChain->SetBranchAddress("GENmassZ1", &GENmassZ1, &b_GENmassZ1);
   fChain->SetBranchAddress("GENmassZ2", &GENmassZ2, &b_GENmassZ2);
   fChain->SetBranchAddress("GENpTZ1", &GENpTZ1, &b_GENpTZ1);
   fChain->SetBranchAddress("GENpTZ2", &GENpTZ2, &b_GENpTZ2);
   fChain->SetBranchAddress("GENdPhiZZ", &GENdPhiZZ, &b_GENdPhiZZ);
   fChain->SetBranchAddress("GENmassZZ", &GENmassZZ, &b_GENmassZZ);
   fChain->SetBranchAddress("GENpTZZ", &GENpTZZ, &b_GENpTZZ);
   fChain->SetBranchAddress("GENHmass", &GENHmass, &b_GENHmass);
   fChain->SetBranchAddress("stage0cat", &stage0cat, &b_stage0cat);
   fChain->SetBranchAddress("stage1cat", &stage1cat, &b_stage1cat);
   fChain->SetBranchAddress("stage1p1cat", &stage1p1cat, &b_stage1p1cat);
   fChain->SetBranchAddress("stage1p2cat", &stage1p2cat, &b_stage1p2cat);
   fChain->SetBranchAddress("passedFiducialRivet", &passedFiducialRivet, &b_passedFiducialRivet);
   fChain->SetBranchAddress("GENpT4lRivet", &GENpT4lRivet, &b_GENpT4lRivet);
   fChain->SetBranchAddress("GENnjets_pt30_eta4p7Rivet", &GENnjets_pt30_eta4p7Rivet, &b_GENnjets_pt30_eta4p7Rivet);
   fChain->SetBranchAddress("GENpt_leadingjet_pt30_eta4p7Rivet", &GENpt_leadingjet_pt30_eta4p7Rivet, &b_GENpt_leadingjet_pt30_eta4p7Rivet);
   fChain->SetBranchAddress("GENjet_pt", &GENjet_pt, &b_GENjet_pt);
   fChain->SetBranchAddress("GENjet_eta", &GENjet_eta, &b_GENjet_eta);
   fChain->SetBranchAddress("GENjet_phi", &GENjet_phi, &b_GENjet_phi);
   fChain->SetBranchAddress("GENjet_mass", &GENjet_mass, &b_GENjet_mass);
   fChain->SetBranchAddress("GENnjets_pt30_eta4p7", &GENnjets_pt30_eta4p7, &b_GENnjets_pt30_eta4p7);
   fChain->SetBranchAddress("GENpt_leadingjet_pt30_eta4p7", &GENpt_leadingjet_pt30_eta4p7, &b_GENpt_leadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("GENabsrapidity_leadingjet_pt30_eta4p7", &GENabsrapidity_leadingjet_pt30_eta4p7, &b_GENabsrapidity_leadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("GENabsdeltarapidity_hleadingjet_pt30_eta4p7", &GENabsdeltarapidity_hleadingjet_pt30_eta4p7, &b_GENabsdeltarapidity_hleadingjet_pt30_eta4p7);
   fChain->SetBranchAddress("GENnjets_pt30_eta2p5", &GENnjets_pt30_eta2p5, &b_GENnjets_pt30_eta2p5);
   fChain->SetBranchAddress("GENpt_leadingjet_pt30_eta2p5", &GENpt_leadingjet_pt30_eta2p5, &b_GENpt_leadingjet_pt30_eta2p5);
   fChain->SetBranchAddress("lheNj", &lheNj, &b_lheNj);
   fChain->SetBranchAddress("lheNb", &lheNb, &b_lheNb);
   fChain->SetBranchAddress("nGenStatus2bHad", &nGenStatus2bHad, &b_nGenStatus2bHad);
   fChain->SetBranchAddress("me_0plus_JHU", &me_0plus_JHU, &b_me_0plus_JHU);
   fChain->SetBranchAddress("me_qqZZ_MCFM", &me_qqZZ_MCFM, &b_me_qqZZ_MCFM);
   fChain->SetBranchAddress("p0plus_m4l", &p0plus_m4l, &b_p0plus_m4l);
   fChain->SetBranchAddress("bkg_m4l", &bkg_m4l, &b_bkg_m4l);
   fChain->SetBranchAddress("D_bkg_kin", &D_bkg_kin, &b_D_bkg_kin);
   fChain->SetBranchAddress("D_bkg_kin_vtx_BS", &D_bkg_kin_vtx_BS, &b_D_bkg_kin_vtx_BS);
   fChain->SetBranchAddress("D_bkg", &D_bkg, &b_D_bkg);
   fChain->SetBranchAddress("Dgg10_VAMCFM", &Dgg10_VAMCFM, &b_Dgg10_VAMCFM);
   fChain->SetBranchAddress("D_g4", &D_g4, &b_D_g4);
   fChain->SetBranchAddress("D_g1g4", &D_g1g4, &b_D_g1g4);
   fChain->SetBranchAddress("D_VBF", &D_VBF, &b_D_VBF);
   fChain->SetBranchAddress("D_VBF1j", &D_VBF1j, &b_D_VBF1j);
   fChain->SetBranchAddress("D_HadWH", &D_HadWH, &b_D_HadWH);
   fChain->SetBranchAddress("D_HadZH", &D_HadZH, &b_D_HadZH);
   fChain->SetBranchAddress("D_bkg_VBFdec", &D_bkg_VBFdec, &b_D_bkg_VBFdec);
   fChain->SetBranchAddress("D_bkg_VHdec", &D_bkg_VHdec, &b_D_bkg_VHdec);
   fChain->SetBranchAddress("D_VBF_QG", &D_VBF_QG, &b_D_VBF_QG);
   fChain->SetBranchAddress("D_VBF1j_QG", &D_VBF1j_QG, &b_D_VBF1j_QG);
   fChain->SetBranchAddress("D_HadWH_QG", &D_HadWH_QG, &b_D_HadWH_QG);
   fChain->SetBranchAddress("D_HadZH_QG", &D_HadZH_QG, &b_D_HadZH_QG);
   Notify();
}

#endif // #ifdef MyClass_cxx
