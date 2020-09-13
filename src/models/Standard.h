#ifndef STANDARD_H_
#define STANDARD_H_

#include <string>
#include <vector>

class Standard
{

public:
    Standard();
    double getMin();
    void setMin(double);
    double getMax();
    void setMax(double);
    std::vector<std::string> &getSymbols();
    void setSymbols(std::vector<std::string>);

private:
    std::vector<std::string> symbols;
    double min;
    double max;
};

#endif /* STANDARD_H_ */
