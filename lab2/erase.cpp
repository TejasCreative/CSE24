#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]){

    string a;
    int b, c;
    a = argv[1];
    b = stoi(argv[2]);
    c = stoi(argv[3]);
    a.replace(b, c, "");
    cout << a << endl;

    return 0;
}
