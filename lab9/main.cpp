#include <iostream>
#include <graphs.h>

using namespace std;


int main(){
    int nodes = 10;
    int graph_matrix[nodes][nodes] = {
        //       0  1  2  3  4  5  6  7  8  9
        //      ------------------------------
        /* 0 */ {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        /* 1 */ {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        /* 2 */ {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        /* 3 */ {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        /* 4 */ {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        /* 5 */ {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        /* 6 */ {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        /* 7 */ {0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        /* 8 */ {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        /* 9 */ {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
    };

    int** graph_list = new int*[nodes];
    graph_list[0] = new int[2];
    graph_list[0][0] = 1;
    graph_list[0][1] = 2;

    graph_list[1] = new int[2];
    graph_list[1][0] = 0;
    graph_list[1][1] = 2;

    graph_list[2] = new int[3];
    graph_list[2][0] = 0;
    graph_list[2][1] = 1;
    graph_list[2][2] = 3;

    graph_list[3] = new int[2];
    graph_list[3][0] = 2;
    graph_list[3][1] = 6;

    graph_list[4] = new int[3];
    graph_list[4][0] = 5;
    graph_list[4][1] = 6;
    graph_list[4][2] = 7;

    graph_list[5] = new int[1];
    graph_list[5][0] = 4;

    graph_list[6] = new int[2];
    graph_list[6][0] = 3;
    graph_list[6][1] = 4;

    graph_list[7] = new int[3];
    graph_list[7][0] = 4;
    graph_list[7][1] = 8;
    graph_list[7][2] = 9;

    graph_list[8] = new int[2];
    graph_list[8][0] = 7;
    graph_list[8][1] = 9;

    graph_list[9] = new int[2];
    graph_list[9][0] = 7;
    graph_list[9][1] = 8;

    int* sizes = new int[nodes];
    sizes[0] = 2;
    sizes[1] = 2;
    sizes[2] = 3;
    sizes[3] = 2;
    sizes[4] = 3;
    sizes[5] = 1;
    sizes[6] = 2;
    sizes[7] = 3;
    sizes[8] = 2;
    sizes[9] = 2;

    cout << boolalpha; // Make booleans print alphabetically (as true or false) instead of 1 or 0;
    
    cout << "Friends List" << endl;
    print(graph_list, nodes, sizes);

    cout << "Is it true that 6 and 3 are friends? ";
    cout << friends(graph_list, sizes, 6, 3) << endl;

    cout << "How about 6 and 7, are they friends? ";
    cout << friends(graph_list, sizes, 6, 7) << endl;

    cout << "Do 6 and 7 have a mutual friend? ";
    cout << mutual(graph_list, sizes, 6, 7) << endl;

    cout << "Do 3 and 5 have a mutual friend? ";
    cout << mutual(graph_list, sizes, 3, 5) << endl;



    // Clean up the heap
    for (int i = 0; i < nodes; i++){
        delete[] graph_list[i];
    }

    delete[] graph_list;
    delete[] sizes;

    return 0;
}
