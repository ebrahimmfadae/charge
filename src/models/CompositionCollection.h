#ifndef COMPOSITIONCOLLECTION_H_
#define COMPOSITIONCOLLECTION_H_

#include <string>
#include <vector>
#include "Composition.h"

using namespace std;

class Composition;
class CompositionCollection;

class CompositionCollection
{
public:
    CompositionCollection();
    CompositionCollection(string);
    Composition &get(int);
    string getBaseElement();
    void setBaseElement(string);
    int size();

private:
    string baseElement;
    vector<Composition> *array;
};

#endif /* COMPOSITIONCOLLECTION_H_ */
