#include <igloo/igloo.h>
#include <list_utils.h>

using namespace igloo;


Context(TestAverage){
    Spec(Test1){
        float list[5] = {1,2,3,4,5};
        int len = 5;
        float ans = 3;
        Assert::That(ucm::average(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test2){
        float list[5] = {0,0,0,0,0};
        int len = 5;
        float ans = 0;
        Assert::That(ucm::average(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test3){
        float list[1] = {3};
        int len = 1;
        float ans = 3;
        Assert::That(ucm::average(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test4){
        float list[5] = {534, 876, 235, 248, 871};
        int len = 5;
        float ans = 552.8;
        Assert::That(ucm::average(list, len), EqualsWithDelta(ans, 0.01));
    }
    Spec(Test5){
        float list[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
        int len = 5;
        float ans = 3.4;
        Assert::That(ucm::average(list, len), EqualsWithDelta(ans, 0.01));
    }
};

int main(int argc, const char** argv){
    TestRunner::RunAllTests(argc, argv);
}