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
cout << checkMonth(month)  << '/' << checkDay( day ) << '/' << checkYear( year );;
} 
void Date::nextDay(){
    if ( day == 31 && month == 12 ){
        day = 1;
        month = 1;
        year++;
    }
    else if ( day == 31 && ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ) ){
        day = 1;
        month++;
    }
    else if ( day == 30 && ( month == 4 || month == 6 || month == 9 || month == 11 ) ){
        day = 1;
        month++;
    }
    else if ( day == 28 && month == 2 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) ){
        day++;
    }
    else if ( day == 29 && month == 2 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) ){
        day = 1;
        month++;
    }
    else{
        day++;
    }
    return;
}

unsigned int Date::checkDay( int testDay ) const{ 
    const int daysPerMonth[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  
    if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
    return testDay;
    if ( month == 2 && testDay == 29 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
    return testDay;
    cout << "\nInvalid day (" << testDay << ") set to 1,so the output is\n";
    return 1; 
}
unsigned int Date::checkMonth( int testMonth ) const{
    if ( testMonth > 0 && testMonth <= 12 )
    return testMonth;
    cout << "\nInvalid month (" << testMonth << ") set to 1,so the output is\n";
    testMonth = 1;
    return 1; 
}
unsigned int Date::checkYear( int testYear ) const{
    if ( testYear >= 1900 && testYear <= 2100 )
    return testYear;
    cout << "\nInvalid year (" << testYear << ") set to 1900,so the output is:\n";
    return 1900; 
}
