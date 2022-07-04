#include <iostream>
#include <square.h>
#include <random>
#include <vector>

namespace random_player{

struct Vec{
    int x;
    int y;

    Vec(){
        x = 0;
        y = 0;
    }

    Vec(int x, int y){
        this->x = x;
        this->y = y;
    }

};

Square play(int board[3][3], int token){

    std::vector<Vec> available;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 0){
                available.push_back(Vec(i,j));
            }
        }
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, available.size() - 1);

    int r = dist(rng);

    return Square(available[r].x, available[r].y, token);

    return Square();
}

}