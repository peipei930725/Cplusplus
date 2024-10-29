#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;

    // 新增元素
    q.push(10);
    q.push(20);
    q.push(30);

    // 取得佇列大小
    std::cout << "佇列大小：" << q.size() << std::endl;

    // 取得佇列前端元素
    std::cout << "佇列前端：" << q.front() << std::endl;

    // 取得佇列尾端元素
    std::cout << "佇列尾端：" << q.back() << std::endl;

    // 移除前端元素
    q.pop();

    // 檢查佇列是否為空
    if (!q.empty()) {
        std::cout << "佇列不為空" << std::endl;
    }

    // 清空佇列
    while (!q.empty()) {
        q.pop();
    }
}

// a. 優先佇列（Priority Queue）： *****
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
//     // 輸出：30 20 10
// }

// b. 雙端佇列（Deque）： ***
// #include <deque>
// #include <iostream>

// int main() {
//     std::deque<int> dq;

//     dq.push_back(10);
//     dq.push_front(20);
//     dq.push_back(30);

//     std::cout << "前端：" << dq.front() << std::endl;
//     std::cout << "尾端：" << dq.back() << std::endl;

//     dq.pop_front();
//     dq.pop_back();
// }

// c. 循環佇列（使用陣列實現）：
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

// d. 使用兩個堆疊實現佇列：
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