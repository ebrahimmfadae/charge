#ifndef COMPOSITION_H_
#define COMPOSITION_H_

#include <string>
#include <vector>
#include "Chemical.h"

using namespace std;

class Chemical;
class Composition;

class Composition
{

public:
    Composition();
    Composition(string);
    Chemical &get(size_t);
    Chemical &get(string);
    string getBaseElement();
    void setBaseElement(string);
    size_t size();

private:
    string baseElement;
    vector<Chemical> *array;
};

#endif /* COMPOSITION_H_ */
