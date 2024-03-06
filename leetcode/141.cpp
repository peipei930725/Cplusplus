#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
vector<ListNode*> hash;
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        hash.push_back(head);
        for(int i=0;i<hash.size()-1;++i){
            if(head==hash[i]) return true;
        }
        hasCycle(head->next);
        return false;
    }
};

int main(){
    Solution s;
    ListNode* head=new ListNode(3);
    head->next=new ListNode(2);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(-4);
    head->next->next->next->next=head->next;
    cout<<s.hasCycle(head);
}   // Output: 1