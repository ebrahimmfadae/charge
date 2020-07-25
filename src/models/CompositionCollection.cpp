#include "CompositionCollection.h"

CompositionCollection::CompositionCollection()
{
    baseElement = "Fe";
    get(0).setSymbol("C");
    get(1).setSymbol("Si");
}

Composition CompositionCollection::getBase()
{
    double percentage = 0;
    int length = 2;

    for (int i = 0; i < length; i++)
    {
        percentage += get(i).getPercentage();
    }

    return Composition(baseElement, 100 - percentage);
}

Composition &CompositionCollection::get(int index)
{
    return array[index];
}

void CompositionCollection::set(int index, Composition cmp)
{
    *(array + index) = cmp;
}

void CompositionCollection::setBase(int index)
{
    Composition cmp = get(index);
    set(index, getBase());
    baseElement = cmp.getSymbol();
}
