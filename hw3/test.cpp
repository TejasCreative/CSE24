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

std::string compile_run(std::string filename){
    std::string compile = exec("g++ -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("./temp");
        system("rm -f temp");
    }

    return output;
}

std::string compile_run(std::string filename, std::string input){
    std::string compile = exec("g++ -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("echo \"" + input + "\" | ./temp");
        system("rm -f temp");
    }

    return output;
}

Context(Strings){
    Spec(JustinCredible){
        std::string result = compile_run("main.cpp", "justin\ncredible");
        std::string expected = "String: justin\nLength: 6\nEmpty: 0\nFirst: j\nLast: n\n---\nString: credible\nLength: 8\nEmpty: 0\nFirst: c\nLast: e\n---\njustincredible";
        Assert::That(result, Equals(expected));
    }
    Spec(ApplePie){
        std::string result = compile_run("main.cpp", "apple\npie");
        std::string expected = "String: apple\nLength: 5\nEmpty: 0\nFirst: a\nLast: e\n---\nString: pie\nLength: 3\nEmpty: 0\nFirst: p\nLast: e\n---\napplepie";
        Assert::That(result, Equals(expected));
    }
};



int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
