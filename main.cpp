#include <iostream>
#include "PeronalBudget.h"
#include <sstream>
#include <fstream>
#include <algorithm>

#include <ctime>
#include "PeronalBudget.h"

using namespace std;

int _main() {
    int currentDate;
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    currentDate = Interface::tmToInt(now);
    cout << currentDate << endl;
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
