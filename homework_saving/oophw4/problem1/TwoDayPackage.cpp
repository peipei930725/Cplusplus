#include"TwoDayPackage.h"
#include<iostream>
#include<string>

using namespace std;

TwoDayPackage::TwoDayPackage()
:flatFee(0){

}
TwoDayPackage::TwoDayPackage(double fee)
:flatFee(fee){

}

void TwoDayPackage::setFlatFee(double fee){
    flatFee = fee;
}

double TwoDayPackage::calculateCost(){
    return PACKAGE::calculateCost() + flatFee;
}
