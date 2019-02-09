#ifndef TRANSACTIONFILES_H
#define TRANSACTIONFILES_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"

using namespace std;

class TransactionFiles {
public:
    void addTransactionToFile (Transaction transaction, string filename);
    vector<Transaction> loadTransactionsFromFile(string filename);
    void sortTransactionsInFile(string filename);
};

#endif // TRANSACTIONFILES_H
