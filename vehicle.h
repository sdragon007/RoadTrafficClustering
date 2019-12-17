#ifndef _Vehicle
#define _Vehicle
#include <bits/stdc++.h>
#include "point_network.h"
using namespace std;

class Vehicle {
	public:
		mt19937* randGen;
		int index;
		Point *source,
			*destination,
			direction,
			current;
		double velocity,
			minV,
			maxV;
		PointNetwork* network;
		
		Vehicle() {
			
		}
		
		virtual ~Vehicle() {
			
		}
		
		virtual void move() {
			
		}
			
		void setV() {
			uniform_real_distribution<double> dist(minV, maxV);
			velocity = dist(*randGen);
		}
		
		virtual void setSrcDst() {
			
		}
		
		virtual void printInformation() {
			printf("Vehicle index %d with current velocity %.3f\n", index, velocity);
			printf("\tsource: ");
			source->print();
			printf("\tdestination: ");
			destination->print();
			printf("\tcurrent position: ");
			current.print();
			printf("\tcurrent unit direction: ");
			direction.print();
		}
};
#endif
