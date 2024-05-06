#ifndef _KING_H_
#define _KING_H_
#include "piece.h"

class King : public Piece
{
    std::string colour;
    int numberOfMoves;

protected:
    King *clone_impl() const override;

public:
    King(std::string colour);
    bool isValidMove(Cell &start, Cell &dest, Board &b) override;
    bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
    void incrementMoveCount();
    int getMovesCount();
};

#endif
