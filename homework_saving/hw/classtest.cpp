#include<iostream>
#include<string>

using namespace std;

class hello{
public:
    void displayMessage(){
        cout<<"helloworld"<<endl;
    }
};
int main(){
    hello first;
    first.displayMessage();

    return 0;
}