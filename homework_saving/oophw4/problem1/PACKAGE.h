#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;


class PACKAGE{
    public:
        PACKAGE();
        string name;
        string city;
        string state;
        string zipCode;
        unsigned int weight;
        unsigned int costPerOunce;
        double calculateCost();
};

#endif
