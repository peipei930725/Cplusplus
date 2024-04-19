#include<iostream>
#include<vector>
#include "SpraseMatrix.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

SpraseMatrix::SpraseMatrix(int r,int c){ //定義矩陣的大小
    row=r;
    col=c;
    establish_row_index();
}

void SpraseMatrix::Add(int r,int c,int v){ //放入matrix裡面做暫存
    mdata temp;
    temp.row=r;
    temp.col=c;
    temp.value=v;
    Row_counting[c].rowsize++;  //row_index的建置，把RowSize做+1

    matrix.push_back(temp); //要算col的個數放到index裡面
}

void SpraseMatrix::establish_row_index(){
    for(int i=0;i<col;++i){          //擴充好Row_counting的大小
        fast_row temp;
        temp.rowsize=0;
        temp.rowstart=0;
        Row_counting.push_back(temp);
    }
}

void SpraseMatrix::traditional(){ //把稀疏矩陣放入傳統的2維矩陣
    traditional_matrix.resize(row, vector<int>(col, 0)); // 將traditional_matrix 設置為row行col列的矩陣，並將所有元素設為0

    after_traditional_matrix.resize(col, vector<int>(row, 0)); // 將after_traditional_matrix 設置為col行row列的矩陣，並將所有元素設為0
    for(int i=0;i<matrix.size();++i){ //把有值的矩陣做元素取代
        traditional_matrix[matrix[i].row][matrix[i].col]=matrix[i].value;
    }
}

void SpraseMatrix::traditional_transpose() { 
    // cout<<"Traditional 2-dimensional array:"<<endl;
    auto start_time = high_resolution_clock::now(); //開始計時

    traditional(); // 先將稀疏矩陣轉換為傳統矩陣

    for (int i=0; i<col; ++i) {
        for (int j=0; j<row; ++j) {
            after_traditional_matrix[i][j]=traditional_matrix[j][i];
        }
    }

    auto end_time = high_resolution_clock::now();   //結束計時
    auto duration = duration_cast<microseconds>(end_time - start_time);

    // for (int i=0; i<row; ++i) {
    //     for (int j=0; j<col; ++j) {
    //         cout<<traditional_matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for (int i=0; i<col; ++i) {
    //     for (int j=0; j<row; ++j) {
    //         cout<<after_traditional_matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout << "traditional 2-dimensional array execution time: " << duration.count() << " milliseconds" << endl;
    cout<<endl;
}

void SpraseMatrix::Transpose(){ //第二種轉移
    // cout<<"Fast Transpose:"<<endl;
    auto start_time = high_resolution_clock::now(); //開始計時
    for(int i=0;i<row;++i){     //跑row的大小
        for(int k=0;k<matrix.size();++k){
            if(matrix[k].col==i){ //如果原來的matrix的col==轉置後的row
                mdata temp;
                temp.row=matrix[k].col;
                temp.col=matrix[k].row;
                temp.value=matrix[k].value;
                second_matrix.push_back(temp);
            }
        }
    }
    auto end_time = high_resolution_clock::now();   //結束計時
    auto duration2 = duration_cast<microseconds>(end_time - start_time);

    // for(int i=0;i<matrix.size();++i){
    //     cout<<second_matrix[i].row<<" "<<second_matrix[i].col<<" "<<second_matrix[i].value<<endl;
    // }

    cout << "Transpose execution time: " << duration2.count() << " milliseconds" << endl;
    cout<<endl;
}

void SpraseMatrix::Fast_transpose(){ 
    for(int i=0;i<matrix.size();++i){ //先擴充好vector的大小
        mdata temp1;
        temp1.row=0;
        temp1.col=0;
        temp1.value=0;
        fast_matrix.push_back(temp1);
    }
    
    int sum=0;
    for(int i=0;i<col;++i){        //做row start的建置
        Row_counting[i].rowstart=sum;
        sum+=Row_counting[i].rowsize;
    }
    auto start_time = high_resolution_clock::now(); //開始計時
    for(int k=0;k<matrix.size();++k){
        mdata temp;
        temp.row=matrix[k].col;
        temp.col=matrix[k].row;
        temp.value=matrix[k].value;
        fast_matrix[Row_counting[temp.col].rowstart] = temp;
        Row_counting[temp.col].rowstart++;                  //rowstart++
    }
    auto end_time = high_resolution_clock::now();   //結束計時
    auto duration3 = duration_cast<microseconds>(end_time - start_time);

    // for(int i=0;i<matrix.size();++i){
    //     cout<<fast_matrix[i].row<<" "<<fast_matrix[i].col<<" "<<fast_matrix[i].value<<endl;
    // }

    cout << "Fast Transpose execution time: " << duration3.count() << " milliseconds" << endl;
    cout<<endl;
}