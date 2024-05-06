#ifndef _PAWN_H_
#define _PAWN_H_
#include "piece.h"

class Pawn : public Piece
{
  std::string colour;
  int number_of_moves;
  bool en_passant;
  bool isEnPassantCapture;

protected:
  Pawn *clone_impl() const override;

public:
  Pawn(std::string colour);
  bool isValidMove(Cell &start, Cell &dest, Board &b) override;
  bool isPieceCaptured(Cell &start, Cell &dest, Board &b) override;
  void incrementMoveCount();
  void turnOffEnPassant();
  bool isEnPassant();
  bool isEnPassantCaptureMove();
};

#endif
