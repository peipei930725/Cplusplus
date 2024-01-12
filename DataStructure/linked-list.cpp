#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
private:
    int size;                // size是用來記錄Linked list的長度, 非必要
    int back;
    Node *first;            // list的第一個node

public:
    LinkedList():first(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};


int main(){
    Node test;
}