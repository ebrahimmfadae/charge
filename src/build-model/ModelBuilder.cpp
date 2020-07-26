#include "ModelBuilder.h"

ModelBuilder::ModelBuilder()
{
    alloymakers = new vector<Alloymaker>();
}

double ModelBuilder::compositionVarAmount(Standard &std)
{
    return 0;
}

double ModelBuilder::composition(Standard &std)
{
    return 0;
}

double ModelBuilder::amount()
{
    return 0;
}

double ModelBuilder::capacity()
{
    return 0;
}

vector<Alloymaker> &ModelBuilder::getAlloymakers()
{
    return *alloymakers;
}

void ModelBuilder::setAlloymakers(vector<Alloymaker> &value)
{
    ModelBuilder::alloymakers = &value;
}
