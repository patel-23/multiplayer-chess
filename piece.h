#ifndef _PIECE_H_
#define _PIECE_H_
#include <string>
#include <memory>

class Cell;
class Board;

class Piece
{
  std::string colour;
  char name;
  int value;

protected:
  virtual Piece *clone_impl() const = 0;

public:
  Piece(std::string colour, std::string name, int value);

  Piece(std::string colour, char name, int value);
  auto clone() const { return std::unique_ptr<Piece>(clone_impl()); }
  virtual ~Piece();
  virtual std::string getColour();
  virtual char getName();
  virtual int getValue();
  virtual bool isValidMove(Cell &start, Cell &dest, Board &b);
  virtual bool isPieceCaptured(Cell &start, Cell &dest, Board &b);
};
#endif
