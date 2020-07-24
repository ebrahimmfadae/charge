#include <iostream>
#include <string>
#include "models/Alloymaker.h"

using namespace std;

int main() {
    Alloymaker alloymaker;
    alloymaker.getCompositions().get(0).setPercentage(1.2);
    alloymaker.getCompositions().get(1).setPercentage(0.6);
    cout << alloymaker.getCompositions().getBase().toString()
         << alloymaker.getCompositions().get(0).toString()
         << alloymaker.getCompositions().get(1).toString() << endl;
    alloymaker.getCompositions().setBase(0);
    cout << alloymaker.getCompositions().getBase().toString() << endl;
    return 0;
}