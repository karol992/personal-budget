#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>

#include "StartManager.h"
#include "UserManager.h"
#include "Interface.h"
#include "User.h"

using namespace std;

class PersonalBudget {
    StartManager startManager;
    UserManager *userManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    PersonalBudget (string usersFilename, string incomesFilename, string expensesFilename)
        : startManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename) {
        userManager = NULL;
    };
    ~PersonalBudget() {
        delete userManager;
        userManager = NULL;
    }
    void loginMenu();
    void userMenu();
    void registration();
    void login();
    bool userIsLogged();
    void userLogOut();
    void changeLoggedUserPassword();
    void addIncome();
};

#endif // PERSONALBUDGET_H
