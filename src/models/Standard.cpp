#include "Standard.h"

Standard::Standard()
{
    symbols = new string[0];
    min = 0;
    max = 0;
}

double Standard::getMin()
{
    return min;
}

void Standard::setMin(double value)
{
    min = value;
}

double Standard::getMax()
{
    return max;
}

void Standard::setMax(double value)
{
    max = value;
}

string *Standard::getSymbols()
{
    return symbols;
}

void Standard::setSymbols(string value[])
{
    symbols = value;
}
