#include <iostream>
#include <vector>
#include <string>
#include <map_utils.h>

using namespace std;



int main(){
    // A map of distances, it shows that city 0 is 110 miles from city 1, and city 3 is 17 miles from city 2, etc...
    int distances[4][4] = {
        {  0, 110, 130, 136},
        {110,   0,  64,  75},
        {130,  64,   0,  17},
        {136,  75,  17,   0}
    };

    // Giving names to the indices of the map
    string campuses[4] = {"UC Merced", "UC Davis", "UC Berkeley", "UC San Francisco"};

    // Compute the best greedy roundtrip itinerary for the map above, given a starting point
    vector<string> itinerary = planTrip(0, distances, campuses, 4);

    // Print out the itinerary
    for (int i = 0; i < itinerary.size(); i++){
        cout << itinerary[i];
        if (i < itinerary.size() - 1){
            cout << " - ";
        }
    }
    cout << endl;

    return 0;
}