#include"PACKAGE.h"
#include<iostream>
#include<string>

using namespace std;

PACKAGE::PACKAGE()
:name(""),city(""),state(""),zipCode(""),weight(0),costPerOunce(0){
    
}

double PACKAGE::calculateCost(){
    return weight * costPerOunce;
}


