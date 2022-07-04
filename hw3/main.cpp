#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    int testa, testb;
    int vala = 0;
    int valb = 0;

    cin >> a;

    cin >> b;


    testa = a.length();
    testb = b.length();


    if(testb == 0){
        valb = 1;
    }

    if(testa == 0){
        vala = 1;
    }

    cout << "String: " << a << endl;
    cout << "Length: " << testa << endl;
    cout << "Empty: " << vala << endl;
    cout << "First: " << a[0] << endl;
    cout << "Last: " << a[testa-1]<< endl;
    cout << "---" << endl;
    cout << "String: " << b << endl;
    cout << "Length: " << testb << endl;
    cout << "Empty: " << valb << endl;
    cout << "First: " << b[0] << endl;
    cout << "Last: " << b[testb-1] << endl;
    cout << "---" << endl;
    cout << a << b << endl;

    return 0;
}
