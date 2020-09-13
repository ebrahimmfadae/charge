#include <stdexcept>
#include "Alloymaker.h"
#include "Composition.h"

using namespace std;

Alloymaker::Alloymaker()
{
    name = "";
    price = 0;
    lossPercentage = 0;
    count = 0;
    unitWeight = 0;
    weight = 0;
    isQuantified = false;
    lowerBound = 0;
    upperBound = 0;
    compositions = new Composition();
}

string Alloymaker::getName()
{
    return name;
}

void Alloymaker::setName(string value)
{
    name = value;
}

Composition &Alloymaker::getCompositions()
{
    return *compositions;
}

void Alloymaker::setCompositions(Composition &value)
{
    compositions = &value;
}

double Alloymaker::getUnitWeight()
{
    return unitWeight;
}

void Alloymaker::setUnitWeight(double value)
{
    unitWeight = value;
}

double Alloymaker::getWeight()
{
    return getIsQuantified() ? weight : getCount() * getUnitWeight();
}

void Alloymaker::setWeight(double value)
{
    if (getIsQuantified())
        throw runtime_error("can't set weight for a quantified alloymaker");
    weight = value;
}

size_t Alloymaker::getCount()
{
    return count;
}

void Alloymaker::setCount(size_t value)
{
    if (!getIsQuantified())
        throw runtime_error("can't set count for a not quantified alloymaker");
    count = value;
}

void Alloymaker::setIsQuantified(bool value)
{
    isQuantified = value;
}

bool Alloymaker::getIsQuantified()
{
    return isQuantified;
}

double Alloymaker::getLossPercentage()
{
    return lossPercentage;
}

void Alloymaker::setLossPercentage(double value)
{
    lossPercentage = value;
}

double Alloymaker::getLowerBound()
{
    return lowerBound;
}

void Alloymaker::setLowerBound(double value)
{
    lowerBound = value;
}

double Alloymaker::getUpperBound()
{
    return upperBound;
}

void Alloymaker::setUpperBound(double value)
{
    upperBound = value;
}

size_t Alloymaker::getPrice()
{
    return price;
}

void Alloymaker::setPrice(size_t value)
{
    price = value;
}
