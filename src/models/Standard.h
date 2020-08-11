#ifndef STANDARD_H_
#define STANDARD_H_

#include <string>
#include <vector>

using namespace std;

class Standard
{

public:
    Standard();
    double getMin();
    void setMin(double);
    double getMax();
    void setMax(double);
    vector<string> &getSymbols();
    void setSymbols(vector<string>);

private:
    vector<string> symbols;
    double min;
    double max;
};

#endif /* STANDARD_H_ */
