#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "models/Alloymaker.h"
#include "models/Standard.h"

class Variable
{

public:
    Variable(Alloymaker &);
    void setAlloymaker(Alloymaker &);
    Alloymaker &getAlloymaker();
    double composition(Standard &std);
    double goal();
    double amount();
    double capacity();
    double lowerBound();
    double upperBound();
    bool isInteger();
    void setAnswer(double value);
    double getAnswer();

private:
    Alloymaker *alloymaker;
    double answer;
};

#endif /* VARIABLE_H_ */
