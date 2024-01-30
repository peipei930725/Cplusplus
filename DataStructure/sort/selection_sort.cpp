#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v={5,3,10,4,7};
    int min=0;

    for(int i=0;i<v.size();++i){
        min=i;
        for(int j=i;j<v.size();++j){
            if(v[j]<v[min]){
                min=j;     
            }
        }
        swap(v[min],v[i]);
    }

    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}