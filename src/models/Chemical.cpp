#include <string>
#include <sstream>
#include <iostream>
#include "Chemical.h"

Chemical::Chemical(Composition &compositions) : Chemical("", 0, compositions)
{
}

Chemical::Chemical(string symbol, double percentage, Composition &compositions)
{
    this->symbol = symbol;
    this->percentage = percentage;
    this->compositions = &compositions;
}

double Chemical::getPercentage()
{
    return percentage;
}

void Chemical::setPercentage(double value)
{
    string baseElement = compositions->getBaseElement();
    if (getSymbol() == baseElement)
    {
        return;
    }
    if (value < 0 || value > 100)
    {
        throw out_of_range("value");
    }
    Chemical *baseComposition;
    double sum = value;
    for (size_t i = 0; i < compositions->size(); i++)
    {
        Chemical &cmp = compositions->get(i);
        if (cmp.getSymbol() != baseElement)
        {
            sum += cmp.getPercentage();
        }
        else
        {
            baseComposition = &cmp;
        }
    }
    if (baseComposition)
    {
        if (sum + value > 100)
        {
            throw out_of_range("value");
        }
        else
        {
            baseComposition->percentage = 100 - sum;
        }
    }
    percentage = value;
}

string Chemical::getSymbol()
{
    return symbol;
}

void Chemical::setSymbol(string value)
{
    symbol = value;
}

string Chemical::toString()
{
    ostringstream stream;
    stream << symbol << " " << percentage;
    return stream.str();
}
