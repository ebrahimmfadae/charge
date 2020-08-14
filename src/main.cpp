#include <stdio.h>
#include <iostream>
#include <string>
#include "models/Alloymaker.h"
#include "models/Standard.h"
#include "optimizer/Variable.h"
#include "optimizer/Solution.h"

using namespace std;

int main()
{
    Alloymaker a1;
    a1.setPrice(15633);
    a1.setPertPercentage(5);
    a1.getCompositions().get("C").setPercentage(0.2);
    a1.getCompositions().get("Si").setPercentage(0.6);
    Alloymaker a2;
    a2.setPrice(23134);
    a2.setPertPercentage(12);
    a2.getCompositions().get("C").setPercentage(90);
    Alloymaker a3;
    a3.setPrice(5665);
    a3.setPertPercentage(2);
    a3.getCompositions().get("Si").setPercentage(1.6);
    auto std1 = Standard();
    std1.setSymbols(vector<string>{"C"});
    std1.setMax(0.6);
    std1.setMin(0.4);
    auto std2 = Standard();
    std2.setSymbols(vector<string>{"Si"});
    std2.setMax(1.2);
    std2.setMin(1);
    auto v1 = new Variable(a1);
    auto v2 = new Variable(a2);
    auto v3 = new Variable(a3);
    auto s = new Solution(5000);
    auto vs = new vector<Variable>{*v1,*v2,*v3};
    auto stds = vector<Standard>{std1};
    s->setStandards(stds);
    s->autoSolve(*vs, 500);
    return 0;
}