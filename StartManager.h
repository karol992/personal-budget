#ifndef STARTMANAGER_H
#define STARTMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class StartManager {
    User user;
    vector <User> users;
    User enterNewUserData();
    bool isLoginExist(string login);
    int getNewUserId();
public:
    void registration();
    void showUsers();
};

#endif // STARTMANAGER_H
