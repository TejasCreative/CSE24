#ifndef LISTPROC_H
#define LISTPROC_H

#include <iostream>
#include <vector>

// Your code here
// Remember we are not using namespace std here, 
// so if you want to declare a vector, you need to use std::vector

void doubleOrNothing(std::vector<int>& arr){
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] %2 == 0){
            arr[i] = arr[i] * 2;
        }
        else{
            arr[i] = NULL;
        }
    }
}



#endif