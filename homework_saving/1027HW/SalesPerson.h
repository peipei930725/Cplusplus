#ifndef SALESP_H
#define SALESP_H

class SalesPerson{
    public:
    SalesPerson();
    void getSalesFromUser();
    void setSales(int ,double);
    void printAnnualSales();
    private:
    double totalAnnualSales();
    double sales[4];
};

#endif