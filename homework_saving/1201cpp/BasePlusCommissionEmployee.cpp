#include <iostream>
#include "BasePlusCommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
const string &first, const string &last, const string &ssn,
double sales, double rate,double salary )
{
firstName = first; // should validate
lastName = last; // should validate
socialSecurityNumber = ssn; // should validate
setGrossSales( sales ); // validate and store gross sales
setCommissionRate( rate ); // validate and store commission rate
setBaseSalary( salary ); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set first name
void BasePlusCommissionEmployee::setFirstName( const string &first )
{
firstName = first; // should validate
} // end function setFirstName

// return first name
string BasePlusCommissionEmployee::getFirstName() const
{
return firstName;
} // end function getFirstName

void BasePlusCommissionEmployee::setLastName( const string &last )
{
lastName = last;
} 

// return first name
string BasePlusCommissionEmployee::getLastName() const
{
return lastName;
} 

void BasePlusCommissionEmployee::setSocialSecurityNumber( const string &SSName )
{
socialSecurityNumber = SSName;
} 

// return first name
string BasePlusCommissionEmployee::getSocialSecurityNumber() const
{
return socialSecurityNumber;
} 

void BasePlusCommissionEmployee::setGrossSales(double GS )
{
grossSales = GS;
} 

// return first name
double BasePlusCommissionEmployee::getGrossSales() const
{
return grossSales;
} 

void BasePlusCommissionEmployee::setCommissionRate(double CR )
{
commissionRate = CR;
} 

// return first name
double BasePlusCommissionEmployee::getCommissionRate() const
{
return commissionRate;
} 

// set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
return baseSalary;
} // end function getBaseSalary

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
return baseSalary + ( commissionRate * grossSales );
} // end function earnings

// print BasePlusCommissionEmployee object
void BasePlusCommissionEmployee::print() const
{
cout << "commission employee: " << firstName << ' ' << lastName
<< "\nsocial security number: " << socialSecurityNumber
<< "\ngross sales: " << grossSales
<< "\ncommission rate: " << commissionRate
<< "\nbase salary: " << baseSalary;

} // end function print 