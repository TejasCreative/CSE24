#include <iostream>
#include <vector>
#include <listproc.h>

using namespace std;

void print(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i];
        if (i < nums.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}

int main(){

    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};

    print(numbers);

    doubleOrNothing(numbers);

    print(numbers);

    return 0;
}
