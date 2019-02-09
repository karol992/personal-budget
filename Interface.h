#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <ctime>


using namespace std;

class Interface {
public:
    static char loadSign();
    static string firstCapitalRestLowercase(string text);
    static string doubleToString(double number);
    static double stringToDouble(string number);
    static string intToString(int number);
    static int tmToInt(tm* &tmDate);
};


#endif // INTERFACE_H
