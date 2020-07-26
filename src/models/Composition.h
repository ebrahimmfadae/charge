#ifndef COMPOSITION_H_
#define COMPOSITION_H_

#include <string>
#include "CompositionCollection.h"

using namespace std;

class Composition;
class CompositionCollection;

class Composition
{
public:
    Composition(CompositionCollection &);
    Composition(string, double, CompositionCollection &);
    double getPercentage();
    void setPercentage(double);
    string getSymbol();
    void setSymbol(string);
    string toString();

private:
    CompositionCollection *compositions;
    string symbol;
    double percentage;
};

#endif /* COMPOSITION_H_ */
