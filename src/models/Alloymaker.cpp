#include "Alloymaker.h"
#include "Uncountable.h"
#include "CompositionCollection.h"

using namespace std;

Alloymaker::Alloymaker() : quantity(*new Uncountable())
{
    name = "";
    price = 0;
    pertPercentage = 0;
    compositions = CompositionCollection();
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
    return compositions;
}

Quantity &Alloymaker::getQuantity()
{
    return quantity;
}

void Alloymaker::setQuantity(Quantity &value)
{
    quantity = value;
}

double Alloymaker::getPertPercentage()
{
    return pertPercentage;
}

void Alloymaker::setPertPercentage(double value)
{
    pertPercentage = value;
}

int Alloymaker::getPrice()
{
    return price;
}

void Alloymaker::setPrice(int value)
{
    price = value;
}
