#ifndef ALLOYMAKER_H_
#define ALLOYMAKER_H_

#include <string>
#include "Composition.h"

using namespace std;

class Alloymaker
{

public:
    Alloymaker();
    Composition &getCompositions();
    double getUnitWeight();
    void setUnitWeight(double);
    double getWeight();
    void setWeight(double);
    unsigned int getCount();
    void setCount(unsigned int);
    double getPertPercentage();
    void setPertPercentage(double);
    unsigned int getPrice();
    void setPrice(unsigned int);
    string getName();
    void setName(string);

private:
    Composition *compositions;
    string name;
    double pertPercentage;
    double unitWeight;
    double weight;
    unsigned int count; // Count 0 means the quantity is continous
    unsigned int price;
};

#endif /* ALLOYMAKER_H_ */
