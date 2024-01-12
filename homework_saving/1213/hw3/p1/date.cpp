#include <iostream>
#include "date.h" // include Date class definition
using namespace std;


Date::Date(int yr,int mn, int dy ){
    if (mn > 0 && mn <= monthsPerYear)
        month = mn;
    else{
        month = 1;
    }

    year = yr;
    day = checkDay(dy);

    print();
    cout << endl;
}

void Date::print() const{
    cout << year << '/' << month  << '/' << day;
}



unsigned Date::checkDay(int testDay) const{
    static const int daysPerMonth[monthsPerYear + 1] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    cout << "Invalid day (" << testDay << ") set to 1.\n";
    return 1;
}

void Date::nextDay() {
    static const int daysPerMonth[monthsPerYear + 1] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Increment day
    ++day;

    // Check if day exceeds the maximum day of the month
    if (day > daysPerMonth[month] && !(month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))) {
        // First day of the next month
        day = 1;
        ++month;
    }

    // Check if month exceeds December
    if (month > 12) {
        // First month of the next year
        month = 1;
        ++year;
    }
    print();
    cout << endl;

}