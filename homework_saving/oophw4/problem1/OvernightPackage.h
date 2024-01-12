#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include"PACKAGE.h"
#include<iostream>
#include<string>

using namespace std;

class OvernightPackage:public PACKAGE{
    public:
        OvernightPackage();
        OvernightPackage(double);
        double calculateCost();
        void setAdditionalFee(double);
    private:
        double additionalFee;
};

#endif