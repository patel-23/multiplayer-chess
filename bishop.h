#ifndef _BISHOP_H_
#define _BISHOP_H_
#include "piece.h"

class Bishop : public Piece
{
  std::string colour;

protected:
  Bishop *clone_impl() const override;

public:
  Bishop(std::string colour);
  bool isValidMove(Cell &start, Cell &dest, Board &b) override;
  bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
};

#endif
