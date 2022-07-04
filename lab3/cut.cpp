#include <iostream>
#include <string_utils.h>

using namespace std;
using namespace strings;

int main (int argc, char* argv[]){
    string phrase = argv[1];

    cout << cut(phrase) << endl;

    return 0;
}