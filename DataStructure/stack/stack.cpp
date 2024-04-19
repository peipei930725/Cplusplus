#include<iostream>

using namespace std;


class stack{
public:
stack (int MaxStackSize);
bool IsFull();
bool IsEmpty();
void push(int item);
void pop();

private:
int top;
int *stacking;
int Maxsize;
};

// template<class T>
stack::stack(int MaxStackSize) : Maxsize(MaxStackSize), top(-1) {
    stacking = new int[Maxsize];
}

inline bool stack::IsFull(){
    if(top==Maxsize-1) return 1;
    else return 0;
}