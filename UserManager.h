#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>
#include <iomanip>

#include "TransactionFiles.h"
#include "Transaction.h"
#include "User.h"
#include "Interface.h"

using namespace std;

class UserManager {
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    TransactionFiles transactionFiles;
    User loggedUserCopy;

    int getCurrentDate();
    int getUserDate();
    bool correctSignsInDate(string date);
    int convertStringDateToInt(string date);
    int daysInMonth(int year, int month);
    double getTransactionValue();
    bool correctSignsInValue(string stringValue);
    double convertStringValueToDouble(string stringValue);
    int getNewIncomeId();
public:
    UserManager(string newIncomeFilename, string newExpensesFilename, User newLoggedUser)
    : transactionFiles(newIncomeFilename, newExpensesFilename), loggedUserCopy(newLoggedUser) {
    incomes = transactionFiles.loadIncomesFromFile();
    };
    void addIncome();
};

#endif // USERMANAGER_H
