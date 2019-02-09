#ifndef TRANSACTIONFILES_H
#define TRANSACTIONFILES_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"

using namespace std;

class TransactionFiles {
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
public:
    TransactionFiles(string newIncomeFilename, string newExpensesFilename)
    : INCOMES_FILENAME(newIncomeFilename), EXPENSES_FILENAME(newExpensesFilename) {};
    void addIncomeToFile(Transaction income);
    vector<Transaction> loadIncomesFromFile();
    void addExpenseToFile(Transaction expense);
    vector<Transaction> loadExpensesFromFile();
};

#endif // TRANSACTIONFILES_H
