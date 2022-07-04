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

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}