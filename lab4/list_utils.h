#ifndef LIST_UTILS_H
#define LIST_UTILS_H

namespace ucm{

float addUp(float nums[], int size){
       float total = 0;
       for(int i = 0; i<size; i++){
           total = total + nums[i];
       }
       return total;
}

float average(float nums[], int size){
    float total = 0;
    for (int i = 0; i<size; i++){
        total = total + nums[i];
    }
    return total/(float)size;
}

float min(float nums[], int size){
    float small = nums[0];
    for(int i = 0; i<size; i++){
        if(small > nums[i]){
            small = nums[i];
        }
    }
    return small;
}

float max(float nums[], int size){
    float large = nums[0];
    for(int i = 0; i<size; i++){
        if(large < nums[i]){
            large = nums[i];
        }

    }
    return large;
}



}

#endif
