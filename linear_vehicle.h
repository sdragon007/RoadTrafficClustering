#ifndef _LinearVehicle
#define _LinearVehicle

#include "vehicle.h"
using namespace std;

class LinearVehicle : public Vehicle {
	public:
		LinearVehicle() : Vehicle() {
			
		}
		
		LinearVehicle(int id, double minv, double maxv, mt19937* mr, PointNetwork* net) : Vehicle() {
			index = id;
			randGen = mr;
			minV = minv;
			maxV = maxv;
			network = net;
			setV();
			setSrcDst();
		}
		
		~LinearVehicle() {
			
		}
		
		void move() {
			
		}
		
		void setSrcDst() {
			vector <Point*> v = network->randomPoints(2);
			source = v[0];
			destination = v[1];
			current = *source;
			direction = *destination;
			int d=direction.coordinates.size();
			double s=0;
			for (int i=0; i<d; ++i) {
				direction.coordinates[i] -= source->coordinates[i];
				s += sqr(direction.coordinates[i]);
			}
			s = sqrt(s);
			for (int i=0; i<d; ++i) {
				direction.coordinates[i] /= s;
			}
		}
};
#endif
