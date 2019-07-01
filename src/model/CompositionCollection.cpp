#include "CompositionCollection.h"

CompositionCollection::CompositionCollection() {
    CompositionCollection::baseElement = "Fe";
    CompositionCollection::get(0).setSymbol("C");
    CompositionCollection::get(1).setSymbol("Si");
}

Composition CompositionCollection::getBase() {
    double percentage = 0;
    int length = 2;

    for (int i = 0; i < length; i++) {
        percentage += CompositionCollection::get(i).getPercentage();
    }

    return Composition(CompositionCollection::baseElement, 100 - percentage);
}

Composition &CompositionCollection::get(int index) {
    return CompositionCollection::array[index];
}

void CompositionCollection::set(int index, Composition cmp) {
    *(CompositionCollection::array + index) = cmp;
}

void CompositionCollection::setBase(int index) {
    Composition cmp = CompositionCollection::get(index);
    CompositionCollection::set(index, CompositionCollection::getBase());
    CompositionCollection::baseElement = cmp.getSymbol();
}

