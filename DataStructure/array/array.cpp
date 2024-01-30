#include<iostream>

using namespace std;

void print1(int *ptr,int rows){
    for(int i=0;i<rows;++i){
        cout<<ptr+i<<" "<<*(ptr+i)<<endl;
    }
    return;
}

int main(){
    int one[]={1,2,3,4,5};

    print1(one,5);

    return 0;
}