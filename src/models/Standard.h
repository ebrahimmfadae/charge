#ifndef STANDARD_H_
#define STANDARD_H_

#include <string>

using namespace std;

class Standard
{

public:
    Standard();
    double getMin();
    void setMin(double);
    double getMax();
    void setMax(double);
    string *getSymbols();
    void setSymbols(string[]);

private:
    string symbols[];
    double min;
    double max;
};

#endif /* STANDARD_H_ */
