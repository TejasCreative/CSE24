#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace igloo;

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   while (!feof(pipe)) {
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

Context(TestingWithIncorrectFunctions){
    
    static void SetUpContext(){
        std::ifstream infile("test.cpp");

        std::string line;
        std::string new_file = "";
        bool inContext = false;
        std::string con = "";
        while (std::getline(infile, line)){
            
            if (line.find("#include") != std::string::npos && line.find("geometry.h") != std::string::npos){
                line = "// " + line+ '\n';
                line = line + "bool pointInRect1(float x, float y, float rx, float ry, float rw, float rh){\n\treturn false;\n}\n\n";
                line = line + "bool pointInRect2(float x, float y, float rx, float ry, float rw, float rh){\n\treturn true;\n}\n\n";
                line = line + "bool pointInRect3(float x, float y, float rx, float ry, float rw, float rh){\n\treturn x >= rx;\n}\n\n";
                line = line + "bool pointInRect4(float x, float y, float rx, float ry, float rw, float rh){\n\treturn x <= rx + rw;\n}\n\n";
                line = line + "bool pointInRect5(float x, float y, float rx, float ry, float rw, float rh){\n\treturn y <= ry;\n}\n\n";
                line = line + "bool pointInRect6(float x, float y, float rx, float ry, float rw, float rh){\n\treturn y >= ry-rh;\n}\n\n";
            }
            else if (line.find("Context") != std::string::npos){
                inContext = true;
            }
            else if (line.find("};") != std::string::npos){
                inContext = false;
                con += line + '\n';
            }

            if (inContext){
                con += line + '\n';
            }
            new_file += line + '\n';
        }

        std::string one = con;
        std::string two = con;
        std::string three = con;
        std::string four = con;
        std::string five = con;
        std::string six = con;

        
        findAndReplaceAll(one, "pointInRect", "pointInRect1");
        findAndReplaceAll(one, "PointInRectTestSuite", "Test1");
        findAndReplaceAll(two, "pointInRect", "pointInRect2");
        findAndReplaceAll(two, "PointInRectTestSuite", "Test2");
        findAndReplaceAll(three, "pointInRect", "pointInRect3");
        findAndReplaceAll(three, "PointInRectTestSuite", "Test3");
        findAndReplaceAll(four, "pointInRect", "pointInRect4");
        findAndReplaceAll(four, "PointInRectTestSuite", "Test4");
        findAndReplaceAll(five, "pointInRect", "pointInRect5");
        findAndReplaceAll(five, "PointInRectTestSuite", "Test5");
        findAndReplaceAll(six, "pointInRect", "pointInRect6");
        findAndReplaceAll(six, "PointInRectTestSuite", "Test6");

        std::string combine = one + "\n\n" + two + "\n\n" + three + "\n\n" + four + "\n\n" + five + "\n\n" + six + "\n\n";

        findAndReplaceAll(new_file, con, combine);

        std::ofstream out("test_with_incorrect.cpp");
        out << new_file;
        out.close(); 

        system("rm -f temp_test_with_incorrect");
        std::string compile = exec("g++ -I. -o temp_test_with_incorrect test_with_incorrect.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }
        system("rm -f test_with_incorrect.cpp");

    }
    static void TearDownContext(){
        system("rm -f temp_test_with_incorrect");
    }

    Spec(TestWithIncorrectFucntion){
        std::string result = exec("./temp_test_with_incorrect");
        std::stringstream input_stringstream(result);
        std::string first_line;

        std::string outcome = "An incorrect function is passing all your tests.";
     
        std::string tests[6] = {"Test1::", "Test2::", "Test3::", "Test4::", "Test5::", "Test6::"};
        bool all_fail = true;

        for (int i = 0; i < 6; i++){
            std::string curr = tests[i];

            if (result.find(curr) == std::string::npos){
                all_fail = false;
            }
        }

        if (all_fail){
            outcome = "An incorrect function is failing some of your tests.";
        }
   
        
        Assert::That(outcome, Equals("An incorrect function is failing some of your tests."));
    }
};

Context(TestingWithCorrectFunction){
    
    static void SetUpContext(){
        std::ifstream infile("test.cpp");

        std::string line;
        std::string new_file = "";
        while (std::getline(infile, line)){
            if (line.find("#include") != std::string::npos && line.find("geometry.h") != std::string::npos){
                line = "// " + line+ '\n';
                line = line + "bool pointInRect(float x, float y, float rx, float ry, float rw, float rh){\n\treturn x >= rx && x <= rx + rw && y <= ry && y >= ry - rh;\n}";
                
            }
            new_file += line + "\n";
        }

        std::ofstream out("test_with_correct.cpp");
        out << new_file;
        out.close(); 

        system("rm -f temp_test_with_correct");
        std::string compile = exec("g++ -I. -o temp_test_with_correct test_with_correct.cpp");
        std::string output = compile;
        if (compile != ""){
            std::cout << "Your program fails to compile:" << std::endl << std::endl;
            std::cout << compile << std::endl;
        }
        system("rm -f test_with_correct.cpp");

    }
    static void TearDownContext(){
        system("rm -f temp_test_with_correct");
    }

    Spec(TestWithCorrectFucntion){
        std::string result = exec("./temp_test_with_correct");
        std::stringstream input_stringstream(result);
        std::string first_line;

        std::string outcome = "A correct function is passing all your tests.";
        if (getline(input_stringstream, first_line))
        {
            if (first_line.find("F") != std::string::npos){
                outcome = "A correct function is failing some of your tests.";
            }
        }

        Assert::That(outcome, Equals("A correct function is passing all your tests."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
