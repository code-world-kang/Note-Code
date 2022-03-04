//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 26 11:17:40 2019 by ROOT version 6.14/02
// from TTree t1//rarf/w/r04/chenrj/root/runmust20077.root
// found on file: runmust20077.root
//////////////////////////////////////////////////////////

#ifndef ppac_h
#define ppac_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"

class ppac {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunNumber;
   Int_t           EventNumber;
   Int_t           Trig[16];
   Int_t           GATCONF;
   Float_t         MM_LEFT_PLF7;
   Float_t         MM_LEFT_PPAC;
   Float_t         FPPosition[12][4];
   Float_t         FPTime[12][6];
   Float_t         FPdE[12][3];
 //TMust2Data      *Must2;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   vector<UShort_t> fMM_StripXE_DetectorNbr;
   vector<UShort_t> fMM_StripXE_StripNbr;
   vector<Double_t> fMM_StripXE_Energy;
   vector<UShort_t> fMM_StripXT_DetectorNbr;
   vector<UShort_t> fMM_StripXT_StripNbr;
   vector<Double_t> fMM_StripXT_Time;
   vector<UShort_t> fMM_StripYE_DetectorNbr;
   vector<UShort_t> fMM_StripYE_StripNbr;
   vector<Double_t> fMM_StripYE_Energy;
   vector<UShort_t> fMM_StripYT_DetectorNbr;
   vector<UShort_t> fMM_StripYT_StripNbr;
   vector<Double_t> fMM_StripYT_Time;
   vector<UShort_t> fMM_SiLiE_DetectorNbr;
   vector<UShort_t> fMM_SiLiE_PadNbr;
   vector<Double_t> fMM_SiLiE_Energy;
   vector<UShort_t> fMM_SiLiT_DetectorNbr;
   vector<UShort_t> fMM_SiLiT_PadNbr;
   vector<Double_t> fMM_SiLiT_Time;
   vector<UShort_t> fMM_CsIE_DetectorNbr;
   vector<UShort_t> fMM_CsIE_CristalNbr;
   vector<Double_t> fMM_CsIE_Energy;
   vector<UShort_t> fMM_CsIT_DetectorNbr;
   vector<UShort_t> fMM_CsIT_CristalNbr;
   vector<Double_t> fMM_CsIT_Time;
   Float_t         PPACF8[5][5];
   Float_t         PPACF5[5][5];
   Float_t         PPACF9[5][5];
   Float_t         F5PPACRawData[5][10];
   Float_t         F8PPACRawData[5][10];
   Float_t         F9PPACRawData[5][10];
   Float_t         F10PPACRawData[5][10];
   Float_t         F11PPACRawData[5][10];
   Float_t         F3PlaRawData[4];
   Float_t         F7PlaRawData[4];
   Float_t         F11PlaRawData[4];
   Float_t         F11ICRawData[10];
   Float_t         TOF[8];
   Float_t         AoQ[9][4];

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_Trig;   //!
   TBranch        *b_GATCONF;   //!
   TBranch        *b_MM_LEFT_PLF7;   //!
   TBranch        *b_MM_LEFT_PPAC;   //!
   TBranch        *b_FPPosition;   //!
   TBranch        *b_FPTime;   //!
   TBranch        *b_FPdE;   //!
   TBranch        *b_Must2_fUniqueID;   //!
   TBranch        *b_Must2_fBits;   //!
   TBranch        *b_Must2_fMM_StripXE_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_StripXE_StripNbr;   //!
   TBranch        *b_Must2_fMM_StripXE_Energy;   //!
   TBranch        *b_Must2_fMM_StripXT_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_StripXT_StripNbr;   //!
   TBranch        *b_Must2_fMM_StripXT_Time;   //!
   TBranch        *b_Must2_fMM_StripYE_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_StripYE_StripNbr;   //!
   TBranch        *b_Must2_fMM_StripYE_Energy;   //!
   TBranch        *b_Must2_fMM_StripYT_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_StripYT_StripNbr;   //!
   TBranch        *b_Must2_fMM_StripYT_Time;   //!
   TBranch        *b_Must2_fMM_SiLiE_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_SiLiE_PadNbr;   //!
   TBranch        *b_Must2_fMM_SiLiE_Energy;   //!
   TBranch        *b_Must2_fMM_SiLiT_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_SiLiT_PadNbr;   //!
   TBranch        *b_Must2_fMM_SiLiT_Time;   //!
   TBranch        *b_Must2_fMM_CsIE_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_CsIE_CristalNbr;   //!
   TBranch        *b_Must2_fMM_CsIE_Energy;   //!
   TBranch        *b_Must2_fMM_CsIT_DetectorNbr;   //!
   TBranch        *b_Must2_fMM_CsIT_CristalNbr;   //!
   TBranch        *b_Must2_fMM_CsIT_Time;   //!
   TBranch        *b_PPACF8;   //!
   TBranch        *b_PPACF5;   //!
   TBranch        *b_PPACF9;   //!
   TBranch        *b_F5PPACRawData;   //!
   TBranch        *b_F8PPACRawData;   //!
   TBranch        *b_F9PPACRawData;   //!
   TBranch        *b_F10PPACRawData;   //!
   TBranch        *b_F11PPACRawData;   //!
   TBranch        *b_F3PlaRawData;   //!
   TBranch        *b_F7PlaRawData;   //!
   TBranch        *b_F11PlaRawData;   //!
   TBranch        *b_F11ICRawData;   //!
   TBranch        *b_TOF;   //!
   TBranch        *b_AoQ;   //!

