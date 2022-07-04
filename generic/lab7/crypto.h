#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <string>
#include <vector>
#include <RandomSupport.h>

void pad(int val){
    std::string space = "";

    if (val < 10){
        space = "  ";
    }
    else if (val < 100){
        space = " ";
    }

    std::cout << space << val;
}

void core_dump(void* p, int length){
    unsigned char* q = (unsigned char*)p;
    std::cout << "| ";
    for (int i = 0; i < length; i++){
        int curr = (int)(*q);
        pad(curr);

        if (i == length - 1){
            std::cout << " |";
        }
        else{
            std::cout << " | ";
        }

        q++;
    }
    std::cout << std::endl;
}

std::string decode(std::vector<unsigned int>& ciphertext){

    unsigned int current = 0;
    std::string result = "";
    for(int i = 0; i< ciphertext.size(); i++){
        current = ciphertext.at(i);
        unsigned char* c = (unsigned char*)&current;

        c++;
        c++;
        char test = (int)*c;
        result += test;
        



    }
    


    return result;
}


std::vector<unsigned int> encode(std::string plaintext){
    char value;
    unsigned int counter;

    std::vector<unsigned int> ciphertext;
    for(int i = 0; i<plaintext.length(); i++){
        value = plaintext[i];
        unsigned char* c = (unsigned char*)&counter;
        RNG generator(0, 255);
        unsigned int x = generator.get();
        *c = (unsigned char)x;
        c++;
        x = generator.get();
        *c = (unsigned char)x;
        c++;
        *c = (unsigned char)value;
        c++;
        x = generator.get();
        *c = (unsigned char)x;

        ciphertext.push_back(counter);





    }
    
    

    return ciphertext;
}

#endif
