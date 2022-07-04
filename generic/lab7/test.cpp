#include <igloo/igloo.h>
#include <crypto.h>
#include <vector>

using namespace igloo;

bool valid(std::vector<unsigned int>& ciphertext, std::string plaintext){
    for (int i = 0; i < ciphertext.size(); i++){
        unsigned char pt = plaintext[i];
        unsigned char* c = (unsigned char*) &ciphertext[i];
        c++;
        c++;
        if (*c != pt){
            return false;
        }
    }
    return true;
}

Context(DecodeFunctionTest){
    Spec(DecodeUCM){
        std::vector<unsigned int> ciphertext = {173364855, 2453923808, 4031596914};
        Assert::That(decode(ciphertext), Equals("UCM"));
    }
};

Context(EncodeFunctionTest){
    Spec(EncodeUCM){
        std::vector<unsigned int> ciphertext = encode("UCM");
        Assert::That(valid(ciphertext, "UCM"), IsTrue());
    }
};


int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}
