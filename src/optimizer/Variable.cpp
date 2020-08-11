#include "Variable.h"

Variable::Variable(Alloymaker &alloymaker)
{
    setAlloymaker(alloymaker);
}

void Variable::setAlloymaker(Alloymaker &value)
{
    alloymaker = &value;
}

Alloymaker &Variable::getAlloymaker()
{
    return *alloymaker;
}

double Variable::composition(Standard &std)
{
    vector<string> &symbols = std.getSymbols();
    size_t length = symbols.size();
    double sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        string element = symbols[i];
        auto &cmp = getAlloymaker().getCompositions().get(element);
        sum += cmp.getPercentage();
    }

    return sum;
}

double Variable::goal()
{
    return alloymaker->getPrice();
}

double Variable::amount()
{
    return alloymaker->getQuantity().getWeight() * (1 - alloymaker->getPertPercentage() / 100);
}

double Variable::capacity()
{
    return alloymaker->getQuantity().getWeight();
}
