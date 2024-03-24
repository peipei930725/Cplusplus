#include"linkedlist.h"
#include<iostream>

using namespace std;

void LinkedList::PrintList(){
    if(first==0){
        cout<<"array is empty"<<endl;
    }
    Node *current =first;
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
    }
}
void LinkedList::Push_front(int n){
    Node *num;
    num->next=first;
    num->data=n;
}
void LinkedList::Push_back(int n){
    Node *ptr=first;
    for(int i=0;i<size;++i){
        ptr=ptr->next;
    }
    Node*newNode;
    ptr->next=newNode;
    newNode->data=n;
}
void LinkedList::Delete(int n){
    Node *flag=first;
    while(first->data==n&&first!=0){
        first=first->next;
    }
    flag=first;
    while(flag->next->data==n && flag->next!=0){
        flag->next=flag->next->next;
    }
}
void LinkedList::Clear(){
    while (first != 0) { 
        Node *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}
void LinkedList::Reverse(){
    Node *current = first;
    Node *prev = 0;
    Node *next = 0;
    while (current != 0) {
        next = current->next;//先保存下一個節點

        current->next = prev;//把它斷掉，然後接到prev

        prev = current;
        current = next;
    }
    first = prev;
}
// A->B->C->D
// D->C