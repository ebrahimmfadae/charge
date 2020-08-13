#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>
#include "optimizer/Variable.h"
#include "models/Standard.h"

class Solution
{

public:
    void solve(vector<Variable &>, vector<Standard &>);

private:
};

#endif /* SOLUTION_H_ */