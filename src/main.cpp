#include <iostream>
#include <string>
#include "models/Alloymaker.h"

using namespace std;

int main()
{
    Alloymaker alloymaker;
    alloymaker.getCompositions().get(1).setPercentage(0.6);
    alloymaker.getCompositions().get(2).setPercentage(0.6);
    cout << alloymaker.getCompositions().get(0).toString()
         << alloymaker.getCompositions().get(1).toString()
         << alloymaker.getCompositions().get(2).toString() << endl;
    return 0;
}