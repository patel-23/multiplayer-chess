#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"

class Rook : public Piece
{
  std::string colour;
  int number_of_moves;

protected:
  Rook *clone_impl() const override;

public:
  Rook(std::string colour);
  bool isValidMove(Cell &start, Cell &dest, Board &b) override;
  bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
  int getMovesCount();
  void incrementMoveCount();
};

#endif
