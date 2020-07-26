#ifndef COEFFICIENT_H_
#define COEFFICIENT_H_

#include "models/Alloymaker.h"
#include "models/Standard.h"

class CoefficientCalculator
{

public:
    CoefficientCalculator(Alloymaker &);
    void setAlloymaker(Alloymaker &);
    Alloymaker &getAlloymaker();
    double composition();
    double compositionVarAmount(double);
    double amount();
    double capacity();

private:
    Alloymaker *alloymaker;
};

#endif /* COEFFICIENT_H_ */
