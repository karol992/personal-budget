#include "PeronalBudget.h"

void PersonalBudget::loginMenu() {
    system("cls");
    cin.sync();
    cout << "    >>> MENU LOGOWANIA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    switch (Interface::loadSign()) {
    case '1':
        registration();
        break;
    case '2':
        login();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
}
void PersonalBudget::userMenu() {
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    switch (Interface::loadSign()) {
    case '1':
        addIncome();
        break;
    case '2':
        addExpense();
        break;
    case '3':
        showCurrentMonthBalance();
        break;
    case '4':
        //showLastMonthBalance();
        break;
    case '5':
        showBalance();
        break;
    case '6':
        changeLoggedUserPassword();
        break;
    case '7':
        userLogOut();
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
}
void PersonalBudget::registration() {
    startManager.registration();
}
void PersonalBudget::login() {
    startManager.login();
    if (startManager.userIsLogged()) {
        userManager = new UserManager(INCOMES_FILENAME, EXPENSES_FILENAME, startManager.getLoggedUser());
    }
}
bool PersonalBudget::userIsLogged() {
    return startManager.userIsLogged();
}
void PersonalBudget::userLogOut() {
    startManager.clearLoggedUser();
}
void PersonalBudget::changeLoggedUserPassword() {
    startManager.changeLoggedUserPassword();
}
void PersonalBudget::addIncome() {
    userManager->addIncome();
}
void PersonalBudget::addExpense() {
    userManager->addExpense();
}
void PersonalBudget::showBalance() {
    userManager->showBalance();
}
void PersonalBudget::showCurrentMonthBalance() {
    userManager->showCurrentMonthBalance();
}

//
