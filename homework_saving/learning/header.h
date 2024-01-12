#include<iostream>
#include<string>

using namespace std;

class area{
    int width;
    int height;
public:
    // area(){
    //     width=0;
    //     height=0;
    //     cout<<"area is "<<width*height<<endl;
    // }
    area(int a=10,int b=10){        
        width=a;
        height=b;
        cout<<"area is "<<width*height<<endl;
    }
};