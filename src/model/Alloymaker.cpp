#include "Alloymaker.h"
#include "Uncountable.h"
#include "CompositionCollection.h"

using namespace std;

Alloymaker::Alloymaker() {
    Alloymaker::name = "";
    Alloymaker::price = 0;
    Alloymaker::pertPercentage = 0;
    Alloymaker::quantity = new Uncountable();
    Alloymaker::compositions = CompositionCollection();
}

string Alloymaker::getName() {
    return Alloymaker::name;
}

void Alloymaker::setName(string value) {
    Alloymaker::name = value;
}

CompositionCollection &Alloymaker::getCompositions() {
    return Alloymaker::compositions;
}

Quantity &Alloymaker::getQuantity() {
    return *Alloymaker::quantity;
}

void Alloymaker::setQuantity(Quantity &value) {
    Alloymaker::quantity = &value;
}

double Alloymaker::getPertPercentage() {
    return Alloymaker::pertPercentage;
}

void Alloymaker::setPertPercentage(double value) {
    Alloymaker::pertPercentage = value;
}

int Alloymaker::getPrice() {
    return Alloymaker::price;
}

void Alloymaker::setPrice(int value) {
    Alloymaker::price = value;
}
