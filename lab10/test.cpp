#include <iostream>
#include <igloo/igloo.h>
#include <square.h>
#include <game.h>
#include <student_ai.h>
#include <naive_player.h>
#include <random_player.h>

using namespace igloo;

Context(TestAI){
    Spec(MustBeatNaivePlayerAsPlayer1){
        Game game;
        Square (*player1)(int[3][3], int) = student_ai::play;
        Square (*player2)(int[3][3], int) = naive_player::play;

        int player = 1;
    
        while (game.status == ongoing){
            Square movePlayer;
            if (player == 1){
                movePlayer = player1(game.board, player);
            }
            else if (player == 2){
                movePlayer = player2(game.board, player);
            }
            
            game.apply(movePlayer);

            if (player == 1){
                player = 2;
            }
            else if (player == 2){
                player = 1;
            }
        }
        Assert::That(game.status, Equals(player1win));
    }

    Spec(MustBeatNaivePlayerAsPlayer2){
        Game game;
        Square (*player1)(int[3][3], int) = naive_player::play;
        Square (*player2)(int[3][3], int) = student_ai::play;

        int player = 1;
    
        while (game.status == ongoing){
            Square movePlayer;
            if (player == 1){
                movePlayer = player1(game.board, player);
            }
            else if (player == 2){
                movePlayer = player2(game.board, player);
            }
            
            game.apply(movePlayer);

            if (player == 1){
                player = 2;
            }
            else if (player == 2){
                player = 1;
            }
        }
        Assert::That(game.status, Equals(player2win));
    }

    Spec(MustWinMoreThan50TimesAsPlayer1AgainstRandomPlayer){
        Square (*player1)(int[3][3], int) = student_ai::play;
        Square (*player2)(int[3][3], int) = random_player::play;

        int wins = 0;
        int losses = 0;

        for (int i = 0; i < 100; i++){

            Game game;

            int player = 1;
        
            while (game.status == ongoing){
                Square movePlayer;
                if (player == 1){
                    movePlayer = player1(game.board, player);
                }
                else if (player == 2){
                    movePlayer = player2(game.board, player);
                }
                
                game.apply(movePlayer);

                if (player == 1){
                    player = 2;
                }
                else if (player == 2){
                    player = 1;
                }
            }
            if (game.status == player1win){
                wins++;
            }
            else if (game.status == player2win){
                losses++;
            }
        }
        Assert::That(wins, IsGreaterThan(50));
    }

    Spec(MustWinMoreThan50TimesAsPlayer2AgainstRandomPlayer){
        Square (*player1)(int[3][3], int) = random_player::play;
        Square (*player2)(int[3][3], int) = student_ai::play;

        int wins = 0;
        int losses = 0;

        for (int i = 0; i < 100; i++){

            Game game;

            int player = 1;
        
            while (game.status == ongoing){
                Square movePlayer;
                if (player == 1){
                    movePlayer = player1(game.board, player);
                }
                else if (player == 2){
                    movePlayer = player2(game.board, player);
                }
                
                game.apply(movePlayer);

                if (player == 1){
                    player = 2;
                }
                else if (player == 2){
                    player = 1;
                }
            }
            if (game.status == player1win){
                losses++;
            }
            else if (game.status == player2win){
                
                wins++;
            }
        }
        Assert::That(wins, IsGreaterThan(50));
    }
};


int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}