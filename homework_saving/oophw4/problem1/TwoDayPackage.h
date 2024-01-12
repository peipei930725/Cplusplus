#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include"PACKAGE.h"
#include<iostream>
#include<string>

using namespace std;

class TwoDayPackage:public PACKAGE{
    public:
        TwoDayPackage();
        TwoDayPackage(double);
        double calculateCost();
        void setFlatFee(double);
    private:
        double flatFee;
};

#endif