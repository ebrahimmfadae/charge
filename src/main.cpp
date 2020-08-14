#include <stdio.h>
#include <iostream>
#include <string>
#include "models/Alloymaker.h"
#include "optimizer/Variable.h"

using namespace std;

int main()
{
    Alloymaker alloymaker;
    alloymaker.getCompositions().get(1).setPercentage(0.6);
    alloymaker.getCompositions().get(2).setPercentage(0.6);
    cout << alloymaker.getCompositions().get(0).toString() << endl
         << alloymaker.getCompositions().get(1).toString() << endl
         << alloymaker.getCompositions().get(2).toString() << endl;
    cout << "--------------" << endl;
    auto std = Standard();
    std.setSymbols(vector<string>{"Fe", "C"});
    auto variable = new Variable(alloymaker);
    cout << "Sum of compositions is -> " << variable->composition(std) << endl;
    // cout << "--------------" << endl;
    return 0;
}