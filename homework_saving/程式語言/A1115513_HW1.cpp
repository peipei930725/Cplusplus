#include <iostream>
#include <string>

using namespace std;

// 當前字元位置
int pos = 0;
string input;

bool id();
bool term();
bool expr();
bool factor();
bool assign();

// <assign> -> <id> = <expr>
bool assign() {
    if (!id()) return false;  // 解析 <id>
    if (pos < input.size() && input[pos] == '=') {
        pos++;  // 跳過 '='
        if (!expr()) return false;  // 解析 <expr>
        return pos == input.size();  // 確保已經匹配到輸入結尾
    }
    return false;
}

// <id> -> A | B | C | D
bool id() {
    if (pos < input.size() && (input[pos] == 'A' || input[pos] == 'B' || input[pos] == 'C' || input[pos] == 'D')) {
        pos++;
        return true;
    }
    return false;
}

// <expr> -> <expr> - <term> | <id>
bool expr() {
    if (!term()) return false;  // 先嘗試解析 <term>

    while (pos < input.size() && input[pos] == '-') {
        pos++;  // 跳過 '-'
        if (!term()) return false;  // 解析 <term>
    }
    return true;
}

// <term> -> <term> * <factor> | <term> / <factor> | <factor>
bool term() {
    if (!factor()) return false;  // 先嘗試解析 <factor>

    while (pos < input.size() && (input[pos] == '*' || input[pos] == '/')) {
        pos++;  // 跳過運算符
        if (!factor()) return false;  // 解析 <factor>
    }
    return true;
}

// <factor> -> (<expr>) | <id>
bool factor() {
    if (pos < input.size() && input[pos] == '(') {
        pos++;  // 跳過 '('
        if (!expr()) return false;  // 解析 <expr>
        if (pos < input.size() && input[pos] == ')') {
            pos++;  // 跳過 ')'
            return true;
        }
        return false;
    } else {
        return id();  // 嘗試解析 <id>
    }
}



int main() {
    string statements[] = {
        "A=B-C/A-A",    // Statement1
        "A=B*C/D-A",    // Statement2
        "A=B/(C-A)",    // Statement3
        "A=B-(C*A)",    // Statement4
        "A=B*(D-A)"     // Statement5
    };

    for (int i = 0; i < 5; ++i) {
        input = statements[i];
        pos = 0;  // 重置位置
        if (assign()) {
            cout << "Statement " << i + 1 << ": True" << endl;
        } else {
            cout << "Statement " << i + 1 << ": False" << endl;
        }
    }

    return 0;
}
