#include<iostream>
#include<algorithm>
#include<vector>

bool myfunction(int i, int j){
    return (i < j);
}

struct myclass{
    bool operator()(int i, int j){
        return (i < j);
    }
}myobject;

int main(){
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + 8);

    // using default comparison (operator <):
    std::sort(myvector.begin(), myvector.end());

    // using function as comp
    std::sort(myvector.begin(), myvector.end(), myfunction);

    // using object as comp
    std::sort(myvector.begin(), myvector.end(), myobject);

    // print out content:
}