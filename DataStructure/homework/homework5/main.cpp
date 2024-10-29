#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <limits>
#include "HuffmanNode.hpp"

using namespace std;

string HuffmanNode::huffman_code[26]; // 靜態成員變數的定義

bool compareFreq(const HuffmanNode* a, const HuffmanNode* b) {
    if (a == nullptr) return false;
    if (b == nullptr) return true;
    return a->freq < b->freq;
}

int main(void) {
    freopen("textin.txt", "r", stdin);
    freopen("textout.txt", "w", stdout);
    HuffmanNode* arr[100] = {nullptr};
    char ch;
    int freq;
    int count = 0;

    // 讀取字母和頻率
    while(cin.peek()!='\n') {
        cin >> ch >> freq;
        HuffmanNode *root = new HuffmanNode(ch, freq);
        arr[count++] = root;
        cin.ignore();
    }
    string str;
    cin >> str;

    int size=count;
    while(count > 1){
        sort(arr, arr + count, compareFreq);  
        HuffmanNode *left = arr[0];
        HuffmanNode *right = arr[1];
        HuffmanNode *newroot = new HuffmanNode(' ', left->freq + right->freq, left, right);
        arr[0] = newroot;
        swap(arr[1], arr[count-1]);
        count--;
    }
    
    HuffmanNode *root = arr[0];
    root->traverse(root,"");

    for(int i = 0; i < size; i++) {
        cout<<char('A'+i)<<" "<<HuffmanNode::huffman_code[i]<<endl;
    }

    for(int j = 0; j < str.size(); j++) {
        cout<<HuffmanNode::huffman_code[str[j]-'A'];
    }
    
    return 0;
}