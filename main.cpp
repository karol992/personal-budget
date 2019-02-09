#include <iostream>
#include "PeronalBudget.h"
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

int _main() {
    double db;
    int integer;
    cin >> db;
    integer = db;
    cout << integer;
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
