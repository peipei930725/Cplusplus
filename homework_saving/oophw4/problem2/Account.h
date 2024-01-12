#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<string>

using namespace std;

class Account{
    public:
        Account();
        Account(double);
        void credit(double);
        void debit(double);
        double getBalance();
        void checkBalance();
    private:
        double balance;
};

#endif

