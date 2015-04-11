/*
 * Board.h
 *
 *  Created on: Jun 28, 2014
 *      Author: weiyi
 */

#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board{
public:
    char c_board[9]; // 9 entries of the board
    char c_whoseTurn; // record whose turn to go
    int i_numMoves; // record number of moves currently
    void initialize();
    bool checkwin();
    void showBoard();
    int checkAlmostWinLine(int i_charSum);
    int findLineBlank(int i_almostWinLine);
    int checkAlmostWinEdge(int i_charSum);
};

void Board::initialize() {
    /*
    @summary: initialize board, including reset number of moves, whose turn and entries
    */
    i_numMoves = 0;
    c_whoseTurn = 'X';
    for (int i = 0; i < 9; i++)
        c_board[i] = '_';
}

bool Board::checkwin() {
    /*
    @summary: check whether there is line of same symbols on the board
    @return: true if exists, otherwise false
    */
    if (c_board[0] == c_board[4] && c_board[4] == c_board[8] && c_board[8] != '_')
        return true;
    else if (c_board[3] == c_board[4] && c_board[4] == c_board[5] && c_board[5] != '_')
        return true;
    else if (c_board[1] == c_board[4] && c_board[4] == c_board[7] && c_board[7] != '_')
        return true;
    else if (c_board[2] == c_board[4] && c_board[4] == c_board[6] && c_board[6] != '_')
        return true;
    else if (c_board[0] == c_board[1] && c_board[1] == c_board[2] && c_board[2] != '_')
        return true;
    else if (c_board[0] == c_board[3] && c_board[3] == c_board[6] && c_board[6] != '_')
        return true;
    else if (c_board[6] == c_board[7] && c_board[7] == c_board[8] && c_board[8] != '_')
        return true;
    else if (c_board[2] == c_board[5] && c_board[5] == c_board[8] && c_board[8] != '_')
        return true;
    return false;
}

void Board::showBoard() {
    /*
    @summary: print out the board
    */
    cout << "Board after round " << i_numMoves << ":\n";
    for (int i = 0; i < 9; i++) {
        cout << c_board[i] << " ";
        if ((i+1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

int Board::checkAlmostWinLine(int i_charSum) {
    /*
    @summary: check if there exist a line with two same symbols inside
    @param i_charSum: 271 if there are two X and one _, 253 if there are two O and one _
    @return: line number of almost win line
    */
    if (c_board[0] + c_board[1] + c_board[2] == i_charSum)
        return 1;
    if (c_board[3] + c_board[4] + c_board[5] == i_charSum)
        return 2;
    if (c_board[6] + c_board[7] + c_board[8] == i_charSum)
        return 3;
    if (c_board[0] + c_board[3] + c_board[6] == i_charSum)
        return 4;
    if (c_board[1] + c_board[4] + c_board[7] == i_charSum)
        return 5;
    if (c_board[2] + c_board[5] + c_board[8] == i_charSum)
        return 6;
    if (c_board[0] + c_board[4] + c_board[8] == i_charSum)
        return 7;
    if (c_board[2] + c_board[4] + c_board[6] == i_charSum)
        return 8;
    return 0;
}

int Board::checkAlmostWinEdge(int i_charSum) {
    /*
    @summary: check if there exist an edge with entry '_', but also with two same symbols on its two lines
    @param i_charSum: 538 if there are two Os seperately at two line, 556 if there are two Xs
    @return: return that almost win edge
    */
    if (c_board[1] + c_board[2] + c_board[3] + c_board[6] + 2 * c_board[0] == i_charSum)
        return 0;
    if (c_board[0] + c_board[1] + c_board[5] + c_board[8] + 2 * c_board[2] == i_charSum)
        return 2;
    if (c_board[0] + c_board[3] + c_board[7] + c_board[8] + 2 * c_board[6] == i_charSum)
        return 6;
    if (c_board[2] + c_board[5] + c_board[6] + c_board[7] + 2 * c_board[8] == i_charSum)
        return 8;
    return 0;
}

int Board::findLineBlank(int i_almostWinLine) {
    /*
    @summary: find _ in a line
    @param i_almostWinLine: the line we are going to check
    @return: the board number with entry _
    */
    if (i_almostWinLine <= 3) {
        for (int i = (i_almostWinLine - 1) * 3; i < i_almostWinLine * 3; i++)
            if (c_board[i] == '_')
                return i; 
    }
    else if (i_almostWinLine <= 6) {
        for (int i = i_almostWinLine - 4; i < i_almostWinLine + 3; i += 3)
            if (c_board[i] == '_')
                return i;
    }   
    else if (i_almostWinLine == 7) {
        for (int i = 0; i < 9; i += 4)
            if (c_board[i] == '_')
                return i;
    }
    else if (i_almostWinLine == 8) {
        for (int i = 2; i < 7; i += 2)
            if (c_board[i] == '_')
                return i;
    }
    return 100;
}

#endif /* BOARD_H_ */
