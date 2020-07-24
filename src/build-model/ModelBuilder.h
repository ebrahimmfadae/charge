#ifndef ROWBUILDER_H_
#define ROWBUILDER_H_

#include "model/Alloymaker.h"
#include "model/Standard.h"

class ModelBuilder
{

public:
    ModelBuilder();
    double *composition(Standard *std);
    double *compositionVarAmount(Standard *std);
    double *amount();
    double *capacity();
    Alloymaker *getAlloymakers();
    void setAlloymakers(Alloymaker *);

private:
    Alloymaker *alloymakers;
};

#endif /* ROWBUILDER_H_ */
