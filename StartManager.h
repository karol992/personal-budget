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
    StartManager();
    void registration();
    void login();
    void showUsers();
    bool userIsLogged();
};

#endif // STARTMANAGER_H
