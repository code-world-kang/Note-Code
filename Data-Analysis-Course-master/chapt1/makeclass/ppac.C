#define ppac_cxx
#include "ppac.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

TH1D *h1=new TH1D("h1","h1",2000,0,2000);
void ppac::Loop()
{   
    //Ttree *fChain - Pointer pointing to the tree
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
       //user code
     if(jentry %10 ==0) h1->Fill(F8PPACRawData[0][1]+F8PPACRawData[0][0]-2*F8PPACRawData[0][4]);
   }
    h1->Draw();
}
