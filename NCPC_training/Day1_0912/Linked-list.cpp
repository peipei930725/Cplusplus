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

    // ���J�`�I�]�b�Y�����J�^
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // �R���`�I�]�R���Ĥ@�ӭȬ�val���`�I�^
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

    // �M�����
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // �d��`�I
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

    // 1. �������
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

    // 2. �˴���
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

    // 3. ��줤���`�I
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

    // 4. �X�֦������
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

    // �Ω���ժ����U��k
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

    cout << "��l���: ";
    list.traverse();

    // ���դ���
    list.reverse();
    cout << "�����: ";
    list.traverse();

    // �����˴���
    cout << "�O�_����: " << (list.hasCycle() ? "�O" : "�_") << endl;

    // ���է䤤���`�I
    Node* middle = list.findMiddle();
    cout << "�����`�I��: " << (middle ? to_string(middle->data) : "�L") << endl;

    // ���զX�֦������
    LinkedList list1, list2;
    list1.append(1);
    list1.append(3);
    list1.append(5);
    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "���1: ";
    list1.traverse();
    cout << "���2: ";
    list2.traverse();

    LinkedList mergedList = LinkedList::mergeSorted(list1, list2);
    cout << "�X�֫�: ";
    mergedList.traverse();

    return 0;
}


