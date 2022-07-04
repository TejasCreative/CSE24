#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <string>

namespace strings {

char first(std::string sen){
    return sen[0];
}

std::string format_int_division(int num, int den){
    std::string returnable;
    std::string x;
    std::string y;

    x = std::to_string(num);
    y = std::to_string(den);
    returnable += x;
    returnable += " rem ";
    returnable += y;
    return returnable;
}
std::string cut(std::string phase){
    int x = phase.length();
    int half = x/2;
    std::string first;
    std::string last;
    std::string able;
    x = x+1;
    first = phase.substr(0,half);
    last = phase.substr(half, x);
    able = last;
    able += first;
    return able;
}


void help(){
    std::cout << "This is the strings module" << std::endl;
}


}

#endif
