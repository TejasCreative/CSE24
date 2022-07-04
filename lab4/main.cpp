#include <iostream>
#include <list_utils.h>

using namespace std;
using namespace ucm;

int main (int argc, char* argv[]){

    if(argc < 3){
        cout << "Usage: ./calc [operation] [list of numbers...]" << endl;
        cout << "Operations:" << endl;
        cout << "  -add\t\tAdd up the input list" << endl;
        cout << "  -avg\t\tCompute the average of the input list" << endl;
        cout << "  -min\t\tFind the maximum of the input list" << endl;
        cout << "  -min\t\tFind the minimum of the input list" << endl;
        return -1;
    }

    string flag = argv[1];
    int gar = argc-2;
    float arr[gar];
    float a;


    for(int i = 2; i < argc; i++){
        arr[i-1] = stof(argv[i]);
    }

    int val = size_t(arr);

    if(flag == "-add"){
        a = addUp(arr, val);
        cout << a << endl;
    }
    else if(flag == "-avg"){
        a = average(arr, val);
        cout << a << endl;
    }
    else if(flag == "-min"){
        a = min(arr, val);
        cout << a << endl;
    }
    else if(flag == "-max"){
        a = max(arr, val);
        cout << a << endl;
    }
    else{
        cout << "Invalid operation: " << flag << endl;
    }




    return 0;
}
