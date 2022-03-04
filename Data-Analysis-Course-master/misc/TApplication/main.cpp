#include <fstream>
#include <iostream>

#include <TString.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TROOT.h>
#include <TApplication.h>

#include "tracking.h"

using namespace std;

int main(int argc, char **argv){
    Int_t runNum = 8;
    if(argc == 2)
	runNum = atoi(argv[1]);

	TApplication * app = new TApplication("myApp", &argc, argv);
    tracking * track = new tracking(runNum);
    track->Loop();

	app->Run();
	delete app;
    return 0;
}
