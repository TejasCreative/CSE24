#include <igloo/igloo.h>
#include <square.h>

using namespace igloo;

Context(TestSquares){
    Spec(Default){
        Square s;
        Assert::That(s.row, Equals(0));
        Assert::That(s.col, Equals(0));
        Assert::That(s.token, Equals(0));
    }

    Spec(Custom){
        Square s(1,2,1);
        Assert::That(s.row, Equals(1));
        Assert::That(s.col, Equals(2));
        Assert::That(s.token, Equals(1));
    }

    Spec(Another){
        Square s(0,1,2);
        Assert::That(s.row, Equals(0));
        Assert::That(s.col, Equals(1));
        Assert::That(s.token, Equals(2));
    }
};

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}