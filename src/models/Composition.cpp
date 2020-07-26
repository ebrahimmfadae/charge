#include <string>
#include <sstream>
#include <iostream>
#include "Composition.h"

Composition::Composition(CompositionCollection &compositions) : Composition("", 0, compositions)
{
}

Composition::Composition(string symbol, double percentage, CompositionCollection &compositions)
{
    this->symbol = symbol;
    this->percentage = percentage;
    this->compositions = &compositions;
}

double Composition::getPercentage()
{
    return percentage;
}

void Composition::setPercentage(double value)
{
    string baseElement = compositions->getBaseElement();
    if (getSymbol() == baseElement)
        return;
    if (value < 0 || value > 100)
        throw out_of_range("value");
    Composition *baseComposition;
    double sum = value;
    for (size_t i = 0; i < compositions->size(); i++)
    {
        Composition &cmp = compositions->get(i);
        if (cmp.getSymbol() != baseElement)
            sum += cmp.getPercentage();
        else
            baseComposition = &cmp;
    }
    if (baseComposition)
        if (sum + value > 100)
            throw out_of_range("value");
        else
            baseComposition->percentage = 100 - sum;
    percentage = value;
}

string Composition::getSymbol()
{
    return symbol;
}

void Composition::setSymbol(string value)
{
    symbol = value;
}

string Composition::toString()
{
    ostringstream stream;
    stream << symbol << " " << percentage << "\n";
    return stream.str();
}
