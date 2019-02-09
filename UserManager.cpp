#include "UserManager.h"

void UserManager::addIncome() {
    addTransaction(incomes, INCOMES_FILENAME, "dochodu");
}
void UserManager::addExpense() {
    addTransaction(expenses, EXPENSES_FILENAME, "wydatku");
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
    do {
        getline(cin, stringUserDate);
        if (correctSignsInDate(stringUserDate)) {
            integerUserDate = convertStringDateToInt(stringUserDate);
            if (integerUserDate != 0)
                break;
        }
        cout << "Wpisz poprawna date: " << endl;
    } while (true);
    return integerUserDate;
}
bool UserManager::correctSignsInDate(string date) {
    int dashCounter = 0;
    if (date[0] == '-') {
        cout << "Zly format daty. #1" << endl;
        return false;
    }
    for (int i = 0; i < date.size(); i++) {
        int sign = date[i];
        if (((sign < 48) || (sign > 57)) && (sign != 45)) {
            cout << "Niedozwolony znak w dacie." << endl;
            return false;
        }
        else if (sign == 45 && int(date[i+1]) == 45) {
            cout << "Zly format daty. #2" << endl;
            return false;
        }
        if (sign == 45) {
            dashCounter++;
        }
    }
    if ((dashCounter != 2) || (date[date.size() - 1] == 45)) {
        cout << "Zly format daty. #3" << endl;
        return false;
    }
    return true;
}
int UserManager::convertStringDateToInt(string date) {
    int i = 0, year = 0, month = 0, day = 0, intDate = 0;
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++) {
        year=year*10+int(date[i])-48;
    }
    i++;
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++) {
        month=month*10+int(date[i])-48;
    }
    i++;
    for(; i < date.size(); i++) {
        day=day*10+int(date[i])-48;
    }
    if ((year < 1000) || (year > 9999)) {
        cout << "Niepoprawny rok." << endl;
        return 0;
    }
    if ((month < 1) || (month > 12)) {
        cout << "Niepoprawny miesiac." << endl;
        return 0;
    }
    if ((day == 0) || (day > daysInMonth(year,month))) {
        cout << "Niepoprawny dzien." << endl;
        return 0;
    }
    intDate = (year * pow (10,4)) + (month * pow (10,2)) + day;
    return intDate;
}
int UserManager::daysInMonth(int year, int month) { // http://www.cplusplus.com/forum/beginner/115693/
    int days;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 02) {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (!leapYear)
            days = 28;
        else
            days = 29;
    } else
        days = 31;
    return days;
}
double UserManager::getTransactionValue() {
    double transactionValue = 0;
    string stringValue = "";
    do {
        getline(cin, stringValue);
        if (correctSignsInValue(stringValue)) {
            transactionValue = convertStringValueToDouble(stringValue);
            break;
        }
        cout << "Wpisz poprawna wartosc: " << endl;
    } while (true);
    return transactionValue;
}
bool UserManager::correctSignsInValue(string stringValue) {
    int dotCounter = 0;
    for (int i = 0; i < stringValue.size(); i++) {
        int sign = stringValue[i];
        if (sign == 44 || sign == 46) {
            dotCounter++;
            if (stringValue.size() > i+3) {
                cout << "Zly format wartosci. #1" << endl;
                return false;
            }
        }
        if (((sign < 48) || (sign > 57)) && (sign != 46)&& (sign != 44)) {
            cout << "Niepoprawny znak w wartosci." << endl;
            return false;
        }
    }
    if (dotCounter > 1) {
        cout << "Zly format wartosci. #2" << endl;
        return false;
    }
    if (stringValue.empty()) {
        cout << "Nie wprowadzono wartosci." << endl;
        return false;
    }
    return true;
}
double UserManager::convertStringValueToDouble(string stringValue) {
    double doubleValue = 0;
    for (int i = 0, j = stringValue.size()-1; i < stringValue.size(); i++, j--) {
            int sign = stringValue[i];
            if (sign == 44 || sign == 46) {
                    doubleValue = doubleValue / pow(10,j+1);
                    j = 0;
            }
            else {
                    doubleValue = doubleValue + ((sign - 48) * pow(10,j));
            }
    }
    return doubleValue;
}
int UserManager::getNewTransactionId(vector <Transaction> transactions) {
    if (transactions.empty() == true)
        return 1;
    else
        return transactions.back().getId() + 1;
}
void UserManager::addTransaction(vector<Transaction> &transactions, string filename, string keyWord) {
    Transaction transaction;
    string item;
    transaction.setId(getNewTransactionId(transactions));
    transaction.setUserId(loggedUserCopy.getId());
    char choice = NULL;
    do {
        system("cls");
        cout << " >>> DODAWANIE " << keyWord << " <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "Czy dodac z dzisiejsza data? (t/n)" << endl;
        cin.sync();
        choice = Interface::loadSign();
        switch (choice) {
        case 't':
            transaction.setDate(getCurrentDate());
            cout << "Wpisz wartosc " << keyWord << ": ";
            transaction.setValue(getTransactionValue());
            break;
        case 'n':
            cout << "Wpisz date " << keyWord << " (yyyy-mm-dd): ";
            transaction.setDate(getUserDate());
            cout << "Wpisz wartosc " << keyWord << ": ";
            transaction.setValue(getTransactionValue());
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            break;
        }
    } while (choice!='n' && choice!='t');
    cout << "Wpisz nazwe " << keyWord << ": ";
    getline(cin, item);
    transaction.setItem(item);
    transactions.push_back(transaction);
    transactionFiles.addTransactionToFile(transaction, filename);
    system("pause");
}

//
