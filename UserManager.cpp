#include "UserManager.h"

void UserManager::addIncome() {
    addTransaction(incomes, INCOMES_FILENAME, "PRZYCHODU");
}
void UserManager::addExpense() {
    addTransaction(expenses, EXPENSES_FILENAME, "WYDATKU");
}
int UserManager::getCurrentDate() {
    int currentDate;
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    currentDate = Interface::tmToInt(now);
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
    time_t t = time(0);
    tm* now = localtime(&t);
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
    if ((year < 2000) || (year > (now->tm_year + 1900))) {
        cout << "Niepoprawny rok." << endl;
        return 0;
    }
    if ( ((month < 1) || (month > 12)) || (year == (now->tm_year + 1900) && month > (now->tm_mon + 1)) ) {
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
                cout << "Zly format wartosci: waluta z dokladnoscia do 0.01 ." << endl;
                return false;
            }
        }
        if (((sign < 48) || (sign > 57)) && (sign != 46)&& (sign != 44)) {
            cout << "Niepoprawny znak w wartosci." << endl;
            return false;
        }
    }
    if (dotCounter > 1) {
        cout << "Zly format wartosci: zbyt wiele przecinkow." << endl;
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
        cout << "   >>> DODAWANIE " << keyWord << " <<<" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Czy dodac z dzisiejsza data? (t/n)" << endl;
        cin.sync();
        choice = Interface::loadSign();
        switch (choice) {
        case 't':
            transaction.setDate(getCurrentDate());
            break;
        case 'n':
            cout << "Wpisz date (yyyy-mm-dd): ";
            transaction.setDate(getUserDate());
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            break;
        }
    } while (choice!='n' && choice!='t');
    cout << "Wpisz nazwe: ";
    getline(cin, item);
    if(item.size() > 16)
        item.resize(16);
    transaction.setItem(item);
    cout << "Wpisz wartosc: ";
    transaction.setValue(getTransactionValue());
    transactions.push_back(transaction);
    transactionFiles.addTransactionToFile(transaction, filename);
    transform(keyWord.begin(), keyWord.end(), keyWord.begin(), ::tolower);
    cout << "Dodano pozycje " << keyWord << "." << endl << endl;
    system("pause");
}
void UserManager::sortTransactions(vector<Transaction> &transactions) {
    sort(transactions.begin(), transactions.end(), comparison());
}
void UserManager::showSelectedPeriodBalance() {
    system("cls");
    int startDate = 0, endDate = 0;
    cout << "Podaj date poczatkowa(yyyy-mm-dd): ";
    startDate = getUserDate();
    do {
        cout << "Podaj date koncowa(yyyy-mm-dd): ";
        endDate = getUserDate();
        if (endDate < startDate) {
            cout << "Data koncowa nie moze byc wczesniejsza niz poczatkowa." << endl;
        }
    } while (endDate < startDate);
    showBalanceTable(startDate,endDate);
}
void UserManager::showBalanceTable(int startDate, int endDate) {
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    string intro, temp1, temp2;
    stringstream ss;
    ss << convertIntDateToString(startDate);
    ss >> temp1;
    ss.clear();
    ss << convertIntDateToString(endDate);
    ss >> temp2;
    ss.clear();
    intro = "od " + temp1 + " do " + temp2;

    vector<Transaction> selectedIncomes, selectedExpenses;
    for (int i = 0; i < incomes.size(); i++) {
        if((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate)) {
            selectedIncomes.push_back(incomes[i]);
        }
    }
    for (int i = 0; i < expenses.size(); i++) {
        if((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <= endDate)) {
            selectedExpenses.push_back(expenses[i]);
        }
    }

    sortTransactions(selectedIncomes);
    sortTransactions(selectedExpenses);
    double totalIncome = 0, totalExpense = 0, sum = 0;
    for (int i = 0; i < selectedIncomes.size(); i++) {
        totalIncome+= selectedIncomes[i].getValue();
    }
    for (int i = 0; i < selectedExpenses.size(); i++) {
        totalExpense+= selectedExpenses[i].getValue();
    }
    system("cls");
    cout << "    >>> BILANS BUDZETU OSOBISTEGO <<<     " << endl;
    cout << ",----------------------------------------," << endl;
    cout << "| Wlasciciel: ";
    cout.width(27); cout << left << getUserFullName() << "|" << endl;
    cout << "| Okres: ";
    cout.width(31); cout << left << intro << " |" << endl;
    cout << "|========================================|" << endl;
    cout << "| Przychody: ";
    cout.width(28); cout << left << fixed << setprecision(2) << totalIncome << "|" << endl;
    //cout << "|                                    |" << endl;
    cout << "|  ,-------------------------------------|" << endl;
    cout << "|  | Wartosc |      Nazwa     |   Data   |" << endl;
    cout << "|  |-------------------------------------|" << endl;
    for (int i = 0; i < selectedIncomes.size(); i++) {
        cout << "|  |";
        cout.width(9); cout << right << fixed << setprecision(2) << selectedIncomes[i].getValue() << "|";
        cout.width(16); cout << left << selectedIncomes[i].getItem() << "|";
        cout.width(10); cout << right << selectedIncomes[i].getStringDate() << "|";
        cout << endl;
    }
    cout << "|========================================|" << endl;
    cout << "| Wydatki: ";
    cout.width(30); cout << left << fixed << setprecision(2) << totalExpense << "|" << endl;
    //cout << "|                                    |" << endl;
    cout << "|  ,-------------------------------------|" << endl;
    cout << "|  | Wartosc |      Nazwa     |   Data   |" << endl;
    cout << "|  |-------------------------------------|" << endl;
    for (int i = 0; i < selectedExpenses.size(); i++) {
        cout << "|  |";
        cout.width(9); cout << right << fixed << setprecision(2) << selectedExpenses[i].getValue() << "|";
        cout.width(16); cout << left << selectedExpenses[i].getItem() << "|";
        cout.width(10); cout << right << selectedExpenses[i].getStringDate() << "|";
        cout << endl;
    }
    cout << "|========================================|" << endl;
    cout << "| Saldo: ";
    sum = totalIncome-totalExpense;
    int textAlign = 32;
    if (sum >=0) {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << "+";
        textAlign--;
    }
    else {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    }
    cout.width(textAlign); cout << left << fixed << setprecision(2) <<totalIncome-totalExpense ;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout << "|" << endl;
    cout << "'----------------------------------------'" << endl;
    system("pause");
}
void UserManager::showCurrentMonthBalance() {
    int startDate = 0, endDate = 0;
    time_t t = time(0);
    tm* now = localtime(&t);
    startDate = ((Interface::tmToInt(now))/100) * 100 + 1; // first day of current month
    endDate = startDate + daysInMonth((now->tm_year) + 1900,(now->tm_mon) + 1) - 1;
    showBalanceTable(startDate,endDate);
}
void UserManager::showPreviousMonthBalance() {
    int startDate = 0, endDate = 0;
    time_t t = time(0);
    tm* now = localtime(&t);
    startDate = ((Interface::tmToInt(now))/100) * 100 + 1; // first day of current month
    if ((now->tm_mon) == 0) { // 0 = styczeñ
        startDate = startDate - 10000 + 1100; // -10000(-one year), +1100(from 1. January to 1. December)
        endDate = startDate + 30;
    }
    else {
        startDate -= 100; // -100 (-one month)
        endDate = startDate + daysInMonth((now->tm_year) + 1900,(now->tm_mon)) - 1; // from first to last day of month
    }
    showBalanceTable(startDate,endDate);
}
string UserManager::convertIntDateToString(int date) {
    string stringDate = Interface::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
    return stringDate;
}
string UserManager::getUserFullName() {
    string fullname;
    fullname = loggedUserCopy.getName() + " " + loggedUserCopy.getSurname();
    return fullname;
}

//
