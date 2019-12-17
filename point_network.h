#ifndef _PointNetwork
#define _PointNetwork

#include "point.h"
#include "network.h"
using namespace std;

//base network class
class PointNetwork : public Network{
	private:
		int numPoints,
		    dimension;
		vector <Point> points;
	
	public:
		PointNetwork() : Network() {
			numPoints = 0;
		}
		
	    PointNetwork(char *fileName, mt19937* mr, bool std):Network(fileName) {
	    	randGen = mr;
	    	FILE* fin = fopen(fileName, "r");
	    	char s[10001];
	    	fgets(s, 10000, fin);
	    	dimension = 0;
	    	for (int i=0; s[i]; ++i) {
	    		if (s[i] == ' ') {
	    			++dimension;
				}
			}
			numPoints = 1;
			while (fgets(s, 10000, fin)) {
				++numPoints;
			}
			fclose(fin);
			fin = fopen(fileName, "r");
			vector <double> c(dimension);
			points.resize(numPoints);
			int line = 0;
	    	while (1) {
	    		char n[110];
				int i;
	    		for (i=0; i<dimension; ++i) {
	    			if (fscanf(fin, "%lf", &c[i]) == EOF) {
	    				break;
					}
				}
				if (i<dimension) {
					break;
				}
				fscanf(fin, "%s", n);
	    		points[line] = Point(n, c, line);
	    		++line;
			}
	    	numPoints = points.size();
	    	printf("Network loading complete. Total %d points loaded with dimension %d\n", numPoints, dimension);
	    	fclose(fin);
	    	if (std) {
	    		standardize();
			}
		}
		
		~PointNetwork() {
			
		}
		
		void standardize() {
			int i, j;
			double mn, mx;
			mn = mx = points[0].coordinates[0];
			for (i=0; i<numPoints; ++i) {
				for (j=0; j<dimension; ++j) {
					mx = max(mx, points[i].coordinates[j]);
					mn = min(mn, points[i].coordinates[j]);
				}
			}
			for (i=0; i<numPoints; ++i) {
				points[i].standardize(mn, mx);
			}
		}
		
		int randomIndex() {
			return (*randGen)() % numPoints;
		}
		
		int randomIndex(set <int> &indexToExclude) {
			int i;
			while (1) {
				i = (*randGen)() % (numPoints - 1);
				if (indexToExclude.find(i) == indexToExclude.end()) {
					return i;
				}
			}
		}
		
		vector <Point*> randomPoints(int n) {
			set <int> s;
			int i;
			vector <Point*> ans;
			while (ans.size()<n) {
				i = randomIndex(s);
				ans.push_back(&points[i]);
			}
			return ans;
		}
};
#endif
