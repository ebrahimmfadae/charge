#include "CompositionCollection.h"

CompositionCollection::CompositionCollection() : CompositionCollection("Fe")
{
}

CompositionCollection::CompositionCollection(string baseElement) : baseElement(baseElement)
{
    array = new vector<Composition>{
        Composition("Fe", 100, *this),
        Composition("C", 0, *this),
        Composition("Si", 0, *this)};
}

Composition &CompositionCollection::get(int index)
{
    return array->at(index);
}

Composition &CompositionCollection::get(string s)
{
    for (size_t i = 0; i < array->size(); i++)
    {
        auto &cmp = array->at(i);
        if (cmp.getSymbol() == s)
            return array->at(i);
    }
    throw exception();
}

string CompositionCollection::getBaseElement()
{
    return baseElement;
}

void CompositionCollection::setBaseElement(string symbol)
{
    baseElement = symbol;
}

int CompositionCollection::size()
{
    return array->size();
}
