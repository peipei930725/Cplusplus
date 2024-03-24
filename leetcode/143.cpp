struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reg;
    void findend(ListNode* ans){
        while(ans->next->next!=nullptr){
            ans=ans->next;
        }
        reg=ans->next;
        ans->next=nullptr;
    }
    void reorderList(ListNode* head) {
        ListNode* ans=head;
        ListNode* first=head;
        int size=1;
        while(head->next!=nullptr){
            head=head->next;
            size++;
        }
        head=first;
        while(size>1){
            ans=first;
            findend(ans);
            reg->next=head->next;
            head->next=reg;
            head=head->next->next;
            size-=2;
        }
    }
};

int main(){
    ListNode* head=new ListNode(1);
    ListNode* first=head;
    head->next=new ListNode(2);
    head=head->next;
    head->next=new ListNode(3);
    head=head->next;
    head->next=new ListNode(4);

    Solution s;
    s.reorderList(first);

    return 0;
}