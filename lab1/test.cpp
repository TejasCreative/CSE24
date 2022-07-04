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

Context(FeetToMeters){
    Spec(Check100ftIs30_48m){
        float result = std::stof(compile_run("f2m.cpp", "100"));
        Assert::That(result, EqualsWithDelta(30.48, 0.01));
    }
    Spec(Check5ftIs1_524m){
        float result = std::stof(compile_run("f2m.cpp", "5"));
        Assert::That(result, EqualsWithDelta(1.524, 0.01));
    }
};

Context(MetersToFeet){
    Spec(Check30_48mIs100ft){
        float result = std::stof(compile_run("m2f.cpp", "30.48"));
        Assert::That(result, EqualsWithDelta(100, 0.01));
    }
    Spec(Check1_524mIs5ft){
        float result = std::stof(compile_run("m2f.cpp", "1.524"));
        Assert::That(result, EqualsWithDelta(5, 0.01));
    }
};

Context(FToC){
    Spec(Check75FIs23_8889C){
        float result = std::stof(compile_run("f2c.cpp", "75"));
        Assert::That(result, EqualsWithDelta(23.8889, 0.01));
    }
    Spec(Check100FIs37_7778C){
        float result = std::stof(compile_run("f2c.cpp", "100"));
        Assert::That(result, EqualsWithDelta(37.7778, 0.01));
    }
};

Context(CToF){
    Spec(Check40CIs104F){
        float result = std::stof(compile_run("c2f.cpp", "40"));
        Assert::That(result, EqualsWithDelta(104, 0.01));
    }
    Spec(Check0CIs32F){
        float result = std::stof(compile_run("c2f.cpp", "0"));
        Assert::That(result, EqualsWithDelta(32, 0.01));
    }
    Spec(Check23CIs73_4F){
        float result = std::stof(compile_run("c2f.cpp", "23"));
        Assert::That(result, EqualsWithDelta(73.4, 0.01));
    }
};

Context(Slope){
    Spec(Check1_2_3_Neg2IsNeg2){
        float result = std::stof(compile_run("slope.cpp", "1 2 3 -2"));
        Assert::That(result, EqualsWithDelta(-2, 0.01));
    }
    Spec(Check1_2_Neg3_0Is0_5){
        float result = std::stof(compile_run("slope.cpp", "1 2 -3 0"));
        Assert::That(result, EqualsWithDelta(0.5, 0.01));
    }
};

Context(Length){
    Spec(Check0_0_1_1Is1_41421){
        float result = std::stof(compile_run("length.cpp", "0 0 1 1"));
        Assert::That(result, EqualsWithDelta(1.41421, 0.01));
    }
    Spec(Check0_0_1_0Is1){
        float result = std::stof(compile_run("length.cpp", "0 0 1 0"));
        Assert::That(result, EqualsWithDelta(1, 0.01));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
