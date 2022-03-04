#define gm_cxx
#include "gm.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void gm::Loop()
{

  int achit;
  double aex[1000],aey[1000],atx[1000],aty[1000];
  TFile *fout=new TFile("ebc01.root","RECREATE");
  TTree *tout=new TTree("tree","tree");
  tout->Branch("achit",&achit,"achit/I");
  tout->Branch("aex",&aex,"aex[achit]/D");
  tout->Branch("aey",&aey,"aey[achit]/D");
  tout->Branch("atx",&atx,"atx[achit]/D");
  tout->Branch("aty",&aty,"aty[achit]/D");
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
          achit=0;
    for(int i=0; i<ahit; i++) {
        for(int j=0; j<ahit; j++) {
            if(i==j) continue;
            aex[achit]=ae[i];
            aey[achit]=ae[j];
            atx[achit]=at[i];
            aty[achit]=at[j];
            achit++;
        }
    }
    if(achit>0) tout->Fill();
    if(jentry%100000==0) cout<<jentry<<endl;;
   }
   tout->Write();
   fout->Close();
}