   ppac(TTree *tree=0);
   virtual ~ppac();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ppac_cxx
ppac::ppac(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("runmust20077.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("runmust20077.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

ppac::~ppac()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ppac::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ppac::LoadTree(Long64_t entry)
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

void ppac::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("Trig", Trig, &b_Trig);
   fChain->SetBranchAddress("GATCONF", &GATCONF, &b_GATCONF);
   fChain->SetBranchAddress("MM_LEFT_PLF7", &MM_LEFT_PLF7, &b_MM_LEFT_PLF7);
   fChain->SetBranchAddress("MM_LEFT_PPAC", &MM_LEFT_PPAC, &b_MM_LEFT_PPAC);
   fChain->SetBranchAddress("FPPosition", FPPosition, &b_FPPosition);
   fChain->SetBranchAddress("FPTime", FPTime, &b_FPTime);
   fChain->SetBranchAddress("FPdE", FPdE, &b_FPdE);
   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_Must2_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_Must2_fBits);
   fChain->SetBranchAddress("fMM_StripXE_DetectorNbr", &fMM_StripXE_DetectorNbr, &b_Must2_fMM_StripXE_DetectorNbr);
   fChain->SetBranchAddress("fMM_StripXE_StripNbr", &fMM_StripXE_StripNbr, &b_Must2_fMM_StripXE_StripNbr);
   fChain->SetBranchAddress("fMM_StripXE_Energy", &fMM_StripXE_Energy, &b_Must2_fMM_StripXE_Energy);
   fChain->SetBranchAddress("fMM_StripXT_DetectorNbr", &fMM_StripXT_DetectorNbr, &b_Must2_fMM_StripXT_DetectorNbr);
   fChain->SetBranchAddress("fMM_StripXT_StripNbr", &fMM_StripXT_StripNbr, &b_Must2_fMM_StripXT_StripNbr);
   fChain->SetBranchAddress("fMM_StripXT_Time", &fMM_StripXT_Time, &b_Must2_fMM_StripXT_Time);
   fChain->SetBranchAddress("fMM_StripYE_DetectorNbr", &fMM_StripYE_DetectorNbr, &b_Must2_fMM_StripYE_DetectorNbr);
   fChain->SetBranchAddress("fMM_StripYE_StripNbr", &fMM_StripYE_StripNbr, &b_Must2_fMM_StripYE_StripNbr);
   fChain->SetBranchAddress("fMM_StripYE_Energy", &fMM_StripYE_Energy, &b_Must2_fMM_StripYE_Energy);
   fChain->SetBranchAddress("fMM_StripYT_DetectorNbr", &fMM_StripYT_DetectorNbr, &b_Must2_fMM_StripYT_DetectorNbr);
   fChain->SetBranchAddress("fMM_StripYT_StripNbr", &fMM_StripYT_StripNbr, &b_Must2_fMM_StripYT_StripNbr);
   fChain->SetBranchAddress("fMM_StripYT_Time", &fMM_StripYT_Time, &b_Must2_fMM_StripYT_Time);
   fChain->SetBranchAddress("fMM_SiLiE_DetectorNbr", &fMM_SiLiE_DetectorNbr, &b_Must2_fMM_SiLiE_DetectorNbr);
   fChain->SetBranchAddress("fMM_SiLiE_PadNbr", &fMM_SiLiE_PadNbr, &b_Must2_fMM_SiLiE_PadNbr);
   fChain->SetBranchAddress("fMM_SiLiE_Energy", &fMM_SiLiE_Energy, &b_Must2_fMM_SiLiE_Energy);
   fChain->SetBranchAddress("fMM_SiLiT_DetectorNbr", &fMM_SiLiT_DetectorNbr, &b_Must2_fMM_SiLiT_DetectorNbr);
   fChain->SetBranchAddress("fMM_SiLiT_PadNbr", &fMM_SiLiT_PadNbr, &b_Must2_fMM_SiLiT_PadNbr);
   fChain->SetBranchAddress("fMM_SiLiT_Time", &fMM_SiLiT_Time, &b_Must2_fMM_SiLiT_Time);
   fChain->SetBranchAddress("fMM_CsIE_DetectorNbr", &fMM_CsIE_DetectorNbr, &b_Must2_fMM_CsIE_DetectorNbr);
   fChain->SetBranchAddress("fMM_CsIE_CristalNbr", &fMM_CsIE_CristalNbr, &b_Must2_fMM_CsIE_CristalNbr);
   fChain->SetBranchAddress("fMM_CsIE_Energy", &fMM_CsIE_Energy, &b_Must2_fMM_CsIE_Energy);
   fChain->SetBranchAddress("fMM_CsIT_DetectorNbr", &fMM_CsIT_DetectorNbr, &b_Must2_fMM_CsIT_DetectorNbr);
   fChain->SetBranchAddress("fMM_CsIT_CristalNbr", &fMM_CsIT_CristalNbr, &b_Must2_fMM_CsIT_CristalNbr);
   fChain->SetBranchAddress("fMM_CsIT_Time", &fMM_CsIT_Time, &b_Must2_fMM_CsIT_Time);
   fChain->SetBranchAddress("PPACF8", PPACF8, &b_PPACF8);
   fChain->SetBranchAddress("PPACF5", PPACF5, &b_PPACF5);
   fChain->SetBranchAddress("PPACF9", PPACF9, &b_PPACF9);
   fChain->SetBranchAddress("F5PPACRawData", F5PPACRawData, &b_F5PPACRawData);
   fChain->SetBranchAddress("F8PPACRawData", F8PPACRawData, &b_F8PPACRawData);
   fChain->SetBranchAddress("F9PPACRawData", F9PPACRawData, &b_F9PPACRawData);
   fChain->SetBranchAddress("F10PPACRawData", F10PPACRawData, &b_F10PPACRawData);
   fChain->SetBranchAddress("F11PPACRawData", F11PPACRawData, &b_F11PPACRawData);
   fChain->SetBranchAddress("F3PlaRawData", F3PlaRawData, &b_F3PlaRawData);
   fChain->SetBranchAddress("F7PlaRawData", F7PlaRawData, &b_F7PlaRawData);
   fChain->SetBranchAddress("F11PlaRawData", F11PlaRawData, &b_F11PlaRawData);
   fChain->SetBranchAddress("F11ICRawData", F11ICRawData, &b_F11ICRawData);
   fChain->SetBranchAddress("TOF", TOF, &b_TOF);
   fChain->SetBranchAddress("AoQ", AoQ, &b_AoQ);
   Notify();
}

Bool_t ppac::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ppac::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ppac::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ppac_cxx
