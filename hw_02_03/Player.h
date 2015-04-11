/*
 * Player.h
 *
 *  Created on: Jun 28, 2014
 *      Author: weiyi
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Player{
public:
    bool b_isYou; // record whether this player is user
    char c_symbol; // record this player's symbol on board, X or O
    int i_move; // record player's next move on board
    void updateBoard(Board &board);
    void loadMoveFromFile(string s_inputDir, unsigned int ui_wait);
    void saveMoveToFile(string s_outputDir);
    void move(Board &board, string s_inputDir, string s_outputDir, unsigned int ui_wait, char &c_win);
    int moveStrategy(Board board);
};

void Player::updateBoard(Board &board) {
    /*
    @summary: player's move on board to update
    @param board: the board for player to play
    */
    while (board.c_board[i_move] != '_') {
        cout << "This place has been taken. Please re-input coordinates: ";
        int i_coordinateX, i_coordinateY;
        cin >> i_coordinateX >> i_coordinateY;
        i_move = i_coordinateY + i_coordinateX * 3;
    }
    board.c_board[i_move] = board.c_whoseTurn;
}

void Player::loadMoveFromFile(string s_inputDir, unsigned int ui_wait) {
    /*
    @summary: load opponent's move from inputDir/tttmove.txt
    @param s_inputDir: param_3 in problem description
    @param ui_wait: param_2 in problem descrition, wait time in seconds
    */
    string s_filePath = s_inputDir + "tttmove.txt";
    fstream in_stream;
    do {
        sleep(ui_wait);
        in_stream.open(s_filePath.c_str());
    } while (!in_stream);
    if (remove(s_filePath.c_str()) != 0) {
        perror( "Error deleting file" );
    }
    int i_coordinateX, i_coordinateY;
    in_stream >> i_coordinateX >> i_coordinateY;
    i_move = i_coordinateX * 3 + i_coordinateY;
}

void Player::saveMoveToFile(string s_outputDir) {
    /*
    @summary: save user's move to file
    @param s_outputDir: param_4 in problem description
    */
    string s_filePath = s_outputDir + "tttmove.txt";
    ofstream out_stream(s_filePath.c_str());
    if (!out_stream)
        cout << "Unable to open output file." << endl;
    int i_coordinateY = i_move % 3, i_coordinateX = i_move / 3;
    out_stream << i_coordinateX << ' ' << i_coordinateY << endl;
}

int Player::moveStrategy(Board board) {
    /*
    @summary: player's optimal strategy to play tic-tac-toe
    @param board: current board information
    @return: next move
    */
    if (c_symbol == 'X') {
        int i_almostWinLine = board.checkAlmostWinLine(271);
        if (i_almostWinLine != 0)
            return board.findLineBlank(i_almostWinLine);
        i_almostWinLine = board.checkAlmostWinLine(253);
        if (i_almostWinLine != 0)
            return board.findLineBlank(i_almostWinLine);
        if (board.c_board[4] == '_')
            return 4;
        int i_almostWinEdge = board.checkAlmostWinEdge(538);
        if (i_almostWinEdge != 0)
            return i_almostWinEdge;
        int i_checklist[8] = {0, 2, 6, 8, 1, 3, 5, 7};
        for (int i = 0; i < 8; i++)
            if (board.c_board[i_checklist[i]] == '_')
                return i_checklist[i];
    }
    else {
        int i_almostWinLine = board.checkAlmostWinLine(253);
        if (i_almostWinLine != 0)
            return board.findLineBlank(i_almostWinLine);
        i_almostWinLine = board.checkAlmostWinLine(271);
        if (i_almostWinLine != 0)
            return board.findLineBlank(i_almostWinLine);
        if (board.c_board[4] == '_')
            return 4;
        int i_almostWinEdge = board.checkAlmostWinEdge(556);
        if (i_almostWinEdge != 0)
            return i_almostWinEdge;
        int i_checklist[8] = {0, 2, 6, 8, 1, 3, 5, 7};
        for (int i = 0; i < 8; i++)
            if (board.c_board[i_checklist[i]] == '_')
                return i_checklist[i];    
    }
    return 100;
}

void Player::move(Board &board, string s_inputDir, string s_outputDir, unsigned int ui_wait, char &c_win) {
    /*
    @summary: player's whole move in each round, including updating board, generating strategies, read and write moves, check wins...
    @param board: board to play on
    @param s_inputDir: param_3
    @param s_outputDir: param_4
    @param ui_wait: waiting time in seconds
    @c_win: record the winner in the play
    */
    if (b_isYou) {
        //cout << "Please input coordinates of your next move: ";
        //int i_coordinateX, i_coordinateY;
        //cin >> i_coordinateX >> i_coordinateY;
        //i_move = i_coordinateX * 3 + i_coordinateY;
        i_move = moveStrategy(board);
        updateBoard(board);
        board.i_numMoves++;
        saveMoveToFile(s_outputDir);
        if (board.checkwin()) {
            cout << "You win.\n";
            c_win = 'Y';
            return;
        }
        board.c_whoseTurn = 167 - board.c_whoseTurn;
    }
    else {
        loadMoveFromFile(s_inputDir, ui_wait);
        updateBoard(board);
        board.i_numMoves++;
        if (board.checkwin()) {
            board.showBoard();
            cout << "Your opponent wins.\n";
            c_win = 'O';
            return;
        }
        board.c_whoseTurn = 167 - board.c_whoseTurn;
    }
}

#endif /* PLAYER_H_ */
