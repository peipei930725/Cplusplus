#include <iostream>
#include "Time.cpp" // include definition of class Time from Time.h
using namespace std;

int main()
{
Time t1; // all argume
Time t2( 2 ); // h
Time t3( 21, 34 );
Time t4( 12, 25, 42 );
Time t5( 27, 74, 99 );
cout << "Constructed with:\n\nt1: all arguments defaulted\n ";

t1.printUniversal(); // 00:00:00
cout << "\n ";
t1.printStandard(); // 12:00:00 AM
cout << "\n\nt2: hour specified; minute and second defaulted\n ";

t2.printUniversal(); // 02:00:00
cout << "\n ";
t2.printStandard(); // 2:00:00 AM
cout << "\n\nt3: hour and minute specified; second defaulted\n ";

t3.printUniversal(); // 21:34:00
cout << "\n ";
t3.printStandard(); // 9:34:00 PM
cout << "\n\nt4: hour, minute and second specified\n ";

t4.printUniversal(); // 12:25:42
cout << "\n ";
t4.printStandard(); // 12:25:42 PM
cout << "\n\nt5: all invalid values specified\n ";

t5.printUniversal(); // 00:00:00
cout << "\n ";
t5.printStandard(); // 12:00:00 AM
cout << endl;
} // end main