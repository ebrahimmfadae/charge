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
    size_t getCount();
    void setCount(size_t);
    void setIsQuantified(bool);
    bool getIsQuantified();
    double getPertPercentage();
    void setPertPercentage(double);
    size_t getPrice();
    void setPrice(size_t);
    string getName();
    void setName(string);

private:
    Composition *compositions;
    string name;
    double pertPercentage;
    double unitWeight;
    double weight;
    size_t count;
    bool isQuantified;
    size_t price;
};

#endif /* ALLOYMAKER_H_ */
