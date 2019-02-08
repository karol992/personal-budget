#include <iostream>
#include "PeronalBudget.h"

using namespace std;

int _main() {
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
