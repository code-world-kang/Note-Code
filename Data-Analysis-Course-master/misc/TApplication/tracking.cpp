#define tracking_cxx
#include "tracking.h"

void tracking::Loop()
{
	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();

	Long64_t nbytes = 0, nb = 0;

	fChain->SetBranchStatus("*",0);
	fChain->SetBranchStatus("PPACF8",1);
	fChain->SetBranchStatus("beamTrig",1);	
	fChain->SetBranchStatus("must2Trig",1);
	Initial();

	cout<<nentries<<endl;
	int nbeam=0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		int mustTrig=0;
		for(int i=0;i<8;i++) mustTrig += must2Trig[i];
	       	if(mustTrig==1) {
		  Track();
		  nbeam++;
		  }
		if(nbeam%200==0){
			if(gSystem->ProcessEvents()) break;
			c1->cd(1);
			htf8x->Draw("colz");	target->Draw("same");
			ppac1->Draw("same");ppac2->Draw("same");ppac3->Draw("same");

			c1->cd(2);
			htf8y->Draw("colz");target->Draw("same");
			ppac1->Draw("same");ppac2->Draw("same");ppac3->Draw("same");

			c1->cd(3);
			htar->Draw("colz");

			c1->cd();

			c1->Modified();
			c1->Update();
		}

	}
}

void tracking::SetTrace(TH2F *h,Double_t k,Double_t b,Int_t min,Int_t max){
	if(h==0) return;
	if(min>=max) return;

	for(int i=min;i<max;i++){
		h->Fill(i,(Int_t)(i*k+b));
	}
}

void tracking::Track(){
	Double_t xx[5];
	Double_t xz[5];
	Double_t yy[5];
	Double_t yz[5];
	Int_t xcnt=0;
	Int_t ycnt=0;
	Bool_t xflag[3];
	Bool_t yflag[3];
	for(int i=0;i<3;i++) {
		xflag[i]=false;
		yflag[i]=false;
	}
	for(int i=0;i<5;i++){
		if(PPACF8[i][0]>-999) {
			xx[xcnt]=PPACF8[i][0];
			xz[xcnt]=PPACF8[i][2];
			xcnt++;
			xflag[i/2]=true;
		}
		if(PPACF8[i][1]>-999) {
			yy[ycnt]=PPACF8[i][1];
			yz[ycnt]=PPACF8[i][3];
			ycnt++;
			yflag[i/2]=true;
		}
	}
	Int_t cxflag=0;
	Int_t cyflag=0;
	for(int i=0;i<3;i++){
		if(xflag[i]) cxflag++;
		if(yflag[i]) cyflag++;
	}

	if(cxflag>=2){
		TGraph *grx=new TGraph(xcnt,xz,xx);
		TF1 *fx=new TF1("fx","pol1",-2000,0);
		grx->Fit(fx,"q+");

		SetTrace(htf8x,fx->GetParameter(1),fx->GetParameter(0),-1800,0);
		tx=fx->Eval(0);
		delete grx;
		delete fx;
	}
	if(cyflag>=2){
		TGraph *gry=new TGraph(ycnt,yz,yy);
		TF1 *fy=new TF1("fy","pol1",-2000,0);
		gry->Fit(fy,"q+");

		SetTrace(htf8y,fy->GetParameter(1),fy->GetParameter(0),-1800,0);
		ty=fy->Eval(0);
		delete gry;
		delete fy;
	}
	if(tx>-999&&ty>-999) htar->Fill(tx,ty);
}

void tracking::Initial(){
	if(htf8x==0) htf8x=new TH2F("htf8x","x trace by ppac",2200,-2000,200,300,-150,150);
	else htf8x->Reset();
	if(htf8y==0) htf8y=new TH2F("htf8y","y trace by ppac",2200,-2000,200,300,-150,150);
	else htf8y->Reset();
	if(htar==0) htar=new TH2F("htar","distribution on target",100,-50,50,100,-50,50);
	else htar->Reset();
	if(c1==0){
		c1=new TCanvas();
		c1->Divide(2,2);
	}
	if(target==0) target=new TLine(0,-50,0,50);
	target->SetLineWidth(2);
	if(ppac1==0) ppac1=new TLine(-1736,-50,-1736,50);
	if(ppac2==0) ppac2=new TLine(-1236,-50,-1236,50);
	if(ppac3==0) ppac3=new TLine(-377,-50,-377,50);
}

