#include<iostream>
#include<string>

using namespace std;

template<class T>
class stack{
public:
stack ();
void push(T item);
void pop();
void showthetop();
void BACK();
void FORWARD();
void VISIT(string a);
void QUIT();

private:
int max;
int top;
T *stacking;
int Maxsize;
};

template<class T>
stack<T>::stack() 
: Maxsize(101), top(-1) ,max(-1)
{
    stacking = new T[Maxsize];
    max=-1;
    top=-1;

}

template<class T>
void stack<T>::push(T item){
    top++;
    stacking[top]=item;
    if(top>max){
        max=top;
    }
}

template<class T>
void stack<T>::pop(){
    if(top==-1){
        top=-1;
    }
    else    {
        top--;
    }

}

template<class T>
void stack<T>::showthetop(){
    cout<<stacking[top]<<endl;
}

template<class T>
void stack<T>::BACK(){
    pop();
    if(top!=-1){
        showthetop();
    }
    else {
        cout<<"Ignored"<<endl;
        top=-1;
    }
}

template<class T>
void stack<T>::FORWARD(){
    cout<<top<<" "<<max<<endl;
    if(top+1>max){
        cout<<"Ignored"<<endl;
    }
    else{
        if(top==-1) top=0;
        else{
            top++;
            showthetop();
        }
    }
}

template<class T>
void stack<T>::VISIT(string http){
    push(http);
    showthetop();
}

template<class T>
void stack<T>::QUIT(){
    return;
}

int main(){
    string input;
    stack<string> answer;
    string a="http://www.acm.org/";
    answer.push(a);
    while(cin>>input){
        if(input=="VISIT"){
            string https;
            cin>>https;
            answer.VISIT(https);
        }
        else if(input=="BACK"){
            answer.BACK();
        }
        else if(input=="FORWARD"){
            answer.FORWARD();
        }
        else if(input=="QUIT"){
            answer.QUIT();
            return 0;
        }
    }


    
    return 0;
}