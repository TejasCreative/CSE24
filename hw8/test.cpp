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

    Spec(Check1_10){
        std::string result = exec("./temp 1 2 3 4 5 6 7 8 9 10");
        Assert::That(result, Equals("2 4 6 8 10"));
    }

    Spec(CheckRandom){
        std::string result = exec("./temp 3 4 5 67 8 645 53 243 2 123 12 435 4 765 765 56 1321 534 654 7 31 41 36 27356  3142");
        Assert::That(result, Equals("4 8 2 12 4 56 534 654 36 27356 3142"));
    }

    Spec(CheckAllEven){
        std::string result = exec("./temp 10 20 30 40 50 60 70 80 90 100");
        Assert::That(result, Equals("10 20 30 40 50 60 70 80 90 100"));
    }

    Spec(CheckAllOdd){
        std::string result = exec("./temp 1 21 31 41 51 61 71 81 91 101");
        Assert::That(result, Equals(""));
    }
    
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
