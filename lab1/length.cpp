// A simple program to calculate the length of a line segment
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x1, x2, y1, y2, x, y, total, outer;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    x = (x1-x2)*(x1-x2);
    y = (y1-y2)*(y1-y2);

    total = x + y;

    outer = sqrt(total);

    cout << outer << endl;

    return 0;
}
