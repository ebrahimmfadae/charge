#ifndef COMPOSITION_H_
#define COMPOSITION_H_

#include <string>

using namespace std;

class Composition {
public:
    Composition();

    Composition(string, double);

    double getPercentage();

    void setPercentage(double);

    string getSymbol();

    void setSymbol(string);

    string toString();

private:
    string symbol;
    double percentage;
};

#endif /* COMPOSITION_H_ */
