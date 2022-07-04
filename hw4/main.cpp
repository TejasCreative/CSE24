#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){
    float x1, x2, y1, y2, x, y, total, outer;

    x1 = stof(argv[1]);
    y1 = stof(argv[2]);
    x2 = stof(argv[3]);
    y2 = stof(argv[4]);

    x = (x1-x2)*(x1-x2);
    y = (y1-y2)*(y1-y2);

    total = x + y;

    outer = sqrt(total);

    cout << outer << endl;


    return 0;
}
