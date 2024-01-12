#include<iostream>
#include<iomanip>
#include "Time.h"

using namespace std;

Time::Time(int hr,int min,int sec){
    setTime(hr,min,sec);
}

void Time::setTime(int h,int m,int s){
    setHour(h);
    setMinute(m);
    setSecond(s);
}
void Time::setHour(int h){
    hour=(h>=0 && h<24)?h:0;
}
void Time::setMinute(int m){
    minute=(m>=0 && m<60)?m:0;
}
void Time::setSecond(int s){
    second=(s>=0 && s<60)?s:0;
}
int Time::getHour(){
    return hour;
}