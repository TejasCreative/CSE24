#include <igloo/igloo.h>
#include <vector>
#include <listproc.h>

using namespace igloo;

Context(DoubleOrNothingFunction){
    Spec(Alternate){
        std::vector<int> nums = {1,2,3,4,5,6};
        doubleOrNothing(nums);

        std::vector<int> result = {0,4,0,8,0,12};
        Assert::That(nums, Equals(result));
    }

    Spec(EvenOnly){
        std::vector<int> nums = {2,4,6,8};
        doubleOrNothing(nums);

        std::vector<int> result = {4,8,12,16};
        Assert::That(nums, Equals(result));
    }

    Spec(OddOnly){
        std::vector<int> nums = {1,3,5,7,9};
        doubleOrNothing(nums);

        std::vector<int> result = {0,0,0,0,0};
        Assert::That(nums, Equals(result));
    }

    Spec(Empty){
        std::vector<int> nums = {};
        doubleOrNothing(nums);

        std::vector<int> result = {};
        Assert::That(nums, Equals(result));
    }

    Spec(Zeros){
        std::vector<int> nums = {0,0,0,0,0};
        doubleOrNothing(nums);

        std::vector<int> result = {0,0,0,0,0};
        Assert::That(nums, Equals(result));
    }

    Spec(Negatives){
        std::vector<int> nums = {-1, -2, -3, -4, -5};
        doubleOrNothing(nums);

        std::vector<int> result = {0, -4, 0, -8, 0};
        Assert::That(nums, Equals(result));
    }
};


int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}
