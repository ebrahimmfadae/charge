#include "Standard.h"

using namespace std;

Standard::Standard()
{
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

vector<string> &Standard::getSymbols()
{
    return symbols;
}

void Standard::setSymbols(vector<string> value)
{
    symbols = value;
}
