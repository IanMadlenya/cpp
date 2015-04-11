//
//  main.cpp
//  hw_02_03
//
//  Created by Weiyi Chen on 6/28/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "Board.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[])
{
    Player player_X, player_O; // two players playing tic-tac-toe
    player_X.c_symbol = 'X'; // initialization
    player_O.c_symbol = 'O';
    Board board; // playing board for tic-tac-toe
    board.initialize();

    // param1 = s - you start, d - demo, n - you don't start
    if (*argv[1] == 's') {
        player_X.b_isYou = true; // record whether you're X or O
        player_O.b_isYou = false;
    }
    else if (*argv[1] == 'n') {
        player_X.b_isYou = false;
        player_O.b_isYou = true;
    }
    else if (*argv[1] == 'd') {
        cout << "The following example game is a demo:" << endl;
        player_X.b_isYou = true;
        player_O.b_isYou = true;
    }

    unsigned int ui_wait = atoi(argv[2]); // param2 = wait in seconds
    char c_win = '_'; // record who is winner

    while (board.i_numMoves < 9 && c_win == '_') {
        board.showBoard(); // display board after each move
        if (board.c_whoseTurn == 'X')
            player_X.move(board, argv[3], argv[4], ui_wait, c_win); // player_X's move
        else
            player_O.move(board, argv[3], argv[4], ui_wait, c_win); // player_O's move
    }
    if (c_win == '_') { // Draw game
        board.showBoard(); 
        cout << "Draw game." << endl;
    }
        
    return 0;
}
