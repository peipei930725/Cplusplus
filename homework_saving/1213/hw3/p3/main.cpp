#include <iostream>
#include "time.cpp"
using namespace std;
int main() {
    Time t;

    t.setTime(17, 23, 50);
    cout << "Universal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();

    return 0;
}