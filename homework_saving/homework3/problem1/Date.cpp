#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;


Date::Date( int m, int d, int y ){
month = m;
day = d;
year = y;
} // end constructor Date

// print Date in the format mm/dd/yyyy
void Date::print()
{
cout << month << '/' << day << '/' << year;
} 