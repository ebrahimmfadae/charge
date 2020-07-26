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
