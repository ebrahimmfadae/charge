#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>
#include "optimizer/Variable.h"
#include "models/Standard.h"

class Solution
{

public:
    Solution();
    Solution(double);
    void setCapacity(double);
    double getCapacity();
    vector<Standard> &getStandards();
    void setStandards(vector<Standard> &);
    void autoSolve(vector<Variable> &, double);

private:
    double capacity;
    vector<Standard> standards;
};

#endif /* SOLUTION_H_ */