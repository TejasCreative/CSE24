#include <igloo/igloo.h>
#include <str_utils.h>

using namespace igloo;

Context(TestReplace){
    Spec(TestWorldEarth){
        Assert::That(replace_pattern("hello world", "world", "earth"), Equals("hello earth"));
    }

    Spec(TestStationedStoned){
        Assert::That(replace_pattern("stationed", "ati", ""), Equals("stoned"));
    }

    Spec(TestNumberOneBest){
        Assert::That(replace_pattern("C++ is the number one language", "number one", "best"), Equals("C++ is the best language"));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}