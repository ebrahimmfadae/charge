#define BOOST_TEST_MODULE Simple
#include <boost/test/included/unit_test.hpp>
#include "../core/models/Alloymaker.h"
#include "../core/models/Standard.h"
#include "../core/optimization/Variable.h"
#include "../core/optimization/Solution.h"

using namespace std;

BOOST_AUTO_TEST_CASE(solve_test)
{
    Alloymaker a1;
    a1.setPrice(15633);
    a1.setLossPercentage(5);
    a1.getCompositions().get("C").setPercentage(0.2);
    a1.getCompositions().get("Si").setPercentage(0.6);
    Alloymaker a2;
    a2.setPrice(23134);
    a2.setLossPercentage(12);
    a2.getCompositions().get("C").setPercentage(90);
    Alloymaker a3;
    a3.setPrice(5665);
    a3.setLossPercentage(2);
    a3.getCompositions().get("Si").setPercentage(1.6);
    auto std1 = Standard();
    std1.setSymbols(vector<string>{"C"});
    std1.setMax(0.6);
    std1.setMin(0.4);
    auto std2 = Standard();
    std2.setSymbols(vector<string>{"Si"});
    std2.setMax(1.2);
    std2.setMin(1);
    auto v1 = Variable(a1);
    auto v2 = Variable(a2);
    auto v3 = Variable(a3);
    auto s = Solution(5000);
    auto vs = vector<Variable>{v1, v2, v3};
    auto stds = vector<Standard>{std1};
    s.setStandards(stds);
    s.autoSolve(vs, 500);
    ostringstream st;
    st << vs.at(0).getAnswer();
    BOOST_CHECK_EQUAL(st.str(), "0");
    st.str("");
    st << vs.at(1).getAnswer();
    BOOST_CHECK_EQUAL(st.str(), "2.52525");
    st.str("");
    st << vs.at(2).getAnswer();
    BOOST_CHECK_EQUAL(st.str(), "507.937");
}