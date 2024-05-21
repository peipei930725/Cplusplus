#include <iostream>
#include <string>
#include "bcd.cpp"
using namespace std;

int main(void) {
    string num1;
    string num2;
    
    while(true) {
        string num1;
        string symbol;
        string num2;

        cin >> num1;
        if(num1=="STOP"){//判斷是否為數字
            break;
        } 
        stringtolink lnum1= stringtolink(num1);

        while(true){
            cin >> symbol;
            if(symbol== "+"){
                cin >> num2;
                stringtolink lnum2= stringtolink(num2);
                lnum1.link_add(lnum2.head);
            }
            else if(symbol=="-"){
                cin >> num2;
                stringtolink lnum2= stringtolink(num2);
            }
            else{ //symbol== "="
                break;
            }
        }
        lnum1.print();
        int carryout = 0;
        int carryin = 0;
    }
    return 0;
}
