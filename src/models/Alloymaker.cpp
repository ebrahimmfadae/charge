#include "Alloymaker.h"
#include "CompositionCollection.h"

using namespace std;

Alloymaker::Alloymaker()
{
    name = "";
    price = 0;
    pertPercentage = 0;
    count = 0;
    unitWeight = 0;
    weight = 0;
    compositions = new CompositionCollection();
}

string Alloymaker::getName()
{
    return name;
}

void Alloymaker::setName(string value)
{
    name = value;
}

CompositionCollection &Alloymaker::getCompositions()
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

unsigned int Alloymaker::getCount()
{
    return count;
}

void Alloymaker::setCount(unsigned int value)
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

unsigned int Alloymaker::getPrice()
{
    return price;
}

void Alloymaker::setPrice(unsigned int value)
{
    price = value;
}
