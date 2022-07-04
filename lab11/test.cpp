#include <igloo/igloo.h>
#include <Date.h>

using namespace igloo;

Context(AgeTesting){
    Spec(AfterBirthday){
        Date today(2022, 11, 11);
        Date birthday(2000, 9, 9);
        int age = today - birthday;
        
        Assert::That(age, Equals(22));
    }

    Spec(BeforeBirthday){
        Date today(2022, 5, 5);
        Date birthday(2000, 9, 9);
        int age = today - birthday;
        
        Assert::That(age, Equals(21));
    }

    Spec(SameMonthAfterBirthday){
        Date today(2022, 9, 15);
        Date birthday(2000, 9, 9);
        int age = today - birthday;
        
        Assert::That(age, Equals(22));
    }

    Spec(SameMonthBeforeBirthday){
        Date today(2022, 9, 5);
        Date birthday(2000, 9, 9);
        int age = today - birthday;
        
        Assert::That(age, Equals(21));
    }

    Spec(HappyBirthday){
        Date today(2022, 9, 9);
        Date birthday(2000, 9, 9);
        int age = today - birthday;
        
        Assert::That(age, Equals(22));
    }
};

int main(){
    return TestRunner::RunAllTests();
}