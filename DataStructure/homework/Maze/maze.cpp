#include"maze.h"
#include <string>
#include <fstream> // 包含文件操作相關的頭文件
#include<iostream>

using namespace std;

maze::maze() {
    themap = nullptr; // 初始化為空指標
}

void maze::input() {
    ifstream file("test3.in"); // 打開文件
    if (!file.is_open()) {
        cout << "Error opening file: test3.in" << endl;
        return;
    }

    string row_input;
    int row_num = 0;
    int empty_lines = 0; // 紀錄空行數量
    while (getline(file, row_input)) { // 從文件中逐行讀取資料
        if (row_input.empty()) { // 如果是空行
            empty_lines++;
            if (empty_lines >= 2) // 如果已經有兩個連續的空行
                break; // 結束輸入
            else
                continue; // 繼續讀取下一行
        }

        empty_lines = 0; // 如果不是空行，重置空行計數

        // 去除空格字符，只保留有效的地圖元素
        string map_row;
        for (char ch : row_input) {
            if (ch != ' ') // 如果不是空格，加入到地圖行中
                map_row.push_back(ch);
        }

        // 將每行資料加入地圖中
        int row_size = map_row.size();
        char* row = new char[row_size];
        for (int i = 0; i < row_size; ++i) {
            row[i] = map_row[i];
        }
        // 更新地圖
        if (!themap) {
            height = 1; // 初始化地圖高度
            width = row_size; // 初始化地圖寬度
            themap = new char*[height]; // 分配記憶體
            themap[0] = row; // 添加第一行
        } else {
            // 重新分配記憶體，將舊資料拷貝到新地圖中
            char** new_map = new char*[height + 1];
            for (int i = 0; i < height; ++i) {
                new_map[i] = new char[width];
                for (int j = 0; j < width; ++j) {
                    new_map[i][j] = themap[i][j];
                }
                delete[] themap[i]; // 釋放原地圖的內存
            }
            new_map[height] = row; // 添加新行
            delete[] themap; // 釋放原地圖的內存
            themap = new_map; // 更新地圖指標
            ++height; // 更新地圖高度
        }

        // 更新起點和終點位置
        size_t pos_s = map_row.find('s');
        if (pos_s != string::npos) {
            start_pos = make_pair(row_num + 1, pos_s + 1);
            offsets input;
            input.a = start_pos.first;
            input.b = start_pos.second;
            input.drections = No;
            thepath.push(input);
        }
        size_t pos_e = map_row.find('e');
        if (pos_e != string::npos) {
            end_pos = make_pair(row_num + 1, pos_e + 1);
        }

        row_num++;
    }

    file.close(); // 關閉文件

    // 在地圖的四周加上 'b'
    char** new_map = new char*[height + 2];
    for (int i = 0; i < height + 2; ++i) {
        new_map[i] = new char[width + 2];
    }
    for (int i = 0; i < height + 2; ++i) {
        for (int j = 0; j < width + 2; ++j) {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1) {
                new_map[i][j] = 'b';
            } else {
                new_map[i][j] = themap[i - 1][j - 1];
            }
        }
    }
    // 釋放原來的地圖內存
    for (int i = 0; i < height; ++i) {
        delete[] themap[i];
    }
    delete[] themap;
    // 更新地圖為新的地圖
    themap = new_map;
}

void maze::findpath (){
    while(!result()){   //找是不是終點
        current_row = thepath.top().a;
        current_col = thepath.top().b;

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
    if ((current_row + 1 == end_pos.first && current_col + 1 == end_pos.second) ||
        (current_row + 1 == end_pos.first && current_col == end_pos.second) ||
        (current_row == end_pos.first && current_col + 1 == end_pos.second) ||
        (current_row - 1 == end_pos.first && current_col + 1 == end_pos.second) ||
        (current_row + 1 == end_pos.first && current_col - 1 == end_pos.second) ||
        (current_row == end_pos.first && current_col + 1 == end_pos.second) ||
        (current_row - 1 == end_pos.first && current_col == end_pos.second) ||
        (current_row - 1 == end_pos.first && current_col - 1 == end_pos.second)) {
        return true;
    } 
    else {
        return false;
    }
}

void maze::output(){
    for(int i = 1; i < height + 1; ++i){
        for(int j = 1; j < width + 1; ++j){
            cout << themap[i][j] << " ";
        }
        cout << '\n';
    }
}

void maze::outputToFile() {
    std::ofstream outFile("test3.out"); // 創建一個用於輸出的檔案流

    // 將地圖內容寫入檔案
    for(int i = 1; i < height + 1; ++i){
        for(int j = 1; j < width + 1; ++j){
            outFile << themap[i][j] << " ";
        }
        outFile << '\n';
    }
    outFile<<"Total "<<count+1<<" Steps."<<endl;

    outFile.close(); // 關閉檔案
}
