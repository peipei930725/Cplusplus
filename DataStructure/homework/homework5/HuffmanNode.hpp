// HuffmanNode.hpp
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
using namespace std;

class HuffmanNode {
public:
    char ch;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
    static string huffman_code[]; // 靜態成員變數的聲明

    HuffmanNode(char ch, int freq) : ch(ch), freq(freq), left(NULL), right(NULL) {}
    HuffmanNode(char ch, int freq, HuffmanNode *left, HuffmanNode *right) : ch(ch), freq(freq), left(left), right(right) {}

    void traverse(HuffmanNode* ptr, string str) {
        if(left == nullptr && right == nullptr) {
            huffman_code[ch-'A'] = str;
            return;
        }
        if(left != nullptr) {
            left->traverse(ptr->left,str + '0');
        }
        if(right != nullptr) {
            right->traverse(ptr->right,str + '1');
        }
    }
};

#endif
