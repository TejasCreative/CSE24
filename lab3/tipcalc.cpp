#include <iostream>
#include <iomanip>
#include <math_utils.h>

using namespace std;
using namespace math;

int main(int argc, char* argv[]){

    float amount = stof(argv[1]);
    int percent = stoi(argv[2]);
    int people = stoi(argv[3]);

    float per_person = calculate_tip(amount, percent, people);

    cout << "Splitting $" << amount << " with " << percent << "% tip, amongst " << people << " people..." << endl;
    cout << "Each person owes: $" << fixed << setprecision(2) << per_person << "." << endl;

    return 0;
}