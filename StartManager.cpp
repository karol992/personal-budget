#include "StartManager.h"

StartManager::StartManager() {
    users = usersFile.loadUsersFromFile();
}
void StartManager::registration() {
    User user = enterNewUserData();
    users.push_back(user);
    usersFile.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User StartManager::enterNewUserData() {
    User user;
    user.setId(getNewUserId());
    string login, password, name, surname;
    do {
        system("cls");
        cout << "    >>> REJESTRACJA <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(Interface::firstCapitalRestLowercase(name));
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(Interface::firstCapitalRestLowercase(surname));
    return user;
}
bool StartManager::isLoginExist(string login) {
    for (int i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            system("pause");
            return true;
        }
    }
    return false;
}
int StartManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
//

//testMethods below
void StartManager::showUsers() {
    for (int i=0; i < users.size(); i++) {
        cout << users[i].getId()
             << " " << users[i].getLogin()
             << " " << users[i].getPassword()
             << " " << users[i].getName()
             << " " << users[i].getSurname() << endl;
    }
}
