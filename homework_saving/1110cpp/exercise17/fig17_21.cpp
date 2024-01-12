#include <iostream>
#include "Employee.cpp" 
#include "Date.cpp" 
using namespace std;

int main()
{
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Date birth1(7,25,2004);
    Date hire1(11,10,2022);

    Employee manager("Bob", "Blue", birth, hire);
    Employee manager1("Alan", "Liou", birth1, hire1);

    cout << endl;

    manager.print();
    manager1.print();

    return 0; 
}