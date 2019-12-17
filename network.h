#ifndef _Network
#define _Network

#include <bits/stdc++.h>
using namespace std;

//base network class
class Network {
	public:
		mt19937* randGen;
		
		Network() {
			
		}
		
	    Network(char *fileName) {
			printf("Loading network data from file: \"%s\"\n", fileName);
		}
		
		virtual ~Network() {
			
		}
};

#endif
