#include "Utils.hpp"
#include <iostream>
using namespace std;

namespace RateReturnLib{

bool readData(const string& filename, double& S,unsigned int& n, double* &w, double* &r){
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "File open fail" << endl;
        return false;
    }

    string line;
    getline(file,line);
    istringstream convert(line);
    char a, separatore;
    convert >> a >> separatore >> S;

    getline(file,line);
    istringstream convert2(line);
    char b;
    convert2 >> b >> separatore >> n;

    getline(file,line);

    w = new double[n];
    r = new double[n];
    int i = 0;
    while(getline(file,line)){
        istringstream convert3(line);
        convert3 >> w[i] >> separatore >> r[i];
        i++;
    }

    file.close();
    return true;
}

double calculateEarnings(const double* const& w,const double* const& r,unsigned int &n, double &S){
    double earnings = 0.0;
    for(unsigned int i=0; i<n; i++){
        earnings += (1 + r[i]) * (S * w[i]);
    }
    return earnings;
}

double calculateRate(double earnings, double S){
    return (earnings/S)-1;
}

void writeResults(const string& filename, double &S,unsigned int &n, const string &sw, const string &sr, double &earnings){
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Failed to open output file" << endl;
        return;
    }

    outFile << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    outFile << "w = " << sw << endl;
    outFile << "r = " << sr << endl;

    outFile << "Rate of return of the portfolio: " << fixed << setprecision(4) << calculateRate(earnings, S) << endl;
    outFile << "V: " << fixed << setprecision(2) << earnings <<endl;
    outFile.close();
}

string ArrayToString(const unsigned int &n, const double* const &v){
    string str;
    ostringstream toString;
    toString<< "[ ";
    for(unsigned int i = 0; i<n; i++){
        toString << v[i] << " ";
    }
    toString << "]";
    return toString.str();
}

}
