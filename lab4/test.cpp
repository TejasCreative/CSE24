#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <list_utils.h>

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}


Context(TestingMain){

    static void SetUpContext(){
        system("rm -f temp");
        std::string compile = exec("g++ -I. -o temp main.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }

    }
    static void TearDownContext(){
        system("rm -f temp");
    }

    Spec(TestNoArgs){
        std::string result = exec("./temp");
        Assert::That(result, Equals("Usage: ./calc [operation] [list of numbers...]\nOperations:\n  -add\t\tAdd up the input list\n  -avg\t\tCompute the average of the input list\n  -min\t\tFind the maximum of the input list\n  -min\t\tFind the minimum of the input list"));
    }

    Spec(TestInvalidOption){
        std::string result = exec("./temp -try 1 2 3 4 5");
        Assert::That(result, Equals("Invalid operation: -try"));
    }
    
};

Context(TestAddUp){
    Spec(Test1){
        float list[5] = {1,2,3,4,5};
        int len = 5;
        float ans = 15;
        Assert::That(ucm::addUp(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test2){
        float list[5] = {0,0,0,0,0};
        int len = 5;
        float ans = 0;
        Assert::That(ucm::addUp(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test3){
        float list[1] = {3};
        int len = 1;
        float ans = 3;
        Assert::That(ucm::addUp(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test4){
        float list[5] = {534, 876, 235, 248, 871};
        int len = 5;
        float ans = 2764;
        Assert::That(ucm::addUp(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test5){
        float list[2] = {1.1, 2.2};
        int len = 2;
        float ans = 3.3;
        Assert::That(ucm::addUp(list, len), EqualsWithDelta(ans, 0.01));
    }
};

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

Context(TestMax){
    Spec(Test1){
        float list[5] = {1,2,3,4,5};
        int len = 5;
        float ans = 5;
        Assert::That(ucm::max(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test2){
        float list[5] = {0,0,0,0,0};
        int len = 5;
        float ans = 0;
        Assert::That(ucm::max(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test3){
        float list[1] = {3};
        int len = 1;
        float ans = 3;
        Assert::That(ucm::max(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test4){
        float list[5] = {534, 876, 235, 248, 871};
        int len = 5;
        float ans = 876;
        Assert::That(ucm::max(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test5){
        float list[2] = {5.1, 7.1};
        int len = 2;
        float ans = 7.1;
        Assert::That(ucm::max(list, len), EqualsWithDelta(ans, 0.01));
    }
};

Context(TestMin){
    Spec(Test1){
        float list[5] = {1,2,3,4,5};
        int len = 5;
        float ans = 1;
        Assert::That(ucm::min(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test2){
        float list[5] = {0,0,0,0,0};
        int len = 5;
        float ans = 0;
        Assert::That(ucm::min(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test3){
        float list[1] = {3};
        int len = 1;
        float ans = 3;
        Assert::That(ucm::min(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test4){
        float list[5] = {534, 876, 235, 248, 871};
        int len = 5;
        float ans = 235;
        Assert::That(ucm::min(list, len), EqualsWithDelta(ans, 0.01));
    }

    Spec(Test5){
        float list[2] = {1.1, 3.3};
        int len = 2;
        float ans = 1.1;
        Assert::That(ucm::min(list, len), EqualsWithDelta(ans, 0.01));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}