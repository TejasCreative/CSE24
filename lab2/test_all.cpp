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


Context(TestingInsert){

    static void SetUpContext(){
        system("rm -f temp_insert");
        std::string compile = exec("g++ -o temp_insert insert.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }

    }
    static void TearDownContext(){
        system("rm -f temp_insert");
    }

    Spec(TestWorldWideWeb){
        std::string result = exec("./temp_insert worldweb wide 5");
        Assert::That(result, Equals("worldwideweb"));
    }

    Spec(TestControl){
        std::string result2 = exec("./temp_insert cool ntr 2");
        Assert::That(result2, Equals("control"));
    }
};

Context(TestingErase){

    static void SetUpContext(){
        system("rm -f temp_erase");
        std::string compile = exec("g++ -o temp_erase erase.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }

    }
    static void TearDownContext(){
        system("rm -f temp_erase");
    }

    Spec(TestWorldWideWeb){
        std::string result = exec("./temp_erase catalog 1 4");
        Assert::That(result, Equals("cog"));
    }

    Spec(TestControl){
        std::string result2 = exec("./temp_erase championship 2 8");
        Assert::That(result2, Equals("chip"));
    }
};

Context(TestingReplace){

    static void SetUpContext(){
        system("rm -f temp_replace");
        std::string compile = exec("g++ -o temp_replace replace.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }

    }
    static void TearDownContext(){
        system("rm -f temp_replace");
    }

    Spec(TestWorldWideWeb){
        std::string result = exec("./temp_replace \"World Wrestling Federation\" Federation Entertainment");
        Assert::That(result, Equals("World Wrestling Entertainment"));
    }

    Spec(TestControl){
        std::string result2 = exec("./temp_replace awful ful esome");
        Assert::That(result2, Equals("awesome"));
    }    
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
