#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> v={1,3,5,7,9};

    vector<int>::iterator itr;  
    for(itr=v.begin();itr<v.end();++itr){
        cout<<*itr<<' ';
    }

    for(int i:v){
        cout<<i<<' ';
    }//不推薦

    for(auto i:v){
        cout<<i<<' ';
    }//無法改變i值

    for(auto &i:v){
        cout<<i<<' ';
    }//遇到bool會掛掉

    for(auto &&i:v){
    cout<<i<<' ';
    }//all right
}