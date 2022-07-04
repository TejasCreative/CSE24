#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <iostream>
#include <cmath>

namespace math {

int inc(int x){
    return x + 1;
}

float calculate_tip(float a, int b, int c){
    float per_tip = float(b)/100;
    float true_tip = per_tip * a;
    float total = true_tip + a;
    return total/c;


}
float circle_area(float radius){
    float total = M_PI * radius * radius;
    return total;

}
void help(){
    std::cout << "This is the math module" << std::endl;
}

}

#endif
