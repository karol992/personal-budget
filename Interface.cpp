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
string Interface::intToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int Interface::tmToInt(tm* &tmDate) {
    int intDate;
    intDate = (tmDate->tm_year + 1900) * pow(10,4) + (tmDate->tm_mon + 1) * pow (10,2) + tmDate->tm_mday;
    return intDate;
}
//
