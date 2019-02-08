#include "Transaction.h"

int Transaction::getId() {
    return id;
}
int Transaction::getUserId() {
    return userId;
}
int Transaction::getDate() {
    return date;
}
string Transaction::getItem() {
    return item;
}
double Transaction::getValue() {
    return value;
}
string Transaction::getStringValue() {
    return stringValue;
}

void Transaction::setId(int newId) {
    id = newId;
}
void Transaction::setUserId(int newUserId) {
    userId = newUserId;
}
void Transaction::setDate(int newDate) {
    date = newDate;
}
void Transaction::setItem(string newItem) {
    item = newItem;
}
void Transaction::setValue(double newValue) {
    value = newValue;
    stringValue = Interface::doubleToString(value);
}
