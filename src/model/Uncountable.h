#ifndef UNCOUNTABLE_H_
#define UNCOUNTABLE_H_

#include "Quantity.h"

class Uncountable : public Quantity
{

public:
    Uncountable();
    void setWeight(double);
    double getWeight();

private:
    double weight;
};

#endif /* UNCOUNTABLE_H_ */
