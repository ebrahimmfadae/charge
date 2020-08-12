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
    return count == 0 ? weight : getCount() * getUnitWeight();
}

void Alloymaker::setWeight(double value)
{
    weight = value;
}

size_t Alloymaker::getCount()
{
    return count;
}

void Alloymaker::setCount(size_t value)
{
    count = value;
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
