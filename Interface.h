#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <sstream>
//#include <fstream>
#include <algorithm>


using namespace std;

class Interface {
public:
    static char loadSign();
    static string firstCapitalRestLowercase(string text);
    static string doubleToString(double number);
    static double stringToDouble(string number);
};


#endif // INTERFACE_H
