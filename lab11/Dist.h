#ifndef DIST_H
#define DIST_H

#include <ostream>

struct Dist{
    int feet;
    int inches;

    Dist(){
        feet = 0;
        inches = 0;
    }

    Dist(int feet, int inches){
        int temp = inches / 12;
        int rem = inches % 12;
        this->feet = feet + temp;
        this->inches = rem;
    }


    Dist operator+(const Dist d){
        int i = inches + d.inches;
        int f = feet + d.feet + (i / 12);
        i = i % 12;
        return Dist(f, i);
    }

    Dist operator/(int d){
        int i = (inches + ((feet%d)*12)) / d;
        int f = feet / d;
        return Dist(f, i);
    }

};

std::ostream& operator<<(std::ostream& os, const Dist& d){
    os << d.feet << "' " << d.inches << "\"";
    return os;
}

#endif