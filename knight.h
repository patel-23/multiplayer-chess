#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "piece.h"

class Knight : public Piece
{
  std::string colour;

protected:
  Knight *clone_impl() const override;

public:
  Knight(std::string colour);
  bool isValidMove(Cell &start, Cell &dest, Board &b) override;
  bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
};
#endif
