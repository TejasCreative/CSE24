
#include <iostream>
#include <vector>
#include <string>
#include <map_utils.h>

using namespace std;



int main(){

   int map[4][4] = {
        {  0, 110, 130, 136},
        {110,   0,  64,  75},
        {130,  64,   0,  17},
        {136,  75,  17,   0}
    };

        cout << nearestNeighbor(0, map)<< endl;
    

//     Spec(DavisBerkeley){
//         int map[4][4] = {
//             {  0, 110, 130, 136},
//             {110,   0,  64,  75},
//             {130,  64,   0,  17},
//             {136,  75,  17,   0}
//         };

//         Assert::That(nearestNeighbor(1, map), Equals(2));
//     }

//     Spec(BerkeleySF){
//         int map[4][4] = {
//             {  0, 110, 130, 136},
//             {110,   0,  64,  75},
//             {130,  64,   0,  17},
//             {136,  75,  17,   0}
//         };

//         Assert::That(nearestNeighbor(2, map), Equals(3));
//     }

//     Spec(SFBerkeley){
//         int map[4][4] = {
//             {  0, 110, 130, 136},
//             {110,   0,  64,  75},
//             {130,  64,   0,  17},
//             {136,  75,  17,   0}
//         };

//         Assert::That(nearestNeighbor(3, map), Equals(2));
//     }
// };

    return 0;
}