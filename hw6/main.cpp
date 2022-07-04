#include <iostream>
#include <str_utils.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    string s = argv[1];
    string p = argv[2];
    string r = argv[3];

    string result = replace_pattern(s, p, r);

    cout << result << endl;

    return 0;
}
