#include<iostream>
#include <fstream> // 包含文件操作相關的頭文件
#include"maze.cpp"

using namespace std;

int main(){
    maze m;
    m.input();
    m.findpath();
    m.outputToFile();
    return 0;
}