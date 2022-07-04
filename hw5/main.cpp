#include <iostream>
#include <utils.h>

using namespace std;

int main(int argc, char* argv[]){

    int a = stoi(argv[1]);
    int b = stoi(argv[2]);

    cout << add(a, b) << endl;

    return 0;
}
