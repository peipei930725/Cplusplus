#ifndef DATE_H
#define DATE_H

// class Date definition
class Date
{
public:
explicit Date( int = 1, int = 1, int = 2000 ); // default constructor
void print();
void nextDay();
private:
unsigned int month;
unsigned int day;
unsigned int year;

unsigned int checkDay( int ) const; // utility function to check day
unsigned int checkMonth( int ) const; // utility function to check month
unsigned int checkYear( int ) const; // utility function to check year
}; // end class Date
#endif