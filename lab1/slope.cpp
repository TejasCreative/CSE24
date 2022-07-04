// A simple program to calculate the slope of a line segment
#include <iostream>

using namespace std;

int main(){

    float x1, x2, y1, y2, x, y, total;
    cin >> x2;
    cin >> y2;
    cin >> x1;
    cin >> y1;

    x = x2-x1;
    y = y2-y1;
    total = y/x;

    cout << total;

    return 0;
}
