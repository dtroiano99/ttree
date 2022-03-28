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
#endif // #ifdef MyClass_cxx
