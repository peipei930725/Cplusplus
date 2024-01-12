#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h" // CommissionEmployee class declaration
using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
BasePlusCommissionEmployee( const string &, const string &,
const string &, double = 0.0, double = 0.0, double = 0.0 );

void setBaseSalary( double ); // set base salary
double getBaseSalary() const; // return base salary
void setBonus( double ); // set base salary
double getBonus() const; // return base salary

double earnings() const; // calculate earnings
void print() const; // print BasePlusCommissionEmployee object
private:
double baseSalary; // base salary
double bonus;
}; // end class BasePlusCommissionEmployee

#endif