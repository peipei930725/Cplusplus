#include<iostream>
#include<string>
#include "Header.h"

using namespace std;

int main() {
    GradeBook gradeBook1("CS101");
    GradeBook gradeBook2("CS102");
    GradeBook gradeBook3("CS103");

    cout << "course name is: " << gradeBook1.getCourseName() << endl;
    cout << "course name is: " << gradeBook2.getCourseName() << endl;
    cout << "course name is: " << gradeBook3.getCourseName() << endl;
}