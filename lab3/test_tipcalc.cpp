#include <igloo/igloo.h>
#include <math_utils.h>

using namespace igloo;
using namespace math;

Context(TestTipCalc){
    Spec(Check100_20_2Is60){
        Assert::That(calculate_tip(100, 20, 2), EqualsWithDelta(60, 0.01));
    }

    Spec(Check100_18_7Is16_86){
        Assert::That(calculate_tip(100, 18, 7), EqualsWithDelta(16.86, 0.01));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}