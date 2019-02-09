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
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
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
    int getNewTransactionId(vector<Transaction> transactions);

    void addTransaction(vector<Transaction> &transactions, string filename, string keyWord);
public:
    UserManager(string newIncomeFilename, string newExpensesFilename, User newLoggedUser)
    : INCOMES_FILENAME(newIncomeFilename), EXPENSES_FILENAME(newExpensesFilename), loggedUserCopy(newLoggedUser) {
    incomes = transactionFiles.loadTransactionsFromFile(INCOMES_FILENAME);
    expenses = transactionFiles.loadTransactionsFromFile(EXPENSES_FILENAME);
    };
    void addIncome();
    void addExpense();
};

#endif // USERMANAGER_H
