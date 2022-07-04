#include <iostream>
#include <vector>
#include <crypto.h>

using namespace std;

int main(){
    vector<unsigned int> ciphertext;

    unsigned int curr;

    while (cin >> curr){
        ciphertext.push_back(curr);
    }
    
    string plaintext = decode(ciphertext);

    cout << plaintext << endl;

    return 0;
}
