
#include "LookUpTable.h"

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::exception;


class PriData {
private:
    vector<double> x;
    vector<double> y;
    vector<double> z;

    void loadData(string filename){
    try {
        exampleReadData(filename, x, y, z);
    } catch(const exception& e) {
        cerr << "Failed to read file: " << e.what() << endl;
    return;
    }
    };
    double PrivateInterpolationMethod(double Xin,double Yin){
    double Zout=(pow(2,Xin)+pow(2,Yin));
    return Zout;
    };
public:
    string userInputFilename;
    double UserInputX,UserInputY,UserOutputZ;

    void doLoadData(void){
        cout << "please enter file name________" << "##note: must be a .txt file##" << endl;
        //cin >> userInputFilename;
        //in case input file name manually. Automatic filling of file type can be helpful.
        userInputFilename="lookupTab.txt";
        loadData(userInputFilename);
        cout << "Data Loaded"<< endl;
        return;
   };

    void doprintData(void){
        cout << "Lookup table: \n";
        cout << "Count x: " << x.size() << "\n";
        cout << "Count y: " << y.size() << "\n";
        cout << "Count z: " << z.size() << "\n\n";

        size_t limit = x.size();

        for(size_t i = 0; i < limit-1; i++) {
        cout << i << " : " << x[i] << ", " << y[i] << ", " << z[i] << "\n";
        }
        cout << endl;
        };

    void doInterpolation(void){
    cout << "Start interpolation\n Please Enter Coordinate X: ";
    cin >> UserInputX;
    cout << "Enter coorfdinate Y: ";
    cin >> UserInputY;
    cout << "start dummy interpolation \n";
    UserOutputZ=PrivateInterpolationMethod(UserInputX,UserInputY);
    cout << "Interpolation result is:" << UserOutputZ << "\n" <<endl;
    return;
    };

};


int main() {

    PriData ThriDimData;

    ThriDimData.doLoadData();
    //ThriDimData.doprintData();
    ThriDimData.doInterpolation();

    return 0;
}

