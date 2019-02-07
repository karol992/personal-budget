#include <iostream>
#include "PeronalBudget.h"

using namespace std;

int _main() {
    PersonalBudget test;
    StartManager a;
    //a.registration();
    //a.registration();
    //a.registration();
    a.showUsers();
    return 0;
}
int main() {
    PersonalBudget test;
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
