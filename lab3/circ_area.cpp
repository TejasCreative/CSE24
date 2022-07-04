#include <iostream>
#include <iomanip>
#include <math_utils.h>

using namespace std;
using namespace math;

int main(int argc, char* argv[]){

    float radius = stof(argv[1]);

    float area = circle_area(radius);

    cout << "Circle with radius " << radius << " has an area of " << fixed << setprecision(2) << area << "." << endl;

    return 0;
}
