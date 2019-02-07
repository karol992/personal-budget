#include "UserManager.h"

void UserManager::addIncome() {
    string value = "";
    int date = NULL;
    char choice = NULL;
    do {
    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Czy dodac z dzisiejsza data? (t/n)" << endl;
    cin.sync();
    choice = Interface::loadSign();
    switch (choice) {
    case 't':
        date = getCurrentDate();
        cout << "Wpisz wartosc przychodu: " << endl;
        cin >> value;
        break;
    case 'n':
        cout << "Wpisz date przychodu (yyyy-mm-dd): " << endl;
        date = getUserDate();
        cout << "Wpisz wartosc przychodu: " << endl;
        cin >> value;
        break;
    default:
        cout << "Niepoprawny wybor." << endl;
        break;
    }
    } while (choice!='n' && choice!='t');
}
int UserManager::getCurrentDate() {
    int currentDate;
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    currentDate = (now->tm_year + 1900) * pow(10,4) + (now->tm_mon + 1) * pow (10,2) + now->tm_mday;
    return currentDate;
}
int UserManager::getUserDate() {
    int integerUserDate = NULL;
    string stringUserDate = "";
    getline(cin, stringUserDate);



    return integerUserDate;
}

//
