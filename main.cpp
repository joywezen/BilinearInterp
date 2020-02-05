#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>

using namespace std;


int main()
{
  Eigen::MatrixXd  xx;
  Eigen::VectorXd  x;
  Eigen::VectorXd  y;
  Eigen::VectorXd  z;
  ifstream ReadData;
  stringstream strStream;
  printData pt;
  int n=0;


  string strTemp;
  string::size_type sz;
  ReadData.open("lookupTab.txt",ios::in); // readonly
  //check lookupTab is opened correctly:
    if (ReadData.fail()) //unsucessful open
    {
        cerr << "Error in opening the lookupTab.txt!\n";
        exit (1);//exit if unsucessful
    }
    else //file is available
    {
        cout << "sucessfully opened the lookupTab.txt\n";
        while (getline(ReadData,strTemp,'\n')) //(ReadData>>strTemp)//
        {
        cout <<  strTemp.length() << endl;
        cout <<  stod(strTemp,&sz) << endl;
        cout <<  stod(strTemp.substr(sz)) << endl;
        //xx(n,0)=stod(strTemp);
       // cout <<  xx(n,0) << endl;
            n++;
        }
        //xx.transpose();
       // xx.resize(3,101);

        ReadData.close();

    }

  return 0;
}
