#ifndef _Config
#define _Config

class Config {
	public:
		int seed,
			numVehicles,
			k;
		bool standardize,
			debug;
		double maxV,
			minV;
		map <string, string> inputArg;
		
		Config() {
			setDefault();
		}
		
		Config(int argc, char** argv) {
			setDefault();
			for (int i=1; i<argc; i+=2) {
				inputArg[argv[i]] = argv[i+1];
			}
			
			if (inputArg.find("-seed")!=inputArg.end()) {
				seed = toInt(inputArg["-seed"]);
				assert(seed>=0);
			}
			
			if (inputArg.find("-standardize")!=inputArg.end()) {
				standardize = toBool(inputArg["-standardize"]);
			}
			
			if (inputArg.find("-debug")!=inputArg.end()) {
				debug = toBool(inputArg["-debug"]);
			}
			
			if (inputArg.find("-maxv")!=inputArg.end()) {
				maxV = toDouble(inputArg["-maxv"]);
				assert(maxV>=0);
			}
			
			if (inputArg.find("-minv")!=inputArg.end()) {
				maxV = toDouble(inputArg["-minv"]);
				assert(minV>=0);
			}
			
			if (inputArg.find("-k")!=inputArg.end()) {
				k = toInt(inputArg["-k"]);
				assert(k>0);
				
			}
			
			if (inputArg.find("-numv")!=inputArg.end()) {
				numVehicles = toInt(inputArg["-numv"]);
				assert(numVehicles>0);
			}
		}
		
		static printArgList() {
			Config conf = Config();
			printf("Valid arguments:\n");
			printf("\t-seed: [int]random seed, default %d\n", conf.seed);
			printf("\t-standardize: [boolean]standardize network coordinates to [0,1], default %s\n", conf.standardize ? "true":"false");
			printf("\t-debug: [boolean]debugging mode flag, default%s\n", conf.debug ? "true":"false");
			printf("\t-maxv: [float]maximum velocity of vehicles, default %.1f\n", conf.maxV);
			printf("\t-maxv: [float]minimum velocity of vehicles, default %.1f\n", conf.minV);
			printf("\t-k: [int]number of clusters, default %d\n", conf.k);
			printf("\t-numv: [int]number of vehicles, default %d\n", conf.numVehicles);
		}
	
	private:
		int toInt(string c) {
			int s = 0;
			sscanf(c.c_str(), "%d", &s);
			return s;
		}
		
		double toDouble(string c) {
			double s = 0;
			sscanf(c.c_str(), "%lf", &s);
			return s;
		}
		
		bool toBool(string c) {
			for (int i=0; i<c.length(); ++i) {
				c[i] = tolower(c[i]);
			}
			if (c=="0" || c=="false" || c=="f") {
				return 0;
			}
			return 1;
		}
		
		void setDefault() {
			seed = 0;
			standardize = 1;
			maxV = 1;
			minV = 0.1;
			k = 1;
			numVehicles = 64;
			debug = 0;
		}
};
#endif
