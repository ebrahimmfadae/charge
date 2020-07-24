#include <string>
#include <sstream>
#include "Composition.h"

Composition::Composition()
{
    Composition::symbol = "";
    Composition::percentage = 0;
}

Composition::Composition(string symbol, double percentage)
{
    Composition::symbol = symbol;
    Composition::percentage = percentage;
}

double Composition::getPercentage()
{
    return Composition::percentage;
}

void Composition::setPercentage(double value)
{
    Composition::percentage = value;
}

string Composition::getSymbol()
{
    return Composition::symbol;
}

void Composition::setSymbol(string value)
{
    Composition::symbol = value;
}

string Composition::toString()
{
    ostringstream stream;
    stream << Composition::symbol << " " << Composition::percentage << "\n";
    return stream.str();
}
