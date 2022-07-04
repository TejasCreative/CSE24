#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]){

    string a, b;
    int c;
    a = argv[1];
    b = argv[2];
    c = stoi(argv[3]);
    a.insert(c, b);
    cout << a << endl;

    return 0;
}
