#include <iostream>
#include "date.cpp"     // Date class definition
using namespace std;

int main(){
    Date Date(2023,12,30);
    Date.nextDay();
    Date.nextDay();
    cout << "\n";

}