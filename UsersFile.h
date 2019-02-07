#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFile {
    const string USERS_FILENAME;
public:
    UsersFile(): USERS_FILENAME("xml/users.xml") {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif // USERS_H
