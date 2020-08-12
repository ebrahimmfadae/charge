#include <sstream>
#include "Composition.h"

Composition::Composition() : Composition("Fe")
{
}

Composition::Composition(string baseElement) : baseElement(baseElement)
{
    array = new vector<Chemical>{
        Chemical("Fe", 100, *this),
        Chemical("C", 0, *this),
        Chemical("Si", 0, *this)};
}

Chemical &Composition::get(size_t index)
{
    return array->at(index);
}

Chemical &Composition::get(string s)
{
    auto size = array->size();

    for (size_t i = 0; i < size; i++)
    {
        auto &cmp = array->at(i);
        if (cmp.getSymbol() == s)
        {
            return cmp;
        }
    }

    ostringstream stream;
    stream << "item with (\"" << s << "\") symbol not found";
    throw invalid_argument(stream.str());
}

string Composition::getBaseElement()
{
    return baseElement;
}

void Composition::setBaseElement(string symbol)
{
    baseElement = symbol;
}

size_t Composition::size()
{
    return array->size();
}
