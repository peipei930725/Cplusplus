#include<iostream>
#include<vector>

using namespace std;

class MartixTerm{
    friend SparseMatrix;
private:
    int rows,cols,value;//original matrix declare
};

class SparseMatrix{
private:
    MartixTerm smArray[100];//matrix array
    int Rows,Cols,Terms;
public:
    SparseMatrix Transpose();
};

SparseMatrix SparseMatrix::Transpose(){
    int *RowSize=new int[Cols];
    int *RowStart=new int[Cols];
    SparseMatrix b;
    b.Rows=Cols;
    b.Cols=Rows;
    b.Terms=Terms;

    int i;

    if(Terms>0){
        for(i=0;i<Cols;++i) RowSize[i]=0;

        for(i=0;i<Terms;++i) RowSize[smArray[i].cols]++;

        RowStart[0]=0;
        for(i=0;i<Cols;++i){
            RowStart[i]=RowStart[i-1]+RowSize[i-1];
        }

        for(i=0;i<Terms;++i){
            int j=RowStart[smArray[i].cols];
            b.smArray[j].rows=b.smArray[j].cols;
            b.smArray[j].cols=b.smArray[j].rows;
            b.smArray[j].value=b.smArray[j].value;
            RowStart[smArray[i].cols]++;
        }

        delete[] RowSize;
        delete[] RowStart;
        return b;
    }
}