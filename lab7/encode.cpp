#include <iostream>
#include <string>
#include <vector>
#include <crypto.h>


using namespace std;

int main(int argc, char* argv[]){

    if (argc != 2){
        cout << "Usage: ./encode \"PLAINTEXT HERE\"" << endl;
        return 1;
    }

    string message = argv[1];

    vector<unsigned int> ciphertext = encode(message);

    for (int i = 0; i < ciphertext.size(); i++){
        cout << ciphertext[i] << endl;
    }

    return 0;
}
