#include <igloo/igloo.h>
#include <math_utils.h>

using namespace igloo;
using namespace math;

Context(TestCircArea){
    Spec(CheckRad2AreaIs12_57){
        Assert::That(circle_area(2), EqualsWithDelta(12.57, 0.01));
    }

    Spec(CheckRad7AreaIs153_94){
        Assert::That(circle_area(7), EqualsWithDelta(153.94, 0.01));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}