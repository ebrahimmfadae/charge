#include <string>
#include <sstream>
#include "Composition.h"

Composition::Composition()
{
    symbol = "";
    percentage = 0;
}

Composition::Composition(string symbol, double percentage)
{
    this->symbol = symbol;
    this->percentage = percentage;
}

double Composition::getPercentage()
{
    return percentage;
}

void Composition::setPercentage(double value)
{
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
