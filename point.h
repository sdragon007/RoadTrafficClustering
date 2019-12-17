#ifndef _Point
#define _Point

#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))

class Point {
	public:
		string name;
		int index;
		vector <double> coordinates;
		
	Point() {
		name = "";
		index = -1;
	}
	
	Point(string n, vector <double> c, int i) {
		name = n;
		coordinates = c;
		index = i;
	}
	
	~Point() {
		
	}
	
	double distance(Point p) {
		double t=0, i;
		for (i=coordinates.size()-1; i>=0; --i) {
			t += sqr(coordinates[i] - coordinates[i]);
		}
		return sqrt(t);
	}
	
	void standardize(double mn, double mx) {
		for (int i=coordinates.size()-1; i>=0; --i) {
			coordinates[i] = (coordinates[i] - mn) / (mx - mn);
		}
	}
	
	void print() {
		printf("(");
		for (int i=0; i<coordinates.size(); ++i) {
			printf(" %.3f ", coordinates[i]);
		}
		printf(" )\n");
	}
};
#endif
