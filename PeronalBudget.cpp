#include "PeronalBudget.h"

void PersonalBudget::showStartMenu() {
    system("cls");
    cin.sync();
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    switch (Interface::loadSign()) {
    case '1':
        //registration();
        break;
    case '2':
        //login();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        Sleep(1000);
        break;
    }
}
