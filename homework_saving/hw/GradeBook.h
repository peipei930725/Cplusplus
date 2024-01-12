#include<iostream>
#include<string>

using namespace std;

class GradeBook{
public:
    GradeBook(string name);
    void setGradeBook(string name);
    string getCourseBook();
    void displayMessage();
private:
    string courseBook;
};