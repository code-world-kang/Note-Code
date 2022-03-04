void treeover(){
 const Double_t nD=500;//cm, distance between target and the scin.(Center)
 const Double_t nL=100;//cm, half length of the scin.
 const Double_t nTh=5;//cm, thickness of the scin.
 const Double_t ts=1./2.36;//ns, sigma of time of the scin.
 const Double_t lambda=380;//cm, attenuation lenght of the scin.
 const Double_t Qs=0.1;//relative energy resolution of the scin. 
 const Double_t vsc=7.5;//ns/cm, speed of light in the scin.

 //neutron & gamma
 const Double_t En0=50;//MeV, average neutron energy
 const Double_t Ens=10;//MeV, sigma of En
 const Double_t Eg0=2;//MeV, gamma energy  

 const Double_t ngeff=0.5;//=Nn,g/Nbeam， 1-eff = ratio of events with no real TDC&ADC signal: 
 const Double_t rgamma=0.1;//ratio of gamma, neutron=0.9; 

 //charged particle hited in Neutron Detector, 
 const Double_t cpeff=0.1;//ratio of charge particle
 const Double_t Ec0=100;//MeV
 const Double_t Ecs=5;//MeV

 //ADC
 const Double_t ADCgain=60;//1MeV=60ch.
 const Double_t ADCuPed=100;//baseline of ADC
 const Double_t ADCdPed=120;
 const Double_t ADCnoise=10;//sigma of noise
 const Double_t ADCoverflow=5000.;

 //TDC
 const Double_t TDCgain=40;//1ns=40ch.
 const Double_t TDCoverflow=5000;
  
  TFile *opf=new TFile("treeover.root","recreate");//新文件tree.root的指针 *opf
  TTree *opt=new TTree("tree","tree structure");//新tree的指针 *opt
  // 在tree结构中定义需要的变量分支
  Double_t x;
  Double_t E;
  Double_t L;
  int ng;
  Double_t TOF, nTOF;
  Double_t tu, td;
  Double_t Qu, Qd;
    
  Double_t tu_off=5.5;//time offset
  Double_t td_off=20.4;//time offset
 
  // 将变量分支添加到tree结构中,第一个参数为变量名称，第二个为上面定义的变量地址，第三个为变量的类型说明，D表示Double_t。
  opt->Branch("x", &x, "x/D");//position of neutron
  opt->Branch("E", &E, "E/D");//energy of gamma or neutron
  opt->Branch("TOF", &TOF, "TOF/D");//time of flight
  opt->Branch("L",&L,"L/D");
  opt->Branch("nTOF",&nTOF,"nTOF/D");//TOF from exp. data
  opt->Branch("ng", &ng, "ng/I");//1/0 : neutron/gamma  
  opt->Branch("tu", &tu, "tu/D");//time of upper side
  opt->Branch("td", &td, "td/D");//time of bottom side
  opt->Branch("Qu", &Qu, "Qu/D");//Q 
  opt->Branch("Qd", &Qd, "Qd/D");//Q  

  TRandom3 *gr=new TRandom3(0);
  // 循环，逐事件往tree结构里添加对应分支信息。
  for(int i=0;i<1000000;i++){
    x=gr->Uniform(-nL, nL);
    Double_t D=nD+gr->Uniform(-0.5,0.5)*nTh;
    L=TMath::Sqrt(D*D+x*x)*0.01;//m, flight path
    
    if(gr->Uniform()<ngeff) {
      if(gr->Uniform() < rgamma) { //gamma
	ng=0;
	E=Eg0;
	TOF=3*L;
      }
      else {  //neutron
        ng=1;
        E=gr->Gaus(En0, Ens); // neutron
        TOF=72./TMath::Sqrt(E)*L;
      }
    }
    else if(gr->Uniform()<cpeff) {//charged particle
      ng=2;
      E=gr->Gaus(Ec0, Ecs); // neutron
      TOF=72./TMath::Sqrt(E)*L;
    }
    else {//no particle hit neutron detector
      ng=3;
    }
  
    if(ng==3) {//
      tu=TDCoverflow;
      td=TDCoverflow;
      Qu=ADCuPed+gr->Gaus(0,ADCnoise);
      Qd=ADCdPed+gr->Gaus(0,ADCnoise);
    }
    else {
      tu=TOF+(nL-x)/vsc+gr->Gaus(0,ts)+tu_off;
      td=TOF+(nL+x)/vsc+gr->Gaus(0,ts)+td_off;
      tu *=TDCgain;
      td *=TDCgain;

      Double_t Q=E*ADCgain*gr->Uniform();//neutron &gamma
      if(ng==2) Q=E*ADCgain;//charged particle
      Qu=Q*TMath::Exp(-(nL-x)/lambda);
      Qu=gr->Gaus(Qu,Qs*Qu)+ADCuPed+gr->Gaus(0,ADCnoise);
      Qd=Q*TMath::Exp(-(nL+x)/lambda);
      Qd=gr->Gaus(Qd,Qs*Qd)+ADCdPed+gr->Gaus(0,ADCnoise);
      if(gr->Uniform()<0.1) {
	tu=TDCoverflow;
	Qu=ADCuPed+gr->Gaus(0,ADCnoise);
      }
      if(gr->Uniform()>0.9) {
	td=TDCoverflow;
	Qd=ADCdPed+gr->Gaus(0,ADCnoise);
      }
    }
    if(tu>TDCoverflow) tu=TDCoverflow;
    if(td>TDCoverflow) td=TDCoverflow;
    if(Qu>ADCoverflow) Qu=ADCoverflow;
    if(Qd>ADCoverflow) Qd=ADCoverflow;
    opt->Fill();
  }
  // 将数据写入root文件中
  opt->Write();
  opf->Close();
}
