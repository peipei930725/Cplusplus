#include<iostream>
#include<vector>
#include "SpraseMatrix.cpp"

using namespace std;

int main(){
    int rows;
    int cols;
    cin>>rows>>cols;
    SpraseMatrix testcase(rows,cols);
    int row,col,value;
    while(cin>>row && cin>>col && cin>>value){
        testcase.Add(row,col,value);
    }


    // SpraseMatrix myMatrix(5, 6);
    // myMatrix.Add(0, 0, 1);
    // myMatrix.Add(1, 2, 2);
    // myMatrix.Add(2, 1, 3);

    testcase.traditional_transpose();
    testcase.Transpose();
    testcase.Fast_transpose();

    return 0;
}
