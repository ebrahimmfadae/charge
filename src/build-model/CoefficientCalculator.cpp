#include "CoefficientCalculator.h"

CoefficientCalculator::CoefficientCalculator(Alloymaker &alloymaker)
{
    setAlloymaker(alloymaker);
}

void CoefficientCalculator::setAlloymaker(Alloymaker &value)
{
    CoefficientCalculator::alloymaker = &value;
}

Alloymaker &CoefficientCalculator::getAlloymaker()
{
    return *alloymaker;
}

double CoefficientCalculator::composition()
{
    return 0;
}

double CoefficientCalculator::compositionVarAmount(double limit)
{
    return 0;
}

double CoefficientCalculator::amount()
{
    return 0;
}

double CoefficientCalculator::capacity()
{
    return 0;
}
