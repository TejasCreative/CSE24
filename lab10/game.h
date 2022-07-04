#ifndef GAME_H
#define GAME_H

#include <ostream>
#include <square.h>

enum outcome {ongoing, draw, player1win, player2win};

std::ostream& operator<<(std::ostream& os, outcome res){
    if (res == ongoing) os << "Ongoing";
    else if (res == draw) os << "Draw";
    else if (res == player1win) os << "Player 1 Wins";
    else if (res == player2win) os << "Player 2 Wins";

    return os;
}

struct Game{
    int board[3][3];
    outcome status;

    Game(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = 0;
            }
        }
        status = checkGame();
    }

    outcome checkGame(){
        // Check if a player has a complete row
        for (int i = 0; i < 3; i++){
            int curr = board[i][0];
            if (curr == 1 || curr == 2){
                bool winning = true;
                for (int j = 1; j < 3; j++){
                    if (board[i][j] != curr){
                        winning = false;
                    }
                }
                if (winning){
                    if (curr == 1){
                        return player1win;
                    }
                    else {
                        return player2win;
                    }
                }
            }
        }

        // Check if a player has a complete column
        for (int i = 0; i < 3; i++){
            int curr = board[0][i];
            if (curr == 1 || curr == 2){
                bool winning = true;
                for (int j = 1; j < 3; j++){
                    if (board[j][i] != curr){
                        winning = false;
                    }
                }
                if (winning){
                    if (curr == 1){
                        return player1win;
                    }
                    else {
                        return player2win;
                    }
                }
            }
        }

        // Check if a player has a diagonal
        if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1){
            return player1win;
        }
        if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1){
            return player1win;
        }
        if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2){
            return player2win;
        }
        if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2){
            return player2win;
        }

        // Check if it is a draw
        bool done = true;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    done = false;
                }
            }
        }

        if (done){
            return draw;
        }
        else{
            return ongoing;
        }

    }

    void display(){
        for (int i = 0; i < 7; i++){
            if (i % 2 == 1){
                std::cout << "| ";

                for (int j = 0; j < 3; j++){
                    char marker = ' ';
                    if (board[i/2][j] == 1){
                        marker = 'x';
                    }
                    else if (board[i/2][j] == 2){
                        marker = 'o';
                    }
                    std::cout << marker << " | ";
                }
            }
            else{
                std::cout << " ";
            
                for (int j = 0; j < 3; j++){
                    std::cout << "--- ";
                }
            }
            std::cout << std::endl;
        }
    }

    void apply(Square move){
        int player = move.token;
        
        if (move.row < 0 || move.col < 0 || move.row > 2 || move.col > 2){
            if (player == 1){
                status = player2win;
            }
            else if (player == 2){
                status = player1win;
            }
        }
        if (board[move.row][move.col] == 0){
            board[move.row][move.col] = move.token;
            status = checkGame();
        }
        else{
            if (player == 1){
                status = player2win;
            }
            else if (player == 2){
                status = player1win;
            }
        }
    }
};

#endif
