#include <iostream>
#include "BasePlusCommissionEmployee.h"
using std::cout;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
const string &first, const string &last, const string &ssn,
double sales, double rate, double salary )
// explicitly call base-class constructor
: CommissionEmployee( first, last, ssn, sales, rate )
{
setBaseSalary( salary ); // validate and store base salary
setBonus( 100.0 );
} // end BasePlusCommissionEmployee constructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
return baseSalary;
}
void BasePlusCommissionEmployee::setBonus( double bon )
{
bonus = bon;
} // end function setBaseSalary

double BasePlusCommissionEmployee::getBonus() const
{
return bonus;
} // end function setBaseSalary

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
// derived class cannot access the base class’s private data
return baseSalary + ( commissionRate * grossSales )+bonus;
} // end function earnings

// print BasePlusCommissionEmployee object
void BasePlusCommissionEmployee::print() const
{
// derived class cannot access the base class’s private data
cout << "base-salaried commission employee: " << firstName << ' '
<< lastName << "\nsocial security number: " << socialSecurityNumber
<< "\ngross sales: " << grossSales
<< "\ncommission rate: " << commissionRate
<< "\nbase salary: " << baseSalary
<< "\nbonus: " << bonus;
} // end function print