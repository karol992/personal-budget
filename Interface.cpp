#include "Interface.h"

char Interface::loadSign() {
    string input = "";
    char sign  = {0};
    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
string Interface::firstCapitalRestLowercase(string word) {
    if (!word.empty()) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word[0] = toupper(word[0]);
    }
    return word;
}
string Interface::doubleToString(double number)
{
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    return  str;
}
double Interface::stringToDouble(string number) {
    double doubleNumber;
    istringstream iss(number);
    iss >> doubleNumber;
    return doubleNumber;
}
//
