#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include"Account.h"
#include<iostream>
#include<string>

using namespace std;

class CheckingAccount:public Account{
    public:
        CheckingAccount();
        CheckingAccount(double,double);
        void setFee(double);
        double getFee();
        void credit(double);
        void debit(double);
    private:
        double fee;
};

#endif