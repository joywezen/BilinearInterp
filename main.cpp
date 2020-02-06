
#include "LookUpTable.h"

#include <iostream>
#include <exception>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::exception;

class PubData {
public:
int getValue(double TargetPubData) const {return TargetPubData;};
vector<double> y;
vector<double> z;
vector<double> x;
};

class PriData {
private:
    vector<double> x;
    vector<double> y;
    vector<double> z;
public:

    int getPrivateDoubleValue(double TargetPrivateDouble) const  {return TargetPrivateDouble;};
    vector <double>& getPrivateVectorX() {return x;}; //need &
    vector <double>& getPrivateVectorY() {return y;}; //need &
    vector <double>& getPrivateVectorZ() {return z;}; //need &
;
};

double DummyInterpfun (double UserInputX, double UserInputY)
{
double UserOutputZ;

UserOutputZ=(UserInputX+UserInputY)/2;
return UserOutputZ;
};

int main() {
PriData TabData; // define as Public data
double UserInputX, UserInputY, UserOutputZ;
    try {
        exampleReadData("lookupTab.txt", TabData.getPrivateVectorX(), TabData.getPrivateVectorY(), TabData.getPrivateVectorZ());
    } catch(const exception& e) {
        cerr << "Failed to read file: " << e.what() << endl;
        return -1;
    }

    cout << "Lookup table: \n";
    cout << "Count x: " << TabData.getPrivateVectorX().size() << "\n";
    cout << "Count y: " << TabData.getPrivateVectorY().size() << "\n";
    cout << "Count z: " << TabData.getPrivateVectorZ().size() << "\n\n";

    size_t limit = TabData.getPrivateVectorX().size();

    for(size_t i = 0; i < limit-1; i++) {
        cout << i << " : " << TabData.getPrivateDoubleValue(TabData.getPrivateVectorX()[i]) << ", " << TabData.getPrivateDoubleValue(TabData.getPrivateVectorY()[i]) << ", " << TabData.getPrivateDoubleValue(TabData.getPrivateVectorZ()[i]) << "\n";
    }
    cout << endl;

    cout << "Enter coordinate X: ";
    cin >> UserInputX;
    cout << "Enter coorfdinate Y: ";
    cin >> UserInputY;
    cout << "start dummy interpolation \n";
    UserOutputZ=DummyInterpfun(UserInputX,UserInputY);
    cout << "The UserOutputZ is:" << UserOutputZ << "\n" <<endl;
    return 0;
}
