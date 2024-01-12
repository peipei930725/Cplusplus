#include<iostream>
#include<string>
#include"cshape.h"

using namespace std;

cshape::cshape(){
    //cout<<"cshape is created"<<endl;
    area=0;
    girth=0;
}

cshape::~cshape(){
    cout<<"cshape is deleted"<<endl;
}

void cshape::setzero(){
    cout<<"cshape setzero"<<endl;
}

void cshape::setfive(){
    cout<<"cshape setfive"<<endl;
}