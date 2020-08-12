#ifndef CHEMICAL_H_
#define CHEMICAL_H_

#include <string>
#include "Composition.h"

using namespace std;

class Chemical;
class Composition;

class Chemical
{

public:
    Chemical(Composition &);
    Chemical(string, double, Composition &);
    double getPercentage();
    void setPercentage(double);
    string getSymbol();
    void setSymbol(string);
    string toString();

private:
    Composition *compositions;
    string symbol;
    double percentage;
};

#endif /* CHEMICAL_H_ */
