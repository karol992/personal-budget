#include "StartManager.h"

void StartManager::registration() {
    User user;// = enterNewUserData();

    //users.push_back(user);
    //usersFile.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User StartManager::enterNewUserData() {
    User user;
    //user.ustawId(getNewUserId());
    /*string login, password;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    */
    return user;
}
