#include <bits/stdc++.h>
#include "point_network.h"
#include "config.h"
#include "linear_vehicle.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc%2==0) {
		printf("Incorrect arguments\n");
		Config().printArgList();
		return 0;
	}
	if (argc>1) {
		printf("Execution arguments:\n");
		for (int i=1; i<argc; i+=2) {
			printf("%s %s\n", argv[i], argv[i+1]);
		}
	}
	Config conf = Config(argc, argv);
	printf("Random seed initiated as: %d\n", conf.seed);
	mt19937 mrand=mt19937(conf.seed);
	PointNetwork network = PointNetwork((char *)"data/caldata.txt", &mrand, conf.standardize);
	
	vector <LinearVehicle> vehicles(conf.numVehicles);
	for (int i=0; i<conf.numVehicles; i++) {
		vehicles[i] = LinearVehicle(i, conf.minV, conf.maxV, &mrand, &network);
		if (conf.debug) {
			vehicles[i].printInformation();
		}
	}
	
	return 0;
}
