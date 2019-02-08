#ifndef TRANSACTIONFILES_H
#define TRANSACTIONFILES_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"

using namespace std;

class TransactionFiles {
    const string INCOMES_FILENAME;
    const string EXPENSES_FILNAME;
public:
    TransactionFiles(string newIncomeFilename, string newExpensesFilename)
    : INCOMES_FILENAME(newIncomeFilename), EXPENSES_FILNAME(newExpensesFilename) {};
    void addIncomeToFile(Transaction income);
    vector<Transaction> loadIncomesFromFile();
};

#endif // TRANSACTIONFILES_H
