#ifndef COMPOSITION_H_
#define COMPOSITION_H_

#include <string>
#include <vector>
#include "Chemical.h"

class Chemical;
class Composition;

class Composition
{

public:
    Composition();
    Composition(std::string);
    Chemical &get(size_t);
    Chemical &get(std::string);
    std::string getBaseElement();
    void setBaseElement(std::string);
    size_t size();

private:
    std::string baseElement;
    std::vector<Chemical> *array;
};

#endif /* COMPOSITION_H_ */
