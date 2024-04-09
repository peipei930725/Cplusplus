#include<iostream>
#include<vector>

using namespace std;

struct mdata                            //輸入矩陣的定義
{
    int row;
    int col;
    int value;
};

struct fast_row{                        //快速轉置的vector定義
    int rowsize;
    int rowstart;
};

class SpraseMatrix{
private:
    int row;
    int col;
    vector <mdata> matrix;              //做輸入矩陣的暫存

    vector<vector<int>> traditional_matrix; //傳統的2維矩陣
    vector<vector<int>> after_traditional_matrix; //轉置後傳統的2維矩陣
    vector <mdata> second_matrix;       //稀疏矩陣的特例處理
    vector <mdata> fast_matrix;         //快速轉置的稀疏矩陣處理
    vector <fast_row> Row_counting;     //快速轉置的row資料 
    void establish_row_index();
public:
    SpraseMatrix(int r,int c);          //定義SpraseMatrix的大小
    void Transpose();                   //第二種轉移
    void Add(int r,int c,int v);        //把輸入裝入matrix

    void traditional();                 //把輸入轉成傳統的2維矩陣
    void traditional_transpose();       //做2維矩陣的轉置

    void Fast_transpose();              //快速轉置
};