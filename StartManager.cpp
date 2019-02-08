#include "StartManager.h"

StartManager::StartManager(string usersFilename) : usersFile(usersFilename) {
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
    string login = "", password = "", name = "", surname = "";
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
void StartManager::login() {
    string login = "", password = "";
    system("cls");
    cout << "    >>> LOGOWANIE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Podaj login: ";
    cin >> login;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int tryAmount = 3; tryAmount > 0; tryAmount--) {
                cout << "Podaj haslo. Pozostalo prob: " << tryAmount << ": ";
                cin >> password;

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUser = users[i];
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}
bool StartManager::userIsLogged() {
if (loggedUser.getId() > 0)
        return true;
    else
        return false;
}
void StartManager::clearLoggedUser() {
    loggedUser.clear();
}
void StartManager::changeLoggedUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedUser.getId())
        {
            users[i].setPassword(newPassword);
            loggedUser.setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.changePasswordInFile(loggedUser);
}
User StartManager::getLoggedUser() {
    return loggedUser;
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
