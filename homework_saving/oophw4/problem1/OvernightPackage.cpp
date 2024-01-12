#include"OvernightPackage.h"
#include<iostream>
#include<string>

using namespace std;

OvernightPackage::OvernightPackage()
:additionalFee(0){

}

OvernightPackage::OvernightPackage(double fee)
:additionalFee(fee){

}

double OvernightPackage::calculateCost(){
    return PACKAGE::calculateCost() + additionalFee;
}

void OvernightPackage::setAdditionalFee(double fee){
    additionalFee = fee;
}