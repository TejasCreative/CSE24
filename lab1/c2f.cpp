// A simple program to convert C to F
#include <iostream>

using namespace std;

int main(){

    float enter;

    cin >> enter;
    enter = enter*9;
    enter = enter/5.0;
    enter = enter + 32;

    cout << enter << endl;


    return 0;
}
