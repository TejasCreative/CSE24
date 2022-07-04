#include <igloo/igloo.h>
#include <fifth.h>
#include <string>
#include <fstream>

using namespace igloo;

Context(FifthElementFunctionTest){
    Spec(noForbiddenText){
        std::fstream f;

        f.open("fifth.h", std::ios::in); 
        if (f.is_open()){
            bool clean = true;
            std::string line;
            while(getline(f, line)){
                if (line.find("[") != std::string::npos || line.find("]") != std::string::npos || line.find("include") != std::string::npos){
                    clean = false;
                    break;
                }
            }
            f.close();

            if (clean){
                Assert::That(true, IsTrue());
            }
            else{
                Assert::That("Contains '[' or ']' or include", Equals("Code is clean"));
            }
        }
        else{
            Assert::That("File not found", Equals("File exists"));
        }
        
    }

    Spec(FifthElementIs42){
        int arr[6] = {1,2,3,4,5,42};
        
        Assert::That(theFifthElement(arr), Equals(42));
    }

    Spec(FifthElementIs27){
        int arr[9] = {1, 2, 3, 4, 5, 27, 7, 8, 9};
        
        Assert::That(theFifthElement(arr), Equals(27));
    }


};

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}
