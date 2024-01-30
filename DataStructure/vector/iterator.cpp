#include<iostream>
#include<vector>

using namespace std;

int main(){ 
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    cout<<*(v.begin()+2)<<endl;

    return 0; 
}