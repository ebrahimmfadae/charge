#ifndef COUNTABLE_H_
#define COUNTABLE_H_

#include "Quantity.h"

class Countable : public Quantity
{

public:
    Countable();
    int getCount();
    void setCount(int);
    double getUnitWeight();
    void setUnitWeight(double);
    double getWeight();

private:
    int count;
    double unitWeight;
};

#endif /* COUNTABLE_H_ */
