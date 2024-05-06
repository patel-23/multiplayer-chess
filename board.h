#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
#include "textdisplay.h"

class Board
{
    const int GRIDSIZE;              // Size of the grid.
    std::unique_ptr<TextDisplay> td; // The text display.
    std::unique_ptr<Piece> latestCapturedPiece;
    bool checkMate;
    bool isCastleExecuted;
    void clearBoard(); // Frees the grid.
    void initPiece(char piece, Cell &cell);
    bool isCellUnderCheckForCheckmate(int player, int row, int col, Board &b, int &numOfAttackers);
    bool isRangeIntereceptable(int player, int rowFrom, int colFrom, int rowTo, int colTo, Board &b);
    std::string getSpaceColour(int r, int c);

public:
    std::vector<std::vector<Cell>> chessBoard; // The actual grid.
    int whiteKingRow;
    int whiteKingCol;
    int blackKingRow;
    int blackKingCol;
    Board();
    ~Board();
    Board &operator=(const Board &other);

    bool isCheckMate() const; // Call to determine if grid is in a winning state.
    char getLatestCapturedPiece() const;
    void init(); // Sets up an n x n grid.  Clears old grid, if necessary.
    std::vector<std::vector<Cell>> getGrid();
    void addPiece(std::string pos, char piece);
    void removePiece(std::string pos);
    bool movePiece(std::string from, std::string to, int playerToMove);
    bool isCheck() const;
    void removeOpponentEnPassant(int currentPlayer);
    bool isGameValid();
    bool isStaleMate(int playerToMove);
    std::unique_ptr<Piece> promotePawn(int r, int c, Board &b, std::string color);
    bool isCellUnderCheck(int player, int row, int col, Board &b, int &numOfAttackers);
    bool isCastlingAllowed(std::vector<std::vector<Cell>> &chessBoard, int rowFrom, int colFrom, int rowTo, int colTo, int playerToMove);
    bool isOwnKingUnderCheck(int player, Board &b);
    bool isOwnMovedKingUnderCheck(int player, Board &b, int newKingRow, int newKingCol);
    bool isOtherKingInCheck(int player, Board &b, int &numOfAttackers);
    bool isOtherKingInCheckMate(int player, Board &b, int &numOfAttackers);
    bool isValidMove(int rowFrom, int colFrom, int rowTo, int colTo, int playerToMove, bool &isCastle, bool isLogError);
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
