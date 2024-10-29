#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // ���J����
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "���|�j�p: " << s.size() << std::endl;
    std::cout << "���|��������: " << s.top() << std::endl;

    // ������������
    s.pop();

    std::cout << "�����@�Ӥ����᪺���|�j�p: " << s.size() << std::endl;
    std::cout << "�s�����|��������: " << s.top() << std::endl;

    // �ˬd���|�O�_����
    if (!s.empty()) {
        std::cout << "���|������" << std::endl;
    }

    // �M�Ű��|
    while (!s.empty()) {
        s.pop();
    }

    std::cout << "�M�ū���|�j�p: " << s.size() << std::endl;

    return 0;
}