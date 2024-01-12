#ifndef _CCIRCLE_H_
#define _CCIRCLE_H_

#include<iostream>
#include<string>
#include"cshape.h"

using namespace std;

class ccircle:public cshape{
public:
    ccircle();
    virtual ~ccircle();

    int getRadius() const{
        return radius;
    }
    void setRadius(int radius){
        this->radius=radius;    
        setArea(radius*radius*3.14);
        setGirth(2*radius*3.14);
    }

    virtual void setzero();
private:
    int radius;
};

#endif