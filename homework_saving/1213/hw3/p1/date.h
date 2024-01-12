
#ifndef DATE_H
#define DATE_H

class Date{
public:
    static const int monthsPerYear = 12; 
    Date(int = 1900, int = 1, int = 1); 
    void print() const; 
    void nextDay() ;
private:
    unsigned int month; 
    unsigned int day; 
    unsigned int year; 

    unsigned int checkDay(int) const;
    
}; 

#endif