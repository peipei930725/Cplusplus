#include"maze.h"

using namespace std;

maze::maze(){
    themap = vector<vector<char>>(6, vector<char>(7, 'b')); //把外圍+b的牆壁
    offsets input;
    input.a=1;
    input.b=1;
    input.drections=No;
    thepath.push(input);
}

void maze::input(int row,int col,char value){ 
    themap[row+1][col+1]=value; //在(1,1)開始迷宮
    if(value=='e'){
        exit_row=row+1;
        exit_col=col+1;
    }
}

void maze::findpath (){
    while(!result()){   //找是不是終點
        current_row=thepath.elements.back().a;
        current_col=thepath.elements.back().b;

        if(themap[current_row+1][current_col+1]=='0'){
            count++;
            offsets input;
            current_row+=1;
            current_col+=1;
            themap[current_row][current_col]='\\';
            input.a=current_row;
            input.b=current_col;
            input.drections=SE;
            thepath.push(input);
        }
        else if(themap[current_row+1][current_col]=='0'){
            count++;
            offsets input;
            current_row+=1;
            //current_col+=1;
            themap[current_row][current_col]='|';
            input.a=current_row;
            input.b=current_col;
            input.drections=S;
            thepath.push(input);

        }
        else if(themap[current_row][current_col+1]=='0'){
            count++;
            offsets input;
            //current_row+=1;
            current_col+=1;
            themap[current_row][current_col]='-';
            input.a=current_row;
            input.b=current_col;
            input.drections=E;
            thepath.push(input);
        }
        else if(themap[current_row-1][current_col+1]=='0'){
            count++;
            offsets input;
            current_row-=1;
            current_col+=1;
            themap[current_row][current_col]='/';
            input.a=current_row;
            input.b=current_col;
            input.drections=NE;
            thepath.push(input);
        }
        else if(themap[current_row+1][current_col-1]=='0'){
            count++;
            offsets input;
            current_row+=1;
            current_col-=1;
            themap[current_row][current_col]='/';
            input.a=current_row;
            input.b=current_col;
            input.drections=SW;
            thepath.push(input);
        }
        else if(themap[current_row][current_col-1]=='0'){
            count++;
            offsets input;
            //current_row+=1;
            current_col-=1;
            themap[current_row][current_col]='-';
            input.a=current_row;
            input.b=current_col;
            input.drections=W;
            thepath.push(input);
        }
        else if(themap[current_row-1][current_col]=='0'){
            count++;
            offsets input;
            current_row-=1;
            //current_col-=1;
            themap[current_row][current_col]='|';
            input.a=current_row;
            input.b=current_col;
            input.drections=N;
            thepath.push(input);
        }
        else if(themap[current_row-1][current_col-1]=='0'){
            count++;
            offsets input;
            current_row-=1;
            current_col-=1;
            themap[current_row][current_col]='\\';
            input.a=current_row;
            input.b=current_col;
            input.drections=NW;
            thepath.push(input);
        }
        else {
            count--;
            themap[current_row][current_col]='b';
            thepath.pop();
        }
    }
    output();
    cout<<"Total "<<count+1<<" Steps."<<endl;

}

bool maze::result() {
    if ((current_row + 1 == exit_row && current_col + 1 == exit_col) ||
        (current_row + 1 == exit_row && current_col == exit_col) ||
        (current_row == exit_row && current_col + 1 == exit_col) ||
        (current_row - 1 == exit_row && current_col + 1 == exit_col) ||
        (current_row + 1 == exit_row && current_col - 1 == exit_col) ||
        (current_row == exit_row && current_col + 1 == exit_col) ||
        (current_row - 1 == exit_row && current_col == exit_col) ||
        (current_row - 1 == exit_row && current_col - 1 == exit_col)) {

        return true;
    } 
    else {
        return false;
    }
}

void maze::output(){
    for(int i=1;i<5;++i){
        for(int j=1;j<6;++j){
            cout<<themap[i][j]<<" ";
        }
        cout<<'\n';
    }
}

