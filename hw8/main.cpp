#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    for(int i = 1; i<argc; i++){
        int a = stoi(argv[i]);
        if(a%2 == 0){
            cout << a << " " << flush;
        }
    }

    return 0;
}
