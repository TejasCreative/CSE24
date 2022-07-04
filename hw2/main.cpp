#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;
    getline(cin, name);
    cin >> age;
    cout <<"Hello, "<< name << ", it's good to be " << age << " years old." << endl;

	return 0;
}
