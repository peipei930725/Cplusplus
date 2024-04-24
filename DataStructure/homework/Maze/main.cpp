#include<iostream>
#include<vector>
#include"maze.cpp"

using namespace std;

int main(){
    maze m;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            char input;
            cin>>input;
            m.input(i,j,input);
        }
    } 
    m.findpath();
    return 0;
}