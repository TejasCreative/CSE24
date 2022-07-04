#include <iostream>
#include <game.h>
#include <square.h>


#include <random_player.h>
#include <naive_player.h>
#include <student_ai.h>

using namespace std;

int main(int argc, char* argv[]){
    // Create a new game
    Game game;

    // The 2 player functions
    Square (*player1)(int[3][3], int) = nullptr;
    Square (*player2)(int[3][3], int) = nullptr;

    string error = "Usage: ./play [player1] [player2]\n\nOptions for player1 and player2:\n  naive:\tPlays first available square.\n  random:\tPlays a randomly chosen available square.\n  student:\tPlays the student created AI.\n";

    if (argc == 3){
        if (string(argv[1]) == "naive"){
            player1 = naive_player::play;
        }
        else if (string(argv[1]) == "random"){
            player1 = random_player::play;
        }
        else if (string(argv[1]) == "student"){
            player1 = student_ai::play;
        }
        else{
            cout << error << endl;
            return 1;
        }

        if (string(argv[2]) == "naive"){
            player2 = naive_player::play;
        }
        else if (string(argv[2]) == "random"){
            player2 = random_player::play;
        }
        else if (string(argv[2]) == "student"){
            player2 = student_ai::play;
        }
        else{
            cout << error << endl;
            return 1;
        }

    }
    else {
        cout << error << endl;
        return 1;
    }
    
    // Ready player 1
    int player = 1;
    
    while (game.status == ongoing){
        // Display whose turn it is
        cout << "Player " << player << endl;

        // Appropriate player makes their move
        Square movePlayer;
        if (player == 1){
            movePlayer = player1(game.board, player);
        }
        else if (player == 2){
            movePlayer = player2(game.board, player);
        }
        // Apply the player's move to the game
        game.apply(movePlayer); // game.status gets updated here

        // Display current board
        game.display();

        // Switch player turns
        if (player == 1){
            player = 2;
        }
        else if (player == 2){
            player = 1;
        }
    }

    // Game is over. Display who the winner is
    cout << game.status << endl;

    return 0;
}