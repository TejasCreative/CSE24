#include <igloo/igloo.h>
#include <string_utils.h>
#include <math_utils.h>

using namespace igloo;
using namespace strings;
using namespace math;

Context(TestTipCalc){
    Spec(Check100_20_2Is60){
        Assert::That(calculate_tip(100, 20, 2), EqualsWithDelta(60, 0.01));
    }

    Spec(Check100_18_7Is16_86){
        Assert::That(calculate_tip(100, 18, 7), EqualsWithDelta(16.86, 0.01));
    }
};

Context(TestCircArea){
    Spec(CheckRad2AreaIs12_57){
        Assert::That(circle_area(2), EqualsWithDelta(12.57, 0.01));
    }

    Spec(CheckRad7AreaIs153_94){
        Assert::That(circle_area(7), EqualsWithDelta(153.94, 0.01));
    }
};

Context(TestDiv){
    Spec(Check1rem7){
        Assert::That(format_int_division(1, 7), Equals("1 rem 7"));
    }

    Spec(Check5rem3){
        Assert::That(format_int_division(5, 3), Equals("5 rem 3"));
    }
};

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