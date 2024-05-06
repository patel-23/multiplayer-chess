#ifndef _QUEEN_H_
#define QUEEN_H_
#include "piece.h"

class Queen : public Piece
{
  std::string colour;

protected:
  Queen *clone_impl() const override;

public:
  Queen(std::string colour);
  bool isValidMove(Cell &start, Cell &dest, Board &b) override;
  bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
};

#endif
