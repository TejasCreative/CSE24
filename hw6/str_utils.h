#ifndef STR_UTILS_H
#define STR_UTILS_H

#include<string>

std::string replace_pattern(std::string a, std::string b, std::string c){
    int val;
    int lenb;
    val = a.find(b);
    lenb = b.length();
    a.replace(val, lenb, c);
    return a;
}

#endif
