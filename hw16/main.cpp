#include <iostream>

using namespace std;


void print(int** map, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    // You can change the dimension sizes below if you want

    int map1rows = 2;
    int map1cols = 2;
    
    int map2rows = 4;
    int map2cols = 4;

    // Create the map1 variable as a 2D array of the correct sizes (map1rows x map1cols) and fill it with whatever integers you want
    // Do the same for map2
    int** map1 = new int*[map1cols];


    for(int i = 0; i<map1cols; i++){
        map1[i] = new int[map1rows];
        for(int j = 0; j < map1rows; j++){
            map1[i][j] = 1; 
        }
    }
    int** map2 = new int*[map2cols];
    for(int k = 0; k<map2cols; k++){
        map2[k] = new int[map2rows];
        for(int o = 0; o < map2rows; o++){
            map2[k][o] = 2; 
        }
    }
    print(map1, map1rows, map1cols);
    print(map2, map2rows, map2cols);

    return 0;
}
