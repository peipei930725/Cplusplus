#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void RP(vector<char> &v, int begin,int end) {
    if(begin==end){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int j=begin;j<end;++j){
            swap(v[begin],v[j]);
            RP(v,begin+1,end);
            swap(v[begin],v[j]);
        }
    }
}

int main() {
    vector<char> v = {'a', 'b', 'c' ,'d'};

    RP(v,0,v.size());

    return 0;
}