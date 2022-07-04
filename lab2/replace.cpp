#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]){

    string a, b, c;
    int val, lenb;
    a = argv[1];
    b = argv[2];
    c = argv[3];
    val = a.find(b);
    lenb = b.length();
    a.replace(val, lenb, c);
    cout << a << endl;




    return 0;
}
