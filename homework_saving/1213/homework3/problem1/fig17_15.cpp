#include <iostream>
#include "Date.cpp" // include definition of class Date from Date.h
using namespace std;

int main()
{
int day, month, year;
cin >> month >> day >> year;
Date date1( month, day, year );
Date date2; // date2 defaults to 1/1/2000

cout << "date1 = ";
date1.print();
date1.nextDay();
cout << "\n\nAfter nextDay, date1 = ";
date1.print();

return 0;
} 