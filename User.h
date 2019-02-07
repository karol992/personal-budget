#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string login, password, name, surname;
public:
    User();
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string surname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
    void clear();
};

#endif // USER_H
