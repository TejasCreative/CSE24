#include <square.h>


// Do not make any includes from inside the namespace. That causes unimaginable pain and suffering...
namespace student_ai{

// Improve upon the function below. It currently plays the first available square
Square play(int board[3][3], int token){
    Square result(-1,-1, token);
    bool empty = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != 0){
                empty = false;
            }
        }
    }
    if(empty){
        result.col = 2;
        result.row = 2;
        return result;
    }

    if(board[2][2] == token && board[1][1] == 0 && board[0][2] == token && board[1][2]== 0){
        result.col = 2;
        result.row = 1;
        return result;
    }
    if(board[2][2] == token && board[1][1] == 0 && board[0][2] == token && board[1][2]!= 0 && board[2][0]==0){
        result.col = 0;
        result.row = 2;
        return result;
    }
    if(board[2][2] == token && board[1][1] == 0 && board[0][2] == token && board[1][2]!= 0 && board[2][0]==2){
        result.col = 1;
        result.row = 1;
        return result;
    }
    if(board[2][2] == token && board[1][1] != 0 && board[0][2] == token && board[1][2]!= 0 && board[2][0]==2){
        result.col = 1;
        result.row = 2;
        return result;
    }
    if(board[2][2] == token && board[1][1] == 0 && board[0][2] == 0){
        result.col = 2;
        result.row = 0;
        return result;
    }
    if(token == 2 && board[2][2] == 0){
        result.col = 2;
        result.row = 2;
        return result;           
    }
 
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 0){
                result.row = i;
                result.col = j;
                return result;
            }
        }
    }
    return result;
}

}