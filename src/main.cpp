#include <stdio.h>
#include <iostream>
#include <string>
#include "models/Alloymaker.h"
#include "optimizer/Variable.h"
#include "lpsolve/lp_lib.h"

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
    cout << "--------------" << endl;
    lprec *lp;
    int majorversion, minorversion, release, build;
    char buf[1024];
    if ((lp = make_lp(0, 4)) == NULL)
        throw "make lp error";
    lp_solve_version(&majorversion, &minorversion, &release, &build);
    sprintf(buf, "lp_solve %d.%d.%d.%d demo\n\n", majorversion, minorversion, release, build);
    print_str(lp, buf);
    return 0;
}