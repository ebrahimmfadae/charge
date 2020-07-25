#ifndef ROWBUILDER_H_
#define ROWBUILDER_H_

#include "models/Alloymaker.h"
#include "models/Standard.h"
#include "vector"

class ModelBuilder
{

public:
    ModelBuilder();
    double composition(Standard &);
    double compositionVarAmount(Standard &);
    double amount();
    double capacity();
    vector<Alloymaker> &getAlloymakers();
    void setAlloymakers(vector<Alloymaker> &);

private:
    vector<Alloymaker> &alloymakers;
};

#endif /* ROWBUILDER_H_ */
