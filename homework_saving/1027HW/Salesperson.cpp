#include<iostream>

using namespace std;

#include<iomanip>
#include "SalesPerson.h"

SalesPerson::SalesPerson(){
    for(int i=0;i<4;++i){
        sales[i]=0.0;
    }
}
void SalesPerson::getSalesFromUser(){
    double salesFigure;

    for(int i=1;i<=4;++i){
        cout<<"Enter sales amount for quarterly"<<i<<": ";
        cin>>salesFigure;
        setSales(i,salesFigure);
    }
}
void SalesPerson::setSales(int quarter,double amount){
    if(quarter>=1 && quarter<=4 && amount>0){
        sales[quarter-1]=amount;
    }
    else{
        cout<<"Invalid month or sales figure"<<endl;
    }
}
void SalesPerson::printAnnualSales(){
    cout<<setprecision(2)<<fixed
    <<"\nThe total annual sales are: $"
    <<totalAnnualSales()<<endl;
}
double SalesPerson::totalAnnualSales (){
    double total=0.0;

    for(int i=0;i<4;++i){
        total+=sales[i];
    }

    return total;
}