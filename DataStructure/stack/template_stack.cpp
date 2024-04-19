#include<iostream>

using namespace std;

template<class T>
class stack{
public:
stack (int MaxStackSize);
bool IsFull();
bool IsEmpty();
void push(int item);
void pop();

private:
int top;
T *stacking;
int Maxsize;
};

template<class T>
stack<T>::stack(int MaxStackSize) : Maxsize(MaxStackSize), top(-1) {
    stacking = new int[Maxsize];
}

template<class T>
inline bool stack<T>::IsFull(){
    if(top==Maxsize-1) return 1;
    else return 0;
}