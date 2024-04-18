#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <memory>
#include "Utils.hpp"

using namespace std;
using namespace RateReturnLib;

int main()
{
    string filename = "data.csv";
    double S;
    unsigned int n;
    double* w = nullptr;
    double* r = nullptr;

    if (!readData(filename, S, n, w, r))
        return 1;

    double earnings = calculateEarnings(w,r,n,S);;
    cout << fixed << setprecision(2) << earnings <<endl;

    string sw = ArrayToString(n,w);
    string sr = ArrayToString(n,r);

    writeResults("result.txt", S, n, sw, sr, earnings);

    delete [] w;
    delete [] r;

  return 0;
}

