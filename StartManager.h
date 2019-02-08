#ifndef STARTMANAGER_H
#define STARTMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "UsersFile.h"
#include "Interface.h"

using namespace std;

class StartManager {
    vector <User> users;
    UsersFile usersFile;
    User loggedUser;

    User enterNewUserData();
    bool isLoginExist(string login);
    int getNewUserId();
public:
    StartManager(string usersFilename);
    void registration();
    void login();
    void showUsers();
    bool userIsLogged();
    void clearLoggedUser();
    void changeLoggedUserPassword();
    User getLoggedUser();
};

#endif // STARTMANAGER_H
