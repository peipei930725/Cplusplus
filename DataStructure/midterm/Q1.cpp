#include<iostream>
#include<vector>

using namespace std;

struct mdata{ //row col value的資料型態
    int row;
    int col;
    int value;
};

class SparseMatrix{
public:
vector<mdata> Matrix_data;
void input(int a,int b,int c);
void input_value(int thevalue);
void transpose();
private:
};

void SparseMatrix::transpose(){ //直接轉置並輸出
    for(int i=0;i<Matrix_data.size();++i){
        int temp=Matrix_data[i].row;
        Matrix_data[i].row=Matrix_data[i].col;
        Matrix_data[i].col=temp;
        cout<<Matrix_data[i].row<<Matrix_data[i].col<<Matrix_data[i].value<<endl;
    }
}

void SparseMatrix::input(int a,int b,int c){ //輸入
    mdata reg;
    reg.row=a;
    reg.col=b;
    reg.value=c;
    Matrix_data.push_back(reg);
}

void SparseMatrix::input_value(int thevalue){

}

int main(){
    SparseMatrix myMatrix;
    int row,col;
    cin>>row>>col;
    int t=row;
    while(t--){
        // int therow;
        // cin>>therow;
        // int count;
        // int amount;
        // while(count--){
        //     int column;
        //     int value;
        //     cin>>column;
        //     cin>>value;
        //     myMatrix.input(therow,column,value); //輸入陣列
        //     amount++;
        // }
        //真的看不懂題目 只好寫正常的矩陣輸入和轉置

        int therow,thecol,thevalue;
        cin>>therow>>thecol>>thevalue;
        myMatrix.input(therow,thecol,thevalue);
        myMatrix.transpose();
    }
}