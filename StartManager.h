#ifndef STARTMANAGER_H
#define STARTMANAGER_H

#include <iostream>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class StartManager {
    User user;
    User enterNewUserData();
public:
    void registration();
};

#endif // STARTMANAGER_H
