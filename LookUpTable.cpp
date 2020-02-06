
#include "LookUpTable.h"

#include <fstream>
#include <stdexcept>

using std::string;
using std::vector;
using std::ifstream;
using std::runtime_error;

void exampleReadData(string filename, vector<double>& vx, vector<double>& vy, vector<double>& vz) {
    ifstream ins(filename);
    if(ins.fail()) {
        string errMsg = "Cannot open file " + filename;
        throw runtime_error(errMsg.c_str());
    }
    while(ins.good()) {
        double x, y, z;
        ins >> x >> y >> z;
        vx.push_back(x);
        vy.push_back(y);
        vz.push_back(z);
    }
}
