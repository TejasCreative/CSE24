#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>

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


Context(TestingSegLen){

    static void SetUpContext(){
        system("rm -f temp");
        std::string compile = exec("g++ -o temp main.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }

    }
    static void TearDownContext(){
        system("rm -f temp");
    }

    Spec(Check0_0_1_1Is1_41421){
        float result = std::stof(exec("./temp 0 0 1 1"));
        Assert::That(result, EqualsWithDelta(1.41421, 0.01));
    }

    Spec(Check0_0_1_0Is1){
        float result = std::stof(exec("./temp 0 0 1 0"));
        Assert::That(result, EqualsWithDelta(1, 0.01));
    }
    Spec(CheckUnitCircle){
        float result = std::stof(exec("./temp 0 0 0.707106781186548 0.707106781186548"));
        Assert::That(result, EqualsWithDelta(1, 0.01));
    }
    
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
