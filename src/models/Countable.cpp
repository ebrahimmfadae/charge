#include "Countable.h"

Countable::Countable()
{
    Countable::count = 0;
    Countable::unitWeight = 0;
}

double Countable::getWeight()
{
    return Countable::count * Countable::unitWeight;
}

void Countable::setCount(int value)
{
    Countable::count = value;
}

double Countable::getUnitWeight()
{
    return Countable::unitWeight;
}

void Countable::setUnitWeight(double value)
{
    Countable::unitWeight = value;
}
