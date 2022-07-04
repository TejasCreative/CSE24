#include <iostream>
#include <string_utils.h>

using namespace std;
using namespace strings;

int main(int argc, char* argv[]){

    int numerator = stoi(argv[1]);
    int denominator = stoi(argv[2]);

    cout << format_int_division(numerator / denominator, numerator % denominator) << endl;

    return 0;
}