#include <iostream>
#include "CommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(
const string &first, const string &last, const string &ssn,
double sales, double rate )
{
firstName = first; // should validate
lastName = last; // should validate
socialSecurityNumber = ssn; // should validate
setGrossSales( sales ); // validate and store gross sales
setCommissionRate( rate ); // validate and store commission rate
} // end CommissionEmployee constructor

// set first name
void CommissionEmployee::setFirstName( const string &first )
{
firstName = first; // should validate
} // end function setFirstName

// return first name
string CommissionEmployee::getFirstName() const
{
return firstName;
} // end function getFirstName

void CommissionEmployee::setLastName( const string &last )
{
lastName = last;
} 

// return first name
string CommissionEmployee::getLastName() const
{
return lastName;
} 

void CommissionEmployee::setSocialSecurityNumber( const string &SSName )
{
socialSecurityNumber = SSName;
} 

// return first name
string CommissionEmployee::getSocialSecurityNumber() const
{
return socialSecurityNumber;
} 

void CommissionEmployee::setGrossSales(double GS )
{
grossSales = GS;
} 

// return first name
double CommissionEmployee::getGrossSales() const
{
return grossSales;
} 

void CommissionEmployee::setCommissionRate(double CR )
{
commissionRate = CR;
} 

// return first name
double CommissionEmployee::getCommissionRate() const
{
return commissionRate;
} 

// calculate earnings
double CommissionEmployee::earnings() const
{
return commissionRate * grossSales;
} // end function earnings

// print CommissionEmployee object
void CommissionEmployee::print() const
{
cout << "commission employee: " << firstName << ' ' << lastName
<< "\nsocial security number: " << socialSecurityNumber
<< "\ngross sales: " << grossSales
<< "\ncommission rate: " << commissionRate;
} // end function print 