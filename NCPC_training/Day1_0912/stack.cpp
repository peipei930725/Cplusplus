#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // 推入元素
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "堆疊大小: " << s.size() << std::endl;
    std::cout << "堆疊頂部元素: " << s.top() << std::endl;

    // 移除頂部元素
    s.pop();

    std::cout << "移除一個元素後的堆疊大小: " << s.size() << std::endl;
    std::cout << "新的堆疊頂部元素: " << s.top() << std::endl;

    // 檢查堆疊是否為空
    if (!s.empty()) {
        std::cout << "堆疊不為空" << std::endl;
    }

    // 清空堆疊
    while (!s.empty()) {
        s.pop();
    }

    std::cout << "清空後堆疊大小: " << s.size() << std::endl;

    return 0;
}