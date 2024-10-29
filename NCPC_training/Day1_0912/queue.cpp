#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;

    // �s�W����
    q.push(10);
    q.push(20);
    q.push(30);

    // ���o��C�j�p
    std::cout << "��C�j�p�G" << q.size() << std::endl;

    // ���o��C�e�ݤ���
    std::cout << "��C�e�ݡG" << q.front() << std::endl;

    // ���o��C���ݤ���
    std::cout << "��C���ݡG" << q.back() << std::endl;

    // �����e�ݤ���
    q.pop();

    // �ˬd��C�O�_����
    if (!q.empty()) {
        std::cout << "��C������" << std::endl;
    }

    // �M�Ŧ�C
    while (!q.empty()) {
        q.pop();
    }
}

// a. �u����C�]Priority Queue�^�G *****
// #include <queue>
// #include <iostream>

// int main() {
//     std::priority_queue<int> pq;

//     pq.push(30);
//     pq.push(10);
//     pq.push(20);

//     while (!pq.empty()) {
//         std::cout << pq.top() << " ";
//         pq.pop();
//     }
//     // ��X�G30 20 10
// }

// b. ���ݦ�C�]Deque�^�G ***
// #include <deque>
// #include <iostream>

// int main() {
//     std::deque<int> dq;

//     dq.push_back(10);
//     dq.push_front(20);
//     dq.push_back(30);

//     std::cout << "�e�ݡG" << dq.front() << std::endl;
//     std::cout << "���ݡG" << dq.back() << std::endl;

//     dq.pop_front();
//     dq.pop_back();
// }

// c. �`����C�]�ϥΰ}�C��{�^�G
// class CircularQueue {
// private:
//     std::vector<int> data;
//     int front, rear, size;

// public:
//     CircularQueue(int k) : data(k), front(0), rear(0), size(0) {}

//     bool enQueue(int value) {
//         if (isFull()) return false;
//         data[rear] = value;
//         rear = (rear + 1) % data.size();
//         size++;
//         return true;
//     }

//     bool deQueue() {
//         if (isEmpty()) return false;
//         front = (front + 1) % data.size();
//         size--;
//         return true;
//     }

//     int Front() {
//         if (isEmpty()) return -1;
//         return data[front];
//     }

//     int Rear() {
//         if (isEmpty()) return -1;
//         return data[(rear - 1 + data.size()) % data.size()];
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     bool isFull() {
//         return size == data.size();
//     }
// };

// d. �ϥΨ�Ӱ��|��{��C�G
// class QueueUsingStacks {
// private:
//     std::stack<int> s1, s2;

// public:
//     void push(int x) {
//         s1.push(x);
//     }

//     int pop() {
//         if (s2.empty()) {
//             while (!s1.empty()) {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int result = s2.top();
//         s2.pop();
//         return result;
//     }

//     int peek() {
//         if (s2.empty()) {
//             while (!s1.empty()) {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         return s2.top();
//     }

//     bool empty() {
//         return s1.empty() && s2.empty();
//     }
// };