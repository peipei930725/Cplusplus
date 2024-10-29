#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 插入節點（在頭部插入）
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 刪除節點（刪除第一個值為val的節點）
    void remove(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // 遍歷鏈表
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 查找節點
    bool search(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // 1. 反轉鏈表
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 2. 檢測環
    bool hasCycle() {
        if (head == nullptr || head->next == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }

    // 3. 找到中間節點
    Node* findMiddle() {
        if (head == nullptr) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // 4. 合併有序鏈表
    static LinkedList mergeSorted(LinkedList& list1, LinkedList& list2) {
        LinkedList result;
        Node* dummy = new Node(0);
        Node* current = dummy;
        
        Node* p1 = list1.head;
        Node* p2 = list2.head;
        
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->data <= p2->data) {
                current->next = p1;
                p1 = p1->next;
            } else {
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        
        if (p1 != nullptr) current->next = p1;
        if (p2 != nullptr) current->next = p2;
        
        result.head = dummy->next;
        delete dummy;
        return result;
    }

    // 用於測試的輔助方法
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    cout << "原始鏈表: ";
    list.traverse();

    // 測試反轉
    list.reverse();
    cout << "反轉後: ";
    list.traverse();

    // 測試檢測環
    cout << "是否有環: " << (list.hasCycle() ? "是" : "否") << endl;

    // 測試找中間節點
    Node* middle = list.findMiddle();
    cout << "中間節點值: " << (middle ? to_string(middle->data) : "無") << endl;

    // 測試合併有序鏈表
    LinkedList list1, list2;
    list1.append(1);
    list1.append(3);
    list1.append(5);
    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "鏈表1: ";
    list1.traverse();
    cout << "鏈表2: ";
    list2.traverse();

    LinkedList mergedList = LinkedList::mergeSorted(list1, list2);
    cout << "合併後: ";
    mergedList.traverse();

    return 0;
}


