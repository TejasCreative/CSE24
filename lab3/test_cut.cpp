#include <igloo/igloo.h>
#include <string_utils.h>

using namespace igloo;
using namespace strings;

Context(TestCut){
    Spec(CheckNetflix_Flixnet){
        Assert::That(cut("netflix"), Equals("flixnet"));
    }

    Spec(CheckGoogleGlegoo){
        Assert::That(cut("google"), Equals("glegoo"));
    }

    Spec(CheckSteveEvest){
        Assert::That(cut("steve"), Equals("evest"));
    }

    Spec(CheckOneLetter){
        Assert::That(cut("x"), Equals("x"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}