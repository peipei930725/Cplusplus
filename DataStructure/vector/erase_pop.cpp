#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> v={1,23,45,6,7,89,};

    v.erase(v.begin()+2);

    for(auto i:v){
        cout<<i<<' ';
    }
    return 0;
}