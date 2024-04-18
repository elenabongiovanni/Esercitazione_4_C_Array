#ifndef __RATERETURN_H
#define __RATERETURN_H

#include "iostream"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
namespace RateReturnLib{

double calculateEarnings(const double* const &w, const double* const &r,unsigned int &n, double &S);
double calculateRate(double earnings, double S);
bool readData(const string& filename, double& S, unsigned int &n, double* &w, double* &r);
void writeResults(const string& filename, double &S,unsigned int &n, const string &sw, const string &sr, double &earnings);
string ArrayToString(const unsigned int &n, const double* const &v);

}

#endif
