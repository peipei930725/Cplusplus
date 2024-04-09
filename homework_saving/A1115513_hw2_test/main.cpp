#include<iostream>
#include<fstream> 
#include "SpraseMatrix.cpp"

using namespace std;

int main() {
    ifstream inputFile("hw2-testcase/721_850.in"); // 打開輸入檔案
    if (!inputFile) {
        cerr << "cant open!" << endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;

    SpraseMatrix testcase(rows, cols);
    int row, col, value;
    while (inputFile >> row && inputFile >> col && inputFile >> value) {
        testcase.Add(row, col, value);
    }

    inputFile.close(); // 關閉輸入檔案

    testcase.traditional_transpose();
    testcase.Transpose();
    testcase.Fast_transpose();

    return 0;
}
