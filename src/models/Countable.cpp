#include "Countable.h"

Countable::Countable()
{
    count = 0;
    unitWeight = 0;
}

double Countable::getWeight()
{
    return count * unitWeight;
}

void Countable::setCount(int value)
{
    count = value;
}

double Countable::getUnitWeight()
{
    return unitWeight;
}

void Countable::setUnitWeight(double value)
{
    unitWeight = value;
}
