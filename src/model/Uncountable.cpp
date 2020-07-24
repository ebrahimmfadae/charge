#include "Uncountable.h"

Uncountable::Uncountable()
{
    Uncountable::weight = 0;
}

double Uncountable::getWeight()
{
    return Uncountable::weight;
}

void Uncountable::setWeight(double value)
{
    Uncountable::weight = value;
}
