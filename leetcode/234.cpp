#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> compare;
        while(head->next!=nullptr)
        {   
            auto a=head->val;
            compare.push_back(a);
            head=head->next;
        }
        for(int i=0;i<compare.size()/2;++i){
            if(compare[i]!=compare[compare.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(1);

    Solution s;
    cout<<s.isPalindrome(head);
}