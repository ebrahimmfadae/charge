#ifndef ALLOYMAKER_H_
#define ALLOYMAKER_H_

#include <string>
#include "CompositionCollection.h"
#include "Quantity.h"

using namespace std;

class Alloymaker
{

public:
    Alloymaker();
    CompositionCollection &getCompositions();
    Quantity &getQuantity();
    void setQuantity(Quantity &);
    double getPertPercentage();
    void setPertPercentage(double);
    int getPrice();
    void setPrice(int);
    string getName();
    void setName(string);

private:
    CompositionCollection *compositions;
    string name;
    double pertPercentage;
    int price;
    Quantity *quantity;
};

#endif /* ALLOYMAKER_H_ */
