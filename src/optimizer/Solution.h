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
    std::vector<Standard> &getStandards();
    void setStandards(std::vector<Standard> &);
    void autoSolve(std::vector<Variable> &, double);

private:
    double capacity;
    std::vector<Standard> standards;
};

#endif /* SOLUTION_H_ */