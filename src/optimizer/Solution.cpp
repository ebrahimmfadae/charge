#ifndef ERROR()
#define ERROR()                     \
    {                               \
        fprintf(stderr, "Error\n"); \
        return;                     \
    }
#endif

#include "Solution.h"
#include "lpsolve/lp_lib.h"

Solution::Solution() : Solution(0) {}

Solution::Solution(double capacity)
{
    this->capacity = capacity;
    standards = vector<Standard>();
}

void Solution::setCapacity(double value)
{
    capacity = value;
}

double Solution::getCapacity()
{
    return capacity;
}

vector<Standard> &Solution::getStandards()
{
    return standards;
}

void Solution::setStandards(vector<Standard> &value)
{
    standards = value;
}

void Solution::autoSolve(vector<Variable> &variables, double amount)
{

    lprec *lp;
    size_t rows = 0;
    const size_t columns = variables.size();

    if ((lp = make_lp(rows, columns)) == NULL)
    {
        ERROR();
    }

    set_maxim(lp);
    {
        double row[columns];
        for (size_t i = 0; i < columns; i++)
        {
            row[i] = variables[i].goal();
        }
        if (!set_obj_fn(lp, row))
        {
            ERROR();
        }
    }

    {
        double row[columns];
        for (size_t i = 0; i < columns; i++)
        {
            row[i] = variables[i].amount();
        }
        if (!add_constraint(lp, row, EQ, amount))
        {
            ERROR();
        }
        else
        {
            rows++;
        }
    }

    {
        double row[columns];
        for (size_t i = 0; i < columns; i++)
        {
            row[i] = variables[i].capacity();
        }
        if (!add_constraint(lp, row, LE, capacity))
        {
            ERROR();
        }
        else
        {
            rows++;
        }
    }

    for (size_t i = 0; i < standards.size(); i++)
    {
        double row[columns];
        for (size_t i = 0; i < columns; i++)
        {
            row[i] = variables[i].composition(standards[i]);
        }
        const double max = standards[i].getMax();
        const double rh = standards[i].getMin() - max;
        if (!add_constraint(lp, row, LE, standards[i].getMax()))
        {
            ERROR();
        }
        if (!set_rh(lp, rows, rh))
        {
            ERROR();
        }
    }

    for (size_t i = 0; i < columns; i++)
    {
        if (variables[i].isInteger() && !set_int(lp, i, TRUE))
        {
            ERROR();
        }
    }

    for (size_t i = 0; i < columns; i++)
    {
        // set_lowbo(lp, 2, 2);
        // set_upbo(lp, 4, 5.3);
    }

    solve(lp);

    print_objective(lp);
    print_solution(lp, 1);
    print_constraints(lp, 1);
    write_lp(lp, "solution.lp");

    delete_lp(lp);
}