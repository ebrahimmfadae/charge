#include "Alloymaker.h"
#include "Composition.h"

using namespace std;

Alloymaker::Alloymaker()
{
    name = "";
    price = 0;
    pertPercentage = 0;
    count = 0;
    unitWeight = 0;
    weight = 0;
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
        throw "You can't set weight for a quantified alloymaker";
    weight = value;
}

size_t Alloymaker::getCount()
{
    if (!getIsQuantified())
        return 0 / 0;
    return count;
}

void Alloymaker::setCount(size_t value)
{
    if (!getIsQuantified())
        throw "You can't set count for a not quantified alloymaker";
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

double Alloymaker::getPertPercentage()
{
    return pertPercentage;
}

void Alloymaker::setPertPercentage(double value)
{
    pertPercentage = value;
}

size_t Alloymaker::getPrice()
{
    return price;
}

void Alloymaker::setPrice(size_t value)
{
    price = value;
}
