#include <iostream>
#include <string>
#include <fstream>
#include "bcd.cpp" // 假設這個檔案包含 BCD64 類別定義
#include <chrono>
using namespace std;
using namespace std::chrono;

// 假設有一個 stringtolink 類別和相應的方法
// stringtolink 應該是用來處理從字串轉換為 BCD 類別或鏈結列表的類別

int main(void) {    
    ifstream file("in100.txt");   
    ofstream outfile("output100.out");     
    if (!file) {
        cerr << "Unable to open file in.txt";
        return 1; // 如果檔案無法打開，返回錯誤
    }
    auto start_time = high_resolution_clock::now(); //開始計時
    while(true) {
                string num1, symbol, num2;

        getline(file, num1);
        if (num1 == "STOP") { // 判斷是否為停止標誌
            break;
        }
        stringtolink lnum1 = stringtolink(num1);

        while (true) {
            getline(file, symbol);
            if (symbol == "+") {
                getline(file, num2);
                stringtolink lnum2 = stringtolink(num2);
                lnum1.link_add(lnum2.head);
            } else if (symbol == "-") {
                getline(file, num2);
                stringtolink lnum2 = stringtolink(num2);
                lnum1.link_sub(lnum2.head);
            } else if (symbol == "=") {
                break;
            }
        }
        ListNode* current = lnum1.head;
        ListNode* reversed = reverseLinkedList(current);
        while (reversed != nullptr) {
            outfile << reversed->obj;
            reversed = reversed->next;
        }
        outfile << endl;
    }
    auto end_time = high_resolution_clock::now();   //結束計時
    auto duration = duration_cast<microseconds>(end_time - start_time);    
    outfile << "Transpose execution time: " << duration.count() << " milliseconds" << endl;
    outfile<<endl;

    outfile.close();
    return 0;
}
