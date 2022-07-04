#include <igloo/igloo.h>
#include <utils.h>

using namespace igloo;

Context(TestAdd){
    Spec(Check0plus0is0){
        Assert::That(add(0, 0), Equals(0));
    }

    Spec(CheckNeg7plus5isNeg2){
        Assert::That(add(-7, 5), Equals(-2));
    }

    Spec(Check100plus7is107){
        Assert::That(add(100, 7), Equals(107));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}

