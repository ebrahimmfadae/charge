#ifndef COMPOSITIONCOLLECTION_H_
#define COMPOSITIONCOLLECTION_H_

#include <string>
#include "Composition.h"

using namespace std;

class CompositionCollection {
public:
    CompositionCollection();

    Composition &get(int);

    void set(int, Composition);

    Composition getBase();

    void setBase(int);

private:
    string baseElement;
    Composition array[2];

};

#endif /* COMPOSITIONCOLLECTION_H_ */
