#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "Interface.h"

using namespace std;

class Transaction {
    int id;
    int userId;
    int date;
    string item;
    double value;
    string stringValue;
public:
    Transaction() : id(0), userId(0), date(0), item(""), value(0), stringValue("") {};
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getValue();
    string getStringValue();

    void setId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setValue(double newValue);

};

#endif // TRANSACTION_H
