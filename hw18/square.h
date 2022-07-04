#ifndef SQUARE_H
#define SQUARE_H

#include <ostream>


struct Square{
    int row;
    int col;
    int token;
    Square(){
        row = 0;
        col = 0;
        token = 0;
    }
    Square(int row, int col, int token){
        this->row = row;
        this->col = col;
        this->token = token;

    }
};

std::ostream& operator<<(std::ostream& os, const Square& s){
    os << s.token << ": (" << s.row << ", " << s.col << ")";
    return os;
}

#endif