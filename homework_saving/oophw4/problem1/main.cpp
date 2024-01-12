#include<iostream>
#include<string>
#include"PACKAGE.cpp"
#include"TwoDayPackage.cpp"
#include"OvernightPackage.cpp"

using namespace std;

int main(){
    PACKAGE package1;
    package1.name = "John";
    package1.city = "New York";
    package1.state = "New York";
    package1.zipCode = "10001";
    package1.weight = 10;
    package1.costPerOunce = 5;
    cout << "Package 1: " << package1.calculateCost() << endl;
    
    TwoDayPackage package2;
    package2.name = "John";
    package2.city = "New York";
    package2.state = "New York";
    package2.zipCode = "10001";
    package2.weight = 10;
    package2.costPerOunce = 5;
    package2.setFlatFee(10);
    cout << "Package 2: " << package2.calculateCost() << endl;
    
    OvernightPackage package3;
    package3.name = "John";
    package3.city = "New York";
    package3.state = "New York";
    package3.zipCode = "10001";
    package3.weight = 10;
    package3.costPerOunce = 5;
    package3.setAdditionalFee(5);
    cout << "Package 3: " << package3.calculateCost() << endl;
    
    return 0;
}