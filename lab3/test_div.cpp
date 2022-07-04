#include <igloo/igloo.h>
#include <string_utils.h>

using namespace igloo;
using namespace strings;

Context(TestDiv){
    Spec(Check1rem7){
        Assert::That(format_int_division(1, 7), Equals("1 rem 7"));
    }

    Spec(Check5rem3){
        Assert::That(format_int_division(5, 3), Equals("5 rem 3"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}