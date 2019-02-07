#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>

#include "TransactionFiles.h"
#include "Transaction.h"
#include "User.h"

using namespace std;

class UserManager {
public:
    UserManager(string newIncomeFilename, string newExpensesFilename, User newLoggedUser) {};
};

#endif // USERMANAGER_H
