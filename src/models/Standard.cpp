#include "Standard.h"

Standard::Standard()
{
    Standard::symbols = new string[0];
    Standard::min = 0;
    Standard::max = 0;
}

double Standard::getMin()
{
    return Standard::min;
}

void Standard::setMin(double value)
{
    Standard::min = value;
}

double Standard::getMax()
{
    return Standard::max;
}

void Standard::setMax(double value)
{
    Standard::max = value;
}

string *Standard::getSymbols()
{
    return Standard::symbols;
}

void Standard::setSymbols(string value[])
{
    Standard::symbols = value;
}
