#include <square.h>

namespace naive_player{


Square play(int board[3][3], int token){
    Square result(-1,-1, token);

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
