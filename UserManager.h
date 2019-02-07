#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

#include "TransactionFiles.h"
#include "Transaction.h"
#include "User.h"
#include "Interface.h"

using namespace std;

class UserManager {
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILNAME;
    User loggedUserCopy;

    int getCurrentDate();
    int getUserDate();
    bool correctSignsInDate(string date);
    int convertStringDateToInt(string date);
    int daysInMonth(int year, int month);
    double getTransationValue();
public:
    UserManager(string newIncomeFilename, string newExpensesFilename, User newLoggedUser)
    : INCOMES_FILENAME(newIncomeFilename), EXPENSES_FILNAME(newExpensesFilename), loggedUserCopy(newLoggedUser) {};
    void addIncome();
};

#endif // USERMANAGER_H
