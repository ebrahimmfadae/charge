#include "Variable.h"

using namespace std;

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

    return sum * amount();
}

double Variable::goal()
{
    return alloymaker->getPrice();
}

double Variable::amount()
{
    return 1 - alloymaker->getLossPercentage() / 100;
}

double Variable::capacity()
{
    return 1;
}

bool Variable::isInteger()
{
    return alloymaker->getIsQuantified();
}

void Variable::setAnswer(double value)
{
    answer = value;
}

double Variable::getAnswer()
{
    return answer;
}
