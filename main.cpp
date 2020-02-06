
#include "LookUpTable.h"

#include <iostream>
#include <exception>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::exception;

int main() {
    vector<double> x;
    vector<double> y;
    vector<double> z;

    try {
        exampleReadData("lookupTab.txt", x, y, z);
    } catch(const exception& e) {
        cerr << "Failed to read file: " << e.what() << endl;
        return -1;
    }

    cout << "Lookup table: \n";
    cout << "Count x: " << x.size() << "\n";
    cout << "Count y: " << y.size() << "\n";
    cout << "Count z: " << z.size() << "\n\n";

    size_t limit = x.size();

    for(size_t i = 0; i < limit; i++) {
        cout << i << " : " << x[i] << ", " << y[i] << ", " << z[i] << "\n";
    }
    cout << endl;

    return 0;
}
