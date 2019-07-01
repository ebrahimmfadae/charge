#include "ModelBuilder.h"

ModelBuilder::ModelBuilder() {
    ModelBuilder::alloymakers = new Alloymaker[0];
}

double *ModelBuilder::compositionVarAmount(Standard *std) {
    return 0;
}

double *ModelBuilder::composition(Standard *std) {
    return 0;
}

double *ModelBuilder::amount() {
    return 0;
}

double *ModelBuilder::capacity() {
    return 0;
}

Alloymaker *ModelBuilder::getAlloymakers() {
    return ModelBuilder::alloymakers;
}

void ModelBuilder::setAlloymakers(Alloymaker *value) {
    ModelBuilder::alloymakers = value;
}
