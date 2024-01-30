#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> v={1,2,3,4,5,6};

    v.insert(v.begin()+3,100);

    for(auto num:v){
        cout<<num<<" ";
    }

    return 0;
}