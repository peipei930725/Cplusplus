#ifndef _CSHAPE_H_
#define _CSHAPE_H_

#include<iostream>
#include<string>

using namespace std;

class cshape{
public:
    cshape();
    virtual ~cshape();

    double getArea() const{
        return area;
    }
    double getGirth() const{
        return girth;
    }
    virtual void setzero();
    virtual void setfive();
protected:
    void setArea(double area){
        this->area=area;
    }
    void setGirth(double girth){
        this->girth=girth;
    }
private:
    double area;
    double girth;
};

#endif
