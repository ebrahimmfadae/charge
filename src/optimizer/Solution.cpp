#ifndef ERROR
#define ERROR()                     \
    {                               \
        fprintf(stderr, "Error\n"); \
        return;                     \
    }
#endif

#include <iostream>
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

    {
        double row[columns + 1];
        for (size_t i = 0; i < columns; i++)
        {
            row[i + 1] = variables[i].goal();
        }
        if (!set_obj_fn(lp, row))
        {
            ERROR();
        }
    }

    {
        double row[columns + 1];
        for (size_t i = 0; i < columns; i++)
        {
            row[i + 1] = variables[i].amount();
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
        double row[columns + 1];
        for (size_t i = 0; i < columns; i++)
        {
            row[i + 1] = variables[i].capacity();
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
        auto &std = standards[i];
        double row[columns + 1];
        for (size_t j = 0; j < columns; j++)
        {
            row[j + 1] = variables[j].composition(std) / amount;
        }
        const double rh = std.getMin() - std.getMax();
        if (!add_constraint(lp, row, LE, std.getMax()))
        {
            ERROR();
        } 
        else
        {
            rows++;
        }
        if (!set_rh_range(lp, rows, rh))
        {
            ERROR();
        }
    }

    for (size_t i = 0; i < columns; i++)
    {
        if (variables[i].isInteger() && !set_int(lp, i + 1, TRUE))
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
    // write_lp(lp, "solution.lp");

    delete_lp(lp);
}