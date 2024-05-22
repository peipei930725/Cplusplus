#include<iostream>
#include "bcd.h"

using namespace std;

BCD64::BCD64() {
    bcd = 0;
}

BCD64::BCD64(unsigned long long bcd) {
    this->bcd = bcd;
}

BCD64::BCD64(const BCD64 &bcd_obj) {
    bcd = bcd_obj.bcd;
}

BCD64::BCD64(string &num_str) {
    bcd = stoull(num_str);
}

BCD64 BCD64::add(BCD64 &num, int &carryout, int &carryin) {
    BCD64 result;
    unsigned long long sum = 0;

    for(int i = 0; i < 16; ++i) { // 應該確保16位元結果，每個BCD數字4位元組
        int a = bcd & 0x0f;
        int b = num.bcd & 0x0f;
        sum = a + b + carryin;
        if(sum > 15) {
            carryout = 1;
            sum -= 16;
        } else {
            carryout = 0;
        }

        result.bcd |= (sum << (i * 4)); // 將加法結果設置到對應位置
        carryin = carryout;

        // 右移位準備處理下一組BCD位元
        bcd >>= 4;
        num.bcd >>= 4;
    }

    return result;
}
/*
    1100 1011
    1101 1110 +
   11110 1011
*/

BCD64 BCD64::sub(BCD64 &num, int &carryout, int &carryin) {
    BCD64 result;
    unsigned long long sum = 0;

    for(int i = 0; i < 16; ++i) { // 應該確保16位元結果，每個BCD數字4位元組
        int a = bcd & 0x0f;
        int b = num.bcd & 0x0f;
        // sum = a - b - carryin; //最後4個位元相減
        if(a - b - carryin < 0) {
            carryout = 1;
            sum = 16 + a - b - carryin;
        } else {
            carryout = 0;
            sum = a - b - carryin;
        }
        result.bcd |= (sum << (i * 4)); 
        carryin = carryout;

        // 右移位準備處理下一組BCD位元
        bcd >>= 4;
        num.bcd >>= 4;
    }

    return result;
}

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next; // 暫存下一個節點
        current->next = prev;               // 反轉當前節點的指向
        prev = current;                     // 移動prev指針到當前節點
        current = nextNode;                 // 移動current指針到下一個節點
    }
    return prev; // 新的頭節點
}

stringtolink::stringtolink(string num) {
    head = nullptr;
    ListNode* tail = nullptr;
    int len = num.length();
    int chunkSize = 16;

    while (len > 0) {
        int start = (len - chunkSize) < 0 ? 0 : (len - chunkSize);
        //18-16=2
        string chunk (16,'0');
        int count=0;
        if((len - chunkSize) < 0) count=chunkSize-len;
        for(int i=start;i<len;i++){
            chunk[count]=num[i];
            count++;
        }

        ListNode* newNode = new ListNode(BCD64(chunk));

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        len -= chunkSize;
    }
}

void stringtolink::link_add(ListNode* node) {
    ListNode* current = head;   //自己的link
    int carryout = 0;
    int carryin = 0;

    while (true) {
        BCD64 result = current->obj.add(node->obj, carryout, carryin);
        // 讓自己的link加上node的link
        current->obj = result;
        // 放到自己的link->obj

        if (carryout == 1) {
            if (current->next == nullptr) { // 如果是最後一個node
                ListNode* newNode = new ListNode(BCD64(1));
                current->next = newNode;
            } else { // 如果不是最後一個node，直接改變carryin
                carryin = 1;
            }
        }

        if(node->next==nullptr && current->next==nullptr){
            break;
        }
        else if(current->next==nullptr){
            ListNode* newNode = new ListNode(BCD64(0));
            current->next = newNode;
        }
        else if(node->next==nullptr){
            ListNode* newNode = new ListNode(BCD64(0));
            node->next = newNode;
        }
        current = current->next;
        node = node->next;
    }
}

void stringtolink::link_sub(ListNode* node) {
    ListNode* current = head;   //自己的link
    int carryout = 0;
    int carryin = 0;

    while (true) {
        BCD64 result = current->obj.sub(node->obj, carryout, carryin);
        // 讓自己的link加上node的link
        current->obj = result;
        // 放到自己的link->obj

        if (carryout == 1) {
            if (current->next == nullptr) { // 如果是最後一個node
                ListNode* newNode = new ListNode(BCD64(1));
                current->next = newNode;
            } else { // 如果不是最後一個node，直接改變carryin
                carryin = 1;
            }
        }

        if(node->next==nullptr && current->next==nullptr){
            break;
        }
        else if(current->next==nullptr){
            ListNode* newNode = new ListNode(BCD64(0));
            current->next = newNode;
        }
        else if(node->next==nullptr){
            ListNode* newNode = new ListNode(BCD64(0));
            node->next = newNode;
        }
        current = current->next;
        node = node->next;
    }
}

void stringtolink::print() { //反過來輸出
    ListNode* current = head;
    ListNode* reversed = reverseLinkedList(current);
    while (reversed != nullptr) {
        cout << reversed->obj;
        reversed = reversed->next;
    }
    cout << endl;
}