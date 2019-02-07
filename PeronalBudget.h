#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>

#include "StartManager.h"
#include "UserManager.h"
#include "Interface.h"

using namespace std;

class PersonalBudget {
    StartManager startManager;
public:
    void loginMenu();
    void userMenu();
    void registration();
    void login();
    bool userIsLogged();
    void userLogOut();
    void changeLoggedUserPassword();
};


#endif // PERSONALBUDGET_H
