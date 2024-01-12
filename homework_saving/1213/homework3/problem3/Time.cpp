#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s) {
    totalSeconds = (h * 3600) + (m * 60) + s;
}

void Time::printUniversal() const {
    int hour = totalSeconds / 3600;
    int remainder = totalSeconds % 3600;
    int minute = remainder / 60;
    int second = remainder % 60;

    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;
}

void Time::printStandard() const {
    int hour = totalSeconds / 3600;
    int remainder = totalSeconds % 3600;
    int minute = remainder / 60;
    int second = remainder % 60;

    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << ":"
        << setw(2) << second << (hour < 12 ? " AM" : " PM");
}