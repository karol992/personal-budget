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
    UsersFile(string usersFilename): USERS_FILENAME(usersFilename) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changePasswordInFile (User loggedUser);
};

#endif // USERS_H
