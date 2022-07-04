#include <iostream>
#include <math_utils.h>     // The two libraries we have created
#include <string_utils.h>

using namespace std;
using namespace math;       // Each of the libraries we created is namespaced
using namespace strings;

int main(int argc, char* argv[]){

    cout << inc(7) << endl;  

    cout << first("hello") << endl;

    strings::help();        // Both libraries contain a help() function.
    math::help();           // Therefore we need to specify which one we want to
                            // call, using the scope (::) operator.
    return 0;
}