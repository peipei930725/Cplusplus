#include<iostream>
#include<string>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name){//constructer
    setGradeBook(name);
}
void GradeBook::setGradeBook(string name){
    courseBook=name;
}
string GradeBook::getCourseBook(){
    return courseBook;
}
void GradeBook::displayMessage(){
    cout<<getCourseBook()<<endl;
}
