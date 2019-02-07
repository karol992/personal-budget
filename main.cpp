#include <iostream>
#include "PeronalBudget.h"

using namespace std;

int _main() {
    PersonalBudget test("xml/users.xml","xml/incomes.xml","xml/expenses.xml");
    StartManager a("xml/users.xml");
    //a.registration();
    //a.registration();
    //a.registration();
    a.showUsers();
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
