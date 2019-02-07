#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string login, password, name, surname;
public:
    User() : id(0), login(""), password(""), name(""), surname("") {};
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
};

#endif // USER_H
