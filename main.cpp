#include <iostream>
#include "PeronalBudget.h"
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

int _main() {
    string liczba;
    cin >> liczba;
    double liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    cout << liczbaInt << endl;
    return 0;
}
int __main() {
    string a;
    int b;
    while (true) {
    cin >> a;
    b = a[0];
    cout << b << endl;
    }
    return 0;
}
int main() {
    PersonalBudget test("xml/users.xml","xml/incomes.xml","xml/expenses.xml");
    while(true) {
        if(!test.userIsLogged()) {
            test.loginMenu();
        }
        else {
            test.userMenu();
        }
    }
    return 0;
}
