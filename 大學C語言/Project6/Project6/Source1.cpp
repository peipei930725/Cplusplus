#include<iostream>
#include<string>
#include "Header.h"

using namespace std;

GradeBook::GradeBook(string name) {//constructer
    setCourseName(name);
}
void GradeBook::setCourseName(string name) {
    courseName = name;
}
string GradeBook::getCourseName() {
    return courseName;
}
void GradeBook::displayMessage() {
    cout << "Welcome to the grade book dor\n" << getCourseName() << "!" << endl;
}
