#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int time = 0;
    int fintime = 0;

    ListNode* removeZeroSumSublists(ListNode* head) {
        int time = 0;
        if(head==NULL) return NULL;
        if(head->val==0&&head->next==NULL) return NULL;
        ListNode* reg = head;
        ListNode* head2 = head;
        int maxSum=0;
        int maxTime=0;
        while(head2->next!=nullptr){
            time++;
            if(counting(head2)>maxSum){
                maxSum=counting(head2);
                maxTime=time;
            }
            head2=head2->next;
        }            
        maxTime--;
        for (int i = 0; i < maxTime-1; ++i) {
            head = head->next;
        }
        if(maxTime==0) maxSum--;
        for (int i = 0; i < maxSum; ++i) {
            if (head->next==NULL) {
                break;
            }
            head->next = head->next->next;
        }
        if(maxTime==0) reg=reg->next;

        head=reg;

        if(maxSum==0&&head->next){
            while(head->next->next){
                head = head->next;
            }
            if(head->next->val==0) head->next=NULL;
        }

        if(maxSum!=0){
            return removeZeroSumSublists(reg);
        }

        return reg;
    }

    int counting(ListNode* head) {
        int count = 0;
        int sum = 0;
        int max=0;
        do {
            sum += head->val;
            head = head->next;
            count++;
            if(sum==0){
                max=count;
            }
        } while (head != nullptr);

        return max;
    }
};





// Test your code
int main() {
    // Test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);

    Solution sol;
    ListNode* result = sol.removeZeroSumSublists(head);

    // Output the result (print the list)
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
