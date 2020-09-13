#ifndef CHEMICAL_H_
#define CHEMICAL_H_

#include <string>
#include "Composition.h"

class Chemical;
class Composition;

class Chemical
{

public:
    Chemical(Composition &);
    Chemical(std::string, double, Composition &);
    double getPercentage();
    void setPercentage(double);
    std::string getSymbol();
    void setSymbol(std::string);
    std::string toString();

private:
    Composition *compositions;
    std::string symbol;
    double percentage;
};

#endif /* CHEMICAL_H_ */
